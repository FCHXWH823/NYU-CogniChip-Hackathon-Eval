# CogniChip Hackathon Evaluation Receipt — group016

## Submission Overview
- Team folder: `group016`
- Slides: `slides/FunkyMonkey - A RISC-V Neural Processing Accelerator for Edge AI Inference.pdf`
- Video: `video/Cognichip Hackathon (Ferdi, Tyler, Hivansh).mp4`
- Code/Repo: `src/neurisc_cognichip_hackathon/` — directory present but **empty** (no files committed)
- Evidence completeness: **Very Low** — slides and video present but unreadable; source code directory is entirely empty.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 5 | 30 |
| Cognichip Platform Usage | 5 | 20 |
| Innovation & Creativity | 10 | 15 |
| Clarity — Slides | 6 | 10 |
| Clarity — Video | 6 | 10 |
| Clarity — Repo Organization | 0 | 5 |
| Potential Real-World Impact | 7 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **39** | **110** |

## Detailed Evaluation

### A) Technical Correctness (5/30)
- Strengths:
  - Project title "RISC-V Neural Processing Accelerator for Edge AI Inference" is technically specific and ambitious.
  - Team names (Ferdi, Tyler, Hivansh) and video present.
- Weaknesses / Missing evidence:
  - `src/neurisc_cognichip_hackathon/` is completely empty — no RTL, testbench, README, or simulation artifact.
  - Cap rule applied: no simulation/verification evidence → capped at 12/30; scored 5/30.
- Key evidence:
  - (slides/FunkyMonkey - A RISC-V Neural Processing Accelerator for Edge AI Inference.pdf — present, unreadable)
  - *(no code evidence)*

### B) Effective Use of the Cognichip Platform (5/20)
- Strengths:
  - Video filename includes "Cognichip Hackathon" suggesting platform was used.
- Weaknesses / Missing evidence:
  - No DEPS.yml, EDA logs, simulation results.
  - Cap rule applied; scored 5/20.
- Key evidence:
  - (video/Cognichip Hackathon (Ferdi, Tyler, Hivansh).mp4 — title implies platform use)

### C) Innovation & Creativity (10/15)
- Strengths:
  - A RISC-V Neural Processing Accelerator (NPA) for edge AI inference combining a standard ISA with neural acceleration is an interesting and timely target.
  - "FunkyMonkey" branding suggests a distinct design identity; "NeuRISC" name in src folder implies RISC-V + neural integration.
  - Combining RISC-V base ISA with neural/ML-specific extensions is a genuinely novel direction.
- Weaknesses:
  - Without code or slides content, specific innovations (e.g., ISA extensions, MAC arrays, memory bandwidth optimization) cannot be verified.
- Key evidence: *(inferred from slide title)*

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (6/10)
- Notes: PDF present with highly descriptive title. Cannot assess internal quality.
- Evidence: (slides/FunkyMonkey - A RISC-V Neural Processing Accelerator for Edge AI Inference.pdf)

#### D2) Video clarity (6/10)
- Notes: MP4 present. Cannot parse.
- Evidence: (video/Cognichip Hackathon (Ferdi, Tyler, Hivansh).mp4)

#### D3) Repo organization (0/5)
- Notes: `src/neurisc_cognichip_hackathon/` is empty.
- Evidence: *(absent)*

### E) Potential Real-World Impact (7/10)
- Notes: RISC-V neural accelerators for edge AI inference are a hot research/product area (e.g., SiFive P-series, CVITEK). A working implementation would have genuine commercial relevance.
- Evidence: *(inferred from project title)*

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No evidence.
- Evidence: *(absent)*

## Final Recommendation
- Overall verdict: **Intriguing concept with zero verifiable implementation — empty source directory.**
- The project topic (RISC-V NPA for edge AI) is among the most commercially relevant in this cohort, but the complete absence of source code makes it impossible to score technically. The slides and video alone are insufficient for a strong evaluation.

## Actionable Feedback (Most Important Improvements)
1. **Submit source code**: Push RISC-V RTL with neural extensions, testbenches, and DEPS.yml to `src/neurisc_cognichip_hackathon/`.
2. **Provide simulation evidence**: A Cognichip EDA run log showing at least one neural operation (MAC/dot-product) would substantially improve the score.
3. **Describe ISA extensions**: Document any custom neural instructions added to the RISC-V base ISA with encoding and semantics.

## Issues (If Any)
- PDF slides and MP4 video cannot be parsed in this environment.
- `src/neurisc_cognichip_hackathon/` directory is entirely empty.
