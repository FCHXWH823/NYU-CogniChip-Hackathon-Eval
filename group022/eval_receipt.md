# CogniChip Hackathon Evaluation Receipt — TeenyTinyTrustyCore (3TC) — Hardware Root of Trust

## Submission Overview
- Team folder: `group022`
- Slides: `slides/TeenyTinyTrustyCore (3TC).pdf`
- Video: `video/` (directory exists with files)
- Code/Repo: `src/teenytinytrustycore/` — two approaches to Hardware Root of Trust using CogniChip
- Evidence completeness: Good — FINAL_STATUS.md shows 5/7 tests passing (SHA-256 100%, HMAC 100%, AES fails); CRYPTO_TEST_RESULTS.md documents specific failure modes; waveforms referenced; clear documentation of what works and what doesn't.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 22 | 30 |
| Cognichip Platform Usage | 17 | 20 |
| Innovation & Creativity | 13 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 7 | 10 |
| Clarity — Repo Organization | 4 | 5 |
| Potential Real-World Impact | 9 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **79** | **110** |

## Detailed Evaluation

### A) Technical Correctness (22/30)
- Strengths:
  - FINAL_STATUS.md: 5/7 tests PASS (71% pass rate) — SHA-256 (3/3 PASS ✅), HMAC-SHA-256 (2/2 PASS ✅), AES-CTR (0/2 FAIL).
  - CRYPTO_TEST_RESULTS.md (approach1) documents initial results: 3/7 PASS, 4/7 FAIL with specific failure modes (HMAC timeout, AES bypass/counter reset issues).
  - Comparison of approach1 vs approach2 shows iterative improvement (HMAC fixed in approach2).
  - Specific bug fixes documented: 3 critical timing bugs in top-level, 1 in KDF, 1 in HMAC module.
  - PUF enrollment sequence, Key Derivation Function, SHA-256, and HMAC modules all verified.
  - Approach2 SIMULATION_RESULTS.md documents additional verification passes.
- Weaknesses / Missing evidence:
  - AES-CTR module remains broken — encryption bypass and counter reset issues unresolved.
  - Initial CRYPTO_TEST_RESULTS shows 3/7 (43%) pass rate; final is 5/7 (71%); AES still incomplete.
- Key evidence:
  - (src/teenytinytrustycore/approach1/FINAL_STATUS.md — 5/7 results)
  - (src/teenytinytrustycore/approach1/CRYPTO_TEST_RESULTS.md — failure mode analysis)
  - (src/teenytinytrustycore/approach2/SIMULATION_RESULTS.md)

### B) Effective Use of the Cognichip Platform (17/20)
- Strengths:
  - README states the entire project was "designed solely using CogniChip."
  - Two approaches (approach1 and approach2) demonstrate iterative platform engagement — approach2 was a fresh attempt to fix approach1's issues.
  - Specific debugging collaboration with "Cognichip AI Co-Designer" documented in FINAL_STATUS.md.
  - Bug fixes across 5 modules documented as Cognichip-assisted iterations.
- Weaknesses / Missing evidence:
  - No explicit prompt log; AI Co-Designer role described narratively but not documented in detail.
- Key evidence:
  - (src/teenytinytrustycore/README.md — "designed solely using CogniChip")
  - (src/teenytinytrustycore/approach1/FINAL_STATUS.md — "Cognichip AI Co-Designer" mention)

### C) Innovation & Creativity (13/15)
- Strengths:
  - Hardware Root of Trust with PUF, KDF, SHA-256, HMAC-SHA-256, and AES-CTR is one of the most ambitious security-focused designs in the hackathon.
  - Two-attempt approach (approach1 and approach2) demonstrates intellectual honesty and persistent problem-solving.
  - PUF + KDF for device unique secret derivation is a production-grade security architecture.
- Weaknesses:
  - AES-CTR implementation remains incomplete, reducing the overall security chain.
- Key evidence:
  - (src/teenytinytrustycore/README.md — schematic description, 3TC-schematic.png)

### D) Clarity of Presentation (18/25)
#### D1) Slides clarity (7/10)
- Notes: PDF exists; cannot verify content directly, but reasonable base score awarded.
- Evidence: `slides/TeenyTinyTrustyCore (3TC).pdf`

#### D2) Video clarity (7/10)
- Notes: Video directory exists with files.
- Evidence: `video/` directory with contents.

#### D3) Repo organization (4/5)
- Notes: Clear two-approach structure with FINAL_STATUS.md, CRYPTO_TEST_RESULTS.md, SIMULATION_RESULTS.md in each approach. Architecture schematic image committed. UVM verification in approach2. README is concise and links to relevant files.
- Evidence: (src/teenytinytrustycore/ directory structure)

### E) Potential Real-World Impact (9/10)
- Notes: Hardware Root of Trust is a critical security component for IoT, secure boot, key storage, and attestation. SHA-256 and HMAC working at 100% with a functional PUF+KDF chain represents a usable security foundation. AES-CTR completion would make it production-relevant.
- Evidence: FINAL_STATUS.md — "Production-Ready" SHA-256 and HMAC modules

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No FPGA or Tiny Tapeout targeting steps documented.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Strong submission**
- 3TC demonstrates an ambitious security-focused design with transparent reporting of both successes and failures. The two-approach iteration driven entirely by Cognichip is a strong demonstration of platform usage. AES-CTR completion and FPGA targeting would make this an exceptional submission.

## Actionable Feedback (Most Important Improvements)
1. Debug and fix the AES-CTR module (counter reset issue and encryption bypass) to complete the full security chain — the failure mode is clearly documented and should be fixable.
2. Target Tiny Tapeout for silicon fabrication (3TC is exactly the right scale and application for TT).
3. Document the Cognichip prompt history for both approaches to create a comprehensive AI-assisted security design case study.

## Issues (If Any)
- AES-CTR bug: "Encryption appears to be bypassed (ciphertext = plaintext)" — suggests the AES key schedule or CTR mode logic has a fundamental issue that needs investigation.
