// ===========================================================================
// TeenyTinyTrustyCore (3TC) - Top Level Integration
// ===========================================================================
// Hardware Root of Trust for TinyTapeout-scale designs.
// Integrates DUS storage, Device ID, KDF, and crypto engines.
//
// Security Architecture:
// - DUS never exposed externally (stays within DUS storage module)
// - All keys derived on-demand and zeroized after use
// - Device ID immutable and always readable
// - Command interface for crypto operations
//
// Command Interface (simplified):
//   cmd_op[2:0]:
//     000 = NOP
//     001 = Get Device ID
//     010 = SHA-256 hash
//     011 = HMAC-SHA256
//     100 = AES-CTR encrypt/decrypt
//     101 = Derive key (internal test)
//
// ===========================================================================

module ttc3_top #(
    parameter int DUS_WIDTH     = 256,
    parameter int DEVICE_ID_WIDTH = 128,
    parameter int KEY_WIDTH     = 256
) (
    input  logic         clock,
    input  logic         reset,
    
    // DUS initialization (one-time, from secure boot/fuse)
    input  logic                    dus_write_enable,
    input  logic [DUS_WIDTH-1:0]    dus_write_data,
    
    // Device ID initialization (from fuse if available)
    input  logic                        device_id_fuse_valid,
    input  logic [DEVICE_ID_WIDTH-1:0]  device_id_fuse_data,
    
    // Command interface
    input  logic        cmd_valid,
    input  logic [2:0]  cmd_op,
    input  logic [511:0] cmd_data,      // Multi-purpose data input
    output logic        cmd_ready,
    output logic        cmd_done,
    
    // Response interface
    output logic [511:0] resp_data,
    output logic         resp_valid
);

    // -----------------------------------------------------------------------
    // Command Opcodes
    // -----------------------------------------------------------------------
    localparam logic [2:0] OP_NOP        = 3'b000;
    localparam logic [2:0] OP_GET_ID     = 3'b001;
    localparam logic [2:0] OP_SHA256     = 3'b010;
    localparam logic [2:0] OP_HMAC       = 3'b011;
    localparam logic [2:0] OP_AES_CTR    = 3'b100;
    localparam logic [2:0] OP_DERIVE_KEY = 3'b101;
    
    // -----------------------------------------------------------------------
    // Internal Signals
    // -----------------------------------------------------------------------
    logic                    dus_valid;
    logic                    kdf_request;
    logic [DUS_WIDTH-1:0]    kdf_dus;
    logic [DEVICE_ID_WIDTH-1:0] device_id;
    logic                    device_id_valid;
    
    // KDF signals
    logic                 kdf_start;
    logic [63:0]          kdf_info;
    logic                 kdf_done;
    logic                 kdf_busy;
    logic [KEY_WIDTH-1:0] derived_key;
    
    // SHA-256 signals
    logic         sha_start;
    logic [511:0] sha_block;
    logic         sha_done;
    logic         sha_busy;
    logic [255:0] sha_digest;
    
    // HMAC signals
    logic         hmac_start;
    logic [255:0] hmac_key;
    logic [255:0] hmac_message;
    logic         hmac_done;
    logic         hmac_busy;
    logic [255:0] hmac_tag;
    
    // AES signals
    logic         aes_start;
    logic         aes_decrypt;
    logic [127:0] aes_key;
    logic [127:0] aes_plaintext;
    logic [127:0] aes_counter;
    logic         aes_done;
    logic         aes_busy;
    logic [127:0] aes_ciphertext;
    
    // -----------------------------------------------------------------------
    // Module Instantiations
    // -----------------------------------------------------------------------
    
    // DUS Storage (security-critical: DUS never leaves this module)
    ttc3_dus_storage #(
        .DUS_WIDTH (DUS_WIDTH)
    ) u_dus_storage (
        .clock        (clock),
        .reset        (reset),
        .write_enable (dus_write_enable),
        .write_data   (dus_write_data),
        .dus_valid    (dus_valid),
        .kdf_request  (kdf_request),
        .kdf_dus      (kdf_dus)
    );
    
    // Device ID Storage (immutable, publicly readable)
    ttc3_device_id #(
        .ID_WIDTH (DEVICE_ID_WIDTH)
    ) u_device_id (
        .clock       (clock),
        .reset       (reset),
        .fuse_valid  (device_id_fuse_valid),
        .fuse_id     (device_id_fuse_data),
        .device_id   (device_id),
        .id_valid    (device_id_valid)
    );
    
    // Key Derivation Function
    ttc3_kdf #(
        .DUS_WIDTH     (DUS_WIDTH),
        .KEY_WIDTH     (KEY_WIDTH),
        .INFO_WIDTH    (64)
    ) u_kdf (
        .clock       (clock),
        .reset       (reset),
        .dus_request (kdf_request),
        .dus_secret  (kdf_dus),
        .kdf_start   (kdf_start),
        .kdf_info    (kdf_info),
        .kdf_done    (kdf_done),
        .kdf_busy    (kdf_busy),
        .derived_key (derived_key)
    );
    
    // SHA-256 Core
    ttc3_sha256 u_sha256 (
        .clock         (clock),
        .reset         (reset),
        .hash_start    (sha_start),
        .message_block (sha_block),
        .hash_done     (sha_done),
        .hash_busy     (sha_busy),
        .hash_digest   (sha_digest)
    );
    
    // HMAC Engine
    ttc3_hmac u_hmac (
        .clock         (clock),
        .reset         (reset),
        .hmac_start    (hmac_start),
        .hmac_key      (hmac_key),
        .hmac_message  (hmac_message),
        .hmac_done     (hmac_done),
        .hmac_busy     (hmac_busy),
        .hmac_tag      (hmac_tag)
    );
    
    // AES-CTR Engine
    ttc3_aes_ctr u_aes_ctr (
        .clock          (clock),
        .reset          (reset),
        .aes_start      (aes_start),
        .aes_decrypt    (aes_decrypt),
        .aes_key        (aes_key),
        .aes_plaintext  (aes_plaintext),
        .aes_counter    (aes_counter),
        .aes_done       (aes_done),
        .aes_busy       (aes_busy),
        .aes_ciphertext (aes_ciphertext)
    );
    
    // -----------------------------------------------------------------------
    // Command Processor State Machine
    // -----------------------------------------------------------------------
    typedef enum logic [2:0] {
        ST_READY        = 3'b000,
        ST_DERIVE_KEY   = 3'b001,
        ST_EXECUTE      = 3'b010,
        ST_WAIT         = 3'b011,
        ST_RESPOND      = 3'b100
    } cmd_state_e;
    
    cmd_state_e state_q, state_d;
    logic [2:0] op_q;
    
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            state_q <= ST_READY;
            op_q    <= OP_NOP;
        end else begin
            state_q <= state_d;
            if (cmd_valid && state_q == ST_READY) begin
                op_q <= cmd_op;
            end
        end
    end
    
    always_comb begin
        state_d     = state_q;
        cmd_ready   = 1'b0;
        cmd_done    = 1'b0;
        resp_valid  = 1'b0;
        resp_data   = '0;
        
        // Crypto engine controls (default: inactive)
        kdf_start   = 1'b0;
        kdf_info    = '0;
        sha_start   = 1'b0;
        sha_block   = '0;
        hmac_start  = 1'b0;
        hmac_key    = '0;
        hmac_message = '0;
        aes_start   = 1'b0;
        aes_decrypt = 1'b0;
        aes_key     = '0;
        aes_plaintext = '0;
        aes_counter = '0;
        
        case (state_q)
            ST_READY: begin
                cmd_ready = 1'b1;
                if (cmd_valid) begin
                    case (cmd_op)
                        OP_GET_ID: begin
                            // Return Device ID immediately (no crypto needed)
                            state_d = ST_RESPOND;
                        end
                        
                        OP_SHA256: begin
                            state_d = ST_EXECUTE;
                        end
                        
                        OP_HMAC: begin
                            // Derive HMAC key from DUS first
                            state_d = ST_DERIVE_KEY;
                        end
                        
                        OP_AES_CTR: begin
                            // Derive AES key from DUS first
                            state_d = ST_DERIVE_KEY;
                        end
                        
                        OP_DERIVE_KEY: begin
                            // Test operation: derive key
                            state_d = ST_DERIVE_KEY;
                        end
                        
                        default: begin
                            // NOP or unknown: stay ready
                            state_d = ST_READY;
                        end
                    endcase
                end
            end
            
            ST_DERIVE_KEY: begin
                if (!kdf_busy) begin
                    kdf_start = 1'b1;
                    // Use operation type as derivation context
                    kdf_info  = {56'd0, 5'd0, op_q};
                    state_d   = ST_WAIT;
                end
            end
            
            ST_EXECUTE: begin
                case (op_q)
                    OP_SHA256: begin
                        if (!sha_busy) begin
                            sha_start = 1'b1;
                            sha_block = cmd_data;
                            state_d   = ST_WAIT;
                        end
                    end
                    
                    OP_HMAC: begin
                        if (kdf_done && !hmac_busy) begin
                            hmac_start   = 1'b1;
                            hmac_key     = derived_key;
                            hmac_message = cmd_data[255:0];
                            state_d      = ST_WAIT;
                        end else if (kdf_done) begin
                            state_d = ST_EXECUTE;
                        end
                    end
                    
                    OP_AES_CTR: begin
                        if (kdf_done && !aes_busy) begin
                            aes_start     = 1'b1;
                            aes_key       = derived_key[127:0];
                            aes_plaintext = cmd_data[255:128];
                            aes_counter   = cmd_data[127:0];
                            state_d       = ST_WAIT;
                        end else if (kdf_done) begin
                            state_d = ST_EXECUTE;
                        end
                    end
                    
                    default: begin
                        state_d = ST_READY;
                    end
                endcase
            end
            
            ST_WAIT: begin
                // Wait for crypto operation to complete
                if (kdf_done && (op_q == OP_HMAC || op_q == OP_AES_CTR)) begin
                    state_d = ST_EXECUTE;
                end else if (sha_done || hmac_done || aes_done || kdf_done) begin
                    state_d = ST_RESPOND;
                end
            end
            
            ST_RESPOND: begin
                resp_valid = 1'b1;
                cmd_done   = 1'b1;
                
                case (op_q)
                    OP_GET_ID: begin
                        resp_data = {{(512-DEVICE_ID_WIDTH){1'b0}}, device_id};
                    end
                    
                    OP_SHA256: begin
                        resp_data = {256'd0, sha_digest};
                    end
                    
                    OP_HMAC: begin
                        resp_data = {256'd0, hmac_tag};
                    end
                    
                    OP_AES_CTR: begin
                        resp_data = {384'd0, aes_ciphertext};
                    end
                    
                    OP_DERIVE_KEY: begin
                        // For testing only: return derived key
                        // In production, derived keys should NEVER be externally visible
                        resp_data = {256'd0, derived_key};
                    end
                    
                    default: begin
                        resp_data = '0;
                    end
                endcase
                
                state_d = ST_READY;
            end
            
            default: begin
                state_d = ST_READY;
            end
        endcase
    end
    
endmodule
