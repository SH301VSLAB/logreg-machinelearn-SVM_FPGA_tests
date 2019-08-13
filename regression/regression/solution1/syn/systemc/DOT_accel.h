// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2015.2
// Copyright (C) 2015 Xilinx Inc. All rights reserved.
// 
// ===========================================================

#ifndef _DOT_accel_HH_
#define _DOT_accel_HH_

#include "systemc.h"
#include "AESL_pkg.h"

#include "DOT_accel_fadd_32ns_32ns_32_5_full_dsp.h"
#include "DOT_accel_fmul_32ns_32ns_32_4_max_dsp.h"
#include "DOT_accel_fdiv_32ns_32ns_32_16.h"
#include "DOT_accel_fpext_32ns_64_1.h"
#include "DOT_accel_dcmp_64ns_64ns_1_1.h"
#include "DOT_accel_CONTROL_BUS_s_axi.h"

namespace ap_rtl {

template<unsigned int C_S_AXI_CONTROL_BUS_ADDR_WIDTH = 5,
         unsigned int C_S_AXI_CONTROL_BUS_DATA_WIDTH = 32>
struct DOT_accel : public sc_module {
    // Port declarations 38
    sc_in< sc_logic > s_axi_CONTROL_BUS_AWVALID;
    sc_out< sc_logic > s_axi_CONTROL_BUS_AWREADY;
    sc_in< sc_uint<C_S_AXI_CONTROL_BUS_ADDR_WIDTH> > s_axi_CONTROL_BUS_AWADDR;
    sc_in< sc_logic > s_axi_CONTROL_BUS_WVALID;
    sc_out< sc_logic > s_axi_CONTROL_BUS_WREADY;
    sc_in< sc_uint<C_S_AXI_CONTROL_BUS_DATA_WIDTH> > s_axi_CONTROL_BUS_WDATA;
    sc_in< sc_uint<C_S_AXI_CONTROL_BUS_DATA_WIDTH/8> > s_axi_CONTROL_BUS_WSTRB;
    sc_in< sc_logic > s_axi_CONTROL_BUS_ARVALID;
    sc_out< sc_logic > s_axi_CONTROL_BUS_ARREADY;
    sc_in< sc_uint<C_S_AXI_CONTROL_BUS_ADDR_WIDTH> > s_axi_CONTROL_BUS_ARADDR;
    sc_out< sc_logic > s_axi_CONTROL_BUS_RVALID;
    sc_in< sc_logic > s_axi_CONTROL_BUS_RREADY;
    sc_out< sc_uint<C_S_AXI_CONTROL_BUS_DATA_WIDTH> > s_axi_CONTROL_BUS_RDATA;
    sc_out< sc_lv<2> > s_axi_CONTROL_BUS_RRESP;
    sc_out< sc_logic > s_axi_CONTROL_BUS_BVALID;
    sc_in< sc_logic > s_axi_CONTROL_BUS_BREADY;
    sc_out< sc_lv<2> > s_axi_CONTROL_BUS_BRESP;
    sc_in_clk ap_clk;
    sc_in< sc_logic > ap_rst_n;
    sc_in< sc_lv<32> > INPUT_STREAM_TDATA;
    sc_in< sc_logic > INPUT_STREAM_TVALID;
    sc_out< sc_logic > INPUT_STREAM_TREADY;
    sc_in< sc_lv<4> > INPUT_STREAM_TKEEP;
    sc_in< sc_lv<4> > INPUT_STREAM_TSTRB;
    sc_in< sc_lv<4> > INPUT_STREAM_TUSER;
    sc_in< sc_lv<1> > INPUT_STREAM_TLAST;
    sc_in< sc_lv<5> > INPUT_STREAM_TID;
    sc_in< sc_lv<5> > INPUT_STREAM_TDEST;
    sc_out< sc_lv<32> > OUTPUT_STREAM_TDATA;
    sc_out< sc_logic > OUTPUT_STREAM_TVALID;
    sc_in< sc_logic > OUTPUT_STREAM_TREADY;
    sc_out< sc_lv<4> > OUTPUT_STREAM_TKEEP;
    sc_out< sc_lv<4> > OUTPUT_STREAM_TSTRB;
    sc_out< sc_lv<4> > OUTPUT_STREAM_TUSER;
    sc_out< sc_lv<1> > OUTPUT_STREAM_TLAST;
    sc_out< sc_lv<5> > OUTPUT_STREAM_TID;
    sc_out< sc_lv<5> > OUTPUT_STREAM_TDEST;
    sc_out< sc_logic > interrupt;


    // Module declarations
    DOT_accel(sc_module_name name);
    SC_HAS_PROCESS(DOT_accel);

    ~DOT_accel();

    sc_trace_file* mVcdFile;

