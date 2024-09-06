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
	{ mnist_data float 32 regular {array 900 { 1 3 } 1 1 } {global 0}  }
	{ conv_kernel_1 float 32 regular {array 9 { 1 3 } 1 1 } {global 0}  }
	{ conv_out_1 float 32 regular {array 784 { 2 3 } 1 1 } {global 2}  }
	{ conv_kernel_2 float 32 regular {array 9 { 1 3 } 1 1 } {global 0}  }
	{ conv_out_2 float 32 regular {array 676 { 2 3 } 1 1 } {global 2}  }
	{ conv_kernel_3 float 32 regular {array 9 { 1 3 } 1 1 } {global 0}  }
	{ fc_in_1_0 float 32 regular {array 576 { 2 3 } 1 1 } {global 2}  }
	{ fc_out_1_0 float 32 regular {array 180 { 2 3 } 1 1 } {global 2}  }
	{ fc_hidden_layer1 float 32 regular {array 103680 { 1 3 } 1 1 } {global 0}  }
	{ fc_in_2_relu1_0 float 32 regular {array 180 { 2 3 } 1 1 } {global 2}  }
	{ fc_out_2_0 float 32 regular {array 45 { 2 3 } 1 1 } {global 2}  }
	{ fc_hidden_layer2 float 32 regular {array 8100 { 1 3 } 1 1 } {global 0}  }
	{ fc_in_3_relu2_0 float 32 regular {array 45 { 2 3 } 1 1 } {global 2}  }
	{ fc_hidden_layer3 float 32 regular {array 450 { 1 3 } 1 1 } {global 0}  }
	{ probability_result float 32 regular {array 10 { 0 3 } 0 1 } {global 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "mnist_data", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "conv_kernel_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "conv_out_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "conv_kernel_2", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "conv_out_2", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "conv_kernel_3", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "fc_in_1_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "fc_out_1_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "fc_hidden_layer1", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "fc_in_2_relu1_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "fc_out_2_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "fc_hidden_layer2", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "fc_in_3_relu2_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "fc_hidden_layer3", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "probability_result", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY", "extern" : 0} ]}
