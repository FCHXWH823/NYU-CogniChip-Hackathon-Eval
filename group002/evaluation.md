# CogniChip Hackathon Evaluation Receipt — group002

## Submission Overview
- Team folder: `group002`
- Slides: `slides/AI-Driven Layout-Aware RTL Optimization Loop (Abhishek, Saishruti, Harshal, Bhanuja).pdf`
- Video: `video/AI-Driven Layout-Aware RTL Optimization Loop (Abhishek, Saishruti, Harshal, Bhanuja).mp4`
- Code/Repo: *(no `src/` folder present)*
- Evidence completeness: **Low** — slides and video are present but cannot be parsed in this environment; no source code, testbenches, or simulation evidence is provided.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 5 | 30 |
| Cognichip Platform Usage | 6 | 20 |
| Innovation & Creativity | 9 | 15 |
| Clarity — Slides | 6 | 10 |
| Clarity — Video | 6 | 10 |
| Clarity — Repo Organization | 0 | 5 |
| Potential Real-World Impact | 7 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **39** | **110** |

## Detailed Evaluation

### A) Technical Correctness (5/30)
- Strengths:
  - Slides title implies an AI-driven loop that iterates over RTL, performs layout estimation, and feeds back into RTL optimization — an ambitious and technically credible concept.
  - Both slides and video are present, suggesting a complete story was prepared.
- Weaknesses / Missing evidence:
  - **No source code, testbenches, or simulation logs** — the `src/` folder is entirely absent.
  - No waveform, synthesis report, timing closure result, or any executable artifact.
  - Cannot verify any technical claim.
  - Cap rule applied: no simulation/verification evidence → **capped at 12/30**; further reduced to 5/30 due to complete absence of any code artifact.
- Key evidence:
  - (slides/AI-Driven Layout-Aware RTL Optimization Loop (Abhishek, Saishruti, Harshal, Bhanuja).pdf — present, unreadable)
  - *(no code evidence)*

### B) Effective Use of the Cognichip Platform (6/20)
- Strengths:
  - Slide title explicitly references an "optimization loop" — consistent with iterative Cognichip EDA usage.
  - Video demo present — may contain Cognichip platform screen recordings.
- Weaknesses / Missing evidence:
  - No DEPS.yml, no EDA log files, no eda_results.json.
  - Cannot confirm specific Cognichip features were used.
  - Cap rule applied: without specific step-by-step Cognichip feature description verifiable from code, **capped at 8/20**; scored 6/20 due to complete absence of code artifacts.
- Key evidence:
  - (slides/AI-Driven Layout-Aware RTL Optimization Loop ... .pdf — title suggests Cognichip use)

### C) Innovation & Creativity (9/15)
- Strengths:
  - A layout-aware RTL optimization loop with AI feedback is a genuinely novel idea — closing the loop between physical design metrics and RTL-level decisions is an unsolved industrial problem.
  - Combination of AI + layout awareness + RTL in an automated loop is creative and non-trivial.
- Weaknesses:
  - Without code, it is impossible to verify that any part of the loop was implemented vs. described conceptually.
- Key evidence:
  - (slides/AI-Driven Layout-Aware RTL Optimization Loop ... .pdf — concept inferred from title)

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (6/10)
- Notes: PDF is present. Full project title suggests the slides are descriptive. Cannot assess internal content; score reflects existence and informative title.
- Evidence: (slides/AI-Driven Layout-Aware RTL Optimization Loop (Abhishek, Saishruti, Harshal, Bhanuja).pdf)

#### D2) Video clarity (6/10)
- Notes: MP4 present with matching descriptive filename. Cannot parse; scored based on presence.
- Evidence: (video/AI-Driven Layout-Aware RTL Optimization Loop (Abhishek, Saishruti, Harshal, Bhanuja).mp4)

#### D3) Repo organization (0/5)
- Notes: No `src/` directory — no code, no README, no scripts. Lowest possible score.
- Evidence: *(absent)*

### E) Potential Real-World Impact (7/10)
- Notes: Layout-aware RTL optimization is highly relevant — closing the gap between front-end and back-end design in an AI loop would materially reduce tape-out iterations and improve PPA. Highly applicable to industrial chip design.
- Evidence: (slides/... — project title)

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No code, no constraints, no synthesis results. Cannot award bonus.
- Evidence: *(absent)*

## Final Recommendation
- Overall verdict: **Interesting concept, zero verifiable implementation — presentation-only submission.**
- The project concept (AI-driven layout-aware RTL optimization loop) is compelling and relevant, but the complete absence of source code, testbenches, or simulation artifacts means nothing can be verified. This submission reads as a proposal or concept deck rather than a working prototype.

## Actionable Feedback (Most Important Improvements)
1. **Submit source code**: Even a minimal Python script or RTL snippet demonstrating one iteration of the loop would dramatically improve the score. Include a DEPS.yml for Cognichip EDA.
2. **Provide simulation or synthesis logs**: Attach at least one `eda_results.json`, waveform, or synthesis report showing the loop was executed end-to-end.
3. **Add a README**: Describe the loop architecture, tool dependencies, how to reproduce results, and what was accomplished vs. planned.

## Issues (If Any)
- PDF slides and MP4 video cannot be parsed in this environment; all content scoring is based on presence and filename only.
- `src/` folder is entirely absent — no code submitted.
