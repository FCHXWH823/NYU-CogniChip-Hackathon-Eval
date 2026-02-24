// Hardware Root of Trust - Testbench Top Module
// Top-level module that instantiates DUT and connects to UVM testbench

`include "uvm_macros.svh"

module rot_tb_top;
    
    import uvm_pkg::*;
    import rot_transaction_pkg::*;
    import rot_control_agent_pkg::*;
    import rot_crypto_agents_pkg::*;
    import rot_security_monitor_pkg::*;
    import rot_env_pkg::*;
    import rot_base_test_pkg::*;
    
    // ====================================================================
    // Clock and Reset Generation
    // ====================================================================
    logic clock;
    logic reset;
    
    // Clock generation - 100MHz (10ns period)
    initial begin
        clock = 0;
        forever #5ns clock = ~clock;
    end
    
    // Reset generation
    initial begin
        reset = 1;
        repeat(10) @(posedge clock);
        reset = 0;
        $display("LOG: %0t : INFO : rot_tb_top : reset : expected_value: 0 actual_value: 0", $time);
    end
    
    // ====================================================================
    // Interface Instantiation
    // ====================================================================
    rot_if vif (
        .clock(clock),
        .reset(reset)
    );
    
    // ====================================================================
    // DUT Instantiation
    // ====================================================================
    root_of_trust_top dut (
        .clock(clock),
        .reset(reset),
        
        // Control Interface
        .system_init(vif.system_init),
        .derive_new_keys(vif.derive_new_keys),
        .zeroize_all(vif.zeroize_all),
        
        // PUF DUS Interface
        .puf_dus_enroll(vif.puf_dus_enroll),
        .puf_dus_regenerate(vif.puf_dus_regenerate),
        .puf_dus_helper_in(vif.puf_dus_helper_in),
        .puf_dus_helper_out(vif.puf_dus_helper_out),
        .puf_dus_helper_valid(vif.puf_dus_helper_valid),
        
        // PUF Device ID Interface
        .puf_devid_enroll(vif.puf_devid_enroll),
        .puf_devid_read(vif.puf_devid_read),
        .device_id(vif.device_id),
        .device_id_valid(vif.device_id_valid),
        
        // SHA-256 Interface
        .sha_start(vif.sha_start),
        .sha_init(vif.sha_init),
        .sha_message(vif.sha_message),
        .sha_ready(vif.sha_ready),
        .sha_valid(vif.sha_valid),
        .sha_hash(vif.sha_hash),
        
        // HMAC-SHA-256 Interface
        .hmac_start(vif.hmac_start),
        .hmac_init(vif.hmac_init),
        .hmac_final(vif.hmac_final),
        .hmac_message(vif.hmac_message),
        .hmac_ready(vif.hmac_ready),
        .hmac_valid(vif.hmac_valid),
        .hmac_mac(vif.hmac_mac),
        
        // AES-CTR Interface
        .aes_start(vif.aes_start),
        .aes_init(vif.aes_init),
        .aes_nonce(vif.aes_nonce),
        .aes_counter_init(vif.aes_counter_init),
        .aes_data_in(vif.aes_data_in),
        .aes_ready(vif.aes_ready),
        .aes_valid(vif.aes_valid),
        .aes_data_out(vif.aes_data_out),
        
        // System Status
        .system_ready(vif.system_ready),
        .keys_active(vif.keys_active),
        .security_fault(vif.security_fault)
    );
    
    // ====================================================================
    // Waveform Dump
    // ====================================================================
    initial begin
        $dumpfile("dumpfile.fst");
        $dumpvars(0);
    end
    
    // ====================================================================
    // UVM Configuration and Test Execution
    // ====================================================================
    initial begin
        // Set virtual interface in config DB
        uvm_config_db#(virtual rot_if)::set(null, "*", "vif", vif);
        
        // Print test start banner
        $display("TEST START");
        $display("=======================================================");
        $display("  Hardware Root of Trust - UVM Verification");
        $display("  Testbench: %m");
        $display("  Time: %0t", $time);
        $display("=======================================================");
        
        // Run the test
        run_test();
    end
    
    // ====================================================================
    // Timeout Watchdog
    // ====================================================================
    initial begin
        #100ms;  // 100ms timeout
        $display("LOG: %0t : ERROR : rot_tb_top : timeout : expected_value: test_complete actual_value: timeout", $time);
        $display("ERROR");
        $fatal(1, "Test timeout - simulation ran for 100ms without completing");
    end
    
    // ====================================================================
    // Final Block - Test Completion
    // ====================================================================
    final begin
        $display("=======================================================");
        $display("  Test completed at time: %0t", $time);
        $display("=======================================================");
    end
    
endmodule : rot_tb_top
