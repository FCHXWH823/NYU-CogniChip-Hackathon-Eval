"""
Map Transformer layer operations to GEMM shapes for cost analysis.

Each Transformer layer contains:
  Attention: Q/K/V projections, output projection
  FFN (SwiGLU): gate / up / down projections

Attention score computation (QK^T, Score*V) is modelled separately
since it involves the KV cache and has different access patterns.
"""

from __future__ import annotations

import math
from dataclasses import dataclass
from typing import List, Dict

from config import ModelConfig, HWConfig, QWEN3_8B
from cost_model import GEMMShape, GEMMCost, TilingConfig, compute_gemm_cost


def get_layer_gemms(model: ModelConfig, seq_len: int) -> List[GEMMShape]:
    """
    Return the GEMM shapes for one Transformer layer.

    For decode (seq_len=1) these become matrix-vector products.
    For prefill (seq_len>1) these are full GEMMs.
    """
    M = seq_len
    H = model.hidden_size
    KV = model.kv_dim  # num_kv_heads * head_dim
    I = model.intermediate_size

    return [
        GEMMShape("attn_q_proj", M, H, H),  # X @ Wq  -> [M, 4096]
        GEMMShape("attn_k_proj", M, KV, H),  # X @ Wk  -> [M, 1024]
        GEMMShape("attn_v_proj", M, KV, H),  # X @ Wv  -> [M, 1024]
        GEMMShape("attn_o_proj", M, H, H),  # X @ Wo  -> [M, 4096]
        GEMMShape("ffn_gate_proj", M, I, H),  # X @ Wg  -> [M, 12288]
        GEMMShape("ffn_up_proj", M, I, H),  # X @ Wu  -> [M, 12288]
        GEMMShape("ffn_down_proj", M, H, I),  # X @ Wd  -> [M, 4096]
    ]


def get_unique_gemm_groups(
    model: ModelConfig, seq_len: int
) -> Dict[str, List[GEMMShape]]:
    """
    Group GEMMs by unique (N, K) shape — these share optimal tiling.

    Returns dict mapping group_name -> list of GEMMShapes.
    For Qwen3-8B this yields 4 groups:
      "Hx H"     : Q proj, O proj          (N=4096, K=4096)
      "KVxH"    : K proj, V proj          (N=1024, K=4096)
      "IxH"     : gate proj, up proj      (N=12288, K=4096)
      "HxI"     : down proj               (N=4096, K=12288)
    """
    gemms = get_layer_gemms(model, seq_len)
    groups: Dict[str, List[GEMMShape]] = {}
    for g in gemms:
        key = f"{g.N}x{g.K}"
        groups.setdefault(key, []).append(g)
    return groups


@dataclass
class LayerCost:
    """Aggregate cost for one full Transformer layer."""

    gemm_costs: Dict[str, GEMMCost]
    total_dram_bytes: int
    total_compute_cycles: float
    total_cycles: float
    avg_utilisation: float


def compute_layer_cost(
    model: ModelConfig,
    seq_len: int,
    tilings: Dict[str, TilingConfig],
    hw: HWConfig,
) -> LayerCost | None:
    """
    Compute cost for one Transformer layer.

    Args:
        tilings: maps GEMM name (e.g. "attn_q_proj") -> TilingConfig.
                 If a GEMM's name is missing, falls back to key "{N}x{K}".
    """
    gemms = get_layer_gemms(model, seq_len)
    costs: Dict[str, GEMMCost] = {}

    for g in gemms:
        tiling = tilings.get(g.name) or tilings.get(f"{g.N}x{g.K}")
        if tiling is None:
            return None
        cost = compute_gemm_cost(g, tiling, hw)
        if cost is None:
            return None
        costs[g.name] = cost

    total_dram = sum(c.dram_total for c in costs.values())
    total_compute = sum(c.ideal_compute_cycles for c in costs.values())
    total_wall = sum(c.total_cycles for c in costs.values())
    avg_util = total_compute / total_wall if total_wall > 0 else 0.0

    return LayerCost(
        gemm_costs=costs,
        total_dram_bytes=total_dram,
        total_compute_cycles=total_compute,
        total_cycles=total_wall,
        avg_utilisation=avg_util,
    )


@dataclass
class ModelCost:
    """Aggregate cost across all layers of the Transformer."""

    layer_cost: LayerCost
    num_layers: int

    @property
    def total_dram_bytes(self) -> int:
        return self.layer_cost.total_dram_bytes * self.num_layers

    @property
    def total_cycles(self) -> float:
        return self.layer_cost.total_cycles * self.num_layers

    @property
    def total_time_ms(self) -> float:
        """Wall-clock time in milliseconds (at given MAC frequency)."""
        return self.total_cycles * 2.0 / 1e6  # 2ns/cycle @ 500MHz

    @property
    def avg_utilisation(self) -> float:
        return self.layer_cost.avg_utilisation
