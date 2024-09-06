// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

#include "MaxPooBackPropagatio_1.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

const sc_logic MaxPooBackPropagatio_1::ap_const_logic_1 = sc_dt::Log_1;
const sc_logic MaxPooBackPropagatio_1::ap_const_logic_0 = sc_dt::Log_0;
const sc_lv<8> MaxPooBackPropagatio_1::ap_ST_fsm_state1 = "1";
const sc_lv<8> MaxPooBackPropagatio_1::ap_ST_fsm_state2 = "10";
const sc_lv<8> MaxPooBackPropagatio_1::ap_ST_fsm_state3 = "100";
const sc_lv<8> MaxPooBackPropagatio_1::ap_ST_fsm_state4 = "1000";
const sc_lv<8> MaxPooBackPropagatio_1::ap_ST_fsm_state5 = "10000";
const sc_lv<8> MaxPooBackPropagatio_1::ap_ST_fsm_state6 = "100000";
const sc_lv<8> MaxPooBackPropagatio_1::ap_ST_fsm_state7 = "1000000";
const sc_lv<8> MaxPooBackPropagatio_1::ap_ST_fsm_state8 = "10000000";
const sc_lv<32> MaxPooBackPropagatio_1::ap_const_lv32_0 = "00000000000000000000000000000000";
const sc_lv<32> MaxPooBackPropagatio_1::ap_const_lv32_1 = "1";
const sc_lv<1> MaxPooBackPropagatio_1::ap_const_lv1_0 = "0";
const sc_lv<32> MaxPooBackPropagatio_1::ap_const_lv32_2 = "10";
const sc_lv<32> MaxPooBackPropagatio_1::ap_const_lv32_3 = "11";
const sc_lv<32> MaxPooBackPropagatio_1::ap_const_lv32_4 = "100";
const sc_lv<32> MaxPooBackPropagatio_1::ap_const_lv32_5 = "101";
const sc_lv<32> MaxPooBackPropagatio_1::ap_const_lv32_6 = "110";
const sc_lv<5> MaxPooBackPropagatio_1::ap_const_lv5_0 = "00000";
const sc_lv<1> MaxPooBackPropagatio_1::ap_const_lv1_1 = "1";
const sc_lv<4> MaxPooBackPropagatio_1::ap_const_lv4_0 = "0000";
const sc_lv<32> MaxPooBackPropagatio_1::ap_const_lv32_7 = "111";
const sc_lv<5> MaxPooBackPropagatio_1::ap_const_lv5_1C = "11100";
const sc_lv<5> MaxPooBackPropagatio_1::ap_const_lv5_1 = "1";
const sc_lv<2> MaxPooBackPropagatio_1::ap_const_lv2_0 = "00";
const sc_lv<4> MaxPooBackPropagatio_1::ap_const_lv4_E = "1110";
const sc_lv<4> MaxPooBackPropagatio_1::ap_const_lv4_1 = "1";
const sc_lv<32> MaxPooBackPropagatio_1::ap_const_lv32_1F = "11111";
const sc_lv<32> MaxPooBackPropagatio_1::ap_const_lv32_17 = "10111";
const sc_lv<32> MaxPooBackPropagatio_1::ap_const_lv32_1E = "11110";
const sc_lv<9> MaxPooBackPropagatio_1::ap_const_lv9_181 = "110000001";
const sc_lv<32> MaxPooBackPropagatio_1::ap_const_lv32_8 = "1000";
const sc_lv<8> MaxPooBackPropagatio_1::ap_const_lv8_7F = "1111111";
const sc_lv<32> MaxPooBackPropagatio_1::ap_const_lv32_18 = "11000";
const sc_lv<32> MaxPooBackPropagatio_1::ap_const_lv32_37 = "110111";
const bool MaxPooBackPropagatio_1::ap_const_boolean_1 = true;

