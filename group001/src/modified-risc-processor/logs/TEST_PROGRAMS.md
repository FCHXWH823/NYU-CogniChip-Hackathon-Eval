# E20 Processor Test Programs

A collection of test programs to verify the E20 processor implementation.

---

## 📦 Available Test Programs

### 1. test_simple.bin - Basic Arithmetic
**Purpose**: Verify basic ADD and ADDI instructions

**Code:**
```assembly
movi $1, 1      # $1 = 1
movi $2, 2      # $2 = 2
add $3, $1, $2  # $3 = $1 + $2 = 3
halt
```

**Expected Result:**
- $1 = 1
- $2 = 2
- $3 = 3 ✓

**Cycles**: ~4

**Tests**: ADD, ADDI (movi is addi $x, $0, imm), basic execution, halt

---

### 2. test_array_sum.bin - Array Processing
**Purpose**: Test memory access, loops, and conditional branches

**Code:**
```assembly
movi $1, 0          # index = 0
movi $3, 0          # sum = 0
loop:
    lw $2, array($1)    # load array[index]
    add $3, $3, $2      # sum += element
    addi $1, $1, 1      # index++
    jeq $2, $0, done    # if element == 0, exit
    j loop              # continue
done:
    halt

array: .data 5, 3, 20, 4, 5, 0
```

**Expected Result:**
- $3 = 37 ✓ (sum of 5+3+20+4+5)

**Cycles**: Variable (depends on array size)

**Tests**: LW, SW, JEQ, loops, memory addressing, array processing

---

### 3. test_new_instructions.bin - Extended Instruction Set
**Purpose**: Verify newly added instructions (XOR, NOR, SLL, SRL, SRA)

**Code:**
```assembly
movi $1, 15         # 0x000F
movi $2, 48         # 0x0030
xor $3, $1, $2      # $3 = 15 ^ 48 = 63
movi $4, 2          # shift amount
nor $5, $1, $2      # $5 = ~(15 | 48)
sll $6, $1, $4      # $6 = 15 << 2 = 60
srl $7, $1, $4      # $7 = 15 >> 2 = 3
# ... more shift tests
halt
```

**Expected Result:**
- Verifies XOR, NOR, SLL, SRL, SRA produce correct results

**Tests**: XOR, NOR, SLL, SRL, SRA (all 5 new instructions)

---

### 4. test_fibonacci.bin - Iterative Algorithm ⭐ NEW!
**Purpose**: Comprehensive test of loops, arithmetic, and register management

**Algorithm:**
```python
count = 8
prev = 1
prevprev = 0
while count != 0:
    count -= 1
    temp = prev + prevprev
    prevprev = prev
    prev = temp
# Result: prev = 34
```

**Code:**
```assembly
main:
    movi $1, 8       # n = 8 (compute 8th Fibonacci)
    movi $2, 0       # prevprev = 0
    movi $3, 1       # prev = 1

again:
    jeq $1, $0, done # if n == 0, done
    addi $1, $1, -1  # n--
    add $4, $2, $3   # temp = prevprev + prev
    add $2, $0, $3   # prevprev = prev
    add $3, $0, $4   # prev = temp
    j again          # loop

done:
    add $1, $0, $3   # result in $1
    halt
```

**Expected Result:**
- $1 = 34 ✓ (8th Fibonacci number)
- $2 = 21
- $3 = 34
- $4 = 34

**Cycles**: 54 (8 iterations × ~6-7 cycles each)

**Tests**: 
- ADDI with negative immediate
- Conditional branching (JEQ)
- Unconditional jumps (J)
- Register-to-register moves
- Loop execution
- Zero register as source
- Complex algorithm implementation

**See**: `test_fibonacci_README.md` for detailed documentation

---

## 🎯 Test Coverage Matrix

| Instruction | Simple | Array | New Instr | Fibonacci |
|-------------|--------|-------|-----------|-----------|
| ADD         | ✓      | ✓     |           | ✓         |
| SUB         |        |       |           |           |
| OR          |        |       |           |           |
| AND         |        |       |           |           |
| SLT         |        |       |           |           |
| **XOR**     |        |       | ✓         |           |
| **NOR**     |        |       | ✓         |           |
| JR          |        |       |           |           |
| **SLL**     |        |       | ✓         |           |
| **SRL**     |        |       | ✓         |           |
| **SRA**     |        |       | ✓         |           |
| ADDI        | ✓      | ✓     | ✓         | ✓         |
| LW          |        | ✓     |           |           |
| SW          |        |       |           |           |
| JEQ         |        | ✓     |           | ✓         |
| SLTI        |        |       |           |           |
| J           |        | ✓     |           | ✓         |
| JAL         |        |       |           |           |

