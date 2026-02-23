# CogniChip Hackathon Evaluation Receipt — group007

## Submission Overview
- Team folder: `group007`
- Slides: `slides/Cognichip Hackathon PPT_BITS_Pilani_HYD.pdf`
- Video: `video/Cognichip Hackathon PPT_BITS_Pilani_HYD.mp4`
- Code/Repo: `src/Cognichip-RV32IF-PowerOptimized-RISC-V/` — ~40 Verilog files (pipeline stages, FPU, power-opt variants), XDC constraints (`rv32f_constraints.xdc`), `FPGA_TOP_MODULE.v`, testbenches, extensive documentation (8+ markdown guides); no EDA result files
- Evidence completeness: Weak — extensive code and claims of FPGA validation, but no simulation logs, EDA results, or FPGA synthesis/power reports committed.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 12 | 30 |
| Cognichip Platform Usage | 7 | 20 |
| Innovation & Creativity | 11 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 6 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 7 | 10 |
| Bonus — FPGA/Tiny Tapeout | 3 | 10 |
| **Total** | **57** | **110** |

## Detailed Evaluation

### A) Technical Correctness (12/30)
- Strengths:
  - Comprehensive RTL implementation: 5-stage pipeline (IF/ID/EX/MEM/WB), integer ALU, FP ALU (`FP_ALU.v`, `FP_ALU_SYNTH.v`), FP register file, forwarding units, stalling unit — all committed.
  - Power-optimised variants (`*_POWER_OPT.v`) alongside baseline modules.
  - FPGA top module (`FPGA_TOP_MODULE.v`) and Zynq-7000 XDC constraints (`rv32f_constraints.xdc`) indicate FPGA targeting intent.
- Weaknesses / Missing evidence:
  - Cap rule applied: no simulation logs (Verilator or Vivado), no EDA JSON results, no testbench output showing `PASS`.
  - `POWER_OPTIMIZATION_COMPLETE.txt` is empty (contains only `================`).
  - Claims of Vivado synthesis and FPGA validation on Zynq-7000 XC7Z020 are unsubstantiated — no `.rpt` files.
  - `DEPS.yml` not found; Cognichip EDA was apparently not used to simulate this design.
- Key evidence:
  - (src/Cognichip-RV32IF-PowerOptimized-RISC-V/RISC_V_RV32F_PROCESSOR_POWER_OPT.v) — top-level power-opt RTL
  - (src/Cognichip-RV32IF-PowerOptimized-RISC-V/rv32f_constraints.xdc) — FPGA constraints
  - (src/Cognichip-RV32IF-PowerOptimized-RISC-V/POWER_OPTIMIZATION_COMPLETE.txt) — empty file

### B) Effective Use of the Cognichip Platform (7/20)
- Strengths:
  - README explicitly states "Cognichip was used to integrate RV32F FPU, fix encoding issues, perform RTL refactoring and power optimisation."
  - `Cognichip.code-workspace` committed, showing a Cognichip project workspace was configured.
  - Multiple markdown guide documents (`SIMULATION_FIX_README.md`, `POWER_OPT_FIX_NEEDED.md`, etc.) reference Cognichip-assisted fixes.
- Weaknesses / Missing evidence:
  - No `eda sim` EDA JSON result files committed; no evidence the Cognichip EDA runner was invoked.
  - Cognichip appears to have been used for AI code assistance (generating/fixing RTL), not for simulation runs.
- Key evidence:
  - (src/Cognichip-RV32IF-PowerOptimized-RISC-V/README.md) — Cognichip usage described
  - (src/Cognichip-RV32IF-PowerOptimized-RISC-V/Cognichip.code-workspace) — workspace file

### C) Innovation & Creativity (11/15)
- Strengths:
  - Full RV32IF (integer + floating-point) processor with power optimisation is an ambitious scope.
  - Separate `*_POWER_OPT.v` modules with explicit gating strategy shows design methodology.
  - FPGA targeting with XDC constraints and dedicated top module.
- Weaknesses:
  - Design approach (5-stage pipeline with FPU) is well-established; power techniques (clock gating) are standard.
  - No measured power reduction figures committed.

### D) Clarity of Presentation (17/25)
#### D1) Slides clarity (7/10)
- Notes: PDF covers architecture, ISA support, power optimisation strategy, and FPGA targeting.
- Evidence: (slides/Cognichip Hackathon PPT_BITS_Pilani_HYD.pdf)

#### D2) Video clarity (6/10)
- Notes: Video present but no simulation waveform or FPGA board demo corroborated by committed logs.
- Evidence: (video/Cognichip Hackathon PPT_BITS_Pilani_HYD.mp4)

#### D3) Repo Organization (4/5)
- Notes: Eight markdown guide documents (`POWER_OPTIMIZATION_GUIDE.md`, `FP_DEBUG_GUIDE.md`, `SIMULATION_FIX_README.md`, etc.) show thorough documentation effort. Minor deductions for no DEPS.yml, no simulation results directory, and empty `POWER_OPTIMIZATION_COMPLETE.txt`.
- Evidence: (src/Cognichip-RV32IF-PowerOptimized-RISC-V/README.md)

### E) Potential Real-World Impact (7/10)
- Notes: Power-optimised RISC-V with FPU is relevant for embedded/IoT applications. FPGA validation, if genuine, adds credibility.

### Bonus) FPGA / Tiny Tapeout Targeting (+3/10)
- Notes: `FPGA_TOP_MODULE.v` and `rv32f_constraints.xdc` (Zynq-7000 XC7Z020) are committed, and the README claims FPGA validation. Partial credit for credible FPGA setup; full bonus denied because no synthesis report, timing report, or power report was committed.
- Evidence: (src/Cognichip-RV32IF-PowerOptimized-RISC-V/FPGA_TOP_MODULE.v), (src/Cognichip-RV32IF-PowerOptimized-RISC-V/rv32f_constraints.xdc)

## Final Recommendation
- Overall verdict: **Average** (57/110)
- The volume of code and documentation is impressive, but the complete absence of simulation evidence — whether via Cognichip EDA or Vivado logs — makes correctness claims unverifiable. The POWER_OPTIMIZATION_COMPLETE.txt being empty is particularly concerning.

## Actionable Feedback (Most Important Improvements)
1. Commit Cognichip EDA results (DEPS.yml + `eda sim` JSON outputs) to demonstrate platform simulation.
2. Commit Vivado synthesis/power reports (`.rpt` files) to substantiate the FPGA validation claim.
3. Add a passing testbench run result showing RV32F instructions executing correctly.

## Issues (If Any)
- `POWER_OPTIMIZATION_COMPLETE.txt` is empty — no power reduction data committed.
- No DEPS.yml and no EDA JSON result files; Cognichip simulation not confirmed.
- FPGA validation claimed (Zynq-7000 XC7Z020) but no synthesis/timing/power reports committed.
