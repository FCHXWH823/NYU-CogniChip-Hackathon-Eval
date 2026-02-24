// Secure Key Distributor Module
// Distributes derived keys from KDF to crypto modules
// COMPLETELY ISOLATED - No bus access, hardware-only paths
// Ensures keys never leak outside secure perimeter

module secure_key_distributor (
    input  logic        clock,
    input  logic        reset,
    
    // Control interface (from secure controller)
    input  logic        enable_distribution, // Enable key distribution
    input  logic        zeroize_keys,        // Emergency key zeroization
    output logic        keys_distributed,    // Keys successfully distributed
    output logic        keys_active,         // Keys are active and valid
    
    // Input from KDF (ISOLATED)
    input  logic [255:0] kdf_hmac_key,      // HMAC key from KDF
    input  logic [255:0] kdf_aes_key,       // AES key from KDF
    input  logic [255:0] kdf_sha_key,       // SHA key from KDF
    input  logic         kdf_keys_valid,    // KDF keys are valid
    
    // Output to HMAC-SHA-256 (ISOLATED)
    output logic [255:0] hmac_key_out,
    output logic         hmac_key_valid,
    
    // Output to AES-CTR (ISOLATED)
    output logic [255:0] aes_key_out,
    output logic         aes_key_valid,
    
    // Output to SHA-256 (ISOLATED - for keyed operations)
    output logic [255:0] sha_key_out,
    output logic         sha_key_valid
);

    // State machine for secure key distribution
    typedef enum logic [2:0] {
        IDLE,
        VALIDATE_KEYS,
        DISTRIBUTE,
        ACTIVE,
        ZEROIZE
    } state_t;
    
    state_t state, next_state;
    
    // Key storage registers (isolated, never exposed to bus)
    logic [255:0] hmac_key_reg;
    logic [255:0] aes_key_reg;
    logic [255:0] sha_key_reg;
    
    // Key validity tracking
    logic keys_valid_reg;
    logic keys_locked;  // Once locked, keys cannot be changed without zeroization
    
    // Tamper detection (simple integrity check)
    logic [7:0] integrity_counter;
    logic integrity_fail;
    
    // State machine
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end
    
    always_comb begin
        next_state = state;
        
        case (state)
            IDLE: begin
                if (zeroize_keys) begin
                    next_state = ZEROIZE;
                end else if (enable_distribution && kdf_keys_valid && !keys_locked) begin
                    next_state = VALIDATE_KEYS;
                end
            end
            
            VALIDATE_KEYS: begin
                // Validate keys are non-zero (basic sanity check)
                if (kdf_hmac_key != 256'h0 && 
                    kdf_aes_key != 256'h0 && 
                    kdf_sha_key != 256'h0) begin
                    next_state = DISTRIBUTE;
                end else begin
                    next_state = IDLE;
                end
            end
            
            DISTRIBUTE: begin
                next_state = ACTIVE;
            end
            
            ACTIVE: begin
                if (zeroize_keys) begin
                    next_state = ZEROIZE;
                end
                // Stay active until zeroization
            end
            
            ZEROIZE: begin
                next_state = IDLE;
            end
        endcase
    end
    
    // Key distribution logic
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            hmac_key_reg <= 256'h0;
            aes_key_reg <= 256'h0;
            sha_key_reg <= 256'h0;
            keys_valid_reg <= 1'b0;
            keys_locked <= 1'b0;
        end else begin
            case (state)
                IDLE: begin
                    keys_valid_reg <= 1'b0;
                    if (next_state == ZEROIZE) begin
                        keys_locked <= 1'b0;
                    end
                end
                
                VALIDATE_KEYS: begin
                    // No changes yet, just validation
                end
                
                DISTRIBUTE: begin
                    // Securely transfer keys from KDF to local registers
                    hmac_key_reg <= kdf_hmac_key;
                    aes_key_reg <= kdf_aes_key;
                    sha_key_reg <= kdf_sha_key;
                    keys_valid_reg <= 1'b1;
                    keys_locked <= 1'b1;  // Lock keys after first distribution
                end
                
                ACTIVE: begin
                    // Keys remain stable
                    keys_valid_reg <= 1'b1;
                end
                
                ZEROIZE: begin
                    // Emergency zeroization - overwrite all key material
                    hmac_key_reg <= 256'h0;
                    aes_key_reg <= 256'h0;
                    sha_key_reg <= 256'h0;
                    keys_valid_reg <= 1'b0;
                    keys_locked <= 1'b0;
                end
            endcase
        end
    end
    
    // Integrity monitoring (detect potential tampering)
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            integrity_counter <= 8'h0;
            integrity_fail <= 1'b0;
        end else begin
            if (state == ACTIVE) begin
                // Periodically verify key registers haven't been corrupted
                integrity_counter <= integrity_counter + 8'h1;
                
                // Simple integrity check: verify keys are still non-zero
                if (integrity_counter == 8'hFF) begin
                    if (hmac_key_reg == 256'h0 || 
                        aes_key_reg == 256'h0 || 
                        sha_key_reg == 256'h0) begin
                        integrity_fail <= 1'b1;
                    end
                end
            end else begin
                integrity_counter <= 8'h0;
                if (state == ZEROIZE || state == IDLE) begin
                    integrity_fail <= 1'b0;
                end
            end
        end
    end
    
    // Output assignments (isolated paths to crypto modules)
    always_comb begin
        // Only output keys when valid and not failed
        if (keys_valid_reg && !integrity_fail) begin
            hmac_key_out = hmac_key_reg;
            aes_key_out = aes_key_reg;
            sha_key_out = sha_key_reg;
            hmac_key_valid = 1'b1;
            aes_key_valid = 1'b1;
            sha_key_valid = 1'b1;
        end else begin
            // Output zeros if keys not valid or integrity failed
            hmac_key_out = 256'h0;
            aes_key_out = 256'h0;
            sha_key_out = 256'h0;
            hmac_key_valid = 1'b0;
            aes_key_valid = 1'b0;
            sha_key_valid = 1'b0;
        end
        
        // Status outputs
        keys_distributed = (state == ACTIVE);
        keys_active = (state == ACTIVE) && !integrity_fail;
    end
    
    // Security assertions (for verification)
    // synthesis translate_off
    always @(posedge clock) begin
        // Ensure keys are never all-ones (invalid state)
        if (state == ACTIVE) begin
            assert (hmac_key_reg != 256'hFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF)
                else $error("HMAC key is all-ones - security violation!");
            assert (aes_key_reg != 256'hFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF)
                else $error("AES key is all-ones - security violation!");
            assert (sha_key_reg != 256'hFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF)
                else $error("SHA key is all-ones - security violation!");
        end
        
        // Ensure keys are zeroized when commanded
        if (state == ZEROIZE) begin
            assert (next_state == IDLE) 
                else $error("Zeroize must return to IDLE!");
        end
        
        // Ensure keys don't change while active
        if (state == ACTIVE && $past(state) == ACTIVE && !zeroize_keys) begin
            assert (hmac_key_reg == $past(hmac_key_reg))
                else $error("HMAC key changed while active!");
            assert (aes_key_reg == $past(aes_key_reg))
                else $error("AES key changed while active!");
            assert (sha_key_reg == $past(sha_key_reg))
                else $error("SHA key changed while active!");
        end
    end
    // synthesis translate_on

endmodule
