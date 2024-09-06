// ==============================================================
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2019.1 (64-bit)
// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// ctrl
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x10 : Data signal of flag
//        bit 31~0 - flag[31:0] (Read/Write)
// 0x14 : reserved
// 0x18 : Data signal of in_r
//        bit 31~0 - in_r[31:0] (Read/Write)
// 0x1c : reserved
// 0x20 : Data signal of conv1
//        bit 31~0 - conv1[31:0] (Read/Write)
// 0x24 : reserved
// 0x28 : Data signal of conv2
//        bit 31~0 - conv2[31:0] (Read/Write)
// 0x2c : reserved
// 0x30 : Data signal of fc1
//        bit 31~0 - fc1[31:0] (Read/Write)
// 0x34 : reserved
// 0x38 : Data signal of fc2
//        bit 31~0 - fc2[31:0] (Read/Write)
// 0x3c : reserved
// 0x40 : Data signal of out_r
//        bit 31~0 - out_r[31:0] (Read/Write)
// 0x44 : reserved
// 0x48 : Data signal of label_r
//        bit 31~0 - label_r[31:0] (Read/Write)
// 0x4c : reserved
// 0x50 : Data signal of lr
//        bit 31~0 - lr[31:0] (Read/Write)
// 0x54 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XFORW_BACK_CTRL_ADDR_AP_CTRL      0x00
#define XFORW_BACK_CTRL_ADDR_GIE          0x04
#define XFORW_BACK_CTRL_ADDR_IER          0x08
#define XFORW_BACK_CTRL_ADDR_ISR          0x0c
#define XFORW_BACK_CTRL_ADDR_FLAG_DATA    0x10
#define XFORW_BACK_CTRL_BITS_FLAG_DATA    32
#define XFORW_BACK_CTRL_ADDR_IN_R_DATA    0x18
#define XFORW_BACK_CTRL_BITS_IN_R_DATA    32
#define XFORW_BACK_CTRL_ADDR_CONV1_DATA   0x20
#define XFORW_BACK_CTRL_BITS_CONV1_DATA   32
#define XFORW_BACK_CTRL_ADDR_CONV2_DATA   0x28
#define XFORW_BACK_CTRL_BITS_CONV2_DATA   32
#define XFORW_BACK_CTRL_ADDR_FC1_DATA     0x30
#define XFORW_BACK_CTRL_BITS_FC1_DATA     32
#define XFORW_BACK_CTRL_ADDR_FC2_DATA     0x38
#define XFORW_BACK_CTRL_BITS_FC2_DATA     32
#define XFORW_BACK_CTRL_ADDR_OUT_R_DATA   0x40
#define XFORW_BACK_CTRL_BITS_OUT_R_DATA   32
#define XFORW_BACK_CTRL_ADDR_LABEL_R_DATA 0x48
#define XFORW_BACK_CTRL_BITS_LABEL_R_DATA 32
#define XFORW_BACK_CTRL_ADDR_LR_DATA      0x50
#define XFORW_BACK_CTRL_BITS_LR_DATA      32

