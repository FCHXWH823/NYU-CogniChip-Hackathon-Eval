# CogniChip Hackathon Evaluation Receipt — group004

## Submission Overview
- Team folder: `group004`
- Slides: `slides/Andre Nakkab Cognichip Hackathon.pdf`
- Video: `video/Andre Nakkab Cognichip Video.mp4`
- Code/Repo: `src/cognichip-hackathon/aes/` — AES RTL modules (S-box, inv-S-box, key schedule, round logic), testbenches, 12 Cognichip EDA result directories
- Evidence completeness: Partial — 2 of 12 EDA runs passed (S-box submodules only); main AES key-memory module failed in all 10 attempts.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 12 | 30 |
| Cognichip Platform Usage | 10 | 20 |
| Innovation & Creativity | 9 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 7 | 10 |
| Clarity — Repo Organization | 3 | 5 |
| Potential Real-World Impact | 6 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **54** | **110** |

## Detailed Evaluation

### A) Technical Correctness (12/30)
- Strengths:
  - `aes_sbox_sim` (return_code: 0) and `aes_inv_sbox_sim` (return_code: 0) both passed on Cognichip, confirming correct lookup table implementations.
  - Multiple EDA runs on the key-memory module show systematic debugging iteration.
- Weaknesses / Missing evidence:
  - Cap rule applied: concrete end-to-end AES simulation evidence is absent; the key-memory module (`aes_key_mem_sim`) failed in all 10 EDA attempts with `return_code: 30`.
  - Full AES encryption/decryption correctness is unverified.
  - README links to an external GitHub repo for results; self-contained evidence is missing.
- Key evidence:
  - (src/cognichip-hackathon/aes/simulation_results/sim_2026-02-21T00-46-51-713Z/eda_results.json) — `aes_sbox_sim` PASS
  - (src/cognichip-hackathon/aes/simulation_results/sim_2026-02-21T00-54-21-681Z/eda_results.json) — `aes_inv_sbox_sim` PASS
  - (src/cognichip-hackathon/aes/simulation_results/sim_2026-02-21T01-10-45-151Z/eda_results.json) — `aes_key_mem_sim` failure (return_code: 30)

### B) Effective Use of the Cognichip Platform (10/20)
- Strengths:
  - 12 Cognichip EDA runs across multiple AES submodules showing progressive debugging.
  - Used Cognichip as the backbone for the ROME hierarchical-prompting methodology — a specific, novel use of the platform.
  - README explicitly describes the Cognichip-vs-iVerilog comparison study.
- Weaknesses / Missing evidence:
  - Only 2 of 12 runs succeeded; 10 failures on the primary module undercut the demonstration.
  - README notes daily message limits as a "major disadvantage" — Cognichip-specific iteration was truncated.
- Key evidence:
  - (src/cognichip-hackathon/README.md) — ROME + Cognichip comparison described
  - (src/cognichip-hackathon/aes/simulation_results/*/eda_results.json) — 12 EDA runs

### C) Innovation & Creativity (9/15)
- Strengths:
  - Applying the ROME hierarchical-prompting methodology with Cognichip as its LLM backbone to generate a combined 128-bit/256-bit AES architecture is novel.
  - Comparative evaluation (Cognichip vs OpenAI + iVerilog) adds academic value.
- Weaknesses:
  - AES itself is a well-studied, standard algorithm; novelty lies in the generation methodology.
  - Outcome is incomplete due to daily message limits.

### D) Clarity of Presentation (17/25)
#### D1) Slides clarity (7/10)
- Notes: PDF covers the ROME methodology, Cognichip integration, and AES design goals.
- Evidence: (slides/Andre Nakkab Cognichip Hackathon.pdf)

#### D2) Video clarity (7/10)
- Notes: Video present; covers the project demonstration.
- Evidence: (video/Andre Nakkab Cognichip Video.mp4)

#### D3) Repo Organization (3/5)
- Notes: README is sparse (primarily links to external repo). EDA result directories are present but no `DEPS.yml` found in the main submission. Simulation results directory has clear timestamps.
- Evidence: (src/cognichip-hackathon/README.md)

### E) Potential Real-World Impact (6/10)
- Notes: Hardware AES acceleration is widely needed in security applications. Using AI to auto-generate verified RTL for standard cryptographic cores is a credible use case, though the demonstration is incomplete.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA constraints or tapeout plan found.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Average** (54/110)
- The ROME + Cognichip approach is intellectually interesting and the S-box submodule EDA passes are legitimate evidence; however, the main AES block failed all verification attempts, leaving the primary claim unsubstantiated.

## Actionable Feedback (Most Important Improvements)
1. Debug the `aes_key_mem_sim` failures and obtain a passing EDA run for the top-level AES module.
2. Include a self-contained README with DEPS.yml rather than linking to an external repository.
3. Add quantitative comparison results (latency, accuracy) between Cognichip-ROME and iVerilog-ROME pipelines.

## Issues (If Any)
- `aes_key_mem_sim` failed in all 10 EDA attempts (return_code: 30); full AES functionality unverified.
- No `DEPS.yml` found in the submitted source directory.
- README links to external GitHub repo for results rather than including them in the submission.
