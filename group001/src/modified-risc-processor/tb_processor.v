// =============================================================================
// E20 Processor Testbench
// =============================================================================
// Description:
//   Comprehensive testbench for E20 processor that mimics the C++ simulator
//   behavior. Loads programs from .bin files and displays final state.
//
// Usage:
//   1. Compile: iverilog -o sim tb_processor.v processor.v
//   2. Run: ./sim +program=test.bin
//   3. View output matching C++ simulator format
//
// =============================================================================

`timescale 1ns/1ps

module tb_processor;

    // =============================================================================
    // Parameters and Constants
    // =============================================================================
    parameter CLK_PERIOD = 10;  // 10ns = 100MHz
    parameter TB_MEM_SIZE = 8192;
    parameter TB_NUM_REGS = 8;
    parameter MEM_DUMP_SIZE = 128;  // Match C++ simulator
    parameter MAX_CYCLES = 100000;   // Timeout to prevent infinite loops
    
    // =============================================================================
    // Testbench Signals
    // =============================================================================
    reg         clock;
    reg         reset;
    wire        halt;
    wire [15:0] debug_pc;
    wire [15:0] debug_instr;
    wire [31:0] debug_cycle;
    
    // File handling
    reg [8*200-1:0] program_file;  // String for program filename
    integer file;
    integer status;
    
    // Test control
    integer test_passed;
    
    // Loop variables (declared at module level to avoid redeclaration issues)
    integer idx;
    integer words_printed;
    integer mem_init_i;
    
    // =============================================================================
    // Memory Initialization
    // =============================================================================
    initial begin
        // Initialize all memory to zero for clean simulation
        for (mem_init_i = 0; mem_init_i < TB_MEM_SIZE; mem_init_i = mem_init_i + 1) begin
            dut.ram[mem_init_i] = 16'h0000;
        end
    end
    
    // =============================================================================
    // DUT Instantiation
    // =============================================================================
    processor dut (
        .clock(clock),
        .reset(reset),
        .halt(halt),
        .debug_pc(debug_pc),
        .debug_instr(debug_instr),
        .debug_cycle(debug_cycle)
    );
    
    // =============================================================================
    // Clock Generation
    // =============================================================================
    initial begin
        clock = 0;
        forever #(CLK_PERIOD/2) clock = ~clock;
    end
    
    // =============================================================================
    // Test Stimulus
    // =============================================================================
    initial begin
        // Initialize
        reset = 1;
        test_passed = 0;
        
        // Check for program file from command line
        if (!$value$plusargs("program=%s", program_file)) begin
            program_file = "program.bin";  // Default filename
            $display("No +program argument, using default: %s", program_file);
        end else begin
            $display("Loading program: %s", program_file);
        end
        
        // Load program into processor memory
        load_program(program_file);
        
        // Release reset after a few cycles
        repeat(5) @(posedge clock);
        reset = 0;
        $display("\n[E20] Processor reset released, starting execution...\n");
        
        // Wait for halt or timeout
        fork
            // Process 1: Wait for halt
            begin
                @(posedge halt);
                $display("\n[E20] Processor halted naturally");
                test_passed = 1;
            end
            
            // Process 2: Timeout watchdog
            begin
                repeat(MAX_CYCLES) @(posedge clock);
                $display("\n[E20] ERROR: Timeout after %0d cycles (possible infinite loop)", MAX_CYCLES);
                test_passed = 0;
            end
        join_any
        disable fork;
        
        // Wait a few more cycles for signals to settle
        repeat(5) @(posedge clock);
        
        // Print final state
        print_final_state;
        
        // Test summary
        $display("\n=============================================================================");
        if (test_passed) begin
            $display("TEST PASSED - Processor halted normally after %0d cycles", debug_cycle);
        end else begin
            $display("TEST FAILED - Timeout or error occurred");
        end
        $display("=============================================================================\n");
        
        $finish;
    end
    
    // =============================================================================
    // Monitor Execution (Optional - for debugging)
    // =============================================================================
    // Uncomment to see instruction-by-instruction execution
    /*
    always @(posedge clock) begin
        if (!reset && !halt) begin
            $display("[%0d] PC=0x%04h  INSTR=0x%04h  $1=0x%04h  $2=0x%04h", 
                     debug_cycle, debug_pc, debug_instr, 
                     dut.regs[1], dut.regs[2]);
        end
    end
    */
    
    // =============================================================================
    // Tasks
    // =============================================================================
    
    // Load program from binary file (matches C++ simulator format)
    task load_program;
        input [8*200-1:0] filename;
        reg [15:0] addr;
        reg [15:0] instr;
        integer line_num;
        integer scan_result;
        reg [8*500-1:0] line;
        begin
            $display("Opening file: %s", filename);
            file = $fopen(filename, "r");
            
            if (file == 0) begin
                $display("ERROR: Could not open file: %s", filename);
                $finish;
            end
            
            addr = 0;
            line_num = 0;
            
            // Read file line by line
            while (!$feof(file)) begin
                scan_result = $fgets(line, file);
                if (scan_result != 0) begin
                    line_num = line_num + 1;
                    
                    // Parse line: ram[addr] = 16'bXXXXXXXXXXXXXXXX;
                    scan_result = $sscanf(line, "ram[%d] = 16'b%b;", addr, instr);
                    
                    if (scan_result == 2) begin
                        if (addr >= TB_MEM_SIZE) begin
                            $display("ERROR: Address %0d exceeds memory size", addr);
                            $finish;
                        end
                        dut.ram[addr] = instr;
                    end else begin
                        // Try hex format: ram[addr] = 16'hXXXX;
                        scan_result = $sscanf(line, "ram[%d] = 16'h%h;", addr, instr);
                        if (scan_result == 2) begin
                            if (addr >= TB_MEM_SIZE) begin
                                $display("ERROR: Address %0d exceeds memory size", addr);
                                $finish;
                            end
                            dut.ram[addr] = instr;
                        end
                    end
                end
            end
            
            $fclose(file);
            $display("Program loaded successfully (%0d lines processed)", line_num);
        end
    endtask
    
    // Print final state (matches C++ simulator output format)
    task print_final_state;
        begin
            $display("\nFinal state:");
            $display("    pc=%5d", debug_pc);
            
            // Print all registers
            for (idx = 0; idx < TB_NUM_REGS; idx = idx + 1) begin
                $display("    $%0d=%5d", idx, dut.regs[idx]);
            end
            
            // Print memory dump (first 128 words, 8 per line)
            words_printed = 0;
            while (words_printed < MEM_DUMP_SIZE) begin
                $write("%04h ", dut.ram[words_printed]);
                words_printed = words_printed + 1;
                if (words_printed % 8 == 0) begin
                    $display("");
                end
            end
            if (words_printed % 8 != 0) begin
                $display("");
            end
        end
    endtask
    
    // =============================================================================
    // Waveform Dump (Optional)
    // =============================================================================
    initial begin
        if ($test$plusargs("vcd")) begin
            $dumpfile("processor.vcd");
            $dumpvars(0, tb_processor);
            $display("VCD waveform dump enabled");
        end
    end
    
    // =============================================================================
    // Performance Statistics
    // =============================================================================
    initial begin
        @(posedge halt);
        @(posedge clock);
        $display("\n=== Performance Statistics ===");
        $display("Total cycles:        %0d", debug_cycle);
        $display("Final PC:            0x%04h (%0d)", debug_pc, debug_pc);
        $display("Instructions executed: %0d", debug_cycle);
        $display("==============================\n");
    end

endmodule
