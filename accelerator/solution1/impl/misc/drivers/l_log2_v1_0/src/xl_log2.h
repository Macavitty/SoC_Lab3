// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XL_LOG2_H
#define XL_LOG2_H

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
#include "xl_log2_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XL_log2_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XL_log2;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XL_log2_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XL_log2_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XL_log2_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XL_log2_ReadReg(BaseAddress, RegOffset) \
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
int XL_log2_Initialize(XL_log2 *InstancePtr, u16 DeviceId);
XL_log2_Config* XL_log2_LookupConfig(u16 DeviceId);
int XL_log2_CfgInitialize(XL_log2 *InstancePtr, XL_log2_Config *ConfigPtr);
#else
int XL_log2_Initialize(XL_log2 *InstancePtr, const char* InstanceName);
int XL_log2_Release(XL_log2 *InstancePtr);
#endif

void XL_log2_Start(XL_log2 *InstancePtr);
u32 XL_log2_IsDone(XL_log2 *InstancePtr);
u32 XL_log2_IsIdle(XL_log2 *InstancePtr);
u32 XL_log2_IsReady(XL_log2 *InstancePtr);
void XL_log2_EnableAutoRestart(XL_log2 *InstancePtr);
void XL_log2_DisableAutoRestart(XL_log2 *InstancePtr);

void XL_log2_Set_x(XL_log2 *InstancePtr, u32 Data);
u32 XL_log2_Get_x(XL_log2 *InstancePtr);
u32 XL_log2_Get_y(XL_log2 *InstancePtr);
u32 XL_log2_Get_y_vld(XL_log2 *InstancePtr);

void XL_log2_InterruptGlobalEnable(XL_log2 *InstancePtr);
void XL_log2_InterruptGlobalDisable(XL_log2 *InstancePtr);
void XL_log2_InterruptEnable(XL_log2 *InstancePtr, u32 Mask);
void XL_log2_InterruptDisable(XL_log2 *InstancePtr, u32 Mask);
void XL_log2_InterruptClear(XL_log2 *InstancePtr, u32 Mask);
u32 XL_log2_InterruptGetEnabled(XL_log2 *InstancePtr);
u32 XL_log2_InterruptGetStatus(XL_log2 *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
