-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- PROGRAM		"Quartus II 64-Bit"
-- VERSION		"Version 13.1.0 Build 162 10/23/2013 SJ Web Edition"
-- CREATED		"Sat Oct 18 15:16:39 2014"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY DC_motor_control_block_diagram IS 
	PORT
	(
		Input_Clock :  IN  STD_LOGIC;
		Reset_signal :  IN  STD_LOGIC;
		DIR_SEL_SWITCH :  IN  STD_LOGIC;
		STOP :  IN  STD_LOGIC;
		PWM_SELECT :  IN  STD_LOGIC_VECTOR(2 DOWNTO 0);
		EN_PHMODHB3 :  OUT  STD_LOGIC;
		DIROUT_PHMODHB3 :  OUT  STD_LOGIC
	);
END DC_motor_control_block_diagram;

ARCHITECTURE bdf_type OF DC_motor_control_block_diagram IS 

COMPONENT pwm
	PORT(clk : IN STD_LOGIC;
		 clr : IN STD_LOGIC;
		 PWM_25 : OUT STD_LOGIC;
		 PWM_50 : OUT STD_LOGIC;
		 PWM_75 : OUT STD_LOGIC
	);
END COMPONENT;

COMPONENT threetoonemux
	PORT(PWM_25 : IN STD_LOGIC;
		 PWM_50 : IN STD_LOGIC;
		 PWM_75 : IN STD_LOGIC;
		 PWM_SELECT : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
		 PWM_OUT : OUT STD_LOGIC
	);
END COMPONENT;

COMPONENT dc_motor_control
	PORT(DIRIN : IN STD_LOGIC;
		 PWM : IN STD_LOGIC;
		 STOP : IN STD_LOGIC;
		 EN : OUT STD_LOGIC;
		 DIROUT : OUT STD_LOGIC
	);
END COMPONENT;

SIGNAL	SYNTHESIZED_WIRE_0 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_1 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_2 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_3 :  STD_LOGIC;


BEGIN 



b2v_inst : pwm
PORT MAP(clk => Input_Clock,
		 clr => Reset_signal,
		 PWM_25 => SYNTHESIZED_WIRE_0,
		 PWM_50 => SYNTHESIZED_WIRE_1,
		 PWM_75 => SYNTHESIZED_WIRE_2);


b2v_inst1 : threetoonemux
PORT MAP(PWM_25 => SYNTHESIZED_WIRE_0,
		 PWM_50 => SYNTHESIZED_WIRE_1,
		 PWM_75 => SYNTHESIZED_WIRE_2,
		 PWM_SELECT => PWM_SELECT,
		 PWM_OUT => SYNTHESIZED_WIRE_3);


b2v_inst2 : dc_motor_control
PORT MAP(DIRIN => DIR_SEL_SWITCH,
		 PWM => SYNTHESIZED_WIRE_3,
		 STOP => STOP,
		 EN => EN_PHMODHB3,
		 DIROUT => DIROUT_PHMODHB3);


END bdf_type;