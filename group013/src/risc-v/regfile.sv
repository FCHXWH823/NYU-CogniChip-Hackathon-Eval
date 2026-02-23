// regfile.sv
// 32 x 32-bit Register File for RV32I CPU
// Two read ports, one write port
// x0 is hardwired to zero

module regfile (
    input  logic        clock,
    input  logic        reset,
    input  logic [4:0]  rs1_addr,      // Read address 1
    input  logic [4:0]  rs2_addr,      // Read address 2
    input  logic [4:0]  rd_addr,       // Write address
    input  logic [31:0] rd_data,       // Write data
    input  logic        reg_write,     // Write enable
    output logic [31:0] rs1_data,      // Read data 1
    output logic [31:0] rs2_data       // Read data 2
);

    // 32 registers, each 32 bits wide
    logic [31:0] registers [31:0];

    // Asynchronous read
    assign rs1_data = (rs1_addr == 5'b0) ? 32'b0 : registers[rs1_addr];
    assign rs2_data = (rs2_addr == 5'b0) ? 32'b0 : registers[rs2_addr];

    // Synchronous write
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            // Initialize all registers to zero
            for (int i = 0; i < 32; i++) begin
                registers[i] <= 32'b0;
            end
        end else begin
            // Write to register if enabled and not writing to x0
            if (reg_write && (rd_addr != 5'b0)) begin
                registers[rd_addr] <= rd_data;
            end
        end
    end

endmodule
