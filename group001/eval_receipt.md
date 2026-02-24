# CogniChip Hackathon Evaluation Receipt — E20 Modified RISC Processor

## Submission Overview
- Team folder: `group001`
- Slides: `slides/a-modified-risc-processor-public.pdf`
- Video: None
- Code/Repo: `src/modified-risc-processor/`
- Evidence completeness: Strong — 12/12 documented test results, waveform file present, and comprehensive documentation across multiple guides.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 25 | 30 |
| Cognichip Platform Usage | 8 | 20 |
| Innovation & Creativity | 8 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 5 | 5 |
| Potential Real-World Impact | 5 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **58** | **110** |

## Detailed Evaluation

### A) Technical Correctness (25/30)
- Strengths:
  - FINAL_TEST_REPORT.md documents 12/12 tests PASS (4 custom programs + 8 basic tests) with cycle counts for each.
  - `dumpfile.fst` waveform file is present and viewable in GTKWave.
  - Full 5-stage pipelined processor with documented hazard handling (load-use stalls, forwarding, branch flushing).
  - Both simple (Verilog-2001) and comprehensive (SystemVerilog) testbenches provided.
  - Comparison methodology vs C++ reference simulator described.
- Weaknesses / Missing evidence:
  - Pipelined implementation is separate from behavioral; test results appear to include both, some tests described in README only.
  - No screenshots of waveform outputs included.
  - Cognichip "Co-Designer" mention in test report lacks specifics about what it contributed.
- Key evidence:
  - (src/modified-risc-processor/logs/FINAL_TEST_REPORT.md — all 12/12 PASS with cycle counts)
  - (src/modified-risc-processor/dumpfile.fst — waveform present)
  - (src/modified-risc-processor/logs/PIPELINED_SUMMARY.md — 5-stage architecture documented)

### B) Effective Use of the Cognichip Platform (8/20)
- Strengths:
  - Cognichip "Co-Designer" is referenced in the test report as part of the workflow.
- Weaknesses / Missing evidence:
  - No description of which specific Cognichip features/flows were used (no prompts, iterations, or platform-specific steps documented).
  - Capped at 8/20 — platform usage is only mentioned generically without specific steps or features.
- Key evidence:
  - (src/modified-risc-processor/logs/FINAL_TEST_REPORT.md — "Cognichip Co-Designer" mention)

### C) Innovation & Creativity (8/15)
- Strengths:
  - Extended E20 ISA with 5 new instructions (XOR, NOR, SLL, SRL, SRA).
  - 5-stage pipelined implementation built on top of educational E20 base.
  - Fibonacci, array-sum, new-instruction programs demonstrate non-trivial design.
- Weaknesses:
  - E20 is an existing educational architecture; extensions are modest.
  - No novel architectural feature beyond ISA extension and pipelining.
- Key evidence:
  - (src/modified-risc-processor/README.md — instruction table, pipeline architecture)

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (7/10)
- Notes: PDF exists; cannot verify content directly, but reasonable base score awarded.
- Evidence: `slides/a-modified-risc-processor-public.pdf`

#### D2) Video clarity (0/10)
- Notes: No video submission.
- Evidence: No video folder or file present.

#### D3) Repo organization (5/5)
- Notes: Exemplary organization — `logs/` folder contains 15 documentation files, `basic-tests/` for test programs, shell scripts, two testbench variants. README is comprehensive with tables and examples.
- Evidence: (src/modified-risc-processor/ structure)

### E) Potential Real-World Impact (5/10)
- Notes: Strong educational value for teaching pipelined processor design. E20 is a course-specific architecture with limited production applicability, but the verification methodology and pipelining are transferable skills.
- Evidence: README learning path, ENHANCEMENTS_SUMMARY.md

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: E20_MODIFICATIONS.md mentions an FPGA version concept but no constraint files, synthesis results, or bitstreams are provided.
- Evidence: None confirming actual FPGA targeting.

## Final Recommendation
- Overall verdict: **Strong submission**
- The team delivers a complete, well-documented processor with genuine verification evidence (12/12 tests, waveform, dual testbenches). The main gaps are the generic Cognichip platform description and absence of a video presentation.

## Actionable Feedback (Most Important Improvements)
1. Document specific Cognichip platform interactions (which prompts, which features, how many iterations) to demonstrate deeper platform engagement.
2. Add a video walkthrough demonstrating both the processor running and waveform analysis.
3. Add FPGA synthesis constraints and build a bitstream to qualify for bonus points; the E20_MODIFICATIONS.md already hints at FPGA awareness.

## Issues (If Any)
- Pipelined vs. behavioral test scoping could be clarified — it's not immediately obvious which 12 tests run against which implementation.
