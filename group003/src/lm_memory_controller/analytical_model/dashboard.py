#!/usr/bin/env python3
"""
Unified Dashboard for LLM Memory Controller Results.

Parses RTL simulation logs, runs the analytical model, performs cross-validation,
and displays everything in formatted terminal tables + matplotlib charts.

Usage:
    # Analytical model only (no simulation logs needed)
    uv run dashboard.py

    # With simulation log files from Cognichip ACI
    uv run dashboard.py --logs sim_tb1.log sim_tb2.log ...

    # Decode-only analysis
    uv run dashboard.py --mode decode

    # Custom prefill sequence length
    uv run dashboard.py --seq-len 512
"""

from __future__ import annotations

import argparse
import os
import re
import time
from dataclasses import dataclass, field
from typing import Dict, List, Optional, Tuple

from config import DEFAULT_HW, QWEN3_8B, BufferScheme, HWConfig, ModelConfig
from cost_model import TilingConfig, compute_gemm_cost
from cross_validate import GEMM_SHAPES
from layer_model import get_layer_gemms
from sweep import (
    SweepResult,
    compare_uniform_vs_per_gemm,
    sweep_all_layer_gemms,
)

try:
    import matplotlib

    matplotlib.use("Agg")
    import matplotlib.pyplot as plt

    HAS_MPL = True
except ImportError:
    HAS_MPL = False


# ─────────────────────────────────────────────────────────────────────────────
# Constants
# ─────────────────────────────────────────────────────────────────────────────

OUTPUT_DIR = os.path.join(os.path.dirname(__file__), "figures")

# ---------------------------------------------------------------------------
# RTL simulation hardware config (matches tb_gemm_traffic testbench)
# ---------------------------------------------------------------------------
# The RTL testbench uses:
#   - 100 MHz clock (CLK_PERIOD=10ns)
#   - INT8 for both activations and weights (DATA_WIDTH_A=8, DATA_WIDTH_B=8)
#   - Instant DRAM model (dram_req_ready=1, 1 beat/cycle, no latency)
#   - PREFETCH_DEPTH=4 (prefetch engine read amplification)
#
# This differs from DEFAULT_HW which models a production edge SoC (500 MHz,
# INT4 weights, 50 GB/s LPDDR5 with realistic latency).
RTL_SIM_HW = HWConfig(
    mac_freq_mhz=100,
    dram_peak_bw_gbps=1.6,  # 16 bytes/beat / 10 ns = 1.6 GB/s
    dram_page_hit_latency_ns=0.0,
    dram_page_miss_latency_ns=0.0,
    dram_burst_efficiency=1.0,
    dram_page_hit_rate=1.0,
    act_bytes=1.0,  # INT8 activations (DATA_WIDTH_A=8)
    weight_bytes=1.0,  # INT8 weights     (DATA_WIDTH_B=8)
    acc_bytes=4,
    output_bytes=1.0,
    mac_array_m=32,
    mac_array_n=32,
    sram_total_bytes=2 * 1024 * 1024,
    sram_num_banks=4,
    sram_bank_bytes=512 * 1024,
)
RTL_PREFETCH_DEPTH = 4  # tb_gemm_traffic PREFETCH_DEPTH parameter

# Known testbench names and their expected output patterns
KNOWN_TESTBENCHES = [
    "tb_config_regs",
    "tb_tile_scheduler",
    "tb_dram_prefetch_engine",
    "tb_sram_bank_arbiter",
    "tb_llm_memory_controller",
    "tb_gemm_traffic",
    "tb_dynamic_reconfig",
    "tb_llm_memory_controller_comparison",
]


# ─────────────────────────────────────────────────────────────────────────────
# Data structures for parsed simulation results
# ─────────────────────────────────────────────────────────────────────────────


@dataclass
class PerfCounters:
    """Performance counters extracted from simulation log."""

    total_cycles: int = 0
    dram_read_beats: int = 0
    dram_write_beats: int = 0
    tile_count: int = 0
    idle_cycles: int = 0


@dataclass
class ComparisonResult:
    """Baseline vs Optimized comparison from tb_llm_memory_controller_comparison."""

    baseline: PerfCounters = field(default_factory=PerfCounters)
    optimized: PerfCounters = field(default_factory=PerfCounters)
    speedup: float = 0.0
    baseline_done: bool = False
    optimized_done: bool = False


@dataclass
class GEMMPerfLine:
    """Parsed PERF line from tb_gemm_traffic."""

    gemm_name: str = ""
    cycles: int = 0
    dram_reads: int = 0
    dram_writes: int = 0
    tiles: int = 0


@dataclass
class TestbenchResult:
    """Result of parsing one testbench log."""

    name: str
    passed: Optional[bool] = None  # None = not found in logs
    pass_count: Optional[int] = None  # for tb_dynamic_reconfig: N/5
    total_count: Optional[int] = None
    perf_lines: List[GEMMPerfLine] = field(default_factory=list)
    comparison: Optional[ComparisonResult] = None
    log_file: str = ""


# ─────────────────────────────────────────────────────────────────────────────
# Log Parsing
# ─────────────────────────────────────────────────────────────────────────────

# Regex patterns for testbench output
RE_TEST_PASSED = re.compile(r"TEST PASSED")
RE_TEST_FAILED = re.compile(r"TEST FAILED")
RE_DYNAMIC_RESULT = re.compile(r"=== (\d+)/(\d+) TESTS PASSED ===")
RE_PERF_LINE = re.compile(
    r"PERF:\s+gemm=(\S+)\s+cycles=(\d+)\s+dram_reads=(\d+)\s+"
    r"dram_writes=(\d+)\s+tiles=(\d+)"
)
RE_COMPARISON_HEADER = re.compile(r"BASELINE vs OPTIMIZED COMPARISON")
RE_COMPARISON_FAILED = re.compile(r"COMPARISON FAILED")

# Counters from print_single_run_counters
RE_MODE_HEADER = re.compile(r"\[(BASELINE|OPTIMIZED)\] Performance Counters:")
RE_COUNTER = re.compile(
    r"^\s+(total_cycles|dram_read_beats|dram_write_beats|tile_count|idle_cycles)\s+=\s+(\d+)"
)

# Comparison summary metrics
RE_SPEEDUP = re.compile(r"total_cycles\s+(\d+)\s+(\d+)\s+([\d.]+)x faster")


