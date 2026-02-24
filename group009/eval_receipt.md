# CogniChip Hackathon Evaluation Receipt — Out-of-Order (OoO) Design Project

## Submission Overview
- Team folder: `group009`
- Slides: `slides/Cognichip Hackathon Project (Leo Wang and Ben Feng).pdf`
- Video: None
- Code/Repo: `src/OoO-Design-Project/`
- Evidence completeness: Very weak — README is a roadmap/status document showing the project is at Phase 1 with all components "In Progress"; no RTL, testbenches, or simulation results found.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 5 | 30 |
| Cognichip Platform Usage | 4 | 20 |
| Innovation & Creativity | 9 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 2 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **33** | **110** |

## Detailed Evaluation

### A) Technical Correctness (5/30)
- Strengths:
  - Roadmap shows clear understanding of OoO processor components (Fetch, Decode, Execute, Memory, Writeback, Hazard Unit).
  - Phase 0 (Architecture Design & ISA Definition) marked as complete.
- Weaknesses / Missing evidence:
  - All five pipeline stage components are marked "🏗️ In Progress" — no component is complete.
  - No RTL source files found in the repository.
  - No testbenches, simulation logs, or waveforms.
  - Phase 2 (OoO Pipeline) and Phase 3 (FPGA Testing) are explicitly marked "Not started."
  - No evidence of any functional implementation.
- Key evidence:
  - (src/OoO-Design-Project/README.md — progress tracker table)

### B) Effective Use of the Cognichip Platform (4/20)
- Strengths:
  - Submitted to Cognichip Hackathon.
- Weaknesses / Missing evidence:
  - No mention of Cognichip in the README.
  - No description of AI-assisted design workflow.
- Key evidence:
  - (src/OoO-Design-Project/README.md — no Cognichip mention found)

### C) Innovation & Creativity (9/15)
- Strengths:
  - Out-of-order execution is architecturally ambitious and technically challenging.
  - Clear progression from in-order baseline to OoO with planned features (Tomasulo algorithm implied by planned "dynamic scheduling").
- Weaknesses:
  - Project is incomplete; the innovative parts (OoO scheduling, reorder buffer) have not been started.
  - Design choices not yet explained beyond the roadmap.
- Key evidence:
  - (src/OoO-Design-Project/README.md — "Planned Features" section)

### D) Clarity of Presentation (9/25)
#### D1) Slides clarity (7/10)
- Notes: PDF exists; cannot verify content directly, but reasonable base score awarded.
- Evidence: `slides/Cognichip Hackathon Project (Leo Wang and Ben Feng).pdf`

#### D2) Video clarity (0/10)
- Notes: No video submission.
- Evidence: No video folder present.

#### D3) Repo organization (2/5)
- Notes: Only a README.md in the src directory; no source code, no directory structure, no build system. The README itself is a clean status document but represents the entirety of the submission.
- Evidence: (src/OoO-Design-Project/README.md)

### E) Potential Real-World Impact (6/10)
- Notes: Out-of-order processors are fundamental to modern high-performance computing. If completed, an AI-assisted OoO design would be a significant contribution. As submitted, impact cannot be assessed beyond the concept.
- Evidence: README — OoO architecture roadmap

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: Phase 3 (FPGA) planned but not started.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Weak submission**
- The project is significantly incomplete — no RTL, no testbenches, and no simulation results. The README describes an ambitious architecture that was not implemented within the hackathon timeframe.

## Actionable Feedback (Most Important Improvements)
1. Implement at least the in-order baseline (Phase 1) with a working testbench and simulation results before submitting.
2. Use Cognichip to accelerate RTL generation for at least the basic pipeline stages and document the AI-assisted workflow.
3. Even partial progress (e.g., a working fetch stage or ALU with passing tests) would significantly strengthen the submission.

## Issues (If Any)
- Repository contains essentially no implementation artifacts; this appears to be a project in planning/early stages.
