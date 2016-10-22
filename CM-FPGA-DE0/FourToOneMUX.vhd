-- This file contains logic for the Four to One MUX used in the stepper motor control module
-- Created : 24/09/2014
-- Authors : Joseph Banda and Lance MacArthur

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;


ENTITY FourToOneMUX IS
	PORT(	clk_190, clk_763, clk_3051, clk_12207 : in STD_LOGIC;
			SW1, SW2 : in STD_LOGIC;
			clk1 :	out STD_LOGIC
			);
END FourToOneMUX;

ARCHITECTURE Behavioral OF FourToOneMUX IS
BEGIN

		PROCESS (SW1, SW2)
			BEGIN
			
			IF SW1 = '0' AND SW2 = '0' THEN
				clk1 <= clk_190;
			ELSIF SW1 = '0' AND SW2 = '1' THEN
				clk1 <= clk_763;
			ELSIF SW1 = '1' AND SW2 = '0' THEN
				clk1 <= clk_3051;
			ELSIF SW1 = '1' AND SW2 = '1' THEN
				clk1 <= clk_12207;
			END IF;
			

		END PROCESS;


END Behavioral;
