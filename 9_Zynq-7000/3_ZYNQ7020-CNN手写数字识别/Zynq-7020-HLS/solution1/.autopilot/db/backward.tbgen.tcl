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
	{ fc_in_2_relu1_0 float 32 regular {array 20 { 1 3 } 1 1 } {global 0}  }
	{ fc_hidden_layer2 float 32 regular {array 200 { 2 3 } 1 1 } {global 2}  }
	{ fc_out_1_0 float 32 regular {array 20 { 1 3 } 1 1 } {global 0}  }
	{ fc_in_1_0 float 32 regular {array 36 { 1 3 } 1 1 } {global 0}  }
	{ fc_hidden_layer1 float 32 regular {array 720 { 2 3 } 1 1 } {global 2}  }
	{ max_poo_locate_2 float 32 regular {array 36 { 1 3 } 1 1 } {global 0}  }
	{ max_poo_out_1 float 32 regular {array 196 { 1 3 } 1 1 } {global 0}  }
	{ conv_kernel_2 float 32 regular {array 9 { 2 3 } 1 1 } {global 2}  }
	{ max_poo_locate_1 float 32 regular {array 196 { 1 3 } 1 1 } {global 0}  }
	{ mnist_data float 32 regular {array 900 { 1 3 } 1 1 } {global 0}  }
	{ conv_kernel_1 float 32 regular {array 9 { 2 3 } 1 1 } {global 2}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "label_r", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "lr_in", "interface" : "axi_master", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "lr_in_offset", "interface" : "wire", "bitwidth" : 30, "direction" : "READONLY"} , 
 	{ "Name" : "probability_result", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "fc_in_2_relu1_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "fc_hidden_layer2", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "fc_out_1_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "fc_in_1_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "fc_hidden_layer1", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "max_poo_locate_2", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "max_poo_out_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "conv_kernel_2", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "max_poo_locate_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "mnist_data", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "conv_kernel_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} ]}
