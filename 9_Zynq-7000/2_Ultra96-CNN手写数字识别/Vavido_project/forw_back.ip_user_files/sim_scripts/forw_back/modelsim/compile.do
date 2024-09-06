vlib modelsim_lib/work
vlib modelsim_lib/msim

vlib modelsim_lib/msim/xilinx_vip
vlib modelsim_lib/msim/xil_defaultlib
vlib modelsim_lib/msim/xpm
vlib modelsim_lib/msim/axi_infrastructure_v1_1_0
vlib modelsim_lib/msim/axi_vip_v1_1_5
vlib modelsim_lib/msim/zynq_ultra_ps_e_vip_v1_0_5
vlib modelsim_lib/msim/xlconstant_v1_1_6
vlib modelsim_lib/msim/lib_cdc_v1_0_2
vlib modelsim_lib/msim/proc_sys_reset_v5_0_13
vlib modelsim_lib/msim/smartconnect_v1_0
vlib modelsim_lib/msim/generic_baseblocks_v2_1_0
vlib modelsim_lib/msim/fifo_generator_v13_2_4
vlib modelsim_lib/msim/axi_data_fifo_v2_1_18
vlib modelsim_lib/msim/axi_register_slice_v2_1_19
vlib modelsim_lib/msim/axi_protocol_converter_v2_1_19
vlib modelsim_lib/msim/axi_clock_converter_v2_1_18
vlib modelsim_lib/msim/blk_mem_gen_v8_4_3
vlib modelsim_lib/msim/axi_dwidth_converter_v2_1_19
vlib modelsim_lib/msim/xbip_utils_v3_0_10
vlib modelsim_lib/msim/axi_utils_v2_0_6
vlib modelsim_lib/msim/xbip_pipe_v3_0_6
vlib modelsim_lib/msim/xbip_dsp48_wrapper_v3_0_4
vlib modelsim_lib/msim/xbip_dsp48_addsub_v3_0_6
vlib modelsim_lib/msim/xbip_dsp48_multadd_v3_0_6
vlib modelsim_lib/msim/xbip_bram18k_v3_0_6
vlib modelsim_lib/msim/mult_gen_v12_0_15
vlib modelsim_lib/msim/floating_point_v7_1_8

vmap xilinx_vip modelsim_lib/msim/xilinx_vip
vmap xil_defaultlib modelsim_lib/msim/xil_defaultlib
vmap xpm modelsim_lib/msim/xpm
vmap axi_infrastructure_v1_1_0 modelsim_lib/msim/axi_infrastructure_v1_1_0
vmap axi_vip_v1_1_5 modelsim_lib/msim/axi_vip_v1_1_5
vmap zynq_ultra_ps_e_vip_v1_0_5 modelsim_lib/msim/zynq_ultra_ps_e_vip_v1_0_5
vmap xlconstant_v1_1_6 modelsim_lib/msim/xlconstant_v1_1_6
vmap lib_cdc_v1_0_2 modelsim_lib/msim/lib_cdc_v1_0_2
vmap proc_sys_reset_v5_0_13 modelsim_lib/msim/proc_sys_reset_v5_0_13
vmap smartconnect_v1_0 modelsim_lib/msim/smartconnect_v1_0
vmap generic_baseblocks_v2_1_0 modelsim_lib/msim/generic_baseblocks_v2_1_0
vmap fifo_generator_v13_2_4 modelsim_lib/msim/fifo_generator_v13_2_4
vmap axi_data_fifo_v2_1_18 modelsim_lib/msim/axi_data_fifo_v2_1_18
vmap axi_register_slice_v2_1_19 modelsim_lib/msim/axi_register_slice_v2_1_19
vmap axi_protocol_converter_v2_1_19 modelsim_lib/msim/axi_protocol_converter_v2_1_19
vmap axi_clock_converter_v2_1_18 modelsim_lib/msim/axi_clock_converter_v2_1_18
vmap blk_mem_gen_v8_4_3 modelsim_lib/msim/blk_mem_gen_v8_4_3
vmap axi_dwidth_converter_v2_1_19 modelsim_lib/msim/axi_dwidth_converter_v2_1_19
vmap xbip_utils_v3_0_10 modelsim_lib/msim/xbip_utils_v3_0_10
vmap axi_utils_v2_0_6 modelsim_lib/msim/axi_utils_v2_0_6
vmap xbip_pipe_v3_0_6 modelsim_lib/msim/xbip_pipe_v3_0_6
vmap xbip_dsp48_wrapper_v3_0_4 modelsim_lib/msim/xbip_dsp48_wrapper_v3_0_4
vmap xbip_dsp48_addsub_v3_0_6 modelsim_lib/msim/xbip_dsp48_addsub_v3_0_6
vmap xbip_dsp48_multadd_v3_0_6 modelsim_lib/msim/xbip_dsp48_multadd_v3_0_6
vmap xbip_bram18k_v3_0_6 modelsim_lib/msim/xbip_bram18k_v3_0_6
vmap mult_gen_v12_0_15 modelsim_lib/msim/mult_gen_v12_0_15
vmap floating_point_v7_1_8 modelsim_lib/msim/floating_point_v7_1_8

