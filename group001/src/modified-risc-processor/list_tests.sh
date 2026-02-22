#!/bin/bash

# =============================================================================
# List Available Tests
# =============================================================================

echo "========================================="
echo "E20 Pipelined Processor - Available Tests"
echo "========================================="
echo ""

echo "Custom Tests (current directory):"
echo "-----------------------------------"
if ls test_*.bin 1> /dev/null 2>&1; then
    for test in test_*.bin; do
        echo "  • $(basename $test)"
    done
else
    echo "  (none found)"
fi

echo ""
echo "Basic Tests (basic-tests/):"
echo "-----------------------------------"
if [ -d "basic-tests" ]; then
    if ls basic-tests/*.bin 1> /dev/null 2>&1; then
        for test in basic-tests/*.bin; do
            echo "  • $(basename $test)"
        done
    else
        echo "  (none found)"
    fi
else
    echo "  (basic-tests directory not found)"
fi

echo ""
echo "Usage Examples:"
echo "-----------------------------------"
echo "  Run all basic tests:"
echo "    ./run_pipelined_basic_tests.sh"
echo ""
echo "  Run single test:"
echo "    ./run_pipelined_test.sh test_simple.bin"
echo "    ./run_pipelined_test.sh basic-tests/array-sum.bin"
echo ""
