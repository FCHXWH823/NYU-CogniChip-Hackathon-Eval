// Hardware Root of Trust - Control Agent
// Manages system initialization, zeroization, and control operations

package rot_control_agent_pkg;
    
    import uvm_pkg::*;
    `include "uvm_macros.svh"
    import rot_transaction_pkg::*;
    
    // ====================================================================
    // Control Driver
    // ====================================================================
    class rot_control_driver extends uvm_driver #(rot_control_transaction);
        
        `uvm_component_utils(rot_control_driver)
        
        virtual rot_if vif;
        
        function new(string name = "rot_control_driver", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            if (!uvm_config_db#(virtual rot_if)::get(this, "", "vif", vif)) begin
                `uvm_fatal("NOVIF", "Virtual interface not found")
            end
        endfunction
        
        task run_phase(uvm_phase phase);
            rot_control_transaction trans;
            
            // Initialize all control signals
            vif.driver_cb.system_init <= 1'b0;
            vif.driver_cb.derive_new_keys <= 1'b0;
            vif.driver_cb.zeroize_all <= 1'b0;
            vif.driver_cb.puf_dus_enroll <= 1'b0;
            vif.driver_cb.puf_dus_regenerate <= 1'b0;
            vif.driver_cb.puf_dus_helper_in <= 256'h0;
            vif.driver_cb.puf_devid_enroll <= 1'b0;
            vif.driver_cb.puf_devid_read <= 1'b0;
            
            forever begin
                seq_item_port.get_next_item(trans);
                drive_transaction(trans);
                seq_item_port.item_done();
            end
        endtask
        
        task drive_transaction(rot_control_transaction trans);
            `uvm_info(get_type_name(), $sformatf("Driving control transaction:\n%s", trans.sprint()), UVM_HIGH)
            
            // Apply control signals
            vif.driver_cb.system_init <= trans.system_init;
            vif.driver_cb.derive_new_keys <= trans.derive_new_keys;
            vif.driver_cb.zeroize_all <= trans.zeroize_all;
            vif.driver_cb.puf_dus_helper_in <= trans.puf_dus_helper_in;
            vif.driver_cb.puf_devid_enroll <= trans.puf_devid_enroll;
            vif.driver_cb.puf_devid_read <= trans.puf_devid_read;
            
            // Handle PUF enrollment vs regeneration
            if (trans.system_init) begin
                if (trans.puf_dus_enroll) begin
                    vif.driver_cb.puf_dus_enroll <= 1'b1;
                    vif.driver_cb.puf_dus_regenerate <= 1'b0;
                end else begin
                    vif.driver_cb.puf_dus_enroll <= 1'b0;
                    vif.driver_cb.puf_dus_regenerate <= 1'b1;
                end
            end else begin
                vif.driver_cb.puf_dus_enroll <= 1'b0;
                vif.driver_cb.puf_dus_regenerate <= 1'b0;
            end
            
            // Wait for one clock cycle
            @(vif.driver_cb);
            
            // Capture outputs
            trans.puf_dus_helper_out = vif.driver_cb.puf_dus_helper_out;
            trans.puf_dus_helper_valid = vif.driver_cb.puf_dus_helper_valid;
            trans.device_id = vif.driver_cb.device_id;
            trans.device_id_valid = vif.driver_cb.device_id_valid;
            trans.system_ready = vif.driver_cb.system_ready;
            trans.keys_active = vif.driver_cb.keys_active;
            trans.security_fault = vif.driver_cb.security_fault;
            
            // Deassert control signals (pulse-based)
            vif.driver_cb.system_init <= 1'b0;
            vif.driver_cb.derive_new_keys <= 1'b0;
            vif.driver_cb.zeroize_all <= 1'b0;
            vif.driver_cb.puf_devid_read <= 1'b0;
            
        endtask
        
    endclass : rot_control_driver
    
    // ====================================================================
    // Control Monitor
    // ====================================================================
    class rot_control_monitor extends uvm_monitor;
        
        `uvm_component_utils(rot_control_monitor)
        
        virtual rot_if vif;
        uvm_analysis_port #(rot_control_transaction) ap;
        
        function new(string name = "rot_control_monitor", uvm_component parent = null);
            super.new(name, parent);
            ap = new("ap", this);
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            if (!uvm_config_db#(virtual rot_if)::get(this, "", "vif", vif)) begin
                `uvm_fatal("NOVIF", "Virtual interface not found")
            end
        endfunction
        
        task run_phase(uvm_phase phase);
            rot_control_transaction trans;
            
            forever begin
                @(vif.monitor_cb);
                
                // Sample control transactions
                if (vif.monitor_cb.system_init || vif.monitor_cb.derive_new_keys || 
                    vif.monitor_cb.zeroize_all || vif.monitor_cb.puf_devid_read) begin
                    
                    trans = rot_control_transaction::type_id::create("trans");
                    
                    trans.system_init = vif.monitor_cb.system_init;
                    trans.derive_new_keys = vif.monitor_cb.derive_new_keys;
                    trans.zeroize_all = vif.monitor_cb.zeroize_all;
                    trans.puf_dus_enroll = vif.monitor_cb.puf_dus_enroll;
                    trans.puf_dus_helper_in = vif.monitor_cb.puf_dus_helper_in;
                    trans.puf_dus_helper_out = vif.monitor_cb.puf_dus_helper_out;
                    trans.puf_dus_helper_valid = vif.monitor_cb.puf_dus_helper_valid;
                    trans.puf_devid_enroll = vif.monitor_cb.puf_devid_enroll;
                    trans.puf_devid_read = vif.monitor_cb.puf_devid_read;
                    trans.device_id = vif.monitor_cb.device_id;
                    trans.device_id_valid = vif.monitor_cb.device_id_valid;
                    trans.system_ready = vif.monitor_cb.system_ready;
                    trans.keys_active = vif.monitor_cb.keys_active;
                    trans.security_fault = vif.monitor_cb.security_fault;
                    
                    `uvm_info(get_type_name(), $sformatf("Monitored control transaction:\n%s", trans.sprint()), UVM_HIGH)
                    ap.write(trans);
                end
            end
        endtask
        
    endclass : rot_control_monitor
    
    // ====================================================================
    // Control Sequencer
    // ====================================================================
    typedef uvm_sequencer #(rot_control_transaction) rot_control_sequencer;
    
    // ====================================================================
    // Control Agent
    // ====================================================================
    class rot_control_agent extends uvm_agent;
        
        `uvm_component_utils(rot_control_agent)
        
        rot_control_driver driver;
        rot_control_monitor monitor;
        rot_control_sequencer sequencer;
        
        uvm_analysis_port #(rot_control_transaction) ap;
        
        function new(string name = "rot_control_agent", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            
            monitor = rot_control_monitor::type_id::create("monitor", this);
            
            if (get_is_active() == UVM_ACTIVE) begin
                driver = rot_control_driver::type_id::create("driver", this);
                sequencer = rot_control_sequencer::type_id::create("sequencer", this);
            end
        endfunction
        
        function void connect_phase(uvm_phase phase);
            super.connect_phase(phase);
            
            if (get_is_active() == UVM_ACTIVE) begin
                driver.seq_item_port.connect(sequencer.seq_item_export);
            end
            
            ap = monitor.ap;
        endfunction
        
    endclass : rot_control_agent
    
endpackage : rot_control_agent_pkg
