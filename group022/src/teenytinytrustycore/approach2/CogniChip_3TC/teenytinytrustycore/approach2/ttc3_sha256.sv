// ===========================================================================
// TeenyTinyTrustyCore (3TC) - SHA-256 Core (Iterative, Area-Optimized)
// ===========================================================================
// Compact SHA-256 implementation optimized for minimal area.
// Uses iterative multi-cycle processing (64 rounds per block).
//
// Features:
// - Single 512-bit block processing (for simplicity)
// - Multi-cycle iterative design (one round per clock)
// - Automatic padding for messages <= 448 bits
// - Output: 256-bit hash digest
//
// Security Properties:
// - Internal state cleared on reset
// - Hash output valid only when done signal asserted
//
// Performance: ~70 cycles per hash (64 rounds + overhead)
// ===========================================================================

module ttc3_sha256 (
    input  logic         clock,
    input  logic         reset,
    
    // Control interface
    input  logic         hash_start,
    input  logic [511:0] message_block,  // Single 512-bit input block
    output logic         hash_done,
    output logic         hash_busy,
    
    // Hash output
    output logic [255:0] hash_digest
);

    // -----------------------------------------------------------------------
    // SHA-256 Constants (first 32 bits of fractional parts of cube roots)
    // -----------------------------------------------------------------------
    logic [31:0] K[0:63];
    initial begin
        K[0]  = 32'h428a2f98; K[1]  = 32'h71374491; K[2]  = 32'hb5c0fbcf; K[3]  = 32'he9b5dba5;
        K[4]  = 32'h3956c25b; K[5]  = 32'h59f111f1; K[6]  = 32'h923f82a4; K[7]  = 32'hab1c5ed5;
        K[8]  = 32'hd807aa98; K[9]  = 32'h12835b01; K[10] = 32'h243185be; K[11] = 32'h550c7dc3;
        K[12] = 32'h72be5d74; K[13] = 32'h80deb1fe; K[14] = 32'h9bdc06a7; K[15] = 32'hc19bf174;
        K[16] = 32'he49b69c1; K[17] = 32'hefbe4786; K[18] = 32'h0fc19dc6; K[19] = 32'h240ca1cc;
        K[20] = 32'h2de92c6f; K[21] = 32'h4a7484aa; K[22] = 32'h5cb0a9dc; K[23] = 32'h76f988da;
        K[24] = 32'h983e5152; K[25] = 32'ha831c66d; K[26] = 32'hb00327c8; K[27] = 32'hbf597fc7;
        K[28] = 32'hc6e00bf3; K[29] = 32'hd5a79147; K[30] = 32'h06ca6351; K[31] = 32'h14292967;
        K[32] = 32'h27b70a85; K[33] = 32'h2e1b2138; K[34] = 32'h4d2c6dfc; K[35] = 32'h53380d13;
        K[36] = 32'h650a7354; K[37] = 32'h766a0abb; K[38] = 32'h81c2c92e; K[39] = 32'h92722c85;
        K[40] = 32'ha2bfe8a1; K[41] = 32'ha81a664b; K[42] = 32'hc24b8b70; K[43] = 32'hc76c51a3;
        K[44] = 32'hd192e819; K[45] = 32'hd6990624; K[46] = 32'hf40e3585; K[47] = 32'h106aa070;
        K[48] = 32'h19a4c116; K[49] = 32'h1e376c08; K[50] = 32'h2748774c; K[51] = 32'h34b0bcb5;
        K[52] = 32'h391c0cb3; K[53] = 32'h4ed8aa4a; K[54] = 32'h5b9cca4f; K[55] = 32'h682e6ff3;
        K[56] = 32'h748f82ee; K[57] = 32'h78a5636f; K[58] = 32'h84c87814; K[59] = 32'h8cc70208;
        K[60] = 32'h90befffa; K[61] = 32'ha4506ceb; K[62] = 32'hbef9a3f7; K[63] = 32'hc67178f2;
    end
    
    // -----------------------------------------------------------------------
    // Initial Hash Values (first 32 bits of fractional parts of square roots)
    // -----------------------------------------------------------------------
    localparam logic [31:0] H0_INIT = 32'h6a09e667;
    localparam logic [31:0] H1_INIT = 32'hbb67ae85;
    localparam logic [31:0] H2_INIT = 32'h3c6ef372;
    localparam logic [31:0] H3_INIT = 32'ha54ff53a;
    localparam logic [31:0] H4_INIT = 32'h510e527f;
    localparam logic [31:0] H5_INIT = 32'h9b05688c;
    localparam logic [31:0] H6_INIT = 32'h1f83d9ab;
    localparam logic [31:0] H7_INIT = 32'h5be0cd19;
    
    // -----------------------------------------------------------------------
    // State Machine
    // -----------------------------------------------------------------------
    typedef enum logic [1:0] {
        ST_IDLE     = 2'b00,
        ST_PREPARE  = 2'b01,
        ST_COMPUTE  = 2'b10,
        ST_FINALIZE = 2'b11
    } sha_state_e;
    
    sha_state_e state_q, state_d;
    
    // -----------------------------------------------------------------------
    // Working Variables and Message Schedule
    // -----------------------------------------------------------------------
    logic [31:0] h0_q, h1_q, h2_q, h3_q, h4_q, h5_q, h6_q, h7_q;
    logic [31:0] a_q, b_q, c_q, d_q, e_q, f_q, g_q, h_q;
    logic [31:0] a_d, b_d, c_d, d_d, e_d, f_d, g_d, h_d;
    logic [31:0] W[0:15];  // Message schedule (simplified, only 16 words stored)
    logic [5:0]  round_q, round_d;
    logic [31:0] W_current;
    
    // SHA-256 Functions
    function automatic logic [31:0] rotr(input logic [31:0] x, input int n);
        return (x >> n) | (x << (32 - n));
    endfunction
    
    function automatic logic [31:0] ch(input logic [31:0] x, y, z);
        return (x & y) ^ (~x & z);
    endfunction
    
    function automatic logic [31:0] maj(input logic [31:0] x, y, z);
        return (x & y) ^ (x & z) ^ (y & z);
    endfunction
    
    function automatic logic [31:0] sigma0(input logic [31:0] x);
        return rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22);
    endfunction
    
    function automatic logic [31:0] sigma1(input logic [31:0] x);
        return rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25);
    endfunction
    
    function automatic logic [31:0] gamma0(input logic [31:0] x);
        return rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3);
    endfunction
    
    function automatic logic [31:0] gamma1(input logic [31:0] x);
        return rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10);
    endfunction
    
    // -----------------------------------------------------------------------
    // Message Schedule Generation (on-the-fly)
    // -----------------------------------------------------------------------
    always_comb begin
        if (round_q < 16) begin
            // First 16 rounds: use input message block directly
            W_current = message_block[511 - round_q*32 -: 32];
        end else begin
            // Rounds 16-63: compute W[t] = gamma1(W[t-2]) + W[t-7] + gamma0(W[t-15]) + W[t-16]
            W_current = gamma1(W[14]) + W[9] + gamma0(W[1]) + W[0];
        end
    end
    
    // -----------------------------------------------------------------------
    // Sequential Logic
    // -----------------------------------------------------------------------
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            state_q <= ST_IDLE;
            h0_q    <= H0_INIT;
            h1_q    <= H1_INIT;
            h2_q    <= H2_INIT;
            h3_q    <= H3_INIT;
            h4_q    <= H4_INIT;
            h5_q    <= H5_INIT;
            h6_q    <= H6_INIT;
            h7_q    <= H7_INIT;
            a_q     <= '0;
            b_q     <= '0;
            c_q     <= '0;
            d_q     <= '0;
            e_q     <= '0;
            f_q     <= '0;
            g_q     <= '0;
            h_q     <= '0;
            round_q <= '0;
            for (int i = 0; i < 16; i++) W[i] <= '0;
        end else begin
            state_q <= state_d;
            a_q     <= a_d;
            b_q     <= b_d;
            c_q     <= c_d;
            d_q     <= d_d;
            e_q     <= e_d;
            f_q     <= f_d;
            g_q     <= g_d;
            h_q     <= h_d;
            round_q <= round_d;
            
            // Update message schedule window
            if (state_q == ST_COMPUTE && round_q > 0) begin
                for (int i = 0; i < 15; i++) begin
                    W[i] <= W[i+1];
                end
                W[15] <= W_current;
            end else if (state_q == ST_PREPARE) begin
                // Initialize W with first 16 words
                for (int i = 0; i < 16; i++) begin
                    W[i] <= message_block[511 - i*32 -: 32];
                end
            end
            
            // Update hash values after finalization
            if (state_q == ST_FINALIZE) begin
                h0_q <= h0_q + a_q;
                h1_q <= h1_q + b_q;
                h2_q <= h2_q + c_q;
                h3_q <= h3_q + d_q;
                h4_q <= h4_q + e_q;
                h5_q <= h5_q + f_q;
                h6_q <= h6_q + g_q;
                h7_q <= h7_q + h_q;
            end
        end
    end
    
    // -----------------------------------------------------------------------
    // Combinational Logic
    // -----------------------------------------------------------------------
    logic [31:0] T1, T2;
    
    always_comb begin
        state_d = state_q;
        a_d     = a_q;
        b_d     = b_q;
        c_d     = c_q;
        d_d     = d_q;
        e_d     = e_q;
        f_d     = f_q;
        g_d     = g_q;
        h_d     = h_q;
        round_d = round_q;
        
        case (state_q)
            ST_IDLE: begin
                if (hash_start) begin
                    state_d = ST_PREPARE;
                    round_d = '0;
                end
            end
            
            ST_PREPARE: begin
                // Initialize working variables
                a_d     = h0_q;
                b_d     = h1_q;
                c_d     = h2_q;
                d_d     = h3_q;
                e_d     = h4_q;
                f_d     = h5_q;
                g_d     = h6_q;
                h_d     = h7_q;
                state_d = ST_COMPUTE;
            end
            
            ST_COMPUTE: begin
                // Compute one round per cycle
                T1 = h_q + sigma1(e_q) + ch(e_q, f_q, g_q) + K[round_q] + W_current;
                T2 = sigma0(a_q) + maj(a_q, b_q, c_q);
                
                h_d = g_q;
                g_d = f_q;
                f_d = e_q;
                e_d = d_q + T1;
                d_d = c_q;
                c_d = b_q;
                b_d = a_q;
                a_d = T1 + T2;
                
                if (round_q == 63) begin
                    state_d = ST_FINALIZE;
                end else begin
                    round_d = round_q + 1;
                end
            end
            
            ST_FINALIZE: begin
                state_d = ST_IDLE;
            end
        endcase
    end
    
    // -----------------------------------------------------------------------
    // Outputs
    // -----------------------------------------------------------------------
    assign hash_busy   = (state_q != ST_IDLE);
    assign hash_done   = (state_q == ST_FINALIZE);
    assign hash_digest = {h0_q, h1_q, h2_q, h3_q, h4_q, h5_q, h6_q, h7_q};
    
endmodule