    ofstream mHdltvinHandle;
    ofstream mHdltvoutHandle;
    DOT_accel_CONTROL_BUS_s_axi<C_S_AXI_CONTROL_BUS_ADDR_WIDTH,C_S_AXI_CONTROL_BUS_DATA_WIDTH>* DOT_accel_CONTROL_BUS_s_axi_U;
    DOT_accel_fadd_32ns_32ns_32_5_full_dsp<1,5,32,32,32>* DOT_accel_fadd_32ns_32ns_32_5_full_dsp_U0;
    DOT_accel_fadd_32ns_32ns_32_5_full_dsp<1,5,32,32,32>* DOT_accel_fadd_32ns_32ns_32_5_full_dsp_U1;
    DOT_accel_fadd_32ns_32ns_32_5_full_dsp<1,5,32,32,32>* DOT_accel_fadd_32ns_32ns_32_5_full_dsp_U2;
    DOT_accel_fmul_32ns_32ns_32_4_max_dsp<1,4,32,32,32>* DOT_accel_fmul_32ns_32ns_32_4_max_dsp_U3;
    DOT_accel_fmul_32ns_32ns_32_4_max_dsp<1,4,32,32,32>* DOT_accel_fmul_32ns_32ns_32_4_max_dsp_U4;
    DOT_accel_fmul_32ns_32ns_32_4_max_dsp<1,4,32,32,32>* DOT_accel_fmul_32ns_32ns_32_4_max_dsp_U5;
    DOT_accel_fmul_32ns_32ns_32_4_max_dsp<1,4,32,32,32>* DOT_accel_fmul_32ns_32ns_32_4_max_dsp_U6;
    DOT_accel_fmul_32ns_32ns_32_4_max_dsp<1,4,32,32,32>* DOT_accel_fmul_32ns_32ns_32_4_max_dsp_U7;
    DOT_accel_fmul_32ns_32ns_32_4_max_dsp<1,4,32,32,32>* DOT_accel_fmul_32ns_32ns_32_4_max_dsp_U8;
    DOT_accel_fdiv_32ns_32ns_32_16<1,16,32,32,32>* DOT_accel_fdiv_32ns_32ns_32_16_U9;
    DOT_accel_fdiv_32ns_32ns_32_16<1,16,32,32,32>* DOT_accel_fdiv_32ns_32ns_32_16_U10;
    DOT_accel_fdiv_32ns_32ns_32_16<1,16,32,32,32>* DOT_accel_fdiv_32ns_32ns_32_16_U11;
    DOT_accel_fdiv_32ns_32ns_32_16<1,16,32,32,32>* DOT_accel_fdiv_32ns_32ns_32_16_U12;
    DOT_accel_fpext_32ns_64_1<1,1,32,64>* DOT_accel_fpext_32ns_64_1_U13;
    DOT_accel_dcmp_64ns_64ns_1_1<1,1,64,64,1>* DOT_accel_dcmp_64ns_64ns_1_1_U14;
    sc_signal< sc_logic > ap_rst_n_inv;
    sc_signal< sc_logic > ap_start;
    sc_signal< sc_logic > ap_done;
    sc_signal< sc_logic > ap_idle;
    sc_signal< sc_lv<79> > ap_CS_fsm;
    sc_signal< sc_logic > ap_sig_cseq_ST_st1_fsm_0;
    sc_signal< bool > ap_sig_bdd_120;
    sc_signal< sc_logic > ap_ready;
    sc_signal< sc_logic > DOT_accel_CONTROL_BUS_s_axi_U_ap_dummy_ce;
    sc_signal< sc_lv<32> > grp_fu_372_p2;
    sc_signal< sc_lv<32> > reg_450;
    sc_signal< sc_logic > ap_sig_cseq_ST_st7_fsm_6;
    sc_signal< bool > ap_sig_bdd_165;
    sc_signal< sc_logic > ap_sig_cseq_ST_st28_fsm_27;
    sc_signal< bool > ap_sig_bdd_172;
    sc_signal< sc_logic > ap_sig_cseq_ST_st48_fsm_47;
    sc_signal< bool > ap_sig_bdd_180;
    sc_signal< sc_lv<32> > grp_fu_378_p2;
    sc_signal< sc_lv<32> > reg_459;
    sc_signal< sc_logic > ap_sig_cseq_ST_st37_fsm_36;
    sc_signal< bool > ap_sig_bdd_190;
    sc_signal< sc_lv<32> > grp_fu_384_p2;
    sc_signal< sc_lv<32> > reg_466;
    sc_signal< sc_lv<32> > grp_fu_390_p2;
    sc_signal< sc_lv<32> > reg_473;
    sc_signal< sc_logic > ap_sig_cseq_ST_st41_fsm_40;
    sc_signal< bool > ap_sig_bdd_202;
    sc_signal< sc_lv<32> > grp_fu_358_p2;
    sc_signal< sc_lv<32> > reg_480;
    sc_signal< sc_logic > ap_sig_cseq_ST_st12_fsm_11;
    sc_signal< bool > ap_sig_bdd_212;
    sc_signal< sc_logic > ap_sig_cseq_ST_st17_fsm_16;
    sc_signal< bool > ap_sig_bdd_219;
    sc_signal< sc_logic > ap_sig_cseq_ST_st22_fsm_21;
    sc_signal< bool > ap_sig_bdd_227;
    sc_signal< sc_logic > ap_sig_cseq_ST_st53_fsm_52;
    sc_signal< bool > ap_sig_bdd_235;
    sc_signal< sc_logic > ap_sig_cseq_ST_st58_fsm_57;
    sc_signal< bool > ap_sig_bdd_243;
    sc_signal< sc_logic > ap_sig_cseq_ST_st63_fsm_62;
    sc_signal< bool > ap_sig_bdd_251;
    sc_signal< sc_logic > ap_sig_cseq_ST_st68_fsm_67;
    sc_signal< bool > ap_sig_bdd_259;
    sc_signal< sc_logic > ap_sig_cseq_ST_st73_fsm_72;
    sc_signal< bool > ap_sig_bdd_267;
    sc_signal< sc_lv<32> > grp_fu_362_p2;
    sc_signal< sc_lv<32> > reg_490;
    sc_signal< sc_lv<32> > grp_fu_366_p2;
    sc_signal< sc_lv<32> > reg_497;
    sc_signal< sc_lv<32> > grp_fu_409_p2;
    sc_signal< sc_lv<32> > reg_503;
    sc_signal< sc_logic > ap_sig_cseq_ST_st61_fsm_60;
    sc_signal< bool > ap_sig_bdd_286;
    sc_signal< sc_lv<32> > grp_fu_415_p2;
    sc_signal< sc_lv<32> > reg_509;
    sc_signal< sc_lv<32> > grp_fu_420_p2;
    sc_signal< sc_lv<32> > reg_514;
    sc_signal< sc_lv<32> > grp_fu_425_p2;
    sc_signal< sc_lv<32> > reg_519;
    sc_signal< sc_lv<32> > reg_524;
    sc_signal< sc_logic > ap_sig_cseq_ST_st62_fsm_61;
    sc_signal< bool > ap_sig_bdd_302;
    sc_signal< sc_logic > ap_sig_cseq_ST_st67_fsm_66;
    sc_signal< bool > ap_sig_bdd_309;
    sc_signal< sc_logic > ap_sig_cseq_ST_st78_fsm_77;
    sc_signal< bool > ap_sig_bdd_317;
    sc_signal< sc_lv<32> > reg_531;
    sc_signal< sc_logic > ap_sig_cseq_ST_st66_fsm_65;
    sc_signal< bool > ap_sig_bdd_326;
    sc_signal< sc_logic > ap_sig_cseq_ST_st71_fsm_70;
    sc_signal< bool > ap_sig_bdd_333;
    sc_signal< sc_lv<1> > exitcond1_i_fu_537_p2;
    sc_signal< sc_logic > ap_sig_cseq_ST_st2_fsm_1;
    sc_signal< bool > ap_sig_bdd_343;
    sc_signal< bool > ap_sig_bdd_349;
    sc_signal< sc_lv<3> > i_fu_543_p2;
    sc_signal< sc_lv<32> > a_5_4_fu_615_p3;
    sc_signal< sc_lv<32> > a_5_9_fu_655_p3;
    sc_signal< sc_lv<32> > a_5_14_fu_687_p3;
    sc_signal< sc_lv<32> > a_5_18_fu_711_p3;
    sc_signal< sc_lv<32> > a_5_23_fu_727_p3;
    sc_signal< sc_lv<32> > a_5_24_fu_735_p3;
    sc_signal< sc_lv<3> > i_1_fu_749_p2;
    sc_signal< sc_logic > ap_sig_cseq_ST_st3_fsm_2;
    sc_signal< bool > ap_sig_bdd_374;
    sc_signal< sc_lv<1> > exitcond_i_fu_743_p2;
    sc_signal< bool > ap_sig_bdd_379;
    sc_signal< sc_lv<32> > b_5_4_fu_821_p3;
    sc_signal< sc_lv<32> > b_5_9_fu_861_p3;
    sc_signal< sc_lv<32> > b_5_14_fu_893_p3;
    sc_signal< sc_lv<32> > b_5_18_fu_917_p3;
    sc_signal< sc_lv<32> > b_5_23_fu_933_p3;
    sc_signal< sc_lv<32> > b_5_24_fu_941_p3;
    sc_signal< sc_lv<32> > grp_fu_396_p2;
    sc_signal< sc_lv<32> > tmp_2_1_reg_1072;
    sc_signal< sc_lv<32> > grp_fu_402_p2;
    sc_signal< sc_lv<32> > tmp_10_1_reg_1077;
    sc_signal< sc_lv<64> > tmp_s_fu_438_p1;
    sc_signal< sc_lv<64> > tmp_s_reg_1082;
    sc_signal< sc_logic > ap_sig_cseq_ST_st23_fsm_22;
    sc_signal< bool > ap_sig_bdd_406;
    sc_signal< sc_lv<1> > tmp_18_fu_984_p2;
    sc_signal< sc_lv<1> > tmp_18_reg_1088;
    sc_signal< sc_logic > ap_sig_cseq_ST_st24_fsm_23;
    sc_signal< bool > ap_sig_bdd_415;
    sc_signal< sc_lv<32> > tmp_7_reg_1092;
    sc_signal< sc_logic > ap_sig_cseq_ST_st32_fsm_31;
    sc_signal< bool > ap_sig_bdd_423;
    sc_signal< sc_lv<32> > pow_4_reg_1098;
    sc_signal< sc_logic > ap_sig_cseq_ST_st33_fsm_32;
    sc_signal< bool > ap_sig_bdd_431;
    sc_signal< sc_lv<32> > tmp_10_reg_1108;
    sc_signal< sc_lv<32> > tmp_21_1_reg_1114;
    sc_signal< sc_lv<32> > tmp_25_1_reg_1120;
    sc_signal< sc_lv<32> > tmp_30_1_reg_1126;
    sc_signal< sc_lv<32> > tmp_21_2_reg_1132;
    sc_signal< sc_logic > ap_sig_cseq_ST_st45_fsm_44;
    sc_signal< bool > ap_sig_bdd_443;
    sc_signal< sc_lv<32> > tmp_25_2_reg_1137;
    sc_signal< sc_lv<32> > tmp_30_2_reg_1142;
    sc_signal< sc_lv<32> > tmp_35_2_reg_1147;
    sc_signal< sc_lv<32> > tmp_39_6_reg_1152;
    sc_signal< sc_logic > ap_sig_cseq_ST_st57_fsm_56;
    sc_signal< bool > ap_sig_bdd_454;
    sc_signal< sc_lv<32> > tmp_39_7_reg_1157;
    sc_signal< sc_lv<32> > tmp_39_8_reg_1162;
    sc_signal< sc_lv<32> > tmp_39_9_reg_1167;
    sc_signal< sc_lv<32> > tmp_44_4_reg_1172;
    sc_signal< sc_lv<32> > tmp_44_6_reg_1177;
    sc_signal< sc_lv<32> > a_5_s_reg_181;
    sc_signal< sc_lv<32> > a_4_s_reg_193;
    sc_signal< sc_lv<32> > a_5_21_reg_205;
    sc_signal< sc_lv<32> > a_5_10_reg_217;
    sc_signal< sc_lv<32> > a_5_15_reg_229;
    sc_signal< sc_lv<32> > a_5_19_reg_241;
    sc_signal< sc_lv<3> > i_0_i_reg_253;
    sc_signal< sc_lv<32> > b_5_s_reg_264;
    sc_signal< sc_lv<32> > b_4_s_reg_276;
    sc_signal< sc_lv<32> > b_5_21_reg_288;
    sc_signal< sc_lv<32> > b_5_10_reg_300;
    sc_signal< sc_lv<32> > b_5_15_reg_312;
    sc_signal< sc_lv<32> > b_5_19_reg_324;
    sc_signal< sc_lv<3> > i1_0_i_reg_336;
    sc_signal< sc_lv<32> > p_0_phi_fu_351_p4;
    sc_signal< sc_lv<32> > p_0_reg_347;
    sc_signal< sc_logic > ap_sig_cseq_ST_st25_fsm_24;
    sc_signal< bool > ap_sig_bdd_502;
    sc_signal< sc_logic > ap_sig_cseq_ST_st79_fsm_78;
    sc_signal< bool > ap_sig_bdd_512;
    sc_signal< sc_logic > ap_sig_ioackin_OUTPUT_STREAM_TREADY;
    sc_signal< sc_logic > ap_reg_ioackin_OUTPUT_STREAM_TREADY;
    sc_signal< sc_lv<32> > grp_fu_358_p0;
    sc_signal< sc_lv<32> > grp_fu_358_p1;
    sc_signal< sc_logic > ap_sig_cseq_ST_st8_fsm_7;
    sc_signal< bool > ap_sig_bdd_551;
    sc_signal< sc_logic > ap_sig_cseq_ST_st13_fsm_12;
    sc_signal< bool > ap_sig_bdd_558;
    sc_signal< sc_logic > ap_sig_cseq_ST_st18_fsm_17;
    sc_signal< bool > ap_sig_bdd_565;
    sc_signal< sc_logic > ap_sig_cseq_ST_st49_fsm_48;
    sc_signal< bool > ap_sig_bdd_573;
    sc_signal< sc_logic > ap_sig_cseq_ST_st54_fsm_53;
    sc_signal< bool > ap_sig_bdd_581;
    sc_signal< sc_logic > ap_sig_cseq_ST_st59_fsm_58;
    sc_signal< bool > ap_sig_bdd_588;
    sc_signal< sc_logic > ap_sig_cseq_ST_st64_fsm_63;
    sc_signal< bool > ap_sig_bdd_596;
    sc_signal< sc_logic > ap_sig_cseq_ST_st69_fsm_68;
    sc_signal< bool > ap_sig_bdd_604;
    sc_signal< sc_logic > ap_sig_cseq_ST_st74_fsm_73;
    sc_signal< bool > ap_sig_bdd_612;
    sc_signal< sc_lv<32> > grp_fu_362_p0;
    sc_signal< sc_lv<32> > grp_fu_362_p1;
    sc_signal< sc_lv<32> > grp_fu_366_p0;
    sc_signal< sc_lv<32> > grp_fu_366_p1;
    sc_signal< sc_lv<32> > grp_fu_372_p0;
    sc_signal< sc_lv<32> > grp_fu_372_p1;
    sc_signal< sc_logic > ap_sig_cseq_ST_st4_fsm_3;
    sc_signal< bool > ap_sig_bdd_628;
    sc_signal< sc_logic > ap_sig_cseq_ST_st29_fsm_28;
    sc_signal< bool > ap_sig_bdd_635;
    sc_signal< sc_logic > ap_sig_cseq_ST_st30_fsm_29;
    sc_signal< bool > ap_sig_bdd_642;
    sc_signal< sc_logic > ap_sig_cseq_ST_st34_fsm_33;
    sc_signal< bool > ap_sig_bdd_650;
    sc_signal< sc_logic > ap_sig_cseq_ST_st38_fsm_37;
    sc_signal< bool > ap_sig_bdd_658;
    sc_signal< sc_logic > ap_sig_cseq_ST_st42_fsm_41;
    sc_signal< bool > ap_sig_bdd_665;
    sc_signal< sc_lv<32> > grp_fu_378_p0;
    sc_signal< sc_lv<32> > grp_fu_378_p1;
    sc_signal< sc_lv<32> > grp_fu_384_p0;
    sc_signal< sc_lv<32> > grp_fu_384_p1;
    sc_signal< sc_lv<32> > grp_fu_390_p0;
    sc_signal< sc_lv<32> > grp_fu_390_p1;
    sc_signal< sc_lv<32> > grp_fu_396_p0;
    sc_signal< sc_lv<32> > grp_fu_396_p1;
    sc_signal< sc_lv<32> > grp_fu_402_p0;
    sc_signal< sc_lv<32> > grp_fu_402_p1;
    sc_signal< sc_lv<32> > grp_fu_409_p0;
    sc_signal< sc_lv<32> > grp_fu_409_p1;
    sc_signal< sc_logic > ap_sig_cseq_ST_st46_fsm_45;
    sc_signal< bool > ap_sig_bdd_693;
    sc_signal< sc_lv<32> > grp_fu_415_p0;
    sc_signal< sc_lv<32> > grp_fu_415_p1;
    sc_signal< sc_lv<32> > grp_fu_420_p0;
    sc_signal< sc_lv<32> > grp_fu_420_p1;
    sc_signal< sc_lv<32> > grp_fu_425_p0;
    sc_signal< sc_lv<32> > grp_fu_425_p1;
    sc_signal< sc_lv<32> > tmp_s_fu_438_p0;
    sc_signal< sc_lv<64> > tmp_17_fu_441_p0;
    sc_signal< sc_lv<64> > tmp_17_fu_441_p1;
    sc_signal< sc_lv<1> > sel_tmp_fu_553_p2;
    sc_signal< sc_lv<32> > a_0_fu_549_p1;
    sc_signal< sc_lv<1> > sel_tmp2_fu_567_p2;
    sc_signal< sc_lv<32> > a_5_fu_559_p3;
    sc_signal< sc_lv<1> > sel_tmp4_fu_581_p2;
    sc_signal< sc_lv<32> > a_5_1_fu_573_p3;
    sc_signal< sc_lv<1> > sel_tmp6_fu_595_p2;
    sc_signal< sc_lv<32> > a_5_2_fu_587_p3;
    sc_signal< sc_lv<1> > sel_tmp8_fu_609_p2;
    sc_signal< sc_lv<32> > a_5_3_fu_601_p3;
    sc_signal< sc_lv<32> > a_5_5_fu_623_p3;
    sc_signal< sc_lv<32> > a_5_6_fu_631_p3;
    sc_signal< sc_lv<32> > a_5_7_fu_639_p3;
    sc_signal< sc_lv<32> > a_5_8_fu_647_p3;
    sc_signal< sc_lv<32> > a_5_11_fu_663_p3;
    sc_signal< sc_lv<32> > a_5_12_fu_671_p3;
    sc_signal< sc_lv<32> > a_5_13_fu_679_p3;
    sc_signal< sc_lv<32> > a_5_16_fu_695_p3;
    sc_signal< sc_lv<32> > a_5_17_fu_703_p3;
    sc_signal< sc_lv<32> > a_5_22_fu_719_p3;
    sc_signal< sc_lv<1> > sel_tmp1_fu_759_p2;
    sc_signal< sc_lv<32> > b_0_fu_755_p1;
    sc_signal< sc_lv<1> > sel_tmp3_fu_773_p2;
    sc_signal< sc_lv<32> > b_5_fu_765_p3;
    sc_signal< sc_lv<1> > sel_tmp5_fu_787_p2;
    sc_signal< sc_lv<32> > b_5_1_fu_779_p3;
    sc_signal< sc_lv<1> > sel_tmp7_fu_801_p2;
    sc_signal< sc_lv<32> > b_5_2_fu_793_p3;
    sc_signal< sc_lv<1> > sel_tmp9_fu_815_p2;
    sc_signal< sc_lv<32> > b_5_3_fu_807_p3;
    sc_signal< sc_lv<32> > b_5_5_fu_829_p3;
    sc_signal< sc_lv<32> > b_5_6_fu_837_p3;
    sc_signal< sc_lv<32> > b_5_7_fu_845_p3;
    sc_signal< sc_lv<32> > b_5_8_fu_853_p3;
    sc_signal< sc_lv<32> > b_5_11_fu_869_p3;
    sc_signal< sc_lv<32> > b_5_12_fu_877_p3;
    sc_signal< sc_lv<32> > b_5_13_fu_885_p3;
    sc_signal< sc_lv<32> > b_5_16_fu_901_p3;
    sc_signal< sc_lv<32> > b_5_17_fu_909_p3;
    sc_signal< sc_lv<32> > b_5_22_fu_925_p3;
    sc_signal< sc_lv<64> > tmp_to_int_fu_949_p1;
    sc_signal< sc_lv<11> > tmp_fu_952_p4;
    sc_signal< sc_lv<52> > tmp_8_fu_962_p1;
    sc_signal< sc_lv<1> > notrhs_fu_972_p2;
    sc_signal< sc_lv<1> > notlhs_fu_966_p2;
    sc_signal< sc_lv<1> > tmp_16_fu_978_p2;
    sc_signal< sc_lv<1> > tmp_17_fu_441_p2;
    sc_signal< sc_logic > grp_fu_358_ce;
    sc_signal< sc_logic > grp_fu_362_ce;
    sc_signal< sc_logic > grp_fu_366_ce;
    sc_signal< sc_logic > grp_fu_372_ce;
    sc_signal< sc_logic > grp_fu_378_ce;
    sc_signal< sc_logic > grp_fu_384_ce;
    sc_signal< sc_logic > grp_fu_390_ce;
    sc_signal< sc_logic > grp_fu_396_ce;
    sc_signal< sc_logic > grp_fu_402_ce;
    sc_signal< sc_logic > grp_fu_409_ce;
    sc_signal< sc_logic > grp_fu_415_ce;
    sc_signal< sc_logic > grp_fu_420_ce;
    sc_signal< sc_logic > grp_fu_425_ce;
    sc_signal< sc_lv<5> > tmp_17_fu_441_opcode;
    sc_signal< sc_lv<79> > ap_NS_fsm;
    static const sc_logic ap_const_logic_1;
    static const sc_logic ap_const_logic_0;
    static const sc_lv<79> ap_ST_st1_fsm_0;
    static const sc_lv<79> ap_ST_st2_fsm_1;
    static const sc_lv<79> ap_ST_st3_fsm_2;
    static const sc_lv<79> ap_ST_st4_fsm_3;
    static const sc_lv<79> ap_ST_st5_fsm_4;
    static const sc_lv<79> ap_ST_st6_fsm_5;
    static const sc_lv<79> ap_ST_st7_fsm_6;
    static const sc_lv<79> ap_ST_st8_fsm_7;
    static const sc_lv<79> ap_ST_st9_fsm_8;
    static const sc_lv<79> ap_ST_st10_fsm_9;
    static const sc_lv<79> ap_ST_st11_fsm_10;
    static const sc_lv<79> ap_ST_st12_fsm_11;
    static const sc_lv<79> ap_ST_st13_fsm_12;
    static const sc_lv<79> ap_ST_st14_fsm_13;
    static const sc_lv<79> ap_ST_st15_fsm_14;
    static const sc_lv<79> ap_ST_st16_fsm_15;
    static const sc_lv<79> ap_ST_st17_fsm_16;
    static const sc_lv<79> ap_ST_st18_fsm_17;
    static const sc_lv<79> ap_ST_st19_fsm_18;
    static const sc_lv<79> ap_ST_st20_fsm_19;
    static const sc_lv<79> ap_ST_st21_fsm_20;
    static const sc_lv<79> ap_ST_st22_fsm_21;
    static const sc_lv<79> ap_ST_st23_fsm_22;
    static const sc_lv<79> ap_ST_st24_fsm_23;
    static const sc_lv<79> ap_ST_st25_fsm_24;
    static const sc_lv<79> ap_ST_st26_fsm_25;
    static const sc_lv<79> ap_ST_st27_fsm_26;
    static const sc_lv<79> ap_ST_st28_fsm_27;
    static const sc_lv<79> ap_ST_st29_fsm_28;
    static const sc_lv<79> ap_ST_st30_fsm_29;
    static const sc_lv<79> ap_ST_st31_fsm_30;
    static const sc_lv<79> ap_ST_st32_fsm_31;
    static const sc_lv<79> ap_ST_st33_fsm_32;
    static const sc_lv<79> ap_ST_st34_fsm_33;
    static const sc_lv<79> ap_ST_st35_fsm_34;
    static const sc_lv<79> ap_ST_st36_fsm_35;
    static const sc_lv<79> ap_ST_st37_fsm_36;
    static const sc_lv<79> ap_ST_st38_fsm_37;
    static const sc_lv<79> ap_ST_st39_fsm_38;
    static const sc_lv<79> ap_ST_st40_fsm_39;
    static const sc_lv<79> ap_ST_st41_fsm_40;
    static const sc_lv<79> ap_ST_st42_fsm_41;
    static const sc_lv<79> ap_ST_st43_fsm_42;
    static const sc_lv<79> ap_ST_st44_fsm_43;
    static const sc_lv<79> ap_ST_st45_fsm_44;
    static const sc_lv<79> ap_ST_st46_fsm_45;
    static const sc_lv<79> ap_ST_st47_fsm_46;
    static const sc_lv<79> ap_ST_st48_fsm_47;
    static const sc_lv<79> ap_ST_st49_fsm_48;
    static const sc_lv<79> ap_ST_st50_fsm_49;
    static const sc_lv<79> ap_ST_st51_fsm_50;
    static const sc_lv<79> ap_ST_st52_fsm_51;
    static const sc_lv<79> ap_ST_st53_fsm_52;
    static const sc_lv<79> ap_ST_st54_fsm_53;
    static const sc_lv<79> ap_ST_st55_fsm_54;
    static const sc_lv<79> ap_ST_st56_fsm_55;
    static const sc_lv<79> ap_ST_st57_fsm_56;
    static const sc_lv<79> ap_ST_st58_fsm_57;
    static const sc_lv<79> ap_ST_st59_fsm_58;
    static const sc_lv<79> ap_ST_st60_fsm_59;
    static const sc_lv<79> ap_ST_st61_fsm_60;
    static const sc_lv<79> ap_ST_st62_fsm_61;
    static const sc_lv<79> ap_ST_st63_fsm_62;
    static const sc_lv<79> ap_ST_st64_fsm_63;
    static const sc_lv<79> ap_ST_st65_fsm_64;
    static const sc_lv<79> ap_ST_st66_fsm_65;
    static const sc_lv<79> ap_ST_st67_fsm_66;
    static const sc_lv<79> ap_ST_st68_fsm_67;
    static const sc_lv<79> ap_ST_st69_fsm_68;
    static const sc_lv<79> ap_ST_st70_fsm_69;
    static const sc_lv<79> ap_ST_st71_fsm_70;
    static const sc_lv<79> ap_ST_st72_fsm_71;
    static const sc_lv<79> ap_ST_st73_fsm_72;
    static const sc_lv<79> ap_ST_st74_fsm_73;
    static const sc_lv<79> ap_ST_st75_fsm_74;
    static const sc_lv<79> ap_ST_st76_fsm_75;
    static const sc_lv<79> ap_ST_st77_fsm_76;
    static const sc_lv<79> ap_ST_st78_fsm_77;
    static const sc_lv<79> ap_ST_st79_fsm_78;
    static const sc_lv<32> ap_const_lv32_0;
    static const sc_lv<1> ap_const_lv1_1;
    static const int C_S_AXI_DATA_WIDTH;
    static const sc_lv<32> ap_const_lv32_6;
    static const sc_lv<32> ap_const_lv32_1B;
    static const sc_lv<32> ap_const_lv32_2F;
    static const sc_lv<32> ap_const_lv32_24;
    static const sc_lv<32> ap_const_lv32_28;
    static const sc_lv<32> ap_const_lv32_B;
    static const sc_lv<32> ap_const_lv32_10;
    static const sc_lv<32> ap_const_lv32_15;
    static const sc_lv<32> ap_const_lv32_34;
    static const sc_lv<32> ap_const_lv32_39;
    static const sc_lv<32> ap_const_lv32_3E;
    static const sc_lv<32> ap_const_lv32_43;
    static const sc_lv<32> ap_const_lv32_48;
    static const sc_lv<32> ap_const_lv32_3C;
    static const sc_lv<32> ap_const_lv32_3D;
    static const sc_lv<32> ap_const_lv32_42;
    static const sc_lv<32> ap_const_lv32_4D;
    static const sc_lv<32> ap_const_lv32_41;
    static const sc_lv<32> ap_const_lv32_46;
    static const sc_lv<32> ap_const_lv32_1;
    static const sc_lv<1> ap_const_lv1_0;
    static const sc_lv<32> ap_const_lv32_2;
    static const sc_lv<32> ap_const_lv32_16;
    static const sc_lv<32> ap_const_lv32_17;
    static const sc_lv<32> ap_const_lv32_1F;
    static const sc_lv<32> ap_const_lv32_20;
    static const sc_lv<32> ap_const_lv32_2C;
    static const sc_lv<32> ap_const_lv32_38;
    static const sc_lv<3> ap_const_lv3_0;
    static const sc_lv<32> ap_const_lv32_18;
    static const sc_lv<32> ap_const_lv32_4E;
    static const sc_lv<4> ap_const_lv4_F;
    static const sc_lv<4> ap_const_lv4_0;
    static const sc_lv<5> ap_const_lv5_0;
    static const sc_lv<32> ap_const_lv32_3F800000;
    static const sc_lv<32> ap_const_lv32_7;
    static const sc_lv<32> ap_const_lv32_C;
    static const sc_lv<32> ap_const_lv32_11;
    static const sc_lv<32> ap_const_lv32_30;
    static const sc_lv<32> ap_const_lv32_35;
    static const sc_lv<32> ap_const_lv32_3A;
    static const sc_lv<32> ap_const_lv32_3F;
    static const sc_lv<32> ap_const_lv32_44;
    static const sc_lv<32> ap_const_lv32_49;
    static const sc_lv<32> ap_const_lv32_3F000000;
    static const sc_lv<32> ap_const_lv32_3;
    static const sc_lv<32> ap_const_lv32_1C;
    static const sc_lv<32> ap_const_lv32_1D;
    static const sc_lv<32> ap_const_lv32_21;
    static const sc_lv<32> ap_const_lv32_25;
    static const sc_lv<32> ap_const_lv32_29;
    static const sc_lv<32> ap_const_lv32_40C00000;
    static const sc_lv<32> ap_const_lv32_41C00000;
    static const sc_lv<32> ap_const_lv32_471D8000;
    static const sc_lv<32> ap_const_lv32_4DE467E0;
    static const sc_lv<32> ap_const_lv32_2D;
    static const sc_lv<32> ap_const_lv32_42F00000;
    static const sc_lv<32> ap_const_lv32_48B13000;
    static const sc_lv<32> ap_const_lv32_4FB99466;
    static const sc_lv<32> ap_const_lv32_44340000;
    static const sc_lv<32> ap_const_lv32_4A5D7C00;
    static const sc_lv<32> ap_const_lv32_51A261D9;
    static const sc_lv<32> ap_const_lv32_459D8000;
    static const sc_lv<32> ap_const_lv32_4C184540;
    static const sc_lv<32> ap_const_lv32_53983BBB;
    static const sc_lv<64> ap_const_lv64_C01425729B280F13;
    static const sc_lv<3> ap_const_lv3_6;
    static const sc_lv<3> ap_const_lv3_1;
    static const sc_lv<3> ap_const_lv3_4;
    static const sc_lv<3> ap_const_lv3_3;
    static const sc_lv<3> ap_const_lv3_2;
    static const sc_lv<11> ap_const_lv11_7FF;
    static const sc_lv<52> ap_const_lv52_0;
    static const sc_lv<5> ap_const_lv5_5;
    // Thread declarations
    void thread_ap_clk_no_reset_();
    void thread_DOT_accel_CONTROL_BUS_s_axi_U_ap_dummy_ce();
    void thread_INPUT_STREAM_TREADY();
    void thread_OUTPUT_STREAM_TDATA();
    void thread_OUTPUT_STREAM_TDEST();
    void thread_OUTPUT_STREAM_TID();
    void thread_OUTPUT_STREAM_TKEEP();
    void thread_OUTPUT_STREAM_TLAST();
    void thread_OUTPUT_STREAM_TSTRB();
    void thread_OUTPUT_STREAM_TUSER();
    void thread_OUTPUT_STREAM_TVALID();
    void thread_a_0_fu_549_p1();
    void thread_a_5_11_fu_663_p3();
    void thread_a_5_12_fu_671_p3();
    void thread_a_5_13_fu_679_p3();
    void thread_a_5_14_fu_687_p3();
    void thread_a_5_16_fu_695_p3();
    void thread_a_5_17_fu_703_p3();
    void thread_a_5_18_fu_711_p3();
    void thread_a_5_1_fu_573_p3();
    void thread_a_5_22_fu_719_p3();
    void thread_a_5_23_fu_727_p3();
    void thread_a_5_24_fu_735_p3();
    void thread_a_5_2_fu_587_p3();
    void thread_a_5_3_fu_601_p3();
    void thread_a_5_4_fu_615_p3();
    void thread_a_5_5_fu_623_p3();
    void thread_a_5_6_fu_631_p3();
    void thread_a_5_7_fu_639_p3();
    void thread_a_5_8_fu_647_p3();
    void thread_a_5_9_fu_655_p3();
    void thread_a_5_fu_559_p3();
    void thread_ap_done();
    void thread_ap_idle();
    void thread_ap_ready();
    void thread_ap_rst_n_inv();
    void thread_ap_sig_bdd_120();
    void thread_ap_sig_bdd_165();
    void thread_ap_sig_bdd_172();
    void thread_ap_sig_bdd_180();
    void thread_ap_sig_bdd_190();
    void thread_ap_sig_bdd_202();
    void thread_ap_sig_bdd_212();
    void thread_ap_sig_bdd_219();
    void thread_ap_sig_bdd_227();
    void thread_ap_sig_bdd_235();
    void thread_ap_sig_bdd_243();
    void thread_ap_sig_bdd_251();
    void thread_ap_sig_bdd_259();
    void thread_ap_sig_bdd_267();
    void thread_ap_sig_bdd_286();
    void thread_ap_sig_bdd_302();
    void thread_ap_sig_bdd_309();
    void thread_ap_sig_bdd_317();
    void thread_ap_sig_bdd_326();
    void thread_ap_sig_bdd_333();
    void thread_ap_sig_bdd_343();
    void thread_ap_sig_bdd_349();
    void thread_ap_sig_bdd_374();
    void thread_ap_sig_bdd_379();
    void thread_ap_sig_bdd_406();
    void thread_ap_sig_bdd_415();
    void thread_ap_sig_bdd_423();
    void thread_ap_sig_bdd_431();
    void thread_ap_sig_bdd_443();
    void thread_ap_sig_bdd_454();
    void thread_ap_sig_bdd_502();
    void thread_ap_sig_bdd_512();
    void thread_ap_sig_bdd_551();
    void thread_ap_sig_bdd_558();
    void thread_ap_sig_bdd_565();
    void thread_ap_sig_bdd_573();
    void thread_ap_sig_bdd_581();
    void thread_ap_sig_bdd_588();
    void thread_ap_sig_bdd_596();
    void thread_ap_sig_bdd_604();
    void thread_ap_sig_bdd_612();
    void thread_ap_sig_bdd_628();
    void thread_ap_sig_bdd_635();
    void thread_ap_sig_bdd_642();
    void thread_ap_sig_bdd_650();
    void thread_ap_sig_bdd_658();
    void thread_ap_sig_bdd_665();
    void thread_ap_sig_bdd_693();
    void thread_ap_sig_cseq_ST_st12_fsm_11();
    void thread_ap_sig_cseq_ST_st13_fsm_12();
    void thread_ap_sig_cseq_ST_st17_fsm_16();
    void thread_ap_sig_cseq_ST_st18_fsm_17();
    void thread_ap_sig_cseq_ST_st1_fsm_0();
    void thread_ap_sig_cseq_ST_st22_fsm_21();
    void thread_ap_sig_cseq_ST_st23_fsm_22();
    void thread_ap_sig_cseq_ST_st24_fsm_23();
    void thread_ap_sig_cseq_ST_st25_fsm_24();
    void thread_ap_sig_cseq_ST_st28_fsm_27();
    void thread_ap_sig_cseq_ST_st29_fsm_28();
    void thread_ap_sig_cseq_ST_st2_fsm_1();
    void thread_ap_sig_cseq_ST_st30_fsm_29();
    void thread_ap_sig_cseq_ST_st32_fsm_31();
    void thread_ap_sig_cseq_ST_st33_fsm_32();
    void thread_ap_sig_cseq_ST_st34_fsm_33();
    void thread_ap_sig_cseq_ST_st37_fsm_36();
    void thread_ap_sig_cseq_ST_st38_fsm_37();
    void thread_ap_sig_cseq_ST_st3_fsm_2();
    void thread_ap_sig_cseq_ST_st41_fsm_40();
    void thread_ap_sig_cseq_ST_st42_fsm_41();
    void thread_ap_sig_cseq_ST_st45_fsm_44();
    void thread_ap_sig_cseq_ST_st46_fsm_45();
    void thread_ap_sig_cseq_ST_st48_fsm_47();
    void thread_ap_sig_cseq_ST_st49_fsm_48();
    void thread_ap_sig_cseq_ST_st4_fsm_3();
    void thread_ap_sig_cseq_ST_st53_fsm_52();
    void thread_ap_sig_cseq_ST_st54_fsm_53();
    void thread_ap_sig_cseq_ST_st57_fsm_56();
    void thread_ap_sig_cseq_ST_st58_fsm_57();
    void thread_ap_sig_cseq_ST_st59_fsm_58();
    void thread_ap_sig_cseq_ST_st61_fsm_60();
    void thread_ap_sig_cseq_ST_st62_fsm_61();
    void thread_ap_sig_cseq_ST_st63_fsm_62();
    void thread_ap_sig_cseq_ST_st64_fsm_63();
    void thread_ap_sig_cseq_ST_st66_fsm_65();
    void thread_ap_sig_cseq_ST_st67_fsm_66();
    void thread_ap_sig_cseq_ST_st68_fsm_67();
    void thread_ap_sig_cseq_ST_st69_fsm_68();
    void thread_ap_sig_cseq_ST_st71_fsm_70();
    void thread_ap_sig_cseq_ST_st73_fsm_72();
    void thread_ap_sig_cseq_ST_st74_fsm_73();
    void thread_ap_sig_cseq_ST_st78_fsm_77();
    void thread_ap_sig_cseq_ST_st79_fsm_78();
    void thread_ap_sig_cseq_ST_st7_fsm_6();
    void thread_ap_sig_cseq_ST_st8_fsm_7();
    void thread_ap_sig_ioackin_OUTPUT_STREAM_TREADY();
    void thread_b_0_fu_755_p1();
    void thread_b_5_11_fu_869_p3();
    void thread_b_5_12_fu_877_p3();
    void thread_b_5_13_fu_885_p3();
    void thread_b_5_14_fu_893_p3();
    void thread_b_5_16_fu_901_p3();
    void thread_b_5_17_fu_909_p3();
    void thread_b_5_18_fu_917_p3();
    void thread_b_5_1_fu_779_p3();
    void thread_b_5_22_fu_925_p3();
    void thread_b_5_23_fu_933_p3();
    void thread_b_5_24_fu_941_p3();
    void thread_b_5_2_fu_793_p3();
    void thread_b_5_3_fu_807_p3();
    void thread_b_5_4_fu_821_p3();
    void thread_b_5_5_fu_829_p3();
    void thread_b_5_6_fu_837_p3();
    void thread_b_5_7_fu_845_p3();
    void thread_b_5_8_fu_853_p3();
    void thread_b_5_9_fu_861_p3();
    void thread_b_5_fu_765_p3();
    void thread_exitcond1_i_fu_537_p2();
    void thread_exitcond_i_fu_743_p2();
    void thread_grp_fu_358_ce();
    void thread_grp_fu_358_p0();
    void thread_grp_fu_358_p1();
    void thread_grp_fu_362_ce();
    void thread_grp_fu_362_p0();
    void thread_grp_fu_362_p1();
    void thread_grp_fu_366_ce();
    void thread_grp_fu_366_p0();
    void thread_grp_fu_366_p1();
    void thread_grp_fu_372_ce();
    void thread_grp_fu_372_p0();
    void thread_grp_fu_372_p1();
    void thread_grp_fu_378_ce();
    void thread_grp_fu_378_p0();
    void thread_grp_fu_378_p1();
    void thread_grp_fu_384_ce();
    void thread_grp_fu_384_p0();
    void thread_grp_fu_384_p1();
    void thread_grp_fu_390_ce();
    void thread_grp_fu_390_p0();
    void thread_grp_fu_390_p1();
    void thread_grp_fu_396_ce();
    void thread_grp_fu_396_p0();
    void thread_grp_fu_396_p1();
    void thread_grp_fu_402_ce();
    void thread_grp_fu_402_p0();
    void thread_grp_fu_402_p1();
    void thread_grp_fu_409_ce();
    void thread_grp_fu_409_p0();
    void thread_grp_fu_409_p1();
    void thread_grp_fu_415_ce();
    void thread_grp_fu_415_p0();
    void thread_grp_fu_415_p1();
    void thread_grp_fu_420_ce();
    void thread_grp_fu_420_p0();
    void thread_grp_fu_420_p1();
    void thread_grp_fu_425_ce();
    void thread_grp_fu_425_p0();
    void thread_grp_fu_425_p1();
    void thread_i_1_fu_749_p2();
    void thread_i_fu_543_p2();
    void thread_notlhs_fu_966_p2();
    void thread_notrhs_fu_972_p2();
    void thread_p_0_phi_fu_351_p4();
    void thread_sel_tmp1_fu_759_p2();
    void thread_sel_tmp2_fu_567_p2();
    void thread_sel_tmp3_fu_773_p2();
    void thread_sel_tmp4_fu_581_p2();
    void thread_sel_tmp5_fu_787_p2();
    void thread_sel_tmp6_fu_595_p2();
    void thread_sel_tmp7_fu_801_p2();
    void thread_sel_tmp8_fu_609_p2();
    void thread_sel_tmp9_fu_815_p2();
    void thread_sel_tmp_fu_553_p2();
    void thread_tmp_16_fu_978_p2();
    void thread_tmp_17_fu_441_opcode();
    void thread_tmp_17_fu_441_p0();
    void thread_tmp_17_fu_441_p1();
    void thread_tmp_18_fu_984_p2();
    void thread_tmp_8_fu_962_p1();
    void thread_tmp_fu_952_p4();
    void thread_tmp_s_fu_438_p0();
    void thread_tmp_to_int_fu_949_p1();
    void thread_ap_NS_fsm();
    void thread_hdltv_gen();
};

}

using namespace ap_rtl;

#endif