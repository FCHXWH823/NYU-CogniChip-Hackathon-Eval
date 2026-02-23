// =============================================================================
// Module: llm_memory_controller
// Description: Top-level LLM GEMM Tiling Memory Controller
//              Integrates config_regs, tile_scheduler, dram_prefetch_engine,
//              and sram_bank_arbiter
// =============================================================================

module llm_memory_controller #(
    parameter int SRAM_BANKS        = 8,
    parameter int SRAM_BANK_DEPTH   = 2048,
    parameter int SRAM_DATA_WIDTH   = 32,
    parameter int DRAM_ADDR_WIDTH   = 32,
    parameter int DRAM_DATA_WIDTH   = 128,
    parameter int DATA_WIDTH_A      = 8,
    parameter int DATA_WIDTH_B      = 8,
    parameter int DATA_WIDTH_C      = 32,
    parameter int MAX_TILE_DIM      = 64,
    parameter int PREFETCH_DEPTH    = 4,
    // Derived parameter - must be last
    parameter int SRAM_ADDR_WIDTH   = $clog2(SRAM_BANKS * SRAM_BANK_DEPTH)
) (
    input  logic clk,
    input  logic rst_n,
    
    // Software Config Interface
    input  logic [7:0]  cfg_addr,
    input  logic [31:0] cfg_wdata,
    input  logic        cfg_wen,
    input  logic        cfg_ren,
    output logic [31:0] cfg_rdata,
    
    // DRAM Interface - Request Channel
    output logic                        dram_req_valid,
    input  logic                        dram_req_ready,
    output logic                        dram_req_is_write,
    output logic [DRAM_ADDR_WIDTH-1:0]  dram_req_addr,
    output logic [15:0]                 dram_req_bytes,
    
    // DRAM Interface - Read Response Channel
    input  logic                        dram_rvalid,
    output logic                        dram_rready,
    input  logic [DRAM_DATA_WIDTH-1:0]  dram_rdata,
    input  logic                        dram_rlast,
    
    // DRAM Interface - Write Data Channel
    output logic                        dram_wvalid,
    input  logic                        dram_wready,
    output logic [DRAM_DATA_WIDTH-1:0]  dram_wdata,
    output logic                        dram_wlast,
    
    // DRAM Interface - Write Response Channel
    input  logic                        dram_bvalid,
    output logic                        dram_bready,
    
    // SRAM Interface (per bank) - Fully Synchronous
    output logic [SRAM_BANKS-1:0]                                  sram_wen,
    output logic [SRAM_BANKS-1:0]                                  sram_ren,
    output logic [SRAM_BANKS-1:0][$clog2(SRAM_BANK_DEPTH)-1:0]    sram_addr,
    output logic [SRAM_BANKS-1:0][SRAM_DATA_WIDTH-1:0]            sram_wdata,
    input  logic [SRAM_BANKS-1:0][SRAM_DATA_WIDTH-1:0]            sram_rdata,
    
    // Compute Engine Interface - Tile Metadata
    output logic                        tile_valid,
    input  logic                        tile_ready,
    input  logic                        tile_done,
    output logic [SRAM_ADDR_WIDTH-1:0]  tile_sram_addr_a,
    output logic [SRAM_ADDR_WIDTH-1:0]  tile_sram_addr_b,
    output logic [SRAM_ADDR_WIDTH-1:0]  tile_sram_addr_c,
    output logic [12:0]                 tile_m_dim,
    output logic [12:0]                 tile_n_dim,
    output logic [12:0]                 tile_k_dim,
    
    // Compute Engine Interface - SRAM Access
    input  logic                        compute_sram_req_valid,
    output logic                        compute_sram_req_ready,
    input  logic                        compute_sram_req_wen,
    input  logic [SRAM_ADDR_WIDTH-1:0]  compute_sram_req_addr,
    input  logic [SRAM_DATA_WIDTH-1:0]  compute_sram_req_wdata,
    output logic [SRAM_DATA_WIDTH-1:0]  compute_sram_req_rdata,
    output logic                        compute_sram_req_rdata_valid,
    
    // Top-Level Status
    output logic done,
    output logic error,

    // Performance Counters (Observational)
    output logic [31:0] perf_cycle_count,
    output logic [31:0] perf_dram_read_beats,
    output logic [31:0] perf_dram_write_beats,
    output logic [15:0] perf_tile_count,
    output logic [31:0] perf_idle_cycles
);

    // =========================================================================
    // Local Parameters
    // =========================================================================
    
    // SRAM_ADDR_WIDTH is now a parameter
    
    // =========================================================================
    // Internal Signals - Config Regs to Scheduler
    // =========================================================================
    
    logic [15:0] matrix_m;
    logic [15:0] matrix_n;
    logic [15:0] matrix_k;
    logic [12:0] tile_m;
    logic [12:0] tile_n;
    logic [12:0] tile_k;
    logic [1:0]  buffering_mode;
    logic [31:0] dram_base_a;
    logic [31:0] dram_base_b;
    logic [31:0] dram_base_c;
    logic [15:0] sram_base_a_ping;
    logic [15:0] sram_base_a_pong;
    logic [15:0] sram_base_b_ping;
    logic [15:0] sram_base_b_pong;
    logic [15:0] sram_base_c;
    logic        start;
    logic        ctrl_reset;
    logic        baseline_mode;
    
    logic        sched_busy;
    logic        sched_done;
    logic        sched_error;
    logic        config_error;

    logic [31:0] perf_cycle_count_reg;
    logic [31:0] perf_dram_read_beats_reg;
    logic [31:0] perf_dram_write_beats_reg;
    logic [15:0] perf_tile_count_reg;
    logic [31:0] perf_idle_cycles_reg;
    
    // =========================================================================
    // Internal Signals - Scheduler to Prefetch Engine
    // =========================================================================
    
    logic        fetch_req_valid;
    logic        fetch_req_ready;
    logic        fetch_req_is_write;
    logic [31:0] fetch_req_dram_addr_a;
    logic [31:0] fetch_req_dram_addr_b;
    logic [31:0] fetch_req_dram_addr_c;
    logic [SRAM_ADDR_WIDTH-1:0] fetch_req_sram_addr_a;
    logic [SRAM_ADDR_WIDTH-1:0] fetch_req_sram_addr_b;
    logic [SRAM_ADDR_WIDTH-1:0] fetch_req_sram_addr_c;
    logic [15:0] fetch_req_num_elements_a;
    logic [15:0] fetch_req_num_elements_b;
    logic [15:0] fetch_req_num_elements_c;
    logic        fetch_done;
    
    // =========================================================================
    // Internal Signals - Prefetch Engine to SRAM Arbiter
    // =========================================================================
    
    logic                        prefetch_sram_req_valid;
    logic                        prefetch_sram_req_ready;
    logic                        prefetch_sram_req_wen;
    logic [SRAM_ADDR_WIDTH-1:0]  prefetch_sram_req_addr;
    logic [SRAM_DATA_WIDTH-1:0]  prefetch_sram_req_wdata;
    logic [SRAM_DATA_WIDTH-1:0]  prefetch_sram_req_rdata;
    logic                        prefetch_sram_req_rdata_valid;
    
    // =========================================================================
    // Compute SRAM Access - Exposed as Top-Level Ports
    // =========================================================================
    // Compute engine SRAM access signals are now top-level ports
    // and directly connected to the arbiter compute port
    
    // =========================================================================
    // Module Instantiation: config_regs
    // =========================================================================
    
    config_regs u_config_regs (
        .clk               (clk),
        .rst_n             (rst_n),
        
        // Host Interface
        .addr              (cfg_addr),
        .wdata             (cfg_wdata),
        .wen               (cfg_wen),
        .ren               (cfg_ren),
        .rdata             (cfg_rdata),
        
        // Configuration Outputs
        .matrix_m          (matrix_m),
        .matrix_n          (matrix_n),
        .matrix_k          (matrix_k),
        .tile_m            (tile_m),
        .tile_n            (tile_n),
        .tile_k            (tile_k),
        .buffering_mode    (buffering_mode),
        .dram_base_a       (dram_base_a),
        .dram_base_b       (dram_base_b),
        .dram_base_c       (dram_base_c),
        .sram_base_a_ping  (sram_base_a_ping),
        .sram_base_a_pong  (sram_base_a_pong),
        .sram_base_b_ping  (sram_base_b_ping),
        .sram_base_b_pong  (sram_base_b_pong),
        .sram_base_c       (sram_base_c),
        .start             (start),
        .ctrl_reset        (ctrl_reset),
        .baseline_mode     (baseline_mode),
        .reconfig_trigger  (sched_done),
        
        // Status Inputs
        .busy              (sched_busy),
        .done              (sched_done),
        .error_in          (sched_error),
        .perf_cycle_count      (perf_cycle_count_reg),
        .perf_dram_read_beats  (perf_dram_read_beats_reg),
        .perf_dram_write_beats (perf_dram_write_beats_reg),
        .perf_tile_count       (perf_tile_count_reg),
        .perf_idle_cycles      (perf_idle_cycles_reg),
        .error_out         (config_error)
    );
    
    // =========================================================================
    // Baseline Mode Override Logic
    // =========================================================================
    // When baseline_mode = 1, force simplest configuration for comparison:
    // - Single buffering (no ping-pong): buffering_mode forced to 0
    // - The existing design naturally operates in baseline mode when:
    //   * No double buffering (buffering_mode=0)
    //   * Scheduler issues fetch requests synchronously
    //   * No compute/memory overlap (tile_scheduler waits for fetch_done)
    //
    // When baseline_mode = 0, use optimized settings from config_regs
    
    logic [1:0] effective_buffering_mode;
    
    assign effective_buffering_mode = baseline_mode ? 2'b00 : buffering_mode;
    
    // =========================================================================
    // Module Instantiation: tile_scheduler
    // =========================================================================
    
    tile_scheduler #(
        .MAX_TILE_DIM     (MAX_TILE_DIM),
        .SRAM_ADDR_WIDTH  (SRAM_ADDR_WIDTH),
        .DATA_WIDTH_A     (DATA_WIDTH_A),
        .DATA_WIDTH_B     (DATA_WIDTH_B),
        .DATA_WIDTH_C     (DATA_WIDTH_C)
    ) u_tile_scheduler (
        .clk               (clk),
        .rst_n             (rst_n),
        
        // Config Interface
        .matrix_m          (matrix_m),
        .matrix_n          (matrix_n),
        .matrix_k          (matrix_k),
        .tile_m            (tile_m),
        .tile_n            (tile_n),
        .tile_k            (tile_k),
        .buffering_mode    (effective_buffering_mode),
        .dram_base_a       (dram_base_a),
        .dram_base_b       (dram_base_b),
        .dram_base_c       (dram_base_c),
        .sram_base_a_ping  (sram_base_a_ping),
        .sram_base_a_pong  (sram_base_a_pong),
        .sram_base_b_ping  (sram_base_b_ping),
        .sram_base_b_pong  (sram_base_b_pong),
        .sram_base_c       (sram_base_c),
        .start             (start),
        
        // Prefetch Engine Interface
        .fetch_req_valid          (fetch_req_valid),
        .fetch_req_ready          (fetch_req_ready),
        .fetch_req_is_write       (fetch_req_is_write),
        .fetch_req_dram_addr_a    (fetch_req_dram_addr_a),
        .fetch_req_dram_addr_b    (fetch_req_dram_addr_b),
        .fetch_req_dram_addr_c    (fetch_req_dram_addr_c),
        .fetch_req_sram_addr_a    (fetch_req_sram_addr_a),
        .fetch_req_sram_addr_b    (fetch_req_sram_addr_b),
        .fetch_req_sram_addr_c    (fetch_req_sram_addr_c),
        .fetch_req_num_elements_a (fetch_req_num_elements_a),
        .fetch_req_num_elements_b (fetch_req_num_elements_b),
        .fetch_req_num_elements_c (fetch_req_num_elements_c),
        .fetch_done               (fetch_done),
        
        // Compute Engine Interface
        .tile_valid        (tile_valid),
        .tile_ready        (tile_ready),
        .tile_done         (tile_done),
        .tile_sram_addr_a  (tile_sram_addr_a),
        .tile_sram_addr_b  (tile_sram_addr_b),
        .tile_sram_addr_c  (tile_sram_addr_c),
        .tile_m_dim        (tile_m_dim),
        .tile_n_dim        (tile_n_dim),
        .tile_k_dim        (tile_k_dim),
        
        // Status
        .busy              (sched_busy),
        .done              (sched_done),
        .error             (sched_error)
    );
    
    // =========================================================================
    // Module Instantiation: dram_prefetch_engine
    // =========================================================================
    
    dram_prefetch_engine #(
        .DRAM_ADDR_WIDTH  (DRAM_ADDR_WIDTH),
        .DRAM_DATA_WIDTH  (DRAM_DATA_WIDTH),
        .SRAM_ADDR_WIDTH  (SRAM_ADDR_WIDTH),
        .SRAM_DATA_WIDTH  (SRAM_DATA_WIDTH),
        .DATA_WIDTH_A     (DATA_WIDTH_A),
        .DATA_WIDTH_B     (DATA_WIDTH_B),
        .DATA_WIDTH_C     (DATA_WIDTH_C),
        .PREFETCH_DEPTH   (PREFETCH_DEPTH)
    ) u_dram_prefetch_engine (
        .clk               (clk),
        .rst_n             (rst_n),
        
        // Scheduler Interface
        .fetch_req_valid          (fetch_req_valid),
        .fetch_req_ready          (fetch_req_ready),
        .fetch_req_is_write       (fetch_req_is_write),
        .fetch_req_dram_addr_a    (fetch_req_dram_addr_a),
        .fetch_req_dram_addr_b    (fetch_req_dram_addr_b),
        .fetch_req_dram_addr_c    (fetch_req_dram_addr_c),
        .fetch_req_sram_addr_a    (fetch_req_sram_addr_a),
        .fetch_req_sram_addr_b    (fetch_req_sram_addr_b),
        .fetch_req_sram_addr_c    (fetch_req_sram_addr_c),
        .fetch_req_num_elements_a (fetch_req_num_elements_a),
        .fetch_req_num_elements_b (fetch_req_num_elements_b),
        .fetch_req_num_elements_c (fetch_req_num_elements_c),
        .fetch_done               (fetch_done),
        
        // DRAM Interface
        .dram_req_valid    (dram_req_valid),
        .dram_req_ready    (dram_req_ready),
        .dram_req_is_write (dram_req_is_write),
        .dram_req_addr     (dram_req_addr),
        .dram_req_bytes    (dram_req_bytes),
        .dram_rvalid       (dram_rvalid),
        .dram_rready       (dram_rready),
        .dram_rdata        (dram_rdata),
        .dram_rlast        (dram_rlast),
        .dram_wvalid       (dram_wvalid),
        .dram_wready       (dram_wready),
        .dram_wdata        (dram_wdata),
        .dram_wlast        (dram_wlast),
        .dram_bvalid       (dram_bvalid),
        .dram_bready       (dram_bready),
        
        // SRAM Arbiter Interface
        .sram_req_valid       (prefetch_sram_req_valid),
        .sram_req_ready       (prefetch_sram_req_ready),
        .sram_req_wen         (prefetch_sram_req_wen),
        .sram_req_addr        (prefetch_sram_req_addr),
        .sram_req_wdata       (prefetch_sram_req_wdata),
        .sram_req_rdata       (prefetch_sram_req_rdata),
        .sram_req_rdata_valid (prefetch_sram_req_rdata_valid)
    );
    
    // =========================================================================
    // Module Instantiation: sram_bank_arbiter
    // =========================================================================
    
    sram_bank_arbiter #(
        .SRAM_BANKS       (SRAM_BANKS),
        .SRAM_BANK_DEPTH  (SRAM_BANK_DEPTH),
        .SRAM_DATA_WIDTH  (SRAM_DATA_WIDTH),
        .SRAM_ADDR_WIDTH  (SRAM_ADDR_WIDTH)
    ) u_sram_bank_arbiter (
        .clk               (clk),
        .rst_n             (rst_n),
        
        // Prefetch Engine Port
        .prefetch_req_valid       (prefetch_sram_req_valid),
        .prefetch_req_ready       (prefetch_sram_req_ready),
        .prefetch_req_wen         (prefetch_sram_req_wen),
        .prefetch_req_addr        (prefetch_sram_req_addr),
        .prefetch_req_wdata       (prefetch_sram_req_wdata),
        .prefetch_req_rdata       (prefetch_sram_req_rdata),
        .prefetch_req_rdata_valid (prefetch_sram_req_rdata_valid),
        
        // Compute Engine Port
        .compute_req_valid       (compute_sram_req_valid),
        .compute_req_ready       (compute_sram_req_ready),
        .compute_req_wen         (compute_sram_req_wen),
        .compute_req_addr        (compute_sram_req_addr),
        .compute_req_wdata       (compute_sram_req_wdata),
        .compute_req_rdata       (compute_sram_req_rdata),
        .compute_req_rdata_valid (compute_sram_req_rdata_valid),
        
        // Physical SRAM Banks
        .sram_wen          (sram_wen),
        .sram_ren          (sram_ren),
        .sram_addr         (sram_addr),
        .sram_wdata        (sram_wdata),
        .sram_rdata        (sram_rdata)
    );
    
    // =========================================================================
    // Performance Counters
    // =========================================================================

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            perf_cycle_count_reg      <= 32'h0;
            perf_dram_read_beats_reg  <= 32'h0;
            perf_dram_write_beats_reg <= 32'h0;
            perf_tile_count_reg       <= 16'h0;
            perf_idle_cycles_reg      <= 32'h0;
        end else if (start || ctrl_reset) begin
            perf_cycle_count_reg      <= 32'h0;
            perf_dram_read_beats_reg  <= 32'h0;
            perf_dram_write_beats_reg <= 32'h0;
            perf_tile_count_reg       <= 16'h0;
            perf_idle_cycles_reg      <= 32'h0;
        end else if (!sched_done) begin
            perf_cycle_count_reg <= perf_cycle_count_reg + 32'h1;

            if (dram_rvalid && dram_rready)
                perf_dram_read_beats_reg <= perf_dram_read_beats_reg + 32'h1;

            if (dram_wvalid && dram_wready)
                perf_dram_write_beats_reg <= perf_dram_write_beats_reg + 32'h1;

            if (tile_done)
                perf_tile_count_reg <= perf_tile_count_reg + 16'h1;

            if (sched_busy && !dram_rvalid && !dram_wvalid && (!tile_valid || !tile_ready))
                perf_idle_cycles_reg <= perf_idle_cycles_reg + 32'h1;
        end
    end

    assign perf_cycle_count      = perf_cycle_count_reg;
    assign perf_dram_read_beats  = perf_dram_read_beats_reg;
    assign perf_dram_write_beats = perf_dram_write_beats_reg;
    assign perf_tile_count       = perf_tile_count_reg;
    assign perf_idle_cycles      = perf_idle_cycles_reg;
    
    // =========================================================================
    // Top-Level Status
    // =========================================================================
    
    assign done  = sched_done;
    assign error = config_error || sched_error;

endmodule
