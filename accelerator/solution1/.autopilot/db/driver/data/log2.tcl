# ==============================================================
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
# Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
# ==============================================================
proc generate {drv_handle} {
    xdefine_include_file $drv_handle "xparameters.h" "XLog2" \
        "NUM_INSTANCES" \
        "DEVICE_ID" \
        "C_S_AXI_AXILITES_BASEADDR" \
        "C_S_AXI_AXILITES_HIGHADDR"

    xdefine_config_file $drv_handle "xlog2_g.c" "XLog2" \
        "DEVICE_ID" \
        "C_S_AXI_AXILITES_BASEADDR"

    xdefine_canonical_xpars $drv_handle "xparameters.h" "XLog2" \
        "DEVICE_ID" \
        "C_S_AXI_AXILITES_BASEADDR" \
        "C_S_AXI_AXILITES_HIGHADDR"
}

