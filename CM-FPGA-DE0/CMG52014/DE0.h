/*
						 ______   _______  _______    __    _  ___   _______  _______  _______
						|      | |       ||  _    |  |  |  | ||   | |       ||       ||       |
						|  _    ||    ___|| | |   |  |   |_| ||   | |   _   ||  _____||____   |
						| | |   ||   |___ | | |   |  |       ||   | |  | |  || |_____  ____|  |
						| |_|   ||    ___|| |_|   |  |  _    ||   | |  |_|  ||_____  || ______|
						|       ||   |___ |       |  | | |   ||   | |       | _____| || |_____
						|______| |_______||_______|  |_|  |__||___| |_______||_______||_______|



 * Crazy Machine Group 5 ADD ESE
 * Use Only on DE0 <NIOS2 from CM Group 5>
 *
 * THIS IS HEADER FILE => DE0.h
 *
 * Must include
 * 			>"DE0.c"
 *
 *  Close Source -- CRAZY MACHINE PROJECT GROUP 5 ONLY
 *
 *
 *  Update Log:>
 *  > Last Tested On:
 * 			 > 03/10/2014 with NIOS II Eclipse 13.0 on University Program DE0 NIOS2 Basic Computer.
 *
 *  More about coding NIOS2 on DE0
 *  REF: http://www-ug.eecg.toronto.edu/msl/nios_devices/
 *
*/

/********************************************************************************************************************/
	#include <stdio.h>
	#include <string.h>
	#include <math.h>
	#include "type_bool.h"
/*********************************************************************************************************Heading*end*/

/*********************************************************************************************************************
 * 																									NIOS-II Addressing
 * -> Check Qsys "nios_system.qsys" for all the addressing value and IRQ.
 * -> Always update new address on here.
 * -> Last Update 30/09/2014 11:09PM [Alex Lim]
 *********************************************************************************************************************/

//Board
//	#define green_LED_ptr ((volatile unsigned char *) 0x10000010) // green LED address 		    - 10bit wide output

	#define HEX3_HEX0_ptr ((volatile 		  long *) 0x10000020) // HEX3_HEX0 address  		- 32bit wide output
	#define SW_switch_ptr ((volatile unsigned char *) 0x10000040) // SW slider switch address   - 10bit wide  input
	#define KEY_ptr       ((volatile unsigned char *) 0x10000050) // pushbutton KEY address	    - 2bit wide Button0 as RST on VHDL

//GPIO2
	#define ADDR_JP2PORT  ((volatile          char *) 0x10000070) // EXT J5 IDE address 		- 32bit wide 2 way-direction

//GPIO1 - VHDL SPECIAL PINS
	#define MSP430_TR_SE  ((volatile unsigned char *) 0x00800030) // MSP-TRACK_SERVO PIN		- 1 bit wide input
	#define RASPI_PIN	  ((volatile unsigned char *) 0x00800020) // RASPI-MUSIC PIN			- 1 bit wide output

	#define DC_MOT_DIR	  ((volatile unsigned char *) 0x00800050) // DC-MOT-DIRECTION			- 1 bit wide input
	#define DC_MOT_SEL	  ((volatile unsigned char *) 0x00800010) // DC-MOT-PWM SELECTOR		- 1 bit wide input
	#define DC_MOT_STOP	  ((volatile unsigned char *) 0x00800040) // DC-MOT-STOP				- 1 bit wide input

	#define SERVO_P0	  ((volatile unsigned char *) 0x00800000) // SERVO-MOT-PIN0				- 7 bit wide input
	#define SERVO_P1      ((volatile unsigned char *) 0x00800090) // SERVO-MOT-PIN1     		- 7 bit wide input
	//#define SERVO_1_DUTY  ((volatile unsigned char *) 0x00800000) // SERVO-MOT-PIN1DUTY			- 4 bit wide input

	#define STEP_SEL	  ((volatile unsigned char *) 0x00800070) // STEPPER-PWM SELECTOR		- 2 bit wide input
	#define STEP_DIR	  ((volatile unsigned char *) 0x00800080) // STEPPER-DIRECTION			- 1 bit wide input
	#define STEP_STOP	  ((volatile unsigned char *) 0x00800060) // STEPPER-STOP				- 1 bit wide input
///*******************************************************************************************************Addressing*end*/



/*********************************************************************************************************************
 * 																									  Constants define
 * -> CONSTANTS only, which will not change through out the project
 * -> Last Update 30/09/2014 11:09PM [Alex Lim]
 *********************************************************************************************************************/
