// ===========================================================================
// TTC3 UVM Interface
// ===========================================================================
// SystemVerilog interface for connecting UVM testbench to TTC3 DUT
//
// Features:
// - Clocking blocks for driver and monitor
// - Modport definitions for clear signal direction
// - Synchronous driving with setup/hold timing
// ===========================================================================

interface ttc3_if (
    input logic clock
);
    
    // -----------------------------------------------------------------------
    // Signals matching ttc3_top interface
    // -----------------------------------------------------------------------
    logic         reset;
    
    // DUS initialization
    logic         dus_write_enable;
    logic [255:0] dus_write_data;
    
    // Device ID initialization
    logic         device_id_fuse_valid;
    logic [127:0] device_id_fuse_data;
    
    // Command interface
    logic         cmd_valid;
    logic [2:0]   cmd_op;
    logic [511:0] cmd_data;
    logic         cmd_ready;
    logic         cmd_done;
    
    // Response interface
    logic [511:0] resp_data;
    logic         resp_valid;
    
    // -----------------------------------------------------------------------
    // Clocking Block for Driver (synchronous driving)
    // -----------------------------------------------------------------------
    clocking drv_cb @(posedge clock);
        default input #1ns output #1ns;
        
        output reset;
        output dus_write_enable;
        output dus_write_data;
        output device_id_fuse_valid;
        output device_id_fuse_data;
        output cmd_valid;
        output cmd_op;
        output cmd_data;
        
        input  cmd_ready;
        input  cmd_done;
        input  resp_data;
        input  resp_valid;
    endclocking
    
    // -----------------------------------------------------------------------
    // Clocking Block for Monitor (sample after clock edge)
    // -----------------------------------------------------------------------
    clocking mon_cb @(posedge clock);
        default input #1ns output #1ns;
        
        input reset;
        input dus_write_enable;
        input dus_write_data;
        input device_id_fuse_valid;
        input device_id_fuse_data;
        input cmd_valid;
        input cmd_op;
        input cmd_data;
        input cmd_ready;
        input cmd_done;
        input resp_data;
        input resp_valid;
    endclocking
    
    // -----------------------------------------------------------------------
    // Modports
    // -----------------------------------------------------------------------
    modport driver (
        clocking drv_cb,
        input clock
    );
    
    modport monitor (
        clocking mon_cb,
        input clock
    );
    
    modport dut (
        input  clock,
        input  reset,
        input  dus_write_enable,
        input  dus_write_data,
        input  device_id_fuse_valid,
        input  device_id_fuse_data,
        input  cmd_valid,
        input  cmd_op,
        input  cmd_data,
        output cmd_ready,
        output cmd_done,
        output resp_data,
        output resp_valid
    );
    
endinterface
