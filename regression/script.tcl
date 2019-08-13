############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 2015 Xilinx Inc. All rights reserved.
############################################################
open_project MATRIX_dot_exponential
set_top KBF_accel
add_files DOT_accel.cpp -cflags "-DOT_EXP_DEBUG"
add_files -tb DOT_test.cpp -cflags "-DOT_EXP_DEBUG"
add_files -tb MATRIX_dot_exponential/Matrix_exp_wth_soft.cpp
open_solution "solution21"
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
source "./MATRIX_dot_exponential/solution21/directives.tcl"
csim_design -argv {-Wall} -clean
csynth_design
cosim_design -argv {-Wall}
export_design -format ip_catalog