def detect_testbench_name(log_text: str, filename: str) -> str:
    """Guess which testbench produced this log based on content or filename."""
    fname_lower = filename.lower()
    for tb in KNOWN_TESTBENCHES:
        if tb in fname_lower:
            return tb

    # Content-based detection
    if "BASELINE vs OPTIMIZED COMPARISON" in log_text:
        return "tb_llm_memory_controller_comparison"
    if "PERF: gemm=" in log_text:
        return "tb_gemm_traffic"
    if "TESTS PASSED ===" in log_text and "[PASS]" in log_text:
        return "tb_dynamic_reconfig"
    if "TEST 1:" in log_text and "TEST 4:" in log_text:
        return "tb_llm_memory_controller"

    return os.path.basename(filename).replace(".log", "").replace(".txt", "")


def parse_single_run_counters(lines: List[str], start_idx: int) -> PerfCounters:
    """Parse performance counters from print_single_run_counters output."""
    counters = PerfCounters()
    for i in range(start_idx, min(start_idx + 15, len(lines))):
        m = RE_COUNTER.match(lines[i])
        if m:
            name, value = m.group(1), int(m.group(2))
            if name == "total_cycles":
                counters.total_cycles = value
            elif name == "dram_read_beats":
                counters.dram_read_beats = value
            elif name == "dram_write_beats":
                counters.dram_write_beats = value
            elif name == "tile_count":
                counters.tile_count = value
            elif name == "idle_cycles":
                counters.idle_cycles = value
    return counters


def parse_log_file(filepath: str) -> TestbenchResult:
    """Parse a simulation log file and extract results."""
    with open(filepath, "r", errors="replace") as f:
        text = f.read()
    lines = text.splitlines()

    tb_name = detect_testbench_name(text, filepath)
    result = TestbenchResult(name=tb_name, log_file=filepath)

    # PASS/FAIL detection
    if RE_TEST_PASSED.search(text):
        result.passed = True
    elif RE_TEST_FAILED.search(text):
        result.passed = False

    # Dynamic reconfig: "=== N/5 TESTS PASSED ==="
    m = RE_DYNAMIC_RESULT.search(text)
    if m:
        result.pass_count = int(m.group(1))
        result.total_count = int(m.group(2))
        result.passed = result.pass_count == result.total_count

    # PERF lines (tb_gemm_traffic)
    for m in RE_PERF_LINE.finditer(text):
        result.perf_lines.append(
            GEMMPerfLine(
                gemm_name=m.group(1),
                cycles=int(m.group(2)),
                dram_reads=int(m.group(3)),
                dram_writes=int(m.group(4)),
                tiles=int(m.group(5)),
            )
        )

    # Comparison results (tb_llm_memory_controller_comparison)
    if RE_COMPARISON_HEADER.search(text) or RE_COMPARISON_FAILED.search(text):
        comp = ComparisonResult()
        for i, line in enumerate(lines):
            m_mode = RE_MODE_HEADER.match(line)
            if m_mode:
                mode = m_mode.group(1)
                counters = parse_single_run_counters(lines, i + 1)
                if mode == "BASELINE":
                    comp.baseline = counters
                    comp.baseline_done = True
                elif mode == "OPTIMIZED":
                    comp.optimized = counters
                    comp.optimized_done = True

        # Extract speedup
        m_speed = RE_SPEEDUP.search(text)
        if m_speed:
            comp.speedup = float(m_speed.group(3))

        if RE_COMPARISON_FAILED.search(text):
            # Check which one failed
            comp.baseline_done = "BASELINE: RUN FAILED" not in text
            comp.optimized_done = "OPTIMIZED: RUN FAILED" not in text

        result.comparison = comp

    return result


# ─────────────────────────────────────────────────────────────────────────────
# Terminal Display Helpers
# ─────────────────────────────────────────────────────────────────────────────

BOLD = "\033[1m"
GREEN = "\033[32m"
RED = "\033[31m"
YELLOW = "\033[33m"
CYAN = "\033[36m"
DIM = "\033[2m"
RESET = "\033[0m"


def _color(text: str, color: str) -> str:
    return f"{color}{text}{RESET}"


def fmt_bytes(b: int | float) -> str:
    if b >= 1e9:
        return f"{b / 1e9:.2f} GB"
    if b >= 1e6:
        return f"{b / 1e6:.2f} MB"
    if b >= 1e3:
        return f"{b / 1e3:.1f} KB"
    return f"{b} B"


def fmt_cycles(c: float, hw: HWConfig = DEFAULT_HW) -> str:
    time_us = c * hw.cycle_time_ns / 1000
    if time_us >= 1000:
        return f"{c / 1e6:.1f}M cyc ({time_us / 1000:.2f} ms)"
    if time_us >= 1:
        return f"{c / 1e3:.1f}K cyc ({time_us:.1f} us)"
    return f"{c:.0f} cyc ({time_us * 1000:.0f} ns)"


def bar_chart_ascii(label: str, value: float, max_val: float, width: int = 30) -> str:
    """Draw a horizontal ASCII bar."""
    if max_val <= 0:
        filled = 0
    else:
        filled = int(round(value / max_val * width))
    filled = min(filled, width)
    bar = "█" * filled + "░" * (width - filled)
    return f"  {label:30s} │{bar}│ {value:.1f}"


# ─────────────────────────────────────────────────────────────────────────────
# Section 1: Testbench Status Table
# ─────────────────────────────────────────────────────────────────────────────


def print_testbench_status(results: List[TestbenchResult]):
    """Print a summary table of all testbench PASS/FAIL status."""
    print()
    print(_color("=" * 72, BOLD))
    print(_color("  Section 1: RTL Testbench Status", BOLD))
    print(_color("=" * 72, BOLD))
    print()

    if not results:
        print("  (No simulation logs provided. Use --logs to supply log files.)")
        print()
        return

    print(f"  {'#':<3s}  {'Testbench':<44s}  {'Status':<10s}  {'Detail'}")
    print(f"  {'─' * 3}  {'─' * 44}  {'─' * 10}  {'─' * 20}")

    pass_count = 0
    fail_count = 0
    unknown_count = 0

    for i, r in enumerate(results, 1):
        if r.passed is True:
            status = _color("PASS", GREEN)
            pass_count += 1
        elif r.passed is False:
            status = _color("FAIL", RED)
            fail_count += 1
        else:
            status = _color("???", YELLOW)
            unknown_count += 1

        detail = ""
        if r.pass_count is not None and r.total_count is not None:
            detail = f"{r.pass_count}/{r.total_count} tests"
        elif r.perf_lines:
            detail = f"{len(r.perf_lines)} PERF lines"
        elif r.comparison is not None:
            bl = "OK" if r.comparison.baseline_done else "FAIL"
            opt = "OK" if r.comparison.optimized_done else "FAIL"
            detail = f"baseline={bl} optimized={opt}"

        print(f"  {i:<3d}  {r.name:<44s}  {status:<21s}  {detail}")

    total = pass_count + fail_count + unknown_count
    print()
    summary_parts = []
    if pass_count:
        summary_parts.append(_color(f"{pass_count} passed", GREEN))
    if fail_count:
        summary_parts.append(_color(f"{fail_count} failed", RED))
    if unknown_count:
        summary_parts.append(_color(f"{unknown_count} unknown", YELLOW))
    print(f"  Total: {total} testbenches — {', '.join(summary_parts)}")
    print()


