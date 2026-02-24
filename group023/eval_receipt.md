# CogniChip Hackathon Evaluation Receipt — group023

## Submission Overview
- Team folder: `group023`
- Slides: `slides/VERICADE Presentation by The Aicoholics - Cognichip Hackathon.pdf`
- Video: `video/` (folder exists but is empty — no video file)
- Code/Repo: `src/Vericade_CogniChip-Hackathon/` (26 files; four game RTL modules + top-level, synthesis log, testbench auto-grader, Yosys synthesis scripts, DEPS.yml, waveforms)
- Evidence completeness: Good — Yosys synthesis log confirms successful synthesis of all game modules; waveforms present; README claims 100% test pass; slides show Cognichip prompts and verification testing.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 21 | 30 |
| Cognichip Platform Usage | 15 | 20 |
| Innovation & Creativity | 13 | 15 |
| Clarity — Slides | 9 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 8 | 10 |
| Bonus — FPGA/Tiny Tapeout | 5 | 10 |
| **Total** | **75** | **110** |

## Detailed Evaluation

### A) Technical Correctness (21/30)
- Strengths:
  - Yosys synthesis log (`synthesis.log`) confirms successful synthesis of all modules: full_adder, input_controller, matrix_driver, binary_adder_game, maze_game, tictactoe_game, connect4_game, game_manager.
  - Synthesis stats: ~1,850 cells, ~500 FFs per README — concrete area numbers.
  - Two waveform files present (`dumpfile.fst`, `dumpfile_2.fst`).
  - DEPS.yml committed for Cognichip EDA simulation.
  - README claims "✅ All tests pass (100%), synthesis succeeds" with `bench_autograde` testbench.
  - Four progressive game modules: Binary Adder, LED Maze, Tic-Tac-Toe, Connect Four — each teaching a hardware concept.
- Weaknesses / Missing evidence:
  - No Cognichip EDA `eda_results.json` in committed files — synthesis is via Yosys, not Cognichip EDA.
  - "100% pass" claim in README not backed by committed simulation log output.
  - Synthesis with Yosys confirms synthesizability but not functional correctness.
- Key evidence:
  - (src/Vericade_CogniChip-Hackathon/synthesis.log — Yosys synthesis successful for all 8 modules)
  - (src/Vericade_CogniChip-Hackathon/dumpfile.fst, dumpfile_2.fst — simulation waveforms)
  - (src/Vericade_CogniChip-Hackathon/README.md — "All tests pass (100%)")

### B) Effective Use of the Cognichip Platform (15/20)
- Strengths:
  - Slides explicitly show Cognichip setup and prompts — specific prompts documented for RTL generation and verification testing.
  - Cognichip used for testbench generation ("AI-auto-grader") for comprehensive edge case coverage.
  - DEPS.yml present suggesting Cognichip EDA configuration was set up.
  - Slides show "Cognichip Design Verification Testing" and "Cognichip Testbench Verification Testing" sections with actual prompt screenshots.
- Weaknesses / Missing evidence:
  - Cognichip EDA results not committed despite DEPS.yml being present.
- Key evidence:
  - (slides/VERICADE Presentation by The Aicoholics - Cognichip Hackathon.pdf — Cognichip prompt screenshots and verification test prompts)

### C) Innovation & Creativity (13/15)
- Strengths:
  - Educational gamification of hardware design is a genuinely creative and unique application.
  - Four progressive games map to fundamental hardware concepts (combinational → FSM → sequential logic).
  - "Learning it by Playing it" paradigm — turns FPGA into a gaming console.
  - Targets a real education gap: hardware design is intimidating for beginners.
  - AI auto-grader concept for hardware testbenches is novel.
- Weaknesses:
  - Game implementations (binary adder, tic-tac-toe) are standard designs; innovation is in the application context.
- Key evidence:
  - (slides/VERICADE Presentation by The Aicoholics - Cognichip Hackathon.pdf — "Transform Verilog into a magic spell")
  - (src/Vericade_CogniChip-Hackathon/ — four game modules)

### D) Clarity of Presentation (13/25)
#### D1) Slides clarity (9/10)
- Notes: Excellent slides with clear vision, team introduction, RTL description, Cognichip setup/prompts, and results screenshots. The "Learning it by Playing it" narrative is compelling and well-communicated.
- Evidence: (slides/VERICADE Presentation by The Aicoholics - Cognichip Hackathon.pdf)

#### D2) Video clarity (0/10)
- Notes: Video folder exists but is empty — no video file submitted.
- Evidence: (video/ — empty directory)

#### D3) Repo organization (4/5)
- Notes: Clean repo with 26 files: game RTL modules, synthesis script, DEPS.yml, waveforms. README is excellent (quick start, game descriptions, expected results, synthesis stats).
- Evidence: (src/Vericade_CogniChip-Hackathon/README.md — clear quick start)

### E) Potential Real-World Impact (8/10)
- Notes: Educational hardware design tools address a real need — hardware is hard for beginners. An FPGA-based game console approach could significantly lower the entry barrier for digital design education.
- Evidence: (slides/VERICADE Presentation by The Aicoholics - Cognichip Hackathon.pdf — "bridge the gap between software coding and hardware engineering")

### Bonus) FPGA / Tiny Tapeout Targeting (+5/10)
- Notes: Yosys synthesis for FPGA targeting confirmed (synthesis.log commits, ~1,850 cells synthesized). Specific synthesis stats reported. The project targets physical FPGA deployment as its core use case. No FPGA-specific constraints file, no timing report, no board testing. Partial bonus for synthesis evidence.
- Evidence:
  - (src/Vericade_CogniChip-Hackathon/synthesis.log — successful Yosys synthesis)
  - (src/Vericade_CogniChip-Hackathon/README.md — "~1,850 cells, ~500 FFs")

## Final Recommendation
- Overall verdict: **Strong submission — most creative application concept**
- Vericade is uniquely creative — using FPGA as a gaming console to teach hardware design is a compelling innovation. Yosys synthesis confirms the design is synthesizable with concrete cell counts. Slides are excellent with actual Cognichip prompts. Missing Cognichip EDA test results and empty video folder are the main gaps.

## Actionable Feedback (Most Important Improvements)
1. Run `bench_autograde` on Cognichip EDA and commit the eda_results.json to confirm "100% pass."
2. Record a video showing the games running on an actual FPGA board — this is the most impactful demo for this concept.
3. Add FPGA-specific constraints file and run implementation to get timing/power reports.

## Issues (If Any)
- Video folder exists but is empty — a demo video is critical for this concept.
- No Cognichip EDA results committed despite DEPS.yml being present.
