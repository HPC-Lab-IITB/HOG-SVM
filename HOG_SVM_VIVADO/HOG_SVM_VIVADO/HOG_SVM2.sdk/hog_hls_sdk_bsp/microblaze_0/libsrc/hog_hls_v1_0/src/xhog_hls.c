// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xhog_hls.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XHog_hls_CfgInitialize(XHog_hls *InstancePtr, XHog_hls_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Axilites_BaseAddress = ConfigPtr->Axilites_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XHog_hls_Start(XHog_hls *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHog_hls_ReadReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_AP_CTRL) & 0x80;
    XHog_hls_WriteReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_AP_CTRL, Data | 0x01);
}

u32 XHog_hls_IsDone(XHog_hls *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHog_hls_ReadReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XHog_hls_IsIdle(XHog_hls *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHog_hls_ReadReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XHog_hls_IsReady(XHog_hls *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHog_hls_ReadReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XHog_hls_EnableAutoRestart(XHog_hls *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHog_hls_WriteReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_AP_CTRL, 0x80);
}

void XHog_hls_DisableAutoRestart(XHog_hls *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHog_hls_WriteReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_AP_CTRL, 0);
}

u32 XHog_hls_Get_return(XHog_hls *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHog_hls_ReadReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_AP_RETURN);
    return Data;
}
void XHog_hls_Set_image_r(XHog_hls *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHog_hls_WriteReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_IMAGE_R_DATA, Data);
}

u32 XHog_hls_Get_image_r(XHog_hls *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHog_hls_ReadReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_IMAGE_R_DATA);
    return Data;
}

void XHog_hls_InterruptGlobalEnable(XHog_hls *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHog_hls_WriteReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_GIE, 1);
}

void XHog_hls_InterruptGlobalDisable(XHog_hls *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHog_hls_WriteReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_GIE, 0);
}

void XHog_hls_InterruptEnable(XHog_hls *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XHog_hls_ReadReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_IER);
    XHog_hls_WriteReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_IER, Register | Mask);
}

void XHog_hls_InterruptDisable(XHog_hls *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XHog_hls_ReadReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_IER);
    XHog_hls_WriteReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_IER, Register & (~Mask));
}

void XHog_hls_InterruptClear(XHog_hls *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHog_hls_WriteReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_ISR, Mask);
}

u32 XHog_hls_InterruptGetEnabled(XHog_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XHog_hls_ReadReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_IER);
}

u32 XHog_hls_InterruptGetStatus(XHog_hls *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XHog_hls_ReadReg(InstancePtr->Axilites_BaseAddress, XHOG_HLS_AXILITES_ADDR_ISR);
}

