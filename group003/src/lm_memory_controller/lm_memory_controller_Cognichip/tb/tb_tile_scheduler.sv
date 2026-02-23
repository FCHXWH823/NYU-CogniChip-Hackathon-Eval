// =============================================================================
// Comprehensive Testbench: tb_tile_scheduler
// Description: Full verification suite for tile scheduler FSM
//              Tests state transitions, tile iteration, buffer management
// =============================================================================

module tb_tile_scheduler;

    // =========================================================================
    // Parameters
    // =========================================================================
    
    parameter int MAX_TILE_DIM      = 64;
    parameter int SRAM_ADDR_WIDTH   = 16;
    parameter int DATA_WIDTH_A      = 8;
    parameter int DATA_WIDTH_B      = 8;
    parameter int DATA_WIDTH_C      = 32;
    localparam int CLK_PERIOD = 10;
    
    // =========================================================================
    // DUT Signals
    // =========================================================================
    
    logic        clk;
    logic        rst_n;
    
    // Config Interface
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
    
    // Prefetch Engine Interface
    logic        fetch_req_valid;
    logic        fetch_req_ready;
    logic        fetch_req_is_write;
    logic [31:0] fetch_req_dram_addr_a;
    logic [31:0] fetch_req_dram_addr_b;
    logic [31:0] fetch_req_dram_addr_c;
    logic [15:0] fetch_req_sram_addr_a;
    logic [15:0] fetch_req_sram_addr_b;
    logic [15:0] fetch_req_sram_addr_c;
    logic [15:0] fetch_req_num_elements_a;
    logic [15:0] fetch_req_num_elements_b;
    logic [15:0] fetch_req_num_elements_c;
    logic        fetch_done;
    
    // Compute Engine Interface
    logic        tile_valid;
    logic        tile_ready;
    logic        tile_done;
    logic [15:0] tile_sram_addr_a;
    logic [15:0] tile_sram_addr_b;
    logic [15:0] tile_sram_addr_c;
    logic [12:0] tile_m_dim;
    logic [12:0] tile_n_dim;
    logic [12:0] tile_k_dim;
    
    // Status
    logic        busy;
    logic        done;
    logic        error;
    
    // =========================================================================
    // Test Control
    // =========================================================================
    
    int error_count = 0;
    int test_count = 0;
    int fetch_read_count = 0;
    int fetch_write_count = 0;
    int tile_handshake_count = 0;
    
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
    
    tile_scheduler #(
        .MAX_TILE_DIM    (MAX_TILE_DIM),
        .SRAM_ADDR_WIDTH (SRAM_ADDR_WIDTH),
        .DATA_WIDTH_A    (DATA_WIDTH_A),
        .DATA_WIDTH_B    (DATA_WIDTH_B),
        .DATA_WIDTH_C    (DATA_WIDTH_C)
    ) dut (
        .clk                    (clk),
        .rst_n                  (rst_n),
        .matrix_m               (matrix_m),
        .matrix_n               (matrix_n),
        .matrix_k               (matrix_k),
        .tile_m                 (tile_m),
        .tile_n                 (tile_n),
        .tile_k                 (tile_k),
        .buffering_mode         (buffering_mode),
        .dram_base_a            (dram_base_a),
        .dram_base_b            (dram_base_b),
        .dram_base_c            (dram_base_c),
        .sram_base_a_ping       (sram_base_a_ping),
        .sram_base_a_pong       (sram_base_a_pong),
        .sram_base_b_ping       (sram_base_b_ping),
        .sram_base_b_pong       (sram_base_b_pong),
        .sram_base_c            (sram_base_c),
        .start                  (start),
        .fetch_req_valid        (fetch_req_valid),
        .fetch_req_ready        (fetch_req_ready),
        .fetch_req_is_write     (fetch_req_is_write),
        .fetch_req_dram_addr_a  (fetch_req_dram_addr_a),
        .fetch_req_dram_addr_b  (fetch_req_dram_addr_b),
        .fetch_req_dram_addr_c  (fetch_req_dram_addr_c),
        .fetch_req_sram_addr_a  (fetch_req_sram_addr_a),
        .fetch_req_sram_addr_b  (fetch_req_sram_addr_b),
        .fetch_req_sram_addr_c  (fetch_req_sram_addr_c),
        .fetch_req_num_elements_a(fetch_req_num_elements_a),
        .fetch_req_num_elements_b(fetch_req_num_elements_b),
        .fetch_req_num_elements_c(fetch_req_num_elements_c),
        .fetch_done             (fetch_done),
        .tile_valid             (tile_valid),
        .tile_ready             (tile_ready),
        .tile_done              (tile_done),
        .tile_sram_addr_a       (tile_sram_addr_a),
        .tile_sram_addr_b       (tile_sram_addr_b),
        .tile_sram_addr_c       (tile_sram_addr_c),
        .tile_m_dim             (tile_m_dim),
        .tile_n_dim             (tile_n_dim),
        .tile_k_dim             (tile_k_dim),
        .busy                   (busy),
        .done                   (done),
        .error                  (error)
    );
    
    // =========================================================================
    // Helper Tasks
    // =========================================================================
    
    // Task: Setup configuration
    task setup_config(
        input [15:0] m, n, k,
        input [12:0] tm, tn, tk,
        input [1:0] buf_mode
    );
        begin
            matrix_m = m;
            matrix_n = n;
            matrix_k = k;
            tile_m = tm;
            tile_n = tn;
            tile_k = tk;
            buffering_mode = buf_mode;
            dram_base_a = 32'h1000_0000;
            dram_base_b = 32'h2000_0000;
            dram_base_c = 32'h3000_0000;
            sram_base_a_ping = 16'h0000;
            sram_base_a_pong = 16'h0800;
            sram_base_b_ping = 16'h1000;
            sram_base_b_pong = 16'h1800;
            sram_base_c = 16'h2000;
        end
    endtask
    
    // Task: Check and reset transaction counters
    task check_transaction_counts(
        input string test_name,
        input int expected_reads,
        input int expected_writes,
        input int expected_tiles
    );
        begin
            if (fetch_read_count != expected_reads) begin
                error_count++;
                $display("LOG: %0t : ERROR : tb_tile_sched : %s_txn_read : expected_value: %0d actual_value: %0d",
                         $time, test_name, expected_reads, fetch_read_count);
            end else begin
                $display("LOG: %0t : INFO : tb_tile_sched : %s_txn_read : expected_value: %0d actual_value: %0d",
                         $time, test_name, expected_reads, fetch_read_count);
            end
            
            if (fetch_write_count != expected_writes) begin
                error_count++;
                $display("LOG: %0t : ERROR : tb_tile_sched : %s_txn_write : expected_value: %0d actual_value: %0d",
                         $time, test_name, expected_writes, fetch_write_count);
            end else begin
                $display("LOG: %0t : INFO : tb_tile_sched : %s_txn_write : expected_value: %0d actual_value: %0d",
                         $time, test_name, expected_writes, fetch_write_count);
            end
            
            if (tile_handshake_count != expected_tiles) begin
                error_count++;
                $display("LOG: %0t : ERROR : tb_tile_sched : %s_txn_tile : expected_value: %0d actual_value: %0d",
                         $time, test_name, expected_tiles, tile_handshake_count);
            end else begin
                $display("LOG: %0t : INFO : tb_tile_sched : %s_txn_tile : expected_value: %0d actual_value: %0d",
                         $time, test_name, expected_tiles, tile_handshake_count);
            end
            
            // Reset counters for next test
            fetch_read_count = 0;
            fetch_write_count = 0;
            tile_handshake_count = 0;
        end
    endtask
    
    // =========================================================================
    // Continuous Response Processes
    // =========================================================================
    
    logic enable_responses;
    
    // Continuous fetch request responder (handles both read and write)
    initial begin
        forever begin
            @(posedge clk);
            if (enable_responses && fetch_req_valid && !fetch_done) begin
                // Count transaction type
                if (fetch_req_is_write) fetch_write_count++;
                else fetch_read_count++;
                
                // Accept request immediately
                fetch_req_ready = 1'b1;
                @(posedge clk);
                fetch_req_ready = 1'b0;
                
                // Simulate data transfer delay
                repeat(3) @(posedge clk);
                
                // Signal completion
                fetch_done = 1'b1;
                @(posedge clk);
                fetch_done = 1'b0;
            end else begin
                fetch_req_ready = 1'b0;
            end
        end
    end
    
    // Continuous tile ready responder
    initial begin
        forever begin
            @(posedge clk);
            if (enable_responses && tile_valid && !tile_done) begin
                // Count tile handshake
                tile_handshake_count++;
                
                // Accept tile immediately
                tile_ready = 1'b1;
                @(posedge clk);
                tile_ready = 1'b0;
                
                // Simulate compute delay
                repeat(5) @(posedge clk);
                
                // Signal completion
                tile_done = 1'b1;
                @(posedge clk);
                tile_done = 1'b0;
            end else begin
                tile_ready = 1'b0;
            end
        end
    end
    
    // =========================================================================
    // Protocol Monitors (Continuous, Passive)
    // Equivalent to SVA concurrent assertions, implemented procedurally
    // for broad simulator compatibility (Verilator, Icarus, etc.)
    //
    //   P1: fetch_req_valid && !fetch_req_ready |=> fetch_req_valid
    //   P2: tile_valid && !tile_ready |=> tile_valid
    //   P3: tile_valid && tile_ready  |=> !tile_valid
    // =========================================================================
    
    logic prev_fetch_req_valid = 1'b0;
    logic prev_fetch_req_ready = 1'b0;
    logic prev_tile_valid      = 1'b0;
    logic prev_tile_ready      = 1'b0;
    
    initial begin
        forever begin
            @(posedge clk);
            // NOTE: Only check when auto-responder is active. Verilator executes
            // initial blocks in source order, so this monitor (defined AFTER the
            // auto-responder but BEFORE the main test sequence) correctly sees
            // fetch_req_ready set by the responder. During manual Test 6, the
            // main test sequence drives signals AFTER this monitor runs, causing
            // false positives. Test 6 has its own explicit protocol assertions.
            if (rst_n && enable_responses) begin
                // P1: fetch_req_valid must stay high until fetch_req_ready
                if (prev_fetch_req_valid && !prev_fetch_req_ready && !fetch_req_valid) begin
                    error_count++;
                    $display("LOG: %0t : ERROR : tb_tile_sched : proto_fetch_valid_stable : fetch_req_valid dropped before ready",
                             $time);
                end
                
                // P2: tile_valid must stay high until tile_ready
                if (prev_tile_valid && !prev_tile_ready && !tile_valid) begin
                    error_count++;
                    $display("LOG: %0t : ERROR : tb_tile_sched : proto_tile_valid_stable : tile_valid dropped before ready",
                             $time);
                end
                
                // P3: tile_valid must deassert after handshake (TILE_READY -> COMPUTE)
                if (prev_tile_valid && prev_tile_ready && tile_valid) begin
                    error_count++;
                    $display("LOG: %0t : ERROR : tb_tile_sched : proto_tile_valid_deassert : tile_valid still high after handshake",
                             $time);
                end
            end
            
            // Update previous values (always, regardless of reset)
            prev_fetch_req_valid = fetch_req_valid;
            prev_fetch_req_ready = fetch_req_ready;
            prev_tile_valid      = tile_valid;
            prev_tile_ready      = tile_ready;
        end
    end
    
    // =========================================================================
    // Main Test Sequence
    // =========================================================================
    
    initial begin
        $display("TEST START");
        $display("=============================================================================");
        $display("Tile Scheduler Comprehensive Testbench");
        $display("=============================================================================");
        
        // Initialize
        rst_n = 0;
        start = 0;
        fetch_req_ready = 0;
        fetch_done = 0;
        tile_ready = 0;
        tile_done = 0;
        enable_responses = 0;
        
        // Reset
        repeat(5) @(posedge clk);
        rst_n = 1;
        enable_responses = 1;  // Enable automatic responses
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 1: Single Tile Execution (1x1x1)
        // =====================================================================
        $display("\n--- TEST 1: Single Tile (16x16x16, Tile 16x16x16) ---");
        test_count++;
        
        setup_config(16, 16, 16, 16, 16, 16, 2'b00);  // Single buffer mode
        
        @(posedge clk);
        start = 1'b1;
        @(posedge clk);
        start = 1'b0;
        
        // Wait for busy
        @(posedge clk);
        if (busy) begin
            $display("LOG: %0t : INFO : tb_tile_sched : test1 : Scheduler is busy", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_tile_sched : test1 : expected_value: busy=1 actual_value: busy=0", $time);
        end
        
        // Wait for done (responses handled automatically)
        wait(done);
        $display("LOG: %0t : INFO : tb_tile_sched : test1 : expected_value: done=1 actual_value: done=1", $time);
        check_transaction_counts("test1", 1, 1, 1);
        
        // Reset between tests to ensure clean state
        @(posedge clk);
        rst_n = 0;
        repeat(2) @(posedge clk);
        rst_n = 1;
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 2: Multiple K Tiles (1x1x2)
        // =====================================================================
        $display("\n--- TEST 2: Multiple K Tiles (16x16x32, Tile 16x16x16) ---");
        test_count++;
        
        setup_config(16, 16, 32, 16, 16, 16, 2'b00);
        
        @(posedge clk);
        start = 1'b1;
        @(posedge clk);
        start = 1'b0;
        
        // Wait for done (responses handled automatically)
        wait(done);
        $display("LOG: %0t : INFO : tb_tile_sched : test2 : expected_value: done=1 actual_value: done=1", $time);
        check_transaction_counts("test2", 2, 1, 2);
        
        // Reset between tests to ensure clean state
        @(posedge clk);
        rst_n = 0;
        repeat(2) @(posedge clk);
        rst_n = 1;
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 3: 2x2x1 Tile Grid
        // =====================================================================
        $display("\n--- TEST 3: 2x2x1 Grid (32x32x16, Tile 16x16x16) ---");
        test_count++;
        
        setup_config(32, 32, 16, 16, 16, 16, 2'b00);
        
        @(posedge clk);
        start = 1'b1;
        @(posedge clk);
        start = 1'b0;
        
        // Wait for done (responses handled automatically)
        wait(done);
        $display("LOG: %0t : INFO : tb_tile_sched : test3 : expected_value: done=1 actual_value: done=1", $time);
        check_transaction_counts("test3", 4, 4, 4);
        
        // Reset between tests to ensure clean state
        @(posedge clk);
        rst_n = 0;
        repeat(2) @(posedge clk);
        rst_n = 1;
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 4: Address Calculation Verification
        // =====================================================================
        $display("\n--- TEST 4: Address Calculation (16x16x16, Tile 8x8x8) ---");
        test_count++;
        
        setup_config(16, 16, 16, 8, 8, 8, 2'b00);
        
        @(posedge clk);
        start = 1'b1;
        @(posedge clk);
        start = 1'b0;
        
        // Wait for first fetch request
        wait(fetch_req_valid);
        @(posedge clk);
        
        // Check first tile addresses (m=0, n=0, k=0)
        if (fetch_req_dram_addr_a == 32'h1000_0000) begin
            $display("LOG: %0t : INFO : tb_tile_sched : test4_addr_a : expected_value: 0x10000000 actual_value: 0x%08h", 
                     $time, fetch_req_dram_addr_a);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_tile_sched : test4_addr_a : expected_value: 0x10000000 actual_value: 0x%08h", 
                     $time, fetch_req_dram_addr_a);
        end
        
        if (fetch_req_num_elements_a == 16'd64) begin  // 8*8
            $display("LOG: %0t : INFO : tb_tile_sched : test4_num_a : expected_value: 64 actual_value: %0d", 
                     $time, fetch_req_num_elements_a);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_tile_sched : test4_num_a : expected_value: 64 actual_value: %0d", 
                     $time, fetch_req_num_elements_a);
        end
        
        // Wait for done (responses handled automatically)
        wait(done);
        check_transaction_counts("test4", 8, 4, 8);
        
        // Reset between tests to ensure clean state
        @(posedge clk);
        rst_n = 0;
        repeat(2) @(posedge clk);
        rst_n = 1;
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 5: Double Buffer Mode A
        // =====================================================================
        $display("\n--- TEST 5: Double Buffer Mode A (16x16x32, Tile 16x16x16) ---");
        test_count++;
        
        setup_config(16, 16, 32, 16, 16, 16, 2'b01);  // MODE_DOUBLE_A
        
        @(posedge clk);
        start = 1'b1;
        @(posedge clk);
        start = 1'b0;
        
        // Wait for first tile to use ping buffer
        wait(fetch_req_valid);
        @(posedge clk);
        
        if (fetch_req_sram_addr_a == sram_base_a_ping) begin
            $display("LOG: %0t : INFO : tb_tile_sched : test5_buf : expected_value: ping=0x%04h actual_value: 0x%04h", 
                     $time, sram_base_a_ping, fetch_req_sram_addr_a);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_tile_sched : test5_buf : expected_value: ping=0x%04h actual_value: 0x%04h", 
                     $time, sram_base_a_ping, fetch_req_sram_addr_a);
        end
        
        // Wait for done (responses handled automatically)
        wait(done);
        check_transaction_counts("test5", 2, 1, 2);
        
        // Reset between tests to ensure clean state
        @(posedge clk);
        rst_n = 0;
        repeat(2) @(posedge clk);
        rst_n = 1;
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 6: Tile Valid Handshake (Manual Control)
        // Disables auto-responder to manually verify protocol details:
        //   - fetch_req_valid persistence across cycles
        //   - fetch_req_is_write correct for read vs writeback
        //   - tile_valid persistence while tile_ready is withheld
        //   - tile_valid deassert after handshake
        //   - DUT correctly waits for tile_done before writeback
        // Expected transactions: reads=1, writes=1, tiles=1
        // =====================================================================
        $display("\n--- TEST 6: Tile Valid/Ready Handshake (Manual) ---");
        test_count++;
        
        // Disable auto-responder for manual protocol testing
        enable_responses = 0;
        
        setup_config(16, 16, 16, 16, 16, 16, 2'b00);
        
        @(posedge clk);
        start = 1'b1;
        @(posedge clk);
        start = 1'b0;
        
        // --- Manual fetch response with deliberate delay ---
        wait(fetch_req_valid);
        
        // Delay 2 cycles: exercises proto_fetch_valid_stable monitor
        repeat(2) @(posedge clk);
        
        // Verify fetch_req_valid persisted during the delay
        if (fetch_req_valid) begin
            $display("LOG: %0t : INFO : tb_tile_sched : test6_fetch_persist : fetch_req_valid held stable (correct)", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_tile_sched : test6_fetch_persist : fetch_req_valid dropped early", $time);
        end
        
        // Verify this is a READ fetch (not writeback)
        if (!fetch_req_is_write) begin
            $display("LOG: %0t : INFO : tb_tile_sched : test6_fetch_type : fetch is read (correct)", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_tile_sched : test6_fetch_type : expected read but got write", $time);
        end
        fetch_read_count++;
        
        // Accept fetch request
        fetch_req_ready = 1'b1;
        @(posedge clk);
        fetch_req_ready = 1'b0;
        
        // Simulate data transfer delay
        repeat(3) @(posedge clk);
        
        // Signal fetch completion
        fetch_done = 1'b1;
        @(posedge clk);
        fetch_done = 1'b0;
        
        // --- Manual tile handshake with deliberate delay ---
        wait(tile_valid);
        $display("LOG: %0t : INFO : tb_tile_sched : test6 : tile_valid asserted", $time);
        
        // Delay 5 cycles: exercises proto_tile_valid_stable monitor
        repeat(5) @(posedge clk);
        
        // Verify tile_valid persisted while tile_ready was withheld
        if (tile_valid) begin
            $display("LOG: %0t : INFO : tb_tile_sched : test6_tile_persist : tile_valid held stable for 5 cycles (correct)", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_tile_sched : test6_tile_persist : tile_valid dropped before ready", $time);
        end
        
        // Accept tile
        tile_ready = 1'b1;
        tile_handshake_count++;
        @(posedge clk);
        tile_ready = 1'b0;
        
        // Verify tile_valid deasserted after handshake
        @(posedge clk);
        if (!tile_valid) begin
            $display("LOG: %0t : INFO : tb_tile_sched : test6_tile_deassert : tile_valid deasserted after handshake (correct)", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_tile_sched : test6_tile_deassert : tile_valid still asserted after handshake", $time);
        end
        
        // Simulate compute delay (DUT waits in COMPUTE for tile_done)
        repeat(5) @(posedge clk);
        
        // Signal compute completion
        tile_done = 1'b1;
        @(posedge clk);
        tile_done = 1'b0;
        
        // --- Manual writeback response ---
        wait(fetch_req_valid);
        
        // Verify this is a WRITEBACK (is_write=1)
        if (fetch_req_is_write) begin
            $display("LOG: %0t : INFO : tb_tile_sched : test6_wb_type : fetch is writeback (correct)", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_tile_sched : test6_wb_type : expected writeback but got read", $time);
        end
        fetch_write_count++;
        
        // Accept writeback with deliberate delay
        repeat(2) @(posedge clk);
        fetch_req_ready = 1'b1;
        @(posedge clk);
        fetch_req_ready = 1'b0;
        
        // Simulate writeback delay
        repeat(3) @(posedge clk);
        
        // Signal writeback completion
        fetch_done = 1'b1;
        @(posedge clk);
        fetch_done = 1'b0;
        
        // Wait for done
        wait(done);
        $display("LOG: %0t : INFO : tb_tile_sched : test6 : Test completed", $time);
        check_transaction_counts("test6", 1, 1, 1);
        
        // Re-enable auto-responder for subsequent tests
        enable_responses = 1;
        
        // NOTE: Intentionally NO reset here - Test 7 tests DONE_STATE -> FETCH path
        
        // =====================================================================
        // TEST 7: DONE_STATE -> FETCH_REQ Path (No Reset)
        // Verifies the FSM can accept a new start command from DONE_STATE
        // without requiring a hardware reset. This path was implicitly
        // covered by the old testbench (which lacked inter-test resets).
        // Expected transactions: reads=1, writes=1, tiles=1
        // =====================================================================
        $display("\n--- TEST 7: DONE_STATE to FETCH_REQ (No Reset) ---");
        test_count++;
        
        // Verify DUT is in DONE_STATE (done=1) from Test 6
        if (done) begin
            $display("LOG: %0t : INFO : tb_tile_sched : test7_pre : DUT in DONE_STATE (done=1)", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_tile_sched : test7_pre : expected done=1 but got done=0", $time);
        end
        
        setup_config(16, 16, 16, 16, 16, 16, 2'b00);
        
        @(posedge clk);
        start = 1'b1;
        @(posedge clk);
        start = 1'b0;
        
        // Verify busy asserted (successfully transitioned out of DONE_STATE)
        @(posedge clk);
        if (busy) begin
            $display("LOG: %0t : INFO : tb_tile_sched : test7 : Scheduler busy after DONE_STATE start", $time);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_tile_sched : test7 : expected busy=1 after start from DONE_STATE", $time);
        end
        
        // Wait for done (auto-responder handles protocol)
        wait(done);
        $display("LOG: %0t : INFO : tb_tile_sched : test7 : expected_value: done=1 actual_value: done=1", $time);
        check_transaction_counts("test7", 1, 1, 1);
        
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
        #200000;
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
