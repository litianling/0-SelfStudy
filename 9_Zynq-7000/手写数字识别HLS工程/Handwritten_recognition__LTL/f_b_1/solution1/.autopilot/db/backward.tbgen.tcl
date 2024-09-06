set moduleName backward
set isTopModule 0
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isFreeRunPipelineModule 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {backward}
set C_modelType { void 0 }
set C_modelArgList {
	{ label_r int 32 regular  }
	{ lr_in float 32 regular {axi_master 0}  }
	{ lr_in_offset int 30 regular  }
	{ probability_result float 32 regular {array 10 { 1 3 } 1 1 } {global 0}  }
	{ fc_in_3_relu2_0 float 32 regular {array 45 { 1 3 } 1 1 } {global 0}  }
	{ fc_hidden_layer3 float 32 regular {array 450 { 2 3 } 1 1 } {global 2}  }
	{ fc_out_2_0 float 32 regular {array 45 { 1 3 } 1 1 } {global 0}  }
	{ fc_in_2_relu1_0 float 32 regular {array 180 { 1 3 } 1 1 } {global 0}  }
	{ fc_hidden_layer2 float 32 regular {array 8100 { 1 0 } 1 1 } {global 2}  }
	{ fc_out_1_0 float 32 regular {array 180 { 1 3 } 1 1 } {global 0}  }
	{ fc_in_1_0 float 32 regular {array 576 { 1 3 } 1 1 } {global 0}  }
	{ fc_hidden_layer1 float 32 regular {array 103680 { 2 3 } 1 1 } {global 2}  }
	{ conv_out_2 float 32 regular {array 676 { 1 3 } 1 1 } {global 0}  }
	{ conv_kernel_3 float 32 regular {array 9 { 2 3 } 1 1 } {global 2}  }
	{ conv_out_1 float 32 regular {array 784 { 1 3 } 1 1 } {global 0}  }
	{ conv_kernel_2 float 32 regular {array 9 { 2 3 } 1 1 } {global 2}  }
	{ mnist_data float 32 regular {array 900 { 1 3 } 1 1 } {global 0}  }
	{ conv_kernel_1 float 32 regular {array 9 { 2 3 } 1 1 } {global 2}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "label_r", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "lr_in", "interface" : "axi_master", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "lr_in_offset", "interface" : "wire", "bitwidth" : 30, "direction" : "READONLY"} , 
 	{ "Name" : "probability_result", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "fc_in_3_relu2_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "fc_hidden_layer3", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "fc_out_2_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "fc_in_2_relu1_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "fc_hidden_layer2", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "fc_out_1_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "fc_in_1_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "fc_hidden_layer1", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "conv_out_2", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "conv_kernel_3", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "conv_out_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "conv_kernel_2", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "mnist_data", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "conv_kernel_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} ]}
# RTL Port declarations: 
set portNum 112
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ label_r sc_in sc_lv 32 signal 0 } 
	{ m_axi_lr_in_AWVALID sc_out sc_logic 1 signal 1 } 
	{ m_axi_lr_in_AWREADY sc_in sc_logic 1 signal 1 } 
	{ m_axi_lr_in_AWADDR sc_out sc_lv 32 signal 1 } 
	{ m_axi_lr_in_AWID sc_out sc_lv 1 signal 1 } 
	{ m_axi_lr_in_AWLEN sc_out sc_lv 32 signal 1 } 
	{ m_axi_lr_in_AWSIZE sc_out sc_lv 3 signal 1 } 
	{ m_axi_lr_in_AWBURST sc_out sc_lv 2 signal 1 } 
	{ m_axi_lr_in_AWLOCK sc_out sc_lv 2 signal 1 } 
	{ m_axi_lr_in_AWCACHE sc_out sc_lv 4 signal 1 } 
	{ m_axi_lr_in_AWPROT sc_out sc_lv 3 signal 1 } 
	{ m_axi_lr_in_AWQOS sc_out sc_lv 4 signal 1 } 
	{ m_axi_lr_in_AWREGION sc_out sc_lv 4 signal 1 } 
	{ m_axi_lr_in_AWUSER sc_out sc_lv 1 signal 1 } 
	{ m_axi_lr_in_WVALID sc_out sc_logic 1 signal 1 } 
	{ m_axi_lr_in_WREADY sc_in sc_logic 1 signal 1 } 
	{ m_axi_lr_in_WDATA sc_out sc_lv 32 signal 1 } 
	{ m_axi_lr_in_WSTRB sc_out sc_lv 4 signal 1 } 
	{ m_axi_lr_in_WLAST sc_out sc_logic 1 signal 1 } 
	{ m_axi_lr_in_WID sc_out sc_lv 1 signal 1 } 
	{ m_axi_lr_in_WUSER sc_out sc_lv 1 signal 1 } 
	{ m_axi_lr_in_ARVALID sc_out sc_logic 1 signal 1 } 
	{ m_axi_lr_in_ARREADY sc_in sc_logic 1 signal 1 } 
	{ m_axi_lr_in_ARADDR sc_out sc_lv 32 signal 1 } 
	{ m_axi_lr_in_ARID sc_out sc_lv 1 signal 1 } 
	{ m_axi_lr_in_ARLEN sc_out sc_lv 32 signal 1 } 
	{ m_axi_lr_in_ARSIZE sc_out sc_lv 3 signal 1 } 
	{ m_axi_lr_in_ARBURST sc_out sc_lv 2 signal 1 } 
	{ m_axi_lr_in_ARLOCK sc_out sc_lv 2 signal 1 } 
	{ m_axi_lr_in_ARCACHE sc_out sc_lv 4 signal 1 } 
	{ m_axi_lr_in_ARPROT sc_out sc_lv 3 signal 1 } 
	{ m_axi_lr_in_ARQOS sc_out sc_lv 4 signal 1 } 
	{ m_axi_lr_in_ARREGION sc_out sc_lv 4 signal 1 } 
	{ m_axi_lr_in_ARUSER sc_out sc_lv 1 signal 1 } 
	{ m_axi_lr_in_RVALID sc_in sc_logic 1 signal 1 } 
	{ m_axi_lr_in_RREADY sc_out sc_logic 1 signal 1 } 
	{ m_axi_lr_in_RDATA sc_in sc_lv 32 signal 1 } 
	{ m_axi_lr_in_RLAST sc_in sc_logic 1 signal 1 } 
	{ m_axi_lr_in_RID sc_in sc_lv 1 signal 1 } 
	{ m_axi_lr_in_RUSER sc_in sc_lv 1 signal 1 } 
	{ m_axi_lr_in_RRESP sc_in sc_lv 2 signal 1 } 
	{ m_axi_lr_in_BVALID sc_in sc_logic 1 signal 1 } 
	{ m_axi_lr_in_BREADY sc_out sc_logic 1 signal 1 } 
	{ m_axi_lr_in_BRESP sc_in sc_lv 2 signal 1 } 
	{ m_axi_lr_in_BID sc_in sc_lv 1 signal 1 } 
	{ m_axi_lr_in_BUSER sc_in sc_lv 1 signal 1 } 
	{ lr_in_offset sc_in sc_lv 30 signal 2 } 
	{ probability_result_address0 sc_out sc_lv 4 signal 3 } 
	{ probability_result_ce0 sc_out sc_logic 1 signal 3 } 
	{ probability_result_q0 sc_in sc_lv 32 signal 3 } 
	{ fc_in_3_relu2_0_address0 sc_out sc_lv 6 signal 4 } 
	{ fc_in_3_relu2_0_ce0 sc_out sc_logic 1 signal 4 } 
	{ fc_in_3_relu2_0_q0 sc_in sc_lv 32 signal 4 } 
	{ fc_hidden_layer3_address0 sc_out sc_lv 9 signal 5 } 
	{ fc_hidden_layer3_ce0 sc_out sc_logic 1 signal 5 } 
	{ fc_hidden_layer3_we0 sc_out sc_logic 1 signal 5 } 
	{ fc_hidden_layer3_d0 sc_out sc_lv 32 signal 5 } 
	{ fc_hidden_layer3_q0 sc_in sc_lv 32 signal 5 } 
	{ fc_out_2_0_address0 sc_out sc_lv 6 signal 6 } 
	{ fc_out_2_0_ce0 sc_out sc_logic 1 signal 6 } 
	{ fc_out_2_0_q0 sc_in sc_lv 32 signal 6 } 
	{ fc_in_2_relu1_0_address0 sc_out sc_lv 8 signal 7 } 
	{ fc_in_2_relu1_0_ce0 sc_out sc_logic 1 signal 7 } 
	{ fc_in_2_relu1_0_q0 sc_in sc_lv 32 signal 7 } 
	{ fc_hidden_layer2_address0 sc_out sc_lv 13 signal 8 } 
	{ fc_hidden_layer2_ce0 sc_out sc_logic 1 signal 8 } 
	{ fc_hidden_layer2_q0 sc_in sc_lv 32 signal 8 } 
	{ fc_hidden_layer2_address1 sc_out sc_lv 13 signal 8 } 
	{ fc_hidden_layer2_ce1 sc_out sc_logic 1 signal 8 } 
	{ fc_hidden_layer2_we1 sc_out sc_logic 1 signal 8 } 
	{ fc_hidden_layer2_d1 sc_out sc_lv 32 signal 8 } 
	{ fc_out_1_0_address0 sc_out sc_lv 8 signal 9 } 
	{ fc_out_1_0_ce0 sc_out sc_logic 1 signal 9 } 
	{ fc_out_1_0_q0 sc_in sc_lv 32 signal 9 } 
	{ fc_in_1_0_address0 sc_out sc_lv 10 signal 10 } 
	{ fc_in_1_0_ce0 sc_out sc_logic 1 signal 10 } 
	{ fc_in_1_0_q0 sc_in sc_lv 32 signal 10 } 
	{ fc_hidden_layer1_address0 sc_out sc_lv 17 signal 11 } 
	{ fc_hidden_layer1_ce0 sc_out sc_logic 1 signal 11 } 
	{ fc_hidden_layer1_we0 sc_out sc_logic 1 signal 11 } 
	{ fc_hidden_layer1_d0 sc_out sc_lv 32 signal 11 } 
	{ fc_hidden_layer1_q0 sc_in sc_lv 32 signal 11 } 
	{ conv_out_2_address0 sc_out sc_lv 10 signal 12 } 
	{ conv_out_2_ce0 sc_out sc_logic 1 signal 12 } 
	{ conv_out_2_q0 sc_in sc_lv 32 signal 12 } 
	{ conv_kernel_3_address0 sc_out sc_lv 4 signal 13 } 
	{ conv_kernel_3_ce0 sc_out sc_logic 1 signal 13 } 
	{ conv_kernel_3_we0 sc_out sc_logic 1 signal 13 } 
	{ conv_kernel_3_d0 sc_out sc_lv 32 signal 13 } 
	{ conv_kernel_3_q0 sc_in sc_lv 32 signal 13 } 
	{ conv_out_1_address0 sc_out sc_lv 10 signal 14 } 
	{ conv_out_1_ce0 sc_out sc_logic 1 signal 14 } 
	{ conv_out_1_q0 sc_in sc_lv 32 signal 14 } 
	{ conv_kernel_2_address0 sc_out sc_lv 4 signal 15 } 
	{ conv_kernel_2_ce0 sc_out sc_logic 1 signal 15 } 
	{ conv_kernel_2_we0 sc_out sc_logic 1 signal 15 } 
	{ conv_kernel_2_d0 sc_out sc_lv 32 signal 15 } 
	{ conv_kernel_2_q0 sc_in sc_lv 32 signal 15 } 
	{ mnist_data_address0 sc_out sc_lv 10 signal 16 } 
	{ mnist_data_ce0 sc_out sc_logic 1 signal 16 } 
	{ mnist_data_q0 sc_in sc_lv 32 signal 16 } 
	{ conv_kernel_1_address0 sc_out sc_lv 4 signal 17 } 
	{ conv_kernel_1_ce0 sc_out sc_logic 1 signal 17 } 
	{ conv_kernel_1_we0 sc_out sc_logic 1 signal 17 } 
	{ conv_kernel_1_d0 sc_out sc_lv 32 signal 17 } 
	{ conv_kernel_1_q0 sc_in sc_lv 32 signal 17 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "label_r", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "label_r", "role": "default" }} , 
 	{ "name": "m_axi_lr_in_AWVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "AWVALID" }} , 
 	{ "name": "m_axi_lr_in_AWREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "AWREADY" }} , 
 	{ "name": "m_axi_lr_in_AWADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "lr_in", "role": "AWADDR" }} , 
 	{ "name": "m_axi_lr_in_AWID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "AWID" }} , 
 	{ "name": "m_axi_lr_in_AWLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "lr_in", "role": "AWLEN" }} , 
 	{ "name": "m_axi_lr_in_AWSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "lr_in", "role": "AWSIZE" }} , 
 	{ "name": "m_axi_lr_in_AWBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "lr_in", "role": "AWBURST" }} , 
 	{ "name": "m_axi_lr_in_AWLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "lr_in", "role": "AWLOCK" }} , 
 	{ "name": "m_axi_lr_in_AWCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "lr_in", "role": "AWCACHE" }} , 
 	{ "name": "m_axi_lr_in_AWPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "lr_in", "role": "AWPROT" }} , 
 	{ "name": "m_axi_lr_in_AWQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "lr_in", "role": "AWQOS" }} , 
 	{ "name": "m_axi_lr_in_AWREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "lr_in", "role": "AWREGION" }} , 
 	{ "name": "m_axi_lr_in_AWUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "AWUSER" }} , 
 	{ "name": "m_axi_lr_in_WVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "WVALID" }} , 
 	{ "name": "m_axi_lr_in_WREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "WREADY" }} , 
 	{ "name": "m_axi_lr_in_WDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "lr_in", "role": "WDATA" }} , 
 	{ "name": "m_axi_lr_in_WSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "lr_in", "role": "WSTRB" }} , 
 	{ "name": "m_axi_lr_in_WLAST", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "WLAST" }} , 
 	{ "name": "m_axi_lr_in_WID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "WID" }} , 
 	{ "name": "m_axi_lr_in_WUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "WUSER" }} , 
 	{ "name": "m_axi_lr_in_ARVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "ARVALID" }} , 
 	{ "name": "m_axi_lr_in_ARREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "ARREADY" }} , 
 	{ "name": "m_axi_lr_in_ARADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "lr_in", "role": "ARADDR" }} , 
 	{ "name": "m_axi_lr_in_ARID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "ARID" }} , 
 	{ "name": "m_axi_lr_in_ARLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "lr_in", "role": "ARLEN" }} , 
 	{ "name": "m_axi_lr_in_ARSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "lr_in", "role": "ARSIZE" }} , 
 	{ "name": "m_axi_lr_in_ARBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "lr_in", "role": "ARBURST" }} , 
 	{ "name": "m_axi_lr_in_ARLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "lr_in", "role": "ARLOCK" }} , 
 	{ "name": "m_axi_lr_in_ARCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "lr_in", "role": "ARCACHE" }} , 
 	{ "name": "m_axi_lr_in_ARPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "lr_in", "role": "ARPROT" }} , 
 	{ "name": "m_axi_lr_in_ARQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "lr_in", "role": "ARQOS" }} , 
 	{ "name": "m_axi_lr_in_ARREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "lr_in", "role": "ARREGION" }} , 
 	{ "name": "m_axi_lr_in_ARUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "ARUSER" }} , 
 	{ "name": "m_axi_lr_in_RVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "RVALID" }} , 
 	{ "name": "m_axi_lr_in_RREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "RREADY" }} , 
 	{ "name": "m_axi_lr_in_RDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "lr_in", "role": "RDATA" }} , 
 	{ "name": "m_axi_lr_in_RLAST", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "RLAST" }} , 
 	{ "name": "m_axi_lr_in_RID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "RID" }} , 
 	{ "name": "m_axi_lr_in_RUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "RUSER" }} , 
 	{ "name": "m_axi_lr_in_RRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "lr_in", "role": "RRESP" }} , 
 	{ "name": "m_axi_lr_in_BVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "BVALID" }} , 
 	{ "name": "m_axi_lr_in_BREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "BREADY" }} , 
 	{ "name": "m_axi_lr_in_BRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "lr_in", "role": "BRESP" }} , 
 	{ "name": "m_axi_lr_in_BID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "BID" }} , 
 	{ "name": "m_axi_lr_in_BUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "lr_in", "role": "BUSER" }} , 
 	{ "name": "lr_in_offset", "direction": "in", "datatype": "sc_lv", "bitwidth":30, "type": "signal", "bundle":{"name": "lr_in_offset", "role": "default" }} , 
 	{ "name": "probability_result_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "probability_result", "role": "address0" }} , 
 	{ "name": "probability_result_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "probability_result", "role": "ce0" }} , 
 	{ "name": "probability_result_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "probability_result", "role": "q0" }} , 
 	{ "name": "fc_in_3_relu2_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "fc_in_3_relu2_0", "role": "address0" }} , 
 	{ "name": "fc_in_3_relu2_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_in_3_relu2_0", "role": "ce0" }} , 
 	{ "name": "fc_in_3_relu2_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_in_3_relu2_0", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "address0" }} , 
 	{ "name": "fc_hidden_layer3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "ce0" }} , 
 	{ "name": "fc_hidden_layer3_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "we0" }} , 
 	{ "name": "fc_hidden_layer3_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "d0" }} , 
 	{ "name": "fc_hidden_layer3_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "q0" }} , 
 	{ "name": "fc_out_2_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "fc_out_2_0", "role": "address0" }} , 
 	{ "name": "fc_out_2_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_out_2_0", "role": "ce0" }} , 
 	{ "name": "fc_out_2_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_out_2_0", "role": "q0" }} , 
 	{ "name": "fc_in_2_relu1_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "fc_in_2_relu1_0", "role": "address0" }} , 
 	{ "name": "fc_in_2_relu1_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_in_2_relu1_0", "role": "ce0" }} , 
 	{ "name": "fc_in_2_relu1_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_in_2_relu1_0", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "address0" }} , 
 	{ "name": "fc_hidden_layer2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "ce0" }} , 
 	{ "name": "fc_hidden_layer2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer2_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "address1" }} , 
 	{ "name": "fc_hidden_layer2_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "ce1" }} , 
 	{ "name": "fc_hidden_layer2_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "we1" }} , 
 	{ "name": "fc_hidden_layer2_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "d1" }} , 
 	{ "name": "fc_out_1_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "fc_out_1_0", "role": "address0" }} , 
 	{ "name": "fc_out_1_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_out_1_0", "role": "ce0" }} , 
 	{ "name": "fc_out_1_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_out_1_0", "role": "q0" }} , 
 	{ "name": "fc_in_1_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "address0" }} , 
 	{ "name": "fc_in_1_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "ce0" }} , 
 	{ "name": "fc_in_1_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":17, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "address0" }} , 
 	{ "name": "fc_hidden_layer1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "ce0" }} , 
 	{ "name": "fc_hidden_layer1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "we0" }} , 
 	{ "name": "fc_hidden_layer1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "d0" }} , 
 	{ "name": "fc_hidden_layer1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "q0" }} , 
 	{ "name": "conv_out_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "conv_out_2", "role": "address0" }} , 
 	{ "name": "conv_out_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_out_2", "role": "ce0" }} , 
 	{ "name": "conv_out_2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_out_2", "role": "q0" }} , 
 	{ "name": "conv_kernel_3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv_kernel_3", "role": "address0" }} , 
 	{ "name": "conv_kernel_3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel_3", "role": "ce0" }} , 
 	{ "name": "conv_kernel_3_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel_3", "role": "we0" }} , 
 	{ "name": "conv_kernel_3_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel_3", "role": "d0" }} , 
 	{ "name": "conv_kernel_3_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel_3", "role": "q0" }} , 
 	{ "name": "conv_out_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "conv_out_1", "role": "address0" }} , 
 	{ "name": "conv_out_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_out_1", "role": "ce0" }} , 
 	{ "name": "conv_out_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_out_1", "role": "q0" }} , 
 	{ "name": "conv_kernel_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv_kernel_2", "role": "address0" }} , 
 	{ "name": "conv_kernel_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel_2", "role": "ce0" }} , 
 	{ "name": "conv_kernel_2_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel_2", "role": "we0" }} , 
 	{ "name": "conv_kernel_2_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel_2", "role": "d0" }} , 
 	{ "name": "conv_kernel_2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel_2", "role": "q0" }} , 
 	{ "name": "mnist_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "mnist_data", "role": "address0" }} , 
 	{ "name": "mnist_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "mnist_data", "role": "ce0" }} , 
 	{ "name": "mnist_data_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "mnist_data", "role": "q0" }} , 
 	{ "name": "conv_kernel_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv_kernel_1", "role": "address0" }} , 
 	{ "name": "conv_kernel_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel_1", "role": "ce0" }} , 
 	{ "name": "conv_kernel_1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel_1", "role": "we0" }} , 
 	{ "name": "conv_kernel_1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel_1", "role": "d0" }} , 
 	{ "name": "conv_kernel_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel_1", "role": "q0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "22", "26", "29", "33", "37", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51"],
		"CDFG" : "backward",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state93", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_1_fu_984"},
			{"State" : "ap_ST_fsm_state87", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_3_fu_991"},
			{"State" : "ap_ST_fsm_state95", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_fu_998"},
			{"State" : "ap_ST_fsm_state83", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_4_fu_1006"},
			{"State" : "ap_ST_fsm_state89", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_2_fu_1014"},
			{"State" : "ap_ST_fsm_state91", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MatrixBackPropagatio_1_fu_1022"},
			{"State" : "ap_ST_fsm_state93", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MatrixBackPropagatio_1_fu_1022"},
			{"State" : "ap_ST_fsm_state97", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MatrixBackPropagatio_1_fu_1022"},
			{"State" : "ap_ST_fsm_state85", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Padding_1_fu_1032"},
			{"State" : "ap_ST_fsm_state91", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Padding_fu_1038"},
			{"State" : "ap_ST_fsm_state83", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_OverturnKernel_fu_1044"},
			{"State" : "ap_ST_fsm_state83", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_OverturnKernel_fu_1051"}],
		"Port" : [
			{"Name" : "label_r", "Type" : "None", "Direction" : "I"},
			{"Name" : "lr_in", "Type" : "MAXI", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "lr_in_blk_n_AR", "Type" : "RtlSignal"},
					{"Name" : "lr_in_blk_n_R", "Type" : "RtlSignal"}]},
			{"Name" : "lr_in_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "probability_result", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_in_3_relu2_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_hidden_layer3", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_out_2_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_in_2_relu1_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_hidden_layer2", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_out_1_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_in_1_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_hidden_layer1", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "conv_out_2", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "29", "SubInstance" : "grp_Conv2d_4_fu_1006", "Port" : "conv_out_2"}]},
			{"Name" : "conv_kernel_3", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "37", "SubInstance" : "grp_MatrixBackPropagatio_1_fu_1022", "Port" : "output_matrix"},
					{"ID" : "42", "SubInstance" : "grp_OverturnKernel_fu_1044", "Port" : "input_matrix"}]},
			{"Name" : "conv_out_1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "33", "SubInstance" : "grp_Conv2d_2_fu_1014", "Port" : "conv_out_1"}]},
			{"Name" : "conv_kernel_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "37", "SubInstance" : "grp_MatrixBackPropagatio_1_fu_1022", "Port" : "output_matrix"},
					{"ID" : "43", "SubInstance" : "grp_OverturnKernel_fu_1051", "Port" : "input_matrix"}]},
			{"Name" : "mnist_data", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "26", "SubInstance" : "grp_Conv2d_fu_998", "Port" : "input_matrix"}]},
			{"Name" : "conv_kernel_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "37", "SubInstance" : "grp_MatrixBackPropagatio_1_fu_1022", "Port" : "output_matrix"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grad_3_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.wgrad_3_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.rgrad_2_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grad_2_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.wgrad_2_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.rgrad_1_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grad_1_U", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.wgrad_1_U", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grad_0_U", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.kernel_grad_3_U", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.conv_grad_2_U", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.kernel_grad_3_overtu_U", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.conv_grad_3_padding_U", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.kernel_grad_2_U", "Parent" : "0"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.conv_grad_1_U", "Parent" : "0"},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.kernel_grad_2_overtu_U", "Parent" : "0"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.conv_grad_2_padding_U", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.kernel_grad_1_U", "Parent" : "0"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_1_fu_984", "Parent" : "0", "Child" : ["20", "21"],
		"CDFG" : "Conv2d_1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_matrix", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "kernel", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "out_matrix", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "20", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_1_fu_984.forw_back_fadd_32bkb_U79", "Parent" : "19"},
	{"ID" : "21", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_1_fu_984.forw_back_fmul_32cud_U80", "Parent" : "19"},
	{"ID" : "22", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_3_fu_991", "Parent" : "0", "Child" : ["23", "24", "25"],
		"CDFG" : "Conv2d_3",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_matrix", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "kernel", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "out_matrix", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "23", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_3_fu_991.forw_back_fadd_32bkb_U64", "Parent" : "22"},
	{"ID" : "24", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_3_fu_991.forw_back_fmul_32cud_U65", "Parent" : "22"},
	{"ID" : "25", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_3_fu_991.forw_back_mac_muldEe_U66", "Parent" : "22"},
	{"ID" : "26", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_fu_998", "Parent" : "0", "Child" : ["27", "28"],
		"CDFG" : "Conv2d",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "388", "EstimateLatencyMax" : "388",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_matrix", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "kernel", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "out_matrix", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "27", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_fu_998.forw_back_fadd_32bkb_U84", "Parent" : "26"},
	{"ID" : "28", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_fu_998.forw_back_fmul_32cud_U85", "Parent" : "26"},
	{"ID" : "29", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_4_fu_1006", "Parent" : "0", "Child" : ["30", "31", "32"],
		"CDFG" : "Conv2d_4",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "388", "EstimateLatencyMax" : "388",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "kernel", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "out_matrix", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "conv_out_2", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "30", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_4_fu_1006.forw_back_fadd_32bkb_U53", "Parent" : "29"},
	{"ID" : "31", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_4_fu_1006.forw_back_fmul_32cud_U54", "Parent" : "29"},
	{"ID" : "32", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_4_fu_1006.forw_back_mac_mullbW_U55", "Parent" : "29"},
	{"ID" : "33", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_2_fu_1014", "Parent" : "0", "Child" : ["34", "35", "36"],
		"CDFG" : "Conv2d_2",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "388", "EstimateLatencyMax" : "388",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "kernel", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "out_matrix", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "conv_out_1", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "34", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_2_fu_1014.forw_back_fadd_32bkb_U70", "Parent" : "33"},
	{"ID" : "35", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_2_fu_1014.forw_back_fmul_32cud_U71", "Parent" : "33"},
	{"ID" : "36", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_2_fu_1014.forw_back_mac_mulmb6_U72", "Parent" : "33"},
	{"ID" : "37", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_MatrixBackPropagatio_1_fu_1022", "Parent" : "0", "Child" : ["38", "39"],
		"CDFG" : "MatrixBackPropagatio_1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "88", "EstimateLatencyMax" : "88",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_matrix", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "output_matrix", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "lr", "Type" : "None", "Direction" : "I"}]},
	{"ID" : "38", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_MatrixBackPropagatio_1_fu_1022.forw_back_fsub_32ncg_U89", "Parent" : "37"},
	{"ID" : "39", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_MatrixBackPropagatio_1_fu_1022.forw_back_fmul_32cud_U90", "Parent" : "37"},
	{"ID" : "40", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Padding_1_fu_1032", "Parent" : "0",
		"CDFG" : "Padding_1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "786", "EstimateLatencyMax" : "786",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_matrix", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "output_matrix", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "41", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Padding_fu_1038", "Parent" : "0",
		"CDFG" : "Padding",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "902", "EstimateLatencyMax" : "902",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_matrix", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "output_matrix", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "42", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_OverturnKernel_fu_1044", "Parent" : "0",
		"CDFG" : "OverturnKernel",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "25", "EstimateLatencyMax" : "25",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_matrix", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "output_matrix", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "43", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_OverturnKernel_fu_1051", "Parent" : "0",
		"CDFG" : "OverturnKernel",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "25", "EstimateLatencyMax" : "25",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_matrix", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "output_matrix", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "44", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_faddfsuxdS_U95", "Parent" : "0"},
	{"ID" : "45", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fmul_32cud_U96", "Parent" : "0"},
	{"ID" : "46", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fptrunceOg_U97", "Parent" : "0"},
	{"ID" : "47", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fpext_3fYi_U98", "Parent" : "0"},
	{"ID" : "48", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fcmp_32g8j_U99", "Parent" : "0"},
	{"ID" : "49", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_dmul_64ibs_U100", "Parent" : "0"},
	{"ID" : "50", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_mac_mulyd2_U101", "Parent" : "0"},
	{"ID" : "51", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_mac_mulzec_U102", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	backward {
		label_r {Type I LastRead 0 FirstWrite -1}
		lr_in {Type I LastRead 32 FirstWrite -1}
		lr_in_offset {Type I LastRead 4 FirstWrite -1}
		probability_result {Type I LastRead 5 FirstWrite -1}
		fc_in_3_relu2_0 {Type I LastRead 6 FirstWrite -1}
		fc_hidden_layer3 {Type IO LastRead 39 FirstWrite 45}
		fc_out_2_0 {Type I LastRead 9 FirstWrite -1}
		fc_in_2_relu1_0 {Type I LastRead 10 FirstWrite -1}
		fc_hidden_layer2 {Type IO LastRead 39 FirstWrite 43}
		fc_out_1_0 {Type I LastRead 13 FirstWrite -1}
		fc_in_1_0 {Type I LastRead 14 FirstWrite -1}
		fc_hidden_layer1 {Type IO LastRead 37 FirstWrite 43}
		conv_out_2 {Type I LastRead 2 FirstWrite -1}
		conv_kernel_3 {Type IO LastRead 6 FirstWrite -1}
		conv_out_1 {Type I LastRead 2 FirstWrite -1}
		conv_kernel_2 {Type IO LastRead 6 FirstWrite -1}
		mnist_data {Type I LastRead 2 FirstWrite -1}
		conv_kernel_1 {Type IO LastRead 6 FirstWrite 10}}
	Conv2d_1 {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		kernel {Type I LastRead 2 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}}
	Conv2d_3 {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		kernel {Type I LastRead 2 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}}
	Conv2d {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		kernel {Type I LastRead 2 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}}
	Conv2d_4 {
		kernel {Type I LastRead 2 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}
		conv_out_2 {Type I LastRead 2 FirstWrite -1}}
	Conv2d_2 {
		kernel {Type I LastRead 2 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}
		conv_out_1 {Type I LastRead 2 FirstWrite -1}}
	MatrixBackPropagatio_1 {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		output_matrix {Type IO LastRead 6 FirstWrite 10}
		lr {Type I LastRead 0 FirstWrite -1}}
	Padding_1 {
		input_matrix {Type I LastRead 1 FirstWrite -1}
		output_matrix {Type O LastRead -1 FirstWrite 1}}
	Padding {
		input_matrix {Type I LastRead 1 FirstWrite -1}
		output_matrix {Type O LastRead -1 FirstWrite 1}}
	OverturnKernel {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		output_matrix {Type O LastRead -1 FirstWrite 3}}
	OverturnKernel {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		output_matrix {Type O LastRead -1 FirstWrite 3}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "-1", "Max" : "-1"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
	{"Pipeline" : "2", "EnableSignal" : "ap_enable_pp2"}
]}

set Spec2ImplPortList { 
	label_r { ap_none {  { label_r in_data 0 32 } } }
	lr_in { m_axi {  { m_axi_lr_in_AWVALID VALID 1 1 }  { m_axi_lr_in_AWREADY READY 0 1 }  { m_axi_lr_in_AWADDR ADDR 1 32 }  { m_axi_lr_in_AWID ID 1 1 }  { m_axi_lr_in_AWLEN LEN 1 32 }  { m_axi_lr_in_AWSIZE SIZE 1 3 }  { m_axi_lr_in_AWBURST BURST 1 2 }  { m_axi_lr_in_AWLOCK LOCK 1 2 }  { m_axi_lr_in_AWCACHE CACHE 1 4 }  { m_axi_lr_in_AWPROT PROT 1 3 }  { m_axi_lr_in_AWQOS QOS 1 4 }  { m_axi_lr_in_AWREGION REGION 1 4 }  { m_axi_lr_in_AWUSER USER 1 1 }  { m_axi_lr_in_WVALID VALID 1 1 }  { m_axi_lr_in_WREADY READY 0 1 }  { m_axi_lr_in_WDATA DATA 1 32 }  { m_axi_lr_in_WSTRB STRB 1 4 }  { m_axi_lr_in_WLAST LAST 1 1 }  { m_axi_lr_in_WID ID 1 1 }  { m_axi_lr_in_WUSER USER 1 1 }  { m_axi_lr_in_ARVALID VALID 1 1 }  { m_axi_lr_in_ARREADY READY 0 1 }  { m_axi_lr_in_ARADDR ADDR 1 32 }  { m_axi_lr_in_ARID ID 1 1 }  { m_axi_lr_in_ARLEN LEN 1 32 }  { m_axi_lr_in_ARSIZE SIZE 1 3 }  { m_axi_lr_in_ARBURST BURST 1 2 }  { m_axi_lr_in_ARLOCK LOCK 1 2 }  { m_axi_lr_in_ARCACHE CACHE 1 4 }  { m_axi_lr_in_ARPROT PROT 1 3 }  { m_axi_lr_in_ARQOS QOS 1 4 }  { m_axi_lr_in_ARREGION REGION 1 4 }  { m_axi_lr_in_ARUSER USER 1 1 }  { m_axi_lr_in_RVALID VALID 0 1 }  { m_axi_lr_in_RREADY READY 1 1 }  { m_axi_lr_in_RDATA DATA 0 32 }  { m_axi_lr_in_RLAST LAST 0 1 }  { m_axi_lr_in_RID ID 0 1 }  { m_axi_lr_in_RUSER USER 0 1 }  { m_axi_lr_in_RRESP RESP 0 2 }  { m_axi_lr_in_BVALID VALID 0 1 }  { m_axi_lr_in_BREADY READY 1 1 }  { m_axi_lr_in_BRESP RESP 0 2 }  { m_axi_lr_in_BID ID 0 1 }  { m_axi_lr_in_BUSER USER 0 1 } } }
	lr_in_offset { ap_none {  { lr_in_offset in_data 0 30 } } }
	probability_result { ap_memory {  { probability_result_address0 mem_address 1 4 }  { probability_result_ce0 mem_ce 1 1 }  { probability_result_q0 mem_dout 0 32 } } }
	fc_in_3_relu2_0 { ap_memory {  { fc_in_3_relu2_0_address0 mem_address 1 6 }  { fc_in_3_relu2_0_ce0 mem_ce 1 1 }  { fc_in_3_relu2_0_q0 mem_dout 0 32 } } }
	fc_hidden_layer3 { ap_memory {  { fc_hidden_layer3_address0 mem_address 1 9 }  { fc_hidden_layer3_ce0 mem_ce 1 1 }  { fc_hidden_layer3_we0 mem_we 1 1 }  { fc_hidden_layer3_d0 mem_din 1 32 }  { fc_hidden_layer3_q0 mem_dout 0 32 } } }
	fc_out_2_0 { ap_memory {  { fc_out_2_0_address0 mem_address 1 6 }  { fc_out_2_0_ce0 mem_ce 1 1 }  { fc_out_2_0_q0 mem_dout 0 32 } } }
	fc_in_2_relu1_0 { ap_memory {  { fc_in_2_relu1_0_address0 mem_address 1 8 }  { fc_in_2_relu1_0_ce0 mem_ce 1 1 }  { fc_in_2_relu1_0_q0 mem_dout 0 32 } } }
	fc_hidden_layer2 { ap_memory {  { fc_hidden_layer2_address0 mem_address 1 13 }  { fc_hidden_layer2_ce0 mem_ce 1 1 }  { fc_hidden_layer2_q0 mem_dout 0 32 }  { fc_hidden_layer2_address1 MemPortADDR2 1 13 }  { fc_hidden_layer2_ce1 MemPortCE2 1 1 }  { fc_hidden_layer2_we1 MemPortWE2 1 1 }  { fc_hidden_layer2_d1 MemPortDIN2 1 32 } } }
	fc_out_1_0 { ap_memory {  { fc_out_1_0_address0 mem_address 1 8 }  { fc_out_1_0_ce0 mem_ce 1 1 }  { fc_out_1_0_q0 mem_dout 0 32 } } }
	fc_in_1_0 { ap_memory {  { fc_in_1_0_address0 mem_address 1 10 }  { fc_in_1_0_ce0 mem_ce 1 1 }  { fc_in_1_0_q0 mem_dout 0 32 } } }
	fc_hidden_layer1 { ap_memory {  { fc_hidden_layer1_address0 mem_address 1 17 }  { fc_hidden_layer1_ce0 mem_ce 1 1 }  { fc_hidden_layer1_we0 mem_we 1 1 }  { fc_hidden_layer1_d0 mem_din 1 32 }  { fc_hidden_layer1_q0 mem_dout 0 32 } } }
	conv_out_2 { ap_memory {  { conv_out_2_address0 mem_address 1 10 }  { conv_out_2_ce0 mem_ce 1 1 }  { conv_out_2_q0 mem_dout 0 32 } } }
	conv_kernel_3 { ap_memory {  { conv_kernel_3_address0 mem_address 1 4 }  { conv_kernel_3_ce0 mem_ce 1 1 }  { conv_kernel_3_we0 mem_we 1 1 }  { conv_kernel_3_d0 mem_din 1 32 }  { conv_kernel_3_q0 mem_dout 0 32 } } }
	conv_out_1 { ap_memory {  { conv_out_1_address0 mem_address 1 10 }  { conv_out_1_ce0 mem_ce 1 1 }  { conv_out_1_q0 mem_dout 0 32 } } }
	conv_kernel_2 { ap_memory {  { conv_kernel_2_address0 mem_address 1 4 }  { conv_kernel_2_ce0 mem_ce 1 1 }  { conv_kernel_2_we0 mem_we 1 1 }  { conv_kernel_2_d0 mem_din 1 32 }  { conv_kernel_2_q0 mem_dout 0 32 } } }
	mnist_data { ap_memory {  { mnist_data_address0 mem_address 1 10 }  { mnist_data_ce0 mem_ce 1 1 }  { mnist_data_q0 mem_dout 0 32 } } }
	conv_kernel_1 { ap_memory {  { conv_kernel_1_address0 mem_address 1 4 }  { conv_kernel_1_ce0 mem_ce 1 1 }  { conv_kernel_1_we0 mem_we 1 1 }  { conv_kernel_1_d0 mem_din 1 32 }  { conv_kernel_1_q0 mem_dout 0 32 } } }
}
