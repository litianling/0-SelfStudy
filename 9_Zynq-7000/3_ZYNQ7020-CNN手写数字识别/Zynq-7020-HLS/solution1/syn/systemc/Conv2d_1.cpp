// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "Conv2d_1.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic Conv2d_1::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic Conv2d_1::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<16> Conv2d_1::ap_ST_fsm_state1 = "1";
const sc_lv<16> Conv2d_1::ap_ST_fsm_state2 = "10";
const sc_lv<16> Conv2d_1::ap_ST_fsm_state3 = "100";
const sc_lv<16> Conv2d_1::ap_ST_fsm_state4 = "1000";
const sc_lv<16> Conv2d_1::ap_ST_fsm_state5 = "10000";
const sc_lv<16> Conv2d_1::ap_ST_fsm_state6 = "100000";
const sc_lv<16> Conv2d_1::ap_ST_fsm_state7 = "1000000";
const sc_lv<16> Conv2d_1::ap_ST_fsm_state8 = "10000000";
const sc_lv<16> Conv2d_1::ap_ST_fsm_state9 = "100000000";
const sc_lv<16> Conv2d_1::ap_ST_fsm_state10 = "1000000000";
const sc_lv<16> Conv2d_1::ap_ST_fsm_state11 = "10000000000";
const sc_lv<16> Conv2d_1::ap_ST_fsm_state12 = "100000000000";
const sc_lv<16> Conv2d_1::ap_ST_fsm_state13 = "1000000000000";
const sc_lv<16> Conv2d_1::ap_ST_fsm_state14 = "10000000000000";
const sc_lv<16> Conv2d_1::ap_ST_fsm_state15 = "100000000000000";
const sc_lv<16> Conv2d_1::ap_ST_fsm_state16 = "1000000000000000";
const sc_lv<32> Conv2d_1::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<32> Conv2d_1::ap_const_lv32_1 = "1";
const sc_lv<1> Conv2d_1::ap_const_lv1_0 = "0";
const sc_lv<32> Conv2d_1::ap_const_lv32_2 = "10";
const sc_lv<32> Conv2d_1::ap_const_lv32_3 = "11";
const sc_lv<1> Conv2d_1::ap_const_lv1_1 = "1";
const sc_lv<32> Conv2d_1::ap_const_lv32_4 = "100";
const sc_lv<32> Conv2d_1::ap_const_lv32_5 = "101";
const sc_lv<32> Conv2d_1::ap_const_lv32_6 = "110";
const sc_lv<32> Conv2d_1::ap_const_lv32_9 = "1001";
const sc_lv<32> Conv2d_1::ap_const_lv32_E = "1110";
const sc_lv<4> Conv2d_1::ap_const_lv4_0 = "0000";
const sc_lv<32> Conv2d_1::ap_const_lv32_F = "1111";
const sc_lv<32> Conv2d_1::ap_const_lv32_A = "1010";
const sc_lv<4> Conv2d_1::ap_const_lv4_E = "1110";
const sc_lv<4> Conv2d_1::ap_const_lv4_1 = "1";
const sc_lv<5> Conv2d_1::ap_const_lv5_3 = "11";
const bool Conv2d_1::ap_const_boolean_1 = true;

