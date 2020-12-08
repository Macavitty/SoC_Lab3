
log_wave [get_objects -filter {type == in_port || type == out_port || type == inout_port || type == port} /apatb_l_log2_top/AESL_inst_l_log2/*]
set designtopgroup [add_wave_group "Design Top Signals"]
set cinoutgroup [add_wave_group "C InOuts" -into $designtopgroup]
set x__y__return_group [add_wave_group x__y__return(axi_slave) -into $cinoutgroup]
add_wave /apatb_l_log2_top/AESL_inst_l_log2/interrupt -into $x__y__return_group -color #ffff00 -radix hex
add_wave /apatb_l_log2_top/AESL_inst_l_log2/s_axi_AXILiteS_BRESP -into $x__y__return_group -radix hex
add_wave /apatb_l_log2_top/AESL_inst_l_log2/s_axi_AXILiteS_BREADY -into $x__y__return_group -color #ffff00 -radix hex
add_wave /apatb_l_log2_top/AESL_inst_l_log2/s_axi_AXILiteS_BVALID -into $x__y__return_group -color #ffff00 -radix hex
add_wave /apatb_l_log2_top/AESL_inst_l_log2/s_axi_AXILiteS_RRESP -into $x__y__return_group -radix hex
add_wave /apatb_l_log2_top/AESL_inst_l_log2/s_axi_AXILiteS_RDATA -into $x__y__return_group -radix hex
add_wave /apatb_l_log2_top/AESL_inst_l_log2/s_axi_AXILiteS_RREADY -into $x__y__return_group -color #ffff00 -radix hex
add_wave /apatb_l_log2_top/AESL_inst_l_log2/s_axi_AXILiteS_RVALID -into $x__y__return_group -color #ffff00 -radix hex
add_wave /apatb_l_log2_top/AESL_inst_l_log2/s_axi_AXILiteS_ARREADY -into $x__y__return_group -color #ffff00 -radix hex
add_wave /apatb_l_log2_top/AESL_inst_l_log2/s_axi_AXILiteS_ARVALID -into $x__y__return_group -color #ffff00 -radix hex
add_wave /apatb_l_log2_top/AESL_inst_l_log2/s_axi_AXILiteS_ARADDR -into $x__y__return_group -radix hex
add_wave /apatb_l_log2_top/AESL_inst_l_log2/s_axi_AXILiteS_WSTRB -into $x__y__return_group -radix hex
add_wave /apatb_l_log2_top/AESL_inst_l_log2/s_axi_AXILiteS_WDATA -into $x__y__return_group -radix hex
add_wave /apatb_l_log2_top/AESL_inst_l_log2/s_axi_AXILiteS_WREADY -into $x__y__return_group -color #ffff00 -radix hex
add_wave /apatb_l_log2_top/AESL_inst_l_log2/s_axi_AXILiteS_WVALID -into $x__y__return_group -color #ffff00 -radix hex
add_wave /apatb_l_log2_top/AESL_inst_l_log2/s_axi_AXILiteS_AWREADY -into $x__y__return_group -color #ffff00 -radix hex
add_wave /apatb_l_log2_top/AESL_inst_l_log2/s_axi_AXILiteS_AWVALID -into $x__y__return_group -color #ffff00 -radix hex
add_wave /apatb_l_log2_top/AESL_inst_l_log2/s_axi_AXILiteS_AWADDR -into $x__y__return_group -radix hex
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_l_log2_top/AESL_inst_l_log2/ap_rst_n -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_l_log2_top/AESL_inst_l_log2/ap_clk -into $clockgroup
save_wave_config l_log2.wcfg
run all
quit

