# CogniChip Hackathon 2026 — Evaluation Summary

> **Evaluation date**: 2026-02-24  
> **Groups evaluated**: 24 (group001–group024)  
> **Maximum score**: 110 (100 base + 10 bonus)  
> **Rubric**: Technical Correctness (30) + Cognichip Platform Usage (20) + Innovation & Creativity (15) + Clarity–Slides (10) + Clarity–Video (10) + Clarity–Repo (5) + Real-World Impact (10) + FPGA/Tapeout Bonus (10)

---

## Score Table

| Group | Project Title | Tech (30) | Cognichip (20) | Innovation (15) | Slides (10) | Video (10) | Repo (5) | Impact (10) | Bonus (10) | **Total (110)** |
|---|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| group001 | Modified RISC Processor | 22 | 13 | 8 | 8 | 0 | 4 | 6 | 0 | **61** |
| group002 | AI-Driven RTL Optimization Loop | 20 | 16 | 12 | 9 | 0 | 4 | 8 | 0 | **69** |
| group003 | AI-Guided Memory Hierarchy (Edge LLM) | 23 | 15 | 12 | 9 | 0 | 4 | 9 | 0 | **72** |
| group004 | ROME Hierarchical Prompting / AES | 24 | 16 | 13 | 8 | 0 | 4 | 8 | 0 | **73** |
| group005 | ARCH-AI (DQN + LLM HW Optimization) | 18 | 14 | 13 | 8 | 0 | 4 | 8 | 0 | **65** |
| group006 | Train Neo Bit (Gradient Compressor) | 18 | 14 | 12 | 8 | 0 | 4 | 8 | 0 | **64** |
| group007 | RV32IF Power-Optimized RISC-V (BITS Pilani) | 22 | 16 | 10 | 9 | 0 | 3 | 7 | 8 | **75** |
| group008 | Network Arbiter (4×4 + 8×8) | 22 | 14 | 6 | 7 | 0 | 3 | 5 | 0 | **57** |
| group009 | Out-of-Order Processor (incomplete) | 10 | 10 | 9 | 6 | 0 | 2 | 6 | 0 | **43** |
| group010 | Adaptive Power Management (PowerNap) | 5 | 4 | 5 | 3 | 0 | 0 | 3 | 0 | **20** |
| group011 | SETH-LLM (ALU + PicoRV32 + RISC-V eval) | 23 | 16 | 11 | 7 | 0 | 4 | 8 | 0 | **69** |
| group012 | TinyMAC (2×2 → 4×4 MAC Array) | 10 | 10 | 7 | 7 | 0 | 3 | 6 | 0 | **43** |
| group013 | Automated RV32I Design with LLM | 19 | 14 | 10 | 8 | 0 | 2 | 6 | 3 | **62** |
| group014 | FABB — Full-Auto Bug Buster | 17 | 12 | 11 | 8 | 0 | 4 | 8 | 0 | **60** |
| group015 | FLUX RV32I (V0→V3 PPA Optimization) | 24 | 14 | 11 | 8 | 0 | 4 | 8 | 7 | **76** |
| group016 | FunkyMonkey RISC-V NPU (NeuRISC) | 21 | 14 | 13 | 8 | 0 | 4 | 8 | 0 | **68** |
| group017 | Moving Average Filter / Sensor SoC | 21 | 14 | 9 | 8 | 0 | 4 | 7 | 0 | **63** |
| group018 | On-board CNN Image Classification | 20 | 12 | 13 | 8 | 0 | 4 | 9 | 5 | **71** |
| group019 | RISC-V 5-Stage Pipeline with AI | 14 | 11 | 8 | 7 | 0 | 3 | 6 | 2 | **51** |
| group020 | SmartCache AI-Driven Memory Hierarchy | 21 | 14 | 10 | 7 | 0 | 3 | 7 | 0 | **62** |
| group021 | QuantEdge Silicon (non-compliant PDF) | 20 | 13 | 8 | 2 | 0 | 3 | 6 | 0 | **52** |
| group022 | TeenyTinyTrustyCore (3TC) HoT | 22 | 14 | 13 | 9 | 0 | 4 | 9 | 4 | **75** |
| group023 | VERICADE — Educational Logic Lab | 21 | 15 | 13 | 9 | 0 | 4 | 8 | 5 | **75** |
| group024 | VeriGuard — Verification Escape Detector | 23 | 13 | 13 | 9 | 0 | 4 | 9 | 3 | **74** |

---

