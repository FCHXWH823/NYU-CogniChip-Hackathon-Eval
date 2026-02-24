# CogniChip Hackathon Evaluation Receipt — FABB — Full-Auto Bug Buster

## Submission Overview
- Team folder: `group014`
- Slides: `slides/FABB - Cognichip (Bob Huang, Shahran Newaz).pdf`
- Video: `video/` (directory exists but appears empty)
- Code/Repo: `src/Bug-Buster/` — Python browser-based RTL debugging agent
- Evidence completeness: Moderate — complete Python application code with sample project files; no simulation run logs or waveform outputs demonstrating the tool catching real bugs.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 12 | 30 |
| Cognichip Platform Usage | 6 | 20 |
| Innovation & Creativity | 12 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 2 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 9 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **52** | **110** |

## Detailed Evaluation

### A) Technical Correctness (12/30)
- Strengths:
  - Complete, structured Python application: `fabb.py` launcher, `backend/server.py` HTTP API, `frontend/index.html` chat UI.
  - Multi-stage pipeline: indexer → RTL parser → VCD parser → log parser → bug classifier → LLM engine.
  - `sample_project/` includes three test artifacts: `counter.v` (with 3 injected bugs), `fsm_traffic.v`, `counter.vcd`, `counter_sim.log` — demonstrating the tool's use case.
  - LLM engine supports OpenAI and Anthropic backends for AI-powered explanations.
- Weaknesses / Missing evidence:
  - No demonstration log showing the tool actually detecting the 3 injected bugs in `counter.v`.
  - No test suite or automated verification of the FABB tool itself.
  - Cap applied: no concrete simulation/verification evidence of the tool's effectiveness in the repository.
- Key evidence:
  - (src/Bug-Buster/README.md — architecture and usage documentation)
  - (src/Bug-Buster/sample_project/ — demo RTL files with injected bugs)

### B) Effective Use of the Cognichip Platform (6/20)
- Strengths:
  - Submitted to Cognichip Hackathon; slides mention Cognichip.
- Weaknesses / Missing evidence:
  - README describes using OpenAI/Anthropic APIs, not specifically Cognichip.
  - FABB is an independent tool that can analyze any VCD/RTL; Cognichip is not integrated as the analysis backend.
  - No description of Cognichip-specific usage in building or testing FABB.
- Key evidence:
  - (src/Bug-Buster/README.md — mentions OpenAI/Anthropic, not Cognichip specifically)

### C) Innovation & Creativity (12/15)
- Strengths:
  - Browser-based chat interface for RTL debugging is an original and accessible UX design.
  - Multi-stage pipeline (static analysis + VCD parsing + log parsing + LLM) is a thoughtful architecture.
  - Natural language RTL debug queries ("find all reset logic bugs") is a compelling user interaction model.
  - Fuzzy file resolver for handling messy project structures shows practical engineering thinking.
- Weaknesses:
  - LLM-based RTL debugging is an active research/tooling area; FABB applies known techniques.
- Key evidence:
  - (src/Bug-Buster/README.md — example prompts table, architecture description)

### D) Clarity of Presentation (13/25)
#### D1) Slides clarity (7/10)
- Notes: PDF exists; cannot verify content directly, but reasonable base score awarded.
- Evidence: `slides/FABB - Cognichip (Bob Huang, Shahran Newaz).pdf`

#### D2) Video clarity (2/10)
- Notes: Video directory exists but appears empty; no video file found in the directory listing.
- Evidence: `video/` directory present but empty.

#### D3) Repo organization (4/5)
- Notes: Clean project structure with launcher, frontend/, backend/ (server + pipeline modules), sample_project/. README is well-written with quick-start, example prompts table, and project structure diagram. Minor: no automated tests for the FABB tool itself.
- Evidence: (src/Bug-Buster/ directory structure)

### E) Potential Real-World Impact (9/10)
- Notes: RTL debugging is a major productivity bottleneck in hardware design. A natural language interface to VCD/RTL analysis with LLM-powered explanations could significantly reduce debug time. The browser-based approach makes it accessible without EDA tool familiarity.
- Evidence: README — example prompts, sample buggy designs

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: The tool supports RTL targeting for any FPGA, but no specific FPGA targeting workflow was implemented as part of the submission.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Average submission**
- FABB is a creative and practical tool concept with a clean implementation architecture. The main weaknesses are that the tool's effectiveness is not demonstrated (no sample run showing bug detection), Cognichip is not integrated as a backend, and no video demo is available.

## Actionable Feedback (Most Important Improvements)
1. Run FABB on the sample_project counter.v and commit the output showing all 3 injected bugs being detected — this is the most important missing evidence.
2. Integrate Cognichip as the LLM backend option alongside OpenAI/Anthropic to deepen platform relevance.
3. Add a video demo showing the browser UI, a debug session, and the AI explanation output.

## Issues (If Any)
- Video directory is empty; if a video was intended, the file was not committed.
