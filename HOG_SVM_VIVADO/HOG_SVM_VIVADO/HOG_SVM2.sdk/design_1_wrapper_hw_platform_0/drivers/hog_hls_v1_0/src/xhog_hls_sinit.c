// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xhog_hls.h"

extern XHog_hls_Config XHog_hls_ConfigTable[];

XHog_hls_Config *XHog_hls_LookupConfig(u16 DeviceId) {
	XHog_hls_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XHOG_HLS_NUM_INSTANCES; Index++) {
		if (XHog_hls_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XHog_hls_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XHog_hls_Initialize(XHog_hls *InstancePtr, u16 DeviceId) {
	XHog_hls_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XHog_hls_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XHog_hls_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

