/*
 //  __   __  _______  _______  _   ___  _______  _______ 
 // |  |_|  ||       ||       || | |   ||       ||  _    |
 // |       ||  _____||    _  || |_|   ||___    || | |   |
 // |       || |_____ |   |_| ||       | ___|   || | |   |
 // |       ||_____  ||    ___||___    ||___    || |_|   |
 // | ||_|| | _____| ||   |        |   | ___|   ||       |
 // |_|   |_||_______||___|        |___||_______||_______|
 // 
 //
 // 
 // Crazy Machine Group 5 ADD ESE
 // Use only on MSP430FR5739
 // 
 //
 // 
 // 
 // Update Log:>
 // > Last Tested on
 // > 03/10/2014 with Energia ver 0101E0012 MSP430FR5739[1110004350]
 // > 31/08/2014 with Energia ver 0101E0012 MSP430FR5739[1110004350]
 //   
 // 
 */

//==== Global Functions Variables ==========================================================
static int j          = 0; // Animation counter for LCD LINE 0 -> LCD
static int change     = 0; // Animation Sequence LCD LINE 0 -> LCD
static int reset_try  = 0; // Truck RESET counter
static int assume     = 0;
static bool SW2_FLAG  = false;
static char SW_2FLAG_STATE1 = 0;
static char SW_2FLAG_STATE2 = 0;
static char data00[17]; // LCD line 0 array

//==== Global Functions Variables ======================================================END=



//==== STATE =RESET8= [RESET STATE] ========================================================
// >Send 1/0 to DE0 [P2.5]/[P2.6]
// >RESET all machineary to original state
// >after DE0 reset its part; DE0 send 0/1 [P2.5]/[P2.6]
//==== STATE =RESET8= [RESET STATE] ===============================================function=
bool RESET(int STATE){
//===============================================================LCD COMPONENT [RESET] =====  
  sprintf((char *)data00,"<<< RESET #8 >>>");
  lcd.setCursor(0,0);
  lcd.print(data00);
  lcd.setCursor(0,1);
  lcd.print("..PLEASE  WAIT..");
//===============================================================LCD COMPONENT [RESET] =END=

//=============================================================TRUCK COMPONENT [RESET] =====

   if(digitalRead(TP_S1)==HIGH)   
     {
      j = 0;
      change = 0;
      //REPLY READY STATE TO DE0
      lcd.setCursor(0,0);
      lcd.print("MSP430 >>>>> DE0");  
      CARSTOP(); //STOP MOVING CAR
      reset_try = 0;                       //INIT reset_try flag
      SW2_FLAG = false;
      assume = 0;
      DE0_data(DE0_1,HIGH);                 //REPLY DE0
                  
      return true;                         //RESET was DONE
     }
   else
     {
          if(DEBUG) Serial.println("PRESS TAP SWITCH 1");
          digitalWrite(LED7,HIGH);
           if(reset_try == 0)
           {
             CAR(DN);
             reset_try = 1;
           }
           else
           {
             CARSTOP();
             digitalWrite(LED7,LOW);
             re:
                   if(digitalRead(TP_S2)==LOW && SW2_FLAG == false)
                   {
                     if(DEBUG) Serial.println("PRESS TAP SWITCH 2");
                     digitalWrite(LED8,HIGH);
                     CAR(UP);
                     goto re;
                   }
                   else
                   {
                     CAR(DN);       
                     digitalWrite(LED8,LOW);
                     SW2_FLAG = true;
                    }
           }
      for(int i=0;i<8;i++)
      digitalWrite(LED_DATA[i], LOW);   //This will turn all LEDs on board to OFF 
      return false; // NOT yet finish reset //RECURSIVE RESET(STATE) AGAIN
     }
//=============================================================TRUCK COMPONENT [RESET] =END=     
 }
 
//==== STATE =RESET8= [RESET STATE] ====================================================END=



//==== STATE =0= [READY STATE] =============================================================
// >Ready for ball into the machine
// >Send 1/1 to DE0 for RESET STATE /READY STATE =#0=
// >Show LED1 on MSP430 BOARD to show current state
// >Serial Print Current State
// >LCD Animation for INSERT BALL
//==== STATE =0= [READY STATE] ====================================================function=
bool READY(int STATE){
  unsigned int LINE_SENSOR_VAL =  analogRead(LI_SN); //Read value from line sensor
  lcd.setCursor(0,0);
  lcd.print("<<<< INSERT BALL");
  lcd.setCursor(0,1);
  //lcd.print(LINE_SENSOR_VAL);
  lcd.print("   ");
  lcd.print("  READY #");
  lcd.print(STATE);
  lcd.print("   ");  
//=========================================================================LINE SENSOR =====
  if(LINE_SENSOR_VAL < 1020)
  {
    CAR(DN);
  }
  else{CARSTOP();}
  
  if(LINE_SENSOR_VAL < 950) //BALL INSERTED Assume line sensor sensitivity is 900
  {
   pinMode(DE0_1,OUTPUT)	;
   digitalWrite(DE0_1,LOW)	;
   pinMode(DE0_0,OUTPUT)	;
   digitalWrite(DE0_0,LOW)	;
   // change = 0;
    return HIGH;
  }
  else
  {
    pinMode(DE0_1,OUTPUT);
    digitalWrite(DE0_1,HIGH);
    pinMode(DE0_0,OUTPUT);
    digitalWrite(DE0_0,HIGH);
    //DE0_data(DE0_1,HIGH);   //send data bit to DE0
	   if(DEBUG) Serial.println(LINE_SENSOR_VAL);
	   if(DEBUG) Serial.println("TRIG LINE SENSOR");
    return LOW;
  }
//=========================================================================LINE SENSOR =END=
   delay(10000); //for ball roll into truck
}
//==== STATE =0= [READY STATE] =========================================================END=





