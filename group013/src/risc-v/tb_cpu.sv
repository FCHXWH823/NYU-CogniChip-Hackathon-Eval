// tb_cpu.sv
// Testbench for single-cycle RISC-V CPU with edge-aligned lockstep golden reference checking
//
// Strategy:
// - Posedge: snapshot the "fetch" PC/instruction for DUT and Golden (pre-step view).
// - Golden steps on posedge (same as DUT).
// - Negedge: compare using TEMPORARY (blocking) values so we don't trip on NBA ordering.

module tb_cpu;

    // Clock and reset
    logic clock;
    logic reset;

    // CPU-Memory interface signals
    logic [31:0] imem_addr;
    logic [31:0] imem_data;
    logic [31:0] dmem_addr;
    logic [31:0] dmem_wdata;
    logic [31:0] dmem_rdata;
    logic        dmem_write;
    logic        dmem_read;

    // CPU debug signals
    logic [31:0] dbg_pc;
    logic        dbg_regwrite;
    logic [4:0]  dbg_rd;
    logic [31:0] dbg_wdata;
    logic        dbg_memwrite;
    logic [31:0] dbg_memaddr;
    logic [31:0] dbg_memwdata;

    // Golden reference signals
    logic        golden_step_en;
    logic [31:0] golden_instr;  // Combinational instruction feed
    logic [31:0] g_pc;
    logic        g_regwrite;
    logic [4:0]  g_rd;
    logic [31:0] g_wdata;
    logic        g_memwrite;
    logic [31:0] g_memaddr;
    logic [31:0] g_memwdata;

    // Cycle counter and control
    int cycle_count;
    localparam int MAX_CYCLES = 20000;
    logic valid;  // comparisons valid after first committed instruction

    // Fetch snapshot (captured on posedge)
    logic [31:0] dut_f_pc;
    logic [31:0] dut_f_instr;
    logic [31:0] g_f_pc;
    logic [31:0] g_f_instr;

    // (Optional) Registered commit bundles (not required for correctness)
    logic [31:0] dut_c_pc;
    logic [31:0] dut_c_instr;
    logic        dut_c_regwrite;
    logic [4:0]  dut_c_rd;
    logic [31:0] dut_c_wdata;
    logic        dut_c_memwrite;
    logic [31:0] dut_c_memaddr;
    logic [31:0] dut_c_memwdata;

    logic [31:0] g_c_pc;
    logic [31:0] g_c_instr;
    logic        g_c_regwrite;
    logic [4:0]  g_c_rd;
    logic [31:0] g_c_wdata;
    logic        g_c_memwrite;
    logic [31:0] g_c_memaddr;
    logic [31:0] g_c_memwdata;

    // Clock generation (period = 10)
    initial begin
        clock = 0;
        forever #5 clock = ~clock;
    end

    // Reset generation (assert for 2 cycles)
    initial begin
        reset = 1;
        #20;
        reset = 0;
        $display("TEST START");
        $display("Reset deasserted at time %0t", $time);
    end

    // Instantiate DUT
    cpu_top u_cpu_top (
        .clock        (clock),
        .reset        (reset),
        .imem_addr    (imem_addr),
        .imem_data    (imem_data),
        .dmem_addr    (dmem_addr),
        .dmem_wdata   (dmem_wdata),
        .dmem_rdata   (dmem_rdata),
        .dmem_write   (dmem_write),
        .dmem_read    (dmem_read),
        .dbg_pc       (dbg_pc),
        .dbg_regwrite (dbg_regwrite),
        .dbg_rd       (dbg_rd),
        .dbg_wdata    (dbg_wdata),
        .dbg_memwrite (dbg_memwrite),
        .dbg_memaddr  (dbg_memaddr),
        .dbg_memwdata (dbg_memwdata)
    );

    // Instantiate memory model
    mem_model u_mem_model (
        .clock      (clock),
        .imem_addr  (imem_addr),
        .imem_data  (imem_data),
        .dmem_addr  (dmem_addr),
        .dmem_wdata (dmem_wdata),
        .dmem_rdata (dmem_rdata),
        .dmem_write (dmem_write),
        .dmem_read  (dmem_read)
    );

    // Golden instruction fetch and step enable
    assign golden_instr   = u_mem_model.imem[g_pc[31:2]];
    assign golden_step_en = ~reset;

    // Instantiate golden model (same clock edge as DUT)
    golden_rv32i #(.DMEM_WORDS(1024)) u_golden (
        .clk        (clock),
        .reset      (reset),
        .step_en    (golden_step_en),
        .instr      (golden_instr),
        .g_pc       (g_pc),
        .g_regwrite (g_regwrite),
        .g_rd       (g_rd),
        .g_wdata    (g_wdata),
        .g_memwrite (g_memwrite),
        .g_memaddr  (g_memaddr),
        .g_memwdata (g_memwdata)
    );

    // Posedge: snapshot fetch state
    always_ff @(posedge clock) begin
        if (reset) begin
            cycle_count <= 0;

            dut_f_pc    <= 32'h0;
            dut_f_instr <= 32'h0;
            g_f_pc      <= 32'h0;
            g_f_instr   <= 32'h0;
        end else begin
            cycle_count <= cycle_count + 1;

            dut_f_pc    <= dbg_pc;
            g_f_pc      <= g_pc;

            dut_f_instr <= u_mem_model.imem[dbg_pc[31:2]];
            g_f_instr   <= u_mem_model.imem[g_pc[31:2]];
        end
    end

    // Negedge: compare using temporaries (blocking)
    always_ff @(negedge clock) begin
        if (reset) begin
            valid <= 1'b0;

            // optional registered commit bundle reset
            dut_c_pc       <= 32'h0;
            dut_c_instr    <= 32'h0;
            dut_c_regwrite <= 1'b0;
            dut_c_rd       <= 5'd0;
            dut_c_wdata    <= 32'h0;
            dut_c_memwrite <= 1'b0;
            dut_c_memaddr  <= 32'h0;
            dut_c_memwdata <= 32'h0;

            g_c_pc         <= 32'h0;
            g_c_instr      <= 32'h0;
            g_c_regwrite   <= 1'b0;
            g_c_rd         <= 5'd0;
            g_c_wdata      <= 32'h0;
            g_c_memwrite   <= 1'b0;
            g_c_memaddr    <= 32'h0;
            g_c_memwdata   <= 32'h0;

        end else begin
            // Build "commit" view for THIS cycle using blocking temporaries
            logic [31:0] t_dut_pc, t_dut_instr;
            logic        t_dut_regwrite;
            logic [4:0]  t_dut_rd;
            logic [31:0] t_dut_wdata;
            logic        t_dut_memwrite;
            logic [31:0] t_dut_memaddr, t_dut_memwdata;

            logic [31:0] t_g_pc, t_g_instr;
            logic        t_g_regwrite;
            logic [4:0]  t_g_rd;
            logic [31:0] t_g_wdata;
            logic        t_g_memwrite;
            logic [31:0] t_g_memaddr, t_g_memwdata;

            // Commit corresponds to the instruction we snapped at posedge
            t_dut_pc       = dut_f_pc;
            t_dut_instr    = dut_f_instr;
            t_dut_regwrite = dbg_regwrite;
            t_dut_rd       = dbg_rd;
            t_dut_wdata    = dbg_wdata;
            t_dut_memwrite = dbg_memwrite;
            t_dut_memaddr  = dbg_memaddr;
            t_dut_memwdata = dbg_memwdata;

            t_g_pc         = g_f_pc;
            t_g_instr      = g_f_instr;
            t_g_regwrite   = g_regwrite;
            t_g_rd         = g_rd;
            t_g_wdata      = g_wdata;
            t_g_memwrite   = g_memwrite;
            t_g_memaddr    = g_memaddr;
            t_g_memwdata   = g_memwdata;

            // Optional: register commit bundles for waveform viewing
            dut_c_pc       <= t_dut_pc;
            dut_c_instr    <= t_dut_instr;
            dut_c_regwrite <= t_dut_regwrite;
            dut_c_rd       <= t_dut_rd;
            dut_c_wdata    <= t_dut_wdata;
            dut_c_memwrite <= t_dut_memwrite;
            dut_c_memaddr  <= t_dut_memaddr;
            dut_c_memwdata <= t_dut_memwdata;

            g_c_pc         <= t_g_pc;
            g_c_instr      <= t_g_instr;
            g_c_regwrite   <= t_g_regwrite;
            g_c_rd         <= t_g_rd;
            g_c_wdata      <= t_g_wdata;
            g_c_memwrite   <= t_g_memwrite;
            g_c_memaddr    <= t_g_memaddr;
            g_c_memwdata   <= t_g_memwdata;

            // Enable comparisons after first committed instruction
            if (!valid) begin
                valid <= 1'b1;
            end else begin
                // Check 1: PC
                if (t_dut_pc !== t_g_pc) begin
                    $display("\n========================================");
                    $display("ERROR: PC MISMATCH at cycle %0d", cycle_count);
                    $display("========================================");
                    $display("DUT Instruction:    0x%08h", t_dut_instr);
                    $display("Golden Instruction: 0x%08h", t_g_instr);
                    $display("DUT PC:    0x%08h", t_dut_pc);
                    $display("Golden PC: 0x%08h", t_g_pc);
                    $fatal(1, "TEST FAILED: PC mismatch");
                end

                // Check 2: Regwrite
                if (t_dut_regwrite || t_g_regwrite) begin
                    if (t_dut_regwrite !== t_g_regwrite) begin
                        $display("\n========================================");
                        $display("ERROR: REGWRITE FLAG MISMATCH at cycle %0d", cycle_count);
                        $display("========================================");
                        $display("PC: 0x%08h", t_dut_pc);
                        $display("Instruction: 0x%08h", t_dut_instr);
                        $display("DUT regwrite: %0b", t_dut_regwrite);
                        $display("Golden regwrite: %0b", t_g_regwrite);
                        $fatal(1, "TEST FAILED: Register write flag mismatch");
                    end

                    if (t_dut_regwrite) begin
                        if (t_dut_rd !== t_g_rd) begin
                            $display("\n========================================");
                            $display("ERROR: DESTINATION REGISTER MISMATCH at cycle %0d", cycle_count);
                            $display("========================================");
                            $display("PC: 0x%08h", t_dut_pc);
                            $display("Instruction: 0x%08h", t_dut_instr);
                            $display("DUT rd:    x%0d", t_dut_rd);
                            $display("Golden rd: x%0d", t_g_rd);
                            $fatal(1, "TEST FAILED: Destination register mismatch");
                        end

                        if (t_dut_wdata !== t_g_wdata) begin
                            $display("\n========================================");
                            $display("ERROR: REGISTER WRITE DATA MISMATCH at cycle %0d", cycle_count);
                            $display("========================================");
                            $display("PC: 0x%08h", t_dut_pc);
                            $display("Instruction: 0x%08h", t_dut_instr);
                            $display("Register: x%0d", t_dut_rd);
                            $display("DUT    wdata: 0x%08h", t_dut_wdata);
                            $display("Golden wdata: 0x%08h", t_g_wdata);
                            $fatal(1, "TEST FAILED: Register write data mismatch");
                        end
                    end
                end

                // Check 3: Memwrite
                if (t_dut_memwrite || t_g_memwrite) begin
                    if (t_dut_memwrite !== t_g_memwrite) begin
                        $display("\n========================================");
                        $display("ERROR: MEMWRITE FLAG MISMATCH at cycle %0d", cycle_count);
                        $display("========================================");
                        $display("PC: 0x%08h", t_dut_pc);
                        $display("Instruction: 0x%08h", t_dut_instr);
                        $display("DUT memwrite: %0b", t_dut_memwrite);
                        $display("Golden memwrite: %0b", t_g_memwrite);
                        $fatal(1, "TEST FAILED: Memory write flag mismatch");
                    end

                    if (t_dut_memwrite) begin
                        if (t_dut_memaddr !== t_g_memaddr) begin
                            $display("\n========================================");
                            $display("ERROR: MEMORY ADDRESS MISMATCH at cycle %0d", cycle_count);
                            $display("========================================");
                            $display("PC: 0x%08h", t_dut_pc);
                            $display("Instruction: 0x%08h", t_dut_instr);
                            $display("DUT memaddr:    0x%08h", t_dut_memaddr);
                            $display("Golden memaddr: 0x%08h", t_g_memaddr);
                            $fatal(1, "TEST FAILED: Memory address mismatch");
                        end

                        if (t_dut_memwdata !== t_g_memwdata) begin
                            $display("\n========================================");
                            $display("ERROR: MEMORY WRITE DATA MISMATCH at cycle %0d", cycle_count);
                            $display("========================================");
                            $display("PC: 0x%08h", t_dut_pc);
                            $display("Instruction: 0x%08h", t_dut_instr);
                            $display("Address: 0x%08h", t_dut_memaddr);
                            $display("DUT    wdata: 0x%08h", t_dut_memwdata);
                            $display("Golden wdata: 0x%08h", t_g_memwdata);
                            $fatal(1, "TEST FAILED: Memory write data mismatch");
                        end
                    end
                end

                // Completion
                if (t_dut_memwrite &&
                    t_dut_memaddr  == 32'h0000_0100 &&
                    t_dut_memwdata == 32'h0000_0001) begin
                    $display("\n========================================");
                    $display("TEST PASSED");
                    $display("========================================");
                    $display("Completion detected at cycle %0d", cycle_count);
                    $finish;
                end

                // Timeout
                if (cycle_count >= MAX_CYCLES) begin
                    $display("ERROR: Maximum cycle limit (%0d) reached", MAX_CYCLES);
                    $fatal(1, "TEST FAILED: Timeout");
                end
            end
        end
    end

    // Waveform dump
    initial begin
        $dumpfile("dumpfile.fst");
        $dumpvars(0, tb_cpu);
    end

endmodule
