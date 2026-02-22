$date
	Fri Feb 20 13:07:09 2026
$end
$version
	Icarus Verilog
$end
$timescale
	1ps
$end
$scope module tb_pipelined_tests $end
$var wire 1 ! halt $end
$var wire 16 " debug_pc [15:0] $end
$var wire 16 # debug_instr [15:0] $end
$var wire 32 $ debug_cycle [31:0] $end
$var parameter 32 % CLK_PERIOD $end
$var parameter 32 & MAX_CYCLES $end
$var reg 1 ' clock $end
$var reg 1 ( reset $end
$var reg 400 ) test_name [399:0] $end
$var integer 32 * cycle_count [31:0] $end
$var integer 32 + mem_init_idx [31:0] $end
$var integer 32 , test_num [31:0] $end
$scope module dut $end
$var wire 1 - MUXifpc $end
$var wire 1 . Pnop1 $end
$var wire 1 / Pnop2 $end
$var wire 1 0 Pnop2_exec2 $end
$var wire 1 1 Pstall $end
$var wire 1 2 WEreg $end
$var wire 3 3 aluOp [2:0] $end
$var wire 16 4 b3_next [15:0] $end
$var wire 1 ' clock $end
$var wire 32 5 debug_cycle [31:0] $end
$var wire 16 6 debug_instr [15:0] $end
$var wire 16 7 debug_pc [15:0] $end
$var wire 1 ! halt $end
$var wire 16 8 instr_fetched [15:0] $end
$var wire 1 9 is_jr $end
$var wire 16 : mem_data [15:0] $end
$var wire 1 ; needs_stall $end
$var wire 1 ( reset $end
$var wire 1 < take_jump $end
$var wire 3 = wb_opcode [2:0] $end
$var wire 16 > wb_data [15:0] $end
$var wire 3 ? wb_addr [2:0] $end
$var wire 16 @ r2_data [15:0] $end
$var wire 3 A r2_addr [2:0] $end
$var wire 16 B r1_data [15:0] $end
$var wire 3 C r1_addr [2:0] $end
$var wire 16 D pc_next [15:0] $end
$var wire 16 E muxalu2_out [15:0] $end
$var wire 16 F mout_next [15:0] $end
$var wire 13 G mem_addr [12:0] $end
$var wire 1 H is_jeq $end
$var wire 1 I is_jal $end
$var wire 1 J is_j $end
$var wire 1 K ir5_writes $end
$var wire 3 L ir5_dest [2:0] $end
$var wire 1 M ir4_writes $end
$var wire 3 N ir4_dest [2:0] $end
$var wire 1 O ir3_writes $end
$var wire 3 P ir3_dest [2:0] $end
$var wire 3 Q ir2_reg2 [2:0] $end
$var wire 3 R ir2_reg1 [2:0] $end
$var wire 1 S ir2_is_lw $end
$var wire 3 T ir2_dest [2:0] $end
$var wire 3 U ir1_reg2 [2:0] $end
$var wire 3 V ir1_reg1 [2:0] $end
$var wire 16 W b2_next [15:0] $end
$var wire 16 X alu_operand2 [15:0] $end
$var wire 16 Y alu_operand1 [15:0] $end
$var wire 16 Z alu_in2 [15:0] $end
$var wire 16 [ alu_in1 [15:0] $end
$var wire 16 \ alu_imm7 [15:0] $end
$var wire 1 ] WEram $end
$var wire 1 ^ WEpc $end
$var wire 1 _ MUXtgt $end
$var wire 2 ` MUXrw [1:0] $end
$var wire 1 a MUXr1 $end
$var wire 1 b MUXmout $end
$var wire 16 c MUXjmp [15:0] $end
$var wire 1 d MUXb $end
$var wire 1 e MUXalu3 $end
$var wire 2 f MUXalu2 [1:0] $end
$var wire 2 g MUXalu1 [1:0] $end
$var wire 1 h EQ $end
$var parameter 4 i ADD $end
$var parameter 3 j ADDI $end
$var parameter 3 k ALU_ADD $end
$var parameter 3 l ALU_AND $end
$var parameter 3 m ALU_NOR $end
$var parameter 3 n ALU_OR $end
$var parameter 3 o ALU_SLT $end
$var parameter 3 p ALU_SUB $end
$var parameter 3 q ALU_XOR $end
$var parameter 4 r AND $end
$var parameter 3 s J $end
$var parameter 3 t JAL $end
$var parameter 3 u JEQ $end
$var parameter 4 v JR $end
$var parameter 3 w LINK_REG $end
$var parameter 3 x LW $end
$var parameter 32 y MEM_SIZE $end
$var parameter 16 z NOP $end
$var parameter 4 { NOR $end
$var parameter 32 | NUM_REGS $end
$var parameter 4 } OR $end
$var parameter 32 ~ REG_BITS $end
$var parameter 4 !" SLL $end
$var parameter 4 "" SLT $end
$var parameter 3 #" SLTI $end
$var parameter 4 $" SRA $end
$var parameter 4 %" SRL $end
$var parameter 4 &" SUB $end
$var parameter 3 '" SW $end
$var parameter 3 (" THREE_REG $end
$var parameter 4 )" XOR $end
$var reg 16 *" A2 [15:0] $end
$var reg 16 +" B2 [15:0] $end
$var reg 16 ," B3 [15:0] $end
$var reg 16 -" IR1 [15:0] $end
$var reg 16 ." IR2 [15:0] $end
$var reg 16 /" IR3 [15:0] $end
$var reg 16 0" IR4 [15:0] $end
$var reg 16 1" IR5 [15:0] $end
$var reg 16 2" PC0 [15:0] $end
$var reg 16 3" PC1 [15:0] $end
$var reg 16 4" PC2 [15:0] $end
$var reg 16 5" PC3 [15:0] $end
$var reg 16 6" PC4 [15:0] $end
$var reg 16 7" aluOut [15:0] $end
$var reg 3 8" alu_op_val [2:0] $end
$var reg 16 9" alu_result [15:0] $end
$var reg 32 :" cycle_count [31:0] $end
$var reg 1 ;" halted $end
$var reg 16 <" mOut [15:0] $end
$var reg 2 =" muxalu1_val [1:0] $end
$var reg 2 >" muxalu2_val [1:0] $end
$var reg 4 ?" pc_unchanged_count [3:0] $end
$var reg 16 @" prev_pc0 [15:0] $end
$var reg 16 A" wbOut [15:0] $end
$var integer 32 B" i [31:0] $end
$scope function get_dest_reg $end
$var reg 16 C" instr [15:0] $end
$var reg 3 D" op [2:0] $end
$upscope $end
$scope function get_func $end
$var reg 16 E" instr [15:0] $end
$upscope $end
$scope function get_imm13 $end
$var reg 16 F" instr [15:0] $end
$upscope $end
$scope function get_imm7_signed $end
$var reg 7 G" imm7 [6:0] $end
$var reg 16 H" instr [15:0] $end
$upscope $end
$scope function get_opcode $end
$var reg 16 I" instr [15:0] $end
$upscope $end
$scope function get_reg1 $end
$var reg 16 J" instr [15:0] $end
$upscope $end
$scope function get_reg2 $end
$var reg 16 K" instr [15:0] $end
$upscope $end
$scope function get_reg3 $end
$var reg 16 L" instr [15:0] $end
$upscope $end
$scope function is_jump $end
$var reg 4 M" fn [3:0] $end
$var reg 16 N" instr [15:0] $end
$var reg 3 O" op [2:0] $end
$upscope $end
$scope function is_lw $end
$var reg 16 P" instr [15:0] $end
$upscope $end
$scope function is_sw $end
$var reg 16 Q" instr [15:0] $end
$upscope $end
$scope function writes_register $end
$var reg 4 R" fn [3:0] $end
$var reg 16 S" instr [15:0] $end
$var reg 3 T" op [2:0] $end
$upscope $end
$upscope $end
$scope task load_test_array_sum $end
$upscope $end
$scope task load_test_fibonacci $end
$upscope $end
$scope task load_test_new_instructions $end
$upscope $end
$scope task load_test_simple $end
$upscope $end
$scope task print_state $end
$var integer 32 U" i [31:0] $end
$upscope $end
$scope task verify_results $end
$upscope $end
$upscope $end
$enddefinitions $end
$comment Show the parameter values. $end
$dumpall
b101 )"
b0 ("
b101 '"
b1 &"
b1010 %"
b1011 $"
b111 #"
b100 ""
b1001 !"
b11 ~
b10 }
b1000 |
b110 {
b0 z
b10000000000000 y
b100 x
b111 w
b1000 v
b110 u
b11 t
b10 s
b11 r
b101 q
b1 p
b100 o
b11 n
b110 m
b10 l
b0 k
b1 j
b0 i
b11000011010100000 &
b1010 %
$end
#0
$dumpvars
bx U"
b0 T"
b0 S"
b0 R"
b0 Q"
b0 P"
bx O"
bx N"
bx M"
b0 L"
b0 K"
b0 J"
b0 I"
b0 H"
b0 G"
b0 F"
b0 E"
b0 D"
b0 C"
b1000 B"
b0 A"
b0 @"
b0 ?"
b11 >"
b11 ="
b0 <"
0;"
b0 :"
b0 9"
b0 8"
b0 7"
b0 6"
b0 5"
b0 4"
b0 3"
b0 2"
b0 1"
b0 0"
b0 /"
b0 ."
b0 -"
b0 ,"
b0 +"
b0 *"
1h
b11 g
b11 f
1e
0d
b0 c
0b
0a
b1 `
0_
1^
0]
b0 \
b0 [
b0 Z
b0 Y
b0 X
b0 W
b0 V
b0 U
b0 T
0S
b0 R
b0 Q
b0 P
1O
b0 N
1M
b0 L
1K
0J
0I
0H
b0 G
b0 F
b0 E
b1 D
b0 C
b0 B
b0 A
b0 @
b0 ?
b0 >
b0 =
0<
0;
b10000010001100 :
09
b10000010001100 8
b0 7
b0 6
b0 5
b0 4
b0 3
02
01
00
0/
0.
0-
b11 ,
b10000000000000 +
b0 *
b11101000110010101110011011101000101111101101110011001010111011101011111011010010110111001110011011101000111001001110101011000110111010001101001011011110110111001110011 )
1(
0'
b0 $
b0 #
b0 "
0!
$end
#5000
b1000 B"
1'
#10000
0'
#15000
b1000 B"
1'
#20000
0'
#25000
b1000 B"
1'
#30000
0'
#35000
b1000 B"
1'
#40000
0'
#45000
b10000100000101 8
b10 D
b1 U
b10000010001100 I"
b10000010001100 J"
b1 A
b10000010001100 K"
b10000010001100 F"
b1 $
b1 5
b1 :"
b1 ?"
b1 "
b1 7
b1 2"
b10000010001100 #
b10000010001100 6
b10000010001100 -"
0(
1'
#50000
0'
#55000
b1100 9"
b1100 X
0e
b10001100 c
b10100110101 8
b11 D
b10 U
b10000010001100 I"
b10000100000101 J"
b10 A
b10000100000101 K"
b10000100000101 F"
b10000010001100 P"
b1 T
b1 D"
b10000010001100 C"
b1 Q
b10000010001100 E"
b1100 \
b1100 G"
b10000010001100 H"
b10 $
b10 5
b10 :"
b1 @"
b0 ?"
b10 "
b10 7
b10 2"
b1 3"
b10000100000101 #
b10000100000101 6
b10000100000101 -"
b10000010001100 ."
b1 *
1'
#60000
0'
#65000
b1 C
b100000101 c
b101 9"
1a
b101 X
b10101000110 8
b100 D
b1 V
b10100110101 J"
b10100110101 F"
b10000100000101 P"
b10 T
b10000100000101 C"
b10 Q
b10000100000101 I"
b10000100000101 E"
b101 \
b101 G"
b10000100000101 H"
b0 :
b1100 G
b1100 F
b1 P
b10100110101 K"
b1100 R"
b1 T"
b10000010001100 S"
b10000010001100 Q"
b11 $
b11 5
b11 :"
b10 @"
b11 "
b11 7
b11 2"
b10 3"
b10100110101 #
b10100110101 6
b10100110101 -"
b1 4"
b10000100000101 ."
b1100 7"
b10000010001100 /"
b10 *
1'
#70000
0'
#75000
1e
b1 ?
b1100 [
b1100 Y
b10100110101 c
b1001 9"
0h
b101 Z
b101 4
b101 E
b0 `
b101 X
b0 f
b0 >"
b1 g
b1 ="
12
b10001010000010 8
b101 D
b10101000110 J"
b10101000110 F"
b101 3
b101 8"
b10100110101 P"
b11 T
b0 D"
b1 R
b110101 \
b110101 G"
b10100110101 H"
b10101011001 :
b101 G
b101 F
b10 P
b101 R"
b10000100000101 S"
b10000100000101 Q"
b1100 >
b1 N
b1 =
b10100110101 E"
b10100110101 I"
b10100110101 C"
b10100110101 L"
b10101000110 K"
b100 $
b100 5
b100 :"
b11 @"
b100 "
b100 7
b100 2"
b11 3"
b10101000110 #
b10101000110 6
b10101000110 -"
b10 4"
b10100110101 ."
b101 7"
b1 5"
b10000100000101 /"
b1100 <"
b10000010001100 0"
b11 *
1'
#80000
0'
#85000
b10101000110 c
b10 ?
0h
0a
b0 C
b101 X
b1100 [
b1100 Y
b1 f
b1 >"
b10 g
b10 ="
b0 B
b10101011001 8
b110 D
b0 V
b101 U
b10001010000010 J"
b101 A
b10001010000010 F"
b1111111111110010 9"
b110 3
b110 8"
b10101000110 P"
b100 T
b1111111111000110 \
b1000110 G"
b10101000110 H"
b101 Z
b101 4
b101 E
b0 :
b1001 G
b1001 F
b11 P
b0 T"
b10100110101 Q"
b101 >
b10 N
b10101000110 L"
b1 L
b10001010000010 K"
b0 D"
b10101000110 C"
b101 R"
b10101000110 E"
b10101000110 I"
b10100110101 S"
b101 $
b101 5
b101 :"
b100 @"
b101 "
b101 7
b101 2"
b100 3"
b10001010000010 #
b10001010000010 6
b10001010000010 -"
b11 4"
b10101000110 ."
b101 ,"
b1001 7"
b10 5"
b10100110101 /"
b101 <"
b1 6"
b10000100000101 0"
b1100 A"
b10000010001100 1"
b100 *
1'
#90000
0'
#95000
0e
b11 ?
1h
b1100 B
b1 C
b101 W
b1010000010 c
b10 X
b1 `
b0 [
b0 Y
1a
b101 @
b0 Z
b0 4
b0 E
b11 f
b11 >"
b11 g
b11 ="
b10101101010 8
b111 D
b1 V
b10 U
b10101011001 J"
b10 A
b10101011001 F"
b10 9"
b0 3
b0 8"
b10001010000010 P"
b101 T
b0 R
b101 Q
b10 \
b10 G"
b10001010000010 H"
b1111111110010 G
b1111111111110010 F
b100 P
b110 R"
b10101000110 Q"
b1001 >
b11 N
b0 =
b10101000110 L"
b10 L
b10101011001 K"
b1 D"
b10001010000010 C"
b10001010000010 E"
b0 T"
b10001010000010 I"
b10101000110 S"
b110 $
b110 5
b110 :"
b101 @"
b110 "
b110 7
b110 2"
b101 3"
b10101011001 #
b10101011001 6
b10101011001 -"
b100 4"
b10001010000010 ."
b1111111111110010 7"
b11 5"
b10101000110 /"
b1001 <"
b10 6"
b10100110101 0"
b101 A"
b10000100000101 1"
b101 *
1'
#100000
0'
#105000
1e
b101 Z
b101 4
b101 E
0h
b1100 [
b1100 Y
b10101011001 c
b100 ?
b101 X
b100000000000111 8
b1000 D
b10101101010 J"
b10101101010 F"
b110000000 9"
b10101011001 P"
b1 R
b10 Q
b1111111111011001 \
b1011001 G"
b10101011001 H"
b10100110101 :
b10 G
b10 F
b101 P
b1 T"
b10001010000010 Q"
b1111111111110010 >
b100 N
b10101101010 K"
b11 L
b10101011001 L"
b0 D"
b10101011001 C"
b10 R"
b10101011001 E"
b10101011001 I"
b10001010000010 S"
b111 $
b111 5
b111 :"
b110 @"
b111 "
b111 7
b111 2"
b110 3"
b10101101010 #
b10101101010 6
b10101101010 -"
b101 +"
b1100 *"
b101 4"
b10101011001 ."
b0 ,"
b10 7"
b100 5"
b10001010000010 /"
b1111111111110010 <"
b11 6"
b10101000110 0"
b1001 A"
b10100110101 1"
b110 *
1'
#110000
0'
#115000
1d
b0 B
b111 W
b10101101010 c
b0 `
b101 ?
0a
b0 C
b0 @
b0 8
b1001 D
b0 V
b0 U
b100000000000111 J"
b0 A
b100000000000111 F"
b0 9"
b10101101010 P"
b110 T
b1111111111101010 \
b1101010 G"
b10101101010 H"
b0 :
b110000000 G
b110000000 F
b10101011001 Q"
b10 >
b101 N
b1 =
b0 D"
b100000000000111 K"
b100 L
b10101101010 L"
b10101101010 C"
b1001 R"
b10101101010 E"
b0 T"
b100000000000111 I"
b10101011001 S"
b1000 $
b1000 5
b1000 :"
b111 @"
b1000 "
b1000 7
b1000 2"
b111 3"
b100000000000111 #
b100000000000111 6
b100000000000111 -"
b110 4"
b10101101010 ."
b101 ,"
b110000000 7"
b101 5"
b10101011001 /"
b10 <"
b100 6"
b10001010000010 0"
b1111111111110010 A"
b10101000110 1"
b111 *
1'
#120000
0'
#125000
b111 X
10
1-
1<
0d
b111 Z
b111 4
b111 E
b0 [
b0 Y
b111 c
b1 `
b101 ?
b0 W
b111 D
b0 J"
b0 F"
b111 9"
b100000000000111 P"
b0 T
b0 R
b0 Q
1J
b111 \
b111 G"
b100000000000111 H"
b10000010001100 :
b0 G
b0 F
b110 P
b10101101010 Q"
b110000000 >
b0 =
b10101101010 L"
b101 L
b0 K"
b10 D"
b100000000000111 C"
b1010 R"
b100000000000111 E"
b0 T"
b100000000000111 I"
b10101101010 S"
b1001 $
b1001 5
b1001 :"
b1000 @"
b1001 "
b1001 7
b1001 2"
b1000 3"
b0 #
b0 6
b0 -"
b111 +"
b0 *"
b111 4"
b100000000000111 ."
b0 7"
b110 5"
b10101101010 /"
b110000000 <"
b101 6"
b10101011001 0"
b10 A"
b10001010000010 1"
b1000 *
1'
#130000
0'
#135000
b0 9"
b0 X
00
0-
0<
b1000 D
1h
b0 Z
b0 4
b0 E
b0 c
b110 ?
b100000000000111 8
b0 P"
0J
b0 \
b0 G"
b0 H"
b100000000000111 :
b111 G
b111 F
b0 P
b10 T"
b100000000000111 Q"
b0 >
b110 N
b0 K"
b0 L"
b0 D"
b0 C"
b111 R"
b0 E"
b0 I"
b100000000000111 S"
b1010 $
b1010 5
b1010 :"
b1001 @"
1!
1;"
b111 "
b111 7
b111 2"
b1001 3"
b0 +"
b1000 4"
b0 ."
b111 ,"
b111 7"
b111 5"
b100000000000111 /"
b0 <"
b110 6"
b10101101010 0"
b110000000 A"
b10101011001 1"
b1001 *
1'
#140000
0'
#145000
b1010 *
1'
#150000
0'
#155000
1'
#160000
0'
#165000
b1000 U"
1'
