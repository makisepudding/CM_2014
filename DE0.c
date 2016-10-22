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
 * THIS IS Functions C FILE => DE0.c
 *
 * Must include
 * 			>"DE0.h"
 *
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
	#include "DE0.h"

/*********************************************************************************************************Heading*end*/





/*********************************************************************************************************************
 * 																									   		 Functions
 * -> Always put a short description on newly created function.
 * -> Last Update 30/09/2014 11:18PM [Alex Lim]
 *********************************************************************************************************************/
	/****************************************************************************************************************
	 * FUNCTION: DELAY_CYCLES(unsigned long x)
	 * > Return Logic Boolean, when delay is done, will return TRUE
	 * DESP:
	 * 	unsigned long x: number of clock cycle delay
	 ****************************************************************************************************************/
	  extern bool DELAY_CYCLES(unsigned long x){
		  unsigned long delay_i;
		  for(delay_i = 0; delay_i <= x; ++delay_i){};
		  return TRUE;
	  }
	 /****************************************************************************************************************/



	/****************************************************************************************************************
	 * FUNCTION: BOARD_LED(unsigned int x, bool state)
	 * > Return Logic Boolean [TRUE/FALSE]
	 * DESP:
	 * 	int x		: control which LED on the DE0 board, i.e. x = LEDG1; LEDG1 on the board will be selected
	 * 	bool state	: Either Switch HIGH/LOW on the specified LED
	 *
	 *
	 *
	 * 	LEDG NOT USING ANYMORE
	 ****************************************************************************************************************/
