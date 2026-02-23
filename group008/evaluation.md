# CogniChip Hackathon Evaluation Receipt — group008

## Submission Overview
- Team folder: `group008`
- Slides: `slides/Cognichip Hackathon Presentation (Gary Guan, Az Li).pdf`
- Video: `video/al7675_xg2523_cognichip.mp4`
- Code/Repo: `src/Cognichip_NetworkArbiter/` — `arbiter_4x4.sv`, `tb_arbiter_simple.sv`, `switch_arbiter_8x8.sv`, `tb_switch_arbiter_8x8.sv`, `DEPS.yml` (×2), `4x4/eda_results.json`, `8x8/eda_results.json`, README
- Evidence completeness: Strong — both 4×4 and 8×8 designs passed Cognichip EDA runs with `TEST PASSED`.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 22 | 30 |
| Cognichip Platform Usage | 14 | 20 |
| Innovation & Creativity | 8 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 7 | 10 |
| Clarity — Repo Organization | 3 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **67** | **110** |

## Detailed Evaluation

### A) Technical Correctness (22/30)
- Strengths:
  - **4×4 arbiter**: Cognichip EDA pass (`return_code: 0`). Four tests passed: single-request grant, all-requests round-robin cycling (all 4 clients served fairly), two-request alternation, and no-request (grant=0). `TEST PASSED` confirmed.
  - **8×8 arbiter**: Cognichip EDA pass (`return_code: 0`). Five tests (C1–C5) all passed including grant-without-acknowledge priority hold, confirmed via `LOG: ... expected_value: PASS actual_value: PASS`. `TEST PASSED` confirmed.
  - Both designs use structured `LOG:` assertions with expected/actual values, showing good testbench quality.
  - Round-robin fairness demonstrated empirically through sequential grant cycling.
- Weaknesses / Missing evidence:
  - Only one testbench per design; no edge-case tests (e.g., request starvation, acknowledge-less cycles for 4×4).
  - No waveform files committed.
  - No area or timing characterisation.
- Key evidence:
  - (src/Cognichip_NetworkArbiter/4x4/eda_results.json) — `TEST PASSED`, `return_code: 0`; round-robin cycling confirmed
  - (src/Cognichip_NetworkArbiter/8x8/eda_results.json) — `TEST PASSED`, `return_code: 0`; C1–C5 all PASS

### B) Effective Use of the Cognichip Platform (14/20)
- Strengths:
  - Two successful Cognichip EDA runs committed with JSON artifacts.
  - DEPS.yml present in both design directories, showing proper Cognichip project structure.
  - README explicitly thanks the Cognichip team and references ACI tool.
- Weaknesses / Missing evidence:
  - Only 2 EDA runs total; limited platform iteration visible — no failed-then-fixed debugging cycle.
  - No mention of Cognichip AI assistance in design generation beyond "created with the help of the CogniChip ACI tool."
- Key evidence:
  - (src/Cognichip_NetworkArbiter/4x4/eda_results.json), (src/Cognichip_NetworkArbiter/8x8/eda_results.json)
  - (src/Cognichip_NetworkArbiter/README.md) — references Cognichip ACI

### C) Innovation & Creativity (8/15)
- Strengths:
  - Two arbiter sizes (4×4 and 8×8) with round-robin priority, submitted as a network switch module.
  - Acknowledge-based priority-hold semantics in 8×8 design (grant held until ack) adds a real protocol feature.
- Weaknesses:
  - Round-robin arbiters are standard designs; limited algorithmic novelty.
  - No advanced features such as weighted fair queuing, credit-based flow control, or QoS.

### D) Clarity of Presentation (17/25)
#### D1) Slides clarity (7/10)
- Notes: PDF covers network switch motivation, arbiter architecture, and test results.
- Evidence: (slides/Cognichip Hackathon Presentation (Gary Guan, Az Li).pdf)

#### D2) Video clarity (7/10)
- Notes: Video present; covers project overview and demo.
- Evidence: (video/al7675_xg2523_cognichip.mp4)

#### D3) Repo Organization (3/5)
- Notes: README is brief (3 short paragraphs). No unified project-level README or architecture diagram in source. EDA results placed in flat `4x4/` and `8x8/` directories alongside RTL, which is functional but not ideal.
- Evidence: (src/Cognichip_NetworkArbiter/README.md)

### E) Potential Real-World Impact (6/10)
- Notes: Network switch arbiters are fundamental to on-chip interconnects (NoC, AXI crossbars). Dual-size implementation is practically useful, though not differentiated from existing open-source arbiters.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA constraints or tapeout plan found.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Good** (67/110)
- Both designs are cleanly verified on the Cognichip platform with comprehensive round-robin tests and expected/actual LOG assertions. Score is limited by minimal platform iteration, brief documentation, and incremental innovation.

## Actionable Feedback (Most Important Improvements)
1. Add a more comprehensive testbench (e.g., starvation test, random request patterns, burst traffic) to strengthen verification coverage.
2. Expand README with architecture diagrams, performance characteristics, and instructions for reproducing results.
3. Consider adding synthesis area estimates (even via Yosys) to quantify the 4×4 vs 8×8 trade-offs.

## Issues (If Any)
- `4x4/temp.txt` (empty scratch file) committed; remove or add to `.gitignore`.
- No waveform files committed despite Cognichip EDA supporting wave capture.