MaxPooBackPropagatio_1::MaxPooBackPropagatio_1(sc_module_name name) : sc_module(name), mVcdFile(0) {

    SC_METHOD(thread_ap_clk_no_reset_);
    dont_initialize();
    sensitive << ( ap_clk.pos() );

    SC_METHOD(thread_add_ln101_fu_294_p2);
    sensitive << ( sub_ln101_reg_483 );
    sensitive << ( j_0_cast_fu_278_p1 );

    SC_METHOD(thread_add_ln339_fu_352_p2);
    sensitive << ( zext_ln339_fu_348_p1 );

    SC_METHOD(thread_add_ln97_fu_222_p2);
    sensitive << ( sub_ln97_reg_462 );
    sensitive << ( low_0_cast_fu_206_p1 );

    SC_METHOD(thread_ap_CS_fsm_state1);
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

    SC_METHOD(thread_ap_CS_fsm_state8);
    sensitive << ( ap_CS_fsm );

    SC_METHOD(thread_ap_done);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( icmp_ln99_fu_236_p2 );

    SC_METHOD(thread_ap_idle);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm_state1 );

    SC_METHOD(thread_ap_ready);
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( icmp_ln99_fu_236_p2 );

    SC_METHOD(thread_col_fu_170_p2);
    sensitive << ( col_0_reg_120 );

    SC_METHOD(thread_i_fu_242_p2);
    sensitive << ( i_0_reg_142 );

    SC_METHOD(thread_icmp_ln100_fu_282_p2);
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( j_0_reg_153 );

    SC_METHOD(thread_icmp_ln95_fu_164_p2);
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( col_0_reg_120 );

    SC_METHOD(thread_icmp_ln96_fu_210_p2);
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( low_0_reg_131 );

    SC_METHOD(thread_icmp_ln99_fu_236_p2);
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( i_0_reg_142 );

    SC_METHOD(thread_input_matrix_address0);
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( zext_ln101_fu_303_p1 );

    SC_METHOD(thread_input_matrix_ce0);
    sensitive << ( ap_CS_fsm_state5 );

    SC_METHOD(thread_isNeg_fu_358_p3);
    sensitive << ( add_ln339_fu_352_p2 );

    SC_METHOD(thread_j_0_cast_fu_278_p1);
    sensitive << ( j_0_reg_153 );

    SC_METHOD(thread_j_fu_288_p2);
    sensitive << ( j_0_reg_153 );

    SC_METHOD(thread_low_0_cast_fu_206_p1);
    sensitive << ( low_0_reg_131 );

    SC_METHOD(thread_low_fu_216_p2);
    sensitive << ( low_0_reg_131 );

    SC_METHOD(thread_mantissa_V_fu_334_p4);
    sensitive << ( tmp_V_3_fu_330_p1 );

    SC_METHOD(thread_max_poo_locate_1_address0);
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( zext_ln101_fu_303_p1 );

    SC_METHOD(thread_max_poo_locate_1_ce0);
    sensitive << ( ap_CS_fsm_state5 );

    SC_METHOD(thread_output_matrix_address0);
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( ap_CS_fsm_state8 );
    sensitive << ( zext_ln97_fu_231_p1 );
    sensitive << ( sext_ln102_fu_449_p1 );

    SC_METHOD(thread_output_matrix_ce0);
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( ap_CS_fsm_state8 );

    SC_METHOD(thread_output_matrix_d0);
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( input_matrix_load_reg_511 );
    sensitive << ( ap_CS_fsm_state8 );

    SC_METHOD(thread_output_matrix_we0);
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( icmp_ln96_fu_210_p2 );
    sensitive << ( ap_CS_fsm_state8 );

    SC_METHOD(thread_p_Val2_17_fu_430_p3);
    sensitive << ( isNeg_fu_358_p3 );
    sensitive << ( zext_ln662_fu_416_p1 );
    sensitive << ( tmp_12_fu_420_p4 );

    SC_METHOD(thread_p_Val2_18_fu_443_p3);
    sensitive << ( p_Result_s_reg_516 );
    sensitive << ( p_Val2_17_reg_521 );
    sensitive << ( result_V_3_fu_438_p2 );

    SC_METHOD(thread_p_Val2_s_fu_309_p1);
    sensitive << ( max_poo_locate_1_loa_reg_506 );

    SC_METHOD(thread_r_V_3_fu_402_p2);
    sensitive << ( zext_ln682_fu_344_p1 );
    sensitive << ( zext_ln1287_fu_392_p1 );

    SC_METHOD(thread_r_V_fu_396_p2);
    sensitive << ( mantissa_V_fu_334_p4 );
    sensitive << ( sext_ln1311_4_fu_388_p1 );

    SC_METHOD(thread_result_V_3_fu_438_p2);
    sensitive << ( p_Val2_17_reg_521 );

    SC_METHOD(thread_sext_ln101_fu_299_p1);
    sensitive << ( add_ln101_fu_294_p2 );

    SC_METHOD(thread_sext_ln102_fu_449_p1);
    sensitive << ( p_Val2_18_fu_443_p3 );

    SC_METHOD(thread_sext_ln1311_3_fu_384_p1);
    sensitive << ( ush_fu_376_p3 );

    SC_METHOD(thread_sext_ln1311_4_fu_388_p1);
    sensitive << ( ush_fu_376_p3 );

    SC_METHOD(thread_sext_ln1311_fu_372_p1);
    sensitive << ( sub_ln1311_fu_366_p2 );

    SC_METHOD(thread_sext_ln97_fu_227_p1);
    sensitive << ( add_ln97_fu_222_p2 );

    SC_METHOD(thread_shl_ln101_2_fu_260_p3);
    sensitive << ( i_0_reg_142 );

    SC_METHOD(thread_shl_ln8_fu_248_p3);
    sensitive << ( i_0_reg_142 );

    SC_METHOD(thread_shl_ln97_2_fu_188_p3);
    sensitive << ( col_0_reg_120 );

    SC_METHOD(thread_shl_ln_fu_176_p3);
    sensitive << ( col_0_reg_120 );

    SC_METHOD(thread_sub_ln101_fu_272_p2);
    sensitive << ( zext_ln101_1_fu_256_p1 );
    sensitive << ( zext_ln101_2_fu_268_p1 );

    SC_METHOD(thread_sub_ln1311_fu_366_p2);
    sensitive << ( tmp_V_fu_320_p4 );

    SC_METHOD(thread_sub_ln97_fu_200_p2);
    sensitive << ( zext_ln97_1_fu_184_p1 );
    sensitive << ( zext_ln97_2_fu_196_p1 );

    SC_METHOD(thread_tmp_12_fu_420_p4);
    sensitive << ( r_V_3_fu_402_p2 );

    SC_METHOD(thread_tmp_V_3_fu_330_p1);
    sensitive << ( p_Val2_s_fu_309_p1 );

    SC_METHOD(thread_tmp_V_fu_320_p4);
    sensitive << ( p_Val2_s_fu_309_p1 );

    SC_METHOD(thread_tmp_fu_408_p3);
    sensitive << ( r_V_fu_396_p2 );

    SC_METHOD(thread_ush_fu_376_p3);
    sensitive << ( add_ln339_fu_352_p2 );
    sensitive << ( isNeg_fu_358_p3 );
    sensitive << ( sext_ln1311_fu_372_p1 );

    SC_METHOD(thread_zext_ln101_1_fu_256_p1);
    sensitive << ( shl_ln8_fu_248_p3 );

    SC_METHOD(thread_zext_ln101_2_fu_268_p1);
    sensitive << ( shl_ln101_2_fu_260_p3 );

    SC_METHOD(thread_zext_ln101_fu_303_p1);
    sensitive << ( sext_ln101_fu_299_p1 );

    SC_METHOD(thread_zext_ln1287_fu_392_p1);
    sensitive << ( sext_ln1311_3_fu_384_p1 );

    SC_METHOD(thread_zext_ln339_fu_348_p1);
    sensitive << ( tmp_V_fu_320_p4 );

    SC_METHOD(thread_zext_ln662_fu_416_p1);
    sensitive << ( tmp_fu_408_p3 );

    SC_METHOD(thread_zext_ln682_fu_344_p1);
    sensitive << ( mantissa_V_fu_334_p4 );

    SC_METHOD(thread_zext_ln97_1_fu_184_p1);
    sensitive << ( shl_ln_fu_176_p3 );

    SC_METHOD(thread_zext_ln97_2_fu_196_p1);
    sensitive << ( shl_ln97_2_fu_188_p3 );

    SC_METHOD(thread_zext_ln97_fu_231_p1);
    sensitive << ( sext_ln97_fu_227_p1 );

    SC_METHOD(thread_ap_NS_fsm);
    sensitive << ( ap_start );
    sensitive << ( ap_CS_fsm );
    sensitive << ( ap_CS_fsm_state1 );
    sensitive << ( ap_CS_fsm_state2 );
    sensitive << ( icmp_ln95_fu_164_p2 );
    sensitive << ( ap_CS_fsm_state3 );
    sensitive << ( ap_CS_fsm_state4 );
    sensitive << ( icmp_ln99_fu_236_p2 );
    sensitive << ( ap_CS_fsm_state5 );
    sensitive << ( icmp_ln100_fu_282_p2 );
    sensitive << ( icmp_ln96_fu_210_p2 );

    ap_CS_fsm = "00000001";
    static int apTFileNum = 0;
    stringstream apTFilenSS;
    apTFilenSS << "MaxPooBackPropagatio_1_sc_trace_" << apTFileNum ++;
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
    sc_trace(mVcdFile, output_matrix_address0, "(port)output_matrix_address0");
    sc_trace(mVcdFile, output_matrix_ce0, "(port)output_matrix_ce0");
    sc_trace(mVcdFile, output_matrix_we0, "(port)output_matrix_we0");
    sc_trace(mVcdFile, output_matrix_d0, "(port)output_matrix_d0");
    sc_trace(mVcdFile, max_poo_locate_1_address0, "(port)max_poo_locate_1_address0");
    sc_trace(mVcdFile, max_poo_locate_1_ce0, "(port)max_poo_locate_1_ce0");
    sc_trace(mVcdFile, max_poo_locate_1_q0, "(port)max_poo_locate_1_q0");
