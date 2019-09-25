/*
  basic state machine 2
 
  Modified to switch between states to write, read and clear EEPROM
 
 Demonstrates how to use a case statement to create a simple state machine.
 This code uses a potentiometer knob to select between 3 states.
 
 The circuit:
 * pot from analog in 0 to +5V
 * 10K resistor from analog in 0 to ground
 
 created 13 Apr 2010
 by Wendy Ju 
 modified from switchCase by Tom Igoe
 
 12 Sep 2018
 Modified to switch between states to write, read and clear EEPROM
 */

#include <EEPROM.h>

#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int numStates = 3;
const int sensorMin =0;
const int sensorMax = 1024;
const int EEPROMSIZE=1024;

int sensorPin = A0;    // input pin for FSR
int redPin = 6;
int greenPin = 10;
int bluePin = 9;   
int state,lastState = -1;

int buttonState = 0;
int button = 8;
int color = 0;
int run = 0;
byte value;
int amount = 0;

void setColor(int red, int green, int blue) {
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

void setup() {
  // initialize serial communication:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  pinMode(button, INPUT_PULLUP);
  
  lcd.begin(16, 2);
  Serial.begin(9600);  
//  setColor(255,255,255); //off
  lcd.print("Push the button");
  lcd.setCursor(0,1);
  lcd.print("to start!");
}



void state0Setup(){
//  setColor(0,255,0); //green

  for (int i=0; i<5; i++){
    lcd.clear();
    lcd.print("Go!");
    delay(2000);
    Serial.println(analogRead(sensorPin));
    color = map(analogRead(sensorPin), 0, 1023, 0,3);
    Serial.println(color);

    EEPROM.write(i, color);
    }

  }
  


void state0Loop(){
}

void doState0(){
  if(lastState != 0){ state0Setup();}
  state0Loop();
}


void state1Setup(){
  delay(3000);
  lcd.clear();
  lcd.print("Look @ light: ");
  
  for (int i=0; i<5; i++){
    value = EEPROM.read(i);
    if(value==0){

    }
    else if(value == 1){
      setColor(0, 0, 255);

    }
    else if (value ==2){
      setColor(255, 0, 0);

    }
    delay(1000);
  }
  lcd.clear();
  lcd.print("Pattern done");
  setColor(0,0,0);
}

void doState1(){
  if (lastState != 1){ state1Setup();}
  state1Loop();
}


void state1Loop(){
}

void loop(){
 
  buttonState = digitalRead(button);
//  Serial.println(buttonState);
  if (buttonState == LOW){
    state = 0;
    run=100;
    delay(1000);
  }

  else if (lastState == 0 and run==100){
    state = 1;
  }
  else{
    state = -1;
  }
    

  switch(state){
    case 0:    
      doState0();
      break;
    case 1:    
      doState1();
      break;

  } 
  lastState = state;

  }
  
