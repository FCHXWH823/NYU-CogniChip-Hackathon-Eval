# CogniChip Hackathon Evaluation Receipt — group014

## Submission Overview
- Team folder: `group014`
- Slides: `slides/FABB - Cognichip (Bob Huang, Shahran Newaz).pdf`
- Video: `video/` (folder exists but is empty — no video file)
- Code/Repo: `src/Bug-Buster/` (25 files; Python web-based AI RTL debugger — backend server, pipeline modules, sample project with sim log)
- Evidence completeness: Moderate — slides describe the tool architecture, README is comprehensive; sample simulation log demonstrates the use case; no video; tool is an AI-powered debugging assistant rather than an RTL design itself.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 17 | 30 |
| Cognichip Platform Usage | 12 | 20 |
| Innovation & Creativity | 11 | 15 |
| Clarity — Slides | 8 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 8 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **60** | **110** |

## Detailed Evaluation

### A) Technical Correctness (17/30)
- Strengths:
  - Working Python backend with server (`fabb.py`, `server.py`), pipeline modules (`vcd_parser.py`, `log_parser.py`, `rtl_parser.py`, `bug_classifier.py`, `llm_engine.py`), and file indexer.
  - Sample project includes `counter_sim.log` demonstrating the tool's target input.
  - README describes a functional tool with clear usage instructions and example prompts.
  - All backend functionality uses Python stdlib only — no external dependencies needed for core function.
- Weaknesses / Missing evidence:
  - No RTL hardware design tested — FABB is a tooling project, not an RTL design.
  - No simulation logs showing FABB successfully finding bugs in a design.
  - Correctness of bug detection algorithm cannot be verified from static code review alone.
  - Optional LLM layer requires external API key (OpenAI/Anthropic) — AI-powered explanations not testable without keys.
  - Slides reference "Simulation Results" but the tool's effectiveness is not quantified.
- Key evidence:
  - (src/Bug-Buster/fabb.py — main entry point)
  - (src/Bug-Buster/backend/pipeline/ — parser and bug classifier modules)
  - (src/Bug-Buster/sample_project/counter_sim.log — sample simulation log)

### B) Effective Use of the Cognichip Platform (12/20)
- Strengths:
  - CogniChip used to develop the foundational framework.
  - Slides describe iterative use: "broke down complex instructions into smaller, manageable inputs" due to large-prompt limitations.
  - FABB is designed to work with Cognichip's simulation artifacts (logs, VCDs).
- Weaknesses / Missing evidence:
  - Cognichip's primary role was development assistance, not as an integrated component of the final tool.
  - No Cognichip EDA simulation results — the tool was built with Cognichip help but doesn't produce Cognichip outputs.
  - Specific Cognichip features used beyond general LLM assistance not detailed.
- Key evidence:
  - (slides/FABB - Cognichip (Bob Huang, Shahran Newaz).pdf — "We utilized CogniChip to develop the foundational framework")

### C) Innovation & Creativity (11/15)
- Strengths:
  - AI-powered RTL debugging agent accessible via web browser is a novel and practical tool.
  - Local Python stdlib backend with no external dependencies is an excellent design decision for accessibility.
  - Multi-artifact analysis (RTL + VCD + logs simultaneously) in a chat interface is creative.
  - "Chat with a verification engineer" UX paradigm is an interesting framing.
- Weaknesses:
  - LLM-based RTL debugging is an active research and commercial area (Synopsys AI, Cadence AI).
  - Without the LLM API key, the tool degrades to a simpler pattern-matching approach.
- Key evidence:
  - (src/Bug-Buster/README.md — "Run locally: Python stdlib backend + static HTML chat UI")
  - (slides/FABB - Cognichip (Bob Huang, Shahran Newaz).pdf — "FABB in 1 Slide")

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (8/10)
- Notes: Well-structured presentation: problem domain, project overview, design methodology, architecture, simulation results, challenges, future work. Clear table of contents. FABB-in-1-slide is an effective overview.
- Evidence: (slides/FABB - Cognichip (Bob Huang, Shahran Newaz).pdf)

#### D2) Video clarity (0/10)
- Notes: Video folder exists but is empty — no video file submitted.
- Evidence: (video/ — empty directory)

#### D3) Repo organization (4/5)
- Notes: Well-organized Python project: separate backend/pipeline modules, file_index module, sample project. Comprehensive README with setup, usage, example prompts, and project structure.
- Evidence: (src/Bug-Buster/README.md — comprehensive documentation)

### E) Potential Real-World Impact (8/10)
- Notes: RTL debugging is time-consuming and expensive. A local, no-dependency debugger with optional LLM support could meaningfully reduce iteration time for small teams and students. The privacy-preserving local design is a practical advantage.
- Evidence: (slides/FABB - Cognichip (Bob Huang, Shahran Newaz).pdf — "RTL debugging is still painfully manual")

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: Not applicable — FABB is a debugging tool, not a hardware design.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Above Average**
- A practical and well-implemented AI-powered RTL debugging tool. The multi-artifact analysis approach (RTL + VCD + logs) is genuinely useful, and the zero-dependency design is admirable. Scoring is limited by the absence of demonstrated bug-finding effectiveness (no demo log showing a successful debug session) and empty video folder.

## Actionable Feedback (Most Important Improvements)
1. Upload a video demonstrating FABB finding a real bug in a counter or FSM design.
2. Include a sample output showing FABB's bug report for a known-buggy design.
3. Quantify effectiveness — e.g., "found 3 of 5 injected bugs in test designs" — to validate correctness.

## Issues (If Any)
- Video folder exists but is empty.
- No demonstration of FABB successfully identifying a bug (only a counter_sim.log provided as input).
- AI-powered explanations require external API keys not included.
