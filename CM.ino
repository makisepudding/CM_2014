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
 // Must include
 // > STATE_MACHINE.ino
 //
 // Close Source -- CRAZY MACHINE PROJECT GROUP 5 ONLY 
 // 
 // Update Log:>
 // > Last Tested on
 // > 11/10/2014 with Energia ver 0101E0012 MSP430FR5739[1110004350]
 // > 03/10/2014 with Energia ver 0101E0012 MSP430FR5739[1110004350]
 // > 31/08/2014 with Energia ver 0101E0012 MSP430FR5739[1110004350]
 //   
 // 
 */

#if defined(__MSP430FR5739__)
#include "Energia.h"
#else // error
#error MSP430FR5739 ONLY
#endif

#define UP true
#define DN false

//==== HEADER FILES ========================================================================
//#include <Servo.h>              //Servo Control Library
#include <Wire.h>                 //I2C Config Library
#include <LiquidCrystal_I2C.h>    //I2C LCD Library -Modified
//==== HEADER FILES ====================================================================END=

//==== LCD SETUP ===========================================================================
LiquidCrystal_I2C lcd(0x27,16,2);  //I2C LCD Address 0x27 for 16x2 display
//==== LCD SETUP =======================================================================END=

//==== DEBUG SETUP =========================================================================
bool DEBUG = true;
bool FIRSTBOOT = true;
//==== DEBUG SETUP =====================================================================END=

//==== SERVO SETUP =========================================================================
//Servo TRACK_SERVO;                 //Object for Class Servo
//==== SERVO SETUP =====================================================================END=

//==== Global constants ====================================================================
#define printByte(args)  write(args);  //For Printing on LCD 

//CONFIG PINS=============================================================================
unsigned char RC_DN = P2_1; //REMOTE CONTROL PIN FW     --DIGITAL 1 bit [O]
unsigned char RC_UP = P2_2; //REMOTE CONTROL PIN BW     --DIGITAL 1 bit [O]
//unsigned char TR_SE = P1_3; //TRACK SERVO PIN ON DE-0   --DIGITAL 1 bit [O]
unsigned char DE0_0 = P2_5; //DE0 GPIO2_0 <-> MSP DE0_0 --DIGITAL 1 bit [I/O]
unsigned char DE0_1 = P2_6; //DE0 GPIO2_1 <-> MSP DE0_1 --DIGITAL 1 bit [I/O]
unsigned char TP_S1 = P1_4; //TAP_SW1                   --DIGITAL 1 bit [I] //TRUCK rest bay
unsigned char TP_S2 = P1_5; //TAP_SW2                   --DIGITAL 1 bit [I] //3 point turn
unsigned char TP_S3 = P4_0; //TAP_SW3                   --DIGITAL 1 bit [I] //loading bay
unsigned char LI_SN = P1_1; //LINE SENSOR               --ANALOG  16 bit => 1024dec [I]
unsigned char RASPI = P1_0; //RASPI-BOOT DETECTOR       --DIGITAL 1 bit
//========================================================================================

const int LED_DATA[9] = {
  LED1, LED2, LED3, LED4, LED5, LED6, LED7, LED8}; // LEDs array  
//==== Global constants ================================================================END=

//==== Global variables ====================================================================
unsigned char iLED         = 0;         // Array selector for LED_DATA : Counter
unsigned char aLED         = 0;         // Array selector for LED_DATA : OFF
unsigned char STATE        = 8;         // STATE machine counter -Start from RESET state = 8
int LCD_COUNT;
//==== Global variables ================================================================END=


