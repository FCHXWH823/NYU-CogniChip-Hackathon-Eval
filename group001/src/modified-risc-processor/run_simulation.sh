#!/bin/bash
# E20 Processor Simulation Script
# Usage: ./run_simulation.sh [test_program.bin]

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Default program
PROGRAM="test_simple.bin"

# Check for program argument
if [ $# -ge 1 ]; then
    PROGRAM="$1"
fi

echo "========================================"
echo "E20 Processor Simulation"
echo "========================================"
echo ""

# Check if program file exists
if [ ! -f "$PROGRAM" ]; then
    echo -e "${RED}Error: Program file '$PROGRAM' not found${NC}"
    echo "Available test programs:"
    ls -1 test_*.bin 2>/dev/null
    exit 1
fi

echo "Program: $PROGRAM"
echo ""

# Compile if needed
if [ ! -f "sim" ] || [ "processor.v" -nt "sim" ] || [ "tb_processor_simple.v" -nt "sim" ]; then
    echo -e "${YELLOW}Compiling testbench...${NC}"
    iverilog -o sim tb_processor_simple.v processor.v
    
    if [ $? -ne 0 ]; then
        echo -e "${RED}Compilation failed!${NC}"
        exit 1
    fi
    echo -e "${GREEN}Compilation successful${NC}"
    echo ""
fi

# Run simulation
echo "Running simulation..."
echo "========================================"
./sim +program="$PROGRAM"
SIM_RESULT=$?
echo "========================================"

if [ $SIM_RESULT -eq 0 ]; then
    echo ""
    echo -e "${GREEN}✓ Simulation completed successfully${NC}"
else
    echo ""
    echo -e "${RED}✗ Simulation failed${NC}"
    exit 1
fi

# Offer to compare with C++ simulator if it exists
if [ -f "e20-simulator" ] || [ -f "e20-sim" ]; then
    echo ""
    read -p "Compare with C++ simulator? (y/n) " -n 1 -r
    echo
    if [[ $REPLY =~ ^[Yy]$ ]]; then
        echo ""
        echo "Running C++ simulator..."
        if [ -f "e20-simulator" ]; then
            CPP_SIM="./e20-simulator"
        else
            CPP_SIM="./e20-sim"
        fi
        
        $CPP_SIM "$PROGRAM" > cpp_output.txt
        ./sim +program="$PROGRAM" 2>&1 | grep -A 200 "Final state" > verilog_output.txt
        
        echo "Comparing outputs..."
        if diff -q cpp_output.txt verilog_output.txt > /dev/null 2>&1; then
            echo -e "${GREEN}✓ Outputs match!${NC}"
        else
            echo -e "${YELLOW}⚠ Outputs differ:${NC}"
            diff cpp_output.txt verilog_output.txt
        fi
    fi
fi

echo ""
echo "Done."