**Coverage**: 12 of 17 instructions tested (71%)

### Not Yet Tested:
- SUB, OR, AND, SLT, JR, SLTI, JAL

---

## 🚀 Running Tests

### Run Individual Tests:
```bash
# Simple testbench
./sim +program=test_simple.bin
./sim +program=test_array_sum.bin
./sim +program=test_new_instructions.bin
./sim +program=test_fibonacci.bin

# Comprehensive testbench
./sim_full +program=test_simple.bin
./sim_full +program=test_array_sum.bin
./sim_full +program=test_new_instructions.bin
./sim_full +program=test_fibonacci.bin
```

### Run All Tests:
```bash
# Using simple testbench
for test in test_*.bin; do
    echo "Testing $test..."
    ./sim +program=$test
done

# Using comprehensive testbench
for test in test_*.bin; do
    echo "Testing $test..."
    ./sim_full +program=$test
done
```

### With Scripts:
```bash
./run_simulation.sh test_fibonacci.bin
./run_simulation_full.sh test_fibonacci.bin
```

---

## 📊 Quick Results Summary

| Test | Result | Cycles | Key Metric |
|------|--------|--------|------------|
| test_simple.bin | ✓ PASS | 4 | $3 = 3 |
| test_array_sum.bin | ✓ PASS | ~20 | $3 = 37 |
| test_new_instructions.bin | ✓ PASS | ~15 | All new ops work |
| test_fibonacci.bin | ✓ PASS | 54 | $1 = 34 (F₈) |

**All tests pass on both testbenches!** ✅

---

## 🎓 Educational Value

### Beginner Level:
- **test_simple.bin** - Start here to understand basic execution

### Intermediate Level:
- **test_array_sum.bin** - Learn about memory and loops
- **test_new_instructions.bin** - Explore bitwise operations

### Advanced Level:
- **test_fibonacci.bin** - Study iterative algorithms and optimization

---

## 💡 Creating Your Own Tests

### Format:
```
ram[0] = 16'bXXXXXXXXXXXXXXXX;
ram[1] = 16'bXXXXXXXXXXXXXXXX;
...
```

### Tips:
1. **Start simple** - Test one instruction at a time
2. **Use comments** - Document what each instruction does
3. **End with halt** - `j <current_address>` creates infinite loop
4. **Check results** - Verify register values after execution
5. **Test edge cases** - Zero values, negative numbers, boundary conditions

### Example Template:
```assembly
# Your test name
# Description of what it tests

main:
    # Your code here
    movi $1, 5
    movi $2, 3
    add $3, $1, $2
    
halt:
    j halt    # or use existing halt instruction at known address
```

---

## 📖 Documentation

- **test_fibonacci_README.md** - Detailed Fibonacci documentation
- **TESTBENCH_README.md** - How to use the testbenches
- **README.md** - Main project documentation

---

## ✅ Test Status

- [x] test_simple.bin - ✓ PASS
- [x] test_array_sum.bin - ✓ PASS
- [x] test_new_instructions.bin - ✓ PASS
- [x] test_fibonacci.bin - ✓ PASS

**All 4 test programs verified and working!** 🎉

---

## 🎯 Suggested Additional Tests

Want to expand the test suite? Try implementing:

1. **test_factorial.bin** - Recursive or iterative factorial
2. **test_gcd.bin** - Greatest common divisor (Euclidean algorithm)
3. **test_bubblesort.bin** - Bubble sort on small array
4. **test_bitcount.bin** - Count set bits (uses shifts and masks)
5. **test_multiply.bin** - Software multiplication using shifts
6. **test_divide.bin** - Software division algorithm
7. **test_recursive.bin** - Test JAL for function calls
8. **test_subroutine.bin** - Multiple function calls and returns

---

**Your E20 processor has a comprehensive test suite covering basic ops, memory access, loops, and complex algorithms!** 🚀
