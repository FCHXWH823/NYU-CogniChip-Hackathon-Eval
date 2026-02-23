"""
Tiling parameter sweep engine and Pareto frontier extraction.
"""

from __future__ import annotations

import math
import itertools
from dataclasses import dataclass, field
from typing import List, Optional, Dict, Tuple

from config import HWConfig, BufferScheme, DEFAULT_HW
from cost_model import (
    GEMMShape,
    TilingConfig,
    GEMMCost,
    compute_gemm_cost,
    baseline_tiling,
)


TILE_M_CANDIDATES = [1, 2, 4, 8, 16, 32, 64, 128, 256]
TILE_N_CANDIDATES = [32, 64, 128, 256, 512, 1024, 2048, 4096]
TILE_K_CANDIDATES = [32, 64, 128, 256, 512, 1024, 2048, 4096]
BUFFER_SCHEMES = [
    BufferScheme.SINGLE,
    BufferScheme.DOUBLE_B,
    BufferScheme.DOUBLE_A,
    BufferScheme.DOUBLE_AB,
]


def generate_tiling_candidates(
    shape: GEMMShape,
    hw: HWConfig = DEFAULT_HW,
    tile_m_list: List[int] | None = None,
    tile_n_list: List[int] | None = None,
    tile_k_list: List[int] | None = None,
    schemes: List[BufferScheme] | None = None,
) -> List[TilingConfig]:
    """
    Enumerate valid tiling configurations for a GEMM shape.

    Filters out tiles larger than the GEMM dimension and configs
    that obviously exceed SRAM.  Full SRAM validation is deferred
    to compute_gemm_cost (which returns None on overflow).
    """
    tm_list = tile_m_list or TILE_M_CANDIDATES
    tn_list = tile_n_list or TILE_N_CANDIDATES
    tk_list = tile_k_list or TILE_K_CANDIDATES
    buf_list = schemes or BUFFER_SCHEMES

    candidates: List[TilingConfig] = []
    for tm, tn, tk, scheme in itertools.product(tm_list, tn_list, tk_list, buf_list):
        if tm > shape.M:
            tm_eff = shape.M
        else:
            tm_eff = tm
        if tn > shape.N:
            tn_eff = shape.N
        else:
            tn_eff = tn
        if tk > shape.K:
            tk_eff = shape.K
        else:
            tk_eff = tk

        a_mult = 2 if scheme in (BufferScheme.DOUBLE_A, BufferScheme.DOUBLE_AB) else 1
        b_mult = 2 if scheme in (BufferScheme.DOUBLE_B, BufferScheme.DOUBLE_AB) else 1
        rough_sram = (
            int(math.ceil(tm_eff * tk_eff * hw.act_bytes)) * a_mult
            + int(math.ceil(tk_eff * tn_eff * hw.weight_bytes)) * b_mult
            + tm_eff * tn_eff * hw.acc_bytes
        )
        if rough_sram > hw.sram_total_bytes:
            continue

        candidates.append(TilingConfig(tm_eff, tn_eff, tk_eff, scheme))

    seen = set()
    deduped: List[TilingConfig] = []
    for c in candidates:
        key = (c.tile_m, c.tile_n, c.tile_k, c.buffer_scheme)
        if key not in seen:
            seen.add(key)
            deduped.append(c)

    return deduped


@dataclass
class SweepResult:
    """Results of sweeping one GEMM shape across all tiling candidates."""

    shape: GEMMShape
    all_costs: List[GEMMCost]
    pareto_costs: List[GEMMCost]
    baseline_cost: GEMMCost

    @property
    def best_utilisation(self) -> GEMMCost:
        return max(self.pareto_costs, key=lambda c: c.compute_utilisation)

    @property
    def best_dram(self) -> GEMMCost:
        return min(self.pareto_costs, key=lambda c: c.dram_total)


def sweep_gemm(
    shape: GEMMShape,
    hw: HWConfig = DEFAULT_HW,
    **kwargs,
) -> SweepResult:
    """
    Sweep all valid tiling configs for a single GEMM shape.

    Returns a SweepResult containing all valid costs and the Pareto frontier.
    """
    candidates = generate_tiling_candidates(shape, hw, **kwargs)
    costs: List[GEMMCost] = []
    for tiling in candidates:
        cost = compute_gemm_cost(shape, tiling, hw)
        if cost is not None:
            costs.append(cost)

    bl_tiling = baseline_tiling(shape, hw)
    bl_cost = compute_gemm_cost(shape, bl_tiling, hw)
    assert bl_cost is not None, f"Baseline tiling doesn't fit for {shape.name}"

    pareto = extract_pareto(costs)

    return SweepResult(
        shape=shape,
        all_costs=costs,
        pareto_costs=pareto,
        baseline_cost=bl_cost,
    )


