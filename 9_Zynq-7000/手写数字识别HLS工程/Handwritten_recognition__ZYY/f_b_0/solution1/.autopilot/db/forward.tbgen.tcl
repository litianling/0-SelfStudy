set moduleName forward
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
set C_modelName {forward}
set C_modelType { void 0 }
set C_modelArgList {
	{ input_matrix float 32 regular {axi_master 0}  }
	{ input_matrix_offset int 30 regular  }
	{ conv1_offset int 30 regular  }
	{ conv2_offset int 30 regular  }
	{ conv3_offset int 30 regular  }
	{ fc1_offset int 30 regular  }
	{ fc2_offset int 30 regular  }
	{ fc3_offset int 30 regular  }
	{ mnist_data float 32 regular {array 900 { 2 3 } 1 1 } {global 2}  }
	{ conv_kernel1 float 32 regular {array 9 { 2 3 } 1 1 } {global 2}  }
	{ conv_kernel2 float 32 regular {array 9 { 2 3 } 1 1 } {global 2}  }
	{ conv_kernel3 float 32 regular {array 9 { 2 3 } 1 1 } {global 2}  }
	{ first_conv1 float 32 regular {array 784 { 2 3 } 1 1 } {global 2}  }
	{ sencond_conv1 float 32 regular {array 676 { 2 3 } 1 1 } {global 2}  }
	{ fc_hidden_layer1 float 32 regular {array 103680 { 2 3 } 1 1 } {global 2}  }
	{ fc_hidden_layer2 float 32 regular {array 8100 { 1 0 } 1 1 } {global 2}  }
	{ fc_hidden_layer3 float 32 regular {array 450 { 2 3 } 1 1 } {global 2}  }
	{ flatten_conv_0 float 32 regular {array 576 { 2 3 } 1 1 } {global 2}  }
	{ first_fc_0 float 32 regular {array 180 { 2 3 } 1 1 } {global 2}  }
	{ first_relu_0 float 32 regular {array 180 { 2 3 } 1 1 } {global 2}  }
	{ second_fc_0 float 32 regular {array 45 { 2 3 } 1 1 } {global 2}  }
	{ second_relu_0 float 32 regular {array 45 { 2 3 } 1 1 } {global 2}  }
	{ outmlp_0 float 32 regular {array 10 { 0 3 } 0 1 } {global 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "input_matrix", "interface" : "axi_master", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "input_matrix_offset", "interface" : "wire", "bitwidth" : 30, "direction" : "READONLY"} , 
 	{ "Name" : "conv1_offset", "interface" : "wire", "bitwidth" : 30, "direction" : "READONLY"} , 
 	{ "Name" : "conv2_offset", "interface" : "wire", "bitwidth" : 30, "direction" : "READONLY"} , 
 	{ "Name" : "conv3_offset", "interface" : "wire", "bitwidth" : 30, "direction" : "READONLY"} , 
 	{ "Name" : "fc1_offset", "interface" : "wire", "bitwidth" : 30, "direction" : "READONLY"} , 
 	{ "Name" : "fc2_offset", "interface" : "wire", "bitwidth" : 30, "direction" : "READONLY"} , 
 	{ "Name" : "fc3_offset", "interface" : "wire", "bitwidth" : 30, "direction" : "READONLY"} , 
 	{ "Name" : "mnist_data", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "conv_kernel1", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "conv_kernel2", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "conv_kernel3", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "first_conv1", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "sencond_conv1", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "fc_hidden_layer1", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "fc_hidden_layer2", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "fc_hidden_layer3", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "flatten_conv_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "first_fc_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "first_relu_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "second_fc_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "second_relu_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "outmlp_0", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY", "extern" : 0} ]}
