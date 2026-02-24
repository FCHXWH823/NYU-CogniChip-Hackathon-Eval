// Hardware Root of Trust - Security Monitor
// Monitors for isolation violations, zeroization, and security events

package rot_security_monitor_pkg;
    
    import uvm_pkg::*;
    `include "uvm_macros.svh"
    import rot_transaction_pkg::*;
    
    // ====================================================================
    // Security Monitor
    // ====================================================================
    class rot_security_monitor extends uvm_monitor;
        
        `uvm_component_utils(rot_security_monitor)
        
        virtual rot_if vif;
        uvm_analysis_port #(security_event_transaction) ap;
        
        // Tracking variables
        bit [255:0] dus_secret_shadow;  // Track DUS if visible
        bit [255:0] hmac_key_shadow;
        bit [255:0] aes_key_shadow;
        bit [255:0] sha_key_shadow;
        bit keys_active_prev;
        bit security_fault_prev;
        
        // Statistics
        int zeroization_count;
        int fault_count;
        int isolation_violation_count;
        
        function new(string name = "rot_security_monitor", uvm_component parent = null);
            super.new(name, parent);
            ap = new("ap", this);
            zeroization_count = 0;
            fault_count = 0;
            isolation_violation_count = 0;
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            if (!uvm_config_db#(virtual rot_if)::get(this, "", "vif", vif)) begin
                `uvm_fatal("NOVIF", "Virtual interface not found")
            end
        endfunction
        
        task run_phase(uvm_phase phase);
            fork
                monitor_zeroization();
                monitor_faults();
                monitor_isolation();
                monitor_key_lifecycle();
            join_none
        endtask
        
        // ================================================================
        // Monitor Zeroization Events
        // ================================================================
        task monitor_zeroization();
            security_event_transaction evt;
            
            forever begin
                @(vif.monitor_cb);
                
                if (vif.monitor_cb.zeroize_all) begin
                    evt = security_event_transaction::type_id::create("zeroize_evt");
                    evt.event_type = security_event_transaction::ZEROIZATION;
                    evt.event_time = $time;
                    evt.description = "Zeroization command detected";
                    
                    // Wait a few cycles to check if keys are cleared
                    repeat(10) @(vif.monitor_cb);
                    
                    // Check if keys_active deasserted
                    if (!vif.monitor_cb.keys_active) begin
                        evt.keys_cleared = 1'b1;
                        `uvm_info(get_type_name(), "SECURITY CHECK PASSED: Keys cleared after zeroization", UVM_MEDIUM)
                    end else begin
                        evt.keys_cleared = 1'b0;
                        `uvm_error(get_type_name(), "SECURITY VIOLATION: Keys not cleared after zeroization!")
                    end
                    
                    // Check if fault state entered
                    if (vif.monitor_cb.security_fault) begin
                        evt.fault_state_entered = 1'b1;
                    end
                    
                    zeroization_count++;
                    ap.write(evt);
                end
            end
        endtask
        
        // ================================================================
        // Monitor Security Faults
        // ================================================================
        task monitor_faults();
            security_event_transaction evt;
            
            forever begin
                @(vif.monitor_cb);
                
                if (vif.monitor_cb.security_fault && !security_fault_prev) begin
                    evt = security_event_transaction::type_id::create("fault_evt");
                    evt.event_type = security_event_transaction::FAULT_DETECTED;
                    evt.event_time = $time;
                    evt.description = "Security fault detected";
                    evt.fault_state_entered = 1'b1;
                    
                    `uvm_warning(get_type_name(), $sformatf("Security fault detected at time %0t", $time))
                    
                    fault_count++;
                    ap.write(evt);
                end
                
                security_fault_prev = vif.monitor_cb.security_fault;
            end
        endtask
        
        // ================================================================
        // Monitor Isolation - Check DUS/Keys Never Appear on Bus
        // ================================================================
        task monitor_isolation();
            security_event_transaction evt;
            bit violation_detected;
            
            forever begin
                @(vif.monitor_cb);
                
                violation_detected = 1'b0;
                
                // Check if any sensitive data appears on bus-accessible outputs
                // Note: In real implementation, we'd need to probe internal DUS signal
                // For now, we check for suspicious correlations
                
                // Check Device ID doesn't contain obvious key material patterns
                if (vif.monitor_cb.device_id_valid) begin
                    // Simple check: Device ID should not be all zeros or all ones
                    if (vif.monitor_cb.device_id == 128'h0) begin
                        `uvm_warning(get_type_name(), "Device ID is all zeros - potential issue")
                    end
                    if (vif.monitor_cb.device_id == 128'hFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF) begin
                        `uvm_warning(get_type_name(), "Device ID is all ones - potential issue")
                    end
                end
                
                // Check that when keys are not active, crypto outputs should be invalid
                if (!vif.monitor_cb.keys_active) begin
                    if (vif.monitor_cb.hmac_valid || vif.monitor_cb.aes_valid) begin
                        evt = security_event_transaction::type_id::create("isolation_evt");
                        evt.event_type = security_event_transaction::ISOLATION_VIOLATION;
                        evt.event_time = $time;
                        evt.description = "Crypto operation valid when keys not active";
                        
                        `uvm_error(get_type_name(), "SECURITY VIOLATION: Crypto outputs valid without active keys!")
                        
                        isolation_violation_count++;
                        ap.write(evt);
                    end
                end
                
                // Additional checks can be added here for more sophisticated monitoring
            end
        endtask
        
        // ================================================================
        // Monitor Key Lifecycle
        // ================================================================
        task monitor_key_lifecycle();
            forever begin
                @(vif.monitor_cb);
                
                // Track key activation transitions
                if (vif.monitor_cb.keys_active && !keys_active_prev) begin
                    `uvm_info(get_type_name(), $sformatf("Keys activated at time %0t", $time), UVM_MEDIUM)
                end
                
                if (!vif.monitor_cb.keys_active && keys_active_prev) begin
                    `uvm_info(get_type_name(), $sformatf("Keys deactivated at time %0t", $time), UVM_MEDIUM)
                end
                
                keys_active_prev = vif.monitor_cb.keys_active;
            end
        endtask
        
        // ================================================================
        // Report Phase - Print Statistics
        // ================================================================
        function void report_phase(uvm_phase phase);
            super.report_phase(phase);
            
            `uvm_info(get_type_name(), "=== SECURITY MONITOR STATISTICS ===", UVM_LOW)
            `uvm_info(get_type_name(), $sformatf("Zeroization events: %0d", zeroization_count), UVM_LOW)
            `uvm_info(get_type_name(), $sformatf("Fault events: %0d", fault_count), UVM_LOW)
            `uvm_info(get_type_name(), $sformatf("Isolation violations: %0d", isolation_violation_count), UVM_LOW)
            
            if (isolation_violation_count > 0) begin
                `uvm_error(get_type_name(), "SECURITY TEST FAILED: Isolation violations detected!")
            end else begin
                `uvm_info(get_type_name(), "SECURITY TEST PASSED: No isolation violations detected", UVM_LOW)
            end
        endfunction
        
    endclass : rot_security_monitor
    
endpackage : rot_security_monitor_pkg
