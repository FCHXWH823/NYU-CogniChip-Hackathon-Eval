"""
Core GEMM tiling cost model.

For a GEMM  C[M, N] = A[M, K] x B[K, N]:
  - A = activations  (INT8,  act_bytes   per element)
  - B = weights       (INT4,  weight_bytes per element)
  - C = accumulator   (INT32, acc_bytes    per element)

The cost model evaluates a given (tile_m, tile_n, tile_k, buffer_scheme)
configuration against hardware constraints and returns DRAM traffic,
cycle counts, and compute utilization.

Loop nest assumed (A-reuse with output grouping):
  for i in [n_m]:                      # output row tiles
    for jg in [n_jg]:                  # output column groups
      init C tiles in SRAM (J_c tiles)
      for k in [n_k]:                  # reduction tiles
        load A[i,k]                    # reused across J_c columns
        for j in [J_c]:               # columns within group
          load B[k, jg*J_c+j]
          C[i, jg*J_c+j] += A * B
      store J_c output tiles

This gives:
  A loads  = n_m * n_jg * n_k          (A reuse factor = J_c)
  B loads  = n_m * n_jg * n_k * J_c    (= n_m * n_n * n_k, no B reuse across i)
  C writes = n_m * n_n
"""

from __future__ import annotations

import math
from dataclasses import dataclass
from typing import Optional

from config import HWConfig, BufferScheme


# ---------------------------------------------------------------------------
# Data structures
# ---------------------------------------------------------------------------


@dataclass(frozen=True)
class GEMMShape:
    """Describes a single GEMM: C[M,N] = A[M,K] x B[K,N]."""

    name: str
    M: int  # output rows    (seq_len for prefill, 1 for decode)
    N: int  # output columns (projection output dim)
    K: int  # inner dim      (projection input dim)

    @property
    def total_macs(self) -> int:
        return self.M * self.N * self.K

    @property
    def weight_elements(self) -> int:
        return self.K * self.N


@dataclass(frozen=True)
class TilingConfig:
    """Tile dimensions and buffer strategy."""

    tile_m: int
    tile_n: int
    tile_k: int
    buffer_scheme: BufferScheme = BufferScheme.SINGLE


@dataclass
class GEMMCost:
    """Result of cost evaluation for one GEMM + tiling configuration."""

    shape: GEMMShape
    tiling: TilingConfig

    # Tile counts
    n_tiles_m: int = 0
    n_tiles_n: int = 0
    n_tiles_k: int = 0
    n_j_groups: int = 0  # number of output-column groups
    j_c: int = 0  # output column tiles kept in SRAM simultaneously

    # SRAM usage (bytes)
    sram_a: int = 0  # A buffer (single or double)
    sram_b: int = 0  # B buffer (single or double)
    sram_c: int = 0  # C accumulator tiles
    sram_total: int = 0

    # DRAM traffic (bytes)
    dram_read_a: int = 0
    dram_read_b: int = 0
    dram_write_c: int = 0
    dram_total: int = 0

    # Cycle counts
    compute_cycles: float = 0.0  # time the MAC array is working
    ideal_compute_cycles: float = 0.0  # if array were 100% efficient
    memory_cycles: float = 0.0  # DRAM transfer time (total)
    total_cycles: float = 0.0  # wall-clock cycles (with overlap)

    # Utilisation metrics
    mac_array_efficiency: float = 0.0  # tile shape vs array shape
    compute_utilisation: float = 0.0  # ideal_compute / total_cycles
    arithmetic_intensity: float = 0.0  # MACs / DRAM byte

    @property
    def dram_read_total(self) -> int:
        return self.dram_read_a + self.dram_read_b

    @property
    def is_compute_bound(self) -> bool:
        return self.compute_cycles >= self.memory_cycles


# ---------------------------------------------------------------------------
# Core cost computation
# ---------------------------------------------------------------------------