# RTL Port declarations: 
set portNum 134
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ m_axi_input_matrix_AWVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_input_matrix_AWREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_input_matrix_AWADDR sc_out sc_lv 32 signal 0 } 
	{ m_axi_input_matrix_AWID sc_out sc_lv 1 signal 0 } 
	{ m_axi_input_matrix_AWLEN sc_out sc_lv 32 signal 0 } 
	{ m_axi_input_matrix_AWSIZE sc_out sc_lv 3 signal 0 } 
	{ m_axi_input_matrix_AWBURST sc_out sc_lv 2 signal 0 } 
	{ m_axi_input_matrix_AWLOCK sc_out sc_lv 2 signal 0 } 
	{ m_axi_input_matrix_AWCACHE sc_out sc_lv 4 signal 0 } 
	{ m_axi_input_matrix_AWPROT sc_out sc_lv 3 signal 0 } 
	{ m_axi_input_matrix_AWQOS sc_out sc_lv 4 signal 0 } 
	{ m_axi_input_matrix_AWREGION sc_out sc_lv 4 signal 0 } 
	{ m_axi_input_matrix_AWUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_input_matrix_WVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_input_matrix_WREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_input_matrix_WDATA sc_out sc_lv 32 signal 0 } 
	{ m_axi_input_matrix_WSTRB sc_out sc_lv 4 signal 0 } 
	{ m_axi_input_matrix_WLAST sc_out sc_logic 1 signal 0 } 
	{ m_axi_input_matrix_WID sc_out sc_lv 1 signal 0 } 
	{ m_axi_input_matrix_WUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_input_matrix_ARVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_input_matrix_ARREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_input_matrix_ARADDR sc_out sc_lv 32 signal 0 } 
	{ m_axi_input_matrix_ARID sc_out sc_lv 1 signal 0 } 
	{ m_axi_input_matrix_ARLEN sc_out sc_lv 32 signal 0 } 
	{ m_axi_input_matrix_ARSIZE sc_out sc_lv 3 signal 0 } 
	{ m_axi_input_matrix_ARBURST sc_out sc_lv 2 signal 0 } 
	{ m_axi_input_matrix_ARLOCK sc_out sc_lv 2 signal 0 } 
	{ m_axi_input_matrix_ARCACHE sc_out sc_lv 4 signal 0 } 
	{ m_axi_input_matrix_ARPROT sc_out sc_lv 3 signal 0 } 
	{ m_axi_input_matrix_ARQOS sc_out sc_lv 4 signal 0 } 
	{ m_axi_input_matrix_ARREGION sc_out sc_lv 4 signal 0 } 
	{ m_axi_input_matrix_ARUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_input_matrix_RVALID sc_in sc_logic 1 signal 0 } 
	{ m_axi_input_matrix_RREADY sc_out sc_logic 1 signal 0 } 
	{ m_axi_input_matrix_RDATA sc_in sc_lv 32 signal 0 } 
	{ m_axi_input_matrix_RLAST sc_in sc_logic 1 signal 0 } 
	{ m_axi_input_matrix_RID sc_in sc_lv 1 signal 0 } 
	{ m_axi_input_matrix_RUSER sc_in sc_lv 1 signal 0 } 
	{ m_axi_input_matrix_RRESP sc_in sc_lv 2 signal 0 } 
	{ m_axi_input_matrix_BVALID sc_in sc_logic 1 signal 0 } 
	{ m_axi_input_matrix_BREADY sc_out sc_logic 1 signal 0 } 
	{ m_axi_input_matrix_BRESP sc_in sc_lv 2 signal 0 } 
	{ m_axi_input_matrix_BID sc_in sc_lv 1 signal 0 } 
	{ m_axi_input_matrix_BUSER sc_in sc_lv 1 signal 0 } 
	{ input_matrix_offset sc_in sc_lv 30 signal 1 } 
	{ conv1_offset sc_in sc_lv 30 signal 2 } 
	{ conv2_offset sc_in sc_lv 30 signal 3 } 
	{ conv3_offset sc_in sc_lv 30 signal 4 } 
	{ fc1_offset sc_in sc_lv 30 signal 5 } 
	{ fc2_offset sc_in sc_lv 30 signal 6 } 
	{ fc3_offset sc_in sc_lv 30 signal 7 } 
	{ mnist_data_address0 sc_out sc_lv 10 signal 8 } 
	{ mnist_data_ce0 sc_out sc_logic 1 signal 8 } 
	{ mnist_data_we0 sc_out sc_logic 1 signal 8 } 
	{ mnist_data_d0 sc_out sc_lv 32 signal 8 } 
	{ mnist_data_q0 sc_in sc_lv 32 signal 8 } 
	{ conv_kernel1_address0 sc_out sc_lv 4 signal 9 } 
	{ conv_kernel1_ce0 sc_out sc_logic 1 signal 9 } 
	{ conv_kernel1_we0 sc_out sc_logic 1 signal 9 } 
	{ conv_kernel1_d0 sc_out sc_lv 32 signal 9 } 
	{ conv_kernel1_q0 sc_in sc_lv 32 signal 9 } 
	{ conv_kernel2_address0 sc_out sc_lv 4 signal 10 } 
	{ conv_kernel2_ce0 sc_out sc_logic 1 signal 10 } 
	{ conv_kernel2_we0 sc_out sc_logic 1 signal 10 } 
	{ conv_kernel2_d0 sc_out sc_lv 32 signal 10 } 
	{ conv_kernel2_q0 sc_in sc_lv 32 signal 10 } 
	{ conv_kernel3_address0 sc_out sc_lv 4 signal 11 } 
	{ conv_kernel3_ce0 sc_out sc_logic 1 signal 11 } 
	{ conv_kernel3_we0 sc_out sc_logic 1 signal 11 } 
	{ conv_kernel3_d0 sc_out sc_lv 32 signal 11 } 
	{ conv_kernel3_q0 sc_in sc_lv 32 signal 11 } 
	{ first_conv1_address0 sc_out sc_lv 10 signal 12 } 
	{ first_conv1_ce0 sc_out sc_logic 1 signal 12 } 
	{ first_conv1_we0 sc_out sc_logic 1 signal 12 } 
	{ first_conv1_d0 sc_out sc_lv 32 signal 12 } 
	{ first_conv1_q0 sc_in sc_lv 32 signal 12 } 
	{ sencond_conv1_address0 sc_out sc_lv 10 signal 13 } 
	{ sencond_conv1_ce0 sc_out sc_logic 1 signal 13 } 
	{ sencond_conv1_we0 sc_out sc_logic 1 signal 13 } 
	{ sencond_conv1_d0 sc_out sc_lv 32 signal 13 } 
	{ sencond_conv1_q0 sc_in sc_lv 32 signal 13 } 
	{ fc_hidden_layer1_address0 sc_out sc_lv 17 signal 14 } 
	{ fc_hidden_layer1_ce0 sc_out sc_logic 1 signal 14 } 
	{ fc_hidden_layer1_we0 sc_out sc_logic 1 signal 14 } 
	{ fc_hidden_layer1_d0 sc_out sc_lv 32 signal 14 } 
	{ fc_hidden_layer1_q0 sc_in sc_lv 32 signal 14 } 
	{ fc_hidden_layer2_address0 sc_out sc_lv 13 signal 15 } 
	{ fc_hidden_layer2_ce0 sc_out sc_logic 1 signal 15 } 
	{ fc_hidden_layer2_q0 sc_in sc_lv 32 signal 15 } 
	{ fc_hidden_layer2_address1 sc_out sc_lv 13 signal 15 } 
	{ fc_hidden_layer2_ce1 sc_out sc_logic 1 signal 15 } 
	{ fc_hidden_layer2_we1 sc_out sc_logic 1 signal 15 } 
	{ fc_hidden_layer2_d1 sc_out sc_lv 32 signal 15 } 
	{ fc_hidden_layer3_address0 sc_out sc_lv 9 signal 16 } 
	{ fc_hidden_layer3_ce0 sc_out sc_logic 1 signal 16 } 
	{ fc_hidden_layer3_we0 sc_out sc_logic 1 signal 16 } 
	{ fc_hidden_layer3_d0 sc_out sc_lv 32 signal 16 } 
	{ fc_hidden_layer3_q0 sc_in sc_lv 32 signal 16 } 
	{ flatten_conv_0_address0 sc_out sc_lv 10 signal 17 } 
	{ flatten_conv_0_ce0 sc_out sc_logic 1 signal 17 } 
	{ flatten_conv_0_we0 sc_out sc_logic 1 signal 17 } 
	{ flatten_conv_0_d0 sc_out sc_lv 32 signal 17 } 
	{ flatten_conv_0_q0 sc_in sc_lv 32 signal 17 } 
	{ first_fc_0_address0 sc_out sc_lv 8 signal 18 } 
	{ first_fc_0_ce0 sc_out sc_logic 1 signal 18 } 
	{ first_fc_0_we0 sc_out sc_logic 1 signal 18 } 
	{ first_fc_0_d0 sc_out sc_lv 32 signal 18 } 
	{ first_fc_0_q0 sc_in sc_lv 32 signal 18 } 
	{ first_relu_0_address0 sc_out sc_lv 8 signal 19 } 
	{ first_relu_0_ce0 sc_out sc_logic 1 signal 19 } 
	{ first_relu_0_we0 sc_out sc_logic 1 signal 19 } 
	{ first_relu_0_d0 sc_out sc_lv 32 signal 19 } 
	{ first_relu_0_q0 sc_in sc_lv 32 signal 19 } 
	{ second_fc_0_address0 sc_out sc_lv 6 signal 20 } 
	{ second_fc_0_ce0 sc_out sc_logic 1 signal 20 } 
	{ second_fc_0_we0 sc_out sc_logic 1 signal 20 } 
	{ second_fc_0_d0 sc_out sc_lv 32 signal 20 } 
	{ second_fc_0_q0 sc_in sc_lv 32 signal 20 } 
	{ second_relu_0_address0 sc_out sc_lv 6 signal 21 } 
	{ second_relu_0_ce0 sc_out sc_logic 1 signal 21 } 
	{ second_relu_0_we0 sc_out sc_logic 1 signal 21 } 
	{ second_relu_0_d0 sc_out sc_lv 32 signal 21 } 
	{ second_relu_0_q0 sc_in sc_lv 32 signal 21 } 
	{ outmlp_0_address0 sc_out sc_lv 4 signal 22 } 
	{ outmlp_0_ce0 sc_out sc_logic 1 signal 22 } 
	{ outmlp_0_we0 sc_out sc_logic 1 signal 22 } 
	{ outmlp_0_d0 sc_out sc_lv 32 signal 22 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "m_axi_input_matrix_AWVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "AWVALID" }} , 
 	{ "name": "m_axi_input_matrix_AWREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "AWREADY" }} , 
 	{ "name": "m_axi_input_matrix_AWADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_matrix", "role": "AWADDR" }} , 
 	{ "name": "m_axi_input_matrix_AWID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "AWID" }} , 
 	{ "name": "m_axi_input_matrix_AWLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_matrix", "role": "AWLEN" }} , 
 	{ "name": "m_axi_input_matrix_AWSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "input_matrix", "role": "AWSIZE" }} , 
 	{ "name": "m_axi_input_matrix_AWBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "input_matrix", "role": "AWBURST" }} , 
 	{ "name": "m_axi_input_matrix_AWLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "input_matrix", "role": "AWLOCK" }} , 
 	{ "name": "m_axi_input_matrix_AWCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "input_matrix", "role": "AWCACHE" }} , 
 	{ "name": "m_axi_input_matrix_AWPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "input_matrix", "role": "AWPROT" }} , 
 	{ "name": "m_axi_input_matrix_AWQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "input_matrix", "role": "AWQOS" }} , 
 	{ "name": "m_axi_input_matrix_AWREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "input_matrix", "role": "AWREGION" }} , 
 	{ "name": "m_axi_input_matrix_AWUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "AWUSER" }} , 
 	{ "name": "m_axi_input_matrix_WVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "WVALID" }} , 
 	{ "name": "m_axi_input_matrix_WREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "WREADY" }} , 
 	{ "name": "m_axi_input_matrix_WDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_matrix", "role": "WDATA" }} , 
 	{ "name": "m_axi_input_matrix_WSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "input_matrix", "role": "WSTRB" }} , 
 	{ "name": "m_axi_input_matrix_WLAST", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "WLAST" }} , 
 	{ "name": "m_axi_input_matrix_WID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "WID" }} , 
 	{ "name": "m_axi_input_matrix_WUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "WUSER" }} , 
 	{ "name": "m_axi_input_matrix_ARVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "ARVALID" }} , 
 	{ "name": "m_axi_input_matrix_ARREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "ARREADY" }} , 
 	{ "name": "m_axi_input_matrix_ARADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_matrix", "role": "ARADDR" }} , 
 	{ "name": "m_axi_input_matrix_ARID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "ARID" }} , 
 	{ "name": "m_axi_input_matrix_ARLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_matrix", "role": "ARLEN" }} , 
 	{ "name": "m_axi_input_matrix_ARSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "input_matrix", "role": "ARSIZE" }} , 
 	{ "name": "m_axi_input_matrix_ARBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "input_matrix", "role": "ARBURST" }} , 
 	{ "name": "m_axi_input_matrix_ARLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "input_matrix", "role": "ARLOCK" }} , 
 	{ "name": "m_axi_input_matrix_ARCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "input_matrix", "role": "ARCACHE" }} , 
 	{ "name": "m_axi_input_matrix_ARPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "input_matrix", "role": "ARPROT" }} , 
 	{ "name": "m_axi_input_matrix_ARQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "input_matrix", "role": "ARQOS" }} , 
 	{ "name": "m_axi_input_matrix_ARREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "input_matrix", "role": "ARREGION" }} , 
 	{ "name": "m_axi_input_matrix_ARUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "ARUSER" }} , 
 	{ "name": "m_axi_input_matrix_RVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "RVALID" }} , 
 	{ "name": "m_axi_input_matrix_RREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "RREADY" }} , 
 	{ "name": "m_axi_input_matrix_RDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_matrix", "role": "RDATA" }} , 
 	{ "name": "m_axi_input_matrix_RLAST", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "RLAST" }} , 
 	{ "name": "m_axi_input_matrix_RID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "RID" }} , 
 	{ "name": "m_axi_input_matrix_RUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "RUSER" }} , 
 	{ "name": "m_axi_input_matrix_RRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "input_matrix", "role": "RRESP" }} , 
 	{ "name": "m_axi_input_matrix_BVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "BVALID" }} , 
 	{ "name": "m_axi_input_matrix_BREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "BREADY" }} , 
 	{ "name": "m_axi_input_matrix_BRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "input_matrix", "role": "BRESP" }} , 
 	{ "name": "m_axi_input_matrix_BID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "BID" }} , 
 	{ "name": "m_axi_input_matrix_BUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "BUSER" }} , 
 	{ "name": "input_matrix_offset", "direction": "in", "datatype": "sc_lv", "bitwidth":30, "type": "signal", "bundle":{"name": "input_matrix_offset", "role": "default" }} , 
 	{ "name": "conv1_offset", "direction": "in", "datatype": "sc_lv", "bitwidth":30, "type": "signal", "bundle":{"name": "conv1_offset", "role": "default" }} , 
 	{ "name": "conv2_offset", "direction": "in", "datatype": "sc_lv", "bitwidth":30, "type": "signal", "bundle":{"name": "conv2_offset", "role": "default" }} , 
 	{ "name": "conv3_offset", "direction": "in", "datatype": "sc_lv", "bitwidth":30, "type": "signal", "bundle":{"name": "conv3_offset", "role": "default" }} , 
 	{ "name": "fc1_offset", "direction": "in", "datatype": "sc_lv", "bitwidth":30, "type": "signal", "bundle":{"name": "fc1_offset", "role": "default" }} , 
 	{ "name": "fc2_offset", "direction": "in", "datatype": "sc_lv", "bitwidth":30, "type": "signal", "bundle":{"name": "fc2_offset", "role": "default" }} , 
 	{ "name": "fc3_offset", "direction": "in", "datatype": "sc_lv", "bitwidth":30, "type": "signal", "bundle":{"name": "fc3_offset", "role": "default" }} , 
 	{ "name": "mnist_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "mnist_data", "role": "address0" }} , 
 	{ "name": "mnist_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "mnist_data", "role": "ce0" }} , 
 	{ "name": "mnist_data_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "mnist_data", "role": "we0" }} , 
 	{ "name": "mnist_data_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "mnist_data", "role": "d0" }} , 
 	{ "name": "mnist_data_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "mnist_data", "role": "q0" }} , 
 	{ "name": "conv_kernel1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv_kernel1", "role": "address0" }} , 
 	{ "name": "conv_kernel1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel1", "role": "ce0" }} , 
 	{ "name": "conv_kernel1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel1", "role": "we0" }} , 
 	{ "name": "conv_kernel1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel1", "role": "d0" }} , 
 	{ "name": "conv_kernel1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel1", "role": "q0" }} , 
 	{ "name": "conv_kernel2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv_kernel2", "role": "address0" }} , 
 	{ "name": "conv_kernel2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel2", "role": "ce0" }} , 
 	{ "name": "conv_kernel2_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel2", "role": "we0" }} , 
 	{ "name": "conv_kernel2_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel2", "role": "d0" }} , 
 	{ "name": "conv_kernel2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel2", "role": "q0" }} , 
 	{ "name": "conv_kernel3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv_kernel3", "role": "address0" }} , 
 	{ "name": "conv_kernel3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel3", "role": "ce0" }} , 
 	{ "name": "conv_kernel3_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel3", "role": "we0" }} , 
 	{ "name": "conv_kernel3_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel3", "role": "d0" }} , 
 	{ "name": "conv_kernel3_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel3", "role": "q0" }} , 
 	{ "name": "first_conv1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "first_conv1", "role": "address0" }} , 
 	{ "name": "first_conv1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "first_conv1", "role": "ce0" }} , 
 	{ "name": "first_conv1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "first_conv1", "role": "we0" }} , 
 	{ "name": "first_conv1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "first_conv1", "role": "d0" }} , 
 	{ "name": "first_conv1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "first_conv1", "role": "q0" }} , 
 	{ "name": "sencond_conv1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "sencond_conv1", "role": "address0" }} , 
 	{ "name": "sencond_conv1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "sencond_conv1", "role": "ce0" }} , 
 	{ "name": "sencond_conv1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "sencond_conv1", "role": "we0" }} , 
 	{ "name": "sencond_conv1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "sencond_conv1", "role": "d0" }} , 
 	{ "name": "sencond_conv1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "sencond_conv1", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":17, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "address0" }} , 
 	{ "name": "fc_hidden_layer1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "ce0" }} , 
 	{ "name": "fc_hidden_layer1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "we0" }} , 
 	{ "name": "fc_hidden_layer1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "d0" }} , 
 	{ "name": "fc_hidden_layer1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "address0" }} , 
 	{ "name": "fc_hidden_layer2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "ce0" }} , 
 	{ "name": "fc_hidden_layer2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer2_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "address1" }} , 
 	{ "name": "fc_hidden_layer2_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "ce1" }} , 
 	{ "name": "fc_hidden_layer2_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "we1" }} , 
 	{ "name": "fc_hidden_layer2_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "d1" }} , 
 	{ "name": "fc_hidden_layer3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "address0" }} , 
 	{ "name": "fc_hidden_layer3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "ce0" }} , 
 	{ "name": "fc_hidden_layer3_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "we0" }} , 
 	{ "name": "fc_hidden_layer3_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "d0" }} , 
 	{ "name": "fc_hidden_layer3_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "q0" }} , 
 	{ "name": "flatten_conv_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "flatten_conv_0", "role": "address0" }} , 
 	{ "name": "flatten_conv_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "flatten_conv_0", "role": "ce0" }} , 
 	{ "name": "flatten_conv_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "flatten_conv_0", "role": "we0" }} , 
 	{ "name": "flatten_conv_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "flatten_conv_0", "role": "d0" }} , 
 	{ "name": "flatten_conv_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "flatten_conv_0", "role": "q0" }} , 
 	{ "name": "first_fc_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "first_fc_0", "role": "address0" }} , 
 	{ "name": "first_fc_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "first_fc_0", "role": "ce0" }} , 
 	{ "name": "first_fc_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "first_fc_0", "role": "we0" }} , 
 	{ "name": "first_fc_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "first_fc_0", "role": "d0" }} , 
 	{ "name": "first_fc_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "first_fc_0", "role": "q0" }} , 
 	{ "name": "first_relu_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "first_relu_0", "role": "address0" }} , 
 	{ "name": "first_relu_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "first_relu_0", "role": "ce0" }} , 
 	{ "name": "first_relu_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "first_relu_0", "role": "we0" }} , 
 	{ "name": "first_relu_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "first_relu_0", "role": "d0" }} , 
 	{ "name": "first_relu_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "first_relu_0", "role": "q0" }} , 
 	{ "name": "second_fc_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "second_fc_0", "role": "address0" }} , 
 	{ "name": "second_fc_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "second_fc_0", "role": "ce0" }} , 
 	{ "name": "second_fc_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "second_fc_0", "role": "we0" }} , 
 	{ "name": "second_fc_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "second_fc_0", "role": "d0" }} , 
 	{ "name": "second_fc_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "second_fc_0", "role": "q0" }} , 
 	{ "name": "second_relu_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "second_relu_0", "role": "address0" }} , 
 	{ "name": "second_relu_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "second_relu_0", "role": "ce0" }} , 
 	{ "name": "second_relu_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "second_relu_0", "role": "we0" }} , 
 	{ "name": "second_relu_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "second_relu_0", "role": "d0" }} , 
 	{ "name": "second_relu_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "second_relu_0", "role": "q0" }} , 
 	{ "name": "outmlp_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "outmlp_0", "role": "address0" }} , 
 	{ "name": "outmlp_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "outmlp_0", "role": "ce0" }} , 
 	{ "name": "outmlp_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "outmlp_0", "role": "we0" }} , 
 	{ "name": "outmlp_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "outmlp_0", "role": "d0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "5", "9", "12", "13", "14", "15", "16", "17"],
		"CDFG" : "forward",
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
			{"State" : "ap_ST_fsm_state43", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d1_fu_855"},
			{"State" : "ap_ST_fsm_state45", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d2_fu_865"},
			{"State" : "ap_ST_fsm_state47", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d3_fu_875"}],
		"Port" : [
			{"Name" : "input_matrix", "Type" : "MAXI", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "input_matrix_blk_n_AR", "Type" : "RtlSignal"},
					{"Name" : "input_matrix_blk_n_R", "Type" : "RtlSignal"}]},
			{"Name" : "input_matrix_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "conv1_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "conv2_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "conv3_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "fc1_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "fc2_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "fc3_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "mnist_data", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "2", "SubInstance" : "grp_Conv2d1_fu_855", "Port" : "input_matrix"}]},
			{"Name" : "conv_kernel1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "2", "SubInstance" : "grp_Conv2d1_fu_855", "Port" : "kernel"}]},
			{"Name" : "conv_kernel2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "grp_Conv2d2_fu_865", "Port" : "kernel"}]},
			{"Name" : "conv_kernel3", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "9", "SubInstance" : "grp_Conv2d3_fu_875", "Port" : "kernel"}]},
			{"Name" : "first_conv1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "grp_Conv2d2_fu_865", "Port" : "input_matrix"},
					{"ID" : "2", "SubInstance" : "grp_Conv2d1_fu_855", "Port" : "out_matrix"}]},
			{"Name" : "sencond_conv1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "grp_Conv2d2_fu_865", "Port" : "out_matrix"},
					{"ID" : "9", "SubInstance" : "grp_Conv2d3_fu_875", "Port" : "input_matrix"}]},
			{"Name" : "third_conv1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "9", "SubInstance" : "grp_Conv2d3_fu_875", "Port" : "out_matrix"}]},
			{"Name" : "fc_hidden_layer1", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_hidden_layer2", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_hidden_layer3", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "flatten_conv_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "first_fc_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "first_relu_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "second_fc_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "second_relu_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "outmlp_0", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.third_conv1_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d1_fu_855", "Parent" : "0", "Child" : ["3", "4"],
		"CDFG" : "Conv2d1",
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
	{"ID" : "3", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d1_fu_855.forw_back_fadd_32bkb_U1", "Parent" : "2"},
	{"ID" : "4", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d1_fu_855.forw_back_fmul_32cud_U2", "Parent" : "2"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d2_fu_865", "Parent" : "0", "Child" : ["6", "7", "8"],
		"CDFG" : "Conv2d2",
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
	{"ID" : "6", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d2_fu_865.forw_back_fadd_32bkb_U8", "Parent" : "5"},
	{"ID" : "7", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d2_fu_865.forw_back_fmul_32cud_U9", "Parent" : "5"},
	{"ID" : "8", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d2_fu_865.forw_back_mac_muldEe_U10", "Parent" : "5"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d3_fu_875", "Parent" : "0", "Child" : ["10", "11"],
		"CDFG" : "Conv2d3",
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
	{"ID" : "10", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d3_fu_875.forw_back_fadd_32bkb_U15", "Parent" : "9"},
	{"ID" : "11", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d3_fu_875.forw_back_fmul_32cud_U16", "Parent" : "9"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fadd_32bkb_U20", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fmul_32cud_U21", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fptrunceOg_U22", "Parent" : "0"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fpext_3fYi_U23", "Parent" : "0"},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fcmp_32g8j_U24", "Parent" : "0"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_dmul_64hbi_U25", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	forward {
		input_matrix {Type I LastRead 56 FirstWrite -1}
		input_matrix_offset {Type I LastRead 0 FirstWrite -1}
		conv1_offset {Type I LastRead 6 FirstWrite -1}
		conv2_offset {Type I LastRead 6 FirstWrite -1}
		conv3_offset {Type I LastRead 6 FirstWrite -1}
		fc1_offset {Type I LastRead 6 FirstWrite -1}
		fc2_offset {Type I LastRead 6 FirstWrite -1}
		fc3_offset {Type I LastRead 6 FirstWrite -1}
		mnist_data {Type IO LastRead 2 FirstWrite -1}
		conv_kernel1 {Type IO LastRead 2 FirstWrite -1}
		conv_kernel2 {Type IO LastRead 2 FirstWrite -1}
		conv_kernel3 {Type IO LastRead 2 FirstWrite -1}
		first_conv1 {Type IO LastRead 2 FirstWrite -1}
		sencond_conv1 {Type IO LastRead 2 FirstWrite -1}
		third_conv1 {Type IO LastRead -1 FirstWrite -1}
		fc_hidden_layer1 {Type IO LastRead 59 FirstWrite 41}
		fc_hidden_layer2 {Type IO LastRead 61 FirstWrite 49}
		fc_hidden_layer3 {Type IO LastRead 63 FirstWrite 57}
		flatten_conv_0 {Type IO LastRead 59 FirstWrite 59}
		first_fc_0 {Type IO LastRead 59 FirstWrite 59}
		first_relu_0 {Type IO LastRead 61 FirstWrite 69}
		second_fc_0 {Type IO LastRead 61 FirstWrite 61}
		second_relu_0 {Type IO LastRead 63 FirstWrite 71}
		outmlp_0 {Type O LastRead -1 FirstWrite 63}}
	Conv2d1 {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		kernel {Type I LastRead 2 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}}
	Conv2d2 {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		kernel {Type I LastRead 2 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}}
	Conv2d3 {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		kernel {Type I LastRead 2 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "-1", "Max" : "-1"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
	{"Pipeline" : "2", "EnableSignal" : "ap_enable_pp2"}
	{"Pipeline" : "3", "EnableSignal" : "ap_enable_pp3"}
	{"Pipeline" : "4", "EnableSignal" : "ap_enable_pp4"}
	{"Pipeline" : "5", "EnableSignal" : "ap_enable_pp5"}
	{"Pipeline" : "6", "EnableSignal" : "ap_enable_pp6"}
]}

set Spec2ImplPortList { 
	input_matrix { m_axi {  { m_axi_input_matrix_AWVALID VALID 1 1 }  { m_axi_input_matrix_AWREADY READY 0 1 }  { m_axi_input_matrix_AWADDR ADDR 1 32 }  { m_axi_input_matrix_AWID ID 1 1 }  { m_axi_input_matrix_AWLEN LEN 1 32 }  { m_axi_input_matrix_AWSIZE SIZE 1 3 }  { m_axi_input_matrix_AWBURST BURST 1 2 }  { m_axi_input_matrix_AWLOCK LOCK 1 2 }  { m_axi_input_matrix_AWCACHE CACHE 1 4 }  { m_axi_input_matrix_AWPROT PROT 1 3 }  { m_axi_input_matrix_AWQOS QOS 1 4 }  { m_axi_input_matrix_AWREGION REGION 1 4 }  { m_axi_input_matrix_AWUSER USER 1 1 }  { m_axi_input_matrix_WVALID VALID 1 1 }  { m_axi_input_matrix_WREADY READY 0 1 }  { m_axi_input_matrix_WDATA DATA 1 32 }  { m_axi_input_matrix_WSTRB STRB 1 4 }  { m_axi_input_matrix_WLAST LAST 1 1 }  { m_axi_input_matrix_WID ID 1 1 }  { m_axi_input_matrix_WUSER USER 1 1 }  { m_axi_input_matrix_ARVALID VALID 1 1 }  { m_axi_input_matrix_ARREADY READY 0 1 }  { m_axi_input_matrix_ARADDR ADDR 1 32 }  { m_axi_input_matrix_ARID ID 1 1 }  { m_axi_input_matrix_ARLEN LEN 1 32 }  { m_axi_input_matrix_ARSIZE SIZE 1 3 }  { m_axi_input_matrix_ARBURST BURST 1 2 }  { m_axi_input_matrix_ARLOCK LOCK 1 2 }  { m_axi_input_matrix_ARCACHE CACHE 1 4 }  { m_axi_input_matrix_ARPROT PROT 1 3 }  { m_axi_input_matrix_ARQOS QOS 1 4 }  { m_axi_input_matrix_ARREGION REGION 1 4 }  { m_axi_input_matrix_ARUSER USER 1 1 }  { m_axi_input_matrix_RVALID VALID 0 1 }  { m_axi_input_matrix_RREADY READY 1 1 }  { m_axi_input_matrix_RDATA DATA 0 32 }  { m_axi_input_matrix_RLAST LAST 0 1 }  { m_axi_input_matrix_RID ID 0 1 }  { m_axi_input_matrix_RUSER USER 0 1 }  { m_axi_input_matrix_RRESP RESP 0 2 }  { m_axi_input_matrix_BVALID VALID 0 1 }  { m_axi_input_matrix_BREADY READY 1 1 }  { m_axi_input_matrix_BRESP RESP 0 2 }  { m_axi_input_matrix_BID ID 0 1 }  { m_axi_input_matrix_BUSER USER 0 1 } } }
	input_matrix_offset { ap_none {  { input_matrix_offset in_data 0 30 } } }
	conv1_offset { ap_none {  { conv1_offset in_data 0 30 } } }
	conv2_offset { ap_none {  { conv2_offset in_data 0 30 } } }
	conv3_offset { ap_none {  { conv3_offset in_data 0 30 } } }
	fc1_offset { ap_none {  { fc1_offset in_data 0 30 } } }
	fc2_offset { ap_none {  { fc2_offset in_data 0 30 } } }
	fc3_offset { ap_none {  { fc3_offset in_data 0 30 } } }
	mnist_data { ap_memory {  { mnist_data_address0 mem_address 1 10 }  { mnist_data_ce0 mem_ce 1 1 }  { mnist_data_we0 mem_we 1 1 }  { mnist_data_d0 mem_din 1 32 }  { mnist_data_q0 mem_dout 0 32 } } }
	conv_kernel1 { ap_memory {  { conv_kernel1_address0 mem_address 1 4 }  { conv_kernel1_ce0 mem_ce 1 1 }  { conv_kernel1_we0 mem_we 1 1 }  { conv_kernel1_d0 mem_din 1 32 }  { conv_kernel1_q0 mem_dout 0 32 } } }
	conv_kernel2 { ap_memory {  { conv_kernel2_address0 mem_address 1 4 }  { conv_kernel2_ce0 mem_ce 1 1 }  { conv_kernel2_we0 mem_we 1 1 }  { conv_kernel2_d0 mem_din 1 32 }  { conv_kernel2_q0 mem_dout 0 32 } } }
	conv_kernel3 { ap_memory {  { conv_kernel3_address0 mem_address 1 4 }  { conv_kernel3_ce0 mem_ce 1 1 }  { conv_kernel3_we0 mem_we 1 1 }  { conv_kernel3_d0 mem_din 1 32 }  { conv_kernel3_q0 mem_dout 0 32 } } }
	first_conv1 { ap_memory {  { first_conv1_address0 mem_address 1 10 }  { first_conv1_ce0 mem_ce 1 1 }  { first_conv1_we0 mem_we 1 1 }  { first_conv1_d0 mem_din 1 32 }  { first_conv1_q0 mem_dout 0 32 } } }
	sencond_conv1 { ap_memory {  { sencond_conv1_address0 mem_address 1 10 }  { sencond_conv1_ce0 mem_ce 1 1 }  { sencond_conv1_we0 mem_we 1 1 }  { sencond_conv1_d0 mem_din 1 32 }  { sencond_conv1_q0 mem_dout 0 32 } } }
	fc_hidden_layer1 { ap_memory {  { fc_hidden_layer1_address0 mem_address 1 17 }  { fc_hidden_layer1_ce0 mem_ce 1 1 }  { fc_hidden_layer1_we0 mem_we 1 1 }  { fc_hidden_layer1_d0 mem_din 1 32 }  { fc_hidden_layer1_q0 mem_dout 0 32 } } }
	fc_hidden_layer2 { ap_memory {  { fc_hidden_layer2_address0 mem_address 1 13 }  { fc_hidden_layer2_ce0 mem_ce 1 1 }  { fc_hidden_layer2_q0 mem_dout 0 32 }  { fc_hidden_layer2_address1 MemPortADDR2 1 13 }  { fc_hidden_layer2_ce1 MemPortCE2 1 1 }  { fc_hidden_layer2_we1 MemPortWE2 1 1 }  { fc_hidden_layer2_d1 MemPortDIN2 1 32 } } }
	fc_hidden_layer3 { ap_memory {  { fc_hidden_layer3_address0 mem_address 1 9 }  { fc_hidden_layer3_ce0 mem_ce 1 1 }  { fc_hidden_layer3_we0 mem_we 1 1 }  { fc_hidden_layer3_d0 mem_din 1 32 }  { fc_hidden_layer3_q0 mem_dout 0 32 } } }
	flatten_conv_0 { ap_memory {  { flatten_conv_0_address0 mem_address 1 10 }  { flatten_conv_0_ce0 mem_ce 1 1 }  { flatten_conv_0_we0 mem_we 1 1 }  { flatten_conv_0_d0 mem_din 1 32 }  { flatten_conv_0_q0 mem_dout 0 32 } } }
	first_fc_0 { ap_memory {  { first_fc_0_address0 mem_address 1 8 }  { first_fc_0_ce0 mem_ce 1 1 }  { first_fc_0_we0 mem_we 1 1 }  { first_fc_0_d0 mem_din 1 32 }  { first_fc_0_q0 mem_dout 0 32 } } }
	first_relu_0 { ap_memory {  { first_relu_0_address0 mem_address 1 8 }  { first_relu_0_ce0 mem_ce 1 1 }  { first_relu_0_we0 mem_we 1 1 }  { first_relu_0_d0 mem_din 1 32 }  { first_relu_0_q0 mem_dout 0 32 } } }
	second_fc_0 { ap_memory {  { second_fc_0_address0 mem_address 1 6 }  { second_fc_0_ce0 mem_ce 1 1 }  { second_fc_0_we0 mem_we 1 1 }  { second_fc_0_d0 mem_din 1 32 }  { second_fc_0_q0 mem_dout 0 32 } } }
	second_relu_0 { ap_memory {  { second_relu_0_address0 mem_address 1 6 }  { second_relu_0_ce0 mem_ce 1 1 }  { second_relu_0_we0 mem_we 1 1 }  { second_relu_0_d0 mem_din 1 32 }  { second_relu_0_q0 mem_dout 0 32 } } }
	outmlp_0 { ap_memory {  { outmlp_0_address0 mem_address 1 4 }  { outmlp_0_ce0 mem_ce 1 1 }  { outmlp_0_we0 mem_we 1 1 }  { outmlp_0_d0 mem_din 1 32 } } }
}
