// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XHOG_HLS_H
#define XHOG_HLS_H

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
#include "xhog_hls_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XHog_hls_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XHog_hls;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XHog_hls_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XHog_hls_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XHog_hls_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XHog_hls_ReadReg(BaseAddress, RegOffset) \
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
int XHog_hls_Initialize(XHog_hls *InstancePtr, u16 DeviceId);
XHog_hls_Config* XHog_hls_LookupConfig(u16 DeviceId);
int XHog_hls_CfgInitialize(XHog_hls *InstancePtr, XHog_hls_Config *ConfigPtr);
#else
int XHog_hls_Initialize(XHog_hls *InstancePtr, const char* InstanceName);
int XHog_hls_Release(XHog_hls *InstancePtr);
#endif

void XHog_hls_Start(XHog_hls *InstancePtr);
u32 XHog_hls_IsDone(XHog_hls *InstancePtr);
u32 XHog_hls_IsIdle(XHog_hls *InstancePtr);
u32 XHog_hls_IsReady(XHog_hls *InstancePtr);
void XHog_hls_EnableAutoRestart(XHog_hls *InstancePtr);
void XHog_hls_DisableAutoRestart(XHog_hls *InstancePtr);
u32 XHog_hls_Get_return(XHog_hls *InstancePtr);

void XHog_hls_Set_image_r(XHog_hls *InstancePtr, u32 Data);
u32 XHog_hls_Get_image_r(XHog_hls *InstancePtr);

void XHog_hls_InterruptGlobalEnable(XHog_hls *InstancePtr);
void XHog_hls_InterruptGlobalDisable(XHog_hls *InstancePtr);
void XHog_hls_InterruptEnable(XHog_hls *InstancePtr, u32 Mask);
void XHog_hls_InterruptDisable(XHog_hls *InstancePtr, u32 Mask);
void XHog_hls_InterruptClear(XHog_hls *InstancePtr, u32 Mask);
u32 XHog_hls_InterruptGetEnabled(XHog_hls *InstancePtr);
u32 XHog_hls_InterruptGetStatus(XHog_hls *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
