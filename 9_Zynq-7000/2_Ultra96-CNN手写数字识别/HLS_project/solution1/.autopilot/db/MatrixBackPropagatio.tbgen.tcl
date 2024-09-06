set moduleName MatrixBackPropagatio
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
set C_modelName {MatrixBackPropagatio}
set C_modelType { void 0 }
set C_modelArgList {
	{ input_matrix float 32 regular {array 9 { 1 3 } 1 1 }  }
	{ output_matrix float 32 regular {array 9 { 2 3 } 1 1 }  }
	{ lr float 32 regular  }
}
set C_modelArgMapList {[ 
	{ "Name" : "input_matrix", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "output_matrix", "interface" : "memory", "bitwidth" : 32, "direction" : "READWRITE"} , 
 	{ "Name" : "lr", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} ]}
# RTL Port declarations: 
set portNum 15
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ input_matrix_address0 sc_out sc_lv 4 signal 0 } 
	{ input_matrix_ce0 sc_out sc_logic 1 signal 0 } 
	{ input_matrix_q0 sc_in sc_lv 32 signal 0 } 
	{ output_matrix_address0 sc_out sc_lv 4 signal 1 } 
	{ output_matrix_ce0 sc_out sc_logic 1 signal 1 } 
	{ output_matrix_we0 sc_out sc_logic 1 signal 1 } 
	{ output_matrix_d0 sc_out sc_lv 32 signal 1 } 
	{ output_matrix_q0 sc_in sc_lv 32 signal 1 } 
	{ lr sc_in sc_lv 32 signal 2 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "input_matrix_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "input_matrix", "role": "address0" }} , 
 	{ "name": "input_matrix_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "ce0" }} , 
 	{ "name": "input_matrix_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_matrix", "role": "q0" }} , 
 	{ "name": "output_matrix_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "output_matrix", "role": "address0" }} , 
 	{ "name": "output_matrix_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "output_matrix", "role": "ce0" }} , 
 	{ "name": "output_matrix_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "output_matrix", "role": "we0" }} , 
 	{ "name": "output_matrix_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "output_matrix", "role": "d0" }} , 
 	{ "name": "output_matrix_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "output_matrix", "role": "q0" }} , 
 	{ "name": "lr", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "lr", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2"],
		"CDFG" : "MatrixBackPropagatio",
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
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fsub_32mb6_U79", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fmul_32cud_U80", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	MatrixBackPropagatio {
		input_matrix {Type I LastRead 2 FirstWrite -1}
		output_matrix {Type IO LastRead 6 FirstWrite 10}
		lr {Type I LastRead 0 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "88", "Max" : "88"}
	, {"Name" : "Interval", "Min" : "88", "Max" : "88"}
]}

set PipelineEnableSignalInfo {[
]}

set Spec2ImplPortList { 
	input_matrix { ap_memory {  { input_matrix_address0 mem_address 1 4 }  { input_matrix_ce0 mem_ce 1 1 }  { input_matrix_q0 mem_dout 0 32 } } }
	output_matrix { ap_memory {  { output_matrix_address0 mem_address 1 4 }  { output_matrix_ce0 mem_ce 1 1 }  { output_matrix_we0 mem_we 1 1 }  { output_matrix_d0 mem_din 1 32 }  { output_matrix_q0 mem_dout 0 32 } } }
	lr { ap_none {  { lr in_data 0 32 } } }
}
