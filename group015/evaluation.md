# CogniChip Hackathon Evaluation Receipt — group015

## Submission Overview
- Team folder: `group015`
- Slides: `slides/FLUX_RV32I_Cognichip Presentation.pdf`
- Video: `video/CogniChip_TeamFLUX.mp4`
- Code/Repo: `src/FluxV/` — directory exists but is empty; no files committed.
- Evidence completeness: Minimal — slides and video only; no code, no simulation results.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 0 | 30 |
| Cognichip Platform Usage | 0 | 20 |
| Innovation & Creativity | 6 | 15 |
| Clarity — Slides | 6 | 10 |
| Clarity — Video | 6 | 10 |
| Clarity — Repo Organization | 0 | 5 |
| Potential Real-World Impact | 5 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **23** | **110** |

## Detailed Evaluation

### A) Technical Correctness (0/30)
- Strengths:
  - None — no code or simulation evidence submitted.
- Weaknesses / Missing evidence:
  - `src/FluxV/` is an empty directory; no RTL, no testbench, no EDA results.
- Key evidence:
  - None.

### B) Effective Use of the Cognichip Platform (0/20)
- Strengths:
  - None.
- Weaknesses / Missing evidence:
  - No DEPS.yml, no EDA results, no ACI interaction logs.
- Key evidence:
  - None.

### C) Innovation & Creativity (6/15)
- Strengths:
  - RV32I processor implementation with a custom design methodology ("FLUX" flow) suggests a structured design approach.
- Weaknesses:
  - Concept only; RV32I is a well-established baseline ISA.
- Key evidence:
  - (slides/FLUX_RV32I_Cognichip Presentation.pdf) — concept described

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (6/10)
- Notes: PDF slides submitted. Content not parseable; scored based on presence.
- Evidence: (slides/FLUX_RV32I_Cognichip Presentation.pdf)

#### D2) Video clarity (6/10)
- Notes: Video present.
- Evidence: (video/CogniChip_TeamFLUX.mp4)

#### D3) Repo Organization (0/5)
- Notes: `src/FluxV/` is an empty directory.
- Evidence: None.

### E) Potential Real-World Impact (5/10)
- Notes: RV32I processors are foundational; novel design methodology could add value. Without implementation, impact is speculative.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No evidence.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Very Poor** (23/110)
- Only slides and video were submitted; the source directory is empty.

## Actionable Feedback (Most Important Improvements)
1. Submit RV32I RTL implementation with at least a basic testbench and one passing EDA simulation.
2. Populate `src/FluxV/` with code and add DEPS.yml for Cognichip platform setup.
3. Demonstrate what "FLUX" methodology means concretely with design artifacts.

## Issues (If Any)
- `src/FluxV/` is an empty directory; no code submitted.
