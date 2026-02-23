// alu.sv
// 32-bit ALU for RV32I single-cycle CPU
// Supports arithmetic, logical, and comparison operations

module alu (
    input  logic [31:0] operand_a,     // First operand
    input  logic [31:0] operand_b,     // Second operand
    input  logic [3:0]  alu_control,   // ALU operation select
    output logic [31:0] alu_result,    // ALU output
    output logic        zero_flag      // Zero flag for branch decisions
);

    // ALU operation encoding
    localparam [3:0] ALU_ADD  = 4'b0000;
    localparam [3:0] ALU_SUB  = 4'b0001;
    localparam [3:0] ALU_AND  = 4'b0010;
    localparam [3:0] ALU_OR   = 4'b0011;
    localparam [3:0] ALU_XOR  = 4'b0100;
    localparam [3:0] ALU_SLT  = 4'b0101;  // Set less than (signed)
    localparam [3:0] ALU_SLTU = 4'b0110;  // Set less than (unsigned)
    localparam [3:0] ALU_SLL  = 4'b0111;  // Shift left logical
    localparam [3:0] ALU_SRL  = 4'b1000;  // Shift right logical
    localparam [3:0] ALU_SRA  = 4'b1001;  // Shift right arithmetic

    // ALU operation logic
    always_comb begin
        case (alu_control)
            ALU_ADD:  alu_result = operand_a + operand_b;
            ALU_SUB:  alu_result = operand_a - operand_b;
            ALU_AND:  alu_result = operand_a & operand_b;
            ALU_OR:   alu_result = operand_a | operand_b;
            ALU_XOR:  alu_result = operand_a ^ operand_b;
            ALU_SLT:  alu_result = {31'b0, $signed(operand_a) < $signed(operand_b)};
            ALU_SLTU: alu_result = {31'b0, operand_a < operand_b};
            ALU_SLL:  alu_result = operand_a << operand_b[4:0];
            ALU_SRL:  alu_result = operand_a >> operand_b[4:0];
            ALU_SRA:  alu_result = $signed(operand_a) >>> operand_b[4:0];
            default:  alu_result = 32'b0;
        endcase
    end

    // Zero flag for branch conditions
    assign zero_flag = (alu_result == 32'b0);

endmodule
