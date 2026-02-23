# RTL Auto-Fix Pipeline × Cognix (ACI)

Brief Description
RTL Auto-Fix Pipeline × Cognix (ACI) is an automated RTL verification and self-optimizing system that uses a three-stage verification pipeline (Verilator simulation → Yosys pre-synthesis → OpenSTA timing analysis). When any stage fails, it automatically generates AI-powered fix prompts for Cognix AI, applies the fixes automatically without human interactions, and re-runs the program pipeline until all checks pass and the RTL code is either fixed or improved w.r.t. constraints.

Automated RTL verification and self-optimizing loop:  
**Verilator simulation → Yosys pre-synthesis → OpenSTA timing → Cognix AI fix → repeat**

---

## Pipeline Overview

```
test/*.sv
    │
    ▼
┌─────────────┐    FAIL ──► Cognix prompt (sim + Yosys context)
│  Verilator  │                  │
│ Simulation  │                  ▼ (Apply) ──► re-run
└─────────────┘
    │ PASS
    ▼
┌─────────────┐    BLOCKING ──► Cognix prompt (Yosys-only fix)
│    Yosys    │                      │
│ Pre-Synth   │                      ▼ (Apply) ──► re-run
└─────────────┘
    │ CLEAN  (also emits gate-level netlist)
    ▼
┌─────────────┐    VIOLATIONS ──► Cognix prompt (timing-fix)
│   OpenSTA   │                        │
│ Timing STA  │                        ▼ (Apply) ──► re-run
└─────────────┘
    │ CLEAN
    ▼
✅  ALL CHECKS PASSED
    run_logs/<timestamp>/  ← full archive
```

---

## Quick Start

```bash
# 1. Put your RTL + TB in test/
ls test/
#   my_design.sv   my_design_tb.sv

# 2. Run the pipeline
python3 auto_fix_cognix.py

# 3. When a fix prompt appears, paste it in Cognix → Enter → Apply
#    The script watches for the file save and re-runs automatically.
```

---

## Installation

### Required

| Tool | Install |
|------|---------|
| Python 3.10+ | bundled on most systems |
| Verilator | `brew install verilator` / `apt install verilator` |

### onal (but recommended)

| Tool | Purpose | Install |
|------|---------|---------|
| Yosys | Gate-level pre-synthesis checks | `brew install yosys` / `apt install yosys` |
| OpenSTA | Static timing analysis | See below |

### Installing OpenSTA

**on A — automated build script (Linux/macOS):**
```bash
bash install_opensta.sh
```

**Option B — package manager:**
```bash
brew install opensta      # macOS Homebrew
guix install opensta      # Linux Guix
```

**Option C — manual build from source:**
```bash
git clone https://github.com/parallaxsw/OpenSTA.git
cd OpenSTA && mkdir build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local
make -j$(nproc)
sudo make install
# verify:
sta -version
```

> The OpenROAD project mirrors OpenSTA at:  
> https://github.com/The-OpenROAD-Project/OpenSTA

### Liberty file (required for OpenSTA)

The script **auto-downloads NanGate45** on first run and caches it at  
`~/.cache/rtl_autofix/nangate45.lib`.

To use your own PDK Liberty file:
```bash
export LIBERTY_PATH=/path/to/your_library.lib
# OR
python3 auto_fix_cognix.py --liberty /path/to/your_library.lib
```

---

## Usage

```
python3 auto_fix_cognix.py [OPTIONS]

Options:
  --top          <module>    Top module for simulation (auto-detected)
  --max          <N>         Max Cognix fix iterations (default: 5)
  --timeout      <sec>       Seconds to wait for Cognix Apply (default: 300)
  --clock-period <ns>        Target clock period for STA (default: 5.0 ns = 200 MHz)
  --clock-port   <port>      RTL clock port name (auto-detected via heuristic)
  --liberty      <path>      Liberty .lib file for OpenSTA
  --skip-yosys               Disable Yosys stage
  --skip-sta                 Disable OpenSTA stage
```

**Examples:**
```bash
# Basic run
python3 auto_fix_cognix.py

# Custom clock constraint (250 MHz target)
python3 auto_fix_cognix.py --clock-period 4.0

# Simulation only (skip synthesis and timing)
python3 auto_fix_cognix.py --skip-yosys --skip-sta

# Custom Liberty + explicit clock port
python3 auto_fix_cognix.py --liberty ~/pdk/sky130.lib --clock-port clk_i

# Custom top module
python3 auto_fix_cognix.py --top tb_my_design
```

---

## What Each Stage Does

### Verilator Simulation
- Compiles RTL + TB using `verilator --binary --timing --trace`
- Runs the compiled binary
- Passes if `TEST PASSED` appears in output with no `TEST FAILED`

### Yosys Pre-Synthesis
- Reads RTL-only (not TB) with `read_verilog -sv`
- Runs `hierarchy -check`, `proc`, `flatten`, `synth -noabc`, `check -assert`
- Flags blocking issues: latches, combinational loops, multiple drivers, errors
- Writes gate-level netlist `_sta_netlist_<top>.v` for OpenSTA

### OpenSTA Timing Analysis
- Reads the Yosys netlist + NanGate45 Liberty
- Creates clock constraint on detected clock port (or virtual clock)
- Reports WNS (Worst Negative Slack) and TNS (Total Negative Slack)
- Triggers Cognix fix if WNS < −0.1 ns (−100 ps threshold)
- Full path breakdown (startpoint → endpoint) included in the prompt

---

## Run Logs

Every successful run is archived to `run_logs/<YYYYMMDD_HHMMSS>/`:

```
run_logs/20250220_143022/
  summary.json           ← structured pass report
  verilator_output.txt   ← full Verilator stdout/stderr
  yosys_output.txt       ← full Yosys output (if ran)
  sta_output.txt         ← full OpenSTA output (if ran)
  dump.vcd               ← waveform (if TB uses $dumpfile)
  my_design.sv           ← final passing RTL
  my_design_tb.sv        ← final passing TB
```

Intermediate backups are saved to `ai_fix_backups/iter_NN/` before each fix attempt.

---

## Project Structure

```
RTL_Automation/
├── auto_fix_cognix.py      ← main pipeline script
├── install_opensta.sh      ← OpenSTA build helper
├── DEPS.yml                ← tool dependency manifest
├── README.md               ← this file
├── test/
│   ├── <your_rtl>.sv       ← RTL design under test
│   └── <your_tb>.sv        ← SystemVerilog testbench
├── Correct/                ← reference examples
│   ├── count.sv / count_tb.sv
│   └── ring_counter.sv / ring_counter_tb.sv
└── run_logs/               ← auto-created on success
```

---

## Timing Violation FAQ

**Q: OpenSTA reports violations but my design is simple — why?**  
A: The default clock period is 5 ns (200 MHz) with NanGate45 generic cells.  
Use `--clock-period` to relax the target, or `--skip-sta` to disable timing checks.

**Q: What does WNS mean?**  
A: Worst Negative Slack. A value of −0.5 ns means the critical path is 500 ps  
too slow for the target frequency. Zero or positive = timing met.

**Q: Can I use my own PDK?**  
A: Yes — point to your Liberty file with `--liberty` or `LIBERTY_PATH`.  
The netlist Yosys generates uses generic cells; for real PDK cells you'd  
need Yosys synthesis with your PDK's tech library (not covered here).

---
