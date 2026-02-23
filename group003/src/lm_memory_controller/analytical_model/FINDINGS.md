# LLM Memory Controller — Analytical Model Findings

## 1 Overview

This document presents the results of a tiling design-space exploration for `lm_memory_controller`, a parameterizable memory-subsystem IP targeting edge LLM inference. The analytical model sweeps ~14 000 tiling configurations across all seven linear-projection GEMMs in each Transformer layer of **Qwen3-8B (INT4 weights / INT8 activations)**, evaluating them against the following hardware target:

| Parameter | Value |
|-----------|-------|
| On-chip SRAM | 2 MB (4 × 512 KB banks) |
| Off-chip DRAM | LPDDR5-6400, 50 GB/s peak |
| DRAM page-hit latency | 17 ns |
| DRAM page-miss latency | 52 ns |
| Compute array | 32 × 32 INT8 MACs @ 500 MHz (512 GOPS peak) |

Two inference regimes are evaluated: **decode** (seq_len = 1, autoregressive token generation) and **prefill** (seq_len = 256, prompt processing).

---

## 2 Model Architecture — GEMM Shapes per Layer

Each of the 36 Transformer layers contains seven weight-projection GEMMs. For decode (M = 1) these become matrix–vector products; for prefill (M = 256) they are full matrix multiplications.

| GEMM | M | N | K | Weight Size (INT4) |
|------|---|------|------|---------------------|
| Q projection | M | 4096 | 4096 | 8 MB |
| K projection | M | 1024 | 4096 | 2 MB |
| V projection | M | 1024 | 4096 | 2 MB |
| O projection | M | 4096 | 4096 | 8 MB |
| FFN gate | M | 12288 | 4096 | 24 MB |
| FFN up | M | 12288 | 4096 | 24 MB |
| FFN down | M | 4096 | 12288 | 24 MB |

Total weight per layer: **92 MB**. Full model (36 layers): **3.3 GB**.

---

## 3 Tiling & Buffer Model

### 3.1 Loop Nest

The cost model assumes an A-reuse loop nest with output grouping:

```
for i in [ceil(M/tm)]:                    // output row tiles
  for jg in [ceil(n_n / J_c)]:           // output column groups
    initialize J_c accumulator tiles in SRAM
    for k in [ceil(K/tk)]:               // reduction tiles
      load A[i,k]                        // reused across J_c columns
      for j in [J_c]:                    // columns within group
        load B[k, jg·J_c + j]
        C[i, jg·J_c + j] += A × B
    store J_c output tiles
```

**J_c** (the number of C tiles held simultaneously in SRAM) is determined by the SRAM budget remaining after A and B buffers are allocated. Larger J_c increases A reuse and reduces DRAM re-reads.

### 3.2 DRAM Traffic Equations

| Operand | Total loads | Bytes |
|---------|------------|-------|
| A (activations) | n_m × n_jg × n_k | M × K × act_bytes × n_jg |
| B (weights) | n_m × n_n × n_k | n_m × K × N × weight_bytes |
| C (output) | n_m × n_n | M × N × output_bytes |

### 3.3 Pipeline Overlap

Four buffer schemes are evaluated. Per k-iteration steady-state time:

| Scheme | Per-iteration time |
|--------|-------------------|
| Single | load_A + J_c × (load_B + compute) |
| Double-B | load_A + J_c × max(load_B, compute) |
| Double-A | max(load_A, J_c × (load_B + compute)) |
| Double-AB | max(load_A, J_c × max(load_B, compute)) |

DRAM transfer time per tile uses a physical model: `t = avg_initial_latency + bytes / sustained_bw`, where `avg_initial_latency = 0.7 × 17 ns + 0.3 × 52 ns = 27.5 ns`. This penalizes small tiles (latency-dominated) and rewards large sequential transfers (bandwidth-dominated).

---

## 4 Key Findings

### 4.1 Decode vs Prefill: Two Fundamentally Different Regimes

| Metric | Decode (M = 1) | Prefill (M = 256) |
|--------|:--------------:|:------------------:|
| Best MAC utilization | **3.1%** | **99.7%** |
| DRAM reduction (vs baseline) | **0%** | **48–70%** |
| Dominant bottleneck | Array shape mismatch | Compute-bound |
| Speedup from double-buffering | 1.61× | 1.62× |
| Total DRAM per layer (best) | 96.5 MB | 401 MB |
| Full model (36L) latency | 56.7 ms | 674 ms |

> **Figures**: `figures/prefill_vs_decode.png`, `figures/layer_comparison_decode.png`, `figures/layer_comparison_prefill-256.png`

