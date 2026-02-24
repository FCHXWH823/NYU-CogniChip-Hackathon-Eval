// Hardware Root of Trust - Cryptographic Agents
// SHA-256, HMAC-SHA-256, and AES-CTR agents

package rot_crypto_agents_pkg;
    
    import uvm_pkg::*;
    `include "uvm_macros.svh"
    import rot_transaction_pkg::*;
    
    // ====================================================================
    // SHA-256 Driver
    // ====================================================================
    class sha256_driver extends uvm_driver #(sha256_transaction);
        
        `uvm_component_utils(sha256_driver)
        
        virtual rot_if vif;
        
        function new(string name = "sha256_driver", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            if (!uvm_config_db#(virtual rot_if)::get(this, "", "vif", vif)) begin
                `uvm_fatal("NOVIF", "Virtual interface not found")
            end
        endfunction
        
        task run_phase(uvm_phase phase);
            sha256_transaction trans;
            
            // Initialize SHA signals
            vif.driver_cb.sha_start <= 1'b0;
            vif.driver_cb.sha_init <= 1'b0;
            vif.driver_cb.sha_message <= 512'h0;
            
            forever begin
                seq_item_port.get_next_item(trans);
                drive_sha_transaction(trans);
                seq_item_port.item_done();
            end
        endtask
        
        task drive_sha_transaction(sha256_transaction trans);
            `uvm_info(get_type_name(), $sformatf("Driving SHA-256 transaction"), UVM_HIGH)
            
            // Wait for ready
            while (!vif.driver_cb.sha_ready) begin
                @(vif.driver_cb);
            end
            
            // Apply inputs
            vif.driver_cb.sha_message <= trans.sha_message;
            vif.driver_cb.sha_init <= trans.sha_init;
            vif.driver_cb.sha_start <= trans.sha_start;
            @(vif.driver_cb);
            
            // Deassert start
            vif.driver_cb.sha_start <= 1'b0;
            
            // Wait for valid output
            while (!vif.driver_cb.sha_valid) begin
                @(vif.driver_cb);
            end
            
            // Capture output
            trans.sha_hash = vif.driver_cb.sha_hash;
            trans.sha_valid = vif.driver_cb.sha_valid;
            trans.sha_ready = vif.driver_cb.sha_ready;
            
            `uvm_info(get_type_name(), $sformatf("SHA-256 hash: 0x%0h", trans.sha_hash), UVM_MEDIUM)
        endtask
        
    endclass : sha256_driver
    
    // ====================================================================
    // SHA-256 Monitor
    // ====================================================================
    class sha256_monitor extends uvm_monitor;
        
        `uvm_component_utils(sha256_monitor)
        
        virtual rot_if vif;
        uvm_analysis_port #(sha256_transaction) ap;
        
        function new(string name = "sha256_monitor", uvm_component parent = null);
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
            sha256_transaction trans;
            
            forever begin
                @(vif.monitor_cb);
                
                if (vif.monitor_cb.sha_start && vif.monitor_cb.sha_ready) begin
                    trans = sha256_transaction::type_id::create("trans");
                    
                    trans.sha_start = vif.monitor_cb.sha_start;
                    trans.sha_init = vif.monitor_cb.sha_init;
                    trans.sha_message = vif.monitor_cb.sha_message;
                    
                    // Wait for result
                    while (!vif.monitor_cb.sha_valid) begin
                        @(vif.monitor_cb);
                    end
                    
                    trans.sha_hash = vif.monitor_cb.sha_hash;
                    trans.sha_valid = vif.monitor_cb.sha_valid;
                    trans.sha_ready = vif.monitor_cb.sha_ready;
                    
                    ap.write(trans);
                end
            end
        endtask
        
    endclass : sha256_monitor
    
    // ====================================================================
    // SHA-256 Agent
    // ====================================================================
    typedef uvm_sequencer #(sha256_transaction) sha256_sequencer;
    
    class sha256_agent extends uvm_agent;
        
        `uvm_component_utils(sha256_agent)
        
        sha256_driver driver;
        sha256_monitor monitor;
        sha256_sequencer sequencer;
        uvm_analysis_port #(sha256_transaction) ap;
        
        function new(string name = "sha256_agent", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            monitor = sha256_monitor::type_id::create("monitor", this);
            if (get_is_active() == UVM_ACTIVE) begin
                driver = sha256_driver::type_id::create("driver", this);
                sequencer = sha256_sequencer::type_id::create("sequencer", this);
            end
        endfunction
        
        function void connect_phase(uvm_phase phase);
            super.connect_phase(phase);
            if (get_is_active() == UVM_ACTIVE) begin
                driver.seq_item_port.connect(sequencer.seq_item_export);
            end
            ap = monitor.ap;
        endfunction
        
    endclass : sha256_agent
    
    // ====================================================================
    // HMAC-SHA-256 Driver
    // ====================================================================
    class hmac_driver extends uvm_driver #(hmac_transaction);
        
        `uvm_component_utils(hmac_driver)
        
        virtual rot_if vif;
        
        function new(string name = "hmac_driver", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            if (!uvm_config_db#(virtual rot_if)::get(this, "", "vif", vif)) begin
                `uvm_fatal("NOVIF", "Virtual interface not found")
            end
        endfunction
        
        task run_phase(uvm_phase phase);
            hmac_transaction trans;
            
            // Initialize HMAC signals
            vif.driver_cb.hmac_start <= 1'b0;
            vif.driver_cb.hmac_init <= 1'b0;
            vif.driver_cb.hmac_final <= 1'b0;
            vif.driver_cb.hmac_message <= 512'h0;
            
            forever begin
                seq_item_port.get_next_item(trans);
                drive_hmac_transaction(trans);
                seq_item_port.item_done();
            end
        endtask
        
        task drive_hmac_transaction(hmac_transaction trans);
            `uvm_info(get_type_name(), $sformatf("Driving HMAC transaction"), UVM_HIGH)
            
            // Wait for ready
            while (!vif.driver_cb.hmac_ready) begin
                @(vif.driver_cb);
            end
            
            // Apply inputs
            vif.driver_cb.hmac_message <= trans.hmac_message;
            vif.driver_cb.hmac_init <= trans.hmac_init;
            vif.driver_cb.hmac_final <= trans.hmac_final;
            vif.driver_cb.hmac_start <= trans.hmac_start;
            @(vif.driver_cb);
            
            // Deassert start
            vif.driver_cb.hmac_start <= 1'b0;
            
            // Wait for valid output
            while (!vif.driver_cb.hmac_valid) begin
                @(vif.driver_cb);
            end
            
            // Capture output
            trans.hmac_mac = vif.driver_cb.hmac_mac;
            trans.hmac_valid = vif.driver_cb.hmac_valid;
            trans.hmac_ready = vif.driver_cb.hmac_ready;
            
            `uvm_info(get_type_name(), $sformatf("HMAC MAC: 0x%0h", trans.hmac_mac), UVM_MEDIUM)
        endtask
        
    endclass : hmac_driver
    
    // ====================================================================
    // HMAC-SHA-256 Monitor
    // ====================================================================
    class hmac_monitor extends uvm_monitor;
        
        `uvm_component_utils(hmac_monitor)
        
        virtual rot_if vif;
        uvm_analysis_port #(hmac_transaction) ap;
        
        function new(string name = "hmac_monitor", uvm_component parent = null);
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
            hmac_transaction trans;
            
            forever begin
                @(vif.monitor_cb);
                
                if (vif.monitor_cb.hmac_start && vif.monitor_cb.hmac_ready) begin
                    trans = hmac_transaction::type_id::create("trans");
                    
                    trans.hmac_start = vif.monitor_cb.hmac_start;
                    trans.hmac_init = vif.monitor_cb.hmac_init;
                    trans.hmac_final = vif.monitor_cb.hmac_final;
                    trans.hmac_message = vif.monitor_cb.hmac_message;
                    
                    // Wait for result
                    while (!vif.monitor_cb.hmac_valid) begin
                        @(vif.monitor_cb);
                    end
                    
                    trans.hmac_mac = vif.monitor_cb.hmac_mac;
                    trans.hmac_valid = vif.monitor_cb.hmac_valid;
                    trans.hmac_ready = vif.monitor_cb.hmac_ready;
                    
                    ap.write(trans);
                end
            end
        endtask
        
    endclass : hmac_monitor
    
    // ====================================================================
    // HMAC Agent
    // ====================================================================
    typedef uvm_sequencer #(hmac_transaction) hmac_sequencer;
    
    class hmac_agent extends uvm_agent;
        
        `uvm_component_utils(hmac_agent)
        
        hmac_driver driver;
        hmac_monitor monitor;
        hmac_sequencer sequencer;
        uvm_analysis_port #(hmac_transaction) ap;
        
        function new(string name = "hmac_agent", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            monitor = hmac_monitor::type_id::create("monitor", this);
            if (get_is_active() == UVM_ACTIVE) begin
                driver = hmac_driver::type_id::create("driver", this);
                sequencer = hmac_sequencer::type_id::create("sequencer", this);
            end
        endfunction
        
        function void connect_phase(uvm_phase phase);
            super.connect_phase(phase);
            if (get_is_active() == UVM_ACTIVE) begin
                driver.seq_item_port.connect(sequencer.seq_item_export);
            end
            ap = monitor.ap;
        endfunction
        
    endclass : hmac_agent
    
    // ====================================================================
    // AES-CTR Driver
    // ====================================================================
    class aes_driver extends uvm_driver #(aes_transaction);
        
        `uvm_component_utils(aes_driver)
        
        virtual rot_if vif;
        
        function new(string name = "aes_driver", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            if (!uvm_config_db#(virtual rot_if)::get(this, "", "vif", vif)) begin
                `uvm_fatal("NOVIF", "Virtual interface not found")
            end
        endfunction
        
        task run_phase(uvm_phase phase);
            aes_transaction trans;
            
            // Initialize AES signals
            vif.driver_cb.aes_start <= 1'b0;
            vif.driver_cb.aes_init <= 1'b0;
            vif.driver_cb.aes_nonce <= 128'h0;
            vif.driver_cb.aes_counter_init <= 64'h0;
            vif.driver_cb.aes_data_in <= 128'h0;
            
            forever begin
                seq_item_port.get_next_item(trans);
                drive_aes_transaction(trans);
                seq_item_port.item_done();
            end
        endtask
        
        task drive_aes_transaction(aes_transaction trans);
            `uvm_info(get_type_name(), $sformatf("Driving AES transaction"), UVM_HIGH)
            
            // Wait for ready
            while (!vif.driver_cb.aes_ready) begin
                @(vif.driver_cb);
            end
            
            // Apply inputs
            vif.driver_cb.aes_nonce <= trans.aes_nonce;
            vif.driver_cb.aes_counter_init <= trans.aes_counter_init;
            vif.driver_cb.aes_data_in <= trans.aes_data_in;
            vif.driver_cb.aes_init <= trans.aes_init;
            vif.driver_cb.aes_start <= trans.aes_start;
            @(vif.driver_cb);
            
            // Deassert start
            vif.driver_cb.aes_start <= 1'b0;
            
            // Wait for valid output
            while (!vif.driver_cb.aes_valid) begin
                @(vif.driver_cb);
            end
            
            // Capture output
            trans.aes_data_out = vif.driver_cb.aes_data_out;
            trans.aes_valid = vif.driver_cb.aes_valid;
            trans.aes_ready = vif.driver_cb.aes_ready;
            
            `uvm_info(get_type_name(), $sformatf("AES output: 0x%0h", trans.aes_data_out), UVM_MEDIUM)
        endtask
        
    endclass : aes_driver
    
    // ====================================================================
    // AES-CTR Monitor
    // ====================================================================
    class aes_monitor extends uvm_monitor;
        
        `uvm_component_utils(aes_monitor)
        
        virtual rot_if vif;
        uvm_analysis_port #(aes_transaction) ap;
        
        function new(string name = "aes_monitor", uvm_component parent = null);
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
            aes_transaction trans;
            
            forever begin
                @(vif.monitor_cb);
                
                if (vif.monitor_cb.aes_start && vif.monitor_cb.aes_ready) begin
                    trans = aes_transaction::type_id::create("trans");
                    
                    trans.aes_start = vif.monitor_cb.aes_start;
                    trans.aes_init = vif.monitor_cb.aes_init;
                    trans.aes_nonce = vif.monitor_cb.aes_nonce;
                    trans.aes_counter_init = vif.monitor_cb.aes_counter_init;
                    trans.aes_data_in = vif.monitor_cb.aes_data_in;
                    
                    // Wait for result
                    while (!vif.monitor_cb.aes_valid) begin
                        @(vif.monitor_cb);
                    end
                    
                    trans.aes_data_out = vif.monitor_cb.aes_data_out;
                    trans.aes_valid = vif.monitor_cb.aes_valid;
                    trans.aes_ready = vif.monitor_cb.aes_ready;
                    
                    ap.write(trans);
                end
            end
        endtask
        
    endclass : aes_monitor
    
    // ====================================================================
    // AES Agent
    // ====================================================================
    typedef uvm_sequencer #(aes_transaction) aes_sequencer;
    
    class aes_agent extends uvm_agent;
        
        `uvm_component_utils(aes_agent)
        
        aes_driver driver;
        aes_monitor monitor;
        aes_sequencer sequencer;
        uvm_analysis_port #(aes_transaction) ap;
        
        function new(string name = "aes_agent", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            monitor = aes_monitor::type_id::create("monitor", this);
            if (get_is_active() == UVM_ACTIVE) begin
                driver = aes_driver::type_id::create("driver", this);
                sequencer = aes_sequencer::type_id::create("sequencer", this);
            end
        endfunction
        
        function void connect_phase(uvm_phase phase);
            super.connect_phase(phase);
            if (get_is_active() == UVM_ACTIVE) begin
                driver.seq_item_port.connect(sequencer.seq_item_export);
            end
            ap = monitor.ap;
        endfunction
        
    endclass : aes_agent
    
endpackage : rot_crypto_agents_pkg
