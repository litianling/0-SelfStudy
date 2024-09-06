############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_resource -core RAM_2P_LUTRAM "max" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "Conv2d1" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "Conv2d2" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "Conv2d3" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "Relu1" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "Relu2" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "MatrixExtensionImproved" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "MatrixMultiply1" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "MatrixMultiply2" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "MatrixMultiply3" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "Conv2d_b1" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "Conv2d_b2" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "Conv2d_b3" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "Conv2d_b4" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "Conv2d_b5" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "MatrixBackPropagationMultiply1" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "MatrixBackPropagationMultiply2" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "MatrixBackPropagationMultiply3" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "CalculateMatrixGrad1" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "CalculateMatrixGrad2" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "CalculateMatrixGrad3" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "ReluBackPropagation1" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "ReluBackPropagation2" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "Padding1" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "Padding2" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "OverturnKernel" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "MatrixSplit" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "backward" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "forward" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "outWrite" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "forw_back" fc_hidden_layer2
set_directive_interface -mode s_axilite -bundle ctrl "forw_back" lr
set_directive_pipeline "Conv2d_b1/Conv2d_b1_label4"
set_directive_pipeline "Conv2d_b2/Conv2d_b2_label5"
set_directive_pipeline "Conv2d_b3/Conv2d_b3_label6"
set_directive_pipeline "Conv2d_b4/Conv2d_b4_label7"
set_directive_pipeline "Conv2d_b5/Conv2d_b5_label8"
set_directive_pipeline "Conv2d1/Conv2d1_label0"
set_directive_pipeline "Conv2d2/Conv2d2_label1"
set_directive_pipeline "Conv2d3/Conv2d3_label2"
set_directive_interface -mode m_axi -depth 32 -bundle data "forw_back" lr
