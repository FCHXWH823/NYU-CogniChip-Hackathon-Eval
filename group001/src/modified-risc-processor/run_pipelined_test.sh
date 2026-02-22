#!/bin/bash

# =============================================================================
# E20 Pipelined Processor - Single Test Runner
# =============================================================================
# Run a single test on the pipelined processor
# Usage: ./run_pipelined_test.sh <test_file.bin>
# Example: ./run_pipelined_test.sh basic-tests/array-sum.bin
# =============================================================================

# Colors
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# Check arguments
if [ $# -eq 0 ]; then
    echo "Usage: $0 <test_file.bin>"
    echo ""
    echo "Examples:"
    echo "  $0 test_simple.bin"
    echo "  $0 test_fibonacci.bin"
    echo "  $0 test_array_sum.bin"
    echo "  $0 basic-tests/array-sum.bin"
    echo "  $0 basic-tests/loop1.bin"
    echo ""
    exit 1
fi

TEST_FILE=$1

# Check if test file exists
if [ ! -f "$TEST_FILE" ]; then
    echo -e "${RED}ERROR: Test file not found: $TEST_FILE${NC}"
    exit 1
fi

# Extract test name
TEST_NAME=$(basename "$TEST_FILE" .bin)

echo -e "${BLUE}========================================${NC}"
echo -e "${BLUE}E20 Pipelined Processor - Single Test${NC}"
echo -e "${BLUE}========================================${NC}"
echo ""
echo "Test file: $TEST_FILE"
echo "Test name: $TEST_NAME"
echo ""

# Check for required files
if [ ! -f "processor_pipelined.v" ]; then
    echo -e "${RED}ERROR: processor_pipelined.v not found${NC}"
    exit 1
fi

if [ ! -f "tb_processor_pipelined.v" ]; then
    echo -e "${RED}ERROR: tb_processor_pipelined.v not found${NC}"
    exit 1
fi

# Check for iverilog
if ! command -v iverilog &> /dev/null; then
    echo -e "${RED}ERROR: Icarus Verilog not found${NC}"
    echo "Install with: brew install icarus-verilog (macOS)"
    exit 1
fi

# Create output directory
mkdir -p sim_output

# Compile
echo -e "${YELLOW}[1/2] Compiling...${NC}"
if iverilog -g2012 -o sim_output/${TEST_NAME}.vvp \
    processor_pipelined.v tb_processor_pipelined.v 2>&1 | tee sim_output/${TEST_NAME}_compile.log; then
    echo -e "${GREEN}✓ Compilation successful${NC}"
else
    echo -e "${RED}✗ Compilation failed${NC}"
    echo "See sim_output/${TEST_NAME}_compile.log for details"
    exit 1
fi

echo ""

# Run simulation
echo -e "${YELLOW}[2/2] Running simulation...${NC}"
if vvp sim_output/${TEST_NAME}.vvp "+program=${TEST_FILE}" \
    2>&1 | tee sim_output/${TEST_NAME}_sim.log; then
    
    echo ""
    echo -e "${BLUE}========================================${NC}"
    
    # Check results
    if grep -q "TEST PASSED" sim_output/${TEST_NAME}_sim.log; then
        echo -e "${GREEN}✓ TEST PASSED${NC}"
        
        # Extract cycle count
        cycles=$(grep "halted normally after" sim_output/${TEST_NAME}_sim.log | \
                 sed -n 's/.*after \([0-9]*\) cycles.*/\1/p')
        if [ -n "$cycles" ]; then
            echo -e "${GREEN}  Execution cycles: $cycles${NC}"
        fi
        
        echo -e "${BLUE}========================================${NC}"
        exit 0
    else
        echo -e "${RED}✗ TEST FAILED${NC}"
        echo -e "${BLUE}========================================${NC}"
        exit 1
    fi
else
    echo ""
    echo -e "${RED}✗ Simulation failed${NC}"
    exit 1
fi
