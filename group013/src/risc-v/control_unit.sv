// control_unit.sv
// Control Unit for RV32I single-cycle CPU
// Decodes instruction and generates all control signals

module control_unit (
    input  logic [31:0] instruction,   // 32-bit instruction
    output logic [3:0]  alu_control,   // ALU operation select
    output logic [2:0]  imm_sel,       // Immediate type selector
    output logic        reg_write,     // Register write enable
    output logic        mem_write,     // Memory write enable
    output logic        mem_read,      // Memory read enable
    output logic        mem_to_reg,    // Memory to register mux
    output logic        alu_src,       // ALU source mux (0=rs2, 1=imm)
    output logic [1:0]  pc_src,        // PC source select
    output logic        branch,        // Branch instruction flag
    output logic        jal,           // JAL instruction flag
    output logic        jalr           // JALR instruction flag
);

    // Instruction fields
    logic [6:0] opcode;
    logic [2:0] funct3;
    logic [6:0] funct7;

    assign opcode = instruction[6:0];
    assign funct3 = instruction[14:12];
    assign funct7 = instruction[31:25];

    // Opcode definitions
    localparam [6:0] OP_RTYPE  = 7'b0110011;  // R-type (add, sub, and, or, xor, slt, sltu)
    localparam [6:0] OP_ITYPE  = 7'b0010011;  // I-type ALU (addi)
    localparam [6:0] OP_LOAD   = 7'b0000011;  // Load (lw)
    localparam [6:0] OP_STORE  = 7'b0100011;  // Store (sw)
    localparam [6:0] OP_BRANCH = 7'b1100011;  // Branch (beq, bne)
    localparam [6:0] OP_JAL    = 7'b1101111;  // JAL
    localparam [6:0] OP_JALR   = 7'b1100111;  // JALR
    localparam [6:0] OP_LUI    = 7'b0110111;  // LUI
    localparam [6:0] OP_AUIPC  = 7'b0010111;  // AUIPC

    // ALU control encoding
    localparam [3:0] ALU_ADD  = 4'b0000;
    localparam [3:0] ALU_SUB  = 4'b0001;
    localparam [3:0] ALU_AND  = 4'b0010;
    localparam [3:0] ALU_OR   = 4'b0011;
    localparam [3:0] ALU_XOR  = 4'b0100;
    localparam [3:0] ALU_SLT  = 4'b0101;
    localparam [3:0] ALU_SLTU = 4'b0110;

    // Immediate type encoding
    localparam [2:0] IMM_I = 3'b000;
    localparam [2:0] IMM_S = 3'b001;
    localparam [2:0] IMM_B = 3'b010;
    localparam [2:0] IMM_U = 3'b011;
    localparam [2:0] IMM_J = 3'b100;

    // PC source encoding
    localparam [1:0] PC_PLUS4  = 2'b00;  // PC + 4
    localparam [1:0] PC_BRANCH = 2'b01;  // PC + branch_offset (when branch taken)
    localparam [1:0] PC_JAL    = 2'b10;  // PC + jal_offset
    localparam [1:0] PC_JALR   = 2'b11;  // rs1 + offset

    // Control signal generation
    always_comb begin
        // Default values
        reg_write  = 1'b0;
        mem_write  = 1'b0;
        mem_read   = 1'b0;
        mem_to_reg = 1'b0;
        alu_src    = 1'b0;
        pc_src     = PC_PLUS4;
        branch     = 1'b0;
        jal        = 1'b0;
        jalr       = 1'b0;
        alu_control = ALU_ADD;
        imm_sel    = IMM_I;

        case (opcode)
            // R-type instructions
            OP_RTYPE: begin
                reg_write = 1'b1;
                alu_src   = 1'b0;  // Use rs2
                
                case (funct3)
                    3'b000: alu_control = (funct7[5]) ? ALU_SUB : ALU_ADD;  // add/sub
                    3'b111: alu_control = ALU_AND;   // and
                    3'b110: alu_control = ALU_OR;    // or
                    3'b100: alu_control = ALU_XOR;   // xor
                    3'b010: alu_control = ALU_SLT;   // slt
                    3'b011: alu_control = ALU_SLTU;  // sltu
                    default: alu_control = ALU_ADD;
                endcase
            end

            // I-type ALU instructions (addi)
            OP_ITYPE: begin
                reg_write = 1'b1;
                alu_src   = 1'b1;  // Use immediate
                imm_sel   = IMM_I;
                
                case (funct3)
                    3'b000: alu_control = ALU_ADD;   // addi
                    default: alu_control = ALU_ADD;
                endcase
            end

            // Load instructions (lw)
            OP_LOAD: begin
                reg_write  = 1'b1;
                mem_read   = 1'b1;
                mem_to_reg = 1'b1;
                alu_src    = 1'b1;  // Use immediate
                alu_control = ALU_ADD;
                imm_sel    = IMM_I;
            end

            // Store instructions (sw)
            OP_STORE: begin
                mem_write   = 1'b1;
                alu_src     = 1'b1;  // Use immediate
                alu_control = ALU_ADD;
                imm_sel     = IMM_S;
            end

            // Branch instructions (beq, bne)
            OP_BRANCH: begin
                branch      = 1'b1;
                alu_src     = 1'b0;  // Use rs2
                imm_sel     = IMM_B;
                pc_src      = PC_BRANCH;
                
                case (funct3)
                    3'b000: alu_control = ALU_SUB;  // beq (check if equal via subtraction)
                    3'b001: alu_control = ALU_SUB;  // bne (check if not equal)
                    default: alu_control = ALU_SUB;
                endcase
            end

            // JAL instruction
            OP_JAL: begin
                reg_write   = 1'b1;
                jal         = 1'b1;
                pc_src      = PC_JAL;
                imm_sel     = IMM_J;
            end

            // JALR instruction
            OP_JALR: begin
                reg_write   = 1'b1;
                jalr        = 1'b1;
                alu_src     = 1'b1;  // Use immediate
                pc_src      = PC_JALR;
                imm_sel     = IMM_I;
                alu_control = ALU_ADD;
            end

            // LUI instruction
            OP_LUI: begin
                reg_write   = 1'b1;
                imm_sel     = IMM_U;
                alu_src     = 1'b1;
                alu_control = ALU_ADD;  // Will be overridden in datapath to just pass immediate
            end

            // AUIPC instruction
            OP_AUIPC: begin
                reg_write   = 1'b1;
                imm_sel     = IMM_U;
                alu_src     = 1'b1;
                alu_control = ALU_ADD;  // Add PC + immediate
            end

            default: begin
                // Do nothing for unrecognized instructions
            end
        endcase
    end

endmodule
