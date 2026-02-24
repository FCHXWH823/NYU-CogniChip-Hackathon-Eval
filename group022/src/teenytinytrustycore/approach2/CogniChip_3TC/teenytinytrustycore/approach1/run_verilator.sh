#!/bin/bash
# Verilator Compilation and Simulation Script
# Hardware Root of Trust - Enrollment Test

echo "======================================================="
echo "  Hardware Root of Trust - Verilator Simulation"
echo "======================================================="

# Verilator path
VERILATOR=/tools/verilator/5.040/bin/verilator

# Check if Verilator exists
if [ ! -f "$VERILATOR" ]; then
    echo "ERROR: Verilator not found at $VERILATOR"
    exit 1
fi

echo "Using Verilator: $VERILATOR"
$VERILATOR --version

# Clean previous build
echo ""
echo "Cleaning previous build..."
rm -rf obj_dir
rm -f dumpfile.fst dumpfile.vcd

# Compile with Verilator
echo ""
echo "Compiling design with Verilator..."
$VERILATOR \
    --binary \
    --trace-fst \
    --trace-structs \
    --trace-params \
    --trace-max-array 1024 \
    --top-module tb_enrollment_simple \
    -Wno-fatal \
    -Wno-UNOPTFLAT \
    -Wno-WIDTH \
    -Wno-UNUSEDSIGNAL \
    tb_enrollment_simple.sv \
    root_of_trust_top.sv \
    puf_dus.sv \
    puf_device_id.sv \
    kdf_module.sv \
    secure_key_distributor.sv \
    sha256_core.sv \
    hmac_sha256.sv \
    aes_ctr.sv

# Check compilation status
if [ $? -ne 0 ]; then
    echo ""
    echo "ERROR: Verilator compilation failed!"
    exit 1
fi

echo ""
echo "Compilation successful!"

# Run simulation
echo ""
echo "Running simulation..."
echo "======================================================="
./obj_dir/Vtb_enrollment_simple

# Check simulation status
SIM_STATUS=$?

echo ""
echo "======================================================="
if [ $SIM_STATUS -eq 0 ]; then
    echo "Simulation completed successfully!"
else
    echo "Simulation failed with exit code: $SIM_STATUS"
fi

# Check for waveform
if [ -f "dumpfile.fst" ]; then
    echo "Waveform generated: dumpfile.fst"
    echo "View with: gtkwave dumpfile.fst"
else
    echo "No waveform file generated"
fi

echo "======================================================="

exit $SIM_STATUS