# RTL Port declarations: 
set portNum 66
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ mnist_data_address0 sc_out sc_lv 10 signal 0 } 
	{ mnist_data_ce0 sc_out sc_logic 1 signal 0 } 
	{ mnist_data_q0 sc_in sc_lv 32 signal 0 } 
	{ conv_kernel_1_address0 sc_out sc_lv 4 signal 1 } 
	{ conv_kernel_1_ce0 sc_out sc_logic 1 signal 1 } 
	{ conv_kernel_1_q0 sc_in sc_lv 32 signal 1 } 
	{ conv_out_1_address0 sc_out sc_lv 10 signal 2 } 
	{ conv_out_1_ce0 sc_out sc_logic 1 signal 2 } 
	{ conv_out_1_we0 sc_out sc_logic 1 signal 2 } 
	{ conv_out_1_d0 sc_out sc_lv 32 signal 2 } 
	{ conv_out_1_q0 sc_in sc_lv 32 signal 2 } 
	{ conv_kernel_2_address0 sc_out sc_lv 4 signal 3 } 
	{ conv_kernel_2_ce0 sc_out sc_logic 1 signal 3 } 
	{ conv_kernel_2_q0 sc_in sc_lv 32 signal 3 } 
	{ conv_out_2_address0 sc_out sc_lv 10 signal 4 } 
	{ conv_out_2_ce0 sc_out sc_logic 1 signal 4 } 
	{ conv_out_2_we0 sc_out sc_logic 1 signal 4 } 
	{ conv_out_2_d0 sc_out sc_lv 32 signal 4 } 
	{ conv_out_2_q0 sc_in sc_lv 32 signal 4 } 
	{ conv_kernel_3_address0 sc_out sc_lv 4 signal 5 } 
	{ conv_kernel_3_ce0 sc_out sc_logic 1 signal 5 } 
	{ conv_kernel_3_q0 sc_in sc_lv 32 signal 5 } 
	{ fc_in_1_0_address0 sc_out sc_lv 10 signal 6 } 
	{ fc_in_1_0_ce0 sc_out sc_logic 1 signal 6 } 
	{ fc_in_1_0_we0 sc_out sc_logic 1 signal 6 } 
	{ fc_in_1_0_d0 sc_out sc_lv 32 signal 6 } 
	{ fc_in_1_0_q0 sc_in sc_lv 32 signal 6 } 
	{ fc_out_1_0_address0 sc_out sc_lv 8 signal 7 } 
	{ fc_out_1_0_ce0 sc_out sc_logic 1 signal 7 } 
	{ fc_out_1_0_we0 sc_out sc_logic 1 signal 7 } 
	{ fc_out_1_0_d0 sc_out sc_lv 32 signal 7 } 
	{ fc_out_1_0_q0 sc_in sc_lv 32 signal 7 } 
	{ fc_hidden_layer1_address0 sc_out sc_lv 17 signal 8 } 
	{ fc_hidden_layer1_ce0 sc_out sc_logic 1 signal 8 } 
	{ fc_hidden_layer1_q0 sc_in sc_lv 32 signal 8 } 
	{ fc_in_2_relu1_0_address0 sc_out sc_lv 8 signal 9 } 
	{ fc_in_2_relu1_0_ce0 sc_out sc_logic 1 signal 9 } 
	{ fc_in_2_relu1_0_we0 sc_out sc_logic 1 signal 9 } 
	{ fc_in_2_relu1_0_d0 sc_out sc_lv 32 signal 9 } 
	{ fc_in_2_relu1_0_q0 sc_in sc_lv 32 signal 9 } 
	{ fc_out_2_0_address0 sc_out sc_lv 6 signal 10 } 
	{ fc_out_2_0_ce0 sc_out sc_logic 1 signal 10 } 
	{ fc_out_2_0_we0 sc_out sc_logic 1 signal 10 } 
	{ fc_out_2_0_d0 sc_out sc_lv 32 signal 10 } 
	{ fc_out_2_0_q0 sc_in sc_lv 32 signal 10 } 
	{ fc_hidden_layer2_address0 sc_out sc_lv 13 signal 11 } 
	{ fc_hidden_layer2_ce0 sc_out sc_logic 1 signal 11 } 
	{ fc_hidden_layer2_q0 sc_in sc_lv 32 signal 11 } 
	{ fc_in_3_relu2_0_address0 sc_out sc_lv 6 signal 12 } 
	{ fc_in_3_relu2_0_ce0 sc_out sc_logic 1 signal 12 } 
	{ fc_in_3_relu2_0_we0 sc_out sc_logic 1 signal 12 } 
	{ fc_in_3_relu2_0_d0 sc_out sc_lv 32 signal 12 } 
	{ fc_in_3_relu2_0_q0 sc_in sc_lv 32 signal 12 } 
	{ fc_hidden_layer3_address0 sc_out sc_lv 9 signal 13 } 
	{ fc_hidden_layer3_ce0 sc_out sc_logic 1 signal 13 } 
	{ fc_hidden_layer3_q0 sc_in sc_lv 32 signal 13 } 
	{ probability_result_address0 sc_out sc_lv 4 signal 14 } 
	{ probability_result_ce0 sc_out sc_logic 1 signal 14 } 
	{ probability_result_we0 sc_out sc_logic 1 signal 14 } 
	{ probability_result_d0 sc_out sc_lv 32 signal 14 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "mnist_data_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "mnist_data", "role": "address0" }} , 
 	{ "name": "mnist_data_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "mnist_data", "role": "ce0" }} , 
 	{ "name": "mnist_data_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "mnist_data", "role": "q0" }} , 
 	{ "name": "conv_kernel_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv_kernel_1", "role": "address0" }} , 
 	{ "name": "conv_kernel_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel_1", "role": "ce0" }} , 
 	{ "name": "conv_kernel_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel_1", "role": "q0" }} , 
 	{ "name": "conv_out_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "conv_out_1", "role": "address0" }} , 
 	{ "name": "conv_out_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_out_1", "role": "ce0" }} , 
 	{ "name": "conv_out_1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_out_1", "role": "we0" }} , 
 	{ "name": "conv_out_1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_out_1", "role": "d0" }} , 
 	{ "name": "conv_out_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_out_1", "role": "q0" }} , 
 	{ "name": "conv_kernel_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv_kernel_2", "role": "address0" }} , 
 	{ "name": "conv_kernel_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel_2", "role": "ce0" }} , 
 	{ "name": "conv_kernel_2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel_2", "role": "q0" }} , 
 	{ "name": "conv_out_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "conv_out_2", "role": "address0" }} , 
 	{ "name": "conv_out_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_out_2", "role": "ce0" }} , 
 	{ "name": "conv_out_2_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_out_2", "role": "we0" }} , 
 	{ "name": "conv_out_2_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_out_2", "role": "d0" }} , 
 	{ "name": "conv_out_2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_out_2", "role": "q0" }} , 
 	{ "name": "conv_kernel_3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv_kernel_3", "role": "address0" }} , 
 	{ "name": "conv_kernel_3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel_3", "role": "ce0" }} , 
 	{ "name": "conv_kernel_3_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel_3", "role": "q0" }} , 
 	{ "name": "fc_in_1_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "address0" }} , 
 	{ "name": "fc_in_1_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "ce0" }} , 
 	{ "name": "fc_in_1_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "we0" }} , 
 	{ "name": "fc_in_1_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "d0" }} , 
 	{ "name": "fc_in_1_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "q0" }} , 
 	{ "name": "fc_out_1_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "fc_out_1_0", "role": "address0" }} , 
 	{ "name": "fc_out_1_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_out_1_0", "role": "ce0" }} , 
 	{ "name": "fc_out_1_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_out_1_0", "role": "we0" }} , 
 	{ "name": "fc_out_1_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_out_1_0", "role": "d0" }} , 
 	{ "name": "fc_out_1_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_out_1_0", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":17, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "address0" }} , 
 	{ "name": "fc_hidden_layer1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "ce0" }} , 
 	{ "name": "fc_hidden_layer1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "q0" }} , 
 	{ "name": "fc_in_2_relu1_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "fc_in_2_relu1_0", "role": "address0" }} , 
 	{ "name": "fc_in_2_relu1_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_in_2_relu1_0", "role": "ce0" }} , 
 	{ "name": "fc_in_2_relu1_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_in_2_relu1_0", "role": "we0" }} , 
 	{ "name": "fc_in_2_relu1_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_in_2_relu1_0", "role": "d0" }} , 
 	{ "name": "fc_in_2_relu1_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_in_2_relu1_0", "role": "q0" }} , 
 	{ "name": "fc_out_2_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "fc_out_2_0", "role": "address0" }} , 
 	{ "name": "fc_out_2_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_out_2_0", "role": "ce0" }} , 
 	{ "name": "fc_out_2_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_out_2_0", "role": "we0" }} , 
 	{ "name": "fc_out_2_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_out_2_0", "role": "d0" }} , 
 	{ "name": "fc_out_2_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_out_2_0", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":13, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "address0" }} , 
 	{ "name": "fc_hidden_layer2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "ce0" }} , 
 	{ "name": "fc_hidden_layer2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "q0" }} , 
 	{ "name": "fc_in_3_relu2_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "fc_in_3_relu2_0", "role": "address0" }} , 
 	{ "name": "fc_in_3_relu2_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_in_3_relu2_0", "role": "ce0" }} , 
 	{ "name": "fc_in_3_relu2_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_in_3_relu2_0", "role": "we0" }} , 
 	{ "name": "fc_in_3_relu2_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_in_3_relu2_0", "role": "d0" }} , 
 	{ "name": "fc_in_3_relu2_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_in_3_relu2_0", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "address0" }} , 
 	{ "name": "fc_hidden_layer3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "ce0" }} , 
 	{ "name": "fc_hidden_layer3_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer3", "role": "q0" }} , 
 	{ "name": "probability_result_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "probability_result", "role": "address0" }} , 
 	{ "name": "probability_result_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "probability_result", "role": "ce0" }} , 
 	{ "name": "probability_result_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "probability_result", "role": "we0" }} , 
 	{ "name": "probability_result_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "probability_result", "role": "d0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "6", "10", "13", "14", "15", "16", "17", "18", "19", "20", "21"],
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
			{"State" : "ap_ST_fsm_state2", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_7_fu_530"},
			{"State" : "ap_ST_fsm_state4", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_6_fu_540"},
			{"State" : "ap_ST_fsm_state6", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_5_fu_550"}],
		"Port" : [
			{"Name" : "mnist_data", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "3", "SubInstance" : "grp_Conv2d_7_fu_530", "Port" : "input_matrix"}]},
			{"Name" : "conv_kernel_1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "3", "SubInstance" : "grp_Conv2d_7_fu_530", "Port" : "kernel"}]},
			{"Name" : "conv_out_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "6", "SubInstance" : "grp_Conv2d_6_fu_540", "Port" : "input_matrix"},
					{"ID" : "3", "SubInstance" : "grp_Conv2d_7_fu_530", "Port" : "out_matrix"}]},
			{"Name" : "conv_kernel_2", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "6", "SubInstance" : "grp_Conv2d_6_fu_540", "Port" : "kernel"}]},
			{"Name" : "conv_out_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "6", "SubInstance" : "grp_Conv2d_6_fu_540", "Port" : "out_matrix"},
					{"ID" : "10", "SubInstance" : "grp_Conv2d_5_fu_550", "Port" : "input_matrix"}]},
			{"Name" : "conv_kernel_3", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "grp_Conv2d_5_fu_550", "Port" : "kernel"}]},
			{"Name" : "conv_out_3", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "10", "SubInstance" : "grp_Conv2d_5_fu_550", "Port" : "out_matrix"}]},
			{"Name" : "fc_in_1_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_out_1_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_hidden_layer1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_in_2_relu1_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_out_2_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_hidden_layer2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_in_3_relu2_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_out_3_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_hidden_layer3", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "probability_result", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.conv_out_3_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_out_3_0_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_7_fu_530", "Parent" : "0", "Child" : ["4", "5"],
		"CDFG" : "Conv2d_7",
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
	{"ID" : "4", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_7_fu_530.forw_back_fadd_32bkb_U1", "Parent" : "3"},
	{"ID" : "5", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_7_fu_530.forw_back_fmul_32cud_U2", "Parent" : "3"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_6_fu_540", "Parent" : "0", "Child" : ["7", "8", "9"],
		"CDFG" : "Conv2d_6",
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
	{"ID" : "7", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_6_fu_540.forw_back_fadd_32bkb_U8", "Parent" : "6"},
	{"ID" : "8", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_6_fu_540.forw_back_fmul_32cud_U9", "Parent" : "6"},
	{"ID" : "9", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_6_fu_540.forw_back_mac_muldEe_U10", "Parent" : "6"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_5_fu_550", "Parent" : "0", "Child" : ["11", "12"],
		"CDFG" : "Conv2d_5",
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
	{"ID" : "11", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_5_fu_550.forw_back_fadd_32bkb_U15", "Parent" : "10"},
	{"ID" : "12", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_5_fu_550.forw_back_fmul_32cud_U16", "Parent" : "10"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fadd_32bkb_U20", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fmul_32cud_U21", "Parent" : "0"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fptrunceOg_U22", "Parent" : "0"},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fpext_3fYi_U23", "Parent" : "0"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fcmp_32g8j_U24", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_dadd_64hbi_U25", "Parent" : "0"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_dmul_64ibs_U26", "Parent" : "0"},
	{"ID" : "20", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_ddiv_64jbC_U27", "Parent" : "0"},
	{"ID" : "21", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_dexp_64kbM_U28", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	forward {
		mnist_data {Type I LastRead 2 FirstWrite -1}
		conv_kernel_1 {Type I LastRead 2 FirstWrite -1}
		conv_out_1 {Type IO LastRead 2 FirstWrite -1}
		conv_kernel_2 {Type I LastRead 2 FirstWrite -1}
		conv_out_2 {Type IO LastRead 2 FirstWrite -1}
		conv_kernel_3 {Type I LastRead 2 FirstWrite -1}
		conv_out_3 {Type IO LastRead -1 FirstWrite -1}
		fc_in_1_0 {Type IO LastRead 8 FirstWrite 8}
		fc_out_1_0 {Type IO LastRead 8 FirstWrite 8}
		fc_hidden_layer1 {Type I LastRead 8 FirstWrite -1}
		fc_in_2_relu1_0 {Type IO LastRead 10 FirstWrite 18}
		fc_out_2_0 {Type IO LastRead 10 FirstWrite 10}
		fc_hidden_layer2 {Type I LastRead 10 FirstWrite -1}
		fc_in_3_relu2_0 {Type IO LastRead 12 FirstWrite 20}
		fc_out_3_0 {Type IO LastRead -1 FirstWrite -1}
		fc_hidden_layer3 {Type I LastRead 12 FirstWrite -1}
		probability_result {Type O LastRead -1 FirstWrite 53}}
	Conv2d_7 {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		kernel {Type I LastRead 2 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}}
	Conv2d_6 {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		kernel {Type I LastRead 2 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}}
	Conv2d_5 {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		kernel {Type I LastRead 2 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "-1", "Max" : "-1"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	mnist_data { ap_memory {  { mnist_data_address0 mem_address 1 10 }  { mnist_data_ce0 mem_ce 1 1 }  { mnist_data_q0 mem_dout 0 32 } } }
	conv_kernel_1 { ap_memory {  { conv_kernel_1_address0 mem_address 1 4 }  { conv_kernel_1_ce0 mem_ce 1 1 }  { conv_kernel_1_q0 mem_dout 0 32 } } }
	conv_out_1 { ap_memory {  { conv_out_1_address0 mem_address 1 10 }  { conv_out_1_ce0 mem_ce 1 1 }  { conv_out_1_we0 mem_we 1 1 }  { conv_out_1_d0 mem_din 1 32 }  { conv_out_1_q0 mem_dout 0 32 } } }
	conv_kernel_2 { ap_memory {  { conv_kernel_2_address0 mem_address 1 4 }  { conv_kernel_2_ce0 mem_ce 1 1 }  { conv_kernel_2_q0 mem_dout 0 32 } } }
	conv_out_2 { ap_memory {  { conv_out_2_address0 mem_address 1 10 }  { conv_out_2_ce0 mem_ce 1 1 }  { conv_out_2_we0 mem_we 1 1 }  { conv_out_2_d0 mem_din 1 32 }  { conv_out_2_q0 mem_dout 0 32 } } }
	conv_kernel_3 { ap_memory {  { conv_kernel_3_address0 mem_address 1 4 }  { conv_kernel_3_ce0 mem_ce 1 1 }  { conv_kernel_3_q0 mem_dout 0 32 } } }
	fc_in_1_0 { ap_memory {  { fc_in_1_0_address0 mem_address 1 10 }  { fc_in_1_0_ce0 mem_ce 1 1 }  { fc_in_1_0_we0 mem_we 1 1 }  { fc_in_1_0_d0 mem_din 1 32 }  { fc_in_1_0_q0 mem_dout 0 32 } } }
	fc_out_1_0 { ap_memory {  { fc_out_1_0_address0 mem_address 1 8 }  { fc_out_1_0_ce0 mem_ce 1 1 }  { fc_out_1_0_we0 mem_we 1 1 }  { fc_out_1_0_d0 mem_din 1 32 }  { fc_out_1_0_q0 mem_dout 0 32 } } }
	fc_hidden_layer1 { ap_memory {  { fc_hidden_layer1_address0 mem_address 1 17 }  { fc_hidden_layer1_ce0 mem_ce 1 1 }  { fc_hidden_layer1_q0 mem_dout 0 32 } } }
	fc_in_2_relu1_0 { ap_memory {  { fc_in_2_relu1_0_address0 mem_address 1 8 }  { fc_in_2_relu1_0_ce0 mem_ce 1 1 }  { fc_in_2_relu1_0_we0 mem_we 1 1 }  { fc_in_2_relu1_0_d0 mem_din 1 32 }  { fc_in_2_relu1_0_q0 mem_dout 0 32 } } }
	fc_out_2_0 { ap_memory {  { fc_out_2_0_address0 mem_address 1 6 }  { fc_out_2_0_ce0 mem_ce 1 1 }  { fc_out_2_0_we0 mem_we 1 1 }  { fc_out_2_0_d0 mem_din 1 32 }  { fc_out_2_0_q0 mem_dout 0 32 } } }
	fc_hidden_layer2 { ap_memory {  { fc_hidden_layer2_address0 mem_address 1 13 }  { fc_hidden_layer2_ce0 mem_ce 1 1 }  { fc_hidden_layer2_q0 mem_dout 0 32 } } }
	fc_in_3_relu2_0 { ap_memory {  { fc_in_3_relu2_0_address0 mem_address 1 6 }  { fc_in_3_relu2_0_ce0 mem_ce 1 1 }  { fc_in_3_relu2_0_we0 mem_we 1 1 }  { fc_in_3_relu2_0_d0 mem_din 1 32 }  { fc_in_3_relu2_0_q0 mem_dout 0 32 } } }
	fc_hidden_layer3 { ap_memory {  { fc_hidden_layer3_address0 mem_address 1 9 }  { fc_hidden_layer3_ce0 mem_ce 1 1 }  { fc_hidden_layer3_q0 mem_dout 0 32 } } }
	probability_result { ap_memory {  { probability_result_address0 mem_address 1 4 }  { probability_result_ce0 mem_ce 1 1 }  { probability_result_we0 mem_we 1 1 }  { probability_result_d0 mem_din 1 32 } } }
}
