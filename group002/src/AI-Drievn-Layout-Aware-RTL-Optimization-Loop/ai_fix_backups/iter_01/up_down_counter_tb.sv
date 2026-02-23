// =============================================================================
// Testbench for Up-Down Counter
// =============================================================================

module tb_up_down_counter;

    logic       clock;
    logic       reset;
    logic       enable;
    logic       direction;
    logic [2:0] count;
    logic       at_max;
    logic       at_min;
    int         error_count;

    // Clock: 100ns period
    initial begin
        clock = 0;
        forever #50 clock = ~clock;
    end

    // DUT
    up_down_counter dut (le   (enable),
        .direction(direction),
        .count    (count),
        .at_max   (at_max),
        .at_min   (at_min)
    );

    // Check task
    task check(
        input logic [2:0] exp_count,
        input logic       exp_max,
        input logic       exp_min

        if (count !== exp_count) begin
            $display("LOG: %0t : ERROR : count : expected 3'd%0d actual 3'd%0d",
                     $time, exp_count, count);
            error_count++;
        end
        if (at_max !== exp_max) begin
            $display("LOG: %0t : ERROR : at_max : expected %0b actual %0b",
                     $time, exp_max, at_max);
            error_count++;
        end
        if (at_min !== exp_min) begin
            $display("LOG: %0t : ERROR : at_min : expected %0b actual %0b",
                     $time, exp_min, at_min);
            error_count++;
        end
    endtask

    initial begin
        $display("TEST START");
        error_count = 0;
        reset     = 1;
        enable    = 0;
        direction = 1;

        // ── Test 1: Reset ─────────────────────────────────────────────────
        @(posedge clock); #1;
        reset = 0;
        @(posedge clock); #1;
        check(3'd0, 1'b0, 1'b1);   // expect count=0, at_min=1
        $display("LOG: Test 1 - Reset check");

        // ── Test 2: Count UP 0→7 ─────────────────────────────────────────
        enable = 1;
        direction = 1;
        for (int i = 0; i < 7; i++) begin
            @(posedge clock); #1;
        end
        check(3'd7, 1'b1, 1'b0);   // should be at max
        $display("LOG: Test 2 - Count UP reached 7");
; #1;
        check(3'd0, 1'b0, 1'b1);   // wraps to 0
        $display("LOG: Test 3 - UP wrap 7→0");

        // ── Test 4: Count DOWN 0→7 wrap ───────────────────────────────────
        direction = 0;
        @(posedge clock); #1;
        check(3'd7, 1'b1, 1'b0);   // wraps to 7
        $display("LOG: Test 4 - DOWN wrap 0→7");

        // ── Test 5: Count DOWN 7→0 ────────────────────────────────────────
        for (int i = 0; i < 7; i++) begin
            @(posedge clock); #1;
        end
        check(3'd0, 1'b0, 1'b1);
        $display("LOG: Test 5 - Count DOWN reached 0");

        // ── Test 6: Enable = 0 holds value ───────────────────────────────
        enable = 0;
        repeat(3) begin
            @(posedge clock); #1;
            check(3'd0, 1'b0, 1'b1);
        end
        $display("LOG: Test 6 - Enable=0 holds");

        // ── Test 7: Reset mid-count ───────────────────────────────────────
        enable    = 1;
        direction = 1;
        repeat(3) @(posedge clock);
        reset = 1;
        @(posedge clock); #1;
        check(3'd0, 1'b0, 1'b1);
        reset = 0;
        $display("LOG: Test 7 - Reset mid-count");

        // ── Final ─────────────────────────────────────────────────────────
        #100;
        if (error_count == 0)
            $display("TEST PASSED");
        else begin
            $display("ERROR");
            $error("TEST FAILED - %0d errors", error_count);
        end
        $finish;
    end

    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(0, tb_up_down_counter);
    end

endmodule