# CogniChip Hackathon Evaluation Receipt — RISC-V CPU Design with AI (5-Stage Pipeline)

## Submission Overview
- Team folder: `group019`
- Slides: `slides/RISC-V CPU Design with AI.pdf`
- Video: None
- Code/Repo: `src/5-Stage-Pipeline-RISC-V/src/` — complete 5-stage RV32I RTL with testbenches and Yosys scripts
- Evidence completeness: Weak — full RTL code present (16 modules + testbenches + Yosys scripts + DEPS.yml), but README is a single line and no simulation log output or waveforms committed.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 12 | 30 |
| Cognichip Platform Usage | 6 | 20 |
| Innovation & Creativity | 7 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 3 | 5 |
| Potential Real-World Impact | 5 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **40** | **110** |

## Detailed Evaluation

### A) Technical Correctness (12/30)
- Strengths:
  - Comprehensive set of SystemVerilog modules: branch_unit, control_unit, forwarding_unit, immediate_generator, instruction_rom, load_store_unit, 4 pipeline registers, program_counter, register_file, riscv_alu, riscv_cpu_top, simple_memory.
  - Corresponding testbenches for each module (tb_branch_unit.sv, tb_control_unit.sv, tb_riscv_alu.sv, etc.).
  - Yosys synthesis scripts (synth_alu.ys, synth_alu_simple.ys) present.
  - `DEPS.yml` for simulation automation.
- Weaknesses / Missing evidence:
  - No simulation output logs committed (no .fst waveform, no testbench run results).
  - README is a single sentence: "RISC-V chip Design using AI tools(Cognichip) using RV32I" — no architecture description, no test results.
  - Cap applied: no concrete simulation/verification evidence present in repository.
- Key evidence:
  - (src/5-Stage-Pipeline-RISC-V/src/ — RTL module listing)
  - (src/5-Stage-Pipeline-RISC-V/src/tb_riscv_alu.sv, tb_riscv_cpu_top.sv — testbenches present)

### B) Effective Use of the Cognichip Platform (6/20)
- Strengths:
  - README explicitly states "using AI tools(Cognichip)" — direct attribution.
- Weaknesses / Missing evidence:
  - No workflow description, prompt logs, or iteration documentation.
  - Single-line README does not elaborate on how Cognichip shaped the design.
- Key evidence:
  - (src/5-Stage-Pipeline-RISC-V/README.md — "using AI tools(Cognichip)")

### C) Innovation & Creativity (7/15)
- Strengths:
  - Forwarding unit and hazard-handling modules show understanding of pipeline complexity.
  - Complete module hierarchy for a 5-stage pipeline is more substantial than a single-cycle design.
- Weaknesses:
  - 5-stage RV32I pipeline is a standard academic design exercise; limited novelty without distinguishing features.
  - No unique architectural features or optimization documented.
- Key evidence:
  - (src/5-Stage-Pipeline-RISC-V/src/ — forwarding_unit.sv, branch_unit.sv)

### D) Clarity of Presentation (10/25)
#### D1) Slides clarity (7/10)
- Notes: PDF exists; cannot verify content directly, but reasonable base score awarded.
- Evidence: `slides/RISC-V CPU Design with AI.pdf`

#### D2) Video clarity (0/10)
- Notes: No video submission.
- Evidence: No video folder present.

#### D3) Repo organization (3/5)
- Notes: Module files are clearly named. DEPS.yml present. Yosys scripts included. However, the README provides no architectural context, and no documentation hierarchy beyond the source files exists.
- Evidence: (src/5-Stage-Pipeline-RISC-V/src/ listing)

### E) Potential Real-World Impact (5/10)
- Notes: A 5-stage RV32I pipeline is a foundational building block. Without distinguishing features (power optimization, security extensions, accelerators), impact is limited to educational value.
- Evidence: Source file presence

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA or Tiny Tapeout targeting steps provided.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Weak submission**
- The code volume is respectable (16 modules + testbenches + synthesis scripts), but the complete absence of simulation results, documentation, and meaningful README makes it impossible to assess correctness. The submission would benefit enormously from running existing testbenches and committing the output.

## Actionable Feedback (Most Important Improvements)
1. Run existing testbenches (tb_riscv_alu.sv, tb_riscv_cpu_top.sv, etc.) using the DEPS.yml and commit simulation output logs.
2. Write a README documenting the pipeline architecture, instruction set support, hazard handling approach, and how Cognichip was used.
3. Complete and commit the Yosys synthesis (synth_alu.ys scripts are present) to provide area metrics.

## Issues (If Any)
- Code quality and completeness cannot be assessed without running simulations; RTL may be fully functional but lacks any verification record.
