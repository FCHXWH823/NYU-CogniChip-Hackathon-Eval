// HMAC-SHA-256 Module
// Implements Hash-based Message Authentication Code using SHA-256
// BUS-ACCESSIBLE - Can be used for message authentication
// Uses derived key from KDF

module hmac_sha256 (
    input  logic        clock,
    input  logic        reset,
    
    // Control interface
    input  logic        start,          // Start HMAC computation
    input  logic        init,           // Initialize (first block)
    input  logic        final_block,    // Final block (complete HMAC)
    output logic        ready,          // Ready for operation
    output logic        valid,          // MAC output valid
    output logic        busy,           // Operation in progress
    
    // Key input (from KDF - isolated path)
    input  logic [255:0] hmac_key,      // 256-bit key from KDF
    input  logic         key_valid,     // Key is valid
    
    // Data interface
    input  logic [511:0] message_block, // 512-bit message block
    input  logic [9:0]   message_length,// Message length in this block (bytes)
    output logic [255:0] mac_out        // 256-bit MAC output
);

    // State machine
    typedef enum logic [2:0] {
        IDLE,
        INNER_INIT,
        INNER_HASH,
        OUTER_INIT,
        OUTER_HASH,
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
    
    // HMAC pads
    localparam logic [7:0] IPAD = 8'h36;
    localparam logic [7:0] OPAD = 8'h5C;
    
    // Key processing (K ⊕ ipad and K ⊕ opad)
    logic [255:0] key_ipad;  // K ⊕ ipad (inner pad)
    logic [255:0] key_opad;  // K ⊕ opad (outer pad)
    
    // Intermediate hash storage
    logic [255:0] inner_hash;    // Result of inner hash
    logic [255:0] mac_reg;       // Final MAC value
    
    // Block tracking
    logic first_message_block;
    logic is_final_block;
    
    // Compute padded keys
    always_comb begin
        key_ipad = hmac_key ^ {32{IPAD}};
        key_opad = hmac_key ^ {32{OPAD}};
    end
    
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
                if (start && key_valid) begin
                    next_state = INNER_INIT;
                end
            end
            
            INNER_INIT: begin
                // Start SHA operation, then immediately move to INNER_HASH to wait for completion
                if (sha_ready) begin
                    next_state = INNER_HASH;
                end
            end
            
            INNER_HASH: begin
                if (sha_valid) begin
                    if (is_final_block) begin
                        next_state = OUTER_INIT;
                    end else begin
                        next_state = IDLE; // Wait for next block
                    end
                end
            end
            
            OUTER_INIT: begin
                if (sha_ready) begin
                    next_state = OUTER_HASH;
                end
            end
            
            OUTER_HASH: begin
                if (sha_valid) begin
                    next_state = DONE;
                end
            end
            
            DONE: begin
                next_state = IDLE;
            end
        endcase
    end
    
    // Track first block and final block
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            first_message_block <= 1'b1;
            is_final_block <= 1'b0;
        end else begin
            if (state == IDLE && start) begin
                first_message_block <= init;
                is_final_block <= final_block;
            end else if (state == INNER_HASH && sha_valid) begin
                first_message_block <= 1'b0;
            end
        end
    end
    
    // SHA-256 control logic
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            sha_start <= 1'b0;
            sha_init <= 1'b0;
            sha_message <= 512'h0;
            inner_hash <= 256'h0;
            mac_reg <= 256'h0;
        end else begin
            // Default: deassert start
            sha_start <= 1'b0;
            sha_init <= 1'b0;
            
            case (state)
                IDLE: begin
                    if (start && key_valid) begin
                        // No action here, prepare in next state
                    end
                end
                
                INNER_INIT: begin
                    if (sha_ready) begin
                        if (first_message_block) begin
                            // First block: H((K ⊕ ipad) || M[0])
                            sha_message <= {key_ipad, message_block[511:256]};
                            sha_init <= 1'b1;
                            sha_start <= 1'b1;
                        end else begin
                            // Continue hashing: H(... || M[i])
                            sha_message <= message_block;
                            sha_init <= 1'b0;
                            sha_start <= 1'b1;
                        end
                    end
                end
                
                INNER_HASH: begin
                    if (sha_valid) begin
                        if (is_final_block) begin
                            // Store inner hash result
                            inner_hash <= sha_hash;
                        end
                    end
                end
                
                OUTER_INIT: begin
                    if (sha_ready) begin
                        // Outer hash: H((K ⊕ opad) || inner_hash)
                        sha_message <= {key_opad, inner_hash};
                        sha_init <= 1'b1;
                        sha_start <= 1'b1;
                    end
                end
                
                OUTER_HASH: begin
                    if (sha_valid) begin
                        // Store final MAC
                        mac_reg <= sha_hash;
                    end
                end
                
                DONE: begin
                    // MAC is stable
                end
            endcase
        end
    end
    
    // Output logic
    always_comb begin
        ready = (state == IDLE);
        valid = (state == DONE);
        busy = (state != IDLE) && (state != DONE);
        mac_out = mac_reg;
    end

endmodule
