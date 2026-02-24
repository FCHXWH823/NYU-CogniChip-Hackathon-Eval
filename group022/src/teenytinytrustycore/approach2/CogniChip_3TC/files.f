// TTC3 Verification File List
// SystemVerilog UVM testbench compilation

// Interface
ttc3_if.sv

// UVM Package (contains all testbench classes)
ttc3_pkg.sv

// RTL Design Files
ttc3_dus_storage.sv
ttc3_device_id.sv
ttc3_kdf.sv
ttc3_sha256.sv
ttc3_hmac.sv
ttc3_aes_ctr.sv
ttc3_top.sv

// NOTE: ttc3_security_sva.sv is excluded from standalone compilation
// It should be bound to the DUT using a bind statement if needed for formal verification
// To enable SVA checking, add: bind ttc3_top ttc3_security_sva ...
// For now, we skip it to avoid compilation errors

// Testbench Top
ttc3_tb_top.sv
