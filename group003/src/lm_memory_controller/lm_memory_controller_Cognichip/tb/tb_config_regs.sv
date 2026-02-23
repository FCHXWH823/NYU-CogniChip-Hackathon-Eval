// =============================================================================
// Comprehensive Testbench: tb_config_regs
// Description: Full verification suite for configuration registers
//              Tests register access, validation, control flow
// =============================================================================

module tb_config_regs;

    // =========================================================================
    // Parameters
    // =========================================================================
    
    localparam int CLK_PERIOD = 10;
    
    // Register addresses
    localparam logic [7:0] ADDR_CTRL         = 8'h00;
    localparam logic [7:0] ADDR_STATUS       = 8'h04;
    localparam logic [7:0] ADDR_MATRIX_M     = 8'h08;
    localparam logic [7:0] ADDR_MATRIX_N     = 8'h0C;
    localparam logic [7:0] ADDR_MATRIX_K     = 8'h10;
    localparam logic [7:0] ADDR_TILE_DIM     = 8'h14;
    localparam logic [7:0] ADDR_BUF_MODE     = 8'h18;
    localparam logic [7:0] ADDR_TILE_K_MODE  = 8'h58;
    localparam logic [7:0] ADDR_DRAM_BASE_A  = 8'h1C;
    localparam logic [7:0] ADDR_DRAM_BASE_B  = 8'h20;
    localparam logic [7:0] ADDR_DRAM_BASE_C  = 8'h24;
    localparam logic [7:0] ADDR_SRAM_A_PING  = 8'h28;
    localparam logic [7:0] ADDR_SRAM_A_PONG  = 8'h2C;
    localparam logic [7:0] ADDR_SRAM_B_PING  = 8'h30;
    localparam logic [7:0] ADDR_SRAM_B_PONG  = 8'h34;
    localparam logic [7:0] ADDR_SRAM_C       = 8'h38;
    
    // =========================================================================
    // DUT Signals
    // =========================================================================
    
    logic        clk;
    logic        rst_n;
    
    // Host Interface
    logic [7:0]  addr;
    logic [31:0] wdata;
    logic        wen;
    logic        ren;
    logic [31:0] rdata;
    
    // Configuration Outputs
    logic [15:0] matrix_m;
    logic [15:0] matrix_n;
    logic [15:0] matrix_k;
    logic [12:0]  tile_m;
    logic [12:0]  tile_n;
    logic [12:0]  tile_k;
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
    
    // Status Inputs
    logic        busy;
    logic        done;
    logic        error_in;
    logic        error_out;
    
    // =========================================================================
    // Test Control
    // =========================================================================
    
    int error_count = 0;
    int test_count = 0;
    
    // =========================================================================
    // Clock Generation
    // =========================================================================
    
    initial begin
        clk = 0;
        forever #(CLK_PERIOD/2) clk = ~clk;
    end
    
    // =========================================================================
    // DUT Instantiation
    // =========================================================================
    
    config_regs dut (
        .clk                (clk),
        .rst_n              (rst_n),
        .addr               (addr),
        .wdata              (wdata),
        .wen                (wen),
        .ren                (ren),
        .rdata              (rdata),
        .matrix_m           (matrix_m),
        .matrix_n           (matrix_n),
        .matrix_k           (matrix_k),
        .tile_m             (tile_m),
        .tile_n             (tile_n),
        .tile_k             (tile_k),
        .buffering_mode     (buffering_mode),
        .dram_base_a        (dram_base_a),
        .dram_base_b        (dram_base_b),
        .dram_base_c        (dram_base_c),
        .sram_base_a_ping   (sram_base_a_ping),
        .sram_base_a_pong   (sram_base_a_pong),
        .sram_base_b_ping   (sram_base_b_ping),
        .sram_base_b_pong   (sram_base_b_pong),
        .sram_base_c        (sram_base_c),
        .start              (start),
        .ctrl_reset         (ctrl_reset),
        .busy               (busy),
        .done               (done),
        .error_in           (error_in),
        .error_out          (error_out)
    );
    
    // =========================================================================
    // Helper Tasks
    // =========================================================================
    
    // Task: Write register
    task write_reg(input [7:0] reg_addr, input [31:0] data);
        begin
            @(posedge clk);
            addr = reg_addr;
            wdata = data;
            wen = 1'b1;
            @(posedge clk);
            wen = 1'b0;
            @(posedge clk);
        end
    endtask
    
    // Task: Read register
    task read_reg(input [7:0] reg_addr, output [31:0] data);
        begin
            @(posedge clk);
            addr = reg_addr;
            ren = 1'b1;
            @(posedge clk);
            ren = 1'b0;
            @(posedge clk);
            data = rdata;
        end
    endtask
    
    // Task: Setup valid configuration
    task setup_valid_config();
        begin
            write_reg(ADDR_MATRIX_M, 32'h0000_0040);     // 64
            write_reg(ADDR_MATRIX_N, 32'h0000_0040);     // 64
            write_reg(ADDR_MATRIX_K, 32'h0000_0040);     // 64
            write_reg(ADDR_TILE_DIM, {6'h0, 13'd16, 13'd16});     // tile_m=16, tile_n=16
            write_reg(ADDR_TILE_K_MODE, {17'h0, 2'b00, 13'd16});  // tile_k=16, mode=single buffer
            write_reg(ADDR_DRAM_BASE_A, 32'h1000_0000);
            write_reg(ADDR_DRAM_BASE_B, 32'h2000_0000);
            write_reg(ADDR_DRAM_BASE_C, 32'h3000_0000);
            write_reg(ADDR_SRAM_A_PING, 32'h0000_0000);
            write_reg(ADDR_SRAM_A_PONG, 32'h0000_0800);
            write_reg(ADDR_SRAM_B_PING, 32'h0000_1000);
            write_reg(ADDR_SRAM_B_PONG, 32'h0000_1800);
            write_reg(ADDR_SRAM_C, 32'h0000_2000);
        end
    endtask
    
    // =========================================================================
    // Main Test Sequence
    // =========================================================================
    
    initial begin
        logic [31:0] read_data;
        logic [15:0] old_matrix_m;
        
        $display("TEST START");
        $display("=============================================================================");
        $display("Config Registers Comprehensive Testbench");
        $display("=============================================================================");
        
        // Initialize
        rst_n = 0;
        addr = 0;
        wdata = 0;
        wen = 0;
        ren = 0;
        busy = 0;
        done = 0;
        error_in = 0;
        
        // Reset
        repeat(5) @(posedge clk);
        rst_n = 1;
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 1: Basic Write and Read
        // =====================================================================
        $display("\n--- TEST 1: Basic Register Write/Read ---");
        test_count++;
        
        // Write matrix_m
        write_reg(ADDR_MATRIX_M, 32'h0000_0100);
        
        // Read back matrix_m
        read_reg(ADDR_MATRIX_M, read_data);
        
        if (read_data == 32'h0000_0100) begin
            $display("LOG: %0t : INFO : tb_config_regs : test1 : expected_value: 0x00000100 actual_value: 0x%08h", 
                     $time, read_data);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test1 : expected_value: 0x00000100 actual_value: 0x%08h", 
                     $time, read_data);
        end
        
        // Verify output port
        if (matrix_m == 16'h0100) begin
            $display("LOG: %0t : INFO : tb_config_regs : test1_port : expected_value: 0x0100 actual_value: 0x%04h", 
                     $time, matrix_m);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test1_port : expected_value: 0x0100 actual_value: 0x%04h", 
                     $time, matrix_m);
        end
        
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 2: Multiple Register Access
        // =====================================================================
        $display("\n--- TEST 2: Multiple Register Access ---");
        test_count++;
        
        write_reg(ADDR_MATRIX_N, 32'h0000_0080);
        write_reg(ADDR_MATRIX_K, 32'h0000_00C0);
        write_reg(ADDR_DRAM_BASE_A, 32'hDEAD_BEEF);
        
        read_reg(ADDR_MATRIX_N, read_data);
        if (read_data[15:0] == 16'h0080) begin
            $display("LOG: %0t : INFO : tb_config_regs : test2_n : Matrix N correct", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test2_n : expected_value: 0x0080 actual_value: 0x%04h", 
                     $time, read_data[15:0]);
        end
        
        read_reg(ADDR_DRAM_BASE_A, read_data);
        if (read_data == 32'hDEAD_BEEF) begin
            $display("LOG: %0t : INFO : tb_config_regs : test2_dram : DRAM base correct", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test2_dram : expected_value: 0xDEADBEEF actual_value: 0x%08h", 
                     $time, read_data);
        end
        
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 3: Tile Dimension Register (Packed Fields)
        // =====================================================================
        $display("\n--- TEST 3: Packed Tile Dimension Register ---");
        test_count++;
        
        // Write tile_m=8, tile_n=16, tile_k=32
        write_reg(ADDR_TILE_DIM, {6'h0, 13'd16, 13'd8});     // tile_m=8, tile_n=16
        write_reg(ADDR_TILE_K_MODE, {17'h0, 2'b00, 13'd32}); // tile_k=32, mode=single buffer
        
        if (tile_m == 13'd8 && tile_n == 13'd16 && tile_k == 13'd32) begin
            $display("LOG: %0t : INFO : tb_config_regs : test3 : Tile dimensions unpacked correctly", $time);
            $display("LOG: %0t : INFO : tb_config_regs : test3_m : tile_m=0x%03h", $time, tile_m);
            $display("LOG: %0t : INFO : tb_config_regs : test3_n : tile_n=0x%03h", $time, tile_n);
            $display("LOG: %0t : INFO : tb_config_regs : test3_k : tile_k=0x%03h", $time, tile_k);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test3 : Tile dimensions incorrect", $time);
        end
        
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 4: Valid Configuration and Start
        // =====================================================================
        $display("\n--- TEST 4: Valid Configuration and Start ---");
        test_count++;
        
        setup_valid_config();
        
        // Issue start command
        @(posedge clk);
        addr = ADDR_CTRL;
        wdata = 32'h0000_0001;  // START bit
        wen = 1'b1;
        
        @(posedge clk);
        wen = 1'b0;
        // Check start signal on same cycle as write completes
        if (start) begin
            $display("LOG: %0t : INFO : tb_config_regs : test4 : expected_value: start=1 actual_value: start=1", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test4 : expected_value: start=1 actual_value: start=0", $time);
        end
        
        // Start should self-clear
        @(posedge clk);
        if (!start) begin
            $display("LOG: %0t : INFO : tb_config_regs : test4_clear : Start self-cleared", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test4_clear : Start did not self-clear", $time);
        end
        
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 5: Invalid Configuration (Zero Dimensions)
        // =====================================================================
        $display("\n--- TEST 5: Invalid Config - Zero Matrix Dimension ---");
        test_count++;
        
        // Reset configuration
        rst_n = 0;
        repeat(2) @(posedge clk);
        rst_n = 1;
        repeat(2) @(posedge clk);
        
        // Setup with matrix_m = 0 (invalid)
        write_reg(ADDR_MATRIX_M, 32'h0000_0000);  // Invalid: zero
        write_reg(ADDR_MATRIX_N, 32'h0000_0040);
        write_reg(ADDR_MATRIX_K, 32'h0000_0040);
        write_reg(ADDR_TILE_DIM, {6'h0, 13'd16, 13'd16});     // tile_m=16, tile_n=16
        write_reg(ADDR_TILE_K_MODE, {17'h0, 2'b00, 13'd16});  // tile_k=16, mode=single buffer
        
        // Try to start
        write_reg(ADDR_CTRL, 32'h0000_0001);
        
        @(posedge clk);
        if (!start) begin
            $display("LOG: %0t : INFO : tb_config_regs : test5 : Start correctly blocked (invalid config)", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test5 : Start should be blocked", $time);
        end
        
        // Check error flag
        @(posedge clk);
        if (error_out) begin
            $display("LOG: %0t : INFO : tb_config_regs : test5_err : expected_value: error=1 actual_value: error=1", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test5_err : expected_value: error=1 actual_value: error=0", $time);
        end
        
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 6: Invalid Configuration (Non-Divisible)
        // =====================================================================
        $display("\n--- TEST 6: Invalid Config - Non-Divisible Dimensions ---");
        test_count++;
        
        // Clear error
        write_reg(ADDR_CTRL, 32'h0000_0002);  // RESET bit
        repeat(2) @(posedge clk);
        
        // Setup with matrix_m=50, tile_m=16 (50 % 16 != 0, invalid)
        write_reg(ADDR_MATRIX_M, 32'h0000_0032);  // 50
        write_reg(ADDR_MATRIX_N, 32'h0000_0040);  // 64
        write_reg(ADDR_MATRIX_K, 32'h0000_0040);  // 64
        write_reg(ADDR_TILE_DIM, {6'h0, 13'd16, 13'd16});     // tile_m=16, tile_n=16
        write_reg(ADDR_TILE_K_MODE, {17'h0, 2'b00, 13'd16});  // tile_k=16, mode=single buffer
        
        // Try to start
        write_reg(ADDR_CTRL, 32'h0000_0001);
        
        @(posedge clk);
        if (!start) begin
            $display("LOG: %0t : INFO : tb_config_regs : test6 : Start blocked (non-divisible)", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test6 : Start should be blocked", $time);
        end
        
        @(posedge clk);
        if (error_out) begin
            $display("LOG: %0t : INFO : tb_config_regs : test6_err : Error flag set", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test6_err : Error flag should be set", $time);
        end
        
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 7: Busy Signal Gating
        // =====================================================================
        $display("\n--- TEST 7: Busy Signal Gates Config Writes ---");
        test_count++;
        
        // Clear error and setup valid config
        rst_n = 0;
        repeat(2) @(posedge clk);
        rst_n = 1;
        repeat(2) @(posedge clk);
        
        setup_valid_config();
        
        // Start operation
        write_reg(ADDR_CTRL, 32'h0000_0001);
        @(posedge clk);
        
        // Simulate busy
        busy = 1'b1;
        repeat(2) @(posedge clk);
        
        // Try to write matrix_m while busy
        old_matrix_m = matrix_m;
        write_reg(ADDR_MATRIX_M, 32'h0000_1234);
        
        if (matrix_m == old_matrix_m) begin
            $display("LOG: %0t : INFO : tb_config_regs : test7 : Write blocked during busy (correct)", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test7 : Write allowed during busy", $time);
        end
        
        // Clear busy
        busy = 1'b0;
        repeat(2) @(posedge clk);
        
        // Now write should work
        write_reg(ADDR_MATRIX_M, 32'h0000_1234);
        
        if (matrix_m == 16'h1234) begin
            $display("LOG: %0t : INFO : tb_config_regs : test7_after : Write allowed after busy cleared", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test7_after : Write failed after busy cleared", $time);
        end
        
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 8: Status Register
        // =====================================================================
        $display("\n--- TEST 8: Status Register Read ---");
        test_count++;
        
        // Set status signals
        busy = 1'b1;
        done = 1'b0;
        error_in = 1'b0;
        
        read_reg(ADDR_STATUS, read_data);
        
        // Status register: {29'h0, error, done, busy}
        if (read_data[0] == 1'b1 && read_data[1] == 1'b0) begin
            $display("LOG: %0t : INFO : tb_config_regs : test8 : Status register correct (busy=1, done=0)", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test8 : Status register incorrect: 0x%08h", $time, read_data);
        end
        
        // Change status
        busy = 1'b0;
        done = 1'b1;
        
        read_reg(ADDR_STATUS, read_data);
        
        if (read_data[0] == 1'b0 && read_data[1] == 1'b1) begin
            $display("LOG: %0t : INFO : tb_config_regs : test8_done : Status updated (busy=0, done=1)", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test8_done : Status not updated: 0x%08h", $time, read_data);
        end
        
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 9: Error Input Sets Error Register
        // =====================================================================
        $display("\n--- TEST 9: External Error Input ---");
        test_count++;
        
        // Clear error
        write_reg(ADDR_CTRL, 32'h0000_0002);
        repeat(2) @(posedge clk);
        
        // Assert error_in
        error_in = 1'b1;
        @(posedge clk);
        error_in = 1'b0;
        @(posedge clk);
        
        if (error_out) begin
            $display("LOG: %0t : INFO : tb_config_regs : test9 : External error captured", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test9 : External error not captured", $time);
        end
        
        // Error should be sticky
        repeat(3) @(posedge clk);
        if (error_out) begin
            $display("LOG: %0t : INFO : tb_config_regs : test9_sticky : Error is sticky", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test9_sticky : Error not sticky", $time);
        end
        
        // Clear with reset
        write_reg(ADDR_CTRL, 32'h0000_0002);
        @(posedge clk);
        if (!error_out) begin
            $display("LOG: %0t : INFO : tb_config_regs : test9_clear : Error cleared by reset", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test9_clear : Error not cleared", $time);
        end
        
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 10: Reset Functionality
        // =====================================================================
        $display("\n--- TEST 10: Hardware Reset ---");
        test_count++;
        
        // Write some values
        setup_valid_config();
        
        // Hardware reset
        rst_n = 0;
        repeat(3) @(posedge clk);
        rst_n = 1;
        repeat(2) @(posedge clk);
        
        // Check registers are cleared
        if (matrix_m == 16'h0 && matrix_n == 16'h0 && matrix_k == 16'h0) begin
            $display("LOG: %0t : INFO : tb_config_regs : test10 : Registers cleared after reset", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test10 : Registers not cleared", $time);
        end
        
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 11: Large Tile Dimension (tile_n=4096)
        // =====================================================================
        $display("\n--- TEST 11: Large Tile Dimension (tile_n=4096) ---");
        test_count++;
        
        // Reset to clean state
        rst_n = 0;
        repeat(2) @(posedge clk);
        rst_n = 1;
        repeat(2) @(posedge clk);
        
        // Configure minimal matrix dimensions: M=8, N=8192, K=32
        // Goal: 2 tiles in N dimension (8192/4096=2), single tiles in M/K
        write_reg(ADDR_MATRIX_M, 32'd8);
        write_reg(ADDR_MATRIX_N, 32'd8192);
        write_reg(ADDR_MATRIX_K, 32'd32);
        
        // Configure tile dimensions: tile_m=8, tile_n=4096, tile_k=32
        write_reg(ADDR_TILE_DIM, {6'h0, 13'd4096, 13'd8});     // tile_n=4096, tile_m=8
        write_reg(ADDR_TILE_K_MODE, {17'h0, 2'b00, 13'd32});   // tile_k=32, mode=single buffer
        
        // Configure DRAM base addresses
        write_reg(ADDR_DRAM_BASE_A, 32'h1000_0000);
        write_reg(ADDR_DRAM_BASE_B, 32'h2000_0000);
        write_reg(ADDR_DRAM_BASE_C, 32'h3000_0000);
        
        // Issue start command
        write_reg(ADDR_CTRL, 32'h0000_0001);  // start=1
        @(posedge clk);
        // Clear start
        write_reg(ADDR_CTRL, 32'h0000_0000);  // start=0
        
        // Check configuration was accepted (error bit should be 0)
        @(posedge clk);
        read_reg(ADDR_STATUS, read_data);
        
        if (read_data[2]) begin  // error bit
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test11 : Controller rejected tile_n=4096 configuration (error=1)", $time);
        end else begin
            $display("LOG: %0t : INFO : tb_config_regs : test11 : Controller accepted tile_n=4096 configuration (error=0)", $time);
        end
        
        // Verify tile dimensions match configured values
        if (tile_m == 13'd8 && tile_n == 13'd4096 && tile_k == 13'd32) begin
            $display("LOG: %0t : INFO : tb_config_regs : test11_dims : tile_m=%0d, tile_n=%0d, tile_k=%0d", 
                     $time, tile_m, tile_n, tile_k);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_config_regs : test11_dims : Tile dimensions mismatch: expected (8,4096,32), got (%0d,%0d,%0d)",
                     $time, tile_m, tile_n, tile_k);
        end
        
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // Test Summary
        // =====================================================================
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
    
    // =========================================================================
    // Timeout Watchdog
    // =========================================================================
    
    initial begin
        #50000;
        $display("\n=============================================================================");
        $display("ERROR: Test timeout");
        $display("=============================================================================");
        $fatal(1, "Test timeout");
    end
    
    // =========================================================================
    // Waveform Dump
    // =========================================================================
    
    initial begin
        $dumpfile("dumpfile.fst");
        $dumpvars(0);
    end

endmodule
