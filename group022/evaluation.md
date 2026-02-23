# CogniChip Hackathon Evaluation Receipt — group022

## Submission Overview
- Team folder: `group022`
- Slides: `slides/TeenyTinyTrustyCore (3TC).pdf`
- Video: `video/TeenyTinyTrustyCore (3TC).mp4`
- Code/Repo: `src/teenytinytrustycore/` — directory exists but is empty; no files committed.
- Evidence completeness: Minimal — slides and video only; no code, no simulation results. The name "TeenyTinyTrustyCore" strongly implies Tiny Tapeout targeting, but no implementation evidence exists.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 0 | 30 |
| Cognichip Platform Usage | 0 | 20 |
| Innovation & Creativity | 8 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 7 | 10 |
| Clarity — Repo Organization | 0 | 5 |
| Potential Real-World Impact | 7 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **29** | **110** |

## Detailed Evaluation

### A) Technical Correctness (0/30)
- Strengths:
  - None — no code or simulation evidence submitted.
- Weaknesses / Missing evidence:
  - `src/teenytinytrustycore/` is an empty directory; no RTL, no testbench, no EDA results.
- Key evidence:
  - None.

### B) Effective Use of the Cognichip Platform (0/20)
- Strengths:
  - None.
- Weaknesses / Missing evidence:
  - No DEPS.yml, no EDA results, no ACI interaction logs.
- Key evidence:
  - None.

### C) Innovation & Creativity (8/15)
- Strengths:
  - "TeenyTinyTrustyCore" implies a minimal, security-focused processor targeting Tiny Tapeout — a creative framing combining minimal-area design with trust/security properties.
  - Security-hardened small cores are commercially relevant for IoT and embedded security.
- Weaknesses:
  - Concept only; no implementation to evaluate.
- Key evidence:
  - (slides/TeenyTinyTrustyCore (3TC).pdf) — concept described

### D) Clarity of Presentation (14/25)
#### D1) Slides clarity (7/10)
- Notes: PDF title and project naming are polished and clear. The "3TC" branding suggests a well-thought-out presentation.
- Evidence: (slides/TeenyTinyTrustyCore (3TC).pdf)

#### D2) Video clarity (7/10)
- Notes: Video present with a matching project title — presentation-quality naming.
- Evidence: (video/TeenyTinyTrustyCore (3TC).mp4)

#### D3) Repo Organization (0/5)
- Notes: `src/teenytinytrustycore/` is an empty directory.
- Evidence: None.

### E) Potential Real-World Impact (7/10)
- Notes: A security-focused minimal processor for tapeout has strong real-world relevance for embedded security, hardware roots of trust, and IoT applications.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: The project name strongly implies Tiny Tapeout intent, but no RTL, constraints, area estimates, or tapeout deliverables were committed. Bonus requires evidence of steps taken; none exists.
- Evidence: None confirming tapeout steps.

## Final Recommendation
- Overall verdict: **Poor** (29/110)
- The 3TC concept is well-branded and the Tiny Tapeout intent is plausible, but no implementation was submitted. The bonus cannot be awarded without evidence of tapeout steps.

## Actionable Feedback (Most Important Improvements)
1. Submit the minimal core RTL with a testbench; run `eda sim` on Cognichip and commit EDA results.
2. Provide Tiny Tapeout flow files (area estimates, sky130 synthesis results, `info.yaml`) to earn the tapeout bonus.
3. Document the specific security properties/mechanisms implemented in the core.

## Issues (If Any)
- `src/teenytinytrustycore/` is an empty directory; no code submitted.
- Tiny Tapeout claim cannot be awarded without implementation evidence.
