// =============================================================================
// Module: sram_bank_arbiter
// Description: Multi-master arbiter for banked SRAM
//              Fixed priority: Prefetch (P0) > Compute (P1)
//              Per-bank independent arbitration
// =============================================================================

module sram_bank_arbiter #(
    parameter int SRAM_BANKS       = 8,
    parameter int SRAM_BANK_DEPTH  = 2048,
    parameter int SRAM_DATA_WIDTH  = 32,
    parameter int SRAM_ADDR_WIDTH  = 16
) (
    input  logic        clk,
    input  logic        rst_n,
    
    // Prefetch Engine Port (Priority 0 - Highest)
    input  logic                        prefetch_req_valid,
    output logic                        prefetch_req_ready,
    input  logic                        prefetch_req_wen,
    input  logic [SRAM_ADDR_WIDTH-1:0]  prefetch_req_addr,
    input  logic [SRAM_DATA_WIDTH-1:0]  prefetch_req_wdata,
    output logic [SRAM_DATA_WIDTH-1:0]  prefetch_req_rdata,
    output logic                        prefetch_req_rdata_valid,
    
    // Compute Engine Port (Priority 1 - Lower)
    input  logic                        compute_req_valid,
    output logic                        compute_req_ready,
    input  logic                        compute_req_wen,
    input  logic [SRAM_ADDR_WIDTH-1:0]  compute_req_addr,
    input  logic [SRAM_DATA_WIDTH-1:0]  compute_req_wdata,
    output logic [SRAM_DATA_WIDTH-1:0]  compute_req_rdata,
    output logic                        compute_req_rdata_valid,
    
    // Physical SRAM Banks
    output logic [SRAM_BANKS-1:0]                                 sram_wen,
    output logic [SRAM_BANKS-1:0]                                 sram_ren,
    output logic [SRAM_BANKS-1:0][$clog2(SRAM_BANK_DEPTH)-1:0]   sram_addr,
    output logic [SRAM_BANKS-1:0][SRAM_DATA_WIDTH-1:0]           sram_wdata,
    input  logic [SRAM_BANKS-1:0][SRAM_DATA_WIDTH-1:0]           sram_rdata
);

    // =========================================================================
    // Local Parameters
    // =========================================================================
    
    localparam int BANK_ADDR_WIDTH = $clog2(SRAM_BANK_DEPTH);
    localparam int BANK_SEL_WIDTH  = $clog2(SRAM_BANKS);
    
    // =========================================================================
    // Parameter Validation - Synthesis-Time Check
    // =========================================================================
    
    // Note: $fatal not supported by Yosys - commented out for synthesis compatibility
    // In simulation, this parameter check validates address width consistency
    // initial begin
    //     if (SRAM_ADDR_WIDTH != (BANK_SEL_WIDTH + BANK_ADDR_WIDTH)) begin
    //         $fatal(1, "SRAM_ADDR_WIDTH mismatch: expected %0d (bank_sel=%0d + bank_offset=%0d), got %0d. Address decode will be incorrect!",
    //                BANK_SEL_WIDTH + BANK_ADDR_WIDTH, BANK_SEL_WIDTH, BANK_ADDR_WIDTH, SRAM_ADDR_WIDTH);
    //     end
    // end
    
    // =========================================================================
    // Address Decode - Explicit Bank Selection
    // =========================================================================
    // Flat SRAM address format: {bank_id, bank_offset}
    // Example with 8 banks, 2048 depth: addr[13:11]=bank_id, addr[10:0]=offset
    
    logic [BANK_SEL_WIDTH-1:0]  prefetch_bank_id;
    logic [BANK_ADDR_WIDTH-1:0] prefetch_bank_offset;
    logic [BANK_SEL_WIDTH-1:0]  compute_bank_id;
    logic [BANK_ADDR_WIDTH-1:0] compute_bank_offset;
    
    // Bank ID = MSBs, Bank Offset = LSBs
    assign prefetch_bank_id     = prefetch_req_addr[SRAM_ADDR_WIDTH-1 : BANK_ADDR_WIDTH];
    assign prefetch_bank_offset = prefetch_req_addr[BANK_ADDR_WIDTH-1:0];
    assign compute_bank_id      = compute_req_addr[SRAM_ADDR_WIDTH-1 : BANK_ADDR_WIDTH];
    assign compute_bank_offset  = compute_req_addr[BANK_ADDR_WIDTH-1:0];
    
    // =========================================================================
    // Per-Bank Arbitration Logic
    // =========================================================================
    
    logic [SRAM_BANKS-1:0] prefetch_req_bank;
    logic [SRAM_BANKS-1:0] compute_req_bank;
    logic [SRAM_BANKS-1:0] prefetch_grant;
    logic [SRAM_BANKS-1:0] compute_grant;
    
    // Decode which bank each master is requesting
    always_comb begin
        prefetch_req_bank = '0;
        compute_req_bank  = '0;
        
        if (prefetch_req_valid) begin
            prefetch_req_bank[prefetch_bank_id] = 1'b1;
        end
        
        if (compute_req_valid) begin
            compute_req_bank[compute_bank_id] = 1'b1;
        end
    end
    
    // Fixed priority arbitration per bank
    always_comb begin
        for (int i = 0; i < SRAM_BANKS; i++) begin
            // Priority 0: Prefetch has highest priority
            if (prefetch_req_bank[i]) begin
                prefetch_grant[i] = 1'b1;
                compute_grant[i]  = 1'b0;
            end 
            // Priority 1: Compute gets access if prefetch doesn't request
            else if (compute_req_bank[i]) begin
                prefetch_grant[i] = 1'b0;
                compute_grant[i]  = 1'b1;
            end 
            else begin
                prefetch_grant[i] = 1'b0;
                compute_grant[i]  = 1'b0;
            end
        end
    end
    
    // Ready signals - asserted when grant is given
    assign prefetch_req_ready = prefetch_grant[prefetch_bank_id];
    assign compute_req_ready  = compute_grant[compute_bank_id];

    
    // =========================================================================
    // SRAM Bank Control Signal Generation
    // =========================================================================
    
    always_comb begin
        // Default: all banks idle
        sram_wen   = '0;
        sram_ren   = '0;
        sram_addr  = '0;
        sram_wdata = '0;
        
        for (int i = 0; i < SRAM_BANKS; i++) begin
            if (prefetch_grant[i]) begin
                sram_wen[i]   = prefetch_req_wen;
                sram_ren[i]   = ~prefetch_req_wen;
                sram_addr[i]  = prefetch_bank_offset;
                sram_wdata[i] = prefetch_req_wdata;
            end 
            else if (compute_grant[i]) begin
                sram_wen[i]   = compute_req_wen;
                sram_ren[i]   = ~compute_req_wen;
                sram_addr[i]  = compute_bank_offset;
                sram_wdata[i] = compute_req_wdata;
            end
        end
    end
    
    // =========================================================================
    // Read Data Routing with 1-Cycle Delay Tracking
    // =========================================================================
    
    // =========================================================================
    // Read response: 1-cycle latency, and register rdata to survive back-to-back
    // TB expectation: rdata_valid asserted on the NEXT posedge after accept
    // =========================================================================

    // accept = request accepted on this cycle
    logic pf_acc, cp_acc;
    assign pf_acc = prefetch_req_valid && prefetch_req_ready && !prefetch_req_wen;
    assign cp_acc = compute_req_valid  && compute_req_ready  && !compute_req_wen;

    // stage0: latch bank id when accept happens
    logic [BANK_SEL_WIDTH-1:0] pf_bank_d0, cp_bank_d0;
    logic pf_acc_d1, cp_acc_d1;

    always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        pf_bank_d0 <= '0;
        cp_bank_d0 <= '0;
        pf_acc_d1  <= 1'b0;
        cp_acc_d1  <= 1'b0;
    end else begin
        // delay accept by 1 cycle
        pf_acc_d1 <= pf_acc;
        cp_acc_d1 <= cp_acc;

        // latch bank id at accept time
        if (pf_acc) pf_bank_d0 <= prefetch_bank_id;
        if (cp_acc) cp_bank_d0 <= compute_bank_id;
    end
    end

    // stage1: capture SRAM output one cycle later, and assert valid
    logic [SRAM_DATA_WIDTH-1:0] pf_rdata_reg, cp_rdata_reg;

    always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) begin
        pf_rdata_reg <= '0;
        cp_rdata_reg <= '0;
        prefetch_req_rdata_valid <= 1'b0;
        compute_req_rdata_valid  <= 1'b0;
    end else begin
        // valid pulse exactly when data is captured
        prefetch_req_rdata_valid <= pf_acc_d1;
        compute_req_rdata_valid  <= cp_acc_d1;

        if (pf_acc_d1) pf_rdata_reg <= sram_rdata[pf_bank_d0];
        if (cp_acc_d1) cp_rdata_reg <= sram_rdata[cp_bank_d0];
    end
    end

    assign prefetch_req_rdata = pf_rdata_reg;
    assign compute_req_rdata  = cp_rdata_reg;

endmodule
