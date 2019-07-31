#include "DOT_Full_Algorithm_accel.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void DOT_Full_Algorithm_accel::thread_DOT_Full_Algorithm_accel_CONTROL_BUS_s_axi_U_ap_dummy_ce() {
    DOT_Full_Algorithm_accel_CONTROL_BUS_s_axi_U_ap_dummy_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_INPUT_STREAM_TREADY() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_fu_1527_p2.read()) && 
          !ap_sig_bdd_2505.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st3_fsm_2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond8_i_fu_1593_p2.read()) && 
          !ap_sig_bdd_2526.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten1_fu_1863_p2.read()) && 
          !ap_sig_bdd_2825.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st191_fsm_40.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten2_fu_1991_p2.read()) && 
          !ap_sig_bdd_3029.read()))) {
        INPUT_STREAM_TREADY = ap_const_logic_1;
    } else {
        INPUT_STREAM_TREADY = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_OUTPUT_STREAM_TDATA() {
    OUTPUT_STREAM_TDATA = grp_fu_1057_p2.read();
}

void DOT_Full_Algorithm_accel::thread_OUTPUT_STREAM_TDEST() {
    OUTPUT_STREAM_TDEST = ap_const_lv5_0;
}

void DOT_Full_Algorithm_accel::thread_OUTPUT_STREAM_TID() {
    OUTPUT_STREAM_TID = ap_const_lv5_0;
}

void DOT_Full_Algorithm_accel::thread_OUTPUT_STREAM_TKEEP() {
    OUTPUT_STREAM_TKEEP = ap_const_lv4_F;
}

void DOT_Full_Algorithm_accel::thread_OUTPUT_STREAM_TLAST() {
    OUTPUT_STREAM_TLAST = ap_reg_ppstg_last_assign_reg_2475_pp7_it14.read();
}

void DOT_Full_Algorithm_accel::thread_OUTPUT_STREAM_TSTRB() {
    OUTPUT_STREAM_TSTRB = ap_const_lv4_F;
}

void DOT_Full_Algorithm_accel::thread_OUTPUT_STREAM_TUSER() {
    OUTPUT_STREAM_TUSER = ap_const_lv4_0;
}

void DOT_Full_Algorithm_accel::thread_OUTPUT_STREAM_TVALID() {
    if (((esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_exitcond_i_reg_2466_pp7_it14.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp7_it15.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_OUTPUT_STREAM_TREADY.read())))) {
        OUTPUT_STREAM_TVALID = ap_const_logic_1;
    } else {
        OUTPUT_STREAM_TVALID = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_a_0_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read())) {
        a_0_address0 =  (sc_lv<3>) (tmp_1_fu_1567_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        a_0_address0 =  (sc_lv<3>) (tmp_s_fu_1811_p1.read());
    } else {
        a_0_address0 = "XXX";
    }
}

void DOT_Full_Algorithm_accel::thread_a_0_ce0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read()) && 
          !ap_sig_bdd_2505.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read())))) {
        a_0_ce0 = ap_const_logic_1;
    } else {
        a_0_ce0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_a_0_d0() {
    a_0_d0 = ret_fu_1577_p1.read();
}

void DOT_Full_Algorithm_accel::thread_a_0_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_fu_1527_p2.read()) && 
          !ap_sig_bdd_2505.read() && 
          esl_seteq<1,3,3>(ap_const_lv3_0, j_0_i_mid2_fu_1545_p3.read())))) {
        a_0_we0 = ap_const_logic_1;
    } else {
        a_0_we0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_a_1_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read())) {
        a_1_address0 =  (sc_lv<3>) (tmp_1_fu_1567_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        a_1_address0 =  (sc_lv<3>) (tmp_s_fu_1811_p1.read());
    } else {
        a_1_address0 = "XXX";
    }
}

void DOT_Full_Algorithm_accel::thread_a_1_ce0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read()) && 
          !ap_sig_bdd_2505.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read())))) {
        a_1_ce0 = ap_const_logic_1;
    } else {
        a_1_ce0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_a_1_d0() {
    a_1_d0 = ret_fu_1577_p1.read();
}

void DOT_Full_Algorithm_accel::thread_a_1_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_fu_1527_p2.read()) && 
          !ap_sig_bdd_2505.read() && 
          esl_seteq<1,3,3>(j_0_i_mid2_fu_1545_p3.read(), ap_const_lv3_1)))) {
        a_1_we0 = ap_const_logic_1;
    } else {
        a_1_we0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_a_2_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read())) {
        a_2_address0 =  (sc_lv<3>) (tmp_1_fu_1567_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        a_2_address0 =  (sc_lv<3>) (tmp_s_fu_1811_p1.read());
    } else {
        a_2_address0 = "XXX";
    }
}

void DOT_Full_Algorithm_accel::thread_a_2_ce0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read()) && 
          !ap_sig_bdd_2505.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read())))) {
        a_2_ce0 = ap_const_logic_1;
    } else {
        a_2_ce0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_a_2_d0() {
    a_2_d0 = ret_fu_1577_p1.read();
}

void DOT_Full_Algorithm_accel::thread_a_2_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_fu_1527_p2.read()) && 
          !ap_sig_bdd_2505.read() && 
          esl_seteq<1,3,3>(j_0_i_mid2_fu_1545_p3.read(), ap_const_lv3_2)))) {
        a_2_we0 = ap_const_logic_1;
    } else {
        a_2_we0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_a_3_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read())) {
        a_3_address0 =  (sc_lv<3>) (tmp_1_fu_1567_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        a_3_address0 =  (sc_lv<3>) (tmp_s_fu_1811_p1.read());
    } else {
        a_3_address0 = "XXX";
    }
}

void DOT_Full_Algorithm_accel::thread_a_3_ce0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read()) && 
          !ap_sig_bdd_2505.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read())))) {
        a_3_ce0 = ap_const_logic_1;
    } else {
        a_3_ce0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_a_3_d0() {
    a_3_d0 = ret_fu_1577_p1.read();
}

void DOT_Full_Algorithm_accel::thread_a_3_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_fu_1527_p2.read()) && 
          !ap_sig_bdd_2505.read() && 
          esl_seteq<1,3,3>(j_0_i_mid2_fu_1545_p3.read(), ap_const_lv3_3)))) {
        a_3_we0 = ap_const_logic_1;
    } else {
        a_3_we0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_a_4_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read())) {
        a_4_address0 =  (sc_lv<3>) (tmp_1_fu_1567_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        a_4_address0 =  (sc_lv<3>) (tmp_s_fu_1811_p1.read());
    } else {
        a_4_address0 = "XXX";
    }
}

void DOT_Full_Algorithm_accel::thread_a_4_ce0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read()) && 
          !ap_sig_bdd_2505.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read())))) {
        a_4_ce0 = ap_const_logic_1;
    } else {
        a_4_ce0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_a_4_d0() {
    a_4_d0 = ret_fu_1577_p1.read();
}

void DOT_Full_Algorithm_accel::thread_a_4_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_fu_1527_p2.read()) && 
          !ap_sig_bdd_2505.read() && 
          esl_seteq<1,3,3>(j_0_i_mid2_fu_1545_p3.read(), ap_const_lv3_4)))) {
        a_4_we0 = ap_const_logic_1;
    } else {
        a_4_we0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_a_5_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read())) {
        a_5_address0 =  (sc_lv<3>) (tmp_1_fu_1567_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        a_5_address0 =  (sc_lv<3>) (tmp_s_fu_1811_p1.read());
    } else {
        a_5_address0 = "XXX";
    }
}

