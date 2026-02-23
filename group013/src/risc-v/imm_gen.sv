// imm_gen.sv
// Immediate Generator for RV32I CPU
// Extracts and sign-extends immediates from instruction

module imm_gen (
    input  logic [31:0] instruction,   // 32-bit instruction
    input  logic [2:0]  imm_sel,       // Immediate type selector
    output logic [31:0] immediate      // Sign-extended immediate
);

    // Immediate format encoding
    localparam [2:0] IMM_I = 3'b000;  // I-type (addi, lw, jalr)
    localparam [2:0] IMM_S = 3'b001;  // S-type (sw)
    localparam [2:0] IMM_B = 3'b010;  // B-type (beq, bne)
    localparam [2:0] IMM_U = 3'b011;  // U-type (lui, auipc)
    localparam [2:0] IMM_J = 3'b100;  // J-type (jal)

    always_comb begin
        case (imm_sel)
            // I-type: inst[31:20]
            IMM_I: begin
                immediate = {{20{instruction[31]}}, instruction[31:20]};
            end
            
            // S-type: {inst[31:25], inst[11:7]}
            IMM_S: begin
                immediate = {{20{instruction[31]}}, instruction[31:25], instruction[11:7]};
            end
            
            // B-type: {inst[31], inst[7], inst[30:25], inst[11:8], 1'b0}
            IMM_B: begin
                immediate = {{19{instruction[31]}}, instruction[31], instruction[7], 
                             instruction[30:25], instruction[11:8], 1'b0};
            end
            
            // U-type: {inst[31:12], 12'b0}
            IMM_U: begin
                immediate = {instruction[31:12], 12'b0};
            end
            
            // J-type: {inst[31], inst[19:12], inst[20], inst[30:21], 1'b0}
            IMM_J: begin
                immediate = {{11{instruction[31]}}, instruction[31], instruction[19:12], 
                             instruction[20], instruction[30:21], 1'b0};
            end
            
            default: begin
                immediate = 32'b0;
            end
        endcase
    end

endmodule
