# E20 Pipelined Processor - Testing Guide

This guide explains how to run tests on the pipelined processor implementation.

## Overview

The pipelined processor has been successfully verified with multiple test programs including:
- ✅ test_simple (arithmetic operations)
- ✅ test_array_sum (memory operations and loops)
- ✅ test_fibonacci (complex control flow)
- ✅ test_new_instructions (XOR, NOR, SLL, SRL, SRA)

## Test Scripts

### 1. Run All Basic Tests

**Script:** `run_pipelined_basic_tests.sh`

Runs all tests in the `basic-tests/` directory automatically.

```bash
./run_pipelined_basic_tests.sh
```

**Features:**
- Automatically runs all 8 basic tests
- Color-coded output (Pass/Fail)
- Detailed results saved to `pipelined_test_results.txt`
- Simulation logs saved to `sim_pipelined_basic/`
- Shows cycle counts for passed tests

**Basic Tests Included:**
1. `array-sum.bin` - Array summation with terminator
2. `loop1.bin` - Simple loop test
3. `loop2.bin` - Nested loop test
4. `loop3.bin` - Complex loop test
5. `math.bin` - Mathematical operations
6. `subroutine1.bin` - Function call test
7. `subroutine2.bin` - Nested function calls
8. `vars1.bin` - Variable manipulation

### 2. Run Single Test

**Script:** `run_pipelined_test.sh`

Runs a single test file with detailed output.

```bash
./run_pipelined_test.sh <test_file.bin>
```

**Examples:**
```bash
# Run a specific basic test
./run_pipelined_test.sh basic-tests/array-sum.bin

# Run custom test
./run_pipelined_test.sh test_fibonacci.bin
./run_pipelined_test.sh test_simple.bin
./run_pipelined_test.sh test_array_sum.bin
```

**Features:**
- Clean, focused output for single test
- Shows compilation and simulation steps
- Displays cycle count on success
- Logs saved to `sim_output/`

## Prerequisites

### Icarus Verilog Installation

**macOS:**
```bash
brew install icarus-verilog
```

**Ubuntu/Debian:**
```bash
sudo apt-get install iverilog
```

**Verification:**
```bash
iverilog -V
```

## Files Required

The test scripts expect these files in the current directory:
- `processor_pipelined.v` - Pipelined processor implementation
- `tb_processor_pipelined.v` - Testbench with file loading capability
- Test binary files (`.bin` format)

## Test Binary Format

Test files use this format:
```verilog
ram[0] = 16'b0010000010000001;
ram[1] = 16'b0010000100000010;
...
```

## Output Files

### run_pipelined_basic_tests.sh
- `pipelined_test_results.txt` - Summary of all test results
- `sim_pipelined_basic/` - Directory with detailed logs
  - `<test>_compile.log` - Compilation output
  - `<test>_sim.log` - Simulation output
  - `<test>.vvp` - Compiled simulation executable

### run_pipelined_test.sh
- `sim_output/<test>_compile.log` - Compilation output
- `sim_output/<test>_sim.log` - Simulation output  
- `sim_output/<test>.vvp` - Compiled simulation executable

## Interpreting Results

### Successful Test
```
[✓] array-sum: PASSED
  Cycles: 145
```

### Failed Test
```
[✗] loop1: FAILED
Error output:
...
```

### Test Summary
```
========================================
Test Summary
========================================
Total tests:   8
Passed:        7
Failed:        1
Skipped:       0
```

## Pipelined Processor Features

The pipelined processor includes:

### Pipeline Architecture
- **5 stages:** IF (Fetch), ID (Decode), EXEC (Execute), MEM (Memory), WB (Write Back)
- Pipeline registers between each stage
- Proper instruction propagation through pipeline

### Hazard Handling
1. **Data Hazards:**
   - Load-use stalling (1-cycle bubble insertion)
   - 3-stage forwarding (from EXEC, MEM, WB stages)
   - Automatic hazard detection

2. **Control Hazards:**
   - Pipeline flushing on jumps/branches
   - Jump target calculation
   - Branch resolution in EXEC stage

### Control Modules
- **CTLid:** Decode and stalling control
- **CTLexec1:** Execution and forwarding control
- **CTLexec2:** Jump and branch control
- **CTLmem:** Memory access control
- **CTLwb:** Write-back control

### Supported Instructions
All 17 E20 instructions:
- Arithmetic: ADD, SUB, ADDI, SLT, SLTI
- Logical: AND, OR, XOR, NOR
- Shift: SLL, SRL, SRA
- Memory: LW, SW
- Control: J, JAL, JR, JEQ

## Debugging Tips

### Compilation Errors
Check the compile log:
```bash
cat sim_pipelined_basic/<test>_compile.log
# or
cat sim_output/<test>_compile.log
```

### Runtime Errors
Check the simulation log:
```bash
cat sim_pipelined_basic/<test>_sim.log
# or
cat sim_output/<test>_sim.log
```

### View Waveforms
Waveforms are saved as `dumpfile.fst` (if generated). View with:
```bash
gtkwave dumpfile.fst
```

## Performance Comparison

The pipelined processor achieves better throughput than the single-cycle version:

| Feature | Single-Cycle | Pipelined |
|---------|--------------|-----------|
| CPI (ideal) | 1.0 | ~1.0 |
| Clock Speed | Lower | Higher |
| Throughput | 1 instr/cycle | ~1 instr/cycle (with stalls) |
| Latency | 1 cycle | 5 cycles |

## Troubleshooting

### Script Won't Run
```bash
chmod +x run_pipelined_basic_tests.sh
chmod +x run_pipelined_test.sh
```

### Iverilog Not Found
Install Icarus Verilog (see Prerequisites section)

### Test File Not Found
Ensure test files are in the correct location:
- Custom tests: Current directory
- Basic tests: `basic-tests/` subdirectory

### All Tests Timeout
Check MAX_CYCLES parameter in testbench:
```verilog
parameter MAX_CYCLES = 100000;
```

## Advanced Usage

### Modify Timeout
Edit `tb_processor_pipelined.v`:
```verilog
parameter MAX_CYCLES = 200000;  // Increase for longer tests
```

### Enable Waveform Dumping
Waveforms are automatically generated. To disable, comment out in testbench:
```verilog
// initial begin
//     $dumpfile("dumpfile.fst");
//     $dumpvars(0);
// end
```

### Custom Test Creation
Create a `.bin` file with your program:
```verilog
ram[0] = 16'b0010000010000101;  // addi $1, $0, 5
ram[1] = 16'b0010000100000011;  // addi $2, $0, 3
ram[2] = 16'b0000100111000000;  // add $3, $2, $1
ram[3] = 16'b0100000000000011;  // j 3 (halt)
```

Then run:
```bash
./run_pipelined_test.sh my_custom_test.bin
```

## Support

For issues or questions about the pipelined processor:
1. Check simulation logs in `sim_pipelined_basic/` or `sim_output/`
2. Review `pipelined_test_results.txt` for test summary
3. Examine processor state in simulation logs

## Verification Status

✅ **Pipelined Processor Verified**
- All arithmetic operations: PASS
- Memory operations (LW/SW): PASS  
- Control flow (jumps/branches): PASS
- Data forwarding: PASS
- Load-use hazard detection: PASS
- New instructions (XOR, NOR, shifts): PASS

The pipelined processor is production-ready! 🚀
