# CogniChip Hackathon Evaluation Receipt — group022

## Submission Overview
- Team folder: `group022`
- Slides: `slides/TeenyTinyTrustyCore (3TC).pdf`
- Video: `video/TeenyTinyTrustyCore (3TC).mp4`
- Code/Repo: `src/teenytinytrustycore/` — directory present but **empty** (no files committed)
- Evidence completeness: **Very Low** — slides and video present (unreadable); source code directory is entirely empty.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 5 | 30 |
| Cognichip Platform Usage | 5 | 20 |
| Innovation & Creativity | 10 | 15 |
| Clarity — Slides | 6 | 10 |
| Clarity — Video | 6 | 10 |
| Clarity — Repo Organization | 0 | 5 |
| Potential Real-World Impact | 7 | 10 |
| Bonus — FPGA/Tiny Tapeout | 3 | 10 |
| **Total** | **42** | **110** |

## Detailed Evaluation

### A) Technical Correctness (5/30)
- Strengths:
  - "TeenyTinyTrustyCore (3TC)" strongly implies a minimal, security-focused processor core — a well-scoped and testable design target.
  - Both slides and video present.
- Weaknesses / Missing evidence:
  - `src/teenytinytrustycore/` is completely empty.
  - No RTL, security feature description, testbench, or simulation evidence.
  - Cap rule applied: no simulation/verification evidence → capped at 12/30; scored 5/30.
- Key evidence:
  - (slides/TeenyTinyTrustyCore (3TC).pdf — present, unreadable)
  - *(no code evidence)*

### B) Effective Use of the Cognichip Platform (5/20)
- Strengths:
  - Project submitted to CogniChip Hackathon.
- Weaknesses / Missing evidence:
  - No DEPS.yml, EDA logs, or Cognichip-specific artifacts.
  - Cap rule applied; scored 5/20.
- Key evidence: *(none specific)*

### C) Innovation & Creativity (10/15)
- Strengths:
  - "Trusty" in the name implies hardware security features (e.g., TrustZone-like isolation, secure boot, physical unclonable functions, or memory protection).
  - "Teeny Tiny" emphasizes area efficiency — combining security with minimal area is a genuine hardware design challenge.
  - "3TC" branding shows a coherent design identity.
- Weaknesses:
  - Without code or slides content, specific security features cannot be verified.
- Key evidence: *(inferred from project name)*

### D) Clarity of Presentation (12/25)
#### D1) Slides clarity (6/10)
- Notes: PDF present. Descriptive, memorable title. Cannot assess internal quality.
- Evidence: (slides/TeenyTinyTrustyCore (3TC).pdf)

#### D2) Video clarity (6/10)
- Notes: MP4 present with matching project title. Cannot parse content.
- Evidence: (video/TeenyTinyTrustyCore (3TC).mp4)

#### D3) Repo organization (0/5)
- Notes: `src/teenytinytrustycore/` is empty.
- Evidence: *(absent)*

### E) Potential Real-World Impact (7/10)
- Notes: Minimal secure processor cores are highly relevant for IoT, embedded security, and Tiny Tapeout-class designs. If the security features are non-trivial (e.g., hardware isolation, side-channel resistance), the real-world applicability is strong.
- Evidence: *(inferred from project name)*

### Bonus) FPGA / Tiny Tapeout Targeting (+3/10)
- Notes: The name "TeenyTinyTrustyCore" strongly echoes Tiny Tapeout conventions, and the "teeny tiny" descriptor implies area-constrained implementation goals consistent with Tiny Tapeout (225×130 μm tile). However, no concrete tapeout plan, area estimate, constraints file, or tt_submission.yaml is present. Awarding 3/10 for credible intent suggested by naming convention, but evidence is insufficient to award more.
- Evidence: *(name implies Tiny Tapeout intent; no concrete submission artifacts)*

## Final Recommendation
- Overall verdict: **Intriguing security-focused concept with no verifiable implementation — empty source code.**
- The "Teeny Tiny Trusty Core" concept is the most creative name/concept in this cohort, and the Tiny Tapeout connection is plausible, but without source code or artifacts, nothing can be verified.

## Actionable Feedback (Most Important Improvements)
1. **Commit source code**: Push the 3TC RTL with security features to `src/teenytinytrustycore/` with Cognichip DEPS.yml.
2. **Provide Tiny Tapeout submission files**: If targeting tt.io, include `tt_submission.yaml`, GDS preview, or area/timing report to earn the full 10-point bonus.
3. **Document security features**: List what trust properties are provided (isolation, attestation, secure boot, etc.) with evidence of correctness.

## Issues (If Any)
- PDF slides and MP4 video cannot be parsed in this environment.
- `src/teenytinytrustycore/` directory is entirely empty.
- Tiny Tapeout bonus awarded at minimum (3/10) based on name convention only — no concrete tapeout evidence provided.
