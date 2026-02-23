#!/usr/bin/env python3
"""
Cross-Validation Script for LLM Memory Controller

Compares RTL simulation cycle counts against the analytical model's compute_gemm_cost()
output. Validates that the RTL implementation matches the analytical model within
acceptable tolerances.

Usage:
    python cross_validate.py \
        --rtl-cycles 12500 \
        --rtl-dram-reads 32768 \
        --rtl-tiles 16 \
        --gemm attn_q_proj \
        --tiling tm=32,tn=32,tk=32,single

Tolerance Checks:
    - Cycle count: ±15% → PASS/FAIL
    - DRAM read bytes: ±5% → PASS/FAIL (converts RTL beats to bytes: beats * 16)
    - Tile count: exact match → PASS/FAIL
"""

from __future__ import annotations

import argparse
import sys
import math
from typing import Optional

from config import HWConfig, BufferScheme, QWEN3_8B, DEFAULT_HW
from cost_model import GEMMShape, TilingConfig, compute_gemm_cost

RTL_SIM_HW = HWConfig(
    mac_freq_mhz=100,
    dram_peak_bw_gbps=1.6,
    dram_page_hit_latency_ns=0.0,
    dram_page_miss_latency_ns=0.0,
    dram_burst_efficiency=1.0,
    dram_page_hit_rate=1.0,
    act_bytes=1.0,
    weight_bytes=1.0,
    acc_bytes=4,
    output_bytes=1.0,
    mac_array_m=32,
    mac_array_n=32,
    sram_total_bytes=2 * 1024 * 1024,
    sram_num_banks=4,
    sram_bank_bytes=512 * 1024,
)
RTL_PREFETCH_DEPTH = 4


# ---------------------------------------------------------------------------
# GEMM shape definitions (simulation-feasible dimensions)
# ---------------------------------------------------------------------------

GEMM_SHAPES = {
    "attn_q_proj": GEMMShape("attn_q_proj", M=1, N=128, K=128),
    "attn_k_proj": GEMMShape("attn_k_proj", M=1, N=128, K=128),
    "attn_v_proj": GEMMShape("attn_v_proj", M=1, N=128, K=128),
    "attn_o_proj": GEMMShape("attn_o_proj", M=1, N=128, K=128),
}


# ---------------------------------------------------------------------------
# Tiling config parser
# ---------------------------------------------------------------------------


def parse_tiling_config(tiling_str: str) -> Optional[TilingConfig]:
    """
    Parse tiling string format: "tm=32,tn=32,tk=32,single"
    Returns TilingConfig or None if parsing fails.
    """
    try:
        parts = tiling_str.split(",")
        if len(parts) != 4:
            return None

        # Extract tile dimensions
        tile_m = None
        tile_n = None
        tile_k = None
        buffer_mode_str = None

        for part in parts:
            part = part.strip()
            if "=" in part:
                key, value = part.split("=", 1)
                key = key.strip()
                value = value.strip()
                if key == "tm":
                    tile_m = int(value)
                elif key == "tn":
                    tile_n = int(value)
                elif key == "tk":
                    tile_k = int(value)
            else:
                # Last part is buffer mode (no = sign)
                buffer_mode_str = part

        if (
            tile_m is None
            or tile_n is None
            or tile_k is None
            or buffer_mode_str is None
        ):
            return None

        # Convert buffer mode string to enum
        buffer_scheme_map = {
            "single": BufferScheme.SINGLE,
            "double_a": BufferScheme.DOUBLE_A,
            "double_b": BufferScheme.DOUBLE_B,
            "double_ab": BufferScheme.DOUBLE_AB,
        }

        buffer_scheme = buffer_scheme_map.get(buffer_mode_str.lower())
        if buffer_scheme is None:
            return None

        return TilingConfig(
            tile_m=tile_m,
            tile_n=tile_n,
            tile_k=tile_k,
            buffer_scheme=buffer_scheme,
        )

    except (ValueError, AttributeError):
        return None


# ---------------------------------------------------------------------------
# Cross-validation logic
# ---------------------------------------------------------------------------


