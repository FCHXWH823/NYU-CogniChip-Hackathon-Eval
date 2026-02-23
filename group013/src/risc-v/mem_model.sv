// mem_model.sv
// Simple instruction and data memory model for single-cycle RV32I CPU
// Word-addressed memories with 1024 words each
//
// Supports loading a hex via plusarg:
//   +HEX=program.hex
// If not provided, tries a small set of default paths, then falls back
// to a minimal built-in smoke test program.

module mem_model (
    input  logic        clock,
    // Instruction memory interface
    input  logic [31:0] imem_addr,     // Instruction memory address (byte-addressed)
    output logic [31:0] imem_data,     // Instruction read data
    // Data memory interface
    input  logic [31:0] dmem_addr,     // Data memory address (byte-addressed)
    input  logic [31:0] dmem_wdata,    // Data to write
    output logic [31:0] dmem_rdata,    // Data read
    input  logic        dmem_write,    // Data memory write enable
    input  logic        dmem_read      // Data memory read enable
);

    // Memory arrays (word-addressed: 1024 words each)
    logic [31:0] imem [0:1023];
    logic [31:0] dmem [0:1023];

    // Instruction memory - combinational read
    assign imem_data = imem[imem_addr[31:2]];

    // Data memory - synchronous write
    always_ff @(posedge clock) begin
        if (dmem_write) begin
            dmem[dmem_addr[31:2]] <= dmem_wdata;
        end
    end

    // Data memory - combinational read
    always_comb begin
        if (dmem_read) begin
            dmem_rdata = dmem[dmem_addr[31:2]];
        end else begin
            dmem_rdata = 32'h0;
        end
    end

    // Initialize instruction memory from hex file (or fallback program)
    initial begin
        string candidates [0:4];
        string hex_path;
        int    f;
        logic  file_found;

        // Default search paths
        candidates[0] = "program.hex";
        candidates[1] = "./program.hex";
        candidates[2] = "../program.hex";
        candidates[3] = "../../program.hex";
        candidates[4] = "../../../program.hex";

        file_found = 0;

        // If user provides +HEX=..., try that first
        if ($value$plusargs("HEX=%s", hex_path)) begin
            $display("HEX plusarg provided: %s", hex_path);
            f = $fopen(hex_path, "r");
            if (f) begin
                $fclose(f);
                $display("Loading imem from: %s", hex_path);
                $readmemh(hex_path, imem);
                file_found = 1;
            end else begin
                $display("WARNING: Unable to open +HEX file: %s", hex_path);
            end
        end

        // Otherwise, try default candidates
        if (!file_found) begin : search
            for (int i = 0; i <= 4; i++) begin
                $display("Trying to load: %s", candidates[i]);
                f = $fopen(candidates[i], "r");
                if (f) begin
                    $fclose(f);
                    $display("Found: %s", candidates[i]);
                    $readmemh(candidates[i], imem);
                    file_found = 1;
                    disable search;
                end
            end
        end

        // Built-in fallback if nothing was found
        if (!file_found) begin
            $display("WARNING: program.hex not found, using built-in fallback test program");

            // Fill with NOPs: addi x0, x0, 0
            for (int i = 0; i < 1024; i++) begin
                imem[i] = 32'h0000_0013;
            end

            // 0x00: addi x2, x0, 0x100  (x2 = 256)
            imem[0] = 32'h1000_0113;

            // 0x04: addi x3, x0, 1      (x3 = 1)
            imem[1] = 32'h0010_0193;

            // 0x08: sw x3, 0(x2)        (mem[0x100] = 1)
            imem[2] = 32'h0031_2023;

            // 0x0C: jal x0, 0           (spin)
            imem[3] = 32'h0000_006F;
        end

        // Initialize data memory to zeros
        for (int i = 0; i < 1024; i++) begin
            dmem[i] = 32'h0;
        end
    end

endmodule
