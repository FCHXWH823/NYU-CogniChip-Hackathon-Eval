// =============================================================================
// Module: tile_scheduler
// Description: Tile scheduling FSM with 3-nested-loop iteration
//              Manages buffer allocation, DRAM fetch requests, compute handshake
//              Supports single/double_a/double_b/double_ab buffering modes
// =============================================================================

module tile_scheduler #(
    parameter int MAX_TILE_DIM      = 64,
    parameter int SRAM_ADDR_WIDTH   = 16,
    parameter int DATA_WIDTH_A      = 8,
    parameter int DATA_WIDTH_B      = 8,
    parameter int DATA_WIDTH_C      = 32
) (
    input  logic        clk,
    input  logic        rst_n,
    
    // Config Interface
    input  logic [15:0] matrix_m,
    input  logic [15:0] matrix_n,
    input  logic [15:0] matrix_k,
    input  logic [12:0]  tile_m,
    input  logic [12:0]  tile_n,
    input  logic [12:0]  tile_k,
    input  logic [1:0]  buffering_mode,
    input  logic [31:0] dram_base_a,
    input  logic [31:0] dram_base_b,
    input  logic [31:0] dram_base_c,
    input  logic [15:0] sram_base_a_ping,
    input  logic [15:0] sram_base_a_pong,
    input  logic [15:0] sram_base_b_ping,
    input  logic [15:0] sram_base_b_pong,
    input  logic [15:0] sram_base_c,
    input  logic        start,
    
    // Prefetch Engine Interface
    output logic        fetch_req_valid,
    input  logic        fetch_req_ready,
    output logic        fetch_req_is_write,
    output logic [31:0] fetch_req_dram_addr_a,
    output logic [31:0] fetch_req_dram_addr_b,
    output logic [31:0] fetch_req_dram_addr_c,
    output logic [SRAM_ADDR_WIDTH-1:0] fetch_req_sram_addr_a,
    output logic [SRAM_ADDR_WIDTH-1:0] fetch_req_sram_addr_b,
    output logic [SRAM_ADDR_WIDTH-1:0] fetch_req_sram_addr_c,
    output logic [15:0] fetch_req_num_elements_a,
    output logic [15:0] fetch_req_num_elements_b,
    output logic [15:0] fetch_req_num_elements_c,
    input  logic        fetch_done,
    
    // Compute Engine Interface
    output logic        tile_valid,
    input  logic        tile_ready,
    input  logic        tile_done,
    output logic [SRAM_ADDR_WIDTH-1:0] tile_sram_addr_a,
    output logic [SRAM_ADDR_WIDTH-1:0] tile_sram_addr_b,
    output logic [SRAM_ADDR_WIDTH-1:0] tile_sram_addr_c,
    output logic [12:0]  tile_m_dim,
    output logic [12:0]  tile_n_dim,
    output logic [12:0]  tile_k_dim,
    
    // Status
    output logic        busy,
    output logic        done,
    output logic        error
);

    // =========================================================================
    // Local Parameters
    // =========================================================================
    
    localparam int ELEM_SIZE_A = DATA_WIDTH_A / 8;
    localparam int ELEM_SIZE_B = DATA_WIDTH_B / 8;
    localparam int ELEM_SIZE_C = DATA_WIDTH_C / 8;
    
    // Buffering modes
    localparam logic [1:0] MODE_SINGLE    = 2'b00;
    localparam logic [1:0] MODE_DOUBLE_A  = 2'b01;
    localparam logic [1:0] MODE_DOUBLE_B  = 2'b10;
    localparam logic [1:0] MODE_DOUBLE_AB = 2'b11;
    
    // FSM States
    typedef enum logic [3:0] {
        IDLE        = 4'b0000,
        FETCH_REQ   = 4'b0001,
        WAIT_DATA   = 4'b0010,
        TILE_READY  = 4'b0011,
        COMPUTE     = 4'b0100,
        WRITEBACK_C = 4'b0101,
        WB_WAIT_DONE = 4'b0110,
        NEXT_TILE   = 4'b0111,
        DONE_STATE  = 4'b1000
    } state_t;
    
    state_t state, state_next;
    
    // =========================================================================
    // Tile Loop Counters - Current and Next Tile Tracking
    // =========================================================================
    
    logic [15:0] m_tile, n_tile, k_tile;  // Current tile being computed
    logic [15:0] next_m_tile, next_n_tile, next_k_tile;  // Next tile for prefetch
    logic [15:0] m_tiles_total, n_tiles_total, k_tiles_total;
    logic        last_k_tile, all_tiles_done, next_tile_exists;
    
    always_comb begin
        m_tiles_total = matrix_m / {3'h0, tile_m};
        n_tiles_total = matrix_n / {3'h0, tile_n};
        k_tiles_total = matrix_k / {3'h0, tile_k};
    end
    
    assign last_k_tile = (k_tile == k_tiles_total - 1);
    assign all_tiles_done = (m_tile == m_tiles_total - 1) && 
                           (n_tile == n_tiles_total - 1) && 
                           (k_tile == k_tiles_total - 1);
    
    // Compute next tile indices for prefetch overlap
    always_comb begin
        next_k_tile = k_tile;
        next_n_tile = n_tile;
        next_m_tile = m_tile;
        next_tile_exists = 1'b0;
        
        if (!all_tiles_done) begin
            next_tile_exists = 1'b1;
            if (k_tile < k_tiles_total - 1) begin
                next_k_tile = k_tile + 1;
            end else begin
                next_k_tile = '0;
                if (n_tile < n_tiles_total - 1) begin
                    next_n_tile = n_tile + 1;
                end else begin
                    next_n_tile = '0;
                    next_m_tile = m_tile + 1;
                end
            end
        end
    end
    
    // =========================================================================
    // Buffer Management with Overlap Support
    // =========================================================================
    
    logic buffer_a_sel, buffer_b_sel;              // Current tile buffer: 0=ping, 1=pong
    logic next_buffer_a_sel, next_buffer_b_sel;    // Next tile buffer (for overlap)
    logic [1:0] buffer_a_locked, buffer_b_locked;  // [0]=ping, [1]=pong
    logic buffers_available;                       // Current tile buffers free
    logic next_buffers_available;                  // Next tile buffers free (for overlap)
    logic prefetch_pending;                        // Prefetch of next tile issued during COMPUTE
    
    // Next buffer is opposite of current buffer in double modes
    assign next_buffer_a_sel = ~buffer_a_sel;
    assign next_buffer_b_sel = ~buffer_b_sel;
    
    always_comb begin
        // Check if current tile buffers are available
        buffers_available = 1'b1;
        
        // Check A buffer availability
        if ((buffering_mode == MODE_DOUBLE_A) || (buffering_mode == MODE_DOUBLE_AB)) begin
            buffers_available = buffers_available && !buffer_a_locked[buffer_a_sel];
        end else begin
            buffers_available = buffers_available && !buffer_a_locked[0];
        end
        
        // Check B buffer availability
        if ((buffering_mode == MODE_DOUBLE_B) || (buffering_mode == MODE_DOUBLE_AB)) begin
            buffers_available = buffers_available && !buffer_b_locked[buffer_b_sel];
        end else begin
            buffers_available = buffers_available && !buffer_b_locked[0];
        end
        
        // Check if next tile buffers are available (for overlap during COMPUTE)
        next_buffers_available = 1'b1;
        
        if ((buffering_mode == MODE_DOUBLE_A) || (buffering_mode == MODE_DOUBLE_AB)) begin
            next_buffers_available = next_buffers_available && !buffer_a_locked[next_buffer_a_sel];
        end
        
        if ((buffering_mode == MODE_DOUBLE_B) || (buffering_mode == MODE_DOUBLE_AB)) begin
            next_buffers_available = next_buffers_available && !buffer_b_locked[next_buffer_b_sel];
        end
    end
    
    // =========================================================================
    // Address Calculation - Current and Next Tile
    // =========================================================================
    
    logic [31:0] dram_addr_a_calc, dram_addr_b_calc, dram_addr_c_calc;
    logic [31:0] next_dram_addr_a_calc, next_dram_addr_b_calc;
    logic [31:0] tile_offset_a, tile_offset_b, tile_offset_c;
    logic [31:0] next_tile_offset_a, next_tile_offset_b;
    logic [15:0] num_elements_a, num_elements_b, num_elements_c;
    
    always_comb begin
        // Current tile addresses
        // A matrix: (m_tile * Tm * K + k_tile * Tk) * elem_size
        tile_offset_a = (m_tile * {3'h0, tile_m} * matrix_k + k_tile * {3'h0, tile_k}) * ELEM_SIZE_A;
        dram_addr_a_calc = dram_base_a + tile_offset_a;
        num_elements_a = {3'h0, tile_m} * {3'h0, tile_k};
        
        // B matrix: (k_tile * Tk * N + n_tile * Tn) * elem_size
        tile_offset_b = (k_tile * {3'h0, tile_k} * matrix_n + n_tile * {3'h0, tile_n}) * ELEM_SIZE_B;
        dram_addr_b_calc = dram_base_b + tile_offset_b;
        num_elements_b = {3'h0, tile_k} * {3'h0, tile_n};
        
        // C matrix: (m_tile * Tm * N + n_tile * Tn) * elem_size
        tile_offset_c = (m_tile * {3'h0, tile_m} * matrix_n + n_tile * {3'h0, tile_n}) * ELEM_SIZE_C;
        dram_addr_c_calc = dram_base_c + tile_offset_c;
        num_elements_c = {3'h0, tile_m} * {3'h0, tile_n};
        
        // Next tile addresses (for prefetch overlap)
        next_tile_offset_a = (next_m_tile * {3'h0, tile_m} * matrix_k + next_k_tile * {3'h0, tile_k}) * ELEM_SIZE_A;
        next_dram_addr_a_calc = dram_base_a + next_tile_offset_a;
        
        next_tile_offset_b = (next_k_tile * {3'h0, tile_k} * matrix_n + next_n_tile * {3'h0, tile_n}) * ELEM_SIZE_B;
        next_dram_addr_b_calc = dram_base_b + next_tile_offset_b;
    end
    
    // SRAM address selection based on buffer select
    logic [SRAM_ADDR_WIDTH-1:0] sram_addr_a_sel, sram_addr_b_sel;
    logic [SRAM_ADDR_WIDTH-1:0] next_sram_addr_a_sel, next_sram_addr_b_sel;
    
    always_comb begin
        // Current tile A buffer selection
        if ((buffering_mode == MODE_DOUBLE_A) || (buffering_mode == MODE_DOUBLE_AB)) begin
            sram_addr_a_sel = buffer_a_sel ? sram_base_a_pong : sram_base_a_ping;
            next_sram_addr_a_sel = next_buffer_a_sel ? sram_base_a_pong : sram_base_a_ping;
        end else begin
            sram_addr_a_sel = sram_base_a_ping;
            next_sram_addr_a_sel = sram_base_a_ping;
        end
        
        // Current tile B buffer selection
        if ((buffering_mode == MODE_DOUBLE_B) || (buffering_mode == MODE_DOUBLE_AB)) begin
            sram_addr_b_sel = buffer_b_sel ? sram_base_b_pong : sram_base_b_ping;
            next_sram_addr_b_sel = next_buffer_b_sel ? sram_base_b_pong : sram_base_b_ping;
        end else begin
            sram_addr_b_sel = sram_base_b_ping;
            next_sram_addr_b_sel = sram_base_b_ping;
        end
    end
    
    // =========================================================================
    // FSM State Register
    // =========================================================================
    
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= IDLE;
        end else begin
            state <= state_next;
        end
    end
    
    // =========================================================================
    // FSM Next State Logic
    // =========================================================================
    
    always_comb begin
        state_next = state;
        
        case (state)
            IDLE: begin
                if (start) begin
                    state_next = FETCH_REQ;
                end
            end
            
            FETCH_REQ: begin
                // Issue atomic A+B fetch request; wait for acceptance
                if (fetch_req_valid && fetch_req_ready && buffers_available) begin
                    state_next = WAIT_DATA;
                end
            end
            
            WAIT_DATA: begin
                // Wait for fetch_done indicating A+B are loaded to SRAM
                if (fetch_done) begin
                    state_next = TILE_READY;
                end
            end
            
            TILE_READY: begin
                // Explicit tile acceptance: tile_valid && tile_ready
                if (tile_valid && tile_ready) begin
                    state_next = COMPUTE;
                end
            end
            
            COMPUTE: begin
                // During COMPUTE, may issue overlapped prefetch for next tile
                // State advances only on tile_done
                if (tile_done) begin
                    if (last_k_tile) begin
                        state_next = WRITEBACK_C;
                    end else begin
                        state_next = NEXT_TILE;
                    end
                end
            end
            
            WRITEBACK_C: begin
                // Issue C write-back request; wait for acceptance
                if (fetch_req_valid && fetch_req_ready) begin
                    state_next = WB_WAIT_DONE;
                end
            end
            
            WB_WAIT_DONE: begin
                // Wait for fetch_done (indicating DRAM bvalid seen)
                if (fetch_done) begin
                    state_next = NEXT_TILE;
                end
            end
            
            NEXT_TILE: begin
                if (all_tiles_done) begin
                    state_next = DONE_STATE;
                end else if (prefetch_pending) begin
                    // Next tile already prefetched during overlap, skip FETCH_REQ
                    state_next = TILE_READY;
                end else begin
                    // Normal path: need to fetch next tile
                    state_next = FETCH_REQ;
                end
            end
            
            DONE_STATE: begin
                // Stay in DONE until reset or new start
                if (start) begin
                    state_next = FETCH_REQ;
                end
            end
            
            default: state_next = IDLE;
        endcase
    end
    
    // =========================================================================
    // Tile Counter Update
    // =========================================================================
    
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            m_tile <= '0;
            n_tile <= '0;
            k_tile <= '0;
        end else begin
            if (state == IDLE && start) begin
                m_tile <= '0;
                n_tile <= '0;
                k_tile <= '0;
            end else if (state == NEXT_TILE) begin
                // Increment k first (innermost loop)
                if (k_tile < k_tiles_total - 1) begin
                    k_tile <= k_tile + 1;
                end else begin
                    k_tile <= '0;
                    // Then increment n
                    if (n_tile < n_tiles_total - 1) begin
                        n_tile <= n_tile + 1;
                    end else begin
                        n_tile <= '0;
                        // Finally increment m (outermost)
                        if (m_tile < m_tiles_total - 1) begin
                            m_tile <= m_tile + 1;
                        end
                    end
                end
            end
        end
    end
    
    // =========================================================================
    // Prefetch Overlap Control
    // =========================================================================
    
    // Track if prefetch for next tile was issued during COMPUTE
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            prefetch_pending <= 1'b0;
        end else begin
            // Set when overlapped prefetch issued from COMPUTE
            if (state == COMPUTE && fetch_req_valid && fetch_req_ready && !fetch_req_is_write) begin
                prefetch_pending <= 1'b1;
            end
            // Clear when moving to next tile
            else if (state == NEXT_TILE) begin
                prefetch_pending <= 1'b0;
            end
            // Also clear on IDLE
            else if (state == IDLE) begin
                prefetch_pending <= 1'b0;
            end
        end
    end
    
    // =========================================================================
    // Buffer Lock Management with Overlap Support
    // =========================================================================
    
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            buffer_a_locked <= 2'b00;
            buffer_b_locked <= 2'b00;
            buffer_a_sel    <= 1'b0;
            buffer_b_sel    <= 1'b0;
        end else begin
            // Lock buffers when fetch completes in WAIT_DATA (serial path)
            if (state == WAIT_DATA && fetch_done) begin
                if ((buffering_mode == MODE_DOUBLE_A) || (buffering_mode == MODE_DOUBLE_AB)) begin
                    buffer_a_locked[buffer_a_sel] <= 1'b1;
                end else begin
                    buffer_a_locked[0] <= 1'b1;
                end
                
                if ((buffering_mode == MODE_DOUBLE_B) || (buffering_mode == MODE_DOUBLE_AB)) begin
                    buffer_b_locked[buffer_b_sel] <= 1'b1;
                end else begin
                    buffer_b_locked[0] <= 1'b1;
                end
            end
            
            // Lock NEXT buffers when overlapped prefetch completes during COMPUTE
            if (state == COMPUTE && fetch_done && prefetch_pending) begin
                if ((buffering_mode == MODE_DOUBLE_A) || (buffering_mode == MODE_DOUBLE_AB)) begin
                    buffer_a_locked[next_buffer_a_sel] <= 1'b1;
                end
                
                if ((buffering_mode == MODE_DOUBLE_B) || (buffering_mode == MODE_DOUBLE_AB)) begin
                    buffer_b_locked[next_buffer_b_sel] <= 1'b1;
                end
            end
            
            // Unlock CURRENT buffers when compute completes
            if (state == COMPUTE && tile_done) begin
                if ((buffering_mode == MODE_DOUBLE_A) || (buffering_mode == MODE_DOUBLE_AB)) begin
                    buffer_a_locked[buffer_a_sel] <= 1'b0;
                end else begin
                    buffer_a_locked[0] <= 1'b0;
                end
                
                if ((buffering_mode == MODE_DOUBLE_B) || (buffering_mode == MODE_DOUBLE_AB)) begin
                    buffer_b_locked[buffer_b_sel] <= 1'b0;
                end else begin
                    buffer_b_locked[0] <= 1'b0;
                end
            end
            
            // Toggle buffer selection on tile_done for double buffer modes
            if (state == COMPUTE && tile_done) begin
                if ((buffering_mode == MODE_DOUBLE_A) || (buffering_mode == MODE_DOUBLE_AB)) begin
                    buffer_a_sel <= ~buffer_a_sel;
                end
                
                if ((buffering_mode == MODE_DOUBLE_B) || (buffering_mode == MODE_DOUBLE_AB)) begin
                    buffer_b_sel <= ~buffer_b_sel;
                end
            end
            
            // Reset on IDLE
            if (state == IDLE) begin
                buffer_a_locked <= 2'b00;
                buffer_b_locked <= 2'b00;
                buffer_a_sel    <= 1'b0;
                buffer_b_sel    <= 1'b0;
            end
        end
    end
    
    // =========================================================================
    // Fetch Request Output with Overlap Support
    // =========================================================================
    
    logic overlap_prefetch_enable;
    logic using_overlap_prefetch;
    
    // Enable overlap prefetch during COMPUTE if:
    // - Double buffer mode enabled (not single)
    // - Next tile exists
    // - Next buffers are free
    // - No prefetch already pending
    // - Prefetch engine is ready
    assign overlap_prefetch_enable = (state == COMPUTE) && 
                                     (buffering_mode != MODE_SINGLE) &&
                                     next_tile_exists &&
                                     next_buffers_available &&
                                     !prefetch_pending &&
                                     fetch_req_ready;
    
    // Determine if current request is for overlap (next tile) or normal (current tile)
    assign using_overlap_prefetch = (state == COMPUTE) && overlap_prefetch_enable;
    
    always_comb begin
        fetch_req_valid = 1'b0;
        fetch_req_is_write = 1'b0;
        
        if (state == FETCH_REQ) begin
            fetch_req_valid    = 1'b1;
            fetch_req_is_write = 1'b0;
        end else if (state == WRITEBACK_C) begin
            fetch_req_valid    = 1'b1;
            fetch_req_is_write = 1'b1;
        end else if (using_overlap_prefetch) begin
            // Overlapped prefetch of next tile during COMPUTE
            fetch_req_valid    = 1'b1;
            fetch_req_is_write = 1'b0;
        end
    end
    
    // Mux between current tile and next tile addresses for overlap
    assign fetch_req_dram_addr_a = using_overlap_prefetch ? next_dram_addr_a_calc : dram_addr_a_calc;
    assign fetch_req_dram_addr_b = using_overlap_prefetch ? next_dram_addr_b_calc : dram_addr_b_calc;
    assign fetch_req_dram_addr_c = dram_addr_c_calc;
    assign fetch_req_sram_addr_a = using_overlap_prefetch ? next_sram_addr_a_sel : sram_addr_a_sel;
    assign fetch_req_sram_addr_b = using_overlap_prefetch ? next_sram_addr_b_sel : sram_addr_b_sel;
    assign fetch_req_sram_addr_c = sram_base_c;
    assign fetch_req_num_elements_a = num_elements_a;
    assign fetch_req_num_elements_b = num_elements_b;
    assign fetch_req_num_elements_c = num_elements_c;
    
    // =========================================================================
    // Compute Engine Interface
    // =========================================================================
    
    // tile_valid asserted ONLY in TILE_READY state
    // Ensures single acceptance: tile accepted on (tile_valid && tile_ready)
    // Once in COMPUTE, tile_valid=0, preventing re-acceptance
    assign tile_valid = (state == TILE_READY);
    assign tile_sram_addr_a = sram_addr_a_sel;
    assign tile_sram_addr_b = sram_addr_b_sel;
    assign tile_sram_addr_c = sram_base_c;
    assign tile_m_dim = tile_m;
    assign tile_n_dim = tile_n;
    assign tile_k_dim = tile_k;
    
    // =========================================================================
    // Status Outputs
    // =========================================================================
    
    assign busy = (state != IDLE) && (state != DONE_STATE);
    assign done = (state == DONE_STATE);
    assign error = 1'b0;  // No runtime errors in this version

endmodule
