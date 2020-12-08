// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xl_log2.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XL_log2_CfgInitialize(XL_log2 *InstancePtr, XL_log2_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XL_log2_Start(XL_log2 *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XL_log2_ReadReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_AP_CTRL) & 0x80;
    XL_log2_WriteReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_AP_CTRL, Data | 0x01);
}

u32 XL_log2_IsDone(XL_log2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XL_log2_ReadReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XL_log2_IsIdle(XL_log2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XL_log2_ReadReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XL_log2_IsReady(XL_log2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XL_log2_ReadReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XL_log2_EnableAutoRestart(XL_log2 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XL_log2_WriteReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_AP_CTRL, 0x80);
}

void XL_log2_DisableAutoRestart(XL_log2 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XL_log2_WriteReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_AP_CTRL, 0);
}

void XL_log2_Set_x(XL_log2 *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XL_log2_WriteReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_X_DATA, Data);
}

u32 XL_log2_Get_x(XL_log2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XL_log2_ReadReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_X_DATA);
    return Data;
}

u32 XL_log2_Get_y(XL_log2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XL_log2_ReadReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_Y_DATA);
    return Data;
}

u32 XL_log2_Get_y_vld(XL_log2 *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XL_log2_ReadReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_Y_CTRL);
    return Data & 0x1;
}

void XL_log2_InterruptGlobalEnable(XL_log2 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XL_log2_WriteReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_GIE, 1);
}

void XL_log2_InterruptGlobalDisable(XL_log2 *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XL_log2_WriteReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_GIE, 0);
}

void XL_log2_InterruptEnable(XL_log2 *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XL_log2_ReadReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_IER);
    XL_log2_WriteReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_IER, Register | Mask);
}

void XL_log2_InterruptDisable(XL_log2 *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XL_log2_ReadReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_IER);
    XL_log2_WriteReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_IER, Register & (~Mask));
}

void XL_log2_InterruptClear(XL_log2 *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XL_log2_WriteReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_ISR, Mask);
}

u32 XL_log2_InterruptGetEnabled(XL_log2 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XL_log2_ReadReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_IER);
}

u32 XL_log2_InterruptGetStatus(XL_log2 *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XL_log2_ReadReg(InstancePtr->Axilites_BaseAddress, XL_LOG2_AXILITES_ADDR_ISR);
}

