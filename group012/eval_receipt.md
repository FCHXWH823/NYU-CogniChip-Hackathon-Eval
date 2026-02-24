# CogniChip Hackathon Evaluation Receipt — group012

## Submission Overview
- Team folder: `group012`
- Slides: `slides/Cognichip_TinyMAC.pdf`
- Video: None
- Code/Repo: `src/Cognichip-Hackson/` (9 files; 2×2 MAC array as zip and 4×4 MAC array as RTL with testbench and DEPS.yml; no EDA simulation results)
- Evidence completeness: Partial — slides describe the design and claim simulation evidence but no EDA results, waveforms, or simulation logs are committed to the repository.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 10 | 30 |
| Cognichip Platform Usage | 10 | 20 |
| Innovation & Creativity | 7 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 3 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **43** | **110** |

## Detailed Evaluation

### A) Technical Correctness (10/30)
- Applying cap: no concrete simulation/verification evidence in repository.
- Strengths:
  - RTL design files committed for 4×4 MAC: `mac_unit.sv`, `mac_array_4x4.sv`, `controller_fsm.sv`.
  - Testbench file `tb_mac_array_4x4.sv` committed.
  - `DEPS.yml` for Cognichip present.
  - 2×2 MAC array also included as a zip.
  - README describes clear architecture with 8-bit inputs, 20-bit accumulator.
  - Slides describe "Verification and Simulation Evidence" section (content not accessible without viewing PDF as images).
- Weaknesses / Missing evidence:
  - No `eda_results.json`, no `.fst` waveform, no simulation logs in repository.
  - DEPS.yml present suggesting Cognichip simulation was planned but results not committed.
  - "Verification and Simulation Evidence" section in slides cannot be confirmed without running the simulation.
- Key evidence:
  - (src/Cognichip-Hackson/4x4 8-bit MAC/tb_mac_array_4x4.sv — testbench exists)
  - (src/Cognichip-Hackson/4x4 8-bit MAC/DEPS.yml — Cognichip simulation config)
  - No eda_results.json found.

### B) Effective Use of the Cognichip Platform (10/20)
- Applying cap: usage is described but specific steps/features not confirmed.
- Strengths:
  - DEPS.yml is committed — this is the Cognichip EDA configuration file indicating the platform was used or intended to be used.
  - Slides reference Cognichip platform usage.
- Weaknesses / Missing evidence:
  - No EDA results confirming simulation was actually run on Cognichip.
  - No description of specific Cognichip features used or prompts given.
- Key evidence:
  - (src/Cognichip-Hackson/4x4 8-bit MAC/DEPS.yml — Cognichip config file)

### C) Innovation & Creativity (7/15)
- Strengths:
  - Evolution from 2×2 to 4×4 MAC shows iterative development.
  - MAC array is a fundamental AI accelerator building block.
  - Hierarchical design (mac_unit → mac_array + controller_fsm) shows good design methodology.
- Weaknesses:
  - MAC array is a standard textbook design — no novel features or applications.
  - 4×4 8-bit MAC is a very basic accelerator component.
- Key evidence:
  - (slides/Cognichip_TinyMAC.pdf — "TinyMAC: From 2×2 8-bit Mac Array to 4×4 Micro-Accelerator")
  - (src/Cognichip-Hackson/4x4 8-bit MAC/mac_array_4x4.sv)

### D) Clarity of Presentation (10/25)
#### D1) Slides clarity (7/10)
- Notes: Well-structured slides with Introduction, Architecture and RTL, Cognichip Platform Usage, and Verification and Simulation Evidence sections. Clean academic presentation with clear motivation.
- Evidence: (slides/Cognichip_TinyMAC.pdf — structured 4-section presentation)

#### D2) Video clarity (0/10)
- Notes: No video submitted.
- Evidence: No video directory.

#### D3) Repo organization (3/5)
- Notes: Small but organized with `4x4 8-bit MAC/` subdirectory containing RTL, testbench, and DEPS.yml. README present. The 2×2 array is only included as a zip (not extracted), reducing accessibility.
- Evidence: (src/Cognichip-Hackson/ — organized structure)

### E) Potential Real-World Impact (6/10)
- Notes: MAC arrays are fundamental to AI/ML inference and DSP pipelines. A compact, synthesizable design is practically useful, but the 4×4 8-bit scale is too small for real-world deployment without significant scaling.
- Evidence: (slides/Cognichip_TinyMAC.pdf — "foundation of matrix multiplication, CNNs, digital filters")

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA or tapeout evidence.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Below Average**
- The design scope is modest (MAC array) and executed cleanly in terms of code structure, but simulation evidence was not committed. The DEPS.yml suggests Cognichip simulation was planned; committing those results would significantly improve the score.

## Actionable Feedback (Most Important Improvements)
1. Run the Cognichip simulation and commit the EDA results (eda_results.json, dumpfile.fst) to the repository.
2. Extract the 2×2 MAC zip file so the code is directly accessible.
3. Add assertions in the testbench with explicit PASS/FAIL output for each test case.

## Issues (If Any)
- No video submitted.
- No EDA simulation results committed despite DEPS.yml being present.
- 2×2 MAC only provided as a zip file, not as accessible source code.
