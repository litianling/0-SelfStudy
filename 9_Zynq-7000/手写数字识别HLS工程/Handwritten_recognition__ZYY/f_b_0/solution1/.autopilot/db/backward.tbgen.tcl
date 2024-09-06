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
	{ conv1 float 32 regular {axi_master 2}  }
	{ conv1_offset int 30 regular  }
	{ conv2_offset int 30 regular  }
	{ conv3_offset int 30 regular  }
	{ fc1_offset int 30 regular  }
	{ fc2_offset int 30 regular  }
	{ fc3_offset int 30 regular  }
	{ lr_in_offset int 30 regular  }
	{ result float 32 regular {array 10 { 1 3 } 1 1 } {global 0}  }
	{ second_relu_0 float 32 regular {array 45 { 1 3 } 1 1 } {global 0}  }
	{ fc_hidden_layer3 float 32 regular {array 450 { 2 3 } 1 1 } {global 2}  }
	{ second_fc_0 float 32 regular {array 45 { 1 3 } 1 1 } {global 0}  }
	{ first_relu_0 float 32 regular {array 180 { 1 3 } 1 1 } {global 0}  }
	{ fc_hidden_layer2 float 32 regular {array 8100 { 1 0 } 1 1 } {global 2}  }
	{ first_fc_0 float 32 regular {array 180 { 1 3 } 1 1 } {global 0}  }
	{ flatten_conv_0 float 32 regular {array 576 { 1 3 } 1 1 } {global 0}  }
	{ fc_hidden_layer1 float 32 regular {array 103680 { 2 3 } 1 1 } {global 2}  }
	{ sencond_conv1 float 32 regular {array 676 { 1 1 } 1 1 } {global 0}  }
	{ conv_kernel3 float 32 regular {array 9 { 2 3 } 1 1 } {global 2}  }
	{ first_conv1 float 32 regular {array 784 { 1 1 } 1 1 } {global 0}  }
	{ conv_kernel2 float 32 regular {array 9 { 2 3 } 1 1 } {global 2}  }
	{ mnist_data float 32 regular {array 900 { 1 1 } 1 1 } {global 0}  }
	{ conv_kernel1 float 32 regular {array 9 { 2 3 } 1 1 } {global 2}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "label_r", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "conv1", "interface" : "axi_master", "bitwidth" : 32, "direction" : "READWRITE"} , 
 	{ "Name" : "conv1_offset", "interface" : "wire", "bitwidth" : 30, "direction" : "READONLY"} , 
 	{ "Name" : "conv2_offset", "interface" : "wire", "bitwidth" : 30, "direction" : "READONLY"} , 
 	{ "Name" : "conv3_offset", "interface" : "wire", "bitwidth" : 30, "direction" : "READONLY"} , 
 	{ "Name" : "fc1_offset", "interface" : "wire", "bitwidth" : 30, "direction" : "READONLY"} , 
 	{ "Name" : "fc2_offset", "interface" : "wire", "bitwidth" : 30, "direction" : "READONLY"} , 
 	{ "Name" : "fc3_offset", "interface" : "wire", "bitwidth" : 30, "direction" : "READONLY"} , 
 	{ "Name" : "lr_in_offset", "interface" : "wire", "bitwidth" : 30, "direction" : "READONLY"} , 
 	{ "Name" : "result", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "second_relu_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "fc_hidden_layer3", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "second_fc_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "first_relu_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "fc_hidden_layer2", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "first_fc_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "flatten_conv_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "fc_hidden_layer1", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "sencond_conv1", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "conv_kernel3", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "first_conv1", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "conv_kernel2", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "mnist_data", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "conv_kernel1", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} ]}
# RTL Port declarations: 
set portNum 127
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ label_r sc_in sc_lv 32 signal 0 } 
	{ m_axi_conv1_AWVALID sc_out sc_logic 1 signal 1 } 
	{ m_axi_conv1_AWREADY sc_in sc_logic 1 signal 1 } 
	{ m_axi_conv1_AWADDR sc_out sc_lv 32 signal 1 } 
	{ m_axi_conv1_AWID sc_out sc_lv 1 signal 1 } 
	{ m_axi_conv1_AWLEN sc_out sc_lv 32 signal 1 } 
	{ m_axi_conv1_AWSIZE sc_out sc_lv 3 signal 1 } 
	{ m_axi_conv1_AWBURST sc_out sc_lv 2 signal 1 } 
	{ m_axi_conv1_AWLOCK sc_out sc_lv 2 signal 1 } 
	{ m_axi_conv1_AWCACHE sc_out sc_lv 4 signal 1 } 
	{ m_axi_conv1_AWPROT sc_out sc_lv 3 signal 1 } 
	{ m_axi_conv1_AWQOS sc_out sc_lv 4 signal 1 } 
	{ m_axi_conv1_AWREGION sc_out sc_lv 4 signal 1 } 
	{ m_axi_conv1_AWUSER sc_out sc_lv 1 signal 1 } 
	{ m_axi_conv1_WVALID sc_out sc_logic 1 signal 1 } 
	{ m_axi_conv1_WREADY sc_in sc_logic 1 signal 1 } 
	{ m_axi_conv1_WDATA sc_out sc_lv 32 signal 1 } 
	{ m_axi_conv1_WSTRB sc_out sc_lv 4 signal 1 } 
	{ m_axi_conv1_WLAST sc_out sc_logic 1 signal 1 } 
	{ m_axi_conv1_WID sc_out sc_lv 1 signal 1 } 
	{ m_axi_conv1_WUSER sc_out sc_lv 1 signal 1 } 
	{ m_axi_conv1_ARVALID sc_out sc_logic 1 signal 1 } 
	{ m_axi_conv1_ARREADY sc_in sc_logic 1 signal 1 } 
	{ m_axi_conv1_ARADDR sc_out sc_lv 32 signal 1 } 
	{ m_axi_conv1_ARID sc_out sc_lv 1 signal 1 } 
	{ m_axi_conv1_ARLEN sc_out sc_lv 32 signal 1 } 
	{ m_axi_conv1_ARSIZE sc_out sc_lv 3 signal 1 } 
	{ m_axi_conv1_ARBURST sc_out sc_lv 2 signal 1 } 
	{ m_axi_conv1_ARLOCK sc_out sc_lv 2 signal 1 } 
	{ m_axi_conv1_ARCACHE sc_out sc_lv 4 signal 1 } 
	{ m_axi_conv1_ARPROT sc_out sc_lv 3 signal 1 } 
	{ m_axi_conv1_ARQOS sc_out sc_lv 4 signal 1 } 
	{ m_axi_conv1_ARREGION sc_out sc_lv 4 signal 1 } 
	{ m_axi_conv1_ARUSER sc_out sc_lv 1 signal 1 } 
	{ m_axi_conv1_RVALID sc_in sc_logic 1 signal 1 } 
	{ m_axi_conv1_RREADY sc_out sc_logic 1 signal 1 } 
	{ m_axi_conv1_RDATA sc_in sc_lv 32 signal 1 } 
	{ m_axi_conv1_RLAST sc_in sc_logic 1 signal 1 } 
	{ m_axi_conv1_RID sc_in sc_lv 1 signal 1 } 
	{ m_axi_conv1_RUSER sc_in sc_lv 1 signal 1 } 
	{ m_axi_conv1_RRESP sc_in sc_lv 2 signal 1 } 
	{ m_axi_conv1_BVALID sc_in sc_logic 1 signal 1 } 
	{ m_axi_conv1_BREADY sc_out sc_logic 1 signal 1 } 
	{ m_axi_conv1_BRESP sc_in sc_lv 2 signal 1 } 
	{ m_axi_conv1_BID sc_in sc_lv 1 signal 1 } 
	{ m_axi_conv1_BUSER sc_in sc_lv 1 signal 1 } 
	{ conv1_offset sc_in sc_lv 30 signal 2 } 
	{ conv2_offset sc_in sc_lv 30 signal 3 } 
	{ conv3_offset sc_in sc_lv 30 signal 4 } 
	{ fc1_offset sc_in sc_lv 30 signal 5 } 
	{ fc2_offset sc_in sc_lv 30 signal 6 } 
	{ fc3_offset sc_in sc_lv 30 signal 7 } 
	{ lr_in_offset sc_in sc_lv 30 signal 8 } 
	{ result_address0 sc_out sc_lv 4 signal 9 } 
	{ result_ce0 sc_out sc_logic 1 signal 9 } 
	{ result_q0 sc_in sc_lv 32 signal 9 } 
	{ second_relu_0_address0 sc_out sc_lv 6 signal 10 } 
	{ second_relu_0_ce0 sc_out sc_logic 1 signal 10 } 
	{ second_relu_0_q0 sc_in sc_lv 32 signal 10 } 
	{ fc_hidden_layer3_address0 sc_out sc_lv 9 signal 11 } 
	{ fc_hidden_layer3_ce0 sc_out sc_logic 1 signal 11 } 
	{ fc_hidden_layer3_we0 sc_out sc_logic 1 signal 11 } 
	{ fc_hidden_layer3_d0 sc_out sc_lv 32 signal 11 } 
	{ fc_hidden_layer3_q0 sc_in sc_lv 32 signal 11 } 
	{ second_fc_0_address0 sc_out sc_lv 6 signal 12 } 
	{ second_fc_0_ce0 sc_out sc_logic 1 signal 12 } 
	{ second_fc_0_q0 sc_in sc_lv 32 signal 12 } 
	{ first_relu_0_address0 sc_out sc_lv 8 signal 13 } 
	{ first_relu_0_ce0 sc_out sc_logic 1 signal 13 } 
	{ first_relu_0_q0 sc_in sc_lv 32 signal 13 } 
	{ fc_hidden_layer2_address0 sc_out sc_lv 13 signal 14 } 
	{ fc_hidden_layer2_ce0 sc_out sc_logic 1 signal 14 } 
	{ fc_hidden_layer2_q0 sc_in sc_lv 32 signal 14 } 
	{ fc_hidden_layer2_address1 sc_out sc_lv 13 signal 14 } 
	{ fc_hidden_layer2_ce1 sc_out sc_logic 1 signal 14 } 
	{ fc_hidden_layer2_we1 sc_out sc_logic 1 signal 14 } 
	{ fc_hidden_layer2_d1 sc_out sc_lv 32 signal 14 } 
	{ first_fc_0_address0 sc_out sc_lv 8 signal 15 } 
	{ first_fc_0_ce0 sc_out sc_logic 1 signal 15 } 
	{ first_fc_0_q0 sc_in sc_lv 32 signal 15 } 
	{ flatten_conv_0_address0 sc_out sc_lv 10 signal 16 } 
	{ flatten_conv_0_ce0 sc_out sc_logic 1 signal 16 } 
	{ flatten_conv_0_q0 sc_in sc_lv 32 signal 16 } 
	{ fc_hidden_layer1_address0 sc_out sc_lv 17 signal 17 } 
	{ fc_hidden_layer1_ce0 sc_out sc_logic 1 signal 17 } 
	{ fc_hidden_layer1_we0 sc_out sc_logic 1 signal 17 } 
	{ fc_hidden_layer1_d0 sc_out sc_lv 32 signal 17 } 
	{ fc_hidden_layer1_q0 sc_in sc_lv 32 signal 17 } 
	{ sencond_conv1_address0 sc_out sc_lv 10 signal 18 } 
	{ sencond_conv1_ce0 sc_out sc_logic 1 signal 18 } 
	{ sencond_conv1_q0 sc_in sc_lv 32 signal 18 } 
	{ sencond_conv1_address1 sc_out sc_lv 10 signal 18 } 
	{ sencond_conv1_ce1 sc_out sc_logic 1 signal 18 } 
	{ sencond_conv1_q1 sc_in sc_lv 32 signal 18 } 
	{ conv_kernel3_address0 sc_out sc_lv 4 signal 19 } 
	{ conv_kernel3_ce0 sc_out sc_logic 1 signal 19 } 
	{ conv_kernel3_we0 sc_out sc_logic 1 signal 19 } 
	{ conv_kernel3_d0 sc_out sc_lv 32 signal 19 } 
	{ conv_kernel3_q0 sc_in sc_lv 32 signal 19 } 
	{ first_conv1_address0 sc_out sc_lv 10 signal 20 } 
	{ first_conv1_ce0 sc_out sc_logic 1 signal 20 } 
	{ first_conv1_q0 sc_in sc_lv 32 signal 20 } 
	{ first_conv1_address1 sc_out sc_lv 10 signal 20 } 
	{ first_conv1_ce1 sc_out sc_logic 1 signal 20 } 
	{ first_conv1_q1 sc_in sc_lv 32 signal 20 } 
	{ conv_kernel2_address0 sc_out sc_lv 4 signal 21 } 
	{ conv_kernel2_ce0 sc_out sc_logic 1 signal 21 } 
	{ conv_kernel2_we0 sc_out sc_logic 1 signal 21 } 
	{ conv_kernel2_d0 sc_out sc_lv 32 signal 21 } 
	{ conv_kernel2_q0 sc_in sc_lv 32 signal 21 } 
	{ mnist_data_address0 sc_out sc_lv 10 signal 22 } 
	{ mnist_data_ce0 sc_out sc_logic 1 signal 22 } 
	{ mnist_data_q0 sc_in sc_lv 32 signal 22 } 
	{ mnist_data_address1 sc_out sc_lv 10 signal 22 } 
	{ mnist_data_ce1 sc_out sc_logic 1 signal 22 } 
	{ mnist_data_q1 sc_in sc_lv 32 signal 22 } 
	{ conv_kernel1_address0 sc_out sc_lv 4 signal 23 } 
	{ conv_kernel1_ce0 sc_out sc_logic 1 signal 23 } 
	{ conv_kernel1_we0 sc_out sc_logic 1 signal 23 } 
	{ conv_kernel1_d0 sc_out sc_lv 32 signal 23 } 
	{ conv_kernel1_q0 sc_in sc_lv 32 signal 23 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "label_r", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "label_r", "role": "default" }} , 
 	{ "name": "m_axi_conv1_AWVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "AWVALID" }} , 
 	{ "name": "m_axi_conv1_AWREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "AWREADY" }} , 
 	{ "name": "m_axi_conv1_AWADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv1", "role": "AWADDR" }} , 
 	{ "name": "m_axi_conv1_AWID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "AWID" }} , 
 	{ "name": "m_axi_conv1_AWLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv1", "role": "AWLEN" }} , 
 	{ "name": "m_axi_conv1_AWSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "conv1", "role": "AWSIZE" }} , 
 	{ "name": "m_axi_conv1_AWBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "conv1", "role": "AWBURST" }} , 
 	{ "name": "m_axi_conv1_AWLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "conv1", "role": "AWLOCK" }} , 
 	{ "name": "m_axi_conv1_AWCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv1", "role": "AWCACHE" }} , 
 	{ "name": "m_axi_conv1_AWPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "conv1", "role": "AWPROT" }} , 
 	{ "name": "m_axi_conv1_AWQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv1", "role": "AWQOS" }} , 
 	{ "name": "m_axi_conv1_AWREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv1", "role": "AWREGION" }} , 
 	{ "name": "m_axi_conv1_AWUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "AWUSER" }} , 
 	{ "name": "m_axi_conv1_WVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "WVALID" }} , 
 	{ "name": "m_axi_conv1_WREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "WREADY" }} , 
 	{ "name": "m_axi_conv1_WDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv1", "role": "WDATA" }} , 
 	{ "name": "m_axi_conv1_WSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv1", "role": "WSTRB" }} , 
 	{ "name": "m_axi_conv1_WLAST", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "WLAST" }} , 
 	{ "name": "m_axi_conv1_WID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "WID" }} , 
 	{ "name": "m_axi_conv1_WUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "WUSER" }} , 
 	{ "name": "m_axi_conv1_ARVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "ARVALID" }} , 
 	{ "name": "m_axi_conv1_ARREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "ARREADY" }} , 
 	{ "name": "m_axi_conv1_ARADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv1", "role": "ARADDR" }} , 
 	{ "name": "m_axi_conv1_ARID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "ARID" }} , 
 	{ "name": "m_axi_conv1_ARLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv1", "role": "ARLEN" }} , 
 	{ "name": "m_axi_conv1_ARSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "conv1", "role": "ARSIZE" }} , 
 	{ "name": "m_axi_conv1_ARBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "conv1", "role": "ARBURST" }} , 
 	{ "name": "m_axi_conv1_ARLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "conv1", "role": "ARLOCK" }} , 
 	{ "name": "m_axi_conv1_ARCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv1", "role": "ARCACHE" }} , 
 	{ "name": "m_axi_conv1_ARPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "conv1", "role": "ARPROT" }} , 
 	{ "name": "m_axi_conv1_ARQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv1", "role": "ARQOS" }} , 
 	{ "name": "m_axi_conv1_ARREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv1", "role": "ARREGION" }} , 
 	{ "name": "m_axi_conv1_ARUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "ARUSER" }} , 
 	{ "name": "m_axi_conv1_RVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "RVALID" }} , 
 	{ "name": "m_axi_conv1_RREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "RREADY" }} , 
 	{ "name": "m_axi_conv1_RDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv1", "role": "RDATA" }} , 
 	{ "name": "m_axi_conv1_RLAST", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "RLAST" }} , 
 	{ "name": "m_axi_conv1_RID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "RID" }} , 
 	{ "name": "m_axi_conv1_RUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "RUSER" }} , 
 	{ "name": "m_axi_conv1_RRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "conv1", "role": "RRESP" }} , 
 	{ "name": "m_axi_conv1_BVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "BVALID" }} , 
 	{ "name": "m_axi_conv1_BREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "BREADY" }} , 
 	{ "name": "m_axi_conv1_BRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "conv1", "role": "BRESP" }} , 
 	{ "name": "m_axi_conv1_BID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "BID" }} , 
 	{ "name": "m_axi_conv1_BUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "conv1", "role": "BUSER" }} , 
 	{ "name": "conv1_offset", "direction": "in", "datatype": "sc_lv", "bitwidth":30, "type": "signal", "bundle":{"name": "conv1_offset", "role": "default" }} , 
 	{ "name": "conv2_offset", "direction": "in", "datatype": "sc_lv", "bitwidth":30, "type": "signal", "bundle":{"name": "conv2_offset", "role": "default" }} , 
 	{ "name": "conv3_offset", "direction": "in", "datatype": "sc_lv", "bitwidth":30, "type": "signal", "bundle":{"name": "conv3_offset", "role": "default" }} , 
 	{ "name": "fc1_offset", "direction": "in", "datatype": "sc_lv", "bitwidth":30, "type": "signal", "bundle":{"name": "fc1_offset", "role": "default" }} , 
 	{ "name": "fc2_offset", "direction": "in", "datatype": "sc_lv", "bitwidth":30, "type": "signal", "bundle":{"name": "fc2_offset", "role": "default" }} , 
 	{ "name": "fc3_offset", "direction": "in", "datatype": "sc_lv", "bitwidth":30, "type": "signal", "bundle":{"name": "fc3_offset", "role": "default" }} , 
 	{ "name": "lr_in_offset", "direction": "in", "datatype": "sc_lv", "bitwidth":30, "type": "signal", "bundle":{"name": "lr_in_offset", "role": "default" }} , 
 	{ "name": "result_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "result", "role": "address0" }} , 
 	{ "name": "result_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "result", "role": "ce0" }} , 
 	{ "name": "result_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "result", "role": "q0" }} , 
 	{ "name": "second_relu_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "second_relu_0", "role": "address0" }} , 
 	{ "name": "second_relu_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "second_relu_0", "role": "ce0" }} , 
 	{ "name": "second_relu_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "second_relu_0", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "address0" }} , 
 	{ "name": "fc_hidden_layer3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "ce0" }} , 
 	{ "name": "fc_hidden_layer3_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "we0" }} , 
 	{ "name": "fc_hidden_layer3_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "d0" }} , 
 	{ "name": "fc_hidden_layer3_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "q0" }} , 
 	{ "name": "second_fc_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "second_fc_0", "role": "address0" }} , 
 	{ "name": "second_fc_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "second_fc_0", "role": "ce0" }} , 
 	{ "name": "second_fc_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "second_fc_0", "role": "q0" }} , 
 	{ "name": "first_relu_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "first_relu_0", "role": "address0" }} , 
 	{ "name": "first_relu_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "first_relu_0", "role": "ce0" }} , 
 	{ "name": "first_relu_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "first_relu_0", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "address0" }} , 
 	{ "name": "fc_hidden_layer2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "ce0" }} , 
 	{ "name": "fc_hidden_layer2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer2_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "address1" }} , 
 	{ "name": "fc_hidden_layer2_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "ce1" }} , 
 	{ "name": "fc_hidden_layer2_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "we1" }} , 
 	{ "name": "fc_hidden_layer2_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "d1" }} , 
 	{ "name": "first_fc_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "first_fc_0", "role": "address0" }} , 
 	{ "name": "first_fc_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "first_fc_0", "role": "ce0" }} , 
 	{ "name": "first_fc_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "first_fc_0", "role": "q0" }} , 
 	{ "name": "flatten_conv_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "flatten_conv_0", "role": "address0" }} , 
 	{ "name": "flatten_conv_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "flatten_conv_0", "role": "ce0" }} , 
 	{ "name": "flatten_conv_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "flatten_conv_0", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":17, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "address0" }} , 
 	{ "name": "fc_hidden_layer1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "ce0" }} , 
 	{ "name": "fc_hidden_layer1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "we0" }} , 
 	{ "name": "fc_hidden_layer1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "d0" }} , 
 	{ "name": "fc_hidden_layer1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "q0" }} , 
 	{ "name": "sencond_conv1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "sencond_conv1", "role": "address0" }} , 
 	{ "name": "sencond_conv1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "sencond_conv1", "role": "ce0" }} , 
 	{ "name": "sencond_conv1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "sencond_conv1", "role": "q0" }} , 
 	{ "name": "sencond_conv1_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "sencond_conv1", "role": "address1" }} , 
 	{ "name": "sencond_conv1_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "sencond_conv1", "role": "ce1" }} , 
 	{ "name": "sencond_conv1_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "sencond_conv1", "role": "q1" }} , 
 	{ "name": "conv_kernel3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv_kernel3", "role": "address0" }} , 
 	{ "name": "conv_kernel3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel3", "role": "ce0" }} , 
 	{ "name": "conv_kernel3_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel3", "role": "we0" }} , 
 	{ "name": "conv_kernel3_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel3", "role": "d0" }} , 
 	{ "name": "conv_kernel3_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel3", "role": "q0" }} , 
 	{ "name": "first_conv1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "first_conv1", "role": "address0" }} , 
 	{ "name": "first_conv1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "first_conv1", "role": "ce0" }} , 
 	{ "name": "first_conv1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "first_conv1", "role": "q0" }} , 
 	{ "name": "first_conv1_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "first_conv1", "role": "address1" }} , 
 	{ "name": "first_conv1_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "first_conv1", "role": "ce1" }} , 
 	{ "name": "first_conv1_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "first_conv1", "role": "q1" }} , 
 	{ "name": "conv_kernel2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv_kernel2", "role": "address0" }} , 
 	{ "name": "conv_kernel2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel2", "role": "ce0" }} , 
 	{ "name": "conv_kernel2_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel2", "role": "we0" }} , 
 	{ "name": "conv_kernel2_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel2", "role": "d0" }} , 
 	{ "name": "conv_kernel2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel2", "role": "q0" }} , 
 	{ "name": "mnist_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "mnist_data", "role": "address0" }} , 
 	{ "name": "mnist_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "mnist_data", "role": "ce0" }} , 
 	{ "name": "mnist_data_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "mnist_data", "role": "q0" }} , 
 	{ "name": "mnist_data_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "mnist_data", "role": "address1" }} , 
 	{ "name": "mnist_data_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "mnist_data", "role": "ce1" }} , 
 	{ "name": "mnist_data_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "mnist_data", "role": "q1" }} , 
 	{ "name": "conv_kernel1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv_kernel1", "role": "address0" }} , 
 	{ "name": "conv_kernel1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel1", "role": "ce0" }} , 
 	{ "name": "conv_kernel1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel1", "role": "we0" }} , 
 	{ "name": "conv_kernel1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel1", "role": "d0" }} , 
 	{ "name": "conv_kernel1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel1", "role": "q0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "22", "26", "29", "32", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45"],
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
			{"State" : "ap_ST_fsm_state97", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_b4_fu_1510"},
			{"State" : "ap_ST_fsm_state88", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_b2_fu_1517"},
			{"State" : "ap_ST_fsm_state99", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_b5_fu_1524"},
			{"State" : "ap_ST_fsm_state85", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_b1_fu_1532"},
			{"State" : "ap_ST_fsm_state90", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_b3_fu_1540"},
			{"State" : "ap_ST_fsm_state85", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_OverturnKernel_fu_1548"},
			{"State" : "ap_ST_fsm_state88", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_OverturnKernel_fu_1548"}],
		"Port" : [
			{"Name" : "label_r", "Type" : "None", "Direction" : "I"},
			{"Name" : "conv1", "Type" : "MAXI", "Direction" : "IO",
				"BlockSignal" : [
					{"Name" : "conv1_blk_n_AR", "Type" : "RtlSignal"},
					{"Name" : "conv1_blk_n_R", "Type" : "RtlSignal"},
					{"Name" : "conv1_blk_n_AW", "Type" : "RtlSignal"},
					{"Name" : "conv1_blk_n_W", "Type" : "RtlSignal"},
					{"Name" : "conv1_blk_n_B", "Type" : "RtlSignal"}]},
			{"Name" : "conv1_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "conv2_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "conv3_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "fc1_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "fc2_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "fc3_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "lr_in_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "result", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "out_grad", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "second_relu_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_hidden_layer3", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "second_fc_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "first_relu_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_hidden_layer2", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "first_fc_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "flatten_conv_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_hidden_layer1", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "sencond_conv1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "29", "SubInstance" : "grp_Conv2d_b1_fu_1532", "Port" : "sencond_conv1"}]},
			{"Name" : "conv_kernel3", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "35", "SubInstance" : "grp_OverturnKernel_fu_1548", "Port" : "input_matrix"}]},
			{"Name" : "first_conv1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "32", "SubInstance" : "grp_Conv2d_b3_fu_1540", "Port" : "first_conv1"}]},
			{"Name" : "conv_kernel2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "35", "SubInstance" : "grp_OverturnKernel_fu_1548", "Port" : "input_matrix"}]},
			{"Name" : "mnist_data", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "26", "SubInstance" : "grp_Conv2d_b5_fu_1524", "Port" : "input_matrix"}]},
			{"Name" : "conv_kernel1", "Type" : "Memory", "Direction" : "IO"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.out_grad_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.rgrad_assign_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.second_rgrad_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.second_grad_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.rgrad_assign_1_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.first_rgrad_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.first_grad_U", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.first_wgrad_U", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.third_conv_grad1_U", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.third_kernel_grad_U", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.second_conv_grad1_U", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.third_kernel_overtur_U", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.third_conv_grad_padd_U", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.second_kernel_grad_U", "Parent" : "0"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.first_conv_grad_U", "Parent" : "0"},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.second_kernel_overtu_U", "Parent" : "0"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.second_conv_grad_pad_U", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.first_kernel_grad_U", "Parent" : "0"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_b4_fu_1510", "Parent" : "0", "Child" : ["20", "21"],
		"CDFG" : "Conv2d_b4",
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
	{"ID" : "20", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_b4_fu_1510.forw_back_fadd_32bkb_U72", "Parent" : "19"},
	{"ID" : "21", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_b4_fu_1510.forw_back_fmul_32cud_U73", "Parent" : "19"},
	{"ID" : "22", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_b2_fu_1517", "Parent" : "0", "Child" : ["23", "24", "25"],
		"CDFG" : "Conv2d_b2",
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
	{"ID" : "23", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_b2_fu_1517.forw_back_fadd_32bkb_U61", "Parent" : "22"},
	{"ID" : "24", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_b2_fu_1517.forw_back_fmul_32cud_U62", "Parent" : "22"},
	{"ID" : "25", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_b2_fu_1517.forw_back_mac_muldEe_U63", "Parent" : "22"},
	{"ID" : "26", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_b5_fu_1524", "Parent" : "0", "Child" : ["27", "28"],
		"CDFG" : "Conv2d_b5",
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
	{"ID" : "27", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_b5_fu_1524.forw_back_fadd_32bkb_U77", "Parent" : "26"},
	{"ID" : "28", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_b5_fu_1524.forw_back_fmul_32cud_U78", "Parent" : "26"},
	{"ID" : "29", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_b1_fu_1532", "Parent" : "0", "Child" : ["30", "31"],
		"CDFG" : "Conv2d_b1",
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
			{"Name" : "sencond_conv1", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "30", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_b1_fu_1532.forw_back_fadd_32bkb_U54", "Parent" : "29"},
	{"ID" : "31", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_b1_fu_1532.forw_back_fmul_32cud_U55", "Parent" : "29"},
	{"ID" : "32", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_b3_fu_1540", "Parent" : "0", "Child" : ["33", "34"],
		"CDFG" : "Conv2d_b3",
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
			{"Name" : "first_conv1", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "33", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_b3_fu_1540.forw_back_fadd_32bkb_U67", "Parent" : "32"},
	{"ID" : "34", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_b3_fu_1540.forw_back_fmul_32cud_U68", "Parent" : "32"},
	{"ID" : "35", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_OverturnKernel_fu_1548", "Parent" : "0",
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
	{"ID" : "36", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_faddfsuyd2_U82", "Parent" : "0"},
	{"ID" : "37", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fsub_32zec_U83", "Parent" : "0"},
	{"ID" : "38", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fsub_32zec_U84", "Parent" : "0"},
	{"ID" : "39", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fmul_32cud_U85", "Parent" : "0"},
	{"ID" : "40", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fmul_32cud_U86", "Parent" : "0"},
	{"ID" : "41", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fmul_32cud_U87", "Parent" : "0"},
	{"ID" : "42", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fptrunceOg_U88", "Parent" : "0"},
	{"ID" : "43", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fpext_3fYi_U89", "Parent" : "0"},
	{"ID" : "44", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fcmp_32g8j_U90", "Parent" : "0"},
	{"ID" : "45", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_dmul_64hbi_U91", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	backward {
		label_r {Type I LastRead 0 FirstWrite -1}
		conv1 {Type IO LastRead 62 FirstWrite 33}
		conv1_offset {Type I LastRead 4 FirstWrite -1}
		conv2_offset {Type I LastRead 4 FirstWrite -1}
		conv3_offset {Type I LastRead 4 FirstWrite -1}
		fc1_offset {Type I LastRead 4 FirstWrite -1}
		fc2_offset {Type I LastRead 4 FirstWrite -1}
		fc3_offset {Type I LastRead 4 FirstWrite -1}
		lr_in_offset {Type I LastRead 4 FirstWrite -1}
		result {Type I LastRead 5 FirstWrite -1}
		out_grad {Type IO LastRead -1 FirstWrite -1}
		second_relu_0 {Type I LastRead 6 FirstWrite -1}
		fc_hidden_layer3 {Type IO LastRead 61 FirstWrite 40}
		second_fc_0 {Type I LastRead 8 FirstWrite -1}
		first_relu_0 {Type I LastRead 9 FirstWrite -1}
		fc_hidden_layer2 {Type IO LastRead 55 FirstWrite 38}
		first_fc_0 {Type I LastRead 11 FirstWrite -1}
		flatten_conv_0 {Type I LastRead 12 FirstWrite -1}
		fc_hidden_layer1 {Type IO LastRead 49 FirstWrite 38}
		sencond_conv1 {Type I LastRead 4 FirstWrite -1}
		conv_kernel3 {Type IO LastRead 43 FirstWrite -1}
		first_conv1 {Type I LastRead 4 FirstWrite -1}
		conv_kernel2 {Type IO LastRead 37 FirstWrite -1}
		mnist_data {Type I LastRead 4 FirstWrite -1}
		conv_kernel1 {Type IO LastRead 32 FirstWrite 36}}
	Conv2d_b4 {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		kernel {Type I LastRead 2 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}}
	Conv2d_b2 {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		kernel {Type I LastRead 2 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}}
	Conv2d_b5 {
		input_matrix {Type I LastRead 4 FirstWrite -1}
		kernel {Type I LastRead 4 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}}
	Conv2d_b1 {
		kernel {Type I LastRead 4 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}
		sencond_conv1 {Type I LastRead 4 FirstWrite -1}}
	Conv2d_b3 {
		kernel {Type I LastRead 4 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}
		first_conv1 {Type I LastRead 4 FirstWrite -1}}
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
	{"Pipeline" : "3", "EnableSignal" : "ap_enable_pp3"}
	{"Pipeline" : "4", "EnableSignal" : "ap_enable_pp4"}
	{"Pipeline" : "5", "EnableSignal" : "ap_enable_pp5"}
]}

set Spec2ImplPortList { 
	label_r { ap_none {  { label_r in_data 0 32 } } }
	conv1 { m_axi {  { m_axi_conv1_AWVALID VALID 1 1 }  { m_axi_conv1_AWREADY READY 0 1 }  { m_axi_conv1_AWADDR ADDR 1 32 }  { m_axi_conv1_AWID ID 1 1 }  { m_axi_conv1_AWLEN LEN 1 32 }  { m_axi_conv1_AWSIZE SIZE 1 3 }  { m_axi_conv1_AWBURST BURST 1 2 }  { m_axi_conv1_AWLOCK LOCK 1 2 }  { m_axi_conv1_AWCACHE CACHE 1 4 }  { m_axi_conv1_AWPROT PROT 1 3 }  { m_axi_conv1_AWQOS QOS 1 4 }  { m_axi_conv1_AWREGION REGION 1 4 }  { m_axi_conv1_AWUSER USER 1 1 }  { m_axi_conv1_WVALID VALID 1 1 }  { m_axi_conv1_WREADY READY 0 1 }  { m_axi_conv1_WDATA DATA 1 32 }  { m_axi_conv1_WSTRB STRB 1 4 }  { m_axi_conv1_WLAST LAST 1 1 }  { m_axi_conv1_WID ID 1 1 }  { m_axi_conv1_WUSER USER 1 1 }  { m_axi_conv1_ARVALID VALID 1 1 }  { m_axi_conv1_ARREADY READY 0 1 }  { m_axi_conv1_ARADDR ADDR 1 32 }  { m_axi_conv1_ARID ID 1 1 }  { m_axi_conv1_ARLEN LEN 1 32 }  { m_axi_conv1_ARSIZE SIZE 1 3 }  { m_axi_conv1_ARBURST BURST 1 2 }  { m_axi_conv1_ARLOCK LOCK 1 2 }  { m_axi_conv1_ARCACHE CACHE 1 4 }  { m_axi_conv1_ARPROT PROT 1 3 }  { m_axi_conv1_ARQOS QOS 1 4 }  { m_axi_conv1_ARREGION REGION 1 4 }  { m_axi_conv1_ARUSER USER 1 1 }  { m_axi_conv1_RVALID VALID 0 1 }  { m_axi_conv1_RREADY READY 1 1 }  { m_axi_conv1_RDATA DATA 0 32 }  { m_axi_conv1_RLAST LAST 0 1 }  { m_axi_conv1_RID ID 0 1 }  { m_axi_conv1_RUSER USER 0 1 }  { m_axi_conv1_RRESP RESP 0 2 }  { m_axi_conv1_BVALID VALID 0 1 }  { m_axi_conv1_BREADY READY 1 1 }  { m_axi_conv1_BRESP RESP 0 2 }  { m_axi_conv1_BID ID 0 1 }  { m_axi_conv1_BUSER USER 0 1 } } }
	conv1_offset { ap_none {  { conv1_offset in_data 0 30 } } }
	conv2_offset { ap_none {  { conv2_offset in_data 0 30 } } }
	conv3_offset { ap_none {  { conv3_offset in_data 0 30 } } }
	fc1_offset { ap_none {  { fc1_offset in_data 0 30 } } }
	fc2_offset { ap_none {  { fc2_offset in_data 0 30 } } }
	fc3_offset { ap_none {  { fc3_offset in_data 0 30 } } }
	lr_in_offset { ap_none {  { lr_in_offset in_data 0 30 } } }
	result { ap_memory {  { result_address0 mem_address 1 4 }  { result_ce0 mem_ce 1 1 }  { result_q0 mem_dout 0 32 } } }
	second_relu_0 { ap_memory {  { second_relu_0_address0 mem_address 1 6 }  { second_relu_0_ce0 mem_ce 1 1 }  { second_relu_0_q0 mem_dout 0 32 } } }
	fc_hidden_layer3 { ap_memory {  { fc_hidden_layer3_address0 mem_address 1 9 }  { fc_hidden_layer3_ce0 mem_ce 1 1 }  { fc_hidden_layer3_we0 mem_we 1 1 }  { fc_hidden_layer3_d0 mem_din 1 32 }  { fc_hidden_layer3_q0 mem_dout 0 32 } } }
	second_fc_0 { ap_memory {  { second_fc_0_address0 mem_address 1 6 }  { second_fc_0_ce0 mem_ce 1 1 }  { second_fc_0_q0 mem_dout 0 32 } } }
	first_relu_0 { ap_memory {  { first_relu_0_address0 mem_address 1 8 }  { first_relu_0_ce0 mem_ce 1 1 }  { first_relu_0_q0 mem_dout 0 32 } } }
	fc_hidden_layer2 { ap_memory {  { fc_hidden_layer2_address0 mem_address 1 13 }  { fc_hidden_layer2_ce0 mem_ce 1 1 }  { fc_hidden_layer2_q0 mem_dout 0 32 }  { fc_hidden_layer2_address1 MemPortADDR2 1 13 }  { fc_hidden_layer2_ce1 MemPortCE2 1 1 }  { fc_hidden_layer2_we1 MemPortWE2 1 1 }  { fc_hidden_layer2_d1 MemPortDIN2 1 32 } } }
	first_fc_0 { ap_memory {  { first_fc_0_address0 mem_address 1 8 }  { first_fc_0_ce0 mem_ce 1 1 }  { first_fc_0_q0 mem_dout 0 32 } } }
	flatten_conv_0 { ap_memory {  { flatten_conv_0_address0 mem_address 1 10 }  { flatten_conv_0_ce0 mem_ce 1 1 }  { flatten_conv_0_q0 mem_dout 0 32 } } }
	fc_hidden_layer1 { ap_memory {  { fc_hidden_layer1_address0 mem_address 1 17 }  { fc_hidden_layer1_ce0 mem_ce 1 1 }  { fc_hidden_layer1_we0 mem_we 1 1 }  { fc_hidden_layer1_d0 mem_din 1 32 }  { fc_hidden_layer1_q0 mem_dout 0 32 } } }
	sencond_conv1 { ap_memory {  { sencond_conv1_address0 mem_address 1 10 }  { sencond_conv1_ce0 mem_ce 1 1 }  { sencond_conv1_q0 mem_dout 0 32 }  { sencond_conv1_address1 MemPortADDR2 1 10 }  { sencond_conv1_ce1 MemPortCE2 1 1 }  { sencond_conv1_q1 MemPortDOUT2 0 32 } } }
	conv_kernel3 { ap_memory {  { conv_kernel3_address0 mem_address 1 4 }  { conv_kernel3_ce0 mem_ce 1 1 }  { conv_kernel3_we0 mem_we 1 1 }  { conv_kernel3_d0 mem_din 1 32 }  { conv_kernel3_q0 mem_dout 0 32 } } }
	first_conv1 { ap_memory {  { first_conv1_address0 mem_address 1 10 }  { first_conv1_ce0 mem_ce 1 1 }  { first_conv1_q0 mem_dout 0 32 }  { first_conv1_address1 MemPortADDR2 1 10 }  { first_conv1_ce1 MemPortCE2 1 1 }  { first_conv1_q1 MemPortDOUT2 0 32 } } }
	conv_kernel2 { ap_memory {  { conv_kernel2_address0 mem_address 1 4 }  { conv_kernel2_ce0 mem_ce 1 1 }  { conv_kernel2_we0 mem_we 1 1 }  { conv_kernel2_d0 mem_din 1 32 }  { conv_kernel2_q0 mem_dout 0 32 } } }
	mnist_data { ap_memory {  { mnist_data_address0 mem_address 1 10 }  { mnist_data_ce0 mem_ce 1 1 }  { mnist_data_q0 mem_dout 0 32 }  { mnist_data_address1 MemPortADDR2 1 10 }  { mnist_data_ce1 MemPortCE2 1 1 }  { mnist_data_q1 MemPortDOUT2 0 32 } } }
	conv_kernel1 { ap_memory {  { conv_kernel1_address0 mem_address 1 4 }  { conv_kernel1_ce0 mem_ce 1 1 }  { conv_kernel1_we0 mem_we 1 1 }  { conv_kernel1_d0 mem_din 1 32 }  { conv_kernel1_q0 mem_dout 0 32 } } }
}
