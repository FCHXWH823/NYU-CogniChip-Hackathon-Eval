// ===========================================================================
// TeenyTinyTrustyCore (3TC) - Device ID Storage
// ===========================================================================
// Stores an immutable Device Identifier that provides a unique,
// non-secret identity for the device. Unlike the DUS, the Device ID
// is READABLE externally for identification and attestation purposes.
//
// Security Properties:
// - Device ID is immutable after reset (set once, never changes)
// - ID is derived from a constant or fuse input at reset
// - ID is always readable (public identity, not secret)
// - ID must remain stable across all operations (no glitches)
//
// CWE Mapping:
// - CWE-1272: Immutable attributes must not change after initialization
// ===========================================================================

module ttc3_device_id #(
    parameter int ID_WIDTH = 128,  // 128-bit Device ID
    // Default ID value (can be overridden by fuse input if available)
    parameter logic [ID_WIDTH-1:0] DEFAULT_ID = 128'hDEADBEEF_CAFEBABE_01234567_89ABCDEF
) (
    input  logic                clock,
    input  logic                reset,
    
    // Fuse/OTP input (optional, for production devices)
    input  logic                fuse_valid,
    input  logic [ID_WIDTH-1:0] fuse_id,
    
    // Device ID output (always readable)
    output logic [ID_WIDTH-1:0] device_id,
    output logic                id_valid
);

    // -----------------------------------------------------------------------
    // Immutable ID Register
    // -----------------------------------------------------------------------
    logic [ID_WIDTH-1:0] id_q;
    logic                id_locked;
    
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            // At reset, load ID from fuse if available, else use default
            if (fuse_valid) begin
                id_q <= fuse_id;
            end else begin
                id_q <= DEFAULT_ID;
            end
            id_locked <= 1'b1;  // Lock immediately after reset
        end else begin
            // After reset, ID is IMMUTABLE (no writes allowed)
            // id_q retains its value indefinitely
        end
    end
    
    // -----------------------------------------------------------------------
    // Outputs
    // -----------------------------------------------------------------------
    assign device_id = id_q;
    assign id_valid  = id_locked;
    
    // -----------------------------------------------------------------------
    // Security Assertion: ID immutability after reset
    // -----------------------------------------------------------------------
    // Property: Once set after reset, Device ID must never change
    // CWE-1272: Sensitive Information Uncleared Before Debug/Power State Transition
    `ifdef FORMAL
    property id_immutable;
        @(posedge clock) disable iff (reset)
        id_locked |=> (id_q == $past(id_q));
    endproperty
    assert property (id_immutable)
        else $error("Device ID immutability violated: ID changed after lock");
    `endif
    
    // -----------------------------------------------------------------------
    // Security Assertion: ID always valid after reset
    // -----------------------------------------------------------------------
    `ifdef FORMAL
    property id_always_valid;
        @(posedge clock) disable iff (reset)
        id_locked |-> id_valid;
    endproperty
    assert property (id_always_valid)
        else $error("Device ID validity flag inconsistent");
    `endif
    
endmodule