# ─────────────────────────────────────────────────────────────────────────────
# Section 2: Baseline vs Optimized Comparison
# ─────────────────────────────────────────────────────────────────────────────


def print_comparison(results: List[TestbenchResult]):
    """Print baseline vs optimized comparison if available."""
    comp_result = None
    for r in results:
        if r.comparison is not None:
            comp_result = r
            break

    print(_color("=" * 72, BOLD))
    print(_color("  Section 2: Baseline vs Optimized (RTL Simulation)", BOLD))
    print(_color("=" * 72, BOLD))
    print()

    if comp_result is None:
        print("  (No comparison data found. Run tb_llm_memory_controller_comparison)")
        print("  (and provide its log file via --logs.)")
        print()
        return

    comp = comp_result.comparison
    assert comp is not None

    if not comp.baseline_done or not comp.optimized_done:
        print(_color("  ⚠ Comparison incomplete:", YELLOW))
        if not comp.baseline_done:
            print("    Baseline run: FAILED (timeout)")
        if not comp.optimized_done:
            print("    Optimized run: FAILED (timeout)")
        print()
        return

    bl, opt = comp.baseline, comp.optimized

    # Table
    print(f"  {'Metric':<28s}  {'Baseline':>12s}  {'Optimized':>12s}  {'Change':>12s}")
    print(f"  {'─' * 28}  {'─' * 12}  {'─' * 12}  {'─' * 12}")

    rows = [
        ("Total cycles", bl.total_cycles, opt.total_cycles),
        ("DRAM read beats", bl.dram_read_beats, opt.dram_read_beats),
        ("DRAM write beats", bl.dram_write_beats, opt.dram_write_beats),
        ("Tile count", bl.tile_count, opt.tile_count),
        ("Idle cycles", bl.idle_cycles, opt.idle_cycles),
    ]

    for label, bv, ov in rows:
        if bv > 0:
            change_pct = (ov - bv) / bv * 100
            change_str = f"{change_pct:+.1f}%"
            if change_pct < 0:
                change_str = _color(change_str, GREEN)
            elif change_pct > 0:
                change_str = _color(change_str, RED)
        else:
            change_str = "—"
        print(f"  {label:<28s}  {bv:>12d}  {ov:>12d}  {change_str:>23s}")

    # Derived metrics
    print()
    if bl.total_cycles > 0:
        bl_eff = 100.0 * (1.0 - bl.idle_cycles / bl.total_cycles)
    else:
        bl_eff = 0.0
    if opt.total_cycles > 0:
        opt_eff = 100.0 * (1.0 - opt.idle_cycles / opt.total_cycles)
    else:
        opt_eff = 0.0

    speedup = (
        comp.speedup
        if comp.speedup > 0
        else (bl.total_cycles / opt.total_cycles if opt.total_cycles > 0 else 0)
    )

    print(f"  {_color('Key Results:', BOLD)}")
    print(
        f"    Compute efficiency:  {bl_eff:.1f}%  →  {opt_eff:.1f}%  ({_color(f'+{opt_eff - bl_eff:.1f} pp', GREEN)})"
    )
    print(f"    Speedup:             {_color(f'{speedup:.2f}x', CYAN)}")
    print()


# ─────────────────────────────────────────────────────────────────────────────
# Section 3: Cross-Validation (RTL vs Analytical)
# ─────────────────────────────────────────────────────────────────────────────


