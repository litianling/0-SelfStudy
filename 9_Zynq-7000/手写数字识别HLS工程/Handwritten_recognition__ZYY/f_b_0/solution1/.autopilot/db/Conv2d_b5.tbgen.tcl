set moduleName Conv2d_b5
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
set C_modelName {Conv2d_b5}
set C_modelType { void 0 }
set C_modelArgList {
	{ input_matrix float 32 regular {array 900 { 1 1 } 1 1 }  }
	{ kernel float 32 regular {array 784 { 1 1 } 1 1 }  }
	{ out_matrix float 32 regular {array 9 { 0 3 } 0 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "input_matrix", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "kernel", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "out_matrix", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 22
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ input_matrix_address0 sc_out sc_lv 10 signal 0 } 
	{ input_matrix_ce0 sc_out sc_logic 1 signal 0 } 
	{ input_matrix_q0 sc_in sc_lv 32 signal 0 } 
	{ input_matrix_address1 sc_out sc_lv 10 signal 0 } 
	{ input_matrix_ce1 sc_out sc_logic 1 signal 0 } 
	{ input_matrix_q1 sc_in sc_lv 32 signal 0 } 
	{ kernel_address0 sc_out sc_lv 10 signal 1 } 
	{ kernel_ce0 sc_out sc_logic 1 signal 1 } 
	{ kernel_q0 sc_in sc_lv 32 signal 1 } 
	{ kernel_address1 sc_out sc_lv 10 signal 1 } 
	{ kernel_ce1 sc_out sc_logic 1 signal 1 } 
	{ kernel_q1 sc_in sc_lv 32 signal 1 } 
	{ out_matrix_address0 sc_out sc_lv 4 signal 2 } 
	{ out_matrix_ce0 sc_out sc_logic 1 signal 2 } 
	{ out_matrix_we0 sc_out sc_logic 1 signal 2 } 
	{ out_matrix_d0 sc_out sc_lv 32 signal 2 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "input_matrix_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "input_matrix", "role": "address0" }} , 
 	{ "name": "input_matrix_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "ce0" }} , 
 	{ "name": "input_matrix_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_matrix", "role": "q0" }} , 
 	{ "name": "input_matrix_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "input_matrix", "role": "address1" }} , 
 	{ "name": "input_matrix_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "input_matrix", "role": "ce1" }} , 
 	{ "name": "input_matrix_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "input_matrix", "role": "q1" }} , 
 	{ "name": "kernel_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "kernel", "role": "address0" }} , 
 	{ "name": "kernel_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "kernel", "role": "ce0" }} , 
 	{ "name": "kernel_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "kernel", "role": "q0" }} , 
 	{ "name": "kernel_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "kernel", "role": "address1" }} , 
 	{ "name": "kernel_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "kernel", "role": "ce1" }} , 
 	{ "name": "kernel_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "kernel", "role": "q1" }} , 
 	{ "name": "out_matrix_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "out_matrix", "role": "address0" }} , 
 	{ "name": "out_matrix_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "out_matrix", "role": "ce0" }} , 
 	{ "name": "out_matrix_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "out_matrix", "role": "we0" }} , 
 	{ "name": "out_matrix_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "out_matrix", "role": "d0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2"],
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
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fadd_32bkb_U77", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_fmul_32cud_U78", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	Conv2d_b5 {
		input_matrix {Type I LastRead 4 FirstWrite -1}
		kernel {Type I LastRead 4 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "388", "Max" : "388"}
	, {"Name" : "Interval", "Min" : "388", "Max" : "388"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	input_matrix { ap_memory {  { input_matrix_address0 mem_address 1 10 }  { input_matrix_ce0 mem_ce 1 1 }  { input_matrix_q0 mem_dout 0 32 }  { input_matrix_address1 MemPortADDR2 1 10 }  { input_matrix_ce1 MemPortCE2 1 1 }  { input_matrix_q1 MemPortDOUT2 0 32 } } }
	kernel { ap_memory {  { kernel_address0 mem_address 1 10 }  { kernel_ce0 mem_ce 1 1 }  { kernel_q0 mem_dout 0 32 }  { kernel_address1 MemPortADDR2 1 10 }  { kernel_ce1 MemPortCE2 1 1 }  { kernel_q1 MemPortDOUT2 0 32 } } }
	out_matrix { ap_memory {  { out_matrix_address0 mem_address 1 4 }  { out_matrix_ce0 mem_ce 1 1 }  { out_matrix_we0 mem_we 1 1 }  { out_matrix_d0 mem_din 1 32 } } }
}
