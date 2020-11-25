// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xlog2.h"

extern XLog2_Config XLog2_ConfigTable[];

XLog2_Config *XLog2_LookupConfig(u16 DeviceId) {
	XLog2_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XLOG2_NUM_INSTANCES; Index++) {
		if (XLog2_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XLog2_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XLog2_Initialize(XLog2 *InstancePtr, u16 DeviceId) {
	XLog2_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XLog2_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XLog2_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

