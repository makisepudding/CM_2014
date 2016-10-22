-- This VHDL file contains code for a Three to One MUX to multiplex
-- The three PWM Signals from the PWM generator component
-- Authors: Joseph Banda
-- Revision History:  9th October, 2014 - Initial coding
--					       9th October, 2014 - Interfacing

-- --------------------------------------------------------------------

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY ThreeToOneMux IS 
	PORT(
			PWM_25, PWM_50, PWM_75 : IN STD_LOGIC;			-- Input signals to Multiplex
			PWM_SELECT : IN STD_LOGIC_VECTOR(2 downto 0); -- Input push buttons to select PWM Signals
			
			PWM_OUT: OUT STD_LOGIC		-- Output PWM output after multiplexing 
			);
END ThreeToOneMux;
	
	
ARCHITECTURE Behavioral OF ThreeToOneMux IS 
BEGIN 

		PROCESS(PWM_SELECT(0), PWM_SELECT(1), PWM_SELECT(2))
			BEGIN
				IF (PWM_SELECT(0) = '1') AND (PWM_SELECT(1) = '0') AND (PWM_SELECT(2) ='0') THEN -- Select PWM_25 with switch 0
					PWM_OUT <= PWM_25;
				ELSIF (PWM_SELECT(0) = '0') AND (PWM_SELECT(1) = '1') AND (PWM_SELECT(2) ='0') THEN -- Select PWM_50 with switch 1
					PWM_OUT <= PWM_50;
				ELSIF (PWM_SELECT(0) = '0') AND (PWM_SELECT(1) = '0') AND (PWM_SELECT(2) ='1') THEN -- Select PWM_75 with switch 2
					PWM_OUT <= PWM_75;
				END IF;
				
			END PROCESS;
END Behavioral;