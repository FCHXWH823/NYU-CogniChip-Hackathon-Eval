//=========================================================================
// TeenyTinyTrustyCore (3TC) - Key Derivation Function (KDF)
// ===========================================================================
// Derives application-specific keys from the Device Unique Secret (DUS).
// Uses a simple HMAC-SHA-256 based approach (simplified HKDF-like).
//
// Operation:
//   derived_key = HMAC-SHA256(DUS, info || counter)
//
// Security Properties:
// - Derived keys are ephemeral (zeroized after use)
// - Each derivation uses a unique info to ensure key separation
// - Keys are auto-zeroized on reset
// - No path from DUS to derived key outputs without explicit derivation
//
// Interface:
// - kdf_start: Begin key derivation
// - kdf_info: Application/purpose identifier (e.g., "AES-KEY", "HMAC-KEY")
// - kdf_done: Derivation complete, derived_key valid for ONE cycle
// - derived_key: Output key (valid only when kdf_done=1, auto-zeroized after)
// ===========================================================================

module ttc3_kdf #(
    parameter int DUS_WIDTH     = 256,
    parameter int KEY_WIDTH     = 256,
    parameter int INFO_WIDTH    = 64
) (
    input  logic                   clock,
    input  logic                   reset,
    
    // DUS access (internal, from DUS storage module)
    output logic                   dus_request,
    input  logic [DUS_WIDTH-1:0]   dus_secret,
    
    // Control interface
    input  logic                   kdf_start,
    input  logic [INFO_WIDTH-1:0]  kdf_info,
    output logic                   kdf_done,
    output logic                   kdf_busy,
    
    // Derived key output (ephemeral, valid only when kdf_done=1)
    output logic [KEY_WIDTH-1:0]   derived_key
);

    // -----------------------------------------------------------------------
    // State Machine
    // -----------------------------------------------------------------------
    typedef enum logic [1:0] {
        ST_IDLE      = 2'b00,
        ST_REQUEST   = 2'b01,
        ST_DERIVE    = 2'b10,
        ST_ZEROIZE   = 2'b11
    } kdf_state_e;
    
    kdf_state_e state_q, state_d;
    
    // -----------------------------------------------------------------------
    // Derivation Logic (Simplified HMAC-based)
    // -----------------------------------------------------------------------
    // For area efficiency, we use a simple mixing function instead of
    // full HMAC-SHA256 (which would require SHA-256 core instantiation).
    // In a real implementation, integrate with HMAC engine.
    //
    // Here: derived_key = hash_function(DUS ^ info)
    // This is a placeholder; replace with actual HMAC-SHA256 in production.
    // -----------------------------------------------------------------------
    logic [KEY_WIDTH-1:0] key_q;
    logic [KEY_WIDTH-1:0] key_d;
    logic [3:0]           cycle_count_q;
    logic [3:0]           cycle_count_d;
    logic [KEY_WIDTH-1:0] extended_info;
    
    // Extend info to KEY_WIDTH
    always_comb begin
        extended_info = {{(KEY_WIDTH-INFO_WIDTH){1'b0}}, kdf_info};
    end
    
    // -----------------------------------------------------------------------
    // State Machine: Sequential Logic
    // -----------------------------------------------------------------------
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            state_q       <= ST_IDLE;
            key_q         <= '0;
            cycle_count_q <= '0;
        end else begin
            state_q       <= state_d;
            key_q         <= key_d;
            cycle_count_q <= cycle_count_d;
        end
    end
    
    // -----------------------------------------------------------------------
    // State Machine: Combinational Logic
    // -----------------------------------------------------------------------
    always_comb begin
        // Default assignments
        state_d       = state_q;
        key_d         = key_q;
        cycle_count_d = cycle_count_q;
        dus_request   = 1'b0;
        
        case (state_q)
            ST_IDLE: begin
                key_d         = '0;
                cycle_count_d = '0;
                if (kdf_start) begin
                    state_d = ST_REQUEST;
                end
            end
            
            ST_REQUEST: begin
                dus_request = 1'b1;
                state_d     = ST_DERIVE;
            end
            
            ST_DERIVE: begin
                // Simple mixing operation (placeholder for HMAC)
                // Real implementation: invoke HMAC-SHA256 engine
                if (cycle_count_q < 4'd8) begin
                    // Mix DUS with info over multiple cycles
                    key_d = {key_q[254:0], key_q[255]} + (dus_secret ^ extended_info);
                    cycle_count_d = cycle_count_q + 1;
                end else if (cycle_count_q == 4'd8) begin
                    // Hold key for one cycle so monitor can capture it
                    cycle_count_d = cycle_count_q + 1;
                end else begin
                    // cycle_count_q == 9, now zeroize
                    state_d = ST_ZEROIZE;
                end
            end
            
            ST_ZEROIZE: begin
                // Mandatory zeroization of derived key
                key_d   = '0;
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
    assign kdf_busy    = (state_q != ST_IDLE);
    assign kdf_done    = (state_q == ST_DERIVE && cycle_count_q == 4'd8);
    assign derived_key = (state_q == ST_DERIVE && cycle_count_q == 4'd8) ? key_q : '0;
    
    // -----------------------------------------------------------------------
    // Security Assertion: Key zeroization after use
    // -----------------------------------------------------------------------
    `ifdef FORMAL
    property key_zeroization;
        @(posedge clock) disable iff (reset)
        (state_q == ST_ZEROIZE) |=> (key_q == '0);
    endproperty
    assert property (key_zeroization)
        else $error("KDF: Derived key not zeroized after use");
    `endif
    
endmodule