#endif
#ifdef __HLS_TRACE_LEVEL_INT__
    sc_trace(mVcdFile, ap_CS_fsm, "ap_CS_fsm");
    sc_trace(mVcdFile, ap_CS_fsm_state1, "ap_CS_fsm_state1");
    sc_trace(mVcdFile, col_fu_170_p2, "col_fu_170_p2");
    sc_trace(mVcdFile, col_reg_457, "col_reg_457");
    sc_trace(mVcdFile, ap_CS_fsm_state2, "ap_CS_fsm_state2");
    sc_trace(mVcdFile, sub_ln97_fu_200_p2, "sub_ln97_fu_200_p2");
    sc_trace(mVcdFile, sub_ln97_reg_462, "sub_ln97_reg_462");
    sc_trace(mVcdFile, icmp_ln95_fu_164_p2, "icmp_ln95_fu_164_p2");
    sc_trace(mVcdFile, low_fu_216_p2, "low_fu_216_p2");
    sc_trace(mVcdFile, ap_CS_fsm_state3, "ap_CS_fsm_state3");
    sc_trace(mVcdFile, i_fu_242_p2, "i_fu_242_p2");
    sc_trace(mVcdFile, i_reg_478, "i_reg_478");
    sc_trace(mVcdFile, ap_CS_fsm_state4, "ap_CS_fsm_state4");
    sc_trace(mVcdFile, sub_ln101_fu_272_p2, "sub_ln101_fu_272_p2");
    sc_trace(mVcdFile, sub_ln101_reg_483, "sub_ln101_reg_483");
    sc_trace(mVcdFile, icmp_ln99_fu_236_p2, "icmp_ln99_fu_236_p2");
    sc_trace(mVcdFile, j_fu_288_p2, "j_fu_288_p2");
    sc_trace(mVcdFile, j_reg_491, "j_reg_491");
    sc_trace(mVcdFile, ap_CS_fsm_state5, "ap_CS_fsm_state5");
    sc_trace(mVcdFile, icmp_ln100_fu_282_p2, "icmp_ln100_fu_282_p2");
    sc_trace(mVcdFile, max_poo_locate_1_loa_reg_506, "max_poo_locate_1_loa_reg_506");
    sc_trace(mVcdFile, ap_CS_fsm_state6, "ap_CS_fsm_state6");
    sc_trace(mVcdFile, input_matrix_load_reg_511, "input_matrix_load_reg_511");
    sc_trace(mVcdFile, p_Result_s_reg_516, "p_Result_s_reg_516");
    sc_trace(mVcdFile, ap_CS_fsm_state7, "ap_CS_fsm_state7");
    sc_trace(mVcdFile, p_Val2_17_fu_430_p3, "p_Val2_17_fu_430_p3");
    sc_trace(mVcdFile, p_Val2_17_reg_521, "p_Val2_17_reg_521");
    sc_trace(mVcdFile, col_0_reg_120, "col_0_reg_120");
    sc_trace(mVcdFile, icmp_ln96_fu_210_p2, "icmp_ln96_fu_210_p2");
    sc_trace(mVcdFile, low_0_reg_131, "low_0_reg_131");
    sc_trace(mVcdFile, i_0_reg_142, "i_0_reg_142");
    sc_trace(mVcdFile, j_0_reg_153, "j_0_reg_153");
    sc_trace(mVcdFile, ap_CS_fsm_state8, "ap_CS_fsm_state8");
    sc_trace(mVcdFile, zext_ln97_fu_231_p1, "zext_ln97_fu_231_p1");
    sc_trace(mVcdFile, zext_ln101_fu_303_p1, "zext_ln101_fu_303_p1");
    sc_trace(mVcdFile, sext_ln102_fu_449_p1, "sext_ln102_fu_449_p1");
    sc_trace(mVcdFile, shl_ln_fu_176_p3, "shl_ln_fu_176_p3");
    sc_trace(mVcdFile, shl_ln97_2_fu_188_p3, "shl_ln97_2_fu_188_p3");
    sc_trace(mVcdFile, zext_ln97_1_fu_184_p1, "zext_ln97_1_fu_184_p1");
    sc_trace(mVcdFile, zext_ln97_2_fu_196_p1, "zext_ln97_2_fu_196_p1");
    sc_trace(mVcdFile, low_0_cast_fu_206_p1, "low_0_cast_fu_206_p1");
    sc_trace(mVcdFile, add_ln97_fu_222_p2, "add_ln97_fu_222_p2");
    sc_trace(mVcdFile, sext_ln97_fu_227_p1, "sext_ln97_fu_227_p1");
    sc_trace(mVcdFile, shl_ln8_fu_248_p3, "shl_ln8_fu_248_p3");
    sc_trace(mVcdFile, shl_ln101_2_fu_260_p3, "shl_ln101_2_fu_260_p3");
    sc_trace(mVcdFile, zext_ln101_1_fu_256_p1, "zext_ln101_1_fu_256_p1");
    sc_trace(mVcdFile, zext_ln101_2_fu_268_p1, "zext_ln101_2_fu_268_p1");
    sc_trace(mVcdFile, j_0_cast_fu_278_p1, "j_0_cast_fu_278_p1");
    sc_trace(mVcdFile, add_ln101_fu_294_p2, "add_ln101_fu_294_p2");
    sc_trace(mVcdFile, sext_ln101_fu_299_p1, "sext_ln101_fu_299_p1");
    sc_trace(mVcdFile, p_Val2_s_fu_309_p1, "p_Val2_s_fu_309_p1");
    sc_trace(mVcdFile, tmp_V_3_fu_330_p1, "tmp_V_3_fu_330_p1");
    sc_trace(mVcdFile, mantissa_V_fu_334_p4, "mantissa_V_fu_334_p4");
    sc_trace(mVcdFile, tmp_V_fu_320_p4, "tmp_V_fu_320_p4");
    sc_trace(mVcdFile, zext_ln339_fu_348_p1, "zext_ln339_fu_348_p1");
    sc_trace(mVcdFile, add_ln339_fu_352_p2, "add_ln339_fu_352_p2");
    sc_trace(mVcdFile, sub_ln1311_fu_366_p2, "sub_ln1311_fu_366_p2");
    sc_trace(mVcdFile, isNeg_fu_358_p3, "isNeg_fu_358_p3");
    sc_trace(mVcdFile, sext_ln1311_fu_372_p1, "sext_ln1311_fu_372_p1");
    sc_trace(mVcdFile, ush_fu_376_p3, "ush_fu_376_p3");
    sc_trace(mVcdFile, sext_ln1311_3_fu_384_p1, "sext_ln1311_3_fu_384_p1");
    sc_trace(mVcdFile, sext_ln1311_4_fu_388_p1, "sext_ln1311_4_fu_388_p1");
    sc_trace(mVcdFile, zext_ln682_fu_344_p1, "zext_ln682_fu_344_p1");
    sc_trace(mVcdFile, zext_ln1287_fu_392_p1, "zext_ln1287_fu_392_p1");
    sc_trace(mVcdFile, r_V_fu_396_p2, "r_V_fu_396_p2");
    sc_trace(mVcdFile, tmp_fu_408_p3, "tmp_fu_408_p3");
    sc_trace(mVcdFile, r_V_3_fu_402_p2, "r_V_3_fu_402_p2");
    sc_trace(mVcdFile, zext_ln662_fu_416_p1, "zext_ln662_fu_416_p1");
    sc_trace(mVcdFile, tmp_12_fu_420_p4, "tmp_12_fu_420_p4");
    sc_trace(mVcdFile, result_V_3_fu_438_p2, "result_V_3_fu_438_p2");
    sc_trace(mVcdFile, p_Val2_18_fu_443_p3, "p_Val2_18_fu_443_p3");
    sc_trace(mVcdFile, ap_NS_fsm, "ap_NS_fsm");