Conv2d_1::Conv2d_1(sc_module_name name) : sc_module(name), mVcdFile(0) {
    forw_back_fadd_32bkb_U66 = new forw_back_fadd_32bkb<1,5,32,32,32>("forw_back_fadd_32bkb_U66");
    forw_back_fadd_32bkb_U66->clk(ap_clk);
    forw_back_fadd_32bkb_U66->reset(ap_rst);
    forw_back_fadd_32bkb_U66->din0(empty_159_reg_128);
    forw_back_fadd_32bkb_U66->din1(tmp_reg_435);
    forw_back_fadd_32bkb_U66->ce(ap_var_for_const0);
    forw_back_fadd_32bkb_U66->dout(grp_fu_149_p2);
    forw_back_fmul_32cud_U67 = new forw_back_fmul_32cud<1,4,32,32,32>("forw_back_fmul_32cud_U67");
    forw_back_fmul_32cud_U67->clk(ap_clk);
    forw_back_fmul_32cud_U67->reset(ap_rst);
    forw_back_fmul_32cud_U67->din0(input_matrix_load_reg_420);
    forw_back_fmul_32cud_U67->din1(kernel_q0);
    forw_back_fmul_32cud_U67->ce(ap_var_for_const0);
    forw_back_fmul_32cud_U67->dout(grp_fu_154_p2);

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_add_ln30_fu_243_p2);
    sensitive << ( sub_ln30_reg_350 );
    sensitive << ( zext_ln32_7_fu_223_p1 );

    SC_METHOD(thread_add_ln31_fu_209_p2);
    sensitive << ( col_cast3_fu_163_p1 );

    SC_METHOD(thread_add_ln32_fu_257_p2);
    sensitive << ( zext_ln32_fu_219_p1 );

    SC_METHOD(thread_add_ln33_2_fu_315_p2);
    sensitive << ( sub_ln33_4_reg_392 );
    sensitive << ( row_0_reg_140 );

    SC_METHOD(thread_add_ln33_fu_305_p2);
    sensitive << ( shl_ln33_reg_387 );
    sensitive << ( row_0_reg_140 );

    SC_METHOD(thread_ap_CS_fsm_state1);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state10);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state11);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state15);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state16);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state2);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state3);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state4);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state5);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state6);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_CS_fsm_state7);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln28_fu_167_p2 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln28_fu_167_p2 );

    SC_METHOD(thread_col_6_fu_326_p2);
    sensitive << ( col_0_reg_118 );

    SC_METHOD(thread_col_cast3_fu_163_p1);
    sensitive << ( col_reg_84 );

    SC_METHOD(thread_col_cast4_fu_159_p1);
    sensitive << ( col_reg_84 );

    SC_METHOD(thread_i_fu_173_p2);
    sensitive << ( col_reg_84 );

    SC_METHOD(thread_icmp_ln28_fu_167_p2);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( col_reg_84 );

    SC_METHOD(thread_icmp_ln29_fu_231_p2);
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( row_reg_95 );

    SC_METHOD(thread_icmp_ln31_fu_267_p2);
    sensitive << ( zext_ln31_reg_355 );
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( col_0_reg_118 );

    SC_METHOD(thread_icmp_ln32_fu_300_p2);
    sensitive << ( zext_ln32_9_reg_379 );
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( row_0_reg_140 );

    SC_METHOD(thread_input_matrix_address0);
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( sext_ln33_fu_310_p1 );

    SC_METHOD(thread_input_matrix_ce0);
    sensitive << ( ap_CS_fsm_state5 );

    SC_METHOD(thread_j_fu_237_p2);
    sensitive << ( row_reg_95 );

    SC_METHOD(thread_kernel_address0);
    sensitive << ( ap_CS_fsm_state6 );
    sensitive << ( sext_ln33_1_fu_332_p1 );

    SC_METHOD(thread_kernel_ce0);
    sensitive << ( ap_CS_fsm_state6 );

    SC_METHOD(thread_out_matrix_address0);
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( out_matrix_addr_reg_374 );
    sensitive << ( ap_CS_fsm_state16 );
    sensitive << ( zext_ln30_fu_252_p1 );

    SC_METHOD(thread_out_matrix_ce0);
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( ap_CS_fsm_state16 );

    SC_METHOD(thread_out_matrix_d0);
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( tmp_s_reg_440 );
    sensitive << ( ap_CS_fsm_state16 );

    SC_METHOD(thread_out_matrix_we0);
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( icmp_ln29_fu_231_p2 );
    sensitive << ( ap_CS_fsm_state16 );

    SC_METHOD(thread_row_6_fu_320_p2);
    sensitive << ( row_0_reg_140 );

    SC_METHOD(thread_sext_ln30_fu_248_p1);
    sensitive << ( add_ln30_fu_243_p2 );

    SC_METHOD(thread_sext_ln33_1_fu_332_p1);
    sensitive << ( add_ln33_2_reg_405 );

    SC_METHOD(thread_sext_ln33_fu_310_p1);
    sensitive << ( add_ln33_fu_305_p2 );

    SC_METHOD(thread_shl_ln30_3_fu_191_p3);
    sensitive << ( col_reg_84 );

    SC_METHOD(thread_shl_ln33_5_fu_283_p2);
    sensitive << ( sub_ln33_fu_278_p2 );

    SC_METHOD(thread_shl_ln33_fu_272_p2);
    sensitive << ( col_0_reg_118 );

    SC_METHOD(thread_shl_ln_fu_179_p3);
    sensitive << ( col_reg_84 );

    SC_METHOD(thread_sub_ln30_fu_203_p2);
    sensitive << ( zext_ln30_6_fu_187_p1 );
    sensitive << ( zext_ln30_7_fu_199_p1 );

    SC_METHOD(thread_sub_ln33_4_fu_295_p2);
    sensitive << ( zext_ln32_8_reg_360 );
    sensitive << ( sub_ln33_8_fu_289_p2 );

    SC_METHOD(thread_sub_ln33_8_fu_289_p2);
    sensitive << ( sub_ln33_fu_278_p2 );
    sensitive << ( shl_ln33_5_fu_283_p2 );

    SC_METHOD(thread_sub_ln33_fu_278_p2);
    sensitive << ( col_cast4_reg_336 );
    sensitive << ( col_0_reg_118 );

    SC_METHOD(thread_zext_ln30_6_fu_187_p1);
    sensitive << ( shl_ln_fu_179_p3 );

    SC_METHOD(thread_zext_ln30_7_fu_199_p1);
    sensitive << ( shl_ln30_3_fu_191_p3 );

    SC_METHOD(thread_zext_ln30_fu_252_p1);
    sensitive << ( sext_ln30_fu_248_p1 );

    SC_METHOD(thread_zext_ln31_fu_215_p1);
    sensitive << ( add_ln31_fu_209_p2 );

    SC_METHOD(thread_zext_ln32_7_fu_223_p1);
    sensitive << ( row_reg_95 );

    SC_METHOD(thread_zext_ln32_8_fu_227_p1);
    sensitive << ( row_reg_95 );

    SC_METHOD(thread_zext_ln32_9_fu_263_p1);
    sensitive << ( add_ln32_fu_257_p2 );

    SC_METHOD(thread_zext_ln32_fu_219_p1);
    sensitive << ( row_reg_95 );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln28_fu_167_p2 );
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( icmp_ln29_fu_231_p2 );
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( icmp_ln31_fu_267_p2 );
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( icmp_ln32_fu_300_p2 );

    SC_THREAD(thread_ap_var_for_const0);

    ap_CS_fsm = "0000000000000001";
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "Conv2d_1_sc_trace_" << apTFileNum ++;
    string apTFn = apTFilenSS.str();
    mVcdFile = sc_create_vcd_trace_file(apTFn.c_str());
    mVcdFile->set_time_unit(1, SC_PS);
    if (1) {
#ifdef __HLS_TRACE_LEVEL_PORT_HIER__
    sc_trace(mVcdFile, ap_clk, "(port)ap_clk");
    sc_trace(mVcdFile, ap_rst, "(port)ap_rst");
    sc_trace(mVcdFile, ap_start, "(port)ap_start");
    sc_trace(mVcdFile, ap_done, "(port)ap_done");
    sc_trace(mVcdFile, ap_idle, "(port)ap_idle");
    sc_trace(mVcdFile, ap_ready, "(port)ap_ready");
    sc_trace(mVcdFile, input_matrix_address0, "(port)input_matrix_address0");
    sc_trace(mVcdFile, input_matrix_ce0, "(port)input_matrix_ce0");
    sc_trace(mVcdFile, input_matrix_q0, "(port)input_matrix_q0");
    sc_trace(mVcdFile, kernel_address0, "(port)kernel_address0");
    sc_trace(mVcdFile, kernel_ce0, "(port)kernel_ce0");
    sc_trace(mVcdFile, kernel_q0, "(port)kernel_q0");
    sc_trace(mVcdFile, out_matrix_address0, "(port)out_matrix_address0");
    sc_trace(mVcdFile, out_matrix_ce0, "(port)out_matrix_ce0");
    sc_trace(mVcdFile, out_matrix_we0, "(port)out_matrix_we0");
    sc_trace(mVcdFile, out_matrix_d0, "(port)out_matrix_d0");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_CS_fsm_state1, "ap_CS_fsm_state1");
    sc_trace(mVcdFile, col_cast4_fu_159_p1, "col_cast4_fu_159_p1");
    sc_trace(mVcdFile, col_cast4_reg_336, "col_cast4_reg_336");
    sc_trace(mVcdFile, ap_CS_fsm_state2, "ap_CS_fsm_state2");
    sc_trace(mVcdFile, i_fu_173_p2, "i_fu_173_p2");
    sc_trace(mVcdFile, i_reg_345, "i_reg_345");
    sc_trace(mVcdFile, sub_ln30_fu_203_p2, "sub_ln30_fu_203_p2");
    sc_trace(mVcdFile, sub_ln30_reg_350, "sub_ln30_reg_350");
    sc_trace(mVcdFile, icmp_ln28_fu_167_p2, "icmp_ln28_fu_167_p2");
    sc_trace(mVcdFile, zext_ln31_fu_215_p1, "zext_ln31_fu_215_p1");
    sc_trace(mVcdFile, zext_ln31_reg_355, "zext_ln31_reg_355");
    sc_trace(mVcdFile, zext_ln32_8_fu_227_p1, "zext_ln32_8_fu_227_p1");
    sc_trace(mVcdFile, zext_ln32_8_reg_360, "zext_ln32_8_reg_360");
    sc_trace(mVcdFile, ap_CS_fsm_state3, "ap_CS_fsm_state3");
    sc_trace(mVcdFile, j_fu_237_p2, "j_fu_237_p2");
    sc_trace(mVcdFile, j_reg_369, "j_reg_369");
    sc_trace(mVcdFile, out_matrix_addr_reg_374, "out_matrix_addr_reg_374");
    sc_trace(mVcdFile, icmp_ln29_fu_231_p2, "icmp_ln29_fu_231_p2");
    sc_trace(mVcdFile, zext_ln32_9_fu_263_p1, "zext_ln32_9_fu_263_p1");
    sc_trace(mVcdFile, zext_ln32_9_reg_379, "zext_ln32_9_reg_379");
    sc_trace(mVcdFile, shl_ln33_fu_272_p2, "shl_ln33_fu_272_p2");
    sc_trace(mVcdFile, shl_ln33_reg_387, "shl_ln33_reg_387");
    sc_trace(mVcdFile, ap_CS_fsm_state4, "ap_CS_fsm_state4");
    sc_trace(mVcdFile, icmp_ln31_fu_267_p2, "icmp_ln31_fu_267_p2");
    sc_trace(mVcdFile, sub_ln33_4_fu_295_p2, "sub_ln33_4_fu_295_p2");
    sc_trace(mVcdFile, sub_ln33_4_reg_392, "sub_ln33_4_reg_392");
    sc_trace(mVcdFile, ap_CS_fsm_state5, "ap_CS_fsm_state5");
    sc_trace(mVcdFile, icmp_ln32_fu_300_p2, "icmp_ln32_fu_300_p2");
    sc_trace(mVcdFile, add_ln33_2_fu_315_p2, "add_ln33_2_fu_315_p2");
    sc_trace(mVcdFile, add_ln33_2_reg_405, "add_ln33_2_reg_405");
    sc_trace(mVcdFile, row_6_fu_320_p2, "row_6_fu_320_p2");
    sc_trace(mVcdFile, row_6_reg_410, "row_6_reg_410");
    sc_trace(mVcdFile, col_6_fu_326_p2, "col_6_fu_326_p2");
    sc_trace(mVcdFile, input_matrix_load_reg_420, "input_matrix_load_reg_420");
    sc_trace(mVcdFile, ap_CS_fsm_state6, "ap_CS_fsm_state6");
    sc_trace(mVcdFile, ap_CS_fsm_state7, "ap_CS_fsm_state7");
    sc_trace(mVcdFile, grp_fu_154_p2, "grp_fu_154_p2");
    sc_trace(mVcdFile, tmp_reg_435, "tmp_reg_435");
    sc_trace(mVcdFile, ap_CS_fsm_state10, "ap_CS_fsm_state10");
    sc_trace(mVcdFile, grp_fu_149_p2, "grp_fu_149_p2");
    sc_trace(mVcdFile, tmp_s_reg_440, "tmp_s_reg_440");
    sc_trace(mVcdFile, ap_CS_fsm_state15, "ap_CS_fsm_state15");
    sc_trace(mVcdFile, col_reg_84, "col_reg_84");
    sc_trace(mVcdFile, row_reg_95, "row_reg_95");
    sc_trace(mVcdFile, empty_158_reg_106, "empty_158_reg_106");
    sc_trace(mVcdFile, col_0_reg_118, "col_0_reg_118");
    sc_trace(mVcdFile, empty_159_reg_128, "empty_159_reg_128");
    sc_trace(mVcdFile, ap_CS_fsm_state16, "ap_CS_fsm_state16");
    sc_trace(mVcdFile, row_0_reg_140, "row_0_reg_140");
    sc_trace(mVcdFile, zext_ln30_fu_252_p1, "zext_ln30_fu_252_p1");
    sc_trace(mVcdFile, sext_ln33_fu_310_p1, "sext_ln33_fu_310_p1");
    sc_trace(mVcdFile, sext_ln33_1_fu_332_p1, "sext_ln33_1_fu_332_p1");
    sc_trace(mVcdFile, ap_CS_fsm_state11, "ap_CS_fsm_state11");
    sc_trace(mVcdFile, shl_ln_fu_179_p3, "shl_ln_fu_179_p3");
    sc_trace(mVcdFile, shl_ln30_3_fu_191_p3, "shl_ln30_3_fu_191_p3");
    sc_trace(mVcdFile, zext_ln30_6_fu_187_p1, "zext_ln30_6_fu_187_p1");
    sc_trace(mVcdFile, zext_ln30_7_fu_199_p1, "zext_ln30_7_fu_199_p1");
    sc_trace(mVcdFile, col_cast3_fu_163_p1, "col_cast3_fu_163_p1");
    sc_trace(mVcdFile, add_ln31_fu_209_p2, "add_ln31_fu_209_p2");
    sc_trace(mVcdFile, zext_ln32_7_fu_223_p1, "zext_ln32_7_fu_223_p1");
    sc_trace(mVcdFile, add_ln30_fu_243_p2, "add_ln30_fu_243_p2");
    sc_trace(mVcdFile, sext_ln30_fu_248_p1, "sext_ln30_fu_248_p1");
    sc_trace(mVcdFile, zext_ln32_fu_219_p1, "zext_ln32_fu_219_p1");
    sc_trace(mVcdFile, add_ln32_fu_257_p2, "add_ln32_fu_257_p2");
    sc_trace(mVcdFile, sub_ln33_fu_278_p2, "sub_ln33_fu_278_p2");
    sc_trace(mVcdFile, shl_ln33_5_fu_283_p2, "shl_ln33_5_fu_283_p2");
    sc_trace(mVcdFile, sub_ln33_8_fu_289_p2, "sub_ln33_8_fu_289_p2");
    sc_trace(mVcdFile, add_ln33_fu_305_p2, "add_ln33_fu_305_p2");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
