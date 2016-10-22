
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity DE0_Basic_Computer is

-------------------------------------------------------------------------------
--                             Port Declarations                             --
-------------------------------------------------------------------------------
port (
	-- Inputs
	CLOCK_50             : in std_logic;
	KEY                  : in std_logic_vector (2 downto 0);
	SW                   : in std_logic_vector (9 downto 0);

	--  Communication
	UART_RXD             : in std_logic;

	-- Bidirectionals
	--GPIO_0               : inout std_logic_vector (31 downto 0);
	GPIO_1               : inout std_logic_vector (31 downto 0);

	-- Memory (SDRAM)
	DRAM_DQ					 : inout std_logic_vector (15 downto 0);

	-- Outputs
	--  Simple
	--LEDG                 : out std_logic_vector (9 downto 0);

	HEX0                 : out std_logic_vector (7 downto 0);
	HEX1                 : out std_logic_vector (7 downto 0);
	HEX2                 : out std_logic_vector (7 downto 0);
	HEX3                 : out std_logic_vector (7 downto 0);

	--  Communication
	UART_TXD             : out std_logic;
	
	-- Memory (SDRAM)
	DRAM_ADDR			 : out std_logic_vector (11 downto 0);
	DRAM_BA				 : out std_logic_vector (1 downto 0);
	DRAM_CAS_N			 : out std_logic;
	DRAM_RAS_N			 : out std_logic;
	DRAM_CLK				 : out std_logic;
	DRAM_CKE				 : out std_logic;
	DRAM_CS_N			 : out std_logic;
	DRAM_WE_N			 : out std_logic;
	DRAM_UDQM			 : buffer std_logic;
	DRAM_LDQM			 : buffer std_logic;
	
	-- Servo
	SERVO_0			 		 : out std_logic_vector (6 downto 0);	 
	SERVO_1			 		 : out std_logic_vector (6 downto 0);	 
	
	-- DC MOTOR
	DC_MOT_DIR_SEL		 : out std_logic;
	DC_MOT_STOP			 : out std_logic;
	DC_MOT_PWM			 : out std_logic_vector (2 downto 0);
	
	-- RASPI
	RAS_PI			    : out std_logic;
	
	-- MSP430 [3]
	MSP_430            : in std_logic;
	
	-- Stepper
	STEP_DIR				 : out std_logic;	 
	STEP_PWM				 : out std_logic_vector (1 downto 0);	 
	STEP_STOP			 : out std_logic
 
	);
end DE0_Basic_Computer;


architecture DE0_Basic_Computer_rtl of DE0_Basic_Computer is

-------------------------------------------------------------------------------
--                           Subentity Declarations                          --
-------------------------------------------------------------------------------
	component nios_system
		port (
              -- 1) global signals:
                 signal clk : IN STD_LOGIC;
                 signal reset_n : IN STD_LOGIC;

              -- the_Expansion_JP1
                 --signal GPIO_0_to_and_from_the_Expansion_JP1 : INOUT STD_LOGIC_VECTOR (31 DOWNTO 0);

              -- the_Expansion_JP2
                 signal GPIO_1_to_and_from_the_Expansion_JP2 : INOUT STD_LOGIC_VECTOR (31 DOWNTO 0);

              -- the_Green_LEDs
                 --signal LEDG_from_the_Green_LEDs : OUT STD_LOGIC_VECTOR (9 DOWNTO 0);

              -- the_HEX3_HEX0
                 signal HEX0_from_the_HEX3_HEX0 : OUT STD_LOGIC_VECTOR (7 DOWNTO 0);
                 signal HEX1_from_the_HEX3_HEX0 : OUT STD_LOGIC_VECTOR (7 DOWNTO 0);
                 signal HEX2_from_the_HEX3_HEX0 : OUT STD_LOGIC_VECTOR (7 DOWNTO 0);
                 signal HEX3_from_the_HEX3_HEX0 : OUT STD_LOGIC_VECTOR (7 DOWNTO 0);

              -- the_Pushbuttons
                 signal KEY_to_the_Pushbuttons : IN STD_LOGIC_VECTOR (2 DOWNTO 0);

              -- the_Serial_port
                 signal UART_RXD_to_the_Serial_port 	: IN STD_LOGIC;
                 signal UART_TXD_from_the_Serial_port : OUT STD_LOGIC;

              -- the_Slider_switches
                 signal SW_to_the_Slider_switches : IN STD_LOGIC_VECTOR (9 DOWNTO 0);
                 
              -- the_sdram
                 signal zs_addr_from_the_sdram 			: OUT STD_LOGIC_VECTOR (11 DOWNTO 0);
                 signal zs_ba_from_the_sdram 			: BUFFER STD_LOGIC_VECTOR (1 DOWNTO 0);
                 signal zs_cas_n_from_the_sdram 		: OUT STD_LOGIC;
                 signal zs_cke_from_the_sdram 			: OUT STD_LOGIC;
                 signal zs_cs_n_from_the_sdram 			: OUT STD_LOGIC;
                 signal zs_dq_to_and_from_the_sdram 	: INOUT STD_LOGIC_VECTOR (15 DOWNTO 0);
                 signal zs_dqm_from_the_sdram 			: BUFFER STD_LOGIC_VECTOR (1 DOWNTO 0);
                 signal zs_ras_n_from_the_sdram 		: OUT STD_LOGIC;
                 signal zs_we_n_from_the_sdram 			: OUT STD_LOGIC;
				 
					 signal servo_pos_0_external_interface_export    : out   std_logic_vector(6 downto 0);
					 signal servo_pos_1_external_interface_export    : out   std_logic_vector(6 downto 0);                      -- export
					 
					 signal dc_mot_external_interface_export     	 : out   std_logic; 
					 signal dc_mot_stop_external_interface_export    : out   std_logic;
					 signal dc_mot_pwm_sel_external_interface_export : out   std_logic_vector(2 downto 0);    				 
					 				 
					 signal msp430_external_interface_export    		 : in    std_logic;
					 
					 signal raspi_external_interface_export     		 : out   std_logic;
					 signal step_dir_external_interface_export       : out   std_logic;                                        -- export
					 signal step_pwm_external_interface_export       : out   std_logic_vector(1 downto 0);                     -- export
					 signal step_stop_external_interface_export      : out   std_logic 					 
              );
	end component;
	
	component sdram_pll
		port (
				 signal inclk0 : IN STD_LOGIC;
				 signal c0 : OUT STD_LOGIC;
				 signal c1 : OUT STD_LOGIC
			 );
	end component;

