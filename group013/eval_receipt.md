# CogniChip Hackathon Evaluation Receipt — group013

## Submission Overview
- Team folder: `group013`
- Slides: `slides/Automated Design of RISC-V Processors using LLM-Guided feedback (Nathan and Carlos).pdf`
- Video: None
- Code/Repo: `src/risc-v/` (16 files; single-cycle RV32I CPU RTL modules, Yosys synthesis script, synthesis log, testbench, waveform .fst, golden model)
- Evidence completeness: Moderate — Yosys synthesis log and FST waveform are present; slides describe clear iterative workflow; no README and no Cognichip EDA results.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 19 | 30 |
| Cognichip Platform Usage | 14 | 20 |
| Innovation & Creativity | 10 | 15 |
| Clarity — Slides | 8 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 2 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 3 | 10 |
| **Total** | **62** | **110** |

## Detailed Evaluation

### A) Technical Correctness (19/30)
- Strengths:
  - Yosys synthesis log committed (`src/risc-v/synth_cpu.log`) — synthesis completes without error.
  - FST waveform file present (`src/risc-v/dumpfile.fst`) confirming simulation ran.
  - Golden reference model (`golden_rv32i.sv`) committed — used for lockstep verification.
  - Complete set of RV32I RTL modules: `cpu_top.sv`, `alu.sv`, `control_unit.sv`, `regfile.sv`, `mem_model.sv`, `imm_gen.sv`.
  - Testbench (`tb_cpu.sv`) and program hex file (`program.hex`) included.
  - Slides show clear FAIL → PASS iterative debugging workflow.
- Weaknesses / Missing evidence:
  - No explicit pass/fail log from simulation — waveform exists but test outcome unconfirmed from files.
  - No Cognichip EDA `eda_results.json` — appears simulation used Verilator standalone, not Cognichip platform.
  - No README in repository.
  - Synthesis log is minimal (Yosys ran but output is brief).
- Key evidence:
  - (src/risc-v/synth_cpu.log — Yosys 0.62 synthesis completed)
  - (src/risc-v/dumpfile.fst — simulation waveform)
  - (src/risc-v/golden_rv32i.sv — golden reference model)
  - (slides/Automated Design of RISC-V Processors...pdf — iterative refinement workflow diagram)

### B) Effective Use of the Cognichip Platform (14/20)
- Strengths:
  - Slides explicitly describe Cognichip as "a rapid prototyping and debugging assistant."
  - Specific Cognichip contributions documented: control logic skeleton, datapath structure, PC update logic, debugging of incorrect PC update paths, fixing regwrite conditions, correcting immediate handling.
  - Workflow clearly described: Generate RTL → Simulate (Verilator) → Observe mismatches → Refine with Cognichip.
- Weaknesses / Missing evidence:
  - No Cognichip EDA simulation results — simulation appears to use standalone Verilator.
  - The debugging contributions are claimed in slides but no prompt examples shown.
- Key evidence:
  - (slides/Automated Design of RISC-V Processors...pdf — "How Cognichip Was Used: GENERATED_ and ASSISTED DEBUGGING_")
  - (slides/Automated Design of RISC-V Processors...pdf — 6-step workflow)

### C) Innovation & Creativity (10/15)
- Strengths:
  - Golden reference model lockstep verification is a rigorous approach for CPU correctness.
  - Commit-aligned debug registers for matching golden model states is a thoughtful design detail.
  - Harvard-style memory interface choice is well-motivated.
- Weaknesses:
  - Single-cycle RV32I is a standard educational design.
  - The LLM-guided workflow is similar to other submissions; no unique algorithmic contribution.
- Key evidence:
  - (slides/Automated Design of RISC-V Processors...pdf — "golden_rv32i.sv reference model")
  - (slides/Automated Design of RISC-V Processors...pdf — synthesized datapath connectivity figure)

### D) Clarity of Presentation (10/25)
#### D1) Slides clarity (8/10)
- Notes: Concise and well-structured slides: motivation, workflow diagram, architecture figure, core components table, design choices, Cognichip usage details. Architecture diagram showing synthesized datapath is a strong visual.
- Evidence: (slides/Automated Design of RISC-V Processors...pdf — architecture diagram, 6-step workflow)

#### D2) Video clarity (0/10)
- Notes: No video submitted.
- Evidence: No video directory.

#### D3) Repo organization (2/5)
- Notes: RTL files and synthesis script are present and functional, but no README committed. Missing crucial documentation for reproducibility.
- Evidence: (src/risc-v/ — 16 files, no README)

### E) Potential Real-World Impact (6/10)
- Notes: RV32I processor design with LLM assistance demonstrates a practical design methodology. The golden model lockstep approach has broader applicability to complex designs.
- Evidence: (slides/Automated Design of RISC-V Processors...pdf — workflow applicable to any CPU design)

### Bonus) FPGA / Tiny Tapeout Targeting (+3/10)
- Notes: Yosys synthesis was run (`synth_cpu.ys` and `synth_cpu.log` committed) — this is a step toward FPGA/tapeout but no board-specific constraints, timing reports, or implementation results. Partial evidence.
- Evidence: (src/risc-v/synth_cpu.ys, synth_cpu.log — Yosys synthesis completed)

## Final Recommendation
- Overall verdict: **Above Average**
- Clean, focused implementation of RV32I with a good iterative methodology and golden reference model. The Yosys synthesis and waveform evidence confirms functional work. Missing README and the absence of explicit pass/fail simulation logs from Cognichip reduce the score.

## Actionable Feedback (Most Important Improvements)
1. Add a README explaining how to reproduce the build and simulation.
2. Run simulation on Cognichip platform and commit EDA results to confirm test outcomes.
3. Add explicit PASS/FAIL assertions in the testbench with a summary log.

## Issues (If Any)
- No video submitted.
- No README in the repository.
- No Cognichip EDA results — simulation evidence is waveform-only.
