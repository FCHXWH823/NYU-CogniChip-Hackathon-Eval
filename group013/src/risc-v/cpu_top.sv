// cpu_top.sv
// Top-level module for 32-bit single-cycle RISC-V (RV32I) CPU
// Integrates all components following the single-cycle datapath

module cpu_top (
    input  logic        clock,
    input  logic        reset,
    // Instruction memory interface
    output logic [31:0] imem_addr,     // Instruction memory address
    input  logic [31:0] imem_data,     // Instruction from memory
    // Data memory interface
    output logic [31:0] dmem_addr,     // Data memory address
    output logic [31:0] dmem_wdata,    // Data to write
    input  logic [31:0] dmem_rdata,    // Data read from memory
    output logic        dmem_write,    // Data memory write enable
    output logic        dmem_read,     // Data memory read enable
    // Debug outputs for verification
    output logic [31:0] dbg_pc,        // Current PC value (COMMITTED instruction PC)
    output logic        dbg_regwrite,  // Register write enable (COMMITTED)
    output logic [4:0]  dbg_rd,        // Destination register address (COMMITTED)
    output logic [31:0] dbg_wdata,     // Register write data (COMMITTED)
    output logic        dbg_memwrite,  // Memory write enable (COMMITTED)
    output logic [31:0] dbg_memaddr,   // Memory address (COMMITTED)
    output logic [31:0] dbg_memwdata   // Memory write data (COMMITTED)
);

    // Program Counter
    logic [31:0] pc, pc_next;

    // Instruction and control signals
    logic [31:0] instruction;
    logic [3:0]  alu_control;
    logic [2:0]  imm_sel;
    logic        reg_write;
    logic        mem_write;
    logic        mem_read;
    logic        mem_to_reg;
    logic        alu_src;
    logic [1:0]  pc_src;
    logic        branch;
    logic        jal;
    logic        jalr;

    // Register file signals
    logic [4:0]  rs1_addr, rs2_addr, rd_addr;
    logic [31:0] rs1_data, rs2_data, rd_data;

    // ALU signals
    logic [31:0] alu_operand_a, alu_operand_b;
    logic [31:0] alu_result;
    logic        zero_flag;

    // Immediate value
    logic [31:0] immediate;

    // Branch and jump signals
    logic        branch_taken;
    logic [31:0] branch_target;
    logic [31:0] jal_target;
    logic [31:0] jalr_target;
    logic [31:0] pc_plus4;

    // Additional signals for LUI and AUIPC
    logic        is_lui, is_auipc;

    // -------------------------------------------------------------------------
    // Fetch / Decode
    // -------------------------------------------------------------------------
    assign instruction = imem_data;

    assign rs1_addr = instruction[19:15];
    assign rs2_addr = instruction[24:20];
    assign rd_addr  = instruction[11:7];

    // Detect LUI and AUIPC
    assign is_lui   = (instruction[6:0] == 7'b0110111);
    assign is_auipc = (instruction[6:0] == 7'b0010111);

    // PC + 4
    assign pc_plus4 = pc + 32'd4;

    // Branch / Jump target calculation
    assign branch_target = pc + immediate;
    assign jal_target    = pc + immediate;
    assign jalr_target   = (rs1_data + immediate) & ~32'b1;  // Clear LSB

    // Branch decision logic
    always_comb begin
        case (instruction[14:12])  // funct3
            3'b000: branch_taken = branch &  zero_flag;   // beq
            3'b001: branch_taken = branch & ~zero_flag;   // bne
            default: branch_taken = 1'b0;
        endcase
    end

    // PC update logic
    always_comb begin
        case (pc_src)
            2'b00: begin
                pc_next = branch_taken ? branch_target : pc_plus4;
            end
            2'b01: begin
                pc_next = branch_taken ? branch_target : pc_plus4;
            end
            2'b10: begin
                pc_next = jal_target;
            end
            2'b11: begin
                pc_next = jalr_target;
            end
            default: pc_next = pc_plus4;
        endcase
    end

    // Instruction memory address
    assign imem_addr = pc;

    // -------------------------------------------------------------------------
    // Execute
    // -------------------------------------------------------------------------

    // ALU operand A selection
    always_comb begin
        if (is_auipc) begin
            alu_operand_a = pc;        // AUIPC uses PC
        end else if (is_lui) begin
            alu_operand_a = 32'b0;     // LUI uses 0
        end else begin
            alu_operand_a = rs1_data;
        end
    end

    // ALU operand B selection (mux for rs2 or immediate)
    assign alu_operand_b = alu_src ? immediate : rs2_data;

    // Register file write data selection
    always_comb begin
        if (jal | jalr) begin
            rd_data = pc_plus4;        // return address
        end else if (is_lui) begin
            rd_data = immediate;       // LUI immediate
        end else if (mem_to_reg) begin
            rd_data = dmem_rdata;      // load
        end else begin
            rd_data = alu_result;      // ALU
        end
    end

    // Data memory interface
    assign dmem_addr  = alu_result;
    assign dmem_wdata = rs2_data;
    assign dmem_write = mem_write;
    assign dmem_read  = mem_read;

    // -------------------------------------------------------------------------
    // Units
    // -------------------------------------------------------------------------

    control_unit u_control_unit (
        .instruction  (instruction),
        .alu_control  (alu_control),
        .imm_sel      (imm_sel),
        .reg_write    (reg_write),
        .mem_write    (mem_write),
        .mem_read     (mem_read),
        .mem_to_reg   (mem_to_reg),
        .alu_src      (alu_src),
        .pc_src       (pc_src),
        .branch       (branch),
        .jal          (jal),
        .jalr         (jalr)
    );

    alu u_alu (
        .operand_a    (alu_operand_a),
        .operand_b    (alu_operand_b),
        .alu_control  (alu_control),
        .alu_result   (alu_result),
        .zero_flag    (zero_flag)
    );

    regfile u_regfile (
        .clock        (clock),
        .reset        (reset),
        .rs1_addr     (rs1_addr),
        .rs2_addr     (rs2_addr),
        .rd_addr      (rd_addr),
        .rd_data      (rd_data),
        .reg_write    (reg_write),
        .rs1_data     (rs1_data),
        .rs2_data     (rs2_data)
    );

    imm_gen u_imm_gen (
        .instruction  (instruction),
        .imm_sel      (imm_sel),
        .immediate    (immediate)
    );

    // -------------------------------------------------------------------------
    // PC register (separate always_ff)
    // -------------------------------------------------------------------------
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            pc <= 32'b0;
        end else begin
            pc <= pc_next;
        end
    end

    // -------------------------------------------------------------------------
    // COMMIT-ALIGNED DEBUG OUTPUTS (REGISTERED)
    // This fixes the "1 instruction ahead" issue in the testbench comparisons.
    // -------------------------------------------------------------------------
    logic [31:0] dbg_pc_r;
    logic        dbg_regwrite_r;
    logic [4:0]  dbg_rd_r;
    logic [31:0] dbg_wdata_r;
    logic        dbg_memwrite_r;
    logic [31:0] dbg_memaddr_r;
    logic [31:0] dbg_memwdata_r;

    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            dbg_pc_r       <= 32'b0;
            dbg_regwrite_r <= 1'b0;
            dbg_rd_r       <= 5'b0;
            dbg_wdata_r    <= 32'b0;
            dbg_memwrite_r <= 1'b0;
            dbg_memaddr_r  <= 32'b0;
            dbg_memwdata_r <= 32'b0;
        end else begin
            // Golden model reports PC *after* commit, so match that
            dbg_pc_r       <= pc_next;

            dbg_regwrite_r <= (reg_write && (rd_addr != 5'b0));
            dbg_rd_r       <= rd_addr;
            dbg_wdata_r    <= rd_data;
            dbg_memwrite_r <= mem_write;
            dbg_memaddr_r  <= dmem_addr;
            dbg_memwdata_r <= dmem_wdata;
        end
    end


    assign dbg_pc       = dbg_pc_r;
    assign dbg_regwrite = dbg_regwrite_r;
    assign dbg_rd       = dbg_rd_r;
    assign dbg_wdata    = dbg_wdata_r;
    assign dbg_memwrite = dbg_memwrite_r;
    assign dbg_memaddr  = dbg_memaddr_r;
    assign dbg_memwdata = dbg_memwdata_r;

endmodule
