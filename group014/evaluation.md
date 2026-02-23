# CogniChip Hackathon Evaluation Receipt — group014

## Submission Overview
- Team folder: `group014`
- Slides: `slides/FABB - Cognichip (Bob Huang, Shahran Newaz).pdf`
- Video: `video/CogniChip Demo (Shahran Newaz & Bob Huang).mp4`
- Code/Repo: `src/Bug-Buster/` — directory present but **empty** (no files committed)
- Evidence completeness: **Very Low** — slides and video are present but cannot be parsed in this environment; the source code directory is entirely empty, providing no verifiable technical evidence.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 5 | 30 |
| Cognichip Platform Usage | 5 | 20 |
| Innovation & Creativity | 7 | 15 |
| Clarity — Slides | 6 | 10 |
| Clarity — Video | 6 | 10 |
| Clarity — Repo Organization | 0 | 5 |
| Potential Real-World Impact | 5 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **34** | **110** |

## Detailed Evaluation

### A) Technical Correctness (5/30)
- Strengths:
  - Slide title "FABB - Cognichip" and demo video present suggests a demo was prepared.
- Weaknesses / Missing evidence:
  - `src/Bug-Buster/` directory is completely empty — no RTL, testbench, README, or simulation output.
  - No waveform, synthesis report, simulation log, or any executable artifact.
  - Cannot verify any technical claim from the slides.
  - Cap rule applied: no simulation/verification evidence → capped at 12/30; further reduced to 5/30 due to empty src.
- Key evidence:
  - (slides/FABB - Cognichip (Bob Huang, Shahran Newaz).pdf — present, unreadable)
  - *(no code evidence)*

### B) Effective Use of the Cognichip Platform (5/20)
- Strengths:
  - Video titled "CogniChip Demo" suggests platform was demonstrated.
- Weaknesses / Missing evidence:
  - No DEPS.yml, EDA logs, or eda_results.json.
  - Cap rule applied: without specific steps verifiable from code, capped at 8/20; scored 5/20 due to empty src.
- Key evidence:
  - (video/CogniChip Demo (Shahran Newaz & Bob Huang).mp4 — title implies Cognichip was used)

### C) Innovation & Creativity (7/15)
- Strengths:
  - "Bug-Buster" name implies a debugging-focused design tool, which could be creative.
- Weaknesses:
  - Without code or readable slides/video, novelty cannot be assessed.
- Key evidence: *(inferred from project name only)*

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (6/10)
- Notes: PDF present with descriptive team and project title. Cannot assess internal content.
- Evidence: (slides/FABB - Cognichip (Bob Huang, Shahran Newaz).pdf)

#### D2) Video clarity (6/10)
- Notes: MP4 present with "CogniChip Demo" in filename. Cannot parse content.
- Evidence: (video/CogniChip Demo (Shahran Newaz & Bob Huang).mp4)

#### D3) Repo organization (0/5)
- Notes: `src/Bug-Buster/` is empty. No README, no code, no scripts.
- Evidence: *(absent)*

### E) Potential Real-World Impact (5/10)
- Notes: Cannot assess without slides or code content. Scored at midpoint for plausibility.
- Evidence: *(inferred from team name)*

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No evidence of any kind.
- Evidence: *(absent)*

## Final Recommendation
- Overall verdict: **Incomplete submission — video and slides present but source code is missing.**
- The team provided slides and a demo video but submitted an empty code repository. Without any source code, testbenches, simulation logs, or README, no technical claims can be verified.

## Actionable Feedback (Most Important Improvements)
1. **Commit source code**: Push the Bug-Buster implementation (RTL, Python, or otherwise) to `src/Bug-Buster/`.
2. **Add a README**: Explain what was built, how to run it, and what results were obtained.
3. **Include simulation logs or screenshots**: Any waveform, output log, or screenshot from a Cognichip EDA run would provide verifiable evidence.

## Issues (If Any)
- PDF slides and MP4 video cannot be parsed in this environment.
- `src/Bug-Buster/` directory is entirely empty — no code submitted.
