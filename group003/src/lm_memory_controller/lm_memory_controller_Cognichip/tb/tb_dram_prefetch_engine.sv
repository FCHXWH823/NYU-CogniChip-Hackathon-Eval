// =============================================================================
// Comprehensive Testbench: tb_dram_prefetch_engine
// Description: Full verification suite for DRAM prefetch engine
//              Tests width conversion, queue management, read/write flows
// =============================================================================

module tb_dram_prefetch_engine;

    // =========================================================================
    // Parameters
    // =========================================================================
    
    parameter int DRAM_ADDR_WIDTH  = 32;
    parameter int DRAM_DATA_WIDTH  = 128;
    parameter int SRAM_ADDR_WIDTH  = 16;
    parameter int SRAM_DATA_WIDTH  = 32;
    parameter int DATA_WIDTH_A     = 8;
    parameter int DATA_WIDTH_B     = 8;
    parameter int DATA_WIDTH_C     = 32;
    parameter int PREFETCH_DEPTH   = 4;
    localparam int CLK_PERIOD = 10;
    
    // =========================================================================
    // DUT Signals
    // =========================================================================
    
    logic        clk;
    logic        rst_n;
    
    // Scheduler Interface
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
    
    // DRAM Interface
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
    
    // SRAM Arbiter Interface
    logic                        sram_req_valid;
    logic                        sram_req_ready;
    logic                        sram_req_wen;
    logic [SRAM_ADDR_WIDTH-1:0]  sram_req_addr;
    logic [SRAM_DATA_WIDTH-1:0]  sram_req_wdata;
    logic [SRAM_DATA_WIDTH-1:0]  sram_req_rdata;
    logic                        sram_req_rdata_valid;
    
    // =========================================================================
    // Test Control
    // =========================================================================
    
    int error_count = 0;
    int test_count = 0;
    
    // SRAM model
    logic [SRAM_DATA_WIDTH-1:0] sram_model [16384];  // 16K words
    
    // DRAM model
    logic [DRAM_DATA_WIDTH-1:0] dram_model [4096];   // 4K beats
    
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
    
    dram_prefetch_engine #(
        .DRAM_ADDR_WIDTH (DRAM_ADDR_WIDTH),
        .DRAM_DATA_WIDTH (DRAM_DATA_WIDTH),
        .SRAM_ADDR_WIDTH (SRAM_ADDR_WIDTH),
        .SRAM_DATA_WIDTH (SRAM_DATA_WIDTH),
        .DATA_WIDTH_A    (DATA_WIDTH_A),
        .DATA_WIDTH_B    (DATA_WIDTH_B),
        .DATA_WIDTH_C    (DATA_WIDTH_C),
        .PREFETCH_DEPTH  (PREFETCH_DEPTH)
    ) dut (
        .clk                    (clk),
        .rst_n                  (rst_n),
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
        .dram_req_valid         (dram_req_valid),
        .dram_req_ready         (dram_req_ready),
        .dram_req_is_write      (dram_req_is_write),
        .dram_req_addr          (dram_req_addr),
        .dram_req_bytes         (dram_req_bytes),
        .dram_rvalid            (dram_rvalid),
        .dram_rready            (dram_rready),
        .dram_rdata             (dram_rdata),
        .dram_rlast             (dram_rlast),
        .dram_wvalid            (dram_wvalid),
        .dram_wready            (dram_wready),
        .dram_wdata             (dram_wdata),
        .dram_wlast             (dram_wlast),
        .dram_bvalid            (dram_bvalid),
        .dram_bready            (dram_bready),
        .sram_req_valid         (sram_req_valid),
        .sram_req_ready         (sram_req_ready),
        .sram_req_wen           (sram_req_wen),
        .sram_req_addr          (sram_req_addr),
        .sram_req_wdata         (sram_req_wdata),
        .sram_req_rdata         (sram_req_rdata),
        .sram_req_rdata_valid   (sram_req_rdata_valid)
    );
    
    // =========================================================================
    // SRAM Model
    // =========================================================================
    
    always_ff @(posedge clk) begin
        if (sram_req_valid && sram_req_ready) begin
            if (sram_req_wen) begin
                sram_model[sram_req_addr] <= sram_req_wdata;
                sram_req_rdata_valid <= 1'b0;
            end else begin
                sram_req_rdata <= sram_model[sram_req_addr];
                sram_req_rdata_valid <= 1'b1;
            end
        end else begin
            sram_req_rdata_valid <= 1'b0;
        end
    end
    
    // SRAM always ready
    assign sram_req_ready = 1'b1;
    
    // =========================================================================
    // DRAM Model
    // =========================================================================
    
    int dram_read_beat_count;
    int dram_read_total_beats;
    int dram_write_beat_count;
    logic [31:0] dram_read_addr;
    
    // DRAM Read Channel
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            dram_rvalid <= 1'b0;
            dram_rlast <= 1'b0;
            dram_read_beat_count <= 0;
            dram_read_total_beats <= 0;
            dram_read_addr <= 0;
        end else begin
            // Accept new read request
            if (dram_req_valid && dram_req_ready && !dram_req_is_write) begin
                dram_read_beat_count <= 0;
                dram_read_total_beats <= (dram_req_bytes + 15) / 16;  // 128b = 16 bytes
                dram_read_addr <= dram_req_addr;
                dram_rvalid <= 1'b1;
                dram_rlast <= 1'b0;
            end
            // Send read data
            else if (dram_rvalid && dram_rready) begin
                dram_read_beat_count <= dram_read_beat_count + 1;
                
                if (dram_read_beat_count + 1 >= dram_read_total_beats) begin
                    dram_rvalid <= 1'b0;  // Deassert rvalid after last beat
                    dram_rlast <= 1'b1;    // Assert rlast on last beat
                end else begin
                    dram_rvalid <= 1'b1;  // Keep rvalid asserted for next beat
                    dram_rlast <= 1'b0;
                end
            end
            // Hold rlast for one cycle after rvalid deasserts
            else if (dram_rlast) begin
                dram_rlast <= 1'b0;
            end
        end
    end
    
    // Read data from DRAM model
    always_comb begin
        dram_rdata = dram_model[(dram_read_addr >> 4) + dram_read_beat_count];
    end
    
    // DRAM Write Channel
    logic [31:0] dram_write_addr;  // Captured write address
    
    always_ff @(posedge clk) begin
        if (dram_req_valid && dram_req_ready && dram_req_is_write) begin
            dram_write_beat_count <= 0;
            dram_write_addr <= dram_req_addr;
        end
        
        if (dram_wvalid && dram_wready) begin
            dram_model[(dram_write_addr >> 4) + dram_write_beat_count] <= dram_wdata;
            dram_write_beat_count <= dram_write_beat_count + 1;
        end
    end
    
    // Write response
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            dram_bvalid <= 1'b0;
        end else begin
            if (dram_wvalid && dram_wready && dram_wlast) begin
                dram_bvalid <= 1'b1;
            end else if (dram_bready) begin
                dram_bvalid <= 1'b0;
            end
        end
    end
    
    assign dram_req_ready = 1'b1;
    assign dram_wready = 1'b1;
    
    // =========================================================================
    // Helper Tasks
    // =========================================================================
    
    // Task: Issue read request
    task issue_read_req(
        input [31:0] dram_addr_a, dram_addr_b,
        input [15:0] sram_addr_a, sram_addr_b,
        input [15:0] num_elem_a, num_elem_b
    );
        begin
            @(posedge clk);
            fetch_req_valid = 1'b1;
            fetch_req_is_write = 1'b0;
            fetch_req_dram_addr_a = dram_addr_a;
            fetch_req_dram_addr_b = dram_addr_b;
            fetch_req_sram_addr_a = sram_addr_a;
            fetch_req_sram_addr_b = sram_addr_b;
            fetch_req_num_elements_a = num_elem_a;
            fetch_req_num_elements_b = num_elem_b;
            
            @(posedge clk);
            while (!fetch_req_ready) @(posedge clk);
            
            fetch_req_valid = 1'b0;
        end
    endtask
    
    // Task: Issue write request
    task issue_write_req(
        input [31:0] dram_addr_c,
        input [15:0] sram_addr_c,
        input [15:0] num_elem_c
    );
        begin
            @(posedge clk);
            fetch_req_valid = 1'b1;
            fetch_req_is_write = 1'b1;
            fetch_req_dram_addr_c = dram_addr_c;
            fetch_req_sram_addr_c = sram_addr_c;
            fetch_req_num_elements_c = num_elem_c;
            
            @(posedge clk);
            while (!fetch_req_ready) @(posedge clk);
            
            fetch_req_valid = 1'b0;
        end
    endtask
    
    // =========================================================================
    // Main Test Sequence
    // =========================================================================
    
    initial begin
        int words_written;
        int words_written_partial;
        logic [127:0] written_beat;
        
        $display("TEST START");
        $display("=============================================================================");
        $display("DRAM Prefetch Engine Comprehensive Testbench");
        $display("=============================================================================");
        
        // Initialize
        rst_n = 0;
        fetch_req_valid = 0;
        fetch_req_is_write = 0;
        fetch_req_dram_addr_a = 0;
        fetch_req_dram_addr_b = 0;
        fetch_req_dram_addr_c = 0;
        fetch_req_sram_addr_a = 0;
        fetch_req_sram_addr_b = 0;
        fetch_req_sram_addr_c = 0;
        fetch_req_num_elements_a = 0;
        fetch_req_num_elements_b = 0;
        fetch_req_num_elements_c = 0;
        
        // Initialize memories
        for (int i = 0; i < 16384; i++) begin
            sram_model[i] = '0;
        end
        
        for (int i = 0; i < 4096; i++) begin
            dram_model[i] = {32'hDEAD_0000 | i[15:0], 
                            32'hBEEF_0000 | i[15:0],
                            32'hCAFE_0000 | i[15:0],
                            32'hBABE_0000 | i[15:0]};
        end
        
        // Reset
        repeat(5) @(posedge clk);
        rst_n = 1;
        repeat(2) @(posedge clk);
        
        // =====================================================================
        // TEST 1: Simple Read Request (Small Data)
        // =====================================================================
        $display("\n--- TEST 1: Simple Read A+B (4 elements each) ---");
        test_count++;
        
        issue_read_req(32'h0000_0000, 32'h0000_0010, 16'h0000, 16'h0100, 16'd4, 16'd4);
        
        // Wait for fetch_done
        wait(fetch_done);
        $display("LOG: %0t : INFO : tb_dram_pref : test1 : fetch_done received", $time);
        
        // Verify SRAM was written
        @(posedge clk);
        if (sram_model[16'h0000] != 0) begin
            $display("LOG: %0t : INFO : tb_dram_pref : test1_sram_a : SRAM A written: 0x%08h", 
                     $time, sram_model[16'h0000]);
        end
        
        if (sram_model[16'h0100] != 0) begin
            $display("LOG: %0t : INFO : tb_dram_pref : test1_sram_b : SRAM B written: 0x%08h", 
                     $time, sram_model[16'h0100]);
        end
        
        repeat(3) @(posedge clk);
        
        // =====================================================================
        // TEST 2: Width Conversion (128b DRAM → 32b SRAM)
        // =====================================================================
        $display("\n--- TEST 2: Width Conversion 128b→32b (16 elements) ---");
        test_count++;
        
        issue_read_req(32'h0000_0100, 32'h0000_0200, 16'h0200, 16'h0300, 16'd16, 16'd16);
        
        wait(fetch_done);
        $display("LOG: %0t : INFO : tb_dram_pref : test2 : fetch_done received", $time);
        
        // Check that 16 words were written
        @(posedge clk);
        words_written = 0;
        for (int i = 0; i < 16; i++) begin
            if (sram_model[16'h0200 + i] != 0) words_written++;
        end
        
        if (words_written == 16) begin
            $display("LOG: %0t : INFO : tb_dram_pref : test2_count : expected_value: 16 actual_value: %0d", 
                     $time, words_written);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_dram_pref : test2_count : expected_value: 16 actual_value: %0d", 
                     $time, words_written);
        end
        
        repeat(3) @(posedge clk);
        
        // =====================================================================
        // TEST 3: Write Request (32b SRAM → 128b DRAM)
        // =====================================================================
        $display("\n--- TEST 3: Write C (32b→128b upsizing) ---");
        test_count++;
        
        // Prepare SRAM data
        for (int i = 0; i < 8; i++) begin
            sram_model[16'h0400 + i] = 32'h1000_0000 | i;
        end
        
        issue_write_req(32'h0000_1000, 16'h0400, 16'd8);
        
        wait(fetch_done);
        $display("LOG: %0t : INFO : tb_dram_pref : test3 : fetch_done received", $time);
        
        // Verify DRAM was written (2 beats for 8 words)
        @(posedge clk);
        if (dram_model[32'h1000 >> 4] != 0) begin
            $display("LOG: %0t : INFO : tb_dram_pref : test3_dram : DRAM written: 0x%032h", 
                     $time, dram_model[32'h1000 >> 4]);
        end
        
        repeat(3) @(posedge clk);
        
        // =====================================================================
        // TEST 4: Queue Depth Test (Multiple Requests)
        // =====================================================================
        $display("\n--- TEST 4: Queue Management (Back-to-back requests) ---");
        test_count++;
        
        // Issue multiple requests back-to-back
        begin
            int done_count;
            done_count = 0;
            
            fork
                begin
                    issue_read_req(32'h0000_2000, 32'h0000_2100, 16'h0500, 16'h0600, 16'd4, 16'd4);
                end
            join_none
            
            fork
                begin
                    #(CLK_PERIOD * 2);
                    issue_read_req(32'h0000_2200, 32'h0000_2300, 16'h0700, 16'h0800, 16'd4, 16'd4);
                end
            join_none
            
            // Wait for both to complete: use edge-sensitive detection
            // to avoid missing or double-counting pulses
            while (done_count < 2) begin
                @(posedge clk);
                if (fetch_done) done_count++;
            end
        end
        
        $display("LOG: %0t : INFO : tb_dram_pref : test4 : Multiple requests completed", $time);
        
        repeat(3) @(posedge clk);
        
        // =====================================================================
        // TEST 5: Partial Beat (Non-aligned Size)
        // =====================================================================
        $display("\n--- TEST 5: Partial Beat Handling (7 elements = 1.75 beats) ---");
        test_count++;
        
        // 7 elements of 8-bit data = 7 bytes, needs 1 DRAM beat (16 bytes)
        issue_read_req(32'h0000_3000, 32'h0000_3100, 16'h0900, 16'h0A00, 16'd7, 16'd7);
        
        wait(fetch_done);
        $display("LOG: %0t : INFO : tb_dram_pref : test5 : Partial beat handled", $time);
        
        // Verify correct number of words written
        @(posedge clk);
        words_written_partial = 0;
        for (int i = 0; i < 7; i++) begin
            if (sram_model[16'h0900 + i] != 0) words_written_partial++;
        end
        
        if (words_written_partial == 7) begin
            $display("LOG: %0t : INFO : tb_dram_pref : test5_count : expected_value: 7 actual_value: %0d", 
                     $time, words_written_partial);
        end else begin
            error_count++;
            $display("LOG: %0t : ERROR : tb_dram_pref : test5_count : expected_value: 7 actual_value: %0d", 
                     $time, words_written_partial);
        end
        
        repeat(3) @(posedge clk);
        
        // =====================================================================
        // TEST 6: Queue Full Behavior
        // =====================================================================
        $display("\n--- TEST 6: Queue Full Handling ---");
        test_count++;
        
        // Fill the queue using issue_read_req which properly toggles valid
        // between requests (deasserts valid after each handshake, creating
        // the 0->1 edge the DUT's rising-edge detector needs for each push).
        begin
            int enqueued;
            int drain_count;
            enqueued = 0;
            
            for (int i = 0; i < PREFETCH_DEPTH; i++) begin
                // After first request, check if queue still has room
                if (i > 0 && !fetch_req_ready) begin
                    $display("LOG: %0t : INFO : tb_dram_pref : test6 : Queue filled at entry %0d", $time, i);
                    break;
                end
                issue_read_req(
                    32'h0000_4000 + (i * 32'h100),  // dram_addr_a
                    32'h0000_5000 + (i * 32'h100),  // dram_addr_b
                    16'h0B00 + (i[15:0] * 16'h10),  // sram_addr_a
                    16'h0C00 + (i[15:0] * 16'h10),  // sram_addr_b
                    16'd4,                           // num_elem_a
                    16'd4                            // num_elem_b
                );
                enqueued++;
            end
            
            $display("LOG: %0t : INFO : tb_dram_pref : test6 : Enqueued %0d requests", $time, enqueued);
            
            // Wait for all enqueued requests to complete
            drain_count = 0;
            while (drain_count < enqueued) begin
                @(posedge clk);
                if (fetch_done) drain_count++;
            end
        end
        
        $display("LOG: %0t : INFO : tb_dram_pref : test6 : Queue drained successfully", $time);
        
        repeat(3) @(posedge clk);
        
        // =====================================================================
        // TEST 7: Write with Zero Padding
        // =====================================================================
        $display("\n--- TEST 7: Write with Zero Padding (5 words) ---");
        test_count++;
        
        // Write 5 words (partial beat - should be zero-padded)
        for (int i = 0; i < 5; i++) begin
            sram_model[16'h0D00 + i] = 32'h2000_0000 | i;
        end
        
        issue_write_req(32'h0000_6000, 16'h0D00, 16'd5);
        
        wait(fetch_done);
        $display("LOG: %0t : INFO : tb_dram_pref : test7 : Write with zero padding completed", $time);
        
        // Check DRAM beat (should have 5 words + zeros)
        @(posedge clk);
        written_beat = dram_model[32'h6000 >> 4];
        $display("LOG: %0t : INFO : tb_dram_pref : test7_data : Written beat: 0x%032h", $time, written_beat);
        
        repeat(3) @(posedge clk);
        
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
        #100000;
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
