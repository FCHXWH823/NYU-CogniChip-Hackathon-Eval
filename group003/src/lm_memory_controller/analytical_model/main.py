#!/usr/bin/env python3
"""
LLM Memory Controller — Analytical Performance Model

Sweeps tiling configurations for each GEMM in a Transformer layer,
generates Pareto frontiers (DRAM traffic vs compute utilisation),
and compares baseline vs optimised strategies.

Usage:
    python main.py                          # default: Qwen3-8B, decode + prefill
    python main.py --seq-len 512            # custom prefill length
    python main.py --mode decode            # decode only
"""

from __future__ import annotations

import argparse
import sys
import time

from config import QWEN3_8B, DEFAULT_HW, ModelConfig, HWConfig
from cost_model import GEMMCost
from layer_model import get_layer_gemms, ModelCost, LayerCost, compute_layer_cost
from sweep import (
    sweep_gemm,
    sweep_all_layer_gemms,
    compare_uniform_vs_per_gemm,
    SweepResult,
)
from plot import (
    plot_pareto,
    plot_layer_comparison,
    plot_uniform_vs_per_gemm,
    plot_prefill_vs_decode_summary,
)


def fmt_bytes(b: int) -> str:
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
    return f"{c / 1e3:.1f}K cyc ({time_us:.1f} us)"


def print_header(model: ModelConfig, hw: HWConfig):
    print("=" * 72)
    print("  LLM Memory Controller — Analytical Performance Model")
    print("=" * 72)
    print(
        f"  Model  : {model.name} ({model.num_layers}L, h={model.hidden_size}, "
        f"q={model.num_q_heads}, kv={model.num_kv_heads}, ffn={model.intermediate_size})"
    )
    print(f"  Quant  : INT4 weights, INT8 activations")
    print(
        f"  SRAM   : {hw.sram_total_bytes // 1024} KB "
        f"({hw.sram_num_banks} banks x {hw.sram_bank_bytes // 1024} KB)"
    )
    print(
        f"  DRAM   : {hw.dram_peak_bw_gbps} GB/s LPDDR5 "
        f"(hit={hw.dram_page_hit_latency_ns}ns, miss={hw.dram_page_miss_latency_ns}ns)"
    )
    print(
        f"  Compute: {hw.mac_array_m}x{hw.mac_array_n} MAC @ {hw.mac_freq_mhz} MHz "
        f"= {hw.peak_gops:.0f} GOPS peak"
    )
    print("=" * 72)


def print_gemm_summary(result: SweepResult, hw: HWConfig = DEFAULT_HW):
    shape = result.shape
    bl = result.baseline_cost
    best = result.best_utilisation

    print(
        f"\n  {shape.name}  [{shape.M} x {shape.N} x {shape.K}]  "
        f"({shape.total_macs / 1e6:.1f}M MACs)"
    )
    print(f"    {'':30s} {'DRAM':>12s}  {'Cycles':>20s}  {'Util':>6s}  {'Bound':>8s}")
    print(
        f"    {'Baseline':30s} {fmt_bytes(bl.dram_total):>12s}  "
        f"{fmt_cycles(bl.total_cycles, hw):>20s}  "
        f"{bl.compute_utilisation * 100:5.1f}%  "
        f"{'comp' if bl.is_compute_bound else 'mem':>8s}"
    )

    t = best.tiling
    label = f"Best (tm={t.tile_m},tn={t.tile_n},tk={t.tile_k},{t.buffer_scheme.value})"
    print(
        f"    {label:30s} {fmt_bytes(best.dram_total):>12s}  "
        f"{fmt_cycles(best.total_cycles, hw):>20s}  "
        f"{best.compute_utilisation * 100:5.1f}%  "
        f"{'comp' if best.is_compute_bound else 'mem':>8s}"
    )

    dram_red = (1 - best.dram_total / bl.dram_total) * 100 if bl.dram_total > 0 else 0
    speedup = bl.total_cycles / best.total_cycles if best.total_cycles > 0 else 0
    print(
        f"    -> DRAM reduction: {dram_red:+.1f}%  |  Speedup: {speedup:.2f}x  |  "
        f"Configs explored: {len(result.all_costs)}"
    )


def run_analysis(
    model: ModelConfig,
    hw: HWConfig,
    seq_len: int,
    mode_label: str,
):
    print(f"\n{'─' * 72}")
    print(f"  {mode_label} Analysis  (seq_len = {seq_len})")
    print(f"{'─' * 72}")

    gemms = get_layer_gemms(model, seq_len)
    t0 = time.time()
    results = sweep_all_layer_gemms(gemms, hw)
    elapsed = time.time() - t0
    total_configs = sum(len(r.all_costs) for r in results.values())
    print(f"\n  Sweep: {total_configs} valid configurations in {elapsed:.1f}s")

    for r in results.values():
        print_gemm_summary(r, hw)

    print(f"\n  --- Pareto Plots ---")
    for r in results.values():
        plot_pareto(
            r,
            title_suffix=mode_label,
            filename=f"pareto_{mode_label.lower()}_{r.shape.name}.png",
        )

    plot_layer_comparison(
        results,
        title_suffix=mode_label,
        filename=f"layer_comparison_{mode_label.lower()}.png",
    )

    comparison = compare_uniform_vs_per_gemm(results)
    print(f"\n  --- Uniform vs Per-GEMM Tiling ({model.num_layers} layers) ---")
    print(
        f"    Uniform  : DRAM={fmt_bytes(comparison.uniform_dram * model.num_layers)}, "
        f"Util={comparison.uniform_util * 100:.1f}%"
    )
    print(
        f"    Per-GEMM : DRAM={fmt_bytes(comparison.per_gemm_dram * model.num_layers)}, "
        f"Util={comparison.per_gemm_util * 100:.1f}%"
    )
    print(
        f"    Improvement: {comparison.dram_reduction_pct:.1f}% DRAM reduction, "
        f"+{comparison.util_improvement_pp:.1f} pp utilisation"
    )

    plot_uniform_vs_per_gemm(
        comparison,
        model.num_layers,
        title_suffix=mode_label,
        filename=f"uniform_vs_pergemm_{mode_label.lower()}.png",
    )

    return results


def main():
    parser = argparse.ArgumentParser(
        description="LLM Memory Controller Analytical Model"
    )
    parser.add_argument("--mode", choices=["decode", "prefill", "both"], default="both")
    parser.add_argument(
        "--seq-len",
        type=int,
        default=256,
        help="Prefill sequence length (default: 256)",
    )
    args = parser.parse_args()

    model = QWEN3_8B
    hw = DEFAULT_HW
    print_header(model, hw)

    decode_results = None
    prefill_results = None

    if args.mode in ("decode", "both"):
        decode_results = run_analysis(model, hw, seq_len=1, mode_label="Decode")

    if args.mode in ("prefill", "both"):
        prefill_results = run_analysis(
            model, hw, seq_len=args.seq_len, mode_label=f"Prefill-{args.seq_len}"
        )

    if decode_results and prefill_results:
        print(f"\n{'─' * 72}")
        print(f"  Decode vs Prefill Summary")
        print(f"{'─' * 72}")
        plot_prefill_vs_decode_summary(decode_results, prefill_results)

    print(f"\n{'=' * 72}")
    print(f"  Done. Figures saved to analytical_model/figures/")
    print(f"{'=' * 72}")


if __name__ == "__main__":
    main()
