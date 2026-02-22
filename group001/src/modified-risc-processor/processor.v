// =============================================================================
// E20 Processor
// =============================================================================
// Description:
//   Single-cycle implementation of the E20 RISC processor
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

module processor (
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
    localparam [3:0] XOR  = 4'b0101;  // NEW: Bitwise XOR
    localparam [3:0] NOR  = 4'b0110;  // NEW: Bitwise NOR
    localparam [3:0] JR   = 4'b1000;
    localparam [3:0] SLL  = 4'b1001;  // NEW: Shift left logical
    localparam [3:0] SRL  = 4'b1010;  // NEW: Shift right logical
    localparam [3:0] SRA  = 4'b1011;  // NEW: Shift right arithmetic
    
    // Link register for JAL instruction
    localparam [2:0] LINK_REG = 3'd7;
    
    // Register field positions in instruction
    localparam LEFT_REG_POS  = 10;
    localparam MID_REG_POS   = 7;
    localparam RIGHT_REG_POS = 4;

    // =============================================================================
    // Internal Signals
    // =============================================================================
    
    // Program counter
    reg  [15:0] pc;
    reg  [15:0] pc_next;
    reg  [15:0] prev_pc;
    
    // Memory
    reg  [15:0] ram [0:MEM_SIZE-1];
    
    // Register file
    reg  [15:0] regs [0:NUM_REGS-1];
    
    // Current instruction and decoded fields
    wire [15:0] curr_instr;
    wire [2:0]  opcode;
    wire [3:0]  func;
    wire [2:0]  left_reg;
    wire [2:0]  mid_reg;
    wire [2:0]  right_reg;
    wire [6:0]  imm7_raw;
    wire [15:0] imm7_signed;
    wire [12:0] imm13;
    
    // Register file access
    wire [15:0] reg_left_val;
    wire [15:0] reg_mid_val;
    wire [15:0] reg_right_val;
    
    // Memory address calculation
    wire [12:0] mem_addr;
    wire [15:0] mem_addr_full;
    
    // ALU and control signals
    reg  [15:0] alu_result;
    reg  [15:0] reg_write_data;
    reg  [2:0]  reg_write_addr;
    reg         reg_write_enable;
    reg         mem_write_enable;
    
    // Halt detection
    reg         halted;
    
    // Instruction cycle counter for performance monitoring
    reg  [31:0] cycle_count;
    
    // Debug signal assignments
    assign debug_pc = pc;
    assign debug_instr = curr_instr;
    assign debug_cycle = cycle_count;

    // =============================================================================
    // Instruction Fetch
    // =============================================================================
    
    // Fetch instruction from memory using lower 13 bits of PC
    assign curr_instr = ram[pc[12:0]];
    
    // =============================================================================
    // Instruction Decode
    // =============================================================================
    
    // Extract opcode and function fields
    assign opcode = curr_instr[15:13];
    assign func   = curr_instr[3:0];
    
    // Extract register fields
    assign left_reg  = curr_instr[LEFT_REG_POS +: REG_BITS];
    assign mid_reg   = curr_instr[MID_REG_POS +: REG_BITS];
    assign right_reg = curr_instr[RIGHT_REG_POS +: REG_BITS];
    
    // Extract immediate fields
    assign imm7_raw = curr_instr[6:0];
    assign imm13    = curr_instr[12:0];
    
    // Sign-extend imm7 to 16 bits
    assign imm7_signed = imm7_raw[6] ? {9'b111111111, imm7_raw} : {9'b000000000, imm7_raw};
    
    // Read register values (register 0 is always 0)
    assign reg_left_val  = (left_reg == 3'd0)  ? 16'd0 : regs[left_reg];
    assign reg_mid_val   = (mid_reg == 3'd0)   ? 16'd0 : regs[mid_reg];
    assign reg_right_val = (right_reg == 3'd0) ? 16'd0 : regs[right_reg];
    
    // Calculate memory address (base + offset, masked to 13 bits)
    assign mem_addr_full = reg_left_val + imm7_signed;
    assign mem_addr = mem_addr_full[12:0];

    // =============================================================================
    // Execute & Memory Access
    // =============================================================================
    
    always @(*) begin
        // Default values
        pc_next = pc + 16'd1;  // Default: increment PC
        alu_result = 16'd0;
        reg_write_data = 16'd0;
        reg_write_addr = 3'd0;
        reg_write_enable = 1'b0;
        mem_write_enable = 1'b0;
        
        case (opcode)
            THREE_REG: begin
                // Three-register instructions
                case (func)
                    ADD: begin
                        alu_result = reg_left_val + reg_mid_val;
                        reg_write_data = alu_result;
                        reg_write_addr = right_reg;
                        reg_write_enable = (right_reg != 3'd0);
                    end
                    
                    SUB: begin
                        alu_result = reg_left_val - reg_mid_val;
                        reg_write_data = alu_result;
                        reg_write_addr = right_reg;
                        reg_write_enable = (right_reg != 3'd0);
                    end
                    
                    OR: begin
                        alu_result = reg_left_val | reg_mid_val;
                        reg_write_data = alu_result;
                        reg_write_addr = right_reg;
                        reg_write_enable = (right_reg != 3'd0);
                    end
                    
                    AND: begin
                        alu_result = reg_left_val & reg_mid_val;
                        reg_write_data = alu_result;
                        reg_write_addr = right_reg;
                        reg_write_enable = (right_reg != 3'd0);
                    end
                    
                    SLT: begin
                        // Unsigned comparison
                        alu_result = (reg_left_val < reg_mid_val) ? 16'd1 : 16'd0;
                        reg_write_data = alu_result;
                        reg_write_addr = right_reg;
                        reg_write_enable = (right_reg != 3'd0);
                    end
                    
                    JR: begin
                        // Jump to register value
                        pc_next = reg_left_val;
                    end
                    
                    XOR: begin
                        // Bitwise XOR
                        alu_result = reg_left_val ^ reg_mid_val;
                        reg_write_data = alu_result;
                        reg_write_addr = right_reg;
                        reg_write_enable = (right_reg != 3'd0);
                    end
                    
                    NOR: begin
                        // Bitwise NOR
                        alu_result = ~(reg_left_val | reg_mid_val);
                        reg_write_data = alu_result;
                        reg_write_addr = right_reg;
                        reg_write_enable = (right_reg != 3'd0);
                    end
                    
                    SLL: begin
                        // Shift left logical (use lower 4 bits for shift amount)
                        alu_result = reg_left_val << reg_mid_val[3:0];
                        reg_write_data = alu_result;
                        reg_write_addr = right_reg;
                        reg_write_enable = (right_reg != 3'd0);
                    end
                    
                    SRL: begin
                        // Shift right logical (use lower 4 bits for shift amount)
                        alu_result = reg_left_val >> reg_mid_val[3:0];
                        reg_write_data = alu_result;
                        reg_write_addr = right_reg;
                        reg_write_enable = (right_reg != 3'd0);
                    end
                    
                    SRA: begin
                        // Shift right arithmetic (use lower 4 bits for shift amount)
                        alu_result = $signed(reg_left_val) >>> reg_mid_val[3:0];
                        reg_write_data = alu_result;
                        reg_write_addr = right_reg;
                        reg_write_enable = (right_reg != 3'd0);
                    end
                    
                    default: begin
                        // Invalid function code - do nothing
                    end
                endcase
            end
            
            ADDI: begin
                // Add immediate
                alu_result = reg_left_val + imm7_signed;
                reg_write_data = alu_result;
                reg_write_addr = mid_reg;
                reg_write_enable = (mid_reg != 3'd0);
            end
            
            LW: begin
                // Load word from memory
                reg_write_data = ram[mem_addr];
                reg_write_addr = mid_reg;
                reg_write_enable = (mid_reg != 3'd0);
            end
            
            SW: begin
                // Store word to memory
                mem_write_enable = 1'b1;
            end
            
            JEQ: begin
                // Jump if equal (conditional branch with relative offset)
                if (reg_left_val == reg_mid_val) begin
                    pc_next = pc + 16'd1 + imm7_signed;
                end
            end
            
            SLTI: begin
                // Set less than immediate (unsigned)
                alu_result = (reg_left_val < imm7_signed) ? 16'd1 : 16'd0;
                reg_write_data = alu_result;
                reg_write_addr = mid_reg;
                reg_write_enable = (mid_reg != 3'd0);
            end
            
            J: begin
                // Jump to absolute address (13-bit immediate)
                pc_next = {3'b000, imm13};
            end
            
            JAL: begin
                // Jump and link (save return address in $7)
                reg_write_data = pc + 16'd1;
                reg_write_addr = LINK_REG;
                reg_write_enable = 1'b1;
                pc_next = {3'b000, imm13};
            end
            
            default: begin
                // Invalid opcode - do nothing
            end
        endcase
    end

    // =============================================================================
    // Halt Detection
    // =============================================================================
    
    // Processor halts when PC doesn't change (tight loop)
    assign halt = halted;

    // =============================================================================
    // Sequential Logic
    // =============================================================================
    
    integer i;
    
    always @(posedge clock or posedge reset) begin
        if (reset) begin
            // Initialize all registers to zero
            for (i = 0; i < NUM_REGS; i = i + 1) begin
                regs[i] <= 16'd0;
            end
            
            // Initialize PC to zero
            pc <= 16'd0;
            prev_pc <= 16'd0;
            halted <= 1'b0;
            cycle_count <= 32'd0;
        end else begin
            if (!halted) begin
                // Update previous PC for halt detection
                prev_pc <= pc;
                
                // Update PC
                pc <= pc_next;
                
                // Write to register file (except register 0)
                if (reg_write_enable && reg_write_addr != 3'd0) begin
                    regs[reg_write_addr] <= reg_write_data;
                end
                
                // Write to memory
                if (mem_write_enable) begin
                    ram[mem_addr] <= reg_mid_val;
                end
                
                // Check for halt condition
                if (pc_next == pc) begin
                    halted <= 1'b1;
                    $display("[E20] Processor halted at PC=0x%04h after %0d cycles", pc, cycle_count);
                end
                
                // Increment cycle counter
                cycle_count <= cycle_count + 1;
            end
        end
    end

endmodule
