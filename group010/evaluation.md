# CogniChip Hackathon Evaluation Receipt — group010

## Submission Overview
- Team folder: `group010`
- Slides: `slides/CogniChip_Adaptive_Power_Management (Team PowerNap).pdf`
- Video: `video/Team-PowerNap- AI assisted power management system.mp4`
- Code/Repo: No `src/` directory submitted.
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
  - None — no RTL or simulation evidence submitted.
- Weaknesses / Missing evidence:
  - Cap rule applied and floor applied: no `src/` directory, no code, no simulation logs, no EDA results, no waveforms.
  - Concept cannot be evaluated for correctness without implementation.
- Key evidence:
  - None.

### B) Effective Use of the Cognichip Platform (0/20)
- Strengths:
  - None — no evidence of platform use.
- Weaknesses / Missing evidence:
  - No `src/`, no DEPS.yml, no EDA results; Cognichip platform was not demonstrably used.
- Key evidence:
  - None.

### C) Innovation & Creativity (6/15)
- Strengths:
  - Adaptive power management with AI assistance for dynamic workload-aware gating is a relevant concept.
  - "PowerNap" system name suggests a domain-specific, creative framing.
- Weaknesses:
  - Concept is fully described only in slides; no implementation artifact exists to judge novelty of the technical approach.
- Key evidence:
  - (slides/CogniChip_Adaptive_Power_Management (Team PowerNap).pdf) — concept description

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (6/10)
- Notes: PDF slides are the only technical artifact. Cannot verify depth or quality of content without parsing; scored conservatively based on presence and slide filename.
- Evidence: (slides/CogniChip_Adaptive_Power_Management (Team PowerNap).pdf)

#### D2) Video clarity (6/10)
- Notes: Video present; covers the concept presentation.
- Evidence: (video/Team-PowerNap- AI assisted power management system.mp4)

#### D3) Repo Organization (0/5)
- Notes: No `src/` directory submitted.
- Evidence: None.

### E) Potential Real-World Impact (5/10)
- Notes: AI-driven adaptive power management is a genuine industry need; however, without a hardware implementation, real-world impact cannot be substantiated.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No evidence.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Very Poor** (23/110)
- Only slides and video were submitted; the submission is concept-only with no code or simulation evidence. Technical Correctness, Cognichip Platform Usage, and Repo Organization all score zero.

## Actionable Feedback (Most Important Improvements)
1. Implement the power management module in RTL (even a simple FSM-based controller) and run it through Cognichip EDA.
2. Add a `src/` directory with at minimum a `DEPS.yml` and skeleton RTL file to show project setup.
3. Demonstrate the AI-assistance aspect with actual Cognichip ACI interaction logs or EDA simulation results.

## Issues (If Any)
- No `src/` directory; no code submitted.
- Technical Correctness and Cognichip Platform Usage both scored 0 due to complete absence of implementation evidence.
