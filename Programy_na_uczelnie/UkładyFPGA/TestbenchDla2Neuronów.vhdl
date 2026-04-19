library IEEE;

use IEEE.STD_LOGIC_1164.ALL;

 

entity testbench2 is

end testbench2;

 

architecture Behavioral of testbench2 is

 

component design_2_wrapper is

port (

    ap_clk_0 : in STD_LOGIC;

    ap_rst_0 : in STD_LOGIC;

    ap_start_0 : in STD_LOGIC;

    in_0_0 : in STD_LOGIC_VECTOR (31 downto 0);

    in_0_1 : in STD_LOGIC_VECTOR (31 downto 0);

    ap_return_0 : out STD_LOGIC_VECTOR (31 downto 0);

    ap_return_1 : out STD_LOGIC_VECTOR (31 downto 0)

);

end component;

 

-- sygnały

signal clk, rst, start : std_logic;

signal in0, in1 : std_logic_vector(31 downto 0);

signal out0, out1 : std_logic_vector(31 downto 0);

 

begin

 

-- zegar 100 MHz

process

begin

    clk <= '1';

    wait for 5 ns;

    clk <= '0';

    wait for 5 ns;

end process;

 

-- stymulacja

process

begin

    -- init

    in0 <= x"00000000";

    in1 <= x"00000000";

    start <= '0';

    rst <= '1';

 

    wait for 100 ns;

    rst <= '0';

 

    wait for 50 ns;

 

    -- podanie danych

    wait until rising_edge(clk);

    in0 <= x"40000000"; -- 2.0 (float)

    in1 <= x"3F800000"; -- 1.0 (float)

 

    -- start

    start <= '1';

    wait until rising_edge(clk);

    start <= '0';

 

    -- czekamy

    wait for 500 ns;

 

    wait;

end process;

 

-- instancja

UUT : design_2_wrapper

port map(

    ap_clk_0 => clk,

    ap_rst_0 => rst,

    ap_start_0 => start,

    in_0_0 => in0,

    in_0_1 => in1,

    ap_return_0 => out0,

    ap_return_1 => out1

);

 

end Behavioral;