### 4.2 Decode: The Real Bottleneck Is Not DRAM Bandwidth

A common claim is that LLM decode is "memory-bound." Our model reveals a more nuanced picture.

For the Q-projection GEMM (M=1, N=4096, K=4096):

| Component | Cycles | Time |
|-----------|--------|------|
| Compute (32×32 array) | 524 288 | 1.05 ms |
| Memory transfer (50 GB/s) | 318 771 | 0.64 ms |
| **Bottleneck** | **Compute** | |

The compute time is **not** large because the operation is arithmetically intense — it has only 16.8M MACs. The problem is that the 32 × 32 systolic array processes M = 1 workloads at **1/32 = 3.125% efficiency**: each cycle activates only one row of the array, wasting 31 rows.

Furthermore, DRAM traffic for decode is **invariant to tiling strategy**. With M = 1:
- Total A data = K bytes (entire activation vector, fits in SRAM)
- Total B data = K × N × 0.5 bytes (entire weight matrix, must stream through)
- Both are loaded exactly once regardless of tile sizes

**Implication**: for decode, the memory controller's tiling and prefetch capabilities provide moderate benefit (1.6× from overlap), but the fundamental limit is the compute array's shape inefficiency. Batched decode (M > 1) or a vector-mode compute unit would address the root cause.

### 4.3 Prefill: Tiling Delivers 48–70% DRAM Reduction

For prefill (M = 256), the design space is rich and tiling choices matter significantly.

**Q/O projection** (N = 4096, K = 4096):

| Config | DRAM | Utilization | Speedup |
|--------|------|-------------|---------|
| Baseline (tm=32, tn=32, tk=32, single) | 69.2 MB | 61.7% | 1.0× |
| Best (tm=64, tn=4096, tk=32, double_ab) | 35.7 MB | 99.7% | 1.62× |
| **Reduction** | **48.5%** | **+38 pp** | |

**K/V projection** (N = 1024, K = 4096):

| Config | DRAM | Utilization | Speedup |
|--------|------|-------------|---------|
| Baseline | 18.1 MB | 61.0% | 1.0× |
| Best (tm=128, tn=1024, tk=32, double_ab) | 5.5 MB | 99.7% | 1.63× |
| **Reduction** | **69.6%** | **+38.7 pp** | |

The K/V projections benefit most because their small N = 1024 allows `tn = N` (entire output width in one tile), maximizing A reuse (J_c = 1, n_jg = 1 → A loaded exactly once).

> **Figures**: `figures/pareto_prefill-256_attn_q_proj.png`, `figures/pareto_prefill-256_attn_k_proj.png`

### 4.4 Pareto Frontier Structure

The Pareto frontier for prefill Q-projection exhibits a steep L-shape:

- **Top-left cluster** (low DRAM, high utilization): `double_ab` configurations with `tm ∈ {32, 64, 128}`, `tn = 4096`, `tk = 32`. These achieve near-ideal performance.
- **Knee region** (~80% utilization): transition where DRAM latency overhead begins to compete with compute.
- **Long tail** (high DRAM, low utilization): small tiles with single buffering — dominated on both axes.
- **Baseline** sits at (69 MB, 62%) — far from the frontier.

Single-buffer configurations are **entirely dominated** by double-buffer variants across the full frontier, validating the necessity of the DRAM Prefetch Engine.

> **Figure**: `figures/pareto_prefill-256_attn_q_proj.png`

### 4.5 Uniform vs Per-GEMM Tiling

| Strategy | DRAM (36 layers) | Utilization |
|----------|-----------------|-------------|
| Uniform (best single config) | 14.74 GB | 99.8% |
| Per-GEMM optimal | 14.44 GB | 99.8% |
| **Improvement** | **2.0%** | +0.0 pp |

The gain is modest for prefill at M = 256 because most GEMMs are compute-bound at optimal tiling — DRAM is not the bottleneck. However, per-GEMM tiling becomes more valuable at smaller M (closer to decode) or with tighter SRAM constraints.

The K/V projections (N = 1024) prefer `tn = 1024` to capture the full output width, while FFN layers (N = 12288) must use smaller `tn`. A single tiling config cannot optimally serve both.

**Implication**: the Config Register interface should support at minimum 4 tiling presets (one per unique (N, K) shape group) loadable per layer.

---

## 5 Design Implications for RTL

### 5.1 Tile Scheduler

Recommended default tiling configurations for the Config Registers:

