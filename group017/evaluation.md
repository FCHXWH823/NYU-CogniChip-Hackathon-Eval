# CogniChip Hackathon Evaluation Receipt — group017

## Submission Overview
- Team folder: `group017`
- Slides: `slides/moving_average_filter_presentation.pdf`
- Video: *(not present — no video/ folder)*
- Code/Repo: `src/Sensors_and_Security/` — directory present but **empty** (no files committed)
- Evidence completeness: **Very Low** — only slides are present (unreadable); no video, no source code, no simulation evidence.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 3 | 30 |
| Cognichip Platform Usage | 3 | 20 |
| Innovation & Creativity | 5 | 15 |
| Clarity — Slides | 5 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 0 | 5 |
| Potential Real-World Impact | 5 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **21** | **110** |

## Detailed Evaluation

### A) Technical Correctness (3/30)
- Strengths:
  - A moving average filter is a well-defined, verifiable DSP primitive; the project scope is clear from the title.
- Weaknesses / Missing evidence:
  - No source code, testbench, or simulation log.
  - No video to supplement the slides.
  - Cap rule applied: no simulation/verification evidence → capped at 12/30; scored 3/30 (slides-only, no video, no code).
- Key evidence:
  - (slides/moving_average_filter_presentation.pdf — present, unreadable)
  - *(no code evidence)*

### B) Effective Use of the Cognichip Platform (3/20)
- Strengths:
  - Submission was made in the CogniChip Hackathon context.
- Weaknesses / Missing evidence:
  - No DEPS.yml, EDA logs, or any Cognichip-specific artifact.
  - No mention of Cognichip in the filenames.
  - Cap rule applied; scored 3/20.
- Key evidence: *(none)*

### C) Innovation & Creativity (5/15)
- Strengths:
  - "Sensors_and_Security" src folder name suggests an application context (sensor data filtering for security systems) that adds domain relevance.
- Weaknesses:
  - A moving average filter is a basic DSP building block; without evidence of novel microarchitectural choices (e.g., optimized pipeline depth, configurable window, fixed-point quantization), innovation is assumed minimal.
- Key evidence: *(inferred from filenames)*

### D) Clarity of Presentation (5/25)
#### D1) Slides clarity (5/10)
- Notes: PDF present. Title is specific. No video to complement. Cannot assess internal quality.
- Evidence: (slides/moving_average_filter_presentation.pdf)

#### D2) Video clarity (0/10)
- Notes: No video/ folder present.
- Evidence: *(absent)*

#### D3) Repo organization (0/5)
- Notes: `src/Sensors_and_Security/` is empty; no README or code.
- Evidence: *(absent)*

### E) Potential Real-World Impact (5/10)
- Notes: Moving average filters are widely used in sensor processing, signal conditioning, and security systems. A hardware-efficient implementation on Cognichip could have real value, but the scope is narrow.
- Evidence: *(inferred from project title)*

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No evidence.
- Evidence: *(absent)*

## Final Recommendation
- Overall verdict: **Minimal submission — slides only, no video and no code; insufficient for technical evaluation.**
- The project targets a legitimate DSP primitive, but only a PDF slide deck was submitted with no supporting code or video. This is the least complete submission reviewed.

## Actionable Feedback (Most Important Improvements)
1. **Commit source code**: Push moving average filter RTL/Python to `src/Sensors_and_Security/` with a Cognichip DEPS.yml.
2. **Record a demo video**: Even a 2-minute screen capture of a simulation waveform would add 10 points.
3. **Broaden scope**: A moving average filter alone is narrow; consider framing it within the Sensors_and_Security application (e.g., anomaly detection, signal processing pipeline) to strengthen impact and innovation scores.

## Issues (If Any)
- PDF slides cannot be parsed in this environment.
- No video folder present.
- `src/Sensors_and_Security/` directory is entirely empty.
