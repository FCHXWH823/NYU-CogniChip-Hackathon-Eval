# CogniChip Hackathon Evaluation Receipt — group019

## Submission Overview
- Team folder: `group019`
- Slides: `slides/RISC-V CPU Design with AI.pdf`
- Video: None
- Code/Repo: `src/5-Stage-Pipeline-RISC-V/` (28 files; 5-stage RV32I pipeline RTL modules, testbenches, Yosys synthesis scripts, memory model)
- Evidence completeness: Partial — RTL and testbenches are present with Yosys synthesis scripts; no EDA results, no simulation logs committed; slides describe methodology but quantitative evidence is limited.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 14 | 30 |
| Cognichip Platform Usage | 11 | 20 |
| Innovation & Creativity | 8 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 3 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 2 | 10 |
| **Total** | **51** | **110** |

## Detailed Evaluation

### A) Technical Correctness (14/30)
- Strengths:
  - Complete 5-stage pipeline RTL committed: `riscv_cpu_top.sv`, `riscv_alu.sv`, `control_unit.sv`, `forwarding_unit.sv`, `branch_unit.sv`, `pipeline_if_id.sv`, `pipeline_id_ex.sv`, `pipeline_ex_mem.sv`, `pipeline_mem_wb.sv`, `immediate_generator.sv`, `register_file.sv`, `program_counter.sv`, `load_store_unit.sv`, `instruction_rom.sv`, `simple_memory.sv`.
  - Testbenches for each module: `tb_riscv_cpu_top.sv`, `tb_riscv_alu.sv`, `tb_control_unit.sv`, `tb_forwarding_unit.sv`, etc.
  - Yosys synthesis scripts committed (`synth_alu.ys`, `synth_alu_simple.ys`).
  - Forwarding unit included — hazard handling present.
- Weaknesses / Missing evidence:
  - No EDA `eda_results.json`, no simulation log files.
  - No waveform files.
  - Synthesis scripts present but synthesis results not committed.
  - Cannot verify tests pass from committed artifacts alone.
- Key evidence:
  - (src/5-Stage-Pipeline-RISC-V/src/ — 16 RTL files + 8 testbench files)
  - (src/5-Stage-Pipeline-RISC-V/src/synth_alu_simple.ys — Yosys script)
  - (src/5-Stage-Pipeline-RISC-V/src/tb_riscv_cpu_top.sv — top-level testbench)

### B) Effective Use of the Cognichip Platform (11/20)
- Strengths:
  - Slides describe "Generative AI (Cognichip) as a primary development tool" for RTL generation.
  - Cognichip used for comprehensive testbench generation.
  - Verilator simulation mentioned in workflow.
- Weaknesses / Missing evidence:
  - No Cognichip EDA results — no `eda_results.json` files.
  - Specific Cognichip features or prompts not detailed.
  - Verilator simulation mentioned but results not committed.
- Key evidence:
  - (slides/RISC-V CPU Design with AI.pdf — "leveraged Large Language Models to accelerate RTL code generation")

### C) Innovation & Creativity (8/15)
- Strengths:
  - Targets Basys 3 FPGA specifically for "low-cost hardware" deployment.
  - Full hazard handling (forwarding unit + stalling) included.
  - AI-assisted generation of both RTL and comprehensive testbenches.
- Weaknesses:
  - 5-stage RV32I pipeline is a standard educational design.
  - No novel architectural features.
- Key evidence:
  - (slides/RISC-V CPU Design with AI.pdf — "Basys 3 FPGA", "RV32I base instruction set")

### D) Clarity of Presentation (10/25)
#### D1) Slides clarity (7/10)
- Notes: Clear slides with problem domain, innovation description, design methodology, architecture overview. Good concise presentation style appropriate for the project scope.
- Evidence: (slides/RISC-V CPU Design with AI.pdf)

#### D2) Video clarity (0/10)
- Notes: No video submitted.
- Evidence: No video directory.

#### D3) Repo organization (3/5)
- Notes: All RTL in `src/` subdirectory, README present but minimal (one line). Yosys scripts present. Organization is functional but documentation is sparse.
- Evidence: (src/5-Stage-Pipeline-RISC-V/README.md — minimal)

### E) Potential Real-World Impact (6/10)
- Notes: Custom RV32I for Basys 3 demonstrates democratized chip design. Low-cost FPGA deployment is practical for hobbyists and education.
- Evidence: (slides/RISC-V CPU Design with AI.pdf — "democratized silicon")

### Bonus) FPGA / Tiny Tapeout Targeting (+2/10)
- Notes: Basys 3 is identified as the target FPGA board. Yosys synthesis scripts are present. However, no timing reports, synthesis results, or bitstream evidence committed. Very early-stage FPGA targeting.
- Evidence: (src/5-Stage-Pipeline-RISC-V/src/synth_alu_simple.ys — Yosys synthesis script)

## Final Recommendation
- Overall verdict: **Below Average**
- Complete RTL implementation with testbenches is a reasonable achievement, but the lack of any committed simulation results or synthesis outputs prevents verification of the claimed functionality. The README is minimal and no Cognichip EDA evidence is present.

## Actionable Feedback (Most Important Improvements)
1. Run simulations and commit EDA results or Verilator log files to demonstrate test outcomes.
2. Run Yosys synthesis and commit the synthesis reports.
3. Expand the README with architecture description, build instructions, and test results.

## Issues (If Any)
- No video submitted.
- No simulation results, no EDA results, no waveforms committed.
- README is a single line.
