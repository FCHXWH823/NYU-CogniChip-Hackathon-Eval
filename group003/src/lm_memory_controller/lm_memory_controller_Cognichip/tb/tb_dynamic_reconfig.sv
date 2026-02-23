module tb_dynamic_reconfig;

    localparam int CLK_PERIOD = 10;

    localparam logic [7:0] ADDR_CTRL             = 8'h00;
    localparam logic [7:0] ADDR_STATUS           = 8'h04;
    localparam logic [7:0] ADDR_MATRIX_M         = 8'h08;
    localparam logic [7:0] ADDR_MATRIX_N         = 8'h0C;
    localparam logic [7:0] ADDR_MATRIX_K         = 8'h10;
    localparam logic [7:0] ADDR_TILE_DIM         = 8'h14;
    localparam logic [7:0] ADDR_SRAM_A_PING      = 8'h28;
    localparam logic [7:0] ADDR_SRAM_A_PONG      = 8'h2C;
    localparam logic [7:0] ADDR_SRAM_B_PING      = 8'h30;
    localparam logic [7:0] ADDR_SRAM_B_PONG      = 8'h34;
    localparam logic [7:0] ADDR_SRAM_C           = 8'h38;

    localparam logic [7:0] ADDR_P0_TILING        = 8'h60;
    localparam logic [7:0] ADDR_P0_SRAM_AB       = 8'h64;
    localparam logic [7:0] ADDR_P0_SRAM_BC       = 8'h68;
    localparam logic [7:0] ADDR_P0_SRAM_BP       = 8'h6C;
    localparam logic [7:0] ADDR_P1_TILING        = 8'h70;
    localparam logic [7:0] ADDR_P1_SRAM_AB       = 8'h74;
    localparam logic [7:0] ADDR_P1_SRAM_BC       = 8'h78;
    localparam logic [7:0] ADDR_P1_SRAM_BP       = 8'h7C;
    localparam logic [7:0] ADDR_P2_TILING        = 8'h80;
    localparam logic [7:0] ADDR_P2_SRAM_AB       = 8'h84;
    localparam logic [7:0] ADDR_P2_SRAM_BC       = 8'h88;
    localparam logic [7:0] ADDR_P2_SRAM_BP       = 8'h8C;
    localparam logic [7:0] ADDR_P3_TILING        = 8'h90;
    localparam logic [7:0] ADDR_P3_SRAM_AB       = 8'h94;
    localparam logic [7:0] ADDR_P3_SRAM_BC       = 8'h98;
    localparam logic [7:0] ADDR_P3_SRAM_BP       = 8'h9C;

    localparam logic [7:0] ADDR_RECFG_SEL        = 8'hA0;
    localparam logic [7:0] ADDR_RECFG_ENABLE     = 8'hA4;
    localparam logic [7:0] ADDR_RECFG_COUNT      = 8'hA8;

    // Preset 0: tile_m=8, tile_n=64, tile_k=32, mode=3
    localparam logic [31:0] P0_TILING_MN         = {6'h0, 13'd64, 13'd8};   // tn=64, tm=8
    localparam logic [31:0] P0_TILING_K          = {17'h0, 2'b11, 13'd32};  // mode=3, tk=32
    // Preset 1: tile_m=32, tile_n=32, tile_k=16, mode=1
    localparam logic [31:0] P1_TILING_MN         = {6'h0, 13'd32, 13'd32};  // tn=32, tm=32
    localparam logic [31:0] P1_TILING_K          = {17'h0, 2'b01, 13'd16};  // mode=1, tk=16
    // Preset 2: tile_m=16, tile_n=64, tile_k=32, mode=2
    localparam logic [31:0] P2_TILING_MN         = {6'h0, 13'd64, 13'd16};  // tn=64, tm=16
    localparam logic [31:0] P2_TILING_K          = {17'h0, 2'b10, 13'd32};  // mode=2, tk=32
    // Preset 3: tile_m=64, tile_n=16, tile_k=32, mode=0
    localparam logic [31:0] P3_TILING_MN         = {6'h0, 13'd16, 13'd64};  // tn=16, tm=64
    localparam logic [31:0] P3_TILING_K          = {17'h0, 2'b00, 13'd32};  // mode=0, tk=32

    localparam logic [31:0] P0_SRAM_AB           = 32'h0200_0000;
    localparam logic [31:0] P0_SRAM_BC           = 32'h0600_0400;
    localparam logic [31:0] P0_SRAM_BP           = 32'h0000_0800;
    localparam logic [31:0] P1_SRAM_AB           = 32'h0A00_0900;
    localparam logic [31:0] P1_SRAM_BC           = 32'h0C00_0B00;
    localparam logic [31:0] P1_SRAM_BP           = 32'h0000_0D00;
    localparam logic [31:0] P2_SRAM_AB           = 32'h1200_1100;
    localparam logic [31:0] P2_SRAM_BC           = 32'h1400_1300;
    localparam logic [31:0] P2_SRAM_BP           = 32'h0000_1500;
    localparam logic [31:0] P3_SRAM_AB           = 32'h1A00_1900;
    localparam logic [31:0] P3_SRAM_BC           = 32'h1C00_1B00;
    localparam logic [31:0] P3_SRAM_BP           = 32'h0000_1D00;

    logic        clk;
    logic        rst_n;
    logic [7:0]  addr;
    logic [31:0] wdata;
    logic        wen;
    logic        ren;
    logic [31:0] rdata;

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

    logic        reconfig_trigger;
    logic        busy;
    logic        done;
    logic        error_in;
    logic [31:0] perf_cycle_count;
    logic [31:0] perf_dram_read_beats;
    logic [31:0] perf_dram_write_beats;
    logic [15:0] perf_tile_count;
    logic [31:0] perf_idle_cycles;
    logic        error_out;

    int error_count = 0;
    int test_count = 0;
    int pass_count = 0;

    initial begin
        clk = 1'b0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end

    config_regs dut (
        .clk                  (clk),
        .rst_n                (rst_n),
        .addr                 (addr),
        .wdata                (wdata),
        .wen                  (wen),
        .ren                  (ren),
        .rdata                (rdata),
        .matrix_m             (matrix_m),
        .matrix_n             (matrix_n),
        .matrix_k             (matrix_k),
        .tile_m               (tile_m),
        .tile_n               (tile_n),
        .tile_k               (tile_k),
        .buffering_mode       (buffering_mode),
        .dram_base_a          (dram_base_a),
        .dram_base_b          (dram_base_b),
        .dram_base_c          (dram_base_c),
        .sram_base_a_ping     (sram_base_a_ping),
        .sram_base_a_pong     (sram_base_a_pong),
        .sram_base_b_ping     (sram_base_b_ping),
        .sram_base_b_pong     (sram_base_b_pong),
        .sram_base_c          (sram_base_c),
        .start                (start),
        .ctrl_reset           (ctrl_reset),
        .baseline_mode        (baseline_mode),
        .reconfig_trigger     (reconfig_trigger),
        .busy                 (busy),
        .done                 (done),
        .error_in             (error_in),
        .perf_cycle_count     (perf_cycle_count),
        .perf_dram_read_beats (perf_dram_read_beats),
        .perf_dram_write_beats(perf_dram_write_beats),
        .perf_tile_count      (perf_tile_count),
        .perf_idle_cycles     (perf_idle_cycles),
        .error_out            (error_out)
    );

    task automatic write_reg(input [7:0] reg_addr, input [31:0] data);
        begin
            @(posedge clk);
            #1;
            addr = reg_addr;
            wdata = data;
            wen = 1'b1;
            @(posedge clk);
            #1;
            wen = 1'b0;
            addr = 8'h00;
            wdata = 32'h0;
            @(posedge clk);
            #1;
        end
    endtask

    task automatic read_reg(input [7:0] reg_addr, output [31:0] data);
        begin
            @(posedge clk);
            #1;
            addr = reg_addr;
            ren = 1'b1;
            @(posedge clk);
            #1;
            ren = 1'b0;
            @(posedge clk);
            #1;
            data = rdata;
        end
    endtask

    task automatic read_check(input [7:0] reg_addr, input [31:0] expected, input string name);
        logic [31:0] actual;
        begin
            read_reg(reg_addr, actual);
            if (actual !== expected) begin
                error_count = error_count + 1;
                $display("[FAIL] %s: expected=%0h actual=%0h", name, expected, actual);
            end
        end
    endtask

    task automatic pulse_reconfig();
        begin
            @(posedge clk);
            #1;
            reconfig_trigger = 1'b1;
            @(posedge clk);
            #1;
            reconfig_trigger = 1'b0;
            @(posedge clk);
            #1;
        end
    endtask

    task automatic report_test(input string test_name, input int start_errors);
        int new_errors;
        begin
            test_count = test_count + 1;
            new_errors = error_count - start_errors;
            if (new_errors == 0) begin
                pass_count = pass_count + 1;
                $display("[PASS] %s", test_name);
            end else begin
                $display("[FAIL] %s: expected=%0h actual=%0h", test_name, 32'h0, new_errors[31:0]);
            end
        end
    endtask

    initial begin
        int start_errors;
        logic [31:0] before_tile;
        logic [31:0] after_tile;
        logic [31:0] read_data;

        rst_n = 1'b0;
        addr = 8'h00;
        wdata = 32'h0;
        wen = 1'b0;
        ren = 1'b0;
        reconfig_trigger = 1'b0;
        busy = 1'b0;
        done = 1'b0;
        error_in = 1'b0;
        perf_cycle_count = 32'h0;
        perf_dram_read_beats = 32'h0;
        perf_dram_write_beats = 32'h0;
        perf_tile_count = 16'h0;
        perf_idle_cycles = 32'h0;

        repeat (5) begin
            @(posedge clk);
            #1;
        end
        rst_n = 1'b1;
        repeat (2) begin
            @(posedge clk);
            #1;
        end

        // Test 1: Preset table write/read
        start_errors = error_count;
        write_reg(ADDR_P0_TILING, P0_TILING_MN);
        write_reg(ADDR_P0_SRAM_BP, {P0_TILING_K[14:0], P0_SRAM_BP[15:0]});
        write_reg(ADDR_P0_SRAM_AB, P0_SRAM_AB);
        write_reg(ADDR_P0_SRAM_BC, P0_SRAM_BC);
        write_reg(ADDR_P1_TILING, P1_TILING_MN);
        write_reg(ADDR_P1_SRAM_BP, {P1_TILING_K[14:0], P1_SRAM_BP[15:0]});
        write_reg(ADDR_P1_SRAM_AB, P1_SRAM_AB);
        write_reg(ADDR_P1_SRAM_BC, P1_SRAM_BC);
        write_reg(ADDR_P2_TILING, P2_TILING_MN);
        write_reg(ADDR_P2_SRAM_BP, {P2_TILING_K[14:0], P2_SRAM_BP[15:0]});
        write_reg(ADDR_P2_SRAM_AB, P2_SRAM_AB);
        write_reg(ADDR_P2_SRAM_BC, P2_SRAM_BC);
        write_reg(ADDR_P3_TILING, P3_TILING_MN);
        write_reg(ADDR_P3_SRAM_BP, {P3_TILING_K[14:0], P3_SRAM_BP[15:0]});
        write_reg(ADDR_P3_SRAM_AB, P3_SRAM_AB);
        write_reg(ADDR_P3_SRAM_BC, P3_SRAM_BC);

        read_check(ADDR_P0_TILING, P0_TILING_MN, "test1_p0_tiling");
        read_check(ADDR_P0_SRAM_BP, {P0_TILING_K[14:0], P0_SRAM_BP[15:0]}, "test1_p0_sram_bp");
        read_check(ADDR_P0_SRAM_AB, P0_SRAM_AB, "test1_p0_sram_ab");
        read_check(ADDR_P0_SRAM_BC, P0_SRAM_BC, "test1_p0_sram_bc");
        read_check(ADDR_P1_TILING, P1_TILING_MN, "test1_p1_tiling");
        read_check(ADDR_P1_SRAM_BP, {P1_TILING_K[14:0], P1_SRAM_BP[15:0]}, "test1_p1_sram_bp");
        read_check(ADDR_P1_SRAM_AB, P1_SRAM_AB, "test1_p1_sram_ab");
        read_check(ADDR_P1_SRAM_BC, P1_SRAM_BC, "test1_p1_sram_bc");
        read_check(ADDR_P2_TILING, P2_TILING_MN, "test1_p2_tiling");
        read_check(ADDR_P2_SRAM_BP, {P2_TILING_K[14:0], P2_SRAM_BP[15:0]}, "test1_p2_sram_bp");
        read_check(ADDR_P2_SRAM_AB, P2_SRAM_AB, "test1_p2_sram_ab");
        read_check(ADDR_P2_SRAM_BC, P2_SRAM_BC, "test1_p2_sram_bc");
        read_check(ADDR_P3_TILING, P3_TILING_MN, "test1_p3_tiling");
        read_check(ADDR_P3_SRAM_BP, {P3_TILING_K[14:0], P3_SRAM_BP[15:0]}, "test1_p3_sram_bp");
        read_check(ADDR_P3_SRAM_AB, P3_SRAM_AB, "test1_p3_sram_ab");
        read_check(ADDR_P3_SRAM_BC, P3_SRAM_BC, "test1_p3_sram_bc");
        report_test("test1_preset_table_write_read", start_errors);

        // Test 2: Single reconfiguration trigger
        start_errors = error_count;
        write_reg(ADDR_TILE_DIM, 32'h00_04_04_04);
        write_reg(ADDR_RECFG_SEL, 32'h0);
        write_reg(ADDR_RECFG_ENABLE, 32'h1);
        busy = 1'b0;

        pulse_reconfig();
        repeat (2) begin
            @(posedge clk);
            #1;
        end

        read_check(ADDR_TILE_DIM, P0_TILING_MN, "test2_tile_dim");
        read_check(ADDR_SRAM_A_PING, {16'h0, P0_SRAM_AB[15:0]}, "test2_sram_a_ping");
        read_check(ADDR_SRAM_A_PONG, {16'h0, P0_SRAM_AB[31:16]}, "test2_sram_a_pong");
        read_check(ADDR_SRAM_B_PING, {16'h0, P0_SRAM_BP[15:0]}, "test2_sram_b_ping");
        read_check(ADDR_SRAM_B_PONG, {16'h0, P0_SRAM_BC[15:0]}, "test2_sram_b_pong");
        read_check(ADDR_SRAM_C, {16'h0, P0_SRAM_BC[31:16]}, "test2_sram_c");
        read_check(ADDR_RECFG_COUNT, 32'h0000_0001, "test2_reconfig_count");
        read_check(ADDR_RECFG_SEL, 32'h0000_0001, "test2_reconfig_sel");
        report_test("test2_single_reconfiguration_trigger", start_errors);

        // Test 3: Sequential reconfiguration (4-layer cycle)
        start_errors = error_count;
        write_reg(ADDR_RECFG_SEL, 32'h0);
        write_reg(ADDR_RECFG_ENABLE, 32'h1);
        busy = 1'b0;

        pulse_reconfig();
        repeat (2) begin
            @(posedge clk);
            #1;
        end
        read_check(ADDR_TILE_DIM, P0_TILING_MN, "test3_trigger1_tile");
        read_check(ADDR_RECFG_SEL, 32'h0000_0001, "test3_trigger1_sel");

        pulse_reconfig();
        repeat (2) begin
            @(posedge clk);
            #1;
        end
        read_check(ADDR_TILE_DIM, P1_TILING_MN, "test3_trigger2_tile");
        read_check(ADDR_RECFG_SEL, 32'h0000_0002, "test3_trigger2_sel");

        pulse_reconfig();
        repeat (2) begin
            @(posedge clk);
            #1;
        end
        read_check(ADDR_TILE_DIM, P2_TILING_MN, "test3_trigger3_tile");
        read_check(ADDR_RECFG_SEL, 32'h0000_0003, "test3_trigger3_sel");

        pulse_reconfig();
        repeat (2) begin
            @(posedge clk);
            #1;
        end
        read_check(ADDR_TILE_DIM, P3_TILING_MN, "test3_trigger4_tile");
        read_check(ADDR_RECFG_SEL, 32'h0000_0000, "test3_trigger4_sel_wrap");
        read_check(ADDR_RECFG_COUNT, 32'h0000_0005, "test3_reconfig_count");
        report_test("test3_sequential_reconfiguration", start_errors);

        // Test 4: Guard conditions
        start_errors = error_count;
        write_reg(ADDR_RECFG_ENABLE, 32'h1);
        write_reg(ADDR_RECFG_SEL, 32'h2);
        read_reg(ADDR_TILE_DIM, before_tile);

        // Test 4A: busy=1 blocks reconfig trigger
        busy = 1'b1;
        pulse_reconfig();
        repeat (2) begin
            @(posedge clk);
            #1;
        end
        read_reg(ADDR_TILE_DIM, after_tile);
        if (after_tile !== before_tile) begin
            error_count = error_count + 1;
            $display("[FAIL] test4_busy_blocks_trigger: expected=%0h actual=%0h", before_tile, after_tile);
        end

        // Test 4B: reconfig_enable=0 blocks reconfig trigger
        busy = 1'b0;
        write_reg(ADDR_RECFG_ENABLE, 32'h0);
        read_reg(ADDR_TILE_DIM, before_tile);
        pulse_reconfig();
        repeat (2) begin
            @(posedge clk);
            #1;
        end
        read_reg(ADDR_TILE_DIM, after_tile);
        if (after_tile !== before_tile) begin
            error_count = error_count + 1;
            $display("[FAIL] test4_enable_blocks_trigger: expected=%0h actual=%0h", before_tile, after_tile);
        end

        // Test 4C: preset writes should work even when busy=1
        busy = 1'b1;
        write_reg(ADDR_P1_TILING, 32'h00_0A_AB_11);
        busy = 1'b0;
        read_check(ADDR_P1_TILING, 32'h00_0A_AB_11, "test4_preset_write_while_busy");
        report_test("test4_guard_conditions", start_errors);

        // Restore preset1 tiling for any debug reruns
        write_reg(ADDR_P1_TILING, P1_TILING_MN);
        write_reg(ADDR_P1_SRAM_BP, {P1_TILING_K[14:0], P1_SRAM_BP[15:0]});

        // Test 5: Backward compatibility
        start_errors = error_count;
        write_reg(ADDR_RECFG_ENABLE, 32'h0);
        busy = 1'b0;
        done = 1'b0;
        error_in = 1'b0;
        write_reg(ADDR_MATRIX_M, 32'h0000_0040);
        write_reg(ADDR_MATRIX_N, 32'h0000_0040);
        write_reg(ADDR_MATRIX_K, 32'h0000_0040);
        write_reg(ADDR_TILE_DIM, 32'h00_20_20_20);

        @(posedge clk);
        #1;
        addr = ADDR_CTRL;
        wdata = 32'h0000_0001;
        wen = 1'b1;
        @(posedge clk);
        #1;
        if (start !== 1'b1) begin
            error_count = error_count + 1;
            $display("[FAIL] test5_start_pulse_high: expected=%0h actual=%0h", 32'h1, {31'h0, start});
        end
        wen = 1'b0;
        addr = 8'h00;
        wdata = 32'h0;
        @(posedge clk);
        #1;
        if (start !== 1'b0) begin
            error_count = error_count + 1;
            $display("[FAIL] test5_start_self_clear: expected=%0h actual=%0h", 32'h0, {31'h0, start});
        end

        busy = 1'b1;
        done = 1'b0;
        read_check(ADDR_STATUS, 32'h0000_0001, "test5_status_busy");
        busy = 1'b0;
        done = 1'b1;
        read_check(ADDR_STATUS, 32'h0000_0002, "test5_status_done");
        error_in = 1'b1;
        @(posedge clk);
        #1;
        error_in = 1'b0;
        @(posedge clk);
        #1;
        read_reg(ADDR_STATUS, read_data);
        if (read_data[2] !== 1'b1) begin
            error_count = error_count + 1;
            $display("[FAIL] test5_status_error_bit: expected=%0h actual=%0h", 32'h1, {31'h0, read_data[2]});
        end

        report_test("test5_backward_compatibility", start_errors);

        $display("=== %0d/5 TESTS PASSED ===", pass_count);
        $finish;
    end

    initial begin
        #100000;
        $fatal(1, "Timeout in tb_dynamic_reconfig");
    end

endmodule
