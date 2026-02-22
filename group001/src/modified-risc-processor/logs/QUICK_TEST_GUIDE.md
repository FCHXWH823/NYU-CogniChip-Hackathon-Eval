# Quick Test Guide - Pipelined Processor

## 🚀 Quick Start

### List All Available Tests
```bash
./list_tests.sh
```

### Run All Basic Tests
```bash
./run_pipelined_basic_tests.sh
```

### Run Single Test
```bash
./run_pipelined_test.sh test_simple.bin
./run_pipelined_test.sh basic-tests/array-sum.bin
```

## 📋 Available Test Scripts

| Script | Purpose | Usage |
|--------|---------|-------|
| `list_tests.sh` | Show all available tests | `./list_tests.sh` |
| `run_pipelined_basic_tests.sh` | Run all basic-tests | `./run_pipelined_basic_tests.sh` |
| `run_pipelined_test.sh` | Run single test | `./run_pipelined_test.sh <file.bin>` |

## 🧪 Test Categories

### Custom Tests (Root Directory)
- `test_simple.bin` - Basic arithmetic (✅ Verified: $1=1, $2=2, $3=3)
- `test_array_sum.bin` - Array summation (✅ Verified: Sum=37)
- `test_fibonacci.bin` - Fibonacci calculation (✅ Verified: Fib(8)=21)
- `test_new_instructions.bin` - XOR, NOR, shifts (✅ Verified)

### Basic Tests (basic-tests/)
- `array-sum.bin` - Array summation with terminator
- `loop1.bin` - Simple loop
- `loop2.bin` - Nested loops
- `loop3.bin` - Complex loops
- `math.bin` - Mathematical operations
- `subroutine1.bin` - Function calls
- `subroutine2.bin` - Nested functions
- `vars1.bin` - Variable manipulation

## 📊 Output Files

### After running `run_pipelined_basic_tests.sh`:
- `pipelined_test_results.txt` - Summary report
- `sim_pipelined_basic/` - Detailed simulation logs

### After running `run_pipelined_test.sh`:
- `sim_output/<test>_sim.log` - Simulation output
- `sim_output/<test>_compile.log` - Compilation output

## ✅ Expected Results

All tests should show:
```
[✓] test_name: PASSED
  Cycles: XXX
```

## 🔧 Prerequisites

Install Icarus Verilog:
```bash
# macOS
brew install icarus-verilog

# Ubuntu/Debian
sudo apt-get install iverilog
```

## 📖 Full Documentation

See `PIPELINED_TESTING.md` for comprehensive guide including:
- Detailed test descriptions
- Troubleshooting tips
- Performance comparisons
- Advanced usage
- Debugging techniques

## 🎉 Verification Status

**Pipelined Processor: FULLY VERIFIED** ✅

- ✅ All arithmetic operations working
- ✅ Memory operations (LW/SW) functional
- ✅ Control flow (jumps/branches) operational
- ✅ Data forwarding working correctly
- ✅ Hazard detection functional
- ✅ All 17 E20 instructions supported
