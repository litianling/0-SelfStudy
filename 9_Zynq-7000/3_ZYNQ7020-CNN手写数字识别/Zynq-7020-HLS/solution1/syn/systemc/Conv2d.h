// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#ifndef _Conv2d_HH_
#define _Conv2d_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "forw_back_fadd_32bkb.h"
#include "forw_back_fmul_32cud.h"

namespace ap_rtl {

struct Conv2d : public sc_module {
    // Port declarations 16
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst;
    sc_in< sc_logic > ap_start;
    sc_out< sc_logic > ap_done;
    sc_out< sc_logic > ap_idle;
    sc_out< sc_logic > ap_ready;
    sc_out< sc_lv<10> > input_matrix_address0;
    sc_out< sc_logic > input_matrix_ce0;
    sc_in< sc_lv<32> > input_matrix_q0;
    sc_out< sc_lv<10> > kernel_address0;
    sc_out< sc_logic > kernel_ce0;
    sc_in< sc_lv<32> > kernel_q0;
    sc_out< sc_lv<4> > out_matrix_address0;
    sc_out< sc_logic > out_matrix_ce0;
    sc_out< sc_logic > out_matrix_we0;
    sc_out< sc_lv<32> > out_matrix_d0;
    sc_signal< sc_logic > ap_var_for_const0;


    // Module declarations
    Conv2d(sc_module_name name);
    SC_HAS_PROCESS(Conv2d);

    ~Conv2d();

    sc_trace_file* mVcdFile;

