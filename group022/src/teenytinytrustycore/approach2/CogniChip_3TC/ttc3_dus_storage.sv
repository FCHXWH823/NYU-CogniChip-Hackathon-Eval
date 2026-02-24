// ===========================================================================
// TeenyTinyTrustyCore (3TC) - Device Unique Secret (DUS) Storage
// ===========================================================================
// Security-critical module: stores the root secret that must NEVER be
// observable outside this module. Write-once semantics with no external
// read path.
//
// Security Properties:
// - DUS is loaded once at initialization (write-once)
// - NO read port to external logic (outputs only go to internal KDF)
// - DUS is cleared on reset
// - Physical isolation: dus_secret signal never leaves this module boundary
//
// Interface:
// - write_enable: One-time write strobe (typically from secure boot/fuse 256-bit secret input (e.g., from eFuse, OTP)
// - dus_valid: Indicates DUS has been successfully written
// - kdf_request: Internal KDF requests access to DUS
// - kdf_dus: DUS output ONLY to internal KDF (never to top-level ports)
// ===========================================================================

module ttc3_dus_storage #(
    parameter int DUS_WIDTH = 256  // 256-bit Device Unique Secret
) (
    input  logic                 clock,
    input  logic                 reset,
    
    // Write interface (one-time initialization)
    input  logic                 write_enable,
    input  logic [DUS_WIDTH-1:0] write_data,
    
    // Status
    output logic                 dus_valid,
    
    // Internal KDF access (NEVER exposed to top-level)
    input  logic                 kdf_request,
    output logic [DUS_WIDTH-1:0] kdf_dus
);

    // -----------------------------------------------------------------------
    // Storage: Write-once register for DUS
    // -----------------------------------------------------------------------
    logic [DUS_WIDTH-1:0] dus_secret;
    logic                 dus_locked;  // Write-once flag
    
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            dus_secret <= '0;  // Clear on reset (critical security property)
            dus_locked <= 1'b0;
        end else begin
            // Write-once: only accept write_enable if not already locked
            if (write_enable && !dus_locked) begin
                dus_secret <= write_data;
                dus_locked <= 1'b1;
            end
            // Once locked, dus_secret is immutable until reset
        end
    end
    
    // -----------------------------------------------------------------------
    // Output: DUS valid flag
    // -----------------------------------------------------------------------
    assign dus_valid = dus_locked;
    
    // -----------------------------------------------------------------------
    // Internal KDF Interface: Gated output
    // -----------------------------------------------------------------------
    // Only provide DUS to KDF when explicitly requested AND DUS is valid
    // This adds a minimal layer of access control
    assign kdf_dus = (kdf_request && dus_locked) ? dus_secret : '0;
    
    // -----------------------------------------------------------------------
    // Security Assertion: DUS never driven to zero after being set
    // -----------------------------------------------------------------------
    // If DUS is locked and valid, it should not spontaneously clear
    // (unless reset occurs)
    `ifdef FORMAL
    property dus_retention;
        @(posedge clock) disable iff (reset)
        (dus_locked && (dus_secret != '0)) |=> (dus_locked && (dus_secret == $past(dus_secret)));
    endproperty
    assert property (dus_retention) 
        else $error("DUS retention violated: secret changed after lock");
    `endif
    
endmodule
