# CogniChip Hackathon Evaluation Receipt — group007

## Submission Overview
- Team folder: `group007`
- Slides: `slides/Cognichip Hackathon PPT_BITS_Pilani_HYD.pdf`
- Video: None
- Code/Repo: `src/Cognichip-RV32IF-PowerOptimized-RISC-V/` (61 files; RV32IF processor RTL, power-optimized modules, testbenches, constraints file, SIMULATION_FIX_README)
- Evidence completeness: Strong — slides include FPGA waveforms (ILA/VIO), power/LUT measurements; RTL modules and constraints file present; simulation fix README indicates debugging history; no video submitted.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 22 | 30 |
| Cognichip Platform Usage | 16 | 20 |
| Innovation & Creativity | 10 | 15 |
| Clarity — Slides | 9 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 3 | 5 |
| Potential Real-World Impact | 7 | 10 |
| Bonus — FPGA/Tiny Tapeout | 8 | 10 |
| **Total** | **75** | **110** |

## Detailed Evaluation

### A) Technical Correctness (22/30)
- Strengths:
  - FPGA validation on Zynq-7000 (XC7Z020CLG484-1) claimed, with ILA waveforms and VIO screenshots shown in slides.
  - Quantitative metrics: 7.5% LUT reduction (19,355 → 17,911), 38% power reduction (0.243W → 0.151W).
  - FP operation waveforms shown (add, sub, mul, div, sqrt, min, max, compare, convert, fused multiply-add).
  - Constraints file (`rv32f_constraints.xdc`) committed confirming FPGA targeting.
  - Power-optimized variants with `_POWER_OPT.v` suffix clearly separated.
- Weaknesses / Missing evidence:
  - `SIMULATION_FIX_README.md` in repo suggests simulation issues were encountered.
  - No Cognichip EDA `eda_results.json` in repository — FPGA validation is from Vivado, not Cognichip platform.
  - FP waveform and power screenshots are in slides (images) but not as committed log files.
  - Testbench (`tb_RISC_V_RV32F_PROCESSOR_POWER_OPT.v`) present but no sim log showing pass/fail.
- Key evidence:
  - (slides/Cognichip Hackathon PPT_BITS_Pilani_HYD.pdf — ILA Waveform, VIO Output screenshots)
  - (slides/Cognichip Hackathon PPT_BITS_Pilani_HYD.pdf — power comparison table: 0.243W → 0.151W)
  - (src/Cognichip-RV32IF-PowerOptimized-RISC-V/rv32f_constraints.xdc — Zynq-7000 constraints)
  - (src/Cognichip-RV32IF-PowerOptimized-RISC-V/SIMULATION_FIX_README.md)

### B) Effective Use of the Cognichip Platform (16/20)
- Strengths:
  - Very detailed description of Cognichip use: FPU integration, instruction encoding fix, RTL refactoring, power optimization, gating strategies.
  - Claims "Design-to-FPGA completed within half a day using Cognichip."
  - Slides have a dedicated "Cognichip: Strengths and Improvement Areas" section with specific pros/cons.
  - Describes Cognichip as "effective AI co-designer" with specific contributions listed.
- Weaknesses / Missing evidence:
  - No Cognichip simulation logs (eda_results.json) — FPGA synthesis used Vivado, not Cognichip EDA.
  - "Half a day" claim impressive but unverified.
- Key evidence:
  - (slides/Cognichip Hackathon PPT_BITS_Pilani_HYD.pdf — "Cognichip: Strengths and Improvement Areas")
  - (slides/Cognichip Hackathon PPT_BITS_Pilani_HYD.pdf — "Design-to-FPGA completed within half a day")

### C) Innovation & Creativity (10/15)
- Strengths:
  - Extension from RV32I to RV32IF with FPU integration via Cognichip is a practical contribution.
  - Power gating and enable-based execution for FP units is a real optimization technique.
  - Demonstrates Cognichip as hardware co-designer for a complex ISA extension.
- Weaknesses:
  - RV32IF processor is a standard design task; power optimization via clock gating is well-known.
  - No novel architectural features beyond standard pipeline + FPU.
- Key evidence:
  - (slides/Cognichip Hackathon PPT_BITS_Pilani_HYD.pdf — "Baseline RV32I extended to RV32IF")
  - (src/Cognichip-RV32IF-PowerOptimized-RISC-V/RISC_V_RV32F_PROCESSOR_POWER_OPT.v)

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (9/10)
- Notes: Very professional slides with quantitative metrics, waveform screenshots (ILA/VIO), architecture description, power comparison charts, and balanced pros/cons. Well-structured conclusion.
- Evidence: (slides/Cognichip Hackathon PPT_BITS_Pilani_HYD.pdf — waveforms, power charts, conclusion)

#### D2) Video clarity (0/10)
- Notes: No video submitted.
- Evidence: No video directory.

#### D3) Repo organization (3/5)
- Notes: README is detailed and well-structured with clear module listing. However, `SIMULATION_FIX_README.md` suggests the simulation setup was not clean. Large number of files (61) but organization is reasonable.
- Evidence: (src/Cognichip-RV32IF-PowerOptimized-RISC-V/README.md)

### E) Potential Real-World Impact (7/10)
- Notes: Power-optimized RV32IF processor targeting Zynq-7000 has practical applications in embedded systems. 38% power reduction is meaningful for battery-powered devices. The methodology for Cognichip-assisted power optimization is replicable.
- Evidence: (slides/Cognichip Hackathon PPT_BITS_Pilani_HYD.pdf — power comparison charts)

### Bonus) FPGA / Tiny Tapeout Targeting (+8/10)
- Notes: Strong FPGA evidence: Zynq-7000 (XC7Z020CLG484-1) constraints file committed, bitstream generated, ILA waveforms and VIO output screenshots in slides, power reports from Vivado. Claims functional validation on board.
- Evidence:
  - (src/Cognichip-RV32IF-PowerOptimized-RISC-V/rv32f_constraints.xdc — board constraints)
  - (slides/Cognichip Hackathon PPT_BITS_Pilani_HYD.pdf — ILA waveform, VIO Output, power reports)

## Final Recommendation
- Overall verdict: **Strong submission — best FPGA evidence in the cohort**
- Impressive FPGA validation with quantitative power and area measurements. The Cognichip use is well-documented with specific contributions described. The main weaknesses are the absence of Cognichip EDA simulation logs (Vivado used instead), a SIMULATION_FIX README suggesting initial issues, and no video.

## Actionable Feedback (Most Important Improvements)
1. Commit Vivado synthesis/implementation reports as files (not just screenshots) for full reproducibility.
2. Resolve the simulation issues noted in SIMULATION_FIX_README and commit clean simulation logs.
3. Record a short video demonstrating the FPGA running FP operations.

## Issues (If Any)
- No video submitted.
- `SIMULATION_FIX_README.md` indicates simulation reproducibility issues.
- No Cognichip EDA results — FPGA validation was via Vivado, not Cognichip platform.
