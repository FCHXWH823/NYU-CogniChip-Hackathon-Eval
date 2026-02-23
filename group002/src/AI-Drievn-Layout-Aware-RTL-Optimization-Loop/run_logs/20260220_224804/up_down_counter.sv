// =============================================================================
// Up-Down Counter (FIXED VERSION)
// =============================================================================
// Counts UP from 0-7 or DOWN from 7-0 based on direction input
// =============================================================================

module up_down_counter (
    input  logic       clock,
    input  logic       reset,
    input  logic       enable,
    input  logic       direction, // 1 = up, 0 = down
    output logic [2:0] count,
    output logic       at_max,    // high when count == 7
    output logic       at_min     // high when count == 0
);

    always_ff @(posedge clock) begin
        if (reset) begin
            count <= 3'd0;
        end else if (enable) begin
            if (direction) begin
                // Count UP
                if (count == 3'd7)
                    count <= 3'd0;
                else
                    count <= count + 3'd1;
            end else begin
                // Count DOWN
                if (count == 3'd0)
                    count <= 3'd7;
                else
                    count <= count - 3'd1;
            end
        end
    end

    assign at_max = (count == 3'd7);
    assign at_min = (count == 3'd0);

endmodule