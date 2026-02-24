# CogniChip Hackathon Evaluation Receipt — CogniChip Adaptive Power Management (Team PowerNap)

## Submission Overview
- Team folder: `group010`
- Slides: `slides/CogniChip_Adaptive_Power_Management (Team PowerNap).pdf`
- Video: None
- Code/Repo: None (no src folder)
- Evidence completeness: Very weak — slides-only submission with no source code, testbenches, or simulation evidence.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 5 | 30 |
| Cognichip Platform Usage | 5 | 20 |
| Innovation & Creativity | 7 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 0 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **30** | **110** |

## Detailed Evaluation

### A) Technical Correctness (5/30)
- Strengths:
  - Slides PDF exists and presumably describes the adaptive power management approach.
- Weaknesses / Missing evidence:
  - No source code of any kind in the repository.
  - No testbenches, simulation logs, waveforms, or synthesis results.
  - Cannot evaluate technical correctness without any implementation artifacts.
  - Cap applied: no concrete simulation/verification evidence present.
- Key evidence:
  - `slides/CogniChip_Adaptive_Power_Management (Team PowerNap).pdf` (PDF — content not readable)

### B) Effective Use of the Cognichip Platform (5/20)
- Strengths:
  - Project is named "CogniChip Adaptive Power Management," suggesting platform awareness.
- Weaknesses / Missing evidence:
  - No code, no prompt logs, no iteration history to demonstrate Cognichip usage.
  - Cannot assess platform usage without implementation artifacts.
- Key evidence:
  - None beyond the slide filename.

### C) Innovation & Creativity (7/15)
- Strengths:
  - Adaptive power management is a relevant and challenging hardware design problem.
  - "Team PowerNap" name suggests a focused power-reduction theme.
- Weaknesses:
  - Cannot assess the creative depth of the approach without slides content or implementation.
- Key evidence:
  - Slide filename only.

### D) Clarity of Presentation (7/25)
#### D1) Slides clarity (7/10)
- Notes: PDF exists; cannot verify content directly, but reasonable base score awarded for including a presentation.
- Evidence: `slides/CogniChip_Adaptive_Power_Management (Team PowerNap).pdf`

#### D2) Video clarity (0/10)
- Notes: No video submission.
- Evidence: No video folder present.

#### D3) Repo organization (0/5)
- Notes: No source code directory exists. The repository contains only a slides/ folder.
- Evidence: Repository directory listing — slides only.

### E) Potential Real-World Impact (6/10)
- Notes: Adaptive power management for chips is a high-impact area (mobile, IoT, data centers). Without implementation details, cannot assess the specific approach's merit.
- Evidence: Slide title.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No evidence of FPGA or Tiny Tapeout targeting.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Weak submission**
- This is a presentation-only submission with no implementation artifacts. While the topic (adaptive power management) is relevant, the complete absence of source code, testbenches, and simulation evidence makes it impossible to evaluate technical merit.

## Actionable Feedback (Most Important Improvements)
1. Include at minimum a simple RTL implementation of a power management unit (e.g., clock gating controller, dynamic voltage/frequency scaling FSM) with testbench.
2. Run simulations and commit logs/waveforms demonstrating the power management behavior.
3. Document the Cognichip workflow used to generate or verify the design.

## Issues (If Any)
- No src/ folder present in the repository; this violates minimum submission requirements for a technical hackathon.
