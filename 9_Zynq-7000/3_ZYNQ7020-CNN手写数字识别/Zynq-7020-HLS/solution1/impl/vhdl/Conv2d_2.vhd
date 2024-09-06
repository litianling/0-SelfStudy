-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2019.1
-- Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity Conv2d_2 is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    kernel_address0 : OUT STD_LOGIC_VECTOR (7 downto 0);
    kernel_ce0 : OUT STD_LOGIC;
    kernel_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
    out_matrix_address0 : OUT STD_LOGIC_VECTOR (3 downto 0);
    out_matrix_ce0 : OUT STD_LOGIC;
    out_matrix_we0 : OUT STD_LOGIC;
    out_matrix_d0 : OUT STD_LOGIC_VECTOR (31 downto 0);
    max_poo_out_1_address0 : OUT STD_LOGIC_VECTOR (7 downto 0);
    max_poo_out_1_ce0 : OUT STD_LOGIC;
    max_poo_out_1_q0 : IN STD_LOGIC_VECTOR (31 downto 0) );
end;


architecture behav of Conv2d_2 is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (15 downto 0) := "0000000000000001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (15 downto 0) := "0000000000000010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (15 downto 0) := "0000000000000100";
    constant ap_ST_fsm_state4 : STD_LOGIC_VECTOR (15 downto 0) := "0000000000001000";
    constant ap_ST_fsm_state5 : STD_LOGIC_VECTOR (15 downto 0) := "0000000000010000";
    constant ap_ST_fsm_state6 : STD_LOGIC_VECTOR (15 downto 0) := "0000000000100000";
    constant ap_ST_fsm_state7 : STD_LOGIC_VECTOR (15 downto 0) := "0000000001000000";
    constant ap_ST_fsm_state8 : STD_LOGIC_VECTOR (15 downto 0) := "0000000010000000";
    constant ap_ST_fsm_state9 : STD_LOGIC_VECTOR (15 downto 0) := "0000000100000000";
    constant ap_ST_fsm_state10 : STD_LOGIC_VECTOR (15 downto 0) := "0000001000000000";
    constant ap_ST_fsm_state11 : STD_LOGIC_VECTOR (15 downto 0) := "0000010000000000";
    constant ap_ST_fsm_state12 : STD_LOGIC_VECTOR (15 downto 0) := "0000100000000000";
    constant ap_ST_fsm_state13 : STD_LOGIC_VECTOR (15 downto 0) := "0001000000000000";
    constant ap_ST_fsm_state14 : STD_LOGIC_VECTOR (15 downto 0) := "0010000000000000";
    constant ap_ST_fsm_state15 : STD_LOGIC_VECTOR (15 downto 0) := "0100000000000000";
    constant ap_ST_fsm_state16 : STD_LOGIC_VECTOR (15 downto 0) := "1000000000000000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";
    constant ap_const_lv32_5 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000101";
    constant ap_const_lv32_9 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001001";
    constant ap_const_lv32_E : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001110";
    constant ap_const_lv3_3 : STD_LOGIC_VECTOR (2 downto 0) := "011";
    constant ap_const_lv2_0 : STD_LOGIC_VECTOR (1 downto 0) := "00";
    constant ap_const_lv32_F : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001111";
    constant ap_const_lv32_A : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001010";
    constant ap_const_lv32_6 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000110";
    constant ap_const_lv3_6 : STD_LOGIC_VECTOR (2 downto 0) := "110";
    constant ap_const_lv2_1 : STD_LOGIC_VECTOR (1 downto 0) := "01";
    constant ap_const_lv3_1 : STD_LOGIC_VECTOR (2 downto 0) := "001";
    constant ap_const_lv4_0 : STD_LOGIC_VECTOR (3 downto 0) := "0000";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal ap_CS_fsm : STD_LOGIC_VECTOR (15 downto 0) := "0000000000000001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal col_cast6_fu_186_p1 : STD_LOGIC_VECTOR (2 downto 0);
    signal col_cast6_reg_400 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal col_cast_fu_194_p1 : STD_LOGIC_VECTOR (3 downto 0);
    signal col_cast_reg_405 : STD_LOGIC_VECTOR (3 downto 0);
    signal i_fu_204_p2 : STD_LOGIC_VECTOR (1 downto 0);
    signal i_reg_413 : STD_LOGIC_VECTOR (1 downto 0);
    signal sub_ln30_fu_222_p2 : STD_LOGIC_VECTOR (4 downto 0);
    signal sub_ln30_reg_418 : STD_LOGIC_VECTOR (4 downto 0);
    signal icmp_ln28_fu_198_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal zext_ln32_5_fu_232_p1 : STD_LOGIC_VECTOR (2 downto 0);
    signal zext_ln32_5_reg_423 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_CS_fsm_state3 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state3 : signal is "none";
    signal zext_ln32_6_fu_236_p1 : STD_LOGIC_VECTOR (7 downto 0);
    signal zext_ln32_6_reg_428 : STD_LOGIC_VECTOR (7 downto 0);
    signal j_fu_246_p2 : STD_LOGIC_VECTOR (1 downto 0);
    signal j_reg_436 : STD_LOGIC_VECTOR (1 downto 0);
    signal out_matrix_addr_reg_441 : STD_LOGIC_VECTOR (3 downto 0);
    signal icmp_ln29_fu_240_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal add_ln28_fu_266_p2 : STD_LOGIC_VECTOR (2 downto 0);
    signal sub_ln33_6_fu_306_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal sub_ln33_6_reg_454 : STD_LOGIC_VECTOR (7 downto 0);
    signal ap_CS_fsm_state4 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state4 : signal is "none";
    signal icmp_ln31_fu_276_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal sub_ln33_3_fu_343_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal sub_ln33_3_reg_459 : STD_LOGIC_VECTOR (7 downto 0);
    signal add_ln29_fu_348_p2 : STD_LOGIC_VECTOR (2 downto 0);
    signal ap_CS_fsm_state5 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state5 : signal is "none";
    signal icmp_ln32_fu_358_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal row_5_fu_388_p2 : STD_LOGIC_VECTOR (2 downto 0);
    signal row_5_reg_482 : STD_LOGIC_VECTOR (2 downto 0);
    signal col_5_fu_394_p2 : STD_LOGIC_VECTOR (2 downto 0);
    signal max_poo_out_1_load_reg_492 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_CS_fsm_state6 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state6 : signal is "none";
    signal kernel_load_reg_497 : STD_LOGIC_VECTOR (31 downto 0);
    signal grp_fu_182_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_reg_502 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_CS_fsm_state10 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state10 : signal is "none";
    signal grp_fu_177_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_s_reg_507 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_CS_fsm_state15 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state15 : signal is "none";
    signal indvars_iv5_reg_88 : STD_LOGIC_VECTOR (2 downto 0);
    signal col_reg_100 : STD_LOGIC_VECTOR (1 downto 0);
    signal indvars_iv_reg_111 : STD_LOGIC_VECTOR (2 downto 0);
    signal row_reg_123 : STD_LOGIC_VECTOR (1 downto 0);
    signal empty_152_reg_134 : STD_LOGIC_VECTOR (31 downto 0);
    signal col_0_reg_146 : STD_LOGIC_VECTOR (2 downto 0);
    signal empty_154_reg_156 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_CS_fsm_state16 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state16 : signal is "none";
    signal row_0_reg_168 : STD_LOGIC_VECTOR (2 downto 0);
    signal zext_ln30_fu_261_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal zext_ln33_fu_373_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal sext_ln33_1_fu_383_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal ap_CS_fsm_state11 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state11 : signal is "none";
    signal ap_CS_fsm_state7 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state7 : signal is "none";
    signal shl_ln_fu_210_p3 : STD_LOGIC_VECTOR (3 downto 0);
    signal zext_ln30_5_fu_218_p1 : STD_LOGIC_VECTOR (4 downto 0);
    signal col_cast5_fu_190_p1 : STD_LOGIC_VECTOR (4 downto 0);
    signal zext_ln32_fu_228_p1 : STD_LOGIC_VECTOR (4 downto 0);
    signal add_ln30_fu_252_p2 : STD_LOGIC_VECTOR (4 downto 0);
    signal sext_ln30_fu_257_p1 : STD_LOGIC_VECTOR (31 downto 0);
    signal shl_ln1_fu_282_p3 : STD_LOGIC_VECTOR (6 downto 0);
    signal shl_ln33_5_fu_294_p3 : STD_LOGIC_VECTOR (3 downto 0);
    signal zext_ln33_1_fu_290_p1 : STD_LOGIC_VECTOR (7 downto 0);
    signal zext_ln33_2_fu_302_p1 : STD_LOGIC_VECTOR (7 downto 0);
    signal col_0_cast2_fu_272_p1 : STD_LOGIC_VECTOR (3 downto 0);
    signal sub_ln33_fu_312_p2 : STD_LOGIC_VECTOR (3 downto 0);
    signal shl_ln33_7_fu_325_p3 : STD_LOGIC_VECTOR (5 downto 0);
    signal shl_ln33_6_fu_317_p3 : STD_LOGIC_VECTOR (7 downto 0);
    signal sext_ln33_fu_333_p1 : STD_LOGIC_VECTOR (7 downto 0);
    signal sub_ln33_7_fu_337_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal row_0_cast_fu_354_p1 : STD_LOGIC_VECTOR (7 downto 0);
    signal add_ln33_fu_364_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal sext_ln33_2_fu_369_p1 : STD_LOGIC_VECTOR (31 downto 0);
    signal add_ln33_2_fu_378_p2 : STD_LOGIC_VECTOR (7 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (15 downto 0);

    component forw_back_fadd_32bkb IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        din0 : IN STD_LOGIC_VECTOR (31 downto 0);
        din1 : IN STD_LOGIC_VECTOR (31 downto 0);
        ce : IN STD_LOGIC;
        dout : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;


    component forw_back_fmul_32cud IS
    generic (
        ID : INTEGER;
        NUM_STAGE : INTEGER;
        din0_WIDTH : INTEGER;
        din1_WIDTH : INTEGER;
        dout_WIDTH : INTEGER );
    port (
        clk : IN STD_LOGIC;
        reset : IN STD_LOGIC;
        din0 : IN STD_LOGIC_VECTOR (31 downto 0);
        din1 : IN STD_LOGIC_VECTOR (31 downto 0);
        ce : IN STD_LOGIC;
        dout : OUT STD_LOGIC_VECTOR (31 downto 0) );
    end component;



begin
    forw_back_fadd_32bkb_U59 : component forw_back_fadd_32bkb
    generic map (
        ID => 1,
        NUM_STAGE => 5,
        din0_WIDTH => 32,
        din1_WIDTH => 32,
        dout_WIDTH => 32)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        din0 => empty_154_reg_156,
        din1 => tmp_reg_502,
        ce => ap_const_logic_1,
        dout => grp_fu_177_p2);

    forw_back_fmul_32cud_U60 : component forw_back_fmul_32cud
    generic map (
        ID => 1,
        NUM_STAGE => 4,
        din0_WIDTH => 32,
        din1_WIDTH => 32,
        dout_WIDTH => 32)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        din0 => max_poo_out_1_load_reg_492,
        din1 => kernel_load_reg_497,
        ce => ap_const_logic_1,
        dout => grp_fu_182_p2);





    ap_CS_fsm_assign_proc : process(ap_clk)
    begin
        if (ap_clk'event and ap_clk =  '1') then
            if (ap_rst = '1') then
                ap_CS_fsm <= ap_ST_fsm_state1;
            else
                ap_CS_fsm <= ap_NS_fsm;
            end if;
        end if;
    end process;


    col_0_reg_146_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln32_fu_358_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state5))) then 
                col_0_reg_146 <= col_5_fu_394_p2;
            elsif (((icmp_ln29_fu_240_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                col_0_reg_146 <= col_cast6_reg_400;
            end if; 
        end if;
    end process;

    col_reg_100_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_start = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
                col_reg_100 <= ap_const_lv2_0;
            elsif (((icmp_ln29_fu_240_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                col_reg_100 <= i_reg_413;
            end if; 
        end if;
    end process;

    empty_152_reg_134_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln32_fu_358_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state5))) then 
                empty_152_reg_134 <= empty_154_reg_156;
            elsif (((icmp_ln29_fu_240_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                empty_152_reg_134 <= ap_const_lv32_0;
            end if; 
        end if;
    end process;

    empty_154_reg_156_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln31_fu_276_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state4))) then 
                empty_154_reg_156 <= empty_152_reg_134;
            elsif ((ap_const_logic_1 = ap_CS_fsm_state16)) then 
                empty_154_reg_156 <= tmp_s_reg_507;
            end if; 
        end if;
    end process;

    indvars_iv5_reg_88_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((ap_start = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
                indvars_iv5_reg_88 <= ap_const_lv3_3;
            elsif (((icmp_ln29_fu_240_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                indvars_iv5_reg_88 <= add_ln28_fu_266_p2;
            end if; 
        end if;
    end process;

    indvars_iv_reg_111_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln28_fu_198_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
                indvars_iv_reg_111 <= ap_const_lv3_3;
            elsif (((icmp_ln31_fu_276_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state4))) then 
                indvars_iv_reg_111 <= add_ln29_fu_348_p2;
            end if; 
        end if;
    end process;

    row_0_reg_168_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln31_fu_276_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state4))) then 
                row_0_reg_168 <= zext_ln32_5_reg_423;
            elsif ((ap_const_logic_1 = ap_CS_fsm_state16)) then 
                row_0_reg_168 <= row_5_reg_482;
            end if; 
        end if;
    end process;

    row_reg_123_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln28_fu_198_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
                row_reg_123 <= ap_const_lv2_0;
            elsif (((icmp_ln31_fu_276_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state4))) then 
                row_reg_123 <= j_reg_436;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state2)) then
                    col_cast6_reg_400(1 downto 0) <= col_cast6_fu_186_p1(1 downto 0);
                    col_cast_reg_405(1 downto 0) <= col_cast_fu_194_p1(1 downto 0);
                i_reg_413 <= i_fu_204_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state3)) then
                j_reg_436 <= j_fu_246_p2;
                    zext_ln32_5_reg_423(1 downto 0) <= zext_ln32_5_fu_232_p1(1 downto 0);
                    zext_ln32_6_reg_428(1 downto 0) <= zext_ln32_6_fu_236_p1(1 downto 0);
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state6)) then
                kernel_load_reg_497 <= kernel_q0;
                max_poo_out_1_load_reg_492 <= max_poo_out_1_q0;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln29_fu_240_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3))) then
                out_matrix_addr_reg_441 <= zext_ln30_fu_261_p1(4 - 1 downto 0);
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln32_fu_358_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state5))) then
                row_5_reg_482 <= row_5_fu_388_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln28_fu_198_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                sub_ln30_reg_418 <= sub_ln30_fu_222_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln31_fu_276_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state4))) then
                sub_ln33_3_reg_459 <= sub_ln33_3_fu_343_p2;
                    sub_ln33_6_reg_454(7 downto 1) <= sub_ln33_6_fu_306_p2(7 downto 1);
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state10)) then
                tmp_reg_502 <= grp_fu_182_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state15)) then
                tmp_s_reg_507 <= grp_fu_177_p2;
            end if;
        end if;
    end process;
    col_cast6_reg_400(2) <= '0';
    col_cast_reg_405(3 downto 2) <= "00";
    zext_ln32_5_reg_423(2) <= '0';
    zext_ln32_6_reg_428(7 downto 2) <= "000000";
    sub_ln33_6_reg_454(0) <= '0';

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, ap_CS_fsm_state2, icmp_ln28_fu_198_p2, ap_CS_fsm_state3, icmp_ln29_fu_240_p2, ap_CS_fsm_state4, icmp_ln31_fu_276_p2, ap_CS_fsm_state5, icmp_ln32_fu_358_p2)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_start = ap_const_logic_1) and (ap_const_logic_1 = ap_CS_fsm_state1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((icmp_ln28_fu_198_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state3;
                end if;
            when ap_ST_fsm_state3 => 
                if (((icmp_ln29_fu_240_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state4;
                end if;
            when ap_ST_fsm_state4 => 
                if (((icmp_ln31_fu_276_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state4))) then
                    ap_NS_fsm <= ap_ST_fsm_state3;
                else
                    ap_NS_fsm <= ap_ST_fsm_state5;
                end if;
            when ap_ST_fsm_state5 => 
                if (((icmp_ln32_fu_358_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state5))) then
                    ap_NS_fsm <= ap_ST_fsm_state4;
                else
                    ap_NS_fsm <= ap_ST_fsm_state6;
                end if;
            when ap_ST_fsm_state6 => 
                ap_NS_fsm <= ap_ST_fsm_state7;
            when ap_ST_fsm_state7 => 
                ap_NS_fsm <= ap_ST_fsm_state8;
            when ap_ST_fsm_state8 => 
                ap_NS_fsm <= ap_ST_fsm_state9;
            when ap_ST_fsm_state9 => 
                ap_NS_fsm <= ap_ST_fsm_state10;
            when ap_ST_fsm_state10 => 
                ap_NS_fsm <= ap_ST_fsm_state11;
            when ap_ST_fsm_state11 => 
                ap_NS_fsm <= ap_ST_fsm_state12;
            when ap_ST_fsm_state12 => 
                ap_NS_fsm <= ap_ST_fsm_state13;
            when ap_ST_fsm_state13 => 
                ap_NS_fsm <= ap_ST_fsm_state14;
            when ap_ST_fsm_state14 => 
                ap_NS_fsm <= ap_ST_fsm_state15;
            when ap_ST_fsm_state15 => 
                ap_NS_fsm <= ap_ST_fsm_state16;
            when ap_ST_fsm_state16 => 
                ap_NS_fsm <= ap_ST_fsm_state5;
            when others =>  
                ap_NS_fsm <= "XXXXXXXXXXXXXXXX";
        end case;
    end process;
    add_ln28_fu_266_p2 <= std_logic_vector(unsigned(indvars_iv5_reg_88) + unsigned(ap_const_lv3_1));
    add_ln29_fu_348_p2 <= std_logic_vector(unsigned(indvars_iv_reg_111) + unsigned(ap_const_lv3_1));
    add_ln30_fu_252_p2 <= std_logic_vector(unsigned(sub_ln30_reg_418) + unsigned(zext_ln32_fu_228_p1));
    add_ln33_2_fu_378_p2 <= std_logic_vector(unsigned(row_0_cast_fu_354_p1) + unsigned(sub_ln33_3_reg_459));
    add_ln33_fu_364_p2 <= std_logic_vector(unsigned(sub_ln33_6_reg_454) + unsigned(row_0_cast_fu_354_p1));
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state10 <= ap_CS_fsm(9);
    ap_CS_fsm_state11 <= ap_CS_fsm(10);
    ap_CS_fsm_state15 <= ap_CS_fsm(14);
    ap_CS_fsm_state16 <= ap_CS_fsm(15);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);
    ap_CS_fsm_state3 <= ap_CS_fsm(2);
    ap_CS_fsm_state4 <= ap_CS_fsm(3);
    ap_CS_fsm_state5 <= ap_CS_fsm(4);
    ap_CS_fsm_state6 <= ap_CS_fsm(5);
    ap_CS_fsm_state7 <= ap_CS_fsm(6);

    ap_done_assign_proc : process(ap_start, ap_CS_fsm_state1, ap_CS_fsm_state2, icmp_ln28_fu_198_p2)
    begin
        if ((((icmp_ln28_fu_198_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1)))) then 
            ap_done <= ap_const_logic_1;
        else 
            ap_done <= ap_const_logic_0;
        end if; 
    end process;


    ap_idle_assign_proc : process(ap_start, ap_CS_fsm_state1)
    begin
        if (((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1))) then 
            ap_idle <= ap_const_logic_1;
        else 
            ap_idle <= ap_const_logic_0;
        end if; 
    end process;


    ap_ready_assign_proc : process(ap_CS_fsm_state2, icmp_ln28_fu_198_p2)
    begin
        if (((icmp_ln28_fu_198_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    col_0_cast2_fu_272_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(col_0_reg_146),4));
    col_5_fu_394_p2 <= std_logic_vector(unsigned(col_0_reg_146) + unsigned(ap_const_lv3_1));
    col_cast5_fu_190_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(col_reg_100),5));
    col_cast6_fu_186_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(col_reg_100),3));
    col_cast_fu_194_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(col_reg_100),4));
    i_fu_204_p2 <= std_logic_vector(unsigned(col_reg_100) + unsigned(ap_const_lv2_1));
    icmp_ln28_fu_198_p2 <= "1" when (indvars_iv5_reg_88 = ap_const_lv3_6) else "0";
    icmp_ln29_fu_240_p2 <= "1" when (indvars_iv_reg_111 = ap_const_lv3_6) else "0";
    icmp_ln31_fu_276_p2 <= "1" when (col_0_reg_146 = indvars_iv5_reg_88) else "0";
    icmp_ln32_fu_358_p2 <= "1" when (row_0_reg_168 = indvars_iv_reg_111) else "0";
    j_fu_246_p2 <= std_logic_vector(unsigned(row_reg_123) + unsigned(ap_const_lv2_1));
    kernel_address0 <= sext_ln33_1_fu_383_p1(8 - 1 downto 0);

    kernel_ce0_assign_proc : process(ap_CS_fsm_state5)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            kernel_ce0 <= ap_const_logic_1;
        else 
            kernel_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    max_poo_out_1_address0 <= zext_ln33_fu_373_p1(8 - 1 downto 0);

    max_poo_out_1_ce0_assign_proc : process(ap_CS_fsm_state5)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state5)) then 
            max_poo_out_1_ce0 <= ap_const_logic_1;
        else 
            max_poo_out_1_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    out_matrix_address0_assign_proc : process(ap_CS_fsm_state3, out_matrix_addr_reg_441, ap_CS_fsm_state16, zext_ln30_fu_261_p1)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state16)) then 
            out_matrix_address0 <= out_matrix_addr_reg_441;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state3)) then 
            out_matrix_address0 <= zext_ln30_fu_261_p1(4 - 1 downto 0);
        else 
            out_matrix_address0 <= "XXXX";
        end if; 
    end process;


    out_matrix_ce0_assign_proc : process(ap_CS_fsm_state3, ap_CS_fsm_state16)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state3) or (ap_const_logic_1 = ap_CS_fsm_state16))) then 
            out_matrix_ce0 <= ap_const_logic_1;
        else 
            out_matrix_ce0 <= ap_const_logic_0;
        end if; 
    end process;


    out_matrix_d0_assign_proc : process(ap_CS_fsm_state3, tmp_s_reg_507, ap_CS_fsm_state16)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state16)) then 
            out_matrix_d0 <= tmp_s_reg_507;
        elsif ((ap_const_logic_1 = ap_CS_fsm_state3)) then 
            out_matrix_d0 <= ap_const_lv32_0;
        else 
            out_matrix_d0 <= "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
        end if; 
    end process;


    out_matrix_we0_assign_proc : process(ap_CS_fsm_state3, icmp_ln29_fu_240_p2, ap_CS_fsm_state16)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state16) or ((icmp_ln29_fu_240_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3)))) then 
            out_matrix_we0 <= ap_const_logic_1;
        else 
            out_matrix_we0 <= ap_const_logic_0;
        end if; 
    end process;

    row_0_cast_fu_354_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(row_0_reg_168),8));
    row_5_fu_388_p2 <= std_logic_vector(unsigned(row_0_reg_168) + unsigned(ap_const_lv3_1));
        sext_ln30_fu_257_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(add_ln30_fu_252_p2),32));

        sext_ln33_1_fu_383_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(add_ln33_2_fu_378_p2),64));

        sext_ln33_2_fu_369_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(add_ln33_fu_364_p2),32));

        sext_ln33_fu_333_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(shl_ln33_7_fu_325_p3),8));

    shl_ln1_fu_282_p3 <= (col_0_reg_146 & ap_const_lv4_0);
    shl_ln33_5_fu_294_p3 <= (col_0_reg_146 & ap_const_lv1_0);
    shl_ln33_6_fu_317_p3 <= (sub_ln33_fu_312_p2 & ap_const_lv4_0);
    shl_ln33_7_fu_325_p3 <= (sub_ln33_fu_312_p2 & ap_const_lv2_0);
    shl_ln_fu_210_p3 <= (col_reg_100 & ap_const_lv2_0);
    sub_ln30_fu_222_p2 <= std_logic_vector(unsigned(zext_ln30_5_fu_218_p1) - unsigned(col_cast5_fu_190_p1));
    sub_ln33_3_fu_343_p2 <= std_logic_vector(unsigned(sub_ln33_7_fu_337_p2) - unsigned(zext_ln32_6_reg_428));
    sub_ln33_6_fu_306_p2 <= std_logic_vector(unsigned(zext_ln33_1_fu_290_p1) - unsigned(zext_ln33_2_fu_302_p1));
    sub_ln33_7_fu_337_p2 <= std_logic_vector(unsigned(shl_ln33_6_fu_317_p3) - unsigned(sext_ln33_fu_333_p1));
    sub_ln33_fu_312_p2 <= std_logic_vector(unsigned(col_0_cast2_fu_272_p1) - unsigned(col_cast_reg_405));
    zext_ln30_5_fu_218_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(shl_ln_fu_210_p3),5));
    zext_ln30_fu_261_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(sext_ln30_fu_257_p1),64));
    zext_ln32_5_fu_232_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(row_reg_123),3));
    zext_ln32_6_fu_236_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(row_reg_123),8));
    zext_ln32_fu_228_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(row_reg_123),5));
    zext_ln33_1_fu_290_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(shl_ln1_fu_282_p3),8));
    zext_ln33_2_fu_302_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(shl_ln33_5_fu_294_p3),8));
    zext_ln33_fu_373_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(sext_ln33_2_fu_369_p1),64));
end behav;
