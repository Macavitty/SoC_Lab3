// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// AXILiteS
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x10 : Data signal of x
//        bit 31~0 - x[31:0] (Read/Write)
// 0x14 : reserved
// 0x18 : Data signal of y
//        bit 31~0 - y[31:0] (Read)
// 0x1c : Control signal of y
//        bit 0  - y_ap_vld (Read/COR)
//        others - reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XL_LOG2_AXILITES_ADDR_AP_CTRL 0x00
#define XL_LOG2_AXILITES_ADDR_GIE     0x04
#define XL_LOG2_AXILITES_ADDR_IER     0x08
#define XL_LOG2_AXILITES_ADDR_ISR     0x0c
#define XL_LOG2_AXILITES_ADDR_X_DATA  0x10
#define XL_LOG2_AXILITES_BITS_X_DATA  32
#define XL_LOG2_AXILITES_ADDR_Y_DATA  0x18
#define XL_LOG2_AXILITES_BITS_Y_DATA  32
#define XL_LOG2_AXILITES_ADDR_Y_CTRL  0x1c

