// =============================================================================
// Module: dram_prefetch_engine
// Description: DRAM prefetch engine with atomic tile fetch (A+B)
//              Proper DRAM<->SRAM width conversion (128b DRAM ↔ 32b SRAM)
//              Handles partial beat zero-padding for writes
// =============================================================================

module dram_prefetch_engine #(
    parameter int DRAM_ADDR_WIDTH  = 32,
    parameter int DRAM_DATA_WIDTH  = 128,
    parameter int SRAM_ADDR_WIDTH  = 16,
    parameter int SRAM_DATA_WIDTH  = 32,
    parameter int DATA_WIDTH_A     = 8,
    parameter int DATA_WIDTH_B     = 8,
    parameter int DATA_WIDTH_C     = 32,
    parameter int PREFETCH_DEPTH   = 4
) (
    input  logic        clk,
    input  logic        rst_n,
    
    // Scheduler Interface
    input  logic        fetch_req_valid,
    output logic        fetch_req_ready,
    input  logic        fetch_req_is_write,
    input  logic [31:0] fetch_req_dram_addr_a,
    input  logic [31:0] fetch_req_dram_addr_b,
    input  logic [31:0] fetch_req_dram_addr_c,
    input  logic [SRAM_ADDR_WIDTH-1:0] fetch_req_sram_addr_a,
    input  logic [SRAM_ADDR_WIDTH-1:0] fetch_req_sram_addr_b,
    input  logic [SRAM_ADDR_WIDTH-1:0] fetch_req_sram_addr_c,
    input  logic [15:0] fetch_req_num_elements_a,
    input  logic [15:0] fetch_req_num_elements_b,
    input  logic [15:0] fetch_req_num_elements_c,
    output logic        fetch_done,
    
    // DRAM Interface - Request
    output logic                        dram_req_valid,
    input  logic                        dram_req_ready,
    output logic                        dram_req_is_write,
    output logic [DRAM_ADDR_WIDTH-1:0]  dram_req_addr,
    output logic [15:0]                 dram_req_bytes,
    
    // DRAM Interface - Read Response
    input  logic                        dram_rvalid,
    output logic                        dram_rready,
    input  logic [DRAM_DATA_WIDTH-1:0]  dram_rdata,
    input  logic                        dram_rlast,
    
    // DRAM Interface - Write Data
    output logic                        dram_wvalid,
    input  logic                        dram_wready,
    output logic [DRAM_DATA_WIDTH-1:0]  dram_wdata,
    output logic                        dram_wlast,
    
    // DRAM Interface - Write Response
    input  logic                        dram_bvalid,
    output logic                        dram_bready,
    
    // SRAM Arbiter Interface
    output logic                        sram_req_valid,
    input  logic                        sram_req_ready,
    output logic                        sram_req_wen,
    output logic [SRAM_ADDR_WIDTH-1:0]  sram_req_addr,
    output logic [SRAM_DATA_WIDTH-1:0]  sram_req_wdata,
    input  logic [SRAM_DATA_WIDTH-1:0]  sram_req_rdata,
    input  logic                        sram_req_rdata_valid
);

    // =========================================================================
    // Local Parameters
    // =========================================================================
    
    localparam int DRAM_DATA_WIDTH_BYTES = DRAM_DATA_WIDTH / 8;
    localparam int SRAM_DATA_WIDTH_BYTES = SRAM_DATA_WIDTH / 8;
    localparam int WORDS_PER_BEAT = DRAM_DATA_WIDTH / SRAM_DATA_WIDTH; // 128/32 = 4
    localparam int ELEM_SIZE_A = DATA_WIDTH_A / 8;
    localparam int ELEM_SIZE_B = DATA_WIDTH_B / 8;
    localparam int ELEM_SIZE_C = DATA_WIDTH_C / 8;
    
    // FSM States
    typedef enum logic [3:0] {
        REQ_IDLE           = 4'b0000,
        REQ_ISSUE_A        = 4'b0001,
        FETCH_A            = 4'b0010,
        REQ_ISSUE_B        = 4'b0011,
        FETCH_B            = 4'b0100,
        FETCH_DONE_SIGNAL  = 4'b0101,
        REQ_ISSUE_C        = 4'b0110,
        WRITEBACK_C_READ   = 4'b0111,
        WRITEBACK_C_WRITE  = 4'b1000,
        WB_WAIT_ACK        = 4'b1001
    } state_t;
    
    state_t state, state_next;
    
    // =========================================================================
    // Request Queue - Using separate arrays for Yosys compatibility
    // =========================================================================
    
    // Separate arrays for each field (Yosys-compatible)
    logic        req_queue_is_write [0:PREFETCH_DEPTH-1];
    logic [31:0] req_queue_dram_addr_a [0:PREFETCH_DEPTH-1];
    logic [31:0] req_queue_dram_addr_b [0:PREFETCH_DEPTH-1];
    logic [31:0] req_queue_dram_addr_c [0:PREFETCH_DEPTH-1];
    logic [SRAM_ADDR_WIDTH-1:0] req_queue_sram_addr_a [0:PREFETCH_DEPTH-1];
    logic [SRAM_ADDR_WIDTH-1:0] req_queue_sram_addr_b [0:PREFETCH_DEPTH-1];
    logic [SRAM_ADDR_WIDTH-1:0] req_queue_sram_addr_c [0:PREFETCH_DEPTH-1];
    logic [15:0] req_queue_num_elements_a [0:PREFETCH_DEPTH-1];
    logic [15:0] req_queue_num_elements_b [0:PREFETCH_DEPTH-1];
    logic [15:0] req_queue_num_elements_c [0:PREFETCH_DEPTH-1];
    logic [$clog2(PREFETCH_DEPTH):0] queue_count;
    logic [$clog2(PREFETCH_DEPTH)-1:0] queue_wr_ptr, queue_rd_ptr;
    
    logic queue_full, queue_empty, queue_push, queue_pop;
    
    assign queue_full  = (queue_count == PREFETCH_DEPTH);
    assign queue_empty = (queue_count == 0);
    assign fetch_req_ready = !queue_full;
    assign queue_push = fetch_req_valid && !queue_full;    
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            queue_count  <= '0;
            queue_wr_ptr <= '0;
            queue_rd_ptr <= '0;
        end else begin
            // Update count
            if (queue_push && !queue_pop) begin
                queue_count <= queue_count + 1;
            end else if (!queue_push && queue_pop) begin
                queue_count <= queue_count - 1;
            end
            // Note: if both push and pop, count stays same
            
            // Update pointers
            if (queue_push) queue_wr_ptr <= queue_wr_ptr + 1;
            if (queue_pop)  queue_rd_ptr <= queue_rd_ptr + 1;
        end
    end
    
    always_ff @(posedge clk) begin
        if (queue_push) begin
            // Write to separate arrays for Yosys compatibility
            req_queue_is_write[queue_wr_ptr]       <= fetch_req_is_write;
            req_queue_dram_addr_a[queue_wr_ptr]    <= fetch_req_dram_addr_a;
            req_queue_dram_addr_b[queue_wr_ptr]    <= fetch_req_dram_addr_b;
            req_queue_dram_addr_c[queue_wr_ptr]    <= fetch_req_dram_addr_c;
            req_queue_sram_addr_a[queue_wr_ptr]    <= fetch_req_sram_addr_a;
            req_queue_sram_addr_b[queue_wr_ptr]    <= fetch_req_sram_addr_b;
            req_queue_sram_addr_c[queue_wr_ptr]    <= fetch_req_sram_addr_c;
            req_queue_num_elements_a[queue_wr_ptr] <= fetch_req_num_elements_a;
            req_queue_num_elements_b[queue_wr_ptr] <= fetch_req_num_elements_b;
            req_queue_num_elements_c[queue_wr_ptr] <= fetch_req_num_elements_c;
        end
    end
    
    // Current request fields read from separate arrays
    logic        current_req_is_write;
    logic [31:0] current_req_dram_addr_a;
    logic [31:0] current_req_dram_addr_b;
    logic [31:0] current_req_dram_addr_c;
    logic [SRAM_ADDR_WIDTH-1:0] current_req_sram_addr_a;
    logic [SRAM_ADDR_WIDTH-1:0] current_req_sram_addr_b;
    logic [SRAM_ADDR_WIDTH-1:0] current_req_sram_addr_c;
    logic [15:0] current_req_num_elements_a;
    logic [15:0] current_req_num_elements_b;
    logic [15:0] current_req_num_elements_c;
    
    assign current_req_is_write       = req_queue_is_write[queue_rd_ptr];
    assign current_req_dram_addr_a    = req_queue_dram_addr_a[queue_rd_ptr];
    assign current_req_dram_addr_b    = req_queue_dram_addr_b[queue_rd_ptr];
    assign current_req_dram_addr_c    = req_queue_dram_addr_c[queue_rd_ptr];
    assign current_req_sram_addr_a    = req_queue_sram_addr_a[queue_rd_ptr];
    assign current_req_sram_addr_b    = req_queue_sram_addr_b[queue_rd_ptr];
    assign current_req_sram_addr_c    = req_queue_sram_addr_c[queue_rd_ptr];
    assign current_req_num_elements_a = req_queue_num_elements_a[queue_rd_ptr];
    assign current_req_num_elements_b = req_queue_num_elements_b[queue_rd_ptr];
    assign current_req_num_elements_c = req_queue_num_elements_c[queue_rd_ptr];
    
    // =========================================================================
    // Byte/Beat Calculation
    // =========================================================================
    
    logic [15:0] bytes_a, bytes_b, bytes_c;
    logic [15:0] beats_a, beats_b, beats_c;
    logic [15:0] words_a, words_b, words_c;
    
    always_comb begin
        // TB treats num_elements_* as number of 32-bit SRAM words
        bytes_a = current_req_num_elements_a * SRAM_DATA_WIDTH_BYTES; // 16 -> 64B
        bytes_b = current_req_num_elements_b * SRAM_DATA_WIDTH_BYTES; // 16 -> 64B
        bytes_c = current_req_num_elements_c * SRAM_DATA_WIDTH_BYTES;

        words_a = current_req_num_elements_a;
        words_b = current_req_num_elements_b;
        words_c = current_req_num_elements_c;

        // beats from bytes (16B per 128b beat)
        beats_a = (bytes_a + DRAM_DATA_WIDTH_BYTES - 1) / DRAM_DATA_WIDTH_BYTES;
        beats_b = (bytes_b + DRAM_DATA_WIDTH_BYTES - 1) / DRAM_DATA_WIDTH_BYTES;
        beats_c = (bytes_c + DRAM_DATA_WIDTH_BYTES - 1) / DRAM_DATA_WIDTH_BYTES;
    end
    
    // =========================================================================
    // Transfer Counters and Beat Buffer
    // =========================================================================
    
    logic [15:0] dram_beat_count;
    logic [15:0] sram_word_count;
    logic [15:0] target_beats;
    logic [15:0] target_words;
    logic [15:0] current_bytes;
    
    // Buffer for current DRAM beat during read (for downsizing)
    logic [DRAM_DATA_WIDTH-1:0] dram_beat_buffer;
    logic [1:0] subword_count;  // Track which 32b word within 128b beat (0-3)
    logic beat_buf_valid;       // Flag: beat buffer contains valid data for SRAM write
    
    // Buffer for accumulating DRAM write beat (for upsizing)
    logic [DRAM_DATA_WIDTH-1:0] dram_write_buffer;
    logic [15:0] words_packed_in_beat;  // Words packed into current beat (0-4)
    logic [15:0] words_packed_total;    // Total words packed across all beats
    
    // =========================================================================
    // FSM State Register
    // =========================================================================
    
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) state <= REQ_IDLE;
        else state <= state_next;
    end
    
    // =========================================================================
    // FSM Next State Logic
    // =========================================================================
    
    always_comb begin
        state_next = state;
        queue_pop  = 1'b0;
        fetch_done = 1'b0;
        
        case (state)
            REQ_IDLE: begin
                if (!queue_empty) begin
                    // Use current_req for decision since we're still in IDLE
                    // latched_req will be captured this cycle but available next cycle
                    if (current_req_is_write)
                        state_next = REQ_ISSUE_C;
                    else
                        state_next = REQ_ISSUE_A;
                end
            end
            
            // Atomic A+B fetch flow
            REQ_ISSUE_A: begin
                if (dram_req_valid && dram_req_ready)
                    state_next = FETCH_A;
            end
            
            FETCH_A: begin
                // Done when all SRAM words written
                if (sram_word_count >= words_a)
                    state_next = REQ_ISSUE_B;
            end
            
            REQ_ISSUE_B: begin
                if (dram_req_valid && dram_req_ready)
                    state_next = FETCH_B;
            end
            
            FETCH_B: begin
                if (sram_word_count >= words_b)
                    state_next = FETCH_DONE_SIGNAL;
            end
            
            FETCH_DONE_SIGNAL: begin
                fetch_done = 1'b1;
                queue_pop  = 1'b1;
                state_next = REQ_IDLE;
            end
            
            // C writeback flow
            REQ_ISSUE_C: begin
                if (dram_req_valid && dram_req_ready)
                    state_next = WRITEBACK_C_READ;
            end
            
            WRITEBACK_C_READ: begin
                // Transition to write when: full beat ready OR all words read
                if ((words_packed_in_beat == WORDS_PER_BEAT) || 
                    (words_packed_total >= target_words && words_packed_in_beat != 0))
                    state_next = WRITEBACK_C_WRITE;
            end
            
            WRITEBACK_C_WRITE: begin
                // After writing a beat
                if (dram_wvalid && dram_wready) begin
                    // If this was the last beat, wait for ack
                    if (dram_wlast)
                        state_next = WB_WAIT_ACK;
                    // Otherwise, go back to read more words
                    else
                        state_next = WRITEBACK_C_READ;
                end
            end
            
            WB_WAIT_ACK: begin
                if (dram_bvalid) begin
                    fetch_done = 1'b1;
                    queue_pop  = 1'b1;
                    state_next = REQ_IDLE;
                end
            end
            
            default: state_next = REQ_IDLE;
        endcase
    end
    
    // =========================================================================
    // Counter Management
    // =========================================================================
    
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            dram_beat_count <= '0;
            sram_word_count <= '0;
            subword_count   <= '0;
            target_beats    <= '0;
            target_words    <= '0;
            current_bytes   <= '0;
        end else begin
            case (state)
                REQ_IDLE: begin
                    dram_beat_count <= '0;
                    sram_word_count <= '0;
                    subword_count   <= '0;
                end
                
                REQ_ISSUE_A: begin
                    dram_beat_count <= '0;
                    sram_word_count <= '0;
                    target_beats    <= beats_a;
                    target_words    <= words_a;
                    current_bytes   <= bytes_a;
                    subword_count   <= '0;
                end
                
                FETCH_A: begin
                    // Accept DRAM beat: capture into buffer and set valid
                    if (dram_rvalid && dram_rready) begin
                        dram_beat_count <= dram_beat_count + 1;
                        subword_count   <= '0;  // Reset to start extracting subwords
                    end
                    // Write SRAM word: increment subword pointer
                    if (sram_req_valid && sram_req_ready) begin
                        sram_word_count <= sram_word_count + 1;
                        subword_count   <= subword_count + 1;
                    end
                end
                
                REQ_ISSUE_B: begin
                    dram_beat_count <= '0;
                    sram_word_count <= '0;
                    subword_count   <= '0;
                    target_beats    <= beats_b;
                    target_words    <= words_b;
                    current_bytes   <= bytes_b;
                end
                
                FETCH_B: begin
                    // Accept DRAM beat
                    if (dram_rvalid && dram_rready) begin
                        dram_beat_count <= dram_beat_count + 1;
                        subword_count   <= '0;
                    end
                    // Write SRAM word
                    if (sram_req_valid && sram_req_ready) begin
                        sram_word_count <= sram_word_count + 1;
                        subword_count   <= subword_count + 1;
                    end
                end
                
                REQ_ISSUE_C: begin
                    dram_beat_count      <= '0;
                    sram_word_count      <= '0;
                    target_beats         <= beats_c;
                    target_words         <= words_c;
                    current_bytes        <= bytes_c;
                end
                
                WRITEBACK_C_READ: begin
                    // Read SRAM words
                    if (sram_req_valid && sram_req_ready) begin
                        sram_word_count <= sram_word_count + 1;
                    end
                end
                
                WRITEBACK_C_WRITE: begin
                    // Write DRAM beats
                    if (dram_wvalid && dram_wready) begin
                        dram_beat_count <= dram_beat_count + 1;
                    end
                end
                
                default: ;
            endcase
        end
    end
    
    // =========================================================================
    // DRAM Request Generation (explicit REQ_ISSUE states)
    // =========================================================================
    
    always_comb begin
        dram_req_valid    = 1'b0;
        dram_req_is_write = 1'b0;
        dram_req_addr     = '0;
        dram_req_bytes    = '0;
        
        if (state == REQ_ISSUE_A) begin
            dram_req_valid    = 1'b1;
            dram_req_is_write = 1'b0;
            dram_req_addr     = current_req_dram_addr_a;
            dram_req_bytes    = bytes_a;
        end else if (state == REQ_ISSUE_B) begin
            dram_req_valid    = 1'b1;
            dram_req_is_write = 1'b0;
            dram_req_addr     = current_req_dram_addr_b;
            dram_req_bytes    = bytes_b;
        end else if (state == REQ_ISSUE_C) begin
            dram_req_valid    = 1'b1;
            dram_req_is_write = 1'b1;
            dram_req_addr     = current_req_dram_addr_c;
            dram_req_bytes    = bytes_c;
        end
    end
    
    // =========================================================================
    // DRAM Read Data Path: DRAM (128b) → SRAM (32b) Downsizing with Beat Valid Flag
    // =========================================================================
    
    logic dram_fetch_active;
    logic need_new_beat;
    
    assign dram_fetch_active = (state == FETCH_A) || (state == FETCH_B);
    
    // Need new DRAM beat when:
    // - subword_count wrapped back to 0 (finished extracting 4 words from current beat)
    // - buffer is invalid (requesting first beat or after state transition)
    // - more words remain to transfer
    assign need_new_beat = !beat_buf_valid && (sram_word_count < target_words) && dram_fetch_active;
    
    // Beat buffer valid flag management
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            beat_buf_valid <= 1'b0;
        end else begin
            if (dram_fetch_active) begin
                if (dram_rvalid && dram_rready) begin
                    beat_buf_valid <= 1'b1;
                end
                else if (sram_req_valid && sram_req_ready && (subword_count == 2'b11)) begin
                    // Invalidate buffer after extracting last word from beat
                    // Only if more words remain (will request next beat)
                    if (sram_word_count + 1 < target_words)
                        beat_buf_valid <= 1'b0;
                end
            end else begin
                beat_buf_valid <= 1'b0;
            end
        end
    end

    
    // Buffer DRAM beat when it arrives
    always_ff @(posedge clk) begin
        if (dram_rvalid && dram_rready) begin
            dram_beat_buffer <= dram_rdata;
        end
    end
    
    // Accept DRAM read data when we need a new beat
    assign dram_rready = need_new_beat;
    
    // SRAM request valid: gated by target_words to prevent over-read/over-write
    // For WRITEBACK_C_READ: stop issuing reads when beat is full or all words read
    assign sram_req_valid =
        dram_fetch_active ? (beat_buf_valid && sram_word_count < target_words) :
        (state == WRITEBACK_C_READ) ? (words_packed_total < target_words && words_packed_in_beat < WORDS_PER_BEAT) : 
        1'b0;
    assign sram_req_wen = dram_fetch_active;
    
    logic [SRAM_ADDR_WIDTH-1:0] current_sram_base;
    always_comb begin
        if (state == FETCH_A)
            current_sram_base = current_req_sram_addr_a;
        else if (state == FETCH_B)
            current_sram_base = current_req_sram_addr_b;
        else if (state == WRITEBACK_C_READ)
            current_sram_base = current_req_sram_addr_c;
        else
            current_sram_base = '0;
    end
    
    // SRAM address = base + word_count
    // Bounded by sram_req_valid gating: max address = base + (target_words - 1)
    assign sram_req_addr = current_sram_base + sram_word_count;
    
    // Extract 32b word from 128b beat buffer based on subword_count
    always_comb begin
        case (subword_count)
            2'b00: sram_req_wdata = dram_beat_buffer[31:0];
            2'b01: sram_req_wdata = dram_beat_buffer[63:32];
            2'b10: sram_req_wdata = dram_beat_buffer[95:64];
            2'b11: sram_req_wdata = dram_beat_buffer[127:96];
        endcase
    end
    
    // =========================================================================
    // DRAM Write Data Path: SRAM (32b) → DRAM (128b) Upsizing with Zero-Padding
    // =========================================================================
    
    // Track words packed for write beat assembly
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            words_packed_in_beat <= '0;
            words_packed_total   <= '0;
        end else begin
            case (state)
                REQ_ISSUE_C: begin
                    words_packed_in_beat <= '0;
                    words_packed_total   <= '0;
                end
                
                WRITEBACK_C_READ: begin
                    // Increment packed count when SRAM word captured (only if buffer not full)
                    if (sram_req_rdata_valid && words_packed_in_beat < WORDS_PER_BEAT) begin
                        words_packed_in_beat <= words_packed_in_beat + 1;
                        words_packed_total   <= words_packed_total + 1;
                    end
                end
                
                WRITEBACK_C_WRITE: begin
                    // Reset in-beat counter when beat is sent
                    if (dram_wvalid && dram_wready) begin
                        words_packed_in_beat <= '0;
                    end
                end
                
                default: ;
            endcase
        end
    end
    
    // Accumulate SRAM words into DRAM write buffer with zero-padding
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            dram_write_buffer <= '0;
        end else if (state == WRITEBACK_C_READ && sram_req_rdata_valid && words_packed_in_beat < WORDS_PER_BEAT) begin
            // Pack SRAM word into write buffer based on words_packed_in_beat
            // Only pack if buffer not full to avoid overwriting on in-flight reads
            case (words_packed_in_beat[1:0])
                2'b00: dram_write_buffer[31:0]   <= sram_req_rdata;
                2'b01: dram_write_buffer[63:32]  <= sram_req_rdata;
                2'b10: dram_write_buffer[95:64]  <= sram_req_rdata;
                2'b11: dram_write_buffer[127:96] <= sram_req_rdata;
            endcase
        end else if (state == WRITEBACK_C_WRITE && dram_wvalid && dram_wready) begin
            // Clear buffer for next beat (zero-padding for partial beats)
            dram_write_buffer <= '0;
        end else if (state == REQ_ISSUE_C) begin
            dram_write_buffer <= '0;
        end
    end
    
    // DRAM write valid logic: full beat OR final partial beat
    logic write_beat_ready;
    logic is_last_beat;
    
    assign is_last_beat = (dram_beat_count == target_beats - 1);
    
    // Assert dram_wvalid when:
    // 1. Full beat ready: words_packed_in_beat == WORDS_PER_BEAT (4 words), OR
    // 2. Final partial beat ready: words_packed_total == target_words AND words_packed_in_beat != 0
    assign write_beat_ready = (words_packed_in_beat == WORDS_PER_BEAT) ||
                             (words_packed_total == target_words && words_packed_in_beat != 0);
    
    assign dram_wvalid = (state == WRITEBACK_C_WRITE) && write_beat_ready;
    
    // Zero-padding: unwritten upper bits remain 0 (cleared on beat send)
    // For partial beats, only lower bytes contain valid data
    assign dram_wdata = dram_write_buffer;
    assign dram_wlast = dram_wvalid && is_last_beat;
    assign dram_bready = (state == WB_WAIT_ACK);

endmodule
