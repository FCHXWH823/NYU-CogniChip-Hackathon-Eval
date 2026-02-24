// Key Derivation Function (KDF) Module
// Implements HKDF (HMAC-based KDF) using SHA-256
// ISOLATED MODULE - No bus access
// Takes DUS from PUF and derives keys for crypto modules

module kdf_module (
    input  logic        clock,
    input  logic        reset,
    
    // Control interface
    input  logic        derive_keys,    // Start key derivation
    output logic        ready,          // Ready for operation
    output logic        valid,          // Keys valid
    
    // Input from PUF_DUS (ISOLATED)
    input  logic [255:0] dus_secret,    // Device Unique Secret
    input  logic         dus_valid,     // DUS is valid
    
    // Context/Info for key derivation
    input  logic [255:0] context_info,  // Application context
    
    // Derived keys output (ISOLATED - only to crypto modules)
    output logic [255:0] hmac_key,      // Key for HMAC-SHA-256
    output logic [255:0] aes_key,       // Key for AES-CTR (256-bit)
    output logic [255:0] sha_key,       // Key for SHA-256 operations
    output logic         keys_valid     // All keys are valid
);

    // State machine
    typedef enum logic [3:0] {
        IDLE,
        EXTRACT_INIT,
        EXTRACT_INNER,
        EXTRACT_OUTER,
        EXPAND_HMAC_1,
        EXPAND_HMAC_2,
        EXPAND_AES_1,
        EXPAND_AES_2,
        EXPAND_SHA_1,
        EXPAND_SHA_2,
        DONE
    } state_t;
    
    state_t state, next_state;
    
    // SHA-256 core interface
    logic         sha_start;
    logic         sha_init;
    logic         sha_ready;
    logic         sha_valid;
    logic [511:0] sha_message;
    logic [255:0] sha_hash;
    
    // Instantiate SHA-256 core
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
    
    // HKDF parameters
    localparam logic [255:0] SALT = 256'h5048_4B44_465F_5341_4C54_5F46_4F52_5F48_4D41_435F_4B44_465F_5348_4132_3536_0000;
    
    // Context labels for key derivation
    localparam logic [255:0] HMAC_LABEL = 256'h484D41435F4B45595F434F4E54455854_00000000000000000000000000000000; // "HMAC_KEY_CONTEXT"
    localparam logic [255:0] AES_LABEL  = 256'h4145535F4B45595F434F4E54455854_0000000000000000000000000000000000; // "AES_KEY_CONTEXT"
    localparam logic [255:0] SHA_LABEL  = 256'h5348415F4B45595F434F4E54455854_0000000000000000000000000000000000; // "SHA_KEY_CONTEXT"
    
    // Intermediate values
    logic [255:0] prk;          // Pseudo-Random Key from extract phase
    logic [255:0] t_prev;       // T(i-1) for expand phase
    logic [255:0] hmac_key_reg;
    logic [255:0] aes_key_reg;
    logic [255:0] sha_key_reg;
    
    // HMAC computation registers
    logic [255:0] ipad_key;
    logic [255:0] opad_key;
    logic [255:0] inner_hash;
    
    // Constants for HMAC
    localparam logic [7:0] IPAD = 8'h36;
    localparam logic [7:0] OPAD = 8'h5C;
    
    // Counter for multi-block operations
    logic [2:0] block_count;
    
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
                if (derive_keys && dus_valid) begin
                    next_state = EXTRACT_INIT;
                end
            end
            
            EXTRACT_INIT: begin
                if (sha_ready) begin
                    next_state = EXTRACT_INNER;
                end
            end
            
            EXTRACT_INNER: begin
                if (sha_valid) begin
                    next_state = EXTRACT_OUTER;
                end
            end
            
            EXTRACT_OUTER: begin
                if (sha_valid) begin
                    next_state = EXPAND_HMAC_1;
                end
            end
            
            EXPAND_HMAC_1: begin
                if (sha_valid) begin
                    next_state = EXPAND_HMAC_2;
                end
            end
            
            EXPAND_HMAC_2: begin
                if (sha_valid) begin
                    next_state = EXPAND_AES_1;
                end
            end
            
            EXPAND_AES_1: begin
                if (sha_valid) begin
                    next_state = EXPAND_AES_2;
                end
            end
            
            EXPAND_AES_2: begin
                if (sha_valid) begin
                    next_state = EXPAND_SHA_1;
                end
            end
            
            EXPAND_SHA_1: begin
                if (sha_valid) begin
                    next_state = EXPAND_SHA_2;
                end
            end
            
            EXPAND_SHA_2: begin
                if (sha_valid) begin
                    next_state = DONE;
                end
            end
            
            DONE: begin
                next_state = IDLE;
            end
        endcase
    end
    
    // SHA-256 control and data preparation
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            sha_start <= 1'b0;
            sha_init <= 1'b0;
            sha_message <= 512'h0;
            prk <= 256'h0;
            inner_hash <= 256'h0;
            t_prev <= 256'h0;
            hmac_key_reg <= 256'h0;
            aes_key_reg <= 256'h0;
            sha_key_reg <= 256'h0;
            block_count <= 3'd0;
        end else begin
            // Default: deassert start
            sha_start <= 1'b0;
            
            case (state)
                IDLE: begin
                    block_count <= 3'd0;
                    t_prev <= 256'h0;
                end
                
                // HKDF-Extract: PRK = HMAC-SHA256(salt, DUS)
                EXTRACT_INIT: begin
                    if (sha_ready) begin
                        // Prepare inner hash: H((salt XOR ipad) || DUS)
                        // For simplicity, using salt directly (assuming key length = hash length)
                        ipad_key = SALT ^ {32{IPAD}};
                        
                        // First block: (salt XOR ipad) || first 256 bits of DUS
                        sha_message <= {ipad_key, dus_secret};
                        sha_init <= 1'b1;
                        sha_start <= 1'b1;
                    end
                end
                
                EXTRACT_INNER: begin
                    if (sha_valid) begin
                        inner_hash <= sha_hash;
                        
                        // Prepare outer hash: H((salt XOR opad) || inner_hash)
                        // Use sha_hash directly to avoid timing issue
                        opad_key = SALT ^ {32{OPAD}};
                        sha_message <= {opad_key, sha_hash};  // Use sha_hash, not inner_hash
                        sha_init <= 1'b1;
                        sha_start <= 1'b1;
                    end
                end
                
                EXTRACT_OUTER: begin
                    if (sha_valid) begin
                        prk <= sha_hash; // This is our PRK
                    end
                end
                
                // HKDF-Expand for HMAC key: T(1) = HMAC(PRK, info || 0x01)
                EXPAND_HMAC_1: begin
                    if (sha_ready && state == EXPAND_HMAC_1 && next_state == EXPAND_HMAC_1) begin
                        // Inner: H((PRK XOR ipad) || HMAC_LABEL || context || 0x01)
                        ipad_key = prk ^ {32{IPAD}};
                        sha_message <= {ipad_key, HMAC_LABEL ^ context_info};
                        sha_init <= 1'b1;
                        sha_start <= 1'b1;
                    end else if (sha_valid && next_state == EXPAND_HMAC_2) begin
                        // Inner hash complete, start outer hash immediately
                        inner_hash <= sha_hash;
                        opad_key = prk ^ {32{OPAD}};
                        sha_message <= {opad_key, sha_hash};
                        sha_init <= 1'b1;
                        sha_start <= 1'b1;
                    end
                end
                
                EXPAND_HMAC_2: begin
                    // Just wait for outer hash to complete
                    if (state == EXPAND_HMAC_2 && next_state == EXPAND_AES_1) begin
                        hmac_key_reg <= sha_hash;
                        t_prev <= sha_hash;
                    end
                end
                
                // HKDF-Expand for AES key: T(2) = HMAC(PRK, T(1) || info || 0x02)
                EXPAND_AES_1: begin
                    if (sha_ready && state == EXPAND_AES_1 && next_state == EXPAND_AES_1) begin
                        ipad_key = prk ^ {32{IPAD}};
                        sha_message <= {ipad_key, AES_LABEL ^ context_info};
                        sha_init <= 1'b1;
                        sha_start <= 1'b1;
                    end else if (sha_valid && next_state == EXPAND_AES_2) begin
                        // Inner hash complete, start outer hash immediately
                        inner_hash <= sha_hash;
                        opad_key = prk ^ {32{OPAD}};
                        sha_message <= {opad_key, sha_hash};
                        sha_init <= 1'b1;
                        sha_start <= 1'b1;
                    end
                end
                
                EXPAND_AES_2: begin
                    // Just wait for outer hash to complete
                    if (state == EXPAND_AES_2 && next_state == EXPAND_SHA_1) begin
                        aes_key_reg <= sha_hash;
                        t_prev <= sha_hash;
                    end
                end
                
                // HKDF-Expand for SHA key: T(3) = HMAC(PRK, T(2) || info || 0x03)
                EXPAND_SHA_1: begin
                    if (sha_ready && state == EXPAND_SHA_1 && next_state == EXPAND_SHA_1) begin
                        ipad_key = prk ^ {32{IPAD}};
                        sha_message <= {ipad_key, SHA_LABEL ^ context_info};
                        sha_init <= 1'b1;
                        sha_start <= 1'b1;
                    end else if (sha_valid && next_state == EXPAND_SHA_2) begin
                        // Inner hash complete, start outer hash immediately
                        inner_hash <= sha_hash;
                        opad_key = prk ^ {32{OPAD}};
                        sha_message <= {opad_key, sha_hash};
                        sha_init <= 1'b1;
                        sha_start <= 1'b1;
                    end
                end
                
                EXPAND_SHA_2: begin
                    // Just wait for outer hash to complete
                    if (state == EXPAND_SHA_2 && next_state == DONE) begin
                        sha_key_reg <= sha_hash;
                    end
                end
                
                DONE: begin
                    // Keys are stable
                end
            endcase
        end
    end
    
    // Output logic
    always_comb begin
        ready = (state == IDLE);
        valid = (state == DONE);
        keys_valid = (state == DONE);
        
        hmac_key = hmac_key_reg;
        aes_key = aes_key_reg;
        sha_key = sha_key_reg;
    end

endmodule
