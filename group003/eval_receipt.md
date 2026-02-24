# CogniChip Hackathon Evaluation Receipt — AI-Guided Memory Hierarchy Design for Edge LLM Inference

## Submission Overview
- Team folder: `group003`
- Slides: `slides/AI-Guided Memory Hierarchy Design For Edge LLM Inference.pdf`
- Video: None
- Code/Repo: `src/lm_memory_controller/`
- Evidence completeness: Good — unit-level tests have passing results (10/10, 6/6), integration tests pending ACI verification; waveform file present; detailed architecture documentation.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 22 | 30 |
| Cognichip Platform Usage | 16 | 20 |
| Innovation & Creativity | 12 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 8 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **69** | **110** |

## Detailed Evaluation

### A) Technical Correctness (22/30)
- Strengths:
  - TESTING_REPORT.md documents 7 testbenches with pass/fail status: tb_config_regs (10/10 PASS), tb_tile_scheduler (6/6 PASS), tb_dynamic_reconfig (5/5 PASS).
  - `tb_llm_memory_controller_comparison.fst` waveform file present.
  - Cross-validation methodology between analytical model and RTL (tb_gemm_traffic) is well-designed.
  - Detailed FSM state descriptions (9-state tile scheduler, 10-state DRAM prefetch, 8-bank arbiter) with documented fixes.
  - Analytical model with Pareto frontier analysis and quantitative performance metrics (1.61× double-buffering speedup).
- Weaknesses / Missing evidence:
  - Integration testbenches (tb_llm_memory_controller, tb_dram_prefetch_engine, tb_sram_bank_arbiter, tb_gemm_traffic) marked "Pending ACI verification (local tools unavailable)."
  - Performance numbers (56.7 ms latency, 99.7% MAC utilization) are from analytical model, not verified RTL simulation.
- Key evidence:
  - (src/lm_memory_controller/lm_memory_controller_Cognichip/TESTING_REPORT.md — test status table)
  - (src/lm_memory_controller/tb_llm_memory_controller_comparison.fst — waveform file)
  - (src/lm_memory_controller/README.md — performance metrics and architecture)

### B) Effective Use of the Cognichip Platform (16/20)
- Strengths:
  - README explicitly states "All testbenches are verified on Cognichip ACI using Verilator."
  - AGENTS.md and the TESTING_REPORT reference the ACI workflow.
  - Cross-validation script designed to run with "Cognichip ACI" output parsing.
  - CHANGELOG.md (referenced) documents iterative design improvements through the platform.
- Weaknesses / Missing evidence:
  - No explicit AI prompt log or iteration record showing Cognichip's specific suggestions.
  - ACI referenced primarily for running existing testbenches rather than generating/fixing RTL.
- Key evidence:
  - (src/lm_memory_controller/README.md — "Cognichip platform is recommended" / "verified on Cognichip ACI")
  - (src/lm_memory_controller/lm_memory_controller_Cognichip/ — platform-specific subfolder)

### C) Innovation & Creativity (12/15)
- Strengths:
  - Edge LLM inference memory controller targeting 2 MB SRAM + 50 GB/s LPDDR5 is a specific, relevant problem.
  - Dynamic per-layer reconfiguration (4-entry preset table cycling through attention/FFN tiling strategies automatically) is a non-obvious optimization.
  - Combined analytical model + RTL cross-validation methodology is rigorous.
- Weaknesses:
  - Core idea (memory controller for transformer inference) is an active research area; novelty is incremental rather than breakthrough.
- Key evidence:
  - (src/lm_memory_controller/README.md — Dynamic Per-Layer Reconfiguration section)

### D) Clarity of Presentation (11/25)
#### D1) Slides clarity (7/10)
- Notes: PDF exists; cannot verify content directly, but reasonable base score awarded.
- Evidence: `slides/AI-Guided Memory Hierarchy Design For Edge LLM Inference.pdf`

#### D2) Video clarity (0/10)
- Notes: No video submission.
- Evidence: No video folder present.

#### D3) Repo organization (4/5)
- Notes: Good structure with RTL in `rtl/`, testbenches in `tb/`, analytical model in `analytical_model/`. Architecture documented in ARCHITECTURE.md. Minor: main README could link to TESTING_REPORT more directly.
- Evidence: (src/lm_memory_controller/ directory layout)

### E) Potential Real-World Impact (8/10)
- Notes: Memory bandwidth is the primary bottleneck for LLM inference at the edge. A dedicated memory controller with tiling, prefetching, and per-layer reconfiguration targets a real industrial need. Quantified performance predictions (56.7 ms full-model latency, 1.61× speedup) make impact credible.
- Evidence: README — performance metrics, architecture description

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA or Tiny Tapeout targeting steps provided.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Strong submission**
- This is a technically sophisticated and well-documented submission with real verification evidence for unit-level modules and a thoughtful cross-validation methodology. The primary weakness is that key integration tests are pending ACI verification, leaving the top-level correctness unconfirmed.

## Actionable Feedback (Most Important Improvements)
1. Complete and commit the integration testbench results (tb_llm_memory_controller, tb_dram_prefetch_engine) from ACI to provide end-to-end verification evidence.
2. Add a video walkthrough demonstrating the dashboard, analytical model sweep, and waveform analysis.
3. Document specific Cognichip ACI prompt interactions and how AI feedback shaped the design iterations (CHANGELOG is referenced but not included in the repo).

## Issues (If Any)
- CHANGELOG.md is referenced but not found in the submitted repository.
