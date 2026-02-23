# `lm_memory_controller`

A LLM4ChipDesign challenge for Cognichip Hackathon 2026.

## Analytical Model

To run the project, you should have `uv` installed. After that you can use the following command to run the project

```bash
uv run main.py
```

and the required dependencies will be automatically installed in an isolated environment.

### Dashboard

A unified results dashboard (`dashboard.py`) combines simulation log parsing, analytical model sweep, and cross-validation into a single view with terminal tables and matplotlib charts.

```bash
# Analytical model only (no simulation data needed)
uv run dashboard.py

# With simulation logs from the Cognichip Platform
uv run dashboard.py --logs tb_llm.log tb_gemm.log tb_comp.log

# Decode-only analysis, skip chart generation
uv run dashboard.py --mode decode --no-charts

# Prefill with custom sequence length
uv run dashboard.py --mode prefill --seq-len 512
```

**Sections:**
1. **RTL Testbench Status** — Parses log files for PASS/FAIL results
2. **Baseline vs Optimized** — Extracts performance comparison from `tb_llm_memory_controller_comparison` logs
3. **Cross-Validation** — Compares RTL PERF output against analytical model predictions
4. **Analytical Sweep** — Full tiling design space exploration with Pareto frontier, per-GEMM best configs, uniform vs per-GEMM comparison, and full-model latency

Charts are saved to `analytical_model/figures/`.

## Controller RTL Implementation

To run simulation and synthesis, Cognichip platform is recommended.

## Architecture

The controller consists of 4 main modules coordinating GEMM tiling, DRAM prefetching, and SRAM bank arbitration for memory-bound Transformer inference on edge SoCs (2 MB SRAM, 50 GB/s LPDDR5 DRAM, INT4/INT8 quantized models). See [ARCHITECTURE.md](ARCHITECTURE.md) for detailed block diagrams, FSM states, and pipeline datapath.

**Key Modules:**
- **Config Registers**: APB-like interface for software configuration (matrix dimensions, tiling parameters, DRAM/SRAM base addresses, buffering modes)
- **Tile Scheduler**: 9-state FSM orchestrating tile-level data movement and compute dispatch
- **DRAM Prefetch Engine**: 10-state FSM with request queue, negedge skid capture, and AXI-like split read/write channels
- **SRAM Bank Arbiter**: 8-bank round-robin arbiter with 3-stage read pipeline (2-cycle latency)

## Cross-Validation Results

The analytical cost model predictions are cross-validated against the RTL implementation using the `tb_gemm_traffic` testbench. The testbench replays representative GEMM shapes with parseable PERF output, which is then compared against `compute_gemm_cost()` predictions.

**Validation Script:** `analytical_model/cross_validate.py`

**Tolerance Thresholds:**
- **Cycle count:** ±15% (accounts for pipeline startup/flush overhead not modeled in analytical steady-state equations)
- **DRAM bytes:** ±5% (allows for DRAM alignment effects and prefetch queue behavior)
- **Tile count:** Exact match

**Usage:**
```bash
# Run GEMM traffic testbench on Cognichip ACI
# Then extract PERF line and validate
grep "PERF:" perf_output.txt | uv run analytical_model/cross_validate.py --rtl-log - --gemm attn_q_proj_sim --tiling tm=32,tn=32,tk=32,single
```

## Dynamic Per-Layer Reconfiguration

The controller implements a **4-entry preset table** (16 registers at 0x60-0x9C) storing pre-configured tiling parameters and SRAM base addresses. This enables switching tiling strategies per layer (e.g., attention vs FFN) without software overhead.

**Address Map (New Registers):**
- **Preset 0:** 0x60-0x6C (tiling, sram_ab, sram_bc, sram_bp)
- **Preset 1:** 0x70-0x7C
- **Preset 2:** 0x80-0x8C
- **Preset 3:** 0x90-0x9C
- **Control:** 0xA0 (preset_sel), 0xA4 (enable), 0xA8 (count, read-only)

**Trigger Mechanism:**  
On each GEMM completion (`sched_done` pulse), if `reconfig_enable=1` and `!busy`, the controller automatically loads the next preset, increments the selector (with wrap-around), and increments a reconfiguration counter. Reconfiguration completes in 1 cycle (combinational load).

**Use Case:**  
Software programs all 4 presets once during initialization:
1. **Preset 0:** Attention Q/K/V tiling (tile_m=8, tile_n=64, tile_k=32, mode=3)
2. **Preset 1:** FFN up/gate tiling (tile_m=32, tile_n=32, tile_k=16, mode=1)
3. **Preset 2:** Attention O projection (tile_m=16, tile_n=64, tile_k=32, mode=2)
4. **Preset 3:** FFN down projection (tile_m=64, tile_n=16, tile_k=32, mode=0)

Then enable auto-reconfiguration (`0xA4 = 1`). The controller cycles through presets automatically, eliminating per-layer register write overhead.

**Backward Compatibility:** When `reconfig_enable=0` (default), the controller behaves identically to the original design (manual writes to 0x00-0x3F registers). START remains software-controlled in both modes.

## Simulation

All testbenches are verified on **Cognichip ACI** using Verilator. All testbenches follow Verilator-safe timing conventions (`@(posedge clk); #1;` + blocking assignments in tasks).

**Testbench Targets:**
1. **tb_config_regs** — Config register interface (10 tests: register read/write, control pulse, status readback, perf counters, dynamic reconfig registers)
2. **tb_tile_scheduler** — Tile scheduler FSM (6 tests: single tile, multi-tile GEMM, buffering mode variations)
3. **tb_dram_prefetch_engine** — DRAM prefetch engine with negedge skid capture (7 tests: request queue, A/B/C fetch, prefetch depth)
4. **tb_sram_bank_arbiter** — SRAM bank arbiter with 3-stage read pipeline (comprehensive test: 8-bank arbitration, simultaneous prefetch+compute access)
5. **tb_llm_memory_controller** — Top-level integration (4 test scenarios: single tile flow, 4-tile sequence, perf counter validation, writeback datapath)
6. **tb_gemm_traffic** — GEMM traffic replay with PERF output for cross-validation (attn_q_proj_sim: M=1, N=128, K=128)
7. **tb_dynamic_reconfig** — Dynamic reconfiguration (5 test scenarios: preset write/read, single trigger, sequential 4-cycle, guard conditions, backward compatibility)

## Performance Results

See [analytical_model/FINDINGS.md](analytical_model/FINDINGS.md) for detailed performance analysis, tiling tradeoffs, and Pareto frontier plots.

**Key Highlights:**
- **Decode (M=1):** 3.1% MAC utilization, 56.7 ms full-model latency (36 layers), memory-bound due to array shape mismatch
- **Prefill (M=256):** 99.7% MAC utilization, 674 ms latency, compute-bound with 48-70% DRAM reduction vs baseline
- **Double-buffering speedup:** 1.61× (decode), 1.62× (prefill)
- **Best tiling configs:** Large tile_k for weight reuse, output grouping (J_c) critical for DRAM traffic reduction