//	  extern bool BOARD_LED(unsigned int x, bool state){
//	  	int temp = * green_LED_ptr;
//	  	//int LED_Array[10] = {LEDG0, LEDG1, LEDG2, LEDG3, LEDG4, LEDG5, LEDG6, LEDG7, LEDG8, LEDG9};
//	  	  if(state){
//	  	    *green_LED_ptr = temp | x;//LED_Array[x];
//	  	    return TRUE;
//	  	    }
//	  	  else if(!state){
//	  		temp = * green_LED_ptr;
//	  		*green_LED_ptr = temp &~ x;//LED_Array[x];
//	  		return TRUE;
//	  		}
//	  	  else
//	  		return FALSE;
//	  }
	 /****************************************************************************************************************/


	/****************************************************************************************************************
	 * FUNCTION: INT_7SEG(char x)
	 * > Return integer value that translated into 7segment binary
	 * DESP:
	 * char x: value to display on 7segment 0<->F
	 ****************************************************************************************************************/
	  long INT_7SEG(char x){
		  long seg;
			switch (x){
			case '0': seg = 0x3F; break;
			case '1': seg = 0x06; break;
			case '2': seg = 0x5B; break;
			case '3': seg = 0x4F; break;
			case '4': seg = 0x66; break;
			case '5': seg = 0x6D; break;
			case '6': seg = 0x7D; break;
			case '7': seg = 0x07; break;
			case '8': seg = 0x7F; break;
			case '9': seg = 0x6F; break;
			case 'A': seg = 0x77; break;
			case 'B': seg = 0x7C; break;
			case 'C': seg = 0x39; break;
			case 'D': seg = 0x5E; break;
			case 'E': seg = 0x79; break;
			case 'F': seg = 0x71; break;
			default:
				seg = 0x00; break;
			}
			return seg;
		}

	/****************************************************************************************************************
	 * FUNCTION: SEG_OUT(int x, unsigned int base, bool state)
	 * > Return integer value that output on the 7segments
	 * > Must include header with function: INT_7SEG(char x)
	 * DESP:
	 * int x				: value to ouput as on four 7segments
	 * unsigned int base	: 	#define DEC 0x10    ;    #define HEX 0x11
	 * bool state			: Switch On/Off 7segments
	 ****************************************************************************************************************/

	  int SEG_OUT(int x, unsigned int base, bool state){
	  	char data[4];
	  	if(state){
	  		if(base == 0x10)
	  			sprintf((char *)data, "%04d",x); // as DEC
	  		else if(base == 0x11 )
	  			sprintf((char *)data, "%04X",x); // as HEX
	  		else{};
	  		}
	  	else{
	  		sprintf((char *)data, "%c",'G'); // as HEX SWITCH OFF
	  	}

	  	long HEX_DATA[4];
	  	int i,j;
	  	long sum = 0x00000000;

	  	for(i = 3; i >=0 ; --i){
	  		j = 3-i;
	  		HEX_DATA[i] = INT_7SEG(data[j]);
	  	}
	  	sum = (HEX_DATA[3]  <<24) + (HEX_DATA[2]  <<16) + (HEX_DATA[1] <<8) + HEX_DATA[0];
	  	*(HEX3_HEX0_ptr) = sum;
	  	return sum;
	  }
	 /****************************************************************************************************************/



	/****************************************************************************************************************
	 * FUNCTION: digitalWrite_GPIO(unsigned char PIN, bool state)
	 * > Return Logic Boolean [TRUE/FALSE]
	 * > Must set pinMode_GPIO(PIN, OUTPUT) as OUTPUT
	 * DESP:
	 * 	unsigned char PIN		: control which LED on the DE0 board, i.e. x = LEDG1; LEDG1 on the board will be selected
	 * 	bool state				: Either Switch HIGH/LOW on the specified LED
	 ****************************************************************************************************************/
	  extern bool digitalWrite_GPIO(unsigned char PIN, bool state, unsigned char OFFSET){

		unsigned char temp_J2 		 = *(ADDR_JP2PORT + OFFSET)          ; //Address PTR
		*(ADDR_JP2PORT + OFFSET + 4) = *(ADDR_JP2PORT + OFFSET + 4) | PIN; //SET PIN BIT AS OUTPUT

	  	if(state)	*(ADDR_JP2PORT + OFFSET) = temp_J2 |  PIN;
	  	else	    *(ADDR_JP2PORT + OFFSET) = temp_J2 &~ PIN;
	  	return TRUE;
	  }
     /****************************************************************************************************************/

	/****************************************************************************************************************
	 * FUNCTION: digitalRead_GPIO(unsigned char PIN)
	 * > Return Logic Boolean [TRUE/FALSE]
	 * > Must set pinMode_GPIO(PIN, OUTPUT) as INPUT
	 * DESP:
	 * 	unsigned char PIN		: control which LED on the DE0 board, i.e. x = LEDG1; LEDG1 on the board will be selected
	 ****************************************************************************************************************/
	  extern bool digitalRead_GPIO(unsigned char PIN, unsigned char OFFSET){
		*(ADDR_JP2PORT + OFFSET + 4) = *(ADDR_JP2PORT + OFFSET + 4) &~ PIN; //SET PIN BIT AS INPUT
	    unsigned char temp_J2        = *(ADDR_JP2PORT + OFFSET)   ; //Address PTR


		if((temp_J2 & PIN) == PIN) //if 11000110,ADDR_JR2PORT & 00000100,PIN = 00000100 == PIN
			return HIGH;
		else
			return LOW;
	  }
	 /****************************************************************************************************************/


/********************************************************************************************************Functions*end*/



/*********************************************************************************************************************
 * 																							  Initialization Functions
 * -> Always start with "INIT_"
 * -> Always put a short description on newly created initialization function.
 * -> Last Update 30/09/2014 11:18PM [Alex Lim]
 *********************************************************************************************************************/

	/****************************************************************************************************************
	 * FUNCTION: INIT_BOARD_LED()
	 * > Return Logic Boolean [TRUE/FALSE]
	 * DESP:
	 * Show some LED pattern
	 * TURN OFF ALL LEDS ON DE0 at the end
	 *
	 * LEDG NOT USING ANYMORE
	 ****************************************************************************************************************/
