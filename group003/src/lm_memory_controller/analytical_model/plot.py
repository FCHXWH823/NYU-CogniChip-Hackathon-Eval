"""Visualization for analytical model results."""

from __future__ import annotations

from typing import List, Dict, Optional
import os

from cost_model import GEMMCost
from sweep import SweepResult, UniformVsPerGemmComparison

try:
    import matplotlib

    matplotlib.use("Agg")
    import matplotlib.pyplot as plt
    import matplotlib.ticker as mticker

    HAS_MPL = True
except ImportError:
    HAS_MPL = False


OUTPUT_DIR = os.path.join(os.path.dirname(__file__), "figures")


def _ensure_output_dir():
    os.makedirs(OUTPUT_DIR, exist_ok=True)


def plot_pareto(
    result: SweepResult,
    title_suffix: str = "",
    filename: Optional[str] = None,
):
    if not HAS_MPL:
        print("[plot] matplotlib not available, skipping plot")
        return
    _ensure_output_dir()

    fig, ax = plt.subplots(figsize=(10, 7))

    dram_all = [c.dram_total / 1e6 for c in result.all_costs]
    util_all = [c.compute_utilisation * 100 for c in result.all_costs]
    scheme_all = [c.tiling.buffer_scheme.value for c in result.all_costs]

    scheme_colors = {
        "single": "#aaaaaa",
        "double_b": "#4c72b0",
        "double_a": "#dd8452",
        "double_ab": "#55a868",
    }
    for scheme, color in scheme_colors.items():
        xs = [d for d, s in zip(dram_all, scheme_all) if s == scheme]
        ys = [u for u, s in zip(util_all, scheme_all) if s == scheme]
        if xs:
            ax.scatter(xs, ys, c=color, alpha=0.25, s=12, label=scheme)

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
        f"Pareto: {result.shape.name}  [{result.shape.M}x{result.shape.N}x{result.shape.K}]"
        + (f"  ({title_suffix})" if title_suffix else "")
    )
    ax.legend(fontsize=8, loc="lower right")
    ax.grid(True, alpha=0.3)
    ax.set_xlim(left=0)
    ax.set_ylim(bottom=0)

    fname = filename or f"pareto_{result.shape.name}.png"
    path = os.path.join(OUTPUT_DIR, fname)
    fig.tight_layout()
    fig.savefig(path, dpi=150)
    plt.close(fig)
    print(f"  Saved: {path}")


def plot_layer_comparison(
    sweep_results: Dict[str, SweepResult],
    title_suffix: str = "",
    filename: str = "layer_comparison.png",
):
    if not HAS_MPL:
        print("[plot] matplotlib not available, skipping plot")
        return
    _ensure_output_dir()

    names = list(sweep_results.keys())
    baseline_dram = [r.baseline_cost.dram_total / 1e6 for r in sweep_results.values()]
    best_dram = [r.best_utilisation.dram_total / 1e6 for r in sweep_results.values()]
    baseline_util = [
        r.baseline_cost.compute_utilisation * 100 for r in sweep_results.values()
    ]
    best_util = [
        r.best_utilisation.compute_utilisation * 100 for r in sweep_results.values()
    ]

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

    fig.suptitle(
        f"Per-GEMM Comparison" + (f"  ({title_suffix})" if title_suffix else ""),
        fontsize=13,
    )
    fig.tight_layout()
    path = os.path.join(OUTPUT_DIR, filename)
    fig.savefig(path, dpi=150)
    plt.close(fig)
    print(f"  Saved: {path}")


def plot_uniform_vs_per_gemm(
    comparison: UniformVsPerGemmComparison,
    num_layers: int,
    title_suffix: str = "",
    filename: str = "uniform_vs_per_gemm.png",
):
    if not HAS_MPL:
        print("[plot] matplotlib not available, skipping plot")
        return
    _ensure_output_dir()

    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(10, 5))

    categories = ["Uniform\nTiling", "Per-GEMM\nTiling"]

    dram_vals = [
        comparison.uniform_dram * num_layers / 1e9,
        comparison.per_gemm_dram * num_layers / 1e9,
    ]
    colors_dram = ["#d66", "#6b6"]
    bars1 = ax1.bar(categories, dram_vals, color=colors_dram, width=0.5)
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
    colors_util = ["#d66", "#6b6"]
    bars2 = ax2.bar(categories, util_vals, color=colors_util, width=0.5)
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
        f"Uniform vs Per-GEMM Tiling ({num_layers} layers)"
        + (f"  ({title_suffix})" if title_suffix else ""),
        fontsize=13,
    )
    fig.tight_layout()
    path = os.path.join(OUTPUT_DIR, filename)
    fig.savefig(path, dpi=150)
    plt.close(fig)
    print(f"  Saved: {path}")


def plot_prefill_vs_decode_summary(
    decode_results: Dict[str, SweepResult],
    prefill_results: Dict[str, SweepResult],
    filename: str = "prefill_vs_decode.png",
):
    if not HAS_MPL:
        print("[plot] matplotlib not available, skipping plot")
        return
    _ensure_output_dir()

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
    print(f"  Saved: {path}")
