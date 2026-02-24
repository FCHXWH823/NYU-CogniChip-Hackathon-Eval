// Hardware Root of Trust - Verification Interface
// Connects DUT signals to UVM testbench

interface rot_if (
    input logic clock,
    input logic reset
);
    
    // ============================================
    // Control Interface
    // ============================================
    logic        system_init;
    logic        derive_new_keys;
    logic        zeroize_all;
    
    // ============================================
    // PUF DUS Interface
    // ============================================
    logic        puf_dus_enroll;
    logic        puf_dus_regenerate;
    logic [255:0] puf_dus_helper_in;
    logic [255:0] puf_dus_helper_out;
    logic         puf_dus_helper_valid;
    
    // ============================================
    // PUF Device ID Interface
    // ============================================
    logic        puf_devid_enroll;
    logic        puf_devid_read;
    logic [127:0] device_id;
    logic         device_id_valid;
    
    // ============================================
    // SHA-256 Interface
    // ============================================
    logic        sha_start;
    logic        sha_init;
    logic [511:0] sha_message;
    logic        sha_ready;
    logic        sha_valid;
    logic [255:0] sha_hash;
    
    // ============================================
    // HMAC-SHA-256 Interface
    // ============================================
    logic        hmac_start;
    logic        hmac_init;
    logic        hmac_final;
    logic [511:0] hmac_message;
    logic        hmac_ready;
    logic        hmac_valid;
    logic [255:0] hmac_mac;
    
    // ============================================
    // AES-CTR Interface
    // ============================================
    logic        aes_start;
    logic        aes_init;
    logic [127:0] aes_nonce;
    logic [63:0]  aes_counter_init;
    logic [127:0] aes_data_in;
    logic        aes_ready;
    logic        aes_valid;
    logic [127:0] aes_data_out;
    
    // ============================================
    // System Status
    // ============================================
    logic        system_ready;
    logic        keys_active;
    logic        security_fault;
    
    // ============================================
    // Clocking Blocks for Synchronous Operation
    // ============================================
    
    // Driver clocking block (outputs from TB perspective)
    clocking driver_cb @(posedge clock);
        default input #1step output #1ns;
        
        output system_init;
        output derive_new_keys;
        output zeroize_all;
        output puf_dus_enroll;
        output puf_dus_regenerate;
        output puf_dus_helper_in;
        output puf_devid_enroll;
        output puf_devid_read;
        output sha_start;
        output sha_init;
        output sha_message;
        output hmac_start;
        output hmac_init;
        output hmac_final;
        output hmac_message;
        output aes_start;
        output aes_init;
        output aes_nonce;
        output aes_counter_init;
        output aes_data_in;
        
        input puf_dus_helper_out;
        input puf_dus_helper_valid;
        input device_id;
        input device_id_valid;
        input sha_ready;
        input sha_valid;
        input sha_hash;
        input hmac_ready;
        input hmac_valid;
        input hmac_mac;
        input aes_ready;
        input aes_valid;
        input aes_data_out;
        input system_ready;
        input keys_active;
        input security_fault;
    endclocking
    
    // Monitor clocking block (samples all signals)
    clocking monitor_cb @(posedge clock);
        default input #1step;
        
        input system_init;
        input derive_new_keys;
        input zeroize_all;
        input puf_dus_enroll;
        input puf_dus_regenerate;
        input puf_dus_helper_in;
        input puf_dus_helper_out;
        input puf_dus_helper_valid;
        input puf_devid_enroll;
        input puf_devid_read;
        input device_id;
        input device_id_valid;
        input sha_start;
        input sha_init;
        input sha_message;
        input sha_ready;
        input sha_valid;
        input sha_hash;
        input hmac_start;
        input hmac_init;
        input hmac_final;
        input hmac_message;
        input hmac_ready;
        input hmac_valid;
        input hmac_mac;
        input aes_start;
        input aes_init;
        input aes_nonce;
        input aes_counter_init;
        input aes_data_in;
        input aes_ready;
        input aes_valid;
        input aes_data_out;
        input system_ready;
        input keys_active;
        input security_fault;
    endclocking
    
    // ============================================
    // Modports
    // ============================================
    
    modport driver (
        clocking driver_cb,
        input clock,
        input reset
    );
    
    modport monitor (
        clocking monitor_cb,
        input clock,
        input reset
    );
    
    modport dut (
        input clock,
        input reset,
        input system_init,
        input derive_new_keys,
        input zeroize_all,
        input puf_dus_enroll,
        input puf_dus_regenerate,
        input puf_dus_helper_in,
        output puf_dus_helper_out,
        output puf_dus_helper_valid,
        input puf_devid_enroll,
        input puf_devid_read,
        output device_id,
        output device_id_valid,
        input sha_start,
        input sha_init,
        input sha_message,
        output sha_ready,
        output sha_valid,
        output sha_hash,
        input hmac_start,
        input hmac_init,
        input hmac_final,
        input hmac_message,
        output hmac_ready,
        output hmac_valid,
        output hmac_mac,
        input aes_start,
        input aes_init,
        input aes_nonce,
        input aes_counter_init,
        input aes_data_in,
        output aes_ready,
        output aes_valid,
        output aes_data_out,
        output system_ready,
        output keys_active,
        output security_fault
    );

endinterface : rot_if