#endif

    }
}

Conv2d_1::~Conv2d_1() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

    delete forw_back_fadd_32bkb_U66;
    delete forw_back_fmul_32cud_U67;
}

void Conv2d_1::thread_ap_var_for_const0() {
    ap_var_for_const0 = ap_const_logic_1;
}

void Conv2d_1::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln32_fu_300_p2.read()))) {
        col_0_reg_118 = col_6_fu_326_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln29_fu_231_p2.read()))) {
        col_0_reg_118 = col_cast4_reg_336.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
         esl_seteq<1,1,1>(icmp_ln29_fu_231_p2.read(), ap_const_lv1_1))) {
        col_reg_84 = i_reg_345.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        col_reg_84 = ap_const_lv4_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln32_fu_300_p2.read()))) {
        empty_158_reg_106 = empty_159_reg_128.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln29_fu_231_p2.read()))) {
        empty_158_reg_106 = ap_const_lv32_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && 
         esl_seteq<1,1,1>(icmp_ln31_fu_267_p2.read(), ap_const_lv1_1))) {
        empty_159_reg_128 = empty_158_reg_106.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state16.read())) {
        empty_159_reg_128 = tmp_s_reg_440.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && 
         esl_seteq<1,1,1>(icmp_ln31_fu_267_p2.read(), ap_const_lv1_1))) {
        row_0_reg_140 = zext_ln32_8_reg_360.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state16.read())) {
        row_0_reg_140 = row_6_reg_410.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln31_fu_267_p2.read()))) {
        row_reg_95 = j_reg_369.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
                esl_seteq<1,1,1>(icmp_ln28_fu_167_p2.read(), ap_const_lv1_0))) {
        row_reg_95 = ap_const_lv4_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()) && esl_seteq<1,1,1>(ap_const_lv1_1, icmp_ln32_fu_300_p2.read()))) {
        add_ln33_2_reg_405 = add_ln33_2_fu_315_p2.read();
        row_6_reg_410 = row_6_fu_320_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        col_cast4_reg_336 = col_cast4_fu_159_p1.read();
        i_reg_345 = i_fu_173_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read())) {
        input_matrix_load_reg_420 = input_matrix_q0.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        j_reg_369 = j_fu_237_p2.read();
        zext_ln32_8_reg_360 = zext_ln32_8_fu_227_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln29_fu_231_p2.read()))) {
        out_matrix_addr_reg_374 =  (sc_lv<8>) (zext_ln30_fu_252_p1.read());
        zext_ln32_9_reg_379 = zext_ln32_9_fu_263_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && esl_seteq<1,1,1>(icmp_ln31_fu_267_p2.read(), ap_const_lv1_1))) {
        shl_ln33_reg_387 = shl_ln33_fu_272_p2.read();
        sub_ln33_4_reg_392 = sub_ln33_4_fu_295_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && esl_seteq<1,1,1>(icmp_ln28_fu_167_p2.read(), ap_const_lv1_0))) {
        sub_ln30_reg_350 = sub_ln30_fu_203_p2.read();
        zext_ln31_reg_355 = zext_ln31_fu_215_p1.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state10.read())) {
        tmp_reg_435 = grp_fu_154_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state15.read())) {
        tmp_s_reg_440 = grp_fu_149_p2.read();
    }
}

