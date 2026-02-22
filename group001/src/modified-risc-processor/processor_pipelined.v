// =============================================================================
// E20 Pipelined Processor
// =============================================================================
// Description:
//   5-stage pipelined implementation of the E20 RISC processor
//   - Pipeline stages: IF, ID, EXEC, MEM, WB
//   - Hazard detection: stalling for load-use hazards
//   - Data forwarding from EXEC, MEM, and WB stages
//   - Control hazard handling: flushing for jumps and branches
//   - 8 general-purpose 16-bit registers ($0 hardwired to zero)
//   - 8192 words of 16-bit memory (13-bit addressing)
//   - 17 instructions: ADD, SUB, OR, AND, SLT, JR, XOR, NOR, SLL, SRL, SRA,
//                      ADDI, LW, SW, JEQ, SLTI, J, JAL
//
// Ports:
//   clock         - System clock
//   reset         - Active high reset (initializes PC to 0, clears registers)
//   halt          - Output signal indicating processor has halted (PC unchanged)
//   debug_pc      - Current program counter value (for monitoring)
//   debug_instr   - Current instruction being executed (for monitoring)
//   debug_cycle   - Instruction cycle counter (for performance analysis)
//
// =============================================================================

module processor_pipelined (
    input  wire        clock,
    input  wire        reset,
    output wire        halt,
    // Debug outputs
    output wire [15:0] debug_pc,
    output wire [15:0] debug_instr,
    output wire [31:0] debug_cycle
);

    // =============================================================================
    // Parameters and Constants
    // =============================================================================
    parameter MEM_SIZE = 8192;  // 2^13
    parameter NUM_REGS = 8;
    parameter REG_BITS = 3;
    
    // Opcodes (3 MSBs of instruction [15:13])
    localparam [2:0] THREE_REG = 3'b000;
    localparam [2:0] ADDI      = 3'b001;
    localparam [2:0] J         = 3'b010;
    localparam [2:0] JAL       = 3'b011;
    localparam [2:0] LW        = 3'b100;
    localparam [2:0] SW        = 3'b101;
    localparam [2:0] JEQ       = 3'b110;
    localparam [2:0] SLTI      = 3'b111;
    
    // Function codes for THREE_REG instructions (4 LSBs [3:0])
    localparam [3:0] ADD  = 4'b0000;
    localparam [3:0] SUB  = 4'b0001;
    localparam [3:0] OR   = 4'b0010;
    localparam [3:0] AND  = 4'b0011;
    localparam [3:0] SLT  = 4'b0100;
    localparam [3:0] XOR  = 4'b0101;
    localparam [3:0] NOR  = 4'b0110;
    localparam [3:0] JR   = 4'b1000;
    localparam [3:0] SLL  = 4'b1001;
    localparam [3:0] SRL  = 4'b1010;
    localparam [3:0] SRA  = 4'b1011;
    
    // Link register for JAL instruction
    localparam [2:0] LINK_REG = 3'd7;
    
    // NOP instruction
    localparam [15:0] NOP = 16'h0000;
    
    // ALU operation codes
    localparam [2:0] ALU_ADD = 3'd0;
    localparam [2:0] ALU_SUB = 3'd1;
    localparam [2:0] ALU_AND = 3'd2;
    localparam [2:0] ALU_OR  = 3'd3;
    localparam [2:0] ALU_SLT = 3'd4;
    localparam [2:0] ALU_XOR = 3'd5;
    localparam [2:0] ALU_NOR = 3'd6;

    // =============================================================================
    // Memory and Register File
    // =============================================================================
    
    // Memory
    reg  [15:0] ram [0:MEM_SIZE-1];
    
    // Register file
    reg  [15:0] regs [0:NUM_REGS-1];
    
    // =============================================================================
    // Pipeline Registers - Stage 0 (IF)
    // =============================================================================
    reg  [15:0] PC0;  // Current fetch PC
    
    // =============================================================================
    // Pipeline Registers - Stage 1 (ID)
    // =============================================================================
    reg  [15:0] IR1;  // Instruction register stage 1
    reg  [15:0] PC1;  // PC stage 1
    
    // =============================================================================
    // Pipeline Registers - Stage 2 (EXEC)
    // =============================================================================
    reg  [15:0] IR2;  // Instruction register stage 2
    reg  [15:0] PC2;  // PC stage 2
    reg  [15:0] A2;   // ALU operand A
    reg  [15:0] B2;   // ALU operand B
    
    // =============================================================================
    // Pipeline Registers - Stage 3 (MEM)
    // =============================================================================
    reg  [15:0] IR3;     // Instruction register stage 3
    reg  [15:0] PC3;     // PC stage 3
    reg  [15:0] aluOut;  // ALU result
    reg  [15:0] B3;      // Store data for SW
    
    // =============================================================================
    // Pipeline Registers - Stage 4 (WB)
    // =============================================================================
    reg  [15:0] IR4;   // Instruction register stage 4
    reg  [15:0] PC4;   // PC stage 4
    reg  [15:0] mOut;  // Memory/ALU output
    
    // =============================================================================
    // Pipeline Registers - Stage 5 (for forwarding)
    // =============================================================================
    reg  [15:0] IR5;    // Instruction register stage 5
    reg  [15:0] wbOut;  // Write-back value
    
    // =============================================================================
    // Control Signals
    // =============================================================================
    
    // CTLid outputs
    wire        Pnop1;     // Flush IF/ID pipeline register
    wire        Pstall;    // Stall IF/ID stage
    wire        MUXr1;     // Select register to read
    wire        MUXb;      // Select B2 source
    wire        Pnop2;     // Flush ID/EXEC pipeline register (from CTLid)
    
    // CTLexec1 outputs
    wire [1:0]  MUXalu1;   // ALU input A forwarding mux
    wire [1:0]  MUXalu2;   // ALU input B forwarding mux
    wire        MUXalu3;   // Select immediate or register
    wire [2:0]  aluOp;     // ALU operation
    
    // CTLexec2 outputs
    wire        Pnop2_exec2;  // Flush ID/EXEC (from CTLexec2)
    wire        MUXifpc;      // PC source select
    wire        EQ;           // Equality result
    wire [15:0] MUXjmp;       // Jump target address
    
    // CTLmem outputs
    wire        WEram;     // Memory write enable
    wire        MUXmout;   // Memory output mux
    
    // CTLwb outputs
    wire [1:0]  MUXrw;     // Register write address select
    wire        MUXtgt;    // Register write data select
    wire        WEreg;     // Register write enable
    wire        WEpc;      // PC write enable
    
    // =============================================================================
    // Halt and Cycle Counter
    // =============================================================================
    reg         halted;
    reg  [31:0] cycle_count;
    reg  [15:0] prev_pc0;
    reg  [3:0]  pc_unchanged_count;
    
    // Debug signal assignments
    assign debug_pc = PC0;
    assign debug_instr = IR1;
    assign debug_cycle = cycle_count;
    assign halt = halted;

    // =============================================================================
    // Helper Functions for Instruction Decoding
    // =============================================================================
    
    function [2:0] get_opcode;
        input [15:0] instr;
        begin
            get_opcode = instr[15:13];
        end
    endfunction
    
    function [3:0] get_func;
        input [15:0] instr;
        begin
            get_func = instr[3:0];
        end
    endfunction
    
    function [2:0] get_reg1;
        input [15:0] instr;
        begin
            get_reg1 = instr[12:10];
        end
    endfunction
    
    function [2:0] get_reg2;
        input [15:0] instr;
        begin
            get_reg2 = instr[9:7];
        end
    endfunction
    
    function [2:0] get_reg3;
        input [15:0] instr;
        begin
            get_reg3 = instr[6:4];
        end
    endfunction
    
    function [15:0] get_imm7_signed;
        input [15:0] instr;
        reg [6:0] imm7;
        begin
            imm7 = instr[6:0];
            get_imm7_signed = imm7[6] ? {9'b111111111, imm7} : {9'b000000000, imm7};
        end
    endfunction
    
    function [12:0] get_imm13;
        input [15:0] instr;
        begin
            get_imm13 = instr[12:0];
        end
    endfunction
    
    function is_lw;
        input [15:0] instr;
        begin
            is_lw = (get_opcode(instr) == LW);
        end
    endfunction
    
    function is_sw;
        input [15:0] instr;
        begin
            is_sw = (get_opcode(instr) == SW);
        end
    endfunction
    
    function is_jump;
        input [15:0] instr;
        reg [2:0] op;
        reg [3:0] fn;
        begin
            op = get_opcode(instr);
            fn = get_func(instr);
            is_jump = (op == J) || (op == JAL) || (op == JEQ) || 
                      ((op == THREE_REG) && (fn == JR));
        end
    endfunction
    
    function [2:0] get_dest_reg;
        input [15:0] instr;
        reg [2:0] op;
        begin
            op = get_opcode(instr);
            if (op == THREE_REG)
                get_dest_reg = get_reg3(instr);
            else if (op == JAL)
                get_dest_reg = LINK_REG;
            else
                get_dest_reg = get_reg2(instr);
        end
    endfunction
    
    function writes_register;
        input [15:0] instr;
        reg [2:0] op;
        reg [3:0] fn;
        begin
            op = get_opcode(instr);
            fn = get_func(instr);
            writes_register = !((op == SW) || (op == JEQ) || 
                               ((op == THREE_REG) && (fn == JR)));
        end
    endfunction

    // =============================================================================
    // CTLid - Decode and Stalling Control
    // =============================================================================
    
    wire       needs_stall;
    wire       ir2_is_lw;
    wire [2:0] ir1_reg1, ir1_reg2;
    wire [2:0] ir2_dest;
    
    assign ir2_is_lw = is_lw(IR2);
    assign ir1_reg1 = get_reg1(IR1);
    assign ir1_reg2 = get_reg2(IR1);
    assign ir2_dest = get_dest_reg(IR2);
    
    // Check for load-use hazard
    assign needs_stall = ir2_is_lw && 
                        ((ir1_reg1 == ir2_dest && ir1_reg1 != 3'd0) ||
                         (ir1_reg2 == ir2_dest && ir1_reg2 != 3'd0));
    
    assign Pstall = needs_stall;
    assign Pnop2 = needs_stall;
    assign Pnop1 = 1'b0;  // Only flushed by CTLexec2
    
    // MUXr1: 0=literal 0, 1=IR1.reg1
    assign MUXr1 = (ir1_reg1 != 3'd0) ? 1'b1 : 1'b0;
    
    // MUXb: 0=r2dataOut, 1=IR1.imm13
    assign MUXb = (get_opcode(IR1) == J || get_opcode(IR1) == JAL) ? 1'b1 : 1'b0;

    // =============================================================================
    // CTLexec1 - Execution Control and Forwarding
    // =============================================================================
    
    wire [2:0] ir2_reg1, ir2_reg2, ir3_dest, ir4_dest, ir5_dest;
    wire       ir3_writes, ir4_writes, ir5_writes;
    
    assign ir2_reg1 = get_reg1(IR2);
    assign ir2_reg2 = get_reg2(IR2);
    assign ir3_dest = get_dest_reg(IR3);
    assign ir4_dest = get_dest_reg(IR4);
    assign ir5_dest = get_dest_reg(IR5);
    assign ir3_writes = writes_register(IR3);
    assign ir4_writes = writes_register(IR4);
    assign ir5_writes = writes_register(IR5);
    
    // Forwarding for ALU input A (from A2)
    reg [1:0] muxalu1_val;
    always @(*) begin
        if (ir3_writes && ir3_dest != 3'd0 && ir3_dest == ir2_reg1)
            muxalu1_val = 2'd0;  // Forward from aluOut
        else if (ir4_writes && ir4_dest != 3'd0 && ir4_dest == ir2_reg1)
            muxalu1_val = 2'd1;  // Forward from mOut
        else if (ir5_writes && ir5_dest != 3'd0 && ir5_dest == ir2_reg1)
            muxalu1_val = 2'd2;  // Forward from wbOut
        else
            muxalu1_val = 2'd3;  // Use A2
    end
    assign MUXalu1 = muxalu1_val;
    
    // Forwarding for ALU input B (from B2)
    reg [1:0] muxalu2_val;
    always @(*) begin
        if (ir3_writes && ir3_dest != 3'd0 && ir3_dest == ir2_reg2)
            muxalu2_val = 2'd0;  // Forward from aluOut
        else if (ir4_writes && ir4_dest != 3'd0 && ir4_dest == ir2_reg2)
            muxalu2_val = 2'd1;  // Forward from mOut
        else if (ir5_writes && ir5_dest != 3'd0 && ir5_dest == ir2_reg2)
            muxalu2_val = 2'd2;  // Forward from wbOut
        else
            muxalu2_val = 2'd3;  // Use B2
    end
    assign MUXalu2 = muxalu2_val;
    
    // MUXalu3: 0=IR2.imm7, 1=MUXalu2 output
    assign MUXalu3 = (get_opcode(IR2) == ADDI || get_opcode(IR2) == SLTI ||
                      get_opcode(IR2) == LW || get_opcode(IR2) == SW) ? 1'b0 : 1'b1;
    
    // ALU operation selection
    reg [2:0] alu_op_val;
    always @(*) begin
        case (get_opcode(IR2))
            THREE_REG: begin
                case (get_func(IR2))
                    ADD:  alu_op_val = ALU_ADD;
                    SUB:  alu_op_val = ALU_SUB;
                    AND:  alu_op_val = ALU_AND;
                    OR:   alu_op_val = ALU_OR;
                    SLT:  alu_op_val = ALU_SLT;
                    XOR:  alu_op_val = ALU_XOR;
                    NOR:  alu_op_val = ALU_NOR;
                    default: alu_op_val = ALU_ADD;
                endcase
            end
            ADDI, LW, SW: alu_op_val = ALU_ADD;
            SLTI:         alu_op_val = ALU_SLT;
            default:      alu_op_val = ALU_ADD;
        endcase
    end
    assign aluOp = alu_op_val;

    // =============================================================================
    // CTLexec2 - Jump and Branch Control
    // =============================================================================
    
    wire       is_jeq, is_j, is_jal, is_jr;
    wire       take_jump;
    wire [15:0] alu_in1, alu_in2;
    
    assign is_jeq = (get_opcode(IR2) == JEQ);
    assign is_j = (get_opcode(IR2) == J);
    assign is_jal = (get_opcode(IR2) == JAL);
    assign is_jr = (get_opcode(IR2) == THREE_REG && get_func(IR2) == JR);
    
    // Get ALU inputs after forwarding for equality check
    assign alu_in1 = (MUXalu1 == 2'd0) ? aluOut :
                     (MUXalu1 == 2'd1) ? mOut :
                     (MUXalu1 == 2'd2) ? wbOut : A2;
    
    assign alu_in2 = (MUXalu2 == 2'd0) ? aluOut :
                     (MUXalu2 == 2'd1) ? mOut :
                     (MUXalu2 == 2'd2) ? wbOut : B2;
    
    assign EQ = (alu_in1 == alu_in2);
    
    // Take jump if: unconditional jump OR (conditional jump AND equal)
    assign take_jump = is_j || is_jal || is_jr || (is_jeq && EQ);
    
    assign Pnop2_exec2 = take_jump;
    assign MUXifpc = take_jump;
    
    // Jump target address
    assign MUXjmp = is_jr ? alu_in1 : 
                    (is_jeq ? (PC2 + get_imm7_signed(IR2) + 16'd1) :
                    {3'b000, get_imm13(IR2)});

    // =============================================================================
    // CTLmem - Memory Access Control
    // =============================================================================
    
    assign WEram = is_sw(IR3);
    assign MUXmout = is_lw(IR3) ? 1'b1 : 1'b0;

    // =============================================================================
    // CTLwb - Write Back Control
    // =============================================================================
    
    wire [2:0] wb_opcode;
    assign wb_opcode = get_opcode(IR4);
    
    // MUXrw: 0=IR4.reg2, 1=IR4.reg3, 2=literal 7
    assign MUXrw = (wb_opcode == JAL) ? 2'd2 :
                   (wb_opcode == THREE_REG) ? 2'd1 : 2'd0;
    
    // MUXtgt: 0=mOut, 1=PC4+1
    assign MUXtgt = (wb_opcode == JAL) ? 1'b1 : 1'b0;
    
    // Write enable for registers
    assign WEreg = writes_register(IR4) && (get_dest_reg(IR4) != 3'd0);
    
    // PC write enable (disabled during stall)
    assign WEpc = !Pstall;

    // =============================================================================
    // Pipeline Stage Logic
    // =============================================================================
    
    // Stage 0: Instruction Fetch
    wire [15:0] instr_fetched;
    wire [15:0] pc_next;
    
    assign instr_fetched = ram[PC0[12:0]];
    assign pc_next = MUXifpc ? MUXjmp : (PC0 + 16'd1);
    
    // Stage 1: Instruction Decode
    wire [15:0] r1_data, r2_data;
    wire [2:0]  r1_addr, r2_addr;
    
    assign r1_addr = MUXr1 ? get_reg1(IR1) : 3'd0;
    assign r2_addr = get_reg2(IR1);
    assign r1_data = (r1_addr == 3'd0) ? 16'd0 : regs[r1_addr];
    assign r2_data = (r2_addr == 3'd0) ? 16'd0 : regs[r2_addr];
    
    wire [15:0] b2_next;
    assign b2_next = MUXb ? {3'b000, get_imm13(IR1)} : r2_data;
    
    // Stage 2: Execute
    wire [15:0] alu_operand1, alu_operand2;
    reg  [15:0] alu_result;
    wire [15:0] alu_imm7;
    
    assign alu_operand1 = (MUXalu1 == 2'd0) ? aluOut :
                          (MUXalu1 == 2'd1) ? mOut :
                          (MUXalu1 == 2'd2) ? wbOut : A2;
    
    wire [15:0] muxalu2_out;
    assign muxalu2_out = (MUXalu2 == 2'd0) ? aluOut :
                         (MUXalu2 == 2'd1) ? mOut :
                         (MUXalu2 == 2'd2) ? wbOut : B2;
    
    assign alu_imm7 = get_imm7_signed(IR2);
    assign alu_operand2 = MUXalu3 ? muxalu2_out : alu_imm7;
    
    // ALU implementation
    always @(*) begin
        case (aluOp)
            ALU_ADD: alu_result = alu_operand1 + alu_operand2;
            ALU_SUB: alu_result = alu_operand1 - alu_operand2;
            ALU_AND: alu_result = alu_operand1 & alu_operand2;
            ALU_OR:  alu_result = alu_operand1 | alu_operand2;
            ALU_SLT: alu_result = (alu_operand1 < alu_operand2) ? 16'd1 : 16'd0;
            ALU_XOR: alu_result = alu_operand1 ^ alu_operand2;
            ALU_NOR: alu_result = ~(alu_operand1 | alu_operand2);
            default: alu_result = alu_operand1 + alu_operand2;
        endcase
        
        // Handle shift operations separately
        if (get_opcode(IR2) == THREE_REG) begin
            case (get_func(IR2))
                SLL: alu_result = alu_operand1 << alu_operand2[3:0];
                SRL: alu_result = alu_operand1 >> alu_operand2[3:0];
                SRA: alu_result = $signed(alu_operand1) >>> alu_operand2[3:0];
                default: ;  // Already handled above
            endcase
        end
    end
    
    // B3 forwarding for store operations
    wire [15:0] b3_next;
    assign b3_next = muxalu2_out;
    
    // Stage 3: Memory Access
    wire [15:0] mem_data;
    wire [12:0] mem_addr;
    
    assign mem_addr = aluOut[12:0];
    assign mem_data = ram[mem_addr];
    
    wire [15:0] mout_next;
    assign mout_next = MUXmout ? mem_data : aluOut;
    
    // Stage 4: Write Back
    wire [15:0] wb_data;
    wire [2:0]  wb_addr;
    
    assign wb_data = MUXtgt ? (PC4 + 16'd1) : mOut;
    assign wb_addr = (MUXrw == 2'd2) ? LINK_REG :
                     (MUXrw == 2'd1) ? get_reg3(IR4) : get_reg2(IR4);

    // =============================================================================
    // Sequential Logic - Pipeline Registers Update
    // =============================================================================
    
    integer i;
    
    always @(posedge clock or posedge reset) begin
        if (reset) begin
            // Initialize pipeline registers
            PC0 <= 16'd0;
            IR1 <= NOP;
            PC1 <= 16'd0;
            IR2 <= NOP;
            PC2 <= 16'd0;
            A2 <= 16'd0;
            B2 <= 16'd0;
            IR3 <= NOP;
            PC3 <= 16'd0;
            aluOut <= 16'd0;
            B3 <= 16'd0;
            IR4 <= NOP;
            PC4 <= 16'd0;
            mOut <= 16'd0;
            IR5 <= NOP;
            wbOut <= 16'd0;
            
            // Initialize register file
            for (i = 0; i < NUM_REGS; i = i + 1) begin
                regs[i] <= 16'd0;
            end
            
            halted <= 1'b0;
            cycle_count <= 32'd0;
            prev_pc0 <= 16'd0;
            pc_unchanged_count <= 4'd0;
        end else begin
            if (!halted) begin
                // Stage 5: Write Back completion
                IR5 <= IR4;
                wbOut <= wb_data;
                
                // Stage 4: Memory -> Write Back
                IR4 <= IR3;
                PC4 <= PC3;
                mOut <= mout_next;
                
                // Stage 3: Execute -> Memory
                IR3 <= IR2;
                PC3 <= PC2;
                aluOut <= alu_result;
                B3 <= b3_next;
                
                // Stage 2: Decode -> Execute
                if (Pnop2 || Pnop2_exec2) begin
                    IR2 <= NOP;  // Insert bubble
                end else begin
                    IR2 <= IR1;
                end
                PC2 <= PC1;
                A2 <= r1_data;
                B2 <= b2_next;
                
                // Stage 1: Fetch -> Decode
                if (Pnop1 || Pnop2_exec2) begin
                    IR1 <= NOP;  // Flush on branch/jump
                end else if (!Pstall) begin
                    IR1 <= instr_fetched;
                end
                // else: stall, keep IR1 unchanged
                
                if (!Pstall) begin
                    PC1 <= PC0;
                end
                
                // Stage 0: PC update
                if (WEpc) begin
                    PC0 <= pc_next;
                end
                
                // Write to register file
                if (WEreg) begin
                    regs[wb_addr] <= wb_data;
                end
                
                // Write to memory
                if (WEram) begin
                    ram[mem_addr] <= B3;
                end
                
                // Halt detection: Jump to self or PC unchanged for several cycles
                // Quick halt: if jumping to the same PC (j X when PC=X in EXEC stage)
                if (MUXifpc && (MUXjmp == PC2)) begin
                    halted <= 1'b1;
                end
                // Slower halt: PC hasn't changed for several consecutive cycles
                else if (PC0 == prev_pc0 && !Pstall) begin
                    pc_unchanged_count <= pc_unchanged_count + 1;
                    if (pc_unchanged_count >= 4'd5) begin
                        halted <= 1'b1;
                    end
                end else begin
                    pc_unchanged_count <= 4'd0;
                end
                prev_pc0 <= PC0;
                
                // Increment cycle counter
                cycle_count <= cycle_count + 1;
            end
        end
    end

endmodule
