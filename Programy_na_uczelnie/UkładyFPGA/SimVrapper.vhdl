--Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2022.1 (lin64) Build 3526262 Mon Apr 18 15:47:01 MDT 2022
--Date        : Mon Apr 13 15:41:55 2026
--Host        : cnode01 running 64-bit Ubuntu 22.04.5 LTS
--Command     : generate_target design_2_wrapper.bd
--Design      : design_2_wrapper
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity design_2_wrapper is
  port (
    ap_clk_0 : in STD_LOGIC;
    ap_return_0 : out STD_LOGIC_VECTOR ( 31 downto 0 );
    ap_return_1 : out STD_LOGIC_VECTOR ( 31 downto 0 );
    ap_rst_0 : in STD_LOGIC;
    ap_start_0 : in STD_LOGIC;
    in_0_0 : in STD_LOGIC_VECTOR ( 31 downto 0 );
    in_0_1 : in STD_LOGIC_VECTOR ( 31 downto 0 )
  );
end design_2_wrapper;
 
architecture STRUCTURE of design_2_wrapper is
  component design_2 is
  port (
    ap_return_0 : out STD_LOGIC_VECTOR ( 31 downtotestbench2 0 );
    in_0_0 : in STD_LOGIC_VECTOR ( 31 downto 0 );
    ap_return_1 : out STD_LOGIC_VECTOR ( 31 downto 0 );
    in_0_1 : in STD_LOGIC_VECTOR ( 31 downto 0 );
    ap_start_0 : in STD_LOGIC;
    ap_clk_0 : in STD_LOGIC;
    ap_rst_0 : in STD_LOGIC
  );
  end component design_2;
begin
design_2_i: component design_2
     port map (
      ap_clk_0 => ap_clk_0,
      ap_return_0(31 downto 0) => ap_return_0(31 downto 0),
      ap_return_1(31 downto 0) => ap_return_1(31 downto 0),
      ap_rst_0 => ap_rst_0,
      ap_start_0 => ap_start_0,
      in_0_0(31 downto 0) => in_0_0(31 downto 0),
      in_0_1(31 downto 0) => in_0_1(31 downto 0)
    );
end STRUCTURE;