//	  extern bool INIT_BOARD_LED(){
//		  *green_LED_ptr = 0x00000000;
//		 return TRUE;
//	  }
	 /****************************************************************************************************************/


	/****************************************************************************************************************
	 * FUNCTION: INIT_GPIO()
	 * > Return Logic Boolean [TRUE/FALSE]
	 * DESP:
	 * initialized GPIO on J5 IDE Port
	 ****************************************************************************************************************/
	  extern bool INIT_GPIO(){
		  //*MSP430_TR_SE = 0;
		  //*SERVO_PIN  = 0;
	  	   // INIT GPIO directions
		  *ADDR_JP2PORT = 0;
		  *(ADDR_JP2PORT+4) = 0;
		  DC_MOT(0x0,0x4,0x0); //STOP DC MOTOR
		  SERVO(0, 0);
		  DELAY_CYCLES(1000);
		  SERVO(1, 0);
		  DELAY_CYCLES(1000);
		  unsigned char i = 0;
	  		  while (i<4)
	  		  {
	  			 *(ADDR_JP2PORT + i + 4) = 0xFF; //set every bit direction to output
	  		     i++;
	  		  }
				i = 0;
	  		    *(ADDR_JP2PORT)   = 0X00;
	  			*(ADDR_JP2PORT+1) = 0X00;
	  			*(ADDR_JP2PORT+2) = 0X00;
	  			*(ADDR_JP2PORT+3) = 0X00;
	  	  digitalWrite_GPIO(PR_SN,LOW,0);
	  		    return TRUE;
	  		 }
	  /****************************************************************************************************************/




