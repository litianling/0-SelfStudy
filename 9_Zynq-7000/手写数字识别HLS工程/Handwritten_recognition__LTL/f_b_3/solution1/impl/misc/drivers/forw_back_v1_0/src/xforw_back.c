// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xforw_back.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XForw_back_CfgInitialize(XForw_back *InstancePtr, XForw_back_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Ctrl_BaseAddress = ConfigPtr->Ctrl_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XForw_back_Start(XForw_back *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_AP_CTRL) & 0x80;
    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XForw_back_IsDone(XForw_back *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XForw_back_IsIdle(XForw_back *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XForw_back_IsReady(XForw_back *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XForw_back_EnableAutoRestart(XForw_back *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_AP_CTRL, 0x80);
}

void XForw_back_DisableAutoRestart(XForw_back *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_AP_CTRL, 0);
}

void XForw_back_Set_flag(XForw_back *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_FLAG_DATA, Data);
}

u32 XForw_back_Get_flag(XForw_back *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_FLAG_DATA);
    return Data;
}

void XForw_back_Set_in_r(XForw_back *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_IN_R_DATA, Data);
}

u32 XForw_back_Get_in_r(XForw_back *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_IN_R_DATA);
    return Data;
}

void XForw_back_Set_conv1(XForw_back *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_CONV1_DATA, Data);
}

u32 XForw_back_Get_conv1(XForw_back *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_CONV1_DATA);
    return Data;
}

void XForw_back_Set_conv2(XForw_back *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_CONV2_DATA, Data);
}

u32 XForw_back_Get_conv2(XForw_back *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_CONV2_DATA);
    return Data;
}

void XForw_back_Set_conv3(XForw_back *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_CONV3_DATA, Data);
}

u32 XForw_back_Get_conv3(XForw_back *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_CONV3_DATA);
    return Data;
}

void XForw_back_Set_fc1(XForw_back *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_FC1_DATA, Data);
}

u32 XForw_back_Get_fc1(XForw_back *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_FC1_DATA);
    return Data;
}

void XForw_back_Set_fc2(XForw_back *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_FC2_DATA, Data);
}

u32 XForw_back_Get_fc2(XForw_back *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_FC2_DATA);
    return Data;
}

void XForw_back_Set_fc3(XForw_back *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_FC3_DATA, Data);
}

u32 XForw_back_Get_fc3(XForw_back *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_FC3_DATA);
    return Data;
}

void XForw_back_Set_out_r(XForw_back *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_OUT_R_DATA, Data);
}

u32 XForw_back_Get_out_r(XForw_back *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_OUT_R_DATA);
    return Data;
}

void XForw_back_Set_label_r(XForw_back *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_LABEL_R_DATA, Data);
}

u32 XForw_back_Get_label_r(XForw_back *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_LABEL_R_DATA);
    return Data;
}

void XForw_back_Set_lr(XForw_back *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_LR_DATA, Data);
}

u32 XForw_back_Get_lr(XForw_back *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_LR_DATA);
    return Data;
}

void XForw_back_InterruptGlobalEnable(XForw_back *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_GIE, 1);
}

void XForw_back_InterruptGlobalDisable(XForw_back *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_GIE, 0);
}

void XForw_back_InterruptEnable(XForw_back *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_IER);
    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_IER, Register | Mask);
}

void XForw_back_InterruptDisable(XForw_back *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_IER);
    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_IER, Register & (~Mask));
}

void XForw_back_InterruptClear(XForw_back *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XForw_back_WriteReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_ISR, Mask);
}

u32 XForw_back_InterruptGetEnabled(XForw_back *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_IER);
}

u32 XForw_back_InterruptGetStatus(XForw_back *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XForw_back_ReadReg(InstancePtr->Ctrl_BaseAddress, XFORW_BACK_CTRL_ADDR_ISR);
}

