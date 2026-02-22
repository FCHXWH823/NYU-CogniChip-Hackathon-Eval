// =============================================================================
// E20 Pipelined Processor Testbench
// =============================================================================
// Description:
//   Testbench for the 5-stage pipelined E20 processor
//   - Loads test programs from binary files
//   - Monitors execution and reports results
//   - Verifies correct operation and halt behavior
//
// =============================================================================

`timescale 1ns/1ps

module tb_processor_pipelined;

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
    
    // File handling
    reg [8*200-1:0] program_file;
    integer file_handle;
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
    
    // Initialize memory to zero
    integer mem_init_idx;
    initial begin
        for (mem_init_idx = 0; mem_init_idx < 8192; mem_init_idx = mem_init_idx + 1) begin
            dut.ram[mem_init_idx] = 16'h0000;
        end
    end
    
    // Main test
    initial begin
        $display("TEST START");
        
        // Initialize
        reset = 1;
        cycle_count = 0;
        
        // Get program file
        if (!$value$plusargs("program=%s", program_file)) begin
            program_file = "test_simple.bin";
        end
        
        $display("========================================");
        $display("E20 Pipelined Processor Simulation");
        $display("========================================");
        $display("Program: %s\n", program_file);
        
        // Load program
        load_program_from_file(program_file);
        
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
            $display("LOG: %0t : ERROR : tb_processor_pipelined : dut.halt : expected_value: 1'b1 actual_value: 1'b0", $time);
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
    
    // Load program task
    task load_program_from_file;
        input [8*200-1:0] filename;
        reg [15:0] addr;
        reg [15:0] data;
        reg [8*100-1:0] line;
        integer result;
        integer line_count;
        begin
            $display("Loading program: %s", filename);
            file_handle = $fopen(filename, "r");
            
            if (file_handle == 0) begin
                $display("ERROR: Cannot open file %s", filename);
                $display("LOG: %0t : ERROR : tb_processor_pipelined : file_open : expected_value: valid_handle actual_value: 0", $time);
                $error("File open failed");
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
                $display("    $%0d=%5d (0x%04h)", i, dut.regs[i], dut.regs[i]);
            end
            
            // Print first 128 words of memory (8 per line)
            $display("\nMemory (first 128 words):");
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
    
    // Waveform dump
    initial begin
        $dumpfile("dumpfile.fst");
        $dumpvars(0);
    end
    
    // Optional: Monitor each instruction (uncomment for debugging)
    /*
    always @(posedge clock) begin
        if (!reset && !halt) begin
            $display("[%0d] PC=%04h IR1=%04h IR2=%04h IR3=%04h IR4=%04h", 
                     debug_cycle, debug_pc, dut.IR1, dut.IR2, dut.IR3, dut.IR4);
        end
    end
    */

endmodule
