# CogniChip Hackathon Evaluation Receipt — Moving Average Filter / Tiny Tapeout

## Submission Overview
- Team folder: `group017`
- Slides: `slides/moving_average_filter_presentation.pdf`
- Video: None
- Code/Repo: `src/Sensors_and_Security/` — SystemVerilog moving average filter, Tiny Tapeout config
- Evidence completeness: Good — Tiny Tapeout info.yaml, GitHub Actions CI/CD badge (gds workflow), testbench with 6 scenarios; no simulation log output committed.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 18 | 30 |
| Cognichip Platform Usage | 10 | 20 |
| Innovation & Creativity | 10 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 8 | 10 |
| **Total** | **63** | **110** |

## Detailed Evaluation

### A) Technical Correctness (18/30)
- Strengths:
  - Complete Tiny Tapeout-compliant SystemVerilog design (`tt_um_jonathan_farah_moving_average_filter.sv`) with 24-pin interface mapping.
  - README provides a concrete quick test scenario with expected result ((16+32+48+64)/4 = 40 verified manually).
  - GitHub Actions workflows for `gds` (layout generation) and `docs` build present — CI/CD badges in README.
  - `info.yaml` with complete Tiny Tapeout configuration including pin assignments and test vectors for SkyWater 130nm.
  - TINYTAPEOUT_SUMMARY.md documents 8-bit version: ~140 FFs, ~400 gates (60% reduction from 32-bit version).
- Weaknesses / Missing evidence:
  - No testbench simulation output log committed showing pass/fail results.
  - Design correctness relies on README description and CI badge, not committed simulation logs.
- Key evidence:
  - (src/Sensors_and_Security/README.md — quick test with expected result)
  - (src/Sensors_and_Security/info.yaml — TT08 configuration)
  - (src/Sensors_and_Security/.github/workflows/gds.yaml — CI/CD flow)
  - (src/Sensors_and_Security/TINYTAPEOUT_SUMMARY.md)

### B) Effective Use of the Cognichip Platform (10/20)
- Strengths:
  - README states "Cognichip platform is recommended" for simulation and synthesis.
  - AGENTS.md file (present per repo structure) suggests AI agent workflow.
- Weaknesses / Missing evidence:
  - No explicit Cognichip prompt log or detailed workflow description.
  - Cognichip referenced as a tool recommendation rather than a core design driver.
- Key evidence:
  - (src/Sensors_and_Security/README.md — Cognichip recommendation)

### C) Innovation & Creativity (10/15)
- Strengths:
  - Adapting a moving average filter specifically for Tiny Tapeout's constrained 24-pin interface is a thoughtful design exercise.
  - Circular buffer architecture (no data shifting) is an efficient implementation choice.
  - Power-of-2 optimization for division is a practical hardware constraint.
  - The overall project (Smart Low-Power Proximity Sensor SoC) shows broader system context.
- Weaknesses:
  - Moving average filter itself is a standard DSP building block; the innovation is in the TT adaptation and implementation quality.
- Key evidence:
  - (src/.../README.md — circular buffer architecture, power-of-2 optimization)

### D) Clarity of Presentation (11/25)
#### D1) Slides clarity (7/10)
- Notes: PDF exists; cannot verify content directly, but reasonable base score awarded.
- Evidence: `slides/moving_average_filter_presentation.pdf`

#### D2) Video clarity (0/10)
- Notes: No video submission.
- Evidence: No video folder present.

#### D3) Repo organization (4/5)
- Notes: Good structure with src/, test/, docs/, .github/workflows/. Multiple documentation files (TINYTAPEOUT_SETUP.md, TINYTAPEOUT_SUMMARY.md, README_TINYTAPEOUT.md). README_TINYTAPEOUT badge links are live references.
- Evidence: (src/Sensors_and_Security/ directory structure)

### E) Potential Real-World Impact (6/10)
- Notes: Tiny Tapeout submission represents a path to actual silicon fabrication, which is a significant achievement. Moving average filters are ubiquitous in embedded sensor signal conditioning. The Smart Proximity Sensor SoC concept has IoT applicability.
- Evidence: README — "Ready for Tiny Tapeout TT08 fabrication! 🎉"

### Bonus) FPGA / Tiny Tapeout Targeting (+8/10)
- Notes: Strong Tiny Tapeout evidence: complete `info.yaml` with SkyWater 130nm target, GitHub Actions gds workflow, pin assignments for TT08, test vectors, TINYTAPEOUT_SETUP.md with detailed submission steps. This is a credible and well-prepared TT submission.
- Evidence:
  - (src/Sensors_and_Security/info.yaml — TT08, SkyWater 130nm)
  - (src/Sensors_and_Security/.github/workflows/gds.yaml — GDS build workflow)
  - (src/Sensors_and_Security/TINYTAPEOUT_SETUP.md)

## Final Recommendation
- Overall verdict: **Strong submission**
- This submission demonstrates genuine hardware engineering discipline with a complete Tiny Tapeout targeting pipeline, CI/CD, and careful interface adaptation. The combination of working design + TT submission readiness makes it stand out in the fabrication bonus category.

## Actionable Feedback (Most Important Improvements)
1. Commit testbench simulation output logs to provide concrete correctness evidence beyond the README description.
2. Add a video walkthrough of the design, testbench results, and the Tiny Tapeout submission process.
3. Expand the design to the full Smart Low-Power Proximity Sensor SoC to demonstrate the broader system context mentioned in the overview.

## Issues (If Any)
- GitHub Actions badge URLs reference an external repository (jonathan-farah/Sensors_and_Security); workflow status may not reflect the state of files in this submission.
