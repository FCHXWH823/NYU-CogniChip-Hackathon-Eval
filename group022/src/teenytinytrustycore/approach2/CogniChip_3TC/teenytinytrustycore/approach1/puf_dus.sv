// PUF Module for Device Unique Secret (DUS)
// Generates 256-bit cryptographic secret based on manufacturing variations
// ISOLATED MODULE - No bus access, output only to KDF
// Implements Ring Oscillator PUF with error correction

module puf_dus (
    input  logic        clock,
    input  logic        reset,
    
    // Control interface
    input  logic        enroll,         // Enrollment mode (characterize PUF)
    input  logic        regenerate,     // Regenerate secret from PUF
    output logic        ready,          // Ready for operation
    output logic        valid,          // Secret output valid
    output logic        error,          // Error in regeneration
    
    // Helper data interface (for error correction)
    output logic [255:0] helper_data,   // Helper data from enrollment
    input  logic [255:0] helper_data_in, // Helper data for regeneration
    output logic         helper_valid,  // Helper data valid (enrollment complete)
    
    // Secret output (ISOLATED - only to KDF)
    output logic [255:0] secret_out     // Device Unique Secret
);

    // State machine
    typedef enum logic [2:0] {
        IDLE,
        ENROLL_MEASURE,
        ENROLL_GENERATE,
        REGEN_MEASURE,
        REGEN_CORRECT,
        DONE
    } state_t;
    
    state_t state, next_state;
    
    // PUF raw measurement storage (simulates ring oscillator outputs)
    logic [255:0] puf_raw;
    logic [255:0] puf_enrolled;
    
    // Cycle counter for measurement time
    logic [7:0] measure_cycles;
    logic [7:0] cycle_count;
    
    // Helper data and secret registers
    logic [255:0] helper_data_reg;
    logic [255:0] secret_reg;
    
    // Error detection
    logic [7:0] error_count;
    localparam MAX_ERRORS = 8'd32; // Maximum correctable bit errors (12.5%)
    
    // Simulated PUF source - Ring Oscillator delays
    // In real hardware, this would be physical variations
    // Here we simulate with device-specific constants and noise
    logic [255:0] ro_frequencies;
    logic [31:0] lfsr_noise;
    
    // Device-specific seed (in real HW, this comes from process variations)
    // This would be synthesized differently on each chip
    localparam logic [255:0] DEVICE_SEED = {
        32'hDEADBEEF, 32'hCAFEBABE, 32'hFEEDFACE, 32'hBADDCAFE,
        32'h12345678, 32'h9ABCDEF0, 32'h11111111, 32'h22222222
    };
    
    // LFSR for noise simulation (simulates environmental variations)
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            lfsr_noise <= 32'hACE1FACE;
        end else begin
            // 32-bit LFSR with taps at positions 32, 22, 2, 1
            lfsr_noise <= {lfsr_noise[30:0], 
                          lfsr_noise[31] ^ lfsr_noise[21] ^ lfsr_noise[1] ^ lfsr_noise[0]};
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
                if (enroll) begin
                    next_state = ENROLL_MEASURE;
                end else if (regenerate) begin
                    next_state = REGEN_MEASURE;
                end
            end
            
            ENROLL_MEASURE: begin
                if (cycle_count >= measure_cycles) begin
                    next_state = ENROLL_GENERATE;
                end
            end
            
            ENROLL_GENERATE: begin
                next_state = DONE;
            end
            
            REGEN_MEASURE: begin
                if (cycle_count >= measure_cycles) begin
                    next_state = REGEN_CORRECT;
                end
            end
            
            REGEN_CORRECT: begin
                next_state = DONE;
            end
            
            DONE: begin
                next_state = IDLE;
            end
        endcase
    end
    
    // Cycle counter for measurement
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            cycle_count <= 8'd0;
            measure_cycles <= 8'd64; // 64 cycles to measure
        end else begin
            if (state == ENROLL_MEASURE || state == REGEN_MEASURE) begin
                cycle_count <= cycle_count + 8'd1;
            end else begin
                cycle_count <= 8'd0;
            end
        end
    end
    
    // PUF measurement (simulates ring oscillator frequency comparison)
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            puf_raw <= 256'h0;
        end else begin
            if (state == ENROLL_MEASURE || state == REGEN_MEASURE) begin
                // Simulate PUF measurement with device seed + small noise
                // Each bit represents comparison of two RO frequencies
                for (int i = 0; i < 256; i++) begin
                    // Core PUF response from device characteristics
                    logic core_bit;
                    logic noise_bit;
                    
                    core_bit = DEVICE_SEED[i];
                    
                    // Add small amount of noise (simulates voltage/temp variations)
                    // During enrollment, less noise; during regeneration, more noise
                    noise_bit = lfsr_noise[i % 32] & lfsr_noise[(i+7) % 32];
                    
                    if (state == ENROLL_MEASURE) begin
                        // Cleaner measurement during enrollment
                        puf_raw[i] <= core_bit;
                    end else begin
                        // Add noise during regeneration (realistic behavior)
                        // ~5% bit error rate without correction
                        if ((i + cycle_count) % 20 == 0) begin
                            puf_raw[i] <= core_bit ^ noise_bit;
                        end else begin
                            puf_raw[i] <= core_bit;
                        end
                    end
                end
            end
        end
    end
    
    // Enrollment: Store reference PUF value and generate helper data
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            puf_enrolled <= 256'h0;
            helper_data_reg <= 256'h0;
            secret_reg <= 256'h0;
        end else begin
            if (state == ENROLL_GENERATE) begin
                // Store enrolled PUF value
                puf_enrolled <= puf_raw;
                
                // Generate helper data (simplified error correction)
                // In real implementation, use BCH/Reed-Solomon codes
                // Here we use XOR with a derived key for demonstration
                helper_data_reg <= puf_raw ^ {32{8'hA5}}; // Simple obfuscation
                
                // Generate secret from PUF (apply one-way function)
                // In real system, use strong extraction
                secret_reg <= puf_raw ^ {puf_raw[127:0], puf_raw[255:128]};
            end else if (state == REGEN_CORRECT) begin
                // Regenerate secret using helper data for error correction
                logic [255:0] corrected_puf;
                logic [255:0] syndrome;
                
                // Simple error correction using helper data
                corrected_puf = puf_raw ^ helper_data_in ^ {32{8'hA5}};
                
                // Count bit errors
                syndrome = corrected_puf ^ puf_raw;
                
                // Apply correction if within threshold
                if (error_count <= MAX_ERRORS) begin
                    secret_reg <= corrected_puf ^ {corrected_puf[127:0], corrected_puf[255:128]};
                end
            end
        end
    end
    
    // Error counting
    always_ff @(posedge clock or posedge reset) begin
        if (reset) begin
            error_count <= 8'd0;
        end else begin
            if (state == REGEN_CORRECT) begin
                logic [255:0] syndrome;
                syndrome = (puf_raw ^ helper_data_in ^ {32{8'hA5}}) ^ puf_raw;
                
                // Count number of bit differences
                error_count = 8'd0;
                for (int i = 0; i < 256; i++) begin
                    if (syndrome[i]) error_count = error_count + 8'd1;
                end
            end else begin
                error_count <= 8'd0;
            end
        end
    end
    
    // Output logic
    always_comb begin
        ready = (state == IDLE);
        valid = (state == DONE);
        helper_valid = (state == DONE) && (next_state == IDLE) && (error_count == 8'd0);
        error = (state == DONE) && (error_count > MAX_ERRORS);
        secret_out = secret_reg;
        helper_data = helper_data_reg;
    end

endmodule