#endif

    }
}

MaxPooBackPropagatio_1::~MaxPooBackPropagatio_1() {
    if (mVcdFile) 
        sc_close_vcd_trace_file(mVcdFile);

}

void MaxPooBackPropagatio_1::thread_ap_clk_no_reset_() {
    if ( ap_rst.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
         esl_seteq<1,1,1>(icmp_ln96_fu_210_p2.read(), ap_const_lv1_1))) {
        col_0_reg_120 = col_reg_457.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        col_0_reg_120 = ap_const_lv5_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
         esl_seteq<1,1,1>(icmp_ln95_fu_164_p2.read(), ap_const_lv1_1))) {
        i_0_reg_142 = ap_const_lv4_0;
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()) && 
                esl_seteq<1,1,1>(icmp_ln100_fu_282_p2.read(), ap_const_lv1_1))) {
        i_0_reg_142 = i_reg_478.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln99_fu_236_p2.read()))) {
        j_0_reg_153 = ap_const_lv4_0;
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state8.read())) {
        j_0_reg_153 = j_reg_491.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && 
         esl_seteq<1,1,1>(icmp_ln95_fu_164_p2.read(), ap_const_lv1_0))) {
        low_0_reg_131 = ap_const_lv5_0;
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln96_fu_210_p2.read()))) {
        low_0_reg_131 = low_fu_216_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read())) {
        col_reg_457 = col_fu_170_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read())) {
        i_reg_478 = i_fu_242_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state6.read())) {
        input_matrix_load_reg_511 = input_matrix_q0.read();
        max_poo_locate_1_loa_reg_506 = max_poo_locate_1_q0.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        j_reg_491 = j_fu_288_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state7.read())) {
        p_Result_s_reg_516 = p_Val2_s_fu_309_p1.read().range(31, 31);
        p_Val2_17_reg_521 = p_Val2_17_fu_430_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln99_fu_236_p2.read()))) {
        sub_ln101_reg_483 = sub_ln101_fu_272_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && esl_seteq<1,1,1>(icmp_ln95_fu_164_p2.read(), ap_const_lv1_0))) {
        sub_ln97_reg_462 = sub_ln97_fu_200_p2.read();
    }
}

