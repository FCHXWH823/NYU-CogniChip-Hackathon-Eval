# 2×2 MAC Array Design Project

## Project Overview

This project implements a 2×2 MAC (Multiply-Accumulate) array hardware accelerator using SystemVerilog. MAC units are fundamental building blocks in digital signal processing and AI accelerators.

## What is a MAC?

A MAC performs the following operation:

**accumulator = accumulator + (A × B)**

This operation is the foundation of matrix multiplication, convolutional neural networks, digital filters (FIR/IIR), and many signal processing pipelines. A single MAC unit completes one multiplication and one addition per clock cycle, significantly improving computational throughput.

## Design Architecture

The design follows a **hierarchical and modular architecture**.

### 1. Basic MAC Unit (`mac_unit`)

- Accepts two 8-bit inputs (`a` and `b`)
- Computes multiplication and accumulates into a 20-bit accumulator
- 20-bit accumulator prevents overflow during repeated accumulation
- Supports independent `enable` and `clear` control signals

### 2. Top-Level Array (`mac_array_2x2`)

- 2×2 grid structure containing 4 parallel MAC units
- All MACs share clock, reset, and global enable
- Each MAC has independent input channels and independent accumulator output

Architecture Diagram:

┌─────────────────────────────────┐
│        MAC Array 2x2           │
│  ┌──────────┐   ┌──────────┐   │
│  │ MAC[0,0] │   │ MAC[0,1] │   │
│  │  8x8→20  │   │  8x8→20  │   │
│  └──────────┘   └──────────┘   │
│                                 │
│  ┌──────────┐   ┌──────────┐   │
│  │ MAC[1,0] │   │ MAC[1,1] │   │
│  │  8x8→20  │   │  8x8→20  │   │
│  └──────────┘   └──────────┘   │
└─────────────────────────────────┘

## File Description

### 1. `mac_array_2x2.sv` (RTL Design)

- Contains `mac_unit` module (single MAC)
- Contains `mac_array_2x2` module (top-level 2×2 array)
- Fully synthesizable and simulation-verified

### 2. `tb_mac_array_2x2.sv` (Testbench)

A complete SystemVerilog testbench with 9 comprehensive test cases:

1. Post-reset verification  
2. Single MAC[0][0] operation  
3. Accumulation functionality validation  
4. All MAC units working in parallel  
5. Second accumulation round verification  
6. Clear all accumulators  
7. Re-accumulate after clear  
8. No accumulation when `enable = 0`  
9. Large value test (255 × 255)

### 3. `DEPS.yml` (Dependency File)

Defines design and test dependencies for compilation and simulation.

### 4. `README.md`

Project documentation (this file).

## Key Features

✅ **Parallel Computation** – 4 MAC units operate simultaneously (4 MACs per cycle)  
✅ **Flexible Control** – Global enable signal pauses accumulation  
✅ **Fast Reset** – Single signal clears all accumulators  
✅ **Overflow Protection** – 20-bit accumulator supports 1000+ accumulations safely  
✅ **Scalable Architecture** – Easily extendable to 4×4 or 8×8 arrays  

## Verification Results

✓ All 9 test cases passed  
✓ Compiles with no warnings or errors  
✓ Simulation time: 140 ps  
✓ Waveform file generated  

## Typical Application Scenarios

- **Matrix multiplication acceleration**
- **Neural network inference engines**
- **Digital signal processing (FIR/IIR filters)**
- **Image processing convolution operations**

## Interface Specification

### Input Signals

- `clock` – System clock  
- `reset` – Asynchronous reset (active high)  
- `enable` – Global enable for accumulation  
- `clear_all` – Clears all accumulators  
- `a_ij[7:0]` – First operand for MAC[i][j]  
- `b_ij[7:0]` – Second operand for MAC[i][j]  

### Output Signals

- `acc_ij[19:0]` – Accumulator output for MAC[i][j]  

Where i, j ∈ {0, 1}.

## Parameter Configuration

```systemverilog
parameter DATA_WIDTH = 8;   // Input data width
parameter ACC_WIDTH  = 20;  // Accumulator width
```
### Demo link
https://youtu.be/02nDIMiR23w
