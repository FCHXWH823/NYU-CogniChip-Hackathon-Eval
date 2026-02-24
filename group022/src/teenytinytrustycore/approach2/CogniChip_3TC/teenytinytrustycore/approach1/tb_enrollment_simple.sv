// Simple Enrollment Testbench for Hardware Root of Trust
// Compatible with Verilator
// Tests PUF enrollment and system initialization

module tb_enrollment_simple;

    // Clock and reset
    logic clock;
    logic reset;
    
    // Control signals
    logic system_init;
    logic derive_new_keys;
    logic zeroize_all;
    logic puf_dus_enroll;
    logic puf_dus_regenerate;
    logic [255:0] puf_dus_helper_in;
    logic [255:0] puf_dus_helper_out;
    logic puf_dus_helper_valid;
    
    // PUF Device ID
    logic puf_devid_enroll;
    logic puf_devid_read;
    logic [127:0] device_id;
    logic device_id_valid;
    
    // SHA-256 interface
    logic sha_start;
    logic sha_init;
    logic [511:0] sha_message;
    logic sha_ready;
    logic sha_valid;
    logic [255:0] sha_hash;
    
    // HMAC-SHA-256 interface
    logic hmac_start;
    logic hmac_init;
    logic hmac_final;
    logic [511:0] hmac_message;
    logic hmac_ready;
    logic hmac_valid;
    logic [255:0] hmac_mac;
    
    // AES-CTR interface
    logic aes_start;
    logic aes_init;
    logic [127:0] aes_nonce;
    logic [63:0] aes_counter_init;
    logic [127:0] aes_data_in;
    logic aes_ready;
    logic aes_valid;
    logic [127:0] aes_data_out;
    
    // System status
    logic system_ready;
    logic keys_active;
    logic security_fault;
    
    // Test control
    int cycle_count;
    int error_count;
    logic test_passed;
    
    // ================================================================
    // DUT Instantiation
    // ================================================================
    root_of_trust_top dut (
        .clock(clock),
        .reset(reset),
        .system_init(system_init),
        .derive_new_keys(derive_new_keys),
        .zeroize_all(zeroize_all),
        .puf_dus_enroll(puf_dus_enroll),
        .puf_dus_regenerate(puf_dus_regenerate),
        .puf_dus_helper_in(puf_dus_helper_in),
        .puf_dus_helper_out(puf_dus_helper_out),
        .puf_dus_helper_valid(puf_dus_helper_valid),
        .puf_devid_enroll(puf_devid_enroll),
        .puf_devid_read(puf_devid_read),
        .device_id(device_id),
        .device_id_valid(device_id_valid),
        .sha_start(sha_start),
        .sha_init(sha_init),
        .sha_message(sha_message),
        .sha_ready(sha_ready),
        .sha_valid(sha_valid),
        .sha_hash(sha_hash),
        .hmac_start(hmac_start),
        .hmac_init(hmac_init),
        .hmac_final(hmac_final),
        .hmac_message(hmac_message),
        .hmac_ready(hmac_ready),
        .hmac_valid(hmac_valid),
        .hmac_mac(hmac_mac),
        .aes_start(aes_start),
        .aes_init(aes_init),
        .aes_nonce(aes_nonce),
        .aes_counter_init(aes_counter_init),
        .aes_data_in(aes_data_in),
        .aes_ready(aes_ready),
        .aes_valid(aes_valid),
        .aes_data_out(aes_data_out),
        .system_ready(system_ready),
        .keys_active(keys_active),
        .security_fault(security_fault)
    );
    
    // ================================================================
    // Clock Generation - 100MHz (10ns period)
    // ================================================================
    initial begin
        clock = 0;
        forever #5 clock = ~clock;
    end
    
    // ================================================================
    // Waveform Dump
    // ================================================================
    initial begin
        $dumpfile("dumpfile.fst");
        $dumpvars(0, tb_enrollment_simple);
    end
    
    // ================================================================
    // Monitor Internal State
    // ================================================================
    always @(posedge clock) begin
        // Monitor state machine transitions
        if (dut.init_state != dut.init_next_state) begin
            $display("LOG: %0t : INFO : tb_enrollment_simple : state_transition : expected_value: transition actual_value: %0s_to_%0s", 
                $time, dut.init_state.name(), dut.init_next_state.name());
        end
        
        // Monitor DUS PUF state
        if (dut.puf_dus_inst.state != dut.puf_dus_inst.next_state) begin
            $display("LOG: %0t : INFO : tb_enrollment_simple : puf_dus_state : expected_value: transition actual_value: %0s_to_%0s",
                $time, dut.puf_dus_inst.state.name(), dut.puf_dus_inst.next_state.name());
        end
        
        // Monitor DUS error
        if (dut.dus_error) begin
            $display("LOG: %0t : ERROR : tb_enrollment_simple : dus_error : expected_value: 0 actual_value: 1", $time);
        end
        
        // Monitor DUS valid
        if (dut.dus_valid) begin
            $display("LOG: %0t : INFO : tb_enrollment_simple : dus_valid : expected_value: 1 actual_value: 1", $time);
        end
        
        // Monitor KDF state
        if (dut.kdf_inst.state != dut.kdf_inst.next_state) begin
            $display("LOG: %0t : INFO : tb_enrollment_simple : kdf_state : expected_value: transition actual_value: %0s_to_%0s",
                $time, dut.kdf_inst.state.name(), dut.kdf_inst.next_state.name());
        end
        
        // Monitor KDF valid
        if (dut.kdf_valid) begin
            $display("LOG: %0t : INFO : tb_enrollment_simple : kdf_valid : expected_value: 1 actual_value: 1", $time);
        end
        
        // Monitor Key Distributor state
        if (dut.key_dist_inst.state != dut.key_dist_inst.next_state) begin
            $display("LOG: %0t : INFO : tb_enrollment_simple : key_dist_state : expected_value: transition actual_value: %0s_to_%0s",
                $time, dut.key_dist_inst.state.name(), dut.key_dist_inst.next_state.name());
        end
        
        // Monitor keys_active
        if (dut.keys_active) begin
            $display("LOG: %0t : INFO : tb_enrollment_simple : keys_active : expected_value: 1 actual_value: 1", $time);
        end
    end
    
    // ================================================================
    // Main Test Sequence
    // ================================================================
    initial begin
        $display("TEST START");
        $display("=======================================================");
        $display("  Hardware Root of Trust - Enrollment Test");
        $display("  Testbench: Simple Non-UVM Version");
        $display("  Time: %0t", $time);
        $display("=======================================================");
        
        // Initialize variables
        error_count = 0;
        test_passed = 0;
        cycle_count = 0;
        
        // Initialize all control signals
        system_init = 0;
        derive_new_keys = 0;
        zeroize_all = 0;
        puf_dus_enroll = 0;
        puf_dus_regenerate = 0;
        puf_dus_helper_in = 256'h0;
        puf_devid_enroll = 0;
        puf_devid_read = 0;
        sha_start = 0;
        sha_init = 0;
        sha_message = 512'h0;
        hmac_start = 0;
        hmac_init = 0;
        hmac_final = 0;
        hmac_message = 512'h0;
        aes_start = 0;
        aes_init = 0;
        aes_nonce = 128'h0;
        aes_counter_init = 64'h0;
        aes_data_in = 128'h0;
        
        // Apply reset
        reset = 1;
        $display("LOG: %0t : INFO : tb_enrollment_simple : reset : expected_value: 1 actual_value: %0d", $time, reset);
        repeat(10) @(posedge clock);
        reset = 0;
        $display("LOG: %0t : INFO : tb_enrollment_simple : reset : expected_value: 0 actual_value: %0d", $time, reset);
        repeat(5) @(posedge clock);
        
        // ============================================================
        // Test 1: PUF Enrollment
        // ============================================================
        $display("");
        $display("=== Test 1: PUF Enrollment ===");
        $display("LOG: %0t : INFO : tb_enrollment_simple : test_phase : expected_value: enrollment actual_value: enrollment", $time);
        
        // Trigger system initialization with enrollment
        // Keep control signals asserted until initialization completes
        @(posedge clock);
        system_init = 1;
        puf_dus_enroll = 1;
        $display("LOG: %0t : INFO : tb_enrollment_simple : system_init : expected_value: 1 actual_value: %0d", $time, system_init);
        $display("LOG: %0t : INFO : tb_enrollment_simple : puf_dus_enroll : expected_value: 1 actual_value: %0d", $time, puf_dus_enroll);
        
        // Pulse system_init but keep puf_dus_enroll asserted
        @(posedge clock);
        system_init = 0;
        
        // Wait for system to initialize (max 5000 cycles)
        // Increased timeout for KDF and key distribution
        fork
            begin
                for (cycle_count = 0; cycle_count < 5000; cycle_count++) begin
                    @(posedge clock);
                    
                    // Deassert puf_dus_enroll only when system is fully ready
                    if (system_ready && keys_active && puf_dus_enroll) begin
                        puf_dus_enroll = 0;
                        $display("LOG: %0t : INFO : tb_enrollment_simple : puf_dus_enroll : expected_value: 0 actual_value: 0 (system_ready)", $time);
                    end
                    
                    // Check for helper data valid
                    if (puf_dus_helper_valid) begin
                        $display("LOG: %0t : INFO : tb_enrollment_simple : puf_dus_helper_valid : expected_value: 1 actual_value: 1", $time);
                        $display("LOG: %0t : INFO : tb_enrollment_simple : puf_dus_helper_out : expected_value: non-zero actual_value: 0x%0h", $time, puf_dus_helper_out);
                        if (puf_dus_helper_out == 256'h0) begin
                            $display("LOG: %0t : WARNING : tb_enrollment_simple : puf_dus_helper_out : expected_value: non-zero actual_value: 0x0", $time);
                        end
                    end
                    
                    // Check for device ID valid
                    if (device_id_valid) begin
                        $display("LOG: %0t : INFO : tb_enrollment_simple : device_id_valid : expected_value: 1 actual_value: 1", $time);
                        $display("LOG: %0t : INFO : tb_enrollment_simple : device_id : expected_value: non-zero actual_value: 0x%0h", $time, device_id);
                        if (device_id == 128'h0) begin
                            $display("LOG: %0t : WARNING : tb_enrollment_simple : device_id : expected_value: non-zero actual_value: 0x0", $time);
                        end
                    end
                    
                    // Check for system ready
                    if (system_ready && keys_active) begin
                        $display("LOG: %0t : INFO : tb_enrollment_simple : system_ready : expected_value: 1 actual_value: 1", $time);
                        $display("LOG: %0t : INFO : tb_enrollment_simple : keys_active : expected_value: 1 actual_value: 1", $time);
                        $display("=== Enrollment Complete at cycle %0d ===", cycle_count);
                        break;
                    end
                    
                    // Check for errors
                    if (security_fault) begin
                        $display("LOG: %0t : ERROR : tb_enrollment_simple : security_fault : expected_value: 0 actual_value: 1", $time);
                        $display("ERROR");
                        error_count++;
                        break;
                    end
                end
                
                // Check if timeout
                if (cycle_count >= 5000) begin
                    $display("LOG: %0t : ERROR : tb_enrollment_simple : timeout : expected_value: system_ready actual_value: timeout_after_5000_cycles", $time);
                    $display("ERROR");
                    error_count++;
                end
            end
        join
        
        // ============================================================
        // Verify Final State
        // ============================================================
        repeat(10) @(posedge clock);
        
        $display("");
        $display("=== Final State Verification ===");
        
        // Check system_ready
        if (system_ready) begin
            $display("LOG: %0t : INFO : tb_enrollment_simple : system_ready : expected_value: 1 actual_value: 1", $time);
        end else begin
            $display("LOG: %0t : ERROR : tb_enrollment_simple : system_ready : expected_value: 1 actual_value: 0", $time);
            error_count++;
        end
        
        // Check keys_active
        if (keys_active) begin
            $display("LOG: %0t : INFO : tb_enrollment_simple : keys_active : expected_value: 1 actual_value: 1", $time);
        end else begin
            $display("LOG: %0t : ERROR : tb_enrollment_simple : keys_active : expected_value: 1 actual_value: 0", $time);
            error_count++;
        end
        
        // Check no security fault
        if (!security_fault) begin
            $display("LOG: %0t : INFO : tb_enrollment_simple : security_fault : expected_value: 0 actual_value: 0", $time);
        end else begin
            $display("LOG: %0t : ERROR : tb_enrollment_simple : security_fault : expected_value: 0 actual_value: 1", $time);
            error_count++;
        end
        
        // Check helper data was generated
        if (puf_dus_helper_out != 256'h0) begin
            $display("LOG: %0t : INFO : tb_enrollment_simple : puf_dus_helper_out : expected_value: non-zero actual_value: VALID", $time);
        end else begin
            $display("LOG: %0t : WARNING : tb_enrollment_simple : puf_dus_helper_out : expected_value: non-zero actual_value: 0x0", $time);
        end
        
        // Check device ID was generated
        if (device_id != 128'h0) begin
            $display("LOG: %0t : INFO : tb_enrollment_simple : device_id : expected_value: non-zero actual_value: VALID", $time);
        end else begin
            $display("LOG: %0t : WARNING : tb_enrollment_simple : device_id : expected_value: non-zero actual_value: 0x0", $time);
        end
        
        // ============================================================
        // Test Summary
        // ============================================================
        repeat(10) @(posedge clock);
        
        $display("");
        $display("=======================================================");
        $display("  TEST SUMMARY");
        $display("=======================================================");
        $display("Total Cycles: %0d", cycle_count);
        $display("Errors: %0d", error_count);
        
        if (error_count == 0 && system_ready && keys_active) begin
            $display("TEST PASSED");
            test_passed = 1;
        end else begin
            $display("ERROR");
            $display("TEST FAILED");
            test_passed = 0;
        end
        
        $display("=======================================================");
        $display("Simulation ended at time: %0t", $time);
        $display("=======================================================");
        
        // Finish simulation
        #100;
        $finish;
    end
    
    // ================================================================
    // Timeout Watchdog
    // ================================================================
    initial begin
        #100ms;  // 100ms timeout
        $display("LOG: %0t : ERROR : tb_enrollment_simple : timeout : expected_value: test_complete actual_value: simulation_timeout", $time);
        $display("ERROR");
        $fatal(1, "Simulation timeout - exceeded 100ms");
    end

endmodule
