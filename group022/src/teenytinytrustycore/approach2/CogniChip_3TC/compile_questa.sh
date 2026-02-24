#!/bin/bash
# TTC3 Questa Compilation Script

# Check if UVM_HOME is set, otherwise use Questa default
if [ -z "$UVM_HOME" ]; then
    # Try to find Questa installation
    if [ -n "$QUESTA_HOME" ]; then
        export UVM_HOME=$QUESTA_HOME/verilog_src/uvm-1.2
    elif [ -n "$MODEL_TECH" ]; then
        # ModelSim/Questa is in PATH
        QUESTA_BASE=$(dirname $(dirname $(which vsim)))
        export UVM_HOME=$QUESTA_BASE/verilog_src/uvm-1.2
    else
        echo "ERROR: Cannot find UVM library. Please set QUESTA_HOME or UVM_HOME"
        exit 1
    fi
fi

echo "=================================================="
echo "TTC3 UVM Testbench Compilation"
echo "=================================================="
echo "UVM_HOME: $UVM_HOME"
echo ""

# Clean previous compilation
rm -rf work/
echo "Cleaned work library"
echo ""

# Compile
echo "Compiling files..."
vlog -sv \
     +incdir+$UVM_HOME/src \
     $UVM_HOME/src/uvm_pkg.sv \
     -f files.f

if [ $? -eq 0 ]; then
    echo ""
    echo "=================================================="
    echo "COMPILATION SUCCESSFUL!"
    echo "=================================================="
    echo ""
    echo "To run tests:"
    echo "  vsim -c +UVM_TESTNAME=ttc3_security_test -do \"run -all; quit -f\" ttc3_tb_top"
    echo "  vsim -c +UVM_TESTNAME=ttc3_random_test -do \"run -all; quit -f\" ttc3_tb_top"
    echo "  vsim -c +UVM_TESTNAME=ttc3_reset_test -do \"run -all; quit -f\" ttc3_tb_top"
    echo ""
    echo "Or use GUI:"
    echo "  vsim -gui +UVM_TESTNAME=ttc3_security_test ttc3_tb_top"
    echo ""
else
    echo ""
    echo "=================================================="
    echo "COMPILATION FAILED!"
    echo "=================================================="
    exit 1
fi
