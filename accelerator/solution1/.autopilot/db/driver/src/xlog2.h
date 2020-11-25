// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XLOG2_H
#define XLOG2_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xlog2_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XLog2_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XLog2;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XLog2_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XLog2_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XLog2_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XLog2_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XLog2_Initialize(XLog2 *InstancePtr, u16 DeviceId);
XLog2_Config* XLog2_LookupConfig(u16 DeviceId);
int XLog2_CfgInitialize(XLog2 *InstancePtr, XLog2_Config *ConfigPtr);
#else
int XLog2_Initialize(XLog2 *InstancePtr, const char* InstanceName);
int XLog2_Release(XLog2 *InstancePtr);
#endif

void XLog2_Start(XLog2 *InstancePtr);
u32 XLog2_IsDone(XLog2 *InstancePtr);
u32 XLog2_IsIdle(XLog2 *InstancePtr);
u32 XLog2_IsReady(XLog2 *InstancePtr);
void XLog2_EnableAutoRestart(XLog2 *InstancePtr);
void XLog2_DisableAutoRestart(XLog2 *InstancePtr);

void XLog2_Set_x(XLog2 *InstancePtr, u32 Data);
u32 XLog2_Get_x(XLog2 *InstancePtr);
u32 XLog2_Get_y(XLog2 *InstancePtr);
u32 XLog2_Get_y_vld(XLog2 *InstancePtr);

void XLog2_InterruptGlobalEnable(XLog2 *InstancePtr);
void XLog2_InterruptGlobalDisable(XLog2 *InstancePtr);
void XLog2_InterruptEnable(XLog2 *InstancePtr, u32 Mask);
void XLog2_InterruptDisable(XLog2 *InstancePtr, u32 Mask);
void XLog2_InterruptClear(XLog2 *InstancePtr, u32 Mask);
u32 XLog2_InterruptGetEnabled(XLog2 *InstancePtr);
u32 XLog2_InterruptGetStatus(XLog2 *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
