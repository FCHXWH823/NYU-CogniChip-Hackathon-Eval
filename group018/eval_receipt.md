# CogniChip Hackathon Evaluation Receipt — group018

## Submission Overview
- Team folder: `group018`
- Slides: `slides/On-board Image Classification.pdf`
- Video: `video/` (folder exists but is empty — no video file)
- Code/Repo: `src/Design-Project/` (94 files; quantized MobileNetV2 inference RTL for FPGA — MAC unit, depthwise conv engine, pointwise conv engine, FC layers, testbenches, Python quantization pipeline, .vvp simulation binaries)
- Evidence completeness: Moderate — comprehensive RTL and Python pipeline committed with `.vvp` simulation binaries (implying simulations ran); no EDA results JSON; detailed documentation files present; no video.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 20 | 30 |
| Cognichip Platform Usage | 12 | 20 |
| Innovation & Creativity | 13 | 15 |
| Clarity — Slides | 8 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 9 | 10 |
| Bonus — FPGA/Tiny Tapeout | 5 | 10 |
| **Total** | **71** | **110** |

## Detailed Evaluation

### A) Technical Correctness (20/30)
- Strengths:
  - `.vvp` binaries (`fc_multi.vvp`, `sim.vvp`) committed — these are compiled Verilog simulation binaries confirming simulations ran.
  - Verify testbench script committed (`verify_testbench.sh`).
  - Python quantization pipeline: ONNX export, INT8 quantization, weight extraction to `.mem` files.
  - `test_image.mem` and `rtl_real_weights_results.csv` committed suggesting actual inference runs.
  - Comprehensive testbench suite: MAC unit, depthwise conv, FC, full inference pipeline.
  - DELIVERABLES.md describes 638-line testbench with 3 conv layers and 2-stage classifier.
- Weaknesses / Missing evidence:
  - No explicit pass/fail simulation logs — `.vvp` binaries exist but outputs not committed.
  - No EDA `eda_results.json` from Cognichip platform.
  - Slides note "RTL verification — MAC unit vs Python ← we are here" — not all layers are verified.
  - No Cognichip EDA integration confirmed.
- Key evidence:
  - (src/Design-Project/fc_multi.vvp, sim.vvp — compiled simulation binaries)
  - (src/Design-Project/rtl_real_weights_results.csv — inference results file)
  - (slides/On-board Image Classification.pdf — "RTL verification ← we are here")
  - (src/Design-Project/DELIVERABLES.md — 638-line testbench description)

### B) Effective Use of the Cognichip Platform (12/20)
- Strengths:
  - Slides have a dedicated "Working with Cognichip" section.
  - Cognichip used for RTL generation and verification assistance.
- Weaknesses / Missing evidence:
  - No Cognichip EDA `eda_results.json` — simulation appears to use standalone Icarus Verilog (`vvp` files are Icarus binaries).
  - No description of specific Cognichip features, prompts, or iteration steps.
  - The `vvp` files suggest Icarus Verilog was the primary simulation tool, not Cognichip EDA.
- Key evidence:
  - (slides/On-board Image Classification.pdf — "Working with Cognichip" section)

### C) Innovation & Creativity (13/15)
- Strengths:
  - Quantized MobileNetV2 inference (~48K params, 47 KB INT8) entirely in FPGA BRAM with no external DRAM is a highly constrained and innovative design challenge.
  - Complete ML pipeline: train → ONNX export → INT8 quantize → weight extraction → RTL verification.
  - All computation in on-chip BRAM on Basys 3 (Artix-7 XC7A35T, 225 KB BRAM) — tightly constrained.
  - Real CIFAR-10 training, real ONNX weights, real hardware target.
  - Custom tiny CNN design (not just generic MobileNetV2 — redesigned to fit constraints).
- Weaknesses:
  - Project is still at RTL verification stage, not yet synthesized to FPGA.
  - 10-class CIFAR-10 classification accuracy not reported.
- Key evidence:
  - (slides/On-board Image Classification.pdf — pipeline: Train→ONNX→INT8→.mem→behavioral sim→RTL verify)
  - (src/Design-Project/mobilenet_v2_uint8.onnx — real ONNX model)

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (8/10)
- Notes: Clear slides covering problem, pipeline diagram, modified MobileNetV2 architecture, Cognichip usage, FPGA constraints, results, challenges. The pipeline diagram is excellent.
- Evidence: (slides/On-board Image Classification.pdf — pipeline diagram, FPGA specs)

#### D2) Video clarity (0/10)
- Notes: Video folder exists but is empty.
- Evidence: (video/ — empty directory)

#### D3) Repo organization (4/5)
- Notes: Well-organized with 94 files, comprehensive documentation files (DELIVERABLES.md, COMPLETE_INFERENCE_GUIDE.md, TESTBENCH_QUICK_START.md, FINAL_CLASSIFICATION_PLAN.md), Python scripts, and RTL. README is present but empty.
- Evidence: (src/Design-Project/ — comprehensive file set)

### E) Potential Real-World Impact (9/10)
- Notes: On-device image classification with $150 hardware at <5W power and no internet required directly addresses real small-business edge AI needs. The methodology (fit MobileNetV2 into 225 KB BRAM) is broadly applicable.
- Evidence: (slides/On-board Image Classification.pdf — "$150 hardware cost, <5W power, no internet needed")

### Bonus) FPGA / Tiny Tapeout Targeting (+5/10)
- Notes: Specific FPGA target identified: Xilinx Artix-7 XC7A35T (Basys 3). Detailed constraint analysis (225 KB BRAM, 90 DSPs) used to guide design decisions. Project is at behavioral simulation stage — not yet synthesized with timing/power reports. Partial credit for concrete board targeting and constraint analysis.
- Evidence:
  - (slides/On-board Image Classification.pdf — "Xilinx Artix-7 XC7A35T" specs table)
  - (src/Design-Project/FINAL_CLASSIFICATION_PLAN.md — synthesis as next step)

## Final Recommendation
- Overall verdict: **Strong submission — ambitious FPGA CNN inference project**
- One of the most complex and ambitious projects — quantized MobileNetV2 inference entirely in FPGA BRAM is a genuinely hard engineering problem. The complete ML-to-RTL pipeline is impressive. Score is limited by the project being at the RTL verification stage (not yet synthesized) and the absence of Cognichip EDA results.

## Actionable Feedback (Most Important Improvements)
1. Synthesize to Basys 3 and commit timing/power reports to complete the FPGA bonus evidence.
2. Commit simulation pass/fail log output to document which testbenches pass.
3. Upload a video demonstrating the end-to-end pipeline from image input to classification output.

## Issues (If Any)
- Video folder exists but is empty.
- README.md in Design-Project directory is empty.
- Project is at RTL verification stage — FPGA synthesis not completed.
- No Cognichip EDA results.
