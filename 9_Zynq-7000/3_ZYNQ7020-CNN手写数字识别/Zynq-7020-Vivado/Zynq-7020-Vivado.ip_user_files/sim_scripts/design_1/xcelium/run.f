-makelib xcelium_lib/xilinx_vip -sv \
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
-makelib xcelium_lib/xil_defaultlib -sv \
  "D:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_cdc/hdl/xpm_cdc.sv" \
  "D:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_fifo/hdl/xpm_fifo.sv" \
  "D:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_memory/hdl/xpm_memory.sv" \
-endlib
-makelib xcelium_lib/xpm \
  "D:/Xilinx/Vivado/2019.1/data/ip/xpm/xpm_VCOMP.vhd" \
-endlib
-makelib xcelium_lib/axi_infrastructure_v1_1_0 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/ec67/hdl/axi_infrastructure_v1_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/axi_vip_v1_1_5 -sv \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/d4a8/hdl/axi_vip_v1_1_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/processing_system7_vip_v1_0_7 -sv \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/8c62/hdl/processing_system7_vip_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_processing_system7_0_0/sim/design_1_processing_system7_0_0.v" \
-endlib
-makelib xcelium_lib/xbip_utils_v3_0_10 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/1123/hdl/xbip_utils_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/axi_utils_v2_0_6 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/1971/hdl/axi_utils_v2_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xbip_pipe_v3_0_6 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/7468/hdl/xbip_pipe_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xbip_dsp48_wrapper_v3_0_4 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/cdbf/hdl/xbip_dsp48_wrapper_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xbip_dsp48_addsub_v3_0_6 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/910d/hdl/xbip_dsp48_addsub_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xbip_dsp48_multadd_v3_0_6 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/b0ac/hdl/xbip_dsp48_multadd_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xbip_bram18k_v3_0_6 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/d367/hdl/xbip_bram18k_v3_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/mult_gen_v12_0_15 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/d4d2/hdl/mult_gen_v12_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/floating_point_v7_1_8 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/83a3/hdl/floating_point_v7_1_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/backward.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/backward_conv_grancg.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/backward_conv_grapcA.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/backward_conv_grasc4.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/backward_grad_0.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/backward_grad_2.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/backward_kernel_gocq.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/backward_pool_grarcU.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/backward_rgrad_1.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/backward_wgrad_1.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/backward_wgrad_2.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/Conv2d.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/Conv2d_1.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/Conv2d_2.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/Conv2d_3.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/Conv2d_4.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_conv_kevdy.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_ctrl_s_axi.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_dadd_64ibs.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_data_m_axi.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_ddiv_64kbM.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_dexp_64lbW.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_dmul_64jbC.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_fadd_32bkb.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_faddfsuudo.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_fc_hiddxdS.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_fc_hiddyd2.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_fc_out_DeQ.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_fcmp_32eOg.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_fmul_32cud.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_fpext_3hbi.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_fptruncg8j.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_fsub_32mb6.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_max_pooAem.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_mnist_dzec.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back_sitofp_dEe.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forward.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forward_conv_out_1.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forward_conv_out_2.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forward_fc_out_2_0.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forward_max_poo_ofYi.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/MatrixBackPropagatio.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/MaxPooBackPropagatio.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/MaxPooBackPropagatio_1.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/MaxPool2d.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/MaxPool2d_1.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/Padding.v" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/verilog/forw_back.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/ip/forw_back_ap_dadd_3_full_dsp_64.vhd" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/ip/forw_back_ap_ddiv_29_no_dsp_64.vhd" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/ip/forw_back_ap_dexp_16_full_dsp_64.vhd" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/ip/forw_back_ap_dmul_4_max_dsp_64.vhd" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/ip/forw_back_ap_faddfsub_3_full_dsp_32.vhd" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/ip/forw_back_ap_fadd_3_full_dsp_32.vhd" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/ip/forw_back_ap_fcmp_0_no_dsp_32.vhd" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/ip/forw_back_ap_fmul_2_max_dsp_32.vhd" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/ip/forw_back_ap_fpext_0_no_dsp_32.vhd" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/ip/forw_back_ap_fptrunc_0_no_dsp_64.vhd" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/ip/forw_back_ap_fsub_3_full_dsp_32.vhd" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/0281/hdl/ip/forw_back_ap_sitofp_4_no_dsp_32.vhd" \
  "../../../bd/design_1/ip/design_1_forw_back_0_0/sim/design_1_forw_back_0_0.vhd" \
-endlib
-makelib xcelium_lib/xlconstant_v1_1_6 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/66e7/hdl/xlconstant_v1_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_axi_smc_0/bd_0/ip/ip_0/sim/bd_afc3_one_0.v" \
-endlib
-makelib xcelium_lib/lib_cdc_v1_0_2 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/ef1e/hdl/lib_cdc_v1_0_rfs.vhd" \
-endlib
-makelib xcelium_lib/proc_sys_reset_v5_0_13 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/8842/hdl/proc_sys_reset_v5_0_vh_rfs.vhd" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_axi_smc_0/bd_0/ip/ip_1/sim/bd_afc3_psr_aclk_0.vhd" \
-endlib
-makelib xcelium_lib/smartconnect_v1_0 -sv \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/1ddd/hdl/sc_util_v1_0_vl_rfs.sv" \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/f85e/hdl/sc_mmu_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib -sv \
  "../../../bd/design_1/ip/design_1_axi_smc_0/bd_0/ip/ip_2/sim/bd_afc3_s00mmu_0.sv" \
-endlib
-makelib xcelium_lib/smartconnect_v1_0 -sv \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/ca72/hdl/sc_transaction_regulator_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib -sv \
  "../../../bd/design_1/ip/design_1_axi_smc_0/bd_0/ip/ip_3/sim/bd_afc3_s00tr_0.sv" \
