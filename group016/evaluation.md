# CogniChip Hackathon Evaluation Receipt — group016

## Submission Overview
- Team folder: `group016`
- Slides: `slides/FunkyMonkey - A RISC-V Neural Processing Accelerator for Edge AI Inference.pdf`
- Video: `video/Cognichip Hackathon (Ferdi, Tyler, Hivansh).mp4`
- Code/Repo: `src/neurisc_cognichip_hackathon/` — directory exists but is empty; no files committed.
- Evidence completeness: Minimal — slides and video only; no code, no simulation results.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 0 | 30 |
| Cognichip Platform Usage | 0 | 20 |
| Innovation & Creativity | 9 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 6 | 10 |
| Clarity — Repo Organization | 0 | 5 |
| Potential Real-World Impact | 7 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **29** | **110** |

## Detailed Evaluation

### A) Technical Correctness (0/30)
- Strengths:
  - None — no code or simulation evidence submitted.
- Weaknesses / Missing evidence:
  - `src/neurisc_cognichip_hackathon/` is an empty directory; no RTL, no testbench, no EDA results.
- Key evidence:
  - None.

### B) Effective Use of the Cognichip Platform (0/20)
- Strengths:
  - None.
- Weaknesses / Missing evidence:
  - No DEPS.yml, no EDA results, no platform interaction logs.
- Key evidence:
  - None.

### C) Innovation & Creativity (9/15)
- Strengths:
  - "FunkyMonkey" — a RISC-V Neural Processing Accelerator for Edge AI Inference — is an ambitious concept combining a custom RISC-V ISA extension with neural network acceleration for edge deployment.
  - Targeting edge AI inference with a custom NPU is a relevant and commercially interesting direction.
- Weaknesses:
  - Concept only; no implementation to evaluate technical novelty or design decisions.
- Key evidence:
  - (slides/FunkyMonkey - A RISC-V Neural Processing Accelerator for Edge AI Inference.pdf) — concept described

### D) Clarity of Presentation (13/25)
#### D1) Slides clarity (7/10)
- Notes: PDF title suggests a well-framed presentation covering RISC-V NPU motivation and architecture. Scored based on presence and inferred content quality from the detailed slide filename.
- Evidence: (slides/FunkyMonkey - A RISC-V Neural Processing Accelerator for Edge AI Inference.pdf)

#### D2) Video clarity (6/10)
- Notes: Video present.
- Evidence: (video/Cognichip Hackathon (Ferdi, Tyler, Hivansh).mp4)

#### D3) Repo Organization (0/5)
- Notes: `src/neurisc_cognichip_hackathon/` is an empty directory.
- Evidence: None.

### E) Potential Real-World Impact (7/10)
- Notes: Edge AI inference accelerators tightly coupled with a RISC-V processor are commercially highly relevant (e.g., SiFive X280 P series, RISC-V ISP). The concept scores well on impact potential; implementation is needed to confirm feasibility.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No evidence.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Poor** (29/110)
- The NPU concept is one of the stronger ideas in the empty-src group, but no implementation was submitted.

## Actionable Feedback (Most Important Improvements)
1. Submit at minimum an RTL sketch of one NPU functional unit (e.g., MAC array, activation function, RISC-V custom instruction decode) with a testbench.
2. Add DEPS.yml and commit at least one Cognichip EDA simulation run.
3. Provide architecture diagrams with quantitative goals (throughput, area, power) to back the edge AI claims.

## Issues (If Any)
- `src/neurisc_cognichip_hackathon/` is an empty directory; no code submitted.
