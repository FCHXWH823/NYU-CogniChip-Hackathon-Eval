// Hardware Root of Trust - Transaction Classes Package
// Defines sequence items for all interfaces

package rot_transaction_pkg;
    
    import uvm_pkg::*;
    `include "uvm_macros.svh"
    
    // ====================================================================
    // Control Transaction - System initialization and control
    // ====================================================================
    class rot_control_transaction extends uvm_sequence_item;
        
        // Control signals
        rand bit system_init;
        rand bit derive_new_keys;
        rand bit zeroize_all;
        rand bit puf_dus_enroll;  // 1 = enroll, 0 = regenerate
        rand bit puf_devid_enroll;
        rand bit puf_devid_read;
        
        // PUF helper data
        rand bit [255:0] puf_dus_helper_in;
        bit [255:0] puf_dus_helper_out;
        bit puf_dus_helper_valid;
        
        // Device ID
        bit [127:0] device_id;
        bit device_id_valid;
        
        // Status outputs
        bit system_ready;
        bit keys_active;
        bit security_fault;
        
        // Constraints
        constraint reasonable_c {
            // Only one control command at a time
            $countones({system_init, derive_new_keys, zeroize_all}) <= 1;
            
            // If initializing, specify enrollment type
            system_init -> (puf_dus_enroll inside {0, 1});
        }
        
        `uvm_object_utils_begin(rot_control_transaction)
            `uvm_field_int(system_init, UVM_ALL_ON)
            `uvm_field_int(derive_new_keys, UVM_ALL_ON)
            `uvm_field_int(zeroize_all, UVM_ALL_ON)
            `uvm_field_int(puf_dus_enroll, UVM_ALL_ON)
            `uvm_field_int(puf_devid_enroll, UVM_ALL_ON)
            `uvm_field_int(puf_devid_read, UVM_ALL_ON)
            `uvm_field_int(puf_dus_helper_in, UVM_ALL_ON | UVM_HEX)
            `uvm_field_int(puf_dus_helper_out, UVM_ALL_ON | UVM_HEX)
            `uvm_field_int(puf_dus_helper_valid, UVM_ALL_ON)
            `uvm_field_int(device_id, UVM_ALL_ON | UVM_HEX)
            `uvm_field_int(device_id_valid, UVM_ALL_ON)
            `uvm_field_int(system_ready, UVM_ALL_ON)
            `uvm_field_int(keys_active, UVM_ALL_ON)
            `uvm_field_int(security_fault, UVM_ALL_ON)
        `uvm_object_utils_end
        
        function new(string name = "rot_control_transaction");
            super.new(name);
        endfunction
        
    endclass : rot_control_transaction
    
    // ====================================================================
    // SHA-256 Transaction
    // ====================================================================
    class sha256_transaction extends uvm_sequence_item;
        
        // Inputs
        rand bit sha_start;
        rand bit sha_init;
        rand bit [511:0] sha_message;
        
        // Outputs
        bit sha_ready;
        bit sha_valid;
        bit [255:0] sha_hash;
        
        // Expected hash (for checking)
        bit [255:0] expected_hash;
        bit expected_valid;
        
        `uvm_object_utils_begin(sha256_transaction)
            `uvm_field_int(sha_start, UVM_ALL_ON)
            `uvm_field_int(sha_init, UVM_ALL_ON)
            `uvm_field_int(sha_message, UVM_ALL_ON | UVM_HEX)
            `uvm_field_int(sha_ready, UVM_ALL_ON)
            `uvm_field_int(sha_valid, UVM_ALL_ON)
            `uvm_field_int(sha_hash, UVM_ALL_ON | UVM_HEX)
            `uvm_field_int(expected_hash, UVM_ALL_ON | UVM_HEX)
            `uvm_field_int(expected_valid, UVM_ALL_ON)
        `uvm_object_utils_end
        
        function new(string name = "sha256_transaction");
            super.new(name);
        endfunction
        
    endclass : sha256_transaction
    
    // ====================================================================
    // HMAC-SHA-256 Transaction
    // ====================================================================
    class hmac_transaction extends uvm_sequence_item;
        
        // Inputs
        rand bit hmac_start;
        rand bit hmac_init;
        rand bit hmac_final;
        rand bit [511:0] hmac_message;
        
        // Outputs
        bit hmac_ready;
        bit hmac_valid;
        bit [255:0] hmac_mac;
        
        // Expected MAC (for checking)
        bit [255:0] expected_mac;
        bit expected_valid;
        
        // Key information (for reference model)
        bit [255:0] key;
        bit key_valid;
        
        `uvm_object_utils_begin(hmac_transaction)
            `uvm_field_int(hmac_start, UVM_ALL_ON)
            `uvm_field_int(hmac_init, UVM_ALL_ON)
            `uvm_field_int(hmac_final, UVM_ALL_ON)
            `uvm_field_int(hmac_message, UVM_ALL_ON | UVM_HEX)
            `uvm_field_int(hmac_ready, UVM_ALL_ON)
            `uvm_field_int(hmac_valid, UVM_ALL_ON)
            `uvm_field_int(hmac_mac, UVM_ALL_ON | UVM_HEX)
            `uvm_field_int(expected_mac, UVM_ALL_ON | UVM_HEX)
            `uvm_field_int(expected_valid, UVM_ALL_ON)
        `uvm_object_utils_end
        
        function new(string name = "hmac_transaction");
            super.new(name);
        endfunction
        
    endclass : hmac_transaction
    
    // ====================================================================
    // AES-CTR Transaction
    // ====================================================================
    class aes_transaction extends uvm_sequence_item;
        
        // Inputs
        rand bit aes_start;
        rand bit aes_init;
        rand bit [127:0] aes_nonce;
        rand bit [63:0] aes_counter_init;
        rand bit [127:0] aes_data_in;
        
        // Outputs
        bit aes_ready;
        bit aes_valid;
        bit [127:0] aes_data_out;
        
        // Expected output (for checking)
        bit [127:0] expected_data_out;
        bit expected_valid;
        
        // Key information (for reference model)
        bit [255:0] key;
        bit key_valid;
        
        // Operation type
        typedef enum {ENCRYPT, DECRYPT} aes_op_t;
        rand aes_op_t operation;
        
        `uvm_object_utils_begin(aes_transaction)
            `uvm_field_int(aes_start, UVM_ALL_ON)
            `uvm_field_int(aes_init, UVM_ALL_ON)
            `uvm_field_int(aes_nonce, UVM_ALL_ON | UVM_HEX)
            `uvm_field_int(aes_counter_init, UVM_ALL_ON | UVM_HEX)
            `uvm_field_int(aes_data_in, UVM_ALL_ON | UVM_HEX)
            `uvm_field_int(aes_ready, UVM_ALL_ON)
            `uvm_field_int(aes_valid, UVM_ALL_ON)
            `uvm_field_int(aes_data_out, UVM_ALL_ON | UVM_HEX)
            `uvm_field_int(expected_data_out, UVM_ALL_ON | UVM_HEX)
            `uvm_field_int(expected_valid, UVM_ALL_ON)
            `uvm_field_enum(aes_op_t, operation, UVM_ALL_ON)
        `uvm_object_utils_end
        
        function new(string name = "aes_transaction");
            super.new(name);
        endfunction
        
    endclass : aes_transaction
    
    // ====================================================================
    // Security Event Transaction - For monitoring
    // ====================================================================
    class security_event_transaction extends uvm_sequence_item;
        
        typedef enum {
            ZEROIZATION,
            FAULT_DETECTED,
            DUS_ERROR,
            KEY_CORRUPTION,
            ISOLATION_VIOLATION
        } event_type_t;
        
        event_type_t event_type;
        time event_time;
        string description;
        
        // Related data
        bit keys_cleared;
        bit fault_state_entered;
        bit [255:0] leaked_data;  // For isolation violations
        
        `uvm_object_utils_begin(security_event_transaction)
            `uvm_field_enum(event_type_t, event_type, UVM_ALL_ON)
            `uvm_field_int(event_time, UVM_ALL_ON | UVM_TIME)
            `uvm_field_string(description, UVM_ALL_ON)
            `uvm_field_int(keys_cleared, UVM_ALL_ON)
            `uvm_field_int(fault_state_entered, UVM_ALL_ON)
            `uvm_field_int(leaked_data, UVM_ALL_ON | UVM_HEX)
        `uvm_object_utils_end
        
        function new(string name = "security_event_transaction");
            super.new(name);
        endfunction
        
    endclass : security_event_transaction
    
endpackage : rot_transaction_pkg
