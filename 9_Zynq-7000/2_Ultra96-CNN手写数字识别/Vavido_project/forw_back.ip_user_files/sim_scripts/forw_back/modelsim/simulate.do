onbreak {quit -f}
onerror {quit -f}

vsim -voptargs="+acc" -t 1ps -L xilinx_vip -L xil_defaultlib -L xpm -L axi_infrastructure_v1_1_0 -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L xlconstant_v1_1_6 -L lib_cdc_v1_0_2 -L proc_sys_reset_v5_0_13 -L smartconnect_v1_0 -L generic_baseblocks_v2_1_0 -L fifo_generator_v13_2_4 -L axi_data_fifo_v2_1_18 -L axi_register_slice_v2_1_19 -L axi_protocol_converter_v2_1_19 -L axi_clock_converter_v2_1_18 -L blk_mem_gen_v8_4_3 -L axi_dwidth_converter_v2_1_19 -L xbip_utils_v3_0_10 -L axi_utils_v2_0_6 -L xbip_pipe_v3_0_6 -L xbip_dsp48_wrapper_v3_0_4 -L xbip_dsp48_addsub_v3_0_6 -L xbip_dsp48_multadd_v3_0_6 -L xbip_bram18k_v3_0_6 -L mult_gen_v12_0_15 -L floating_point_v7_1_8 -L xilinx_vip -L unisims_ver -L unimacro_ver -L secureip -lib xil_defaultlib xil_defaultlib.forw_back xil_defaultlib.glbl

do {wave.do}

view wave
view structure
view signals

do {forw_back.udo}

run -all

quit -force
