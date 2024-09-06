-makelib ies_lib/xilinx_vip -sv \
  "D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi4stream_vip_axi4streampc.sv" \
  "D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi_vip_axi4pc.sv" \
  "D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/xil_common_vip_pkg.sv" \
  "D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi4stream_vip_pkg.sv" \
  "D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi_vip_pkg.sv" \
  "D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi4stream_vip_if.sv" \
  "D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/axi_vip_if.sv" \
  "D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/clk_vip_if.sv" \
  "D:/Xilinx/Vivado/2019.1/data/xilinx_vip/hdl/rst_vip_if.sv" \
-endlib
-makelib ies_lib/xil_defaultlib -sv \
  "D:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
  "D:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_fifo/hdl/xpm_fifo.sv" \
  "D:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \
-endlib
-makelib ies_lib/xpm \
  "D:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_VCOMP.vhd" \
-endlib
-makelib ies_lib/axi_infrastructure_v1_1_0 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \
-endlib
-makelib ies_lib/axi_vip_v1_1_5 -sv \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/d4a8/hdl/axi_vip_v1_1_vl_rfs.sv" \
-endlib
-makelib ies_lib/zynq_ultra_ps_e_vip_v1_0_5 -sv \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cac7/hdl/zynq_ultra_ps_e_vip_v1_0_vl_rfs.sv" \
-endlib
-makelib ies_lib/xil_defaultlib \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_zynq_ultra_ps_e_0_0/sim/forw_back_zynq_ultra_ps_e_0_0_vip_wrapper.v" \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/sim/forw_back.v" \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/sim/bd_698c.v" \
-endlib
-makelib ies_lib/xlconstant_v1_1_6 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/66e7/hdl/xlconstant_v1_1_vl_rfs.v" \
-endlib
-makelib ies_lib/xil_defaultlib \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_0/sim/bd_698c_one_0.v" \
-endlib
-makelib ies_lib/lib_cdc_v1_0_2 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \
-endlib
-makelib ies_lib/proc_sys_reset_v5_0_13 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \
-endlib
-makelib ies_lib/xil_defaultlib \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_1/sim/bd_698c_psr_aclk_0.vhd" \
-endlib
-makelib ies_lib/smartconnect_v1_0 -sv \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1ddd/hdl/sc_util_v1_0_vl_rfs.sv" \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/f85e/hdl/sc_mmu_v1_0_vl_rfs.sv" \
-endlib
-makelib ies_lib/xil_defaultlib -sv \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_2/sim/bd_698c_s00mmu_0.sv" \
-endlib
-makelib ies_lib/smartconnect_v1_0 -sv \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ca72/hdl/sc_transaction_regulator_v1_0_vl_rfs.sv" \
-endlib
-makelib ies_lib/xil_defaultlib -sv \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_3/sim/bd_698c_s00tr_0.sv" \
-endlib
-makelib ies_lib/smartconnect_v1_0 -sv \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/7de4/hdl/sc_si_converter_v1_0_vl_rfs.sv" \
-endlib
-makelib ies_lib/xil_defaultlib -sv \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_4/sim/bd_698c_s00sic_0.sv" \
-endlib
-makelib ies_lib/smartconnect_v1_0 -sv \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b89e/hdl/sc_axi2sc_v1_0_vl_rfs.sv" \
-endlib
-makelib ies_lib/xil_defaultlib -sv \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_5/sim/bd_698c_s00a2s_0.sv" \
-endlib
-makelib ies_lib/smartconnect_v1_0 -sv \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b2d0/hdl/sc_node_v1_0_vl_rfs.sv" \
-endlib
-makelib ies_lib/xil_defaultlib -sv \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_6/sim/bd_698c_sarn_0.sv" \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_7/sim/bd_698c_srn_0.sv" \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_8/sim/bd_698c_sawn_0.sv" \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_9/sim/bd_698c_swn_0.sv" \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_10/sim/bd_698c_sbn_0.sv" \
-endlib
-makelib ies_lib/smartconnect_v1_0 -sv \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/7005/hdl/sc_sc2axi_v1_0_vl_rfs.sv" \
-endlib
-makelib ies_lib/xil_defaultlib -sv \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_11/sim/bd_698c_m00s2a_0.sv" \
-endlib
-makelib ies_lib/smartconnect_v1_0 -sv \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b387/hdl/sc_exit_v1_0_vl_rfs.sv" \
-endlib
-makelib ies_lib/xil_defaultlib -sv \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/bd_0/ip/ip_12/sim/bd_698c_m00e_0.sv" \
-endlib
-makelib ies_lib/xil_defaultlib \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_axi_smc_7/sim/forw_back_axi_smc_7.v" \
-endlib
-makelib ies_lib/xil_defaultlib \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_rst_ps8_0_100M_7/sim/forw_back_rst_ps8_0_100M_7.vhd" \
-endlib
-makelib ies_lib/generic_baseblocks_v2_1_0 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \
-endlib
-makelib ies_lib/fifo_generator_v13_2_4 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1f5a/simulation/fifo_generator_vlog_beh.v" \
-endlib
-makelib ies_lib/fifo_generator_v13_2_4 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1f5a/hdl/fifo_generator_v13_2_rfs.vhd" \
-endlib
-makelib ies_lib/fifo_generator_v13_2_4 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1f5a/hdl/fifo_generator_v13_2_rfs.v" \
-endlib
-makelib ies_lib/axi_data_fifo_v2_1_18 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/5b9c/hdl/axi_data_fifo_v2_1_vl_rfs.v" \
-endlib
-makelib ies_lib/axi_register_slice_v2_1_19 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/4d88/hdl/axi_register_slice_v2_1_vl_rfs.v" \
-endlib
-makelib ies_lib/axi_protocol_converter_v2_1_19 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/c83a/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \
-endlib
-makelib ies_lib/axi_clock_converter_v2_1_18 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/ac9d/hdl/axi_clock_converter_v2_1_vl_rfs.v" \
-endlib
-makelib ies_lib/blk_mem_gen_v8_4_3 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/c001/simulation/blk_mem_gen_v8_4.v" \
-endlib
-makelib ies_lib/axi_dwidth_converter_v2_1_19 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/e578/hdl/axi_dwidth_converter_v2_1_vl_rfs.v" \
-endlib
-makelib ies_lib/xil_defaultlib \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_auto_ds_0/sim/forw_back_auto_ds_0.v" \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ip/forw_back_auto_pc_0/sim/forw_back_auto_pc_0.v" \
-endlib
-makelib ies_lib/xbip_utils_v3_0_10 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1123/hdl/xbip_utils_v3_0_vh_rfs.vhd" \
-endlib
-makelib ies_lib/axi_utils_v2_0_6 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/1971/hdl/axi_utils_v2_0_vh_rfs.vhd" \
-endlib
-makelib ies_lib/xbip_pipe_v3_0_6 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/7468/hdl/xbip_pipe_v3_0_vh_rfs.vhd" \
-endlib
-makelib ies_lib/xbip_dsp48_wrapper_v3_0_4 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/cdbf/hdl/xbip_dsp48_wrapper_v3_0_vh_rfs.vhd" \
-endlib
-makelib ies_lib/xbip_dsp48_addsub_v3_0_6 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/910d/hdl/xbip_dsp48_addsub_v3_0_vh_rfs.vhd" \
-endlib
-makelib ies_lib/xbip_dsp48_multadd_v3_0_6 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/b0ac/hdl/xbip_dsp48_multadd_v3_0_vh_rfs.vhd" \
-endlib
-makelib ies_lib/xbip_bram18k_v3_0_6 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/d367/hdl/xbip_bram18k_v3_0_vh_rfs.vhd" \
-endlib
-makelib ies_lib/mult_gen_v12_0_15 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/d4d2/hdl/mult_gen_v12_0_vh_rfs.vhd" \
-endlib
-makelib ies_lib/floating_point_v7_1_8 \
  "../../../../forw_back.srcs/sources_1/bd/forw_back/ipshared/83a3/hdl/floating_point_v7_1_vh_rfs.vhd" \
-endlib
-makelib ies_lib/xil_defaultlib \
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
-endlib
-makelib ies_lib/xil_defaultlib \
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
-endlib
-makelib ies_lib/xil_defaultlib \
  glbl.v
-endlib

