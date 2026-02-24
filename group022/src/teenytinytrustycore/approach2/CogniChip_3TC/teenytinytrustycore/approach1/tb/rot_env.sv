// Hardware Root of Trust - UVM Environment
// Integrates all agents, monitors, and checkers

package rot_env_pkg;
    
    import uvm_pkg::*;
    `include "uvm_macros.svh"
    import rot_transaction_pkg::*;
    import rot_control_agent_pkg::*;
    import rot_crypto_agents_pkg::*;
    import rot_security_monitor_pkg::*;
    
    // ====================================================================
    // Root of Trust Environment
    // ====================================================================
    class rot_env extends uvm_env;
        
        `uvm_component_utils(rot_env)
        
        // Agents
        rot_control_agent   ctrl_agent;
        sha256_agent        sha_agent;
        hmac_agent          hmac_agent;
        aes_agent           aes_agent;
        
        // Security monitor
        rot_security_monitor security_mon;
        
        // Scoreboard (placeholder - would contain reference models)
        // rot_scoreboard scoreboard;
        
        // Coverage collector (placeholder)
        // rot_coverage_collector coverage;
        
        // Configuration
        bit has_scoreboard = 0;
        bit has_coverage = 0;
        
        function new(string name = "rot_env", uvm_component parent = null);
            super.new(name, parent);
        endfunction
        
        function void build_phase(uvm_phase phase);
            super.build_phase(phase);
            
            `uvm_info(get_type_name(), "Building RoT environment", UVM_LOW)
            
            // Create agents
            ctrl_agent = rot_control_agent::type_id::create("ctrl_agent", this);
            sha_agent = sha256_agent::type_id::create("sha_agent", this);
            hmac_agent = hmac_agent::type_id::create("hmac_agent", this);
            aes_agent = aes_agent::type_id::create("aes_agent", this);
            
            // Create security monitor
            security_mon = rot_security_monitor::type_id::create("security_mon", this);
            
            // Create scoreboard if enabled
            if (has_scoreboard) begin
                // scoreboard = rot_scoreboard::type_id::create("scoreboard", this);
                `uvm_info(get_type_name(), "Scoreboard creation pending", UVM_LOW)
            end
            
            // Create coverage collector if enabled
            if (has_coverage) begin
                // coverage = rot_coverage_collector::type_id::create("coverage", this);
                `uvm_info(get_type_name(), "Coverage collector creation pending", UVM_LOW)
            end
        endfunction
        
        function void connect_phase(uvm_phase phase);
            super.connect_phase(phase);
            
            `uvm_info(get_type_name(), "Connecting RoT environment", UVM_LOW)
            
            // Connect agents to scoreboard (when implemented)
            // if (has_scoreboard) begin
            //     ctrl_agent.ap.connect(scoreboard.control_export);
            //     sha_agent.ap.connect(scoreboard.sha_export);
            //     hmac_agent.ap.connect(scoreboard.hmac_export);
            //     aes_agent.ap.connect(scoreboard.aes_export);
            //     security_mon.ap.connect(scoreboard.security_export);
            // end
            
            // Connect to coverage collector (when implemented)
            // if (has_coverage) begin
            //     ctrl_agent.ap.connect(coverage.control_export);
            //     sha_agent.ap.connect(coverage.sha_export);
            //     hmac_agent.ap.connect(coverage.hmac_export);
            //     aes_agent.ap.connect(coverage.aes_export);
            //     security_mon.ap.connect(coverage.security_export);
            // end
        endfunction
        
        function void end_of_elaboration_phase(uvm_phase phase);
            super.end_of_elaboration_phase(phase);
            `uvm_info(get_type_name(), "RoT environment elaboration complete", UVM_LOW)
            uvm_top.print_topology();
        endfunction
        
        task run_phase(uvm_phase phase);
            super.run_phase(phase);
            `uvm_info(get_type_name(), "RoT environment run phase started", UVM_LOW)
        endtask
        
    endclass : rot_env
    
endpackage : rot_env_pkg
