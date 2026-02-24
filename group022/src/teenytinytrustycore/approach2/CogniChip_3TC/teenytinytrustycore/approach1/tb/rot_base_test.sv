// Hardware Root of Trust - Base Test
// Base class for all RoT verification tests

package rot_base_test_pkg;
    
    import uvm_pkg::*;
    `include "uvm_macros.svh"
    import rot_transaction_pkg::*;
    import rot_control_agent_pkg::*;
    import rot_crypto_agents_pkg::*;
    import rot_security_monitor_pkg::*;
    import rot_env_pkg::*;
    
    // ====================================================================
    // Base Sequences
    // ====================================================================
    
    // Reset Sequence
    class reset_sequence extends uvm_sequence #(rot_control_transaction);
        `uvm_object_utils(reset_sequence)
        
        function new(string name = "reset_sequence");
            super.new(name);
        endfunction
        
        task body();
            rot_control_transaction trans;
            trans = rot_control_transaction::type_id::create("trans");
            
            start_item(trans);
            assert(trans.randomize() with {
                system_init == 0;
                derive_new_keys == 0;
                zeroize_all == 0;
            });
            finish_item(trans);
            
            `uvm_info(get_type_name(), "Reset sequence completed", UVM_MEDIUM)
        endtask
    endclass
    
    // PUF Enrollment Sequence
    class enroll_sequence extends uvm_sequence #(rot_control_transaction);
        `uvm_object_utils(enroll_sequence)
        
        function new(string name = "enroll_sequence");
            super.new(name);
        endfunction
        
        task body();
            rot_control_transaction trans;
            trans = rot_control_transaction::type_id::create("trans");
            
            start_item(trans);
            assert(trans.randomize() with {
                system_init == 1;
                puf_dus_enroll == 1;  // First-time enrollment
                derive_new_keys == 0;
                zeroize_all == 0;
            });
            finish_item(trans);
            
            `uvm_info(get_type_name(), "Enrollment sequence completed", UVM_MEDIUM)
            
            // Wait for system to become ready
            repeat(500) begin
                start_item(trans);
                assert(trans.randomize() with {
                    system_init == 0;
                    derive_new_keys == 0;
                    zeroize_all == 0;
                });
                finish_item(trans);
                
                if (trans.system_ready && trans.keys_active) begin
                    `uvm_info(get_type_name(), "System initialized and keys active", UVM_MEDIUM)
                    break;
                end
            end
        endtask
    endclass
    
    // PUF Regeneration Sequence
    class regenerate_sequence extends uvm_sequence #(rot_control_transaction);
        `uvm_object_utils(regenerate_sequence)
        
        bit [255:0] helper_data;  // Helper data from enrollment
        
        function new(string name = "regenerate_sequence");
            super.new(name);
        endfunction
        
        task body();
            rot_control_transaction trans;
            trans = rot_control_transaction::type_id::create("trans");
            
            start_item(trans);
            assert(trans.randomize() with {
                system_init == 1;
                puf_dus_enroll == 0;  // Regeneration mode
                puf_dus_helper_in == helper_data;
                derive_new_keys == 0;
                zeroize_all == 0;
            });
            finish_item(trans);
            
            `uvm_info(get_type_name(), "Regeneration sequence completed", UVM_MEDIUM)
            
            // Wait for system to become ready
            repeat(500) begin
                start_item(trans);
                assert(trans.randomize() with {
                    system_init == 0;
                    derive_new_keys == 0;
                    zeroize_all == 0;
                });
                finish_item(trans);
                
                if (trans.system_ready && trans.keys_active) begin
                    `uvm_info(get_type_name(), "System regenerated and keys active", UVM_MEDIUM)
                    break;
                end
                
                if (trans.security_fault) begin
                    `uvm_error(get_type_name(), "Security fault during regeneration!")
                    break;
                end
            end
        endtask
    endclass
    
    // Zeroization Sequence
    class zeroize_sequence extends uvm_sequence #(rot_control_transaction);
        `uvm_object_utils(zeroize_sequence)
        
        function new(string name = "zeroize_sequence");
            super.new(name);
        endfunction
        
        task body();
            rot_control_transaction trans;
            trans = rot_control_transaction::type_id::create("trans");
            
            start_item(trans);
            assert(trans.randomize() with {
                system_init == 0;
                derive_new_keys == 0;
                zeroize_all == 1;
            });
            finish_item(trans);
            
            `uvm_info(get_type_name(), "Zeroization sequence completed", UVM_MEDIUM)
            
            // Wait and check if keys deactivated
            repeat(20) begin
                start_item(trans);
                assert(trans.randomize() with {
                    system_init == 0;
                    derive_new_keys == 0;
                    zeroize_all == 0;
                });
                finish_item(trans);
                
                if (!trans.keys_active && trans.security_fault) begin
                    `uvm_info(get_type_name(), "Keys deactivated and fault state entered", UVM_MEDIUM)
                    break;
                end
            end
        endtask
    endclass
    
    // SHA-256 Hash Sequence
    class sha_hash_sequence extends uvm_sequence #(sha256_transaction);
        `uvm_object_utils(sha_hash_sequence)
        
        rand bit [511:0] message;
        
        function new(string name = "sha_hash_sequence");
            super.new(name);
        endfunction
        
        task body();
            sha256_transaction trans;
            trans = sha256_transaction::type_id::create("trans");
            
            start_item(trans);
            assert(trans.randomize() with {
                sha_start == 1;
                sha_init == 1;
                sha_message == message;
            });
            finish_item(trans);
            
            `uvm_info(get_type_name(), $sformatf("SHA-256 hash completed: 0x%0h", trans.sha_hash), UVM_MEDIUM)
        endtask
    endclass
    
    // ====================================================================
    // Base Test Class
    // ====================================================================
    class rot_base_test extends uvm_test;
        
        `uvm_component_utils(rot_base_test)
        
        rot_env env;
        
        function new(string name = "rot_base_test", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            
            `uvm_info(get_type_name(), "Building base test", UVM_LOW)
            
            // Create environment
            env = rot_env::type_id::create("env", this);
            
            // Configure environment
            env.has_scoreboard = 0;  // Enable when scoreboard is implemented
            env.has_coverage = 0;    // Enable when coverage is implemented
        endfunction
        
        function void end_of_elaboration_phase(uvm_phase phase);
            super.end_of_elaboration_phase(phase);
            `uvm_info(get_type_name(), "Test elaboration complete", UVM_LOW)
        endfunction
        
        task run_phase(uvm_phase phase);
            super.run_phase(phase);
            phase.raise_objection(this, "Starting base test");
            
            `uvm_info(get_type_name(), "Running base test", UVM_LOW)
            
            // Default: just run for a bit
            #1000ns;
            
            phase.drop_objection(this, "Finishing base test");
        endtask
        
        function void report_phase(uvm_phase phase);
            uvm_report_server svr;
            super.report_phase(phase);
            
            svr = uvm_report_server::get_server();
            
            `uvm_info(get_type_name(), "=== TEST SUMMARY ===", UVM_LOW)
            `uvm_info(get_type_name(), $sformatf("Errors: %0d", svr.get_severity_count(UVM_ERROR)), UVM_LOW)
            `uvm_info(get_type_name(), $sformatf("Warnings: %0d", svr.get_severity_count(UVM_WARNING)), UVM_LOW)
            
            if (svr.get_severity_count(UVM_ERROR) == 0) begin
                `uvm_info(get_type_name(), "TEST PASSED", UVM_LOW)
            end else begin
                `uvm_error(get_type_name(), "TEST FAILED")
            end
        endfunction
        
    endclass : rot_base_test
    
    // ====================================================================
    // Simple Enrollment Test
    // ====================================================================
    class rot_enrollment_test extends rot_base_test;
        
        `uvm_component_utils(rot_enrollment_test)
        
        function new(string name = "rot_enrollment_test", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        task run_phase(uvm_phase phase);
            enroll_sequence enroll_seq;
            
            phase.raise_objection(this, "Starting enrollment test");
            
            `uvm_info(get_type_name(), "Running enrollment test", UVM_LOW)
            
            // Run enrollment sequence
            enroll_seq = enroll_sequence::type_id::create("enroll_seq");
            enroll_seq.start(env.ctrl_agent.sequencer);
            
            // Wait for completion
            #5000ns;
            
            phase.drop_objection(this, "Finishing enrollment test");
        endtask
        
    endclass : rot_enrollment_test
    
endpackage : rot_base_test_pkg
