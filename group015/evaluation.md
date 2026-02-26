# CogniChip Hackathon Evaluation Receipt — group015

## Submission Overview
- Team folder: `group015`
- Slides: `slides/FLUX_RV32I_Cognichip Presentation.pdf`
- Video: `video/CogniChip_TeamFLUX.mp4`
- Code/Repo: `src/FluxV/` — directory present but **empty** (no files committed)
- Evidence completeness: **Very Low** — slides and video present but unreadable in this environment; source code directory is entirely empty.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 5 | 30 |
| Cognichip Platform Usage | 5 | 20 |
| Innovation & Creativity | 8 | 15 |
| Clarity — Slides | 6 | 10 |
| Clarity — Video | 6 | 10 |
| Clarity — Repo Organization | 0 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **36** | **110** |

## Detailed Evaluation

### A) Technical Correctness (5/30)
- Strengths:
  - Slide title "FLUX_RV32I" implies an RV32I (RISC-V 32-bit integer) processor, a well-defined ISA — a clear technical target.
  - Video present.
- Weaknesses / Missing evidence:
  - `src/FluxV/` is completely empty — no RTL, testbench, README, or simulation artifact.
  - No waveform, logs, or executable artifacts to verify functional correctness.
  - Cap rule applied: no simulation/verification evidence → capped at 12/30; scored 5/30 due to empty src.
- Key evidence:
  - (slides/FLUX_RV32I_Cognichip Presentation.pdf — present, unreadable)
  - *(no code evidence)*

### B) Effective Use of the Cognichip Platform (5/20)
- Strengths:
  - "Cognichip" appears in both the slide filename and video filename, suggesting active platform use.
- Weaknesses / Missing evidence:
  - No DEPS.yml, EDA logs, or simulation results.
  - Cap rule applied; scored 5/20.
- Key evidence:
  - (slides/FLUX_RV32I_Cognichip Presentation.pdf — title suggests Cognichip was used)

### C) Innovation & Creativity (8/15)
- Strengths:
  - Implementing a full RV32I RISC-V processor using Cognichip is a non-trivial technical undertaking.
  - "FLUX" branding suggests a pipelined or high-performance variant.
- Weaknesses:
  - Without code or slides content, cannot verify any novel microarchitectural choices.
- Key evidence: *(inferred from slide title)*

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (6/10)
- Notes: PDF present with descriptive title. Cannot assess internal content.
- Evidence: (slides/FLUX_RV32I_Cognichip Presentation.pdf)

#### D2) Video clarity (6/10)
- Notes: MP4 present. Cannot parse content.
- Evidence: (video/CogniChip_TeamFLUX.mp4)

#### D3) Repo organization (0/5)
- Notes: `src/FluxV/` is empty. No README, no code.
- Evidence: *(absent)*

### E) Potential Real-World Impact (6/10)
- Notes: RV32I processor designs are widely used in embedded systems; a Cognichip-optimized RV32I could have real deployment value. Cannot assess without slides.
- Evidence: *(inferred from project title)*

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No evidence.
- Evidence: *(absent)*

## Final Recommendation
- Overall verdict: **Incomplete submission — no source code provided despite promising project topic.**
- Team FLUX presented an RV32I RISC-V processor project with slides and video, but submitted no source code. The project concept is technically credible but entirely unverifiable.

## Actionable Feedback (Most Important Improvements)
1. **Commit the RV32I RTL source**: Push Verilog/SystemVerilog files, testbenches, and a DEPS.yml to `src/FluxV/`.
2. **Include Cognichip simulation logs**: A passing `eda sim` run log would validate the implementation.
3. **Add a README**: Describe the ISA coverage, pipeline stages, and how to reproduce the simulation.

## Issues (If Any)
- PDF slides and MP4 video cannot be parsed in this environment.
- `src/FluxV/` directory is entirely empty — no code submitted.
