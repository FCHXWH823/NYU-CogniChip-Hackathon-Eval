// PUF Module for Device ID
// Generates 128-bit immutable device identifier
// BUS-ACCESSIBLE - Can be read through system bus
// Simpler than DUS PUF, focuses on stable unique ID

module puf_device_id (
    input  logic        clock,
    input  logic        reset,
    
    // Control interface
    input  logic        enroll,         // One-time enrollment
    input  logic        read_id,        // Read device ID
    output logic        ready,          // Ready for operation
    output logic        valid,          // ID output valid
    output logic        enrolled_flag,  // Device has been enrolled
    
    // Device ID output (Bus-accessible)
    output logic [127:0] device_id      // Unique Device Identifier
);

    // State machine
    typedef enum logic [1:0] {
        IDLE,
        ENROLLING,
        READING,
        DONE
    } state_t;
    
    state_t state, next_state;
    
    // Device ID storage (set once during enrollment)
    logic [127:0] device_id_reg;
    logic enrolled;
    
    // PUF measurement
    logic [127:0] puf_measurement;
    logic [7:0] measure_count;
    
    // Device-specific characteristics
    // In real hardware, derived from SRAM startup, RO frequencies, etc.
    // Each chip would have different values due to process variations
    localparam logic [127:0] DEVICE_CHARACTERISTICS = {
        32'hABCD1234, 32'h5678EFAB, 32'hDEADC0DE, 32'hBEEFF00D
    };
    
    // Additional entropy source (simulates layout-dependent variations)
    localparam logic [127:0] LAYOUT_ENTROPY = {
        32'h13579BDF, 32'h2468ACE0, 32'hFEDCBA98, 32'h76543210
    };
    
    // Noise LFSR for measurement variations
    logic [31:0] lfsr;
    
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            lfsr <= 32'h12345678;
        end else begin
            lfsr <= {lfsr[30:0], lfsr[31] ^ lfsr[21] ^ lfsr[1] ^ lfsr[0]};
        end
    end
    
    // State machine
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end
    
    always_comb begin
        next_state = state;
        
        case (state)
            IDLE: begin
                if (enroll && !enrolled) begin
                    next_state = ENROLLING;
                end else if (read_id && enrolled) begin
                    next_state = READING;
                end
            end
            
            ENROLLING: begin
                if (measure_count >= 8'd32) begin
                    next_state = DONE;
                end
            end
            
            READING: begin
                next_state = DONE;
            end
            
            DONE: begin
                next_state = IDLE;
            end
        endcase
    end
    
    // Measurement counter
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            measure_count <= 8'd0;
        end else begin
            if (state == ENROLLING) begin
                measure_count <= measure_count + 8'd1;
            end else begin
                measure_count <= 8'd0;
            end
        end
    end
    
    // PUF measurement (simulates multiple samples for stability)
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            puf_measurement <= 128'h0;
        end else begin
            if (state == ENROLLING) begin
                // Accumulate multiple measurements for stability
                // Simulate majority voting across multiple reads
                logic [127:0] current_sample;
                
                // Generate sample based on device characteristics + minimal noise
                current_sample = DEVICE_CHARACTERISTICS ^ 
                                (LAYOUT_ENTROPY & {4{lfsr}}) ^
                                ({96'h0, lfsr} >> measure_count[4:0]);
                
                // Simple averaging/majority logic
                if (measure_count == 8'd0) begin
                    puf_measurement <= current_sample;
                end else begin
                    // Bit-wise majority voting
                    for (int i = 0; i < 128; i++) begin
                        if (current_sample[i] == puf_measurement[i]) begin
                            puf_measurement[i] <= current_sample[i];
                        end
                    end
                end
            end
        end
    end
    
    // Enrollment and ID storage (immutable after first enrollment)
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            device_id_reg <= 128'h0;
            enrolled <= 1'b0;
        end else begin
            if (state == ENROLLING && measure_count >= 8'd31 && !enrolled) begin
                // Finalize device ID with post-processing
                // Apply mixing function for better distribution
                logic [127:0] mixed_id;
                
                mixed_id[127:96] = puf_measurement[127:96] ^ puf_measurement[63:32];
                mixed_id[95:64]  = puf_measurement[95:64] ^ puf_measurement[31:0];
                mixed_id[63:32]  = puf_measurement[63:32] ^ puf_measurement[127:96];
                mixed_id[31:0]   = puf_measurement[31:0] ^ puf_measurement[95:64];
                
                device_id_reg <= mixed_id;
                enrolled <= 1'b1;
            end
        end
    end
    
    // Output logic
    always_comb begin
        ready = (state == IDLE);
        valid = (state == DONE);
        enrolled_flag = enrolled;
        device_id = device_id_reg;
    end

endmodule
