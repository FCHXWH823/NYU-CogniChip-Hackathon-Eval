// =============================================================================
// E20 Processor Testbench (Simplified for Icarus Verilog compatibility)
// =============================================================================

`timescale 1ns/1ps

module tb_processor_simple;

    // Parameters
    parameter CLK_PERIOD = 10;
    parameter MAX_CYCLES = 100000;
    
    // Signals
    reg         clock;
    reg         reset;
    wire        halt;
    wire [15:0] debug_pc;
    wire [15:0] debug_instr;
    wire [31:0] debug_cycle;
    
    //File handling
    reg [8*200-1:0] program_file;
    integer file_handle;
    integer cycle_count;
    
    // DUT Instantiation
    processor dut (
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
    
    // Initialize memory to zero
    integer mem_init_idx;
    initial begin
        for (mem_init_idx = 0; mem_init_idx < 8192; mem_init_idx = mem_init_idx + 1) begin
            dut.ram[mem_init_idx] = 16'h0000;
        end
    end
    
    // Main test
    initial begin
        // Initialize
        reset = 1;
        cycle_count = 0;
        
        // Get program file
        if (!$value$plusargs("program=%s", program_file)) begin
            program_file = "test_simple.bin";
        end
        
        $display("========================================");
        $display("E20 Processor Simulation");
        $display("========================================");
        $display("Program: %s\n", program_file);
        
        // Load program
        load_program_from_file(program_file);
        
        // Release reset
        repeat(5) @(posedge clock);
        reset = 0;
        $display("[E20] Processor reset released, starting execution...\n");
        
        // Wait for halt or timeout
        while (!halt && cycle_count < MAX_CYCLES) begin
            @(posedge clock);
            cycle_count = cycle_count + 1;
        end
        
        // Check result
        if (halt) begin
            $display("\n[E20] Processor halted normally after %0d cycles", debug_cycle);
        end else begin
            $display("\n[E20] ERROR: Timeout after %0d cycles", MAX_CYCLES);
        end
        
        // Print final state
        repeat(2) @(posedge clock);
        print_state;
        
        $display("\n========================================");
        if (halt) begin
            $display("TEST PASSED");
        end else begin
            $display("TEST FAILED - Timeout");
        end
        $display("========================================\n");
        
        $finish;
    end
    
    // Load program task
    task load_program_from_file;
        input [8*200-1:0] filename;
        reg [15:0] addr;
        reg [15:0] data;
        reg [8*500-1:0] line;
        integer result;
        integer line_count;
        begin
            $display("Loading program: %s", filename);
            file_handle = $fopen(filename, "r");
            
            if (file_handle == 0) begin
                $display("ERROR: Cannot open file %s", filename);
                $finish;
            end
            
            line_count = 0;
            while (!$feof(file_handle)) begin
                result = $fgets(line, file_handle);
                if (result != 0) begin
                    // Try binary format
                    result = $sscanf(line, "ram[%d] = 16'b%b;", addr, data);
                    if (result == 2) begin
                        dut.ram[addr] = data;
                        line_count = line_count + 1;
                    end else begin
                        // Try hex format
                        result = $sscanf(line, "ram[%d] = 16'h%h;", addr, data);
                        if (result == 2) begin
                            dut.ram[addr] = data;
                            line_count = line_count + 1;
                        end
                    end
                end
            end
            
            $fclose(file_handle);
            $display("Program loaded: %0d instructions\n", line_count);
        end
    endtask
    
    // Print state task
    task print_state;
        integer i;
        integer count;
        begin
            $display("\nFinal state:");
            $display("    pc=%5d", debug_pc);
            
            // Print registers
            for (i = 0; i < 8; i = i + 1) begin
                $display("    $%0d=%5d", i, dut.regs[i]);
            end
            
            // Print memory (128 words, 8 per line)
            count = 0;
            while (count < 128) begin
                $write("%04h ", dut.ram[count]);
                count = count + 1;
                if (count % 8 == 0) begin
                    $display("");
                end
            end
        end
    endtask
    
    // Optional: VCD dump
    initial begin
        if ($test$plusargs("vcd")) begin
            $dumpfile("processor.vcd");
            $dumpvars(0, tb_processor_simple);
        end
    end
    
    // Optional: Monitor each instruction
    /*
    always @(posedge clock) begin
        if (!reset && !halt) begin
            $display("[%0d] PC=%04h INSTR=%04h", debug_cycle, debug_pc, debug_instr);
        end
    end
    */

endmodule
