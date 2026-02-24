# CogniChip Hackathon Evaluation Receipt — group021

## Submission Overview
- Team folder: `group021`
- Slides: `slides/Submission Note - QuantEdge Silicon.pdf` — **not a presentation**; this is a note apologizing for not submitting a PDF and providing an external link (https://hackathon-cognichip.netlify.app)
- Video: `video/` (folder exists but is empty — no video file)
- Code/Repo: `src/hackathon_QuantSilicon/` (39 files; hardware design with Cognichip EDA simulation results showing PASS after iteration)
- Evidence completeness: Moderate — slides PDF is a submission note only (external presentation not accessible for review); Cognichip EDA results confirm final simulation passes; no video; project content inferred from code and EDA logs.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 20 | 30 |
| Cognichip Platform Usage | 13 | 20 |
| Innovation & Creativity | 8 | 15 |
| Clarity — Slides | 2 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 3 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **52** | **110** |

## Detailed Evaluation

### A) Technical Correctness (20/30)
- Strengths:
  - EDA results confirm: "TEST PASSED", "Successfully processed all 20 samples."
  - Iterative development visible: earlier runs failed ("Expected 20 outputs, got 13"), final run passes.
  - Top-level testbench (`top_tb`) simulation produces correct 20-sample output.
  - Multiple simulation runs (3+ timestamped directories) with dumpfile.fst waveforms.
  - Cognichip EDA version 0.3.10 confirmed.
- Weaknesses / Missing evidence:
  - Without accessible slides, the nature of the hardware design is not fully clear from code alone.
  - Only one test case visible ("20 samples processed") — no diverse test coverage.
  - Slides presentation not reviewable (external URL, no PDF content).
- Key evidence:
  - (src/hackathon_QuantSilicon/simulation_results/sim_2026-02-18T20-22-42-704Z/eda_results.json — "TEST PASSED, Successfully processed all 20 samples")
  - (src/hackathon_QuantSilicon/simulation_results/sim_2026-02-18T20-19-58-925Z/eda_results.json — earlier failure: "Expected 20 outputs, got 13")

### B) Effective Use of the Cognichip Platform (13/20)
- Strengths:
  - Cognichip EDA platform confirmed used for simulation (version 0.3.10).
  - Multiple simulation runs demonstrate iterative use of the platform for debugging.
- Weaknesses / Missing evidence:
  - Slides PDF is just a submission note — no documentation of how Cognichip was used.
  - Cannot review the external presentation for Cognichip workflow description.
- Key evidence:
  - (src/hackathon_QuantSilicon/simulation_results/ — multiple EDA runs)

### C) Innovation & Creativity (8/15)
- Strengths:
  - The project name "QuantEdge Silicon" suggests quantization for edge computing — relevant topic.
  - Iterative debugging (13 → 20 samples) shows non-trivial pipeline design.
- Weaknesses:
  - Without slides content, full innovation cannot be assessed.
  - Score reflects partial evidence only.
- Key evidence:
  - (src/hackathon_QuantSilicon/ — project code)

### D) Clarity of Presentation (5/25)
#### D1) Slides clarity (2/10)
- Notes: The submitted PDF is not a presentation — it is a one-page submission note directing reviewers to an external Netlify URL. The actual presentation cannot be reviewed as it requires internet access and may change. Scored 2 for the effort of creating and linking the external presentation.
- Evidence: (slides/Submission Note - QuantEdge Silicon.pdf — "Presentation Link: https://hackathon-cognichip.netlify.app")

#### D2) Video clarity (0/10)
- Notes: Video folder exists but is empty.
- Evidence: (video/ — empty directory)

#### D3) Repo organization (3/5)
- Notes: Simulation results organized in timestamped directories. README is present. Some structure exists but without slides it's hard to fully assess.
- Evidence: (src/hackathon_QuantSilicon/ — organized simulation results)

### E) Potential Real-World Impact (6/10)
- Notes: Edge AI quantization hardware is highly relevant. Cannot fully assess without slides content.
- Evidence: Partial — project name and EDA logs suggest edge AI focus.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA or tapeout evidence in repository.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Below Average — penalized for non-compliant submission format**
- The team clearly has a real hardware project with passing Cognichip EDA simulation evidence (20-sample test passes after iteration). However, submitting a submission note instead of a PDF presentation is non-compliant with the hackathon requirements. The actual presentation at the Netlify URL is inaccessible for independent offline review.

## Actionable Feedback (Most Important Improvements)
1. Submit the actual PDF presentation as required — export the interactive slides to PDF.
2. Upload a video recording of the presentation.
3. Add more diverse test cases to the testbench beyond the single 20-sample test.

## Issues (If Any)
- Slides PDF is a submission note, not a presentation — external URL cannot be reviewed offline.
- Video folder exists but is empty.
- Nature of the hardware design unclear without accessible slides.