void DOT_Full_Algorithm_accel::thread_a_5_ce0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read()) && 
          !ap_sig_bdd_2505.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read())))) {
        a_5_ce0 = ap_const_logic_1;
    } else {
        a_5_ce0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_a_5_d0() {
    a_5_d0 = ret_fu_1577_p1.read();
}

void DOT_Full_Algorithm_accel::thread_a_5_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st2_fsm_1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_fu_1527_p2.read()) && 
          !ap_sig_bdd_2505.read() && 
          !esl_seteq<1,3,3>(j_0_i_mid2_fu_1545_p3.read(), ap_const_lv3_4) && 
          !esl_seteq<1,3,3>(j_0_i_mid2_fu_1545_p3.read(), ap_const_lv3_3) && 
          !esl_seteq<1,3,3>(j_0_i_mid2_fu_1545_p3.read(), ap_const_lv3_2) && 
          !esl_seteq<1,3,3>(j_0_i_mid2_fu_1545_p3.read(), ap_const_lv3_1) && 
          !esl_seteq<1,3,3>(ap_const_lv3_0, j_0_i_mid2_fu_1545_p3.read())))) {
        a_5_we0 = ap_const_logic_1;
    } else {
        a_5_we0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_done() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st289_fsm_48.read())) {
        ap_done = ap_const_logic_1;
    } else {
        ap_done = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_idle() {
    if ((!esl_seteq<1,1,1>(ap_const_logic_1, ap_start.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st1_fsm_0.read()))) {
        ap_idle = ap_const_logic_1;
    } else {
        ap_idle = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_ready() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st289_fsm_48.read())) {
        ap_ready = ap_const_logic_1;
    } else {
        ap_ready = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_reg_phiprechg_by2in_0_reg_844pp6_it22() {
    ap_reg_phiprechg_by2in_0_reg_844pp6_it22 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
}

void DOT_Full_Algorithm_accel::thread_ap_reg_phiprechg_p_0_i100_i_reg_730pp2_it22() {
    ap_reg_phiprechg_p_0_i100_i_reg_730pp2_it22 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
}

void DOT_Full_Algorithm_accel::thread_ap_reg_phiprechg_p_0_i66_i_reg_786pp4_it22() {
    ap_reg_phiprechg_p_0_i66_i_reg_786pp4_it22 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
}

void DOT_Full_Algorithm_accel::thread_ap_rst_n_inv() {
    ap_rst_n_inv =  (sc_logic) (~ap_rst_n.read());
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_1781() {
    ap_sig_bdd_1781 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(37, 37));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_2373() {
    ap_sig_bdd_2373 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(39, 39));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_2387() {
    ap_sig_bdd_2387 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(41, 41));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_2500() {
    ap_sig_bdd_2500 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(1, 1));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_2505() {
    ap_sig_bdd_2505 = (esl_seteq<1,1,1>(INPUT_STREAM_TVALID.read(), ap_const_logic_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_fu_1527_p2.read()));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_2522() {
    ap_sig_bdd_2522 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(2, 2));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_2526() {
    ap_sig_bdd_2526 = (esl_seteq<1,1,1>(INPUT_STREAM_TVALID.read(), ap_const_logic_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond8_i_fu_1593_p2.read()));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_2550() {
    ap_sig_bdd_2550 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(3, 3));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_2773() {
    ap_sig_bdd_2773 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(4, 4));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_2784() {
    ap_sig_bdd_2784 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(5, 5));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_2798() {
    ap_sig_bdd_2798 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(6, 6));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_2808() {
    ap_sig_bdd_2808 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(10, 10));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_2821() {
    ap_sig_bdd_2821 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(38, 38));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_2825() {
    ap_sig_bdd_2825 = (esl_seteq<1,1,1>(INPUT_STREAM_TVALID.read(), ap_const_logic_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten1_fu_1863_p2.read()));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_3025() {
    ap_sig_bdd_3025 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(40, 40));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_3029() {
    ap_sig_bdd_3029 = (esl_seteq<1,1,1>(INPUT_STREAM_TVALID.read(), ap_const_logic_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten2_fu_1991_p2.read()));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_3230() {
    ap_sig_bdd_3230 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(47, 47));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_3541() {
    ap_sig_bdd_3541 = (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_56_reg_2256.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_exitcond7_i_reg_2182_pp2_it21.read()));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_3613() {
    ap_sig_bdd_3613 = (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_61_reg_2394.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_exitcond4_i_reg_2348_pp4_it21.read()));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_3687() {
    ap_sig_bdd_3687 = (!esl_seteq<1,1,1>(ap_const_lv1_0, tmp_66_reg_2452.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_exitcond1_i_reg_2407_pp6_it21.read()));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_3849() {
    ap_sig_bdd_3849 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(7, 7));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_3856() {
    ap_sig_bdd_3856 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(12, 12));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_3863() {
    ap_sig_bdd_3863 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(17, 17));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_3872() {
    ap_sig_bdd_3872 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(42, 42));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_4007() {
    ap_sig_bdd_4007 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(22, 22));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_4579() {
    ap_sig_bdd_4579 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(23, 23));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_4587() {
    ap_sig_bdd_4587 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(24, 24));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_4595() {
    ap_sig_bdd_4595 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(25, 25));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_4603() {
    ap_sig_bdd_4603 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(26, 26));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_4611() {
    ap_sig_bdd_4611 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(27, 27));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_4619() {
    ap_sig_bdd_4619 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(28, 28));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_4627() {
    ap_sig_bdd_4627 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(29, 29));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_4635() {
    ap_sig_bdd_4635 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(30, 30));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_4643() {
    ap_sig_bdd_4643 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(31, 31));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_4651() {
    ap_sig_bdd_4651 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(32, 32));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_4659() {
    ap_sig_bdd_4659 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(33, 33));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_4667() {
    ap_sig_bdd_4667 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(34, 34));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_4675() {
    ap_sig_bdd_4675 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(35, 35));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_4683() {
    ap_sig_bdd_4683 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(36, 36));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_4817() {
    ap_sig_bdd_4817 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(48, 48));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_730() {
    ap_sig_bdd_730 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(11, 11));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_738() {
    ap_sig_bdd_738 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(16, 16));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_746() {
    ap_sig_bdd_746 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(21, 21));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_758() {
    ap_sig_bdd_758 = esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm.read().range(46, 46));
}

void DOT_Full_Algorithm_accel::thread_ap_sig_bdd_90() {
    ap_sig_bdd_90 = esl_seteq<1,1,1>(ap_CS_fsm.read().range(0, 0), ap_const_lv1_1);
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_pp2_stg0_fsm_3() {
    if (ap_sig_bdd_2550.read()) {
        ap_sig_cseq_ST_pp2_stg0_fsm_3 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_pp2_stg0_fsm_3 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_pp4_stg0_fsm_39() {
    if (ap_sig_bdd_2373.read()) {
        ap_sig_cseq_ST_pp4_stg0_fsm_39 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_pp4_stg0_fsm_39 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_pp6_stg0_fsm_41() {
    if (ap_sig_bdd_2387.read()) {
        ap_sig_cseq_ST_pp6_stg0_fsm_41 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_pp6_stg0_fsm_41 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_pp7_stg0_fsm_47() {
    if (ap_sig_bdd_3230.read()) {
        ap_sig_cseq_ST_pp7_stg0_fsm_47 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_pp7_stg0_fsm_47 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st100_fsm_24() {
    if (ap_sig_bdd_4587.read()) {
        ap_sig_cseq_ST_st100_fsm_24 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st100_fsm_24 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st101_fsm_25() {
    if (ap_sig_bdd_4595.read()) {
        ap_sig_cseq_ST_st101_fsm_25 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st101_fsm_25 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st102_fsm_26() {
    if (ap_sig_bdd_4603.read()) {
        ap_sig_cseq_ST_st102_fsm_26 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st102_fsm_26 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st103_fsm_27() {
    if (ap_sig_bdd_4611.read()) {
        ap_sig_cseq_ST_st103_fsm_27 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st103_fsm_27 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st104_fsm_28() {
    if (ap_sig_bdd_4619.read()) {
        ap_sig_cseq_ST_st104_fsm_28 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st104_fsm_28 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st105_fsm_29() {
    if (ap_sig_bdd_4627.read()) {
        ap_sig_cseq_ST_st105_fsm_29 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st105_fsm_29 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st106_fsm_30() {
    if (ap_sig_bdd_4635.read()) {
        ap_sig_cseq_ST_st106_fsm_30 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st106_fsm_30 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st107_fsm_31() {
    if (ap_sig_bdd_4643.read()) {
        ap_sig_cseq_ST_st107_fsm_31 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st107_fsm_31 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st108_fsm_32() {
    if (ap_sig_bdd_4651.read()) {
        ap_sig_cseq_ST_st108_fsm_32 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st108_fsm_32 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st109_fsm_33() {
    if (ap_sig_bdd_4659.read()) {
        ap_sig_cseq_ST_st109_fsm_33 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st109_fsm_33 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st110_fsm_34() {
    if (ap_sig_bdd_4667.read()) {
        ap_sig_cseq_ST_st110_fsm_34 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st110_fsm_34 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st111_fsm_35() {
    if (ap_sig_bdd_4675.read()) {
        ap_sig_cseq_ST_st111_fsm_35 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st111_fsm_35 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st112_fsm_36() {
    if (ap_sig_bdd_4683.read()) {
        ap_sig_cseq_ST_st112_fsm_36 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st112_fsm_36 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st113_fsm_37() {
    if (ap_sig_bdd_1781.read()) {
        ap_sig_cseq_ST_st113_fsm_37 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st113_fsm_37 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st114_fsm_38() {
    if (ap_sig_bdd_2821.read()) {
        ap_sig_cseq_ST_st114_fsm_38 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st114_fsm_38 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st191_fsm_40() {
    if (ap_sig_bdd_3025.read()) {
        ap_sig_cseq_ST_st191_fsm_40 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st191_fsm_40 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st1_fsm_0() {
    if (ap_sig_bdd_90.read()) {
        ap_sig_cseq_ST_st1_fsm_0 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st1_fsm_0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st268_fsm_42() {
    if (ap_sig_bdd_3872.read()) {
        ap_sig_cseq_ST_st268_fsm_42 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st268_fsm_42 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st272_fsm_46() {
    if (ap_sig_bdd_758.read()) {
        ap_sig_cseq_ST_st272_fsm_46 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st272_fsm_46 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st289_fsm_48() {
    if (ap_sig_bdd_4817.read()) {
        ap_sig_cseq_ST_st289_fsm_48 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st289_fsm_48 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st2_fsm_1() {
    if (ap_sig_bdd_2500.read()) {
        ap_sig_cseq_ST_st2_fsm_1 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st2_fsm_1 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st3_fsm_2() {
    if (ap_sig_bdd_2522.read()) {
        ap_sig_cseq_ST_st3_fsm_2 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st3_fsm_2 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st80_fsm_4() {
    if (ap_sig_bdd_2773.read()) {
        ap_sig_cseq_ST_st80_fsm_4 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st80_fsm_4 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st81_fsm_5() {
    if (ap_sig_bdd_2784.read()) {
        ap_sig_cseq_ST_st81_fsm_5 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st81_fsm_5 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st82_fsm_6() {
    if (ap_sig_bdd_2798.read()) {
        ap_sig_cseq_ST_st82_fsm_6 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st82_fsm_6 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st83_fsm_7() {
    if (ap_sig_bdd_3849.read()) {
        ap_sig_cseq_ST_st83_fsm_7 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st83_fsm_7 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st86_fsm_10() {
    if (ap_sig_bdd_2808.read()) {
        ap_sig_cseq_ST_st86_fsm_10 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st86_fsm_10 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st87_fsm_11() {
    if (ap_sig_bdd_730.read()) {
        ap_sig_cseq_ST_st87_fsm_11 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st87_fsm_11 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st88_fsm_12() {
    if (ap_sig_bdd_3856.read()) {
        ap_sig_cseq_ST_st88_fsm_12 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st88_fsm_12 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st92_fsm_16() {
    if (ap_sig_bdd_738.read()) {
        ap_sig_cseq_ST_st92_fsm_16 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st92_fsm_16 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st93_fsm_17() {
    if (ap_sig_bdd_3863.read()) {
        ap_sig_cseq_ST_st93_fsm_17 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st93_fsm_17 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st97_fsm_21() {
    if (ap_sig_bdd_746.read()) {
        ap_sig_cseq_ST_st97_fsm_21 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st97_fsm_21 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st98_fsm_22() {
    if (ap_sig_bdd_4007.read()) {
        ap_sig_cseq_ST_st98_fsm_22 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st98_fsm_22 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_cseq_ST_st99_fsm_23() {
    if (ap_sig_bdd_4579.read()) {
        ap_sig_cseq_ST_st99_fsm_23 = ap_const_logic_1;
    } else {
        ap_sig_cseq_ST_st99_fsm_23 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_ap_sig_ioackin_OUTPUT_STREAM_TREADY() {
    if (esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_OUTPUT_STREAM_TREADY.read())) {
        ap_sig_ioackin_OUTPUT_STREAM_TREADY = OUTPUT_STREAM_TREADY.read();
    } else {
        ap_sig_ioackin_OUTPUT_STREAM_TREADY = ap_const_logic_1;
    }
}

void DOT_Full_Algorithm_accel::thread_b_0_fu_1605_p1() {
    b_0_fu_1605_p1 = INPUT_STREAM_TDATA.read();
}

void DOT_Full_Algorithm_accel::thread_b_5_11_fu_1719_p3() {
    b_5_11_fu_1719_p3 = (!sel_tmp2_fu_1623_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp2_fu_1623_p2.read()[0].to_bool())? b_0_fu_1605_p1.read(): b_5_21_reg_660.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_12_fu_1727_p3() {
    b_5_12_fu_1727_p3 = (!sel_tmp4_fu_1637_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp4_fu_1637_p2.read()[0].to_bool())? b_5_21_reg_660.read(): b_5_11_fu_1719_p3.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_13_fu_1735_p3() {
    b_5_13_fu_1735_p3 = (!sel_tmp6_fu_1651_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp6_fu_1651_p2.read()[0].to_bool())? b_5_21_reg_660.read(): b_5_12_fu_1727_p3.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_14_fu_1743_p3() {
    b_5_14_fu_1743_p3 = (!sel_tmp8_fu_1665_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp8_fu_1665_p2.read()[0].to_bool())? b_5_21_reg_660.read(): b_5_13_fu_1735_p3.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_16_fu_1751_p3() {
    b_5_16_fu_1751_p3 = (!sel_tmp4_fu_1637_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp4_fu_1637_p2.read()[0].to_bool())? b_0_fu_1605_p1.read(): b_5_10_reg_672.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_17_fu_1759_p3() {
    b_5_17_fu_1759_p3 = (!sel_tmp6_fu_1651_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp6_fu_1651_p2.read()[0].to_bool())? b_5_10_reg_672.read(): b_5_16_fu_1751_p3.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_18_fu_1767_p3() {
    b_5_18_fu_1767_p3 = (!sel_tmp8_fu_1665_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp8_fu_1665_p2.read()[0].to_bool())? b_5_10_reg_672.read(): b_5_17_fu_1759_p3.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_1_fu_1629_p3() {
    b_5_1_fu_1629_p3 = (!sel_tmp2_fu_1623_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp2_fu_1623_p2.read()[0].to_bool())? b_5_s_reg_636.read(): b_5_fu_1615_p3.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_22_fu_1775_p3() {
    b_5_22_fu_1775_p3 = (!sel_tmp6_fu_1651_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp6_fu_1651_p2.read()[0].to_bool())? b_0_fu_1605_p1.read(): b_5_15_reg_684.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_23_fu_1783_p3() {
    b_5_23_fu_1783_p3 = (!sel_tmp8_fu_1665_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp8_fu_1665_p2.read()[0].to_bool())? b_5_15_reg_684.read(): b_5_22_fu_1775_p3.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_24_fu_1791_p3() {
    b_5_24_fu_1791_p3 = (!sel_tmp8_fu_1665_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp8_fu_1665_p2.read()[0].to_bool())? b_0_fu_1605_p1.read(): b_5_19_reg_696.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_2_fu_1643_p3() {
    b_5_2_fu_1643_p3 = (!sel_tmp4_fu_1637_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp4_fu_1637_p2.read()[0].to_bool())? b_5_s_reg_636.read(): b_5_1_fu_1629_p3.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_3_fu_1657_p3() {
    b_5_3_fu_1657_p3 = (!sel_tmp6_fu_1651_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp6_fu_1651_p2.read()[0].to_bool())? b_5_s_reg_636.read(): b_5_2_fu_1643_p3.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_4_fu_1671_p3() {
    b_5_4_fu_1671_p3 = (!sel_tmp8_fu_1665_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp8_fu_1665_p2.read()[0].to_bool())? b_5_s_reg_636.read(): b_5_3_fu_1657_p3.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_5_fu_1679_p3() {
    b_5_5_fu_1679_p3 = (!sel_tmp_fu_1609_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp_fu_1609_p2.read()[0].to_bool())? b_0_fu_1605_p1.read(): b_4_s_reg_648.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_6_fu_1687_p3() {
    b_5_6_fu_1687_p3 = (!sel_tmp2_fu_1623_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp2_fu_1623_p2.read()[0].to_bool())? b_4_s_reg_648.read(): b_5_5_fu_1679_p3.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_7_fu_1695_p3() {
    b_5_7_fu_1695_p3 = (!sel_tmp4_fu_1637_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp4_fu_1637_p2.read()[0].to_bool())? b_4_s_reg_648.read(): b_5_6_fu_1687_p3.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_8_fu_1703_p3() {
    b_5_8_fu_1703_p3 = (!sel_tmp6_fu_1651_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp6_fu_1651_p2.read()[0].to_bool())? b_4_s_reg_648.read(): b_5_7_fu_1695_p3.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_9_fu_1711_p3() {
    b_5_9_fu_1711_p3 = (!sel_tmp8_fu_1665_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp8_fu_1665_p2.read()[0].to_bool())? b_4_s_reg_648.read(): b_5_8_fu_1703_p3.read());
}

void DOT_Full_Algorithm_accel::thread_b_5_fu_1615_p3() {
    b_5_fu_1615_p3 = (!sel_tmp_fu_1609_p2.read()[0].is_01())? sc_lv<32>(): ((sel_tmp_fu_1609_p2.read()[0].to_bool())? b_5_s_reg_636.read(): b_0_fu_1605_p1.read());
}

void DOT_Full_Algorithm_accel::thread_by2in_0_phi_fu_848_p4() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it75.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_exitcond1_i_reg_2407_pp6_it74.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_66_reg_2452_pp6_it74.read()))) {
        by2in_0_phi_fu_848_p4 = reg_1460.read();
    } else {
        by2in_0_phi_fu_848_p4 = ap_reg_phiprechg_by2in_0_reg_844pp6_it75.read();
    }
}

void DOT_Full_Algorithm_accel::thread_by2in_1_1_fu_2071_p3() {
    by2in_1_1_fu_2071_p3 = (!ap_reg_ppstg_tmp_68_reg_2446_pp6_it74.read()[0].is_01())? sc_lv<32>(): ((ap_reg_ppstg_tmp_68_reg_2446_pp6_it74.read()[0].to_bool())? by2in_0_phi_fu_848_p4.read(): by2in_1_s_reg_809.read());
}

void DOT_Full_Algorithm_accel::thread_by2in_1_2_fu_2078_p3() {
    by2in_1_2_fu_2078_p3 = (!ap_reg_ppstg_tmp_68_reg_2446_pp6_it74.read()[0].is_01())? sc_lv<32>(): ((ap_reg_ppstg_tmp_68_reg_2446_pp6_it74.read()[0].to_bool())? by2in_0_s_reg_821.read(): by2in_0_phi_fu_848_p4.read());
}

void DOT_Full_Algorithm_accel::thread_c_0_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read())) {
        c_0_address0 =  (sc_lv<3>) (tmp_20_fu_1903_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read()))) {
        c_0_address0 =  (sc_lv<3>) (tmp_39_fu_2015_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_39.read()))) {
        c_0_address0 =  (sc_lv<3>) (tmp_22_fu_1941_p1.read());
    } else {
        c_0_address0 = "XXX";
    }
}

void DOT_Full_Algorithm_accel::thread_c_0_ce0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read()) && 
          !ap_sig_bdd_2825.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_39.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        c_0_ce0 = ap_const_logic_1;
    } else {
        c_0_ce0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_c_0_d0() {
    c_0_d0 = ret_1_fu_1913_p1.read();
}

void DOT_Full_Algorithm_accel::thread_c_0_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten1_fu_1863_p2.read()) && 
          !ap_sig_bdd_2825.read() && 
          esl_seteq<1,3,3>(ap_const_lv3_0, j4_0_i_mid2_fu_1881_p3.read())))) {
        c_0_we0 = ap_const_logic_1;
    } else {
        c_0_we0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_c_1_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read())) {
        c_1_address0 =  (sc_lv<3>) (tmp_20_fu_1903_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read()))) {
        c_1_address0 =  (sc_lv<3>) (tmp_39_fu_2015_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_39.read()))) {
        c_1_address0 =  (sc_lv<3>) (tmp_22_fu_1941_p1.read());
    } else {
        c_1_address0 = "XXX";
    }
}

void DOT_Full_Algorithm_accel::thread_c_1_ce0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read()) && 
          !ap_sig_bdd_2825.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_39.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        c_1_ce0 = ap_const_logic_1;
    } else {
        c_1_ce0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_c_1_d0() {
    c_1_d0 = ret_1_fu_1913_p1.read();
}

void DOT_Full_Algorithm_accel::thread_c_1_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten1_fu_1863_p2.read()) && 
          !ap_sig_bdd_2825.read() && 
          esl_seteq<1,3,3>(ap_const_lv3_1, j4_0_i_mid2_fu_1881_p3.read())))) {
        c_1_we0 = ap_const_logic_1;
    } else {
        c_1_we0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_c_2_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read())) {
        c_2_address0 =  (sc_lv<3>) (tmp_20_fu_1903_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read()))) {
        c_2_address0 =  (sc_lv<3>) (tmp_39_fu_2015_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_39.read()))) {
        c_2_address0 =  (sc_lv<3>) (tmp_22_fu_1941_p1.read());
    } else {
        c_2_address0 = "XXX";
    }
}

void DOT_Full_Algorithm_accel::thread_c_2_ce0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read()) && 
          !ap_sig_bdd_2825.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_39.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        c_2_ce0 = ap_const_logic_1;
    } else {
        c_2_ce0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_c_2_d0() {
    c_2_d0 = ret_1_fu_1913_p1.read();
}

void DOT_Full_Algorithm_accel::thread_c_2_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten1_fu_1863_p2.read()) && 
          !ap_sig_bdd_2825.read() && 
          esl_seteq<1,3,3>(ap_const_lv3_2, j4_0_i_mid2_fu_1881_p3.read())))) {
        c_2_we0 = ap_const_logic_1;
    } else {
        c_2_we0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_c_3_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read())) {
        c_3_address0 =  (sc_lv<3>) (tmp_20_fu_1903_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read()))) {
        c_3_address0 =  (sc_lv<3>) (tmp_39_fu_2015_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_39.read()))) {
        c_3_address0 =  (sc_lv<3>) (tmp_22_fu_1941_p1.read());
    } else {
        c_3_address0 = "XXX";
    }
}

void DOT_Full_Algorithm_accel::thread_c_3_ce0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read()) && 
          !ap_sig_bdd_2825.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_39.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        c_3_ce0 = ap_const_logic_1;
    } else {
        c_3_ce0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_c_3_d0() {
    c_3_d0 = ret_1_fu_1913_p1.read();
}

void DOT_Full_Algorithm_accel::thread_c_3_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten1_fu_1863_p2.read()) && 
          !ap_sig_bdd_2825.read() && 
          esl_seteq<1,3,3>(ap_const_lv3_3, j4_0_i_mid2_fu_1881_p3.read())))) {
        c_3_we0 = ap_const_logic_1;
    } else {
        c_3_we0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_c_4_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read())) {
        c_4_address0 =  (sc_lv<3>) (tmp_20_fu_1903_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read()))) {
        c_4_address0 =  (sc_lv<3>) (tmp_39_fu_2015_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it5.read())) {
        c_4_address0 =  (sc_lv<3>) (ap_reg_ppstg_tmp_22_reg_2357_pp4_it4.read());
    } else {
        c_4_address0 = "XXX";
    }
}

void DOT_Full_Algorithm_accel::thread_c_4_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it5.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read()) && 
          !ap_sig_bdd_2825.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        c_4_ce0 = ap_const_logic_1;
    } else {
        c_4_ce0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_c_4_d0() {
    c_4_d0 = ret_1_fu_1913_p1.read();
}

void DOT_Full_Algorithm_accel::thread_c_4_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten1_fu_1863_p2.read()) && 
          !ap_sig_bdd_2825.read() && 
          esl_seteq<1,3,3>(ap_const_lv3_4, j4_0_i_mid2_fu_1881_p3.read())))) {
        c_4_we0 = ap_const_logic_1;
    } else {
        c_4_we0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_c_5_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read())) {
        c_5_address0 =  (sc_lv<3>) (tmp_20_fu_1903_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read()))) {
        c_5_address0 =  (sc_lv<3>) (tmp_39_fu_2015_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it5.read())) {
        c_5_address0 =  (sc_lv<3>) (ap_reg_ppstg_tmp_22_reg_2357_pp4_it4.read());
    } else {
        c_5_address0 = "XXX";
    }
}

void DOT_Full_Algorithm_accel::thread_c_5_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it5.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read()) && 
          !ap_sig_bdd_2825.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        c_5_ce0 = ap_const_logic_1;
    } else {
        c_5_ce0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_c_5_d0() {
    c_5_d0 = ret_1_fu_1913_p1.read();
}

void DOT_Full_Algorithm_accel::thread_c_5_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st114_fsm_38.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten1_fu_1863_p2.read()) && 
          !ap_sig_bdd_2825.read() && 
          !esl_seteq<1,3,3>(ap_const_lv3_4, j4_0_i_mid2_fu_1881_p3.read()) && 
          !esl_seteq<1,3,3>(ap_const_lv3_3, j4_0_i_mid2_fu_1881_p3.read()) && 
          !esl_seteq<1,3,3>(ap_const_lv3_2, j4_0_i_mid2_fu_1881_p3.read()) && 
          !esl_seteq<1,3,3>(ap_const_lv3_1, j4_0_i_mid2_fu_1881_p3.read()) && 
          !esl_seteq<1,3,3>(ap_const_lv3_0, j4_0_i_mid2_fu_1881_p3.read())))) {
        c_5_we0 = ap_const_logic_1;
    } else {
        c_5_we0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_exitcond1_i_fu_2003_p2() {
    exitcond1_i_fu_2003_p2 = (!w10_0_i_reg_833.read().is_01() || !ap_const_lv2_2.is_01())? sc_lv<1>(): sc_lv<1>(w10_0_i_reg_833.read() == ap_const_lv2_2);
}

void DOT_Full_Algorithm_accel::thread_exitcond4_i_fu_1929_p2() {
    exitcond4_i_fu_1929_p2 = (!w6_0_i_reg_775.read().is_01() || !ap_const_lv3_6.is_01())? sc_lv<1>(): sc_lv<1>(w6_0_i_reg_775.read() == ap_const_lv3_6);
}

void DOT_Full_Algorithm_accel::thread_exitcond5_i_fu_1875_p2() {
    exitcond5_i_fu_1875_p2 = (!j4_0_i_reg_764.read().is_01() || !ap_const_lv3_6.is_01())? sc_lv<1>(): sc_lv<1>(j4_0_i_reg_764.read() == ap_const_lv3_6);
}

void DOT_Full_Algorithm_accel::thread_exitcond7_i_fu_1799_p2() {
    exitcond7_i_fu_1799_p2 = (!w_0_i_reg_719.read().is_01() || !ap_const_lv3_6.is_01())? sc_lv<1>(): sc_lv<1>(w_0_i_reg_719.read() == ap_const_lv3_6);
}

void DOT_Full_Algorithm_accel::thread_exitcond8_i_fu_1593_p2() {
    exitcond8_i_fu_1593_p2 = (!j1_0_i_reg_708.read().is_01() || !ap_const_lv3_6.is_01())? sc_lv<1>(): sc_lv<1>(j1_0_i_reg_708.read() == ap_const_lv3_6);
}

void DOT_Full_Algorithm_accel::thread_exitcond9_i_fu_1539_p2() {
    exitcond9_i_fu_1539_p2 = (!j_0_i_reg_625.read().is_01() || !ap_const_lv3_6.is_01())? sc_lv<1>(): sc_lv<1>(j_0_i_reg_625.read() == ap_const_lv3_6);
}

void DOT_Full_Algorithm_accel::thread_exitcond_flatten1_fu_1863_p2() {
    exitcond_flatten1_fu_1863_p2 = (!indvar_flatten1_reg_742.read().is_01() || !ap_const_lv6_24.is_01())? sc_lv<1>(): sc_lv<1>(indvar_flatten1_reg_742.read() == ap_const_lv6_24);
}

void DOT_Full_Algorithm_accel::thread_exitcond_flatten2_fu_1991_p2() {
    exitcond_flatten2_fu_1991_p2 = (!indvar_flatten2_reg_798.read().is_01() || !ap_const_lv4_C.is_01())? sc_lv<1>(): sc_lv<1>(indvar_flatten2_reg_798.read() == ap_const_lv4_C);
}

void DOT_Full_Algorithm_accel::thread_exitcond_flatten_fu_1527_p2() {
    exitcond_flatten_fu_1527_p2 = (!indvar_flatten_reg_603.read().is_01() || !ap_const_lv6_24.is_01())? sc_lv<1>(): sc_lv<1>(indvar_flatten_reg_603.read() == ap_const_lv6_24);
}

void DOT_Full_Algorithm_accel::thread_exitcond_i_fu_2085_p2() {
    exitcond_i_fu_2085_p2 = (!k11_0_i_reg_855.read().is_01() || !ap_const_lv2_2.is_01())? sc_lv<1>(): sc_lv<1>(k11_0_i_reg_855.read() == ap_const_lv2_2);
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1002_ce() {
    grp_fu_1002_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1002_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it30.read())) {
        grp_fu_1002_p0 = ap_reg_ppstg_reg_1200_pp6_it29.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it30.read())) {
        grp_fu_1002_p0 = ap_reg_ppstg_reg_1200_pp4_it29.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it30.read())) {
        grp_fu_1002_p0 = ap_reg_ppstg_reg_1200_pp2_it29.read();
    } else {
        grp_fu_1002_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1002_p1() {
    grp_fu_1002_p1 = reg_1230.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1006_ce() {
    grp_fu_1006_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1006_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it30.read())) {
        grp_fu_1006_p0 = ap_reg_ppstg_reg_1215_pp6_it29.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it30.read())) {
        grp_fu_1006_p0 = ap_reg_ppstg_reg_1215_pp4_it29.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it30.read())) {
        grp_fu_1006_p0 = ap_reg_ppstg_reg_1215_pp2_it29.read();
    } else {
        grp_fu_1006_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1006_p1() {
    grp_fu_1006_p1 = reg_1230.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1010_ce() {
    grp_fu_1010_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1010_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it30.read())) {
        grp_fu_1010_p0 = ap_reg_ppstg_reg_1224_pp6_it29.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it30.read())) {
        grp_fu_1010_p0 = ap_reg_ppstg_reg_1224_pp4_it29.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it30.read())) {
        grp_fu_1010_p0 = ap_reg_ppstg_reg_1224_pp2_it29.read();
    } else {
        grp_fu_1010_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1010_p1() {
    grp_fu_1010_p1 = reg_1230.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1014_ce() {
    grp_fu_1014_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1014_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it34.read())) {
        grp_fu_1014_p0 = ap_reg_ppstg_reg_1230_pp6_it33.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it34.read())) {
        grp_fu_1014_p0 = ap_reg_ppstg_reg_1230_pp4_it33.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it34.read())) {
        grp_fu_1014_p0 = ap_reg_ppstg_reg_1230_pp2_it33.read();
    } else {
        grp_fu_1014_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1014_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it34.read())) {
        grp_fu_1014_p1 = ap_reg_ppstg_reg_1230_pp6_it33.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it34.read())) {
        grp_fu_1014_p1 = ap_reg_ppstg_reg_1230_pp4_it33.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it34.read())) {
        grp_fu_1014_p1 = ap_reg_ppstg_reg_1230_pp2_it33.read();
    } else {
        grp_fu_1014_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1018_ce() {
    grp_fu_1018_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1018_p0() {
    grp_fu_1018_p0 = reg_1247.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1018_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it34.read())) {
        grp_fu_1018_p1 = ap_reg_ppstg_reg_1230_pp6_it33.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it34.read())) {
        grp_fu_1018_p1 = ap_reg_ppstg_reg_1230_pp4_it33.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it34.read())) {
        grp_fu_1018_p1 = ap_reg_ppstg_reg_1230_pp2_it33.read();
    } else {
        grp_fu_1018_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1022_ce() {
    grp_fu_1022_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1022_p0() {
    grp_fu_1022_p0 = reg_1253.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1022_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it34.read())) {
        grp_fu_1022_p1 = ap_reg_ppstg_reg_1230_pp6_it33.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it34.read())) {
        grp_fu_1022_p1 = ap_reg_ppstg_reg_1230_pp4_it33.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it34.read())) {
        grp_fu_1022_p1 = ap_reg_ppstg_reg_1230_pp2_it33.read();
    } else {
        grp_fu_1022_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1026_ce() {
    grp_fu_1026_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1026_p0() {
    grp_fu_1026_p0 = reg_1259.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1026_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it34.read())) {
        grp_fu_1026_p1 = ap_reg_ppstg_reg_1230_pp6_it33.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it34.read())) {
        grp_fu_1026_p1 = ap_reg_ppstg_reg_1230_pp4_it33.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it34.read())) {
        grp_fu_1026_p1 = ap_reg_ppstg_reg_1230_pp2_it33.read();
    } else {
        grp_fu_1026_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1030_ce() {
    grp_fu_1030_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1030_p0() {
    grp_fu_1030_p0 = reg_1265.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1030_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it38.read())) {
        grp_fu_1030_p1 = ap_reg_ppstg_reg_1230_pp6_it37.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it38.read())) {
        grp_fu_1030_p1 = ap_reg_ppstg_reg_1230_pp4_it37.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it38.read())) {
        grp_fu_1030_p1 = ap_reg_ppstg_reg_1230_pp2_it37.read();
    } else {
        grp_fu_1030_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1034_ce() {
    grp_fu_1034_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1034_p0() {
    grp_fu_1034_p0 = reg_1271.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1034_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it38.read())) {
        grp_fu_1034_p1 = ap_reg_ppstg_reg_1230_pp6_it37.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it38.read())) {
        grp_fu_1034_p1 = ap_reg_ppstg_reg_1230_pp4_it37.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it38.read())) {
        grp_fu_1034_p1 = ap_reg_ppstg_reg_1230_pp2_it37.read();
    } else {
        grp_fu_1034_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1038_ce() {
    grp_fu_1038_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1038_p0() {
    grp_fu_1038_p0 = reg_1277.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1038_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it38.read())) {
        grp_fu_1038_p1 = ap_reg_ppstg_reg_1230_pp6_it37.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it38.read())) {
        grp_fu_1038_p1 = ap_reg_ppstg_reg_1230_pp4_it37.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it38.read())) {
        grp_fu_1038_p1 = ap_reg_ppstg_reg_1230_pp2_it37.read();
    } else {
        grp_fu_1038_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1042_ce() {
    grp_fu_1042_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1042_p0() {
    grp_fu_1042_p0 = reg_1283.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1042_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it38.read())) {
        grp_fu_1042_p1 = ap_reg_ppstg_reg_1230_pp6_it37.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it38.read())) {
        grp_fu_1042_p1 = ap_reg_ppstg_reg_1230_pp4_it37.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it38.read())) {
        grp_fu_1042_p1 = ap_reg_ppstg_reg_1230_pp2_it37.read();
    } else {
        grp_fu_1042_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1046_ce() {
    grp_fu_1046_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1046_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it41.read())) {
        grp_fu_1046_p0 = ap_reg_ppstg_reg_1215_pp6_it40.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it41.read())) {
        grp_fu_1046_p0 = ap_reg_ppstg_reg_1215_pp4_it40.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it41.read())) {
        grp_fu_1046_p0 = ap_reg_ppstg_reg_1215_pp2_it40.read();
    } else {
        grp_fu_1046_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1046_p1() {
    grp_fu_1046_p1 = ap_const_lv32_3F000000;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1057_ce() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st113_fsm_37.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_39.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp7_stg0_fsm_47.read()) && 
          !(esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_exitcond_i_reg_2466_pp7_it14.read()) && esl_seteq<1,1,1>(ap_const_logic_0, ap_sig_ioackin_OUTPUT_STREAM_TREADY.read()) && esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp7_it15.read()))) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st98_fsm_22.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st99_fsm_23.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st100_fsm_24.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st101_fsm_25.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st102_fsm_26.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st103_fsm_27.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st104_fsm_28.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st105_fsm_29.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st106_fsm_30.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st107_fsm_31.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st108_fsm_32.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st109_fsm_33.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st110_fsm_34.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st111_fsm_35.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st112_fsm_36.read()))) {
        grp_fu_1057_ce = ap_const_logic_1;
    } else {
        grp_fu_1057_ce = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1057_p0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp7_stg0_fsm_47.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp7_it0.read()))) {
        grp_fu_1057_p0 = v_assign_load_phi_v_fu_2107_p3.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st98_fsm_22.read())) {
        grp_fu_1057_p0 = in_load_5_reg_2270.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it29.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it29.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it29.read()))) {
        grp_fu_1057_p0 = reg_1224.read();
    } else {
        grp_fu_1057_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1057_p1() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp7_stg0_fsm_47.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp7_it0.read())) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st98_fsm_22.read()))) {
        grp_fu_1057_p1 = reg_1166.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it29.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it29.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it29.read()))) {
        grp_fu_1057_p1 = ap_const_lv32_40C00000;
    } else {
        grp_fu_1057_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1062_ce() {
    grp_fu_1062_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1062_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it34.read())) {
        grp_fu_1062_p0 = ap_reg_ppstg_reg_1230_pp6_it33.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it34.read())) {
        grp_fu_1062_p0 = ap_reg_ppstg_reg_1230_pp4_it33.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st98_fsm_22.read())) {
        grp_fu_1062_p0 = in_load_reg_2276.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it34.read())) {
        grp_fu_1062_p0 = ap_reg_ppstg_reg_1230_pp2_it33.read();
    } else {
        grp_fu_1062_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1062_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st98_fsm_22.read())) {
        grp_fu_1062_p1 = reg_1166.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it34.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it34.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it34.read()))) {
        grp_fu_1062_p1 = ap_const_lv32_41C00000;
    } else {
        grp_fu_1062_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1067_ce() {
    grp_fu_1067_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1067_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st98_fsm_22.read())) {
        grp_fu_1067_p0 = in_load_1_reg_2292.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it34.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it34.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it34.read()))) {
        grp_fu_1067_p0 = reg_1247.read();
    } else {
        grp_fu_1067_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1067_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st98_fsm_22.read())) {
        grp_fu_1067_p1 = reg_1166.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it34.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it34.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it34.read()))) {
        grp_fu_1067_p1 = ap_const_lv32_42F00000;
    } else {
        grp_fu_1067_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1072_ce() {
    grp_fu_1072_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1072_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st98_fsm_22.read())) {
        grp_fu_1072_p0 = in_load_2_reg_2298.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it34.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it34.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it34.read()))) {
        grp_fu_1072_p0 = reg_1253.read();
    } else {
        grp_fu_1072_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1072_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st98_fsm_22.read())) {
        grp_fu_1072_p1 = reg_1166.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it34.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it34.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it34.read()))) {
        grp_fu_1072_p1 = ap_const_lv32_44340000;
    } else {
        grp_fu_1072_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1077_ce() {
    grp_fu_1077_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1077_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st98_fsm_22.read())) {
        grp_fu_1077_p0 = in_load_3_reg_2314.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it34.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it34.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it34.read()))) {
        grp_fu_1077_p0 = reg_1259.read();
    } else {
        grp_fu_1077_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1077_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st98_fsm_22.read())) {
        grp_fu_1077_p1 = reg_1166.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it34.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it34.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it34.read()))) {
        grp_fu_1077_p1 = ap_const_lv32_459D8000;
    } else {
        grp_fu_1077_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1082_ce() {
    grp_fu_1082_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1082_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st98_fsm_22.read())) {
        grp_fu_1082_p0 = in_load_4_reg_2320.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it38.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it38.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it38.read()))) {
        grp_fu_1082_p0 = reg_1265.read();
    } else {
        grp_fu_1082_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1082_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st98_fsm_22.read())) {
        grp_fu_1082_p1 = reg_1166.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it38.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it38.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it38.read()))) {
        grp_fu_1082_p1 = ap_const_lv32_471D8000;
    } else {
        grp_fu_1082_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1087_ce() {
    grp_fu_1087_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1087_p0() {
    grp_fu_1087_p0 = reg_1271.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1087_p1() {
    grp_fu_1087_p1 = ap_const_lv32_48B13000;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1092_ce() {
    grp_fu_1092_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1092_p0() {
    grp_fu_1092_p0 = reg_1277.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1092_p1() {
    grp_fu_1092_p1 = ap_const_lv32_4A5D7C00;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1097_ce() {
    grp_fu_1097_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1097_p0() {
    grp_fu_1097_p0 = reg_1283.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1097_p1() {
    grp_fu_1097_p1 = ap_const_lv32_4C184540;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1102_ce() {
    grp_fu_1102_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1102_p0() {
    grp_fu_1102_p0 = reg_1289.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1102_p1() {
    grp_fu_1102_p1 = ap_const_lv32_4DE467E0;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1107_ce() {
    grp_fu_1107_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1107_p0() {
    grp_fu_1107_p0 = reg_1294.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1107_p1() {
    grp_fu_1107_p1 = ap_const_lv32_4FB99466;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1112_ce() {
    grp_fu_1112_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1112_p0() {
    grp_fu_1112_p0 = reg_1299.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1112_p1() {
    grp_fu_1112_p1 = ap_const_lv32_51A261D9;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1117_ce() {
    grp_fu_1117_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1117_p0() {
    grp_fu_1117_p0 = reg_1304.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1117_p1() {
    grp_fu_1117_p1 = ap_const_lv32_53983BBB;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1122_p0() {
    grp_fu_1122_p0 = reg_1200.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1125_opcode() {
    grp_fu_1125_opcode = ap_const_lv5_5;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1125_p0() {
    grp_fu_1125_p0 = reg_1210.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_1125_p1() {
    grp_fu_1125_p1 = ap_const_lv64_C01425729B280F13;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_866_ce() {
    grp_fu_866_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_866_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st268_fsm_42.read())) {
        grp_fu_866_p0 = by2in_0_s_reg_821.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st93_fsm_17.read())) {
        grp_fu_866_p0 = reg_1180.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st88_fsm_12.read())) {
        grp_fu_866_p0 = in_load_3_reg_2314.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st83_fsm_7.read())) {
        grp_fu_866_p0 = in_load_5_reg_2270.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it5.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it5.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it5.read()))) {
        grp_fu_866_p0 = reg_1134.read();
    } else {
        grp_fu_866_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_866_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st268_fsm_42.read())) {
        grp_fu_866_p1 = by2in_1_s_reg_809.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st93_fsm_17.read())) {
        grp_fu_866_p1 = reg_1166.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st88_fsm_12.read())) {
        grp_fu_866_p1 = in_load_4_reg_2320.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st83_fsm_7.read())) {
        grp_fu_866_p1 = in_load_reg_2276.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it5.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it5.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it5.read()))) {
        grp_fu_866_p1 = reg_1139.read();
    } else {
        grp_fu_866_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_870_ce() {
    grp_fu_870_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_870_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st88_fsm_12.read())) {
        grp_fu_870_p0 = reg_1166.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st83_fsm_7.read())) {
        grp_fu_870_p0 = in_load_1_reg_2292.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it5.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it5.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it5.read()))) {
        grp_fu_870_p0 = reg_1144.read();
    } else {
        grp_fu_870_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_870_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st88_fsm_12.read())) {
        grp_fu_870_p1 = reg_1180.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st83_fsm_7.read())) {
        grp_fu_870_p1 = in_load_2_reg_2298.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it5.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it5.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it5.read()))) {
        grp_fu_870_p1 = reg_1149.read();
    } else {
        grp_fu_870_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_874_ce() {
    grp_fu_874_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_874_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it10.read())) {
        grp_fu_874_p0 = reg_1166.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it5.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it5.read()))) {
        grp_fu_874_p0 = reg_1154.read();
    } else {
        grp_fu_874_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_874_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it10.read())) {
        grp_fu_874_p1 = reg_1180.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it5.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it5.read()))) {
        grp_fu_874_p1 = reg_1160.read();
    } else {
        grp_fu_874_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_878_ce() {
    grp_fu_878_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_878_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it10.read())) {
        grp_fu_878_p0 = reg_1154.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it10.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it10.read()))) {
        grp_fu_878_p0 = reg_1166.read();
    } else {
        grp_fu_878_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_878_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it10.read())) {
        grp_fu_878_p1 = reg_1160.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it10.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it10.read()))) {
        grp_fu_878_p1 = reg_1180.read();
    } else {
        grp_fu_878_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_882_ce() {
    grp_fu_882_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_882_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it15.read())) {
        grp_fu_882_p0 = reg_1188.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it15.read()) || 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it15.read()))) {
        grp_fu_882_p0 = reg_1194.read();
    } else {
        grp_fu_882_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_882_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it15.read())) {
        grp_fu_882_p1 = ap_reg_ppstg_reg_1188_pp6_it14.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it15.read())) {
        grp_fu_882_p1 = reg_1194.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it15.read())) {
        grp_fu_882_p1 = ap_reg_ppstg_reg_1188_pp2_it14.read();
    } else {
        grp_fu_882_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_886_ce() {
    grp_fu_886_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_886_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it45.read())) {
        grp_fu_886_p0 = ap_reg_ppstg_reg_1200_pp6_it44.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it45.read())) {
        grp_fu_886_p0 = ap_reg_ppstg_reg_1200_pp4_it44.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it45.read())) {
        grp_fu_886_p0 = ap_reg_ppstg_reg_1200_pp2_it44.read();
    } else {
        grp_fu_886_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_886_p1() {
    grp_fu_886_p1 = ap_const_lv32_3F800000;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_891_ce() {
    grp_fu_891_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_891_p0() {
    grp_fu_891_p0 = reg_1309.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_891_p1() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it45.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it45.read()))) {
        grp_fu_891_p1 = reg_1497.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it45.read())) {
        grp_fu_891_p1 = reg_1314.read();
    } else {
        grp_fu_891_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_895_ce() {
    grp_fu_895_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_895_p0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it50.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it50.read()))) {
        grp_fu_895_p0 = reg_1502.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it50.read())) {
        grp_fu_895_p0 = reg_1325.read();
    } else {
        grp_fu_895_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_895_p1() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it50.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it50.read()))) {
        grp_fu_895_p1 = reg_1507.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it50.read())) {
        grp_fu_895_p1 = reg_1331.read();
    } else {
        grp_fu_895_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_899_ce() {
    grp_fu_899_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_899_p0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it50.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it50.read()))) {
        grp_fu_899_p0 = reg_1512.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it50.read())) {
        grp_fu_899_p0 = reg_1337.read();
    } else {
        grp_fu_899_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_899_p1() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it50.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it50.read()))) {
        grp_fu_899_p1 = reg_1517.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it50.read())) {
        grp_fu_899_p1 = reg_1343.read();
    } else {
        grp_fu_899_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_903_ce() {
    grp_fu_903_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_903_p0() {
    grp_fu_903_p0 = reg_1320.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_903_p1() {
    grp_fu_903_p1 = reg_1349.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_907_ce() {
    grp_fu_907_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_907_p0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it54.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it54.read()))) {
        grp_fu_907_p0 = reg_1522.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it54.read())) {
        grp_fu_907_p0 = reg_1354.read();
    } else {
        grp_fu_907_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_907_p1() {
    grp_fu_907_p1 = reg_1360.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_911_ce() {
    grp_fu_911_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_911_p0() {
    grp_fu_911_p0 = reg_1365.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_911_p1() {
    grp_fu_911_p1 = reg_1370.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_915_ce() {
    grp_fu_915_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_915_p0() {
    grp_fu_915_p0 = reg_1385.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_915_p1() {
    grp_fu_915_p1 = ap_const_lv32_0;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_920_ce() {
    grp_fu_920_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_920_p0() {
    grp_fu_920_p0 = reg_1375.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_920_p1() {
    grp_fu_920_p1 = reg_1380.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_924_ce() {
    grp_fu_924_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_924_p0() {
    grp_fu_924_p0 = reg_1390.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_924_p1() {
    grp_fu_924_p1 = reg_1395.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_928_ce() {
    grp_fu_928_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_928_p0() {
    grp_fu_928_p0 = reg_1400.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_928_p1() {
    grp_fu_928_p1 = reg_1405.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_932_ce() {
    grp_fu_932_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_932_p0() {
    grp_fu_932_p0 = reg_1410.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_932_p1() {
    grp_fu_932_p1 = reg_1415.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_936_ce() {
    grp_fu_936_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_936_p0() {
    grp_fu_936_p0 = reg_1420.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_936_p1() {
    grp_fu_936_p1 = reg_1425.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_940_ce() {
    grp_fu_940_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_940_p0() {
    grp_fu_940_p0 = reg_1430.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_940_p1() {
    grp_fu_940_p1 = reg_1435.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_944_ce() {
    grp_fu_944_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_944_p0() {
    grp_fu_944_p0 = reg_1445.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_944_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it65.read())) {
        grp_fu_944_p1 = ap_reg_ppstg_reg_1440_pp6_it64.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it65.read())) {
        grp_fu_944_p1 = ap_reg_ppstg_reg_1440_pp4_it64.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it65.read())) {
        grp_fu_944_p1 = ap_reg_ppstg_reg_1440_pp2_it64.read();
    } else {
        grp_fu_944_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_948_ce() {
    grp_fu_948_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_948_p0() {
    grp_fu_948_p0 = reg_1455.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_948_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it70.read())) {
        grp_fu_948_p1 = ap_reg_ppstg_reg_1450_pp6_it69.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it70.read())) {
        grp_fu_948_p1 = ap_reg_ppstg_reg_1450_pp4_it69.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it70.read())) {
        grp_fu_948_p1 = ap_reg_ppstg_reg_1450_pp2_it69.read();
    } else {
        grp_fu_948_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_954_ce() {
    grp_fu_954_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_954_p0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_39.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        grp_fu_954_p0 = c_0_q0.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        grp_fu_954_p0 = a_0_q0.read();
    } else {
        grp_fu_954_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_954_p1() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_39.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        grp_fu_954_p1 = reg_1314.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        grp_fu_954_p1 = b_5_19_reg_696.read();
    } else {
        grp_fu_954_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_960_ce() {
    grp_fu_960_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_960_p0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_39.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        grp_fu_960_p0 = c_1_q0.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        grp_fu_960_p0 = a_1_q0.read();
    } else {
        grp_fu_960_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_960_p1() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_39.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        grp_fu_960_p1 = reg_1325.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        grp_fu_960_p1 = b_5_15_reg_684.read();
    } else {
        grp_fu_960_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_966_ce() {
    grp_fu_966_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_966_p0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_39.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        grp_fu_966_p0 = c_2_q0.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        grp_fu_966_p0 = a_2_q0.read();
    } else {
        grp_fu_966_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_966_p1() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_39.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        grp_fu_966_p1 = reg_1331.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        grp_fu_966_p1 = b_5_10_reg_672.read();
    } else {
        grp_fu_966_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_972_ce() {
    grp_fu_972_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_972_p0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_39.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        grp_fu_972_p0 = c_3_q0.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        grp_fu_972_p0 = a_3_q0.read();
    } else {
        grp_fu_972_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_972_p1() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp4_stg0_fsm_39.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        grp_fu_972_p1 = reg_1337.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        grp_fu_972_p1 = b_5_21_reg_660.read();
    } else {
        grp_fu_972_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_978_ce() {
    grp_fu_978_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_978_p0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it6.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        grp_fu_978_p0 = c_4_q0.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        grp_fu_978_p0 = a_4_q0.read();
    } else {
        grp_fu_978_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_978_p1() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it6.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        grp_fu_978_p1 = reg_1343.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        grp_fu_978_p1 = b_4_s_reg_648.read();
    } else {
        grp_fu_978_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_984_ce() {
    grp_fu_984_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_984_p0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it6.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        grp_fu_984_p0 = c_5_q0.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        grp_fu_984_p0 = a_5_q0.read();
    } else {
        grp_fu_984_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_984_p1() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it6.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp6_stg0_fsm_41.read())))) {
        grp_fu_984_p1 = reg_1354.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_pp2_stg0_fsm_3.read()))) {
        grp_fu_984_p1 = b_5_s_reg_636.read();
    } else {
        grp_fu_984_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_990_ce() {
    grp_fu_990_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_990_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it21.read())) {
        grp_fu_990_p0 = ap_reg_ppstg_reg_1200_pp6_it20.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it21.read())) {
        grp_fu_990_p0 = ap_reg_ppstg_reg_1200_pp4_it20.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it21.read())) {
        grp_fu_990_p0 = ap_reg_ppstg_reg_1200_pp2_it20.read();
    } else {
        grp_fu_990_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_990_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it21.read())) {
        grp_fu_990_p1 = ap_reg_ppstg_reg_1200_pp6_it20.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it21.read())) {
        grp_fu_990_p1 = ap_reg_ppstg_reg_1200_pp4_it20.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it21.read())) {
        grp_fu_990_p1 = ap_reg_ppstg_reg_1200_pp2_it20.read();
    } else {
        grp_fu_990_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_994_ce() {
    grp_fu_994_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_994_p0() {
    grp_fu_994_p0 = reg_1215.read();
}

void DOT_Full_Algorithm_accel::thread_grp_fu_994_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it25.read())) {
        grp_fu_994_p1 = ap_reg_ppstg_reg_1200_pp6_it24.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it25.read())) {
        grp_fu_994_p1 = ap_reg_ppstg_reg_1200_pp4_it24.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it25.read())) {
        grp_fu_994_p1 = ap_reg_ppstg_reg_1200_pp2_it24.read();
    } else {
        grp_fu_994_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_998_ce() {
    grp_fu_998_ce = ap_const_logic_1;
}

void DOT_Full_Algorithm_accel::thread_grp_fu_998_p0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it26.read())) {
        grp_fu_998_p0 = ap_reg_ppstg_reg_1215_pp6_it25.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it26.read())) {
        grp_fu_998_p0 = ap_reg_ppstg_reg_1215_pp4_it25.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it26.read())) {
        grp_fu_998_p0 = ap_reg_ppstg_reg_1215_pp2_it25.read();
    } else {
        grp_fu_998_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_grp_fu_998_p1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp6_it26.read())) {
        grp_fu_998_p1 = ap_reg_ppstg_reg_1215_pp6_it25.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it26.read())) {
        grp_fu_998_p1 = ap_reg_ppstg_reg_1215_pp4_it25.read();
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it26.read())) {
        grp_fu_998_p1 = ap_reg_ppstg_reg_1215_pp2_it25.read();
    } else {
        grp_fu_998_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void DOT_Full_Algorithm_accel::thread_i3_0_i_mid2_fu_1895_p3() {
    i3_0_i_mid2_fu_1895_p3 = (!exitcond5_i_fu_1875_p2.read()[0].is_01())? sc_lv<3>(): ((exitcond5_i_fu_1875_p2.read()[0].to_bool())? i_s_fu_1889_p2.read(): i3_0_i_reg_753.read());
}

void DOT_Full_Algorithm_accel::thread_i_0_i_mid2_fu_1559_p3() {
    i_0_i_mid2_fu_1559_p3 = (!exitcond9_i_fu_1539_p2.read()[0].is_01())? sc_lv<3>(): ((exitcond9_i_fu_1539_p2.read()[0].to_bool())? i_fu_1553_p2.read(): i_0_i_reg_614.read());
}

void DOT_Full_Algorithm_accel::thread_i_fu_1553_p2() {
    i_fu_1553_p2 = (!i_0_i_reg_614.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<3>(): (sc_biguint<3>(i_0_i_reg_614.read()) + sc_biguint<3>(ap_const_lv3_1));
}

void DOT_Full_Algorithm_accel::thread_i_s_fu_1889_p2() {
    i_s_fu_1889_p2 = (!i3_0_i_reg_753.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<3>(): (sc_biguint<3>(i3_0_i_reg_753.read()) + sc_biguint<3>(ap_const_lv3_1));
}

void DOT_Full_Algorithm_accel::thread_in_address0() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it75.read())) {
        in_address0 =  (sc_lv<3>) (ap_reg_ppstg_tmp_s_reg_2191_pp2_it74.read());
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st86_fsm_10.read())) {
        in_address0 =  (sc_lv<3>) (ap_const_lv64_5);
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st81_fsm_5.read())) {
        in_address0 =  (sc_lv<3>) (ap_const_lv64_3);
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st80_fsm_4.read())) {
        in_address0 =  (sc_lv<3>) (ap_const_lv64_0);
    } else {
        in_address0 = "XXX";
    }
}

void DOT_Full_Algorithm_accel::thread_in_address1() {
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it75.read())) {
        in_address1 =  (sc_lv<3>) (ap_reg_ppstg_tmp_22_reg_2357_pp4_it74.read());
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st86_fsm_10.read())) {
        in_address1 =  (sc_lv<3>) (ap_const_lv64_4);
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st81_fsm_5.read())) {
        in_address1 =  (sc_lv<3>) (ap_const_lv64_2);
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st80_fsm_4.read())) {
        in_address1 =  (sc_lv<3>) (ap_const_lv64_1);
    } else {
        in_address1 = "XXX";
    }
}

void DOT_Full_Algorithm_accel::thread_in_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it75.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st80_fsm_4.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st81_fsm_5.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st86_fsm_10.read()))) {
        in_ce0 = ap_const_logic_1;
    } else {
        in_ce0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_in_ce1() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it75.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st80_fsm_4.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st81_fsm_5.read()) || 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_sig_cseq_ST_st86_fsm_10.read()))) {
        in_ce1 = ap_const_logic_1;
    } else {
        in_ce1 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_in_d0() {
    in_d0 = p_0_i100_i_phi_fu_734_p4.read();
}

void DOT_Full_Algorithm_accel::thread_in_d1() {
    in_d1 = p_0_i66_i_phi_fu_790_p4.read();
}

void DOT_Full_Algorithm_accel::thread_in_we0() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it75.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_exitcond7_i_reg_2182_pp2_it74.read())))) {
        in_we0 = ap_const_logic_1;
    } else {
        in_we0 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_in_we1() {
    if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it75.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_exitcond4_i_reg_2348_pp4_it74.read())))) {
        in_we1 = ap_const_logic_1;
    } else {
        in_we1 = ap_const_logic_0;
    }
}

