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
	{ max_poo_out_1 float 32 regular {array 196 { 2 3 } 1 1 } {global 2}  }
	{ max_poo_locate_1 float 32 regular {array 196 { 0 3 } 0 1 } {global 1}  }
	{ conv_kernel_2 float 32 regular {array 9 { 1 3 } 1 1 } {global 0}  }
	{ max_poo_locate_2 float 32 regular {array 36 { 0 3 } 0 1 } {global 1}  }
	{ fc_in_1_0 float 32 regular {array 36 { 2 0 } 1 1 } {global 2}  }
	{ fc_out_1_0 float 32 regular {array 20 { 2 3 } 1 1 } {global 2}  }
	{ fc_hidden_layer1 float 32 regular {array 720 { 1 3 } 1 1 } {global 0}  }
	{ fc_in_2_relu1_0 float 32 regular {array 20 { 2 3 } 1 1 } {global 2}  }
	{ fc_hidden_layer2 float 32 regular {array 200 { 1 3 } 1 1 } {global 0}  }
	{ probability_result float 32 regular {array 10 { 0 3 } 0 1 } {global 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "mnist_data", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "conv_kernel_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "max_poo_out_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "max_poo_locate_1", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY", "extern" : 0} , 
 	{ "Name" : "conv_kernel_2", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "max_poo_locate_2", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY", "extern" : 0} , 
 	{ "Name" : "fc_in_1_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "fc_out_1_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "fc_hidden_layer1", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "fc_in_2_relu1_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE", "extern" : 0} , 
 	{ "Name" : "fc_hidden_layer2", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "extern" : 0} , 
 	{ "Name" : "probability_result", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY", "extern" : 0} ]}
# RTL Port declarations: 
set portNum 57
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
	{ max_poo_out_1_address0 sc_out sc_lv 8 signal 2 } 
	{ max_poo_out_1_ce0 sc_out sc_logic 1 signal 2 } 
	{ max_poo_out_1_we0 sc_out sc_logic 1 signal 2 } 
	{ max_poo_out_1_d0 sc_out sc_lv 32 signal 2 } 
	{ max_poo_out_1_q0 sc_in sc_lv 32 signal 2 } 
	{ max_poo_locate_1_address0 sc_out sc_lv 8 signal 3 } 
	{ max_poo_locate_1_ce0 sc_out sc_logic 1 signal 3 } 
	{ max_poo_locate_1_we0 sc_out sc_logic 1 signal 3 } 
	{ max_poo_locate_1_d0 sc_out sc_lv 32 signal 3 } 
	{ conv_kernel_2_address0 sc_out sc_lv 4 signal 4 } 
	{ conv_kernel_2_ce0 sc_out sc_logic 1 signal 4 } 
	{ conv_kernel_2_q0 sc_in sc_lv 32 signal 4 } 
	{ max_poo_locate_2_address0 sc_out sc_lv 6 signal 5 } 
	{ max_poo_locate_2_ce0 sc_out sc_logic 1 signal 5 } 
	{ max_poo_locate_2_we0 sc_out sc_logic 1 signal 5 } 
	{ max_poo_locate_2_d0 sc_out sc_lv 32 signal 5 } 
	{ fc_in_1_0_address0 sc_out sc_lv 6 signal 6 } 
	{ fc_in_1_0_ce0 sc_out sc_logic 1 signal 6 } 
	{ fc_in_1_0_we0 sc_out sc_logic 1 signal 6 } 
	{ fc_in_1_0_d0 sc_out sc_lv 32 signal 6 } 
	{ fc_in_1_0_q0 sc_in sc_lv 32 signal 6 } 
	{ fc_in_1_0_address1 sc_out sc_lv 6 signal 6 } 
	{ fc_in_1_0_ce1 sc_out sc_logic 1 signal 6 } 
	{ fc_in_1_0_we1 sc_out sc_logic 1 signal 6 } 
	{ fc_in_1_0_d1 sc_out sc_lv 32 signal 6 } 
	{ fc_out_1_0_address0 sc_out sc_lv 5 signal 7 } 
	{ fc_out_1_0_ce0 sc_out sc_logic 1 signal 7 } 
	{ fc_out_1_0_we0 sc_out sc_logic 1 signal 7 } 
	{ fc_out_1_0_d0 sc_out sc_lv 32 signal 7 } 
	{ fc_out_1_0_q0 sc_in sc_lv 32 signal 7 } 
	{ fc_hidden_layer1_address0 sc_out sc_lv 10 signal 8 } 
	{ fc_hidden_layer1_ce0 sc_out sc_logic 1 signal 8 } 
	{ fc_hidden_layer1_q0 sc_in sc_lv 32 signal 8 } 
	{ fc_in_2_relu1_0_address0 sc_out sc_lv 5 signal 9 } 
	{ fc_in_2_relu1_0_ce0 sc_out sc_logic 1 signal 9 } 
	{ fc_in_2_relu1_0_we0 sc_out sc_logic 1 signal 9 } 
	{ fc_in_2_relu1_0_d0 sc_out sc_lv 32 signal 9 } 
	{ fc_in_2_relu1_0_q0 sc_in sc_lv 32 signal 9 } 
	{ fc_hidden_layer2_address0 sc_out sc_lv 8 signal 10 } 
	{ fc_hidden_layer2_ce0 sc_out sc_logic 1 signal 10 } 
	{ fc_hidden_layer2_q0 sc_in sc_lv 32 signal 10 } 
	{ probability_result_address0 sc_out sc_lv 4 signal 11 } 
	{ probability_result_ce0 sc_out sc_logic 1 signal 11 } 
	{ probability_result_we0 sc_out sc_logic 1 signal 11 } 
	{ probability_result_d0 sc_out sc_lv 32 signal 11 } 
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
 	{ "name": "max_poo_out_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "max_poo_out_1", "role": "address0" }} , 
 	{ "name": "max_poo_out_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "max_poo_out_1", "role": "ce0" }} , 
 	{ "name": "max_poo_out_1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "max_poo_out_1", "role": "we0" }} , 
 	{ "name": "max_poo_out_1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "max_poo_out_1", "role": "d0" }} , 
 	{ "name": "max_poo_out_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "max_poo_out_1", "role": "q0" }} , 
 	{ "name": "max_poo_locate_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "max_poo_locate_1", "role": "address0" }} , 
 	{ "name": "max_poo_locate_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "max_poo_locate_1", "role": "ce0" }} , 
 	{ "name": "max_poo_locate_1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "max_poo_locate_1", "role": "we0" }} , 
 	{ "name": "max_poo_locate_1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "max_poo_locate_1", "role": "d0" }} , 
 	{ "name": "conv_kernel_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "conv_kernel_2", "role": "address0" }} , 
 	{ "name": "conv_kernel_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "conv_kernel_2", "role": "ce0" }} , 
 	{ "name": "conv_kernel_2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "conv_kernel_2", "role": "q0" }} , 
 	{ "name": "max_poo_locate_2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "max_poo_locate_2", "role": "address0" }} , 
 	{ "name": "max_poo_locate_2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "max_poo_locate_2", "role": "ce0" }} , 
 	{ "name": "max_poo_locate_2_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "max_poo_locate_2", "role": "we0" }} , 
 	{ "name": "max_poo_locate_2_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "max_poo_locate_2", "role": "d0" }} , 
 	{ "name": "fc_in_1_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "address0" }} , 
 	{ "name": "fc_in_1_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "ce0" }} , 
 	{ "name": "fc_in_1_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "we0" }} , 
 	{ "name": "fc_in_1_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "d0" }} , 
 	{ "name": "fc_in_1_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "q0" }} , 
 	{ "name": "fc_in_1_0_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "address1" }} , 
 	{ "name": "fc_in_1_0_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "ce1" }} , 
 	{ "name": "fc_in_1_0_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "we1" }} , 
 	{ "name": "fc_in_1_0_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_in_1_0", "role": "d1" }} , 
 	{ "name": "fc_out_1_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "fc_out_1_0", "role": "address0" }} , 
 	{ "name": "fc_out_1_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_out_1_0", "role": "ce0" }} , 
 	{ "name": "fc_out_1_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_out_1_0", "role": "we0" }} , 
 	{ "name": "fc_out_1_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_out_1_0", "role": "d0" }} , 
 	{ "name": "fc_out_1_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_out_1_0", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "address0" }} , 
 	{ "name": "fc_hidden_layer1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "ce0" }} , 
 	{ "name": "fc_hidden_layer1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer1", "role": "q0" }} , 
 	{ "name": "fc_in_2_relu1_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "fc_in_2_relu1_0", "role": "address0" }} , 
 	{ "name": "fc_in_2_relu1_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_in_2_relu1_0", "role": "ce0" }} , 
 	{ "name": "fc_in_2_relu1_0_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_in_2_relu1_0", "role": "we0" }} , 
 	{ "name": "fc_in_2_relu1_0_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_in_2_relu1_0", "role": "d0" }} , 
 	{ "name": "fc_in_2_relu1_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_in_2_relu1_0", "role": "q0" }} , 
 	{ "name": "fc_hidden_layer2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "address0" }} , 
 	{ "name": "fc_hidden_layer2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "ce0" }} , 
 	{ "name": "fc_hidden_layer2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "fc_hidden_layer2", "role": "q0" }} , 
 	{ "name": "probability_result_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "probability_result", "role": "address0" }} , 
 	{ "name": "probability_result_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "probability_result", "role": "ce0" }} , 
 	{ "name": "probability_result_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "probability_result", "role": "we0" }} , 
 	{ "name": "probability_result_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "probability_result", "role": "d0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "8", "11", "14", "17", "18", "19", "20", "21", "22", "23", "24", "25"],
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
			{"State" : "ap_ST_fsm_state2", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_4_fu_496"},
			{"State" : "ap_ST_fsm_state6", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_3_fu_506"},
			{"State" : "ap_ST_fsm_state4", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MaxPool2d_1_fu_516"},
			{"State" : "ap_ST_fsm_state8", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MaxPool2d_fu_526"}],
		"Port" : [
			{"Name" : "mnist_data", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "grp_Conv2d_4_fu_496", "Port" : "input_matrix"}]},
			{"Name" : "conv_kernel_1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "5", "SubInstance" : "grp_Conv2d_4_fu_496", "Port" : "kernel"}]},
			{"Name" : "conv_out_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "11", "SubInstance" : "grp_MaxPool2d_1_fu_516", "Port" : "conv_out_1"},
					{"ID" : "5", "SubInstance" : "grp_Conv2d_4_fu_496", "Port" : "out_matrix"}]},
			{"Name" : "max_poo_out_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Conv2d_3_fu_506", "Port" : "input_matrix"},
					{"ID" : "11", "SubInstance" : "grp_MaxPool2d_1_fu_516", "Port" : "output_matrix"}]},
			{"Name" : "max_poo_locate_1", "Type" : "Memory", "Direction" : "O",
				"SubConnect" : [
					{"ID" : "11", "SubInstance" : "grp_MaxPool2d_1_fu_516", "Port" : "locate_matrix"}]},
			{"Name" : "conv_kernel_2", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "8", "SubInstance" : "grp_Conv2d_3_fu_506", "Port" : "kernel"}]},
			{"Name" : "conv_out_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "14", "SubInstance" : "grp_MaxPool2d_fu_526", "Port" : "conv_out_2"},
					{"ID" : "8", "SubInstance" : "grp_Conv2d_3_fu_506", "Port" : "out_matrix"}]},
			{"Name" : "max_poo_out_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "14", "SubInstance" : "grp_MaxPool2d_fu_526", "Port" : "output_matrix"}]},
			{"Name" : "max_poo_locate_2", "Type" : "Memory", "Direction" : "O",
				"SubConnect" : [
					{"ID" : "14", "SubInstance" : "grp_MaxPool2d_fu_526", "Port" : "locate_matrix"}]},
			{"Name" : "fc_in_1_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_out_1_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_hidden_layer1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_in_2_relu1_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_out_2_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_hidden_layer2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "probability_result", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.conv_out_1_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.conv_out_2_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.max_poo_out_2_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_out_2_0_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_4_fu_496", "Parent" : "0", "Child" : ["6", "7"],
		"CDFG" : "Conv2d_4",
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
	{"ID" : "6", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_4_fu_496.forw_back_fadd_32bkb_U1", "Parent" : "5"},
	{"ID" : "7", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_4_fu_496.forw_back_fmul_32cud_U2", "Parent" : "5"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_3_fu_506", "Parent" : "0", "Child" : ["9", "10"],
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
	{"ID" : "9", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_3_fu_506.forw_back_fadd_32bkb_U15", "Parent" : "8"},
	{"ID" : "10", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_Conv2d_3_fu_506.forw_back_fmul_32cud_U16", "Parent" : "8"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_MaxPool2d_1_fu_516", "Parent" : "0", "Child" : ["12", "13"],
		"CDFG" : "MaxPool2d_1",
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
			{"Name" : "output_matrix", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "locate_matrix", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "conv_out_1", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "12", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_MaxPool2d_1_fu_516.forw_back_sitofp_dEe_U8", "Parent" : "11"},
	{"ID" : "13", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_MaxPool2d_1_fu_516.forw_back_fcmp_32eOg_U9", "Parent" : "11"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_MaxPool2d_fu_526", "Parent" : "0", "Child" : ["15", "16"],
		"CDFG" : "MaxPool2d",
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
			{"Name" : "output_matrix", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "locate_matrix", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "conv_out_2", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "15", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_MaxPool2d_fu_526.forw_back_sitofp_dEe_U20", "Parent" : "14"},
	{"ID" : "16", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_MaxPool2d_fu_526.forw_back_fcmp_32eOg_U21", "Parent" : "14"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fadd_32bkb_U25", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fmul_32cud_U26", "Parent" : "0"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fptruncg8j_U27", "Parent" : "0"},
	{"ID" : "20", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fpext_3hbi_U28", "Parent" : "0"},
	{"ID" : "21", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fcmp_32eOg_U29", "Parent" : "0"},
	{"ID" : "22", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_dadd_64ibs_U30", "Parent" : "0"},
	{"ID" : "23", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_dmul_64jbC_U31", "Parent" : "0"},
	{"ID" : "24", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_ddiv_64kbM_U32", "Parent" : "0"},
	{"ID" : "25", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_dexp_64lbW_U33", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	forward {
		mnist_data {Type I LastRead 2 FirstWrite -1}
		conv_kernel_1 {Type I LastRead 2 FirstWrite -1}
		conv_out_1 {Type IO LastRead -1 FirstWrite -1}
		max_poo_out_1 {Type IO LastRead 2 FirstWrite -1}
		max_poo_locate_1 {Type O LastRead -1 FirstWrite 12}
		conv_kernel_2 {Type I LastRead 2 FirstWrite -1}
		conv_out_2 {Type IO LastRead -1 FirstWrite -1}
		max_poo_out_2 {Type IO LastRead -1 FirstWrite -1}
		max_poo_locate_2 {Type O LastRead -1 FirstWrite 12}
		fc_in_1_0 {Type IO LastRead 11 FirstWrite 9}
		fc_out_1_0 {Type IO LastRead 11 FirstWrite 11}
		fc_hidden_layer1 {Type I LastRead 11 FirstWrite -1}
		fc_in_2_relu1_0 {Type IO LastRead 13 FirstWrite 21}
		fc_out_2_0 {Type IO LastRead -1 FirstWrite -1}
		fc_hidden_layer2 {Type I LastRead 13 FirstWrite -1}
		probability_result {Type O LastRead -1 FirstWrite 54}}
	Conv2d_4 {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		kernel {Type I LastRead 2 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}}
	Conv2d_3 {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		kernel {Type I LastRead 2 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}}
	MaxPool2d_1 {
		output_matrix {Type O LastRead -1 FirstWrite 6}
		locate_matrix {Type O LastRead -1 FirstWrite 12}
		conv_out_1 {Type I LastRead 7 FirstWrite -1}}
	MaxPool2d {
		output_matrix {Type O LastRead -1 FirstWrite 6}
		locate_matrix {Type O LastRead -1 FirstWrite 12}
		conv_out_2 {Type I LastRead 7 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "-1", "Max" : "-1"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	mnist_data { ap_memory {  { mnist_data_address0 mem_address 1 10 }  { mnist_data_ce0 mem_ce 1 1 }  { mnist_data_q0 mem_dout 0 32 } } }
	conv_kernel_1 { ap_memory {  { conv_kernel_1_address0 mem_address 1 4 }  { conv_kernel_1_ce0 mem_ce 1 1 }  { conv_kernel_1_q0 mem_dout 0 32 } } }
	max_poo_out_1 { ap_memory {  { max_poo_out_1_address0 mem_address 1 8 }  { max_poo_out_1_ce0 mem_ce 1 1 }  { max_poo_out_1_we0 mem_we 1 1 }  { max_poo_out_1_d0 mem_din 1 32 }  { max_poo_out_1_q0 mem_dout 0 32 } } }
	max_poo_locate_1 { ap_memory {  { max_poo_locate_1_address0 mem_address 1 8 }  { max_poo_locate_1_ce0 mem_ce 1 1 }  { max_poo_locate_1_we0 mem_we 1 1 }  { max_poo_locate_1_d0 mem_din 1 32 } } }
	conv_kernel_2 { ap_memory {  { conv_kernel_2_address0 mem_address 1 4 }  { conv_kernel_2_ce0 mem_ce 1 1 }  { conv_kernel_2_q0 mem_dout 0 32 } } }
	max_poo_locate_2 { ap_memory {  { max_poo_locate_2_address0 mem_address 1 6 }  { max_poo_locate_2_ce0 mem_ce 1 1 }  { max_poo_locate_2_we0 mem_we 1 1 }  { max_poo_locate_2_d0 mem_din 1 32 } } }
	fc_in_1_0 { ap_memory {  { fc_in_1_0_address0 mem_address 1 6 }  { fc_in_1_0_ce0 mem_ce 1 1 }  { fc_in_1_0_we0 mem_we 1 1 }  { fc_in_1_0_d0 mem_din 1 32 }  { fc_in_1_0_q0 mem_dout 0 32 }  { fc_in_1_0_address1 MemPortADDR2 1 6 }  { fc_in_1_0_ce1 MemPortCE2 1 1 }  { fc_in_1_0_we1 MemPortWE2 1 1 }  { fc_in_1_0_d1 MemPortDIN2 1 32 } } }
	fc_out_1_0 { ap_memory {  { fc_out_1_0_address0 mem_address 1 5 }  { fc_out_1_0_ce0 mem_ce 1 1 }  { fc_out_1_0_we0 mem_we 1 1 }  { fc_out_1_0_d0 mem_din 1 32 }  { fc_out_1_0_q0 mem_dout 0 32 } } }
	fc_hidden_layer1 { ap_memory {  { fc_hidden_layer1_address0 mem_address 1 10 }  { fc_hidden_layer1_ce0 mem_ce 1 1 }  { fc_hidden_layer1_q0 mem_dout 0 32 } } }
	fc_in_2_relu1_0 { ap_memory {  { fc_in_2_relu1_0_address0 mem_address 1 5 }  { fc_in_2_relu1_0_ce0 mem_ce 1 1 }  { fc_in_2_relu1_0_we0 mem_we 1 1 }  { fc_in_2_relu1_0_d0 mem_din 1 32 }  { fc_in_2_relu1_0_q0 mem_dout 0 32 } } }
	fc_hidden_layer2 { ap_memory {  { fc_hidden_layer2_address0 mem_address 1 8 }  { fc_hidden_layer2_ce0 mem_ce 1 1 }  { fc_hidden_layer2_q0 mem_dout 0 32 } } }
	probability_result { ap_memory {  { probability_result_address0 mem_address 1 4 }  { probability_result_ce0 mem_ce 1 1 }  { probability_result_we0 mem_we 1 1 }  { probability_result_d0 mem_din 1 32 } } }
}
