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
 * THIS IS MAIN FUNCTION C FILE
 *
 * Must include
 * 			>"DE0.h"
 * 			>"DE0.c"
 * 			>"type_bool.h" on BSP folder
 *
 *  Close Source -- CRAZY MACHINE PROJECT GROUP 5 ONLY
 *
 *
 *  Update Log:>
 *  > Last Tested On:
 * 			 > 11/10/2014 with NIOS II Eclipse 13.0 on DE0.
 * 			 > 03/10/2014 with NIOS II Eclipse 13.0 on DE0.
 *
 *  More about coding NIOS2 on DE0
 *  REF: http://www-ug.eecg.toronto.edu/msl/nios_devices/
 *
*/


/*********************************************************************************************************************
 * 																									 C Program Heading
 * -> Last Update 30/09/2014 11:09PM [Alex Lim]
 *********************************************************************************************************************/
	#include <stdio.h>
	#include <string.h>
	#include <system.h>
	#include <math.h>
	#include "DE0.h"
/*********************************************************************************************************Heading*end*/

//==== Global Functions Variables =====================================================================================

	//==== DEBUG SETUP =========================================================================
	bool DEBUG_MSP  = false; // true;
	bool DEBUG		= false;
	//==== DEBUG SETUP =====================================================================END=

	unsigned char STATE          = 8;         // STATE machine counter -Start from RESET state = 8
	unsigned char BALL_WAIT_FLAG = 0;
	unsigned int POLL_COUNT	     = 0;

//==== Global Functions Variables =================================================================================END=


