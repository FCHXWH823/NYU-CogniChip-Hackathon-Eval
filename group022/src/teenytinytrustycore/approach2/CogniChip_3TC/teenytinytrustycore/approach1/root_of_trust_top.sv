// Hardware Root of Trust - Top Level Integration
// Integrates all security and cryptographic modules
// Implements complete root of trust with PUFs, KDF, and crypto engines

module root_of_trust_top (
    input  logic        clock,
    input  logic        reset,
    
    // ============================================
    // Control Interface (simplified, pre-AXI)
    // ============================================
    input  logic        system_init,        // Initialize system (enroll PUFs, derive keys)
    input  logic        derive_new_keys,    // Derive new keys from DUS
    input  logic        zeroize_all,        // Emergency zeroization
    
    // ============================================
    // PUF Control
    // ============================================
    input  logic        puf_dus_enroll,     // Enroll DUS PUF
    input  logic        puf_dus_regenerate, // Regenerate DUS
    input  logic [255:0] puf_dus_helper_in, // Helper data for DUS regeneration
    output logic [255:0] puf_dus_helper_out,// Helper data from enrollment
    output logic         puf_dus_helper_valid,
    
    input  logic        puf_devid_enroll,   // Enroll Device ID PUF
    input  logic        puf_devid_read,     // Read Device ID
    output logic [127:0] device_id,         // Device ID output (bus-accessible)
    output logic         device_id_valid,
    
    // ============================================
    // SHA-256 Interface (bus-accessible)
    // ============================================
    input  logic        sha_start,
    input  logic        sha_init,
    input  logic [511:0] sha_message,
    output logic        sha_ready,
    output logic        sha_valid,
    output logic [255:0] sha_hash,
    
    // ============================================
    // HMAC-SHA-256 Interface (bus-accessible)
    // ============================================
    input  logic        hmac_start,
    input  logic        hmac_init,
    input  logic        hmac_final,
    input  logic [511:0] hmac_message,
    output logic        hmac_ready,
    output logic        hmac_valid,
    output logic [255:0] hmac_mac,
    
    // ============================================
    // AES-CTR Interface (bus-accessible)
    // ============================================
    input  logic        aes_start,
    input  logic        aes_init,
    input  logic [127:0] aes_nonce,
    input  logic [63:0]  aes_counter_init,
    input  logic [127:0] aes_data_in,
    output logic        aes_ready,
    output logic        aes_valid,
    output logic [127:0] aes_data_out,
    
    // ============================================
    // System Status
    // ============================================
    output logic        system_ready,       // System initialized and ready
    output logic        keys_active,        // Crypto keys active
    output logic        security_fault      // Security fault detected
);

    // ====================================================================
    // Internal Signals - Isolated Security Path
    // ====================================================================
    
    // PUF_DUS signals (ISOLATED)
    logic [255:0] dus_secret;
    logic         dus_valid;
    logic         dus_error;
    logic         puf_dus_ready;
    
    // PUF Device ID signals
    logic         puf_devid_ready;
    logic         puf_devid_enrolled;
    
    // KDF signals (ISOLATED)
    logic         kdf_derive;
    logic         kdf_ready;
    logic         kdf_valid;
    logic [255:0] kdf_hmac_key;
    logic [255:0] kdf_aes_key;
    logic [255:0] kdf_sha_key;
    logic         kdf_keys_valid;
    logic [255:0] kdf_context;
    
    // Key Distributor signals (ISOLATED)
    logic         key_dist_enable;
    logic         key_dist_zeroize;
    logic         keys_distributed;
    logic [255:0] hmac_key_internal;
    logic         hmac_key_valid_internal;
    logic [255:0] aes_key_internal;
    logic         aes_key_valid_internal;
    logic [255:0] sha_key_internal;
    logic         sha_key_valid_internal;
    
    // ====================================================================
    // Initialization Sequencer
    // ====================================================================
    
    typedef enum logic [3:0] {
        INIT_IDLE,
        INIT_PUF_DUS,
        INIT_PUF_DEVID,
        INIT_WAIT_DUS,
        INIT_DERIVE_KEYS,
        INIT_WAIT_KDF,
        INIT_DISTRIBUTE_KEYS,
        INIT_COMPLETE,
        FAULT
    } init_state_t;
    
    init_state_t init_state, init_next_state;
    
    // Initialization state machine
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            init_state <= INIT_IDLE;
        end else begin
            init_state <= init_next_state;
        end
    end
    
    // ====================================================================
    // Bug Fix: Signal Latching for State Machine
    // ====================================================================
    
    // Latch dus_valid to avoid timing hazard with puf_dus_ready
    // Also keeps DUS valid signal available for KDF module
    logic dus_valid_latched;
    
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            dus_valid_latched <= 1'b0;
        end else begin
            if (dus_valid) begin
                // Latch when dus_valid goes high
                dus_valid_latched <= 1'b1;
            end else if (init_state == INIT_IDLE || init_state == INIT_COMPLETE || init_state == FAULT) begin
                // Clear only when returning to idle/complete/fault states
                // Keep latched during INIT_DERIVE_KEYS and INIT_WAIT_KDF for KDF module
                dus_valid_latched <= 1'b0;
            end
        end
    end
    
    // Latch enrollment mode to prevent unwanted regeneration
    logic enroll_mode_latched;
    
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            enroll_mode_latched <= 1'b0;
        end else begin
            if (system_init) begin
                // Capture enrollment decision when system_init is asserted
                enroll_mode_latched <= puf_dus_enroll;
            end else if (init_state == INIT_IDLE) begin
                // Clear when returning to idle
                enroll_mode_latched <= 1'b0;
            end
        end
    end
    
    // Latch kdf_keys_valid to keep it available for key distributor
    logic kdf_keys_valid_latched;
    
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            kdf_keys_valid_latched <= 1'b0;
        end else begin
            if (kdf_keys_valid) begin
                // Latch when KDF completes
                kdf_keys_valid_latched <= 1'b1;
            end else if (init_state == INIT_IDLE || init_state == INIT_COMPLETE || init_state == FAULT) begin
                // Clear when returning to idle/complete/fault
                kdf_keys_valid_latched <= 1'b0;
            end
        end
    end
    
    // ====================================================================
    // State Machine Next State Logic
    // ====================================================================
    
    always_comb begin
        init_next_state = init_state;
        
        case (init_state)
            INIT_IDLE: begin
                if (zeroize_all) begin
                    init_next_state = FAULT;
                end else if (system_init) begin
                    init_next_state = INIT_PUF_DUS;
                end else if (derive_new_keys && keys_distributed) begin
                    // Allow key re-derivation if already initialized
                    init_next_state = INIT_DERIVE_KEYS;
                end
            end
            
            INIT_PUF_DUS: begin
                // Use latched dus_valid to avoid timing hazard with puf_dus_ready
                if (puf_dus_ready && dus_valid_latched) begin
                    init_next_state = INIT_PUF_DEVID;
                end else if (dus_error) begin
                    init_next_state = FAULT;
                end
            end
            
            INIT_PUF_DEVID: begin
                if (puf_devid_ready) begin
                    init_next_state = INIT_WAIT_DUS;
                end
            end
            
            INIT_WAIT_DUS: begin
                if (dus_valid) begin
                    init_next_state = INIT_DERIVE_KEYS;
                end
            end
            
            INIT_DERIVE_KEYS: begin
                if (kdf_ready) begin
                    init_next_state = INIT_WAIT_KDF;
                end
            end
            
            INIT_WAIT_KDF: begin
                if (kdf_valid && kdf_keys_valid) begin
                    init_next_state = INIT_DISTRIBUTE_KEYS;
                end
            end
            
            INIT_DISTRIBUTE_KEYS: begin
                if (keys_distributed) begin
                    init_next_state = INIT_COMPLETE;
                end
            end
            
            INIT_COMPLETE: begin
                if (zeroize_all) begin
                    init_next_state = FAULT;
                end else if (derive_new_keys) begin
                    init_next_state = INIT_DERIVE_KEYS;
                end
            end
            
            FAULT: begin
                // Stay in fault until reset
            end
        endcase
    end
    
    // Control signal generation based on init state
    logic puf_dus_enroll_internal;
    logic puf_dus_regenerate_internal;
    logic puf_devid_enroll_internal;
    
    always_comb begin
        // Defaults
        puf_dus_enroll_internal = 1'b0;
        puf_dus_regenerate_internal = 1'b0;
        puf_devid_enroll_internal = 1'b0;
        kdf_derive = 1'b0;
        key_dist_enable = 1'b0;
        key_dist_zeroize = 1'b0;
        kdf_context = 256'h524F4F545F4F465F545255535400000000000000000000000000000000000000; // "ROOT_OF_TRUST"
        
        case (init_state)
            INIT_PUF_DUS: begin
                // Use latched enrollment mode to prevent unwanted regeneration
                if (enroll_mode_latched) begin
                    puf_dus_enroll_internal = 1'b1;
                end else begin
                    puf_dus_regenerate_internal = 1'b1;
                end
            end
            
            INIT_PUF_DEVID: begin
                if (!puf_devid_enrolled) begin
                    puf_devid_enroll_internal = 1'b1;
                end
            end
            
            INIT_DERIVE_KEYS: begin
                kdf_derive = 1'b1;
            end
            
            INIT_DISTRIBUTE_KEYS: begin
                key_dist_enable = 1'b1;
            end
            
            FAULT: begin
                key_dist_zeroize = 1'b1;
            end
        endcase
        
        // Override for emergency zeroization
        if (zeroize_all) begin
            key_dist_zeroize = 1'b1;
        end
    end
    
    // ====================================================================
    // Module Instantiations
    // ====================================================================
    
    // PUF for Device Unique Secret (ISOLATED)
    puf_dus puf_dus_inst (
        .clock(clock),
        .reset(reset),
        .enroll(puf_dus_enroll_internal),
        .regenerate(puf_dus_regenerate_internal),
        .ready(puf_dus_ready),
        .valid(dus_valid),
        .error(dus_error),
        .helper_data(puf_dus_helper_out),
        .helper_data_in(puf_dus_helper_in),
        .helper_valid(puf_dus_helper_valid),
        .secret_out(dus_secret)
    );
    
    // PUF for Device ID (Bus-accessible)
    puf_device_id puf_devid_inst (
        .clock(clock),
        .reset(reset),
        .enroll(puf_devid_enroll_internal | puf_devid_enroll),
        .read_id(puf_devid_read),
        .ready(puf_devid_ready),
        .valid(device_id_valid),
        .enrolled_flag(puf_devid_enrolled),
        .device_id(device_id)
    );
    
    // Key Derivation Function (ISOLATED)
    kdf_module kdf_inst (
        .clock(clock),
        .reset(reset),
        .derive_keys(kdf_derive),
        .ready(kdf_ready),
        .valid(kdf_valid),
        .dus_secret(dus_secret),
        .dus_valid(dus_valid_latched),  // Use latched version for reliable operation
        .context_info(kdf_context),
        .hmac_key(kdf_hmac_key),
        .aes_key(kdf_aes_key),
        .sha_key(kdf_sha_key),
        .keys_valid(kdf_keys_valid)
    );
    
    // Secure Key Distributor (ISOLATED)
    secure_key_distributor key_dist_inst (
        .clock(clock),
        .reset(reset),
        .enable_distribution(key_dist_enable),
        .zeroize_keys(key_dist_zeroize),
        .keys_distributed(keys_distributed),
        .keys_active(keys_active),
        .kdf_hmac_key(kdf_hmac_key),
        .kdf_aes_key(kdf_aes_key),
        .kdf_sha_key(kdf_sha_key),
        .kdf_keys_valid(kdf_keys_valid_latched),  // Use latched version for reliable operation
        .hmac_key_out(hmac_key_internal),
        .hmac_key_valid(hmac_key_valid_internal),
        .aes_key_out(aes_key_internal),
        .aes_key_valid(aes_key_valid_internal),
        .sha_key_out(sha_key_internal),
        .sha_key_valid(sha_key_valid_internal)
    );
    
    // SHA-256 Core (Bus-accessible)
    sha256_core sha_inst (
        .clock(clock),
        .reset(reset),
        .start(sha_start),
        .init(sha_init),
        .ready(sha_ready),
        .valid(sha_valid),
        .message_block(sha_message),
        .hash_out(sha_hash)
    );
    
    // HMAC-SHA-256 (Bus-accessible, uses key from distributor)
    hmac_sha256 hmac_inst (
        .clock(clock),
        .reset(reset),
        .start(hmac_start),
        .init(hmac_init),
        .final_block(hmac_final),
        .ready(hmac_ready),
        .valid(hmac_valid),
        .busy(),  // Not connected
        .hmac_key(hmac_key_internal),
        .key_valid(hmac_key_valid_internal),
        .message_block(hmac_message),
        .message_length(10'd512),  // Full block
        .mac_out(hmac_mac)
    );
    
    // AES-CTR (Bus-accessible, uses key from distributor)
    aes_ctr aes_inst (
        .clock(clock),
        .reset(reset),
        .start(aes_start),
        .init(aes_init),
        .ready(aes_ready),
        .valid(aes_valid),
        .busy(),  // Not connected
        .aes_key(aes_key_internal),
        .key_valid(aes_key_valid_internal),
        .nonce(aes_nonce),
        .counter_init(aes_counter_init),
        .data_in(aes_data_in),
        .data_out(aes_data_out)
    );
    
    // ====================================================================
    // System Status
    // ====================================================================
    
    always_comb begin
        system_ready = (init_state == INIT_COMPLETE);
        security_fault = (init_state == FAULT) || dus_error;
    end

endmodule
