// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module Conv2d (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        input_matrix_address0,
        input_matrix_ce0,
        input_matrix_q0,
        kernel_address0,
        kernel_ce0,
        kernel_q0,
        out_matrix_address0,
        out_matrix_ce0,
        out_matrix_we0,
        out_matrix_d0
);

parameter    ap_ST_fsm_state1 = 7'd1;
parameter    ap_ST_fsm_state2 = 7'd2;
parameter    ap_ST_fsm_pp0_stage0 = 7'd4;
parameter    ap_ST_fsm_pp0_stage1 = 7'd8;
parameter    ap_ST_fsm_pp0_stage2 = 7'd16;
parameter    ap_ST_fsm_pp0_stage3 = 7'd32;
parameter    ap_ST_fsm_state12 = 7'd64;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output  [9:0] input_matrix_address0;
output   input_matrix_ce0;
input  [31:0] input_matrix_q0;
output  [9:0] kernel_address0;
output   kernel_ce0;
input  [31:0] kernel_q0;
output  [3:0] out_matrix_address0;
output   out_matrix_ce0;
output   out_matrix_we0;
output  [31:0] out_matrix_d0;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg input_matrix_ce0;
reg kernel_ce0;
reg[3:0] out_matrix_address0;
reg out_matrix_ce0;
reg out_matrix_we0;
reg[31:0] out_matrix_d0;