void Conv2d_1::thread_add_ln30_fu_243_p2() {
    add_ln30_fu_243_p2 = (!sub_ln30_reg_350.read().is_01() || !zext_ln32_7_fu_223_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(sub_ln30_reg_350.read()) + sc_biguint<9>(zext_ln32_7_fu_223_p1.read()));
}

void Conv2d_1::thread_add_ln31_fu_209_p2() {
    add_ln31_fu_209_p2 = (!col_cast3_fu_163_p1.read().is_01() || !ap_const_lv5_3.is_01())? sc_lv<5>(): (sc_biguint<5>(col_cast3_fu_163_p1.read()) + sc_biguint<5>(ap_const_lv5_3));
}

void Conv2d_1::thread_add_ln32_fu_257_p2() {
    add_ln32_fu_257_p2 = (!zext_ln32_fu_219_p1.read().is_01() || !ap_const_lv5_3.is_01())? sc_lv<5>(): (sc_biguint<5>(zext_ln32_fu_219_p1.read()) + sc_biguint<5>(ap_const_lv5_3));
}

void Conv2d_1::thread_add_ln33_2_fu_315_p2() {
    add_ln33_2_fu_315_p2 = (!sub_ln33_4_reg_392.read().is_01() || !row_0_reg_140.read().is_01())? sc_lv<32>(): (sc_biguint<32>(sub_ln33_4_reg_392.read()) + sc_biguint<32>(row_0_reg_140.read()));
}

