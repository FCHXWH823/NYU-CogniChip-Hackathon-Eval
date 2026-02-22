j# E20 Processor Testbench Guide

This guide explains how to use the E20 processor testbench to verify your design against the C++ simulator.

## Files Overview

| File | Description |
|------|-------------|
| `processor.v` | Enhanced E20 processor with debug outputs |
| `tb_processor.v` | Comprehensive testbench |
| `test_simple.bin` | Simple test program (add and halt) |
| `test_array_sum.bin` | Array summation program |
| `e20-simulator.cpp` | Reference C++ simulator |

## Quick Start

### 1. Compile the Testbench

Using Icarus Verilog:
```bash
iverilog -o sim tb_processor.v processor.v
```

Using other simulators:
```bash
# Verilator
verilator --cc --exe --build tb_processor.v processor.v

# ModelSim/QuestaSim
vlog processor.v tb_processor.v
vsim -c tb_processor -do "run -all; quit"

# VCS
vcs -full64 processor.v tb_processor.v
./simv
```

### 2. Run a Test Program

```bash
# Run with default program (program.bin)
./sim

# Run with specific program
./sim +program=test_simple.bin

# Run with waveform dump
./sim +program=test_simple.bin +vcd

# View waveform (if VCD enabled)
gtkwave processor.vcd
```

### 3. Compare with C++ Simulator

```bash
# Compile C++ simulator
g++ -o e20-sim e20-simulator.cpp

# Run both simulators on same program
./e20-sim test_simple.bin > cpp_output.txt
./sim +program=test_simple.bin > verilog_output.txt

# Compare outputs
diff cpp_output.txt verilog_output.txt
```

## New Instructions Added

The enhanced processor now supports **17 instructions** (up from 12):

### Original Instructions
- **ADD, SUB, OR, AND, SLT, JR** - Three-register operations
- **ADDI** - Add immediate
- **LW, SW** - Load/store word
- **JEQ** - Jump if equal
- **SLTI** - Set less than immediate
- **J, JAL** - Jump and jump-and-link

### New Instructions
- **XOR** (func=0101) - Bitwise XOR: `$rd = $rs ^ $rt`
- **NOR** (func=0110) - Bitwise NOR: `$rd = ~($rs | $rt)`
- **SLL** (func=1001) - Shift left logical: `$rd = $rs << $rt[3:0]`
- **SRL** (func=1010) - Shift right logical: `$rd = $rs >> $rt[3:0]`
- **SRA** (func=1011) - Shift right arithmetic: `$rd = $rs >>> $rt[3:0]`

### Instruction Format Reminder

```
THREE_REG:  | 000 | regA[12:10] | regB[9:7] | regDst[6:4] | func[3:0] |
TWO_REG:    | opc[15:13] | regSrc[12:10] | regDst[9:7] | imm7[6:0] |
JUMP:       | opc[15:13] | imm13[12:0] |
```

## Debug Features

### 1. Debug Outputs

The processor exposes three debug signals:
- `debug_pc` - Current program counter value
- `debug_instr` - Current instruction being executed
- `debug_cycle` - Total instruction cycles executed

### 2. Monitor Execution

Uncomment the monitor block in `tb_processor.v` to see instruction-by-instruction execution:

```verilog
always @(posedge clock) begin
    if (!reset && !halt) begin
        $display("[%0d] PC=0x%04h  INSTR=0x%04h  $1=0x%04h  $2=0x%04h", 
                 debug_cycle, debug_pc, debug_instr, 
                 dut.regs[1], dut.regs[2]);
    end
end
```

### 3. Display Tasks

Available tasks in testbench:
```verilog
display_registers();              // Show all register values
display_memory(start, end);       // Show memory range
print_final_state();              // Show final state (auto-called)
```

## Example Test Programs

### test_simple.bin - Basic Addition
```
Assembly equivalent:
    movi $1, 1      # $1 = 1
    movi $2, 2      # $2 = 2
    add $3, $1, $2  # $3 = $1 + $2 = 3
    j 3             # halt (jump to self)
```

Expected output:
```
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
```

