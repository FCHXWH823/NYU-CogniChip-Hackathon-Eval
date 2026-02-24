# CogniChip Hackathon Evaluation Receipt — Automated Design of RISC-V Processors using LLM-Guided Feedback

## Submission Overview
- Team folder: `group013`
- Slides: `slides/Automated Design of RISC-V Processors using LLM-Guided feedback (Nathan and Carlos).pdf`
- Video: None
- Code/Repo: `src/risc-v/` — RV32I single-cycle CPU with testbench, Yosys synthesis
- Evidence completeness: Partial — Yosys synthesis log committed (though brief), dumpfile.fst waveform present, golden reference testbench with lockstep checking; no explicit pass/fail log output.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 18 | 30 |
| Cognichip Platform Usage | 10 | 20 |
| Innovation & Creativity | 10 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 3 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **54** | **110** |

## Detailed Evaluation

### A) Technical Correctness (18/30)
- Strengths:
  - Complete single-cycle RV32I CPU implementation with all key modules: ALU, control unit, register file, immediate generator, memory model, program counter.
  - `dumpfile.fst` waveform file committed — confirms simulation was actually run.
  - `tb_cpu.sv` uses a golden reference (`golden_rv32i.sv`) with edge-aligned lockstep comparison — a professional verification pattern.
  - `synth_cpu.log` committed showing Yosys synthesis was run.
  - `program.hex` test program present for simulation.
  - `synth_cpu.ys` Yosys synthesis script committed.
- Weaknesses / Missing evidence:
  - `synth_cpu.log` is extremely brief — ends with "End of script" with no cell count or synthesis statistics.
  - No explicit pass/fail log from testbench execution committed (only the waveform FST file).
  - README is a single line: "RISC-V chip Design using AI tools(Cognichip) using RV32I"
- Key evidence:
  - (src/risc-v/dumpfile.fst — waveform evidence of simulation run)
  - (src/risc-v/synth_cpu.log — Yosys synthesis log)
  - (src/risc-v/tb_cpu.sv — golden reference lockstep testbench)
  - (src/risc-v/synth_cpu.ys — Yosys synthesis script)

### B) Effective Use of the Cognichip Platform (10/20)
- Strengths:
  - README explicitly states "using AI tools(Cognichip) using RV32I" — direct attribution.
  - Slides title "Automated Design of RISC-V Processors using LLM-Guided feedback" implies iterative AI usage.
- Weaknesses / Missing evidence:
  - No prompt log, iteration history, or description of how Cognichip specifically shaped design decisions.
  - Could not verify Cognichip-specific features used vs. generic LLM assistance.
- Key evidence:
  - (src/risc-v/README.md — "using AI tools(Cognichip)" statement)

### C) Innovation & Creativity (10/15)
- Strengths:
  - LLM-guided feedback loop for CPU design generation is the core innovation.
  - Golden reference lockstep testbench is a sophisticated verification approach.
  - `Verilog/` subdirectory suggests multiple design iterations were generated.
- Weaknesses:
  - Single-cycle RV32I is a standard academic design; pipeline and hazard handling would add more complexity.
  - Automation/feedback loop not documented in detail.
- Key evidence:
  - (src/risc-v/tb_cpu.sv — lockstep verification methodology)
  - (src/risc-v/Verilog/ — iteration directory)

### D) Clarity of Presentation (10/25)
#### D1) Slides clarity (7/10)
- Notes: PDF exists; cannot verify content directly, but reasonable base score awarded.
- Evidence: `slides/Automated Design of RISC-V Processors using LLM-Guided feedback (Nathan and Carlos).pdf`

#### D2) Video clarity (0/10)
- Notes: No video submission.
- Evidence: No video folder present.

#### D3) Repo organization (3/5)
- Notes: Reasonable file layout with distinct RTL files per module, synthesis scripts, and test program. However, README is a single line and `res` file content is empty. A `Verilog/` subdirectory suggests iteration history but is not documented.
- Evidence: (src/risc-v/ directory listing)

### E) Potential Real-World Impact (6/10)
- Notes: Automated LLM-guided CPU design generation has research value for rapid prototyping and design space exploration. Golden-reference lockstep testing methodology is reusable and practically valuable.
- Evidence: (src/risc-v/tb_cpu.sv — verification methodology)

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA or Tiny Tapeout targeting steps provided.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Average submission**
- A complete RTL CPU implementation with a sophisticated golden reference testbench and Yosys synthesis, but documentation is almost entirely absent. The waveform file confirms actual simulation but explicit test results were not committed.

## Actionable Feedback (Most Important Improvements)
1. Commit the testbench simulation output log showing pass/fail results from the golden reference comparison.
2. Add a proper README documenting the LLM-guided feedback process, iteration history, and specific Cognichip interactions.
3. Complete the Yosys synthesis (the log shows it terminated early) to get meaningful area/cell count statistics.

## Issues (If Any)
- `synth_cpu.log` appears truncated — shows only startup/version info without synthesis results.
- `res` file committed but appears empty.