def print_cross_validation(results: List[TestbenchResult], hw: HWConfig):
    """Cross-validate RTL PERF output against analytical model.

    Uses RTL_SIM_HW (INT8 weights, instant DRAM, 100 MHz) instead of the
    production DEFAULT_HW, because the testbench's DRAM model and data types
    differ fundamentally from the production config.

    Correction factors applied:
      - DRAM traffic: multiplied by RTL_PREFETCH_DEPTH (prefetch engine read
        amplification — the engine issues PREFETCH_DEPTH outstanding requests,
        so perf_dram_read_beats counts all prefetched beats).
      - Cycle count: shown as informational ratio (RTL includes real FSM
        pipeline overhead, SRAM arbiter latency, and prefetch queue stalls
        that the steady-state analytical model does not capture).
    """
    print(_color("=" * 72, BOLD))
    print(_color("  Section 3: Cross-Validation (RTL vs Analytical Model)", BOLD))
    print(_color("=" * 72, BOLD))
    print()

    perf_lines: List[GEMMPerfLine] = []
    for r in results:
        perf_lines.extend(r.perf_lines)

    if not perf_lines:
        print("  (No PERF lines found. Run tb_gemm_traffic and provide its log.)")
        print()
        return

    # Deduplicate PERF lines (tb_gemm_traffic emits both _sim and non-_sim
    # variants with identical data; keep the first occurrence per gemm name)
    seen_gemm: set = set()
    unique_perf: List[GEMMPerfLine] = []
    for perf in perf_lines:
        canonical = perf.gemm_name.replace("_sim", "")
        if canonical not in seen_gemm:
            seen_gemm.add(canonical)
            unique_perf.append(perf)
    perf_lines = unique_perf

    # Print config summary
    print(f"  {_color('RTL-Matched Config:', BOLD)}")
    print(f"    Clock:   {RTL_SIM_HW.mac_freq_mhz} MHz  (testbench CLK_PERIOD=10ns)")
    print(f"    Weights: INT8  (DATA_WIDTH_B=8, analytical default is INT4)")
    print(f"    DRAM:    instant model (1 beat/cycle, no latency)")
    print(f"    Prefetch depth correction: x{RTL_PREFETCH_DEPTH} on DRAM reads")
    print()

    # tb_gemm_traffic uses tm=1,tn=32,tk=32,single tiling
    tiling = TilingConfig(
        tile_m=1, tile_n=32, tile_k=32, buffer_scheme=BufferScheme.SINGLE
    )

    # Tolerances (after correction factors)
    DRAM_TOLERANCE_PCT = 15.0  # ±15% (after INT8 + prefetch correction)
    TILE_TOLERANCE = 0  # exact match required

    for perf in perf_lines:
        gemm_name = perf.gemm_name.replace("_sim", "")
        if gemm_name not in GEMM_SHAPES:
            print(
                f"  {_color('SKIP', YELLOW)}: Unknown GEMM '{perf.gemm_name}' "
                f"(not in cross-validation shapes)"
            )
            continue

        shape = GEMM_SHAPES[gemm_name]
        analytical = compute_gemm_cost(shape, tiling, RTL_SIM_HW)
        if analytical is None:
            print(
                f"  {_color('ERROR', RED)}: Tiling does not fit in SRAM for {gemm_name}"
            )
            continue

        DRAM_BEAT_BYTES = 16
        rtl_dram_bytes = perf.dram_reads * DRAM_BEAT_BYTES
        analytical_tiles = (
            analytical.n_tiles_m * analytical.n_tiles_n * analytical.n_tiles_k
        )
        # Raw analytical DRAM (matches RTL data types via RTL_SIM_HW)
        raw_analytical_dram = analytical.dram_read_total
        # Corrected: prefetch engine amplifies DRAM reads by PREFETCH_DEPTH
        corrected_analytical_dram = raw_analytical_dram * RTL_PREFETCH_DEPTH

        # --- DRAM deviation (after correction) ---
        dram_dev = (
            (rtl_dram_bytes - corrected_analytical_dram)
            / corrected_analytical_dram
            * 100
            if corrected_analytical_dram > 0
            else 0
        )
        dram_pass = abs(dram_dev) <= DRAM_TOLERANCE_PCT

        # --- Tile count (exact match) ---
        tile_match = perf.tiles == analytical_tiles

        # --- Cycle count (informational — ratio only) ---
        cycle_ratio = (
            perf.cycles / analytical.total_cycles
            if analytical.total_cycles > 0
            else float("inf")
        )

        # Overall verdict: tile_count + corrected DRAM
        all_pass = dram_pass and tile_match
        verdict = _color("PASS", GREEN) if all_pass else _color("FAIL", RED)

        print(
            f"  {_color(gemm_name, BOLD)} [{shape.M}x{shape.N}x{shape.K}]  "
            f"Verdict: {verdict}"
        )
        print(
            f"  {'Metric':<22s}  {'RTL':>10s}  {'Analytical':>10s}  "
            f"{'Deviation':>10s}  {'Status'}"
        )
        print(f"  {'─' * 22}  {'─' * 10}  {'─' * 10}  {'─' * 10}  {'─' * 10}")

        t_status = _color("PASS", GREEN) if tile_match else _color("FAIL", RED)
        d_status = _color("PASS", GREEN) if dram_pass else _color("FAIL", RED)
        c_status = _color(f"{cycle_ratio:.1f}x", CYAN)

        print(
            f"  {'tile_count':<22s}  {perf.tiles:>10d}  "
            f"{analytical_tiles:>10d}  "
            f"{perf.tiles - analytical_tiles:>10d}  {t_status}"
        )
        print(
            f"  {'dram_bytes (corrected)':<22s}  {rtl_dram_bytes:>10d}  "
            f"{corrected_analytical_dram:>10d}  "
            f"{dram_dev:>+9.1f}%  {d_status}"
        )
        print(
            f"  {'cycle_count (info)':<22s}  {perf.cycles:>10d}  "
            f"{int(analytical.total_cycles):>10d}  "
            f"{'ratio':>10s}  {c_status}"
        )
        if not all_pass:
            print(
                f"    Note: DRAM analytical = {raw_analytical_dram} bytes "
                f"x {RTL_PREFETCH_DEPTH} (prefetch) = "
                f"{corrected_analytical_dram} bytes"
            )
        print()


# ─────────────────────────────────────────────────────────────────────────────
# Section 4: Analytical Model Sweep
# ─────────────────────────────────────────────────────────────────────────────


def print_analytical_sweep(
    model: ModelConfig,
    hw: HWConfig,
    mode: str,
    seq_len: int,
) -> Tuple[Optional[Dict[str, SweepResult]], Optional[Dict[str, SweepResult]]]:
    """Run analytical model sweep and print results."""
    print(_color("=" * 72, BOLD))
    print(
        _color("  Section 4: Analytical Model — Tiling Design Space Exploration", BOLD)
    )
    print(_color("=" * 72, BOLD))
    print()

    # Hardware summary
    print(f"  {_color('Hardware:', BOLD)}")
    print(
        f"    SRAM:    {hw.sram_total_bytes // 1024} KB ({hw.sram_num_banks} banks x {hw.sram_bank_bytes // 1024} KB)"
    )
    print(f"    DRAM:    {hw.dram_peak_bw_gbps} GB/s LPDDR5")
    print(
        f"    Compute: {hw.mac_array_m}x{hw.mac_array_n} MAC @ {hw.mac_freq_mhz} MHz = {hw.peak_gops:.0f} GOPS"
    )
    print()
    print(
        f"  {_color('Model:', BOLD)} {model.name} ({model.num_layers}L, h={model.hidden_size}, "
        f"q={model.num_q_heads}, kv={model.num_kv_heads}, ffn={model.intermediate_size})"
    )
    print()

    decode_results = None
    prefill_results = None

    if mode in ("decode", "both"):
        decode_results = _run_sweep_and_print(model, hw, seq_len=1, label="Decode")

    if mode in ("prefill", "both"):
        prefill_results = _run_sweep_and_print(
            model, hw, seq_len=seq_len, label=f"Prefill-{seq_len}"
        )

    # Decode vs Prefill summary
    if decode_results and prefill_results:
        _print_decode_vs_prefill(decode_results, prefill_results, model, hw)

    return decode_results, prefill_results