//==== Initialize zone =====================================================================
void setup()
{
  if(DEBUG){Serial.begin(9600);}                 //COM data setup
 
  lcd.init()        ;                 //init I2C LCD
  lcd.backlight()   ;                 //Enable Backlight on LCD

//CAR CONTROL INTERFACE INIT
  CARSTOP();

  for(int i=0;i<9;i++){
    pinMode(LED_DATA[i],   OUTPUT);   //This will switch ON the LEDs
    digitalWrite(LED_DATA[i], LOW);   //This will init LED to OFF
  }                                   //init all LEDs on MSP430's board
  
  pinMode(DE0_0, INPUT);              //DE0 PINS
  pinMode(DE0_1, INPUT);              //DE0 PINS
  pinMode(RC_UP, INPUT);              //INIT CAR pin FW //STOP CAR
  pinMode(RC_DN, INPUT);              //INIT CAR pin BW //STOP CAR
  pinMode(LI_SN, INPUT);              //INIT LINE SENSOR
  pinMode(RASPI, INPUT);              //RASPI DETEC INIT
  //pinMode(TR_SE, OUTPUT);             //INIT SERVO LINK DE0
  
  lcd.setCursor(0,0)           ;      //Print MSP430 STATUS 
  lcd.print(" CM GROUP5 2014 ");  
  lcd.setCursor(0,1)           ;
  lcd.print(" Starting...... ");  
  delay(100);
  int i = 0;
  pinMode(DE0_1, OUTPUT);              //DE0 PINS
  while(1){//digitalRead(DE0_0) == LOW || digitalRead(RASPI)==LOW
    digitalWrite(DE0_1,LOW);
    pinMode(LED_DATA[i],   OUTPUT);   //This will switch ON the LEDs
    digitalWrite(LED_DATA[i], HIGH);   //This will init LED to OFF
    digitalWrite(LED_DATA[i-1],LOW);   //This will init LED to OFF
      lcd.init()        ;                 //init I2C LCD
      lcd.backlight()   ;                 //Enable Backlight on LCD
    if(digitalRead(RASPI) == LOW){
      lcd.setCursor(0,0)           ;      //Print MSP430 STATUS 
      lcd.print("RASPI BOOTING LX");}
    else{
      lcd.setCursor(0,0)           ;      //Print MSP430 STATUS 
      lcd.print("RASPI      READY");}
      
    if(digitalRead(DE0_0) == LOW){
      lcd.setCursor(0,1)           ;
      lcd.print("DE-0   NOT READY");}
    else{
      lcd.setCursor(0,1)           ;
      lcd.print("DE-0       READY");}
      
    if(digitalRead(DE0_0) == HIGH && digitalRead(RASPI)==HIGH){
      // pinMode(DE0_1, INPUT);              //DE0 PINS
      break;}
    else{
      i++; if(i>9){i = 0;}
    }
    }
      i = 0;
      lcd.setCursor(0,0)           ;      //Print MSP430 STATUS 
      lcd.print("RASPI      READY");
      lcd.setCursor(0,1)           ;
      lcd.print("DE-0       READY");
  }
//==== Initialize zone =================================================================END=



