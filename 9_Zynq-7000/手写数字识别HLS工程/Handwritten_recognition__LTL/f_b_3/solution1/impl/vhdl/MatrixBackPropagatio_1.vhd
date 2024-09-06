-- ==============================================================
-- RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
-- Version: 2019.1
-- Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
-- 
-- ===========================================================

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;

entity MatrixBackPropagatio_1 is
port (
    ap_clk : IN STD_LOGIC;
    ap_rst : IN STD_LOGIC;
    ap_start : IN STD_LOGIC;
    ap_done : OUT STD_LOGIC;
    ap_idle : OUT STD_LOGIC;
    ap_ready : OUT STD_LOGIC;
    input_matrix_address0 : OUT STD_LOGIC_VECTOR (3 downto 0);
    input_matrix_ce0 : OUT STD_LOGIC;
    input_matrix_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
    output_matrix_address0 : OUT STD_LOGIC_VECTOR (3 downto 0);
    output_matrix_ce0 : OUT STD_LOGIC;
    output_matrix_we0 : OUT STD_LOGIC;
    output_matrix_d0 : OUT STD_LOGIC_VECTOR (31 downto 0);
    output_matrix_q0 : IN STD_LOGIC_VECTOR (31 downto 0);
    lr : IN STD_LOGIC_VECTOR (31 downto 0) );
end;


