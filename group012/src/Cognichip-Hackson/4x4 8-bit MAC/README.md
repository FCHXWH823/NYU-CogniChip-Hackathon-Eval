# 4×4 MAC Accelerator Design Project

## Project Overview

This project implements a 4×4 MAC (Multiply-Accumulate) array hardware accelerator using SystemVerilog. Compared to the 2×2 version, this design supports internal matrix buffering, FSM-controlled N-cycle accumulation, and register-mapped output readback.

MAC units are fundamental building blocks in digital signal processing and AI accelerators, especially for matrix multiplication and neural network inference engines.

---

## Design Architecture

The design follows a **hierarchical and modular architecture**.

### 1. Basic MAC Unit (`mac_unit`)

- Accepts two signed 8-bit inputs (`a` and `b`)
- Computes signed multiplication (8×8 → 16-bit)
- Accumulates into a signed 32-bit accumulator
- Performs sign extension before accumulation
- Fully synthesizable combinational MAC block
Precision path: 
int8 × int8 → 16-bit product → 32-bit accumulation

### 2. Controller FSM (`controller_fsm`)

- Controls N-cycle accumulation
- Generates `k_index` (0 to 3)
- Implements state transitions: 
IDLE → LOAD → CLEAR → SETUP → COMPUTE → DONE
- Ensures correct k-loop sequencing
- Asserts `done` and `out_valid` after computation completes

---

### 3. Top-Level Array (`mac_array_4x4`)

- 4×4 grid structure containing **16 parallel MAC units**
- Internal A and B register buffers
- 32-bit accumulator matrix `C_acc[4][4]`
- Register-mapped load and readout interface
- Controlled by the FSM for N-cycle matrix multiplication

Internal storage:

A_buf[4][4] – signed int8

B_buf[4][4] – signed int8

C_acc[4][4] – signed int32

Each compute cycle:

- A fixed `k_index` is selected
- A[:,k] and B[k,:] are broadcast into the array
- 16 MAC units compute in parallel
- Accumulation updates `C_acc`
Total computation requires **N = 4 cycles**, with **16 MAC operations per cycle**.

---

## File Description

### 1. `mac_unit.sv` (RTL Design)

- Implements signed multiply-accumulate logic
- Performs sign-extended accumulation
- Fully synthesizable

### 2. `controller_fsm.sv`

- Implements N-cycle control sequencing
- Manages `k_index`
- Controls computation flow and completion signaling

### 3. `mac_array_4x4.sv`

- Top-level 4×4 accelerator module
- Contains internal A/B buffers
- Instantiates 16 MAC units
- Fully synthesizable and simulation-verified

### 4. `tb_mac_array_4x4.sv` (Testbench)

A complete self-checking SystemVerilog testbench with 10 comprehensive test cases:

1. All zeros  
2. Identity × random  
3. Maximum positive values  
4. Maximum negative values  
5. Mixed sign patterns  
6–10. Random matrix regression tests  

The testbench includes:

- Golden reference matrix multiplication model
- Per-element comparison (16 outputs)
- Automatic PASS/FAIL summary
- Waveform dump generation
- Simulation timeout watchdog

### 5. `DEPS.yml`

Defines design and test dependencies for compilation and simulation.

### 6. `README.md`

Project documentation (this file).

---

## Key Features

✅ **Parallel Computation** – 16 MAC units operate simultaneously (16 MACs per cycle)  
✅ **N-Cycle Accumulation** – One k-iteration per cycle  
✅ **Internal Matrix Buffers** – On-chip A and B storage  
✅ **Register-Mapped Readout** – Output accessed via `out_addr`  
✅ **Signed Arithmetic** – int8 inputs with int32 accumulation  
✅ **Scalable Architecture** – Easily extendable to larger arrays  

---

## Verification Results

✓ 5 directed tests passed  
✓ 5 random regression tests passed  
✓ Total mismatches: 0  
✓ Automatic PASS/FAIL reporting  
✓ Waveform (VCD) file generated  

---

## Typical Application Scenarios

- **Matrix multiplication acceleration**
- **Neural network inference engines**
- **Digital signal processing (FIR/IIR filters)**
- **Hardware accelerator prototyping**

---

## Interface Specification

### Input Signals

- `clock` – System clock  
- `reset_n` – Asynchronous reset (active low)  
- `load_A` – Write enable for A buffer  
- `a_addr[3:0]` – Linear address (0–15)  
- `a_wdata[7:0]` – Signed int8 data  
- `load_B` – Write enable for B buffer  
- `b_addr[3:0]` – Linear address (0–15)  
- `b_wdata[7:0]` – Signed int8 data  
- `start` – Start computation  

### Output Signals

- `done` – Computation complete  
- `out_valid` – Output valid flag  
- `out_addr[3:0]` – Read address  
- `out_rdata[31:0]` – Signed int32 accumulator result  

Where i, j ∈ {0, 1, 2, 3}.

Address mapping:

addr = i * 4 + j

row = addr[3:2]

col = addr[1:0]


---

## Parameter Configuration

```systemverilog
parameter int N      = 4;   // Matrix dimension
parameter int DATA_W = 8;   // Signed input width
parameter int MUL_W  = 16;  // Multiplier width
parameter int ACC_W  = 32;  // Accumulator width
