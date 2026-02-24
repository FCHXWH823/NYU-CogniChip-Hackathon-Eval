# CogniChip Hackathon Evaluation Receipt — group004

## Submission Overview
- Team folder: `group004`
- Slides: `slides/Andre Nakkab Cognichip Hackathon.pdf`
- Video: None
- Code/Repo: `src/cognichip-hackathon/` (36 files; AES key memory RTL, simulation results with EDA JSON files showing iterative PASS progression)
- Evidence completeness: Strong — simulation logs show clear FAIL→PASS iteration for AES key memory; quantitative pass rate comparisons shown in slides.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 24 | 30 |
| Cognichip Platform Usage | 16 | 20 |
| Innovation & Creativity | 13 | 15 |
| Clarity — Slides | 8 | 10 |
| Clarity — Video | 0 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 8 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **73** | **110** |

## Detailed Evaluation

### A) Technical Correctness (24/30)
- Strengths:
  - EDA simulation logs clearly show iterative FAIL → PASS for AES-128 key memory: initial run failed (`round_key[1]` mismatch), subsequent runs all PASS (`"*** Test case 1 completed successfully"`).
  - Three `eda_results.json` files document the iteration process.
  - AES-128 key expansion is a cryptographically meaningful and non-trivial design.
  - Round-key validation against known values confirms functional correctness.
- Weaknesses / Missing evidence:
  - Only AES key memory module tested; full AES block cipher simulation not confirmed in accessible logs.
  - Slides mention 128-bit + 256-bit combined AES at pass rate 0.4 — incomplete completion.
  - No formal testbench coverage metrics.
- Key evidence:
  - (src/cognichip-hackathon/aes/simulation_results/sim_2026-02-21T01-04-16-338Z/eda_results.json — `round_key[1]: PASS`, `*** Test case 1 completed successfully`)
  - (src/cognichip-hackathon/aes/simulation_results/sim_2026-02-21T00-59-07-112Z/eda_results.json — initial `round_key[1]` FAIL)
  - (slides/Andre Nakkab Cognichip Hackathon.pdf p.7 — pass rate table: all 0.8–1.0 for ROME+Cognichip)

### B) Effective Use of the Cognichip Platform (16/20)
- Strengths:
  - Cognichip is the primary evaluation platform for the ROME technique — used as the target simulation environment.
  - Specific comparison table of ROME+iVerilog+GPT-5.2 vs. ROME+Cognichip shows Cognichip used for rigorous benchmarking.
  - EDA results confirm Cognichip simulation tool was used (version 0.3.10 logged).
  - Acknowledges Cognichip's built-in simulator as a strength: "great built-in simulator that LLM can consistently execute."
  - Identifies platform limitations: daily message limits, connectivity issues.
- Weaknesses / Missing evidence:
  - The main innovation (ROME technique) is tool-agnostic; Cognichip is one of several tested platforms.
  - No deep description of Cognichip-specific workflow steps beyond using it as an LLM+simulator.
- Key evidence:
  - (slides/Andre Nakkab Cognichip Hackathon.pdf p.7 — comparison table ROME w/ Cognichip)
  - (slides/Andre Nakkab Cognichip Hackathon.pdf p.9 — pros/cons of Cognichip platform)

### C) Innovation & Creativity (13/15)
- Strengths:
  - ROME (hierarchical prompting technique) is a genuinely novel research contribution applicable to hardware design.
  - Two modes: Human-Driven Hierarchical Prompting (HDHP) and Purely-Generative Hierarchical Prompting (PGHP).
  - Mirrors how human engineers decompose designs into submodules — bridges the gap between LLM "flat prompting" and real-world design hierarchy.
  - Applied to non-trivial designs: 64-to-1 MUX, AES-128, AES-256.
- Weaknesses:
  - AES-256 implementation was only partially completed (daily message limit hit).
  - The technique itself is the innovation; the hardware outputs are conventional.
- Key evidence:
  - (slides/Andre Nakkab Cognichip Hackathon.pdf p.4 — "But How Do Humans Code?" → hierarchical decomposition)
  - (slides/Andre Nakkab Cognichip Hackathon.pdf p.5–6 — ROME pipeline diagram and two modes)

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (8/10)
- Notes: Clear narrative structure — problem → solution → methodology → results → conclusions. Comparison tables are informative. Good use of before/after examples (flat vs. hierarchical prompting). 11 slides, well-paced.
- Evidence: (slides/Andre Nakkab Cognichip Hackathon.pdf — 11 slides)

#### D2) Video clarity (0/10)
- Notes: No video submitted.
- Evidence: No video directory.

#### D3) Repo organization (4/5)
- Notes: Well-organized with simulation_results directories and EDA JSON files. README present. GitHub link shared.
- Evidence: (src/cognichip-hackathon/aes/simulation_results/ — three timestamped runs)

### E) Potential Real-World Impact (8/10)
- Notes: ROME technique is immediately applicable to any LLM-assisted hardware design workflow. Hierarchical prompting could meaningfully improve LLM output quality for complex RTL designs, reducing manual iteration. AES implementation has direct security relevance.
- Evidence: (slides/Andre Nakkab Cognichip Hackathon.pdf p.10 — "Hierarchical prompting serves as a great force-multiplier")

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA or tapeout evidence. Not mentioned in project scope.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Strong submission with a novel research contribution**
- The ROME hierarchical prompting technique is a substantive innovation with direct applicability to LLM-assisted chip design. AES simulation evidence is solid (clear FAIL→PASS iteration). The work is limited by a single-person team scope and incomplete AES-256 implementation, but the methodology is sound and well-presented.

## Actionable Feedback (Most Important Improvements)
1. Complete AES-256 implementation and include in simulation evidence.
2. Add a video demonstration showing ROME in action with Cognichip.
3. Formalize and publish the ROME framework as a reusable tool/library.

## Issues (If Any)
- No video submitted.
- AES-256 incomplete (daily message limit reached during hackathon).
