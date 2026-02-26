# CogniChip Hackathon Evaluation Receipt — group018

## Submission Overview
- Team folder: `group018`
- Slides: `slides/On-board Image Classification.pdf`
- Video: `video/hackthon.mp4`
- Code/Repo: `src/Design-Project/` — directory exists but is empty; no files committed.
- Evidence completeness: Minimal — slides and video only; no code, no simulation results.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 0 | 30 |
| Cognichip Platform Usage | 0 | 20 |
| Innovation & Creativity | 7 | 15 |
| Clarity — Slides | 6 | 10 |
| Clarity — Video | 6 | 10 |
| Clarity — Repo Organization | 0 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **25** | **110** |

## Detailed Evaluation

### A) Technical Correctness (0/30)
- Strengths:
  - None — no code or simulation evidence submitted.
- Weaknesses / Missing evidence:
  - `src/Design-Project/` is an empty directory; no RTL, no testbench, no EDA results.
- Key evidence:
  - None.

### B) Effective Use of the Cognichip Platform (0/20)
- Strengths:
  - None.
- Weaknesses / Missing evidence:
  - No DEPS.yml, no EDA results, no platform interaction logs.
- Key evidence:
  - None.

### C) Innovation & Creativity (7/15)
- Strengths:
  - On-board image classification hardware accelerator is a relevant and technically interesting concept, combining CNN inference with hardware design.
  - "On-board" framing implies edge deployment on FPGA or ASIC — a concrete hardware target.
- Weaknesses:
  - Concept only; no implementation to evaluate actual technical decisions.
- Key evidence:
  - (slides/On-board Image Classification.pdf) — concept described

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (6/10)
- Notes: PDF slides submitted. Content not parseable; scored based on presence.
- Evidence: (slides/On-board Image Classification.pdf)

#### D2) Video clarity (6/10)
- Notes: Video present (note: filename `hackthon.mp4` has a typo suggesting it may be a quick recording).
- Evidence: (video/hackthon.mp4)

#### D3) Repo Organization (0/5)
- Notes: `src/Design-Project/` is an empty directory.
- Evidence: None.

### E) Potential Real-World Impact (6/10)
- Notes: Hardware CNN inference on edge devices is a hot commercial area (TinyML, edge AI chips). A working implementation would have significant real-world value.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No evidence.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Very Poor** (25/110)
- The image classification concept is commercially relevant, but no implementation was submitted.

## Actionable Feedback (Most Important Improvements)
1. Submit at least one hardware module (e.g., convolution unit, activation function) as RTL with a testbench.
2. Add DEPS.yml and run at least one `eda sim` to demonstrate Cognichip platform use.
3. Add a CNN topology specification (layer counts, filter sizes, data widths) to make the architecture concrete.

## Issues (If Any)
- `src/Design-Project/` is an empty directory; no code submitted.
- Video filename `hackthon.mp4` contains a typo.