def compute_gemm_cost(
    shape: GEMMShape,
    tiling: TilingConfig,
    hw: HWConfig,
) -> Optional[GEMMCost]:
    """
    Evaluate the cost of executing *shape* with *tiling* on *hw*.

    Returns None if the tiling violates the SRAM constraint.
    """
    tm, tn, tk = tiling.tile_m, tiling.tile_n, tiling.tile_k
    M, N, K = shape.M, shape.N, shape.K
    scheme = tiling.buffer_scheme

    # Clamp tile sizes to GEMM dimensions
    tm = min(tm, M)
    tn = min(tn, N)
    tk = min(tk, K)

    # ------------------------------------------------------------------
    # 1. SRAM footprint
    # ------------------------------------------------------------------
    a_tile_bytes = int(math.ceil(tm * tk * hw.act_bytes))
    b_tile_bytes = int(math.ceil(tk * tn * hw.weight_bytes))
    c_tile_bytes = tm * tn * hw.acc_bytes  # INT32 accumulator

    a_buf_mult = 2 if scheme in (BufferScheme.DOUBLE_A, BufferScheme.DOUBLE_AB) else 1
    b_buf_mult = 2 if scheme in (BufferScheme.DOUBLE_B, BufferScheme.DOUBLE_AB) else 1

    sram_a = a_tile_bytes * a_buf_mult
    sram_b = b_tile_bytes * b_buf_mult

    # Minimum SRAM: A buf + B buf + at least 1 C tile
    min_sram = sram_a + sram_b + c_tile_bytes
    if min_sram > hw.sram_total_bytes:
        return None  # does not fit

    # How many C tiles can we keep? (determines A reuse via J_c)
    sram_for_c = hw.sram_total_bytes - sram_a - sram_b
    j_c = max(1, sram_for_c // c_tile_bytes)

    sram_c = j_c * c_tile_bytes
    sram_total = sram_a + sram_b + sram_c

    # ------------------------------------------------------------------
    # 2. Tile iteration counts
    # ------------------------------------------------------------------
    n_m = math.ceil(M / tm)
    n_n = math.ceil(N / tn)
    n_k = math.ceil(K / tk)
    n_jg = math.ceil(n_n / j_c)  # output-column groups

    # Clamp j_c to actual n_n (don't exceed available columns)
    j_c_eff = min(j_c, n_n)

    # ------------------------------------------------------------------
    # 3. DRAM traffic (bytes)
    # ------------------------------------------------------------------
    # A loads: one per (i, jg, k) triple
    n_a_loads = n_m * n_jg * n_k
    dram_read_a = n_a_loads * a_tile_bytes

    # B loads: one per (i, jg, k, j-within-group) = n_m * n_n * n_k
    n_b_loads = n_m * n_n * n_k
    dram_read_b = n_b_loads * b_tile_bytes

    # C writes: one per output tile
    dram_write_c = n_m * n_n * int(math.ceil(tm * tn * hw.output_bytes))

    dram_total = dram_read_a + dram_read_b + dram_write_c

    # ------------------------------------------------------------------
    # 4. Compute cycles
    # ------------------------------------------------------------------
    # Per-tile: ceil(tm/mac_m) * ceil(tn/mac_n) * tk systolic passes
    sub_tiles_m = math.ceil(tm / hw.mac_array_m)
    sub_tiles_n = math.ceil(tn / hw.mac_array_n)
    compute_per_tile = sub_tiles_m * sub_tiles_n * tk  # cycles

    total_tile_ops = n_m * n_n * n_k
    compute_cycles = total_tile_ops * compute_per_tile

    # Ideal: if array were always fully utilised
    ideal_compute_cycles = shape.total_macs / hw.macs_per_cycle

    # MAC array efficiency (accounts for edge sub-tiles)
    useful_macs_per_tile = tm * tn * tk
    array_macs_per_tile = sub_tiles_m * sub_tiles_n * hw.macs_per_cycle * tk
    mac_efficiency = (
        useful_macs_per_tile / array_macs_per_tile if array_macs_per_tile > 0 else 0.0
    )

    # ------------------------------------------------------------------
    # 5. Memory transfer cycles (with per-tile latency model)
    # ------------------------------------------------------------------
    a_xfer_cycles = hw.dram_transfer_cycles(dram_read_a, num_transactions=n_a_loads)
    b_xfer_cycles = hw.dram_transfer_cycles(dram_read_b, num_transactions=n_b_loads)
    c_xfer_cycles = hw.dram_transfer_cycles(dram_write_c, num_transactions=n_m * n_n)
    memory_cycles = a_xfer_cycles + b_xfer_cycles + c_xfer_cycles

    # ------------------------------------------------------------------
    # 6. Total cycles (overlap model depends on buffer scheme)
    # ------------------------------------------------------------------
    total_cycles = _compute_total_cycles(
        scheme=scheme,
        n_m=n_m,
        n_jg=n_jg,
        n_k=n_k,
        j_c_eff=j_c_eff,
        n_n=n_n,
        a_tile_bytes=a_tile_bytes,
        b_tile_bytes=b_tile_bytes,
        c_tile_bytes=c_tile_bytes,
        compute_per_tile=compute_per_tile,
        hw=hw,
    )

    # ------------------------------------------------------------------
    # 7. Derived metrics
    # ------------------------------------------------------------------
    compute_util = ideal_compute_cycles / total_cycles if total_cycles > 0 else 0.0
    arith_intensity = shape.total_macs / dram_total if dram_total > 0 else float("inf")

    return GEMMCost(
        shape=shape,
        tiling=tiling,
        n_tiles_m=n_m,
        n_tiles_n=n_n,
        n_tiles_k=n_k,
        n_j_groups=n_jg,
        j_c=j_c_eff,
        sram_a=sram_a,
        sram_b=sram_b,
        sram_c=sram_c,
        sram_total=sram_total,
        dram_read_a=dram_read_a,
        dram_read_b=dram_read_b,
        dram_write_c=dram_write_c,
        dram_total=dram_total,
        compute_cycles=compute_cycles,
        ideal_compute_cycles=ideal_compute_cycles,
        memory_cycles=memory_cycles,
        total_cycles=total_cycles,
        mac_array_efficiency=mac_efficiency,
        compute_utilisation=compute_util,
        arithmetic_intensity=arith_intensity,
    )


# ---------------------------------------------------------------------------
# Overlap / pipeline model
# ---------------------------------------------------------------------------


def _compute_total_cycles(
    *,
    scheme: BufferScheme,
    n_m: int,
    n_jg: int,
    n_k: int,
    j_c_eff: int,
    n_n: int,
    a_tile_bytes: int,
    b_tile_bytes: int,
    c_tile_bytes: int,
    compute_per_tile: int,
    hw: HWConfig,
) -> float:
    """
    Compute wall-clock cycles accounting for compute/memory overlap.

    Single buffer:
        Everything sequential within the loop nest.

    Double-buffer B (most common for weight streaming):
        While computing tile[j], prefetch B tile[j+1].
        A loads remain sequential (blocking).
        Per k-iteration:
            load_A + load_B_first + (J_c-1)*max(load_B, compute) + compute_last

    Double-buffer A:
        While doing the J_c inner B+compute loop, prefetch next A.
        Per k-iteration:
            max(load_A, J_c*(load_B + compute))

    Double-buffer both:
        Both overlaps combined.
        Per k-iteration:
            max(load_A, J_c * max(load_B, compute))
    """
    # Per-tile transfer times (cycles) — single tile each
    t_load_a = hw.dram_transfer_cycles(a_tile_bytes, num_transactions=1)
    t_load_b = hw.dram_transfer_cycles(b_tile_bytes, num_transactions=1)
    t_compute = float(compute_per_tile)

    # Output store per group (j_c tiles at a time)
    c_out_bytes_per_tile = int(
        math.ceil(
            (c_tile_bytes // hw.acc_bytes) * hw.output_bytes  # re-quantised
        )
    )
    t_store_group = hw.dram_transfer_cycles(
        c_out_bytes_per_tile * j_c_eff, num_transactions=j_c_eff
    )

    # Time per k-iteration (processes J_c B tiles with one A tile)
    if scheme == BufferScheme.SINGLE:
        # All sequential: load A + J_c * (load B + compute)
        t_k_iter = t_load_a + j_c_eff * (t_load_b + t_compute)

    elif scheme == BufferScheme.DOUBLE_B:
        # Overlap B load with compute (pipeline B tiles)
        # load_A (blocking) + first_B (blocking) +
        #   (J_c-1) * max(load_B, compute) + last_compute
        if j_c_eff <= 1:
            t_k_iter = t_load_a + t_load_b + t_compute
        else:
            t_k_iter = (
                t_load_a
                + t_load_b  # first B
                + (j_c_eff - 1) * max(t_load_b, t_compute)  # pipeline
                + t_compute  # drain
            )

    elif scheme == BufferScheme.DOUBLE_A:
        # Overlap A prefetch with the inner B+compute loop
        inner_time = j_c_eff * (t_load_b + t_compute)
        t_k_iter = max(t_load_a, inner_time)

    elif scheme == BufferScheme.DOUBLE_AB:
        # Both overlaps
        if j_c_eff <= 1:
            inner_time = max(t_load_b, t_compute)
        else:
            inner_time = t_load_b + (j_c_eff - 1) * max(t_load_b, t_compute) + t_compute
        t_k_iter = max(t_load_a, inner_time)

    else:
        raise ValueError(f"Unknown buffer scheme: {scheme}")

    # Total across all output groups
    # For each (i, jg): n_k iterations + store output
    t_per_group = n_k * t_k_iter + t_store_group
    total = n_m * n_jg * t_per_group

    # For double-buffer schemes: add startup cost (first A load not overlapped)
    if scheme in (BufferScheme.DOUBLE_A, BufferScheme.DOUBLE_AB):
        total += t_load_a  # very first A tile can't be overlapped

    return total


# ---------------------------------------------------------------------------
# Baseline (naive single-buffer, small tiles)
# ---------------------------------------------------------------------------


def baseline_tiling(shape: GEMMShape, hw: HWConfig) -> TilingConfig:
    """
    Construct a conservative baseline tiling:
    - Single buffer (no overlap)
    - tile_m = min(M, mac_m)  — one MAC row strip
    - tile_n = mac_n           — one MAC column strip
    - tile_k = mac_n           — small reduction tile
    """
    return TilingConfig(
        tile_m=min(shape.M, hw.mac_array_m),
        tile_n=hw.mac_array_n,
        tile_k=hw.mac_array_n,
        buffer_scheme=BufferScheme.SINGLE,
    )
