# CogniChip Hackathon Evaluation Receipt — group001

## Submission Overview
- Team folder: `group001`
- Slides: `slides/a-modified-risc-processor-public.pdf`
- Video: **None submitted**
- Code/Repo: `src/modified-risc-processor/` — `processor.v`, `tb_processor.v`, `tb_processor_simple.v`, 4 test programs, scripts, 6 guide docs, 12 Cognichip EDA result directories
- Evidence completeness: Moderate — code and slides present, local iverilog sim logs exist, Cognichip EDA mostly failed; no video submitted.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 15 | 30 |
| Cognichip Platform Usage | 10 | 20 |
| Innovation & Creativity | 9 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 5 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **50** | **110** |

## Detailed Evaluation

### A) Technical Correctness (15/30)
- Strengths:
  - Local iverilog tests pass for all 4 programs (`test_simple`, `test_array_sum`, `test_new_instructions`, `test_fibonacci`) per sim logs and README.
  - One Cognichip EDA run passed (`sim_pipelined_inline`, `return_code: 0`), producing an FST waveform.
  - Both a simple Verilog-2001 testbench and a full SystemVerilog testbench are provided.
  - 5 new instructions added (XOR, NOR, SLL, SRL, SRA) on top of 12 original E20 instructions.
- Weaknesses / Missing evidence:
  - 11 of 12 Cognichip EDA runs failed (`return_code: 30` or other errors); failures span all pipelined program tests.
  - The one passing EDA run (`sim_pipelined_inline`) loaded an inline hardcoded program; the processor halted after 1 cycle with all registers zero — effectively a trivial test.
  - No waveform screenshots in slides; pipelined processor correctness under Cognichip is unconfirmed.
  - No video to corroborate claims.
- Key evidence:
  - (src/modified-risc-processor/results/simulation_results/sim_2026-02-20T17-37-31-980Z/eda_results.json) — sole passing EDA run, `TEST PASSED` but trivial program
  - (src/modified-risc-processor/results/simulation_results/sim_2026-02-20T17-51-28-415Z/eda_results.json) — representative failure: timeout after 100 000 cycles, `SLL: $6=0 (expected: 48)`
  - (src/modified-risc-processor/results/sim_output/test_new_instructions_sim.log) — local iverilog XOR/NOR/SLL/SRL/SRA pass

### B) Effective Use of the Cognichip Platform (10/20)
- Strengths:
  - 12 EDA runs submitted, demonstrating active use of `eda sim --tool verilator` across multiple targets.
  - DEPS.yml is present, showing proper Cognichip project structure.
- Weaknesses / Missing evidence:
  - Only 1/12 runs succeeded; failures indicate the team did not fully adapt the testbench to the platform's working directory model (e.g., `.bin` files not co-located with EDA work dir).
  - No description of how the Cognichip AI was used for design assistance.
- Key evidence:
  - (src/modified-risc-processor/results/simulation_results/*/eda_results.json) — 12 runs, 1 pass
  - (src/modified-risc-processor/DEPS.yml) — Cognichip project config

### C) Innovation & Creativity (9/15)
- Strengths:
  - Added 5 meaningful instructions (bitwise XOR, NOR, SLL, SRL, SRA) extending the standard E20 ISA.
  - Designed both a single-cycle and a 5-stage pipelined version; Fibonacci test program is non-trivial.
  - Dual testbench strategy (simple Verilog-2001 + comprehensive SystemVerilog) shows methodical approach.
- Weaknesses:
  - E20 is an existing educational ISA; extending it is incremental.
  - Pipeline design does not clearly demonstrate hazard handling or forwarding beyond basic structure.

### D) Clarity of Presentation (11/25)
#### D1) Slides clarity (7/10)
- Notes: Single PDF submitted. Covers E20 modifications, ISA table, testbench options, and quick-start instructions. Well-organised educational presentation.
- Evidence: (slides/a-modified-risc-processor-public.pdf)

#### D2) Video clarity (0/10)
- Notes: No video was submitted. Score is zero per rubric.
- Evidence: `video/` directory is empty.

#### D3) Repo Organization (4/5)
- Notes: Six markdown guide docs, clean script structure, DEPS.yml, .bin test programs included. Minor issue: `.DS_Store` lock file committed in `slides/`.
- Evidence: (src/modified-risc-processor/README.md), (src/modified-risc-processor/DEPS.yml)

### E) Potential Real-World Impact (5/10)
- Notes: An extended E20 processor with new instructions is a useful educational tool, but real-world impact is limited to teaching contexts.
- Evidence: (src/modified-risc-processor/README.md) — "educational RISC processor"

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA constraints, synthesis reports, or tapeout plan found.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Below Average** (50/110)
- Local simulation is functional, but the submission's key gap is that virtually all Cognichip EDA runs failed due to testbench incompatibility with the platform's file-path model. The absence of a video and the trivial nature of the one passing EDA test further reduce the score.

## Actionable Feedback (Most Important Improvements)
1. Fix testbench to load `.bin` programs from an absolute or EDA-relative path so all Cognichip EDA runs succeed.
2. Submit a demo video showing the processor running at least one non-trivial program (e.g., Fibonacci, array sum) with waveform evidence.
3. Add a hazard/forwarding unit description and include at least one data-hazard test in the Cognichip EDA suite.

## Issues (If Any)
- No video submitted; D2 score is 0.
- `~$a-modified-risc-processor-public.pptx` (Office lock file) committed to `slides/`.
- `.DS_Store` committed to `slides/`.
- 11/12 Cognichip EDA runs failed; only the trivial inline test passed.
