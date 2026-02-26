# CogniChip Hackathon Evaluation Receipt — group011

## Submission Overview
- Team folder: `group011`
- Slides: `slides/cognichip_slides.pdf`
- Video: `video/Seth-llm-cognichip.mp4`
- Code/Repo: `src/CogniChip_SETH/alu/` — 8-bit ALU modules (add, subtract, bitwise ops, compare, shift), `tb_alu_8bit.v`, `8-bit-ALU-in-verilog/` with Yosys synthesis artifacts, `CogniChip_ALU/` with 11 Cognichip EDA runs
- Evidence completeness: Good — 47/47 tests passed in first Cognichip EDA run; Yosys synthesis report and area data committed; 5 of 11 EDA runs passed.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 18 | 30 |
| Cognichip Platform Usage | 13 | 20 |
| Innovation & Creativity | 6 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 6 | 10 |
| Clarity — Repo Organization | 3 | 5 |
| Potential Real-World Impact | 4 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **57** | **110** |

## Detailed Evaluation

### A) Technical Correctness (18/30)
- Strengths:
  - `sim_alu` Cognichip EDA run passed: 47/47 tests verified including ADD, SUB, AND, OR, XOR, NAND, NOR, NOT, SHL, SHR, CMP (LT/GT/EQ), PASS operations. `TEST PASSED` confirmed.
  - `sim_alu_custom` (2 passes) and `sim_alu_custom_design` (1 pass) also confirmed.
  - Yosys synthesis completed with area report (`area_report.txt`, `alu8bit.json`) for ICE40 target — concrete synthesis evidence.
- Weaknesses / Missing evidence:
  - 6 of 11 EDA runs failed (`return_code: 255` for `sim_alu_custom_design` first attempt).
  - `sim_alu_custom_design` passing run shows the simulation terminated at 160 ps without explicit test assertions or a TEST PASSED message — unclear functional coverage.
  - Yosys synthesis has warnings (`wire '\b_in' is assigned in a block` — potential race condition).
- Key evidence:
  - (src/CogniChip_SETH/alu/CogniChip_ALU/simulation_results/sim_2026-02-19T21-51-20-580Z/eda_results.json) — `sim_alu`, 47/47 PASSED
  - (src/CogniChip_SETH/alu/8-bit-ALU-in-verilog/area_report.txt) — Yosys ICE40 synthesis report

### B) Effective Use of the Cognichip Platform (13/20)
- Strengths:
  - 11 Cognichip EDA runs committed, showing active debugging iteration.
  - Separate `CogniChip_ALU/` directory demonstrates the team structured their project specifically for the Cognichip platform.
  - `area_report.txt` via Yosys suggests design was also explored for synthesis.
- Weaknesses / Missing evidence:
  - 6 of 11 runs failed; custom design testbench lacks clear assertions.
  - DEPS.yml not found in the primary `CogniChip_ALU/` directory.
- Key evidence:
  - (src/CogniChip_SETH/alu/CogniChip_ALU/simulation_results/) — 11 EDA run directories

### C) Innovation & Creativity (6/15)
- Strengths:
  - Custom 8-bit ALU with 13 operations (including compare and PASS-through) is more complete than a minimal ALU.
  - Yosys synthesis targeting ICE40 shows awareness of physical implementation.
- Weaknesses:
  - An 8-bit ALU is a classic introductory digital design exercise with limited novelty.
  - No novel architectural feature, algorithm, or hardware acceleration concept introduced.

### D) Clarity of Presentation (16/25)
#### D1) Slides clarity (7/10)
- Notes: PDF covers the SETH framework, ALU design, and Cognichip platform use.
- Evidence: (slides/cognichip_slides.pdf)

#### D2) Video clarity (6/10)
- Notes: Video present; LLM + Cognichip topic suggested by filename.
- Evidence: (video/Seth-llm-cognichip.mp4)

#### D3) Repo Organization (3/5)
- Notes: Repository structure is complex (two parallel ALU directories: `8-bit-ALU-in-verilog/` and `CogniChip_ALU/`). Quartus project artifacts committed (`db/`, `c5_pin_model_dump.txt`, `qar_info.json`). Top-level README is sparse. No unified DEPS.yml.
- Evidence: (src/CogniChip_SETH/README.md), (src/CogniChip_SETH/alu/8-bit-ALU-in-verilog/README.md)

### E) Potential Real-World Impact (4/10)
- Notes: An 8-bit ALU is a foundational building block; as a standalone submission its real-world impact is limited. The SETH framework (from the README) suggests a broader educational LLM-hardware toolchain concept, but it is not substantiated by the submitted code.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: Quartus artifacts suggest Altera FPGA familiarity, but no FPGA synthesis report or bitstream committed.
- Evidence: None confirming FPGA synthesis/targeting was completed.

## Final Recommendation
- Overall verdict: **Average** (57/110)
- The 47-test passing EDA run with explicit LOG assertions is solid technical evidence; Yosys synthesis adds extra value. Score is limited by the simple design scope, complex repo organisation, and non-passing custom testbenches.

## Actionable Feedback (Most Important Improvements)
1. Add explicit `TEST PASSED` / `TEST FAILED` assertions to the custom design testbench to make pass/fail unambiguous.
2. Clean the repo structure: merge the two ALU directories, remove Quartus build artifacts, add a top-level DEPS.yml.
3. Extend the ALU (e.g., multiply/divide, barrel shifter, saturation arithmetic) to increase the novelty of the design.

## Issues (If Any)
- Quartus EDA build artifacts (`db/`, `c5_pin_model_dump.txt`, `qar_info.json`) committed; should be in `.gitignore`.
- Yosys warns about combinational blocking assignment in `add_subtract_8bit.v`; potential race condition.
- `sim_alu_custom_design` passing run has no functional assertions — pass is vacuous (no errors observed).