def extract_pareto(
    costs: List[GEMMCost],
) -> List[GEMMCost]:
    """
    Extract the Pareto frontier on (dram_total ↓, compute_utilisation ↑).

    A point is Pareto-optimal if no other point has BOTH:
      - less or equal DRAM traffic AND
      - higher or equal compute utilisation
    """
    if not costs:
        return []

    sorted_costs = sorted(costs, key=lambda c: c.dram_total)
    pareto: List[GEMMCost] = []
    best_util = -1.0

    for c in sorted_costs:
        if c.compute_utilisation > best_util:
            pareto.append(c)
            best_util = c.compute_utilisation

    return pareto


def sweep_all_layer_gemms(
    gemms: List[GEMMShape],
    hw: HWConfig = DEFAULT_HW,
    **kwargs,
) -> Dict[str, SweepResult]:
    """Sweep each GEMM shape in a layer independently."""
    results: Dict[str, SweepResult] = {}
    for g in gemms:
        results[g.name] = sweep_gemm(g, hw, **kwargs)
    return results


@dataclass
class UniformVsPerGemmComparison:
    """Compare uniform tiling (one config for all GEMMs) vs per-GEMM optimal."""

    uniform_dram: int
    uniform_cycles: float
    uniform_util: float
    per_gemm_dram: int
    per_gemm_cycles: float
    per_gemm_util: float

    @property
    def dram_reduction_pct(self) -> float:
        if self.uniform_dram == 0:
            return 0.0
        return (1 - self.per_gemm_dram / self.uniform_dram) * 100

    @property
    def util_improvement_pp(self) -> float:
        return (self.per_gemm_util - self.uniform_util) * 100


def compare_uniform_vs_per_gemm(
    sweep_results: Dict[str, SweepResult],
) -> UniformVsPerGemmComparison:
    """
    Compare best uniform tiling against per-GEMM-optimal tiling.

    Uniform: find the single tiling config that minimises total cycles
    across all GEMMs (brute-force over the intersection of valid configs).
    Per-GEMM: each GEMM uses its own best-utilisation Pareto point.
    """
    per_gemm_dram = sum(r.best_utilisation.dram_total for r in sweep_results.values())
    per_gemm_cycles = sum(
        r.best_utilisation.total_cycles for r in sweep_results.values()
    )
    per_gemm_ideal = sum(
        r.best_utilisation.ideal_compute_cycles for r in sweep_results.values()
    )
    per_gemm_util = per_gemm_ideal / per_gemm_cycles if per_gemm_cycles > 0 else 0

    all_tilings: Dict[Tuple, TilingConfig] = {}
    for r in sweep_results.values():
        for c in r.all_costs:
            key = (
                c.tiling.tile_m,
                c.tiling.tile_n,
                c.tiling.tile_k,
                c.tiling.buffer_scheme,
            )
            all_tilings[key] = c.tiling

    best_uniform_cycles = float("inf")
    best_uniform_result: Optional[Dict[str, GEMMCost]] = None

    for tiling in all_tilings.values():
        layer_costs: Dict[str, GEMMCost] = {}
        valid = True
        for name, r in sweep_results.items():
            cost = compute_gemm_cost(r.shape, tiling, DEFAULT_HW)
            if cost is None:
                valid = False
                break
            layer_costs[name] = cost
        if not valid:
            continue
        total_cyc = sum(c.total_cycles for c in layer_costs.values())
        if total_cyc < best_uniform_cycles:
            best_uniform_cycles = total_cyc
            best_uniform_result = layer_costs

    if best_uniform_result is None:
        uniform_dram = 0
        uniform_cycles = 0.0
        uniform_util = 0.0
    else:
        uniform_dram = sum(c.dram_total for c in best_uniform_result.values())
        uniform_cycles = sum(c.total_cycles for c in best_uniform_result.values())
        uniform_ideal = sum(
            c.ideal_compute_cycles for c in best_uniform_result.values()
        )
        uniform_util = uniform_ideal / uniform_cycles if uniform_cycles > 0 else 0

    return UniformVsPerGemmComparison(
        uniform_dram=uniform_dram,
        uniform_cycles=uniform_cycles,
        uniform_util=uniform_util,
        per_gemm_dram=per_gemm_dram,
        per_gemm_cycles=per_gemm_cycles,
        per_gemm_util=per_gemm_util,
    )
