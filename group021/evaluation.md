# CogniChip Hackathon Evaluation Receipt — group021

## Submission Overview
- Team folder: `group021`
- Slides: `slides/Submission Note - QuantEdge Silicon.pdf`
- Video: `video/Hackathon_QuantSilicon.mp4`
- Code/Repo: `src/hackathon_QuantSilicon/` — directory present but **empty** (no files committed)
- Evidence completeness: **Very Low** — slides and video present (unreadable); source code directory is entirely empty.

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
  - "QuantEdge Silicon" suggests quantization-aware hardware design — a well-defined technical direction.
  - Both slides and video present.
- Weaknesses / Missing evidence:
  - `src/hackathon_QuantSilicon/` is completely empty.
  - No RTL, quantization scheme, testbench, or simulation artifact.
  - Note: The slide file is titled "Submission Note" rather than a full slide deck — suggests a brief summary document rather than a full presentation.
  - Cap rule applied: no simulation/verification evidence → capped at 12/30; scored 5/30.
- Key evidence:
  - (slides/Submission Note - QuantEdge Silicon.pdf — present, unreadable)
  - *(no code evidence)*

### B) Effective Use of the Cognichip Platform (5/20)
- Strengths:
  - "QuantSilicon" in src folder name and video filename suggests a chip design focus.
- Weaknesses / Missing evidence:
  - No DEPS.yml, EDA logs. "Submission Note" title raises concern about depth of work.
  - Cap rule applied; scored 5/20.
- Key evidence: *(none specific)*

### C) Innovation & Creativity (8/15)
- Strengths:
  - "QuantEdge" combining quantization with edge deployment is a relevant and creative framing.
  - Quantization-aware hardware (e.g., INT4/INT8 MAC units, mixed-precision datapaths) is an active research area.
- Weaknesses:
  - "Submission Note" slide title suggests this may be a brief summary rather than full design presentation, reducing confidence in depth.
- Key evidence: *(inferred from project name)*

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (6/10)
- Notes: PDF present. Title "Submission Note" is unusual for a presentation — may indicate a brief summary doc. Cannot assess internal quality.
- Evidence: (slides/Submission Note - QuantEdge Silicon.pdf)

#### D2) Video clarity (6/10)
- Notes: MP4 present with "QuantSilicon" in filename. Cannot parse content.
- Evidence: (video/Hackathon_QuantSilicon.mp4)

#### D3) Repo organization (0/5)
- Notes: `src/hackathon_QuantSilicon/` is empty.
- Evidence: *(absent)*

### E) Potential Real-World Impact (6/10)
- Notes: Quantization-aware silicon design for edge AI is commercially relevant. Without slides content, cannot confirm whether the scope is narrow or broad.
- Evidence: *(inferred from project name)*

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: "Silicon" in name might imply tapeout intent but no evidence provided.
- Evidence: *(absent)*

## Final Recommendation
- Overall verdict: **Incomplete submission — empty source code and potentially brief slides.**
- The QuantEdge Silicon project name suggests a quantization-focused chip design, but no code or verifiable artifacts were submitted. The "Submission Note" slide title raises concern about presentation completeness.

## Actionable Feedback (Most Important Improvements)
1. **Submit full implementation**: Push quantization-aware RTL or simulation code with Cognichip DEPS.yml.
2. **Replace "Submission Note" with a proper slide deck**: Include architecture diagrams, quantization scheme, results, and comparison baselines.
3. **If targeting tapeout, provide evidence**: Area estimates, timing analysis, or Tiny Tapeout integration plan would unlock the 10-point bonus.

## Issues (If Any)
- PDF slides and MP4 video cannot be parsed in this environment.
- Slide filename "Submission Note" suggests a brief note rather than full presentation slides.
- `src/hackathon_QuantSilicon/` directory is entirely empty.
