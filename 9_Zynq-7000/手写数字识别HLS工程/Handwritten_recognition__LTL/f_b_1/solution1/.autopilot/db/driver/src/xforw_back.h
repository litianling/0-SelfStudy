// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XFORW_BACK_H
#define XFORW_BACK_H

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
#include "xforw_back_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Ctrl_BaseAddress;
} XForw_back_Config;
#endif

typedef struct {
    u32 Ctrl_BaseAddress;
    u32 IsReady;
} XForw_back;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XForw_back_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XForw_back_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XForw_back_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XForw_back_ReadReg(BaseAddress, RegOffset) \
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
int XForw_back_Initialize(XForw_back *InstancePtr, u16 DeviceId);
XForw_back_Config* XForw_back_LookupConfig(u16 DeviceId);
int XForw_back_CfgInitialize(XForw_back *InstancePtr, XForw_back_Config *ConfigPtr);
#else
int XForw_back_Initialize(XForw_back *InstancePtr, const char* InstanceName);
int XForw_back_Release(XForw_back *InstancePtr);
#endif

void XForw_back_Start(XForw_back *InstancePtr);
u32 XForw_back_IsDone(XForw_back *InstancePtr);
u32 XForw_back_IsIdle(XForw_back *InstancePtr);
u32 XForw_back_IsReady(XForw_back *InstancePtr);
void XForw_back_EnableAutoRestart(XForw_back *InstancePtr);
void XForw_back_DisableAutoRestart(XForw_back *InstancePtr);

void XForw_back_Set_flag(XForw_back *InstancePtr, u32 Data);
u32 XForw_back_Get_flag(XForw_back *InstancePtr);
void XForw_back_Set_in_r(XForw_back *InstancePtr, u32 Data);
u32 XForw_back_Get_in_r(XForw_back *InstancePtr);
void XForw_back_Set_conv1(XForw_back *InstancePtr, u32 Data);
u32 XForw_back_Get_conv1(XForw_back *InstancePtr);
void XForw_back_Set_conv2(XForw_back *InstancePtr, u32 Data);
u32 XForw_back_Get_conv2(XForw_back *InstancePtr);
void XForw_back_Set_conv3(XForw_back *InstancePtr, u32 Data);
u32 XForw_back_Get_conv3(XForw_back *InstancePtr);
void XForw_back_Set_fc1(XForw_back *InstancePtr, u32 Data);
u32 XForw_back_Get_fc1(XForw_back *InstancePtr);
void XForw_back_Set_fc2(XForw_back *InstancePtr, u32 Data);
u32 XForw_back_Get_fc2(XForw_back *InstancePtr);
void XForw_back_Set_fc3(XForw_back *InstancePtr, u32 Data);
u32 XForw_back_Get_fc3(XForw_back *InstancePtr);
void XForw_back_Set_out_r(XForw_back *InstancePtr, u32 Data);
u32 XForw_back_Get_out_r(XForw_back *InstancePtr);
void XForw_back_Set_label_r(XForw_back *InstancePtr, u32 Data);
u32 XForw_back_Get_label_r(XForw_back *InstancePtr);
void XForw_back_Set_lr(XForw_back *InstancePtr, u32 Data);
u32 XForw_back_Get_lr(XForw_back *InstancePtr);

void XForw_back_InterruptGlobalEnable(XForw_back *InstancePtr);
void XForw_back_InterruptGlobalDisable(XForw_back *InstancePtr);
void XForw_back_InterruptEnable(XForw_back *InstancePtr, u32 Mask);
void XForw_back_InterruptDisable(XForw_back *InstancePtr, u32 Mask);
void XForw_back_InterruptClear(XForw_back *InstancePtr, u32 Mask);
u32 XForw_back_InterruptGetEnabled(XForw_back *InstancePtr);
u32 XForw_back_InterruptGetStatus(XForw_back *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
