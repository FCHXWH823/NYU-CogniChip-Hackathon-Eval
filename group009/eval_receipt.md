# CogniChip Hackathon Evaluation Receipt — group009

## Submission Overview
- Team folder: `group009`
- Slides: `slides/Cognichip Hackathon Project (Leo Wang and Ben Feng).pdf`
- Video: None
- Code/Repo: `src/OoO-Design-Project/` (9 files; basic in-order pipeline modules, README showing Phase 1 in-progress)
- Evidence completeness: Weak — slides claim 14 tests passed but no simulation logs or EDA results are present in the repository; OoO phase not started; project is incomplete.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 10 | 30 |
| Cognichip Platform Usage | 10 | 20 |
| Innovation & Creativity | 9 | 15 |
| Clarity — Slides | 6 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 2 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **43** | **110** |

## Detailed Evaluation

### A) Technical Correctness (10/30)
- Applying cap: no concrete simulation/verification evidence in repository.
- Strengths:
  - Slides claim "14 tests were conducted to verify addition, subtraction, multiplication, and other operations, and all 14 tests were successfully passed."
  - Some RTL modules committed: ALU (`alu.sv`), control unit (`control_unit.sv`), register file (`register_file.sv`), program counter (`pc.sv`), immediate generator (`immediate_generator.sv`).
- Weaknesses / Missing evidence:
  - No simulation logs, no EDA `eda_results.json`, no waveforms in repository.
  - README clearly states Phase 2 (Out of Order) is "Not started" and Phase 3 (FPGA) is "Not started".
  - Multiple components listed as "In Progress" in README tracker.
  - No testbench files in the repository — 14-test claim is unverifiable.
  - Core_single_cycle is present but no testbench submitted.
- Key evidence:
  - (slides/Cognichip Hackathon Project (Leo Wang and Ben Feng).pdf — "14 tests were successfully passed")
  - (src/OoO-Design-Project/README.md — Phase 1 "In Progress", Phase 2 "Not started")
  - (src/OoO-Design-Project/ — 8 RTL files, no testbenches or logs)

### B) Effective Use of the Cognichip Platform (10/20)
- Applying cap: usage is described generically without specific workflow steps.
- Strengths:
  - Cognichip used for RTL generation, testbench generation, and design iteration per slides.
  - Acknowledges AI limitations: "AI may not be able to fully understand the request."
- Weaknesses / Missing evidence:
  - No EDA results confirming Cognichip simulation was used.
  - No specific Cognichip features, flow steps, or prompts documented.
- Key evidence:
  - (slides/Cognichip Hackathon Project (Leo Wang and Ben Feng).pdf — "AI will be used to generate and refine RTL modules")

### C) Innovation & Creativity (9/15)
- Strengths:
  - OoO processor design is architecturally ambitious for a hackathon timeframe.
  - AI as a "design and verification partner" for CPU development is a valid research direction.
  - Plans for reference checking mechanism comparing register states is a good verification approach.
- Weaknesses:
  - OoO phase was never started — ambitious plan not executed.
  - What was submitted is a standard in-order pipeline at Phase 1.
- Key evidence:
  - (slides/Cognichip Hackathon Project (Leo Wang and Ben Feng).pdf — "Out-of-Order execution model")

### D) Clarity of Presentation (8/25)
#### D1) Slides clarity (6/10)
- Notes: Basic slides covering the problem, architecture sketch, claimed simulation results, and challenges. Lacks detail on architecture, no waveforms, no diagrams. The title is "RISC-V 32 Bit Processor" but slides discuss OoO design — slight inconsistency.
- Evidence: (slides/Cognichip Hackathon Project (Leo Wang and Ben Feng).pdf)

#### D2) Video clarity (0/10)
- Notes: No video submitted.
- Evidence: No video directory.

#### D3) Repo organization (2/5)
- Notes: Very small repo (9 files), README shows project is incomplete. No testbenches, no simulation results. README has a nice progress tracker table but most items are "In Progress."
- Evidence: (src/OoO-Design-Project/README.md — incomplete status)

### E) Potential Real-World Impact (6/10)
- Notes: OoO processors are important for high-performance computing. AI-assisted CPU design at this level would be impactful if completed, but the incomplete state limits assessment.
- Evidence: (slides/Cognichip Hackathon Project (Leo Wang and Ben Feng).pdf — IPC improvement motivation)

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: Phase 3 (FPGA testing) listed as "Not started" in README.
- Evidence: (src/OoO-Design-Project/README.md — "Phase 3: Testing and implementing on FPGA (Not started)")

## Final Recommendation
- Overall verdict: **Below Average**
- Ambitious project concept (OoO processor with AI assistance) but significantly incomplete at submission. The core OoO feature was never started, simulation evidence is missing, and the repository contains only basic RTL modules without testbenches. The 14-test claim in slides cannot be verified.

## Actionable Feedback (Most Important Improvements)
1. Commit testbench files and simulation logs to substantiate the claimed 14 test passes.
2. Start with a solid in-order pipeline with complete verification before attempting OoO features.
3. Scope the project more conservatively to what can be fully completed and verified.

## Issues (If Any)
- No video submitted.
- No simulation evidence (no logs, no EDA results) despite claim of 14 tests passed.
- Project is incomplete — OoO phase not started per README.
