// ===========================================================================
// Testbench for ttc3_device_id
// ===========================================================================
// Tests Device ID storage module
// - Immutability after reset
// - Fuse input handling
// - Always readable
// ===========================================================================

`timescale 1ns/1ps

module tb_ttc3_device_id;

    // Parameters
    parameter ID_WIDTH = 128;
    parameter CLK_PERIOD = 10;
    
    // DUT signals
    logic                clock;
    logic                reset;
    logic                fuse_valid;
    logic [ID_WIDTH-1:0] fuse_id;
    logic [ID_WIDTH-1:0] device_id;
    logic                id_valid;
    
    // Test control
    int test_num = 0;
    int errors = 0;
    logic [ID_WIDTH-1:0] captured_id;
    
    // DUT instantiation
    ttc3_device_id #(
        .ID_WIDTH(ID_WIDTH),
        .DEFAULT_ID(128'hDEADBEEF_CAFEBABE_01234567_89ABCDEF)
    ) dut (
        .clock(clock),
        .reset(reset),
        .fuse_valid(fuse_valid),
        .fuse_id(fuse_id),
        .device_id(device_id),
        .id_valid(id_valid)
    );
    
    // Clock generation
    initial begin
        clock = 0;
        forever #(CLK_PERIOD/2) clock = ~clock;
    end
    
    // Waveform dump
    initial begin
        $dumpfile("tb_ttc3_device_id.vcd");
        $dumpvars(0, tb_ttc3_device_id);
    end
    
    // Test stimulus
    initial begin
        $display("TEST START");
        $display("========================================");
        $display("Testing TTC3 Device ID Module");
        $display("========================================");
        
        // Initialize
        reset = 1;
        fuse_valid = 0;
        fuse_id = '0;
        
        // Reset
        repeat(5) @(posedge clock);
        reset = 0;
        @(posedge clock);
        
        // Test 1: Check ID valid after reset
        test_num = 1;
        $display("\nTest %0d: Device ID valid after reset", test_num);
        repeat(2) @(posedge clock);
        
        if (id_valid) begin
            $display("  PASS: ID valid flag is asserted");
            $display("  Device ID: 0x%h", device_id);
        end else begin
            $display("  FAIL: ID valid flag not asserted");
            errors++;
        end
        
        // Test 2: Check ID is non-zero
        test_num = 2;
        $display("\nTest %0d: Device ID is non-zero", test_num);
        if (device_id != '0) begin
            $display("  PASS: Device ID is non-zero");
        end else begin
            $display("  FAIL: Device ID is zero (invalid)");
            errors++;
        end
        
        // Capture ID for immutability test
        captured_id = device_id;
        
        // Test 3: ID immutability (read multiple times)
        test_num = 3;
        $display("\nTest %0d: Device ID immutability", test_num);
        repeat(10) @(posedge clock);
        
        if (device_id == captured_id) begin
            $display("  PASS: Device ID remained constant");
        end else begin
            $display("  FAIL: Device ID changed!");
            errors++;
        end
        
        // Test 4: Fuse input test (requires new reset)
        test_num = 4;
        $display("\nTest %0d: Fuse input overrides default", test_num);
        fuse_valid = 1;
        fuse_id = 128'h12345678_9ABCDEF0_FEDCBA98_76543210;
        reset = 1;
        repeat(3) @(posedge clock);
        reset = 0;
        fuse_valid = 0;
        repeat(2) @(posedge clock);
        
        if (device_id == 128'h12345678_9ABCDEF0_FEDCBA98_76543210) begin
            $display("  PASS: Fuse value correctly loaded");
            $display("  Device ID: 0x%h", device_id);
        end else begin
            $display("  FAIL: Fuse value not loaded correctly");
            $display("  Expected: 0x12345678_9ABCDEF0_FEDCBA98_76543210");
            $display("  Got:      0x%h", device_id);
            errors++;
        end
        
        // Test 5: New ID also immutable
        test_num = 5;
        $display("\nTest %0d: New ID is also immutable", test_num);
        captured_id = device_id;
        repeat(10) @(posedge clock);
        
        if (device_id == captured_id) begin
            $display("  PASS: New Device ID remained constant");
        end else begin
            $display("  FAIL: New Device ID changed!");
            errors++;
        end
        
        // Summary
        repeat(5) @(posedge clock);
        $display("\n========================================");
        $display("TEST SUMMARY");
        $display("========================================");
        $display("Total Tests: %0d", test_num);
        $display("Errors:      %0d", errors);
        
        if (errors == 0) begin
            $display("TEST PASSED");
        end else begin
            $display("TEST FAILED");
        end
        $display("========================================");
        
        $finish;
    end
    
    // Timeout watchdog
    initial begin
        #100us;
        $display("ERROR: Simulation timeout!");
        $display("TEST FAILED");
        $finish;
    end

endmodule