void Conv2d_1::thread_add_ln33_fu_305_p2() {
    add_ln33_fu_305_p2 = (!row_0_reg_140.read().is_01() || !shl_ln33_reg_387.read().is_01())? sc_lv<32>(): (sc_biguint<32>(row_0_reg_140.read()) + sc_biguint<32>(shl_ln33_reg_387.read()));
}

void Conv2d_1::thread_ap_CS_fsm_state1() {
    ap_CS_fsm_state1 = ap_CS_fsm.read()[0];
}

void Conv2d_1::thread_ap_CS_fsm_state10() {
    ap_CS_fsm_state10 = ap_CS_fsm.read()[9];
}

void Conv2d_1::thread_ap_CS_fsm_state11() {
    ap_CS_fsm_state11 = ap_CS_fsm.read()[10];
}

void Conv2d_1::thread_ap_CS_fsm_state15() {
    ap_CS_fsm_state15 = ap_CS_fsm.read()[14];
}

void Conv2d_1::thread_ap_CS_fsm_state16() {
    ap_CS_fsm_state16 = ap_CS_fsm.read()[15];
}

void Conv2d_1::thread_ap_CS_fsm_state2() {
    ap_CS_fsm_state2 = ap_CS_fsm.read()[1];
}

void Conv2d_1::thread_ap_CS_fsm_state3() {
    ap_CS_fsm_state3 = ap_CS_fsm.read()[2];
}

