// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xl_log2.h"

extern XL_log2_Config XL_log2_ConfigTable[];

XL_log2_Config *XL_log2_LookupConfig(u16 DeviceId) {
	XL_log2_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XL_LOG2_NUM_INSTANCES; Index++) {
		if (XL_log2_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XL_log2_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XL_log2_Initialize(XL_log2 *InstancePtr, u16 DeviceId) {
	XL_log2_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XL_log2_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XL_log2_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