//	//LEDs
//	#define LEDG9  0x200
//	#define LEDG8  0x100
//	#define LEDG7  0x080
//	#define LEDG6  0x040
//	#define LEDG5  0x020
//	#define LEDG4  0x010
//	#define LEDG3  0x008
//	#define LEDG2  0x004
//	#define LEDG1  0x002
//	#define LEDG0  0x001

	//Switches
	#define   SW9  0x200
	#define   SW8  0x100
	#define   SW7  0x080
	#define   SW6  0x040
	#define   SW5  0x020
	#define   SW4  0x010
	#define   SW3  0x008
	#define   SW2  0x004
	#define   SW1  0x002
	#define   SW0  0x001

	//EXT GPIO on J5
	//OFFSET = 0
	#define GPIO2_0  0x01
	#define GPIO2_1  0x02
	#define GPIO2_2  0x04
	#define GPIO2_3  0x08
	#define GPIO2_4  0x10
	#define GPIO2_5  0x20
	#define GPIO2_6  0x40
	#define GPIO2_7  0x80

	//OFFSET = 1
	#define GPIO2_8  0x01
	#define GPIO2_9  0x02
	#define GPIO2_10 0x04
	#define GPIO2_11 0x08
	#define GPIO2_12 0x10
	#define GPIO2_13 0x20
	#define GPIO2_14 0x40
	#define GPIO2_15 0x80

	//OFFSET = 2
	#define GPIO2_16 0x01
	#define GPIO2_17 0x02
	#define GPIO2_18 0x04
	#define GPIO2_19 0x08
	#define GPIO2_20 0x10
	#define GPIO2_21 0x20
	#define GPIO2_22 0x40
	#define GPIO2_23 0x80

	//OFFSET = 3
	#define GPIO2_24 0x01
	#define GPIO2_25 0x02
	#define GPIO2_26 0x04
	#define GPIO2_27 0x08
	#define GPIO2_28 0x10
	#define GPIO2_29 0x20
	#define GPIO2_30 0x40
	#define GPIO2_31 0x80

	#define DEC 0x10
	#define HEX 0x11

/**************************************************************************************************Constants define*end*/

	//CONFIG PINS=============================================================================
	#define MSP_5  GPIO2_0 //MSP PIN P2_5 <-> DE0 GPIO2_0 	 	  --DIGITAL 1 bit [I/O]
	#define MSP_6  GPIO2_1 //MSP PIN P2_6 <-> DE0 GPIO2_1    	  --DIGITAL 1 bit [I/O]
	#define PR_SN  GPIO2_2 //PRESSURE SENSOR         			  --DIGITAL 1 bit [I]
	#define TP_S3  GPIO2_3 //TAP_SW3  [TRUCK]					  --DIGITAL 1 bit [I]
	#define TP_S4  GPIO2_4 //TAP_SW4  [LIFT]					  --DIGITAL 1 bit [I]
	#define LED_G  GPIO2_5 //GREEN LED							  --DIGITAL 1 bit [I]
	#define LED_Y  GPIO2_6 //YELLOW LED							  --DIGITAL 1 bit [I]
	#define LED_R  GPIO2_7 //RED LED							  --DIGITAL 1 bit [I]

	//========================================================================================

/*********************************************************************************************************************
 * 																									   Type Definition
 * -> TRUE,FALSE For boolean purpose
 * -> HIGH, LOW For boolean on I/O
 * -> Last Update 30/09/2014 11:18PM [Alex Lim]
 *********************************************************************************************************************/


/*************************************************************************************************Type Definition*end*/


/*********************************************************************************************************************
 * 																								   Functions Prototype
 ********************************************************************************************************************/

	  extern bool DELAY_CYCLES(unsigned long x);
	  //extern bool BOARD_LED(unsigned int x, bool state);
	  long 		  INT_7SEG(char x);
	  int 		  SEG_OUT(int x, unsigned int base, bool state);

	  extern bool digitalWrite_GPIO(unsigned char PIN, bool state, unsigned char OFFSET);
	  extern bool digitalRead_GPIO(unsigned char PIN, unsigned char OFFSET);

	  //extern bool pinMode_GPIO(unsigned char PIN, unsigned int direction, unsigned char OFFSET);


	  //extern bool INIT_BOARD_LED();
	  extern bool INIT_GPIO();

	  extern bool RESET(unsigned char STATE);
	  extern bool READY(unsigned char STATE);

	  extern bool MACHINE(unsigned char STATE);
	  extern bool STATE_1(unsigned char STATE);
	  extern bool STATE_2(unsigned char STATE);
	  extern bool STATE_3(unsigned char STATE);
	  extern bool STATE_4(unsigned char STATE);
	  extern bool STATE_5(unsigned char STATE);
	  extern bool STATE_6(unsigned char STATE);
	  extern bool STATE_7(unsigned char STATE);

	  void SERVO(unsigned int x, unsigned char DIR);;
	  void DC_MOT(unsigned char DIR, unsigned char SPEED, bool MODE  );
	  void STEPPER(unsigned char DIR, unsigned char SPEED, bool MODE  );
/*********************************************************************************************Functions Prototype*end*/


