-- Crazy Machine Project
-- Group 5
-- Servo Controller
-- Lance MacArthur
--------------------------------------------------------------------------------
-- Servo will be used as track changer for dumptruck
-- Microserver will be used as dumptruck dumper
---------------------------------------------------------------------------------
-- DGServo S05nf std 9g appears to be only able to rotate 160 degress between pulse 1ms and pulse 2ms.
-- Usage: Set pulsecount to amount of clock cycles to move to required position
-- Period : 50mhz/50hz = 1000 000
-- will generate 20ms pulse ie takes 20 ms to count to 1000 000
-- duty cycle of 2ms(2ms/clock period=2 ms/ 20 ns=100000) -- left rotation
-- Center position 75000
-- duty cycle 1ms(2ms/clock period=1 ms/ 20 ns=50000) -- right rotation
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;


entity servoctrl is
    Port ( clk           : in  STD_LOGIC;
               reset      : in  STD_LOGIC; 
               button_l : in  STD_LOGIC;  
               button_r : in  STD_LOGIC; 
               pwm       : out  STD_LOGIC);
   end servoctrl;

architecture Behavioral of servoctrl is
    begin

         process(clk,reset)
			variable counter : integer range 0 to 1000000; -- Total Period 1000000 counts at 50mhz 
			variable duty_cycle:integer:=0;  -- Duty Cycle of pwm
			variable pulsecount:integer:=0; -- To stop pwm after moved to position
              begin
                    
                   if clk='1' and clk'event then
								counter:=counter+1; -- Increment Counter every clock cycle
								
								if	reset = '0' then -- Button 0 reset switch pressed
                        pwm<='0';				-- Set pwm to low
                        counter:=0;				-- Reset Counter
                        duty_cycle:=0;			-- Reset Duty Cycle
								pulsecount:=0;			-- Reset pulse count
								elsif button_r = '0' then-- Button 2 move to left most position
								counter:=0;	
								duty_cycle := 100000; -- 
								pwm<='1';
								pulsecount:=0;
								elsif button_l = '0' then -- button 1 Move to right most position
								counter:=0;	
								duty_cycle := 50000;
								pwm<='1';
								pulsecount:=0;
								end if;
								
								if counter = 1000000 and pulsecount=20 then
								counter:=0; 
								pwm<='0';
								duty_cycle:=0;
								pulsecount:=21;					
								elsif counter = 1000000 and pulsecount <20 then-- Counter Reached end of period
								counter:=0; 
								pulsecount:=pulsecount+1;
								pwm<='1';

								elsif counter = duty_cycle then -- Pwm has been high for required pulse
								pwm<='0';
								
								end if;
							
                   end if;
             end process;
  
end Behavioral;