| GEMM Group | tile_m | tile_n | tile_k | Buffer | SRAM Used |
|------------|--------|--------|--------|--------|-----------|
| Q/O proj (4096×4096) | 64 | 4096 | 32 | double_ab | 1.13 MB |
| K/V proj (1024×4096) | 128 | 1024 | 32 | double_ab | 0.53 MB |
| FFN gate/up (12288×4096) | 64 | 4096 | 32 | double_ab | 1.13 MB |
| FFN down (4096×12288) | 64 | 4096 | 32 | double_ab | 1.13 MB |

These are the best-utilization Pareto points for prefill at M = 256. For decode, tiling has minimal DRAM impact; the scheduler should default to maximizing overlap.

### 5.2 SRAM Bank Arbiter

Key observations for bank allocation:
- **J_c = 1** for the recommended configs (one output tile group at a time)
- The C accumulator tile dominates SRAM usage (e.g., 64 × 4096 × 4 = 1 MB for Q proj)
- A and B buffers are relatively small; double-buffering adds ~130 KB for B
- Bank-level parallelism should prioritize **concurrent A read + B prefetch + C accumulate**

Suggested 4-bank allocation for double_ab at the Q/O tiling point:

| Bank | Content | Size |
|------|---------|------|
| Bank 0 | A tile (ping) | 2 KB |
| Bank 1 | A tile (pong) + B tile (ping) | 2 KB + 64 KB |
| Bank 2 | B tile (pong) | 64 KB |
| Bank 3 | C accumulator | 1 MB |

(Bank 3 absorbs the large accumulator; Banks 1–2 handle the double-buffered streaming.)

### 5.3 DRAM Prefetch Engine

Double-buffering provides a consistent **1.6× speedup** across all configurations and both inference modes. This validates the prefetch engine as a core module rather than an optimization.

For prefill, the critical path in the overlap model is:

```
per_tile_time = max(load_B_time, compute_time)
```

At the recommended tiling (tk=32, tn=4096): `load_B = 742 cycles`, `compute = 8192 cycles`. Memory is **fully hidden** — the prefetch engine has 8192 cycles to complete a 742-cycle transfer, giving 11× margin. This suggests the prefetch engine can be relatively simple (single-request pipelining suffices; deep prefetch queues are unnecessary for these tile sizes).

For decode: `load_B = 742 cycles`, `compute = 4096 cycles`. Memory is still hidden but with less margin (5.5×).

### 5.4 Config Registers — Dynamic Reconfiguration

The model quantifies the case for per-layer tiling reconfiguration:

- **Attention layers** (Q/K/V/O) and **FFN layers** (gate/up/down) have different optimal tile sizes
- 4 preset configurations cover all 7 GEMM shapes in a layer
- Per-layer switching can be done between layers (no mid-computation reconfiguration needed)

The Config Register interface should expose:
- `tile_m`, `tile_n`, `tile_k` (tile dimensions)
- `buffer_scheme` (2-bit: single / double_a / double_b / double_ab)
- `gemm_m`, `gemm_n`, `gemm_k` (full GEMM dimensions for tile count computation)
- A 4-entry preset table, indexed by GEMM type within a layer

---

## 6 Baseline Comparison Summary

Full-model (36 layers) comparison, prefill at M = 256:

| Metric | Baseline | Optimized | Improvement |
|--------|----------|-----------|-------------|
| DRAM traffic | 28.5 GB | 14.4 GB | **−49.3%** |
| Compute utilization | 61.7% | 99.8% | **+38.1 pp** |
| Per-layer latency | 3.65 ms | 2.26 ms | **1.62× faster** |
| Full model latency | 131.6 ms | 81.4 ms | **1.62× faster** |

Baseline definition: single buffer, tile_m = 32, tile_n = 32, tile_k = 32 (one MAC-array-sized tile per dimension, no prefetching).

---

## 7 Limitations & Next Steps

1. **Attention score computation (QK^T, Score×V) not modeled.** These involve the KV cache and have distinct access patterns (growing context window). Adding them would complete the per-layer picture, especially for long-context decode.

2. **Bank conflict modeling.** The current model uses a flat SRAM capacity constraint. A bank-level model would capture conflicts when A prefetch and C writeback target the same bank simultaneously.

3. **Decode batching sweep.** Sweeping M = {1, 2, 4, 8, 16, 32} for decode would identify the crossover point where the MAC array reaches acceptable utilization, informing the minimum batch size for the controller.

4. **INT4 MAC packing.** If the 32×32 array can pack two INT4 ops per INT8 slot, peak throughput doubles to 1024 GOPS, shifting the compute/memory balance for all configurations.

5. **Cross-validation with RTL simulation.** The analytical cycle counts should be compared against the synthesized controller's actual cycle-accurate behavior to calibrate the model's DRAM latency and pipeline overlap assumptions.

---