architecture behav of MatrixBackPropagatio_1 is 
    constant ap_const_logic_1 : STD_LOGIC := '1';
    constant ap_const_logic_0 : STD_LOGIC := '0';
    constant ap_ST_fsm_state1 : STD_LOGIC_VECTOR (10 downto 0) := "00000000001";
    constant ap_ST_fsm_state2 : STD_LOGIC_VECTOR (10 downto 0) := "00000000010";
    constant ap_ST_fsm_state3 : STD_LOGIC_VECTOR (10 downto 0) := "00000000100";
    constant ap_ST_fsm_state4 : STD_LOGIC_VECTOR (10 downto 0) := "00000001000";
    constant ap_ST_fsm_state5 : STD_LOGIC_VECTOR (10 downto 0) := "00000010000";
    constant ap_ST_fsm_state6 : STD_LOGIC_VECTOR (10 downto 0) := "00000100000";
    constant ap_ST_fsm_state7 : STD_LOGIC_VECTOR (10 downto 0) := "00001000000";
    constant ap_ST_fsm_state8 : STD_LOGIC_VECTOR (10 downto 0) := "00010000000";
    constant ap_ST_fsm_state9 : STD_LOGIC_VECTOR (10 downto 0) := "00100000000";
    constant ap_ST_fsm_state10 : STD_LOGIC_VECTOR (10 downto 0) := "01000000000";
    constant ap_ST_fsm_state11 : STD_LOGIC_VECTOR (10 downto 0) := "10000000000";
    constant ap_const_lv32_0 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000000";
    constant ap_const_lv32_1 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000001";
    constant ap_const_lv1_0 : STD_LOGIC_VECTOR (0 downto 0) := "0";
    constant ap_const_lv32_2 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000010";
    constant ap_const_lv32_3 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000011";
    constant ap_const_lv32_6 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000110";
    constant ap_const_lv32_7 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000111";
    constant ap_const_lv2_0 : STD_LOGIC_VECTOR (1 downto 0) := "00";
    constant ap_const_lv1_1 : STD_LOGIC_VECTOR (0 downto 0) := "1";
    constant ap_const_lv32_A : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000001010";
    constant ap_const_lv32_4 : STD_LOGIC_VECTOR (31 downto 0) := "00000000000000000000000000000100";
    constant ap_const_lv2_3 : STD_LOGIC_VECTOR (1 downto 0) := "11";
    constant ap_const_lv2_1 : STD_LOGIC_VECTOR (1 downto 0) := "01";
    constant ap_const_boolean_1 : BOOLEAN := true;

    signal ap_CS_fsm : STD_LOGIC_VECTOR (10 downto 0) := "00000000001";
    attribute fsm_encoding : string;
    attribute fsm_encoding of ap_CS_fsm : signal is "none";
    signal ap_CS_fsm_state1 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state1 : signal is "none";
    signal i_fu_105_p2 : STD_LOGIC_VECTOR (1 downto 0);
    signal i_reg_168 : STD_LOGIC_VECTOR (1 downto 0);
    signal ap_CS_fsm_state2 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state2 : signal is "none";
    signal sub_ln101_fu_123_p2 : STD_LOGIC_VECTOR (4 downto 0);
    signal sub_ln101_reg_173 : STD_LOGIC_VECTOR (4 downto 0);
    signal icmp_ln99_fu_99_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal j_fu_139_p2 : STD_LOGIC_VECTOR (1 downto 0);
    signal j_reg_181 : STD_LOGIC_VECTOR (1 downto 0);
    signal ap_CS_fsm_state3 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state3 : signal is "none";
    signal output_matrix_addr_reg_186 : STD_LOGIC_VECTOR (3 downto 0);
    signal icmp_ln100_fu_133_p2 : STD_LOGIC_VECTOR (0 downto 0);
    signal input_matrix_load_reg_196 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_CS_fsm_state4 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state4 : signal is "none";
    signal grp_fu_91_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal tmp_reg_201 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_CS_fsm_state7 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state7 : signal is "none";
    signal ap_CS_fsm_state8 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state8 : signal is "none";
    signal i_0_reg_63 : STD_LOGIC_VECTOR (1 downto 0);
    signal j_0_reg_74 : STD_LOGIC_VECTOR (1 downto 0);
    signal ap_CS_fsm_state11 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state11 : signal is "none";
    signal zext_ln101_fu_154_p1 : STD_LOGIC_VECTOR (63 downto 0);
    signal grp_fu_85_p2 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_CS_fsm_state5 : STD_LOGIC;
    attribute fsm_encoding of ap_CS_fsm_state5 : signal is "none";
    signal shl_ln_fu_111_p3 : STD_LOGIC_VECTOR (3 downto 0);
    signal zext_ln101_4_fu_119_p1 : STD_LOGIC_VECTOR (4 downto 0);
    signal i_0_cast1_fu_95_p1 : STD_LOGIC_VECTOR (4 downto 0);
    signal j_0_cast_fu_129_p1 : STD_LOGIC_VECTOR (4 downto 0);
    signal add_ln101_fu_145_p2 : STD_LOGIC_VECTOR (4 downto 0);
    signal sext_ln101_fu_150_p1 : STD_LOGIC_VECTOR (31 downto 0);
    signal ap_NS_fsm : STD_LOGIC_VECTOR (10 downto 0);

    component forw_back_fsub_32ncg IS
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
    forw_back_fsub_32ncg_U89 : component forw_back_fsub_32ncg
    generic map (
        ID => 1,
        NUM_STAGE => 4,
        din0_WIDTH => 32,
        din1_WIDTH => 32,
        dout_WIDTH => 32)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        din0 => output_matrix_q0,
        din1 => tmp_reg_201,
        ce => ap_const_logic_1,
        dout => grp_fu_85_p2);

    forw_back_fmul_32cud_U90 : component forw_back_fmul_32cud
    generic map (
        ID => 1,
        NUM_STAGE => 3,
        din0_WIDTH => 32,
        din1_WIDTH => 32,
        dout_WIDTH => 32)
    port map (
        clk => ap_clk,
        reset => ap_rst,
        din0 => input_matrix_load_reg_196,
        din1 => lr,
        ce => ap_const_logic_1,
        dout => grp_fu_91_p2);





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


    i_0_reg_63_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln100_fu_133_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then 
                i_0_reg_63 <= i_reg_168;
            elsif (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then 
                i_0_reg_63 <= ap_const_lv2_0;
            end if; 
        end if;
    end process;

    j_0_reg_74_assign_proc : process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln99_fu_99_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
                j_0_reg_74 <= ap_const_lv2_0;
            elsif ((ap_const_logic_1 = ap_CS_fsm_state11)) then 
                j_0_reg_74 <= j_reg_181;
            end if; 
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state2)) then
                i_reg_168 <= i_fu_105_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state4)) then
                input_matrix_load_reg_196 <= input_matrix_q0;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state3)) then
                j_reg_181 <= j_fu_139_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln100_fu_133_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state3))) then
                output_matrix_addr_reg_186 <= zext_ln101_fu_154_p1(4 - 1 downto 0);
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if (((icmp_ln99_fu_99_p2 = ap_const_lv1_0) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                sub_ln101_reg_173 <= sub_ln101_fu_123_p2;
            end if;
        end if;
    end process;
    process (ap_clk)
    begin
        if (ap_clk'event and ap_clk = '1') then
            if ((ap_const_logic_1 = ap_CS_fsm_state7)) then
                tmp_reg_201 <= grp_fu_91_p2;
            end if;
        end if;
    end process;

    ap_NS_fsm_assign_proc : process (ap_start, ap_CS_fsm, ap_CS_fsm_state1, ap_CS_fsm_state2, icmp_ln99_fu_99_p2, ap_CS_fsm_state3, icmp_ln100_fu_133_p2)
    begin
        case ap_CS_fsm is
            when ap_ST_fsm_state1 => 
                if (((ap_const_logic_1 = ap_CS_fsm_state1) and (ap_start = ap_const_logic_1))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state1;
                end if;
            when ap_ST_fsm_state2 => 
                if (((icmp_ln99_fu_99_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then
                    ap_NS_fsm <= ap_ST_fsm_state1;
                else
                    ap_NS_fsm <= ap_ST_fsm_state3;
                end if;
            when ap_ST_fsm_state3 => 
                if (((icmp_ln100_fu_133_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state3))) then
                    ap_NS_fsm <= ap_ST_fsm_state2;
                else
                    ap_NS_fsm <= ap_ST_fsm_state4;
                end if;
            when ap_ST_fsm_state4 => 
                ap_NS_fsm <= ap_ST_fsm_state5;
            when ap_ST_fsm_state5 => 
                ap_NS_fsm <= ap_ST_fsm_state6;
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
                ap_NS_fsm <= ap_ST_fsm_state3;
            when others =>  
                ap_NS_fsm <= "XXXXXXXXXXX";
        end case;
    end process;
    add_ln101_fu_145_p2 <= std_logic_vector(unsigned(sub_ln101_reg_173) + unsigned(j_0_cast_fu_129_p1));
    ap_CS_fsm_state1 <= ap_CS_fsm(0);
    ap_CS_fsm_state11 <= ap_CS_fsm(10);
    ap_CS_fsm_state2 <= ap_CS_fsm(1);
    ap_CS_fsm_state3 <= ap_CS_fsm(2);
    ap_CS_fsm_state4 <= ap_CS_fsm(3);
    ap_CS_fsm_state5 <= ap_CS_fsm(4);
    ap_CS_fsm_state7 <= ap_CS_fsm(6);
    ap_CS_fsm_state8 <= ap_CS_fsm(7);

    ap_done_assign_proc : process(ap_start, ap_CS_fsm_state1, ap_CS_fsm_state2, icmp_ln99_fu_99_p2)
    begin
        if ((((icmp_ln99_fu_99_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2)) or ((ap_start = ap_const_logic_0) and (ap_const_logic_1 = ap_CS_fsm_state1)))) then 
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


    ap_ready_assign_proc : process(ap_CS_fsm_state2, icmp_ln99_fu_99_p2)
    begin
        if (((icmp_ln99_fu_99_p2 = ap_const_lv1_1) and (ap_const_logic_1 = ap_CS_fsm_state2))) then 
            ap_ready <= ap_const_logic_1;
        else 
            ap_ready <= ap_const_logic_0;
        end if; 
    end process;

    i_0_cast1_fu_95_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(i_0_reg_63),5));
    i_fu_105_p2 <= std_logic_vector(unsigned(i_0_reg_63) + unsigned(ap_const_lv2_1));
    icmp_ln100_fu_133_p2 <= "1" when (j_0_reg_74 = ap_const_lv2_3) else "0";
    icmp_ln99_fu_99_p2 <= "1" when (i_0_reg_63 = ap_const_lv2_3) else "0";
    input_matrix_address0 <= zext_ln101_fu_154_p1(4 - 1 downto 0);

    input_matrix_ce0_assign_proc : process(ap_CS_fsm_state3)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state3)) then 
            input_matrix_ce0 <= ap_const_logic_1;
        else 
            input_matrix_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    j_0_cast_fu_129_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(j_0_reg_74),5));
    j_fu_139_p2 <= std_logic_vector(unsigned(j_0_reg_74) + unsigned(ap_const_lv2_1));
    output_matrix_address0 <= output_matrix_addr_reg_186;

    output_matrix_ce0_assign_proc : process(ap_CS_fsm_state7, ap_CS_fsm_state11)
    begin
        if (((ap_const_logic_1 = ap_CS_fsm_state7) or (ap_const_logic_1 = ap_CS_fsm_state11))) then 
            output_matrix_ce0 <= ap_const_logic_1;
        else 
            output_matrix_ce0 <= ap_const_logic_0;
        end if; 
    end process;

    output_matrix_d0 <= grp_fu_85_p2;

    output_matrix_we0_assign_proc : process(ap_CS_fsm_state11)
    begin
        if ((ap_const_logic_1 = ap_CS_fsm_state11)) then 
            output_matrix_we0 <= ap_const_logic_1;
        else 
            output_matrix_we0 <= ap_const_logic_0;
        end if; 
    end process;

        sext_ln101_fu_150_p1 <= std_logic_vector(IEEE.numeric_std.resize(signed(add_ln101_fu_145_p2),32));

    shl_ln_fu_111_p3 <= (i_0_reg_63 & ap_const_lv2_0);
    sub_ln101_fu_123_p2 <= std_logic_vector(unsigned(zext_ln101_4_fu_119_p1) - unsigned(i_0_cast1_fu_95_p1));
    zext_ln101_4_fu_119_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(shl_ln_fu_111_p3),5));
    zext_ln101_fu_154_p1 <= std_logic_vector(IEEE.numeric_std.resize(unsigned(sext_ln101_fu_150_p1),64));
end behav;
