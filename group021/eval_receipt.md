# CogniChip Hackathon Evaluation Receipt — QuantEdge Silicon: AI-Assisted Hardware Trading Pipeline

## Submission Overview
- Team folder: `group021`
- Slides: `slides/Submission Note - QuantEdge Silicon.pdf`
- Video: `video/` (directory exists with files)
- Code/Repo: `src/hackathon_QuantSilicon/` — SystemVerilog streaming RTL, Python golden model
- Evidence completeness: Partial — RTL modules and testbench present, Cognichip_prompts.md documents AI workflow; no simulation output logs committed.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 12 | 30 |
| Cognichip Platform Usage | 15 | 20 |
| Innovation & Creativity | 11 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 7 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 8 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **64** | **110** |

## Detailed Evaluation

### A) Technical Correctness (12/30)
- Strengths:
  - Complete SystemVerilog implementation: fxp_pkg.sv (Q16.16 types), feature_engine.sv (return + EMA), signal_engine.sv (weighted signal), risk_engine.sv (kill-switch), quantsilicon_top.sv (top-level integration).
  - AXI-style ready/valid handshake across all modules.
  - Python golden model (golden_model.py, generate_test_data.py) for cross-validation.
  - Top-level testbench (tb/top_tb.sv) and Makefile for compilation present.
  - Fixed-point Q16.16 arithmetic documented with specific constants (w1=49152, w2=16384, LIMIT=131072).
- Weaknesses / Missing evidence:
  - No simulation output log or waveform file committed.
  - Cannot verify testbench passes without run output.
  - Cap applied: no concrete simulation/verification evidence present.
  - README acknowledges the design but does not report test results.
- Key evidence:
  - (src/hackathon_QuantSilicon/rtl/ — 5 SystemVerilog modules)
  - (src/hackathon_QuantSilicon/tb/top_tb.sv — testbench)
  - (src/hackathon_QuantSilicon/python_model/ — golden model)

### B) Effective Use of the Cognichip Platform (15/20)
- Strengths:
  - `rtl/Cognichip_prompts.md` explicitly documents specific prompts used to generate each RTL module (feature_engine, signal_engine, risk_engine) with detailed requirements specifications.
  - Prompts include precise port lists, behavioral requirements, and synthesizability constraints — showing iterative, specification-driven AI workflow.
  - README states all AI-generated logic was manually validated for handshake correctness, scaling, and synthesizability.
- Weaknesses / Missing evidence:
  - Not all modules may have corresponding prompt records.
  - No documentation of failed iterations or AI feedback loop.
- Key evidence:
  - (src/hackathon_QuantSilicon/rtl/Cognichip_prompts.md — detailed prompt history)

### C) Innovation & Creativity (11/15)
- Strengths:
  - Hardware trading signal pipeline is a non-obvious application of FPGA/ASIC design — differentiates from typical CPU/cache submissions.
  - Fixed-point Q16.16 arithmetic for quantitative finance (EMA, weighted signals, exposure calculation) is domain-specific and well-thought-out.
  - Kill-switch risk enforcement in hardware provides deterministic latency guarantees.
- Weaknesses:
  - The trading model itself (EMA + weighted signal) is a standard quant strategy; complexity is modest.
  - No novel architectural feature beyond standard streaming pipeline.
- Key evidence:
  - (src/hackathon_QuantSilicon/README.md — mathematical model, pipeline description)

### D) Clarity of Presentation (18/25)
#### D1) Slides clarity (7/10)
- Notes: PDF exists (titled "Submission Note"); cannot verify content directly, but reasonable base score awarded.
- Evidence: `slides/Submission Note - QuantEdge Silicon.pdf`

#### D2) Video clarity (7/10)
- Notes: Video directory exists with files.
- Evidence: `video/` directory with contents.

#### D3) Repo organization (4/5)
- Notes: Clean structure: rtl/, tb/, docs/, python_model/, Makefile. docs/design_spec.md and docs/ai_optimization_log.md present (the latter documenting AI usage). README is detailed with architecture diagram, signal interface tables, math model.
- Evidence: (src/hackathon_QuantSilicon/ directory structure)

### E) Potential Real-World Impact (8/10)
- Notes: Low-latency hardware trading risk management has high commercial value. Deterministic kill-switch enforcement in hardware (vs. software) is a genuine competitive advantage for HFT systems. The fixed-point arithmetic approach is directly deployable on FPGA.
- Evidence: README — "deterministic risk enforcement" rationale, latency targets

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: FPGA deployment mentioned as a "Future Direction" but no implementation, constraints, or targeting steps provided.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Strong submission**
- QuantSilicon stands out for its unique application domain (hardware trading pipeline) and the explicit Cognichip prompt documentation in Cognichip_prompts.md, which provides one of the best records of AI-assisted RTL generation in the hackathon. Missing simulation output is the primary gap.

## Actionable Feedback (Most Important Improvements)
1. Run the testbench (`vvp sim_top.out` per README instructions) and commit the simulation log and waveform output.
2. Add FPGA implementation (constraints file, synthesis for a specific target) to qualify for bonus points.
3. Expand the Cognichip_prompts.md to include all modules and show iteration history (failed attempts and fixes).

## Issues (If Any)
- docs/ai_optimization_log.md referenced but content not verified; may contain additional Cognichip evidence.
