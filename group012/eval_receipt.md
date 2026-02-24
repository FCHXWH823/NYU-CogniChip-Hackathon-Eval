# CogniChip Hackathon Evaluation Receipt — Cognichip TinyMAC (2×2 MAC Array)

## Submission Overview
- Team folder: `group012`
- Slides: `slides/Cognichip_TinyMAC.pdf`
- Video: External YouTube link (`https://youtu.be/02nDIMiR23w`) referenced in README
- Code/Repo: `src/Cognichip-Hackson/` — `mac_array_2x2.sv`, `tb_mac_array_2x2.sv`
- Evidence completeness: Moderate — README documents all 9 test cases with pass/fail, 140 ps simulation time, and waveform generation; actual log files not committed to repo.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 20 | 30 |
| Cognichip Platform Usage | 8 | 20 |
| Innovation & Creativity | 8 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 3 | 10 |
| Clarity — Repo Organization | 3 | 5 |
| Potential Real-World Impact | 7 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **56** | **110** |

## Detailed Evaluation

### A) Technical Correctness (20/30)
- Strengths:
  - README documents 9 specific test cases by name and purpose (reset verification, single MAC, accumulation, parallel operation, clear, re-accumulate, enable=0, large value 255×255).
  - Reported results: "✓ All 9 test cases passed", 140 ps simulation time, waveform file generated.
  - 20-bit accumulator correctly sized to prevent overflow during repeated 8-bit multiplications.
  - `DEPS.yml` present for simulation automation.
  - Design is fully synthesizable with no warnings/errors claimed.
- Weaknesses / Missing evidence:
  - No simulation log files or waveform screenshot committed to repository; test pass claims are self-reported in README.
  - Only 2×2 array tested; README mentions scalability to 4×4 or 8×8 but not implemented.
- Key evidence:
  - (src/Cognichip-Hackson/4x4 8-bit MAC/README.md — test case descriptions and results)
  - (src/Cognichip-Hackson/4x4 8-bit MAC/mac_array_2x2.sv — RTL design)
  - (src/Cognichip-Hackson/4x4 8-bit MAC/tb_mac_array_2x2.sv — testbench)

### B) Effective Use of the Cognichip Platform (8/20)
- Strengths:
  - Folder named "Cognichip-Hackson" and slides titled "Cognichip_TinyMAC"; platform awareness evident.
  - DEPS.yml structure consistent with Cognichip ACI simulation workflow.
- Weaknesses / Missing evidence:
  - No explicit description of how Cognichip was used, which features, or what AI feedback shaped the design.
  - Capped at 8/20 — platform use is implied but not specifically described.
- Key evidence:
  - (src/Cognichip-Hackson/ — DEPS.yml present)

### C) Innovation & Creativity (8/15)
- Strengths:
  - Clean hierarchical MAC → 2×2 array design is a good template for AI accelerators.
  - 20-bit accumulator with explicit overflow protection shows thoughtful design.
  - Independent enable and clear control per MAC unit adds flexibility.
- Weaknesses:
  - 2×2 MAC array is a classic introductory accelerator design exercise; limited novelty in this configuration.
  - The folder is named "4x4 8-bit MAC" but only a 2×2 array is implemented.
- Key evidence:
  - (src/.../README.md — architecture diagram, interface specification)

### D) Clarity of Presentation (13/25)
#### D1) Slides clarity (7/10)
- Notes: PDF exists; cannot verify content directly, but reasonable base score awarded.
- Evidence: `slides/Cognichip_TinyMAC.pdf`

#### D2) Video clarity (3/10)
- Notes: External YouTube link (`https://youtu.be/02nDIMiR23w`) is referenced in README but no video file committed to repo; cannot verify content or quality of video.
- Evidence: README — YouTube URL

#### D3) Repo organization (3/5)
- Notes: RTL and testbench files are present. DEPS.yml included. README is informative with architecture diagram, interface tables, and test cases. Minor: folder name mismatch ("4x4 8-bit MAC" but design is 2×2).
- Evidence: (src/Cognichip-Hackson/ structure)

### E) Potential Real-World Impact (7/10)
- Notes: MAC arrays are fundamental building blocks for neural network inference, DSP filters, and matrix multiplication. The modular design with clear parameters is a practical starting point for larger AI accelerators.
- Evidence: README — "Typical Application Scenarios" section (matrix multiplication, CNN, FIR/IIR, image processing)

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA or Tiny Tapeout targeting steps documented.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Average submission**
- A clean, well-documented basic MAC array with a comprehensive testbench specification. The main weaknesses are that test results are self-reported without committed logs, the scope is small (2×2 array), and Cognichip platform usage is implicit rather than described.

## Actionable Feedback (Most Important Improvements)
1. Commit the actual simulation log output showing all 9 test cases passing, or at minimum a waveform screenshot.
2. Implement the mentioned scalability to 4×4 or 8×8 arrays to demonstrate the parameterized architecture in practice.
3. Document the Cognichip workflow explicitly — what prompts were used, what iteration produced the final design.

## Issues (If Any)
- Folder named "4x4 8-bit MAC" but only a 2×2 design is implemented.
