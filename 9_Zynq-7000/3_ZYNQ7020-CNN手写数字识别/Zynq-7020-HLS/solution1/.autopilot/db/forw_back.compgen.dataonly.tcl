# This script segment is generated automatically by AutoPilot

set axilite_register_dict [dict create]
set port_ctrl {
ap_start { }
ap_done { }
ap_ready { }
ap_idle { }
flag { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 16
	offset_end 23
}
in_r { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 24
	offset_end 31
}
conv1 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 32
	offset_end 39
}
conv2 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 40
	offset_end 47
}
fc1 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 48
	offset_end 55
}
fc2 { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 56
	offset_end 63
}
out_r { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 64
	offset_end 71
}
label_r { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 72
	offset_end 79
}
lr { 
	dir I
	width 32
	depth 1
	mode ap_none
	offset 80
	offset_end 87
}
}
dict set axilite_register_dict ctrl $port_ctrl


