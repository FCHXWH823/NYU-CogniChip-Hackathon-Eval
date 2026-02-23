// golden_rv32i.sv
// Behavioral golden reference for a small RV32I subset.
// Supports: add, addi, lw, sw, beq, jal

module golden_rv32i #(
  parameter int DMEM_WORDS = 1024
) (
  input  logic        clk,
  input  logic        reset,

  // Step control: execute exactly one instruction on posedge when step_en=1
  input  logic        step_en,
  input  logic [31:0] instr,

  // Golden architectural state
  output logic [31:0] g_pc,

  // Commit info for lockstep comparison
  output logic        g_regwrite,
  output logic [4:0]  g_rd,
  output logic [31:0] g_wdata,

  output logic        g_memwrite,
  output logic [31:0] g_memaddr,
  output logic [31:0] g_memwdata
);

  // ----------------------------
  // State
  // ----------------------------
  logic [31:0] regs [0:31];
  logic [31:0] dmem [0:DMEM_WORDS-1];

  // ----------------------------
  // Immediate helpers (tool-safe)
  // ----------------------------
  function automatic logic [31:0] imm_i(input logic [31:0] ins);
    imm_i = {{20{ins[31]}}, ins[31:20]};  // 12-bit sign-extended
  endfunction

  function automatic logic [31:0] imm_s(input logic [31:0] ins);
    imm_s = {{20{ins[31]}}, ins[31:25], ins[11:7]};  // 12-bit sign-extended
  endfunction

  function automatic logic [31:0] imm_b(input logic [31:0] ins);
    imm_b = {{19{ins[31]}}, ins[31], ins[7], ins[30:25], ins[11:8], 1'b0};  // 13-bit signed
  endfunction

  function automatic logic [31:0] imm_j(input logic [31:0] ins);
    imm_j = {{11{ins[31]}}, ins[31], ins[19:12], ins[20], ins[30:21], 1'b0};  // 21-bit signed
  endfunction

  // ----------------------------
  // Data memory helpers (word addressed)
  // ----------------------------
  function automatic logic [31:0] dmem_read_word(input logic [31:0] byte_addr);
    int unsigned idx;
    begin
      idx = byte_addr[31:2];
      if (idx < DMEM_WORDS) dmem_read_word = dmem[idx];
      else                  dmem_read_word = 32'h0000_0000;
    end
  endfunction

  task automatic dmem_write_word(input logic [31:0] byte_addr, input logic [31:0] data);
    int unsigned idx;
    begin
      idx = byte_addr[31:2];
      if (idx < DMEM_WORDS) dmem[idx] <= data;
    end
  endtask

  // ----------------------------
  // Reset + step execution
  // ----------------------------
  integer i;

  always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
      g_pc       <= 32'h0000_0000;
      g_regwrite <= 1'b0;
      g_rd       <= 5'd0;
      g_wdata    <= 32'h0;
      g_memwrite <= 1'b0;
      g_memaddr  <= 32'h0;
      g_memwdata <= 32'h0;

      for (i = 0; i < 32; i++) regs[i] <= 32'h0;
      for (i = 0; i < DMEM_WORDS; i++) dmem[i] <= 32'h0;

    end else begin
      // Defaults each step
      g_regwrite <= 1'b0;
      g_rd       <= 5'd0;
      g_wdata    <= 32'h0;
      g_memwrite <= 1'b0;
      g_memaddr  <= 32'h0;
      g_memwdata <= 32'h0;

      if (step_en) begin
        // Decode
        logic [6:0] opcode;
        logic [2:0] funct3;
        logic [6:0] funct7;
        logic [4:0] rd, rs1, rs2;
        logic [31:0] a, b;
        logic [31:0] next_pc;

        opcode = instr[6:0];
        rd     = instr[11:7];
        funct3 = instr[14:12];
        rs1    = instr[19:15];
        rs2    = instr[24:20];
        funct7 = instr[31:25];

        a = (rs1 == 0) ? 32'h0 : regs[rs1];
        b = (rs2 == 0) ? 32'h0 : regs[rs2];

        next_pc = g_pc + 32'd4;

        unique case (opcode)

          // R-type ADD
          7'b0110011: begin
            if (funct3 == 3'b000 && funct7 == 7'b0000000) begin
              if (rd != 0) begin
                regs[rd]   <= a + b;
                g_regwrite <= 1'b1;
                g_rd       <= rd;
                g_wdata    <= a + b;
              end
            end
          end

          // I-type ADDI
          7'b0010011: begin
            if (funct3 == 3'b000) begin
              logic [31:0] imm;
              imm = imm_i(instr);
              if (rd != 0) begin
                regs[rd]   <= a + imm;
                g_regwrite <= 1'b1;
                g_rd       <= rd;
                g_wdata    <= a + imm;
              end
            end
          end

          // LW
          7'b0000011: begin
            if (funct3 == 3'b010) begin
              logic [31:0] addr;
              logic [31:0] data;
              addr = a + imm_i(instr);
              data = dmem_read_word(addr);
              if (rd != 0) begin
                regs[rd]   <= data;
                g_regwrite <= 1'b1;
                g_rd       <= rd;
                g_wdata    <= data;
              end
            end
          end

          // SW
          7'b0100011: begin
            if (funct3 == 3'b010) begin
              logic [31:0] addr;
              addr = a + imm_s(instr);
              dmem_write_word(addr, b);
              g_memwrite <= 1'b1;
              g_memaddr  <= addr;
              g_memwdata <= b;
            end
          end

          // BEQ
          7'b1100011: begin
            if (funct3 == 3'b000) begin
              if (a == b) next_pc = g_pc + imm_b(instr);
            end
          end

          // JAL
          7'b1101111: begin
            logic [31:0] ret;
            ret = g_pc + 32'd4;
            if (rd != 0) begin
              regs[rd]   <= ret;
              g_regwrite <= 1'b1;
              g_rd       <= rd;
              g_wdata    <= ret;
            end
            next_pc = g_pc + imm_j(instr);
          end

          default: begin
            // Unsupported: no-op (PC still advances by 4)
          end

        endcase

        // Enforce x0 = 0
        regs[0] <= 32'h0;

        // Commit PC
        g_pc <= next_pc;
      end
    end
  end

endmodule