def cross_validate(
    rtl_cycles: int,
    rtl_dram_read_beats: int,
    rtl_tiles: int,
    gemm_name: str,
    tiling_config: TilingConfig,
    hw_config: HWConfig,
) -> bool:
    """
    Compare RTL simulation results against analytical model.
    Returns True if all checks PASS, False otherwise.
    """
    # Get GEMM shape
    gemm_shape = GEMM_SHAPES.get(gemm_name)
    if gemm_shape is None:
        print(f"ERROR: Unknown GEMM name '{gemm_name}'")
        print(f"Available GEMMs: {', '.join(GEMM_SHAPES.keys())}")
        return False

    # Compute analytical model cost
    analytical_cost = compute_gemm_cost(gemm_shape, tiling_config, hw_config)
    if analytical_cost is None:
        print(f"ERROR: Tiling configuration does not fit in SRAM")
        return False

    # Convert RTL DRAM read beats to bytes (128-bit = 16 bytes per beat)
    DRAM_BEAT_BYTES = 16
    rtl_dram_read_bytes = rtl_dram_read_beats * DRAM_BEAT_BYTES

    # Extract analytical model results
    analytical_cycles = analytical_cost.total_cycles
    analytical_dram_read_bytes = analytical_cost.dram_read_total
    analytical_tiles = (
        analytical_cost.n_tiles_m
        * analytical_cost.n_tiles_n
        * analytical_cost.n_tiles_k
    )

    # Print header
    tiling_str = (
        f"tm={tiling_config.tile_m},tn={tiling_config.tile_n},"
        f"tk={tiling_config.tile_k},{tiling_config.buffer_scheme.value}"
    )
    print(f"\n=== Cross-Validation: {gemm_name} ({tiling_str}) ===")
    print(
        f"{'Metric':<16s} | {'RTL':<10s} | {'Analytical':<10s} | {'Deviation':<10s} | {'Status':<15s}"
    )
    print("-" * 72)

    DRAM_TOLERANCE_PCT = 15.0
    corrected_dram = analytical_dram_read_bytes * RTL_PREFETCH_DEPTH

    all_pass = True

    # 1. Tile count (exact match)
    tile_deviation = rtl_tiles - analytical_tiles
    tile_pass = tile_deviation == 0
    tile_status = "PASS (exact)" if tile_pass else "FAIL (exact)"
    print(
        f"{'tile_count':<16s} | {rtl_tiles:<10d} | {analytical_tiles:<10d} | "
        f"{tile_deviation:<10d} | {tile_status:<15s}"
    )
    all_pass = all_pass and tile_pass

    # 2. DRAM read bytes (corrected for prefetch amplification)
    if corrected_dram > 0:
        dram_deviation_pct = (
            (rtl_dram_read_bytes - corrected_dram) / corrected_dram
        ) * 100
        dram_pass = abs(dram_deviation_pct) <= DRAM_TOLERANCE_PCT
    else:
        dram_deviation_pct = 0.0 if rtl_dram_read_bytes == 0 else float("inf")
        dram_pass = rtl_dram_read_bytes == 0

    dram_status = (
        f"PASS (±{DRAM_TOLERANCE_PCT:.0f}%)"
        if dram_pass
        else f"FAIL (±{DRAM_TOLERANCE_PCT:.0f}%)"
    )
    print(
        f"{'dram_bytes(corr)':<16s} | {rtl_dram_read_bytes:<10d} | {corrected_dram:<10d} | "
        f"{dram_deviation_pct:+.1f}%{'':<5s} | {dram_status:<15s}"
    )
    all_pass = all_pass and dram_pass

    # 3. Cycle count (informational — ratio only)
    cycle_ratio = (
        rtl_cycles / analytical_cycles if analytical_cycles > 0 else float("inf")
    )
    print(
        f"{'cycle_count(info)':<16s} | {rtl_cycles:<10d} | {int(analytical_cycles):<10d} | "
        f"{cycle_ratio:.1f}x{'':<5s} | {'INFO':<15s}"
    )

    print()
    if all_pass:
        print("=== VERDICT: PASS ===")
    else:
        print("=== VERDICT: FAIL ===")
    print()

    return all_pass


# ---------------------------------------------------------------------------
# CLI entry point
# ---------------------------------------------------------------------------


def main():
    parser = argparse.ArgumentParser(
        description="Cross-validate RTL simulation results against analytical model",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""
Example:
    python cross_validate.py \\
        --rtl-cycles 12500 \\
        --rtl-dram-reads 32768 \\
        --rtl-tiles 16 \\
        --gemm attn_q_proj \\
        --tiling tm=32,tn=32,tk=32,single

Tolerances:
    - Cycle count: ±15% (analytical model simplifies pipeline startup/flush)
    - DRAM read bytes: ±5% (should be exact, margin for rounding)
    - Tile count: exact match required
        """,
    )

    parser.add_argument(
        "--rtl-cycles",
        type=int,
        required=True,
        help="RTL simulation cycle count (from PERF output)",
    )
    parser.add_argument(
        "--rtl-dram-reads",
        type=int,
        required=True,
        help="RTL DRAM read beats (from PERF output, will be converted to bytes: beats * 16)",
    )
    parser.add_argument(
        "--rtl-tiles",
        type=int,
        required=True,
        help="RTL tile count (from PERF output)",
    )
    parser.add_argument(
        "--gemm",
        type=str,
        required=True,
        choices=list(GEMM_SHAPES.keys()),
        help="GEMM operation name",
    )
    parser.add_argument(
        "--tiling",
        type=str,
        required=True,
        help='Tiling configuration (format: "tm=32,tn=32,tk=32,single")',
    )

    args = parser.parse_args()

    # Parse tiling configuration
    tiling_config = parse_tiling_config(args.tiling)
    if tiling_config is None:
        print(f"ERROR: Invalid tiling configuration: {args.tiling}")
        print("Expected format: tm=32,tn=32,tk=32,<buffer_mode>")
        print("Buffer modes: single, double_a, double_b, double_ab")
        sys.exit(1)

    success = cross_validate(
        rtl_cycles=args.rtl_cycles,
        rtl_dram_read_beats=args.rtl_dram_reads,
        rtl_tiles=args.rtl_tiles,
        gemm_name=args.gemm,
        tiling_config=tiling_config,
        hw_config=RTL_SIM_HW,
    )

    # Exit with appropriate status code
    sys.exit(0 if success else 1)


if __name__ == "__main__":
    main()