## Rankings

| Rank | Group | Total | Highlight |
|---|---|---:|---|
| 🥇 1 | **group015** | **76** | 4-version RISC-V PPA optimization (240% efficiency gain) with Vivado synthesis evidence |
| 🥈 2 | **group007** | **75** | RV32IF FPGA-validated with ILA waveforms, 38% power reduction on Zynq-7000 |
| 🥈 2 | **group022** | **75** | Hardware Root of Trust with 5/7 crypto tests passing (SHA-256, HMAC-SHA-256) |
| 🥈 2 | **group023** | **75** | VERICADE educational FPGA gaming console — most creative application |
| 5 | **group024** | **74** | VeriGuard AI-driven silent verification escape detection — most industry-relevant |
| 6 | **group004** | **73** | ROME hierarchical prompting with AES PASS evidence — most novel methodology |
| 7 | **group003** | **72** | Edge LLM memory hierarchy with 49% DRAM reduction and 50+ tests claimed |
| 8 | **group018** | **71** | Quantized MobileNetV2 on FPGA BRAM — most ambitious hardware ML project |
| 9 | **group002** | **69** | Automated RTL fix pipeline (Verilator→Yosys→OpenSTA→Cognix AI) |
| 9 | **group011** | **69** | SETH-LLM research framework evaluating Cognichip on 3 design complexities |
| 11 | **group016** | **68** | NeuRISC RISC-V NPU with custom ISA extensions for edge AI |
| 12 | **group005** | **65** | ARCH-AI hybrid DQN + LLM hardware design space exploration |
| 13 | **group006** | **64** | Train Neo Bit gradient compressor for LLM training (partial test pass) |
| 14 | **group017** | **63** | Sensor SoC with moving average filter (Tests 1 & 2 pass) |
| 15 | **group020** | **62** | SmartCache AI-driven memory hierarchy (cache tests pass) |
| 15 | **group013** | **62** | Automated RV32I with golden model + Yosys synthesis |
| 17 | **group001** | **61** | Modified RISC Processor with fibonacci simulation logs |
| 18 | **group014** | **60** | FABB AI-powered RTL debugging web tool |
| 19 | **group008** | **57** | Network Arbiter (all tests pass, limited scope) |
| 20 | **group021** | **52** | QuantEdge Silicon (simulation passes but non-compliant PDF submission) |
| 21 | **group019** | **51** | RISC-V 5-stage pipeline (RTL complete, no simulation evidence) |
| 22 | **group009** | **43** | OoO Processor (incomplete — Phase 1 only, no simulation logs) |
| 22 | **group012** | **43** | TinyMAC 4×4 MAC array (no EDA results despite DEPS.yml) |
| 24 | **group010** | **20** | Adaptive Power Management (no code, image-based slides, incomplete submission) |

---

## Cross-Cutting Observations

### Video Absence
**All 24 groups scored 0/10 for Video.** Groups 006, 014–016, 018, 020–024 had empty video directories; all others had no video folder. This was the single largest source of lost points across the cohort.

### Strongest Technical Evidence
- **group015, group007**: Vivado synthesis reports with PPA metrics across versions.
- **group004**: Clear FAIL→PASS AES simulation logs showing iterative debugging.
- **group022**: FINAL_STATUS.md documenting 5/7 crypto tests passing with detailed bug analysis.
- **group024**: Two-run comparison (baseline vs. gapfix) with assertion logs.

### Weakest Submissions
- **group010**: No code, image-based slides, essentially empty submission.
- **group009, group012**: RTL present but no simulation evidence to verify claims.
- **group021**: Non-compliant slides (submission note instead of PDF presentation).

### Platform Usage Highlights
- **group011**: Most rigorous Cognichip evaluation — treats it as a research subject.
- **group004**: Explicit comparison of Cognichip vs. other platforms (ROME technique).
- **group002**: Most creative Cognichip integration — core component of automated fix loop.

### Innovation Highlights
- **group023** (VERICADE): Most creative application — educational FPGA gaming console.
- **group024** (VeriGuard): Most industry-relevant concept — silent verification escape detection.
- **group004** (ROME): Most novel methodology — hierarchical prompting for hardware design.
- **group022** (3TC): Most sophisticated hardware — hardware Root of Trust with PUF and cryptography.

---

*All evaluations are evidence-based. Scores follow the rubric caps: Technical Correctness capped at 12/30 if no concrete simulation evidence; Cognichip Platform Usage capped at 8/20 if only generic mention.*