(* fsm_encoding = "none" *) reg   [6:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
reg   [3:0] indvar_flatten_reg_148;
reg   [2:0] col_0_reg_159;
reg   [31:0] empty_reg_168;
reg   [2:0] row_0_reg_180;
wire   [0:0] icmp_ln31_fu_221_p2;
wire    ap_CS_fsm_state2;
wire   [3:0] add_ln31_fu_227_p2;
reg   [3:0] add_ln31_reg_572;
wire   [2:0] indvars_iv_mid2_fu_245_p3;
reg   [2:0] indvars_iv_mid2_reg_577;
wire   [1:0] row_mid2_fu_253_p3;
reg   [1:0] row_mid2_reg_583;
wire   [1:0] col_cast6_mid2_v_fu_261_p3;
reg   [1:0] col_cast6_mid2_v_reg_588;
wire   [2:0] col_cast6_mid2_fu_269_p1;
wire   [3:0] col_cast_mid2_fu_277_p1;
reg   [3:0] col_cast_mid2_reg_598;
wire   [2:0] row_cast3_fu_311_p1;
reg   [2:0] row_cast3_reg_604;
wire   [8:0] row_cast_fu_315_p1;
reg   [8:0] row_cast_reg_610;
reg   [3:0] out_matrix_addr_reg_615;
wire   [0:0] icmp_ln34_fu_399_p2;
reg   [0:0] icmp_ln34_reg_620;
wire    ap_CS_fsm_pp0_stage0;
wire    ap_block_state3_pp0_stage0_iter0;
wire    ap_block_state7_pp0_stage0_iter1;
wire    ap_block_state11_pp0_stage0_iter2;
wire    ap_block_pp0_stage0_11001;
reg   [0:0] icmp_ln34_reg_620_pp0_iter1_reg;
wire   [3:0] add_ln34_fu_405_p2;
reg   [3:0] add_ln34_reg_624;
reg    ap_enable_reg_pp0_iter0;
wire   [2:0] row_0_mid2_fu_422_p3;
reg   [2:0] row_0_mid2_reg_629;
wire   [2:0] select_ln34_fu_519_p3;
reg   [2:0] select_ln34_reg_634;
reg   [31:0] input_matrix_load_reg_649;
wire    ap_CS_fsm_pp0_stage1;
wire    ap_block_state4_pp0_stage1_iter0;
wire    ap_block_state8_pp0_stage1_iter1;
wire    ap_block_pp0_stage1_11001;
reg   [31:0] kernel_load_reg_654;
wire   [2:0] row_8_fu_553_p2;
reg   [2:0] row_8_reg_659;
wire    ap_CS_fsm_pp0_stage3;
wire    ap_block_state6_pp0_stage3_iter0;
wire    ap_block_state10_pp0_stage3_iter1;
wire    ap_block_pp0_stage3_11001;
wire   [31:0] grp_fu_195_p2;
reg   [31:0] tmp_reg_664;
wire   [31:0] grp_fu_189_p2;
reg    ap_enable_reg_pp0_iter2;
wire   [1:0] j_fu_558_p2;
wire    ap_CS_fsm_state12;
wire   [2:0] add_ln32_fu_563_p2;
wire    ap_block_pp0_stage0_subdone;
reg    ap_condition_pp0_exit_iter0_state3;
reg    ap_enable_reg_pp0_iter1;
wire    ap_block_pp0_stage3_subdone;
reg   [3:0] indvar_flatten7_reg_104;
reg   [1:0] col_reg_115;
reg   [2:0] indvars_iv_reg_126;
reg   [1:0] row_reg_137;
reg   [3:0] ap_phi_mux_indvar_flatten_phi_fu_152_p4;
wire    ap_block_pp0_stage0;
reg   [2:0] ap_phi_mux_col_0_phi_fu_162_p4;
reg   [2:0] ap_phi_mux_row_0_phi_fu_183_p4;
wire   [63:0] zext_ln33_fu_329_p1;
wire   [63:0] zext_ln36_fu_537_p1;
wire  signed [63:0] sext_ln36_1_fu_548_p1;
wire    ap_block_pp0_stage1;
wire    ap_CS_fsm_pp0_stage2;
wire    ap_block_pp0_stage2;
wire   [3:0] shl_ln_fu_203_p3;
wire   [4:0] zext_ln33_11_fu_211_p1;
wire   [4:0] col_cast5_fu_199_p1;
wire   [0:0] icmp_ln32_fu_239_p2;
wire   [1:0] i_fu_233_p2;
wire   [3:0] shl_ln33_mid1_fu_281_p3;
wire   [4:0] zext_ln33_21_fu_289_p1;
wire   [4:0] col_cast5_mid1_fu_273_p1;
wire   [4:0] sub_ln33_6_fu_293_p2;
wire   [4:0] sub_ln33_fu_215_p2;
wire   [4:0] sub_ln33_mid2_fu_299_p3;
wire   [4:0] row_cast4_fu_307_p1;
wire   [4:0] add_ln33_fu_319_p2;
wire  signed [31:0] sext_ln33_fu_325_p1;
wire   [7:0] shl_ln9_fu_338_p3;
wire   [3:0] shl_ln36_s_fu_350_p3;
wire   [8:0] zext_ln36_6_fu_346_p1;
wire   [8:0] zext_ln36_7_fu_358_p1;
wire   [3:0] col_0_cast2_fu_334_p1;
wire   [3:0] sub_ln36_fu_368_p2;
wire   [5:0] shl_ln36_2_fu_381_p3;
wire   [8:0] shl_ln36_1_fu_373_p3;
wire  signed [8:0] sext_ln36_fu_389_p1;
wire   [0:0] icmp_ln35_fu_417_p2;
wire   [2:0] col_10_fu_411_p2;
wire   [7:0] shl_ln36_mid1_fu_433_p3;
wire   [3:0] shl_ln36_11_mid1_fu_445_p3;
wire   [8:0] zext_ln36_8_fu_441_p1;
wire   [8:0] zext_ln36_9_fu_453_p1;
wire   [8:0] sub_ln36_20_fu_457_p2;
wire   [8:0] sub_ln36_13_fu_362_p2;
wire   [3:0] col_0_cast2_mid1_fu_429_p1;
wire   [3:0] sub_ln36_21_fu_471_p2;
wire   [5:0] shl_ln36_13_mid1_fu_484_p3;
wire   [8:0] shl_ln36_12_mid1_fu_476_p3;
wire  signed [8:0] sext_ln36_4_fu_492_p1;
wire   [8:0] sub_ln36_22_fu_496_p2;
wire   [8:0] sub_ln36_14_fu_393_p2;
wire   [8:0] sub_ln36_8_mid2_v_fu_502_p3;
wire   [8:0] sub_ln36_13_mid2_fu_463_p3;
wire   [8:0] row_0_cast_mid2_cast_fu_515_p1;
wire   [8:0] add_ln36_fu_527_p2;
wire  signed [31:0] sext_ln36_3_fu_533_p1;
wire   [8:0] sub_ln36_8_mid2_fu_510_p2;
wire   [8:0] add_ln36_2_fu_542_p2;
wire    ap_block_pp0_stage3;
reg   [6:0] ap_NS_fsm;
wire    ap_block_pp0_stage1_subdone;
wire    ap_block_state5_pp0_stage2_iter0;
wire    ap_block_state9_pp0_stage2_iter1;
wire    ap_block_pp0_stage2_subdone;
reg    ap_idle_pp0;
wire    ap_enable_pp0;

// power-on initialization
initial begin
#0 ap_CS_fsm = 7'd1;
#0 ap_enable_reg_pp0_iter0 = 1'b0;
#0 ap_enable_reg_pp0_iter2 = 1'b0;
#0 ap_enable_reg_pp0_iter1 = 1'b0;
end

forw_back_fadd_32bkb #(
    .ID( 1 ),
    .NUM_STAGE( 4 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
forw_back_fadd_32bkb_U84(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(empty_reg_168),
    .din1(tmp_reg_664),
    .ce(1'b1),
    .dout(grp_fu_189_p2)
);

forw_back_fmul_32cud #(
    .ID( 1 ),
    .NUM_STAGE( 3 ),
    .din0_WIDTH( 32 ),
    .din1_WIDTH( 32 ),
    .dout_WIDTH( 32 ))
forw_back_fmul_32cud_U85(
    .clk(ap_clk),
    .reset(ap_rst),
    .din0(input_matrix_load_reg_649),
    .din1(kernel_load_reg_654),
    .ce(1'b1),
    .dout(grp_fu_195_p2)
);

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter0 <= 1'b0;
    end else begin
        if (((1'b1 == ap_CS_fsm_pp0_stage0) & (1'b1 == ap_condition_pp0_exit_iter0_state3) & (1'b0 == ap_block_pp0_stage0_subdone))) begin
            ap_enable_reg_pp0_iter0 <= 1'b0;
        end else if (((icmp_ln31_fu_221_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
            ap_enable_reg_pp0_iter0 <= 1'b1;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter1 <= 1'b0;
    end else begin
        if (((1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3_subdone))) begin
            ap_enable_reg_pp0_iter1 <= ap_enable_reg_pp0_iter0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_enable_reg_pp0_iter2 <= 1'b0;
    end else begin
        if ((((1'b1 == ap_CS_fsm_pp0_stage0) & (1'b0 == ap_block_pp0_stage0_subdone)) | ((1'b1 == ap_CS_fsm_pp0_stage3) & (1'b0 == ap_block_pp0_stage3_subdone)))) begin
            ap_enable_reg_pp0_iter2 <= ap_enable_reg_pp0_iter1;
        end else if (((icmp_ln31_fu_221_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
            ap_enable_reg_pp0_iter2 <= 1'b0;
        end
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (icmp_ln34_reg_620 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter1 == 1'b1))) begin
        col_0_reg_159 <= select_ln34_reg_634;
    end else if (((icmp_ln31_fu_221_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        col_0_reg_159 <= col_cast6_mid2_fu_269_p1;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state12)) begin
        col_reg_115 <= col_cast6_mid2_v_reg_588;
    end else if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
        col_reg_115 <= 2'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (icmp_ln34_reg_620_pp0_iter1_reg == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        empty_reg_168 <= grp_fu_189_p2;
    end else if (((icmp_ln31_fu_221_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        empty_reg_168 <= 32'd0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state12)) begin
        indvar_flatten7_reg_104 <= add_ln31_reg_572;
    end else if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
        indvar_flatten7_reg_104 <= 4'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (icmp_ln34_reg_620 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter1 == 1'b1))) begin
        indvar_flatten_reg_148 <= add_ln34_reg_624;
    end else if (((icmp_ln31_fu_221_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        indvar_flatten_reg_148 <= 4'd0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state12)) begin
        indvars_iv_reg_126 <= add_ln32_fu_563_p2;
    end else if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
        indvars_iv_reg_126 <= 3'd3;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (icmp_ln34_reg_620 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter1 == 1'b1))) begin
        row_0_reg_180 <= row_8_reg_659;
    end else if (((icmp_ln31_fu_221_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        row_0_reg_180 <= row_cast3_fu_311_p1;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state12)) begin
        row_reg_137 <= j_fu_558_p2;
    end else if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
        row_reg_137 <= 2'd0;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        add_ln31_reg_572 <= add_ln31_fu_227_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
        add_ln34_reg_624 <= add_ln34_fu_405_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln31_fu_221_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        col_cast6_mid2_v_reg_588 <= col_cast6_mid2_v_fu_261_p3;
        col_cast_mid2_reg_598[1 : 0] <= col_cast_mid2_fu_277_p1[1 : 0];
        indvars_iv_mid2_reg_577 <= indvars_iv_mid2_fu_245_p3;
        out_matrix_addr_reg_615 <= zext_ln33_fu_329_p1;
        row_cast3_reg_604[1 : 0] <= row_cast3_fu_311_p1[1 : 0];
        row_cast_reg_610[1 : 0] <= row_cast_fu_315_p1[1 : 0];
        row_mid2_reg_583 <= row_mid2_fu_253_p3;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        icmp_ln34_reg_620 <= icmp_ln34_fu_399_p2;
        icmp_ln34_reg_620_pp0_iter1_reg <= icmp_ln34_reg_620;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln34_reg_620 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage1) & (1'b0 == ap_block_pp0_stage1_11001))) begin
        input_matrix_load_reg_649 <= input_matrix_q0;
        kernel_load_reg_654 <= kernel_q0;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (icmp_ln34_fu_399_p2 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        row_0_mid2_reg_629 <= row_0_mid2_fu_422_p3;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln34_reg_620 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage3) & (ap_enable_reg_pp0_iter0 == 1'b1) & (1'b0 == ap_block_pp0_stage3_11001))) begin
        row_8_reg_659 <= row_8_fu_553_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (icmp_ln34_fu_399_p2 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
        select_ln34_reg_634 <= select_ln34_fu_519_p3;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (icmp_ln34_reg_620 == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage0))) begin
        tmp_reg_664 <= grp_fu_195_p2;
    end
end

always @ (*) begin
    if ((icmp_ln34_fu_399_p2 == 1'd1)) begin
        ap_condition_pp0_exit_iter0_state3 = 1'b1;
    end else begin
        ap_condition_pp0_exit_iter0_state3 = 1'b0;
    end
end

always @ (*) begin
    if ((((icmp_ln31_fu_221_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2)) | ((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1)))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((ap_enable_reg_pp0_iter1 == 1'b0) & (ap_enable_reg_pp0_iter2 == 1'b0) & (ap_enable_reg_pp0_iter0 == 1'b0))) begin
        ap_idle_pp0 = 1'b1;
    end else begin
        ap_idle_pp0 = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln34_reg_620 == 1'd0) & (1'b0 == ap_block_pp0_stage0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter1 == 1'b1))) begin
        ap_phi_mux_col_0_phi_fu_162_p4 = select_ln34_reg_634;
    end else begin
        ap_phi_mux_col_0_phi_fu_162_p4 = col_0_reg_159;
    end
end

always @ (*) begin
    if (((icmp_ln34_reg_620 == 1'd0) & (1'b0 == ap_block_pp0_stage0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter1 == 1'b1))) begin
        ap_phi_mux_indvar_flatten_phi_fu_152_p4 = add_ln34_reg_624;
    end else begin
        ap_phi_mux_indvar_flatten_phi_fu_152_p4 = indvar_flatten_reg_148;
    end
end

always @ (*) begin
    if (((icmp_ln34_reg_620 == 1'd0) & (1'b0 == ap_block_pp0_stage0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter1 == 1'b1))) begin
        ap_phi_mux_row_0_phi_fu_183_p4 = row_8_reg_659;
    end else begin
        ap_phi_mux_row_0_phi_fu_183_p4 = row_0_reg_180;
    end
end

always @ (*) begin
    if (((icmp_ln31_fu_221_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
        input_matrix_ce0 = 1'b1;
    end else begin
        input_matrix_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter0 == 1'b1))) begin
        kernel_ce0 = 1'b1;
    end else begin
        kernel_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        out_matrix_address0 = out_matrix_addr_reg_615;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        out_matrix_address0 = zext_ln33_fu_329_p1;
    end else begin
        out_matrix_address0 = 'bx;
    end
end

always @ (*) begin
    if (((1'b1 == ap_CS_fsm_state2) | ((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter2 == 1'b1)))) begin
        out_matrix_ce0 = 1'b1;
    end else begin
        out_matrix_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((1'b0 == ap_block_pp0_stage0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter2 == 1'b1))) begin
        out_matrix_d0 = grp_fu_189_p2;
    end else if ((1'b1 == ap_CS_fsm_state2)) begin
        out_matrix_d0 = 32'd0;
    end else begin
        out_matrix_d0 = 'bx;
    end
end

always @ (*) begin
    if ((((1'b0 == ap_block_pp0_stage0_11001) & (icmp_ln34_reg_620_pp0_iter1_reg == 1'd0) & (1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter2 == 1'b1)) | ((icmp_ln31_fu_221_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2)))) begin
        out_matrix_we0 = 1'b1;
    end else begin
        out_matrix_we0 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((1'b1 == ap_CS_fsm_state1) & (ap_start == 1'b1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((icmp_ln31_fu_221_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end
        end
        ap_ST_fsm_pp0_stage0 : begin
            if ((~((icmp_ln34_fu_399_p2 == 1'd1) & (ap_enable_reg_pp0_iter0 == 1'b1) & (ap_enable_reg_pp0_iter1 == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone)) & ~((1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter2 == 1'b1) & (ap_enable_reg_pp0_iter1 == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone)) & (1'b0 == ap_block_pp0_stage0_subdone))) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            end else if ((((1'b1 == ap_CS_fsm_pp0_stage0) & (ap_enable_reg_pp0_iter2 == 1'b1) & (ap_enable_reg_pp0_iter1 == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone)) | ((icmp_ln34_fu_399_p2 == 1'd1) & (ap_enable_reg_pp0_iter0 == 1'b1) & (ap_enable_reg_pp0_iter1 == 1'b0) & (1'b0 == ap_block_pp0_stage0_subdone)))) begin
                ap_NS_fsm = ap_ST_fsm_state12;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end
        end
        ap_ST_fsm_pp0_stage1 : begin
            if ((1'b0 == ap_block_pp0_stage1_subdone)) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            end
        end
        ap_ST_fsm_pp0_stage2 : begin
            if ((1'b0 == ap_block_pp0_stage2_subdone)) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage3;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage2;
            end
        end
        ap_ST_fsm_pp0_stage3 : begin
            if ((1'b0 == ap_block_pp0_stage3_subdone)) begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            end else begin
                ap_NS_fsm = ap_ST_fsm_pp0_stage3;
            end
        end
        ap_ST_fsm_state12 : begin
            ap_NS_fsm = ap_ST_fsm_state2;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign add_ln31_fu_227_p2 = (indvar_flatten7_reg_104 + 4'd1);

assign add_ln32_fu_563_p2 = (indvars_iv_mid2_reg_577 + 3'd1);

assign add_ln33_fu_319_p2 = (sub_ln33_mid2_fu_299_p3 + row_cast4_fu_307_p1);

assign add_ln34_fu_405_p2 = (ap_phi_mux_indvar_flatten_phi_fu_152_p4 + 4'd1);

assign add_ln36_2_fu_542_p2 = (row_0_cast_mid2_cast_fu_515_p1 + sub_ln36_8_mid2_fu_510_p2);

assign add_ln36_fu_527_p2 = (sub_ln36_13_mid2_fu_463_p3 + row_0_cast_mid2_cast_fu_515_p1);

assign ap_CS_fsm_pp0_stage0 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_pp0_stage1 = ap_CS_fsm[32'd3];

assign ap_CS_fsm_pp0_stage2 = ap_CS_fsm[32'd4];

assign ap_CS_fsm_pp0_stage3 = ap_CS_fsm[32'd5];

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state12 = ap_CS_fsm[32'd6];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_block_pp0_stage0 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_subdone = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage1 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage1_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage1_subdone = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage2 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage2_subdone = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage3 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage3_11001 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage3_subdone = ~(1'b1 == 1'b1);

assign ap_block_state10_pp0_stage3_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state11_pp0_stage0_iter2 = ~(1'b1 == 1'b1);

assign ap_block_state3_pp0_stage0_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state4_pp0_stage1_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state5_pp0_stage2_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state6_pp0_stage3_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state7_pp0_stage0_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state8_pp0_stage1_iter1 = ~(1'b1 == 1'b1);

assign ap_block_state9_pp0_stage2_iter1 = ~(1'b1 == 1'b1);

assign ap_enable_pp0 = (ap_idle_pp0 ^ 1'b1);

assign col_0_cast2_fu_334_p1 = ap_phi_mux_col_0_phi_fu_162_p4;

assign col_0_cast2_mid1_fu_429_p1 = col_10_fu_411_p2;

assign col_10_fu_411_p2 = (ap_phi_mux_col_0_phi_fu_162_p4 + 3'd1);

assign col_cast5_fu_199_p1 = col_reg_115;

assign col_cast5_mid1_fu_273_p1 = i_fu_233_p2;

assign col_cast6_mid2_fu_269_p1 = col_cast6_mid2_v_fu_261_p3;

assign col_cast6_mid2_v_fu_261_p3 = ((icmp_ln32_fu_239_p2[0:0] === 1'b1) ? i_fu_233_p2 : col_reg_115);

assign col_cast_mid2_fu_277_p1 = col_cast6_mid2_v_fu_261_p3;

assign i_fu_233_p2 = (col_reg_115 + 2'd1);

assign icmp_ln31_fu_221_p2 = ((indvar_flatten7_reg_104 == 4'd9) ? 1'b1 : 1'b0);

assign icmp_ln32_fu_239_p2 = ((indvars_iv_reg_126 == 3'd6) ? 1'b1 : 1'b0);

assign icmp_ln34_fu_399_p2 = ((ap_phi_mux_indvar_flatten_phi_fu_152_p4 == 4'd9) ? 1'b1 : 1'b0);

assign icmp_ln35_fu_417_p2 = ((ap_phi_mux_row_0_phi_fu_183_p4 == indvars_iv_mid2_reg_577) ? 1'b1 : 1'b0);

assign indvars_iv_mid2_fu_245_p3 = ((icmp_ln32_fu_239_p2[0:0] === 1'b1) ? 3'd3 : indvars_iv_reg_126);

assign input_matrix_address0 = zext_ln36_fu_537_p1;

assign j_fu_558_p2 = (row_mid2_reg_583 + 2'd1);

assign kernel_address0 = sext_ln36_1_fu_548_p1;

assign row_0_cast_mid2_cast_fu_515_p1 = row_0_mid2_fu_422_p3;

assign row_0_mid2_fu_422_p3 = ((icmp_ln35_fu_417_p2[0:0] === 1'b1) ? row_cast3_reg_604 : ap_phi_mux_row_0_phi_fu_183_p4);

assign row_8_fu_553_p2 = (row_0_mid2_reg_629 + 3'd1);

assign row_cast3_fu_311_p1 = row_mid2_fu_253_p3;

assign row_cast4_fu_307_p1 = row_mid2_fu_253_p3;

assign row_cast_fu_315_p1 = row_mid2_fu_253_p3;

assign row_mid2_fu_253_p3 = ((icmp_ln32_fu_239_p2[0:0] === 1'b1) ? 2'd0 : row_reg_137);

assign select_ln34_fu_519_p3 = ((icmp_ln35_fu_417_p2[0:0] === 1'b1) ? col_10_fu_411_p2 : ap_phi_mux_col_0_phi_fu_162_p4);

assign sext_ln33_fu_325_p1 = $signed(add_ln33_fu_319_p2);

assign sext_ln36_1_fu_548_p1 = $signed(add_ln36_2_fu_542_p2);

assign sext_ln36_3_fu_533_p1 = $signed(add_ln36_fu_527_p2);

assign sext_ln36_4_fu_492_p1 = $signed(shl_ln36_13_mid1_fu_484_p3);

assign sext_ln36_fu_389_p1 = $signed(shl_ln36_2_fu_381_p3);

assign shl_ln33_mid1_fu_281_p3 = {{i_fu_233_p2}, {2'd0}};

assign shl_ln36_11_mid1_fu_445_p3 = {{col_10_fu_411_p2}, {1'd0}};

assign shl_ln36_12_mid1_fu_476_p3 = {{sub_ln36_21_fu_471_p2}, {5'd0}};

assign shl_ln36_13_mid1_fu_484_p3 = {{sub_ln36_21_fu_471_p2}, {2'd0}};

assign shl_ln36_1_fu_373_p3 = {{sub_ln36_fu_368_p2}, {5'd0}};

assign shl_ln36_2_fu_381_p3 = {{sub_ln36_fu_368_p2}, {2'd0}};

assign shl_ln36_mid1_fu_433_p3 = {{col_10_fu_411_p2}, {5'd0}};

assign shl_ln36_s_fu_350_p3 = {{ap_phi_mux_col_0_phi_fu_162_p4}, {1'd0}};

assign shl_ln9_fu_338_p3 = {{ap_phi_mux_col_0_phi_fu_162_p4}, {5'd0}};

assign shl_ln_fu_203_p3 = {{col_reg_115}, {2'd0}};

assign sub_ln33_6_fu_293_p2 = (zext_ln33_21_fu_289_p1 - col_cast5_mid1_fu_273_p1);

assign sub_ln33_fu_215_p2 = (zext_ln33_11_fu_211_p1 - col_cast5_fu_199_p1);

assign sub_ln33_mid2_fu_299_p3 = ((icmp_ln32_fu_239_p2[0:0] === 1'b1) ? sub_ln33_6_fu_293_p2 : sub_ln33_fu_215_p2);

assign sub_ln36_13_fu_362_p2 = (zext_ln36_6_fu_346_p1 - zext_ln36_7_fu_358_p1);

assign sub_ln36_13_mid2_fu_463_p3 = ((icmp_ln35_fu_417_p2[0:0] === 1'b1) ? sub_ln36_20_fu_457_p2 : sub_ln36_13_fu_362_p2);

assign sub_ln36_14_fu_393_p2 = ($signed(shl_ln36_1_fu_373_p3) - $signed(sext_ln36_fu_389_p1));

assign sub_ln36_20_fu_457_p2 = (zext_ln36_8_fu_441_p1 - zext_ln36_9_fu_453_p1);

assign sub_ln36_21_fu_471_p2 = (col_0_cast2_mid1_fu_429_p1 - col_cast_mid2_reg_598);

assign sub_ln36_22_fu_496_p2 = ($signed(shl_ln36_12_mid1_fu_476_p3) - $signed(sext_ln36_4_fu_492_p1));

assign sub_ln36_8_mid2_fu_510_p2 = (sub_ln36_8_mid2_v_fu_502_p3 - row_cast_reg_610);

assign sub_ln36_8_mid2_v_fu_502_p3 = ((icmp_ln35_fu_417_p2[0:0] === 1'b1) ? sub_ln36_22_fu_496_p2 : sub_ln36_14_fu_393_p2);

assign sub_ln36_fu_368_p2 = (col_0_cast2_fu_334_p1 - col_cast_mid2_reg_598);

assign zext_ln33_11_fu_211_p1 = shl_ln_fu_203_p3;

assign zext_ln33_21_fu_289_p1 = shl_ln33_mid1_fu_281_p3;

assign zext_ln33_fu_329_p1 = $unsigned(sext_ln33_fu_325_p1);

assign zext_ln36_6_fu_346_p1 = shl_ln9_fu_338_p3;

assign zext_ln36_7_fu_358_p1 = shl_ln36_s_fu_350_p3;

assign zext_ln36_8_fu_441_p1 = shl_ln36_mid1_fu_433_p3;

assign zext_ln36_9_fu_453_p1 = shl_ln36_11_mid1_fu_445_p3;

assign zext_ln36_fu_537_p1 = $unsigned(sext_ln36_3_fu_533_p1);

always @ (posedge ap_clk) begin
    col_cast_mid2_reg_598[3:2] <= 2'b00;
    row_cast3_reg_604[2] <= 1'b0;
    row_cast_reg_610[8:2] <= 7'b0000000;
end

endmodule //Conv2d