-------------------------------------------------------------------------------
--                           Parameter Declarations                          --
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
--                 Internal Wires and Registers Declarations                 --
-------------------------------------------------------------------------------
-- Internal Wires
-- Used to connect the Nios 2 system clock to the non-shifted output of the PLL
signal			 system_clock : STD_LOGIC;

-- Used to concatenate some SDRAM control signals
signal			 DQM : STD_LOGIC_VECTOR(1 DOWNTO 0);

-- Internal Registers

-- State Machine Registers

begin

-------------------------------------------------------------------------------
--                         Finite State Machine(s)                           --
-------------------------------------------------------------------------------

-------------------------------------------------------------------------------
--                             Sequential Logic                              --
-------------------------------------------------------------------------------
	
-------------------------------------------------------------------------------
--                            Combinational Logic                            --
-------------------------------------------------------------------------------

DRAM_UDQM  <= DQM(1);
DRAM_LDQM  <= DQM(0);

--GPIO_0( 0) <= 'Z';
--GPIO_0( 2) <= 'Z';
--GPIO_0(16) <= 'Z';
--GPIO_0(18) <= 'Z';

--GPIO_1( 0) <= 'Z';
--GPIO_1( 2) <= 'Z';
--GPIO_1(16) <= 'Z';
--GPIO_1(18) <= 'Z';

-------------------------------------------------------------------------------
--                              Internal Modules                             --
-------------------------------------------------------------------------------



NiosII : nios_system
	port map(
		-- 1) global signals:
		clk       								=> system_clock,
		reset_n    								=> KEY(0),
	
		-- the_Slider_switches
		SW_to_the_Slider_switches				=> SW,
		
		-- the_Pushbuttons
		KEY_to_the_Pushbuttons					=> (KEY(2 downto 1) & "1"),

		-- the_Expansion_JP1
		--GPIO_0_to_and_from_the_Expansion_JP1	=> GPIO_0,

		-- the_Expansion_JP2
		GPIO_1_to_and_from_the_Expansion_JP2	=> GPIO_1,

		-- the_Green_LEDs
		--LEDG_from_the_Green_LEDs 				=> LEDG,
		
		-- the_HEX3_HEX0
		HEX0_from_the_HEX3_HEX0 				=> HEX0,
		HEX1_from_the_HEX3_HEX0 				=> HEX1,
		HEX2_from_the_HEX3_HEX0 				=> HEX2,
		HEX3_from_the_HEX3_HEX0 				=> HEX3,
		
		-- the_Serial_port
		UART_RXD_to_the_Serial_port			=> UART_RXD,
		UART_TXD_from_the_Serial_port			=> UART_TXD,
		
		-- the_sdram
		zs_addr_from_the_sdram					=> DRAM_ADDR,
		zs_ba_from_the_sdram						=> DRAM_BA,
		zs_cas_n_from_the_sdram					=> DRAM_CAS_N,
		zs_cke_from_the_sdram					=> DRAM_CKE,
		zs_cs_n_from_the_sdram					=> DRAM_CS_N,
		zs_dq_to_and_from_the_sdram			=> DRAM_DQ,
		zs_dqm_from_the_sdram					=> DQM,
		zs_ras_n_from_the_sdram					=> DRAM_RAS_N,
		zs_we_n_from_the_sdram					=> DRAM_WE_N,
		
      servo_pos_0_external_interface_export     => SERVO_0,
		servo_pos_1_external_interface_export     => SERVO_1,     --     servo_speed_external_interface.export

		
      dc_mot_external_interface_export    		=> DC_MOT_DIR_SEL, 
		dc_mot_stop_external_interface_export 		=> DC_MOT_STOP,
		dc_mot_pwm_sel_external_interface_export 	=>	DC_MOT_PWM,
		
      msp430_external_interface_export    => MSP_430,
		
      raspi_external_interface_export     => RAS_PI,
		
		step_dir_external_interface_export       => STEP_DIR,       --        step_dir_external_interface.export
		step_pwm_external_interface_export       => STEP_PWM,       --        step_pwm_external_interface.export
		step_stop_external_interface_export      => STEP_STOP			

	);
	
neg_3ns : sdram_pll
	port map (
		inclk0									=> CLOCK_50,
		c0											=> DRAM_CLK,
		c1											=> system_clock
	);

end DE0_Basic_Computer_rtl;