-endlib
-makelib xcelium_lib/smartconnect_v1_0 -sv \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/7de4/hdl/sc_si_converter_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib -sv \
  "../../../bd/design_1/ip/design_1_axi_smc_0/bd_0/ip/ip_4/sim/bd_afc3_s00sic_0.sv" \
-endlib
-makelib xcelium_lib/smartconnect_v1_0 -sv \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/b89e/hdl/sc_axi2sc_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib -sv \
  "../../../bd/design_1/ip/design_1_axi_smc_0/bd_0/ip/ip_5/sim/bd_afc3_s00a2s_0.sv" \
-endlib
-makelib xcelium_lib/smartconnect_v1_0 -sv \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/b2d0/hdl/sc_node_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib -sv \
  "../../../bd/design_1/ip/design_1_axi_smc_0/bd_0/ip/ip_6/sim/bd_afc3_sarn_0.sv" \
  "../../../bd/design_1/ip/design_1_axi_smc_0/bd_0/ip/ip_7/sim/bd_afc3_srn_0.sv" \
  "../../../bd/design_1/ip/design_1_axi_smc_0/bd_0/ip/ip_8/sim/bd_afc3_sawn_0.sv" \
  "../../../bd/design_1/ip/design_1_axi_smc_0/bd_0/ip/ip_9/sim/bd_afc3_swn_0.sv" \
  "../../../bd/design_1/ip/design_1_axi_smc_0/bd_0/ip/ip_10/sim/bd_afc3_sbn_0.sv" \
-endlib
-makelib xcelium_lib/smartconnect_v1_0 -sv \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/7005/hdl/sc_sc2axi_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib -sv \
  "../../../bd/design_1/ip/design_1_axi_smc_0/bd_0/ip/ip_11/sim/bd_afc3_m00s2a_0.sv" \
-endlib
-makelib xcelium_lib/smartconnect_v1_0 -sv \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/b387/hdl/sc_exit_v1_0_vl_rfs.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib -sv \
  "../../../bd/design_1/ip/design_1_axi_smc_0/bd_0/ip/ip_12/sim/bd_afc3_m00e_0.sv" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_axi_smc_0/bd_0/sim/bd_afc3.v" \
  "../../../bd/design_1/ip/design_1_axi_smc_0/sim/design_1_axi_smc_0.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_rst_ps7_0_50M_0/sim/design_1_rst_ps7_0_50M_0.vhd" \
-endlib
-makelib xcelium_lib/generic_baseblocks_v2_1_0 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/b752/hdl/generic_baseblocks_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/fifo_generator_v13_2_4 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/1f5a/simulation/fifo_generator_vlog_beh.v" \
-endlib
-makelib xcelium_lib/fifo_generator_v13_2_4 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/1f5a/hdl/fifo_generator_v13_2_rfs.vhd" \
-endlib
-makelib xcelium_lib/fifo_generator_v13_2_4 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/1f5a/hdl/fifo_generator_v13_2_rfs.v" \
-endlib
-makelib xcelium_lib/axi_data_fifo_v2_1_18 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/5b9c/hdl/axi_data_fifo_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/axi_register_slice_v2_1_19 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/4d88/hdl/axi_register_slice_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/axi_protocol_converter_v2_1_19 \
  "../../../../Zynq-7020-Vivado.srcs/sources_1/bd/design_1/ipshared/c83a/hdl/axi_protocol_converter_v2_1_vl_rfs.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  "../../../bd/design_1/ip/design_1_auto_pc_0/sim/design_1_auto_pc_0.v" \
  "../../../bd/design_1/sim/design_1.v" \
-endlib
-makelib xcelium_lib/xil_defaultlib \
  glbl.v
-endlib