void MaxPooBackPropagatio_1::thread_add_ln101_fu_294_p2() {
    add_ln101_fu_294_p2 = (!j_0_cast_fu_278_p1.read().is_01() || !sub_ln101_reg_483.read().is_01())? sc_lv<9>(): (sc_biguint<9>(j_0_cast_fu_278_p1.read()) + sc_biguint<9>(sub_ln101_reg_483.read()));
}

void MaxPooBackPropagatio_1::thread_add_ln339_fu_352_p2() {
    add_ln339_fu_352_p2 = (!ap_const_lv9_181.is_01() || !zext_ln339_fu_348_p1.read().is_01())? sc_lv<9>(): (sc_bigint<9>(ap_const_lv9_181) + sc_biguint<9>(zext_ln339_fu_348_p1.read()));
}

void MaxPooBackPropagatio_1::thread_add_ln97_fu_222_p2() {
    add_ln97_fu_222_p2 = (!sub_ln97_reg_462.read().is_01() || !low_0_cast_fu_206_p1.read().is_01())? sc_lv<11>(): (sc_biguint<11>(sub_ln97_reg_462.read()) + sc_biguint<11>(low_0_cast_fu_206_p1.read()));
}

void MaxPooBackPropagatio_1::thread_ap_CS_fsm_state1() {
    ap_CS_fsm_state1 = ap_CS_fsm.read()[0];
}

void MaxPooBackPropagatio_1::thread_ap_CS_fsm_state2() {
    ap_CS_fsm_state2 = ap_CS_fsm.read()[1];
}

void MaxPooBackPropagatio_1::thread_ap_CS_fsm_state3() {
    ap_CS_fsm_state3 = ap_CS_fsm.read()[2];
}

void MaxPooBackPropagatio_1::thread_ap_CS_fsm_state4() {
    ap_CS_fsm_state4 = ap_CS_fsm.read()[3];
}

void MaxPooBackPropagatio_1::thread_ap_CS_fsm_state5() {
    ap_CS_fsm_state5 = ap_CS_fsm.read()[4];
}

void MaxPooBackPropagatio_1::thread_ap_CS_fsm_state6() {
    ap_CS_fsm_state6 = ap_CS_fsm.read()[5];
}

void MaxPooBackPropagatio_1::thread_ap_CS_fsm_state7() {
    ap_CS_fsm_state7 = ap_CS_fsm.read()[6];
}

