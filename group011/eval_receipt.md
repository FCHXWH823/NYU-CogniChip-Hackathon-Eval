# CogniChip Hackathon Evaluation Receipt — CogniChip SETH

## Submission Overview
- Team folder: `group011`
- Slides: `slides/cognichip_slides.pdf`
- Video: None
- Code/Repo: `src/CogniChip_SETH/` — 8-bit ALU in Verilog, plus multiple RISC-V core references
- Evidence completeness: Weak — Verilog files for ALU exist alongside referenced cores, but no simulation logs, testbench run results, or waveforms committed; README is a stub.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 10 | 30 |
| Cognichip Platform Usage | 5 | 20 |
| Innovation & Creativity | 5 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 2 | 5 |
| Potential Real-World Impact | 4 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **33** | **110** |

## Detailed Evaluation

### A) Technical Correctness (10/30)
- Strengths:
  - Verilog files exist for an 8-bit ALU (add_4bit.v, add_8bit.v, add_subtract_8bit.v, alu8bit.json) in the `alu/8-bit-ALU-in-verilog/` folder.
  - Waveform file (`add_subtract_8bit.vwf`) and JSON synthesis output present — suggesting some simulation was run.
  - Repository also includes `core_uriscv` and `picorv32` reference cores, indicating broader RISC-V ambition.
- Weaknesses / Missing evidence:
  - No testbench output logs or documented test results.
  - README top-level is a stub ("# CogniChip_SETH — Cognichip Challenge") with only an image reference.
  - No description of what was designed, tested, or demonstrated.
  - Cap applied: no concrete simulation/verification evidence with explicit pass/fail results.
- Key evidence:
  - (src/CogniChip_SETH/alu/8-bit-ALU-in-verilog/ — Verilog files)
  - (src/CogniChip_SETH/alu/8-bit-ALU-in-verilog/add_subtract_8bit.vwf — waveform file)

### B) Effective Use of the Cognichip Platform (5/20)
- Strengths:
  - Project submitted to Cognichip Hackathon.
- Weaknesses / Missing evidence:
  - No description of Cognichip platform usage anywhere in the repository.
  - README mentions "Cognichip Challenge" but provides no workflow details.
- Key evidence:
  - (src/CogniChip_SETH/README.md — title only)

### C) Innovation & Creativity (5/15)
- Strengths:
  - The presence of `core_uriscv` and `picorv32` alongside the custom ALU suggests the team explored multiple design paths.
- Weaknesses:
  - An 8-bit ALU is a very standard introductory design exercise with minimal novelty.
  - No evidence of a higher-level system integration.
- Key evidence:
  - (src/CogniChip_SETH/ — directory contents)

### D) Clarity of Presentation (9/25)
#### D1) Slides clarity (7/10)
- Notes: PDF exists; cannot verify content directly, but reasonable base score awarded.
- Evidence: `slides/cognichip_slides.pdf`

#### D2) Video clarity (0/10)
- Notes: No video submission.
- Evidence: No video folder present.

#### D3) Repo organization (2/5)
- Notes: Sub-directory structure exists (alu/8-bit-ALU-in-verilog/) but the top-level README is effectively empty. Multiple included reference cores (picorv32, core_uriscv) clutter the repo without explanation.
- Evidence: (src/CogniChip_SETH/ structure)

### E) Potential Real-World Impact (4/10)
- Notes: An 8-bit ALU is a basic building block; alone it has limited real-world impact. The presence of RISC-V core references hints at larger ambitions that were not realized in this submission.
- Evidence: (src/CogniChip_SETH/ directory)

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No evidence of FPGA or Tiny Tapeout targeting.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Weak submission**
- The submission has Verilog files present but is essentially undocumented. The design scope (8-bit ALU) is minimal for a hackathon, and the complete absence of documented test results or Cognichip workflow description limits the evaluation severely.

## Actionable Feedback (Most Important Improvements)
1. Add a proper README describing the design goals, implemented components, and how Cognichip was used.
2. Commit testbench run logs or waveform screenshots showing correct ALU operation across all operations.
3. Integrate the ALU into a larger system (RISC-V CPU or datapath) to demonstrate real design scope — the picorv32 reference suggests this was a planned direction.

## Issues (If Any)
- Including third-party cores (picorv32, core_uriscv) without explanation inflates the apparent repository size without adding to the original design work.
