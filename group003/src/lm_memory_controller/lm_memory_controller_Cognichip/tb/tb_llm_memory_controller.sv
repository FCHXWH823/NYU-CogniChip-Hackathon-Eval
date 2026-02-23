// =============================================================================
// Testbench: tb_llm_memory_controller
// Description: Top-level integration testbench for full controller datapath
// =============================================================================

`timescale 1ns/1ps

module tb_llm_memory_controller;

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

    // Config addresses
    localparam logic [7:0] ADDR_CTRL         = 8'h00;
    localparam logic [7:0] ADDR_STATUS       = 8'h04;
    localparam logic [7:0] ADDR_MATRIX_M     = 8'h08;
    localparam logic [7:0] ADDR_MATRIX_N     = 8'h0C;
    localparam logic [7:0] ADDR_MATRIX_K     = 8'h10;
    localparam logic [7:0] ADDR_TILE_DIM     = 8'h14;
    localparam logic [7:0] ADDR_BUF_MODE     = 8'h18;
    localparam logic [7:0] ADDR_DRAM_BASE_A  = 8'h1C;
    localparam logic [7:0] ADDR_DRAM_BASE_B  = 8'h20;
    localparam logic [7:0] ADDR_DRAM_BASE_C  = 8'h24;
    localparam logic [7:0] ADDR_SRAM_A_PING  = 8'h28;
    localparam logic [7:0] ADDR_SRAM_A_PONG  = 8'h2C;
    localparam logic [7:0] ADDR_SRAM_B_PING  = 8'h30;
    localparam logic [7:0] ADDR_SRAM_B_PONG  = 8'h34;
    localparam logic [7:0] ADDR_SRAM_C       = 8'h38;
    localparam logic [7:0] ADDR_TILE_K_MODE  = 8'h58;

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

    logic [SRAM_BANKS-1:0]                               sram_wen;
    logic [SRAM_BANKS-1:0]                               sram_ren;
    logic [SRAM_BANKS-1:0][BANK_ADDR_WIDTH-1:0]          sram_addr;
    logic [SRAM_BANKS-1:0][SRAM_DATA_WIDTH-1:0]          sram_wdata;
    logic [SRAM_BANKS-1:0][SRAM_DATA_WIDTH-1:0]          sram_rdata;

    logic                        tile_valid;
    logic                        tile_ready;
    logic                        tile_done;
    logic [SRAM_ADDR_WIDTH-1:0]  tile_sram_addr_a;
    logic [SRAM_ADDR_WIDTH-1:0]  tile_sram_addr_b;
    logic [SRAM_ADDR_WIDTH-1:0]  tile_sram_addr_c;
    logic [12:0]                 tile_m_dim;
    logic [12:0]                 tile_n_dim;
    logic [12:0]                 tile_k_dim;

    logic                        compute_sram_req_valid;
    logic                        compute_sram_req_ready;
    logic                        compute_sram_req_wen;
    logic [SRAM_ADDR_WIDTH-1:0]  compute_sram_req_addr;
    logic [SRAM_DATA_WIDTH-1:0]  compute_sram_req_wdata;
    logic [SRAM_DATA_WIDTH-1:0]  compute_sram_req_rdata;
    logic                        compute_sram_req_rdata_valid;

    logic                        done;
    logic                        error;
    logic [31:0]                 perf_cycle_count;
    logic [31:0]                 perf_dram_read_beats;
    logic [31:0]                 perf_dram_write_beats;
    logic [15:0]                 perf_tile_count;
    logic [31:0]                 perf_idle_cycles;

    int error_count;
    int test_count;
    int tile_accept_count;
    int tile_done_count;
    int compute_read_count;
    int compute_write_count;

    logic [31:0] last_a_word;
    logic [31:0] last_b_word;

    // DRAM model storage (128b beat addressed)
    logic [DRAM_DATA_WIDTH-1:0] dram_model [0:4095];
    logic [31:0] dram_read_addr;
    int dram_read_beat_count;
    int dram_read_total_beats;
    logic [31:0] dram_write_addr;
    int dram_write_beat_count;

    // Write capture for verification
    logic [127:0] dram_write_capture [0:127];
    logic [31:0]  dram_write_capture_addr [0:127];
    int dram_write_capture_count;

    // SRAM bank model: 8 banks x 2048 x 32b
    logic [SRAM_DATA_WIDTH-1:0] sram_memory [0:SRAM_BANKS-1][0:SRAM_BANK_DEPTH-1];

    // Compute mock controls
    logic compute_mock_enable;
    int   compute_delay_cycles;
    int   compute_tile_index;

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
            dram_write_capture_count <= 0;
        end else begin
            if (dram_req_valid && dram_req_ready && dram_req_is_write) begin
                dram_write_beat_count <= 0;
                dram_write_addr <= dram_req_addr;
            end

            if (dram_wvalid && dram_wready) begin
                dram_model[(dram_write_addr >> 4) + dram_write_beat_count] <= dram_wdata;
                dram_write_capture[dram_write_capture_count] <= dram_wdata;
                dram_write_capture_addr[dram_write_capture_count] <= dram_write_addr + (dram_write_beat_count * 16);
                dram_write_capture_count <= dram_write_capture_count + 1;
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

    task automatic program_config(
        input logic [15:0] m,
        input logic [15:0] n,
        input logic [15:0] k,
        input logic [12:0] tm,
        input logic [12:0] tn,
        input logic [12:0] tk,
        input logic [31:0] base_a,
        input logic [31:0] base_b,
        input logic [31:0] base_c
    );
        begin
            write_cfg(ADDR_MATRIX_M, {16'h0000, m});
            write_cfg(ADDR_MATRIX_N, {16'h0000, n});
            write_cfg(ADDR_MATRIX_K, {16'h0000, k});
            // Split tile dimensions into two registers:
            // ADDR_TILE_DIM (0x14): {6'h0, tile_n[12:0], tile_m[12:0]}
            // ADDR_TILE_K_MODE (0x58): {17'h0, mode[1:0], tile_k[12:0]}
            write_cfg(ADDR_TILE_DIM,    {6'h0, tn, tm});
            write_cfg(ADDR_TILE_K_MODE, {17'h0, 2'b00, tk});
            write_cfg(ADDR_BUF_MODE, 32'h0000_0000);
            write_cfg(ADDR_DRAM_BASE_A, base_a);
            write_cfg(ADDR_DRAM_BASE_B, base_b);
            write_cfg(ADDR_DRAM_BASE_C, base_c);
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

    task automatic wait_done_with_timeout(input int max_cycles, input string tag);
        int cyc;
        begin
            cyc = 0;
            while ((done == 1'b0) && (cyc < max_cycles)) begin
                @(posedge clk); #1;
                cyc = cyc + 1;
            end
            if (done != 1'b1) begin
                error_count = error_count + 1;
                $display("LOG: %0t : ERROR : tb_llm_mem_ctrl : %s_timeout : done not asserted", $time, tag);
            end
        end
    endtask

    task automatic compute_read_word(input logic [SRAM_ADDR_WIDTH-1:0] addr_i, output logic [31:0] data_o);
        int cyc;
        begin
            @(posedge clk); #1;
            compute_sram_req_valid = 1'b1;
            compute_sram_req_wen = 1'b0;
            compute_sram_req_addr = addr_i;
            compute_sram_req_wdata = 32'h0;

            cyc = 0;
            while ((compute_sram_req_ready == 1'b0) && (cyc < 1000)) begin
                @(posedge clk); #1;
                cyc = cyc + 1;
            end

            @(posedge clk); #1;
            compute_sram_req_valid = 1'b0;

            cyc = 0;
            while ((compute_sram_req_rdata_valid == 1'b0) && (cyc < 1000)) begin
                @(posedge clk); #1;
                cyc = cyc + 1;
            end
            data_o = compute_sram_req_rdata;
            compute_read_count = compute_read_count + 1;
        end
    endtask

    task automatic compute_write_word(input logic [SRAM_ADDR_WIDTH-1:0] addr_i, input logic [31:0] data_i);
        int cyc;
        begin
            @(posedge clk); #1;
            compute_sram_req_valid = 1'b1;
            compute_sram_req_wen = 1'b1;
            compute_sram_req_addr = addr_i;
            compute_sram_req_wdata = data_i;

            cyc = 0;
            while ((compute_sram_req_ready == 1'b0) && (cyc < 1000)) begin
                @(posedge clk); #1;
                cyc = cyc + 1;
            end

            @(posedge clk); #1;
            compute_sram_req_valid = 1'b0;
            compute_sram_req_wen = 1'b0;
            compute_write_count = compute_write_count + 1;
        end
    endtask

    task automatic clear_models_and_counters();
        begin
            for (int i = 0; i < 4096; i++) begin
                dram_model[i] = '0;
            end

            for (int b = 0; b < SRAM_BANKS; b++) begin
                for (int j = 0; j < SRAM_BANK_DEPTH; j++) begin
                    sram_memory[b][j] = '0;
                end
            end

            tile_accept_count = 0;
            tile_done_count = 0;
            compute_read_count = 0;
            compute_write_count = 0;
            compute_tile_index = 0;
            last_a_word = 32'h0;
            last_b_word = 32'h0;
            dram_write_capture_count = 0;
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
        logic [31:0] read_word;
        int words_a;
        int words_b;
        int words_c;

        forever begin
            @(posedge clk); #1;
            if (rst_n && compute_mock_enable && tile_valid) begin
                tile_accept_count = tile_accept_count + 1;

                tile_ready = 1'b1;
                @(posedge clk); #1;
                tile_ready = 1'b0;

                for (int d = 0; d < compute_delay_cycles; d++) begin
                    @(posedge clk); #1;
                end

                words_a = (tile_m_dim * tile_k_dim + 3) / 4;
                words_b = (tile_k_dim * tile_n_dim + 3) / 4;
                words_c = (tile_m_dim * tile_n_dim);

                if (words_a > 0) begin
                    compute_read_word(tile_sram_addr_a, read_word);
                    last_a_word = read_word;
                end
                if (words_b > 0) begin
                    compute_read_word(tile_sram_addr_b, read_word);
                    last_b_word = read_word;
                end

                for (int w = 0; w < words_c; w++) begin
                    compute_write_word(tile_sram_addr_c + w[SRAM_ADDR_WIDTH-1:0],
                        32'hC000_0000 | (compute_tile_index[7:0] << 8) | w[7:0]);
                end

                tile_done = 1'b1;
                tile_done_count = tile_done_count + 1;
                @(posedge clk); #1;
                tile_done = 1'b0;

                compute_tile_index = compute_tile_index + 1;
            end
        end
    end

    // -------------------------------------------------------------------------
    // Main test sequence
    // -------------------------------------------------------------------------
    initial begin
        logic [31:0] cfg_status;
        logic [127:0] expected_write_beat0;

        error_count = 0;
        test_count = 0;
        compute_mock_enable = 1'b1;
        compute_delay_cycles = 4;

        $display("TEST START");
        $display("=============================================================================");
        $display("LLM Memory Controller Integration Testbench");
        $display("=============================================================================");

        clear_models_and_counters();
        reset_dut();

        // ---------------------------------------------------------------------
        // Test 1: Single Tile Fetch
        // ---------------------------------------------------------------------
        $display("\n--- Test 1: Single Tile Fetch ---");
        test_count = test_count + 1;

        clear_models_and_counters();
        reset_dut();

        // Preload DRAM A/B patterns (A base=0x100, B base=0x200)
        dram_model[32'h0000_0100 >> 4] = {32'h0102_0304, 32'h1112_1314, 32'h2122_2324, 32'h3132_3334};
        dram_model[32'h0000_0200 >> 4] = {32'h1020_3040, 32'h5060_7080, 32'h90A0_B0C0, 32'hD0E0_F000};

        program_config(16'd4, 16'd4, 16'd4, 13'd4, 13'd4, 13'd4, 32'h0000_0100, 32'h0000_0200, 32'h0000_0300);
        start_controller();
        wait_done_with_timeout(4000, "test1");

        if (tile_accept_count != 1 || tile_done_count != 1) begin
            error_count = error_count + 1;
            $display("LOG: %0t : ERROR : tb_llm_mem_ctrl : test1_tile_count : expected=1 actual_accept=%0d actual_done=%0d",
                $time, tile_accept_count, tile_done_count);
        end

        if (last_a_word !== 32'h3132_3334) begin
            error_count = error_count + 1;
            $display("LOG: %0t : ERROR : tb_llm_mem_ctrl : test1_a_read : expected=0x31323334 actual=0x%08h", $time, last_a_word);
        end
        if (last_b_word !== 32'hD0E0_F000) begin
            error_count = error_count + 1;
            $display("LOG: %0t : ERROR : tb_llm_mem_ctrl : test1_b_read : expected=0xD0E0F000 actual=0x%08h", $time, last_b_word);
        end
        if (done != 1'b1 || error != 1'b0) begin
            error_count = error_count + 1;
            $display("LOG: %0t : ERROR : tb_llm_mem_ctrl : test1_done_error : done=%0b error=%0b", $time, done, error);
        end

        // ---------------------------------------------------------------------
        // Test 2: Multi-Tile Sequence (8x8x4 with 4x4x4 => 4 tiles)
        // ---------------------------------------------------------------------
        $display("\n--- Test 2: Multi-Tile Sequence ---");
        test_count = test_count + 1;

        clear_models_and_counters();
        reset_dut();

        for (int i = 0; i < 16; i++) begin
            dram_model[(32'h0000_0400 >> 4) + i] = {32'hA000_0000 | i, 32'hA100_0000 | i, 32'hA200_0000 | i, 32'hA300_0000 | i};
            dram_model[(32'h0000_0800 >> 4) + i] = {32'hB000_0000 | i, 32'hB100_0000 | i, 32'hB200_0000 | i, 32'hB300_0000 | i};
        end

        program_config(16'd8, 16'd8, 16'd4, 13'd4, 13'd4, 13'd4, 32'h0000_0400, 32'h0000_0800, 32'h0000_0C00);
        start_controller();
        wait_done_with_timeout(12000, "test2");

        if (tile_accept_count != 4 || tile_done_count != 4) begin
            error_count = error_count + 1;
            $display("LOG: %0t : ERROR : tb_llm_mem_ctrl : test2_tile_count : expected=4 actual_accept=%0d actual_done=%0d",
                $time, tile_accept_count, tile_done_count);
        end else begin
            $display("LOG: %0t : INFO : tb_llm_mem_ctrl : test2_tile_count : expected=4 actual=4", $time);
        end

        // ---------------------------------------------------------------------
        // Test 3: Performance Counter Readback/Check
        // ---------------------------------------------------------------------
        $display("\n--- Test 3: Performance Counter Readback ---");
        test_count = test_count + 1;

        read_cfg(ADDR_STATUS, cfg_status);
        $display("LOG: %0t : INFO : tb_llm_mem_ctrl : test3_status_read : cfg_status=0x%08h", $time, cfg_status);
        $display("LOG: %0t : INFO : tb_llm_mem_ctrl : test3_perf : cycle_count=%0d dram_read_beats=%0d dram_write_beats=%0d tile_count=%0d idle_cycles=%0d",
            $time, perf_cycle_count, perf_dram_read_beats, perf_dram_write_beats, perf_tile_count, perf_idle_cycles);

        if (perf_cycle_count == 0) begin
            error_count = error_count + 1;
            $display("LOG: %0t : ERROR : tb_llm_mem_ctrl : test3_cycle_count : expected>0 actual=%0d", $time, perf_cycle_count);
        end
        if (perf_dram_read_beats == 0) begin
            error_count = error_count + 1;
            $display("LOG: %0t : ERROR : tb_llm_mem_ctrl : test3_dram_reads : expected>0 actual=%0d", $time, perf_dram_read_beats);
        end
        if (perf_tile_count != 16'd4) begin
            error_count = error_count + 1;
            $display("LOG: %0t : ERROR : tb_llm_mem_ctrl : test3_tile_count : expected=4 actual=%0d", $time, perf_tile_count);
        end

        // ---------------------------------------------------------------------
        // Test 4: Writeback Path
        // ---------------------------------------------------------------------
        $display("\n--- Test 4: Writeback Path ---");
        test_count = test_count + 1;

        clear_models_and_counters();
        reset_dut();

        dram_model[32'h0000_1100 >> 4] = {32'h0101_0101, 32'h0202_0202, 32'h0303_0303, 32'h0404_0404};
        dram_model[32'h0000_1200 >> 4] = {32'h1111_1111, 32'h2222_2222, 32'h3333_3333, 32'h4444_4444};

        program_config(16'd4, 16'd4, 16'd4, 13'd4, 13'd4, 13'd4, 32'h0000_1100, 32'h0000_1200, 32'h0000_1300);
        start_controller();
        wait_done_with_timeout(6000, "test4");

        expected_write_beat0 = {32'hC000_0003, 32'hC000_0002, 32'hC000_0001, 32'hC000_0000};
        if (dram_write_capture_count < 1) begin
            error_count = error_count + 1;
            $display("LOG: %0t : ERROR : tb_llm_mem_ctrl : test4_write_capture : no DRAM write beats captured", $time);
        end else if (dram_write_capture[0] !== expected_write_beat0) begin
            error_count = error_count + 1;
            $display("LOG: %0t : ERROR : tb_llm_mem_ctrl : test4_write_data : expected=0x%032h actual=0x%032h",
                $time, expected_write_beat0, dram_write_capture[0]);
        end else begin
            $display("LOG: %0t : INFO : tb_llm_mem_ctrl : test4_write_data : first DRAM beat matches expected", $time);
        end

        // ---------------------------------------------------------------------
        // Summary
        // ---------------------------------------------------------------------
        $display("\n=============================================================================");
        $display("Test Summary:");
        $display("  Total Tests: %0d", test_count);
        $display("  Errors: %0d", error_count);
        $display("=============================================================================");

        if (error_count == 0) begin
            $display("TEST PASSED");
        end else begin
            $display("TEST FAILED");
            $error("TEST FAILED with %0d errors", error_count);
        end

        $finish;
    end

    initial begin
        #1000000;
        $display("\n=============================================================================");
        $display("ERROR: Test timeout");
        $display("=============================================================================");
        $fatal(1, "Test timeout");
    end

    initial begin
        $dumpfile("dumpfile.fst");
        $dumpvars(0);
    end

endmodule
