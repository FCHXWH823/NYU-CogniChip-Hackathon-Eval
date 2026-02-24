// ===========================================================================
// Testbench for ttc3_dus_storage
// ===========================================================================
// Tests Device Unique Secret storage module
// - Write-once semantics
// - DUS validity flag
// - KDF request handling
// ===========================================================================

`timescale 1ns/1ps

module tb_ttc3_dus_storage;

    // Parameters
    parameter DUS_WIDTH = 256;
    parameter CLK_PERIOD = 10; // 100MHz
    
    // DUT signals
    logic                 clock;
    logic                 reset;
    logic                 write_enable;
    logic [DUS_WIDTH-1:0] write_data;
    logic                 dus_valid;
    logic                 kdf_request;
    logic [DUS_WIDTH-1:0] kdf_dus;
    
    // Test control
    int test_num = 0;
    int errors = 0;
    logic [DUS_WIDTH-1:0] expected_dus;  // Store original DUS for comparison
    
    // DUT instantiation
    ttc3_dus_storage #(
        .DUS_WIDTH(DUS_WIDTH)
    ) dut (
        .clock(clock),
        .reset(reset),
        .write_enable(write_enable),
        .write_data(write_data),
        .dus_valid(dus_valid),
        .kdf_request(kdf_request),
        .kdf_dus(kdf_dus)
    );
    
    // Clock generation
    initial begin
        clock = 0;
        forever #(CLK_PERIOD/2) clock = ~clock;
    end
    
    // Waveform dump
    initial begin
        $dumpfile("tb_ttc3_dus_storage.vcd");
        $dumpvars(0, tb_ttc3_dus_storage);
    end
    
    // Test stimulus
    initial begin
        $display("TEST START");
        $display("========================================");
        $display("Testing TTC3 DUS Storage Module");
        $display("========================================");
        
        // Initialize
        reset = 1;
        write_enable = 0;
        write_data = '0;
        kdf_request = 0;
        
        // Reset
        repeat(5) @(posedge clock);
        reset = 0;
        @(posedge clock);
        
        // Test 1: Write DUS
        test_num = 1;
        $display("\nTest %0d: Write DUS and check valid flag", test_num);
        write_enable = 1;
        write_data = 256'hDEADBEEF_CAFEBABE_0123456789ABCDEF_FEDCBA9876543210_DEADBEEF_CAFEBABE_01234567_89ABCDEF;
        expected_dus = write_data;  // Save the original DUS value
        @(posedge clock);
        write_enable = 0;
        @(posedge clock);
        
        if (dus_valid) begin
            $display("  PASS: DUS valid flag asserted");
        end else begin
            $display("  FAIL: DUS valid flag not asserted");
            errors++;
        end
        
        // Test 2: Try to re-write DUS (should fail - write-once)
        test_num = 2;
        $display("\nTest %0d: Attempt to re-write DUS (should be locked)", test_num);
        write_enable = 1;
        write_data = 256'h1111111111111111111111111111111111111111111111111111111111111111;
        @(posedge clock);
        write_enable = 0;
        @(posedge clock);
        
        if (dus_valid) begin
            $display("  PASS: DUS remains locked (write-once behavior)");
        end else begin
            $display("  FAIL: DUS lock violated");
            errors++;
        end
        
        // Test 3: KDF request without access
        test_num = 3;
        $display("\nTest %0d: KDF output without request", test_num);
        kdf_request = 0;
        @(posedge clock);
        
        if (kdf_dus == '0) begin
            $display("  PASS: KDF DUS is zero when not requested");
        end else begin
            $display("  FAIL: KDF DUS leaking without request");
            errors++;
        end
        
        // Test 4: KDF request with access
        test_num = 4;
        $display("\nTest %0d: KDF request grants access", test_num);
        kdf_request = 1;
        @(posedge clock);
        
        if (kdf_dus == expected_dus) begin
            $display("  PASS: KDF receives correct DUS when requested");
        end else begin
            $display("  FAIL: KDF DUS mismatch");
            $display("  Expected: 0x%h", expected_dus);
            $display("  Got:      0x%h", kdf_dus);
            errors++;
        end
        
        kdf_request = 0;
        @(posedge clock);
        
        // Test 5: Reset clears DUS
        test_num = 5;
        $display("\nTest %0d: Reset clears DUS", test_num);
        reset = 1;
        repeat(3) @(posedge clock);
        reset = 0;
        @(posedge clock);
        
        if (!dus_valid) begin
            $display("  PASS: DUS cleared and not valid after reset");
        end else begin
            $display("  FAIL: DUS still valid after reset");
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
