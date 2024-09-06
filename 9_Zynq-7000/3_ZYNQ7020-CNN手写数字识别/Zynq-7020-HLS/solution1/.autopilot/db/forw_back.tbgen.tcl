set moduleName forw_back
set isTopModule 1
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
set C_modelName {forw_back}
set C_modelType { void 0 }
set C_modelArgList {
	{ data float 32 regular {axi_master 2}  }
	{ flag int 32 regular {axi_slave 0}  }
	{ in_r int 32 regular {axi_slave 0}  }
	{ conv1 int 32 regular {axi_slave 0}  }
	{ conv2 int 32 regular {axi_slave 0}  }
	{ fc1 int 32 regular {axi_slave 0}  }
	{ fc2 int 32 regular {axi_slave 0}  }
	{ out_r int 32 regular {axi_slave 0}  }
	{ label_r int 32 regular {axi_slave 0}  }
	{ lr int 32 regular {axi_slave 0}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "data", "interface" : "axi_master", "bitwidth" : 32, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "in","cData": "float","bit_use": { "low": 0,"up": 31},"offset": { "type": "dynamic","port_name": "in_r","bundle": "ctrl"},"direction": "READONLY","cArray": [{"low" : 0,"up" : 31,"step" : 1}]},{"cName": "conv1","cData": "float","bit_use": { "low": 0,"up": 31},"offset": { "type": "dynamic","port_name": "conv1","bundle": "ctrl"},"direction": "READWRITE","cArray": [{"low" : 0,"up" : 31,"step" : 1}]},{"cName": "conv2","cData": "float","bit_use": { "low": 0,"up": 31},"offset": { "type": "dynamic","port_name": "conv2","bundle": "ctrl"},"direction": "READWRITE","cArray": [{"low" : 0,"up" : 31,"step" : 1}]},{"cName": "fc1","cData": "float","bit_use": { "low": 0,"up": 31},"offset": { "type": "dynamic","port_name": "fc1","bundle": "ctrl"},"direction": "READWRITE","cArray": [{"low" : 0,"up" : 31,"step" : 1}]},{"cName": "fc2","cData": "float","bit_use": { "low": 0,"up": 31},"offset": { "type": "dynamic","port_name": "fc2","bundle": "ctrl"},"direction": "READWRITE","cArray": [{"low" : 0,"up" : 31,"step" : 1}]},{"cName": "out","cData": "float","bit_use": { "low": 0,"up": 31},"offset": { "type": "dynamic","port_name": "out_r","bundle": "ctrl"},"direction": "WRITEONLY","cArray": [{"low" : 0,"up" : 31,"step" : 1}]},{"cName": "lr","cData": "float","bit_use": { "low": 0,"up": 31},"offset": { "type": "dynamic","port_name": "lr","bundle": "ctrl"},"direction": "READONLY","cArray": [{"low" : 0,"up" : 31,"step" : 1}]}]}]} , 
 	{ "Name" : "flag", "interface" : "axi_slave", "bundle":"ctrl","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "flag","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":16}, "offset_end" : {"in":23}} , 
 	{ "Name" : "in_r", "interface" : "axi_slave", "bundle":"ctrl","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "offset" : {"in":24}, "offset_end" : {"in":31}} , 
 	{ "Name" : "conv1", "interface" : "axi_slave", "bundle":"ctrl","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "offset" : {"in":32}, "offset_end" : {"in":39}} , 
 	{ "Name" : "conv2", "interface" : "axi_slave", "bundle":"ctrl","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "offset" : {"in":40}, "offset_end" : {"in":47}} , 
 	{ "Name" : "fc1", "interface" : "axi_slave", "bundle":"ctrl","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "offset" : {"in":48}, "offset_end" : {"in":55}} , 
 	{ "Name" : "fc2", "interface" : "axi_slave", "bundle":"ctrl","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "offset" : {"in":56}, "offset_end" : {"in":63}} , 
 	{ "Name" : "out_r", "interface" : "axi_slave", "bundle":"ctrl","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "offset" : {"in":64}, "offset_end" : {"in":71}} , 
 	{ "Name" : "label_r", "interface" : "axi_slave", "bundle":"ctrl","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":31,"cElement": [{"cName": "label","cData": "int","bit_use": { "low": 0,"up": 31},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}], "offset" : {"in":72}, "offset_end" : {"in":79}} , 
 	{ "Name" : "lr", "interface" : "axi_slave", "bundle":"ctrl","type":"ap_none","bitwidth" : 32, "direction" : "READONLY", "offset" : {"in":80}, "offset_end" : {"in":87}} ]}
# RTL Port declarations: 
set portNum 65
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ m_axi_data_AWVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_data_AWREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_data_AWADDR sc_out sc_lv 32 signal 0 } 
	{ m_axi_data_AWID sc_out sc_lv 1 signal 0 } 
	{ m_axi_data_AWLEN sc_out sc_lv 8 signal 0 } 
	{ m_axi_data_AWSIZE sc_out sc_lv 3 signal 0 } 
	{ m_axi_data_AWBURST sc_out sc_lv 2 signal 0 } 
	{ m_axi_data_AWLOCK sc_out sc_lv 2 signal 0 } 
	{ m_axi_data_AWCACHE sc_out sc_lv 4 signal 0 } 
	{ m_axi_data_AWPROT sc_out sc_lv 3 signal 0 } 
	{ m_axi_data_AWQOS sc_out sc_lv 4 signal 0 } 
	{ m_axi_data_AWREGION sc_out sc_lv 4 signal 0 } 
	{ m_axi_data_AWUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_data_WVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_data_WREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_data_WDATA sc_out sc_lv 32 signal 0 } 
	{ m_axi_data_WSTRB sc_out sc_lv 4 signal 0 } 
	{ m_axi_data_WLAST sc_out sc_logic 1 signal 0 } 
	{ m_axi_data_WID sc_out sc_lv 1 signal 0 } 
	{ m_axi_data_WUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_data_ARVALID sc_out sc_logic 1 signal 0 } 
	{ m_axi_data_ARREADY sc_in sc_logic 1 signal 0 } 
	{ m_axi_data_ARADDR sc_out sc_lv 32 signal 0 } 
	{ m_axi_data_ARID sc_out sc_lv 1 signal 0 } 
	{ m_axi_data_ARLEN sc_out sc_lv 8 signal 0 } 
	{ m_axi_data_ARSIZE sc_out sc_lv 3 signal 0 } 
	{ m_axi_data_ARBURST sc_out sc_lv 2 signal 0 } 
	{ m_axi_data_ARLOCK sc_out sc_lv 2 signal 0 } 
	{ m_axi_data_ARCACHE sc_out sc_lv 4 signal 0 } 
	{ m_axi_data_ARPROT sc_out sc_lv 3 signal 0 } 
	{ m_axi_data_ARQOS sc_out sc_lv 4 signal 0 } 
	{ m_axi_data_ARREGION sc_out sc_lv 4 signal 0 } 
	{ m_axi_data_ARUSER sc_out sc_lv 1 signal 0 } 
	{ m_axi_data_RVALID sc_in sc_logic 1 signal 0 } 
	{ m_axi_data_RREADY sc_out sc_logic 1 signal 0 } 
	{ m_axi_data_RDATA sc_in sc_lv 32 signal 0 } 
	{ m_axi_data_RLAST sc_in sc_logic 1 signal 0 } 
	{ m_axi_data_RID sc_in sc_lv 1 signal 0 } 
	{ m_axi_data_RUSER sc_in sc_lv 1 signal 0 } 
	{ m_axi_data_RRESP sc_in sc_lv 2 signal 0 } 
	{ m_axi_data_BVALID sc_in sc_logic 1 signal 0 } 
	{ m_axi_data_BREADY sc_out sc_logic 1 signal 0 } 
	{ m_axi_data_BRESP sc_in sc_lv 2 signal 0 } 
	{ m_axi_data_BID sc_in sc_lv 1 signal 0 } 
	{ m_axi_data_BUSER sc_in sc_lv 1 signal 0 } 
	{ s_axi_ctrl_AWVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_ctrl_AWREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_ctrl_AWADDR sc_in sc_lv 7 signal -1 } 
	{ s_axi_ctrl_WVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_ctrl_WREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_ctrl_WDATA sc_in sc_lv 32 signal -1 } 
	{ s_axi_ctrl_WSTRB sc_in sc_lv 4 signal -1 } 
	{ s_axi_ctrl_ARVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_ctrl_ARREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_ctrl_ARADDR sc_in sc_lv 7 signal -1 } 
	{ s_axi_ctrl_RVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_ctrl_RREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_ctrl_RDATA sc_out sc_lv 32 signal -1 } 
	{ s_axi_ctrl_RRESP sc_out sc_lv 2 signal -1 } 
	{ s_axi_ctrl_BVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_ctrl_BREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_ctrl_BRESP sc_out sc_lv 2 signal -1 } 
	{ interrupt sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "s_axi_ctrl_AWADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "ctrl", "role": "AWADDR" },"address":[{"name":"forw_back","role":"start","value":"0","valid_bit":"0"},{"name":"forw_back","role":"continue","value":"0","valid_bit":"4"},{"name":"forw_back","role":"auto_start","value":"0","valid_bit":"7"},{"name":"flag","role":"data","value":"16"},{"name":"in_r","role":"data","value":"24"},{"name":"conv1","role":"data","value":"32"},{"name":"conv2","role":"data","value":"40"},{"name":"fc1","role":"data","value":"48"},{"name":"fc2","role":"data","value":"56"},{"name":"out_r","role":"data","value":"64"},{"name":"label_r","role":"data","value":"72"},{"name":"lr","role":"data","value":"80"}] },
	{ "name": "s_axi_ctrl_AWVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "AWVALID" } },
	{ "name": "s_axi_ctrl_AWREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "AWREADY" } },
	{ "name": "s_axi_ctrl_WVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "WVALID" } },
	{ "name": "s_axi_ctrl_WREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "WREADY" } },
	{ "name": "s_axi_ctrl_WDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "ctrl", "role": "WDATA" } },
	{ "name": "s_axi_ctrl_WSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "ctrl", "role": "WSTRB" } },
	{ "name": "s_axi_ctrl_ARADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":7, "type": "signal", "bundle":{"name": "ctrl", "role": "ARADDR" },"address":[{"name":"forw_back","role":"start","value":"0","valid_bit":"0"},{"name":"forw_back","role":"done","value":"0","valid_bit":"1"},{"name":"forw_back","role":"idle","value":"0","valid_bit":"2"},{"name":"forw_back","role":"ready","value":"0","valid_bit":"3"},{"name":"forw_back","role":"auto_start","value":"0","valid_bit":"7"}] },
	{ "name": "s_axi_ctrl_ARVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "ARVALID" } },
	{ "name": "s_axi_ctrl_ARREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "ARREADY" } },
	{ "name": "s_axi_ctrl_RVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "RVALID" } },
	{ "name": "s_axi_ctrl_RREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "RREADY" } },
	{ "name": "s_axi_ctrl_RDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "ctrl", "role": "RDATA" } },
	{ "name": "s_axi_ctrl_RRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "ctrl", "role": "RRESP" } },
	{ "name": "s_axi_ctrl_BVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "BVALID" } },
	{ "name": "s_axi_ctrl_BREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "BREADY" } },
	{ "name": "s_axi_ctrl_BRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "ctrl", "role": "BRESP" } },
	{ "name": "interrupt", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "ctrl", "role": "interrupt" } }, 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }} , 
 	{ "name": "m_axi_data_AWVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "AWVALID" }} , 
 	{ "name": "m_axi_data_AWREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "AWREADY" }} , 
 	{ "name": "m_axi_data_AWADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "data", "role": "AWADDR" }} , 
 	{ "name": "m_axi_data_AWID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "AWID" }} , 
 	{ "name": "m_axi_data_AWLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "data", "role": "AWLEN" }} , 
 	{ "name": "m_axi_data_AWSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "data", "role": "AWSIZE" }} , 
 	{ "name": "m_axi_data_AWBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "data", "role": "AWBURST" }} , 
 	{ "name": "m_axi_data_AWLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "data", "role": "AWLOCK" }} , 
 	{ "name": "m_axi_data_AWCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "data", "role": "AWCACHE" }} , 
 	{ "name": "m_axi_data_AWPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "data", "role": "AWPROT" }} , 
 	{ "name": "m_axi_data_AWQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "data", "role": "AWQOS" }} , 
 	{ "name": "m_axi_data_AWREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "data", "role": "AWREGION" }} , 
 	{ "name": "m_axi_data_AWUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "AWUSER" }} , 
 	{ "name": "m_axi_data_WVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "WVALID" }} , 
 	{ "name": "m_axi_data_WREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "WREADY" }} , 
 	{ "name": "m_axi_data_WDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "data", "role": "WDATA" }} , 
 	{ "name": "m_axi_data_WSTRB", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "data", "role": "WSTRB" }} , 
 	{ "name": "m_axi_data_WLAST", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "WLAST" }} , 
 	{ "name": "m_axi_data_WID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "WID" }} , 
 	{ "name": "m_axi_data_WUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "WUSER" }} , 
 	{ "name": "m_axi_data_ARVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "ARVALID" }} , 
 	{ "name": "m_axi_data_ARREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "ARREADY" }} , 
 	{ "name": "m_axi_data_ARADDR", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "data", "role": "ARADDR" }} , 
 	{ "name": "m_axi_data_ARID", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "ARID" }} , 
 	{ "name": "m_axi_data_ARLEN", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "data", "role": "ARLEN" }} , 
 	{ "name": "m_axi_data_ARSIZE", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "data", "role": "ARSIZE" }} , 
 	{ "name": "m_axi_data_ARBURST", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "data", "role": "ARBURST" }} , 
 	{ "name": "m_axi_data_ARLOCK", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "data", "role": "ARLOCK" }} , 
 	{ "name": "m_axi_data_ARCACHE", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "data", "role": "ARCACHE" }} , 
 	{ "name": "m_axi_data_ARPROT", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "data", "role": "ARPROT" }} , 
 	{ "name": "m_axi_data_ARQOS", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "data", "role": "ARQOS" }} , 
 	{ "name": "m_axi_data_ARREGION", "direction": "out", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "data", "role": "ARREGION" }} , 
 	{ "name": "m_axi_data_ARUSER", "direction": "out", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "ARUSER" }} , 
 	{ "name": "m_axi_data_RVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "RVALID" }} , 
 	{ "name": "m_axi_data_RREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "RREADY" }} , 
 	{ "name": "m_axi_data_RDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "data", "role": "RDATA" }} , 
 	{ "name": "m_axi_data_RLAST", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "RLAST" }} , 
 	{ "name": "m_axi_data_RID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "RID" }} , 
 	{ "name": "m_axi_data_RUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "RUSER" }} , 
 	{ "name": "m_axi_data_RRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "data", "role": "RRESP" }} , 
 	{ "name": "m_axi_data_BVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "BVALID" }} , 
 	{ "name": "m_axi_data_BREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "BREADY" }} , 
 	{ "name": "m_axi_data_BRESP", "direction": "in", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "data", "role": "BRESP" }} , 
 	{ "name": "m_axi_data_BID", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "BID" }} , 
 	{ "name": "m_axi_data_BUSER", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "data", "role": "BUSER" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "41"],
		"CDFG" : "forw_back",
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
			{"State" : "ap_ST_fsm_state44", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_forward_fu_599"},
			{"State" : "ap_ST_fsm_state47", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_forward_fu_599"},
			{"State" : "ap_ST_fsm_state46", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_backward_fu_635"}],
		"Port" : [
			{"Name" : "data", "Type" : "MAXI", "Direction" : "IO",
				"BlockSignal" : [
					{"Name" : "data_blk_n_AW", "Type" : "RtlSignal"},
					{"Name" : "data_blk_n_W", "Type" : "RtlSignal"},
					{"Name" : "data_blk_n_B", "Type" : "RtlSignal"},
					{"Name" : "data_blk_n_AR", "Type" : "RtlSignal"},
					{"Name" : "data_blk_n_R", "Type" : "RtlSignal"}],
				"SubConnect" : [
					{"ID" : "41", "SubInstance" : "grp_backward_fu_635", "Port" : "lr_in"}]},
			{"Name" : "flag", "Type" : "None", "Direction" : "I"},
			{"Name" : "in_r", "Type" : "None", "Direction" : "I"},
			{"Name" : "conv1", "Type" : "None", "Direction" : "I"},
			{"Name" : "conv2", "Type" : "None", "Direction" : "I"},
			{"Name" : "fc1", "Type" : "None", "Direction" : "I"},
			{"Name" : "fc2", "Type" : "None", "Direction" : "I"},
			{"Name" : "out_r", "Type" : "None", "Direction" : "I"},
			{"Name" : "label_r", "Type" : "None", "Direction" : "I"},
			{"Name" : "lr", "Type" : "None", "Direction" : "I"},
			{"Name" : "conv_kernel_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_forward_fu_599", "Port" : "conv_kernel_1"},
					{"ID" : "41", "SubInstance" : "grp_backward_fu_635", "Port" : "conv_kernel_1"}]},
			{"Name" : "conv_kernel_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_forward_fu_599", "Port" : "conv_kernel_2"},
					{"ID" : "41", "SubInstance" : "grp_backward_fu_635", "Port" : "conv_kernel_2"}]},
			{"Name" : "fc_hidden_layer1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_forward_fu_599", "Port" : "fc_hidden_layer1"},
					{"ID" : "41", "SubInstance" : "grp_backward_fu_635", "Port" : "fc_hidden_layer1"}]},
			{"Name" : "fc_hidden_layer2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_forward_fu_599", "Port" : "fc_hidden_layer2"},
					{"ID" : "41", "SubInstance" : "grp_backward_fu_635", "Port" : "fc_hidden_layer2"}]},
			{"Name" : "mnist_data", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_forward_fu_599", "Port" : "mnist_data"},
					{"ID" : "41", "SubInstance" : "grp_backward_fu_635", "Port" : "mnist_data"}]},
			{"Name" : "conv_out_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_forward_fu_599", "Port" : "conv_out_1"}]},
			{"Name" : "max_poo_out_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_forward_fu_599", "Port" : "max_poo_out_1"},
					{"ID" : "41", "SubInstance" : "grp_backward_fu_635", "Port" : "max_poo_out_1"}]},
			{"Name" : "max_poo_locate_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_forward_fu_599", "Port" : "max_poo_locate_1"},
					{"ID" : "41", "SubInstance" : "grp_backward_fu_635", "Port" : "max_poo_locate_1"}]},
			{"Name" : "conv_out_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_forward_fu_599", "Port" : "conv_out_2"}]},
			{"Name" : "max_poo_out_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_forward_fu_599", "Port" : "max_poo_out_2"}]},
			{"Name" : "max_poo_locate_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_forward_fu_599", "Port" : "max_poo_locate_2"},
					{"ID" : "41", "SubInstance" : "grp_backward_fu_635", "Port" : "max_poo_locate_2"}]},
			{"Name" : "fc_in_1_0", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_forward_fu_599", "Port" : "fc_in_1_0"},
					{"ID" : "41", "SubInstance" : "grp_backward_fu_635", "Port" : "fc_in_1_0"}]},
			{"Name" : "fc_out_1_0", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_forward_fu_599", "Port" : "fc_out_1_0"},
					{"ID" : "41", "SubInstance" : "grp_backward_fu_635", "Port" : "fc_out_1_0"}]},
			{"Name" : "fc_in_2_relu1_0", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_forward_fu_599", "Port" : "fc_in_2_relu1_0"},
					{"ID" : "41", "SubInstance" : "grp_backward_fu_635", "Port" : "fc_in_2_relu1_0"}]},
			{"Name" : "fc_out_2_0", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_forward_fu_599", "Port" : "fc_out_2_0"}]},
			{"Name" : "probability_result", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "15", "SubInstance" : "grp_forward_fu_599", "Port" : "probability_result"},
					{"ID" : "41", "SubInstance" : "grp_backward_fu_635", "Port" : "probability_result"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.conv_kernel_1_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.conv_kernel_2_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_hidden_layer1_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_hidden_layer2_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mnist_data_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.max_poo_out_1_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.max_poo_locate_1_U", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.max_poo_locate_2_U", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_in_1_0_U", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_out_1_0_U", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fc_in_2_relu1_0_U", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.probability_result_U", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_ctrl_s_axi_U", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.forw_back_data_m_axi_U", "Parent" : "0"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599", "Parent" : "0", "Child" : ["16", "17", "18", "19", "20", "23", "26", "29", "32", "33", "34", "35", "36", "37", "38", "39", "40"],
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
			{"State" : "ap_ST_fsm_state4", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MaxPool2d_1_fu_399"},
			{"State" : "ap_ST_fsm_state8", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_MaxPool2d_fu_409"},
			{"State" : "ap_ST_fsm_state2", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_4_fu_419"},
			{"State" : "ap_ST_fsm_state6", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_Conv2d_3_fu_429"}],
		"Port" : [
			{"Name" : "mnist_data", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "26", "SubInstance" : "grp_Conv2d_4_fu_419", "Port" : "input_matrix"}]},
			{"Name" : "conv_kernel_1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "26", "SubInstance" : "grp_Conv2d_4_fu_419", "Port" : "kernel"}]},
			{"Name" : "conv_out_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "20", "SubInstance" : "grp_MaxPool2d_1_fu_399", "Port" : "conv_out_1"},
					{"ID" : "26", "SubInstance" : "grp_Conv2d_4_fu_419", "Port" : "out_matrix"}]},
			{"Name" : "max_poo_out_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "20", "SubInstance" : "grp_MaxPool2d_1_fu_399", "Port" : "output_matrix"},
					{"ID" : "29", "SubInstance" : "grp_Conv2d_3_fu_429", "Port" : "input_matrix"}]},
			{"Name" : "max_poo_locate_1", "Type" : "Memory", "Direction" : "O",
				"SubConnect" : [
					{"ID" : "20", "SubInstance" : "grp_MaxPool2d_1_fu_399", "Port" : "locate_matrix"}]},
			{"Name" : "conv_kernel_2", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "29", "SubInstance" : "grp_Conv2d_3_fu_429", "Port" : "kernel"}]},
			{"Name" : "conv_out_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "23", "SubInstance" : "grp_MaxPool2d_fu_409", "Port" : "conv_out_2"},
					{"ID" : "29", "SubInstance" : "grp_Conv2d_3_fu_429", "Port" : "out_matrix"}]},
			{"Name" : "max_poo_out_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "23", "SubInstance" : "grp_MaxPool2d_fu_409", "Port" : "output_matrix"}]},
			{"Name" : "max_poo_locate_2", "Type" : "Memory", "Direction" : "O",
				"SubConnect" : [
					{"ID" : "23", "SubInstance" : "grp_MaxPool2d_fu_409", "Port" : "locate_matrix"}]},
			{"Name" : "fc_in_1_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_out_1_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_hidden_layer1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "fc_in_2_relu1_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_out_2_0", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "fc_hidden_layer2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "probability_result", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "16", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.conv_out_1_U", "Parent" : "15"},
	{"ID" : "17", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.conv_out_2_U", "Parent" : "15"},
	{"ID" : "18", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.max_poo_out_2_U", "Parent" : "15"},
	{"ID" : "19", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.fc_out_2_0_U", "Parent" : "15"},
	{"ID" : "20", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.grp_MaxPool2d_1_fu_399", "Parent" : "15", "Child" : ["21", "22"],
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
	{"ID" : "21", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.grp_MaxPool2d_1_fu_399.forw_back_sitofp_dEe_U8", "Parent" : "20"},
	{"ID" : "22", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.grp_MaxPool2d_1_fu_399.forw_back_fcmp_32eOg_U9", "Parent" : "20"},
	{"ID" : "23", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.grp_MaxPool2d_fu_409", "Parent" : "15", "Child" : ["24", "25"],
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
	{"ID" : "24", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.grp_MaxPool2d_fu_409.forw_back_sitofp_dEe_U20", "Parent" : "23"},
	{"ID" : "25", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.grp_MaxPool2d_fu_409.forw_back_fcmp_32eOg_U21", "Parent" : "23"},
	{"ID" : "26", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.grp_Conv2d_4_fu_419", "Parent" : "15", "Child" : ["27", "28"],
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
	{"ID" : "27", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.grp_Conv2d_4_fu_419.forw_back_fadd_32bkb_U1", "Parent" : "26"},
	{"ID" : "28", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.grp_Conv2d_4_fu_419.forw_back_fmul_32cud_U2", "Parent" : "26"},
	{"ID" : "29", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.grp_Conv2d_3_fu_429", "Parent" : "15", "Child" : ["30", "31"],
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
	{"ID" : "30", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.grp_Conv2d_3_fu_429.forw_back_fadd_32bkb_U15", "Parent" : "29"},
	{"ID" : "31", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.grp_Conv2d_3_fu_429.forw_back_fmul_32cud_U16", "Parent" : "29"},
	{"ID" : "32", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.forw_back_fadd_32bkb_U25", "Parent" : "15"},
	{"ID" : "33", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.forw_back_fmul_32cud_U26", "Parent" : "15"},
	{"ID" : "34", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.forw_back_fptruncg8j_U27", "Parent" : "15"},
	{"ID" : "35", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.forw_back_fpext_3hbi_U28", "Parent" : "15"},
	{"ID" : "36", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.forw_back_fcmp_32eOg_U29", "Parent" : "15"},
	{"ID" : "37", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.forw_back_dadd_64ibs_U30", "Parent" : "15"},
	{"ID" : "38", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.forw_back_dmul_64jbC_U31", "Parent" : "15"},
	{"ID" : "39", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.forw_back_ddiv_64kbM_U32", "Parent" : "15"},
	{"ID" : "40", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_forward_fu_599.forw_back_dexp_64lbW_U33", "Parent" : "15"},
	{"ID" : "41", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635", "Parent" : "0", "Child" : ["42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "58", "61", "64", "67", "68", "69", "70", "71", "72", "73", "74", "75"],
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
					{"ID" : "68", "SubInstance" : "grp_MaxPooBackPropagatio_fu_725", "Port" : "max_poo_locate_2"}]},
			{"Name" : "max_poo_out_1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "61", "SubInstance" : "grp_Conv2d_2_fu_700", "Port" : "max_poo_out_1"}]},
			{"Name" : "conv_kernel_2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "64", "SubInstance" : "grp_MatrixBackPropagatio_fu_708", "Port" : "output_matrix"}]},
			{"Name" : "max_poo_locate_1", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "67", "SubInstance" : "grp_MaxPooBackPropagatio_1_fu_717", "Port" : "max_poo_locate_1"}]},
			{"Name" : "mnist_data", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "58", "SubInstance" : "grp_Conv2d_fu_692", "Port" : "input_matrix"}]},
			{"Name" : "conv_kernel_1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "64", "SubInstance" : "grp_MatrixBackPropagatio_fu_708", "Port" : "output_matrix"}]}]},
	{"ID" : "42", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grad_2_U", "Parent" : "41"},
	{"ID" : "43", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.wgrad_2_U", "Parent" : "41"},
	{"ID" : "44", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.rgrad_1_U", "Parent" : "41"},
	{"ID" : "45", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grad_1_U", "Parent" : "41"},
	{"ID" : "46", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.wgrad_1_U", "Parent" : "41"},
	{"ID" : "47", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grad_0_U", "Parent" : "41"},
	{"ID" : "48", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.conv_grad_2_U", "Parent" : "41"},
	{"ID" : "49", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.kernel_grad_2_U", "Parent" : "41"},
	{"ID" : "50", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.conv_grad_2_padding_U", "Parent" : "41"},
	{"ID" : "51", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.kernel_grad_2_overtu_U", "Parent" : "41"},
	{"ID" : "52", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.pool_grad_1_U", "Parent" : "41"},
	{"ID" : "53", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.conv_grad_1_U", "Parent" : "41"},
	{"ID" : "54", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.kernel_grad_1_U", "Parent" : "41"},
	{"ID" : "55", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grp_Conv2d_1_fu_685", "Parent" : "41", "Child" : ["56", "57"],
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
	{"ID" : "56", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grp_Conv2d_1_fu_685.forw_back_fadd_32bkb_U66", "Parent" : "55"},
	{"ID" : "57", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grp_Conv2d_1_fu_685.forw_back_fmul_32cud_U67", "Parent" : "55"},
	{"ID" : "58", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grp_Conv2d_fu_692", "Parent" : "41", "Child" : ["59", "60"],
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
	{"ID" : "59", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grp_Conv2d_fu_692.forw_back_fadd_32bkb_U74", "Parent" : "58"},
	{"ID" : "60", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grp_Conv2d_fu_692.forw_back_fmul_32cud_U75", "Parent" : "58"},
	{"ID" : "61", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grp_Conv2d_2_fu_700", "Parent" : "41", "Child" : ["62", "63"],
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
	{"ID" : "62", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grp_Conv2d_2_fu_700.forw_back_fadd_32bkb_U59", "Parent" : "61"},
	{"ID" : "63", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grp_Conv2d_2_fu_700.forw_back_fmul_32cud_U60", "Parent" : "61"},
	{"ID" : "64", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grp_MatrixBackPropagatio_fu_708", "Parent" : "41", "Child" : ["65", "66"],
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
	{"ID" : "65", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grp_MatrixBackPropagatio_fu_708.forw_back_fsub_32mb6_U79", "Parent" : "64"},
	{"ID" : "66", "Level" : "3", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grp_MatrixBackPropagatio_fu_708.forw_back_fmul_32cud_U80", "Parent" : "64"},
	{"ID" : "67", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grp_MaxPooBackPropagatio_1_fu_717", "Parent" : "41",
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
	{"ID" : "68", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grp_MaxPooBackPropagatio_fu_725", "Parent" : "41",
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
	{"ID" : "69", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.grp_Padding_fu_733", "Parent" : "41",
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
	{"ID" : "70", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.forw_back_faddfsuudo_U85", "Parent" : "41"},
	{"ID" : "71", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.forw_back_fmul_32cud_U86", "Parent" : "41"},
	{"ID" : "72", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.forw_back_fptruncg8j_U87", "Parent" : "41"},
	{"ID" : "73", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.forw_back_fpext_3hbi_U88", "Parent" : "41"},
	{"ID" : "74", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.forw_back_fcmp_32eOg_U89", "Parent" : "41"},
	{"ID" : "75", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_backward_fu_635.forw_back_dmul_64jbC_U90", "Parent" : "41"}]}


set ArgLastReadFirstWriteLatency {
	forw_back {
		data {Type IO LastRead 33 FirstWrite -1}
		flag {Type I LastRead 0 FirstWrite -1}
		in_r {Type I LastRead 0 FirstWrite -1}
		conv1 {Type I LastRead 0 FirstWrite -1}
		conv2 {Type I LastRead 0 FirstWrite -1}
		fc1 {Type I LastRead 0 FirstWrite -1}
		fc2 {Type I LastRead 0 FirstWrite -1}
		out_r {Type I LastRead 0 FirstWrite -1}
		label_r {Type I LastRead 0 FirstWrite -1}
		lr {Type I LastRead 0 FirstWrite -1}
		conv_kernel_1 {Type IO LastRead -1 FirstWrite -1}
		conv_kernel_2 {Type IO LastRead -1 FirstWrite -1}
		fc_hidden_layer1 {Type IO LastRead -1 FirstWrite -1}
		fc_hidden_layer2 {Type IO LastRead -1 FirstWrite -1}
		mnist_data {Type IO LastRead -1 FirstWrite -1}
		conv_out_1 {Type IO LastRead -1 FirstWrite -1}
		max_poo_out_1 {Type IO LastRead -1 FirstWrite -1}
		max_poo_locate_1 {Type IO LastRead -1 FirstWrite -1}
		conv_out_2 {Type IO LastRead -1 FirstWrite -1}
		max_poo_out_2 {Type IO LastRead -1 FirstWrite -1}
		max_poo_locate_2 {Type IO LastRead -1 FirstWrite -1}
		fc_in_1_0 {Type IO LastRead -1 FirstWrite -1}
		fc_out_1_0 {Type IO LastRead -1 FirstWrite -1}
		fc_in_2_relu1_0 {Type IO LastRead -1 FirstWrite -1}
		fc_out_2_0 {Type IO LastRead -1 FirstWrite -1}
		probability_result {Type IO LastRead -1 FirstWrite -1}}
	forward {
		mnist_data {Type I LastRead 4 FirstWrite -1}
		conv_kernel_1 {Type I LastRead 5 FirstWrite -1}
		conv_out_1 {Type IO LastRead -1 FirstWrite -1}
		max_poo_out_1 {Type IO LastRead 4 FirstWrite -1}
		max_poo_locate_1 {Type O LastRead -1 FirstWrite 17}
		conv_kernel_2 {Type I LastRead 5 FirstWrite -1}
		conv_out_2 {Type IO LastRead -1 FirstWrite -1}
		max_poo_out_2 {Type IO LastRead -1 FirstWrite -1}
		max_poo_locate_2 {Type O LastRead -1 FirstWrite 17}
		fc_in_1_0 {Type IO LastRead 10 FirstWrite 10}
		fc_out_1_0 {Type IO LastRead 10 FirstWrite 10}
		fc_hidden_layer1 {Type I LastRead 10 FirstWrite -1}
		fc_in_2_relu1_0 {Type IO LastRead 13 FirstWrite 23}
		fc_out_2_0 {Type IO LastRead -1 FirstWrite -1}
		fc_hidden_layer2 {Type I LastRead 12 FirstWrite -1}
		probability_result {Type O LastRead -1 FirstWrite 67}}
	MaxPool2d_1 {
		output_matrix {Type O LastRead -1 FirstWrite 9}
		locate_matrix {Type O LastRead -1 FirstWrite 17}
		conv_out_1 {Type I LastRead 9 FirstWrite -1}}
	MaxPool2d {
		output_matrix {Type O LastRead -1 FirstWrite 9}
		locate_matrix {Type O LastRead -1 FirstWrite 17}
		conv_out_2 {Type I LastRead 9 FirstWrite -1}}
	Conv2d_4 {
		input_matrix {Type I LastRead 4 FirstWrite -1}
		kernel {Type I LastRead 5 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 2}}
	Conv2d_3 {
		input_matrix {Type I LastRead 4 FirstWrite -1}
		kernel {Type I LastRead 5 FirstWrite -1}
		out_matrix {Type O LastRead -1 FirstWrite 2}}
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
	, {"Name" : "Interval", "Min" : "0", "Max" : "0"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
	{"Pipeline" : "2", "EnableSignal" : "ap_enable_pp2"}
	{"Pipeline" : "3", "EnableSignal" : "ap_enable_pp3"}
	{"Pipeline" : "4", "EnableSignal" : "ap_enable_pp4"}
	{"Pipeline" : "5", "EnableSignal" : "ap_enable_pp5"}
	{"Pipeline" : "6", "EnableSignal" : "ap_enable_pp6"}
	{"Pipeline" : "7", "EnableSignal" : "ap_enable_pp7"}
	{"Pipeline" : "8", "EnableSignal" : "ap_enable_pp8"}
	{"Pipeline" : "9", "EnableSignal" : "ap_enable_pp9"}
]}

set Spec2ImplPortList { 
	data { m_axi {  { m_axi_data_AWVALID VALID 1 1 }  { m_axi_data_AWREADY READY 0 1 }  { m_axi_data_AWADDR ADDR 1 32 }  { m_axi_data_AWID ID 1 1 }  { m_axi_data_AWLEN LEN 1 8 }  { m_axi_data_AWSIZE SIZE 1 3 }  { m_axi_data_AWBURST BURST 1 2 }  { m_axi_data_AWLOCK LOCK 1 2 }  { m_axi_data_AWCACHE CACHE 1 4 }  { m_axi_data_AWPROT PROT 1 3 }  { m_axi_data_AWQOS QOS 1 4 }  { m_axi_data_AWREGION REGION 1 4 }  { m_axi_data_AWUSER USER 1 1 }  { m_axi_data_WVALID VALID 1 1 }  { m_axi_data_WREADY READY 0 1 }  { m_axi_data_WDATA DATA 1 32 }  { m_axi_data_WSTRB STRB 1 4 }  { m_axi_data_WLAST LAST 1 1 }  { m_axi_data_WID ID 1 1 }  { m_axi_data_WUSER USER 1 1 }  { m_axi_data_ARVALID VALID 1 1 }  { m_axi_data_ARREADY READY 0 1 }  { m_axi_data_ARADDR ADDR 1 32 }  { m_axi_data_ARID ID 1 1 }  { m_axi_data_ARLEN LEN 1 8 }  { m_axi_data_ARSIZE SIZE 1 3 }  { m_axi_data_ARBURST BURST 1 2 }  { m_axi_data_ARLOCK LOCK 1 2 }  { m_axi_data_ARCACHE CACHE 1 4 }  { m_axi_data_ARPROT PROT 1 3 }  { m_axi_data_ARQOS QOS 1 4 }  { m_axi_data_ARREGION REGION 1 4 }  { m_axi_data_ARUSER USER 1 1 }  { m_axi_data_RVALID VALID 0 1 }  { m_axi_data_RREADY READY 1 1 }  { m_axi_data_RDATA DATA 0 32 }  { m_axi_data_RLAST LAST 0 1 }  { m_axi_data_RID ID 0 1 }  { m_axi_data_RUSER USER 0 1 }  { m_axi_data_RRESP RESP 0 2 }  { m_axi_data_BVALID VALID 0 1 }  { m_axi_data_BREADY READY 1 1 }  { m_axi_data_BRESP RESP 0 2 }  { m_axi_data_BID ID 0 1 }  { m_axi_data_BUSER USER 0 1 } } }
}

set busDeadlockParameterList { 
	{ data { NUM_READ_OUTSTANDING 16 NUM_WRITE_OUTSTANDING 16 MAX_READ_BURST_LENGTH 16 MAX_WRITE_BURST_LENGTH 16 } } \
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
	{ data 1 }
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
	{ data 1 }
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
