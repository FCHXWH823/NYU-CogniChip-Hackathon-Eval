# CogniChip Hackathon Evaluation Receipt — group001

## Submission Overview
- Team folder: `group001`
- Slides: `slides/a-modified-risc-processor-public.pdf`
- Video: None
- Code/Repo: `src/modified-risc-processor/` (110 files; Verilog processor with testbenches, shell scripts, EDA simulation results)
- Evidence completeness: Good — slide deck is complete and readable, simulation logs and EDA results are present for multiple testbenches, but no video was submitted.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 22 | 30 |
| Cognichip Platform Usage | 13 | 20 |
| Innovation & Creativity | 8 | 15 |
| Clarity — Slides | 8 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **61** | **110** |

## Detailed Evaluation

### A) Technical Correctness (22/30)
- Strengths:
  - Simulation logs present for fibonacci, array_sum, simple, and new_instructions tests (`src/modified-risc-processor/results/sim_output/test_fibonacci_sim.log` confirms fibonacci halts after 74 cycles, register $3=34, $4=34 — correct Fibonacci(8)).
  - Two processor implementations: single-cycle and 5-stage pipelined (`src/modified-risc-processor/processor.v`).
  - Automated testbench runner scripts (`src/modified-risc-processor/list_tests.sh`, `run_pipelined_test.sh`).
  - Multiple EDA simulation runs evident (6+ `sim_*` directories with `eda_results.json` and `dumpfile.fst` waveforms).
  - Golden model comparison methodology described.
- Weaknesses / Missing evidence:
  - Some pipelined EDA runs failed with file-not-found errors (`test_fibonacci.bin not found`) indicating reproducibility gaps (`src/modified-risc-processor/results/simulation_results/sim_2026-02-20T17-34-04-097Z/eda_results.json`).
  - No pass/fail assertion counts visible in logs — only "halted normally" observed.
  - Pipeline correctness for hazard handling not explicitly verified in logs.
- Key evidence:
  - (slides/a-modified-risc-processor-public.pdf p.6 — "Simulation results": fibonacci, array sum, basic tests listed)
  - (src/modified-risc-processor/results/sim_output/test_fibonacci_sim.log — halted after 74 cycles, $3=34 ✓)
  - (src/modified-risc-processor/results/simulation_results/sim_2026-02-20T17-34-04-097Z/eda_results.json — pipelined run file-not-found error)

### B) Effective Use of the Cognichip Platform (13/20)
- Strengths:
  - Describes iterative methodology: prompt Cognichip → check results → revise (slides p.3).
  - Notes Cognichip's ability to auto-run commands in terminal and self-correct in feedback loop.
  - Acknowledges limitations: "imperfections of AI, sometimes requires active feedback" (slides p.8).
- Weaknesses / Missing evidence:
  - No description of specific Cognichip features used (e.g., which EDA tools, which synthesis flow).
  - No screenshots or logs showing actual Cognichip prompts/responses.
  - Workflow could apply to any AI assistant; Cognichip-specific features not distinguished.
- Key evidence:
  - (slides/a-modified-risc-processor-public.pdf p.3 — "Iteratively test, prompt Cognichip, check results")
  - (slides/a-modified-risc-processor-public.pdf p.8 — challenges with Cognichip)

### C) Innovation & Creativity (8/15)
- Strengths:
  - Custom ISA inspired by university E20 course — not a standard RISC-V/MIPS clone.
  - Two-tiered halt detection (two consecutive halts as pseudo-halt) is a creative design choice.
  - C++ golden model cross-validation methodology.
- Weaknesses:
  - Educational processor with modest novelty; similar projects are common in courses.
  - No new instruction types beyond standard load/store/branch/arithmetic.
- Key evidence:
  - (slides/a-modified-risc-processor-public.pdf p.2 — "Slightly different from common RISC architectures")
  - (slides/a-modified-risc-processor-public.pdf p.8 — "two consecutive halts as pseudo-instructions")

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (8/10)
- Notes: Well-structured slides with clear problem statement, design methodology, architecture, simulation results, performance discussion, challenges, lessons learned, and future work sections. Architecture diagrams referenced from E20 Manual.
- Evidence: (slides/a-modified-risc-processor-public.pdf — 10+ slides, clear sections)

#### D2) Video clarity (0/10)
- Notes: No video submitted.
- Evidence: No video directory.

#### D3) Repo organization (4/5)
- Notes: Well-organized with separate `results/sim_output/` and `results/simulation_results/` directories, shell scripts for automation, and a README. GitHub link provided in slides.
- Evidence: (src/modified-risc-processor/ — scripts, RTL, results directories)

### E) Potential Real-World Impact (6/10)
- Notes: Primary value is educational — demonstrates AI-assisted chip design for learning purposes. Limited direct commercial applicability as-is. The C++ golden model + RTL comparison methodology is reusable.
- Evidence: (slides/a-modified-risc-processor-public.pdf p.2 — "educational purposes, evaluate feasibility")

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: FPGA synthesis and tapeout explicitly listed as "future work" only. No synthesis results, no constraints file, no bitstream evidence.
- Evidence: (slides/a-modified-risc-processor-public.pdf p.9 — "Future work: Verilog synthesis", "Tapeout?")

## Final Recommendation
- Overall verdict: **Above Average**
- Solid educational project with genuine simulation evidence (fibonacci, array_sum, basic test logs confirm functional correctness). The pipelined design shows real engineering depth, but reproducibility issues (missing .bin files in some EDA runs) and lack of video reduce the score. Cognichip usage is functional but not deeply documented.

## Actionable Feedback (Most Important Improvements)
1. Fix reproducibility: ensure all binary test files are committed alongside the Verilog so the EDA runs succeed without errors.
2. Document specific Cognichip interactions — include prompt examples or screenshots showing the iterative design loop.
3. Add assertion-based testbenches with explicit PASS/FAIL counts rather than relying solely on final register state inspection.

## Issues (If Any)
- No video submitted.
- Some EDA runs failed with missing `test_fibonacci.bin` — reproducibility concern.
- Slides reference E20 Manual architecture diagrams which are not included in the repo.
