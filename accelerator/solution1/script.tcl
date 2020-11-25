############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project accelerator
set_top log2
add_files accelerator/log2.c
open_solution "solution1"
set_part {xc7a100t-csg324-1} -tool vivado
create_clock -period 10 -name default
config_export -display_name log2_ip -format ip_catalog -rtl verilog
#source "./accelerator/solution1/directives.tcl"
#csim_design
csynth_design
#cosim_design
export_design -rtl verilog -format ip_catalog -display_name "log2_ip"