## Appendix: Reproducing Results

```bash
cd analytical_model
uv run python main.py                    # both decode + prefill-256
uv run python main.py --mode decode      # decode only
uv run python main.py --seq-len 512      # prefill at seq_len=512
```

All figures are saved to `analytical_model/figures/`.

---

## 6 RTL Cross-Validation

The analytical cost model predictions are cross-validated against the RTL implementation using the `tb_gemm_traffic` testbench. The testbench replays representative GEMM shapes with parseable PERF output, which is then compared against `compute_gemm_cost()` predictions.

### Validation Approach

`cross_validate.py` automates this comparison by:
1. Parsing RTL PERF output: `gemm=<name> cycles=<N> dram_reads=<M> dram_writes=<W> tiles=<T>`
2. Calling `compute_gemm_cost()` with matching GEMM shape, tiling, and buffer scheme
3. Converting RTL `dram_read_beats` to bytes (× 16 for 128-bit DRAM width)
4. Comparing with tolerance thresholds: ±15% cycles, ±5% DRAM bytes, exact tile count

### Tolerance Rationale

The ±15% cycle tolerance accounts for pipeline startup/flush overhead not modeled in the analytical steady-state cost equations. The ±5% DRAM byte tolerance allows for DRAM alignment effects and prefetch queue behavior.

### Example Usage

```bash
# Run GEMM traffic testbench on Cognichip ACI
eda sim --tool verilator tb_gemm_traffic > perf_output.txt

# Extract PERF line and validate
grep "PERF:" perf_output.txt | uv run analytical_model/cross_validate.py \
  --rtl-log - \
  --gemm attn_q_proj_sim \
  --tiling tm=32,tn=32,tk=32,single
```

### Results

*(Cross-validation results will be populated after running testbenches on Cognichip ACI platform. Expected: cycle count within ±15%, DRAM bytes within ±5%, exact tile count match.)*

---

## 7 Dynamic Per-Layer Reconfiguration

### Motivation

Transformer models have fundamentally different memory access patterns across layer types:

- **Attention projections** (Q/K/V/O): Small inner dimension (N=1024 for K/V), benefit from larger tile_k to maximize weight reuse
- **FFN layers** (gate/up/down): Large inner dimension (N=12288), benefit from smaller tile_n to maximize output grouping (J_c)

### Implementation

The controller implements a 4-entry preset table (16 registers at 0x60-0x9C) storing pre-configured tiling parameters and SRAM base addresses. A control register at 0xA4 enables automatic reconfiguration: on each GEMM completion (`sched_done` pulse), the controller loads the next preset, increments the selector (with wrap-around), and increments a reconfiguration counter.

### Latency

Reconfiguration completes in **1 cycle** (combinational load from preset table to active registers). The `reconfig_active` status bit (0x04[3]) asserts for one cycle to signal completion.

### Use Case

Software programs all 4 presets once during initialization, then enables auto-reconfiguration. The controller cycles through presets automatically, eliminating per-layer register write overhead. Example sequence:

1. **Preset 0:** Attention Q/K/V tiling (tile_m=8, tile_n=64, tile_k=32, mode=3)
2. **Preset 1:** FFN up/gate tiling (tile_m=32, tile_n=32, tile_k=16, mode=1)
3. **Preset 2:** Attention O projection (tile_m=16, tile_n=64, tile_k=32, mode=2)
4. **Preset 3:** FFN down projection (tile_m=64, tile_n=16, tile_k=32, mode=0)

### Backward Compatibility

When `reconfig_enable=0` (default), the controller behaves identically to the original design (manual writes to 0x00-0x3F registers). START remains software-controlled in both modes.

---

## 8 Limitations & Next Steps

1. **Attention score computation (QK^T, Score×V) not modeled.** These involve the KV cache and have distinct access patterns (growing context window). Adding them would complete the per-layer picture, especially for long-context decode.

2. **Bank conflict modeling.** The current model uses a flat SRAM capacity constraint. A bank-level model would capture conflicts when A prefetch and C writeback target the same bank simultaneously.

3. **Decode batching sweep.** Sweeping M = {1, 2, 4, 8, 16, 32} for decode would identify the crossover point where the MAC array reaches acceptable utilization, informing the minimum batch size for the controller.

4. **INT4 MAC packing.** If the 32×32 array can pack two INT4 ops per INT8 slot, peak throughput doubles to 1024 GOPS, shifting the compute/memory balance for all configurations.

5. **Cross-validation with RTL simulation.** The analytical cycle counts should be compared against the synthesized controller's actual cycle-accurate behavior to calibrate the model's DRAM latency and pipeline overlap assumptions.
