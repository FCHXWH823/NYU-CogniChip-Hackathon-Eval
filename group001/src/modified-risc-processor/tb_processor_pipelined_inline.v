// =============================================================================
// E20 Pipelined Processor Testbench - Inline Test
// =============================================================================
// Simple inline test to verify pipelined processor functionality
// =============================================================================

`timescale 1ns/1ps

module tb_processor_pipelined_inline;

    // Parameters
    parameter CLK_PERIOD = 10;
    parameter MAX_CYCLES = 1000;
    
    // Signals
    reg         clock;
    reg         reset;
    wire        halt;
    wire [15:0] debug_pc;
    wire [15:0] debug_instr;
    wire [31:0] debug_cycle;
    
    integer cycle_count;
    
    // DUT Instantiation
    processor_pipelined dut (
        .clock(clock),
        .reset(reset),
        .halt(halt),
        .debug_pc(debug_pc),
        .debug_instr(debug_instr),
        .debug_cycle(debug_cycle)
    );
    
    // Clock Generation
    initial begin
        clock = 0;
        forever #(CLK_PERIOD/2) clock = ~clock;
    end
    
    // Initialize memory with a simple test program
    integer mem_init_idx;
    initial begin
        $display("TEST START");
        
        // Initialize all memory to zero
        for (mem_init_idx = 0; mem_init_idx < 8192; mem_init_idx = mem_init_idx + 1) begin
            dut.ram[mem_init_idx] = 16'h0000;
        end
        
        // Load simple test program
        // Simple arithmetic and halt
        dut.ram[0] = 16'b0010000010000101;  // addi $1, $0, 5    - $1 = 5
        dut.ram[1] = 16'b0010000100000011;  // addi $2, $0, 3    - $2 = 3
        dut.ram[2] = 16'b0000100111000000;  // add $3, $2, $1    - $3 = $2 + $1 = 8
        dut.ram[3] = 16'b0000010100011001;  // sub $4, $1, $2    - $4 = $1 - $2 = 2
        dut.ram[4] = 16'b0000000011101010;  // or $5, $1, $2     - $5 = $1 | $2
        dut.ram[5] = 16'b0100000000000101;  // j 5               - Halt loop (jump to self)
        
        $display("========================================");
        $display("E20 Pipelined Processor - Inline Test");
        $display("========================================");
        $display("Test program loaded (simple arithmetic)");
    end
    
    // Main test
    initial begin
        // Initialize
        reset = 1;
        cycle_count = 0;
        
        // Release reset
        repeat(5) @(posedge clock);
        reset = 0;
        $display("[E20] Pipelined processor reset released, starting execution...\n");
        
        // Wait for halt or timeout
        while (!halt && cycle_count < MAX_CYCLES) begin
            @(posedge clock);
            cycle_count = cycle_count + 1;
        end
        
        // Check result
        if (halt) begin
            $display("\n[E20] Pipelined processor halted normally after %0d cycles", debug_cycle);
        end else begin
            $display("\n[E20] ERROR: Timeout after %0d cycles", MAX_CYCLES);
            $display("LOG: %0t : ERROR : tb_processor_pipelined_inline : dut.halt : expected_value: 1'b1 actual_value: 1'b0", $time);
        end
        
        // Print final state
        repeat(2) @(posedge clock);
        print_state;
        
        $display("\n========================================");
        if (halt) begin
            $display("TEST PASSED");
        end else begin
            $display("ERROR");
            $error("TEST FAILED - Timeout");
        end
        $display("========================================\n");
        
        $finish;
    end
    
    // Print state task
    task print_state;
        integer i;
        begin
            $display("\nFinal state:");
            $display("    pc=%5d", debug_pc);
            
            // Print registers
            for (i = 0; i < 8; i = i + 1) begin
                $display("    $%0d=%5d (0x%04h)", i, dut.regs[i], dut.regs[i]);
            end
        end
    endtask
    
    // Waveform dump
    initial begin
        $dumpfile("dumpfile.fst");
        $dumpvars(0);
    end

endmodule