int main()
{
//======================================================================================================================
//  																							     | Initialize zone |
//======================================================================================================================
  INIT_GPIO()		; 				//REMOVE PAST VALUE ON GPIO REGISTER
//==== Initialize zone =============================================================================================END=
int var = 0;
//======================================================================================================================
//  																										    | LOOP |
//======================================================================================================================
while(1)
{
	//DEBUG MSP430=============================================================================
	  if(*SW_switch_ptr == 0x80 || DEBUG_MSP){
		  	SEG_OUT(430,DEC,true);
		  	INIT_GPIO();
	  		while(1){
//	  			 unsigned char i = 0;
//			  while (i<4)
//				  {
//					 *(ADDR_JP2PORT + i + 4) = 0xFF; //set every bit direction to output
//					 i++;
//				  }
//					i = 0;
//	  			digitalWrite_GPIO(PR_SN,LOW,0);
//	  			digitalWrite_GPIO(PR_SN,LOW,0);
//	  			digitalWrite_GPIO(PR_SN,LOW,0);
//	  			digitalWrite_GPIO(PR_SN,LOW,0);
//	  			digitalWrite_GPIO(PR_SN,LOW,0);
//	  			digitalWrite_GPIO(PR_SN,LOW,0);
//	  			digitalWrite_GPIO(PR_SN,LOW,0);
//				digitalWrite_GPIO(PR_SN,LOW,0);
//
//				while(digitalRead_GPIO(PR_SN,0) == 0 )
//						  {digitalWrite_GPIO(PR_SN,LOW,0);
//						  DELAY_CYCLES(1);}			//SIGNAL SEND TO MSP430};};//digitalRead_GPIO(GPIO2_1,0) == 0){}//poll high
//					  count++;
//
//				SEG_OUT(count,DEC,true);

					//STEPPER(0x0, 0x2, TRUE);
					//DC_MOT(0x1,0x4,TRUE);
					SERVO(0,var); //90degree
					DELAY_CYCLES(1);
					SERVO(1,var); //90degree
					DELAY_CYCLES(100000);
					var++;
					if(var ==0x1F){
						var = 0;
					}
				    *ADDR_JP2PORT  = *SW_switch_ptr;    //USE SW0 SW1 TO CONTROL GPIO2_0  GPIO2_1
				    *RASPI_PIN     = *SW_switch_ptr;	//USE SW0 to control RASPI_PIN
			  }
	  	  }
	  else{}

    //DEBUG MSP430=========================================================================END=


//==== MAIN STATE MACHINE ================================================================================================

  while(*SW_switch_ptr != 0x80 && STATE<9)
  {
      if(!DEBUG){
         printf("\nDE0_GPIO2_0 STATUS: ");
         printf("%d",(int)digitalRead_GPIO(GPIO2_0,0));
         printf("\nDE0_GPIO2_1 STATUS: ");
         printf("%d",(int)digitalRead_GPIO(GPIO2_1,0));
         printf("\n");
      }

	  //==============================================================================RESET=
		if(STATE == 8)
		{
	         if(DEBUG) printf("\nCurrent STATE: ");
	         if(DEBUG) printf("%d",(int)STATE);
	         if(DEBUG) printf("\n");

			 //SEND SIGNAL TO RASPI //PLAY SONG [1.mp3]
			 *RASPI_PIN = 0x1;

			//MSP430 SIGNAL [1/0]
			digitalWrite_GPIO(GPIO2_0,HIGH,0);			//SIGNAL SEND TO MSP430
			digitalWrite_GPIO(GPIO2_1,LOW ,0);			//SIGNAL SEND TO MSP430

			SEG_OUT(STATE,DEC,TRUE);				    //PRINT STATE ON 7SEG

			if(RESET(STATE) == TRUE) {
				digitalWrite_GPIO(GPIO2_1,LOW ,0);		//SIGNAL SEND TO MSP430
				while(digitalRead_GPIO(GPIO2_1,0) == 0){DELAY_CYCLES(1);}//poll high
				STATE++;
			}
			else{}

		}
		else{}
	  //===========================================================================RESET=END=

	  //==============================================================================READY=
		if(STATE == 0)
		{
			 if(DEBUG) printf("\nCurrent STATE: ");
			 if(DEBUG) printf("%d",(int)STATE);
			 if(DEBUG) printf("\n");

			digitalWrite_GPIO(GPIO2_0,HIGH,0);			//SIGNAL SEND TO MSP430
			digitalWrite_GPIO(GPIO2_1,HIGH,0);			//SIGNAL SEND TO MSP430



			SEG_OUT(STATE,DEC,TRUE);				//PRINT STATE ON 7SEG

			if(READY(STATE) == TRUE) {
				while(digitalRead_GPIO(GPIO2_0,0) == 1){DELAY_CYCLES(1);}	//COMMENT WHEN DEBUG //POLL LOW FROM MSP430 ON P2_5/GPIO2_0 //BALL ENTER //PROB
				//DELAY_CYCLES(1000);
				STATE++;
			}
		  else{}
		}

	  //===========================================================================READY=END=

      //=============================================================================STATES =
		if(STATE>0 && STATE <8)
		{
			 if(DEBUG) printf("\nCurrent STATE: ");
			 if(1) printf("%d",(int)STATE);
			 if(1) printf("\n");

			//MSP430 SIGNAL [1/0]
			 if(STATE != 7 ){digitalWrite_GPIO(GPIO2_0, LOW,0);}

			 if(STATE == 1 || STATE == 3 || STATE == 5)
			 {
				 digitalWrite_GPIO(GPIO2_1 ,HIGH,0) ;			//SIGNAL SEND TO MSP430
				 if(MACHINE(STATE))
					 STATE = STATE + 1;
			 }

			 else if(STATE == 2 || STATE == 4 || STATE == 6)
			 {
				 digitalWrite_GPIO(GPIO2_1 ,LOW,0) ;			//SIGNAL SEND TO MSP430
				 if(MACHINE(STATE))
					 STATE = STATE + 1;
			 }

			 else if(STATE == 7 )
			 {
				 digitalWrite_GPIO(GPIO2_0, HIGH,0) ;			//SIGNAL SEND TO MSP430
				 if(MACHINE(STATE))
					 STATE = STATE + 1;
			 }
			 else{}

		}
	   //=============================================================================STATES =

		else{};
  }
  STATE = 0;

}
//======================================================================================================================
//  																									   | LOOP- END |
//======================================================================================================================

  return 0;
}

//==== MAIN ========================================================================================================END=