    forw_back_fadd_32bkb<1,5,32,32,32>* forw_back_fadd_32bkb_U74;
    forw_back_fmul_32cud<1,4,32,32,32>* forw_back_fmul_32cud_U75;
    sc_signal< sc_lv<16> > ap_CS_fsm;
    sc_signal< sc_logic > ap_CS_fsm_state1;
    sc_signal< sc_lv<3> > col_cast6_fu_186_p1;
    sc_signal< sc_lv<3> > col_cast6_reg_400;
    sc_signal< sc_logic > ap_CS_fsm_state2;
    sc_signal< sc_lv<4> > col_cast_fu_194_p1;
    sc_signal< sc_lv<4> > col_cast_reg_405;
    sc_signal< sc_lv<2> > i_fu_204_p2;
    sc_signal< sc_lv<2> > i_reg_413;
    sc_signal< sc_lv<5> > sub_ln30_fu_222_p2;
    sc_signal< sc_lv<5> > sub_ln30_reg_418;
    sc_signal< sc_lv<1> > icmp_ln28_fu_198_p2;
    sc_signal< sc_lv<3> > zext_ln32_10_fu_232_p1;
    sc_signal< sc_lv<3> > zext_ln32_10_reg_423;
    sc_signal< sc_logic > ap_CS_fsm_state3;
    sc_signal< sc_lv<9> > zext_ln32_11_fu_236_p1;
    sc_signal< sc_lv<9> > zext_ln32_11_reg_428;
    sc_signal< sc_lv<2> > j_fu_246_p2;
    sc_signal< sc_lv<2> > j_reg_436;
    sc_signal< sc_lv<4> > out_matrix_addr_reg_441;
    sc_signal< sc_lv<1> > icmp_ln29_fu_240_p2;
    sc_signal< sc_lv<3> > add_ln28_fu_266_p2;
    sc_signal< sc_lv<9> > sub_ln33_9_fu_306_p2;
    sc_signal< sc_lv<9> > sub_ln33_9_reg_454;
    sc_signal< sc_logic > ap_CS_fsm_state4;
    sc_signal< sc_lv<1> > icmp_ln31_fu_276_p2;
    sc_signal< sc_lv<9> > sub_ln33_5_fu_343_p2;
    sc_signal< sc_lv<9> > sub_ln33_5_reg_459;
    sc_signal< sc_lv<3> > add_ln29_fu_348_p2;
    sc_signal< sc_logic > ap_CS_fsm_state5;
    sc_signal< sc_lv<1> > icmp_ln32_fu_358_p2;
    sc_signal< sc_lv<3> > row_7_fu_388_p2;
    sc_signal< sc_lv<3> > row_7_reg_482;
    sc_signal< sc_lv<3> > col_7_fu_394_p2;
    sc_signal< sc_lv<32> > input_matrix_load_reg_492;
    sc_signal< sc_logic > ap_CS_fsm_state6;
    sc_signal< sc_lv<32> > kernel_load_reg_497;
    sc_signal< sc_lv<32> > grp_fu_182_p2;
    sc_signal< sc_lv<32> > tmp_reg_502;
    sc_signal< sc_logic > ap_CS_fsm_state10;
    sc_signal< sc_lv<32> > grp_fu_177_p2;
    sc_signal< sc_lv<32> > tmp_s_reg_507;
    sc_signal< sc_logic > ap_CS_fsm_state15;
    sc_signal< sc_lv<3> > indvars_iv5_reg_88;
    sc_signal< sc_lv<2> > col_reg_100;
    sc_signal< sc_lv<3> > indvars_iv_reg_111;
    sc_signal< sc_lv<2> > row_reg_123;
    sc_signal< sc_lv<32> > empty_162_reg_134;
    sc_signal< sc_lv<3> > col_0_reg_146;
    sc_signal< sc_lv<32> > empty_164_reg_156;
    sc_signal< sc_logic > ap_CS_fsm_state16;
    sc_signal< sc_lv<3> > row_0_reg_168;
    sc_signal< sc_lv<64> > zext_ln30_fu_261_p1;
    sc_signal< sc_lv<64> > zext_ln33_fu_373_p1;
    sc_signal< sc_lv<64> > sext_ln33_1_fu_383_p1;
    sc_signal< sc_logic > ap_CS_fsm_state11;
    sc_signal< sc_logic > ap_CS_fsm_state7;
    sc_signal< sc_lv<4> > shl_ln_fu_210_p3;
    sc_signal< sc_lv<5> > zext_ln30_8_fu_218_p1;
    sc_signal< sc_lv<5> > col_cast5_fu_190_p1;
    sc_signal< sc_lv<5> > zext_ln32_fu_228_p1;
    sc_signal< sc_lv<5> > add_ln30_fu_252_p2;
    sc_signal< sc_lv<32> > sext_ln30_fu_257_p1;
    sc_signal< sc_lv<8> > shl_ln2_fu_282_p3;
    sc_signal< sc_lv<4> > shl_ln33_9_fu_294_p3;
    sc_signal< sc_lv<9> > zext_ln33_3_fu_290_p1;
    sc_signal< sc_lv<9> > zext_ln33_4_fu_302_p1;
    sc_signal< sc_lv<4> > col_0_cast2_fu_272_p1;
    sc_signal< sc_lv<4> > sub_ln33_fu_312_p2;
    sc_signal< sc_lv<6> > shl_ln33_1_fu_325_p3;
    sc_signal< sc_lv<9> > shl_ln33_s_fu_317_p3;
    sc_signal< sc_lv<9> > sext_ln33_fu_333_p1;
    sc_signal< sc_lv<9> > sub_ln33_10_fu_337_p2;
    sc_signal< sc_lv<9> > row_0_cast_fu_354_p1;
    sc_signal< sc_lv<9> > add_ln33_fu_364_p2;
    sc_signal< sc_lv<32> > sext_ln33_3_fu_369_p1;
    sc_signal< sc_lv<9> > add_ln33_2_fu_378_p2;
    sc_signal< sc_lv<16> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<16> ap_ST_fsm_state1;
    static const sc_lv<16> ap_ST_fsm_state2;
    static const sc_lv<16> ap_ST_fsm_state3;
    static const sc_lv<16> ap_ST_fsm_state4;
    static const sc_lv<16> ap_ST_fsm_state5;
    static const sc_lv<16> ap_ST_fsm_state6;
    static const sc_lv<16> ap_ST_fsm_state7;
    static const sc_lv<16> ap_ST_fsm_state8;
    static const sc_lv<16> ap_ST_fsm_state9;
    static const sc_lv<16> ap_ST_fsm_state10;
    static const sc_lv<16> ap_ST_fsm_state11;
    static const sc_lv<16> ap_ST_fsm_state12;
    static const sc_lv<16> ap_ST_fsm_state13;
    static const sc_lv<16> ap_ST_fsm_state14;
    static const sc_lv<16> ap_ST_fsm_state15;
    static const sc_lv<16> ap_ST_fsm_state16;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<1> ap_const_lv1_1;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_4;
    static const sc_lv<32> ap_const_lv32_5;
    static const sc_lv<32> ap_const_lv32_9;
    static const sc_lv<32> ap_const_lv32_E;
    static const sc_lv<3> ap_const_lv3_3;
    static const sc_lv<2> ap_const_lv2_0;
    static const sc_lv<32> ap_const_lv32_F;
    static const sc_lv<32> ap_const_lv32_A;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<3> ap_const_lv3_6;
    static const sc_lv<2> ap_const_lv2_1;
    static const sc_lv<3> ap_const_lv3_1;
    static const sc_lv<5> ap_const_lv5_0;
    static const bool ap_const_boolean_1;
    // Thread declarations
    void thread_ap_var_for_const0();
    void thread_ap_clk_no_reset_();
    void thread_add_ln28_fu_266_p2();
    void thread_add_ln29_fu_348_p2();
    void thread_add_ln30_fu_252_p2();
    void thread_add_ln33_2_fu_378_p2();
    void thread_add_ln33_fu_364_p2();
    void thread_ap_CS_fsm_state1();
    void thread_ap_CS_fsm_state10();
    void thread_ap_CS_fsm_state11();
    void thread_ap_CS_fsm_state15();
    void thread_ap_CS_fsm_state16();
    void thread_ap_CS_fsm_state2();
    void thread_ap_CS_fsm_state3();
    void thread_ap_CS_fsm_state4();
    void thread_ap_CS_fsm_state5();
    void thread_ap_CS_fsm_state6();
    void thread_ap_CS_fsm_state7();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_col_0_cast2_fu_272_p1();
    void thread_col_7_fu_394_p2();
    void thread_col_cast5_fu_190_p1();
    void thread_col_cast6_fu_186_p1();
    void thread_col_cast_fu_194_p1();
    void thread_i_fu_204_p2();
    void thread_icmp_ln28_fu_198_p2();
    void thread_icmp_ln29_fu_240_p2();
    void thread_icmp_ln31_fu_276_p2();
    void thread_icmp_ln32_fu_358_p2();
    void thread_input_matrix_address0();
    void thread_input_matrix_ce0();
    void thread_j_fu_246_p2();
    void thread_kernel_address0();
    void thread_kernel_ce0();
    void thread_out_matrix_address0();
    void thread_out_matrix_ce0();
    void thread_out_matrix_d0();
    void thread_out_matrix_we0();
    void thread_row_0_cast_fu_354_p1();
    void thread_row_7_fu_388_p2();
    void thread_sext_ln30_fu_257_p1();
    void thread_sext_ln33_1_fu_383_p1();
    void thread_sext_ln33_3_fu_369_p1();
    void thread_sext_ln33_fu_333_p1();
    void thread_shl_ln2_fu_282_p3();
    void thread_shl_ln33_1_fu_325_p3();
    void thread_shl_ln33_9_fu_294_p3();
    void thread_shl_ln33_s_fu_317_p3();
    void thread_shl_ln_fu_210_p3();
    void thread_sub_ln30_fu_222_p2();
    void thread_sub_ln33_10_fu_337_p2();
    void thread_sub_ln33_5_fu_343_p2();
    void thread_sub_ln33_9_fu_306_p2();
    void thread_sub_ln33_fu_312_p2();
    void thread_zext_ln30_8_fu_218_p1();
    void thread_zext_ln30_fu_261_p1();
    void thread_zext_ln32_10_fu_232_p1();
    void thread_zext_ln32_11_fu_236_p1();
    void thread_zext_ln32_fu_228_p1();
    void thread_zext_ln33_3_fu_290_p1();
    void thread_zext_ln33_4_fu_302_p1();
    void thread_zext_ln33_fu_373_p1();
    void thread_ap_NS_fsm();
};

}

using namespace ap_rtl;

#endif