/*********************************************************************************************************************
* 																							  Machines Functions
* -> Last Update 11/10/2014 11:18PM [Alex Lim]
*********************************************************************************************************************/
  extern bool RESET(unsigned char STATE){

	  //SERVO 0 = TRACK
	  //SERVO 1 = TRUCK

	  while(*MSP430_TR_SE == 1);
	  SERVO(0, 0X1F);
	  DC_MOT(0x0,0x4,FALSE); //STOP SERVO
	  //STEPPER(0x0, 0x2, TRUE); RESET LIFT
	  digitalWrite_GPIO(LED_G,LOW,0);			    //LED GREEN
	  digitalWrite_GPIO(LED_R,HIGH,0);			//LED RED
	  DELAY_CYCLES(100000);
	  return TRUE;}

  extern bool READY(unsigned char STATE){
	  DELAY_CYCLES(100000);
	  SERVO(0, 0X1F);
	  return TRUE;}




  extern bool MACHINE(unsigned char STATE){
	  SEG_OUT(STATE,DEC,TRUE)			;

	  if(STATE ==1)	{STATE_1(STATE);	}
	  else if(STATE ==2)	{STATE_2(STATE);	}
	  else if(STATE ==3)	{STATE_3(STATE);	}
	  else if(STATE ==4)	{STATE_4(STATE);	}
	  else if(STATE ==5)	{STATE_5(STATE);	}
	  else if(STATE ==6)	{STATE_6(STATE);	}
	  else if(STATE ==7)	{STATE_7(STATE);	}
	  else {return FALSE;}
	  return TRUE;
  }

  //=============================================================================STATE 1=
  extern bool STATE_1(unsigned char STATE){
	  if(STATE == 1)
	  {
		  //Play Sound on Raspi
			digitalWrite_GPIO(GPIO2_0,LOW,0);			//SIGNAL SEND TO MSP430
			digitalWrite_GPIO(GPIO2_1,LOW ,0);			//SIGNAL SEND TO MSP430

		 //SEND SIGNAL TO RASPI //PLAY SONG [2.mp3]
		 *RASPI_PIN = 0x0;

		  digitalWrite_GPIO(GPIO2_1,HIGH,0);	//NOT SURE WHY -SCUMBAG MSP430
		  while(*MSP430_TR_SE == 0x0){DELAY_CYCLES(1);}			//SIGNAL SEND TO MSP430};
		  SERVO(0, 0X1F);
		  DELAY_CYCLES(1000);
		  digitalWrite_GPIO(GPIO2_1,HIGH,0);     //NOT SURE WHY -SCUMBAG MSP430
		  while(digitalRead_GPIO(GPIO2_3,0) == 0 )
				  {DELAY_CYCLES(1);}			//SIGNAL SEND TO MSP430};};//digitalRead_GPIO(GPIO2_1,0) == 0){}//poll high
		  return TRUE;
	  }
	  else{return FALSE;}
  }
  //==========================================================================STATE 1=END=

  //=============================================================================STATE 2=
  extern bool STATE_2(unsigned char STATE){
	  if(STATE == 2)
	  {
			digitalWrite_GPIO(GPIO2_0,LOW,0);			//SIGNAL SEND TO MSP430
			digitalWrite_GPIO(GPIO2_1,HIGH ,0);			//SIGNAL SEND TO MSP430
		  //Play Sound on Raspi
		  DELAY_CYCLES(1000000);
			digitalWrite_GPIO(PR_SN,LOW,0);
			digitalWrite_GPIO(PR_SN,LOW,0);
			digitalWrite_GPIO(PR_SN,LOW,0);
			digitalWrite_GPIO(PR_SN,LOW,0);
		  return TRUE;
	  }
	  else{return FALSE;}
  }
  //==========================================================================STATE 2=END=

  //=============================================================================STATE 3=
  extern bool STATE_3(unsigned char STATE){
	  int count=0;
	  if(STATE == 3)
	  {
			digitalWrite_GPIO(GPIO2_0,LOW,0);			//SIGNAL SEND TO MSP430
			digitalWrite_GPIO(GPIO2_1,LOW ,0);			//SIGNAL SEND TO MSP430
			sensor:
			 //POLL PRESSURE SENSOR,
			  //while(digitalRead_GPIO(PR_SN,0) == 1 )
				//	  {DELAY_CYCLES(1);}

  			digitalWrite_GPIO(PR_SN,LOW,0);
			while(digitalRead_GPIO(PR_SN,0) == 0 )
					  {digitalWrite_GPIO(PR_SN,LOW,0);
					  DELAY_CYCLES(1);
					  }			//SIGNAL SEND TO MSP430};};//digitalRead_GPIO(GPIO2_1,0) == 0){}//poll high
				  count++;
			  count ++;

			  SEG_OUT(count,DEC,true);
			  if(count < 2000){goto sensor;}
			  else{}
			 //LIGHTS UP LEDS R G B
			 //digitalWrite_GPIO(LED_R,HIGH,0);			//LED RED
			 digitalWrite_GPIO(LED_R,LOW ,0);			//LED RED
			 DELAY_CYCLES(100000);
			 digitalWrite_GPIO(LED_Y,HIGH ,0);			//LED YELLOW
			 DELAY_CYCLES(50000);
			 digitalWrite_GPIO(LED_G,HIGH ,0);			//LED GREEN
			 DELAY_CYCLES(100000);
			 digitalWrite_GPIO(LED_Y,LOW ,0);			//LED YELLOW



			 //SEND SIGNAL TO RASPI //PLAY SONG [3.mp3]
			 *RASPI_PIN = 0x1;
			 DC_MOT(0x0,0x4,TRUE);
			 //Play Sound on Raspi
			 DELAY_CYCLES(1000000);
			 //control SERVO TRACK SERVO
		  return TRUE;
	  }
	  else
	  {return FALSE;}
  }
  //==========================================================================STATE 3=END=

  //=============================================================================STATE 4=
  extern bool STATE_4(unsigned char STATE){
	  if(STATE == 4)
	  {
			digitalWrite_GPIO(GPIO2_0,LOW,0);			//SIGNAL SEND TO MSP430
			digitalWrite_GPIO(GPIO2_1,HIGH ,0);			//SIGNAL SEND TO MSP430
		  //Play Sound on Raspi
		  DELAY_CYCLES(1000000);
		  return TRUE;
	  }
	  else{return FALSE;}
  }
  //==========================================================================STATE 4=END=

  //=============================================================================STATE 5=
  extern bool STATE_5(unsigned char STATE){
	  if(STATE == 5)
	  {
			digitalWrite_GPIO(GPIO2_0,LOW,0);			//SIGNAL SEND TO MSP430
			digitalWrite_GPIO(GPIO2_1,LOW ,0);			//SIGNAL SEND TO MSP430

			 //SEND SIGNAL TO RASPI //PLAY SONG [4.mp3]
			 *RASPI_PIN = 0x0;

		  //Play Sound on Raspi
		  DELAY_CYCLES(1000000);
		  return TRUE;
	  }
	  else{return FALSE;}
  }
  //==========================================================================STATE 5=END=

  //=============================================================================STATE 6=
  extern bool STATE_6(unsigned char STATE){
	  if(STATE == 6)
	  {
			digitalWrite_GPIO(GPIO2_0,LOW,0);			//SIGNAL SEND TO MSP430
			digitalWrite_GPIO(GPIO2_1,HIGH ,0);			//SIGNAL SEND TO MSP430

			while(digitalRead_GPIO(GPIO2_4,0) == 0 )
					  {DELAY_CYCLES(1);}			//SIGNAL SEND TO LIFT};};//digitalRead_GPIO(GPIO2_1,0) == 0){}//poll high

			STEPPER(0x0, 0x2, TRUE); //DRIVE LIFT MOTOR

		  //Play Sound on Raspi
		  DELAY_CYCLES(1000000);
		  return TRUE;
	  }
	  else{return FALSE;}
  }
  //==========================================================================STATE 6=END=

  //=============================================================================STATE 7=
  extern bool STATE_7(unsigned char STATE){
	  if(STATE == 7)
	  {
			digitalWrite_GPIO(GPIO2_0,LOW,0);			//SIGNAL SEND TO MSP430
			digitalWrite_GPIO(GPIO2_1,LOW ,0);			//SIGNAL SEND TO MSP430

			STEPPER(0x0, 0x2, FALSE); //STOP LIFT MOTOR
		  //Play Sound on Raspi
		  DELAY_CYCLES(1000000);
		  return TRUE;
	  }
	  else{return FALSE;}
  }
  //==========================================================================STATE 7=END=


  void SERVO(unsigned int x, unsigned char SPEED) //DIR 1 = LEFT 0 = RIGHT
  {
	  //AVOID USING OVER )0x8F for BIG SERVO
	if(x == 0){
			  *SERVO_P0= SPEED;
			  }
	if(x == 1){
		      *SERVO_P1= SPEED;
	}
  }

void DC_MOT(unsigned char DIR, unsigned char SPEED, bool MODE  )
	{
			*DC_MOT_DIR  = DIR; // 0x0 anti clock wise; 0x1 clockwise
			*DC_MOT_SEL  = SPEED; // 0x0 - fastest 0x2 - mid 0x4 - slow //0x1 not useable
			if(MODE){*DC_MOT_STOP = 0x1;} // 0x0 STOP ; 0x1 RUN
			else{*DC_MOT_STOP = 0x0;} // 0x0 STOP ; 0x1 RUN
	}

void STEPPER(unsigned char DIR, unsigned char SPEED, bool MODE  )
	{
			*STEP_DIR  = DIR; // 0x1 anti clock wise; 0x0 clockwise
			*STEP_SEL  = SPEED; //0x2 FASTEST //0x1 MID //0x0 SLOW //0x3 SLOWEST
			if(MODE){*STEP_STOP = 0x1;} // 0x0 STOP ; 0x1 RUN
			else{*STEP_STOP = 0x0;} // 0x0 STOP ; 0x1 RUN
	}