vlog -work xilinx_vip -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
"D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
"D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
"D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
"D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
"D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
"D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi_vip_if.sv" \
"D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/clk_vip_if.sv" \
"D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/rst_vip_if.sv" \

vlog -work xil_defaultlib -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"D:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
"D:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_fifo/hdl/xpm_fifo.sv" \
"D:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \

vcom -work xpm -64 -93 \
"D:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_VCOMP.vhd" \

vlog -work axi_infrastructure_v1_1_0 -64 -incr "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \

vlog -work axi_vip_v1_1_5 -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/d4a8/hdl/axi_vip_v1_1_vl_rfs.sv" \

vlog -work zynq_ultra_ps_e_vip_v1_0_5 -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl/zynq_ultra_ps_e_vip_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -incr "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim/forw_back_zynq_ultra_ps_e_0_0_vip_wrapper.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/sim/forw_back.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/sim/bd_698c.v" \

vlog -work xlconstant_v1_1_6 -64 -incr "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/66e7/hdl/xlconstant_v1_1_vl_rfs.v" \

vlog -work xil_defaultlib -64 -incr "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_0/sim/bd_698c_one_0.v" \

vcom -work lib_cdc_v1_0_2 -64 -93 \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \

vcom -work proc_sys_reset_v5_0_13 -64 -93 \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \

vcom -work xil_defaultlib -64 -93 \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_1/sim/bd_698c_psr_aclk_0.vhd" \

vlog -work smartconnect_v1_0 -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/sc_util_v1_0_vl_rfs.sv" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/f85e/hdl/sc_mmu_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_2/sim/bd_698c_s00mmu_0.sv" \

vlog -work smartconnect_v1_0 -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ca72/hdl/sc_transaction_regulator_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_3/sim/bd_698c_s00tr_0.sv" \

vlog -work smartconnect_v1_0 -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/7de4/hdl/sc_si_converter_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_4/sim/bd_698c_s00sic_0.sv" \

vlog -work smartconnect_v1_0 -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b89e/hdl/sc_axi2sc_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_5/sim/bd_698c_s00a2s_0.sv" \

vlog -work smartconnect_v1_0 -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/sc_node_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_6/sim/bd_698c_sarn_0.sv" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_7/sim/bd_698c_srn_0.sv" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_8/sim/bd_698c_sawn_0.sv" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_9/sim/bd_698c_swn_0.sv" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_10/sim/bd_698c_sbn_0.sv" \

vlog -work smartconnect_v1_0 -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/7005/hdl/sc_sc2axi_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_11/sim/bd_698c_m00s2a_0.sv" \

vlog -work smartconnect_v1_0 -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b387/hdl/sc_exit_v1_0_vl_rfs.sv" \

vlog -work xil_defaultlib -64 -incr -sv -L axi_vip_v1_1_5 -L zynq_ultra_ps_e_vip_v1_0_5 -L smartconnect_v1_0 -L xilinx_vip "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_12/sim/bd_698c_m00e_0.sv" \

vlog -work xil_defaultlib -64 -incr "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/sim/forw_back_axi_smc_7.v" \

vcom -work xil_defaultlib -64 -93 \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_rst_ps8_0_100M_7/sim/forw_back_rst_ps8_0_100M_7.vhd" \

vlog -work generic_baseblocks_v2_1_0 -64 -incr "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \

vlog -work fifo_generator_v13_2_4 -64 -incr "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1f5a/simulation/fifo_generator_vlog_beh.v" \

vcom -work fifo_generator_v13_2_4 -64 -93 \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1f5a/hdl/fifo_generator_v13_2_rfs.vhd" \

vlog -work fifo_generator_v13_2_4 -64 -incr "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1f5a/hdl/fifo_generator_v13_2_rfs.v" \

vlog -work axi_data_fifo_v2_1_18 -64 -incr "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/5b9c/hdl/axi_data_fifo_v2_1_vl_rfs.v" \

vlog -work axi_register_slice_v2_1_19 -64 -incr "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/4d88/hdl/axi_register_slice_v2_1_vl_rfs.v" \

vlog -work axi_protocol_converter_v2_1_19 -64 -incr "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/c83a/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \

