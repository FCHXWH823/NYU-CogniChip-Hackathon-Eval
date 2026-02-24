// ===========================================================================
// Testbench for ttc3_top (Integration Test)
// ===========================================================================
// Tests complete TTC3 system
// - DUS initialization
// - Device ID retrieval
// - SHA-256 operation
// - HMAC operation
// - AES-CTR operation  
// - Key derivation
// ===========================================================================

`timescale 1ns/1ps

module tb_ttc3_top;

    // Parameters
    parameter DUS_WIDTH = 256;
    parameter DEVICE_ID_WIDTH = 128;
    parameter KEY_WIDTH = 256;
    parameter CLK_PERIOD = 10; // 100MHz
    
    // DUT signals
    logic                      clock;
    logic                      reset;
    logic                      dus_write_enable;
    logic [DUS_WIDTH-1:0]      dus_write_data;
    logic                      device_id_fuse_valid;
    logic [DEVICE_ID_WIDTH-1:0] device_id_fuse_data;
    logic                      cmd_valid;
    logic [2:0]                cmd_op;
    logic [511:0]              cmd_data;
    logic                      cmd_ready;
    logic                      cmd_done;
    logic [511:0]              resp_data;
    logic                      resp_valid;
    
    // Test control
    int test_num = 0;
    int errors = 0;
    
    // Operation codes (from RTL)
    localparam [2:0] OP_NOP        = 3'b000;
    localparam [2:0] OP_GET_ID     = 3'b001;
    localparam [2:0] OP_SHA256     = 3'b010;
    localparam [2:0] OP_HMAC       = 3'b011;
    localparam [2:0] OP_AES_CTR    = 3'b100;
    localparam [2:0] OP_DERIVE_KEY = 3'b101;
    
    // DUT instantiation
    ttc3_top #(
        .DUS_WIDTH(DUS_WIDTH),
        .DEVICE_ID_WIDTH(DEVICE_ID_WIDTH),
        .KEY_WIDTH(KEY_WIDTH)
    ) dut (
        .clock(clock),
        .reset(reset),
        .dus_write_enable(dus_write_enable),
        .dus_write_data(dus_write_data),
        .device_id_fuse_valid(device_id_fuse_valid),
        .device_id_fuse_data(device_id_fuse_data),
        .cmd_valid(cmd_valid),
        .cmd_op(cmd_op),
        .cmd_data(cmd_data),
        .cmd_ready(cmd_ready),
        .cmd_done(cmd_done),
        .resp_data(resp_data),
        .resp_valid(resp_valid)
    );
    
    // Clock generation
    initial begin
        clock = 0;
        forever #(CLK_PERIOD/2) clock = ~clock;
    end
    
    // Waveform dump
    initial begin
        $dumpfile("tb_ttc3_top.vcd");
        $dumpvars(0, tb_ttc3_top);
    end
    
    // Helper task: Initialize DUS
    task init_dus(input [DUS_WIDTH-1:0] secret);
        begin
            $display("  Initializing DUS...");
            dus_write_enable = 1;
            dus_write_data = secret;
            @(posedge clock);
            dus_write_enable = 0;
            @(posedge clock);
            $display("  DUS initialized");
        end
    endtask
    
    // Helper task: Send command and wait for response
    task send_command(input [2:0] op, input [511:0] data, output [511:0] response);
        begin
            // Wait for ready
            while (!cmd_ready) @(posedge clock);
            
            // Issue command
            cmd_valid = 1;
            cmd_op = op;
            cmd_data = data;
            @(posedge clock);
            cmd_valid = 0;
            
            // Wait for response
            while (!resp_valid) @(posedge clock);
            response = resp_data;
            @(posedge clock);
        end
    endtask
    
    // Test stimulus
    initial begin
        $display("TEST START");
        $display("========================================");
        $display("Testing TTC3 Top-Level Integration");
        $display("========================================");
        
        // Initialize
        reset = 1;
        dus_write_enable = 0;
        dus_write_data = '0;
        device_id_fuse_valid = 0;
        device_id_fuse_data = '0;
        cmd_valid = 0;
        cmd_op = OP_NOP;
        cmd_data = '0;
        
        // Reset
        repeat(10) @(posedge clock);
        reset = 0;
        repeat(5) @(posedge clock);
        
        // Test 1: Initialize DUS
        test_num = 1;
        $display("\nTest %0d: Initialize Device Unique Secret", test_num);
        init_dus(256'hDEADBEEF_CAFEBABE_0123456789ABCDEF_FEDCBA9876543210_DEADBEEF_CAFEBABE_0123456789ABCDEF_FEDCBA9876543210);
        $display("  PASS: DUS initialization completed");
        
        // Test 2: Get Device ID
        test_num = 2;
        $display("\nTest %0d: Get Device ID", test_num);
        begin
            logic [511:0] response;
            logic [DEVICE_ID_WIDTH-1:0] device_id;
            
            send_command(OP_GET_ID, '0, response);
            device_id = response[DEVICE_ID_WIDTH-1:0];
            
            if (device_id != '0) begin
                $display("  PASS: Device ID retrieved");
                $display("  Device ID: 0x%h", device_id);
            end else begin
                $display("  FAIL: Device ID is zero");
                errors++;
            end
        end
        
        // Test 3: Device ID Immutability (read again)
        test_num = 3;
        $display("\nTest %0d: Device ID Immutability", test_num);
        begin
            logic [511:0] response1, response2;
            
            send_command(OP_GET_ID, '0, response1);
            send_command(OP_GET_ID, '0, response2);
            
            if (response1[DEVICE_ID_WIDTH-1:0] == response2[DEVICE_ID_WIDTH-1:0]) begin
                $display("  PASS: Device ID is immutable");
            end else begin
                $display("  FAIL: Device ID changed!");
                errors++;
            end
        end
        
        // Test 4: SHA-256 operation
        test_num = 4;
        $display("\nTest %0d: SHA-256 Hash Operation", test_num);
        begin
            logic [511:0] response;
            logic [255:0] hash;
            logic [511:0] test_message = 512'h80000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000;
            
            send_command(OP_SHA256, test_message, response);
            hash = response[255:0];
            
            if (hash != '0) begin
                $display("  PASS: SHA-256 hash computed");
                $display("  Hash (first 64 bits): 0x%h", hash[255:192]);
            end else begin
                $display("  FAIL: SHA-256 returned zero");
                errors++;
            end
        end
        
        // Test 5: HMAC operation
        test_num = 5;
        $display("\nTest %0d: HMAC-SHA256 Operation", test_num);
        begin
            logic [511:0] response;
            logic [255:0] tag;
            logic [511:0] test_message = {256'h0, 256'h48656C6C6F20576F726C64}; // "Hello World"
            
            send_command(OP_HMAC, test_message, response);
            tag = response[255:0];
            
            if (tag != '0) begin
                $display("  PASS: HMAC tag computed");
                $display("  Tag (first 64 bits): 0x%h", tag[255:192]);
            end else begin
                $display("  FAIL: HMAC returned zero");
                errors++;
            end
        end
        
        // Test 6: AES-CTR operation
        test_num = 6;
        $display("\nTest %0d: AES-CTR Encryption", test_num);
        begin
            logic [511:0] response;
            logic [127:0] ciphertext;
            logic [127:0] plaintext = 128'h0123456789ABCDEF_FEDCBA9876543210;
            logic [127:0] counter = 128'h00000000000000000000000000000001;
            logic [511:0] aes_data = {384'h0, plaintext, counter};
            
            send_command(OP_AES_CTR, aes_data, response);
            ciphertext = response[127:0];
            
            if (ciphertext != '0) begin
                $display("  PASS: AES-CTR ciphertext generated");
                $display("  Ciphertext: 0x%h", ciphertext);
            end else begin
                $display("  FAIL: AES-CTR returned zero");
                errors++;
            end
        end
        
        // Test 7: Key Derivation (test operation)
        test_num = 7;
        $display("\nTest %0d: Key Derivation", test_num);
        begin
            logic [511:0] response;
            logic [KEY_WIDTH-1:0] derived_key;
            
            send_command(OP_DERIVE_KEY, '0, response);
            derived_key = response[KEY_WIDTH-1:0];
            
            if (derived_key != '0) begin
                $display("  PASS: Key derived");
                $display("  Derived Key (first 64 bits): 0x%h", derived_key[255:192]);
            end else begin
                $display("  FAIL: Derived key is zero");
                errors++;
            end
        end
        
        // Test 8: Key Derivation Determinism
        test_num = 8;
        $display("\nTest %0d: Key Derivation Determinism", test_num);
        begin
            logic [511:0] response1, response2;
            
            send_command(OP_DERIVE_KEY, '0, response1);
            send_command(OP_DERIVE_KEY, '0, response2);
            
            if (response1[KEY_WIDTH-1:0] == response2[KEY_WIDTH-1:0]) begin
                $display("  PASS: Key derivation is deterministic");
            end else begin
                $display("  FAIL: Key derivation is non-deterministic");
                errors++;
            end
        end
        
        // Summary
        repeat(10) @(posedge clock);
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
        #1ms;
        $display("ERROR: Simulation timeout!");
        $display("TEST FAILED");
        $finish;
    end

endmodule
