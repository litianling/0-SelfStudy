############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project f_b_2
set_top forw_back_LTL
add_files f_b_2/forw_back_LTL_new.c
add_files -tb f_b_2/main.c
open_solution "solution1"
set_part {xczu3eg-sbva484-1-e} -tool vivado
create_clock -period 10 -name default
source "./f_b_2/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
