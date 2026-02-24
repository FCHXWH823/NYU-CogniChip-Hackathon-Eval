# CogniChip Hackathon Evaluation Receipt — group008

## Submission Overview
- Team folder: `group008`
- Slides: `slides/Cognichip Hackathon Presentation (Gary Guan, Az Li).pdf`
- Video: None
- Code/Repo: `src/Cognichip_NetworkArbiter/` (11 files; 4x4 and 8x8 round-robin arbiter RTL with testbenches and EDA results)
- Evidence completeness: Good — EDA simulation results clearly show all tests passing for both 4x4 and 8x8 designs; slides include simulation result screenshots.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 22 | 30 |
| Cognichip Platform Usage | 14 | 20 |
| Innovation & Creativity | 6 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 3 | 5 |
| Potential Real-World Impact | 5 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **57** | **110** |

## Detailed Evaluation

### A) Technical Correctness (22/30)
- Strengths:
  - EDA results confirm all 4x4 tests pass: `PASS: req=0001, grant=0001`; `PASS: req=0010, grant=0010`; etc.
  - 8x8 EDA results confirm: `Test A1: PASS`, `Test A2: PASS`, `Test A3: PASS`, `Test A4: PASS`.
  - Two separate designs (4x4 round-robin, 8x8 crossbar) both verified.
  - Waveform file present (`dumpfile.fst`).
  - Slides explicitly show simulation screenshots of passing tests.
- Weaknesses / Missing evidence:
  - No priority/stress testing or corner case coverage (e.g., simultaneous requests from all ports, starvation scenarios).
  - Team acknowledges design lacks an idle state (defaults to 0) — functional gap noted.
  - Small repo (11 files) — testbench coverage appears limited.
- Key evidence:
  - (src/Cognichip_NetworkArbiter/4x4/eda_results.json — `PASS: req=0001, grant=0001`)
  - (src/Cognichip_NetworkArbiter/8x8/eda_results.json — `Test A1: PASS` through `Test A4: PASS`)
  - (src/Cognichip_NetworkArbiter/4x4/dumpfile.fst — waveform)

### B) Effective Use of the Cognichip Platform (14/20)
- Strengths:
  - Cognichip used for design generation, testing, and validation of both arbiter designs.
  - Built-in Cognichip simulation used throughout — EDA version 0.3.10 confirmed in logs.
  - Waveform viewer within Cognichip cited as a key benefit.
  - Acknowledges and documents platform limitations (message limits, simulation reliability issues).
- Weaknesses / Missing evidence:
  - No description of specific Cognichip design prompts or how architecture was refined.
  - Minimal description of the iteration process.
- Key evidence:
  - (slides/Cognichip Hackathon Presentation (Gary Guan, Az Li).pdf — "Cognichip's platform allowed us to quickly generate Verilog designs")
  - (src/Cognichip_NetworkArbiter/4x4/eda_results.json — EDA version 0.3.10 confirmed)

### C) Innovation & Creativity (6/15)
- Strengths:
  - Scaled from 4x4 to 8x8 design showing iterative development.
  - Round-robin arbitration is correctly implemented.
- Weaknesses:
  - Round-robin arbiters are standard textbook designs with many existing implementations.
  - No novel algorithm, architectural feature, or unique application context.
  - No differentiation from standard designs.
- Key evidence:
  - (slides/Cognichip Hackathon Presentation (Gary Guan, Az Li).pdf — "4-Input Round-Robin Arbiter")

### D) Clarity of Presentation (10/25)
#### D1) Slides clarity (7/10)
- Notes: Clear and concise slides covering problem statement, architecture descriptions for both designs, simulation results, challenges, and future work. Could benefit from architecture diagrams.
- Evidence: (slides/Cognichip Hackathon Presentation (Gary Guan, Az Li).pdf)

#### D2) Video clarity (0/10)
- Notes: No video submitted.
- Evidence: No video directory.

#### D3) Repo organization (3/5)
- Notes: Small repo with 4x4 and 8x8 directories, README present. Minimal but functional. No comprehensive documentation beyond README.
- Evidence: (src/Cognichip_NetworkArbiter/ — 4x4 and 8x8 subdirectories)

### E) Potential Real-World Impact (5/10)
- Notes: Network arbiters are fundamental to SoC interconnects and data centers. The specific round-robin implementation is straightforward; impact depends on scaling and optimization for production environments.
- Evidence: (slides/Cognichip Hackathon Presentation (Gary Guan, Az Li).pdf — "data centers rely on high performing arbitration logic")

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: FPGA/Tiny Tapeout listed as "future work" only. No evidence of constraints, synthesis results, or board targeting.
- Evidence: (slides/Cognichip Hackathon Presentation (Gary Guan, Az Li).pdf — "Future Work: implemented through FPGA board or Tiny Tapeout chip")

## Final Recommendation
- Overall verdict: **Average**
- Clean and complete for a small scope project — both arbiters pass all EDA tests. However, the design scope is narrow (standard round-robin arbiter), testbench coverage is limited, and there is no video or FPGA evidence. The submission is technically sound but not innovative.

## Actionable Feedback (Most Important Improvements)
1. Add stress/corner-case testing — simultaneous requests, priority inversion, starvation prevention.
2. Fix the missing idle state identified in the presentation.
3. Scale to 16x16 arbiter or add a novel feature (weighted fairness, priority levels) to differentiate.

## Issues (If Any)
- No video submitted.
- Design acknowledged to lack idle state (defaults to 0).
