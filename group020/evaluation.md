# CogniChip Hackathon Evaluation Receipt — group020

## Submission Overview
- Team folder: `group020`
- Slides: `slides/smartcache_AIDrivenMemoryHierachyOptimization.pdf`
- Video: `video/smartcache_AIdriven memory hierarchi optimization.mp4`
- Code/Repo: `src/SmartCache-AIdriven-Memory-Hierarchy-Optimization/` — directory exists but is empty; no files committed.
- Evidence completeness: Minimal — slides and video only; no code, no simulation results.

## Score Summary
| Criterion | Score | Max |
|---|---:|---:|
| Technical Correctness | 0 | 30 |
| Cognichip Platform Usage | 0 | 20 |
| Innovation & Creativity | 8 | 15 |
| Clarity — Slides | 7 | 10 |
| Clarity — Video | 6 | 10 |
| Clarity — Repo Organization | 0 | 5 |
| Potential Real-World Impact | 7 | 10 |
| Bonus — FPGA/Tiny Tapeout | 0 | 10 |
| **Total** | **28** | **110** |

## Detailed Evaluation

### A) Technical Correctness (0/30)
- Strengths:
  - None — no code or simulation evidence submitted.
- Weaknesses / Missing evidence:
  - `src/SmartCache-AIdriven-Memory-Hierarchy-Optimization/` is an empty directory.
- Key evidence:
  - None.

### B) Effective Use of the Cognichip Platform (0/20)
- Strengths:
  - None.
- Weaknesses / Missing evidence:
  - No DEPS.yml, no EDA results, no platform interaction logs.
- Key evidence:
  - None.

### C) Innovation & Creativity (8/15)
- Strengths:
  - AI-driven cache hierarchy optimisation ("SmartCache") is a technically interesting direction, potentially combining adaptive replacement policies, ML-guided prefetching, or dynamic cache sizing.
  - Topic is directly relevant to memory system performance for AI workloads.
- Weaknesses:
  - Concept only; no implementation to assess the specific innovation.
- Key evidence:
  - (slides/smartcache_AIDrivenMemoryHierachyOptimization.pdf) — concept described

### D) Clarity of Presentation (13/25)
#### D1) Slides clarity (7/10)
- Notes: PDF slides submitted. Title and project name are well-chosen and descriptive.
- Evidence: (slides/smartcache_AIDrivenMemoryHierachyOptimization.pdf)

#### D2) Video clarity (6/10)
- Notes: Video present (note: filename has typos "hierarchi" and "AIdriven").
- Evidence: (video/smartcache_AIdriven memory hierarchi optimization.mp4)

#### D3) Repo Organization (0/5)
- Notes: `src/` is empty.
- Evidence: None.

### E) Potential Real-World Impact (7/10)
- Notes: AI-driven cache optimisation addresses memory bottlenecks in modern processors and AI accelerators — a high-value problem. Impact potential is strong if implemented.

### Bonus) FPGA / Tiny Tapeout Targeting (+0/10)
- Notes: No evidence.
- Evidence: None.

## Final Recommendation
- Overall verdict: **Very Poor** (28/110)
- The SmartCache concept is among the more commercially interesting ideas in the empty-src group, but no implementation was submitted.

## Actionable Feedback (Most Important Improvements)
1. Implement a basic RTL cache module (e.g., direct-mapped or set-associative cache) with a testbench.
2. Add AI-driven prefetch or replacement policy logic and compare with baseline.
3. Run `eda sim` with DEPS.yml and commit Cognichip EDA results.

## Issues (If Any)
- `src/SmartCache-AIdriven-Memory-Hierarchy-Optimization/` is an empty directory; no code submitted.
- Video filename contains typos ("hierarchi", "AIdriven" without space).
