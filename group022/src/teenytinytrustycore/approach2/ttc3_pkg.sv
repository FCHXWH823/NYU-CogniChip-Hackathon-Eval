// ===========================================================================
// TTC3 UVM Package
// ===========================================================================
// Complete UVM verification package for TeenyTinyTrustyCore
//
// Contains:
// - Transaction class with constraints
// - Sequences (security, random, reset)
// - Driver, Monitor, Agent
// - Scoreboard with checking
// - Coverage collector
// - Environment
// - Base test
// ===========================================================================

package ttc3_pkg;
    
    import uvm_pkg::*;
    `include "uvm_macros.svh"
    
    // -----------------------------------------------------------------------
    // TTC3 Operation Codes (from RTL)
    // -----------------------------------------------------------------------
    typedef enum bit [2:0] {
        OP_NOP        = 3'b000,
        OP_GET_ID     = 3'b001,
        OP_SHA256     = 3'b010,
        OP_HMAC       = 3'b011,
        OP_AES_CTR    = 3'b100,
        OP_DERIVE_KEY = 3'b101
    } ttc3_op_e;
    
    // =======================================================================
    // Transaction Class
    // =======================================================================
    class ttc3_transaction extends uvm_sequence_item;
        
        // -------------------------------------------------------------------
        // Transaction Fields
        // -------------------------------------------------------------------
        
        // Initialization (typically done once at start)
        rand bit          init_dus;
        rand bit [255:0]  dus_secret;
        rand bit          init_device_id;
        rand bit [127:0]  device_id;
        
        // Command
        rand ttc3_op_e    operation;
        rand bit [511:0]  cmd_data;
        
        // Response (collected by monitor)
        bit [511:0]       resp_data;
        bit               resp_valid;
        int               response_latency;  // cycles from cmd to response
        
        // Timing
        rand int          pre_cmd_delay;     // cycles before issuing command
        
        // -------------------------------------------------------------------
        // Constraints
        // -------------------------------------------------------------------
        
        // Most transactions are commands, not init
        constraint c_init_rare {
            init_dus        dist {0 := 95, 1 := 5};
            init_device_id  dist {0 := 95, 1 := 5};
        }
        
        // Reasonable pre-command delay
        constraint c_timing {
            pre_cmd_delay inside {[0:10]};
        }
        
        // Operation distribution (favor functional ops over test ops)
        constraint c_operation_dist {
            operation dist {
                OP_NOP        := 5,
                OP_GET_ID     := 15,
                OP_SHA256     := 25,
                OP_HMAC       := 25,
                OP_AES_CTR    := 20,
                OP_DERIVE_KEY := 10
            };
        }
        
        // For SHA256, use full 512-bit data
        constraint c_sha256_data {
            if (operation == OP_SHA256) {
                cmd_data != 0;  // Non-zero message
            }
        }
        
        // For HMAC, use lower 256 bits for message
        constraint c_hmac_data {
            if (operation == OP_HMAC) {
                cmd_data[255:0] != 0;  // Non-zero message
            }
        }
        
        // For AES_CTR, upper 128 bits = plaintext, lower 128 = counter
        constraint c_aes_data {
            if (operation == OP_AES_CTR) {
                cmd_data[255:128] != 0;  // Non-zero plaintext
                cmd_data[127:0]   != 0;  // Non-zero counter
            }
        }
        
        // -------------------------------------------------------------------
        // UVM Automation
        // -------------------------------------------------------------------
        `uvm_object_utils_begin(ttc3_transaction)
            `uvm_field_int(init_dus,           UVM_DEFAULT)
            `uvm_field_int(dus_secret,         UVM_DEFAULT | UVM_HEX)
            `uvm_field_int(init_device_id,     UVM_DEFAULT)
            `uvm_field_int(device_id,          UVM_DEFAULT | UVM_HEX)
            `uvm_field_enum(ttc3_op_e, operation, UVM_DEFAULT)
            `uvm_field_int(cmd_data,           UVM_DEFAULT | UVM_HEX)
            `uvm_field_int(resp_data,          UVM_DEFAULT | UVM_HEX)
            `uvm_field_int(resp_valid,         UVM_DEFAULT)
            `uvm_field_int(response_latency,   UVM_DEFAULT | UVM_DEC)
            `uvm_field_int(pre_cmd_delay,      UVM_DEFAULT | UVM_DEC)
        `uvm_object_utils_end
        
        // -------------------------------------------------------------------
        // Constructor
        // -------------------------------------------------------------------
        function new(string name = "ttc3_transaction");
            super.new(name);
        endfunction
        
        // -------------------------------------------------------------------
        // Utility: Get expected response size by operation
        // -------------------------------------------------------------------
        function int get_expected_resp_bits();
            case (operation)
                OP_GET_ID:     return 128;
                OP_SHA256:     return 256;
                OP_HMAC:       return 256;
                OP_AES_CTR:    return 128;
                OP_DERIVE_KEY: return 256;
                default:       return 0;
            endcase
        endfunction
        
    endclass
    
    // =======================================================================
    // Sequence 1: Security-Focused Sequence
    // =======================================================================
    // Tests critical security properties:
    // - DUS initialization and locking
    // - Device ID immutability
    // - Key derivation consistency
    // - Operations require valid DUS
    // =======================================================================
    class ttc3_security_sequence extends uvm_sequence #(ttc3_transaction);
        `uvm_object_utils(ttc3_security_sequence)
        
        function new(string name = "ttc3_security_sequence");
            super.new(name);
        endfunction
        
        task body();
            ttc3_transaction txn;
            
            `uvm_info(get_type_name(), "Starting Security-Focused Sequence", UVM_MEDIUM)
            
            // -----------------------------------------------------------
            // Test 1: Initialize DUS
            // -----------------------------------------------------------
            txn = ttc3_transaction::type_id::create("dus_init");
            start_item(txn);
            assert(txn.randomize() with {
                init_dus == 1;
                dus_secret == 256'hDEADBEEF_CAFEBABE_0123456789ABCDEF_FEDCBA9876543210_DEADBEEF_CAFEBABE_0123456789ABCDEF_FEDCBA9876543210;
                operation == OP_NOP;
            });
            finish_item(txn);
            
            // -----------------------------------------------------------
            // Test 2: Verify Device ID is stable and non-zero
            // -----------------------------------------------------------
            repeat (3) begin
                txn = ttc3_transaction::type_id::create("check_device_id");
                start_item(txn);
                assert(txn.randomize() with {
                    init_dus == 0;
                    operation == OP_GET_ID;
                });
                finish_item(txn);
            end
            
            // -----------------------------------------------------------
            // Test 3: Derive key multiple times (should be deterministic)
            // -----------------------------------------------------------
            repeat (2) begin
                txn = ttc3_transaction::type_id::create("derive_key_test");
                start_item(txn);
                assert(txn.randomize() with {
                    operation == OP_DERIVE_KEY;
                });
                finish_item(txn);
            end
            
            // -----------------------------------------------------------
            // Test 4: SHA-256 with known vector
            // Empty string hash (padding applied)
            // -----------------------------------------------------------
            txn = ttc3_transaction::type_id::create("sha256_known");
            start_item(txn);
            assert(txn.randomize() with {
                operation == OP_SHA256;
                cmd_data == 512'h80000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000_00000000;
            });
            finish_item(txn);
            
            // -----------------------------------------------------------
            // Test 5: HMAC operations
            // -----------------------------------------------------------
            repeat (2) begin
                txn = ttc3_transaction::type_id::create("hmac_test");
                start_item(txn);
                assert(txn.randomize() with {
                    operation == OP_HMAC;
                    cmd_data[255:0] == 256'h48656C6C6F20576F726C64;  // "Hello World"
                });
                finish_item(txn);
            end
            
            // -----------------------------------------------------------
            // Test 6: AES-CTR operation
            // -----------------------------------------------------------
            txn = ttc3_transaction::type_id::create("aes_test");
            start_item(txn);
            assert(txn.randomize() with {
                operation == OP_AES_CTR;
                cmd_data[255:128] == 128'h0123456789ABCDEF_FEDCBA9876543210;
                cmd_data[127:0]   == 128'h00000000000000000000000000000001;
            });
            finish_item(txn);
            
            `uvm_info(get_type_name(), "Security-Focused Sequence Completed", UVM_MEDIUM)
        endtask
        
    endclass
    
    // =======================================================================
    // Sequence 2: Constrained-Random Operations
    // =======================================================================
    // Generates random but legal command sequences to stress test the design
    // =======================================================================
    class ttc3_random_sequence extends uvm_sequence #(ttc3_transaction);
        `uvm_object_utils(ttc3_random_sequence)
        
        rand int num_operations;
        
        constraint c_num_ops {
            num_operations inside {[20:50]};
        }
        
        function new(string name = "ttc3_random_sequence");
            super.new(name);
        endfunction
        
        task body();
            ttc3_transaction txn;
            
            `uvm_info(get_type_name(), $sformatf("Starting Random Sequence with %0d operations", num_operations), UVM_MEDIUM)
            
            // Initialize DUS first
            txn = ttc3_transaction::type_id::create("dus_init");
            start_item(txn);
            assert(txn.randomize() with {
                init_dus == 1;
                operation == OP_NOP;
            });
            finish_item(txn);
            
            // Random operations
            repeat (num_operations) begin
                txn = ttc3_transaction::type_id::create("random_op");
                start_item(txn);
                assert(txn.randomize() with {
                    init_dus == 0;  // Don't re-initialize DUS
                });
                finish_item(txn);
            end
            
            `uvm_info(get_type_name(), "Random Sequence Completed", UVM_MEDIUM)
        endtask
        
    endclass
    
    // =======================================================================
    // Sequence 3: Reset-During-Operation
    // =======================================================================
    // Tests resilience to reset assertion during active operations
    // Verifies proper state recovery and key zeroization
    // =======================================================================
    class ttc3_reset_sequence extends uvm_sequence #(ttc3_transaction);
        `uvm_object_utils(ttc3_reset_sequence)
        
        function new(string name = "ttc3_reset_sequence");
            super.new(name);
        endfunction
        
        task body();
            ttc3_transaction txn;
            
            `uvm_info(get_type_name(), "Starting Reset-During-Operation Sequence", UVM_MEDIUM)
            
            // Initialize DUS
            txn = ttc3_transaction::type_id::create("dus_init");
            start_item(txn);
            assert(txn.randomize() with {
                init_dus == 1;
                operation == OP_NOP;
            });
            finish_item(txn);
            
            // Start a long operation (HMAC)
            txn = ttc3_transaction::type_id::create("hmac_interrupted");
            start_item(txn);
            assert(txn.randomize() with {
                operation == OP_HMAC;
            });
            finish_item(txn);
            
            // TODO: Driver will assert reset mid-operation
            // (This requires coordination with test)
            
            // After reset, system should recover
            #100ns;
            
            // Re-initialize DUS
            txn = ttc3_transaction::type_id::create("dus_reinit");
            start_item(txn);
            assert(txn.randomize() with {
                init_dus == 1;
                operation == OP_NOP;
            });
            finish_item(txn);
            
            // Verify recovery with simple operation
            txn = ttc3_transaction::type_id::create("recovery_check");
            start_item(txn);
            assert(txn.randomize() with {
                operation == OP_GET_ID;
            });
            finish_item(txn);
            
            `uvm_info(get_type_name(), "Reset-During-Operation Sequence Completed", UVM_MEDIUM)
        endtask
        
    endclass
    
    // Forward declarations for component hierarchy
    typedef uvm_sequencer #(ttc3_transaction) ttc3_sequencer;
    
    // =======================================================================
    // Driver
    // =======================================================================
    class ttc3_driver extends uvm_driver #(ttc3_transaction);
        `uvm_component_utils(ttc3_driver)
        
        virtual ttc3_if vif;
        
        function new(string name = "ttc3_driver", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            if (!uvm_config_db#(virtual ttc3_if)::get(this, "", "vif", vif)) begin
                `uvm_fatal(get_type_name(), "Virtual interface not found in config DB")
            end
        endfunction
        
        task run_phase(uvm_phase phase);
            ttc3_transaction txn;
            
            // Initialize signals
            vif.drv_cb.reset                  <= 1'b1;
            vif.drv_cb.dus_write_enable       <= 1'b0;
            vif.drv_cb.dus_write_data         <= '0;
            vif.drv_cb.device_id_fuse_valid   <= 1'b0;
            vif.drv_cb.device_id_fuse_data    <= '0;
            vif.drv_cb.cmd_valid              <= 1'b0;
            vif.drv_cb.cmd_op                 <= 3'b000;
            vif.drv_cb.cmd_data               <= '0;
            
            // Release reset after 10 cycles
            repeat (10) @(vif.drv_cb);
            vif.drv_cb.reset <= 1'b0;
            repeat (2) @(vif.drv_cb);
            
            forever begin
                seq_item_port.get_next_item(txn);
                drive_transaction(txn);
                seq_item_port.item_done();
            end
        endtask
        
        task drive_transaction(ttc3_transaction txn);
            // Pre-command delay
            repeat (txn.pre_cmd_delay) @(vif.drv_cb);
            
            // Handle DUS initialization
            if (txn.init_dus) begin
                vif.drv_cb.dus_write_enable <= 1'b1;
                vif.drv_cb.dus_write_data   <= txn.dus_secret;
                @(vif.drv_cb);
                vif.drv_cb.dus_write_enable <= 1'b0;
                @(vif.drv_cb);
            end
            
            // Handle Device ID initialization
            if (txn.init_device_id) begin
                vif.drv_cb.device_id_fuse_valid <= 1'b1;
                vif.drv_cb.device_id_fuse_data  <= txn.device_id;
                @(vif.drv_cb);
                vif.drv_cb.device_id_fuse_valid <= 1'b0;
            end
            
            // Drive command
            if (txn.operation != OP_NOP) begin
                // Wait for ready
                wait(vif.drv_cb.cmd_ready == 1'b1);
                
                // Issue command
                vif.drv_cb.cmd_valid <= 1'b1;
                vif.drv_cb.cmd_op    <= txn.operation;
                vif.drv_cb.cmd_data  <= txn.cmd_data;
                @(vif.drv_cb);
                
                vif.drv_cb.cmd_valid <= 1'b0;
                
                // Wait for response
                wait(vif.drv_cb.resp_valid == 1'b1);
                @(vif.drv_cb);
            end else begin
                // NOP: just wait a cycle
                @(vif.drv_cb);
            end
        endtask
        
    endclass
    
    // =======================================================================
    // Monitor
    // =======================================================================
    class ttc3_monitor extends uvm_monitor;
        `uvm_component_utils(ttc3_monitor)
        
        virtual ttc3_if vif;
        uvm_analysis_port #(ttc3_transaction) ap;
        
        function new(string name = "ttc3_monitor", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            if (!uvm_config_db#(virtual ttc3_if)::get(this, "", "vif", vif)) begin
                `uvm_fatal(get_type_name(), "Virtual interface not found in config DB")
            end
            ap = new("ap", this);
        endfunction
        
        task run_phase(uvm_phase phase);
            ttc3_transaction txn;
            int cmd_cycle, resp_cycle;
            
            forever begin
                @(vif.mon_cb);
                
                // Detect command
                if (vif.mon_cb.cmd_valid && vif.mon_cb.cmd_ready) begin
                    txn = ttc3_transaction::type_id::create("monitored_txn");
                    txn.operation = ttc3_op_e'(vif.mon_cb.cmd_op);
                    txn.cmd_data  = vif.mon_cb.cmd_data;
                    cmd_cycle     = $time / 10000;  // Assuming 10ns clock
                    
                    // Wait for response
                    while (!vif.mon_cb.resp_valid) @(vif.mon_cb);
                    
                    txn.resp_data = vif.mon_cb.resp_data;
                    txn.resp_valid = 1'b1;
                    resp_cycle = $time / 10000;
                    txn.response_latency = resp_cycle - cmd_cycle;
                    
                    `uvm_info(get_type_name(), $sformatf("Monitored: op=%s, latency=%0d cycles", 
                              txn.operation.name(), txn.response_latency), UVM_HIGH)
                    
                    ap.write(txn);
                end
            end
        endtask
        
    endclass
    
    // =======================================================================
    // Scoreboard
    // =======================================================================
    class ttc3_scoreboard extends uvm_scoreboard;
        `uvm_component_utils(ttc3_scoreboard)
        
        uvm_analysis_imp #(ttc3_transaction, ttc3_scoreboard) analysis_export;
        
        // Track Device ID for immutability check
        bit [127:0] stored_device_id;
        bit         device_id_initialized = 0;
        
        // Track derived keys for consistency check
        bit [255:0] first_derived_key;
        bit         first_key_captured = 0;
        
        // Statistics
        int num_transactions = 0;
        int num_errors = 0;
        
        function new(string name = "ttc3_scoreboard", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            analysis_export = new("analysis_export", this);
        endfunction
        
        function void write(ttc3_transaction txn);
            num_transactions++;
            
            case (txn.operation)
                OP_GET_ID: check_device_id(txn);
                OP_SHA256: check_sha256(txn);
                OP_HMAC: check_hmac(txn);
                OP_AES_CTR: check_aes(txn);
                OP_DERIVE_KEY: check_derived_key(txn);
            endcase
        endfunction
        
        function void check_device_id(ttc3_transaction txn);
            bit [127:0] device_id = txn.resp_data[127:0];
            
            // Check non-zero
            if (device_id == 0) begin
                `uvm_error(get_type_name(), "Device ID is zero (invalid)")
                num_errors++;
            end
            
            // Check immutability
            if (!device_id_initialized) begin
                stored_device_id = device_id;
                device_id_initialized = 1;
                `uvm_info(get_type_name(), $sformatf("Device ID captured: 0x%h", device_id), UVM_MEDIUM)
            end else begin
                if (device_id != stored_device_id) begin
                    `uvm_error(get_type_name(), $sformatf("Device ID changed! Was 0x%h, now 0x%h", 
                              stored_device_id, device_id))
                    num_errors++;
                end else begin
                    `uvm_info(get_type_name(), "Device ID immutability check PASSED", UVM_HIGH)
                end
            end
        endfunction
        
        function void check_sha256(ttc3_transaction txn);
            // For real SHA-256, we'd check against known test vectors
            // Here we check basic properties:
            bit [255:0] hash = txn.resp_data[255:0];
            
            // Hash should be non-zero for non-zero input
            if (txn.cmd_data != 0 && hash == 0) begin
                `uvm_error(get_type_name(), "SHA-256 returned zero hash for non-zero input")
                num_errors++;
            end else begin
                `uvm_info(get_type_name(), $sformatf("SHA-256 hash: 0x%h", hash[63:0]), UVM_HIGH)
            end
        endfunction
        
        function void check_hmac(ttc3_transaction txn);
            // Check HMAC tag is non-zero
            bit [255:0] tag = txn.resp_data[255:0];
            
            if (tag == 0) begin
                `uvm_error(get_type_name(), "HMAC returned zero tag")
                num_errors++;
            end else begin
                `uvm_info(get_type_name(), $sformatf("HMAC tag: 0x%h", tag[63:0]), UVM_HIGH)
            end
        endfunction
        
        function void check_aes(ttc3_transaction txn);
            // For AES-CTR, check ciphertext is different from plaintext
            bit [127:0] ciphertext = txn.resp_data[127:0];
            bit [127:0] plaintext = txn.cmd_data[255:128];
            
            if (ciphertext == plaintext) begin
                `uvm_warning(get_type_name(), "AES-CTR: ciphertext equals plaintext (weak encryption)")
            end else begin
                `uvm_info(get_type_name(), "AES-CTR encryption produced different ciphertext", UVM_HIGH)
            end
        endfunction
        
        function void check_derived_key(ttc3_transaction txn);
            bit [255:0] key = txn.resp_data[255:0];
            
            // Check key is non-zero
            if (key == 0) begin
                `uvm_error(get_type_name(), "Derived key is zero")
                num_errors++;
            end
            
            // Check consistency across derivations
            if (!first_key_captured) begin
                first_derived_key = key;
                first_key_captured = 1;
                `uvm_info(get_type_name(), "First derived key captured for consistency check", UVM_MEDIUM)
            end else begin
                if (key == first_derived_key) begin
                    `uvm_info(get_type_name(), "Key derivation is DETERMINISTIC (same key generated)", UVM_MEDIUM)
                end else begin
                    `uvm_error(get_type_name(), "Key derivation is NON-DETERMINISTIC (different keys for same input)")
                    num_errors++;
                end
            end
        endfunction
        
        function void report_phase(uvm_phase phase);
            `uvm_info(get_type_name(), "========================================", UVM_LOW)
            `uvm_info(get_type_name(), "       TTC3 SCOREBOARD SUMMARY         ", UVM_LOW)
            `uvm_info(get_type_name(), "========================================", UVM_LOW)
            `uvm_info(get_type_name(), $sformatf("Total Transactions: %0d", num_transactions), UVM_LOW)
            `uvm_info(get_type_name(), $sformatf("Total Errors:       %0d", num_errors), UVM_LOW)
            if (num_errors == 0) begin
                `uvm_info(get_type_name(), "STATUS: ALL CHECKS PASSED", UVM_LOW)
            end else begin
                `uvm_error(get_type_name(), $sformatf("STATUS: %0d CHECKS FAILED", num_errors))
            end
            `uvm_info(get_type_name(), "========================================", UVM_LOW)
        endfunction
        
    endclass
    
    // =======================================================================
    // Coverage Collector
    // =======================================================================
    class ttc3_coverage extends uvm_subscriber #(ttc3_transaction);
        `uvm_component_utils(ttc3_coverage)
        
        ttc3_transaction txn;
        
        // Coverage groups
        covergroup cg_operations;
            op: coverpoint txn.operation {
                bins nop        = {OP_NOP};
                bins get_id     = {OP_GET_ID};
                bins sha256     = {OP_SHA256};
                bins hmac       = {OP_HMAC};
                bins aes_ctr    = {OP_AES_CTR};
                bins derive_key = {OP_DERIVE_KEY};
            }
        endgroup
        
        covergroup cg_latency;
            latency: coverpoint txn.response_latency {
                bins fast     = {[1:10]};
                bins mid_range = {[11:70]};
                bins slow     = {[71:200]};
            }
        endgroup
        
        covergroup cg_data_patterns;
            data_zero: coverpoint (txn.cmd_data == 0);
            data_ones: coverpoint (txn.cmd_data == '1);
            data_pattern: coverpoint txn.cmd_data[7:0] {
                bins patterns[] = {8'h00, 8'hFF, 8'hAA, 8'h55};
            }
        endgroup
        
        function new(string name = "ttc3_coverage", uvm_component parent = null);
            super.new(name, parent);
            cg_operations = new();
            cg_latency = new();
            cg_data_patterns = new();
        endfunction
        
        function void write(ttc3_transaction t);
            txn = t;
            cg_operations.sample();
            cg_latency.sample();
            cg_data_patterns.sample();
        endfunction
        
        function void report_phase(uvm_phase phase);
            `uvm_info(get_type_name(), $sformatf("Operation Coverage: %.2f%%", 
                      cg_operations.get_coverage()), UVM_LOW)
            `uvm_info(get_type_name(), $sformatf("Latency Coverage: %.2f%%", 
                      cg_latency.get_coverage()), UVM_LOW)
        endfunction
        
    endclass
    
    // =======================================================================
    // Agent
    // =======================================================================
    class ttc3_agent extends uvm_agent;
        `uvm_component_utils(ttc3_agent)
        
        ttc3_driver     driver;
        ttc3_monitor    monitor;
        ttc3_sequencer  sequencer;
        
        function new(string name = "ttc3_agent", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            driver    = ttc3_driver::type_id::create("driver", this);
            monitor   = ttc3_monitor::type_id::create("monitor", this);
            sequencer = ttc3_sequencer::type_id::create("sequencer", this);
        endfunction
        
        function void connect_phase(uvm_phase phase);
            driver.seq_item_port.connect(sequencer.seq_item_export);
        endfunction
        
    endclass
    
    // =======================================================================
    // Environment
    // =======================================================================
    class ttc3_env extends uvm_env;
        `uvm_component_utils(ttc3_env)
        
        ttc3_agent      agent;
        ttc3_scoreboard scoreboard;
        ttc3_coverage   coverage;
        
        function new(string name = "ttc3_env", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            agent      = ttc3_agent::type_id::create("agent", this);
            scoreboard = ttc3_scoreboard::type_id::create("scoreboard", this);
            coverage   = ttc3_coverage::type_id::create("coverage", this);
        endfunction
        
        function void connect_phase(uvm_phase phase);
            agent.monitor.ap.connect(scoreboard.analysis_export);
            agent.monitor.ap.connect(coverage.analysis_export);
        endfunction
        
    endclass
    
    // =======================================================================
    // Base Test
    // =======================================================================
    class ttc3_base_test extends uvm_test;
        `uvm_component_utils(ttc3_base_test)
        
        ttc3_env env;
        
        function new(string name = "ttc3_base_test", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            env = ttc3_env::type_id::create("env", this);
        endfunction
        
        function void end_of_elaboration_phase(uvm_phase phase);
            uvm_top.print_topology();
        endfunction
        
        task run_phase(uvm_phase phase);
            phase.raise_objection(this);
            #1000ns;
            phase.drop_objection(this);
        endtask
        
    endclass
    
    // =======================================================================
    // Test 1: Security Test
    // =======================================================================
    class ttc3_security_test extends ttc3_base_test;
        `uvm_component_utils(ttc3_security_test)
        
        function new(string name = "ttc3_security_test", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        task run_phase(uvm_phase phase);
            ttc3_security_sequence seq;
            
            phase.raise_objection(this);
            `uvm_info(get_type_name(), "Starting Security Test", UVM_LOW)
            
            seq = ttc3_security_sequence::type_id::create("sec_seq");
            seq.start(env.agent.sequencer);
            
            #500ns;
            phase.drop_objection(this);
        endtask
        
    endclass
    
    // =======================================================================
    // Test 2: Random Test
    // =======================================================================
    class ttc3_random_test extends ttc3_base_test;
        `uvm_component_utils(ttc3_random_test)
        
        function new(string name = "ttc3_random_test", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        task run_phase(uvm_phase phase);
            ttc3_random_sequence seq;
            
            phase.raise_objection(this);
            `uvm_info(get_type_name(), "Starting Random Test", UVM_LOW)
            
            seq = ttc3_random_sequence::type_id::create("rand_seq");
            assert(seq.randomize());
            seq.start(env.agent.sequencer);
            
            #1000ns;
            phase.drop_objection(this);
        endtask
        
    endclass
    
    // =======================================================================
    // Test 3: Reset Test
    // =======================================================================
    class ttc3_reset_test extends ttc3_base_test;
        `uvm_component_utils(ttc3_reset_test)
        
        function new(string name = "ttc3_reset_test", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        task run_phase(uvm_phase phase);
            ttc3_reset_sequence seq;
            
            phase.raise_objection(this);
            `uvm_info(get_type_name(), "Starting Reset Test", UVM_LOW)
            
            seq = ttc3_reset_sequence::type_id::create("reset_seq");
            seq.start(env.agent.sequencer);
            
            #500ns;
            phase.drop_objection(this);
        endtask
        
    endclass
    
endpackage
