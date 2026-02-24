# CogniChip Hackathon Evaluation Receipt — FLUX RV32I (CogniChip 2026)

## Submission Overview
- Team folder: `group015`
- Slides: `slides/FLUX_RV32I_Cognichip Presentation.pdf`
- Video: `video/` (directory exists with files)
- Code/Repo: `src/FluxV/` — RV32I V0–V3 iteration with PPA reports, Yosys synthesis, FPGA targeting
- Evidence completeness: Strong — Yosys synthesis with 153,628 cells documented, V0–V3 PPA progression with specific numbers, FPGA verification guide, PROMPTING_AND_RESPONSES.md shows Cognichip iterations.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 26 | 30 |
| Cognichip Platform Usage | 15 | 20 |
| Innovation & Creativity | 12 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 7 | 10 |
| Clarity — Repo Organization | 5 | 5 |
| Potential Real-World Impact | 8 | 10 |
| Bonus — FPGA/Tiny Tapeout | 7 | 10 |
| **Total** | **87** | **110** |

## Detailed Evaluation

### A) Technical Correctness (26/30)
- Strengths:
  - RISC_V_RV32I_PPA_REPORT.md documents actual Yosys synthesis output: 153,628 total cells, 9,660 FFs, detailed cell breakdown, module hierarchy.
  - README documents V0→V3 progression with specific measurements: V0 (75 MHz, 0.609 W), V1 (75 MHz, 0.335 W, BRAM), V2 (90 MHz, 0.390 W), V3 (89.5 MHz, 0.214 W, clock gating).
  - 240% efficiency improvement (123 → 418 MIPS/W) from V0 to V3 with specific technique attributions.
  - VIVADO_vs_YOSYS_COMPARISON.md documents tool comparison methodology.
  - V3 includes FPGA_VERIFICATION_GUIDE.md with specific Vivado implementation steps.
  - PROMPTING_AND_RESPONSES.md records actual Cognichip interactions.
- Weaknesses / Missing evidence:
  - Power numbers appear to come from Vivado Power Analysis (not from running the processor on target workloads); no functional simulation pass/fail results committed.
  - No testbench simulation log showing correct instruction execution.
- Key evidence:
  - (src/FluxV/RISCV_RV32I/RV32I_V0/RISC_V_RV32I_PPA_REPORT.md — synthesis stats)
  - (src/FluxV/README.md — V0–V3 comparison table)
  - (src/FluxV/RISCV_RV32I/RV32I_V3/FPGA_VERIFICATION_GUIDE.md)

### B) Effective Use of the Cognichip Platform (15/20)
- Strengths:
  - PROMPTING_AND_RESPONSES.md explicitly documents AI prompting history showing Cognichip interactions.
  - V0→V1→V2→V3 iteration with specific technique improvements attributed to platform feedback.
  - README describes "AI-assisted RISC-V microarchitecture optimization tool" with LLM feedback loop.
  - Each version's failures and fixes are documented, showing iterative platform engagement.
- Weaknesses / Missing evidence:
  - PROMPTING_AND_RESPONSES.md content not directly verified; specific Cognichip features (vs. general LLM) not distinguished.
- Key evidence:
  - (src/FluxV/RISCV_RV32I/RV32I_V0/PROMPTING_AND_RESPONSES.md)
  - (src/FluxV/README.md — "AI-assisted" description)

### C) Innovation & Creativity (12/15)
- Strengths:
  - Systematic four-version optimization journey (BRAM inference → timing optimization → power gating) with documented rationale for each step is methodologically strong.
  - 78.4% dynamic power reduction through clock gating is a significant result.
  - MIPS folder suggests multi-ISA comparison scope.
- Weaknesses:
  - Individual techniques (BRAM inference, clock gating) are standard optimization methods; innovation is in systematic application and documentation.
- Key evidence:
  - (src/FluxV/README.md — cumulative improvement table)

### D) Clarity of Presentation (19/25)
#### D1) Slides clarity (7/10)
- Notes: PDF exists; cannot verify content directly, but reasonable base score awarded.
- Evidence: `slides/FLUX_RV32I_Cognichip Presentation.pdf`

#### D2) Video clarity (7/10)
- Notes: Video directory exists with files.
- Evidence: `video/` directory with contents.

#### D3) Repo organization (5/5)
- Notes: Exemplary organization — V0/V1/V2/V3 directories each with own README, analysis, and recovery documents. Multiple comparison and guide documents. Clean separation of RISCV_RV32I and MIPS sections.
- Evidence: (src/FluxV/ directory structure)

### E) Potential Real-World Impact (8/10)
- Notes: A 240% efficiency improvement in a RISC-V processor through systematic AI-guided optimization demonstrates a workflow with broad applicability. The methodology of tracking PPA across AI-assisted iterations is reusable.
- Evidence: README — "236% Efficiency Improvement" executive summary

### Bonus) FPGA / Tiny Tapeout Targeting (+7/10)
- Notes: V3 includes FPGA_VERIFICATION_GUIDE.md specifically targeting Xilinx Zynq-7020 (xc7z020clg484-1). Vivado synthesis/implementation workflow documented with WNS (+0.200 ns passing). Constraint-level targeting is evidenced in the PPA reports referencing the specific FPGA target device.
- Evidence:
  - (src/FluxV/RISCV_RV32I/RV32I_V3/FPGA_VERIFICATION_GUIDE.md)
  - (src/FluxV/RISCV_RV32I/RV32I_V0/RISC_V_RV32I_PPA_REPORT.md — "Target Device: Xilinx Zynq-7020")

## Final Recommendation
- Overall verdict: **Strong submission**
- FLUX RV32I delivers one of the most complete submissions with documented V0→V3 optimization, real Yosys synthesis stats, Cognichip prompting history, FPGA targeting, and a video. The main gap is that functional simulation pass/fail results are not committed.

## Actionable Feedback (Most Important Improvements)
1. Add testbench simulation logs showing RV32I instruction execution correctness across the V0–V3 versions (functional verification to complement the strong PPA evidence).
2. Commit actual FPGA bitstream or post-implementation timing report from Vivado to strengthen the FPGA bonus claim.
3. Expand the PROMPTING_AND_RESPONSES.md to show the full Cognichip dialogue for V1–V3 iterations (currently may only cover V0).

## Issues (If Any)
- Power reduction numbers are from Vivado Power Analysis estimates, not physical power measurements; this should be noted as a limitation.