# RTL Port declarations: 
set portNum 97
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
	{ fc_in_2_relu1_0_address0 sc_out sc_lv 5 signal 4 } 
	{ fc_in_2_relu1_0_ce0 sc_out sc_logic 1 signal 4 } 
	{ fc_in_2_relu1_0_q0 sc_in sc_lv 32 signal 4 } 
	{ fc_hidden_layer2_address0 sc_out sc_lv 8 signal 5 } 
	{ fc_hidden_layer2_ce0 sc_out sc_logic 1 signal 5 } 
	{ fc_hidden_layer2_we0 sc_out sc_logic 1 signal 5 } 
	{ fc_hidden_layer2_d0 sc_out sc_lv 32 signal 5 } 
	{ fc_hidden_layer2_q0 sc_in sc_lv 32 signal 5 } 
	{ fc_out_1_0_address0 sc_out sc_lv 5 signal 6 } 
	{ fc_out_1_0_ce0 sc_out sc_logic 1 signal 6 } 
	{ fc_out_1_0_q0 sc_in sc_lv 32 signal 6 } 
	{ fc_in_1_0_address0 sc_out sc_lv 6 signal 7 } 
	{ fc_in_1_0_ce0 sc_out sc_logic 1 signal 7 } 
	{ fc_in_1_0_q0 sc_in sc_lv 32 signal 7 } 
	{ fc_hidden_layer1_address0 sc_out sc_lv 10 signal 8 } 
	{ fc_hidden_layer1_ce0 sc_out sc_logic 1 signal 8 } 
	{ fc_hidden_layer1_we0 sc_out sc_logic 1 signal 8 } 
	{ fc_hidden_layer1_d0 sc_out sc_lv 32 signal 8 } 
	{ fc_hidden_layer1_q0 sc_in sc_lv 32 signal 8 } 
	{ max_poo_locate_2_address0 sc_out sc_lv 6 signal 9 } 
	{ max_poo_locate_2_ce0 sc_out sc_logic 1 signal 9 } 
	{ max_poo_locate_2_q0 sc_in sc_lv 32 signal 9 } 
	{ max_poo_out_1_address0 sc_out sc_lv 8 signal 10 } 
	{ max_poo_out_1_ce0 sc_out sc_logic 1 signal 10 } 
	{ max_poo_out_1_q0 sc_in sc_lv 32 signal 10 } 
	{ conv_kernel_2_address0 sc_out sc_lv 4 signal 11 } 
	{ conv_kernel_2_ce0 sc_out sc_logic 1 signal 11 } 
	{ conv_kernel_2_we0 sc_out sc_logic 1 signal 11 } 
	{ conv_kernel_2_d0 sc_out sc_lv 32 signal 11 } 
	{ conv_kernel_2_q0 sc_in sc_lv 32 signal 11 } 
	{ max_poo_locate_1_address0 sc_out sc_lv 8 signal 12 } 
	{ max_poo_locate_1_ce0 sc_out sc_logic 1 signal 12 } 
	{ max_poo_locate_1_q0 sc_in sc_lv 32 signal 12 } 
	{ mnist_data_address0 sc_out sc_lv 10 signal 13 } 
	{ mnist_data_ce0 sc_out sc_logic 1 signal 13 } 
	{ mnist_data_q0 sc_in sc_lv 32 signal 13 } 
	{ conv_kernel_1_address0 sc_out sc_lv 4 signal 14 } 
	{ conv_kernel_1_ce0 sc_out sc_logic 1 signal 14 } 
	{ conv_kernel_1_we0 sc_out sc_logic 1 signal 14 } 
	{ conv_kernel_1_d0 sc_out sc_lv 32 signal 14 } 
	{ conv_kernel_1_q0 sc_in sc_lv 32 signal 14 } 
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
 	{ "name": "fc_in_2_relu1_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "fc_in_2_relu1_0", "role": "address0" }} , 
 	{ "name": "fc_in_2_relu1_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_in_2_relu1_0", "role": "ce0" }} , 
 	{ "name": "fc_in_2_relu1_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_in_2_relu1_0", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "address0" }} , 
 	{ "name": "fc_hidden_layer2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "ce0" }} , 
 	{ "name": "fc_hidden_layer2_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "we0" }} , 
 	{ "name": "fc_hidden_layer2_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "d0" }} , 
 	{ "name": "fc_hidden_layer2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "q0" }} , 
 	{ "name": "fc_out_1_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "fc_out_1_0", "role": "address0" }} , 
 	{ "name": "fc_out_1_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_out_1_0", "role": "ce0" }} , 
 	{ "name": "fc_out_1_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_out_1_0", "role": "q0" }} , 
 	{ "name": "fc_in_1_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "address0" }} , 
 	{ "name": "fc_in_1_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "ce0" }} , 
 	{ "name": "fc_in_1_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "address0" }} , 
 	{ "name": "fc_hidden_layer1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "ce0" }} , 
 	{ "name": "fc_hidden_layer1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "we0" }} , 
 	{ "name": "fc_hidden_layer1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "d0" }} , 
 	{ "name": "fc_hidden_layer1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "q0" }} , 
 	{ "name": "max_poo_locate_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "max_poo_locate_2", "role": "address0" }} , 
 	{ "name": "max_poo_locate_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "max_poo_locate_2", "role": "ce0" }} , 
 	{ "name": "max_poo_locate_2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "max_poo_locate_2", "role": "q0" }} , 
 	{ "name": "max_poo_out_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "max_poo_out_1", "role": "address0" }} , 
 	{ "name": "max_poo_out_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "max_poo_out_1", "role": "ce0" }} , 
 	{ "name": "max_poo_out_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "max_poo_out_1", "role": "q0" }} , 
 	{ "name": "conv_kernel_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv_kernel_2", "role": "address0" }} , 
 	{ "name": "conv_kernel_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel_2", "role": "ce0" }} , 
 	{ "name": "conv_kernel_2_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel_2", "role": "we0" }} , 
 	{ "name": "conv_kernel_2_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel_2", "role": "d0" }} , 
 	{ "name": "conv_kernel_2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel_2", "role": "q0" }} , 
 	{ "name": "max_poo_locate_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "max_poo_locate_1", "role": "address0" }} , 
 	{ "name": "max_poo_locate_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "max_poo_locate_1", "role": "ce0" }} , 
 	{ "name": "max_poo_locate_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "max_poo_locate_1", "role": "q0" }} , 
 	{ "name": "mnist_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "mnist_data", "role": "address0" }} , 
 	{ "name": "mnist_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "mnist_data", "role": "ce0" }} , 
 	{ "name": "mnist_data_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "mnist_data", "role": "q0" }} , 
 	{ "name": "conv_kernel_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv_kernel_1", "role": "address0" }} , 
 	{ "name": "conv_kernel_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel_1", "role": "ce0" }} , 
 	{ "name": "conv_kernel_1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel_1", "role": "we0" }} , 
 	{ "name": "conv_kernel_1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel_1", "role": "d0" }} , 
 	{ "name": "conv_kernel_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel_1", "role": "q0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "17", "20", "23", "26", "27", "28", "29", "30", "31", "32", "33", "34"],
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
			{"State" : "ap_ST_fsm_state77", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_1_fu_685"},
			{"State" : "ap_ST_fsm_state81", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_fu_692"},
			{"State" : "ap_ST_fsm_state66", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_2_fu_700"},
			{"State" : "ap_ST_fsm_state81", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MatrixBackPropagatio_fu_708"},
			{"State" : "ap_ST_fsm_state83", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MatrixBackPropagatio_fu_708"},
			{"State" : "ap_ST_fsm_state79", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MaxPooBackPropagatio_1_fu_717"},
			{"State" : "ap_ST_fsm_state64", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MaxPooBackPropagatio_fu_725"},
			{"State" : "ap_ST_fsm_state68", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Padding_fu_733"}],
		"Port" : [
			{"Name" : "label_r", "Type" : "None", "Direction" : "I"},
			{"Name" : "lr_in", "Type" : "MAXI", "Direction" : "I",
				"BlockSignal" : [
					{"Name" : "lr_in_blk_n_AR", "Type" : "RtlSignal"},
					{"Name" : "lr_in_blk_n_R", "Type" : "RtlSignal"}]},
			{"Name" : "lr_in_offset", "Type" : "None", "Direction" : "I"},
			{"Name" : "probability_result", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_in_2_relu1_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_hidden_layer2", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_out_1_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_in_1_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_hidden_layer1", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "max_poo_locate_2", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "27", "SubInstance" : "grp_MaxPooBackPropagatio_fu_725", "Port" : "max_poo_locate_2"}]},
			{"Name" : "max_poo_out_1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "20", "SubInstance" : "grp_Conv2d_2_fu_700", "Port" : "max_poo_out_1"}]},
			{"Name" : "conv_kernel_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "23", "SubInstance" : "grp_MatrixBackPropagatio_fu_708", "Port" : "output_matrix"}]},
			{"Name" : "max_poo_locate_1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "26", "SubInstance" : "grp_MaxPooBackPropagatio_1_fu_717", "Port" : "max_poo_locate_1"}]},
			{"Name" : "mnist_data", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "17", "SubInstance" : "grp_Conv2d_fu_692", "Port" : "input_matrix"}]},
			{"Name" : "conv_kernel_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "23", "SubInstance" : "grp_MatrixBackPropagatio_fu_708", "Port" : "output_matrix"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grad_2_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.wgrad_2_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.rgrad_1_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grad_1_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.wgrad_1_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grad_0_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.conv_grad_2_U", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.kernel_grad_2_U", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.conv_grad_2_padding_U", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.kernel_grad_2_overtu_U", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.pool_grad_1_U", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.conv_grad_1_U", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.kernel_grad_1_U", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_1_fu_685", "Parent" : "0", "Child" : ["15", "16"],
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
	{"ID" : "15", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_1_fu_685.forw_back_fadd_32bkb_U66", "Parent" : "14"},
	{"ID" : "16", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_1_fu_685.forw_back_fmul_32cud_U67", "Parent" : "14"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_fu_692", "Parent" : "0", "Child" : ["18", "19"],
		"CDFG" : "Conv2d",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1051", "EstimateLatencyMax" : "1051",
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
	{"ID" : "18", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_fu_692.forw_back_fadd_32bkb_U74", "Parent" : "17"},
	{"ID" : "19", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_fu_692.forw_back_fmul_32cud_U75", "Parent" : "17"},
	{"ID" : "20", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_2_fu_700", "Parent" : "0", "Child" : ["21", "22"],
		"CDFG" : "Conv2d_2",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1051", "EstimateLatencyMax" : "1051",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "kernel", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "out_matrix", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "max_poo_out_1", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "21", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_2_fu_700.forw_back_fadd_32bkb_U59", "Parent" : "20"},
	{"ID" : "22", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_2_fu_700.forw_back_fmul_32cud_U60", "Parent" : "20"},
	{"ID" : "23", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_MatrixBackPropagatio_fu_708", "Parent" : "0", "Child" : ["24", "25"],
		"CDFG" : "MatrixBackPropagatio",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "106", "EstimateLatencyMax" : "106",
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
	{"ID" : "24", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_MatrixBackPropagatio_fu_708.forw_back_fsub_32mb6_U79", "Parent" : "23"},
	{"ID" : "25", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_MatrixBackPropagatio_fu_708.forw_back_fmul_32cud_U80", "Parent" : "23"},
	{"ID" : "26", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_MaxPooBackPropagatio_1_fu_717", "Parent" : "0",
		"CDFG" : "MaxPooBackPropagatio_1",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1654", "EstimateLatencyMax" : "1654",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_matrix", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "output_matrix", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "max_poo_locate_1", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "27", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_MaxPooBackPropagatio_fu_725", "Parent" : "0",
		"CDFG" : "MaxPooBackPropagatio",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "326", "EstimateLatencyMax" : "326",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_matrix", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "output_matrix", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "max_poo_locate_2", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "28", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Padding_fu_733", "Parent" : "0",
		"CDFG" : "Padding",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "545", "EstimateLatencyMax" : "545",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "input_matrix", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "output_matrix", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "29", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_faddfsuudo_U85", "Parent" : "0"},
	{"ID" : "30", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fmul_32cud_U86", "Parent" : "0"},
	{"ID" : "31", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fptruncg8j_U87", "Parent" : "0"},
	{"ID" : "32", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fpext_3hbi_U88", "Parent" : "0"},
	{"ID" : "33", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fcmp_32eOg_U89", "Parent" : "0"},
	{"ID" : "34", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_dmul_64jbC_U90", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	backward {
		label_r {Type I LastRead 0 FirstWrite -1}
		lr_in {Type I LastRead 30 FirstWrite -1}
		lr_in_offset {Type I LastRead 6 FirstWrite -1}
		probability_result {Type I LastRead 7 FirstWrite -1}
		fc_in_2_relu1_0 {Type I LastRead 8 FirstWrite -1}
		fc_hidden_layer2 {Type IO LastRead 37 FirstWrite 44}
		fc_out_1_0 {Type I LastRead 10 FirstWrite -1}
		fc_in_1_0 {Type I LastRead 11 FirstWrite -1}
		fc_hidden_layer1 {Type IO LastRead 36 FirstWrite 43}
		max_poo_locate_2 {Type I LastRead 3 FirstWrite -1}
		max_poo_out_1 {Type I LastRead 4 FirstWrite -1}
		conv_kernel_2 {Type IO LastRead 19 FirstWrite 12}
		max_poo_locate_1 {Type I LastRead 3 FirstWrite -1}
		mnist_data {Type I LastRead 4 FirstWrite -1}
		conv_kernel_1 {Type IO LastRead 5 FirstWrite 12}}
	Conv2d_1 {
		input_matrix {Type I LastRead 4 FirstWrite -1}
		kernel {Type I LastRead 5 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 2}}
	Conv2d {
		input_matrix {Type I LastRead 4 FirstWrite -1}
		kernel {Type I LastRead 4 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 2}}
	Conv2d_2 {
		kernel {Type I LastRead 4 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 2}
		max_poo_out_1 {Type I LastRead 4 FirstWrite -1}}
	MatrixBackPropagatio {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		output_matrix {Type IO LastRead 5 FirstWrite 12}
		lr {Type I LastRead 0 FirstWrite -1}}
	MaxPooBackPropagatio_1 {
		input_matrix {Type I LastRead 3 FirstWrite -1}
		output_matrix {Type O LastRead -1 FirstWrite 2}
		max_poo_locate_1 {Type I LastRead 3 FirstWrite -1}}
	MaxPooBackPropagatio {
		input_matrix {Type I LastRead 3 FirstWrite -1}
		output_matrix {Type O LastRead -1 FirstWrite 2}
		max_poo_locate_2 {Type I LastRead 3 FirstWrite -1}}
	Padding {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		output_matrix {Type O LastRead -1 FirstWrite 2}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "-1", "Max" : "-1"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	label_r { ap_none {  { label_r in_data 0 32 } } }
	lr_in { m_axi {  { m_axi_lr_in_AWVALID VALID 1 1 }  { m_axi_lr_in_AWREADY READY 0 1 }  { m_axi_lr_in_AWADDR ADDR 1 32 }  { m_axi_lr_in_AWID ID 1 1 }  { m_axi_lr_in_AWLEN LEN 1 32 }  { m_axi_lr_in_AWSIZE SIZE 1 3 }  { m_axi_lr_in_AWBURST BURST 1 2 }  { m_axi_lr_in_AWLOCK LOCK 1 2 }  { m_axi_lr_in_AWCACHE CACHE 1 4 }  { m_axi_lr_in_AWPROT PROT 1 3 }  { m_axi_lr_in_AWQOS QOS 1 4 }  { m_axi_lr_in_AWREGION REGION 1 4 }  { m_axi_lr_in_AWUSER USER 1 1 }  { m_axi_lr_in_WVALID VALID 1 1 }  { m_axi_lr_in_WREADY READY 0 1 }  { m_axi_lr_in_WDATA DATA 1 32 }  { m_axi_lr_in_WSTRB STRB 1 4 }  { m_axi_lr_in_WLAST LAST 1 1 }  { m_axi_lr_in_WID ID 1 1 }  { m_axi_lr_in_WUSER USER 1 1 }  { m_axi_lr_in_ARVALID VALID 1 1 }  { m_axi_lr_in_ARREADY READY 0 1 }  { m_axi_lr_in_ARADDR ADDR 1 32 }  { m_axi_lr_in_ARID ID 1 1 }  { m_axi_lr_in_ARLEN LEN 1 32 }  { m_axi_lr_in_ARSIZE SIZE 1 3 }  { m_axi_lr_in_ARBURST BURST 1 2 }  { m_axi_lr_in_ARLOCK LOCK 1 2 }  { m_axi_lr_in_ARCACHE CACHE 1 4 }  { m_axi_lr_in_ARPROT PROT 1 3 }  { m_axi_lr_in_ARQOS QOS 1 4 }  { m_axi_lr_in_ARREGION REGION 1 4 }  { m_axi_lr_in_ARUSER USER 1 1 }  { m_axi_lr_in_RVALID VALID 0 1 }  { m_axi_lr_in_RREADY READY 1 1 }  { m_axi_lr_in_RDATA DATA 0 32 }  { m_axi_lr_in_RLAST LAST 0 1 }  { m_axi_lr_in_RID ID 0 1 }  { m_axi_lr_in_RUSER USER 0 1 }  { m_axi_lr_in_RRESP RESP 0 2 }  { m_axi_lr_in_BVALID VALID 0 1 }  { m_axi_lr_in_BREADY READY 1 1 }  { m_axi_lr_in_BRESP RESP 0 2 }  { m_axi_lr_in_BID ID 0 1 }  { m_axi_lr_in_BUSER USER 0 1 } } }
	lr_in_offset { ap_none {  { lr_in_offset in_data 0 30 } } }
	probability_result { ap_memory {  { probability_result_address0 mem_address 1 4 }  { probability_result_ce0 mem_ce 1 1 }  { probability_result_q0 mem_dout 0 32 } } }
	fc_in_2_relu1_0 { ap_memory {  { fc_in_2_relu1_0_address0 mem_address 1 5 }  { fc_in_2_relu1_0_ce0 mem_ce 1 1 }  { fc_in_2_relu1_0_q0 mem_dout 0 32 } } }
	fc_hidden_layer2 { ap_memory {  { fc_hidden_layer2_address0 mem_address 1 8 }  { fc_hidden_layer2_ce0 mem_ce 1 1 }  { fc_hidden_layer2_we0 mem_we 1 1 }  { fc_hidden_layer2_d0 mem_din 1 32 }  { fc_hidden_layer2_q0 mem_dout 0 32 } } }
	fc_out_1_0 { ap_memory {  { fc_out_1_0_address0 mem_address 1 5 }  { fc_out_1_0_ce0 mem_ce 1 1 }  { fc_out_1_0_q0 mem_dout 0 32 } } }
	fc_in_1_0 { ap_memory {  { fc_in_1_0_address0 mem_address 1 6 }  { fc_in_1_0_ce0 mem_ce 1 1 }  { fc_in_1_0_q0 mem_dout 0 32 } } }
	fc_hidden_layer1 { ap_memory {  { fc_hidden_layer1_address0 mem_address 1 10 }  { fc_hidden_layer1_ce0 mem_ce 1 1 }  { fc_hidden_layer1_we0 mem_we 1 1 }  { fc_hidden_layer1_d0 mem_din 1 32 }  { fc_hidden_layer1_q0 mem_dout 0 32 } } }
	max_poo_locate_2 { ap_memory {  { max_poo_locate_2_address0 mem_address 1 6 }  { max_poo_locate_2_ce0 mem_ce 1 1 }  { max_poo_locate_2_q0 mem_dout 0 32 } } }
	max_poo_out_1 { ap_memory {  { max_poo_out_1_address0 mem_address 1 8 }  { max_poo_out_1_ce0 mem_ce 1 1 }  { max_poo_out_1_q0 mem_dout 0 32 } } }
	conv_kernel_2 { ap_memory {  { conv_kernel_2_address0 mem_address 1 4 }  { conv_kernel_2_ce0 mem_ce 1 1 }  { conv_kernel_2_we0 mem_we 1 1 }  { conv_kernel_2_d0 mem_din 1 32 }  { conv_kernel_2_q0 mem_dout 0 32 } } }
	max_poo_locate_1 { ap_memory {  { max_poo_locate_1_address0 mem_address 1 8 }  { max_poo_locate_1_ce0 mem_ce 1 1 }  { max_poo_locate_1_q0 mem_dout 0 32 } } }
	mnist_data { ap_memory {  { mnist_data_address0 mem_address 1 10 }  { mnist_data_ce0 mem_ce 1 1 }  { mnist_data_q0 mem_dout 0 32 } } }
	conv_kernel_1 { ap_memory {  { conv_kernel_1_address0 mem_address 1 4 }  { conv_kernel_1_ce0 mem_ce 1 1 }  { conv_kernel_1_we0 mem_we 1 1 }  { conv_kernel_1_d0 mem_din 1 32 }  { conv_kernel_1_q0 mem_dout 0 32 } } }
}
