// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xforw_back.h"

extern XForw_back_Config XForw_back_ConfigTable[];

XForw_back_Config *XForw_back_LookupConfig(u16 DeviceId) {
	XForw_back_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XFORW_BACK_NUM_INSTANCES; Index++) {
		if (XForw_back_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XForw_back_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XForw_back_Initialize(XForw_back *InstancePtr, u16 DeviceId) {
	XForw_back_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XForw_back_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XForw_back_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

