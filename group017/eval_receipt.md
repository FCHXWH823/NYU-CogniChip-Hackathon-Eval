# CogniChip Hackathon Evaluation Receipt — group017

## Submission Overview
- Team folder: `group017`
- Slides: `slides/moving_average_filter_presentation.pdf`
- Video: None
- Code/Repo: `src/Sensors_and_Security/` (48 files; moving average filter + ADC controller RTL with multiple EDA simulation results, waveforms, and waveform viewing guide)
- Evidence completeness: Good — Cognichip EDA results present showing tests 1 and 2 passing with timeout error detection; iterative debugging history visible; slides provide comprehensive code dissection.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 21 | 30 |
| Cognichip Platform Usage | 14 | 20 |
| Innovation & Creativity | 9 | 15 |
| Clarity — Slides | 8 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 7 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **63** | **110** |

## Detailed Evaluation

### A) Technical Correctness (21/30)
- Strengths:
  - EDA results confirm: "TEST 1: PASSED", "TEST 2: PASSED", timeout error detection working.
  - Two simulation runs show progression — earlier run had errors (samples_captured mismatch, power_enable error, simulation timeout), latest run shows TEST 1 and TEST 2 passing.
  - Waveform viewing guide (`WAVEFORM_VIEWING_GUIDE.md`) and batch file (`view_waveforms.bat`) committed.
  - Simulation results with `eda_results.json` and `dumpfile.fst` waveforms.
  - ADC controller with state machine and handshake protocol verified.
  - Configurable filter length (1–15 taps) with circular buffer — substantive RTL.
- Weaknesses / Missing evidence:
  - TEST 3 is "Timeout Error Detection" — partially verified (timeout detected but not a full pass).
  - Earlier runs showed samples_captured and power_enable assertion failures suggesting debugging was still in progress.
  - No third run confirming all tests stable.
- Key evidence:
  - (src/Sensors_and_Security/simulation_results/sim_2026-02-19T04-29-02-713Z/eda_results.json — TEST 1: PASSED, TEST 2: PASSED)
  - (src/Sensors_and_Security/simulation_results/sim_2026-02-19T04-24-52-960Z/eda_results.json — earlier failures)
  - (src/Sensors_and_Security/simulation_results/sim_2026-02-19T04-29-02-713Z/eda_results.json — dumpfile.fst)

### B) Effective Use of the Cognichip Platform (14/20)
- Strengths:
  - EDA version 0.3.10 confirmed — Cognichip platform actively used.
  - Multiple simulation runs (3 timestamped) show iterative use of Cognichip for debugging.
  - Waveform viewing workflow documented.
- Weaknesses / Missing evidence:
  - No description in slides of specific Cognichip workflow or prompts.
  - Slides are a "code dissection" format — no design methodology section describing platform use.
- Key evidence:
  - (src/Sensors_and_Security/simulation_results/ — 3 EDA run directories)

### C) Innovation & Creativity (9/15)
- Strengths:
  - Combined SoC design (moving average filter + ADC controller + proximity sensor) is a coherent system.
  - Runtime-configurable filter length (1–15 taps) adds flexibility.
  - State machine-driven pipelined operation with handshake protocol shows real hardware design thinking.
- Weaknesses:
  - Moving average filter and ADC controller are standard textbook designs.
  - The "Sensors and Security" combination is not deeply motivated — the security aspect is not evident in the code.
- Key evidence:
  - (slides/moving_average_filter_presentation.pdf — "Smart Low-Power Proximity Sensor SoC")
  - (src/Sensors_and_Security/ — filter + ADC modules)

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (8/10)
- Notes: Very detailed code dissection format — explains module declaration, design philosophy, key features, and trade-offs. More of a technical reference than a presentation, but comprehensive. Generated from markdown source.
- Evidence: (slides/moving_average_filter_presentation.pdf — 20-page code dissection)

#### D2) Video clarity (0/10)
- Notes: No video submitted.
- Evidence: No video directory.

#### D3) Repo organization (4/5)
- Notes: Well-organized with simulation results directories, waveform viewing guides, README, and WAVEFORM_VIEWING_GUIDE.md. 48 files with good structure.
- Evidence: (src/Sensors_and_Security/ — guides, simulation results)

### E) Potential Real-World Impact (7/10)
- Notes: Low-power proximity sensor SoC with noise filtering is applicable to IoT and smart home devices. Configurable filter length adds practical flexibility for different sensor types.
- Evidence: (slides/moving_average_filter_presentation.pdf — "Low-power proximity sensor SoC requiring adaptive noise filtering")

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA constraints, synthesis reports, or tapeout evidence.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Above Average**
- Solid sensor SoC implementation with genuine Cognichip EDA evidence (Tests 1 & 2 passing). The iterative debugging history and waveform documentation show good engineering practice. Score limited by narrow design scope, no video, and incomplete test 3 resolution.

## Actionable Feedback (Most Important Improvements)
1. Fix remaining simulation issues to achieve full test pass including TEST 3.
2. Add a brief design methodology section to slides explaining how Cognichip was used.
3. Record a short demo video showing the filter operation on waveforms.

## Issues (If Any)
- No video submitted.
- TEST 3 (timeout error detection) not conclusively PASS.
- Slides are code-dissection format — no design methodology or architecture overview.
