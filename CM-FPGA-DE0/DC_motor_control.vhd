-- This code contains logic to run a DC Motor
-- Authors : Joseph Banda
-- Revision History : 8th October, 2014 - Initial coding
--							 9th October, 2014 - Interfacing

-- --------------------------------------------------------------------

-- This Control Module for the DC Motor interfaces with a PWM File that 
-- Outputs a PWM Signal to this Module's PWM input. The PWM Signal that is
-- Sent to this module is then sent to EN Output PIN that is connected to
-- The EN input pin of the PmodHB3 H-Bridge. This port is used to enable
-- The Bridge when EN is active high and is also used to determine the 
-- Speed of the motor depending on the duty cycle of the PWM signal it 
-- Receives.
-- The DIRIN input sets the direction of the motor and is implemented at
-- The DIROUT output pin once the PWM Signal hits its falling edge.

-- ---------------------------------------------------------------------

-- This module also interfaces with a PMod HB3 H-Bridge that is used to connect
-- The DC motor to the DE0 FPGA Board

-- ---------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity DC_motor_control is
	port(
			DIRIN    : in std_logic;		-- Select Direction of Rotation of the motor
			PWM 	   : in std_logic;		-- Determine the speed of the motor
			EN		   : out std_logic; 	-- Enables the HBridge and Controls motor speed
			DIROUT   : out std_logic;		-- Direction of Rotation Output
			STOP		: in std_logic   -- STOP THE MOTOR
			
	    );
end DC_motor_control;

architecture behavioral of DC_motor_control is
begin
		process (PWM)
		begin
				DIROUT <= DIRIN;
				
				if (STOP = '1') then
					EN <='0';
				elsif (STOP = '0') then
					EN <= PWM;	-- Applying PWM to the Enable pin.
				end if;
					
		end process;
		
end behavioral;