void MaxPooBackPropagatio_1::thread_ap_CS_fsm_state8() {
    ap_CS_fsm_state8 = ap_CS_fsm.read()[7];
}

void MaxPooBackPropagatio_1::thread_ap_done() {
    if (((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && 
          esl_seteq<1,1,1>(icmp_ln99_fu_236_p2.read(), ap_const_lv1_1)))) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void MaxPooBackPropagatio_1::thread_ap_idle() {
    if ((esl_seteq<1,1,1>(ap_const_logic_0, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void MaxPooBackPropagatio_1::thread_ap_ready() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && 
         esl_seteq<1,1,1>(icmp_ln99_fu_236_p2.read(), ap_const_lv1_1))) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void MaxPooBackPropagatio_1::thread_col_fu_170_p2() {
    col_fu_170_p2 = (!col_0_reg_120.read().is_01() || !ap_const_lv5_1.is_01())? sc_lv<5>(): (sc_biguint<5>(col_0_reg_120.read()) + sc_biguint<5>(ap_const_lv5_1));
}

void MaxPooBackPropagatio_1::thread_i_fu_242_p2() {
    i_fu_242_p2 = (!i_0_reg_142.read().is_01() || !ap_const_lv4_1.is_01())? sc_lv<4>(): (sc_biguint<4>(i_0_reg_142.read()) + sc_biguint<4>(ap_const_lv4_1));
}

void MaxPooBackPropagatio_1::thread_icmp_ln100_fu_282_p2() {
    icmp_ln100_fu_282_p2 = (!j_0_reg_153.read().is_01() || !ap_const_lv4_E.is_01())? sc_lv<1>(): sc_lv<1>(j_0_reg_153.read() == ap_const_lv4_E);
}

void MaxPooBackPropagatio_1::thread_icmp_ln95_fu_164_p2() {
    icmp_ln95_fu_164_p2 = (!col_0_reg_120.read().is_01() || !ap_const_lv5_1C.is_01())? sc_lv<1>(): sc_lv<1>(col_0_reg_120.read() == ap_const_lv5_1C);
}

void MaxPooBackPropagatio_1::thread_icmp_ln96_fu_210_p2() {
    icmp_ln96_fu_210_p2 = (!low_0_reg_131.read().is_01() || !ap_const_lv5_1C.is_01())? sc_lv<1>(): sc_lv<1>(low_0_reg_131.read() == ap_const_lv5_1C);
}

void MaxPooBackPropagatio_1::thread_icmp_ln99_fu_236_p2() {
    icmp_ln99_fu_236_p2 = (!i_0_reg_142.read().is_01() || !ap_const_lv4_E.is_01())? sc_lv<1>(): sc_lv<1>(i_0_reg_142.read() == ap_const_lv4_E);
}

void MaxPooBackPropagatio_1::thread_input_matrix_address0() {
    input_matrix_address0 =  (sc_lv<8>) (zext_ln101_fu_303_p1.read());
}

void MaxPooBackPropagatio_1::thread_input_matrix_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        input_matrix_ce0 = ap_const_logic_1;
    } else {
        input_matrix_ce0 = ap_const_logic_0;
    }
}

void MaxPooBackPropagatio_1::thread_isNeg_fu_358_p3() {
    isNeg_fu_358_p3 = add_ln339_fu_352_p2.read().range(8, 8);
}

void MaxPooBackPropagatio_1::thread_j_0_cast_fu_278_p1() {
    j_0_cast_fu_278_p1 = esl_zext<9,4>(j_0_reg_153.read());
}

void MaxPooBackPropagatio_1::thread_j_fu_288_p2() {
    j_fu_288_p2 = (!j_0_reg_153.read().is_01() || !ap_const_lv4_1.is_01())? sc_lv<4>(): (sc_biguint<4>(j_0_reg_153.read()) + sc_biguint<4>(ap_const_lv4_1));
}

void MaxPooBackPropagatio_1::thread_low_0_cast_fu_206_p1() {
    low_0_cast_fu_206_p1 = esl_zext<11,5>(low_0_reg_131.read());
}

void MaxPooBackPropagatio_1::thread_low_fu_216_p2() {
    low_fu_216_p2 = (!low_0_reg_131.read().is_01() || !ap_const_lv5_1.is_01())? sc_lv<5>(): (sc_biguint<5>(low_0_reg_131.read()) + sc_biguint<5>(ap_const_lv5_1));
}

void MaxPooBackPropagatio_1::thread_mantissa_V_fu_334_p4() {
    mantissa_V_fu_334_p4 = esl_concat<24,1>(esl_concat<1,23>(ap_const_lv1_1, tmp_V_3_fu_330_p1.read()), ap_const_lv1_0);
}

void MaxPooBackPropagatio_1::thread_max_poo_locate_1_address0() {
    max_poo_locate_1_address0 =  (sc_lv<8>) (zext_ln101_fu_303_p1.read());
}

void MaxPooBackPropagatio_1::thread_max_poo_locate_1_ce0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read())) {
        max_poo_locate_1_ce0 = ap_const_logic_1;
    } else {
        max_poo_locate_1_ce0 = ap_const_logic_0;
    }
}

void MaxPooBackPropagatio_1::thread_output_matrix_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state8.read())) {
        output_matrix_address0 =  (sc_lv<10>) (sext_ln102_fu_449_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        output_matrix_address0 =  (sc_lv<10>) (zext_ln97_fu_231_p1.read());
    } else {
        output_matrix_address0 = "XXXXXXXXXX";
    }
}

