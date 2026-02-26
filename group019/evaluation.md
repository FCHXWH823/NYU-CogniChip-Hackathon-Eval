# CogniChip Hackathon Evaluation Receipt — group019

## Submission Overview
- Team folder: `group019`
- Slides: `slides/RISC-V CPU Design with AI.pdf`
- Video: *(not present — no video/ folder)*
- Code/Repo: `src/5-Stage-Pipeline-RISC-V/` — directory present but **empty** (no files committed)
- Evidence completeness: **Very Low** — only slides are present (unreadable); no video and no source code.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 3 | 30 |
| Cognichip Platform Usage | 4 | 20 |
| Innovation & Creativity | 7 | 15 |
| Clarity — Slides | 5 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 0 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **25** | **110** |

## Detailed Evaluation

### A) Technical Correctness (3/30)
- Strengths:
  - "5-Stage-Pipeline-RISC-V" is a clear and specific technical target.
  - Slide title "RISC-V CPU Design with AI" suggests AI-assisted design methodology.
- Weaknesses / Missing evidence:
  - `src/5-Stage-Pipeline-RISC-V/` is completely empty.
  - No RTL, testbench, hazard-handling documentation, or simulation log.
  - No video.
  - Cap rule applied: no simulation/verification evidence → capped at 12/30; scored 3/30.
- Key evidence:
  - (slides/RISC-V CPU Design with AI.pdf — present, unreadable)
  - *(no code evidence)*

### B) Effective Use of the Cognichip Platform (4/20)
- Strengths:
  - Slide title "RISC-V CPU Design with AI" implies AI-assisted design, potentially using Cognichip's AI co-designer.
- Weaknesses / Missing evidence:
  - No DEPS.yml, EDA logs, or simulation artifacts.
  - Cap rule applied; scored 4/20.
- Key evidence: *(inferred from slide title)*

### C) Innovation & Creativity (7/15)
- Strengths:
  - AI-assisted design of a 5-stage pipelined RISC-V CPU is an interesting methodology angle.
  - Using Cognichip's AI co-designer to generate/verify a pipeline could demonstrate novel workflow.
- Weaknesses:
  - A 5-stage RISC-V pipeline is standard academic work; the innovation depends entirely on how AI was used, which cannot be verified.
- Key evidence: *(inferred from slide title)*

### D) Clarity of Presentation (5/25)
#### D1) Slides clarity (5/10)
- Notes: PDF present. Title is descriptive but does not specify team members or ISA subset. Cannot assess internal quality.
- Evidence: (slides/RISC-V CPU Design with AI.pdf)

#### D2) Video clarity (0/10)
- Notes: No video/ folder present.
- Evidence: *(absent)*

#### D3) Repo organization (0/5)
- Notes: `src/5-Stage-Pipeline-RISC-V/` is empty.
- Evidence: *(absent)*

### E) Potential Real-World Impact (6/10)
- Notes: A RISC-V processor designed with AI assistance, if demonstrably faster to develop and verify, could have significant impact on chip design productivity. The methodology claim is more impactful than the artifact itself.
- Evidence: *(inferred from title)*

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No evidence.
- Evidence: *(absent)*

## Final Recommendation
- Overall verdict: **Slides-only submission with no video and no code — severely incomplete.**
- The project topic (AI-assisted 5-stage RISC-V pipeline) is technically sound, but the submission is missing both source code and video, making it impossible to evaluate any technical claims.

## Actionable Feedback (Most Important Improvements)
1. **Commit RTL source**: Push the 5-stage pipeline Verilog/SystemVerilog with hazard handling to `src/5-Stage-Pipeline-RISC-V/` and include a DEPS.yml.
2. **Add a video**: A demo showing simulation waveforms or a live run on Cognichip would add up to 10 points.
3. **Document AI methodology**: Explain specifically how AI (Cognichip or otherwise) was used — prompt examples, AI-generated code snippets, AI-vs-manual comparison — to differentiate from a standard RTL project.

## Issues (If Any)
- PDF slides cannot be parsed in this environment.
- No video/ folder present.
- `src/5-Stage-Pipeline-RISC-V/` directory is entirely empty.
