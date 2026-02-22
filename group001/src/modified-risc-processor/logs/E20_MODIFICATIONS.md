# E20 Processor Modifications Guide

This document outlines modifications for two different use cases:
1. **Educational Version**: Simple, clear, easy to understand for learning
2. **FPGA Synthesis Version**: Optimized for real hardware implementation

---

## Scenario 1: Educational/Simulation Version (Current + Enhancements)

### Goal
Keep the design simple and readable for learning computer architecture concepts, with good simulation support.

### Modifications

#### 1.1 Add Memory Initialization for Testbenches

```verilog
// Add after memory declaration
reg [15:0] ram [0:MEM_SIZE-1];

// Add initial block for testbench support
initial begin
    integer i;
    // Initialize all memory to zero
    for (i = 0; i < MEM_SIZE; i = i + 1) begin
        ram[i] = 16'h0000;
    end
    
    // Optional: Load program from file
    // $readmemb("program.bin", ram);  // Binary format
    // $readmemh("program.hex", ram);  // Hex format
end
```

#### 1.2 Add Debug/Monitoring Signals

```verilog
// Add to module ports for better debugging
module processor (
    input  wire clock,
    input  wire reset,
    output wire halt,
    
    // Debug outputs (for testbench monitoring)
    output wire [15:0] debug_pc,
    output wire [15:0] debug_instr,
    output wire [15:0] debug_reg_val
);

// Assign debug signals
assign debug_pc = pc;
assign debug_instr = curr_instr;
assign debug_reg_val = regs[1];  // Monitor $1, or make parameterizable
```

#### 1.3 Add Additional Instructions (Use Unused Func Codes)

```verilog
// Add to function code definitions
localparam [3:0] XOR  = 4'b0101;  // Bitwise XOR
localparam [3:0] NOR  = 4'b0110;  // Bitwise NOR  
localparam [3:0] SLL  = 4'b1001;  // Shift left logical
localparam [3:0] SRL  = 4'b1010;  // Shift right logical
localparam [3:0] SRA  = 4'b1011;  // Shift right arithmetic

// Add to THREE_REG case statement
XOR: begin
    alu_result = reg_left_val ^ reg_mid_val;
    reg_write_data = alu_result;
    reg_write_addr = right_reg;
    reg_write_enable = (right_reg != 3'd0);
end

NOR: begin
    alu_result = ~(reg_left_val | reg_mid_val);
    reg_write_data = alu_result;
    reg_write_addr = right_reg;
    reg_write_enable = (right_reg != 3'd0);
end

SLL: begin
    alu_result = reg_left_val << reg_mid_val[3:0];  // Use lower 4 bits for shift amount
    reg_write_data = alu_result;
    reg_write_addr = right_reg;
    reg_write_enable = (right_reg != 3'd0);
end

SRL: begin
    alu_result = reg_left_val >> reg_mid_val[3:0];
    reg_write_data = alu_result;
    reg_write_addr = right_reg;
    reg_write_enable = (right_reg != 3'd0);
end

SRA: begin
    alu_result = $signed(reg_left_val) >>> reg_mid_val[3:0];  // Arithmetic shift
    reg_write_data = alu_result;
    reg_write_addr = right_reg;
    reg_write_enable = (right_reg != 3'd0);
end
```

#### 1.4 Add Register File Display Task (for debugging)

```verilog
// Add at end of module (before endmodule)
// Debug task to display register file state
task display_registers;
    integer i;
    begin
        $display("=== Register File ===");
        for (i = 0; i < NUM_REGS; i = i + 1) begin
            $display("$%0d = 0x%04h (%0d)", i, regs[i], regs[i]);
        end
        $display("PC  = 0x%04h (%0d)", pc, pc);
        $display("==================");
    end
endtask
```

#### 1.5 Enhanced Halt Detection with Status

```verilog
// Add after halt signal declaration
reg [7:0] halt_reason;
localparam HALT_LOOP = 8'd1;
localparam HALT_ERROR = 8'd2;

// Modify halt detection
if (pc_next == pc) begin
    halted <= 1'b1;
    halt_reason <= HALT_LOOP;
    $display("Processor halted at PC=0x%04h (tight loop)", pc);
end
```

### Educational Version Summary
- ✅ Keeps single-cycle simplicity
- ✅ Easy to understand and trace
- ✅ Good for simulation and learning
- ✅ Adds useful debug features
- ❌ Not optimized for real hardware

---

## Scenario 2: FPGA Synthesis Version

### Goal
Create a synthesizable, efficient design suitable for FPGA implementation with proper memory handling.

### Major Modifications

#### 2.1 Harvard Architecture (Separate Instruction & Data Memory)

