# CogniChip Hackathon Evaluation Receipt — group013

## Submission Overview
- Team folder: `group013`
- Slides: `slides/Automated Design of RISC-V Processors using LLM-Guided feedback (Nathan and Carlos).pdf`
- Video: `slides/Automated Design of RISC-V Processors using LLM-Guided feedback (Nathan and Carlos).mp4` *(video submitted in `slides/` directory)*
- Code/Repo: `src/risc-v/` — `cpu_top.sv`, `alu.sv`, `control_unit.sv`, `regfile.sv`, `imm_gen.sv`, `mem_model.sv`, `golden_rv32i.sv`, `tb_cpu.sv`, `program.hex`, `DEPS.yml`, `synth_cpu.ys`, `synth_cpu.log`, `dumpfile.fst`, `res/cpu_top_show.svg`
- Evidence completeness: Partial — FST waveform committed (`dumpfile.fst`) and Yosys synthesis script present; no explicit PASS/FAIL output in logs; no EDA JSON results.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 14 | 30 |
| Cognichip Platform Usage | 7 | 20 |
| Innovation & Creativity | 10 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 7 | 10 |
| Clarity — Repo Organization | 3 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **54** | **110** |

## Detailed Evaluation

### A) Technical Correctness (14/30)
- Strengths:
  - `dumpfile.fst` waveform file committed, confirming a simulation ran to completion.
  - `golden_rv32i.sv` implements a golden reference model for lockstep comparison — sophisticated testbench design.
  - `tb_cpu.sv` performs cycle-by-cycle comparison of DUT vs. golden model (PC, register writes, memory writes) up to 20 000 cycles.
  - `synth_cpu.log` shows Yosys ran; `res/cpu_top_show.svg` (netlist visualisation) was generated.
  - `program.hex` provides a concrete test program.
- Weaknesses / Missing evidence:
  - `synth_cpu.ys` is empty (no commands); `synth_cpu.log` shows only header/footer — synthesis was not actually performed.
  - No EDA JSON result files; no explicit PASS/FAIL message visible in committed logs.
  - Cannot determine if the golden-model comparison found mismatches or ran cleanly.
- Key evidence:
  - (src/risc-v/dumpfile.fst) — simulation waveform committed
  - (src/risc-v/tb_cpu.sv) — lockstep golden-model testbench
  - (src/risc-v/synth_cpu.log) — Yosys ran but no synthesis commands executed

### B) Effective Use of the Cognichip Platform (7/20)
- Strengths:
  - `DEPS.yml` committed with `sim_cpu` target listing all RTL/TB dependencies — proper Cognichip project structure.
  - `dumpfile.fst` waveform is consistent with a Cognichip `eda sim --waves` run.
- Weaknesses / Missing evidence:
  - No EDA JSON result files; cannot confirm the simulation was run via Cognichip vs. locally.
  - No description of how Cognichip LLM guidance was actually used in the design process.
- Key evidence:
  - (src/risc-v/DEPS.yml) — Cognichip project config with `sim_cpu` target

### C) Innovation & Creativity (10/15)
- Strengths:
  - LLM-guided iterative RTL refinement with a lockstep golden-model testbench is a thoughtful methodology for automated CPU design verification.
  - `golden_rv32i.sv` as an independent reference model for automated DUT comparison is a strong verification strategy.
  - SVG circuit diagram (`res/cpu_top_show.svg`) demonstrates use of synthesis tools for design understanding.
- Weaknesses:
  - Single-cycle RV32I CPU is a standard introductory design; novelty lies in the LLM-guided methodology rather than the hardware itself.

### D) Clarity of Presentation (17/25)
#### D1) Slides clarity (7/10)
- Notes: PDF covers LLM-guided design methodology, iterative refinement loop, and CPU architecture.
- Evidence: (slides/Automated Design of RISC-V Processors using LLM-Guided feedback (Nathan and Carlos).pdf)

#### D2) Video clarity (7/10)
- Notes: Video is present (in `slides/` directory rather than `video/`). Covers the LLM feedback-driven design process.
- Evidence: (slides/Automated Design of RISC-V Processors using LLM-Guided feedback (Nathan and Carlos).mp4)

#### D3) Repo Organization (3/5)
- Notes: No README committed in `src/`; `Verilog` is a file (not a directory) causing confusion; video placed in `slides/` directory rather than `video/`. DEPS.yml and code files are present but no documentation explaining the design.
- Evidence: (src/risc-v/DEPS.yml)

### E) Potential Real-World Impact (6/10)
- Notes: Automated LLM-guided RTL generation with golden-model verification addresses a real need in chip design automation. Practical impact depends on scaling beyond the single-cycle RISC-V demo.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA constraints or tapeout evidence found.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Average** (54/110)
- The golden-reference testbench approach and the committed FST waveform are meaningful technical evidence. Score is limited by the empty Yosys synthesis script, absence of EDA JSON results, and poor file organisation (video in slides/, no README in src/).

## Actionable Feedback (Most Important Improvements)
1. Commit EDA JSON result files or explicit simulation logs showing the golden-model comparison ran without mismatches.
2. Add a README in `src/risc-v/` explaining the design and the LLM-guided iteration process.
3. Move the video to `video/` and fix the `synth_cpu.ys` script to actually run synthesis so area estimates are available.

## Issues (If Any)
- Video is placed in `slides/` directory rather than `video/`.
- `synth_cpu.ys` is empty; `synth_cpu.log` shows no synthesis commands were executed.
- `Verilog` is committed as a file (not a directory); purpose unclear.
- No README in `src/risc-v/`; no explicit PASS/FAIL evidence in committed logs.