//==== STATE =1-8= [EVENT #1 STATE] ========================================================
// >Send 0/0 to DE0 for STATE =#1=
//
//==== STATE =1-8= [EVENT #1 STATE] ===============================================function=
bool MACHINE(int STATE){

//=============================================================LCD COMPONENT [MACHINE] =====    
  if (STATE == 1)
    sprintf((char *)data00,"  BALL ENTERED  ");
  if (STATE == 2)
    sprintf((char *)data00,"  TRANSPORTING  ");
  if (STATE == 3)
    sprintf((char *)data00,"    CRUSHING    ");
  if (STATE == 4)
    sprintf((char *)data00,"   COLLECTING   ");
  if (STATE == 5)
    sprintf((char *)data00,"   TRANSITING   ");
  if (STATE == 6)
    sprintf((char *)data00,"LIFT MODE: <^UP>");
  if (STATE == 7)
    sprintf((char *)data00,"      EXIT      ");

  //LCD Print 
  lcd.setCursor(0,0);
  lcd.print(data00);
  lcd.setCursor(0,1);
  lcd.print("    PHASE #");
  lcd.print(STATE);
  lcd.print("    ");
  //LCD Print -END
  
//=============================================================LCD COMPONENT [MACHINE] =END=   
  //if (STATE == 1){S1(STATE);}
  
  if(digitalRead(DE0_1) == HIGH && (STATE == 1 || STATE == 3 || STATE == 5)){ //ODD STATE
    return HIGH;
  }
  else if(digitalRead(DE0_1) == LOW  && (STATE == 2 || STATE == 4 || STATE == 6)){ //EVEN STATE
    return HIGH;
  }
  else if(digitalRead(DE0_0) == HIGH && STATE == 7){
    return HIGH;
  }
  else
  {
    return LOW; //NO STATE CHANGE
  }
  
}
//==== STATE =1-7= [EVENT #1 STATE] ====================================================END=



bool S1(int STATE){
  
  if(STATE == 1){
    CARSTOP();
    delay(1000); //wait ball drops
    pinMode(TP_S2,INPUT);
    pinMode(TP_S3,INPUT);
    pinMode(LED1,OUTPUT);
    pinMode(LED2,OUTPUT);   
	
   state_1_SW2_poll: 
   if(digitalRead(TP_S2)==LOW && SW_2FLAG_STATE1 == 0)
     {
         digitalWrite(LED1,HIGH);
         CAR(UP);
         goto state_1_SW2_poll;
     }
	 
   SW_2FLAG_STATE1 = 1;
   CARSTOP();
   
   delay(1000); //wait for track change
   
   state_1_SW3_poll:   
   if(digitalRead(TP_S3)==LOW && SW_2FLAG_STATE1 == 1)
   {
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    //digitalWrite(TR_SE,HIGH); //send high bit to DE0 TR_SERVO
    CAR(DN);
    SW_2FLAG_STATE1 = 1;  
    goto state_1_SW3_poll;
   }
   else
   {
     digitalWrite(LED2,LOW);
    //continue backward to apply PWM for small servo
     CAR(DN);//
     SW_2FLAG_STATE1 = 0;
     return true;
    // DE0_data(DE0_1,HIGH);
   }
  }
  return false;
}

bool S2(int STATE){
  if(STATE == 2){
  CARSTOP();
  CAR(UP);
  
  sw2_state2:
  if(digitalRead(TP_S2)==LOW && SW_2FLAG_STATE2 == 0){
	CAR(UP);
	SW_2FLAG_STATE2 = 0;
	goto sw2_state2;
	}
	else {
	CARSTOP();
	SW_2FLAG_STATE2 = 1;}
	
  delay(1000); //wait for track change

  sw1_state2:
    if(digitalRead(TP_S1)==LOW && SW_2FLAG_STATE2 == 1){
	CAR(DN);
	SW_2FLAG_STATE2 = 1;
	goto sw1_state2;
	}
	else {
	CARSTOP();
	SW_2FLAG_STATE2 = 0;
	return true;
	}
  }
  return false;
}

bool delay_ms(int x){delay(x); return true;}

bool DE0_data(char PIN_OUT, bool MODE){
   pinMode(PIN_OUT,OUTPUT);
   digitalWrite(PIN_OUT,MODE);
   delay_ms(500);
   digitalWrite(PIN_OUT,!MODE);
   pinMode(PIN_OUT,INPUT);
   return true;
}

void CAR(bool x){ //UP DOWN
  if(x == UP){pinMode(RC_UP,OUTPUT); digitalWrite(RC_UP,LOW);}
  else  {pinMode(RC_DN,OUTPUT); digitalWrite(RC_DN,LOW);}
  }

void CARSTOP(){
 pinMode(RC_UP,OUTPUT); digitalWrite(RC_UP,HIGH);
 pinMode(RC_DN,OUTPUT); digitalWrite(RC_DN,HIGH);
}
