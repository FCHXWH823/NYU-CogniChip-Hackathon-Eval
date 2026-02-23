// =============================================================================
// Module: config_regs
// Description: Configuration register bank for LLM memory controller
//              Provides software-accessible registers with validation
// =============================================================================

module config_regs (
    input  logic        clk,
    input  logic        rst_n,
    
    // Host Interface
    input  logic [7:0]  addr,
    input  logic [31:0] wdata,
    input  logic        wen,
    input  logic        ren,
    output logic [31:0] rdata,
    
    // Configuration Outputs to Scheduler
    output logic [15:0] matrix_m,
    output logic [15:0] matrix_n,
    output logic [15:0] matrix_k,
    output logic [12:0] tile_m,
    output logic [12:0] tile_n,
    output logic [12:0] tile_k,
    output logic [1:0]  buffering_mode,
    output logic [31:0] dram_base_a,
    output logic [31:0] dram_base_b,
    output logic [31:0] dram_base_c,
    output logic [15:0] sram_base_a_ping,
    output logic [15:0] sram_base_a_pong,
    output logic [15:0] sram_base_b_ping,
    output logic [15:0] sram_base_b_pong,
    output logic [15:0] sram_base_c,
    output logic        start,
    output logic        ctrl_reset,
    output logic        baseline_mode,
    input  logic        reconfig_trigger,
    
    // Status Inputs
    input  logic        busy,
    input  logic        done,
    input  logic        error_in,
    input  logic [31:0] perf_cycle_count,
    input  logic [31:0] perf_dram_read_beats,
    input  logic [31:0] perf_dram_write_beats,
    input  logic [15:0] perf_tile_count,
    input  logic [31:0] perf_idle_cycles,
    output logic        error_out
);

    // =========================================================================
    // Register Definitions
    // =========================================================================
    
    // Control register (0x00)
    logic        ctrl_start_reg;
    logic        ctrl_reset_reg;
    
    // Status register (0x04) - read-only, driven by inputs
    
    // Matrix dimensions (0x08, 0x0C, 0x10)
    logic [15:0] matrix_m_reg;
    logic [15:0] matrix_n_reg;
    logic [15:0] matrix_k_reg;
    
    // Tile dimensions (0x14, 0x58)
    logic [12:0] tile_m_reg;
    logic [12:0] tile_n_reg;
    logic [12:0] tile_k_reg;
    
    // Buffer mode (0x18)
    logic [1:0]  buffering_mode_reg;
    
    // Baseline mode (0x3C) - for performance comparison
    logic        baseline_mode_reg;
    
    // DRAM base addresses (0x1C, 0x20, 0x24)
    logic [31:0] dram_base_a_reg;
    logic [31:0] dram_base_b_reg;
    logic [31:0] dram_base_c_reg;
    
    // SRAM base addresses (0x28-0x38)
    logic [15:0] sram_base_a_ping_reg;
    logic [15:0] sram_base_a_pong_reg;
    logic [15:0] sram_base_b_ping_reg;
    logic [15:0] sram_base_b_pong_reg;
    logic [15:0] sram_base_c_reg;
    
    // Error register (sticky)
    logic        error_reg;

    // Dynamic reconfiguration preset table (0x60-0x9C)
    logic [31:0] preset_tiling_reg [0:3];
    logic [31:0] preset_sram_ab_reg [0:3];
    logic [31:0] preset_sram_bc_reg [0:3];
    logic [31:0] preset_sram_bp_reg [0:3];

    // Dynamic reconfiguration control/status (0xA0-0xA8)
    logic [1:0]  reconfig_preset_sel_reg;
    logic        reconfig_enable_reg;
    logic [7:0]  reconfig_count_reg;
    logic        reconfig_active_reg;
    
    // =========================================================================
    // Configuration Validation Logic
    // =========================================================================
    
    logic config_valid;
    logic start_requested;
    
    always_comb begin
        // Check all validation conditions
        config_valid = 1'b1;
        
        // Non-zero dimensions check
        if (matrix_m_reg == 16'h0 || matrix_n_reg == 16'h0 || matrix_k_reg == 16'h0) begin
            config_valid = 1'b0;
        end
        
        if (tile_m_reg == 13'h0 || tile_n_reg == 13'h0 || tile_k_reg == 13'h0) begin
            config_valid = 1'b0;
        end
        
        // Divisibility checks
        if ((matrix_m_reg % {3'h0, tile_m_reg}) != 16'h0) begin
            config_valid = 1'b0;
        end
        
        if ((matrix_n_reg % {3'h0, tile_n_reg}) != 16'h0) begin
            config_valid = 1'b0;
        end
        
        if ((matrix_k_reg % {3'h0, tile_k_reg}) != 16'h0) begin
            config_valid = 1'b0;
        end
    end
    
    // Start requested when START bit written
    assign start_requested = wen && (addr == 8'h00) && wdata[0];
    
    // =========================================================================
    // Register Write Logic
    // =========================================================================
    
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            ctrl_start_reg       <= 1'b0;
            ctrl_reset_reg       <= 1'b0;
            matrix_m_reg         <= 16'h0;
            matrix_n_reg         <= 16'h0;
            matrix_k_reg         <= 16'h0;
            tile_m_reg           <= 13'h0;
            tile_n_reg           <= 13'h0;
            tile_k_reg           <= 13'h0;
            buffering_mode_reg   <= 2'b00;
            dram_base_a_reg      <= 32'h0;
            dram_base_b_reg      <= 32'h0;
            dram_base_c_reg      <= 32'h0;
            sram_base_a_ping_reg <= 16'h0;
            sram_base_a_pong_reg <= 16'h0;
            sram_base_b_ping_reg <= 16'h0;
            sram_base_b_pong_reg <= 16'h0;
            sram_base_c_reg      <= 16'h0;
            baseline_mode_reg    <= 1'b0;
            error_reg            <= 1'b0;
            preset_tiling_reg[0] <= 32'h0;
            preset_tiling_reg[1] <= 32'h0;
            preset_tiling_reg[2] <= 32'h0;
            preset_tiling_reg[3] <= 32'h0;
            preset_sram_ab_reg[0] <= 32'h0;
            preset_sram_ab_reg[1] <= 32'h0;
            preset_sram_ab_reg[2] <= 32'h0;
            preset_sram_ab_reg[3] <= 32'h0;
            preset_sram_bc_reg[0] <= 32'h0;
            preset_sram_bc_reg[1] <= 32'h0;
            preset_sram_bc_reg[2] <= 32'h0;
            preset_sram_bc_reg[3] <= 32'h0;
            preset_sram_bp_reg[0] <= 32'h0;
            preset_sram_bp_reg[1] <= 32'h0;
            preset_sram_bp_reg[2] <= 32'h0;
            preset_sram_bp_reg[3] <= 32'h0;
            reconfig_preset_sel_reg <= 2'b00;
            reconfig_enable_reg     <= 1'b0;
            reconfig_count_reg      <= 8'h00;
            reconfig_active_reg     <= 1'b0;
        end else begin
            reconfig_active_reg <= 1'b0;

            // RESET bit is writable even when busy (to allow abort)
            // Must be processed before other logic to maintain self-clearing behavior
            if (wen && (addr == 8'h00)) begin
                ctrl_reset_reg <= wdata[1];
            end else begin
                ctrl_reset_reg <= 1'b0;  // Self-clearing
            end
            
            // Error register management (processed before START to avoid conflicts)
            // Priority: 1. ctrl_reset clears, 2. error_in sets, 3. START validation sets
            if (ctrl_reset_reg) begin
                error_reg <= 1'b0;  // Reset clears error
            end else if (error_in) begin
                error_reg <= 1'b1;  // External error sets (sticky)
            end else if (start_requested && !busy && !config_valid) begin
                error_reg <= 1'b1;  // START validation failure sets error
            end
            // Note: error_reg retains value if none of above conditions met (sticky)
            
            // START is self-clearing, only pulse if validation passes
            if (start_requested && !busy) begin
                if (config_valid) begin
                    ctrl_start_reg <= 1'b1;
                    // Don't clear error_reg here - let it be managed above
                end else begin
                    ctrl_start_reg <= 1'b0;
                    // error_reg is set in error management section above
                end
            end else begin
                ctrl_start_reg <= 1'b0;
            end
            
            // Configuration registers - only writable when not busy
            if (wen && !busy) begin
                case (addr)
                    8'h08: matrix_m_reg         <= wdata[15:0];
                    8'h0C: matrix_n_reg         <= wdata[15:0];
                    8'h10: matrix_k_reg         <= wdata[15:0];
                    8'h14: begin
                        tile_m_reg <= wdata[12:0];
                        tile_n_reg <= wdata[25:13];
                    end
                    8'h18: buffering_mode_reg   <= wdata[1:0];
                    8'h1C: dram_base_a_reg      <= wdata;
                    8'h20: dram_base_b_reg      <= wdata;
                    8'h24: dram_base_c_reg      <= wdata;
                    8'h28: sram_base_a_ping_reg <= wdata[15:0];
                    8'h2C: sram_base_a_pong_reg <= wdata[15:0];
                    8'h30: sram_base_b_ping_reg <= wdata[15:0];
                    8'h34: sram_base_b_pong_reg <= wdata[15:0];
                    8'h38: sram_base_c_reg      <= wdata[15:0];
                    8'h3C: baseline_mode_reg    <= wdata[0];
                    8'h58: begin
                        tile_k_reg <= wdata[12:0];
                        buffering_mode_reg <= wdata[14:13];
                    end
                    8'h60: preset_tiling_reg[0] <= wdata;
                    8'h64: preset_sram_ab_reg[0] <= wdata;
                    8'h68: preset_sram_bc_reg[0] <= wdata;
                    8'h6C: preset_sram_bp_reg[0] <= wdata;
                    8'h70: preset_tiling_reg[1] <= wdata;
                    8'h74: preset_sram_ab_reg[1] <= wdata;
                    8'h78: preset_sram_bc_reg[1] <= wdata;
                    8'h7C: preset_sram_bp_reg[1] <= wdata;
                    8'h80: preset_tiling_reg[2] <= wdata;
                    8'h84: preset_sram_ab_reg[2] <= wdata;
                    8'h88: preset_sram_bc_reg[2] <= wdata;
                    8'h8C: preset_sram_bp_reg[2] <= wdata;
                    8'h90: preset_tiling_reg[3] <= wdata;
                    8'h94: preset_sram_ab_reg[3] <= wdata;
                    8'h98: preset_sram_bc_reg[3] <= wdata;
                    8'h9C: preset_sram_bp_reg[3] <= wdata;
                    8'hA0: reconfig_preset_sel_reg <= wdata[1:0];
                    8'hA4: reconfig_enable_reg <= wdata[0];
                    default: ;
                endcase
            end

            // Dynamic reconfiguration trigger on GEMM completion
            if (reconfig_trigger && reconfig_enable_reg && !busy) begin
                tile_m_reg           <= preset_tiling_reg[reconfig_preset_sel_reg][12:0];
                tile_n_reg           <= preset_tiling_reg[reconfig_preset_sel_reg][25:13];
                tile_k_reg           <= preset_sram_bp_reg[reconfig_preset_sel_reg][28:16];
                buffering_mode_reg   <= preset_sram_bp_reg[reconfig_preset_sel_reg][30:29];
                sram_base_a_ping_reg <= preset_sram_ab_reg[reconfig_preset_sel_reg][15:0];
                sram_base_a_pong_reg <= preset_sram_ab_reg[reconfig_preset_sel_reg][31:16];
                sram_base_b_pong_reg <= preset_sram_bc_reg[reconfig_preset_sel_reg][15:0];
                sram_base_c_reg      <= preset_sram_bc_reg[reconfig_preset_sel_reg][31:16];
                sram_base_b_ping_reg <= preset_sram_bp_reg[reconfig_preset_sel_reg][15:0];

                reconfig_preset_sel_reg <= reconfig_preset_sel_reg + 2'b01;
                reconfig_count_reg      <= reconfig_count_reg + 8'h01;
                reconfig_active_reg     <= 1'b1;
            end
        end
    end
    
    // =========================================================================
    // Register Read Logic - Registered (1-cycle latency)
    // =========================================================================
    
    logic [7:0] raddr_latched;
    
    // Latch address on ren
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            raddr_latched <= 8'h0;
        end else if (ren) begin
            raddr_latched <= addr;
        end
    end
    
    // Registered read response (valid 1 cycle after ren)
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            rdata <= 32'h0;
        end else begin
            case (raddr_latched)
                8'h00: rdata <= {30'h0, ctrl_reset_reg, ctrl_start_reg};
                8'h04: rdata <= {28'h0, reconfig_active_reg, error_reg, done, busy};
                8'h08: rdata <= {16'h0, matrix_m_reg};
                8'h0C: rdata <= {16'h0, matrix_n_reg};
                8'h10: rdata <= {16'h0, matrix_k_reg};
                8'h14: rdata <= {6'h0, tile_n_reg, tile_m_reg};
                8'h18: rdata <= {30'h0, buffering_mode_reg};
                8'h1C: rdata <= dram_base_a_reg;
                8'h20: rdata <= dram_base_b_reg;
                8'h24: rdata <= dram_base_c_reg;
                8'h28: rdata <= {16'h0, sram_base_a_ping_reg};
                8'h2C: rdata <= {16'h0, sram_base_a_pong_reg};
                8'h30: rdata <= {16'h0, sram_base_b_ping_reg};
                8'h34: rdata <= {16'h0, sram_base_b_pong_reg};
                8'h38: rdata <= {16'h0, sram_base_c_reg};
                8'h3C: rdata <= {31'h0, baseline_mode_reg};
                8'h40: rdata <= perf_cycle_count;
                8'h44: rdata <= perf_dram_read_beats;
                8'h48: rdata <= perf_dram_write_beats;
                8'h4C: rdata <= {16'h0, perf_tile_count};
                8'h50: rdata <= perf_idle_cycles;
                8'h58: rdata <= {17'h0, buffering_mode_reg, tile_k_reg};
                8'h60: rdata <= preset_tiling_reg[0];
                8'h64: rdata <= preset_sram_ab_reg[0];
                8'h68: rdata <= preset_sram_bc_reg[0];
                8'h6C: rdata <= preset_sram_bp_reg[0];
                8'h70: rdata <= preset_tiling_reg[1];
                8'h74: rdata <= preset_sram_ab_reg[1];
                8'h78: rdata <= preset_sram_bc_reg[1];
                8'h7C: rdata <= preset_sram_bp_reg[1];
                8'h80: rdata <= preset_tiling_reg[2];
                8'h84: rdata <= preset_sram_ab_reg[2];
                8'h88: rdata <= preset_sram_bc_reg[2];
                8'h8C: rdata <= preset_sram_bp_reg[2];
                8'h90: rdata <= preset_tiling_reg[3];
                8'h94: rdata <= preset_sram_ab_reg[3];
                8'h98: rdata <= preset_sram_bc_reg[3];
                8'h9C: rdata <= preset_sram_bp_reg[3];
                8'hA0: rdata <= {30'h0, reconfig_preset_sel_reg};
                8'hA4: rdata <= {31'h0, reconfig_enable_reg};
                8'hA8: rdata <= {24'h0, reconfig_count_reg};
                default: rdata <= 32'h0;
            endcase
        end
    end
    
    // =========================================================================
    // Output Assignments
    // =========================================================================
    
    assign matrix_m         = matrix_m_reg;
    assign matrix_n         = matrix_n_reg;
    assign matrix_k         = matrix_k_reg;
    assign tile_m           = tile_m_reg;
    assign tile_n           = tile_n_reg;
    assign tile_k           = tile_k_reg;
    assign buffering_mode   = buffering_mode_reg;
    assign dram_base_a      = dram_base_a_reg;
    assign dram_base_b      = dram_base_b_reg;
    assign dram_base_c      = dram_base_c_reg;
    assign sram_base_a_ping = sram_base_a_ping_reg;
    assign sram_base_a_pong = sram_base_a_pong_reg;
    assign sram_base_b_ping = sram_base_b_ping_reg;
    assign sram_base_b_pong = sram_base_b_pong_reg;
    assign sram_base_c      = sram_base_c_reg;
    assign start            = ctrl_start_reg;
    assign ctrl_reset       = ctrl_reset_reg;
    assign baseline_mode    = baseline_mode_reg;
    assign error_out        = error_reg;

endmodule
