// =============================================================================
// Testbench: tb_llm_memory_controller_comparison
// Description: Baseline vs Optimized performance comparison testbench
//              Runs two back-to-back simulations and prints comparison
// =============================================================================

`timescale 1ns/1ps

module tb_llm_memory_controller_comparison;

    // =========================================================================
    // Parameters
    // =========================================================================
    
    localparam int SRAM_BANKS       = 8;
    localparam int SRAM_BANK_DEPTH  = 2048;
    localparam int SRAM_DATA_WIDTH  = 32;
    localparam int DRAM_ADDR_WIDTH  = 32;
    localparam int DRAM_DATA_WIDTH  = 128;
    localparam int DATA_WIDTH_A     = 8;
    localparam int DATA_WIDTH_B     = 8;
    localparam int DATA_WIDTH_C     = 32;
    localparam int MAX_TILE_DIM     = 64;
    localparam int PREFETCH_DEPTH   = 4;
    localparam int SRAM_ADDR_WIDTH  = $clog2(SRAM_BANKS * SRAM_BANK_DEPTH);
    
    localparam int CLK_PERIOD = 10; // 100MHz clock
    
    // =========================================================================
    // DUT Signals
    // =========================================================================
    
    logic clk;
    logic rst_n;
    
    // Software Config Interface
    logic [7:0]  cfg_addr;
    logic [31:0] cfg_wdata;
    logic        cfg_wen;
    logic        cfg_ren;
    logic [31:0] cfg_rdata;
    
    // DRAM Interface - Request Channel
    logic                        dram_req_valid;
    logic                        dram_req_ready;
    logic                        dram_req_is_write;
    logic [DRAM_ADDR_WIDTH-1:0]  dram_req_addr;
    logic [15:0]                 dram_req_bytes;
    
    // DRAM Interface - Read Response Channel
    logic                        dram_rvalid;
    logic                        dram_rready;
    logic [DRAM_DATA_WIDTH-1:0]  dram_rdata;
    logic                        dram_rlast;
    
    // DRAM Interface - Write Data Channel
    logic                        dram_wvalid;
    logic                        dram_wready;
    logic [DRAM_DATA_WIDTH-1:0]  dram_wdata;
    logic                        dram_wlast;
    
    // DRAM Interface - Write Response Channel
    logic                        dram_bvalid;
    logic                        dram_bready;
    
    // SRAM Interface (per bank) - Fully Synchronous
    logic [SRAM_BANKS-1:0]                                  sram_wen;
    logic [SRAM_BANKS-1:0]                                  sram_ren;
    logic [SRAM_BANKS-1:0][$clog2(SRAM_BANK_DEPTH)-1:0]    sram_addr;
    logic [SRAM_BANKS-1:0][SRAM_DATA_WIDTH-1:0]            sram_wdata;
    logic [SRAM_BANKS-1:0][SRAM_DATA_WIDTH-1:0]            sram_rdata;
    
    // Compute Engine Interface - Tile Metadata
    logic                        tile_valid;
    logic                        tile_ready;
    logic                        tile_done;
    logic [SRAM_ADDR_WIDTH-1:0]  tile_sram_addr_a;
    logic [SRAM_ADDR_WIDTH-1:0]  tile_sram_addr_b;
    logic [SRAM_ADDR_WIDTH-1:0]  tile_sram_addr_c;
    logic [12:0]                 tile_m_dim;
    logic [12:0]                 tile_n_dim;
    logic [12:0]                 tile_k_dim;
    
    // Compute Engine Interface - SRAM Access
    logic                        compute_sram_req_valid;
    logic                        compute_sram_req_ready;
    logic                        compute_sram_req_wen;
    logic [SRAM_ADDR_WIDTH-1:0]  compute_sram_req_addr;
    logic [SRAM_DATA_WIDTH-1:0]  compute_sram_req_wdata;
    logic [SRAM_DATA_WIDTH-1:0]  compute_sram_req_rdata;
    logic                        compute_sram_req_rdata_valid;
    
    // Top-Level Status
    logic done;
    logic error;
    
    // Performance Counters
    logic [31:0] perf_cycle_count;
    logic [31:0] perf_dram_read_beats;
    logic [31:0] perf_dram_write_beats;
    logic [15:0] perf_tile_count;
    logic [31:0] perf_idle_cycles;
    
    // =========================================================================
    // Performance Counter Storage (for comparison)
    // =========================================================================
    
    typedef struct {
        longint total_cycles;
        longint dram_read_beats;
        longint dram_write_beats;
        longint tile_count;
        longint idle_cycles;
    } perf_counters_t;
    
    perf_counters_t baseline_perf;
    perf_counters_t optimized_perf;
    
    // =========================================================================
    // DUT Instantiation
    // =========================================================================
    
    llm_memory_controller #(
        .SRAM_BANKS       (SRAM_BANKS),
        .SRAM_BANK_DEPTH  (SRAM_BANK_DEPTH),
        .SRAM_DATA_WIDTH  (SRAM_DATA_WIDTH),
        .DRAM_ADDR_WIDTH  (DRAM_ADDR_WIDTH),
        .DRAM_DATA_WIDTH  (DRAM_DATA_WIDTH),
        .DATA_WIDTH_A     (DATA_WIDTH_A),
        .DATA_WIDTH_B     (DATA_WIDTH_B),
        .DATA_WIDTH_C     (DATA_WIDTH_C),
        .MAX_TILE_DIM     (MAX_TILE_DIM),
        .PREFETCH_DEPTH   (PREFETCH_DEPTH),
        .SRAM_ADDR_WIDTH  (SRAM_ADDR_WIDTH)
    ) dut (
        .clk                        (clk),
        .rst_n                      (rst_n),
        .cfg_addr                   (cfg_addr),
        .cfg_wdata                  (cfg_wdata),
        .cfg_wen                    (cfg_wen),
        .cfg_ren                    (cfg_ren),
        .cfg_rdata                  (cfg_rdata),
        .dram_req_valid             (dram_req_valid),
        .dram_req_ready             (dram_req_ready),
        .dram_req_is_write          (dram_req_is_write),
        .dram_req_addr              (dram_req_addr),
        .dram_req_bytes             (dram_req_bytes),
        .dram_rvalid                (dram_rvalid),
        .dram_rready                (dram_rready),
        .dram_rdata                 (dram_rdata),
        .dram_rlast                 (dram_rlast),
        .dram_wvalid                (dram_wvalid),
        .dram_wready                (dram_wready),
        .dram_wdata                 (dram_wdata),
        .dram_wlast                 (dram_wlast),
        .dram_bvalid                (dram_bvalid),
        .dram_bready                (dram_bready),
        .sram_wen                   (sram_wen),
        .sram_ren                   (sram_ren),
        .sram_addr                  (sram_addr),
        .sram_wdata                 (sram_wdata),
        .sram_rdata                 (sram_rdata),
        .tile_valid                 (tile_valid),
        .tile_ready                 (tile_ready),
        .tile_done                  (tile_done),
        .tile_sram_addr_a           (tile_sram_addr_a),
        .tile_sram_addr_b           (tile_sram_addr_b),
        .tile_sram_addr_c           (tile_sram_addr_c),
        .tile_m_dim                 (tile_m_dim),
        .tile_n_dim                 (tile_n_dim),
        .tile_k_dim                 (tile_k_dim),
        .compute_sram_req_valid     (compute_sram_req_valid),
        .compute_sram_req_ready     (compute_sram_req_ready),
        .compute_sram_req_wen       (compute_sram_req_wen),
        .compute_sram_req_addr      (compute_sram_req_addr),
        .compute_sram_req_wdata     (compute_sram_req_wdata),
        .compute_sram_req_rdata     (compute_sram_req_rdata),
        .compute_sram_req_rdata_valid(compute_sram_req_rdata_valid),
        .done                       (done),
        .error                      (error),
        .perf_cycle_count           (perf_cycle_count),
        .perf_dram_read_beats       (perf_dram_read_beats),
        .perf_dram_write_beats      (perf_dram_write_beats),
        .perf_tile_count            (perf_tile_count),
        .perf_idle_cycles           (perf_idle_cycles)
    );
    
    // =========================================================================
    // Clock Generation
    // =========================================================================
    
    initial begin
        clk = 1'b0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end
    
    // =========================================================================
    // DRAM Model with Latency + Bandwidth Limit (to expose prefetch benefit)
    // =========================================================================
    typedef struct packed {
        logic [DRAM_ADDR_WIDTH-1:0] addr;
        logic [15:0]                bytes;
        logic                       is_write;
    } dram_req_t;

    dram_req_t req_q;
    logic      req_q_valid;

    localparam int READ_LAT  = 30; // cycles between req accept and first beat
    localparam int BEAT_GAP  = 2;  // cycles per beat (1 beat every BEAT_GAP cycles)
    localparam int READY_GAP = 3;  // make dram_req_ready pulse low periodically

    logic [15:0] dram_read_beats_remaining;
    logic        dram_read_active;

    logic [31:0] rd_latency_cnt;
    logic [31:0] beat_gap_cnt;

    // optional: simple ready throttling counter
    logic [31:0] ready_cnt;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            // request channel
            dram_req_ready <= 1'b1;

            // read response channel
            dram_rvalid <= 1'b0;
            dram_rdata  <= '0;
            dram_rlast  <= 1'b0;

            // write channels (keep simple)
            dram_wready <= 1'b1;
            dram_bvalid <= 1'b0;

            // internal state
            dram_read_active          <= 1'b0;
            dram_read_beats_remaining <= '0;
            rd_latency_cnt            <= 0;
            beat_gap_cnt              <= 0;
            ready_cnt                 <= 0;

            // ====== NEW: 1-entry queue reset ======
            req_q_valid               <= 1'b0;
            req_q                     <= '0;   // 可选但推荐
        end else begin
            // -----------------------------
            // (1) Throttle dram_req_ready + queue backpressure
            // -----------------------------
            ready_cnt <= ready_cnt + 1;
            if ((ready_cnt % (READY_GAP + 1) == READY_GAP) || req_q_valid)
                dram_req_ready <= 1'b0;
            else
                dram_req_ready <= 1'b1;

            // -----------------------------
            // (2) Accept a READ request -> enqueue (1-entry)
            // -----------------------------
            if (dram_req_valid && dram_req_ready) begin
                if (!dram_req_is_write) begin
                    // queue must be empty here because ready was deasserted when full
                    req_q_valid    <= 1'b1;
                    req_q.addr     <= dram_req_addr;
                    req_q.bytes    <= dram_req_bytes;
                    req_q.is_write <= dram_req_is_write;
                end
            end

            // -----------------------------
            // (2.5) NEW: If idle and queue has a request -> start read transaction
            // -----------------------------
            if (!dram_read_active && req_q_valid) begin
                dram_read_beats_remaining <= (req_q.bytes + (DRAM_DATA_WIDTH/8) - 1) / (DRAM_DATA_WIDTH/8);
                dram_read_active <= 1'b1;

                rd_latency_cnt <= READ_LAT;
                beat_gap_cnt   <= 0;

                req_q_valid    <= 1'b0;  // dequeue
            end

            // -----------------------------
            // (3) Generate read beats
            // -----------------------------
            dram_rvalid <= 1'b0;
            dram_rlast  <= 1'b0;

            if (dram_read_active) begin
                if (rd_latency_cnt != 0) begin
                    rd_latency_cnt <= rd_latency_cnt - 1;
                end else begin
                    if (beat_gap_cnt != 0) begin
                        beat_gap_cnt <= beat_gap_cnt - 1;
                    end else begin
                        dram_rvalid <= 1'b1;
                        dram_rdata  <= $random;

                        if (dram_rvalid && dram_rready) begin
                            if (dram_read_beats_remaining <= 1) begin
                                dram_rlast <= 1'b1;
                                dram_read_active <= 1'b0;
                                dram_read_beats_remaining <= 0;
                            end else begin
                                dram_read_beats_remaining <= dram_read_beats_remaining - 1;
                            end
                            beat_gap_cnt <= BEAT_GAP;
                        end
                    end
                end
            end

            // -----------------------------
            // (4) Write path (keep always-ready + simple response)
            // -----------------------------
            dram_wready <= 1'b1;

            if (dram_wvalid && dram_wready && dram_wlast && !dram_bvalid) begin
                dram_bvalid <= 1'b1;
            end else if (dram_bvalid && dram_bready) begin
                dram_bvalid <= 1'b0;
            end
        end
    end
    
    // =========================================================================
    // Simple SRAM Model (responds with dummy data)
    // =========================================================================
    
    always_ff @(posedge clk) begin
        for (int i = 0; i < SRAM_BANKS; i++) begin
            if (sram_ren[i])
                sram_rdata[i] <= $random;
        end
    end
    
   
    // =========================================================================
    // Functional Compute Engine Model (generates SRAM traffic) [NO-BUBBLE + STICKY DONE]
    // =========================================================================
    localparam int OPS_PER_TILE = 200;
    localparam int READ_RATIO   = 3;

    logic [31:0] ops_left;
    logic [31:0] op_idx;                    // 新增：当前 tile 内 op 序号
    logic [SRAM_ADDR_WIDTH-1:0] base_addr;

    logic [7:0] tile_process_counter;
    logic       tile_processing;

    // 防止 tile_valid 持续为 1 时重复 accept
    logic       tile_accept_seen;

    // drive compute request signals (TB -> DUT)
    logic [SRAM_ADDR_WIDTH-1:0]  req_addr_q;
    logic                        req_wen_q;
    logic [SRAM_DATA_WIDTH-1:0]  req_wdata_q;

    assign compute_sram_req_addr  = req_addr_q;
    assign compute_sram_req_wen   = req_wen_q;
    assign compute_sram_req_wdata = req_wdata_q;

    // tile_ready 用组合逻辑
    assign tile_ready = (~tile_processing) & (~tile_accept_seen);

    initial begin
        tile_done  = 1'b0;

        compute_sram_req_valid = 1'b0;
        req_addr_q  = '0;
        req_wen_q   = 1'b0;
        req_wdata_q = '0;

        tile_processing = 1'b0;
        tile_process_counter = 8'h0;

        ops_left     = 0;
        op_idx       = 0;
        base_addr    = '0;

        tile_accept_seen = 1'b0;
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            tile_processing       <= 1'b0;
            tile_process_counter  <= 8'h0;
            tile_done             <= 1'b0;

            compute_sram_req_valid <= 1'b0;
            req_addr_q            <= '0;
            req_wen_q             <= 1'b0;
            req_wdata_q           <= '0;

            ops_left              <= 0;
            op_idx                <= 0;
            base_addr             <= '0;

            tile_accept_seen      <= 1'b0;

        end else begin
            // tile_valid 拉低后允许下次 accept
            if (!tile_valid) begin
                tile_accept_seen <= 1'b0;
            end

            // -----------------------
            // Accept a tile to process (只允许一次)
            // -----------------------
            if (tile_valid && tile_ready) begin
                tile_processing      <= 1'b1;
                tile_process_counter <= 8'd20;     // ⚠️可调小一点加速（比如 10~30）
                ops_left             <= OPS_PER_TILE;
                op_idx               <= 0;

                base_addr <= (tile_sram_addr_c ^ tile_sram_addr_a) + 32;

                // 清掉上一次 done（sticky done）
                tile_done <= 1'b0;

                // 初始化第一拍的 request（下一拍开始持续 valid）
                req_addr_q  <= (tile_sram_addr_c ^ tile_sram_addr_a) + 32;
                req_wen_q   <= 1'b0;
                req_wdata_q <= '0;

                tile_accept_seen <= 1'b1;

                $display("%0t NEW_TILE accepted: a=%0d b=%0d c=%0d m=%0d n=%0d k=%0d",
                        $time, tile_sram_addr_a, tile_sram_addr_b, tile_sram_addr_c,
                        tile_m_dim, tile_n_dim, tile_k_dim);
            end

            // -----------------------
            // During processing: generate SRAM requests (NO BUBBLE)
            // -----------------------
            if (tile_processing) begin
                // valid：只要还有 ops，就一直保持 1（避免一拍空泡）
                if (ops_left != 0) begin
                    compute_sram_req_valid <= 1'b1;

                    if (compute_sram_req_ready) begin
                        // 完成一次 op
                        ops_left <= ops_left - 1;
                        op_idx   <= op_idx + 1;

                        // 生成下一拍要发的 request（地址递增 + 读写比例）
                        req_addr_q <= base_addr + (op_idx + 1);

                        if (((op_idx + 1) % (READ_RATIO+1)) == 0) begin
                            req_wen_q   <= 1'b1;
                            req_wdata_q <= $random;
                        end else begin
                            req_wen_q   <= 1'b0;
                            req_wdata_q <= '0;
                        end
                    end
                end else begin
                    compute_sram_req_valid <= 1'b0;
                end

                // compute 计时
                if (tile_process_counter > 0) begin
                    tile_process_counter <= tile_process_counter - 1;
                end

                // -----------------------
                // Tile completion condition
                // -----------------------
                if ((tile_process_counter == 0) && (ops_left == 0)) begin
                    tile_processing <= 1'b0;

                    // sticky done：保持为 1，直到下一次 tile accept 清掉
                    if (!tile_done) begin
                        tile_done <= 1'b1;
                        $display("%0t TILE_DONE (sticky asserted)", $time);
                    end
                end
            end else begin
                compute_sram_req_valid <= 1'b0;
            end
        end
    end
    
    // =========================================================================
    // Test Stimulus - Run BASELINE then OPTIMIZED
    // =========================================================================
    
    logic baseline_done, optimized_done;
    logic baseline_timeout, optimized_timeout;
    
    initial begin
        baseline_done = 1'b0;
        baseline_timeout = 1'b0;
        optimized_done = 1'b0;
        optimized_timeout = 1'b0;
        
        // Initialize signals
        cfg_addr = 8'h0;
        cfg_wdata = 32'h0;
        cfg_wen = 1'b0;
        cfg_ren = 1'b0;
        
        $display("");
        $display("===============================================================================");
        $display("         LLM MEMORY CONTROLLER - BASELINE vs OPTIMIZED COMPARISON");
        $display("===============================================================================");
        $display("");
        
        // =====================================================================
        // TEST 1: BASELINE MODE (baseline_mode = 1)
        // =====================================================================
        
        $display("========================================");
        $display("  TEST 1: BASELINE MODE");
        $display("========================================");
        
        // Reset sequence
        rst_n = 1'b0;
        repeat (5) @(posedge clk);
        rst_n = 1'b1;
        repeat (2) @(posedge clk);
        
        // Configure for baseline mode
        configure_controller(1'b1); // baseline_mode = 1
        
        // Start operation
        write_config(8'h00, 32'h0001); // start = 1
        repeat (5) @(posedge clk);
        
        $display("[BASELINE] Waiting for done...");
        
        // Wait for done signal with timeout
        fork
            begin
                wait(done);
                baseline_done = 1'b1;
                $display("[BASELINE] Done signal asserted!");
            end
            begin
                repeat (200000) @(posedge clk);
                baseline_timeout = 1'b1;
                $display("[BASELINE ERROR] Timeout!");
            end
        join_any
        disable fork;
        
        // Wait a few cycles for counters to stabilize
        repeat (5) @(posedge clk);
        
        // Capture baseline performance counters
        capture_performance_counters(baseline_perf);
        print_single_run_counters("BASELINE", baseline_perf);
        
        // =====================================================================
        // TEST 2: OPTIMIZED MODE (baseline_mode = 0)
        // =====================================================================
        
        $display("");
        $display("========================================");
        $display("  TEST 2: OPTIMIZED MODE");
        $display("========================================");
        
        // Reset sequence
        rst_n = 1'b0;
        repeat (5) @(posedge clk);
        rst_n = 1'b1;
        repeat (2) @(posedge clk);
        
        // Configure for optimized mode
        configure_controller(1'b0); // baseline_mode = 0
        
        // Start operation
        write_config(8'h00, 32'h0001); // start = 1
        repeat (5) @(posedge clk);
        
        $display("[OPTIMIZED] Waiting for done...");
        
        // Wait for done signal with timeout
        fork
            begin
                wait(done);
                optimized_done = 1'b1;
                $display("[OPTIMIZED] Done signal asserted!");
            end
            begin
                repeat (200000) @(posedge clk);
                optimized_timeout = 1'b1;
                $display("[OPTIMIZED ERROR] Timeout!");
            end
        join_any
        disable fork;
        
        // Wait a few cycles for counters to stabilize
        repeat (5) @(posedge clk);
        
        // Capture optimized performance counters
        capture_performance_counters(optimized_perf);
        print_single_run_counters("OPTIMIZED", optimized_perf);
        
        // =====================================================================
        // COMPARISON SUMMARY
        // =====================================================================
        
        $display("");
        
        if (baseline_done && optimized_done) begin
            print_comparison_summary();
        end else begin
            $display("===============================================================================");
            $display("                    COMPARISON FAILED");
            $display("===============================================================================");
            if (baseline_timeout)
                $display("BASELINE: RUN FAILED (timeout)");
            if (optimized_timeout)
                $display("OPTIMIZED: RUN FAILED (timeout)");
            $display("===============================================================================");
        end
        
        $display("");
        $display("===============================================================================");
        $display("                           TEST COMPLETE");
        $display("===============================================================================");
        $display("");
        
        $finish;
    end
    
    // =========================================================================
    // Helper Tasks
    // =========================================================================
    
    task write_config(input [7:0] addr, input [31:0] data);
        @(posedge clk);
        cfg_addr = addr;
        cfg_wdata = data;
        cfg_wen = 1'b1;
        @(posedge clk);
        cfg_wen = 1'b0;
    endtask
    
    task configure_controller(input logic baseline);
        // Matrix dimensions
        write_config(8'h08, 32'h0040); // matrix_m = 64
        write_config(8'h0C, 32'h0040); // matrix_n = 64
        write_config(8'h10, 32'h0040); // matrix_k = 64
        
        // Tile dimensions - split into two registers:
        // ADDR 0x14: {6'h0, tile_n[12:0], tile_m[12:0]}
        // ADDR 0x58: {17'h0, mode[1:0], tile_k[12:0]}
        write_config(8'h14, {6'h0, 13'd16, 13'd16}); // tile_n=16, tile_m=16
        write_config(8'h58, {17'h0, 2'b00, 13'd16}); // tile_k=16, mode=single buffer

        // Buffering mode
        if (baseline)
            write_config(8'h18, 32'h0000); // Single buffer
        else
            write_config(8'h18, 32'h0001); // Double buffer
        
        // DRAM base addresses
        write_config(8'h1C, 32'h0000_1000); // dram_base_a
        write_config(8'h20, 32'h0000_2000); // dram_base_b
        write_config(8'h24, 32'h0000_3000); // dram_base_c
        
        // SRAM base addresses
        write_config(8'h28, 32'h0000); // sram_base_a_ping
        write_config(8'h2C, 32'h0010); // sram_base_a_pong
        write_config(8'h30, 32'h0020); // sram_base_b_ping
        write_config(8'h34, 32'h0030); // sram_base_b_pong
        write_config(8'h38, 32'h0040); // sram_base_c
        
        // Baseline mode configuration
        write_config(8'h3C, baseline ? 32'h0001 : 32'h0000);
        
        repeat (5) @(posedge clk);
    endtask
    
    task capture_performance_counters(output perf_counters_t counters);
        counters.total_cycles           = perf_cycle_count;
        counters.dram_read_beats        = perf_dram_read_beats;
        counters.dram_write_beats       = perf_dram_write_beats;
        counters.tile_count             = perf_tile_count;
        counters.idle_cycles            = perf_idle_cycles;
    endtask
    
    task print_single_run_counters(input string mode_name, input perf_counters_t counters);
        real compute_efficiency;
        real dram_bw_util;
        
        if (counters.total_cycles > 0) begin
            compute_efficiency = 100.0 * (1.0 - (real'(counters.idle_cycles) / real'(counters.total_cycles)));
            dram_bw_util = 100.0 * (real'(counters.dram_read_beats) / real'(counters.total_cycles));
        end else begin
            compute_efficiency = 0.0;
            dram_bw_util = 0.0;
        end
        
        $display("");
        $display("[%s] Performance Counters:", mode_name);
        $display("  total_cycles          = %0d", counters.total_cycles);
        $display("  dram_read_beats       = %0d", counters.dram_read_beats);
        $display("  dram_write_beats      = %0d", counters.dram_write_beats);
        $display("  tile_count            = %0d", counters.tile_count);
        $display("  idle_cycles           = %0d", counters.idle_cycles);
        $display("  compute_efficiency    = %0.2f%%", compute_efficiency);
        $display("  dram_bw_utilization   = %0.2f%%", dram_bw_util);
    endtask
    
    task print_comparison_summary();
        real baseline_compute_eff, optimized_compute_eff;
        real baseline_dram_bw, optimized_dram_bw;
        real speedup;
        real compute_eff_improvement, dram_bw_improvement;
        longint diff_dram_read_beats;
        longint diff_dram_write_beats;
        longint diff_idle;
        
        // Calculate metrics
        if (baseline_perf.total_cycles > 0) begin
            baseline_compute_eff = 100.0 * (1.0 - (real'(baseline_perf.idle_cycles) / real'(baseline_perf.total_cycles)));
            baseline_dram_bw = 100.0 * (real'(baseline_perf.dram_read_beats) / real'(baseline_perf.total_cycles));
        end else begin
            baseline_compute_eff = 0.0;
            baseline_dram_bw = 0.0;
        end
        
        if (optimized_perf.total_cycles > 0) begin
            optimized_compute_eff = 100.0 * (1.0 - (real'(optimized_perf.idle_cycles) / real'(optimized_perf.total_cycles)));
            optimized_dram_bw = 100.0 * (real'(optimized_perf.dram_read_beats) / real'(optimized_perf.total_cycles));
            
            if (baseline_perf.total_cycles > 0)
                speedup = real'(baseline_perf.total_cycles) / real'(optimized_perf.total_cycles);
            else
                speedup = 0.0;
        end else begin
            optimized_compute_eff = 0.0;
            optimized_dram_bw = 0.0;
            speedup = 0.0;
        end
        
        compute_eff_improvement = optimized_compute_eff - baseline_compute_eff;
        dram_bw_improvement = optimized_dram_bw - baseline_dram_bw;
        
        // Calculate differences
        diff_dram_read_beats = optimized_perf.dram_read_beats - baseline_perf.dram_read_beats;
        diff_dram_write_beats = optimized_perf.dram_write_beats - baseline_perf.dram_write_beats;
        diff_idle = optimized_perf.idle_cycles - baseline_perf.idle_cycles;
        
        $display("===============================================================================");
        $display("                    BASELINE vs OPTIMIZED COMPARISON");
        $display("===============================================================================");
        $display("");
        $display("METRIC                          BASELINE        OPTIMIZED       IMPROVEMENT");
        $display("-------------------------------------------------------------------------------");
        $display("total_cycles                    %-15d %-15d %.2fx faster", 
                 baseline_perf.total_cycles, optimized_perf.total_cycles, speedup);
        $display("dram_read_beats                 %-15d %-15d %0d", 
                 baseline_perf.dram_read_beats, optimized_perf.dram_read_beats, diff_dram_read_beats);
        $display("dram_write_beats                %-15d %-15d %0d", 
                 baseline_perf.dram_write_beats, optimized_perf.dram_write_beats, diff_dram_write_beats);
        $display("tile_count                      %-15d %-15d", 
                 baseline_perf.tile_count, optimized_perf.tile_count);
        $display("idle_cycles                     %-15d %-15d %0d", 
                 baseline_perf.idle_cycles, optimized_perf.idle_cycles, diff_idle);
        $display("");
        $display("KEY METRICS:");
        $display("  Compute Efficiency            %-14.2f%% %-14.2f%% %.2f%%", 
                 baseline_compute_eff, optimized_compute_eff, compute_eff_improvement);
        $display("  DRAM BW Utilization           %-14.2f%% %-14.2f%% %.2f%%", 
                 baseline_dram_bw, optimized_dram_bw, dram_bw_improvement);
        $display("  Overall Speedup               -               -               %.2fx", speedup);
        $display("");
        $display("===============================================================================");
    endtask
    
    // =========================================================================
    // Timeout Watchdog
    // =========================================================================
    
    initial begin
        #50000000; // 50ms global timeout (2x 200k cycles @ 10ns + margin)
        $display("[TB ERROR] Global simulation timeout!");
        $finish;
    end

endmodule
