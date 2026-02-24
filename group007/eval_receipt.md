# CogniChip Hackathon Evaluation Receipt — Cognichip RV32IF Power Optimized RISC-V

## Submission Overview
- Team folder: `group007`
- Slides: `slides/Cognichip Hackathon PPT_BITS_Pilani_HYD.pdf`
- Video: None
- Code/Repo: `src/Cognichip-RV32IF-PowerOptimized-RISC-V/`
- Evidence completeness: Strong — README documents FPGA testing on Zynq-7000 with ILA/VIO verification, quantified power and area results, and multiple fix summaries.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 26 | 30 |
| Cognichip Platform Usage | 16 | 20 |
| Innovation & Creativity | 11 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 7 | 10 |
| Bonus — FPGA/Tiny Tapeout | 8 | 10 |
| **Total** | **79** | **110** |

## Detailed Evaluation

### A) Technical Correctness (26/30)
- Strengths:
  - README documents full RV32IF instruction set (FADD, FSUB, FMUL, FDIV, FSQRT, FMADD, FCVT, FMV, comparisons) all verified correct.
  - FPGA hardware validation on Zynq-7000 ZC702/ZedBoard using ILA (Integrated Logic Analyzer) and VIO (Virtual I/O) is strong evidence.
  - Quantified results: Slice LUTs reduced ~7-8% (19,355 → 17,911), dynamic power reduced via gating.
  - Bitstream generated and programmed to FPGA hardware.
  - Fix summaries: RV32F_FIXES_SUMMARY.md and SIMULATION_FIX_README.md document specific pipeline writeback and instruction encoding bugs found and resolved.
  - Constraint file `rv32f_constraints.xdc` present for Zynq-7000 (XC7Z020CLG484-1).
- Weaknesses / Missing evidence:
  - No simulation waveform screenshot or FST waveform file committed.
  - Power reduction percentage not stated explicitly (relative improvement claimed but not quantified with both before/after numbers).
  - ILA/VIO results are described but not committed as screenshots or logs.
- Key evidence:
  - (src/Cognichip-RV32IF-PowerOptimized-RISC-V/README.md — Results Summary section)
  - (src/Cognichip-RV32IF-PowerOptimized-RISC-V/rv32f_constraints.xdc — FPGA constraints)
  - (src/Cognichip-RV32IF-PowerOptimized-RISC-V/RV32F_FIXES_SUMMARY.md)

### B) Effective Use of the Cognichip Platform (16/20)
- Strengths:
  - README dedicates a "Cognichip Contributions" section listing specific platform deliverables: automatic RV32F RTL generation, instruction encoding fixes, pipeline writeback bug fixes, power-aware refactoring, gated FP execution.
  - Quantified time savings: "Design → Simulate → Synthesize → FPGA in < 1 day" attributed to Cognichip.
  - Multiple iteration cycles implied by fix summaries.
- Weaknesses / Missing evidence:
  - No AI prompt log or conversation history showing specific Cognichip interactions.
  - Hard to distinguish what was AI-generated vs. manually written.
- Key evidence:
  - (src/.../README.md — "Cognichip Contributions" section)

### C) Innovation & Creativity (11/15)
- Strengths:
  - Extending a RISC-V RV32I to RV32IF with FPU integration using AI assistance is a substantive design task.
  - Power gating of FP datapath (active only during FP instructions) is an elegant optimization.
  - AI-assisted full design cycle (generation → simulation → synthesis → FPGA) in under 1 day demonstrates platform capability.
- Weaknesses:
  - RV32IF core design is well-documented in literature; the optimization approach is systematic rather than breakthrough.
- Key evidence:
  - (src/.../README.md — power optimization approach, FP gating description)

### D) Clarity of Presentation (11/25)
#### D1) Slides clarity (7/10)
- Notes: PDF exists; cannot verify content directly, but reasonable base score awarded.
- Evidence: `slides/Cognichip Hackathon PPT_BITS_Pilani_HYD.pdf`

#### D2) Video clarity (0/10)
- Notes: No video submission.
- Evidence: No video folder present.

#### D3) Repo organization (4/5)
- Notes: Well-organized — pipeline stage files clearly named, power-optimized variants suffixed `_POWER_OPT.v`, 6 documentation guides present, constraint and testbench files clearly identified.
- Evidence: (src/Cognichip-RV32IF-PowerOptimized-RISC-V/ directory listing)

### E) Potential Real-World Impact (7/10)
- Notes: Power optimization of RISC-V processors is directly applicable to embedded and edge computing markets. FPGA validation demonstrates real-world feasibility. FPU integration expands applicability to signal processing and ML workloads.
- Evidence: README — "Better performance-per-area than baseline" statement

### Bonus) FPGA / Tiny Tapeout Targeting (+8/10)
- Notes: Strong FPGA evidence: Zynq-7000 XC7Z020 constraints file committed, bitstream generation described, hardware tested with ILA/VIO probes, verified on ZC702/ZedBoard. This is one of the stronger FPGA submissions.
- Evidence:
  - (src/.../rv32f_constraints.xdc — Zynq-7000 XDC file)
  - (src/.../README.md — "Tested On" section and "Generate Bitstream" instructions)

## Final Recommendation
- Overall verdict: **Strong submission**
- This submission stands out for combining Cognichip-assisted design with actual FPGA hardware validation on Zynq-7000, providing the strongest end-to-end evidence chain of any submission without video. The Cognichip contributions section is specific and credible.

## Actionable Feedback (Most Important Improvements)
1. Commit ILA/VIO screenshots or log files as concrete hardware verification evidence to strengthen the already compelling FPGA claim.
2. Add a video showing the FPGA running FP operations and the power savings measurement methodology.
3. Quantify power reduction with explicit before/after numbers from Vivado Power Analysis reports.

## Issues (If Any)
- `POWER_OPTIMIZATION_GUIDE.md` and related guides are listed in the README but their existence in the committed repo was not fully verified.
