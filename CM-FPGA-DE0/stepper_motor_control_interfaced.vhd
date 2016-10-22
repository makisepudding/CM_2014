-- Copyright (C) 1991-2012 Altera Corporation
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

-- PROGRAM		"Quartus II 32-bit"
-- VERSION		"Version 12.1 Build 177 11/07/2012 SJ Web Edition"
-- CREATED		"Fri Oct 03 12:17:44 2014"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY stepper_motor_control_interfaced IS 
	PORT
	(
		-- 50 MHz Clock input 
		CLOCK_INPUT :  IN  STD_LOGIC;			-- Clock Input from the four to one multiplexer for clock selection to control speed
		CLOCK_RESET :  IN  STD_LOGIC;			-- Reset Button for the clock
		
		-- Direction of rotation of the stepper motor
		DIRECTION :  IN  STD_LOGIC;			-- Switch to set direction of the stepper motor
		
		-- Selection of clock frequency for speed selection
		SWITCH_1 :  IN  STD_LOGIC;				-- Switch 1 to the four to one MUX for clock selection 
		SWITCH_2 :  IN  STD_LOGIC;				-- Switch 2 to the four to one MUX for clock selection
		
		STOP_STEP :  IN  STD_LOGIC;				-- STOP MOTION
		
		-- Output signals for setting direction of rotatio of the motor
		X_G1 :  OUT  STD_LOGIC;					-- X output signal for motor direction [PIN G1 on OD1]
		Xcomp_G2 :  OUT  STD_LOGIC;			-- X' output signal for motor direction[PIN G2 on OD1]
		Y_G3 :  OUT  STD_LOGIC;					-- Y output signal for motor direction [PIN G3 on OD1]
		Ycomp_G4 :  OUT  STD_LOGIC				-- Y' output signal for motor direction[PIN G4 on OD1]
	);
END stepper_motor_control_interfaced;

ARCHITECTURE Behavioral OF stepper_motor_control_interfaced IS 

COMPONENT fourtoonemux
	PORT(clk_190 : IN STD_LOGIC;
		 clk_763 : IN STD_LOGIC;
		 clk_3051 : IN STD_LOGIC;
		 clk_12207 : IN STD_LOGIC;
		 SW1 : IN STD_LOGIC;
		 SW2 : IN STD_LOGIC;
		 clk1 : OUT STD_LOGIC
	);
END COMPONENT;

COMPONENT clk_div_x4
	PORT(clk : IN STD_LOGIC;
		 clr : IN STD_LOGIC;
		 clk_190 : OUT STD_LOGIC;
		 clk_763 : OUT STD_LOGIC;
		 clk_3051 : OUT STD_LOGIC;
		 clk_12207 : OUT STD_LOGIC
	);
END COMPONENT;

COMPONENT stepper_motor_control
	PORT(CLK : IN STD_LOGIC;
		 DIR : IN STD_LOGIC;
		 STOP : IN STD_LOGIC;
		 X : OUT STD_LOGIC;
		 X_comp : OUT STD_LOGIC;
		 Y : OUT STD_LOGIC;
		 Y_comp : OUT STD_LOGIC
	);
END COMPONENT;

SIGNAL	SYNTHESIZED_WIRE_0 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_1 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_2 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_3 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_4 :  STD_LOGIC;


BEGIN 



b2v_inst : fourtoonemux
PORT MAP(clk_190 => SYNTHESIZED_WIRE_0,
		 clk_763 => SYNTHESIZED_WIRE_1,
		 clk_3051 => SYNTHESIZED_WIRE_2,
		 clk_12207 => SYNTHESIZED_WIRE_3,
		 SW1 => SWITCH_1,
		 SW2 => SWITCH_2,
		 clk1 => SYNTHESIZED_WIRE_4);


b2v_inst1 : clk_div_x4
PORT MAP(clk => CLOCK_INPUT,
		 clr => CLOCK_RESET,
		 clk_190 => SYNTHESIZED_WIRE_0,
		 clk_763 => SYNTHESIZED_WIRE_1,
		 clk_3051 => SYNTHESIZED_WIRE_2,
		 clk_12207 => SYNTHESIZED_WIRE_3);


b2v_inst2 : stepper_motor_control
PORT MAP(CLK => SYNTHESIZED_WIRE_4,
		 DIR => DIRECTION,
		 STOP => STOP_STEP,
		 X => X_G1,
		 X_comp => Xcomp_G2,
		 Y => Y_G3,
		 Y_comp => Ycomp_G4);


END Behavioral;