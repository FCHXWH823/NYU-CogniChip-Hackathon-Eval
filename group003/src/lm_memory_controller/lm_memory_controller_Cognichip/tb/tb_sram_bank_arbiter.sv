// =============================================================================
// Testbench: tb_sram_bank_arbiter
// Description: Comprehensive testbench for SRAM bank arbiter
//              Tests priority arbitration, parallel access, and bank conflicts
// =============================================================================

module tb_sram_bank_arbiter;

    // =========================================================================
    // Parameters - Match DUT configuration
    // =========================================================================
    
    parameter int SRAM_BANKS       = 8;
    parameter int SRAM_BANK_DEPTH  = 2048;
    parameter int SRAM_DATA_WIDTH  = 32;
    parameter int SRAM_ADDR_WIDTH  = 14;  // log2(8*2048) = 3 + 11 = 14
    
    localparam int BANK_ADDR_WIDTH = $clog2(SRAM_BANK_DEPTH);  // 11 bits
    localparam int BANK_SEL_WIDTH  = $clog2(SRAM_BANKS);       // 3 bits
    
    localparam int CLK_PERIOD = 10;
    localparam int TEST_TIMEOUT = 100000;
    
    // =========================================================================
    // DUT Signals
    // =========================================================================
    
    logic                        clk;
    logic                        rst_n;
    
    // Prefetch Engine Port
    logic                        prefetch_req_valid;
    logic                        prefetch_req_ready;
    logic                        prefetch_req_wen;
    logic [SRAM_ADDR_WIDTH-1:0]  prefetch_req_addr;
    logic [SRAM_DATA_WIDTH-1:0]  prefetch_req_wdata;
    logic [SRAM_DATA_WIDTH-1:0]  prefetch_req_rdata;
    logic                        prefetch_req_rdata_valid;
    
    // Compute Engine Port
    logic                        compute_req_valid;
    logic                        compute_req_ready;
    logic                        compute_req_wen;
    logic [SRAM_ADDR_WIDTH-1:0]  compute_req_addr;
    logic [SRAM_DATA_WIDTH-1:0]  compute_req_wdata;
    logic [SRAM_DATA_WIDTH-1:0]  compute_req_rdata;
    logic                        compute_req_rdata_valid;
    
    // Physical SRAM Banks
    logic [SRAM_BANKS-1:0]                       sram_wen;
    logic [SRAM_BANKS-1:0]                       sram_ren;
    logic [SRAM_BANKS-1:0][BANK_ADDR_WIDTH-1:0]  sram_addr;
    logic [SRAM_BANKS-1:0][SRAM_DATA_WIDTH-1:0]  sram_wdata;
    logic [SRAM_BANKS-1:0][SRAM_DATA_WIDTH-1:0]  sram_rdata;
    
    // =========================================================================
    // Test Control Variables
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
    
    sram_bank_arbiter #(
        .SRAM_BANKS      (SRAM_BANKS),
        .SRAM_BANK_DEPTH (SRAM_BANK_DEPTH),
        .SRAM_DATA_WIDTH (SRAM_DATA_WIDTH),
        .SRAM_ADDR_WIDTH (SRAM_ADDR_WIDTH)
    ) dut (
        .clk                      (clk),
        .rst_n                    (rst_n),
        .prefetch_req_valid       (prefetch_req_valid),
        .prefetch_req_ready       (prefetch_req_ready),
        .prefetch_req_wen         (prefetch_req_wen),
        .prefetch_req_addr        (prefetch_req_addr),
        .prefetch_req_wdata       (prefetch_req_wdata),
        .prefetch_req_rdata       (prefetch_req_rdata),
        .prefetch_req_rdata_valid (prefetch_req_rdata_valid),
        .compute_req_valid        (compute_req_valid),
        .compute_req_ready        (compute_req_ready),
        .compute_req_wen          (compute_req_wen),
        .compute_req_addr         (compute_req_addr),
        .compute_req_wdata        (compute_req_wdata),
        .compute_req_rdata        (compute_req_rdata),
        .compute_req_rdata_valid  (compute_req_rdata_valid),
        .sram_wen                 (sram_wen),
        .sram_ren                 (sram_ren),
        .sram_addr                (sram_addr),
        .sram_wdata               (sram_wdata),
        .sram_rdata               (sram_rdata)
    );
    
    // =========================================================================
    // SRAM Bank Models (Simple Memory Array)
    // =========================================================================
    
    logic [SRAM_DATA_WIDTH-1:0] sram_memory [SRAM_BANKS][SRAM_BANK_DEPTH];
    
    // SRAM read/write behavior with 1-cycle read latency
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
    
    // =========================================================================
    // Helper Functions
    // =========================================================================
    
    // Function to build full address from bank_id and offset
    function automatic logic [SRAM_ADDR_WIDTH-1:0] make_addr(
        input logic [BANK_SEL_WIDTH-1:0] bank_id,
        input logic [BANK_ADDR_WIDTH-1:0] bank_offset
    );
        return {bank_id, bank_offset};
    endfunction
    
    // Function to extract bank_id from address
    function automatic logic [BANK_SEL_WIDTH-1:0] get_bank_id(
        input logic [SRAM_ADDR_WIDTH-1:0] addr
    );
        return addr[SRAM_ADDR_WIDTH-1 : BANK_ADDR_WIDTH];
    endfunction
    
    // =========================================================================
    // Task: Reset Sequence
    // =========================================================================
    
    task automatic reset_dut();
        begin
            rst_n = 0;
            prefetch_req_valid = 0;
            prefetch_req_wen = 0;
            prefetch_req_addr = '0;
            prefetch_req_wdata = '0;
            compute_req_valid = 0;
            compute_req_wen = 0;
            compute_req_addr = '0;
            compute_req_wdata = '0;
            
            repeat(5) @(posedge clk);
            rst_n = 1;
            repeat(2) @(posedge clk);
        end
    endtask
    
    // =========================================================================
    // Task: Prefetch Write
    // =========================================================================
    
    task automatic prefetch_write(
        input logic [SRAM_ADDR_WIDTH-1:0] addr,
        input logic [SRAM_DATA_WIDTH-1:0] data
    );
        begin
            @(posedge clk); #1;
            prefetch_req_valid = 1'b1;
            prefetch_req_wen = 1'b1;
            prefetch_req_addr = addr;
            prefetch_req_wdata = data;
            
            @(posedge clk);
            while (!prefetch_req_ready) @(posedge clk);
            #1;
            prefetch_req_valid = 1'b0;
            prefetch_req_wen = 1'b0;
        end
    endtask
    
    // =========================================================================
    // Task: Prefetch Read
    // =========================================================================
    
    task automatic prefetch_read(
        input logic [SRAM_ADDR_WIDTH-1:0] addr,
        output logic [SRAM_DATA_WIDTH-1:0] data
    );
        begin
            @(posedge clk); #1;
            prefetch_req_valid = 1'b1;
            prefetch_req_wen = 1'b0;
            prefetch_req_addr = addr;
            
            @(posedge clk);
            while (!prefetch_req_ready) @(posedge clk);
            #1;
            prefetch_req_valid = 1'b0;
            
            // Wait for rdata_valid (1 cycle delay)
            @(posedge clk);
            while (!prefetch_req_rdata_valid) @(posedge clk);
            data = prefetch_req_rdata;
        end
    endtask
    
    // =========================================================================
    // Task: Compute Write
    // =========================================================================
    
    task automatic compute_write(
        input logic [SRAM_ADDR_WIDTH-1:0] addr,
        input logic [SRAM_DATA_WIDTH-1:0] data
    );
        begin
            @(posedge clk); #1;
            compute_req_valid = 1'b1;
            compute_req_wen = 1'b1;
            compute_req_addr = addr;
            compute_req_wdata = data;
            
            @(posedge clk);
            while (!compute_req_ready) @(posedge clk);
            #1;
            compute_req_valid = 1'b0;
            compute_req_wen = 1'b0;
        end
    endtask
    
    // =========================================================================
    // Task: Compute Read
    // =========================================================================
    
    task automatic compute_read(
        input logic [SRAM_ADDR_WIDTH-1:0] addr,
        output logic [SRAM_DATA_WIDTH-1:0] data
    );
        begin
            @(posedge clk); #1;
            compute_req_valid = 1'b1;
            compute_req_wen = 1'b0;
            compute_req_addr = addr;
            
            @(posedge clk);
            while (!compute_req_ready) @(posedge clk);
            #1;
            compute_req_valid = 1'b0;
            
            // Wait for rdata_valid (1 cycle delay)
            @(posedge clk);
            while (!compute_req_rdata_valid) @(posedge clk);
            data = compute_req_rdata;
        end
    endtask
    
    // =========================================================================
    // Task: Check Result
    // =========================================================================
    
    task automatic check_result(
        input string test_name,
        input logic [SRAM_DATA_WIDTH-1:0] expected,
        input logic [SRAM_DATA_WIDTH-1:0] actual
    );
        begin
            test_count++;
            if (expected !== actual) begin
                error_count++;
                $display("LOG: %0t : ERROR : tb_sram_bank_arbiter : %s : expected_value: 0x%08h actual_value: 0x%08h", 
                         $time, test_name, expected, actual);
            end else begin
                $display("LOG: %0t : INFO : tb_sram_bank_arbiter : %s : expected_value: 0x%08h actual_value: 0x%08h", 
                         $time, test_name, expected, actual);
            end
        end
    endtask
    
    // =========================================================================
    // Main Test Sequence
    // =========================================================================
    
    initial begin
        $display("TEST START");
        $display("=============================================================================");
        $display("Starting SRAM Bank Arbiter Testbench");
        $display("SRAM_BANKS=%0d, SRAM_BANK_DEPTH=%0d, SRAM_DATA_WIDTH=%0d, SRAM_ADDR_WIDTH=%0d",
                 SRAM_BANKS, SRAM_BANK_DEPTH, SRAM_DATA_WIDTH, SRAM_ADDR_WIDTH);
        $display("BANK_SEL_WIDTH=%0d, BANK_ADDR_WIDTH=%0d", BANK_SEL_WIDTH, BANK_ADDR_WIDTH);
        $display("=============================================================================");
        
        // Initialize memory
        for (int i = 0; i < SRAM_BANKS; i++) begin
            for (int j = 0; j < SRAM_BANK_DEPTH; j++) begin
                sram_memory[i][j] = '0;
            end
        end
        
        reset_dut();
        
        // =====================================================================
        // TEST 1: Basic Prefetch Write and Read
        // =====================================================================
        begin
            logic [SRAM_DATA_WIDTH-1:0] read_data;
            logic [SRAM_ADDR_WIDTH-1:0] test_addr;
            logic [SRAM_DATA_WIDTH-1:0] test_data;
            
            $display("\n--- TEST 1: Basic Prefetch Write/Read ---");
            test_addr = make_addr(3'h0, 11'h100);  // Bank 0, offset 0x100
            test_data = 32'hDEADBEEF;
            
            prefetch_write(test_addr, test_data);
            prefetch_read(test_addr, read_data);
            check_result("test1_prefetch_basic", test_data, read_data);
        end
        
        // =====================================================================
        // TEST 2: Basic Compute Write and Read
        // =====================================================================
        begin
            logic [SRAM_DATA_WIDTH-1:0] read_data;
            logic [SRAM_ADDR_WIDTH-1:0] test_addr;
            logic [SRAM_DATA_WIDTH-1:0] test_data;
            
            $display("\n--- TEST 2: Basic Compute Write/Read ---");
            test_addr = make_addr(3'h1, 11'h200);  // Bank 1, offset 0x200
            test_data = 32'hCAFEBABE;
            
            compute_write(test_addr, test_data);
            compute_read(test_addr, read_data);
            check_result("test2_compute_basic", test_data, read_data);
        end
        
        // =====================================================================
        // TEST 3: Priority Arbitration - Prefetch preempts Compute
        // =====================================================================
        begin
            logic [SRAM_ADDR_WIDTH-1:0] addr_bank2;
            
            $display("\n--- TEST 3: Priority Arbitration (Same Bank) ---");
            addr_bank2 = make_addr(3'h2, 11'h300);  // Both access Bank 2
            
            // Write test data first
            prefetch_write(addr_bank2, 32'h12345678);
            
            fork
                // Prefetch attempts read (should win)
                begin
                    logic [SRAM_DATA_WIDTH-1:0] pf_data;
                    @(posedge clk); #1;
                    prefetch_req_valid = 1'b1;
                    prefetch_req_wen = 1'b0;
                    prefetch_req_addr = addr_bank2;
                    @(posedge clk);
                    if (prefetch_req_ready) begin
                        $display("LOG: %0t : INFO : tb_sram_bank_arbiter : test3_priority : Prefetch granted (correct)", $time);
                    end else begin
                        error_count++;
                        $display("LOG: %0t : ERROR : tb_sram_bank_arbiter : test3_priority : Prefetch NOT granted (incorrect)", $time);
                    end
                    #1;
                    prefetch_req_valid = 1'b0;
                end
                
                // Compute attempts read (should lose)
                begin
                    logic [SRAM_DATA_WIDTH-1:0] cmp_data;
                    @(posedge clk); #1;
                    compute_req_valid = 1'b1;
                    compute_req_wen = 1'b0;
                    compute_req_addr = addr_bank2;
                    @(posedge clk);
                    if (!compute_req_ready) begin
                        $display("LOG: %0t : INFO : tb_sram_bank_arbiter : test3_priority : Compute blocked (correct)", $time);
                    end else begin
                        error_count++;
                        $display("LOG: %0t : ERROR : tb_sram_bank_arbiter : test3_priority : Compute granted (incorrect)", $time);
                    end
                    #1;
                    compute_req_valid = 1'b0;
                end
            join
            
            test_count++;
            repeat(3) @(posedge clk);
        end
        
        // =====================================================================
        // TEST 4: Parallel Access to Different Banks
        // =====================================================================
        begin
            logic [SRAM_ADDR_WIDTH-1:0] addr_bank3, addr_bank4;
            logic [SRAM_DATA_WIDTH-1:0] data_bank3, data_bank4;
            
            $display("\n--- TEST 4: Parallel Access (Different Banks) ---");
            addr_bank3 = make_addr(3'h3, 11'h400);  // Bank 3
            addr_bank4 = make_addr(3'h4, 11'h500);  // Bank 4
            data_bank3 = 32'hAAAA5555;
            data_bank4 = 32'h5555AAAA;
            
            // Write test data first
            prefetch_write(addr_bank3, data_bank3);
            compute_write(addr_bank4, data_bank4);
            
            fork
                // Prefetch reads Bank 3
                begin
                    logic [SRAM_DATA_WIDTH-1:0] pf_data;
                    @(posedge clk); #1;
                    prefetch_req_valid = 1'b1;
                    prefetch_req_wen = 1'b0;
                    prefetch_req_addr = addr_bank3;
                    @(posedge clk);
                    if (prefetch_req_ready) begin
                        $display("LOG: %0t : INFO : tb_sram_bank_arbiter : test4_parallel_pf : Prefetch granted Bank 3", $time);
                    end
                    #1;
                    prefetch_req_valid = 1'b0;
                end
                
                // Compute reads Bank 4 (should also succeed)
                begin
                    logic [SRAM_DATA_WIDTH-1:0] cmp_data;
                    @(posedge clk); #1;
                    compute_req_valid = 1'b1;
                    compute_req_wen = 1'b0;
                    compute_req_addr = addr_bank4;
                    @(posedge clk);
                    if (compute_req_ready) begin
                        $display("LOG: %0t : INFO : tb_sram_bank_arbiter : test4_parallel_cmp : Compute granted Bank 4", $time);
                    end else begin
                        error_count++;
                        $display("LOG: %0t : ERROR : tb_sram_bank_arbiter : test4_parallel_cmp : Compute blocked (incorrect)", $time);
                    end
                    #1;
                    compute_req_valid = 1'b0;
                end
            join
            
            test_count++;
            repeat(3) @(posedge clk);
        end
        
        // =====================================================================
        // TEST 5: Address Decode Verification - All Banks
        // =====================================================================
        begin
            logic [SRAM_DATA_WIDTH-1:0] read_data;
            
            $display("\n--- TEST 5: Address Decode (All Banks) ---");
            for (int bank = 0; bank < SRAM_BANKS; bank++) begin
                logic [SRAM_ADDR_WIDTH-1:0] test_addr;
                logic [SRAM_DATA_WIDTH-1:0] test_data;
                
                test_addr = make_addr(bank[BANK_SEL_WIDTH-1:0], 11'h010);
                test_data = 32'h1000_0000 | (bank << 16) | 16'hBEEF;
                
                prefetch_write(test_addr, test_data);
                compute_read(test_addr, read_data);
                check_result($sformatf("test5_bank%0d_decode", bank), test_data, read_data);
            end
        end
        
        // =====================================================================
        // TEST 6: Back-to-Back Transactions
        // =====================================================================
        begin
            logic [SRAM_DATA_WIDTH-1:0] read_data;
            logic [SRAM_ADDR_WIDTH-1:0] addr;
            
            $display("\n--- TEST 6: Back-to-Back Transactions ---");
            for (int i = 0; i < 10; i++) begin
                addr = make_addr(3'h5, 11'h020 + i);
                prefetch_write(addr, 32'h6000_0000 | i);
            end
            
            for (int i = 0; i < 10; i++) begin
                addr = make_addr(3'h5, 11'h020 + i);
                compute_read(addr, read_data);
                check_result($sformatf("test6_burst_%0d", i), 32'h6000_0000 | i, read_data);
            end
        end
        
        // =====================================================================
        // TEST 7: Read Data Routing Verification
        // =====================================================================
        begin
            logic [SRAM_DATA_WIDTH-1:0] pf_data, cmp_data;
            logic [SRAM_ADDR_WIDTH-1:0] addr_bank6, addr_bank7;
            
            $display("\n--- TEST 7: Read Data Routing ---");
            addr_bank6 = make_addr(3'h6, 11'h600);
            addr_bank7 = make_addr(3'h7, 11'h700);
            
            prefetch_write(addr_bank6, 32'h6666_6666);
            compute_write(addr_bank7, 32'h7777_7777);
            
            prefetch_read(addr_bank6, pf_data);
            compute_read(addr_bank7, cmp_data);
            
            check_result("test7_prefetch_routing", 32'h6666_6666, pf_data);
            check_result("test7_compute_routing", 32'h7777_7777, cmp_data);
        end
        
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
        #TEST_TIMEOUT;
        $display("\n=============================================================================");
        $display("ERROR: Test timeout after %0d time units", TEST_TIMEOUT);
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