### test_array_sum.bin - Array Summation
```
Assembly equivalent:
    movi $1, 0          # index = 0
    movi $3, 0          # sum = 0
loop:
    lw $2, myarray($1)  # load array element
    add $3, $3, $2      # sum += element
    addi $1, $1, 1      # index++
    jeq $2, $0, done    # if element == 0, exit
    j loop              # continue
done:
    halt
myarray:
    .fill 5, 3, 20, 4, 5, 0
```

Expected output: `$3 = 37` (sum of array)

## Creating Your Own Test Programs

### Option 1: Hand-Assemble

Create a `.bin` file with the machine code format:
```
ram[0] = 16'b0010000010000001;  # Binary format
ram[1] = 16'h2081;               # Hex format (also supported)
```

### Option 2: Use the C++ Assembler

If you have an E20 assembler, generate the `.bin` file and use it directly.

### Option 3: Write Directly in Machine Code

Instruction encoding reference:
```
movi $1, 5  ->  addi $1, $0, 5
  = 001 | 000 | 001 | 0000101
  = 0010 0000 1000 0101
  = 0x2085
  -> ram[X] = 16'h2085;
```

## Output Format

The testbench matches the C++ simulator's output format:

```
Final state:
    pc=    <value>
    $0=    <value>
    $1=    <value>
    ...
    $7=    <value>
    <128 memory words in hex, 8 per line>
```

This allows direct comparison using `diff`:
```bash
diff <(./e20-sim test.bin) <(./sim +program=test.bin | grep -A 200 "Final state")
```

## Troubleshooting

### Problem: Simulation never halts
**Solution**: Check for infinite loops. The testbench has a timeout of 100,000 cycles.
Increase `MAX_CYCLES` parameter if needed:
```verilog
parameter MAX_CYCLES = 1000000;  // Increase timeout
```

### Problem: Memory not loading
**Solution**: Verify file format. Each line must be:
```
ram[<address>] = 16'b<binary> ;
// or
ram[<address>] = 16'h<hex> ;
```

### Problem: Wrong results
**Solution**: 
1. Enable instruction monitoring (uncomment monitor block)
2. Compare with C++ simulator step-by-step
3. Use `display_registers()` task at breakpoints

### Problem: File not found
**Solution**: Ensure `.bin` file is in same directory as simulation, or provide full path:
```bash
./sim +program=/full/path/to/test.bin
```

## Performance Analysis

The testbench reports:
- **Total cycles**: Number of instructions executed
- **Final PC**: Where execution stopped
- **Instructions executed**: Same as total cycles in single-cycle design

Example output:
```
=== Performance Statistics ===
Total cycles:        142
Final PC:            0x0007 (7)
Instructions executed: 142
==============================
```

## Advanced Usage

### Generate VCD Waveform

```bash
./sim +program=test.bin +vcd
gtkwave processor.vcd
```

In GTKWave, look for:
- `tb_processor.dut.pc` - Program counter
- `tb_processor.dut.regs[1]` - Register $1
- `tb_processor.dut.ram[0]` - Memory location 0
- `tb_processor.halt` - Halt signal

### Automated Testing Script

Create `run_tests.sh`:
```bash
#!/bin/bash
echo "Running E20 Processor Tests..."
for test in test_*.bin; do
    echo "Testing $test..."
    ./sim +program=$test > verilog_out.txt
    ./e20-sim $test > cpp_out.txt
    if diff -q verilog_out.txt cpp_out.txt > /dev/null; then
        echo "  ✓ PASS"
    else
        echo "  ✗ FAIL"
        diff verilog_out.txt cpp_out.txt
    fi
done
```

```bash
chmod +x run_tests.sh
./run_tests.sh
```

## Next Steps

1. **Create more test programs** - Test all instructions
2. **Add assertions** - Verify specific behaviors
3. **Test edge cases** - Overflow, underflow, register $0 writes
4. **Performance tests** - Large programs, loops
5. **Coverage analysis** - Ensure all instructions tested

## Questions?

The testbench is designed to be educational and easy to use. Key features:
- ✅ Matches C++ simulator output format
- ✅ Easy program loading from `.bin` files
- ✅ Debug outputs for monitoring
- ✅ Timeout protection
- ✅ Waveform generation support
- ✅ Performance statistics

Experiment with different programs and compare results with the C++ simulator to verify correctness!
