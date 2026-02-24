#!/bin/bash
# ===========================================================================
# Run All TTC3 Testbenches with Icarus Verilog
# ===========================================================================

echo "========================================"
echo "TTC3 Testbench Suite - Icarus Verilog"
echo "========================================"
echo ""

# Check if Icarus Verilog is installed
if ! command -v iverilog &> /dev/null; then
    echo "ERROR: Icarus Verilog not found!"
    echo "Install with: sudo apt-get install iverilog"
    exit 1
fi

# Check if we're in the right directory
if [ ! -f "Makefile.icarus" ]; then
    echo "ERROR: Must run from testbenches/ directory"
    exit 1
fi

# Clean previous runs
echo "Cleaning previous builds..."
make -f Makefile.icarus clean
echo ""

# Run all tests
echo "Running all testbenches..."
echo ""

TESTS_PASSED=0
TESTS_FAILED=0

# Test 1: DUS Storage
echo "========================================"
echo "Test 1/3: DUS Storage Module"
echo "========================================"
if make -f Makefile.icarus test_dus_storage; then
    TESTS_PASSED=$((TESTS_PASSED + 1))
else
    TESTS_FAILED=$((TESTS_FAILED + 1))
fi
echo ""

# Test 2: Device ID
echo "========================================"
echo "Test 2/3: Device ID Module"
echo "========================================"
if make -f Makefile.icarus test_device_id; then
    TESTS_PASSED=$((TESTS_PASSED + 1))
else
    TESTS_FAILED=$((TESTS_FAILED + 1))
fi
echo ""

# Test 3: Top-Level Integration
echo "========================================"
echo "Test 3/3: Top-Level Integration"
echo "========================================"
if make -f Makefile.icarus test_top; then
    TESTS_PASSED=$((TESTS_PASSED + 1))
else
    TESTS_FAILED=$((TESTS_FAILED + 1))
fi
echo ""

# Summary
echo "========================================"
echo "REGRESSION SUMMARY"
echo "========================================"
echo "Tests Passed: $TESTS_PASSED/3"
echo "Tests Failed: $TESTS_FAILED/3"
echo ""

if [ $TESTS_FAILED -eq 0 ]; then
    echo "✅ ALL TESTS PASSED!"
    echo ""
    echo "Waveforms generated:"
    ls -lh *.vcd
    echo ""
    echo "View waveforms with:"
    echo "  gtkwave tb_ttc3_top.vcd &"
    exit 0
else
    echo "❌ SOME TESTS FAILED!"
    exit 1
fi