void MaxPooBackPropagatio_1::thread_output_matrix_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state8.read()))) {
        output_matrix_ce0 = ap_const_logic_1;
    } else {
        output_matrix_ce0 = ap_const_logic_0;
    }
}

void MaxPooBackPropagatio_1::thread_output_matrix_d0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state8.read())) {
        output_matrix_d0 = input_matrix_load_reg_511.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read())) {
        output_matrix_d0 = ap_const_lv32_0;
    } else {
        output_matrix_d0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void MaxPooBackPropagatio_1::thread_output_matrix_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, icmp_ln96_fu_210_p2.read())) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state8.read()))) {
        output_matrix_we0 = ap_const_logic_1;
    } else {
        output_matrix_we0 = ap_const_logic_0;
    }
}

void MaxPooBackPropagatio_1::thread_p_Val2_17_fu_430_p3() {
    p_Val2_17_fu_430_p3 = (!isNeg_fu_358_p3.read()[0].is_01())? sc_lv<32>(): ((isNeg_fu_358_p3.read()[0].to_bool())? zext_ln662_fu_416_p1.read(): tmp_12_fu_420_p4.read());
}

void MaxPooBackPropagatio_1::thread_p_Val2_18_fu_443_p3() {
    p_Val2_18_fu_443_p3 = (!p_Result_s_reg_516.read()[0].is_01())? sc_lv<32>(): ((p_Result_s_reg_516.read()[0].to_bool())? result_V_3_fu_438_p2.read(): p_Val2_17_reg_521.read());
}

void MaxPooBackPropagatio_1::thread_p_Val2_s_fu_309_p1() {
    p_Val2_s_fu_309_p1 = max_poo_locate_1_loa_reg_506.read();
}

void MaxPooBackPropagatio_1::thread_r_V_3_fu_402_p2() {
    r_V_3_fu_402_p2 = (!zext_ln1287_fu_392_p1.read().is_01())? sc_lv<79>(): zext_ln682_fu_344_p1.read() << (unsigned short)zext_ln1287_fu_392_p1.read().to_uint();
}

void MaxPooBackPropagatio_1::thread_r_V_fu_396_p2() {
    r_V_fu_396_p2 = (!sext_ln1311_4_fu_388_p1.read().is_01())? sc_lv<25>(): mantissa_V_fu_334_p4.read() >> (unsigned short)sext_ln1311_4_fu_388_p1.read().to_uint();
}

void MaxPooBackPropagatio_1::thread_result_V_3_fu_438_p2() {
    result_V_3_fu_438_p2 = (!ap_const_lv32_0.is_01() || !p_Val2_17_reg_521.read().is_01())? sc_lv<32>(): (sc_biguint<32>(ap_const_lv32_0) - sc_biguint<32>(p_Val2_17_reg_521.read()));
}

void MaxPooBackPropagatio_1::thread_sext_ln101_fu_299_p1() {
    sext_ln101_fu_299_p1 = esl_sext<32,9>(add_ln101_fu_294_p2.read());
}

void MaxPooBackPropagatio_1::thread_sext_ln102_fu_449_p1() {
    sext_ln102_fu_449_p1 = esl_sext<64,32>(p_Val2_18_fu_443_p3.read());
}

void MaxPooBackPropagatio_1::thread_sext_ln1311_3_fu_384_p1() {
    sext_ln1311_3_fu_384_p1 = esl_sext<32,9>(ush_fu_376_p3.read());
}

void MaxPooBackPropagatio_1::thread_sext_ln1311_4_fu_388_p1() {
    sext_ln1311_4_fu_388_p1 = esl_sext<25,9>(ush_fu_376_p3.read());
}

void MaxPooBackPropagatio_1::thread_sext_ln1311_fu_372_p1() {
    sext_ln1311_fu_372_p1 = esl_sext<9,8>(sub_ln1311_fu_366_p2.read());
}

void MaxPooBackPropagatio_1::thread_sext_ln97_fu_227_p1() {
    sext_ln97_fu_227_p1 = esl_sext<32,11>(add_ln97_fu_222_p2.read());
}

void MaxPooBackPropagatio_1::thread_shl_ln101_2_fu_260_p3() {
    shl_ln101_2_fu_260_p3 = esl_concat<4,1>(i_0_reg_142.read(), ap_const_lv1_0);
}

void MaxPooBackPropagatio_1::thread_shl_ln8_fu_248_p3() {
    shl_ln8_fu_248_p3 = esl_concat<4,4>(i_0_reg_142.read(), ap_const_lv4_0);
}

void MaxPooBackPropagatio_1::thread_shl_ln97_2_fu_188_p3() {
    shl_ln97_2_fu_188_p3 = esl_concat<5,2>(col_0_reg_120.read(), ap_const_lv2_0);
}

void MaxPooBackPropagatio_1::thread_shl_ln_fu_176_p3() {
    shl_ln_fu_176_p3 = esl_concat<5,5>(col_0_reg_120.read(), ap_const_lv5_0);
}

