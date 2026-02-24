// ===========================================================================
// TTC3 Testbench Top
// ===========================================================================
// Top-level testbench module that:
// - Instantiates the DUT (ttc3_top)
// - Generates clock
// - Instantiates the interface
// - Connects DUT to interface
// - Launches UVM test
// ===========================================================================

module ttc3_tb_top;
    
    import uvm_pkg::*;
    import ttc3_pkg::*;
    
    // -----------------------------------------------------------------------
    // Clock Generation
    // -----------------------------------------------------------------------
    logic clock;
    
    initial begin
        clock = 0;
        forever #5ns clock = ~clock;  // 100MHz clock (10ns period)
    end
    
    // -----------------------------------------------------------------------
    // Interface Instantiation
    // -----------------------------------------------------------------------
    ttc3_if vif(clock);
    
    // -----------------------------------------------------------------------
    // DUT Instantiation
    // -----------------------------------------------------------------------
    ttc3_top #(
        .DUS_WIDTH       (256),
        .DEVICE_ID_WIDTH (128),
        .KEY_WIDTH       (256)
    ) dut (
        .clock                  (vif.clock),
        .reset                  (vif.reset),
        .dus_write_enable       (vif.dus_write_enable),
        .dus_write_data         (vif.dus_write_data),
        .device_id_fuse_valid   (vif.device_id_fuse_valid),
        .device_id_fuse_data    (vif.device_id_fuse_data),
        .cmd_valid              (vif.cmd_valid),
        .cmd_op                 (vif.cmd_op),
        .cmd_data               (vif.cmd_data),
        .cmd_ready              (vif.cmd_ready),
        .cmd_done               (vif.cmd_done),
        .resp_data              (vif.resp_data),
        .resp_valid             (vif.resp_valid)
    );
    
    // -----------------------------------------------------------------------
    // UVM Configuration and Test Launch
    // -----------------------------------------------------------------------
    initial begin
        // Put interface in config DB so UVM components can access it
        uvm_config_db#(virtual ttc3_if)::set(null, "*", "vif", vif);
        
        // Enable waveform dumping
        $dumpfile("ttc3_sim.fst");
        $dumpvars(0, ttc3_tb_top);
        
        // Print simulation start message
        $display("========================================");
        $display("TEST START");
        $display("TTC3 UVM Verification Environment");
        $display("========================================");
        
        // Run the UVM test
        run_test();
        
        // Simulation end
        $display("========================================");
        $display("TEST PASSED");
        $display("========================================");
        $finish;
    end
    
    // -----------------------------------------------------------------------
    // Timeout Watchdog
    // -----------------------------------------------------------------------
    initial begin
        #1ms;  // 1 millisecond timeout (crypto operations take time)
        $display("========================================");
        $display("ERROR: Simulation timeout!");
        $display("TEST FAILED");
        $display("========================================");
        $fatal(1, "Simulation exceeded maximum time limit");
    end
    
    // -----------------------------------------------------------------------
    // Optional: Dump internal DUT signals for debugging
    // -----------------------------------------------------------------------
    initial begin
        $display("DUT Parameters:");
        $display("  DUS_WIDTH:       %0d", dut.DUS_WIDTH);
        $display("  DEVICE_ID_WIDTH: %0d", dut.DEVICE_ID_WIDTH);
        $display("  KEY_WIDTH:       %0d", dut.KEY_WIDTH);
    end
    
endmodule
