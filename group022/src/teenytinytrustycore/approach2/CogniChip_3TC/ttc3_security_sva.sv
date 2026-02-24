// ===========================================================================
// TeenyTinyTrustyCore (3TC) - Security SystemVerilog Assertions (SVA)
// ===========================================================================
// Comprehensive security properties for formal verification and runtime
// checking. Each property is mapped to relevant Common Weakness Enumerations
// (CWE) for traceability to security standards.
//
// Usage:
//   bind ttc3_top ttc3_security_sva #(...) u_security_sva (.*);
//
// Verification:
//   - Formal tools: JasperGold, VC Formal, OneSpin
//   - Simulation: Enable with +define+ASSERTIONS
// ===========================================================================

module ttc3_security_sva #(
    parameter int DUS_WIDTH = 256,
    parameter int DEVICE_ID_WIDTH = 128,
    parameter int KEY_WIDTH = 256
) (
    input logic clock,
    input logic reset,
    
    // DUS storage interface
    input logic                  dus_write_enable,
    input logic [DUS_WIDTH-1:0]  dus_write_data,
    input logic                  dus_valid,
    
    // Device ID interface
    input logic [DEVICE_ID_WIDTH-1:0] device_id,
    input logic                       device_id_valid,
    
    // KDF interface
    input logic                  kdf_request,
    input logic [DUS_WIDTH-1:0]  kdf_dus,
    input logic [KEY_WIDTH-1:0]  derived_key,
    input logic                  kdf_done,
    input logic                  kdf_busy,
    
    // Command interface
    input logic        cmd_valid,
    input logic [2:0]  cmd_op,
    input logic        cmd_done,
    
    // Response interface
    input logic [511:0] resp_data,
    input logic         resp_valid
);

    // =========================================================================
    // CATEGORY 1: DUS ISOLATION PROPERTIES
    // =========================================================================
    // Ensures the Device Unique Secret never escapes the security boundary
    
    // -------------------------------------------------------------------------
    // Property 1.1: DUS Never in Response Data
    // CWE-200: Exposure of Sensitive Information to an Unauthorized Actor
    // Justification: DUS must never be directly observable in any output
    // -------------------------------------------------------------------------
    property dus_not_in_response;
        @(posedge clock) disable iff (reset)
        resp_valid |-> (resp_data != {{(512-DUS_WIDTH){1'b0}}, kdf_dus});
    endproperty
    
    assert property (dus_not_in_response)
        else $error("[CWE-200] DUS leaked in response data");
    
    // -------------------------------------------------------------------------
    // Property 1.2: DUS Only Accessible via KDF Request
    // CWE-552: Files or Directories Accessible to External Parties
    // Justification: DUS should only be accessible through controlled KDF path
    // -------------------------------------------------------------------------
    property dus_gated_access;
        @(posedge clock) disable iff (reset)
        (kdf_dus != '0) |-> kdf_request;
    endproperty
    
    assert property (dus_gated_access)
        else $error("[CWE-552] DUS accessed without proper request gating");
    
    // -------------------------------------------------------------------------
    // Property 1.3: DUS Write-Once Semantics
    // CWE-667: Improper Locking
    // Justification: DUS should be written once and locked to prevent tampering
    // -------------------------------------------------------------------------
    property dus_write_once;
        @(posedge clock) disable iff (reset)
        $rose(dus_valid) |-> ##[1:$] !dus_write_enable;
    endproperty
    
    assert property (dus_write_once)
        else $error("[CWE-667] DUS write attempted after lock");
    
    // =========================================================================
    // CATEGORY 2: KEY ZEROIZATION PROPERTIES
    // =========================================================================
    // Ensures derived keys are cleared after use
    
    // -------------------------------------------------------------------------
    // Property 2.1: Derived Key Cleared After KDF Operation
    // CWE-226: Sensitive Information Uncleared Before Release
    // Justification: Cryptographic keys must be zeroized when no longer needed
    // -------------------------------------------------------------------------
    property derived_key_zeroized;
        @(posedge clock) disable iff (reset)
        (kdf_done ##1 !kdf_busy) |-> ##[1:5] (derived_key == '0);
    endproperty
    
    assert property (derived_key_zeroized)
        else $error("[CWE-226] Derived key not zeroized after use");
    
    // -------------------------------------------------------------------------
    // Property 2.2: Derived Key Only Valid During Active Operation
    // CWE-324: Use of a Key Past its Expiration Date
    // Justification: Keys should only exist during active cryptographic operations
    // -------------------------------------------------------------------------
    property key_ephemeral;
        @(posedge clock) disable iff (reset)
        (derived_key != '0) |-> kdf_busy || kdf_done;
    endproperty
    
    assert property (key_ephemeral)
        else $error("[CWE-324] Derived key persists outside operational window");
    
    // -------------------------------------------------------------------------
    // Property 2.3: Keys Cleared on Reset
    // CWE-1272: Sensitive Information Uncleared Before Debug/Power State Transition
    // Justification: All keys must be cleared during reset to prevent persistence
    // -------------------------------------------------------------------------
    property keys_cleared_on_reset;
        @(posedge clock)
        $rose(reset) |=> (derived_key == '0);
    endproperty
    
    assert property (keys_cleared_on_reset)
        else $error("[CWE-1272] Keys not cleared on reset");
    
    // =========================================================================
    // CATEGORY 3: DEVICE ID IMMUTABILITY PROPERTIES
    // =========================================================================
    // Ensures Device ID remains constant after initialization
    
    // -------------------------------------------------------------------------
    // Property 3.1: Device ID Immutable After Reset
    // CWE-471: Modification of Assumed-Immutable Data
    // Justification: Device ID must never change after initial programming
    // -------------------------------------------------------------------------
    property device_id_immutable;
        @(posedge clock) disable iff (reset)
        device_id_valid |=> (device_id == $past(device_id));
    endproperty
    
    assert property (device_id_immutable)
        else $error("[CWE-471] Device ID modified after initialization");
    
    // -------------------------------------------------------------------------
    // Property 3.2: Device ID Valid After Reset Release
    // CWE-909: Missing Initialization of Resource
    // Justification: Device ID must be properly initialized before use
    // -------------------------------------------------------------------------
    property device_id_initialized;
        @(posedge clock)
        $fell(reset) |-> ##[0:2] device_id_valid;
    endproperty
    
    assert property (device_id_initialized)
        else $error("[CWE-909] Device ID not initialized after reset");
    
    // -------------------------------------------------------------------------
    // Property 3.3: Device ID Never Zero
    // CWE-1291: Public Key Re-Use for Signing both Debug and Production Code
    // Justification: Zero ID would indicate uninitialized or default state
    // -------------------------------------------------------------------------
    property device_id_nonzero;
        @(posedge clock) disable iff (reset)
        device_id_valid |-> (device_id != '0);
    endproperty
    
    assert property (device_id_nonzero)
        else $error("[CWE-1291] Device ID is zero (invalid/default state)");
    
    // =========================================================================
    // CATEGORY 4: OPERATIONAL SECURITY PROPERTIES
    // =========================================================================
    // Ensures secure operational behavior
    
    // -------------------------------------------------------------------------
    // Property 4.1: No Operation Without Valid DUS
    // CWE-311: Missing Encryption of Sensitive Data
    // Justification: Crypto operations should not proceed without root secret
    // -------------------------------------------------------------------------
    property operations_require_dus;
        @(posedge clock) disable iff (reset)
        (cmd_valid && cmd_op != 3'b000 && cmd_op != 3'b001) |-> dus_valid;
    endproperty
    
    assert property (operations_require_dus)
        else $error("[CWE-311] Crypto operation attempted without valid DUS");
    
    // -------------------------------------------------------------------------
    // Property 4.2: Response Only After Command Completion
    // CWE-362: Concurrent Execution using Shared Resource with Improper Sync
    // Justification: Responses must be properly synchronized with commands
    // -------------------------------------------------------------------------
    property response_after_command;
        @(posedge clock) disable iff (reset)
        resp_valid |-> $past(cmd_valid, 1) ##0 cmd_done;
    endproperty
    
    assert property (response_after_command)
        else $error("[CWE-362] Response issued without proper command synchronization");
    
    // -------------------------------------------------------------------------
    // Property 4.3: Command Not Accepted During Busy
    // CWE-841: Improper Enforcement of Behavioral Workflow
    // Justification: New commands should not be accepted while processing
    // -------------------------------------------------------------------------
    property no_command_overlap;
        @(posedge clock) disable iff (reset)
        (cmd_valid && !cmd_done) |=> !cmd_valid until cmd_done;
    endproperty
    
    assert property (no_command_overlap)
        else $error("[CWE-841] Command overlap detected (workflow violation)");
    
    // =========================================================================
    // CATEGORY 5: SIDE-CHANNEL RESISTANCE PROPERTIES (Coverage Goals)
    // =========================================================================
    // These properties check for common side-channel vulnerabilities
    
    // -------------------------------------------------------------------------
    // Property 5.1: Constant-Time Key Operations (Coverage)
    // CWE-208: Observable Timing Discrepancy
    // Justification: Crypto operations should take constant time regardless of key
    // NOTE: This is a coverage goal; full constant-time requires deeper analysis
    // -------------------------------------------------------------------------
    cover property (
        @(posedge clock) disable iff (reset)
        kdf_request ##[1:$] kdf_done
    );
    
    // -------------------------------------------------------------------------
    // Property 5.2: No Key-Dependent Branching (Coverage)
    // CWE-1300: Improper Protection of Physical Side Channels
    // Justification: Control flow should not depend on secret values
    // NOTE: Requires manual review and formal methods for complete verification
    // -------------------------------------------------------------------------
    cover property (
        @(posedge clock) disable iff (reset)
        kdf_busy throughout (derived_key != '0) [*1:$]
    );
    
    // =========================================================================
    // CATEGORY 6: FAULT INJECTION RESISTANCE (Coverage Goals)
    // =========================================================================
    
    // -------------------------------------------------------------------------
    // Property 6.1: Reset Effectiveness
    // CWE-1247: Improper Protection Against Voltage and Clock Glitches
    // Justification: Reset must reliably clear all sensitive state
    // -------------------------------------------------------------------------
    property reset_clears_sensitive_state;
        @(posedge clock)
        reset |-> (derived_key == '0) && (kdf_dus == '0);
    endproperty
    
    assert property (reset_clears_sensitive_state)
        else $error("[CWE-1247] Reset failed to clear sensitive state");
    
    // -------------------------------------------------------------------------
    // Property 6.2: State Machine Deadlock Freedom (Liveness)
    // CWE-833: Deadlock
    // Justification: System should not enter unrecoverable states
    // -------------------------------------------------------------------------
    property no_permanent_busy;
        @(posedge clock) disable iff (reset)
        kdf_busy |-> ##[1:1000] !kdf_busy;
    endproperty
    
    assert property (no_permanent_busy)
        else $error("[CWE-833] KDF entered deadlock state");
    
    // =========================================================================
    // SUMMARY OF CWE MAPPINGS
    // =========================================================================
    // CWE-200:  Exposure of Sensitive Information
    // CWE-226:  Sensitive Information Uncleared Before Release
    // CWE-311:  Missing Encryption of Sensitive Data
    // CWE-324:  Use of a Key Past its Expiration Date
    // CWE-362:  Concurrent Execution using Shared Resource
    // CWE-471:  Modification of Assumed-Immutable Data
    // CWE-552:  Files or Directories Accessible to External Parties
    // CWE-667:  Improper Locking
    // CWE-833:  Deadlock
    // CWE-841:  Improper Enforcement of Behavioral Workflow
    // CWE-909:  Missing Initialization of Resource
    // CWE-1247: Improper Protection Against Voltage and Clock Glitches
    // CWE-1272: Sensitive Information Uncleared Before Debug/Power Transition
    // CWE-1291: Public Key Re-Use for Signing both Debug and Production Code
    // CWE-1300: Improper Protection of Physical Side Channels
    // =========================================================================
    
endmodule