```verilog
module processor (
    input  wire clock,
    input  wire reset,
    output wire halt,
    
    // Instruction Memory Interface (ROM-like)
    output wire [12:0] imem_addr,
    input  wire [15:0] imem_data,
    
    // Data Memory Interface (RAM)
    output wire [12:0] dmem_addr,
    output wire [15:0] dmem_wdata,
    input  wire [15:0] dmem_rdata,
    output wire        dmem_wen
);

// Remove internal RAM declaration
// reg [15:0] ram [0:MEM_SIZE-1];  // DELETE THIS

// Memory interface signals
assign imem_addr = pc[12:0];
assign dmem_addr = mem_addr;
assign dmem_wdata = reg_mid_val;
assign dmem_wen = mem_write_enable && !halted;

// Use external memory for instruction fetch
assign curr_instr = imem_data;

// Use external memory for loads
// Modify LW instruction:
LW: begin
    reg_write_data = dmem_rdata;  // Use external memory read data
    reg_write_addr = mid_reg;
    reg_write_enable = (mid_reg != 3'd0);
end
```

#### 2.2 Add Pipeline Registers for Memory Access (Optional)

For better timing, add a pipeline stage:

```verilog
// Two-cycle design: Fetch+Decode+Execute, then Memory+Writeback

// Add pipeline registers
reg [15:0] mem_data_reg;
reg [2:0]  mem_write_reg;
reg        mem_write_enable_reg;
reg        is_load_reg;

// State machine
reg state;
localparam STATE_EXEC = 1'b0;
localparam STATE_MEM  = 1'b1;

always @(posedge clock or posedge reset) begin
    if (reset) begin
        state <= STATE_EXEC;
        // ... other resets
    end else begin
        case (state)
            STATE_EXEC: begin
                // Execute instruction
                if (opcode == LW || opcode == SW) begin
                    state <= STATE_MEM;  // Need memory cycle
                    // Save control signals
                end else begin
                    // Complete in one cycle
                end
            end
            
            STATE_MEM: begin
                // Memory access complete
                if (is_load_reg) begin
                    regs[mem_write_reg] <= dmem_rdata;
                end
                state <= STATE_EXEC;
                pc <= pc_next;
            end
        endcase
    end
end
```

#### 2.3 Synchronous Memory Wrappers

Create wrapper modules for FPGA Block RAMs:

```verilog
// Instruction Memory (Read-Only)
module instruction_memory (
    input  wire        clock,
    input  wire [12:0] addr,
    output reg  [15:0] data
);
    reg [15:0] mem [0:8191];
    
    initial begin
        $readmemh("program.hex", mem);
    end
    
    always @(posedge clock) begin
        data <= mem[addr];
    end
endmodule

// Data Memory (Read/Write)
module data_memory (
    input  wire        clock,
    input  wire [12:0] addr,
    input  wire [15:0] wdata,
    input  wire        wen,
    output reg  [15:0] rdata
);
    reg [15:0] mem [0:8191];
    
    always @(posedge clock) begin
        if (wen) begin
            mem[addr] <= wdata;
        end
        rdata <= mem[addr];
    end
endmodule
```

#### 2.4 Reset Synchronization

```verilog
// Add reset synchronizer for better FPGA practices
reg [1:0] reset_sync;

always @(posedge clock or posedge reset) begin
    if (reset) begin
        reset_sync <= 2'b11;
    end else begin
        reset_sync <= {reset_sync[0], 1'b0};
    end
end

wire reset_sync_out = reset_sync[1];

// Use reset_sync_out instead of reset in sequential logic
```

#### 2.5 Parameterized Memory Size

```verilog
module processor #(
    parameter IMEM_ADDR_WIDTH = 13,  // 8K instruction memory
    parameter DMEM_ADDR_WIDTH = 13,  // 8K data memory
    parameter DMEM_SIZE_SMALL = 0    // 1=Use smaller data memory for resource optimization
) (
    // ... ports
);

localparam DMEM_SIZE = DMEM_SIZE_SMALL ? 1024 : (1 << DMEM_ADDR_WIDTH);
```

#### 2.6 Optional: Use Xilinx/Intel Primitives

For best resource usage, instantiate vendor-specific blocks:

```verilog
// Example: Xilinx Block RAM instantiation
RAMB36E1 #(
    .DOA_REG(1),
    .DOB_REG(1),
    .READ_WIDTH_A(18),
    .READ_WIDTH_B(18),
    .WRITE_WIDTH_A(18),
    .WRITE_WIDTH_B(18),
    .WRITE_MODE_A("READ_FIRST"),
    .WRITE_MODE_B("READ_FIRST")
) instruction_bram_inst (
    .CLKARDCLK(clock),
    .ADDRARDADDR(imem_addr),
    .DOADO(imem_data),
    // ... other signals
);
```

