// =============================================================================
// Testbench: tb_gemm_traffic
// Description: Replays scaled Qwen3-8B attn_q_proj GEMM traffic for
//              analytical-model cross-validation.
// =============================================================================

`timescale 1ns/1ps

module tb_gemm_traffic;

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
    localparam int BANK_ADDR_WIDTH  = $clog2(SRAM_BANK_DEPTH);
    localparam int CLK_PERIOD       = 10;
    localparam int EXPECTED_TILES   = 16;

    // Config addresses
    localparam logic [7:0] ADDR_CTRL         = 8'h00;
    localparam logic [7:0] ADDR_STATUS       = 8'h04;
    localparam logic [7:0] ADDR_MATRIX_M     = 8'h08;
    localparam logic [7:0] ADDR_MATRIX_N     = 8'h0C;
    localparam logic [7:0] ADDR_MATRIX_K     = 8'h10;
    localparam logic [7:0] ADDR_TILE_DIM     = 8'h14;
    localparam logic [7:0] ADDR_TILE_K_MODE  = 8'h58;
    localparam logic [7:0] ADDR_BUF_MODE     = 8'h18;
    localparam logic [7:0] ADDR_DRAM_BASE_A  = 8'h1C;
    localparam logic [7:0] ADDR_DRAM_BASE_B  = 8'h20;
    localparam logic [7:0] ADDR_DRAM_BASE_C  = 8'h24;
    localparam logic [7:0] ADDR_SRAM_A_PING  = 8'h28;
    localparam logic [7:0] ADDR_SRAM_A_PONG  = 8'h2C;
    localparam logic [7:0] ADDR_SRAM_B_PING  = 8'h30;
    localparam logic [7:0] ADDR_SRAM_B_PONG  = 8'h34;
    localparam logic [7:0] ADDR_SRAM_C       = 8'h38;

    logic clk;
    logic rst_n;

    logic [7:0]  cfg_addr;
    logic [31:0] cfg_wdata;
    logic        cfg_wen;
    logic        cfg_ren;
    logic [31:0] cfg_rdata;

    logic                        dram_req_valid;
    logic                        dram_req_ready;
    logic                        dram_req_is_write;
    logic [DRAM_ADDR_WIDTH-1:0]  dram_req_addr;
    logic [15:0]                 dram_req_bytes;
    logic                        dram_rvalid;
    logic                        dram_rready;
    logic [DRAM_DATA_WIDTH-1:0]  dram_rdata;
    logic                        dram_rlast;
    logic                        dram_wvalid;
    logic                        dram_wready;
    logic [DRAM_DATA_WIDTH-1:0]  dram_wdata;
    logic                        dram_wlast;
    logic                        dram_bvalid;
    logic                        dram_bready;

    logic [SRAM_BANKS-1:0]                      sram_wen;
    logic [SRAM_BANKS-1:0]                      sram_ren;
    logic [SRAM_BANKS-1:0][BANK_ADDR_WIDTH-1:0] sram_addr;
    logic [SRAM_BANKS-1:0][SRAM_DATA_WIDTH-1:0] sram_wdata;
    logic [SRAM_BANKS-1:0][SRAM_DATA_WIDTH-1:0] sram_rdata;

    logic                       tile_valid;
    logic                       tile_ready;
    logic                       tile_done;
    logic [SRAM_ADDR_WIDTH-1:0] tile_sram_addr_a;
    logic [SRAM_ADDR_WIDTH-1:0] tile_sram_addr_b;
    logic [SRAM_ADDR_WIDTH-1:0] tile_sram_addr_c;
    logic [12:0]                tile_m_dim;
    logic [12:0]                tile_n_dim;
    logic [12:0]                tile_k_dim;

    logic                       compute_sram_req_valid;
    logic                       compute_sram_req_ready;
    logic                       compute_sram_req_wen;
    logic [SRAM_ADDR_WIDTH-1:0] compute_sram_req_addr;
    logic [SRAM_DATA_WIDTH-1:0] compute_sram_req_wdata;
    logic [SRAM_DATA_WIDTH-1:0] compute_sram_req_rdata;
    logic                       compute_sram_req_rdata_valid;

    logic        done;
    logic        error;
    logic [31:0] perf_cycle_count;
    logic [31:0] perf_dram_read_beats;
    logic [31:0] perf_dram_write_beats;
    logic [15:0] perf_tile_count;
    logic [31:0] perf_idle_cycles;

    int error_count;
    int tile_accept_count;
    int tile_done_count;

    // DRAM model storage (128-bit beat addressed)
    logic [DRAM_DATA_WIDTH-1:0] dram_model [0:8191];
    logic [31:0] dram_read_addr;
    int dram_read_beat_count;
    int dram_read_total_beats;
    logic [31:0] dram_write_addr;
    int dram_write_beat_count;

    // SRAM bank model: 8 banks x 2048 x 32-bit
    logic [SRAM_DATA_WIDTH-1:0] sram_memory [0:SRAM_BANKS-1][0:SRAM_BANK_DEPTH-1];

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

    initial begin
        clk = 1'b0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    // -------------------------------------------------------------------------
    // SRAM bank model (registered read/write)
    // -------------------------------------------------------------------------
    genvar g;
    generate
        for (g = 0; g < SRAM_BANKS; g++) begin : gen_sram_banks
            always_ff @(posedge clk) begin
                if (sram_wen[g]) begin
                    sram_memory[g][sram_addr[g]] <= sram_wdata[g];
                end

                if (sram_ren[g]) begin
                    sram_rdata[g] <= sram_memory[g][sram_addr[g]];
                end else begin
                    sram_rdata[g] <= '0;
                end
            end
        end
    endgenerate

    // -------------------------------------------------------------------------
    // DRAM model (AXI-like ready/valid pattern)
    // -------------------------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            dram_rvalid <= 1'b0;
            dram_rlast <= 1'b0;
            dram_read_beat_count <= 0;
            dram_read_total_beats <= 0;
            dram_read_addr <= 32'h0;
        end else begin
            if (dram_req_valid && dram_req_ready && !dram_req_is_write) begin
                dram_read_beat_count <= 0;
                dram_read_total_beats <= (dram_req_bytes + 15) / 16;
                dram_read_addr <= dram_req_addr;
                dram_rvalid <= 1'b1;
                dram_rlast <= 1'b0;
            end else if (dram_rvalid && dram_rready) begin
                dram_read_beat_count <= dram_read_beat_count + 1;

                if (dram_read_beat_count + 1 >= dram_read_total_beats) begin
                    dram_rvalid <= 1'b0;
                    dram_rlast <= 1'b1;
                end else begin
                    dram_rvalid <= 1'b1;
                    dram_rlast <= 1'b0;
                end
            end else if (dram_rlast) begin
                dram_rlast <= 1'b0;
            end
        end
    end

    always_comb begin
        dram_rdata = dram_model[(dram_read_addr >> 4) + dram_read_beat_count];
    end

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            dram_write_beat_count <= 0;
            dram_write_addr <= 32'h0;
            dram_bvalid <= 1'b0;
        end else begin
            if (dram_req_valid && dram_req_ready && dram_req_is_write) begin
                dram_write_beat_count <= 0;
                dram_write_addr <= dram_req_addr;
            end

            if (dram_wvalid && dram_wready) begin
                dram_model[(dram_write_addr >> 4) + dram_write_beat_count] <= dram_wdata;
                dram_write_beat_count <= dram_write_beat_count + 1;
            end

            if (dram_wvalid && dram_wready && dram_wlast) begin
                dram_bvalid <= 1'b1;
            end else if (dram_bready) begin
                dram_bvalid <= 1'b0;
            end
        end
    end

    assign dram_req_ready = 1'b1;
    assign dram_wready = 1'b1;

    // -------------------------------------------------------------------------
    // Helper tasks
    // -------------------------------------------------------------------------
    task automatic write_cfg(input logic [7:0] addr_i, input logic [31:0] data_i);
        begin
            @(posedge clk); #1;
            cfg_addr = addr_i;
            cfg_wdata = data_i;
            cfg_wen = 1'b1;
            cfg_ren = 1'b0;
            @(posedge clk); #1;
            cfg_wen = 1'b0;
        end
    endtask

    task automatic read_cfg(input logic [7:0] addr_i, output logic [31:0] data_o);
        begin
            @(posedge clk); #1;
            cfg_addr = addr_i;
            cfg_ren = 1'b1;
            cfg_wen = 1'b0;
            @(posedge clk); #1;
            cfg_ren = 1'b0;
            @(posedge clk); #1;
            data_o = cfg_rdata;
        end
    endtask

    task automatic program_gemm_config();
        begin
            write_cfg(ADDR_MATRIX_M, 32'd1);
            write_cfg(ADDR_MATRIX_N, 32'd128);
            write_cfg(ADDR_MATRIX_K, 32'd128);
            // Split packed tile write into TWO registers:
            // ADDR_TILE_DIM (0x14):   {6'h0, tile_n[12:0], tile_m[12:0]}
            // ADDR_TILE_K_MODE (0x58): {17'h0, mode[1:0], tile_k[12:0]}
            // tile_m=1 (must divide M=1), tile_n=32, tile_k=32
            write_cfg(ADDR_TILE_DIM,     {6'h0, 13'd32, 13'd1});  // tile_n=32, tile_m=1
            write_cfg(ADDR_TILE_K_MODE,  {17'h0, 2'b00, 13'd32}); // tile_k=32, mode=single buffer
            write_cfg(ADDR_BUF_MODE,  32'h0000_0000); // single buffer

            write_cfg(ADDR_DRAM_BASE_A, 32'h0000_1000);
            write_cfg(ADDR_DRAM_BASE_B, 32'h0000_4000);
            write_cfg(ADDR_DRAM_BASE_C, 32'h0000_8000);

            write_cfg(ADDR_SRAM_A_PING, 32'h0000_0000);
            write_cfg(ADDR_SRAM_A_PONG, 32'h0000_0800);
            write_cfg(ADDR_SRAM_B_PING, 32'h0000_1000);
            write_cfg(ADDR_SRAM_B_PONG, 32'h0000_1800);
            write_cfg(ADDR_SRAM_C,      32'h0000_2000);
        end
    endtask

    task automatic start_controller();
        begin
            write_cfg(ADDR_CTRL, 32'h0000_0001);
        end
    endtask

    task automatic wait_status_done_with_timeout(input int max_cycles, output logic [31:0] status_out);
        int cyc;
        logic [31:0] status_local;
        logic done_seen;
        begin
            cyc = 0;
            status_local = 32'h0;
            done_seen = 1'b0;
            while ((cyc < max_cycles) && !done_seen) begin
                read_cfg(ADDR_STATUS, status_local);
                if (status_local[1]) begin
                    done_seen = 1'b1;
                end else begin
                    @(posedge clk); #1;
                    cyc = cyc + 1;
                end
            end

            status_out = status_local;
            if (!done_seen) begin
                error_count = error_count + 1;
                $display("LOG: %0t : ERROR : tb_gemm_traffic : timeout_wait_done : status=0x%08h", $time, status_local);
            end
        end
    endtask

    task automatic clear_models_and_counters();
        begin
            for (int i = 0; i < 8192; i++) begin
                dram_model[i] = '0;
            end

            for (int b = 0; b < SRAM_BANKS; b++) begin
                for (int j = 0; j < SRAM_BANK_DEPTH; j++) begin
                    sram_memory[b][j] = '0;
                end
            end

            tile_accept_count = 0;
            tile_done_count = 0;
        end
    endtask

    task automatic preload_dram_patterns();
        int base_a_idx;
        int base_b_idx;
        int i;
        begin
            base_a_idx = 32'h0000_1000 >> 4;
            base_b_idx = 32'h0000_4000 >> 4;

            // Activation traffic: MxK = 1x128 INT8 = 128B -> 8 beats (over-provisioned)
            for (i = 0; i < 64; i++) begin
                dram_model[base_a_idx + i] = {
                    8'(i*16 + 15), 8'(i*16 + 14), 8'(i*16 + 13), 8'(i*16 + 12),
                    8'(i*16 + 11), 8'(i*16 + 10), 8'(i*16 + 9),  8'(i*16 + 8),
                    8'(i*16 + 7),  8'(i*16 + 6),  8'(i*16 + 5),  8'(i*16 + 4),
                    8'(i*16 + 3),  8'(i*16 + 2),  8'(i*16 + 1),  8'(i*16 + 0)
                };
            end

            // Weight traffic: KxN = 128x128 INT8 = 16384B -> 1024 beats (padded preload window)
            for (i = 0; i < 4096; i++) begin
                dram_model[base_b_idx + i] = {
                    8'(8'h80 + i*16 + 15), 8'(8'h80 + i*16 + 14), 8'(8'h80 + i*16 + 13), 8'(8'h80 + i*16 + 12),
                    8'(8'h80 + i*16 + 11), 8'(8'h80 + i*16 + 10), 8'(8'h80 + i*16 + 9),  8'(8'h80 + i*16 + 8),
                    8'(8'h80 + i*16 + 7),  8'(8'h80 + i*16 + 6),  8'(8'h80 + i*16 + 5),  8'(8'h80 + i*16 + 4),
                    8'(8'h80 + i*16 + 3),  8'(8'h80 + i*16 + 2),  8'(8'h80 + i*16 + 1),  8'(8'h80 + i*16 + 0)
                };
            end
        end
    endtask

    task automatic reset_dut();
        begin
            rst_n = 1'b0;
            cfg_addr = 8'h00;
            cfg_wdata = 32'h0;
            cfg_wen = 1'b0;
            cfg_ren = 1'b0;

            compute_sram_req_valid = 1'b0;
            compute_sram_req_wen = 1'b0;
            compute_sram_req_addr = '0;
            compute_sram_req_wdata = '0;
            tile_ready = 1'b0;
            tile_done = 1'b0;

            repeat (5) begin
                @(posedge clk); #1;
            end
            rst_n = 1'b1;
            repeat (2) begin
                @(posedge clk); #1;
            end
        end
    endtask

    // -------------------------------------------------------------------------
    // Compute engine mock process
    // -------------------------------------------------------------------------
    initial begin : compute_mock
        int ready_wait_cycles;
        forever begin
            @(posedge clk); #1;
            if (rst_n && tile_valid) begin
                tile_accept_count = tile_accept_count + 1;

                tile_ready = 1'b1;
                @(posedge clk); #1;
                tile_ready = 1'b0;

                // Minimal SRAM traffic to mirror integration TB behavior.
                compute_sram_req_valid = 1'b1;
                compute_sram_req_wen = 1'b0;
                compute_sram_req_addr = tile_sram_addr_a;
                compute_sram_req_wdata = 32'h0;
                ready_wait_cycles = 0;
                while ((compute_sram_req_ready == 1'b0) && (ready_wait_cycles < 200)) begin
                    @(posedge clk); #1;
                    ready_wait_cycles = ready_wait_cycles + 1;
                end
                @(posedge clk); #1;
                compute_sram_req_valid = 1'b0;

                repeat (2) begin
                    @(posedge clk); #1;
                end

                tile_done = 1'b1;
                tile_done_count = tile_done_count + 1;
                @(posedge clk); #1;
                tile_done = 1'b0;
            end
        end
    end

    // -------------------------------------------------------------------------
    // Main sequence
    // -------------------------------------------------------------------------
    initial begin
        logic [31:0] cfg_status;

        error_count = 0;

        $display("TEST START: tb_gemm_traffic");

        clear_models_and_counters();
        reset_dut();
        preload_dram_patterns();

        // attn_q_proj_sim cross-validation dimensions
        // M=1, N=128, K=128 with tm=1, tn=32, tk=32, single buffer
        program_gemm_config();
        start_controller();
        wait_status_done_with_timeout(200000, cfg_status);

        if (!cfg_status[1]) begin
            error_count = error_count + 1;
            $display("LOG: %0t : ERROR : tb_gemm_traffic : done_not_seen_in_status : status=0x%08h", $time, cfg_status);
        end

        if (perf_tile_count != 16'(EXPECTED_TILES)) begin
            error_count = error_count + 1;
            $display("LOG: %0t : ERROR : tb_gemm_traffic : tile_count_mismatch : expected=%0d actual=%0d",
                $time, EXPECTED_TILES, perf_tile_count);
        end

        $display("PERF: gemm=attn_q_proj_sim cycles=%0d dram_reads=%0d dram_writes=%0d tiles=%0d",
            perf_cycle_count, perf_dram_read_beats, perf_dram_write_beats, perf_tile_count);
        $display("PERF: gemm=attn_q_proj cycles=%0d dram_reads=%0d dram_writes=%0d tiles=%0d",
            perf_cycle_count, perf_dram_read_beats, perf_dram_write_beats, perf_tile_count);

        if (tile_accept_count != EXPECTED_TILES || tile_done_count != EXPECTED_TILES) begin
            error_count = error_count + 1;
            $display("LOG: %0t : ERROR : tb_gemm_traffic : mock_tile_handshake_mismatch : expected=%0d accept=%0d done=%0d",
                $time, EXPECTED_TILES, tile_accept_count, tile_done_count);
        end

        if (error_count == 0) begin
            $display("TEST PASSED");
        end else begin
            $display("TEST FAILED");
            $error("tb_gemm_traffic failed with %0d errors", error_count);
        end

        $finish;
    end

    initial begin
        #2000000;
        $fatal(1, "tb_gemm_traffic timeout");
    end

    initial begin
        $dumpfile("tb_gemm_traffic.fst");
        $dumpvars(0);
    end

endmodule
