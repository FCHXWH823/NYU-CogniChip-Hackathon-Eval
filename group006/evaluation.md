# CogniChip Hackathon Evaluation Receipt — group006

## Submission Overview
- Team folder: `group006`
- Slides: `slides/Cognichip Hackathon by Train Neo Bit.pdf`
- Video: `video/introduction presentation/CF764826-1843-40A1-96F4-96C7DB169623.mp4` and `video/simulation demo/2026-02-20 23-42-39.mkv` (+ 2 more MKV files)
- Code/Repo: `src/Cognichip-Hackathon-by-Train-Neo-Bit/` — three design iterations ("Dual threshold" folder with 20 Cognichip EDA runs), README
- Evidence completeness: Good — 14 of 20 Cognichip EDA runs passed across multiple targets including the gradient compressor design.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 22 | 30 |
| Cognichip Platform Usage | 16 | 20 |
| Innovation & Creativity | 11 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 7 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 7 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **74** | **110** |

## Detailed Evaluation

### A) Technical Correctness (22/30)
- Strengths:
  - 14 of 20 Cognichip EDA runs passed, covering targets: `sim_simple` (4 passes), `sim_gradient_compressor` (2 passes), `sim_gradient_debug` (1 pass), `sim_stress_small` (1 pass).
  - The gradient compressor itself (`sim_gradient_compressor`) produced passing simulations after iterative debugging.
  - Multiple simulation targets at different abstraction levels (simple, gradient compressor, stress test, debug) suggest thorough coverage.
- Weaknesses / Missing evidence:
  - `sim_gradient_compressor` failed in 3 of 5 runs (return_code: 30); final correctness depends on which version was considered final.
  - `sim_threshold_test` failed in both attempts; dual-threshold logic not fully verified.
  - One `sim_stress_small` run returned code 255 (crash) before the eventual pass.
  - No waveform files committed.
- Key evidence:
  - (src/Cognichip-Hackathon-by-Train-Neo-Bit/Dual threshold/simulation_results/sim_2026-02-20T00-11-42-357Z/eda_results.json) — `sim_simple` PASS
  - (src/Cognichip-Hackathon-by-Train-Neo-Bit/Dual threshold/simulation_results/sim_2026-02-20T01-06-32-119Z/eda_results.json) — `sim_gradient_compressor` PASS
  - (src/Cognichip-Hackathon-by-Train-Neo-Bit/Dual threshold/simulation_results/) — 20 EDA result directories

### B) Effective Use of the Cognichip Platform (16/20)
- Strengths:
  - 20 Cognichip EDA runs committed — the largest number of platform iterations in this cohort.
  - README documents 3 design iterations; iterative debugging via the platform is evident.
  - Simulation demo video shows the platform in action.
- Weaknesses / Missing evidence:
  - `DEPS.yml` not found in the submitted source; platform project configuration not explicitly structured.
  - `sim_threshold_test` never passed, suggesting the dual-threshold feature's platform integration was incomplete.
- Key evidence:
  - (src/Cognichip-Hackathon-by-Train-Neo-Bit/Dual threshold/simulation_results/) — 20 EDA result directories

### C) Innovation & Creativity (11/15)
- Strengths:
  - Hardware gradient compressor using on-chip SRAM buffer with dual threshold to filter insignificant gradient updates is a non-trivial, LLM-training-relevant hardware concept.
  - Three design iterations over the hackathon show meaningful evolution.
  - Targets a real bottleneck (memory wall in distributed LLM training) with a hardware-level solution.
- Weaknesses:
  - The dual-threshold logic itself could not be verified via EDA.
  - Implementation is limited to a behavioural module; no area or power analysis.

### D) Clarity of Presentation (18/25)
#### D1) Slides clarity (7/10)
- Notes: PDF covers the memory wall problem, gradient compression motivation, and architecture overview. Team members and contact information included.
- Evidence: (slides/Cognichip Hackathon by Train Neo Bit.pdf)

#### D2) Video clarity (7/10)
- Notes: Two sets of videos submitted: an introduction presentation and a simulation demo (3 MKV screen recordings). Dual-mode submission is more than most teams provided.
- Evidence: (video/introduction presentation/CF764826-1843-40A1-96F4-96C7DB169623.mp4), (video/simulation demo/2026-02-20 23-42-39.mkv)

#### D3) Repo Organization (4/5)
- Notes: README present with team info, description, and links. Three design iterations are referenced. Minor issues: no DEPS.yml, no explicit final design designation, and video links point to external Drive rather than committed files.
- Evidence: (src/Cognichip-Hackathon-by-Train-Neo-Bit/README.md)

### E) Potential Real-World Impact (7/10)
- Notes: Gradient compression hardware that reduces DRAM bandwidth in distributed AI training is directly commercially relevant. The design targets a documented pain point with an on-chip solution.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA constraints or tapeout evidence found.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Good** (74/110)
- The submission demonstrates active, extensive use of the Cognichip platform with the highest EDA run count; 14 passing runs across multiple targets including the gradient compressor confirm real hardware verification. Score is limited by the failing threshold tests and absence of a DEPS.yml/waveform evidence.

## Actionable Feedback (Most Important Improvements)
1. Debug and pass `sim_threshold_test` to verify the dual-threshold feature that is central to the design's novelty.
2. Add a `DEPS.yml` and commit waveform output for the gradient compressor run.
3. Include area and power estimates (even if via Yosys synthesis) to quantify the compression hardware overhead.

## Issues (If Any)
- `sim_threshold_test` failed in all 2 EDA attempts; dual-threshold feature unverified.
- `DEPS.yml` not found in submitted source.
- External video linked in README (Google Drive) instead of relying solely on committed files.
