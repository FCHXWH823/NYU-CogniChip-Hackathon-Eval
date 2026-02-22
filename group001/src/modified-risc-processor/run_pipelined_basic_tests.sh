#!/bin/bash

# =============================================================================
# E20 Pipelined Processor - Basic Tests Runner
# =============================================================================
# This script runs all basic-tests on the pipelined processor implementation
# Uses Icarus Verilog for simulation
# =============================================================================

set -e  # Exit on error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Configuration
PROC_FILE="processor_pipelined.v"
TB_FILE="tb_processor_pipelined.v"
SIM_DIR="sim_pipelined_basic"
RESULTS_FILE="pipelined_test_results.txt"

# Test files in basic-tests directory
BASIC_TESTS=(
    "basic-tests/array-sum.bin"
    "basic-tests/loop1.bin"
    "basic-tests/loop2.bin"
    "basic-tests/loop3.bin"
    "basic-tests/math.bin"
    "basic-tests/subroutine1.bin"
    "basic-tests/subroutine2.bin"
    "basic-tests/vars1.bin"
)

# Test names (for display)
TEST_NAMES=(
    "array-sum"
    "loop1"
    "loop2"
    "loop3"
    "math"
    "subroutine1"
    "subroutine2"
    "vars1"
)

# Function to print section header
print_header() {
    echo ""
    echo -e "${BLUE}========================================${NC}"
    echo -e "${BLUE}$1${NC}"
    echo -e "${BLUE}========================================${NC}"
    echo ""
}

# Function to print test status
print_status() {
    local test_name=$1
    local status=$2
    if [ "$status" = "PASS" ]; then
        echo -e "[${GREEN}✓${NC}] ${test_name}: ${GREEN}PASSED${NC}"
    elif [ "$status" = "FAIL" ]; then
        echo -e "[${RED}✗${NC}] ${test_name}: ${RED}FAILED${NC}"
    else
        echo -e "[${YELLOW}?${NC}] ${test_name}: ${YELLOW}${status}${NC}"
    fi
}

# Check if Icarus Verilog is installed
check_iverilog() {
    if ! command -v iverilog &> /dev/null; then
        echo -e "${RED}ERROR: Icarus Verilog (iverilog) not found!${NC}"
        echo "Please install it:"
        echo "  macOS:   brew install icarus-verilog"
        echo "  Ubuntu:  sudo apt-get install iverilog"
        exit 1
    fi
    echo -e "${GREEN}Found Icarus Verilog:${NC} $(iverilog -V | head -1)"
}

# Check if required files exist
check_files() {
    local missing=0
    
    if [ ! -f "$PROC_FILE" ]; then
        echo -e "${RED}ERROR: Processor file not found: $PROC_FILE${NC}"
        missing=1
    fi
    
    if [ ! -f "$TB_FILE" ]; then
        echo -e "${RED}ERROR: Testbench file not found: $TB_FILE${NC}"
        missing=1
    fi
    
    for test_file in "${BASIC_TESTS[@]}"; do
        if [ ! -f "$test_file" ]; then
            echo -e "${YELLOW}WARNING: Test file not found: $test_file${NC}"
        fi
    done
    
    if [ $missing -eq 1 ]; then
        exit 1
    fi
}

# Create simulation directory
setup_sim_dir() {
    if [ -d "$SIM_DIR" ]; then
        echo "Cleaning existing simulation directory..."
        rm -rf "$SIM_DIR"
    fi
    mkdir -p "$SIM_DIR"
    echo -e "${GREEN}Created simulation directory: $SIM_DIR${NC}"
}

