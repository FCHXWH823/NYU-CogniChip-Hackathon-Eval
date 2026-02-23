# CogniChip Hackathon Evaluation Receipt — group014

## Submission Overview
- Team folder: `group014`
- Slides: `slides/FABB - Cognichip (Bob Huang, Shahran Newaz).pdf`
- Video: `video/CogniChip Demo (Shahran Newaz & Bob Huang).mp4`
- Code/Repo: `src/Bug-Buster/` — directory exists but is empty; no files committed.
- Evidence completeness: Minimal — slides and video only; no code, no simulation results.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 0 | 30 |
| Cognichip Platform Usage | 0 | 20 |
| Innovation & Creativity | 8 | 15 |
| Clarity — Slides | 6 | 10 |
| Clarity — Video | 6 | 10 |
| Clarity — Repo Organization | 0 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **26** | **110** |

## Detailed Evaluation

### A) Technical Correctness (0/30)
- Strengths:
  - None — no code or simulation evidence submitted.
- Weaknesses / Missing evidence:
  - Cap rule applied and floor applied: `src/Bug-Buster/` is an empty directory.
  - No RTL, no testbench, no simulation logs, no EDA results.
- Key evidence:
  - None.

### B) Effective Use of the Cognichip Platform (0/20)
- Strengths:
  - None.
- Weaknesses / Missing evidence:
  - Empty `src/` directory; no DEPS.yml, no EDA results.
- Key evidence:
  - None.

### C) Innovation & Creativity (8/15)
- Strengths:
  - "FABB" (Fast AI-Based Bug-Buster) concept for automated RTL bug detection/correction using AI is a relevant and non-trivial idea.
  - Targeting RTL verification escape detection aligns with real chip-design pain points.
- Weaknesses:
  - Concept only; no implementation to assess technical novelty.
- Key evidence:
  - (slides/FABB - Cognichip (Bob Huang, Shahran Newaz).pdf) — concept described

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (6/10)
- Notes: PDF slides submitted. Content cannot be verified without parsing; score based on presence and project concept inferred from filename.
- Evidence: (slides/FABB - Cognichip (Bob Huang, Shahran Newaz).pdf)

#### D2) Video clarity (6/10)
- Notes: Video present.
- Evidence: (video/CogniChip Demo (Shahran Newaz & Bob Huang).mp4)

#### D3) Repo Organization (0/5)
- Notes: `src/Bug-Buster/` is an empty directory.
- Evidence: None.

### E) Potential Real-World Impact (6/10)
- Notes: Automated RTL bug detection is a high-value industrial application. Without implementation, impact cannot be substantiated but the concept is credible.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No evidence.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Very Poor** (26/110)
- Slides and video concept are plausible, but no code was submitted. Technical Correctness, Cognichip Platform Usage, and Repo Organization all score zero.

## Actionable Feedback (Most Important Improvements)
1. Submit at least one implemented RTL module and a testbench with an EDA simulation run.
2. Populate `src/Bug-Buster/` with actual implementation code, even if partial.
3. Add DEPS.yml and commit Cognichip EDA results to demonstrate platform use.

## Issues (If Any)
- `src/Bug-Buster/` is an empty directory; no code submitted.