void Conv2d_1::thread_ap_CS_fsm_state4() {
    ap_CS_fsm_state4 = ap_CS_fsm.read()[3];
}

void Conv2d_1::thread_ap_CS_fsm_state5() {
    ap_CS_fsm_state5 = ap_CS_fsm.read()[4];
}

void Conv2d_1::thread_ap_CS_fsm_state6() {
    ap_CS_fsm_state6 = ap_CS_fsm.read()[5];
}

void Conv2d_1::thread_ap_CS_fsm_state7() {
    ap_CS_fsm_state7 = ap_CS_fsm.read()[6];
}

void Conv2d_1::thread_ap_done() {
    if (((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
          esl_seteq<1,1,1>(icmp_ln28_fu_167_p2.read(), ap_const_lv1_1)))) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void Conv2d_1::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void Conv2d_1::thread_ap_ready() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
         esl_seteq<1,1,1>(icmp_ln28_fu_167_p2.read(), ap_const_lv1_1))) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void Conv2d_1::thread_col_6_fu_326_p2() {
    col_6_fu_326_p2 = (!col_0_reg_118.read().is_01() || !ap_const_lv32_1.is_01())? sc_lv<32>(): (sc_biguint<32>(col_0_reg_118.read()) + sc_biguint<32>(ap_const_lv32_1));
}

void Conv2d_1::thread_col_cast3_fu_163_p1() {
    col_cast3_fu_163_p1 = esl_zext<5,4>(col_reg_84.read());
}

void Conv2d_1::thread_col_cast4_fu_159_p1() {
    col_cast4_fu_159_p1 = esl_zext<32,4>(col_reg_84.read());
}

void Conv2d_1::thread_i_fu_173_p2() {
    i_fu_173_p2 = (!col_reg_84.read().is_01() || !ap_const_lv4_1.is_01())? sc_lv<4>(): (sc_biguint<4>(col_reg_84.read()) + sc_biguint<4>(ap_const_lv4_1));
}

void Conv2d_1::thread_icmp_ln28_fu_167_p2() {
    icmp_ln28_fu_167_p2 = (!col_reg_84.read().is_01() || !ap_const_lv4_E.is_01())? sc_lv<1>(): sc_lv<1>(col_reg_84.read() == ap_const_lv4_E);
}

void Conv2d_1::thread_icmp_ln29_fu_231_p2() {
    icmp_ln29_fu_231_p2 = (!row_reg_95.read().is_01() || !ap_const_lv4_E.is_01())? sc_lv<1>(): sc_lv<1>(row_reg_95.read() == ap_const_lv4_E);
}

