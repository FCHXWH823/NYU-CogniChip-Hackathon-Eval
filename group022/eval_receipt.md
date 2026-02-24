# CogniChip Hackathon Evaluation Receipt — group022

## Submission Overview
- Team folder: `group022`
- Slides: `slides/TeenyTinyTrustyCore (3TC).pdf`
- Video: `video/` (folder exists but is empty — no video file)
- Code/Repo: `src/teenytinytrustycore/` (426 files; two approaches — approach1 (Verilator+SHA-256+HMAC-SHA-256+AES-CTR, FINAL_STATUS 5/7 tests pass) and approach2 (Cognichip EDA, simulation errors in 256-bit literal handling))
- Evidence completeness: Good — approach1 has detailed result documentation (FINAL_STATUS.md, SIMULATION_RESULTS.md) and partial test passes; approach2 has EDA results showing compilation errors; comprehensive documentation throughout.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 22 | 30 |
| Cognichip Platform Usage | 14 | 20 |
| Innovation & Creativity | 13 | 15 |
| Clarity — Slides | 9 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 9 | 10 |
| Bonus — FPGA/Tiny Tapeout | 4 | 10 |
| **Total** | **75** | **110** |

## Detailed Evaluation

### A) Technical Correctness (22/30)
- Strengths:
  - FINAL_STATUS.md documents: Total Tests: 7, Passed: 5 (71%), Failed: 2 (AES issues).
  - SHA-256: 3/3 tests PASS, HMAC-SHA-256: 2/2 tests PASS — critical cryptographic functions verified.
  - PUF module successfully performs enrollment: helper data generated, correct state transitions (IDLE → ENROLL_MEASURE → ENROLL_GENERATE → DONE).
  - dumpfile.fst waveform committed confirming simulation ran.
  - Verilator binary compiled (`obj_dir/Vtb_crypto_ops`).
  - SIMULATION_RESULTS.md, CRYPTO_TEST_RESULTS.md, BUG_FIX_RESULTS.md, VERIFICATION_PLAN.md — comprehensive documentation.
- Weaknesses / Missing evidence:
  - AES-CTR: 0/2 tests pass (known issues documented).
  - Approach2 has Cognichip EDA errors (256-bit literal syntax issue in Verilator) — approach2 simulation doesn't compile.
  - State machine deadlock bug identified in root_of_trust_top.sv.
- Key evidence:
  - (src/teenytinytrustycore/approach1/FINAL_STATUS.md — "5/7 PASS, AES-CTR: 0/2 FAIL")
  - (src/teenytinytrustycore/approach1/SIMULATION_RESULTS.md — detailed bug description)
  - (src/teenytinytrustycore/approach2/simulation_results/sim_2026-02-20T23-27-48-110Z/eda_results.json — 256-bit literal error)

### B) Effective Use of the Cognichip Platform (14/20)
- Strengths:
  - Approach2 specifically targets Cognichip EDA platform (eda_results.json present).
  - Slides describe Cognichip as AI co-designer for "Syntactic and Semantic Check" and "Functional Verification."
  - Dual approach shows thoughtful exploration of tool capabilities.
  - Multiple EDA simulation attempts documented.
- Weaknesses / Missing evidence:
  - Approach2 fails to compile on Cognichip platform due to 256-bit literal bug — Cognichip EDA simulation didn't produce passing results.
  - Approach1 used standalone Verilator, not Cognichip platform directly.
- Key evidence:
  - (slides/TeenyTinyTrustyCore (3TC).pdf — "Approach #1: LLM at the Helm", Planned approach table)
  - (src/teenytinytrustycore/approach2/ — Cognichip EDA results with errors)

### C) Innovation & Creativity (13/15)
- Strengths:
  - Hardware Root of Trust (HoT) with PUF, KDF, and crypto engines is a sophisticated security design.
  - 3TC: minimal, fully functional hardware root of trust — unique ID, device secret, key derivation, cryptographic functions.
  - Dual-approach methodology (LLM at the Helm vs. traditional) is methodologically interesting.
  - HMAC-SHA-256 and AES-CTR in hardware root of trust is non-trivial.
- Weaknesses:
  - Hardware Root of Trust is a well-established concept; implementation is sophisticated but not architecturally novel.
- Key evidence:
  - (slides/TeenyTinyTrustyCore (3TC).pdf — "HoT with PUF, KDF, Crypto functions")
  - (src/teenytinytrustycore/approach1/hmac_sha256.sv, aes_ctr.sv, kdf_module.sv)

### D) Clarity of Presentation (13/25)
#### D1) Slides clarity (9/10)
- Notes: Very professional academic slides with clear motivation, structure description, dual-approach methodology table, and prompts section. Well-organized for a complex security design.
- Evidence: (slides/TeenyTinyTrustyCore (3TC).pdf)

#### D2) Video clarity (0/10)
- Notes: Video folder exists but is empty.
- Evidence: (video/ — empty directory)

#### D3) Repo organization (4/5)
- Notes: Excellent documentation — FINAL_STATUS.md, SIMULATION_RESULTS.md, CRYPTO_TEST_RESULTS.md, BUG_FIX_RESULTS.md, UVM_ENVIRONMENT_SUMMARY.md, VERIFICATION_PLAN.md. 426 files well-structured across two approaches. README present.
- Evidence: (src/teenytinytrustycore/ — extensive documentation)

### E) Potential Real-World Impact (9/10)
- Notes: Hardware Root of Trust is critical for IoT security, device identity, and secure boot. A minimal, verified HoT could be widely deployed in edge devices. SHA-256 and HMAC-SHA-256 passing tests make this partly production-ready.
- Evidence: (slides/TeenyTinyTrustyCore (3TC).pdf — "minimal, yet fully functional" HoT)

### Bonus) FPGA / Tiny Tapeout Targeting (+4/10)
- Notes: Slides mention "Tiny Tapeout" in the context of feasibility study. The title "TeenyTinyTrustyCore" suggests targeting Tiny Tapeout. UVM_ENVIRONMENT_SUMMARY.md and extensive verification suggest tapeout-readiness was planned. However, no synthesis reports, area estimates, or tapeout constraints committed. Partial bonus for credible plan.
- Evidence:
  - (slides/TeenyTinyTrustyCore (3TC).pdf — "Feasibility Study" and Tiny Tapeout mention)
  - (src/teenytinytrustycore/approach1/VERIFICATION_PLAN.md)

## Final Recommendation
- Overall verdict: **Strong submission — best security hardware design**
- Sophisticated hardware Root of Trust with PUF, KDF, SHA-256, HMAC, and AES-CTR. SHA-256 and HMAC-SHA-256 fully passing is a significant cryptographic achievement. The honest documentation of failures (AES-CTR, state machine deadlock) with detailed analysis shows engineering rigor.

## Actionable Feedback (Most Important Improvements)
1. Fix the AES-CTR implementation and state machine deadlock to achieve full test pass.
2. Fix the 256-bit literal syntax in approach2 testbenches to pass Cognichip EDA compilation.
3. Upload a video demonstrating the crypto operations or tapeout flow.

## Issues (If Any)
- Video folder exists but is empty.
- AES-CTR: 0/2 tests fail (known bugs documented).
- Approach2 fails to compile in Cognichip EDA (256-bit literal Verilator compatibility issue).
