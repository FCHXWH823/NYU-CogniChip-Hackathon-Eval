# CogniChip Hackathon Evaluation Receipt — group009

## Submission Overview
- Team folder: `group009`
- Slides: `slides/Cognichip Hackathon Project (Leo Wang and Ben Feng).pdf`
- Video: `video/Cognichip Demo (Leo Wang & Ben Feng).mp4`
- Code/Repo: `src/OoO-Design-Project/` — `Top.v`, `core_single_cycle.sv`, `pc.sv`, `alu.sv`, `control_unit.sv`, `register_file.sv`, `immediate_generator.sv`, `load_store_align.sv`, README; no EDA results
- Evidence completeness: Weak — in-order baseline code present, but no simulation results; out-of-order features not implemented.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 6 | 30 |
| Cognichip Platform Usage | 4 | 20 |
| Innovation & Creativity | 8 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 6 | 10 |
| Clarity — Repo Organization | 3 | 5 |
| Potential Real-World Impact | 5 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **39** | **110** |

## Detailed Evaluation

### A) Technical Correctness (6/30)
- Strengths:
  - Seven RTL modules committed covering the basic pipeline stages (PC, register file, ALU, control unit, load/store, top-level).
  - Code files use SystemVerilog (`*.sv`) and are syntactically complete.
- Weaknesses / Missing evidence:
  - Cap rule applied: no simulation logs, EDA JSON results, or waveform files; correctness is unverifiable.
  - README explicitly states the project is at "Phase 1 (In-Order)" with OoO phases "Not started."
  - No testbench file found in the submitted source.
  - No `DEPS.yml` indicating Cognichip EDA project setup.
- Key evidence:
  - (src/OoO-Design-Project/README.md) — roadmap showing Phase 1 incomplete, Phases 2–3 not started
  - (src/OoO-Design-Project/core_single_cycle.sv) — single-cycle core RTL

### B) Effective Use of the Cognichip Platform (4/20)
- Strengths:
  - Slides and README exist; Cognichip is mentioned as the hackathon context.
- Weaknesses / Missing evidence:
  - No `DEPS.yml`, no EDA JSON results, no ACI interaction logs; no evidence the Cognichip platform was used for simulation or design assistance.
- Key evidence:
  - None confirmed beyond naming convention.

### C) Innovation & Creativity (8/15)
- Strengths:
  - Out-of-order execution is a genuinely ambitious and non-trivial hardware goal for a hackathon.
  - Roadmap clearly lays out a three-phase development plan (in-order baseline → OoO → FPGA).
- Weaknesses:
  - Only the in-order baseline exists, and that is incomplete per README.
  - Core concepts (Tomasulo algorithm, ROB, etc.) are described in slides/README but not implemented.

### D) Clarity of Presentation (16/25)
#### D1) Slides clarity (7/10)
- Notes: PDF covers OoO motivation, architecture plan, and ISA design.
- Evidence: (slides/Cognichip Hackathon Project (Leo Wang and Ben Feng).pdf)

#### D2) Video clarity (6/10)
- Notes: Video present. Given the incomplete implementation, the demo likely covers architecture concepts rather than a working simulation.
- Evidence: (video/Cognichip Demo (Leo Wang & Ben Feng).mp4)

#### D3) Repo Organization (3/5)
- Notes: README is well-structured with a roadmap table and progress tracker. No `DEPS.yml`, no simulation results directory, no testbench committed.
- Evidence: (src/OoO-Design-Project/README.md)

### E) Potential Real-World Impact (5/10)
- Notes: OoO execution is a significant performance optimisation for high-IPC processors; the concept is sound and commercially relevant. Impact is heavily discounted because the design is unimplemented.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: Phase 3 (FPGA) is in the roadmap but "Not started."
- Evidence: (src/OoO-Design-Project/README.md) — Phase 3 listed as not started.

## Final Recommendation
- Overall verdict: **Below Average** (39/110)
- The OoO concept is ambitious and the roadmap is clear, but the submission effectively shows only incomplete in-order baseline RTL without any simulation evidence or Cognichip platform usage. The gap between stated goals and delivered artifacts is large.

## Actionable Feedback (Most Important Improvements)
1. Complete Phase 1 (in-order baseline): add a testbench, run `eda sim` on Cognichip, and commit passing results.
2. Add `DEPS.yml` and at least one EDA simulation run to demonstrate platform engagement.
3. Even a partial OoO implementation (e.g., register renaming or reservation stations) would significantly improve the innovation score.

## Issues (If Any)
- No testbench committed; no simulation evidence of any kind.
- No DEPS.yml; Cognichip platform usage unconfirmed.
- OoO phases (2 and 3) explicitly marked "Not started" in README.