void Conv2d_1::thread_icmp_ln31_fu_267_p2() {
    icmp_ln31_fu_267_p2 = (!col_0_reg_118.read().is_01() || !zext_ln31_reg_355.read().is_01())? sc_lv<1>(): (sc_bigint<32>(col_0_reg_118.read()) < sc_bigint<32>(zext_ln31_reg_355.read()));
}

void Conv2d_1::thread_icmp_ln32_fu_300_p2() {
    icmp_ln32_fu_300_p2 = (!row_0_reg_140.read().is_01() || !zext_ln32_9_reg_379.read().is_01())? sc_lv<1>(): (sc_bigint<32>(row_0_reg_140.read()) < sc_bigint<32>(zext_ln32_9_reg_379.read()));
}

void Conv2d_1::thread_input_matrix_address0() {
    input_matrix_address0 =  (sc_lv<8>) (sext_ln33_fu_310_p1.read());
}

void Conv2d_1::thread_input_matrix_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        input_matrix_ce0 = ap_const_logic_1;
    } else {
        input_matrix_ce0 = ap_const_logic_0;
    }
}

void Conv2d_1::thread_j_fu_237_p2() {
    j_fu_237_p2 = (!row_reg_95.read().is_01() || !ap_const_lv4_1.is_01())? sc_lv<4>(): (sc_biguint<4>(row_reg_95.read()) + sc_biguint<4>(ap_const_lv4_1));
}

void Conv2d_1::thread_kernel_address0() {
    kernel_address0 =  (sc_lv<4>) (sext_ln33_1_fu_332_p1.read());
}

void Conv2d_1::thread_kernel_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read())) {
        kernel_ce0 = ap_const_logic_1;
    } else {
        kernel_ce0 = ap_const_logic_0;
    }
}

void Conv2d_1::thread_out_matrix_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state16.read())) {
        out_matrix_address0 = out_matrix_addr_reg_374.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        out_matrix_address0 =  (sc_lv<8>) (zext_ln30_fu_252_p1.read());
    } else {
        out_matrix_address0 = "XXXXXXXX";
    }
}

void Conv2d_1::thread_out_matrix_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state16.read()))) {
        out_matrix_ce0 = ap_const_logic_1;
    } else {
        out_matrix_ce0 = ap_const_logic_0;
    }
}

void Conv2d_1::thread_out_matrix_d0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state16.read())) {
        out_matrix_d0 = tmp_s_reg_440.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        out_matrix_d0 = ap_const_lv32_0;
    } else {
        out_matrix_d0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void Conv2d_1::thread_out_matrix_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln29_fu_231_p2.read())) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state16.read()))) {
        out_matrix_we0 = ap_const_logic_1;
    } else {
        out_matrix_we0 = ap_const_logic_0;
    }
}

void Conv2d_1::thread_row_6_fu_320_p2() {
    row_6_fu_320_p2 = (!row_0_reg_140.read().is_01() || !ap_const_lv32_1.is_01())? sc_lv<32>(): (sc_biguint<32>(row_0_reg_140.read()) + sc_biguint<32>(ap_const_lv32_1));
}

void Conv2d_1::thread_sext_ln30_fu_248_p1() {
    sext_ln30_fu_248_p1 = esl_sext<32,9>(add_ln30_fu_243_p2.read());
}

void Conv2d_1::thread_sext_ln33_1_fu_332_p1() {
    sext_ln33_1_fu_332_p1 = esl_sext<64,32>(add_ln33_2_reg_405.read());
}

void Conv2d_1::thread_sext_ln33_fu_310_p1() {
    sext_ln33_fu_310_p1 = esl_sext<64,32>(add_ln33_fu_305_p2.read());
}

void Conv2d_1::thread_shl_ln30_3_fu_191_p3() {
    shl_ln30_3_fu_191_p3 = esl_concat<4,1>(col_reg_84.read(), ap_const_lv1_0);
}

void Conv2d_1::thread_shl_ln33_5_fu_283_p2() {
    shl_ln33_5_fu_283_p2 = (!ap_const_lv32_2.is_01())? sc_lv<32>(): sub_ln33_fu_278_p2.read() << (unsigned short)ap_const_lv32_2.to_uint();
}

void Conv2d_1::thread_shl_ln33_fu_272_p2() {
    shl_ln33_fu_272_p2 = (!ap_const_lv32_4.is_01())? sc_lv<32>(): col_0_reg_118.read() << (unsigned short)ap_const_lv32_4.to_uint();
}

void Conv2d_1::thread_shl_ln_fu_179_p3() {
    shl_ln_fu_179_p3 = esl_concat<4,4>(col_reg_84.read(), ap_const_lv4_0);
}

void Conv2d_1::thread_sub_ln30_fu_203_p2() {
    sub_ln30_fu_203_p2 = (!zext_ln30_6_fu_187_p1.read().is_01() || !zext_ln30_7_fu_199_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(zext_ln30_6_fu_187_p1.read()) - sc_biguint<9>(zext_ln30_7_fu_199_p1.read()));
}

