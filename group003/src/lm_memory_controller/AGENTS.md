# `lm_memeory_controller`

## Aim

In this project, we plan to design from scratch lm_memory_controller, a synthesizable and parameterizable memory-subsystem IP optimized for edge LLM inference. On edge SoCs, LLM inference is predominantly memory-bound: model weights, activations, and KV-cache must frequently move between limited on-chip SRAM and off-chip DRAM. We target a representative edge SoC configuration with 2 MB on-chip SRAM (4 × 512 KB banks) and 50 GB/s LPDDR5 DRAM, running quantized (INT4/INT8) billion-parameter Transformer models.

In addition to designing a fully functioning controller with four modules — Tile Scheduler, SRAM Bank Arbiter, DRAM Prefetch Engine, and Config Registers — our innovation will use AI-powered design to explore the tiling and buffer allocation problem, a key challenge for edge LLM inference. We will explore different tiling strategies, bank allocation policies, and prefetch depths with an aim to minimize DRAM access count and compute-unit idle cycles while constraining SRAM area — which are competing metrics. The controller is fully parameterizable, adapting to any model's layer count, hidden dimensions, GQA head configuration, and context length through its Config Register interface.

We will use Cognichip ACI to generate different microarchitectural configurations and evaluate them under varying tile sizes and buffer assignments, resulting in a Pareto frontier of DRAM bandwidth vs. compute utilization vs. SRAM area. Through conversation with ACI, we will implement these designs in SystemVerilog and generate testbench environments that replay realistic Transformer GEMM traffic patterns (attention projection, FFN up/down/gate layers).

For validation, we compare against a naive single-buffer, no-prefetch baseline across three metrics: DRAM access reduction (%), compute utilization (idle-cycle ratio), and per-layer cycle count, cross-checked against an analytical model. As a stretch goal, we will extend the controller to support dynamic per-layer reconfiguration — adapting tiling strategy on the fly, since attention and FFN layers have fundamentally different memory access patterns.

Final deliverables include architectural diagrams, RTL modules, performance tradeoff plots, and a live or recorded simulation demo demonstrating reduced DRAM traffic and improved compute utilization.

## Notes

1. For python code, use `uv` to run all related commands. For example, use `uv run app.py` instead of `python app.py`, and `uv add package_name` instead of `pip install package_name`.