def _run_sweep_and_print(
    model: ModelConfig,
    hw: HWConfig,
    seq_len: int,
    label: str,
) -> Dict[str, SweepResult]:
    """Run sweep for one mode (decode or prefill) and print per-GEMM table."""
    print(f"  {_color(f'─── {label} (seq_len={seq_len}) ───', CYAN)}")
    print()

    gemms = get_layer_gemms(model, seq_len)
    t0 = time.time()
    results = sweep_all_layer_gemms(gemms, hw)
    elapsed = time.time() - t0
    total_configs = sum(len(r.all_costs) for r in results.values())

    print(f"  Swept {total_configs} configurations in {elapsed:.1f}s")
    print()

    # Per-GEMM summary table
    print(
        f"  {'GEMM':<20s}  {'Shape':<16s}  {'Baseline DRAM':>14s}  {'Best DRAM':>14s}  "
        f"{'Reduction':>10s}  {'BL Util':>8s}  {'Best Util':>9s}  {'Speedup':>8s}  {'Bound':>6s}"
    )
    print(
        f"  {'─' * 20}  {'─' * 16}  {'─' * 14}  {'─' * 14}  {'─' * 10}  {'─' * 8}  {'─' * 9}  {'─' * 8}  {'─' * 6}"
    )

    for name, r in results.items():
        bl = r.baseline_cost
        best = r.best_utilisation
        shape_str = f"{r.shape.M}x{r.shape.N}x{r.shape.K}"
        dram_red = (
            (1 - best.dram_total / bl.dram_total) * 100 if bl.dram_total > 0 else 0
        )
        speedup = bl.total_cycles / best.total_cycles if best.total_cycles > 0 else 0
        bound = "comp" if best.is_compute_bound else "mem"

        red_color = GREEN if dram_red > 0 else RED
        print(
            f"  {name:<20s}  {shape_str:<16s}  {fmt_bytes(bl.dram_total):>14s}  "
            f"{fmt_bytes(best.dram_total):>14s}  "
            f"{_color(f'{dram_red:+.1f}%', red_color):>21s}  "
            f"{bl.compute_utilisation * 100:>7.1f}%  {best.compute_utilisation * 100:>8.1f}%  "
            f"{speedup:>7.2f}x  {bound:>6s}"
        )

    # Best tiling configs
    print()
    print(f"  {_color('Best Tiling Configs:', BOLD)}")
    for name, r in results.items():
        t = r.best_utilisation.tiling
        print(
            f"    {name:<20s}  tm={t.tile_m:<4d}  tn={t.tile_n:<4d}  tk={t.tile_k:<4d}  {t.buffer_scheme.value}"
        )

    # Uniform vs per-GEMM
    comparison = compare_uniform_vs_per_gemm(results)
    print()
    print(
        f"  {_color('Uniform vs Per-GEMM Tiling:', BOLD)} ({model.num_layers} layers, full model)"
    )
    print(f"    {'Strategy':<20s}  {'DRAM':>14s}  {'Utilization':>12s}")
    print(f"    {'─' * 20}  {'─' * 14}  {'─' * 12}")
    print(
        f"    {'Uniform':<20s}  {fmt_bytes(comparison.uniform_dram * model.num_layers):>14s}  "
        f"{comparison.uniform_util * 100:>11.1f}%"
    )
    print(
        f"    {'Per-GEMM':<20s}  {fmt_bytes(comparison.per_gemm_dram * model.num_layers):>14s}  "
        f"{comparison.per_gemm_util * 100:>11.1f}%"
    )
    print(
        f"    Improvement:       {_color(f'{comparison.dram_reduction_pct:.1f}% DRAM reduction', GREEN)}, "
        f"{_color(f'+{comparison.util_improvement_pp:.1f} pp utilization', GREEN)}"
    )

    # Full model latency
    total_best_cycles = sum(r.best_utilisation.total_cycles for r in results.values())
    total_bl_cycles = sum(r.baseline_cost.total_cycles for r in results.values())
    layer_time_ms = total_best_cycles * hw.cycle_time_ns / 1e6
    model_time_ms = layer_time_ms * model.num_layers
    bl_model_time_ms = total_bl_cycles * hw.cycle_time_ns / 1e6 * model.num_layers

    print()
    print(f"  {_color('Full Model Latency:', BOLD)}")
    print(
        f"    Baseline:   {bl_model_time_ms:.2f} ms  ({model.num_layers} layers x {total_bl_cycles * hw.cycle_time_ns / 1e6:.2f} ms/layer)"
    )
    print(
        f"    Optimized:  {model_time_ms:.2f} ms  ({model.num_layers} layers x {layer_time_ms:.2f} ms/layer)"
    )
    overall_speedup = bl_model_time_ms / model_time_ms if model_time_ms > 0 else 0
    print(f"    Speedup:    {_color(f'{overall_speedup:.2f}x', CYAN)}")
    print()

    return results


def _print_decode_vs_prefill(
    decode_results: Dict[str, SweepResult],
    prefill_results: Dict[str, SweepResult],
    model: ModelConfig,
    hw: HWConfig,
):
    """Print decode vs prefill summary."""
    print(f"  {_color('─── Decode vs Prefill Summary ───', CYAN)}")
    print()
    print(
        f"  {'GEMM':<20s}  {'Dec Util':>9s}  {'Pre Util':>9s}  {'Dec DRAM':>12s}  {'Pre DRAM':>12s}  {'Dec Bound':>10s}  {'Pre Bound':>10s}"
    )
    print(
        f"  {'─' * 20}  {'─' * 9}  {'─' * 9}  {'─' * 12}  {'─' * 12}  {'─' * 10}  {'─' * 10}"
    )

    for name in decode_results:
        if name not in prefill_results:
            continue
        dr = decode_results[name].best_utilisation
        pr = prefill_results[name].best_utilisation
        d_bound = "comp" if dr.is_compute_bound else "mem"
        p_bound = "comp" if pr.is_compute_bound else "mem"
        print(
            f"  {name:<20s}  {dr.compute_utilisation * 100:>8.1f}%  "
            f"{pr.compute_utilisation * 100:>8.1f}%  "
            f"{fmt_bytes(dr.dram_total):>12s}  {fmt_bytes(pr.dram_total):>12s}  "
            f"{d_bound:>10s}  {p_bound:>10s}"
        )

    # Totals
    dec_total_cycles = sum(
        r.best_utilisation.total_cycles for r in decode_results.values()
    )
    pre_total_cycles = sum(
        r.best_utilisation.total_cycles for r in prefill_results.values()
    )
    dec_ms = dec_total_cycles * hw.cycle_time_ns / 1e6 * model.num_layers
    pre_ms = pre_total_cycles * hw.cycle_time_ns / 1e6 * model.num_layers
    print()
    print(
        f"  Full model latency:  Decode = {dec_ms:.2f} ms  |  Prefill = {pre_ms:.2f} ms"
    )
    print()


