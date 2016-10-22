-- This VHDL file contains logic for a stepper motor[Control Module]
-- Authors: Joseph Banda
-- Revision History : 3rd October, 2014 - Initial coding
--							 4th October, 2014 - Interfacing

-- --------------------------------------------------------------------

--Control Module for the stepper motor interfaces with the 4 to 1 MUX
-- That is used to select a clock from four clocks in the clock divider
-- File. Each clock has a different frequency that is used to determine
-- The speed of the motor. The higher the frequency the faster the Motor.

-- ---------------------------------------------------------------------
-- This module also interfaces with a PMod OD1 Chip that is used to connect
-- The stepper motor to the DE0 FPGA Board

-- ---------------------------------------------------------------------



library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY stepper_motor_control IS
	PORT(

			-- Interfacing Signals
			CLK: IN STD_LOGIC; 	-- Normal System Clock
			DIR: IN STD_LOGIC; 	-- Used to set the direction of rotation of the stepper motor. DIR signal can be either high or low
								-- This 
			STOP: IN STD_LOGIC;			
			-- Combinational Logic Signals to determine the direction of the stepper motor
			X : OUT STD_LOGIC;
			X_comp: OUT STD_LOGIC;
			
			Y : OUT STD_LOGIC;
			Y_comp: OUT STD_LOGIC
	);
END stepper_motor_control;

ARCHITECTURE Behavioral OF stepper_motor_control IS

BEGIN
	
	PROCESS (CLK, DIR)
	
		VARIABLE X_cwise: 	STD_LOGIC_VECTOR (3 DOWNTO 0) := "1001"; -- Stepper Motor Clockwise motion
		VARIABLE Y_cwise: 	STD_LOGIC_VECTOR (3 DOWNTO 0) := "1100"; -- Stepper Motor Clockwise motion
		VARIABLE counter: 	INTEGER RANGE 0 TO 3;
		
		BEGIN
		
		IF RISING_EDGE(CLK) THEN
		IF STOP = '0' THEN
		
			IF DIR = '0' THEN	-- Clockwise Motion X and Y value Sequence Logic
				X <= X_cwise(counter);
				X_comp <= NOT X_cwise(counter);
				
				Y <= Y_cwise(counter);
				Y_comp <= NOT Y_cwise(counter);
						
			ELSE				-- Anticlockwise Motion X and Y value Sequence Logic 
				X <= Y_cwise(counter);
				X_comp <= NOT Y_cwise(counter);
				
				Y <= X_cwise(counter);
				Y_comp <= NOT X_cwise(counter);
					
			END IF;
			counter := counter + 1;
			
		ELSE
				X <= '0';
				X_comp <= '0';
				
				Y <= '0';
				Y_comp <= '0';
		END IF;
		
		
		END IF;
	
	END PROCESS;
END Behavioral;

