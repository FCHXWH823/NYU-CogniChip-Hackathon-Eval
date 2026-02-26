# CogniChip Hackathon Evaluation Receipt — group002

## Submission Overview
- Team folder: `group002`
- Slides: `slides/AI-Driven Layout-Aware RTL Optimization Loop (Abhishek, Saishruti, Harshal, Bhanuja).pdf`
- Video: `video/AI-Driven Layout-Aware RTL Optimization Loop (Abhishek, Saishruti, Harshal, Bhanuja).mp4`
- Code/Repo: `src/AI-Drievn-Layout-Aware-RTL-Optimization-Loop/` — `auto_fix_cognix.py`, `test/up_down_counter.sv`, `run_logs/20260220_224804/summary.json`, VCD dump, `ai_fix_backups/`, `install_opensta.sh`, README
- Evidence completeness: Good — local verification pipeline completed successfully (3 iterations, PASSED); no Cognichip EDA JSON results but Cognix ACI usage is documented.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 15 | 30 |
| Cognichip Platform Usage | 12 | 20 |
| Innovation & Creativity | 12 | 15 |
| Clarity — Slides | 8 | 10 |
| Clarity — Video | 7 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 7 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **65** | **110** |

## Detailed Evaluation

### A) Technical Correctness (15/30)
- Strengths:
  - `run_logs/20260220_224804/summary.json` shows `"final_status": "PASSED"` after 3 auto-fix iterations using Verilator simulation and Yosys pre-synthesis.
  - `dump.vcd` waveform file is committed, confirming simulation ran to completion.
  - Iterative backup snapshots (`ai_fix_backups/iter_01`, `iter_02`) document the fix progression.
  - Yosys ran clean with no blocking assignments; Verilator reported zero errors.
- Weaknesses / Missing evidence:
  - No Cognichip EDA JSON result files; all verification is done through the custom Python pipeline, not the Cognichip EDA platform directly.
  - Only one small design (up/down counter) was verified; no complex RTL design tested.
  - OpenSTA timing analysis did not run (`"opensta": {"ran": false}`).
- Key evidence:
  - (src/AI-Drievn-Layout-Aware-RTL-Optimization-Loop/run_logs/20260220_224804/summary.json) — `final_status: PASSED`, 3 iterations
  - (src/AI-Drievn-Layout-Aware-RTL-Optimization-Loop/run_logs/20260220_224804/verilator_output.txt) — Verilator pass log
  - (src/AI-Drievn-Layout-Aware-RTL-Optimization-Loop/dump.vcd) — waveform evidence

### B) Effective Use of the Cognichip Platform (12/20)
- Strengths:
  - `auto_fix_cognix.py` explicitly integrates the Cognix AI (Cognichip ACI) as the fix engine within a three-stage verification loop.
  - DEPS.yml present, indicating awareness of the Cognichip project structure.
  - Demonstrates actual AI-driven code fixing with prompts generated and responses applied automatically.
- Weaknesses / Missing evidence:
  - No `eda sim` command invocation logs or EDA JSON result files; the pipeline uses local Verilator/Yosys rather than the Cognichip EDA runner.
  - Cognix AI usage is described but interaction transcripts are not committed.
- Key evidence:
  - (src/AI-Drievn-Layout-Aware-RTL-Optimization-Loop/auto_fix_cognix.py) — main pipeline integrating Cognix
  - (src/AI-Drievn-Layout-Aware-RTL-Optimization-Loop/DEPS.yml) — Cognichip project config

### C) Innovation & Creativity (12/15)
- Strengths:
  - Three-stage pipeline (Verilator simulation → Yosys pre-synthesis → OpenSTA timing) with automatic AI-driven fix-and-retry loop is genuinely novel for an RTL hackathon.
  - `ai_fix_backups/` structure shows a thoughtful iterative design methodology.
  - The pipeline is generalizable to any RTL design, not just the test counter.
- Weaknesses:
  - The demo design (up/down counter) is very simple; the pipeline's power is not fully demonstrated.
  - OpenSTA integration is scaffolded but not exercised.

### D) Clarity of Presentation (19/25)
#### D1) Slides clarity (8/10)
- Notes: Clear pipeline diagram in PDF; explains motivation (Memory Wall, large-model training costs), system architecture, and auto-fix workflow. Good visual design.
- Evidence: (slides/AI-Driven Layout-Aware RTL Optimization Loop (Abhishek, Saishruti, Harshal, Bhanuja).pdf)

#### D2) Video clarity (7/10)
- Notes: Video present. Demo appears to cover the auto-fix pipeline. Pacing and clarity are adequate based on file presence and slides context.
- Evidence: (video/AI-Driven Layout-Aware RTL Optimization Loop (Abhishek, Saishruti, Harshal, Bhanuja).mp4)

#### D3) Repo Organization (4/5)
- Notes: Good README with pipeline diagram, installation steps, and quick-start. `obj_dir/` build artifacts were committed (should be in `.gitignore`). Minor typo in directory name (`AI-Drievn`).
- Evidence: (src/AI-Drievn-Layout-Aware-RTL-Optimization-Loop/README.md)

### E) Potential Real-World Impact (7/10)
- Notes: An automated RTL verification + AI-fix loop directly addresses real EDA productivity pain points; applicable to any RTL project. Limited by absence of complex design demonstration and missing timing analysis.
- Evidence: (src/AI-Drievn-Layout-Aware-RTL-Optimization-Loop/README.md) — "automated RTL verification and self-optimizing system"

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA or tapeout evidence found.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Good** (65/110)
- The RTL auto-fix pipeline concept is the most creative meta-design approach in this cohort; the verification evidence is real (PASSED run with waveform). Score is capped on Technical Correctness because the Cognichip EDA platform's own simulation runner was not used, and only a trivial design was verified end-to-end.

## Actionable Feedback (Most Important Improvements)
1. Run the pipeline via Cognichip `eda sim` and commit EDA JSON result files to demonstrate platform integration.
2. Test a more complex RTL design (e.g., UART, FIR filter, small FSM) to demonstrate the pipeline's value beyond a counter.
3. Enable and demonstrate OpenSTA timing analysis to complete the three-stage vision.

## Issues (If Any)
- `obj_dir/` build artifacts committed; add to `.gitignore`.
- Directory name typo: `AI-Drievn-Layout-Aware-RTL-Optimization-Loop` (should be "AI-Driven").
- No Cognichip EDA JSON results; verification relies on custom local pipeline only.