# ─────────────────────────────────────────────────────────────────────────────
# Matplotlib Charts
# ─────────────────────────────────────────────────────────────────────────────


def _ensure_output_dir():
    os.makedirs(OUTPUT_DIR, exist_ok=True)


def generate_charts(
    decode_results: Optional[Dict[str, SweepResult]],
    prefill_results: Optional[Dict[str, SweepResult]],
    sim_results: List[TestbenchResult],
    hw: HWConfig,
    model: ModelConfig,
):
    """Generate all matplotlib charts."""
    if not HAS_MPL:
        print(
            f"  {_color('[charts] matplotlib not available, skipping chart generation', YELLOW)}"
        )
        return

    _ensure_output_dir()
    charts_saved = []

    # 1. Pareto frontier plots
    for label, results in [("Decode", decode_results), ("Prefill", prefill_results)]:
        if results is None:
            continue
        for name, r in results.items():
            fname = f"dashboard_pareto_{label.lower()}_{name}.png"
            _plot_pareto(r, title_suffix=label, filename=fname)
            charts_saved.append(fname)

    # 2. Layer comparison (baseline vs optimized)
    for label, results in [("Decode", decode_results), ("Prefill", prefill_results)]:
        if results is None:
            continue
        fname = f"dashboard_layer_comparison_{label.lower()}.png"
        _plot_layer_comparison(results, title_suffix=label, filename=fname)
        charts_saved.append(fname)

    # 3. Uniform vs per-GEMM comparison
    for label, results in [("Decode", decode_results), ("Prefill", prefill_results)]:
        if results is None:
            continue
        comp = compare_uniform_vs_per_gemm(results)
        fname = f"dashboard_uniform_vs_pergemm_{label.lower()}.png"
        _plot_uniform_vs_per_gemm(
            comp, model.num_layers, title_suffix=label, filename=fname
        )
        charts_saved.append(fname)

    # 4. Decode vs Prefill
    if decode_results and prefill_results:
        fname = "dashboard_decode_vs_prefill.png"
        _plot_decode_vs_prefill(decode_results, prefill_results, filename=fname)
        charts_saved.append(fname)

    # 5. RTL comparison chart (if sim data available)
    comp_results = [r for r in sim_results if r.comparison is not None]
    if comp_results:
        fname = "dashboard_rtl_baseline_vs_optimized.png"
        _plot_rtl_comparison(comp_results[0], filename=fname)
        charts_saved.append(fname)

    # 6. Cross-validation chart
    perf_lines = []
    for r in sim_results:
        perf_lines.extend(r.perf_lines)
    if perf_lines:
        fname = "dashboard_cross_validation.png"
        _plot_cross_validation(perf_lines, hw, filename=fname)
        charts_saved.append(fname)

    print(_color("=" * 72, BOLD))
    print(_color(f"  Charts saved to {OUTPUT_DIR}/", BOLD))
    print(_color("=" * 72, BOLD))
    for f in charts_saved:
        print(f"    {f}")
    print()


def _plot_pareto(result: SweepResult, title_suffix: str, filename: str):
    """Pareto frontier scatter plot."""
    fig, ax = plt.subplots(figsize=(10, 7))

    scheme_colors = {
        "single": "#aaaaaa",
        "double_b": "#4c72b0",
        "double_a": "#dd8452",
        "double_ab": "#55a868",
    }
    for c in result.all_costs:
        scheme = c.tiling.buffer_scheme.value
        color = scheme_colors.get(scheme, "#999999")
        ax.scatter(
            c.dram_total / 1e6, c.compute_utilisation * 100, c=color, alpha=0.2, s=10
        )

    # Legend entries (empty scatter for legend)
    for scheme, color in scheme_colors.items():
        ax.scatter([], [], c=color, alpha=0.6, s=30, label=scheme)

    pareto_dram = [c.dram_total / 1e6 for c in result.pareto_costs]
    pareto_util = [c.compute_utilisation * 100 for c in result.pareto_costs]
    ax.plot(
        pareto_dram,
        pareto_util,
        "r-o",
        markersize=5,
        linewidth=1.5,
        label="Pareto frontier",
        zorder=5,
    )

    bl = result.baseline_cost
    ax.scatter(
        [bl.dram_total / 1e6],
        [bl.compute_utilisation * 100],
        marker="X",
        s=150,
        c="black",
        zorder=10,
        label="Baseline",
    )

    ax.set_xlabel("Total DRAM Traffic (MB)")
    ax.set_ylabel("Compute Utilisation (%)")
    ax.set_title(
        f"Pareto: {result.shape.name} [{result.shape.M}x{result.shape.N}x{result.shape.K}]"
        + (f"  ({title_suffix})" if title_suffix else "")
    )
    ax.legend(fontsize=8, loc="lower right")
    ax.grid(True, alpha=0.3)
    ax.set_xlim(left=0)
    ax.set_ylim(bottom=0)

    fig.tight_layout()
    path = os.path.join(OUTPUT_DIR, filename)
    fig.savefig(path, dpi=150)
    plt.close(fig)


def _plot_layer_comparison(
    results: Dict[str, SweepResult], title_suffix: str, filename: str
):
    """Baseline vs best per-GEMM bar chart."""
    names = list(results.keys())
    baseline_dram = [r.baseline_cost.dram_total / 1e6 for r in results.values()]
    best_dram = [r.best_utilisation.dram_total / 1e6 for r in results.values()]
    baseline_util = [
        r.baseline_cost.compute_utilisation * 100 for r in results.values()
    ]
    best_util = [r.best_utilisation.compute_utilisation * 100 for r in results.values()]

    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))
    x = range(len(names))
    w = 0.35

    ax1.bar([i - w / 2 for i in x], baseline_dram, w, label="Baseline", color="#d66")
    ax1.bar([i + w / 2 for i in x], best_dram, w, label="Best Pareto", color="#6b6")
    ax1.set_xticks(list(x))
    ax1.set_xticklabels(names, rotation=45, ha="right", fontsize=8)
    ax1.set_ylabel("DRAM Traffic (MB)")
    ax1.set_title("DRAM Traffic: Baseline vs Optimised")
    ax1.legend()
    ax1.grid(axis="y", alpha=0.3)

    ax2.bar([i - w / 2 for i in x], baseline_util, w, label="Baseline", color="#d66")
    ax2.bar([i + w / 2 for i in x], best_util, w, label="Best Pareto", color="#6b6")
    ax2.set_xticks(list(x))
    ax2.set_xticklabels(names, rotation=45, ha="right", fontsize=8)
    ax2.set_ylabel("Compute Utilisation (%)")
    ax2.set_title("Compute Utilisation: Baseline vs Optimised")
    ax2.legend()
    ax2.grid(axis="y", alpha=0.3)

    fig.suptitle(f"Per-GEMM Comparison ({title_suffix})", fontsize=13)
    fig.tight_layout()
    path = os.path.join(OUTPUT_DIR, filename)
    fig.savefig(path, dpi=150)
    plt.close(fig)