#### 2.7 Add Synthesis Attributes

```verilog
// Register file with proper attributes
(* ram_style = "distributed" *) reg [15:0] regs [0:NUM_REGS-1];  // Use LUTs, not BRAMs

// Or for larger register files
(* ram_style = "block" *) reg [15:0] regs [0:NUM_REGS-1];  // Use BRAMs

// Prevent optimization of specific logic
(* keep = "true" *) wire [15:0] curr_instr;

// FSM encoding
(* fsm_encoding = "one_hot" *) reg [2:0] state;
```

### FPGA Synthesis Version Summary
- ✅ Synthesizes efficiently to FPGA
- ✅ Proper memory handling with BRAMs
- ✅ Better timing closure
- ✅ Resource optimization
- ✅ Vendor tool compatibility
- ❌ More complex to understand
- ❌ Harder to debug in simulation

---

## Comparison Table

| Feature | Educational Version | FPGA Synthesis Version |
|---------|-------------------|----------------------|
| **Memory** | Single unified array | Separate instruction/data memories |
| **Memory Type** | Combinational read | Synchronous BRAM interfaces |
| **Cycles per Instruction** | 1 (idealized) | 1-2 (realistic) |
| **Debug Features** | Extensive (display tasks) | Minimal (area optimization) |
| **Resource Usage** | N/A (simulation) | Optimized for LUTs/BRAMs |
| **Timing Closure** | N/A | Designed for high Fmax |
| **Simulation Speed** | Fast | Slower (more realistic) |
| **Learning Value** | High | Medium |
| **Production Ready** | No | Yes |

---

## Instruction Set Extensions

Both versions can support these additional instructions by using available func codes:

### Available THREE_REG Function Codes (4 bits)
```
Currently used: 0000, 0001, 0010, 0011, 0100, 1000
Available:      0101, 0110, 0111, 1001, 1010, 1011, 1100, 1101, 1110, 1111
```

### Recommended Additions

| Func Code | Mnemonic | Operation | Notes |
|-----------|----------|-----------|-------|
| 0101 | XOR | `rd = rs ^ rt` | Bitwise XOR |
| 0110 | NOR | `rd = ~(rs \| rt)` | Bitwise NOR |
| 0111 | NAND | `rd = ~(rs & rt)` | Bitwise NAND |
| 1001 | SLL | `rd = rs << rt[3:0]` | Shift left logical |
| 1010 | SRL | `rd = rs >> rt[3:0]` | Shift right logical |
| 1011 | SRA | `rd = rs >>> rt[3:0]` | Shift right arithmetic |
| 1100 | MUL | `rd = rs * rt` | Multiply (lower 16 bits) |
| 1101 | MULH | `rd = (rs * rt) >> 16` | Multiply (upper 16 bits) |
| 1110 | SLTS | `rd = ($signed(rs) < $signed(rt))` | Signed comparison |
| 1111 | NOP | No operation | Or reserve for future use |

---

## Resource Estimates (Example: Xilinx Artix-7)

### Educational Version (if synthesized as-is)
- **LUTs**: ~1,500-2,000
- **FFs**: ~300-400
- **BRAMs**: 64+ (inefficient - uses all available memory for unified 8K x 16)
- **Max Frequency**: ~50-80 MHz (long combinational paths)

### FPGA Synthesis Version (optimized)
- **LUTs**: ~800-1,200
- **FFs**: ~400-600
- **BRAMs**: 4-8 (separate I-mem and D-mem, more efficient usage)
- **Max Frequency**: ~100-150 MHz (pipelined memory access)

---

## Recommendations

### For Learning/Class Projects
→ Use **Educational Version** with modifications 1.1-1.5
- Easy to understand and debug
- Great for learning CPU design concepts
- Works perfectly in simulation
- Can run your C++ simulator alongside for verification

### For FPGA Implementation (Hackathon/Demo)
→ Use **FPGA Synthesis Version** with modifications 2.1-2.7
- Will actually fit and run on real hardware
- Better resource utilization
- Meets timing requirements
- Can interface with external peripherals

### Hybrid Approach (Recommended for your situation)
1. Keep current design for learning/simulation
2. Create a separate `processor_fpga.v` with synthesis optimizations
3. Share common testbenches between both versions
4. Use the educational version to understand behavior
5. Use the FPGA version for actual hardware implementation

---

## Next Steps

Would you like me to:
1. **Implement the educational enhancements** (add debug features, more instructions)
2. **Create the FPGA synthesis version** (separate file with all optimizations)
3. **Create a testbench** that works with both versions
4. **Generate example programs** in E20 assembly to test the processor

Let me know which direction you'd like to pursue!
