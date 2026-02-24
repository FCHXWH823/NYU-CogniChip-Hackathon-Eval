# CogniChip Hackathon Evaluation Receipt — On-board Image Classification (CNN on FPGA)

## Submission Overview
- Team folder: `group018`
- Slides: `slides/On-board Image Classification.pdf`
- Video: `video/` (directory exists with files)
- Code/Repo: `src/Design-Project/` — CNN inference engine targeting Basys3 FPGA (XC7A35T)
- Evidence completeness: Strong — `rtl_real_weights_results.csv` shows 4 PASS results matching RTL and Python golden model exactly; FPGA resource estimation table present; Python int8 simulation runs on actual test images.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 27 | 30 |
| Cognichip Platform Usage | 6 | 20 |
| Innovation & Creativity | 13 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 7 | 10 |
| Clarity — Repo Organization | 5 | 5 |
| Potential Real-World Impact | 9 | 10 |
| Bonus — FPGA/Tiny Tapeout | 8 | 10 |
| **Total** | **82** | **110** |

## Detailed Evaluation

### A) Technical Correctness (27/30)
- Strengths:
  - `rtl_real_weights_results.csv` commits 4 explicit test cases with exact value matching: conv1_f0_px5x5 (466870 = 466870 PASS), conv1_f0_px0x0 (118476 = 118476 PASS), conv2_f0_px4x4 (2576776 = 2576776 PASS), fc2_n0 (1255461 = 1255461 PASS).
  - Python behavioral simulation (basys3_sim.py) runs integer-only arithmetic identical to FPGA DSP48E1 operation.
  - Quantitative accuracy: Float32 model 74.2%, Int8 FPGA simulation 74.1% — < 0.1% accuracy loss from quantization.
  - FPGA resource table: 66.1 KB BRAM (29.4% of 225 KB), 90 DSPs time-multiplexed.
  - PyTorch model (tiny_cnn_cifar10.py) trains, exports ONNX, and validates — reproducible pipeline.
- Weaknesses / Missing evidence:
  - Only 4 specific pixel/neuron values verified in CSV; no full-image classification accuracy on hardware.
  - FPGA bitstream not committed; resource estimation is from model, not Vivado implementation.
- Key evidence:
  - (src/Design-Project/rtl_real_weights_results.csv — 4× PASS with exact value matching)
  - (src/Design-Project/tiny-cnn-basys3/README.md — accuracy and resource tables)
  - (src/Design-Project/tiny-cnn-basys3/basys3_sim.py — integer simulation)

### B) Effective Use of the Cognichip Platform (6/20)
- Strengths:
  - Submitted to CogniChip Hackathon.
- Weaknesses / Missing evidence:
  - README does not explicitly mention Cognichip as the AI tool used for design.
  - No Cognichip prompt logs or workflow documentation found.
  - Appears to be primarily an independent FPGA/ML engineering project.
  - Capped: generic AI usage with no specific Cognichip description.
- Key evidence:
  - No Cognichip mention found in examined README files.

### C) Innovation & Creativity (13/15)
- Strengths:
  - End-to-end pipeline: PyTorch training → ONNX export → weight extraction → int8 RTL → FPGA simulation with integer-exact verification is a complete and rigorous flow.
  - DSP48E1-specific optimization (time-multiplexing 90 DSPs) shows deep FPGA architectural awareness.
  - 74.2% CIFAR-10 accuracy in a 47,818-parameter model fitting on Basys3 is a strong result for the constraint.
  - MobileNet-V2 inference attempted alongside custom tiny CNN.
- Weaknesses:
  - CNN inference on FPGA is well-studied; the novel contribution is the specific Basys3 fit and integer verification methodology.
- Key evidence:
  - (src/Design-Project/tiny-cnn-basys3/README.md — architecture, results)
  - (src/Design-Project/rtl_real_weights_results.csv)

### D) Clarity of Presentation (19/25)
#### D1) Slides clarity (7/10)
- Notes: PDF exists; cannot verify content directly, but reasonable base score awarded.
- Evidence: `slides/On-board Image Classification.pdf`

#### D2) Video clarity (7/10)
- Notes: Video directory exists with files.
- Evidence: `video/` directory with contents.

#### D3) Repo organization (5/5)
- Notes: Excellent organization — Python model in root, RTL modules, testbenches, CSV results, TESTBENCH_QUICK_START.md, COMPLETE_INFERENCE_GUIDE.md, DELIVERABLES.md, Makefile. DEPS.yml for simulation. Comprehensive and reproducible.
- Evidence: (src/Design-Project/ directory listing)

### E) Potential Real-World Impact (9/10)
- Notes: On-board image classification (74.2% CIFAR-10) running on a $30 Basys3 FPGA board demonstrates immediate practical applicability for edge AI in cost-constrained scenarios (IoT cameras, drones, industrial vision). The integer-exact simulation methodology is directly deployable.
- Evidence: tiny-cnn-basys3/README.md — "4,008 images/sec @ 100 MHz", "PASS — Model fits on Basys3 with 70% BRAM headroom"

### Bonus) FPGA / Tiny Tapeout Targeting (+8/10)
- Notes: Clear Basys3 (XC7A35T) FPGA targeting with specific resource utilization table (BRAM, DSP counts), latency estimates at 100 MHz, and integer behavioral simulation modeling FPGA-specific arithmetic units (DSP48E1). TESTBENCH_QUICK_START.md guides FPGA-level verification.
- Evidence:
  - (src/Design-Project/tiny-cnn-basys3/README.md — FPGA resource table targeting XC7A35T)
  - (src/Design-Project/tiny-cnn-basys3/basys3_sim.py — DSP48E1-matched simulation)

## Final Recommendation
- Overall verdict: **Strong submission**
- One of the most technically complete submissions — the integer-exact RTL-vs-Python verification in the CSV file is concrete, reproducible evidence. Strong FPGA targeting with Basys3 resource analysis. The main gap is limited Cognichip platform documentation.

## Actionable Feedback (Most Important Improvements)
1. Document Cognichip platform usage explicitly — how AI tools were used to generate or optimize the RTL design.
2. Add Vivado implementation results (post-synthesis timing report, actual resource utilization) to supplement the estimated numbers.
3. Extend the RTL verification to more pixels/neurons — 4 test cases is a good start but a wider sweep would be more convincing.

## Issues (If Any)
- No mention of Cognichip in examined source files; may limit platform usage scoring significantly.