def _plot_uniform_vs_per_gemm(
    comparison, num_layers: int, title_suffix: str, filename: str
):
    """Uniform vs per-GEMM tiling bar chart."""
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(10, 5))

    categories = ["Uniform\nTiling", "Per-GEMM\nTiling"]
    dram_vals = [
        comparison.uniform_dram * num_layers / 1e9,
        comparison.per_gemm_dram * num_layers / 1e9,
    ]
    bars1 = ax1.bar(categories, dram_vals, color=["#d66", "#6b6"], width=0.5)
    ax1.set_ylabel("Total DRAM Traffic (GB)")
    ax1.set_title("Full Model DRAM Traffic")
    ax1.grid(axis="y", alpha=0.3)
    for bar, val in zip(bars1, dram_vals):
        ax1.text(
            bar.get_x() + bar.get_width() / 2,
            bar.get_height() + 0.01,
            f"{val:.2f} GB",
            ha="center",
            va="bottom",
            fontsize=10,
        )

    util_vals = [comparison.uniform_util * 100, comparison.per_gemm_util * 100]
    bars2 = ax2.bar(categories, util_vals, color=["#d66", "#6b6"], width=0.5)
    ax2.set_ylabel("Avg Compute Utilisation (%)")
    ax2.set_title("Full Model Utilisation")
    ax2.set_ylim(0, 100)
    ax2.grid(axis="y", alpha=0.3)
    for bar, val in zip(bars2, util_vals):
        ax2.text(
            bar.get_x() + bar.get_width() / 2,
            bar.get_height() + 1,
            f"{val:.1f}%",
            ha="center",
            va="bottom",
            fontsize=10,
        )

    fig.suptitle(
        f"Uniform vs Per-GEMM Tiling ({num_layers} layers, {title_suffix})", fontsize=13
    )
    fig.tight_layout()
    path = os.path.join(OUTPUT_DIR, filename)
    fig.savefig(path, dpi=150)
    plt.close(fig)


def _plot_decode_vs_prefill(
    decode_results: Dict[str, SweepResult],
    prefill_results: Dict[str, SweepResult],
    filename: str,
):
    """Decode vs Prefill comparison."""
    names = list(decode_results.keys())
    dec_util = [
        r.best_utilisation.compute_utilisation * 100 for r in decode_results.values()
    ]
    pre_util = [
        r.best_utilisation.compute_utilisation * 100 for r in prefill_results.values()
    ]
    dec_dram = [r.best_utilisation.dram_total / 1e6 for r in decode_results.values()]
    pre_dram = [r.best_utilisation.dram_total / 1e6 for r in prefill_results.values()]

    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))
    x = range(len(names))
    w = 0.35

    ax1.bar([i - w / 2 for i in x], dec_util, w, label="Decode (M=1)", color="#4c72b0")
    ax1.bar(
        [i + w / 2 for i in x], pre_util, w, label="Prefill (M=256)", color="#dd8452"
    )
    ax1.set_xticks(list(x))
    ax1.set_xticklabels(names, rotation=45, ha="right", fontsize=8)
    ax1.set_ylabel("Best Compute Utilisation (%)")
    ax1.set_title("Decode vs Prefill: Utilisation")
    ax1.legend()
    ax1.grid(axis="y", alpha=0.3)

    ax2.bar([i - w / 2 for i in x], dec_dram, w, label="Decode (M=1)", color="#4c72b0")
    ax2.bar(
        [i + w / 2 for i in x], pre_dram, w, label="Prefill (M=256)", color="#dd8452"
    )
    ax2.set_xticks(list(x))
    ax2.set_xticklabels(names, rotation=45, ha="right", fontsize=8)
    ax2.set_ylabel("DRAM Traffic (MB)")
    ax2.set_title("Decode vs Prefill: DRAM Traffic")
    ax2.legend()
    ax2.grid(axis="y", alpha=0.3)

    fig.suptitle("Decode vs Prefill Comparison (Best Pareto Points)", fontsize=13)
    fig.tight_layout()
    path = os.path.join(OUTPUT_DIR, filename)
    fig.savefig(path, dpi=150)
    plt.close(fig)


def _plot_rtl_comparison(result: TestbenchResult, filename: str):
    """RTL baseline vs optimized bar chart from simulation data."""
    comp = result.comparison
    if comp is None:
        return

    bl, opt = comp.baseline, comp.optimized

    fig, axes = plt.subplots(1, 3, figsize=(15, 5))

    # Cycles
    categories = ["Baseline", "Optimized"]
    axes[0].bar(
        categories,
        [bl.total_cycles, opt.total_cycles],
        color=["#d66", "#6b6"],
        width=0.5,
    )
    axes[0].set_ylabel("Cycles")
    axes[0].set_title("Total Cycles")
    axes[0].grid(axis="y", alpha=0.3)
    for i, v in enumerate([bl.total_cycles, opt.total_cycles]):
        axes[0].text(i, v + v * 0.02, str(v), ha="center", va="bottom", fontsize=9)

    # DRAM reads
    axes[1].bar(
        categories,
        [bl.dram_read_beats, opt.dram_read_beats],
        color=["#d66", "#6b6"],
        width=0.5,
    )
    axes[1].set_ylabel("Beats")
    axes[1].set_title("DRAM Read Beats")
    axes[1].grid(axis="y", alpha=0.3)
    for i, v in enumerate([bl.dram_read_beats, opt.dram_read_beats]):
        axes[1].text(i, v + v * 0.02, str(v), ha="center", va="bottom", fontsize=9)

    # Idle cycles
    axes[2].bar(
        categories, [bl.idle_cycles, opt.idle_cycles], color=["#d66", "#6b6"], width=0.5
    )
    axes[2].set_ylabel("Cycles")
    axes[2].set_title("Idle Cycles")
    axes[2].grid(axis="y", alpha=0.3)
    for i, v in enumerate([bl.idle_cycles, opt.idle_cycles]):
        axes[2].text(i, v + v * 0.02, str(v), ha="center", va="bottom", fontsize=9)

    speedup_str = f"{comp.speedup:.2f}x" if comp.speedup > 0 else "N/A"
    fig.suptitle(
        f"RTL Simulation: Baseline vs Optimized (Speedup: {speedup_str})", fontsize=13
    )
    fig.tight_layout()
    path = os.path.join(OUTPUT_DIR, filename)
    fig.savefig(path, dpi=150)
    plt.close(fig)


