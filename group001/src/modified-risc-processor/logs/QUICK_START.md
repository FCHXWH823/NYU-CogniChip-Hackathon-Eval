# E20 Processor - Quick Start Guide

## 🎯 Two Testbench Options Available!

You can use either:
- **Simple** (`tb_processor_simple.v`) - Pure Verilog, maximum compatibility
- **Comprehensive** (`tb_processor.v`) - Full features with SystemVerilog

---

## 🚀 Option 1: Simple Testbench (Recommended for beginners)

### Step 1: Compile
```bash
iverilog -o sim tb_processor_simple.v processor.v
```

### Step 2: Run a Test
```bash
./sim +program=test_simple.bin
```

---

## 🚀 Option 2: Comprehensive Testbench (More features)

### Step 1: Compile (with SystemVerilog flag)
```bash
iverilog -g2012 -o sim_full tb_processor.v processor.v
```

### Step 2: Run a Test
```bash
./sim_full +program=test_simple.bin
```

---

## 📝 Or Use the Scripts (Easiest!)

```bash
# Simple version
./run_simulation.sh test_simple.bin

# Comprehensive version  
./run_simulation_full.sh test_simple.bin
```

### Step 3: Compare with C++ Simulator
```bash
# Compile C++ simulator (if not already done)
g++ -o e20-sim e20-simulator.cpp

# Run comparison
./e20-sim test_simple.bin
./sim +program=test_simple.bin
```

## 📁 Files You Have

| File | What It Does |
|------|--------------|
| `processor.v` | **Enhanced E20 processor** (17 instructions + debug) |
| `tb_processor_simple.v` | **Simple testbench** (pure Verilog-2001) |
| `tb_processor.v` | **Comprehensive testbench** (SystemVerilog, more features) |
| `test_simple.bin` | Simple test: add two numbers |
| `test_array_sum.bin` | Array sum loop test |
| `test_new_instructions.bin` | Tests XOR, NOR, shifts |
| `run_simulation.sh` | **Simple testbench script** |
| `run_simulation_full.sh` | **Comprehensive testbench script** |
| `TESTBENCH_COMPARISON.md` | Detailed comparison of both testbenches |
| `TESTBENCH_README.md` | Complete documentation |
| `ENHANCEMENTS_SUMMARY.md` | What changed and why |

## ✨ What's New in Your Processor

### New Instructions (5 added):
- **XOR** - Bitwise exclusive OR
- **NOR** - Bitwise NOR  
- **SLL** - Shift left logical
- **SRL** - Shift right logical
- **SRA** - Shift right arithmetic

### Debug Features:
- `debug_pc` - See current program counter
- `debug_instr` - See current instruction
- `debug_cycle` - Count instruction cycles

### Total: **17 instructions** (up from 12)

## 🎯 Quick Commands

```bash
# SIMPLE TESTBENCH (pure Verilog)
./run_simulation.sh test_simple.bin
# Or manually:
iverilog -o sim tb_processor_simple.v processor.v
./sim +program=test_simple.bin

# COMPREHENSIVE TESTBENCH (SystemVerilog, more features)
./run_simulation_full.sh test_simple.bin
# Or manually:
iverilog -g2012 -o sim_full tb_processor.v processor.v
./sim_full +program=test_simple.bin

# With waveform dump (works with both)
./sim +program=test_simple.bin +vcd
./sim_full +program=test_simple.bin +vcd
gtkwave processor.vcd

# Compare with C++ simulator
diff <(./e20-sim test.bin) <(./sim +program=test.bin | grep -A 100 "Final state")
```

## 📊 Expected Output

When you run a test, you'll see:
```
Loading program: test_simple.bin
Program loaded successfully

[E20] Processor reset released, starting execution...
[E20] Processor halted at PC=0x0003 after 3 cycles

Final state:
    pc=    3
    $0=    0
    $1=    1
    $2=    2
    $3=    3
    $4=    0
    $5=    0
    $6=    0
    $7=    0
0002 0002 01b0 2003 0000 0000 0000 0000 
...

TEST PASSED - Processor halted normally after 3 cycles
```

## 🐛 Troubleshooting

**Problem**: `sim: command not found`
```bash
# Recompile:
iverilog -o sim tb_processor_simple.v processor.v
```

**Problem**: `test_simple.bin: No such file`
```bash
# Make sure test files are in same directory:
ls test_*.bin
```

**Problem**: Outputs don't match C++ simulator
```bash
# Enable detailed monitoring in tb_processor_simple.v
# Uncomment the always @(posedge clock) block near the end
```

## 📚 Read More

- **TESTBENCH_README.md** - Detailed usage guide
- **ENHANCEMENTS_SUMMARY.md** - All changes explained
- **E20_MODIFICATIONS.md** - Educational vs FPGA versions

## 💡 Try This Next

1. **Run all test programs:**
   ```bash
   for test in test_*.bin; do
       echo "Testing $test..."
       ./sim +program=$test
   done
   ```

2. **Create your own test program:**
   - Copy `test_simple.bin`
   - Edit the machine code
   - Run it!

3. **See execution step-by-step:**
   - Edit `tb_processor_simple.v`
   - Uncomment the monitor block (near end of file)
   - Watch each instruction execute

4. **View waveforms:**
   ```bash
   ./sim +program=test_simple.bin +vcd
   gtkwave processor.vcd
   ```

## ✅ You're All Set!

You now have a fully functional E20 processor with:
- ✅ 17 instructions (5 more than original)
- ✅ Debug outputs for monitoring
- ✅ Complete testbench
- ✅ Example programs
- ✅ Automated testing
- ✅ C++ simulator compatibility

**Have fun experimenting with your processor! 🎉**
