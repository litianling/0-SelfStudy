############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_resource -core RAM_2P_LUTRAM "max" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "Conv2d" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "MaxPool2d" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "MatrixExtensionImproved" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "MatrixMultiply" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "Relu" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "MatrixBackPropagationMultiply" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "CalculateMatrixGrad" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "ReluBackPropagation" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "MaxPooBackPropagation" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "OverturnKernel" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "Padding" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "MatrixBackPropagation" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "forward" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "backward" fc_hidden_layer2
set_directive_resource -core RAM_2P_LUTRAM "forw_back" fc_hidden_layer2
set_directive_interface -mode s_axilite -bundle ctrl "forw_back" lr
set_directive_interface -mode m_axi -depth 32 -bundle data "forw_back" lr
set_directive_pipeline "Conv2d/Conv2d_label0"
set_directive_pipeline "MatrixExtensionImproved/MatrixExtensionImproved_label1"
set_directive_pipeline "Padding/Padding_label3"