# Run a single test
run_test() {
    local test_file=$1
    local test_name=$2
    local test_num=$3
    
    echo ""
    echo -e "${YELLOW}Running test $((test_num+1))/${#BASIC_TESTS[@]}: ${test_name}${NC}"
    echo "----------------------------------------"
    
    if [ ! -f "$test_file" ]; then
        print_status "$test_name" "SKIPPED (file not found)"
        echo "SKIP: $test_name (file not found)" >> "$RESULTS_FILE"
        return 1
    fi
    
    # Compile
    echo "Compiling..."
    if ! iverilog -g2012 -o "${SIM_DIR}/${test_name}.vvp" \
        "$PROC_FILE" "$TB_FILE" 2>&1 | tee "${SIM_DIR}/${test_name}_compile.log"; then
        print_status "$test_name" "COMPILE ERROR"
        echo "FAIL: $test_name (compile error)" >> "$RESULTS_FILE"
        return 1
    fi
    
    # Run simulation
    echo "Simulating..."
    if vvp "${SIM_DIR}/${test_name}.vvp" "+program=${test_file}" \
        > "${SIM_DIR}/${test_name}_sim.log" 2>&1; then
        
        # Check if simulation passed
        if grep -q "TEST PASSED" "${SIM_DIR}/${test_name}_sim.log"; then
            print_status "$test_name" "PASS"
            echo "PASS: $test_name" >> "$RESULTS_FILE"
            
            # Extract cycle count if available
            cycles=$(grep "halted normally after" "${SIM_DIR}/${test_name}_sim.log" | \
                     sed -n 's/.*after \([0-9]*\) cycles.*/\1/p')
            if [ -n "$cycles" ]; then
                echo "  Cycles: $cycles"
                echo "  Cycles: $cycles" >> "$RESULTS_FILE"
            fi
            return 0
        else
            print_status "$test_name" "FAIL"
            echo "FAIL: $test_name" >> "$RESULTS_FILE"
            
            # Show error details
            echo ""
            echo "Error output:"
            tail -20 "${SIM_DIR}/${test_name}_sim.log"
            return 1
        fi
    else
        print_status "$test_name" "RUNTIME ERROR"
        echo "FAIL: $test_name (runtime error)" >> "$RESULTS_FILE"
        
        # Show error details
        echo ""
        echo "Error output:"
        tail -20 "${SIM_DIR}/${test_name}_sim.log"
        return 1
    fi
}

# Main execution
main() {
    print_header "E20 Pipelined Processor - Basic Tests"
    
    echo "Checking prerequisites..."
    check_iverilog
    check_files
    
    echo ""
    echo "Setting up simulation environment..."
    setup_sim_dir
    
    # Initialize results file
    echo "E20 Pipelined Processor - Basic Tests Results" > "$RESULTS_FILE"
    echo "Date: $(date)" >> "$RESULTS_FILE"
    echo "========================================" >> "$RESULTS_FILE"
    echo "" >> "$RESULTS_FILE"
    
    # Run all tests
    print_header "Running Basic Tests"
    
    local passed=0
    local failed=0
    local skipped=0
    
    for i in "${!BASIC_TESTS[@]}"; do
        if run_test "${BASIC_TESTS[$i]}" "${TEST_NAMES[$i]}" "$i"; then
            ((passed++))
        else
            if [ -f "${BASIC_TESTS[$i]}" ]; then
                ((failed++))
            else
                ((skipped++))
            fi
        fi
    done
    
    # Print summary
    print_header "Test Summary"
    
    echo "Total tests:   ${#BASIC_TESTS[@]}"
    echo -e "${GREEN}Passed:        $passed${NC}"
    echo -e "${RED}Failed:        $failed${NC}"
    if [ $skipped -gt 0 ]; then
        echo -e "${YELLOW}Skipped:       $skipped${NC}"
    fi
    
    echo ""
    echo "Detailed results saved to: $RESULTS_FILE"
    echo "Simulation logs saved to:  $SIM_DIR/"
    
    # Write summary to results file
    echo "" >> "$RESULTS_FILE"
    echo "========================================" >> "$RESULTS_FILE"
    echo "Summary:" >> "$RESULTS_FILE"
    echo "  Total:   ${#BASIC_TESTS[@]}" >> "$RESULTS_FILE"
    echo "  Passed:  $passed" >> "$RESULTS_FILE"
    echo "  Failed:  $failed" >> "$RESULTS_FILE"
    echo "  Skipped: $skipped" >> "$RESULTS_FILE"
    echo "========================================" >> "$RESULTS_FILE"
    
    echo ""
    if [ $failed -eq 0 ]; then
        print_header "ALL TESTS PASSED! 🎉"
        exit 0
    else
        print_header "SOME TESTS FAILED"
        exit 1
    fi
}

# Run main function
main
