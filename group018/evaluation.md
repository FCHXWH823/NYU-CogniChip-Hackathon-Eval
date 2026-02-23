# CogniChip Hackathon Evaluation Receipt — group018

## Submission Overview
- Team folder: `group018`
- Slides: `slides/On-board Image Classification.pdf`
- Video: `video/hackthon.mp4`
- Code/Repo: `src/Design-Project/` — directory present but **empty** (no files committed)
- Evidence completeness: **Very Low** — slides and video present (unreadable); source code directory is entirely empty.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 5 | 30 |
| Cognichip Platform Usage | 5 | 20 |
| Innovation & Creativity | 8 | 15 |
| Clarity — Slides | 6 | 10 |
| Clarity — Video | 5 | 10 |
| Clarity — Repo Organization | 0 | 5 |
| Potential Real-World Impact | 7 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **36** | **110** |

## Detailed Evaluation

### A) Technical Correctness (5/30)
- Strengths:
  - "On-board Image Classification" implies a complete ML inference pipeline on hardware — a concrete and testable objective.
- Weaknesses / Missing evidence:
  - `src/Design-Project/` is completely empty.
  - No CNN/model description, no RTL, no quantization scheme, no simulation evidence.
  - Cap rule applied: no simulation/verification evidence → capped at 12/30; scored 5/30.
- Key evidence:
  - (slides/On-board Image Classification.pdf — present, unreadable)
  - *(no code evidence)*

### B) Effective Use of the Cognichip Platform (5/20)
- Strengths:
  - Project is a hackathon submission, implying Cognichip platform exposure.
- Weaknesses / Missing evidence:
  - No DEPS.yml, EDA logs. Video filename "hackthon.mp4" (typo) does not reference Cognichip specifically.
  - Cap rule applied; scored 5/20.
- Key evidence: *(none specific to Cognichip)*

### C) Innovation & Creativity (8/15)
- Strengths:
  - On-board (embedded) image classification combining CNN inference with hardware acceleration is a relevant and technically interesting challenge.
  - Implies a full pipeline from image input to classification output on a custom chip.
- Weaknesses:
  - Without code, specific innovations (network architecture, quantization, data path) are unknown.
- Key evidence: *(inferred from slide title)*

### D) Clarity of Presentation (11/25)
#### D1) Slides clarity (6/10)
- Notes: PDF present with descriptive title. Cannot assess internal quality.
- Evidence: (slides/On-board Image Classification.pdf)

#### D2) Video clarity (5/10)
- Notes: MP4 present. Filename "hackthon.mp4" (typo in "hackathon") is non-descriptive, reducing professionalism.
- Evidence: (video/hackthon.mp4)

#### D3) Repo organization (0/5)
- Notes: `src/Design-Project/` is empty.
- Evidence: *(absent)*

### E) Potential Real-World Impact (7/10)
- Notes: On-board image classification is commercially valuable across autonomous systems, surveillance, medical imaging, and IoT. Hardware acceleration of CNNs is an active product category (Google Edge TPU, Apple Neural Engine, etc.).
- Evidence: *(inferred from project title)*

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No evidence.
- Evidence: *(absent)*

## Final Recommendation
- Overall verdict: **Interesting concept with no verifiable implementation — empty source code.**
- On-board image classification is a commercially relevant target, but without any source code, test results, or model specifications, the submission cannot be technically evaluated.

## Actionable Feedback (Most Important Improvements)
1. **Commit design files**: Push RTL (or HLS), CNN model description, and Cognichip DEPS.yml to `src/Design-Project/`.
2. **Fix video filename**: Rename `hackthon.mp4` to a descriptive name (e.g., `on_board_image_classification_demo.mp4`).
3. **Provide quantization/accuracy data**: For an image classification system, state which model (e.g., MobileNet), what dataset, what accuracy, and what inference latency in cycles/ms.

## Issues (If Any)
- PDF slides and MP4 video cannot be parsed in this environment.
- `src/Design-Project/` directory is entirely empty.
- Video filename contains a typo ("hackthon" instead of "hackathon").