def _plot_cross_validation(perf_lines: List[GEMMPerfLine], hw: HWConfig, filename: str):
    """Cross-validation: RTL vs corrected analytical model bar chart."""
    tiling = TilingConfig(
        tile_m=1, tile_n=32, tile_k=32, buffer_scheme=BufferScheme.SINGLE
    )
    DRAM_BEAT_BYTES = 16

    seen: set = set()
    gemm_names = []
    rtl_dram_list = []
    ana_dram_list = []
    rtl_tiles_list = []
    ana_tiles_list = []

    for perf in perf_lines:
        gemm_name = perf.gemm_name.replace("_sim", "")
        if gemm_name not in GEMM_SHAPES or gemm_name in seen:
            continue
        seen.add(gemm_name)
        shape = GEMM_SHAPES[gemm_name]
        analytical = compute_gemm_cost(shape, tiling, RTL_SIM_HW)
        if analytical is None:
            continue

        analytical_tiles = (
            analytical.n_tiles_m * analytical.n_tiles_n * analytical.n_tiles_k
        )
        corrected_dram = analytical.dram_read_total * RTL_PREFETCH_DEPTH

        gemm_names.append(gemm_name)
        rtl_dram_list.append(perf.dram_reads * DRAM_BEAT_BYTES)
        ana_dram_list.append(corrected_dram)
        rtl_tiles_list.append(perf.tiles)
        ana_tiles_list.append(analytical_tiles)

    if not gemm_names:
        return

    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))
    x = range(len(gemm_names))
    w = 0.35

    ax1.bar([i - w / 2 for i in x], rtl_tiles_list, w, label="RTL", color="#4c72b0")
    ax1.bar(
        [i + w / 2 for i in x], ana_tiles_list, w, label="Analytical", color="#dd8452"
    )
    ax1.set_xticks(list(x))
    ax1.set_xticklabels(gemm_names, rotation=45, ha="right", fontsize=8)
    ax1.set_ylabel("Tile Count")
    ax1.set_title("Tile Count: RTL vs Analytical (exact match)")
    ax1.legend()
    ax1.grid(axis="y", alpha=0.3)

    ax2.bar([i - w / 2 for i in x], rtl_dram_list, w, label="RTL", color="#4c72b0")
    ax2.bar(
        [i + w / 2 for i in x],
        ana_dram_list,
        w,
        label=f"Analytical (x{RTL_PREFETCH_DEPTH} prefetch)",
        color="#dd8452",
    )
    ax2.set_xticks(list(x))
    ax2.set_xticklabels(gemm_names, rotation=45, ha="right", fontsize=8)
    ax2.set_ylabel("DRAM Read Bytes")
    ax2.set_title("DRAM Reads: RTL vs Corrected Analytical")
    ax2.legend()
    ax2.grid(axis="y", alpha=0.3)

    fig.suptitle(
        "Cross-Validation: RTL vs Analytical (INT8, prefetch-corrected)",
        fontsize=13,
    )
    fig.tight_layout()
    path = os.path.join(OUTPUT_DIR, filename)
    fig.savefig(path, dpi=150)
    plt.close(fig)


# ─────────────────────────────────────────────────────────────────────────────
# Main
# ─────────────────────────────────────────────────────────────────────────────


def main():
    parser = argparse.ArgumentParser(
        description="Unified Dashboard for LLM Memory Controller Results",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""\
Examples:
    # Analytical model only (no simulation data)
    uv run dashboard.py

    # With simulation logs
    uv run dashboard.py --logs tb1.log tb2.log tb3.log

    # Decode analysis only
    uv run dashboard.py --mode decode

    # Prefill with custom sequence length
    uv run dashboard.py --mode prefill --seq-len 512
""",
    )
    parser.add_argument(
        "--logs",
        nargs="+",
        metavar="FILE",
        help="Simulation log files from Cognichip ACI (stdout captured to file)",
    )
    parser.add_argument(
        "--mode",
        choices=["decode", "prefill", "both"],
        default="both",
        help="Analysis mode (default: both)",
    )
    parser.add_argument(
        "--seq-len",
        type=int,
        default=256,
        help="Prefill sequence length (default: 256)",
    )
    parser.add_argument(
        "--no-charts",
        action="store_true",
        help="Skip matplotlib chart generation",
    )
    args = parser.parse_args()

    model = QWEN3_8B
    hw = DEFAULT_HW

    # ── Banner ──
    print()
    print(
        _color(
            "╔══════════════════════════════════════════════════════════════════════╗",
            BOLD,
        )
    )
    print(
        _color(
            "║          LLM Memory Controller — Unified Results Dashboard         ║",
            BOLD,
        )
    )
    print(
        _color(
            "╚══════════════════════════════════════════════════════════════════════╝",
            BOLD,
        )
    )
    print()

    # ── Section 1: Parse simulation logs ──
    sim_results: List[TestbenchResult] = []
    if args.logs:
        for log_path in args.logs:
            if not os.path.isfile(log_path):
                print(f"  {_color('WARNING', YELLOW)}: Log file not found: {log_path}")
                continue
            result = parse_log_file(log_path)
            sim_results.append(result)

    print_testbench_status(sim_results)

    # ── Section 2: Baseline vs Optimized ──
    print_comparison(sim_results)

    # ── Section 3: Cross-Validation ──
    print_cross_validation(sim_results, hw)

    # ── Section 4: Analytical Model ──
    decode_results, prefill_results = print_analytical_sweep(
        model, hw, args.mode, args.seq_len
    )

    # ── Charts ──
    if not args.no_charts:
        generate_charts(decode_results, prefill_results, sim_results, hw, model)

    print(_color("Done.", BOLD))


if __name__ == "__main__":
    main()