//==== MAIN STATE MACHINE ===================================================================
void loop()
{
  if(STATE == 0)
  {
    lcd.setCursor(0,0)           ;      //Print MSP430 STATUS 
    lcd.print(". #Calibrating .");
    lcd.setCursor(0,1)           ;
    lcd.print("..PLEASE  WAIT..");
    delay(4000);
  }
  while(STATE <9)
    {
      //==============================================================================RESET=
        if(digitalRead(DE0_0) == HIGH && digitalRead(DE0_1) == LOW && STATE == 8)
        {
         //================================================================NOISE PREVENTION= 
         pinMode(DE0_1,OUTPUT);
         digitalWrite(DE0_1,LOW); //SET PIN TO GND AVOID NOISE TRIGGER DE0
         //================================================================NOISE PREVENTION= 
         
         //====================================================ACTION
         if(RESET(STATE) == true) {STATE++;}
         //====================================================ACTION         
        }

        else{}
      //===========================================================================RESET=END=
      

	  
      //==============================================================================READY=
        if((digitalRead(DE0_0) == HIGH && digitalRead(DE0_1) == HIGH && STATE == 0) || (digitalRead(DE0_0) == LOW && digitalRead(DE0_1) == HIGH && STATE == 0) || (digitalRead(DE0_0) == LOW && digitalRead(DE0_1) == LOW && STATE == 0) || (digitalRead(DE0_0) == HIGH && digitalRead(DE0_1) == LOW && STATE == 0))
        {
         if(DEBUG) Serial.print("\nCurrent STATE: ");
         if(DEBUG) Serial.println(STATE); 
         
         if(READY(STATE) == true) {STATE++;}
         else{}          
        }
      //===========================================================================READY=END=         
      
           
      //=============================================================================STATE 1=
        if(digitalRead(DE0_0) == LOW && digitalRead(DE0_1) == LOW && STATE == 1)
        {
          pinMode(DE0_0,INPUT);
          pinMode(DE0_1,INPUT);
          
         if(DEBUG) Serial.print("\nCurrent STATE: ");
         if(DEBUG) Serial.println(STATE); 
		 
         if(MACHINE(STATE) == true) {
              while(S1(STATE) == false){};  
          STATE++;}
          else{}          
        }
      //==========================================================================STATE 1=END=
      
      //=============================================================================STATE 2=
        if(digitalRead(DE0_0) == LOW && digitalRead(DE0_1) == HIGH && STATE == 2)
        {
         if(DEBUG) Serial.print("\nCurrent STATE: ");
         if(DEBUG) Serial.println(STATE); 
          //LED_PATTEREN(STATE);
          if(MACHINE(STATE) == true) {
          while(S2(STATE) == false){};
          STATE++;}
          else{}          
        }
      //==========================================================================STATE 2=END=
      
      //=============================================================================STATE 3=
        if(digitalRead(DE0_0) == LOW && digitalRead(DE0_1) == LOW && STATE == 3)
        {
         if(DEBUG) Serial.print("\nCurrent STATE: ");
         if(DEBUG) Serial.println(STATE); 
          //LED_PATTEREN(STATE);
          if(MACHINE(STATE) == true) {STATE++;}
          else{}          
        }
      //==========================================================================STATE 3=END=
      
      //=============================================================================STATE 4=
        if(digitalRead(DE0_0) == LOW && digitalRead(DE0_1) == HIGH && STATE == 4)
        {
         if(DEBUG) Serial.print("\nCurrent STATE: ");
         if(DEBUG) Serial.println(STATE); 
          //LED_PATTEREN(STATE);
          if(MACHINE(STATE) == true) {STATE++;}
          else{}          
        }
      //==========================================================================STATE 4=END= 
      
      //=============================================================================STATE 5=
        if(digitalRead(DE0_0) == LOW && digitalRead(DE0_1) == LOW && STATE == 5)
        {
         if(DEBUG) Serial.print("\nCurrent STATE: ");
         if(DEBUG) Serial.println(STATE); 
          //LED_PATTEREN(STATE);
          if(MACHINE(STATE) == true) {STATE++;}
          else{}          
        }
      //==========================================================================STATE 5=END=      

      //=============================================================================STATE 6=
        if(digitalRead(DE0_0) == LOW && digitalRead(DE0_1) == HIGH && STATE == 6)
        {
         if(DEBUG) Serial.print("\nCurrent STATE: ");
         if(DEBUG) Serial.println(STATE); 
          //LED_PATTEREN(STATE);
          if(MACHINE(STATE) == true) {STATE++;}
          else{}          
        }
      //==========================================================================STATE 6=END=  

      //=============================================================================STATE 7=
        if(digitalRead(DE0_0) == LOW && digitalRead(DE0_1) == LOW && STATE == 7)
        {
         if(DEBUG) Serial.print("\nCurrent STATE: ");
         if(DEBUG) Serial.println(STATE); 
          //LED_PATTEREN(STATE);
          if(MACHINE(STATE) == true) {STATE++;}
          else{}          
        }
      //==========================================================================STATE 7=END=  

      else
      {
      }  
  delay(1);    
    }
  STATE = 0;
}
