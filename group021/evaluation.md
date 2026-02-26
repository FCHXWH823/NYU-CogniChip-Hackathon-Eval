# CogniChip Hackathon Evaluation Receipt — group021

## Submission Overview
- Team folder: `group021`
- Slides: `slides/Submission Note - QuantEdge Silicon.pdf`
- Video: `video/Hackathon_QuantSilicon.mp4`
- Code/Repo: `src/hackathon_QuantSilicon/` — directory exists but is empty; no files committed.
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
  - `src/hackathon_QuantSilicon/` is an empty directory; no RTL, no testbench, no EDA results.
- Key evidence:
  - None.

### B) Effective Use of the Cognichip Platform (0/20)
- Strengths:
  - None.
- Weaknesses / Missing evidence:
  - No DEPS.yml, no EDA results, no ACI interaction logs.
- Key evidence:
  - None.

### C) Innovation & Creativity (7/15)
- Strengths:
  - "QuantEdge Silicon" name implies quantisation-aware hardware design for edge inference — a commercially relevant and technically interesting direction.
  - Quantisation-aware design for silicon is a non-trivial challenge combining numerical precision management with hardware efficiency.
- Weaknesses:
  - Concept only; no implementation details available.
- Key evidence:
  - (slides/Submission Note - QuantEdge Silicon.pdf) — concept described

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (6/10)
- Notes: PDF is labelled a "Submission Note" rather than a full presentation, suggesting it may be brief.
- Evidence: (slides/Submission Note - QuantEdge Silicon.pdf)

#### D2) Video clarity (6/10)
- Notes: Video present.
- Evidence: (video/Hackathon_QuantSilicon.mp4)

#### D3) Repo Organization (0/5)
- Notes: `src/hackathon_QuantSilicon/` is an empty directory.
- Evidence: None.

### E) Potential Real-World Impact (6/10)
- Notes: Quantisation-aware silicon for edge AI inference is a high-value domain (INT8/INT4 accelerators). A working implementation would have strong commercial applicability.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No evidence.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Very Poor** (25/110)
- Slides are described as a "submission note" rather than a full technical presentation; no code was submitted.

## Actionable Feedback (Most Important Improvements)
1. Implement at least one quantised compute unit (e.g., INT8 multiplier or a quantised MAC) and run it through Cognichip EDA.
2. Expand the submission note into a full technical presentation with architecture diagrams.
3. Add DEPS.yml and commit Cognichip EDA results.

## Issues (If Any)
- Slides described as a "Submission Note" — likely brief, not a full technical presentation.
- `src/hackathon_QuantSilicon/` is an empty directory; no code submitted.