vlog -work axi_clock_converter_v2_1_18 -64 -incr "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ac9d/hdl/axi_clock_converter_v2_1_vl_rfs.v" \

vlog -work blk_mem_gen_v8_4_3 -64 -incr "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/c001/simulation/blk_mem_gen_v8_4.v" \

vlog -work axi_dwidth_converter_v2_1_19 -64 -incr "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/e578/hdl/axi_dwidth_converter_v2_1_vl_rfs.v" \

vlog -work xil_defaultlib -64 -incr "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_auto_ds_0/sim/forw_back_auto_ds_0.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_auto_pc_0/sim/forw_back_auto_pc_0.v" \

vcom -work xbip_utils_v3_0_10 -64 -93 \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1123/hdl/xbip_utils_v3_0_vh_rfs.vhd" \

vcom -work axi_utils_v2_0_6 -64 -93 \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1971/hdl/axi_utils_v2_0_vh_rfs.vhd" \

vcom -work xbip_pipe_v3_0_6 -64 -93 \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/7468/hdl/xbip_pipe_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_wrapper_v3_0_4 -64 -93 \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cdbf/hdl/xbip_dsp48_wrapper_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_addsub_v3_0_6 -64 -93 \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/910d/hdl/xbip_dsp48_addsub_v3_0_vh_rfs.vhd" \

vcom -work xbip_dsp48_multadd_v3_0_6 -64 -93 \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b0ac/hdl/xbip_dsp48_multadd_v3_0_vh_rfs.vhd" \

vcom -work xbip_bram18k_v3_0_6 -64 -93 \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/d367/hdl/xbip_bram18k_v3_0_vh_rfs.vhd" \

vcom -work mult_gen_v12_0_15 -64 -93 \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/d4d2/hdl/mult_gen_v12_0_vh_rfs.vhd" \

vcom -work floating_point_v7_1_8 -64 -93 \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/83a3/hdl/floating_point_v7_1_vh_rfs.vhd" \

vlog -work xil_defaultlib -64 -incr "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/verilog" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim_tlm" "+incdir+../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0" "+incdir+D:/Xilinx/Vivado/2019.1/data/xilinx_vip/include" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/backward.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/backward_conv_grancg.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/backward_conv_grapcA.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/backward_conv_grasc4.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/backward_grad_0.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/backward_grad_2.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/backward_kernel_gocq.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/backward_pool_grarcU.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/backward_rgrad_1.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/backward_wgrad_1.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/backward_wgrad_2.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/Conv2d.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/Conv2d_1.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/Conv2d_2.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/Conv2d_3.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/Conv2d_4.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_conv_kevdy.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_ctrl_s_axi.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_dadd_64ibs.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_data_m_axi.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_ddiv_64kbM.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_dexp_64lbW.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_dmul_64jbC.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_fadd_32bkb.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_faddfsuudo.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_fc_hiddxdS.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_fc_hiddyd2.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_fc_in_1_0.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_fc_out_DeQ.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_fcmp_32eOg.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_fmul_32cud.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_fpext_3hbi.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_fptruncg8j.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_fsub_32mb6.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_max_pooAem.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_max_pooCeG.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_mnist_dzec.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back_sitofp_dEe.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forward.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forward_conv_out_1.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forward_conv_out_2.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forward_fc_out_2_0.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forward_max_poo_ofYi.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/MatrixBackPropagatio.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/MaxPooBackPropagatio.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/MaxPooBackPropagatio_1.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/MaxPool2d.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/MaxPool2d_1.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/Padding.v" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/verilog/forw_back.v" \

vcom -work xil_defaultlib -64 -93 \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/ip/forw_back_ap_dadd_3_full_dsp_64.vhd" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/ip/forw_back_ap_ddiv_20_no_dsp_64.vhd" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/ip/forw_back_ap_dexp_11_full_dsp_64.vhd" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/ip/forw_back_ap_dmul_3_max_dsp_64.vhd" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/ip/forw_back_ap_faddfsub_2_full_dsp_32.vhd" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/ip/forw_back_ap_fadd_2_full_dsp_32.vhd" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/ip/forw_back_ap_fcmp_0_no_dsp_32.vhd" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/ip/forw_back_ap_fmul_1_max_dsp_32.vhd" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/ip/forw_back_ap_fpext_0_no_dsp_32.vhd" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/ip/forw_back_ap_fptrunc_0_no_dsp_64.vhd" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/ip/forw_back_ap_fsub_2_full_dsp_32.vhd" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/03fb/hdl/ip/forw_back_ap_sitofp_2_no_dsp_32.vhd" \
"../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_forw_back_0_15/sim/forw_back_forw_back_0_15.vhd" \

vlog -work xil_defaultlib \
"glbl.v"