void Conv2d_1::thread_sub_ln33_4_fu_295_p2() {
    sub_ln33_4_fu_295_p2 = (!sub_ln33_8_fu_289_p2.read().is_01() || !zext_ln32_8_reg_360.read().is_01())? sc_lv<32>(): (sc_biguint<32>(sub_ln33_8_fu_289_p2.read()) - sc_biguint<32>(zext_ln32_8_reg_360.read()));
}

void Conv2d_1::thread_sub_ln33_8_fu_289_p2() {
    sub_ln33_8_fu_289_p2 = (!shl_ln33_5_fu_283_p2.read().is_01() || !sub_ln33_fu_278_p2.read().is_01())? sc_lv<32>(): (sc_biguint<32>(shl_ln33_5_fu_283_p2.read()) - sc_biguint<32>(sub_ln33_fu_278_p2.read()));
}

void Conv2d_1::thread_sub_ln33_fu_278_p2() {
    sub_ln33_fu_278_p2 = (!col_0_reg_118.read().is_01() || !col_cast4_reg_336.read().is_01())? sc_lv<32>(): (sc_biguint<32>(col_0_reg_118.read()) - sc_biguint<32>(col_cast4_reg_336.read()));
}

void Conv2d_1::thread_zext_ln30_6_fu_187_p1() {
    zext_ln30_6_fu_187_p1 = esl_zext<9,8>(shl_ln_fu_179_p3.read());
}

void Conv2d_1::thread_zext_ln30_7_fu_199_p1() {
    zext_ln30_7_fu_199_p1 = esl_zext<9,5>(shl_ln30_3_fu_191_p3.read());
}

void Conv2d_1::thread_zext_ln30_fu_252_p1() {
    zext_ln30_fu_252_p1 = esl_zext<64,32>(sext_ln30_fu_248_p1.read());
}

void Conv2d_1::thread_zext_ln31_fu_215_p1() {
    zext_ln31_fu_215_p1 = esl_zext<32,5>(add_ln31_fu_209_p2.read());
}

void Conv2d_1::thread_zext_ln32_7_fu_223_p1() {
    zext_ln32_7_fu_223_p1 = esl_zext<9,4>(row_reg_95.read());
}

void Conv2d_1::thread_zext_ln32_8_fu_227_p1() {
    zext_ln32_8_fu_227_p1 = esl_zext<32,4>(row_reg_95.read());
}

void Conv2d_1::thread_zext_ln32_9_fu_263_p1() {
    zext_ln32_9_fu_263_p1 = esl_zext<32,5>(add_ln32_fu_257_p2.read());
}

void Conv2d_1::thread_zext_ln32_fu_219_p1() {
    zext_ln32_fu_219_p1 = esl_zext<5,4>(row_reg_95.read());
}

void Conv2d_1::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && esl_seteq<1,1,1>(icmp_ln28_fu_167_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state1;
            } else {
                ap_NS_fsm = ap_ST_fsm_state3;
            }
            break;
        case 4 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && esl_seteq<1,1,1>(icmp_ln29_fu_231_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state4;
            }
            break;
        case 8 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln31_fu_267_p2.read()))) {
                ap_NS_fsm = ap_ST_fsm_state3;
            } else {
                ap_NS_fsm = ap_ST_fsm_state5;
            }
            break;
        case 16 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln32_fu_300_p2.read()))) {
                ap_NS_fsm = ap_ST_fsm_state4;
            } else {
                ap_NS_fsm = ap_ST_fsm_state6;
            }
            break;
        case 32 : 
            ap_NS_fsm = ap_ST_fsm_state7;
            break;
        case 64 : 
            ap_NS_fsm = ap_ST_fsm_state8;
            break;
        case 128 : 
            ap_NS_fsm = ap_ST_fsm_state9;
            break;
        case 256 : 
            ap_NS_fsm = ap_ST_fsm_state10;
            break;
        case 512 : 
            ap_NS_fsm = ap_ST_fsm_state11;
            break;
        case 1024 : 
            ap_NS_fsm = ap_ST_fsm_state12;
            break;
        case 2048 : 
            ap_NS_fsm = ap_ST_fsm_state13;
            break;
        case 4096 : 
            ap_NS_fsm = ap_ST_fsm_state14;
            break;
        case 8192 : 
            ap_NS_fsm = ap_ST_fsm_state15;
            break;
        case 16384 : 
            ap_NS_fsm = ap_ST_fsm_state16;
            break;
        case 32768 : 
            ap_NS_fsm = ap_ST_fsm_state5;
            break;
        default : 
            ap_NS_fsm =  (sc_lv<16>) ("XXXXXXXXXXXXXXXX");
            break;
    }
}

}

