# CogniChip Hackathon Evaluation Receipt — group012

## Submission Overview
- Team folder: `group012`
- Slides: `slides/Cognichip_TinyMAC.pdf` (also `src/Cognichip-Hackson/Cognichip_TinyMAC.pdf`)
- Video: `video/CogniChip Hackathon TinyMAC Demo.mp4`
- Code/Repo: `src/Cognichip-Hackson/` — `2×2_MAC_Array.zip`, `4x4 8-bit MAC/` directory with `mac_unit.sv`, `mac_array_4x4.sv`, `controller_fsm.sv`, `tb_mac_array_4x4.sv`, `DEPS.yml`; README claims 9/9 tests passed for 2×2 array
- Evidence completeness: Partial — DEPS.yml and RTL code present for both 2×2 and 4×4 designs; README claims test success but no EDA JSON results or simulation logs committed.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 12 | 30 |
| Cognichip Platform Usage | 6 | 20 |
| Innovation & Creativity | 8 | 15 |
| Clarity — Slides | 8 | 10 |
| Clarity — Video | 7 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **51** | **110** |

## Detailed Evaluation

### A) Technical Correctness (12/30)
- Strengths:
  - README states "All 9 test cases passed" with simulation time 140 ps and "Waveform file generated" for the 2×2 MAC array.
  - 4×4 MAC array RTL committed with FSM controller (IDLE→LOAD→CLEAR→SETUP→COMPUTE→DONE), testbench, and DEPS.yml — indicating Cognichip project setup.
  - Design is logically well-specified: 8-bit inputs, 20-bit accumulator (2×2) / 32-bit signed (4×4), overflow analysis documented.
- Weaknesses / Missing evidence:
  - Cap rule applied: no EDA JSON result files, no simulation logs, no waveform files committed; claimed test results cannot be independently confirmed.
  - 2×2 MAC array source code is inside a `.zip` file, not directly in the repo — cannot be independently verified.
  - No EDA result directories found in `src/`.
- Key evidence:
  - (src/Cognichip-Hackson/README.md) — claims 9/9 tests passed, 140 ps simulation
  - (src/Cognichip-Hackson/4x4 8-bit MAC/DEPS.yml) — Cognichip project structure
  - (src/Cognichip-Hackson/4x4 8-bit MAC/tb_mac_array_4x4.sv) — testbench code

### B) Effective Use of the Cognichip Platform (6/20)
- Strengths:
  - `DEPS.yml` in the 4×4 MAC directory confirms Cognichip project structure awareness.
  - Slide deck PDF is also committed inside `src/` alongside the code, suggesting the submission was prepared with the platform.
- Weaknesses / Missing evidence:
  - No `eda sim` JSON results committed; Cognichip simulation cannot be confirmed.
  - No ACI interaction logs or description of platform-specific workflow.
- Key evidence:
  - (src/Cognichip-Hackson/4x4 8-bit MAC/DEPS.yml)

### C) Innovation & Creativity (8/15)
- Strengths:
  - Both a 2×2 and a 4×4 MAC array submitted, showing iterative design progression.
  - 4×4 design adds a non-trivial FSM controller for N-cycle accumulation with register-mapped output, elevating it beyond a simple MAC unit.
  - Signed 8×8→16-bit product with 32-bit accumulation and sign extension is carefully engineered for AI accelerator use.
- Weaknesses:
  - MAC arrays are standard AI accelerator building blocks; the novelty is in the execution quality rather than the concept.

### D) Clarity of Presentation (19/25)
#### D1) Slides clarity (8/10)
- Notes: PDF provides clear architecture diagrams, interface specs, verification results table, and application context. Well-organised with visual diagrams.
- Evidence: (slides/Cognichip_TinyMAC.pdf)

#### D2) Video clarity (7/10)
- Notes: Demo video present; YouTube link also mentioned in README (https://youtu.be/02nDIMiR23w).
- Evidence: (video/CogniChip Hackathon TinyMAC Demo.mp4)

#### D3) Repo Organization (4/5)
- Notes: README with interface specification, architecture diagram, and verification results is thorough. 2×2 array is packaged as a `.zip` instead of plain source files, reducing transparency. DEPS.yml is only in the 4×4 subdirectory.
- Evidence: (src/Cognichip-Hackson/README.md), (src/Cognichip-Hackson/4x4 8-bit MAC/DEPS.yml)

### E) Potential Real-World Impact (6/10)
- Notes: Compact MAC arrays are fundamental to AI inference accelerators (NPUs, TPU systolic arrays). A scalable implementation up to 4×4 with FSM control is a practical building block.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: README mentions scalability to 4×4/8×8 but no FPGA targeting evidence.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Average** (51/110)
- The TinyMAC design is well-specified and clearly presented; the 4×4 array with FSM controller shows good engineering effort. However, the absence of committed EDA results prevents confirming the claimed test success, limiting the Technical Correctness score.

## Actionable Feedback (Most Important Improvements)
1. Run the 4×4 MAC testbench via `eda sim` and commit the EDA JSON result file to verify the claimed pass.
2. Extract the 2×2 array source from the `.zip` file into the repository so it can be independently inspected.
3. Add waveform output (FST/VCD) to demonstrate correct accumulation behaviour visually.

## Issues (If Any)
- No EDA JSON result files committed; "9/9 tests passed" claim unverifiable.
- 2×2 MAC source code is inside `2×2_MAC_Array.zip` — not directly accessible in the repo.
- Slide PDF duplicated in both `slides/` and `src/Cognichip-Hackson/`.
