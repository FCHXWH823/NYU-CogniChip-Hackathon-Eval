# CogniChip Hackathon Evaluation Receipt — group003

## Submission Overview
- Team folder: `group003`
- Slides: `slides/AI-Guided Memory Hierarchy Design  For Edge LLM Inference.pdf`
- Video: None
- Code/Repo: `src/lm_memory_controller/` (35 files; parameterized RTL controller, Python analytical model, testbenches, TESTING_REPORT.md, CHANGELOG.md, .fst waveform)
- Evidence completeness: Strong — slides present quantitative performance data, testing report and changelog confirm iterative development; waveform file present; no video submitted.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 23 | 30 |
| Cognichip Platform Usage | 15 | 20 |
| Innovation & Creativity | 12 | 15 |
| Clarity — Slides | 9 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 9 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **72** | **110** |

## Detailed Evaluation

### A) Technical Correctness (23/30)
- Strengths:
  - Slides state "8 Testbench files, 50+ Tests pass" (slides p.7), and TESTING_REPORT.md in repo confirms test coverage.
  - Waveform file present (`src/lm_memory_controller/tb_llm_memory_controller_comparison.fst`).
  - Analytical model delivers concrete numbers: −49.3% DRAM traffic, +38.1 pp compute utilization, 1.62× latency improvement.
  - CHANGELOG.md documents iterative design evolution.
  - Parameterized RTL controller with GEMM tiling, prefetch, and SRAM bank arbitration.
  - Performance counters for profiling built into design.
- Weaknesses / Missing evidence:
  - EDA simulation results JSON not found in repository (no `eda_results.json`); waveform is present but not from Cognichip EDA directly.
  - "50+ tests pass" claim from slides is not independently verifiable from the repo alone (TESTING_REPORT.md referenced but content not confirmed).
  - Analytical model improvement figures are model predictions, not silicon measurements.
- Key evidence:
  - (slides/AI-Guided Memory Hierarchy Design For Edge LLM Inference.pdf p.7 — "8 Testbench files, 50+ Tests pass")
  - (slides/AI-Guided Memory Hierarchy Design For Edge LLM Inference.pdf p.5 — performance table: −49.3% DRAM traffic)
  - (src/lm_memory_controller/tb_llm_memory_controller_comparison.fst — waveform file)
  - (src/lm_memory_controller/lm_memory_controller_Cognichip/TESTING_REPORT.md)

### B) Effective Use of the Cognichip Platform (15/20)
- Strengths:
  - Clearly describes AI-guided design workflow: natural-language descriptions of edge LLM constraints → Cognichip proposes design configurations (buffer sizes, tile granularity, prefetch strategies).
  - AI used to bootstrap RTL framework and assisted with testbench development.
  - Analytical model used to reduce Cognichip simulation runs — a smart use of the platform.
- Weaknesses / Missing evidence:
  - No EDA `eda_results.json` from Cognichip platform — unclear which simulation runs used Cognichip vs. standalone Verilator.
  - Specific Cognichip prompt examples or screenshots not provided.
- Key evidence:
  - (slides/AI-Guided Memory Hierarchy Design For Edge LLM Inference.pdf p.3 — "How We Used the Cognichip Platform: AI-Guided Design Workflow")
  - (slides/AI-Guided Memory Hierarchy Design For Edge LLM Inference.pdf p.4 — RTL & Simulation Development)

### C) Innovation & Creativity (12/15)
- Strengths:
  - Targets a high-relevance problem: memory-bound LLM inference on edge SoCs with strict SRAM/DRAM constraints.
  - Multi-objective Pareto frontier optimization for GEMM-specific tiling configurations is sophisticated.
  - Combination of analytical model + RTL simulation for design space reduction is a principled methodology.
  - Per-GEMM optimal tiling (rather than uniform tiling) is a nuanced design decision.
- Weaknesses:
  - Memory controller for DNN inference is a well-studied area; specific architecture is incremental rather than breakthrough.
- Key evidence:
  - (slides/AI-Guided Memory Hierarchy Design For Edge LLM Inference.pdf p.4 — Pareto frontier optimization)
  - (src/lm_memory_controller/README.md — multi-GEMM tiling configuration)

### D) Clarity of Presentation (13/25)
#### D1) Slides clarity (9/10)
- Notes: Excellent slides — quantitative performance table, architecture description, clear methodology section, challenges/lessons, and future work. Clean layout with strong data presentation.
- Evidence: (slides/AI-Guided Memory Hierarchy Design For Edge LLM Inference.pdf — well-structured, ~10 slides)

#### D2) Video clarity (0/10)
- Notes: No video submitted.
- Evidence: No video directory.

#### D3) Repo organization (4/5)
- Notes: Good structure with TESTING_REPORT.md, CHANGELOG.md, README, analytical model subdirectory, and RTL controller. Dashboard script with command-line options well documented.
- Evidence: (src/lm_memory_controller/README.md — detailed usage instructions)

### E) Potential Real-World Impact (9/10)
- Notes: Directly addresses the critical bottleneck in edge LLM deployment — memory bandwidth. The 49% DRAM traffic reduction would translate directly to energy and latency savings. Parameterized design is extensible to production SoCs.
- Evidence: (slides/AI-Guided Memory Hierarchy Design For Edge LLM Inference.pdf p.1 — "Edge LLM inference is memory-bound")

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA targeting, constraints, or tapeout evidence. Future work mentions "additional RTL simulations" only.
- Evidence: (slides/AI-Guided Memory Hierarchy Design For Edge LLM Inference.pdf — future work slide)

## Final Recommendation
- Overall verdict: **Strong submission — one of the best technical contributions**
- Rigorous methodology combining analytical modeling and RTL simulation, backed by concrete performance numbers and testing documentation. The memory hierarchy design for edge LLM inference is highly relevant. Score limited by absent video and no Cognichip EDA results files.

## Actionable Feedback (Most Important Improvements)
1. Include the actual Cognichip EDA simulation logs/results to confirm tests were run on the platform.
2. Submit a short demo video showing the dashboard and simulation results.
3. Publish the TESTING_REPORT.md content in the main README for immediate visibility.

## Issues (If Any)
- No video submitted.
- No `eda_results.json` from Cognichip platform — simulation origin unclear.
