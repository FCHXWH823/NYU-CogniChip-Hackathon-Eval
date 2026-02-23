# CogniChip Hackathon Evaluation Receipt — group005

## Submission Overview
- Team folder: `group005`
- Slides: `slides/ARCH-AI_Cognichip_Presentation.pdf`
- Video: `video/ARCH-AI_Demo_Cognichip.mp4`
- Code/Repo: `src/ARCH-AI_Cognichip-Hackathon/` — Python framework (`main.py`, `llm/`, `rl/`, `tools/`), `.cogni/` interaction logs, `requirements.txt`, README; no RTL simulation results
- Evidence completeness: Partial — code and `.cogni` interaction logs present, but no RTL simulation outputs or EDA results confirming any hardware design was verified.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 8 | 30 |
| Cognichip Platform Usage | 7 | 20 |
| Innovation & Creativity | 12 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 7 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 7 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **52** | **110** |

## Detailed Evaluation

### A) Technical Correctness (8/30)
- Strengths:
  - Python framework (`main.py`) with DQN agent, LLM agent, and heuristic fallback is implemented.
  - Verilog generation tool (`tools/generate_verilog.py`) and Yosys synthesis integration present.
  - `.cogni/` directory contains multiple interaction logs showing the platform was actively used.
- Weaknesses / Missing evidence:
  - Cap rule applied: no simulation logs, EDA JSON results, or waveform files confirming any generated RTL was simulated or synthesised.
  - `rtl/best_design.v` (the claimed output) is not confirmed to be functionally correct.
  - No testbench for any generated hardware design is committed.
- Key evidence:
  - (src/ARCH-AI_Cognichip-Hackathon/main.py) — framework entry point
  - (src/ARCH-AI_Cognichip-Hackathon/.cogni/) — Cognichip ACI interaction logs (pip installs, tool invocations)

### B) Effective Use of the Cognichip Platform (7/20)
- Strengths:
  - `.cogni/` logs confirm the Cognichip ACI environment was used (Python package installation, tool execution within the ACI sandbox).
  - The framework explicitly targets the Cognichip platform as its execution environment.
- Weaknesses / Missing evidence:
  - No `eda sim` runs or EDA JSON result files showing RTL simulation on the Cognichip platform.
  - Cognichip is used as a compute environment for Python, not for hardware simulation/synthesis — the primary EDA use case.
- Key evidence:
  - (src/ARCH-AI_Cognichip-Hackathon/.cogni/output_toolu_017eDUx5MSKS4btPPQRTNLvt.txt) — pip install logs in ACI

### C) Innovation & Creativity (12/15)
- Strengths:
  - Combining a DQN agent with LLM-guided reasoning for hardware design space exploration (DSE) is a genuinely novel meta-design approach.
  - Pareto-frontier analysis for multi-objective hardware optimisation (area/performance/efficiency) with automatic Verilog generation is a strong concept.
  - Heuristic fallback ensures robustness when AI models are unavailable.
- Weaknesses:
  - Concept is well-described but execution is incomplete; no end-to-end demonstration of a real hardware optimisation run with verified output.

### D) Clarity of Presentation (18/25)
#### D1) Slides clarity (7/10)
- Notes: PDF covers system architecture, RL pipeline, LLM integration, and use case examples. Well-formatted presentation.
- Evidence: (slides/ARCH-AI_Cognichip_Presentation.pdf)

#### D2) Video clarity (7/10)
- Notes: Demo video present; shows the framework running.
- Evidence: (video/ARCH-AI_Demo_Cognichip.mp4)

#### D3) Repo Organization (4/5)
- Notes: README is clear with installation steps, usage examples, and project structure. `requirements.txt` and `reinforcement_learning/training/requirements_rl.txt` are proper. `.cogni/` output files are committed as evidence of platform usage.
- Evidence: (src/ARCH-AI_Cognichip-Hackathon/README.md)

### E) Potential Real-World Impact (7/10)
- Notes: AI-driven hardware DSE tools addressing area/power/performance trade-offs are highly relevant for chip designers; a working tool would have broad applicability. Impact is discounted because the demo RTL output is unverified.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA or tapeout evidence.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Average** (52/110)
- The concept (DQN + LLM for hardware DSE) is among the most innovative in the cohort, but the submission demonstrates a framework, not a working verified hardware result. The absence of any RTL simulation evidence limits the score significantly.

## Actionable Feedback (Most Important Improvements)
1. Run an end-to-end optimisation on a non-trivial design, commit EDA JSON results confirming the best-design Verilog is functionally correct.
2. Include a concrete before/after comparison: baseline design metrics vs. AI-optimised metrics with synthesis numbers.
3. Add a testbench for `rtl/best_design.v` and run it through `eda sim` to generate verifiable pass/fail evidence.

## Issues (If Any)
- No EDA simulation results or waveform files committed; technical correctness cannot be confirmed.
- `rtl/` directory (generated Verilog output) not committed, making the claimed output unverifiable.
