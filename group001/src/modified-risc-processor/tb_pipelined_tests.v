// =============================================================================
// E20 Pipelined Processor - Comprehensive Tests
// =============================================================================
// Tests: test_simple, test_array_sum, test_fibonacci, test_new_instructions
// =============================================================================

`timescale 1ns/1ps

module tb_pipelined_tests;

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
    
    integer cycle_count;
    integer test_num;
    reg [8*50-1:0] test_name;
    
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
    
    // Task to load test program
    task load_test_simple;
        begin
            dut.ram[0] = 16'b0010000010000001;  // addi $1, $0, 1
            dut.ram[1] = 16'b0010000100000010;  // addi $2, $0, 2
            dut.ram[2] = 16'b0000010100110000;  // add $3, $1, $2
            dut.ram[3] = 16'b0100000000000011;  // j 3 (halt)
        end
    endtask
    
    task load_test_array_sum;
        begin
            dut.ram[0] = 16'b0010000010000000;   // addi $1, $0, 0
            dut.ram[1] = 16'b0010000110000000;   // addi $3, $0, 0
            dut.ram[2] = 16'b1000010100001000;   // lw $2, 8($1)
            dut.ram[3] = 16'b0000110100110000;   // add $3, $3, $2
            dut.ram[4] = 16'b0010010010000001;   // addi $1, $1, 1
            dut.ram[5] = 16'b1100100000000001;   // jeq $2, $0, 1
            dut.ram[6] = 16'b0100000000000010;   // j 2
            dut.ram[7] = 16'b0100000000000111;   // j 7 (halt)
            // Data array
            dut.ram[8] = 16'b0000000000000101;   // 5
            dut.ram[9] = 16'b0000000000000011;   // 3
            dut.ram[10] = 16'b0000000000010100;  // 20
            dut.ram[11] = 16'b0000000000000100;  // 4
            dut.ram[12] = 16'b0000000000000101;  // 5
            dut.ram[13] = 16'b0000000000000000;  // 0 (terminator)
        end
    endtask
    
    task load_test_fibonacci;
        begin
            dut.ram[0] = 16'b0010000010001000;   // addi $1, $0, 8
            dut.ram[1] = 16'b0010000100000000;   // addi $2, $0, 0
            dut.ram[2] = 16'b0010000110000001;   // addi $3, $0, 1
            dut.ram[3] = 16'b1100010000000101;   // jeq $1, $0, 5
            dut.ram[4] = 16'b0010010011111111;   // addi $1, $1, -1
            dut.ram[5] = 16'b0000100111000000;   // add $4, $2, $3
            dut.ram[6] = 16'b0000000110100000;   // add $2, $3, $0
            dut.ram[7] = 16'b0000001000110000;   // add $3, $4, $0
            dut.ram[8] = 16'b0100000000000011;   // j 3
            dut.ram[9] = 16'b0000000110010000;   // add $2, $3, $0
            dut.ram[10] = 16'b0100000000001010;  // j 10 (halt)
        end
    endtask
    
    task load_test_new_instructions;
        begin
            // Test XOR, NOR, SLL, SRL, SRA
            dut.ram[0] = 16'b0010000010001100;   // addi $1, $0, 12
            dut.ram[1] = 16'b0010000100000101;   // addi $2, $0, 5
            dut.ram[2] = 16'b0000010100110101;   // xor $3, $1, $2
            dut.ram[3] = 16'b0000010101000110;   // nor $4, $1, $2
            dut.ram[4] = 16'b0010001010000010;   // addi $5, $0, 2
            dut.ram[5] = 16'b0000010101011001;   // sll $6, $1, $5
            dut.ram[6] = 16'b0000010101101010;   // srl $7, $1, $5
            dut.ram[7] = 16'b0100000000000111;   // j 7 (halt)
        end
    endtask
    
    // Initialize and run tests
    integer mem_init_idx;
    initial begin
        $display("TEST START");
        $display("========================================");
        $display("E20 Pipelined Processor - Test Suite");
        $display("========================================\n");
        
        // Get test selection from plusargs
        if (!$value$plusargs("test=%d", test_num)) begin
            test_num = 0;  // Default to test_simple
        end
        
        // Initialize all memory to zero
        for (mem_init_idx = 0; mem_init_idx < 8192; mem_init_idx = mem_init_idx + 1) begin
            dut.ram[mem_init_idx] = 16'h0000;
        end
        
        // Load selected test
        case (test_num)
            0: begin
                test_name = "test_simple";
                load_test_simple;
            end
            1: begin
                test_name = "test_array_sum";
                load_test_array_sum;
            end
            2: begin
                test_name = "test_fibonacci";
                load_test_fibonacci;
            end
            3: begin
                test_name = "test_new_instructions";
                load_test_new_instructions;
            end
            default: begin
                test_name = "test_simple";
                load_test_simple;
            end
        endcase
        
        $display("Running: %s", test_name);
        $display("----------------------------------------\n");
    end
    
    // Main test
    initial begin
        // Initialize
        reset = 1;
        cycle_count = 0;
        
        // Release reset
        repeat(5) @(posedge clock);
        reset = 0;
        $display("[%s] Reset released, starting execution...\n", test_name);
        
        // Wait for halt or timeout
        while (!halt && cycle_count < MAX_CYCLES) begin
            @(posedge clock);
            cycle_count = cycle_count + 1;
        end
        
        // Check result
        if (halt) begin
            $display("\n[%s] Processor halted normally after %0d cycles", test_name, debug_cycle);
        end else begin
            $display("\n[%s] ERROR: Timeout after %0d cycles", test_name, MAX_CYCLES);
            $display("LOG: %0t : ERROR : tb_pipelined_tests : dut.halt : expected_value: 1'b1 actual_value: 1'b0", $time);
        end
        
        // Print final state
        repeat(2) @(posedge clock);
        print_state;
        
        // Verify results based on test
        verify_results;
        
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
    
    // Verify test results
    task verify_results;
        begin
            case (test_num)
                0: begin  // test_simple
                    $display("\nVerifying test_simple:");
                    $display("  Expected: $1=1, $2=2, $3=3");
                    $display("  Actual:   $1=%0d, $2=%0d, $3=%0d", dut.regs[1], dut.regs[2], dut.regs[3]);
                    if (dut.regs[1] == 1 && dut.regs[2] == 2 && dut.regs[3] == 3) begin
                        $display("  ✓ Results match!");
                    end else begin
                        $display("  ✗ Results mismatch!");
                    end
                end
                1: begin  // test_array_sum
                    $display("\nVerifying test_array_sum:");
                    $display("  Expected sum: 37 (5+3+20+4+5)");
                    $display("  Actual sum:   $3=%0d", dut.regs[3]);
                    if (dut.regs[3] == 37) begin
                        $display("  ✓ Results match!");
                    end else begin
                        $display("  ✗ Results mismatch!");
                    end
                end
                2: begin  // test_fibonacci
                    $display("\nVerifying test_fibonacci:");
                    $display("  Expected: Fib(8) = 21");
                    $display("  Actual:   $3=%0d", dut.regs[3]);
                    if (dut.regs[3] == 21) begin
                        $display("  ✓ Results match!");
                    end else begin
                        $display("  ✗ Results mismatch!");
                    end
                end
                3: begin  // test_new_instructions
                    $display("\nVerifying test_new_instructions:");
                    $display("  XOR: $3=%0d (expected: 9)", dut.regs[3]);
                    $display("  NOR: $4=%0d (expected: 65522)", dut.regs[4]);
                    $display("  SLL: $6=%0d (expected: 48)", dut.regs[6]);
                    $display("  SRL: $7=%0d (expected: 3)", dut.regs[7]);
                end
            endcase
        end
    endtask
    
    // Print state task
    task print_state;
        integer i;
        begin
            $display("\nFinal state:");
            $display("  PC = %5d (0x%04h)", debug_pc, debug_pc);
            $display("  Registers:");
            for (i = 0; i < 8; i = i + 1) begin
                $display("    $%0d = %5d (0x%04h)", i, dut.regs[i], dut.regs[i]);
            end
        end
    endtask
    
    // Waveform dump
    initial begin
        $dumpfile("dumpfile.fst");
        $dumpvars(0);
    end

endmodule
