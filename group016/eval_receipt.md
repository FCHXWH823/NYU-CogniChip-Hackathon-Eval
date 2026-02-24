# CogniChip Hackathon Evaluation Receipt — group016

## Submission Overview
- Team folder: `group016`
- Slides: `slides/FunkyMonkey - A RISC-V Neural Processing Accelerator for Edge AI Inference.pdf`
- Video: `video/` (folder exists but is empty — no video file)
- Code/Repo: `src/neurisc_cognichip_hackathon/` (72 files; RISC-V NPU RTL with EDA results showing pooling tests pass, MAC performance testing guide, performance test script)
- Evidence completeness: Good — EDA results confirm pooling unit tests pass; slides describe design innovations; no video; some EDA runs show errors.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 21 | 30 |
| Cognichip Platform Usage | 14 | 20 |
| Innovation & Creativity | 13 | 15 |
| Clarity — Slides | 8 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 8 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **68** | **110** |

## Detailed Evaluation

### A) Technical Correctness (21/30)
- Strengths:
  - EDA results confirm pooling unit tests pass: "PASS: Bypass mode works correctly (zero latency)", "PASS: Correct output count (4 pooled values)".
  - Max pooling with line buffer and bypass mode correctly verified.
  - EDA waveform likely in simulation results (EDA version 0.3.10 confirmed).
  - Comprehensive design: RISC-V custom ISA extensions, back-to-back K-tile accumulation, double-buffered data loading, output-stationary dataflow, hardware activation functions (ReLU, Sigmoid, Tanh), INT8 with 20-bit accumulators.
  - MAC performance testing guide and shell script committed.
- Weaknesses / Missing evidence:
  - Some EDA runs show errors (`DEPS markup file not found` for MAC performance test).
  - Full MAC performance test and RISC-V integration not evidenced in passing EDA results.
  - MNIST and MobileNet workload correctness not verified in logs.
- Key evidence:
  - (src/neurisc_cognichip_hackathon/eda_results.json — "PASS: Bypass mode works correctly", "PASS: Correct output count")
  - (src/neurisc_cognichip_hackathon/simulation_results/sim_2026-02-16T17-58-18-521Z/eda_results.json — DEPS.yml error)
  - (src/neurisc_cognichip_hackathon/MAC_PERFORMANCE_TESTING_GUIDE.md)

### B) Effective Use of the Cognichip Platform (14/20)
- Strengths:
  - EDA results confirm Cognichip platform was used (version 0.3.10).
  - Slides explicitly state CogniChip AI tool used "to accelerate the design process itself."
  - Multiple simulation runs visible in results directories.
- Weaknesses / Missing evidence:
  - No specific description of Cognichip workflow steps, prompts, or iterations in slides.
  - Multiple EDA runs suggest debugging was needed but process not documented.
- Key evidence:
  - (src/neurisc_cognichip_hackathon/eda_results.json — EDA version 0.3.10)
  - (slides/FunkyMonkey - A RISC-V Neural Processing Accelerator...pdf — "leveraging the CogniChip AI tool")

### C) Innovation & Creativity (13/15)
- Strengths:
  - Deep RISC-V integration with NPU (not just a standalone accelerator) is architecturally innovative.
  - Multiple custom ISA extensions for seamless NPU control via RISC-V instructions.
  - Back-to-back K-tile accumulation eliminating state machine restarts is a clever optimization.
  - Double-buffered data loading for zero data-transfer overhead.
  - Hardware activation functions (ReLU, Sigmoid, Tanh) directly in silicon.
  - Full hardware-software co-design (RTL + C runtime + testbenches).
- Weaknesses:
  - RISC-V NPU integration is an active research area; specific novelty vs. published work not quantified.
- Key evidence:
  - (slides/FunkyMonkey - A RISC-V Neural Processing Accelerator...pdf — "Core Innovations" table)

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (8/10)
- Notes: Professional slides with clear problem statement, innovation table, key differentiators, and Cognichip usage description. Good visual structure showing design philosophy.
- Evidence: (slides/FunkyMonkey - A RISC-V Neural Processing Accelerator...pdf)

#### D2) Video clarity (0/10)
- Notes: Video folder exists but is empty — no video file submitted.
- Evidence: (video/ — empty directory)

#### D3) Repo organization (4/5)
- Notes: Good organization: 72 files, README, MAC_PERFORMANCE_TESTING_GUIDE.md, shell script, EDA results directories. Well-structured for a complex project.
- Evidence: (src/neurisc_cognichip_hackathon/ — organized with guides and results)

### E) Potential Real-World Impact (8/10)
- Notes: Edge AI inference is a massive and growing market. An open-source RISC-V NPU with ISA integration would be highly impactful if completed and verified at scale.
- Evidence: (slides/FunkyMonkey - A RISC-V Neural Processing Accelerator...pdf — "Edge devices require real-time AI inference")

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA constraints, synthesis reports, or tapeout evidence. Not mentioned as completed work.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Strong submission — ambitious design with good partial verification**
- One of the most ambitious hardware designs in the cohort — a deeply integrated RISC-V NPU with custom ISA extensions. Pooling unit tests pass confirming partial verification. The missing video and incomplete MAC/integration testing reduce the score.

## Actionable Feedback (Most Important Improvements)
1. Upload a video demonstrating the NPU running a MNIST or MobileNet inference.
2. Fix the DEPS.yml issue for the MAC performance test and commit passing results.
3. Include end-to-end integration test (RISC-V issuing custom instructions to NPU) with logged results.

## Issues (If Any)
- Video folder exists but is empty.
- MAC performance test EDA run has DEPS.yml error.
- Full RISC-V + NPU integration not verified in committed logs.
