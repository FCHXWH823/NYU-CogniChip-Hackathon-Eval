// =============================================================================
// Ripple Carry Adder
// =============================================================================
// Description:
//   N-bit ripple carry adder that adds two binary numbers by cascading
//   full adder cells. The carry propagates sequentially from LSB to MSB.
//
// Parameters:
//   WIDTH - Bit width of the operands (default: 8)
//
// Ports:
//   a[WIDTH-1:0]    - First operand input
//   b[WIDTH-1:0]    - Second operand input
//   carry_in        - Carry input (for cascading)
//   sum[WIDTH-1:0]  - Sum output
//   carry_out       - Carry output (overflow indicator)
//
// Operation:
//   {carry_out, sum} = a + b + carry_in
//
// =============================================================================

module ripple_carry_adder #(
    parameter WIDTH = 8
) (
    input  logic [WIDTH-1:0] a,
    input  logic [WIDTH-1:0] b,
    input  logic             carry_in,
    output logic [WIDTH-1:0] sum,
    output logic             carry_out
);

    // Internal carry chain connecting each full adder stage
    logic [WIDTH:0] carry;

    // Connect the input carry to the LSB carry chain
    assign carry[0] = carry_in;

    // Generate full adders for each bit position
    genvar i;
    generate
        for (i = 0; i < WIDTH; i = i + 1) begin : full_adder_stage
            // Full adder logic for bit position i
            // Sum: XOR of all three inputs
            // Carry: at least two of the three inputs are 1
            assign sum[i] = a[i] ^ b[i] ^ carry[i];
            assign carry[i+1] = (a[i] & b[i]) | (b[i] & carry[i]) | (a[i] & carry[i]);
        end
    endgenerate

    // Connect the MSB carry to the output
    assign carry_out = carry[WIDTH];

endmodule
