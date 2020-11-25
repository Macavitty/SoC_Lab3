// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xlog2.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XLog2_CfgInitialize(XLog2 *InstancePtr, XLog2_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XLog2_Start(XLog2 *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLog2_ReadReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_AP_CTRL) & 0x80;
    XLog2_WriteReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_AP_CTRL, Data | 0x01);
}

u32 XLog2_IsDone(XLog2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLog2_ReadReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XLog2_IsIdle(XLog2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLog2_ReadReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XLog2_IsReady(XLog2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLog2_ReadReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XLog2_EnableAutoRestart(XLog2 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLog2_WriteReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_AP_CTRL, 0x80);
}

void XLog2_DisableAutoRestart(XLog2 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLog2_WriteReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_AP_CTRL, 0);
}

void XLog2_Set_x(XLog2 *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLog2_WriteReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_X_DATA, Data);
}

u32 XLog2_Get_x(XLog2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLog2_ReadReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_X_DATA);
    return Data;
}

u32 XLog2_Get_y(XLog2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLog2_ReadReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_Y_DATA);
    return Data;
}

u32 XLog2_Get_y_vld(XLog2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XLog2_ReadReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_Y_CTRL);
    return Data & 0x1;
}

void XLog2_InterruptGlobalEnable(XLog2 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLog2_WriteReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_GIE, 1);
}

void XLog2_InterruptGlobalDisable(XLog2 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLog2_WriteReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_GIE, 0);
}

void XLog2_InterruptEnable(XLog2 *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XLog2_ReadReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_IER);
    XLog2_WriteReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_IER, Register | Mask);
}

void XLog2_InterruptDisable(XLog2 *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XLog2_ReadReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_IER);
    XLog2_WriteReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_IER, Register & (~Mask));
}

void XLog2_InterruptClear(XLog2 *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XLog2_WriteReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_ISR, Mask);
}

u32 XLog2_InterruptGetEnabled(XLog2 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XLog2_ReadReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_IER);
}

u32 XLog2_InterruptGetStatus(XLog2 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XLog2_ReadReg(InstancePtr->Axilites_BaseAddress, XLOG2_AXILITES_ADDR_ISR);
}

