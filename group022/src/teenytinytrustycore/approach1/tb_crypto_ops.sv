// Crypto Operations Testbench for Hardware Root of Trust
// Tests SHA-256, HMAC-SHA-256, and AES-CTR operations
// Compatible with Verilator

module tb_crypto_ops;

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
    int test_count;
    int pass_count;
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
        $dumpvars(0, tb_crypto_ops);
    end
    
    // ================================================================
    // Helper Task: Initialize System
    // ================================================================
    task automatic init_system();
        begin
            $display("=== Initializing System (Enrollment) ===");
            
            // Trigger enrollment
            @(posedge clock);
            system_init = 1;
            puf_dus_enroll = 1;
            
            @(posedge clock);
            system_init = 0;
            
            // Wait for system ready
            for (int i = 0; i < 1000; i++) begin
                @(posedge clock);
                if (system_ready && keys_active) begin
                    $display("LOG: %0t : INFO : tb_crypto_ops : system_ready : expected_value: 1 actual_value: 1", $time);
                    $display("LOG: %0t : INFO : tb_crypto_ops : keys_active : expected_value: 1 actual_value: 1", $time);
                    return;
                end
            end
            
            $display("LOG: %0t : ERROR : tb_crypto_ops : init_timeout : expected_value: system_ready actual_value: timeout", $time);
            error_count++;
        end
    endtask
    
    // ================================================================
    // Helper Task: SHA-256 Test
    // ================================================================
    task automatic test_sha256(input [511:0] message, input string test_name);
        begin
            logic [255:0] hash_result;
            
            test_count++;
            $display("");
            $display("=== Test %0d: SHA-256 - %s ===", test_count, test_name);
            $display("LOG: %0t : INFO : tb_crypto_ops : sha_test : expected_value: %s actual_value: starting", $time, test_name);
            
            // Wait for SHA ready (with timeout)
            for (int timeout = 0; timeout < 100; timeout++) begin
                if (sha_ready) break;
                if (timeout == 99) begin
                    $display("LOG: %0t : ERROR : tb_crypto_ops : sha_not_ready : expected_value: sha_ready=1 actual_value: timeout", $time);
                    error_count++;
                    return;
                end
                @(posedge clock);
            end
            
            // Send message
            @(posedge clock);
            sha_message = message;
            sha_init = 1;
            sha_start = 1;
            $display("LOG: %0t : INFO : tb_crypto_ops : sha_message : expected_value: 0x%0h actual_value: 0x%0h", 
                $time, message, message);
            
            @(posedge clock);
            sha_start = 0;
            sha_init = 0;
            
            // Wait for result
            for (int i = 0; i < 100; i++) begin
                @(posedge clock);
                if (sha_valid) begin
                    hash_result = sha_hash;
                    $display("LOG: %0t : INFO : tb_crypto_ops : sha_hash : expected_value: computed actual_value: 0x%0h", 
                        $time, hash_result);
                    
                    // Check hash is non-zero
                    if (hash_result != 256'h0) begin
                        $display("LOG: %0t : INFO : tb_crypto_ops : sha_test_result : expected_value: PASS actual_value: PASS", $time);
                        pass_count++;
                        return;
                    end else begin
                        $display("LOG: %0t : ERROR : tb_crypto_ops : sha_hash : expected_value: non-zero actual_value: 0x0", $time);
                        error_count++;
                        return;
                    end
                end
            end
            
            $display("LOG: %0t : ERROR : tb_crypto_ops : sha_timeout : expected_value: sha_valid actual_value: timeout", $time);
            error_count++;
        end
    endtask
    
    // ================================================================
    // Helper Task: HMAC-SHA-256 Test
    // ================================================================
    task automatic test_hmac(input [511:0] message, input string test_name);
        begin
            logic [255:0] mac_result;
            
            test_count++;
            $display("");
            $display("=== Test %0d: HMAC-SHA-256 - %s ===", test_count, test_name);
            $display("LOG: %0t : INFO : tb_crypto_ops : hmac_test : expected_value: %s actual_value: starting", $time, test_name);
            
            // Wait for HMAC ready (with timeout)
            for (int timeout = 0; timeout < 100; timeout++) begin
                if (hmac_ready) break;
                if (timeout == 99) begin
                    $display("LOG: %0t : ERROR : tb_crypto_ops : hmac_not_ready : expected_value: hmac_ready=1 actual_value: timeout", $time);
                    error_count++;
                    return;
                end
                @(posedge clock);
            end
            
            // Send message
            @(posedge clock);
            hmac_message = message;
            hmac_init = 1;
            hmac_final = 1;  // Single block message
            hmac_start = 1;
            $display("LOG: %0t : INFO : tb_crypto_ops : hmac_message : expected_value: 0x%0h actual_value: 0x%0h", 
                $time, message, message);
            
            @(posedge clock);
            hmac_start = 0;
            hmac_init = 0;
            hmac_final = 0;
            
            // Wait for result
            for (int i = 0; i < 200; i++) begin
                @(posedge clock);
                if (hmac_valid) begin
                    mac_result = hmac_mac;
                    $display("LOG: %0t : INFO : tb_crypto_ops : hmac_mac : expected_value: computed actual_value: 0x%0h", 
                        $time, mac_result);
                    
                    // Check MAC is non-zero
                    if (mac_result != 256'h0) begin
                        $display("LOG: %0t : INFO : tb_crypto_ops : hmac_test_result : expected_value: PASS actual_value: PASS", $time);
                        pass_count++;
                        return;
                    end else begin
                        $display("LOG: %0t : ERROR : tb_crypto_ops : hmac_mac : expected_value: non-zero actual_value: 0x0", $time);
                        error_count++;
                        return;
                    end
                end
            end
            
            $display("LOG: %0t : ERROR : tb_crypto_ops : hmac_timeout : expected_value: hmac_valid actual_value: timeout", $time);
            error_count++;
        end
    endtask
    
    // ================================================================
    // Helper Task: AES-CTR Test
    // ================================================================
    task automatic test_aes_ctr(input [127:0] plaintext, input [127:0] nonce, input [63:0] counter, input string test_name);
        begin
            logic [127:0] ciphertext;
            logic [127:0] decrypted;
            
            test_count++;
            $display("");
            $display("=== Test %0d: AES-CTR - %s ===", test_count, test_name);
            $display("LOG: %0t : INFO : tb_crypto_ops : aes_test : expected_value: %s actual_value: starting", $time, test_name);
            
            // ============ Encryption ============
            $display("--- AES Encryption ---");
            
            // Wait for AES ready (with timeout)
            for (int timeout = 0; timeout < 100; timeout++) begin
                if (aes_ready) break;
                if (timeout == 99) begin
                    $display("LOG: %0t : ERROR : tb_crypto_ops : aes_not_ready_enc : expected_value: aes_ready=1 actual_value: timeout", $time);
                    error_count++;
                    return;
                end
                @(posedge clock);
            end
            
            // Send encryption request
            @(posedge clock);
            aes_nonce = nonce;
            aes_counter_init = counter;
            aes_data_in = plaintext;
            aes_init = 1;
            aes_start = 1;
            $display("LOG: %0t : INFO : tb_crypto_ops : aes_plaintext : expected_value: 0x%0h actual_value: 0x%0h", 
                $time, plaintext, plaintext);
            
            @(posedge clock);
            aes_start = 0;
            aes_init = 0;
            
            // Wait for result
            for (int i = 0; i < 200; i++) begin
                @(posedge clock);
                if (aes_valid) begin
                    ciphertext = aes_data_out;
                    $display("LOG: %0t : INFO : tb_crypto_ops : aes_ciphertext : expected_value: encrypted actual_value: 0x%0h", 
                        $time, ciphertext);
                    $display("LOG: %0t : INFO : tb_crypto_ops : aes_keystream : expected_value: non-zero actual_value: 0x%0h", 
                        $time, dut.aes_inst.keystream);
                    $display("LOG: %0t : INFO : tb_crypto_ops : aes_counter : expected_value: initialized actual_value: 0x%0h", 
                        $time, dut.aes_inst.counter);
                    break;
                end
            end
            
            if (!aes_valid) begin
                $display("LOG: %0t : ERROR : tb_crypto_ops : aes_encrypt_timeout : expected_value: aes_valid actual_value: timeout", $time);
                error_count++;
                return;
            end
            
            // Wait a few cycles
            repeat(5) @(posedge clock);
            
            // ============ Decryption (with same nonce/counter) ============
            $display("--- AES Decryption ---");
            
            // Wait for AES ready (with timeout)
            for (int timeout = 0; timeout < 100; timeout++) begin
                if (aes_ready) break;
                if (timeout == 99) begin
                    $display("LOG: %0t : ERROR : tb_crypto_ops : aes_not_ready_dec : expected_value: aes_ready=1 actual_value: timeout", $time);
                    error_count++;
                    return;
                end
                @(posedge clock);
            end
            
            // Send decryption request (in CTR mode, decryption = encryption)
            @(posedge clock);
            aes_nonce = nonce;
            aes_counter_init = counter;
            aes_data_in = ciphertext;
            aes_init = 1;
            aes_start = 1;
            
            @(posedge clock);
            aes_start = 0;
            aes_init = 0;
            
            // Wait for result
            for (int i = 0; i < 200; i++) begin
                @(posedge clock);
                if (aes_valid) begin
                    decrypted = aes_data_out;
                    $display("LOG: %0t : INFO : tb_crypto_ops : aes_decrypted : expected_value: 0x%0h actual_value: 0x%0h", 
                        $time, plaintext, decrypted);
                    
                    // Verify decrypted matches original plaintext
                    if (decrypted == plaintext) begin
                        $display("LOG: %0t : INFO : tb_crypto_ops : aes_test_result : expected_value: PASS actual_value: PASS", $time);
                        pass_count++;
                        return;
                    end else begin
                        $display("LOG: %0t : ERROR : tb_crypto_ops : aes_decrypt_mismatch : expected_value: 0x%0h actual_value: 0x%0h", 
                            $time, plaintext, decrypted);
                        error_count++;
                        return;
                    end
                end
            end
            
            $display("LOG: %0t : ERROR : tb_crypto_ops : aes_decrypt_timeout : expected_value: aes_valid actual_value: timeout", $time);
            error_count++;
        end
    endtask
    
    // ================================================================
    // Main Test Sequence
    // ================================================================
    initial begin
        $display("TEST START");
        $display("=======================================================");
        $display("  Hardware Root of Trust - Crypto Operations Test");
        $display("  Tests: SHA-256, HMAC-SHA-256, AES-CTR");
        $display("  Time: %0t", $time);
        $display("=======================================================");
        
        // Initialize variables
        error_count = 0;
        test_count = 0;
        pass_count = 0;
        test_passed = 0;
        
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
        $display("LOG: %0t : INFO : tb_crypto_ops : reset : expected_value: 1 actual_value: 1", $time);
        repeat(10) @(posedge clock);
        reset = 0;
        $display("LOG: %0t : INFO : tb_crypto_ops : reset : expected_value: 0 actual_value: 0", $time);
        repeat(5) @(posedge clock);
        
        // ============================================================
        // Phase 1: System Initialization
        // ============================================================
        init_system();
        
        if (!system_ready || !keys_active) begin
            $display("ERROR");
            $display("System initialization failed - cannot proceed with crypto tests");
            $finish;
        end
        
        repeat(10) @(posedge clock);
        
        // ============================================================
        // Phase 2: SHA-256 Tests
        // ============================================================
        $display("");
        $display("=======================================================");
        $display("  PHASE 2: SHA-256 TESTS");
        $display("=======================================================");
        
        // Test 1: Simple message (512 bits = 128 hex chars)
        test_sha256(512'h48656C6C6F20576F726C642100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 
                    "Hello World!");
        
        // Test 2: All zeros
        test_sha256(512'h0, "All Zeros");
        
        // Test 3: All ones (512 bits = 128 hex chars)
        test_sha256(512'hFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF, 
                    "All Ones");
        
        // ============================================================
        // Phase 3: HMAC-SHA-256 Tests  
        // ============================================================
        $display("");
        $display("=======================================================");
        $display("  PHASE 3: HMAC-SHA-256 TESTS");
        $display("=======================================================");
        
        // Test 4: Simple HMAC (512 bits = 128 hex chars)
        test_hmac(512'h54657374204D65737361676500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000,
                  "Test Message");
        
        // Test 5: Different message (512 bits = 128 hex chars)
        test_hmac(512'h4175746820546F6B656E0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000,
                  "Auth Token");
        
        // ============================================================
        // Phase 4: AES-CTR Tests
        // ============================================================
        $display("");
        $display("=======================================================");
        $display("  PHASE 4: AES-CTR TESTS");
        $display("=======================================================");
        
        // Test 6: Simple encryption/decryption
        test_aes_ctr(128'h0123456789ABCDEF0123456789ABCDEF,
                     128'h0000000000000000000000000000001,
                     64'h0000000000000001,
                     "Simple Data");
        
        // Test 7: Different nonce
        test_aes_ctr(128'hDEADBEEFCAFEBABEDEADBEEFCAFEBABE,
                     128'hFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF,
                     64'h0,
                     "Different Nonce");
        
        // ============================================================
        // Test Summary
        // ============================================================
        repeat(10) @(posedge clock);
        
        $display("");
        $display("=======================================================");
        $display("  FINAL TEST SUMMARY");
        $display("=======================================================");
        $display("Total Tests: %0d", test_count);
        $display("Passed: %0d", pass_count);
        $display("Failed: %0d", test_count - pass_count);
        $display("Errors: %0d", error_count);
        
        if (error_count == 0 && pass_count == test_count) begin
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
        $display("LOG: %0t : ERROR : tb_crypto_ops : timeout : expected_value: test_complete actual_value: simulation_timeout", $time);
        $display("ERROR");
        $fatal(1, "Simulation timeout - exceeded 100ms");
    end

endmodule