void DOT_Full_Algorithm_accel::thread_indvar_flatten_next1_fu_1869_p2() {
    indvar_flatten_next1_fu_1869_p2 = (!indvar_flatten1_reg_742.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(indvar_flatten1_reg_742.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void DOT_Full_Algorithm_accel::thread_indvar_flatten_next2_fu_1997_p2() {
    indvar_flatten_next2_fu_1997_p2 = (!indvar_flatten2_reg_798.read().is_01() || !ap_const_lv4_1.is_01())? sc_lv<4>(): (sc_biguint<4>(indvar_flatten2_reg_798.read()) + sc_biguint<4>(ap_const_lv4_1));
}

void DOT_Full_Algorithm_accel::thread_indvar_flatten_next_fu_1533_p2() {
    indvar_flatten_next_fu_1533_p2 = (!indvar_flatten_reg_603.read().is_01() || !ap_const_lv6_1.is_01())? sc_lv<6>(): (sc_biguint<6>(indvar_flatten_reg_603.read()) + sc_biguint<6>(ap_const_lv6_1));
}

void DOT_Full_Algorithm_accel::thread_j4_0_i_mid2_fu_1881_p3() {
    j4_0_i_mid2_fu_1881_p3 = (!exitcond5_i_fu_1875_p2.read()[0].is_01())? sc_lv<3>(): ((exitcond5_i_fu_1875_p2.read()[0].to_bool())? ap_const_lv3_0: j4_0_i_reg_764.read());
}

void DOT_Full_Algorithm_accel::thread_j_0_i_mid2_fu_1545_p3() {
    j_0_i_mid2_fu_1545_p3 = (!exitcond9_i_fu_1539_p2.read()[0].is_01())? sc_lv<3>(): ((exitcond9_i_fu_1539_p2.read()[0].to_bool())? ap_const_lv3_0: j_0_i_reg_625.read());
}

void DOT_Full_Algorithm_accel::thread_j_1_fu_1587_p2() {
    j_1_fu_1587_p2 = (!j_0_i_mid2_fu_1545_p3.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<3>(): (sc_biguint<3>(j_0_i_mid2_fu_1545_p3.read()) + sc_biguint<3>(ap_const_lv3_1));
}

void DOT_Full_Algorithm_accel::thread_j_2_fu_1923_p2() {
    j_2_fu_1923_p2 = (!j4_0_i_mid2_fu_1881_p3.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<3>(): (sc_biguint<3>(j4_0_i_mid2_fu_1881_p3.read()) + sc_biguint<3>(ap_const_lv3_1));
}

void DOT_Full_Algorithm_accel::thread_j_fu_1599_p2() {
    j_fu_1599_p2 = (!j1_0_i_reg_708.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<3>(): (sc_biguint<3>(j1_0_i_reg_708.read()) + sc_biguint<3>(ap_const_lv3_1));
}

void DOT_Full_Algorithm_accel::thread_k_fu_2091_p2() {
    k_fu_2091_p2 = (!k11_0_i_reg_855.read().is_01() || !ap_const_lv2_1.is_01())? sc_lv<2>(): (sc_biguint<2>(k11_0_i_reg_855.read()) + sc_biguint<2>(ap_const_lv2_1));
}

void DOT_Full_Algorithm_accel::thread_last_assign_fu_2101_p2() {
    last_assign_fu_2101_p2 = (!k11_0_i_reg_855.read().is_01() || !ap_const_lv2_1.is_01())? sc_lv<1>(): sc_lv<1>(k11_0_i_reg_855.read() == ap_const_lv2_1);
}

void DOT_Full_Algorithm_accel::thread_notlhs1_fu_1967_p2() {
    notlhs1_fu_1967_p2 = (!tmp_57_fu_1953_p4.read().is_01() || !ap_const_lv11_7FF.is_01())? sc_lv<1>(): sc_lv<1>(tmp_57_fu_1953_p4.read() != ap_const_lv11_7FF);
}

void DOT_Full_Algorithm_accel::thread_notlhs2_fu_2047_p2() {
    notlhs2_fu_2047_p2 = (!tmp_62_fu_2033_p4.read().is_01() || !ap_const_lv11_7FF.is_01())? sc_lv<1>(): sc_lv<1>(tmp_62_fu_2033_p4.read() != ap_const_lv11_7FF);
}

void DOT_Full_Algorithm_accel::thread_notlhs_fu_1839_p2() {
    notlhs_fu_1839_p2 = (!tmp_fu_1825_p4.read().is_01() || !ap_const_lv11_7FF.is_01())? sc_lv<1>(): sc_lv<1>(tmp_fu_1825_p4.read() != ap_const_lv11_7FF);
}

void DOT_Full_Algorithm_accel::thread_notrhs1_fu_1973_p2() {
    notrhs1_fu_1973_p2 = (!tmp_58_fu_1963_p1.read().is_01() || !ap_const_lv52_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_58_fu_1963_p1.read() == ap_const_lv52_0);
}

void DOT_Full_Algorithm_accel::thread_notrhs2_fu_2053_p2() {
    notrhs2_fu_2053_p2 = (!tmp_63_fu_2043_p1.read().is_01() || !ap_const_lv52_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_63_fu_2043_p1.read() == ap_const_lv52_0);
}

void DOT_Full_Algorithm_accel::thread_notrhs_fu_1845_p2() {
    notrhs_fu_1845_p2 = (!tmp_12_fu_1835_p1.read().is_01() || !ap_const_lv52_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_12_fu_1835_p1.read() == ap_const_lv52_0);
}

void DOT_Full_Algorithm_accel::thread_p_0_i100_i_phi_fu_734_p4() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp2_it75.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_exitcond7_i_reg_2182_pp2_it74.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_56_reg_2256_pp2_it74.read()))) {
        p_0_i100_i_phi_fu_734_p4 = reg_1460.read();
    } else {
        p_0_i100_i_phi_fu_734_p4 = ap_reg_phiprechg_p_0_i100_i_reg_730pp2_it75.read();
    }
}

void DOT_Full_Algorithm_accel::thread_p_0_i66_i_phi_fu_790_p4() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_reg_ppiten_pp4_it75.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_exitcond4_i_reg_2348_pp4_it74.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, ap_reg_ppstg_tmp_61_reg_2394_pp4_it74.read()))) {
        p_0_i66_i_phi_fu_790_p4 = reg_1460.read();
    } else {
        p_0_i66_i_phi_fu_790_p4 = ap_reg_phiprechg_p_0_i66_i_reg_786pp4_it75.read();
    }
}

