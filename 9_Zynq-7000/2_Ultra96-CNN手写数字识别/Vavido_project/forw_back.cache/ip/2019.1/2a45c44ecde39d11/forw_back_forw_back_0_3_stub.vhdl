-- Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
-- Date        : Tue Oct 18 22:07:49 2022
-- Host        : DESKTOP-Q47CO10 running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode synth_stub -rename_top decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix -prefix
--               decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix_ forw_back_forw_back_0_3_stub.vhdl
-- Design      : forw_back_forw_back_0_3
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xczu3eg-sbva484-1-e
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
  Port ( 
    s_axi_ctrl_AWADDR : in STD_LOGIC_VECTOR ( 6 downto 0 );
    s_axi_ctrl_AWVALID : in STD_LOGIC;
    s_axi_ctrl_AWREADY : out STD_LOGIC;
    s_axi_ctrl_WDATA : in STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_ctrl_WSTRB : in STD_LOGIC_VECTOR ( 3 downto 0 );
    s_axi_ctrl_WVALID : in STD_LOGIC;
    s_axi_ctrl_WREADY : out STD_LOGIC;
    s_axi_ctrl_BRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_ctrl_BVALID : out STD_LOGIC;
    s_axi_ctrl_BREADY : in STD_LOGIC;
    s_axi_ctrl_ARADDR : in STD_LOGIC_VECTOR ( 6 downto 0 );
    s_axi_ctrl_ARVALID : in STD_LOGIC;
    s_axi_ctrl_ARREADY : out STD_LOGIC;
    s_axi_ctrl_RDATA : out STD_LOGIC_VECTOR ( 31 downto 0 );
    s_axi_ctrl_RRESP : out STD_LOGIC_VECTOR ( 1 downto 0 );
    s_axi_ctrl_RVALID : out STD_LOGIC;
    s_axi_ctrl_RREADY : in STD_LOGIC;
    ap_clk : in STD_LOGIC;
    ap_rst_n : in STD_LOGIC;
    interrupt : out STD_LOGIC;
    m_axi_data_AWADDR : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_data_AWLEN : out STD_LOGIC_VECTOR ( 7 downto 0 );
    m_axi_data_AWSIZE : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_data_AWBURST : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_data_AWLOCK : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_data_AWREGION : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_data_AWCACHE : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_data_AWPROT : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_data_AWQOS : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_data_AWVALID : out STD_LOGIC;
    m_axi_data_AWREADY : in STD_LOGIC;
    m_axi_data_WDATA : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_data_WSTRB : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_data_WLAST : out STD_LOGIC;
    m_axi_data_WVALID : out STD_LOGIC;
    m_axi_data_WREADY : in STD_LOGIC;
    m_axi_data_BRESP : in STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_data_BVALID : in STD_LOGIC;
    m_axi_data_BREADY : out STD_LOGIC;
    m_axi_data_ARADDR : out STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_data_ARLEN : out STD_LOGIC_VECTOR ( 7 downto 0 );
    m_axi_data_ARSIZE : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_data_ARBURST : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_data_ARLOCK : out STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_data_ARREGION : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_data_ARCACHE : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_data_ARPROT : out STD_LOGIC_VECTOR ( 2 downto 0 );
    m_axi_data_ARQOS : out STD_LOGIC_VECTOR ( 3 downto 0 );
    m_axi_data_ARVALID : out STD_LOGIC;
    m_axi_data_ARREADY : in STD_LOGIC;
    m_axi_data_RDATA : in STD_LOGIC_VECTOR ( 31 downto 0 );
    m_axi_data_RRESP : in STD_LOGIC_VECTOR ( 1 downto 0 );
    m_axi_data_RLAST : in STD_LOGIC;
    m_axi_data_RVALID : in STD_LOGIC;
    m_axi_data_RREADY : out STD_LOGIC
  );

end decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix;

architecture stub of decalper_eb_ot_sdeen_pot_pi_dehcac_xnilix is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "s_axi_ctrl_AWADDR[6:0],s_axi_ctrl_AWVALID,s_axi_ctrl_AWREADY,s_axi_ctrl_WDATA[31:0],s_axi_ctrl_WSTRB[3:0],s_axi_ctrl_WVALID,s_axi_ctrl_WREADY,s_axi_ctrl_BRESP[1:0],s_axi_ctrl_BVALID,s_axi_ctrl_BREADY,s_axi_ctrl_ARADDR[6:0],s_axi_ctrl_ARVALID,s_axi_ctrl_ARREADY,s_axi_ctrl_RDATA[31:0],s_axi_ctrl_RRESP[1:0],s_axi_ctrl_RVALID,s_axi_ctrl_RREADY,ap_clk,ap_rst_n,interrupt,m_axi_data_AWADDR[31:0],m_axi_data_AWLEN[7:0],m_axi_data_AWSIZE[2:0],m_axi_data_AWBURST[1:0],m_axi_data_AWLOCK[1:0],m_axi_data_AWREGION[3:0],m_axi_data_AWCACHE[3:0],m_axi_data_AWPROT[2:0],m_axi_data_AWQOS[3:0],m_axi_data_AWVALID,m_axi_data_AWREADY,m_axi_data_WDATA[31:0],m_axi_data_WSTRB[3:0],m_axi_data_WLAST,m_axi_data_WVALID,m_axi_data_WREADY,m_axi_data_BRESP[1:0],m_axi_data_BVALID,m_axi_data_BREADY,m_axi_data_ARADDR[31:0],m_axi_data_ARLEN[7:0],m_axi_data_ARSIZE[2:0],m_axi_data_ARBURST[1:0],m_axi_data_ARLOCK[1:0],m_axi_data_ARREGION[3:0],m_axi_data_ARCACHE[3:0],m_axi_data_ARPROT[2:0],m_axi_data_ARQOS[3:0],m_axi_data_ARVALID,m_axi_data_ARREADY,m_axi_data_RDATA[31:0],m_axi_data_RRESP[1:0],m_axi_data_RLAST,m_axi_data_RVALID,m_axi_data_RREADY";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "forw_back,Vivado 2019.1";
begin
end;
