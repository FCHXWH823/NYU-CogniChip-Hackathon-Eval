# CogniChip Hackathon Evaluation Receipt — group017

## Submission Overview
- Team folder: `group017`
- Slides: `slides/moving_average_filter_presentation.pdf`
- Video: **None submitted**
- Code/Repo: `src/Sensors_and_Security/` — directory exists but is empty; no files committed.
- Evidence completeness: Minimal — slides only; no video, no code, no simulation results.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 0 | 30 |
| Cognichip Platform Usage | 0 | 20 |
| Innovation & Creativity | 5 | 15 |
| Clarity — Slides | 6 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 0 | 5 |
| Potential Real-World Impact | 4 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **15** | **110** |

## Detailed Evaluation

### A) Technical Correctness (0/30)
- Strengths:
  - None — no code or simulation evidence submitted.
- Weaknesses / Missing evidence:
  - `src/Sensors_and_Security/` is an empty directory; no RTL, no testbench, no EDA results.
- Key evidence:
  - None.

### B) Effective Use of the Cognichip Platform (0/20)
- Strengths:
  - None.
- Weaknesses / Missing evidence:
  - No DEPS.yml, no EDA results, no ACI interaction logs.
- Key evidence:
  - None.

### C) Innovation & Creativity (5/15)
- Strengths:
  - A hardware moving average filter with a "Sensors and Security" context implies real-time signal processing applications.
- Weaknesses:
  - Moving average filter is a classic and simple DSP design. No implementation to assess creativity.
- Key evidence:
  - (slides/moving_average_filter_presentation.pdf) — concept described

### D) Clarity of Presentation (6/25)
#### D1) Slides clarity (6/10)
- Notes: PDF slides submitted. Content not parseable; scored conservatively.
- Evidence: (slides/moving_average_filter_presentation.pdf)

#### D2) Video clarity (0/10)
- Notes: No video submitted. Score is zero per rubric.
- Evidence: `video/` directory does not exist.

#### D3) Repo Organization (0/5)
- Notes: `src/Sensors_and_Security/` is an empty directory.
- Evidence: None.

### E) Potential Real-World Impact (4/10)
- Notes: Hardware moving average filters are used in sensor signal conditioning and security systems; however, the impact of a simple FIR filter is limited.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No evidence.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Very Poor** (15/110)
- Only slides were submitted — no video, no code. This is the lowest-evidence submission in the cohort.

## Actionable Feedback (Most Important Improvements)
1. Submit RTL implementation of the moving average filter with a testbench and EDA simulation.
2. Record and submit a demo video demonstrating the filter's operation.
3. Add DEPS.yml and commit Cognichip EDA results to demonstrate platform engagement.

## Issues (If Any)
- No video submitted; D2 score is zero.
- `src/Sensors_and_Security/` is an empty directory; no code submitted.
