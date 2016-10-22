-- This VHDL file contains code for PWM wave production and control
-- Authors: Joseph Banda
-- Revision History:  8th October, 2014 - Initial coding
--					  9th October, 2014 - Interfacing

-- --------------------------------------------------------------------

-- This PWM Control module produces three different PWM Signals with 
-- Different duty cycles. These are 25%, 50% and 70% of a 2kHz PWM Signal
-- The selection of which of these to implement is done using three push
-- Buttons. 
	
-- ---------------------------------------------------------------------
-- This module also interfaces with the DCmotor VHDL file and is used
-- For selection of PWM Input

-- ---------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity PWM is
    Port ( clk : in std_logic;          -- Clock in = 50 MHz
           clr : in std_logic;          -- Main reset. Active low
           --PWM_SELECT : in std_logic_vector(2 downto 0);	-- Three push buttons used to select speed
			  PWM_25, PWM_50, PWM_75 : out std_logic);  -- Divided clock 50MHz/2**12
end PWM;


architecture Behavioral of PWM is

  --variable count: integer range 0 to 24999; --for a 2kHZ pulse
  --variable clk_out: std_logic :='1';

begin

	process (clk, clr)
	
	variable count: integer range 0 to 24999; --for a 2kHZ pulse changed from 24999
	variable clk_out: std_logic := '1';
	
	begin
			if (rising_edge(clk)) then	-- if device is reset
				if (clr ='0') then
					 count := 0;
					 PWM_25 <='0';
					 PWM_50 <='0';
					 PWM_75 <='0';
				else
					count := count +1;
				
					if (count<6249) then	-- for PWM_25 changed from 6249
						PWM_25 <= clk_out;
					else
						PWM_25 <= NOT clk_out;
					end if;
					
					
					if (count<12499) then	-- for PWM_50 changed from 12499
						PWM_50 <= clk_out;
					else
						PWM_50 <= NOT clk_out;
					end if;
					
					
					if (count<18749) then	-- for PWM_75 changed from 18749
						PWM_75 <= clk_out;
					else
						PWM_75 <= NOT clk_out;
					end if;
					
				end if;
				
			end if;
			
--			if (PWM_SELECT(0) = '1')	then		
--			PWM_25 <= clk_out;-- Testing this bit of code here to see that a PWM of 25% is used	
--			else 
--			PWM_25 <= NOT clk_out;
--			end if;
--			
--			if (PWM_SELECT(1) = '1') then
--			PWM_50 <= clk_out;
--			else 
--			PWM_50 <= NOT clk_out;
--			end if;
--		
--			if (PWM_SELECT(2) = '1') then
--			PWM_75 <= clk_out;
--			else
--			PWM_75 <= NOT clk_out;
--			end if;
		
				
		
  end process;
  
end Behavioral;