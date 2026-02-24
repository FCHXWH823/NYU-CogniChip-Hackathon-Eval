// SHA-256 Core Module
// Implements SHA-256 hash algorithm with iterative architecture
// 64 rounds @ 1 round per cycle for area efficiency

module sha256_core (
    input  logic        clock,
    input  logic        reset,
    
    // Control interface
    input  logic        start,          // Start processing block
    input  logic        init,           // Initialize hash (first block)
    output logic        ready,          // Ready for new block
    output logic        valid,          // Hash output valid
    
    // Data interface
    input  logic [511:0] message_block, // 512-bit input block
    output logic [255:0] hash_out       // 256-bit hash output
);

    // SHA-256 Constants (K values)
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

    // SHA-256 Initial Hash Values (H0)
    localparam logic [31:0] H0_INIT[0:7] = '{
        32'h6a09e667, 32'hbb67ae85, 32'h3c6ef372, 32'ha54ff53a,
        32'h510e527f, 32'h9b05688c, 32'h1f83d9ab, 32'h5be0cd19
    };

    // State machine
    typedef enum logic [1:0] {
        IDLE,
        LOAD,
        COMPUTE,
        DONE
    } state_t;
    
    state_t state, next_state;
    
    // Working variables
    logic [31:0] a, b, c, d, e, f, g, h;
    logic [31:0] a_next, b_next, c_next, d_next, e_next, f_next, g_next, h_next;
    
    // Hash values (intermediate and final)
    logic [31:0] H[0:7];
    logic [31:0] H_next[0:7];
    
    // Message schedule (W)
    logic [31:0] W[0:63];
    logic [31:0] W_next[0:63];
    
    // Round counter
    logic [5:0] round;
    logic [5:0] round_next;
    
    // SHA-256 Functions
    function automatic logic [31:0] rotr(logic [31:0] x, int n);
        return (x >> n) | (x << (32 - n));
    endfunction
    
    function automatic logic [31:0] ch(logic [31:0] x, y, z);
        return (x & y) ^ (~x & z);
    endfunction
    
    function automatic logic [31:0] maj(logic [31:0] x, y, z);
        return (x & y) ^ (x & z) ^ (y & z);
    endfunction
    
    function automatic logic [31:0] sigma0(logic [31:0] x);
        return rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22);
    endfunction
    
    function automatic logic [31:0] sigma1(logic [31:0] x);
        return rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25);
    endfunction
    
    function automatic logic [31:0] gamma0(logic [31:0] x);
        return rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3);
    endfunction
    
    function automatic logic [31:0] gamma1(logic [31:0] x);
        return rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10);
    endfunction
    
    // Temporary variables for compression
    logic [31:0] T1, T2;
    
    // State machine logic
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
                if (start) begin
                    next_state = LOAD;
                end
            end
            
            LOAD: begin
                next_state = COMPUTE;
            end
            
            COMPUTE: begin
                if (round == 6'd63) begin
                    next_state = DONE;
                end
            end
            
            DONE: begin
                next_state = IDLE;
            end
        endcase
    end
    
    // Round counter
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            round <= 6'd0;
        end else begin
            round <= round_next;
        end
    end
    
    always_comb begin
        if (state == COMPUTE) begin
            round_next = round + 6'd1;
        end else begin
            round_next = 6'd0;
        end
    end
    
    // Message schedule computation and storage
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            for (int i = 0; i < 64; i++) begin
                W[i] <= 32'h0;
            end
        end else begin
            for (int i = 0; i < 64; i++) begin
                W[i] <= W_next[i];
            end
        end
    end
    
    always_comb begin
        // Default: hold values
        for (int i = 0; i < 64; i++) begin
            W_next[i] = W[i];
        end
        
        if (state == LOAD) begin
            // Load first 16 words from message block (big-endian)
            for (int i = 0; i < 16; i++) begin
                W_next[i] = message_block[511 - i*32 -: 32];
            end
            // Compute remaining 48 words
            for (int i = 16; i < 64; i++) begin
                W_next[i] = gamma1(W_next[i-2]) + W_next[i-7] + gamma0(W_next[i-15]) + W_next[i-16];
            end
        end
    end
    
    // Hash value registers
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            for (int i = 0; i < 8; i++) begin
                H[i] <= H0_INIT[i];
            end
        end else begin
            for (int i = 0; i < 8; i++) begin
                H[i] <= H_next[i];
            end
        end
    end
    
    always_comb begin
        // Default: hold values
        for (int i = 0; i < 8; i++) begin
            H_next[i] = H[i];
        end
        
        if ((state == IDLE) && start && init) begin
            // Initialize hash values
            for (int i = 0; i < 8; i++) begin
                H_next[i] = H0_INIT[i];
            end
        end else if (state == DONE) begin
            // Add compressed chunk to hash values
            H_next[0] = H[0] + a;
            H_next[1] = H[1] + b;
            H_next[2] = H[2] + c;
            H_next[3] = H[3] + d;
            H_next[4] = H[4] + e;
            H_next[5] = H[5] + f;
            H_next[6] = H[6] + g;
            H_next[7] = H[7] + h;
        end
    end
    
    // Working variables
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            a <= 32'h0;
            b <= 32'h0;
            c <= 32'h0;
            d <= 32'h0;
            e <= 32'h0;
            f <= 32'h0;
            g <= 32'h0;
            h <= 32'h0;
        end else begin
            a <= a_next;
            b <= b_next;
            c <= c_next;
            d <= d_next;
            e <= e_next;
            f <= f_next;
            g <= g_next;
            h <= h_next;
        end
    end
    
    // Compression function
    always_comb begin
        // Compute T1 and T2
        T1 = h + sigma1(e) + ch(e, f, g) + K[round] + W[round];
        T2 = sigma0(a) + maj(a, b, c);
        
        // Default: hold values
        a_next = a;
        b_next = b;
        c_next = c;
        d_next = d;
        e_next = e;
        f_next = f;
        g_next = g;
        h_next = h;
        
        if (state == LOAD) begin
            // Initialize working variables from hash values
            a_next = H[0];
            b_next = H[1];
            c_next = H[2];
            d_next = H[3];
            e_next = H[4];
            f_next = H[5];
            g_next = H[6];
            h_next = H[7];
        end else if (state == COMPUTE) begin
            // Perform round computation
            h_next = g;
            g_next = f;
            f_next = e;
            e_next = d + T1;
            d_next = c;
            c_next = b;
            b_next = a;
            a_next = T1 + T2;
        end
    end
    
    // Output logic
    always_comb begin
        ready = (state == IDLE);
        valid = (state == DONE);
        hash_out = {H[0], H[1], H[2], H[3], H[4], H[5], H[6], H[7]};
    end

endmodule
