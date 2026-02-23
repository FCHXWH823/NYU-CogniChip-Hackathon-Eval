# CogniChip Hackathon Evaluation Receipt — group001

## Submission Overview
- Team folder: `group001`
- Slides: `slides/a-modified-risc-processor-public.pdf`
- Video: *(not present — no video/ folder)*
- Code/Repo: `src/modified-risc-processor/` — Verilog/SystemVerilog E20 processor (scalar + 5-stage pipelined versions), multiple testbenches, 15 DEPS.yml simulation targets, simulation logs, FST waveforms
- Evidence completeness: **Moderate-High** — source code and local simulation logs are present and show passing results, but Cognichip EDA runs (eda_results.json) show timeouts on all but one target; video is absent.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 20 | 30 |
| Cognichip Platform Usage | 13 | 20 |
| Innovation & Creativity | 9 | 15 |
| Clarity — Slides | 6 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 5 | 5 |
| Potential Real-World Impact | 5 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **58** | **110** |

## Detailed Evaluation

### A) Technical Correctness (20/30)
- Strengths:
  - Extended E20 ISA from 12 to 17 instructions (XOR, NOR, SLL, SRL, SRA added).
  - 5-stage pipelined processor with documented hazard handling (load-use stall, forwarding, branch flush).
  - Local iverilog simulation logs show 12/12 tests passing (test_simple, test_fibonacci, test_array_sum, test_new_instructions, and 8 basic-tests).
  - FST waveform files generated per test (`dumpfile.fst`).
  - `FINAL_TEST_REPORT.md` documents pass rates, cycle counts, and pipeline efficiency metrics.
- Weaknesses / Missing evidence:
  - All Cognichip EDA Verilator runs in `results/simulation_results/` end with **return_code: 30 (timeout/assertion failure)**; only `sim_pipelined_inline` passed once (return_code 0) before regressing.
  - `sim_test_simple_sim.log` from local run shows `$3=0` (expected 3), suggesting a pipelined ADD result-forwarding issue.
  - Local logs (sim_pipelined_basic/) appear to be generated with `iverilog`, not Cognichip/Verilator, creating a discrepancy.
  - No video demo.
- Key evidence:
  - (src/modified-risc-processor/logs/FINAL_TEST_REPORT.md — 12/12 pass, cycle counts)
  - (src/modified-risc-processor/results/sim_pipelined_basic/loop1_sim.log — PASS 57 cycles)
  - (src/modified-risc-processor/results/simulation_results/sim_2026-02-20T17-37-31-980Z/eda_results.json — only passing Cognichip run, return_code 0, sim_pipelined_inline)
  - (src/modified-risc-processor/results/simulation_results/sim_2026-02-20T17-51-28-415Z/eda_results.json — Cognichip run for sim_test_new_instructions, timeout failure)

### B) Effective Use of the Cognichip Platform (13/20)
- Strengths:
  - `DEPS.yml` is fully structured with 15 Cognichip/OpenCOS EDA targets covering scalar and pipelined variants.
  - Multiple Cognichip EDA runs are evidenced by timestamped `eda_results.json` files in `results/simulation_results/`.
  - OpenCOS EDA tool (`eda sim --tool verilator`) was explicitly invoked for multiple targets.
  - `TESTING_REPORT` references "Cognichip Co-Designer" as the verification engineer.
- Weaknesses / Missing evidence:
  - All but one Cognichip EDA simulation run fails (timeout or file-not-found errors), suggesting the team did not successfully resolve platform-level issues before submission.
  - No Cognichip-specific synthesis or layout features mentioned.
- Key evidence:
  - (src/modified-risc-processor/DEPS.yml — 15 sim targets)
  - (src/modified-risc-processor/results/simulation_results/sim_2026-02-20T17-37-31-980Z/eda_results.json — return_code 0 for sim_pipelined_inline)

### C) Innovation & Creativity (9/15)
- Strengths:
  - ISA extension (5 instructions) with documented design rationale.
  - 5-stage pipeline with full hazard handling (load-use detection, 3-stage forwarding, control flush).
  - Cross-validated against a C++ reference simulator.
  - Multiple testbench types (simple Verilog-2001 and SystemVerilog comprehensive) with structured test programs.
- Weaknesses:
  - The E20 ISA extension is a classroom exercise rather than a novel contribution.
  - Pipelining a teaching processor is standard academic work; no novel microarchitectural ideas (out-of-order, branch prediction, etc.).
- Key evidence:
  - (src/modified-risc-processor/README.md — 17-instruction ISA table)
  - (src/modified-risc-processor/logs/ENHANCEMENTS_SUMMARY.md — design rationale for new instructions)

### D) Clarity of Presentation (11/25)
#### D1) Slides clarity (6/10)
- Notes: PDF present but cannot be parsed in this environment; filename `a-modified-risc-processor-public.pdf` is descriptive. Score based on existence and cross-referencing with code documentation quality.
- Evidence: (slides/a-modified-risc-processor-public.pdf)

#### D2) Video clarity (0/10)
- Notes: No video folder or video file present. This is a significant gap.
- Evidence: *(absent)*

#### D3) Repo organization (5/5)
- Notes: Exceptionally well-organized — README.md with quick-start, 6 supplementary log/guide docs, scripts (run_simulation.sh, run_pipelined_basic_tests.sh, list_tests.sh), structured test directory, results per run. `DEPS.yml` is correctly formatted.
- Evidence: (src/modified-risc-processor/README.md, src/modified-risc-processor/logs/, src/modified-risc-processor/basic-tests/)

### E) Potential Real-World Impact (5/10)
- Notes: Educational RISC processor with ISA extension and pipelining is valuable for computer architecture instruction but has limited direct real-world hardware deployment value. No FPGA target, no synthesis results, no timing analysis.
- Evidence: (src/modified-risc-processor/logs/E20_MODIFICATIONS.md — mentions FPGA as future step only)

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: `E20_MODIFICATIONS.md` discusses synthesis-relevant changes (removing `initial` blocks, using synchronous reset) but no FPGA board target, no constraints file, no synthesis reports, and no Tiny Tapeout integration plan. Insufficient evidence for bonus.
- Evidence: *(none concrete)*

## Final Recommendation
- Overall verdict: **Good effort with strong repo organization; functional discrepancy between local and Cognichip simulation results reduces confidence.**
- The team demonstrated solid software engineering practices (clean code, excellent documentation, comprehensive test infrastructure) and clearly engaged with the Cognichip platform, but the Cognichip EDA runs all fail, and the video presentation is missing, leaving the technical claims only partially verified.

## Actionable Feedback (Most Important Improvements)
1. **Fix Cognichip EDA timeouts**: Investigate why `tb_pipelined_tests` times out on Verilator but passes with iverilog — likely a sensitivity to blocking vs. non-blocking assignments or `$readmemb` path issues. Target `sim_test_simple` first.
2. **Add a video demo**: Record a screen-capture showing the simulation running, waveforms in GTKWave, and expected register values. This is worth 10 points.
3. **Validate `$3` result in test_simple on the pipelined core**: The pipelined sim log shows `$3=0` (expected 3), which suggests a data-forwarding bug between the ADD result stage and register writeback. Diagnose and fix.

## Issues (If Any)
- PDF slides cannot be parsed in this environment; scored based on presence + code documentation quality.
- No video file present (no `video/` folder).
- Cognichip EDA simulation results (`results/simulation_results/`) show all runs failing with timeouts, contradicting the passing results reported in `FINAL_TEST_REPORT.md` (which appears to be from local iverilog runs).