void MaxPooBackPropagatio_1::thread_sub_ln101_fu_272_p2() {
    sub_ln101_fu_272_p2 = (!zext_ln101_1_fu_256_p1.read().is_01() || !zext_ln101_2_fu_268_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(zext_ln101_1_fu_256_p1.read()) - sc_biguint<9>(zext_ln101_2_fu_268_p1.read()));
}

void MaxPooBackPropagatio_1::thread_sub_ln1311_fu_366_p2() {
    sub_ln1311_fu_366_p2 = (!ap_const_lv8_7F.is_01() || !tmp_V_fu_320_p4.read().is_01())? sc_lv<8>(): (sc_biguint<8>(ap_const_lv8_7F) - sc_biguint<8>(tmp_V_fu_320_p4.read()));
}

void MaxPooBackPropagatio_1::thread_sub_ln97_fu_200_p2() {
    sub_ln97_fu_200_p2 = (!zext_ln97_1_fu_184_p1.read().is_01() || !zext_ln97_2_fu_196_p1.read().is_01())? sc_lv<11>(): (sc_biguint<11>(zext_ln97_1_fu_184_p1.read()) - sc_biguint<11>(zext_ln97_2_fu_196_p1.read()));
}

void MaxPooBackPropagatio_1::thread_tmp_12_fu_420_p4() {
    tmp_12_fu_420_p4 = r_V_3_fu_402_p2.read().range(55, 24);
}

void MaxPooBackPropagatio_1::thread_tmp_V_3_fu_330_p1() {
    tmp_V_3_fu_330_p1 = p_Val2_s_fu_309_p1.read().range(23-1, 0);
}

void MaxPooBackPropagatio_1::thread_tmp_V_fu_320_p4() {
    tmp_V_fu_320_p4 = p_Val2_s_fu_309_p1.read().range(30, 23);
}

void MaxPooBackPropagatio_1::thread_tmp_fu_408_p3() {
    tmp_fu_408_p3 = r_V_fu_396_p2.read().range(24, 24);
}

void MaxPooBackPropagatio_1::thread_ush_fu_376_p3() {
    ush_fu_376_p3 = (!isNeg_fu_358_p3.read()[0].is_01())? sc_lv<9>(): ((isNeg_fu_358_p3.read()[0].to_bool())? sext_ln1311_fu_372_p1.read(): add_ln339_fu_352_p2.read());
}

void MaxPooBackPropagatio_1::thread_zext_ln101_1_fu_256_p1() {
    zext_ln101_1_fu_256_p1 = esl_zext<9,8>(shl_ln8_fu_248_p3.read());
}

void MaxPooBackPropagatio_1::thread_zext_ln101_2_fu_268_p1() {
    zext_ln101_2_fu_268_p1 = esl_zext<9,5>(shl_ln101_2_fu_260_p3.read());
}

void MaxPooBackPropagatio_1::thread_zext_ln101_fu_303_p1() {
    zext_ln101_fu_303_p1 = esl_zext<64,32>(sext_ln101_fu_299_p1.read());
}

void MaxPooBackPropagatio_1::thread_zext_ln1287_fu_392_p1() {
    zext_ln1287_fu_392_p1 = esl_zext<79,32>(sext_ln1311_3_fu_384_p1.read());
}

void MaxPooBackPropagatio_1::thread_zext_ln339_fu_348_p1() {
    zext_ln339_fu_348_p1 = esl_zext<9,8>(tmp_V_fu_320_p4.read());
}

void MaxPooBackPropagatio_1::thread_zext_ln662_fu_416_p1() {
    zext_ln662_fu_416_p1 = esl_zext<32,1>(tmp_fu_408_p3.read());
}

void MaxPooBackPropagatio_1::thread_zext_ln682_fu_344_p1() {
    zext_ln682_fu_344_p1 = esl_zext<79,25>(mantissa_V_fu_334_p4.read());
}

void MaxPooBackPropagatio_1::thread_zext_ln97_1_fu_184_p1() {
    zext_ln97_1_fu_184_p1 = esl_zext<11,10>(shl_ln_fu_176_p3.read());
}

void MaxPooBackPropagatio_1::thread_zext_ln97_2_fu_196_p1() {
    zext_ln97_2_fu_196_p1 = esl_zext<11,7>(shl_ln97_2_fu_188_p3.read());
}

void MaxPooBackPropagatio_1::thread_zext_ln97_fu_231_p1() {
    zext_ln97_fu_231_p1 = esl_zext<64,32>(sext_ln97_fu_227_p1.read());
}

void MaxPooBackPropagatio_1::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state2.read()) && esl_seteq<1,1,1>(icmp_ln95_fu_164_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state4;
            } else {
                ap_NS_fsm = ap_ST_fsm_state3;
            }
            break;
        case 4 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state3.read()) && esl_seteq<1,1,1>(icmp_ln96_fu_210_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state2;
            } else {
                ap_NS_fsm = ap_ST_fsm_state3;
            }
            break;
        case 8 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state4.read()) && esl_seteq<1,1,1>(icmp_ln99_fu_236_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state1;
            } else {
                ap_NS_fsm = ap_ST_fsm_state5;
            }
            break;
        case 16 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state5.read()) && esl_seteq<1,1,1>(icmp_ln100_fu_282_p2.read(), ap_const_lv1_1))) {
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
            ap_NS_fsm = ap_ST_fsm_state5;
            break;
        default : 
            ap_NS_fsm =  (sc_lv<8>) ("XXXXXXXX");
            break;
    }
}

}

