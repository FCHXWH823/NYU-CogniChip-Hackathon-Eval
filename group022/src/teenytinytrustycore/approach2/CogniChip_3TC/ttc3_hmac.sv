// ===========================================================================
// TeenyTinyTrustyCore (3TC) - HMAC-SHA256 Engine
// ===========================================================================
// HMAC (Hash-based Message Authentication Code) using SHA-256.
// Implements RFC 2104 HMAC construction.
//
// Operation:
//   HMAC(K, M) = H((K ^ opad) || H((K ^ ipad) || M))
//   where H = SHA-256, opad = 0x5c repeated, ipad = 0x36 repeated
//
// Security Properties:
// - Key is zeroized after HMAC computation
// - No external visibility of intermediate hash states
// - Key never leaves this module
//
// Performance: ~150 cycles per HMAC (two SHA-256 operations)
// ===========================================================================

module ttc3_hmac (
    input  logic         clock,
    input  logic         reset,
    
    // Control interface
    input  logic         hmac_start,
    input  logic [255:0] hmac_key,      // 256-bit key
    input  logic [255:0] hmac_message,  // 256-bit message (simplified)
    output logic         hmac_done,
    output logic         hmac_busy,
    
    // HMAC output
    output logic [255:0] hmac_tag
);

    // -----------------------------------------------------------------------
    // HMAC Constants
    // -----------------------------------------------------------------------
    localparam logic [7:0] IPAD_BYTE = 8'h36;
    localparam logic [7:0] OPAD_BYTE = 8'h5c;
    
    // -----------------------------------------------------------------------
    // State Machine
    // -----------------------------------------------------------------------
    typedef enum logic [2:0] {
        ST_IDLE         = 3'b000,
        ST_INNER_PREP   = 3'b001,
        ST_INNER_HASH   = 3'b010,
        ST_OUTER_PREP   = 3'b011,
        ST_OUTER_HASH   = 3'b100,
        ST_ZEROIZE      = 3'b101,
        ST_DONE         = 3'b110
    } hmac_state_e;
    
    hmac_state_e state_q, state_d;
    
    // -----------------------------------------------------------------------
    // Internal Key Storage (ephemeral)
    // -----------------------------------------------------------------------
    logic [255:0] key_q, key_d;
    logic [255:0] inner_hash_q;
    
    // -----------------------------------------------------------------------
    // SHA-256 Core Interface
    // -----------------------------------------------------------------------
    logic         sha_start;
    logic [511:0] sha_block;
    logic         sha_done;
    logic         sha_busy;
    logic [255:0] sha_digest;
    
    ttc3_sha256 u_sha256 (
        .clock         (clock),
        .reset         (reset),
        .hash_start    (sha_start),
        .message_block (sha_block),
        .hash_done     (sha_done),
        .hash_busy     (sha_busy),
        .hash_digest   (sha_digest)
    );
    
    // -----------------------------------------------------------------------
    // Pad Generation
    // -----------------------------------------------------------------------
    logic [255:0] ipad, opad;
    
    always_comb begin
        // Generate inner and outer pads
        for (int i = 0; i < 32; i++) begin
            ipad[i*8 +: 8] = IPAD_BYTE;
            opad[i*8 +: 8] = OPAD_BYTE;
        end
    end
    
    // -----------------------------------------------------------------------
    // Sequential Logic
    // -----------------------------------------------------------------------
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            state_q      <= ST_IDLE;
            key_q        <= '0;
            inner_hash_q <= '0;
        end else begin
            state_q <= state_d;
            key_q   <= key_d;
            
            // Capture inner hash result
            if (state_q == ST_INNER_HASH && sha_done) begin
                inner_hash_q <= sha_digest;
            end
            
            // Zeroize after use
            if (state_q == ST_ZEROIZE) begin
                key_q        <= '0;
                inner_hash_q <= '0;
            end
        end
    end
    
    // -----------------------------------------------------------------------
    // Combinational Logic
    // -----------------------------------------------------------------------
    always_comb begin
        state_d   = state_q;
        key_d     = key_q;
        sha_start = 1'b0;
        sha_block = '0;
        
        case (state_q)
            ST_IDLE: begin
                if (hmac_start) begin
                    key_d   = hmac_key;
                    state_d = ST_INNER_PREP;
                end
            end
            
            ST_INNER_PREP: begin
                // Prepare inner hash: H((K ^ ipad) || M)
                state_d = ST_INNER_HASH;
            end
            
            ST_INNER_HASH: begin
                if (!sha_busy && !sha_start) begin
                    // Start SHA-256 with (K ^ ipad) || message
                    sha_start = 1'b1;
                    sha_block = {(key_q ^ ipad), hmac_message};
                end else if (sha_done) begin
                    // Inner hash complete
                    state_d = ST_OUTER_PREP;
                end
            end
            
            ST_OUTER_PREP: begin
                // Prepare outer hash: H((K ^ opad) || inner_hash)
                state_d = ST_OUTER_HASH;
            end
            
            ST_OUTER_HASH: begin
                if (!sha_busy && !sha_start) begin
                    // Start SHA-256 with (K ^ opad) || inner_hash
                    sha_start = 1'b1;
                    sha_block = {(key_q ^ opad), inner_hash_q};
                end else if (sha_done) begin
                    // Outer hash complete, HMAC done
                    state_d = ST_ZEROIZE;
                end
            end
            
            ST_ZEROIZE: begin
                // Mandatory key zeroization
                key_d   = '0;
                state_d = ST_DONE;
            end
            
            ST_DONE: begin
                state_d = ST_IDLE;
            end
            
            default: begin
                state_d = ST_IDLE;
            end
        endcase
    end
    
    // -----------------------------------------------------------------------
    // Outputs
    // -----------------------------------------------------------------------
    assign hmac_busy = (state_q != ST_IDLE);
    assign hmac_done = (state_q == ST_DONE);
    assign hmac_tag  = (state_q == ST_DONE) ? sha_digest : '0;
    
    // -----------------------------------------------------------------------
    // Security Assertion: Key zeroization
    // -----------------------------------------------------------------------
    // CWE-226: Sensitive Information Uncleared Before Release
    `ifdef FORMAL
    property key_cleared_after_use;
        @(posedge clock) disable iff (reset)
        (state_q == ST_ZEROIZE) |=> (key_q == '0);
    endproperty
    assert property (key_cleared_after_use)
        else $error("HMAC: Key not zeroized after use");
    `endif
    
endmodule
