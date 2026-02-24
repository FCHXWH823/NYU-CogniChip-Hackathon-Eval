# CogniChip Hackathon Evaluation Receipt — FunkyMonkey: NeuroRISC Neural Processing Accelerator

## Submission Overview
- Team folder: `group016`
- Slides: `slides/FunkyMonkey - A RISC-V Neural Processing Accelerator for Edge AI Inference.pdf`
- Video: `video/` (directory exists with files)
- Code/Repo: `src/neurisc_cognichip_hackathon/` — 10 SystemVerilog modules, testbenches, synthesis scripts
- Evidence completeness: Partial — test pass claims documented in README (25/25), but SYNTHESIS_SUMMARY.md is "tbd" and no simulation log files committed; performance numbers appear to be analytical estimates.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 20 | 30 |
| Cognichip Platform Usage | 8 | 20 |
| Innovation & Creativity | 12 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 7 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 9 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **67** | **110** |

## Detailed Evaluation

### A) Technical Correctness (20/30)
- Strengths:
  - README claims 25/25 tests passing across 3 testbenches: tb_mac_unit.sv (8/8), tb_mac_performance.sv (11/11), tb_pooling_unit.sv (6/6).
  - 10 SystemVerilog modules implementing a complete SoC: dual systolic arrays, pipelined MACs, pooling, activation, DMA, buffers.
  - Specific test commands with expected output documented (iverilog compilation instructions).
  - C software stack (neurisc_runtime.c, mnist_inference.c) present for co-design.
  - Performance analysis documents (2x16x16_PERFORMANCE_ANALYSIS.md, BENCHMARK_TABLE.md) present in docs/.
- Weaknesses / Missing evidence:
  - SYNTHESIS_SUMMARY.md says "tbd" — synthesis not completed/documented.
  - No simulation log files committed; test pass claims are self-reported in README.
  - 95× speedup vs ARM Cortex-M7 and 1.5 GHz frequency targets appear analytical/estimated, not measured from actual simulation.
  - Performance numbers (3,800 GOPS/W) would require hardware measurement to verify.
- Key evidence:
  - (src/neurisc_cognichip_hackathon/README.md — test summary table)
  - (src/neurisc_cognichip_hackathon/tb/ — testbench files present)
  - (src/neurisc_cognichip_hackathon/synthesis/SYNTHESIS_SUMMARY.md — "tbd")

### B) Effective Use of the Cognichip Platform (8/20)
- Strengths:
  - Submitted to CogniChip Hackathon with "AI-driven" in the description.
- Weaknesses / Missing evidence:
  - README does not explicitly mention Cognichip as the AI tool used.
  - No prompt logs, iteration history, or platform-specific workflow documented.
  - "AI-driven" claims reference general AI assistance without Cognichip specifics.
  - Capped at 8/20 — platform usage is generic without specific Cognichip steps documented.
- Key evidence:
  - (src/neurisc_cognichip_hackathon/README.md — no explicit Cognichip mention found)

### C) Innovation & Creativity (12/15)
- Strengths:
  - Dual 16×16 independent systolic arrays for multi-model parallel inference is a distinctive architectural choice.
  - 2-stage pipelined MAC units with INT4/INT8 dual-mode is technically sophisticated.
  - Dedicated hardware pooling unit offloading from MACs shows architectural thinking.
  - RISC-V custom instruction integration (custom_instruction_decoder.sv) extends the ISA meaningfully.
- Weaknesses:
  - Systolic array accelerators for edge inference are a well-explored area; the dual-array multi-model angle is the differentiation.
- Key evidence:
  - (src/.../README.md — dual array architecture, INT4/INT8 mode description)

### D) Clarity of Presentation (18/25)
#### D1) Slides clarity (7/10)
- Notes: PDF exists; cannot verify content directly, but reasonable base score awarded.
- Evidence: `slides/FunkyMonkey - A RISC-V Neural Processing Accelerator for Edge AI Inference.pdf`

#### D2) Video clarity (7/10)
- Notes: Video directory exists with files.
- Evidence: `video/` directory with contents.

#### D3) Repo organization (4/5)
- Notes: Good structure: rtl/, tb/, docs/, sw/, synthesis/. README is comprehensive with architecture diagram, performance tables, and test instructions. Docking 1 point for SYNTHESIS_SUMMARY.md being incomplete ("tbd").
- Evidence: (src/neurisc_cognichip_hackathon/ directory structure)

### E) Potential Real-World Impact (9/10)
- Notes: Edge AI inference acceleration with demonstrated efficiency targets (3,800 GOPS/W claimed) directly addresses a critical industry need. Multi-model parallel inference and cost-effective design ($2-3 estimated) have commercial appeal.
- Evidence: README — MNIST results, industry comparison table

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA or Tiny Tapeout targeting steps; synthesis targets 28nm CMOS but no FPGA constraints or flow documented.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Strong submission**
- Impressive architectural scope with dual systolic arrays, pipelined MACs, and hardware pooling. The comprehensive README with performance benchmarks and test specifications is well-done. Key gaps are the missing simulation logs and incomplete synthesis documentation.

## Actionable Feedback (Most Important Improvements)
1. Commit testbench simulation output logs showing the 25/25 test pass results explicitly.
2. Complete the SYNTHESIS_SUMMARY.md with actual Yosys or 28nm synthesis results.
3. Document the Cognichip platform usage explicitly — what prompts generated which modules, and how many iterations were needed.

## Issues (If Any)
- SYNTHESIS_SUMMARY.md placeholder ("tbd") suggests synthesis step was not completed before submission.
- Performance numbers (95× speedup, 3,800 GOPS/W) are analytical estimates without physical verification disclosure.