void DOT_Full_Algorithm_accel::thread_ret_1_fu_1913_p1() {
    ret_1_fu_1913_p1 = INPUT_STREAM_TDATA.read();
}

void DOT_Full_Algorithm_accel::thread_ret_fu_1577_p1() {
    ret_fu_1577_p1 = INPUT_STREAM_TDATA.read();
}

void DOT_Full_Algorithm_accel::thread_sel_tmp2_fu_1623_p2() {
    sel_tmp2_fu_1623_p2 = (!j1_0_i_reg_708.read().is_01() || !ap_const_lv3_3.is_01())? sc_lv<1>(): sc_lv<1>(j1_0_i_reg_708.read() == ap_const_lv3_3);
}

void DOT_Full_Algorithm_accel::thread_sel_tmp4_fu_1637_p2() {
    sel_tmp4_fu_1637_p2 = (!j1_0_i_reg_708.read().is_01() || !ap_const_lv3_2.is_01())? sc_lv<1>(): sc_lv<1>(j1_0_i_reg_708.read() == ap_const_lv3_2);
}

void DOT_Full_Algorithm_accel::thread_sel_tmp6_fu_1651_p2() {
    sel_tmp6_fu_1651_p2 = (!j1_0_i_reg_708.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<1>(): sc_lv<1>(j1_0_i_reg_708.read() == ap_const_lv3_1);
}

void DOT_Full_Algorithm_accel::thread_sel_tmp8_fu_1665_p2() {
    sel_tmp8_fu_1665_p2 = (!j1_0_i_reg_708.read().is_01() || !ap_const_lv3_0.is_01())? sc_lv<1>(): sc_lv<1>(j1_0_i_reg_708.read() == ap_const_lv3_0);
}

void DOT_Full_Algorithm_accel::thread_sel_tmp_fu_1609_p2() {
    sel_tmp_fu_1609_p2 = (!j1_0_i_reg_708.read().is_01() || !ap_const_lv3_4.is_01())? sc_lv<1>(): sc_lv<1>(j1_0_i_reg_708.read() == ap_const_lv3_4);
}

void DOT_Full_Algorithm_accel::thread_tmp_11_to_int_fu_1821_p1() {
    tmp_11_to_int_fu_1821_p1 = reg_1210.read();
}

void DOT_Full_Algorithm_accel::thread_tmp_12_fu_1835_p1() {
    tmp_12_fu_1835_p1 = tmp_11_to_int_fu_1821_p1.read().range(52-1, 0);
}

void DOT_Full_Algorithm_accel::thread_tmp_1_fu_1567_p1() {
    tmp_1_fu_1567_p1 = esl_zext<64,3>(i_0_i_mid2_fu_1559_p3.read());
}

void DOT_Full_Algorithm_accel::thread_tmp_20_fu_1903_p1() {
    tmp_20_fu_1903_p1 = esl_zext<64,3>(i3_0_i_mid2_fu_1895_p3.read());
}

void DOT_Full_Algorithm_accel::thread_tmp_22_fu_1941_p1() {
    tmp_22_fu_1941_p1 = esl_zext<64,3>(w6_0_i_reg_775.read());
}

void DOT_Full_Algorithm_accel::thread_tmp_28_to_int_fu_1949_p1() {
    tmp_28_to_int_fu_1949_p1 = reg_1210.read();
}

void DOT_Full_Algorithm_accel::thread_tmp_29_fu_1851_p2() {
    tmp_29_fu_1851_p2 = (notrhs_fu_1845_p2.read() | notlhs_fu_1839_p2.read());
}

void DOT_Full_Algorithm_accel::thread_tmp_39_fu_2015_p1() {
    tmp_39_fu_2015_p1 = esl_zext<64,2>(w10_0_i_reg_833.read());
}

void DOT_Full_Algorithm_accel::thread_tmp_45_to_int_fu_2029_p1() {
    tmp_45_to_int_fu_2029_p1 = reg_1210.read();
}

void DOT_Full_Algorithm_accel::thread_tmp_56_fu_1857_p2() {
    tmp_56_fu_1857_p2 = (tmp_29_fu_1851_p2.read() & grp_fu_1125_p2.read());
}

void DOT_Full_Algorithm_accel::thread_tmp_57_fu_1953_p4() {
    tmp_57_fu_1953_p4 = tmp_28_to_int_fu_1949_p1.read().range(62, 52);
}

void DOT_Full_Algorithm_accel::thread_tmp_58_fu_1963_p1() {
    tmp_58_fu_1963_p1 = tmp_28_to_int_fu_1949_p1.read().range(52-1, 0);
}

void DOT_Full_Algorithm_accel::thread_tmp_59_fu_1979_p2() {
    tmp_59_fu_1979_p2 = (notrhs1_fu_1973_p2.read() | notlhs1_fu_1967_p2.read());
}

void DOT_Full_Algorithm_accel::thread_tmp_61_fu_1985_p2() {
    tmp_61_fu_1985_p2 = (tmp_59_fu_1979_p2.read() & grp_fu_1125_p2.read());
}

void DOT_Full_Algorithm_accel::thread_tmp_62_fu_2033_p4() {
    tmp_62_fu_2033_p4 = tmp_45_to_int_fu_2029_p1.read().range(62, 52);
}

void DOT_Full_Algorithm_accel::thread_tmp_63_fu_2043_p1() {
    tmp_63_fu_2043_p1 = tmp_45_to_int_fu_2029_p1.read().range(52-1, 0);
}

void DOT_Full_Algorithm_accel::thread_tmp_64_fu_2059_p2() {
    tmp_64_fu_2059_p2 = (notrhs2_fu_2053_p2.read() | notlhs2_fu_2047_p2.read());
}

void DOT_Full_Algorithm_accel::thread_tmp_66_fu_2065_p2() {
    tmp_66_fu_2065_p2 = (tmp_64_fu_2059_p2.read() & grp_fu_1125_p2.read());
}

void DOT_Full_Algorithm_accel::thread_tmp_67_fu_2097_p1() {
    tmp_67_fu_2097_p1 = k11_0_i_reg_855.read().range(1-1, 0);
}

void DOT_Full_Algorithm_accel::thread_tmp_68_fu_2025_p1() {
    tmp_68_fu_2025_p1 = w10_0_i_reg_833.read().range(1-1, 0);
}

void DOT_Full_Algorithm_accel::thread_tmp_fu_1825_p4() {
    tmp_fu_1825_p4 = tmp_11_to_int_fu_1821_p1.read().range(62, 52);
}

void DOT_Full_Algorithm_accel::thread_tmp_s_fu_1811_p1() {
    tmp_s_fu_1811_p1 = esl_zext<64,3>(w_0_i_reg_719.read());
}

void DOT_Full_Algorithm_accel::thread_v_assign_load_phi_v_fu_2107_p3() {
    v_assign_load_phi_v_fu_2107_p3 = (!tmp_67_fu_2097_p1.read()[0].is_01())? sc_lv<32>(): ((tmp_67_fu_2097_p1.read()[0].to_bool())? by2in_1_s_reg_809.read(): by2in_0_s_reg_821.read());
}

void DOT_Full_Algorithm_accel::thread_w_1_fu_1935_p2() {
    w_1_fu_1935_p2 = (!w6_0_i_reg_775.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<3>(): (sc_biguint<3>(w6_0_i_reg_775.read()) + sc_biguint<3>(ap_const_lv3_1));
}

void DOT_Full_Algorithm_accel::thread_w_2_fu_2009_p2() {
    w_2_fu_2009_p2 = (!w10_0_i_reg_833.read().is_01() || !ap_const_lv2_1.is_01())? sc_lv<2>(): (sc_biguint<2>(w10_0_i_reg_833.read()) + sc_biguint<2>(ap_const_lv2_1));
}

void DOT_Full_Algorithm_accel::thread_w_fu_1805_p2() {
    w_fu_1805_p2 = (!w_0_i_reg_719.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<3>(): (sc_biguint<3>(w_0_i_reg_719.read()) + sc_biguint<3>(ap_const_lv3_1));
}

}

