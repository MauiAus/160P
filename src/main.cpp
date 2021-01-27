#include <Arduino.h>

int sw = 0;//button val
int inpin = 2;

//SSD pins
int pinA = 5;
int pinB = 6;
int pinC = 7;
int pinD = 8;
int pinE = 9;
int pinF = 4;
int pinG = 3;
//Stepper pins
int stp_pin1 = 10;
int stp_pin2 = 11;
int stp_pin3 = 12;
int stp_pin4 = 13;

int stp_ctr = 0;//stepper counter
int park_ctr = 9;//Parking counter
int stp_steps = 0;

void displaySSD(int ctr);
void OneStep(bool dir);
void park_dec();

void setup() {
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);  
  pinMode(stp_pin1, OUTPUT);
  pinMode(stp_pin2, OUTPUT);
  pinMode(stp_pin3, OUTPUT);
  pinMode(stp_pin4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sw = digitalRead(inpin);

  if(sw == HIGH)
  {
    if(park_ctr <= 0){
      displaySSD(-1);
      for(int i = 0; i < 500; i++)
        OneStep(true);
      park_ctr = 10;
      stp_steps = 0;
    }
    park_dec();

  }
  
  if(park_ctr == 0){
    //Serial.print(stp_steps);
    //closeG();
    //stp_steps++;
    
    for(stp_steps; stp_steps < 1000; stp_steps++)
      OneStep(false);
    
    //OneStep(false);

    //closeG();
  }


  displaySSD(park_ctr);
  //if(park_ctr == 0)
  //  closeG();
  //else if(park_ctr == 9)
  //  openG();
}

void park_dec(){
  if(park_ctr >= 0)
    park_ctr--;
  delay(500);
}

//function to create one step
void OneStep(bool dir){
  if(dir){
    switch(stp_ctr){
      case 0:
        digitalWrite(stp_pin1, HIGH);
        digitalWrite(stp_pin2, LOW);
        digitalWrite(stp_pin3, LOW);
        digitalWrite(stp_pin4, LOW);
        break;
      case 1:
        digitalWrite(stp_pin1, LOW);
        digitalWrite(stp_pin2, HIGH);
        digitalWrite(stp_pin3, LOW);
        digitalWrite(stp_pin4, LOW);
        break;
      case 2:
        digitalWrite(stp_pin1, LOW);
        digitalWrite(stp_pin2, LOW);
        digitalWrite(stp_pin3, HIGH);
        digitalWrite(stp_pin4, LOW);
        break;
      case 3:
        digitalWrite(stp_pin1, LOW);
        digitalWrite(stp_pin2, LOW);
        digitalWrite(stp_pin3, LOW);
        digitalWrite(stp_pin4, HIGH);
        break;
    }
  }
    else{
      switch(stp_ctr){
        case 0:
        digitalWrite(stp_pin1, LOW);
        digitalWrite(stp_pin2, LOW);
        digitalWrite(stp_pin3, LOW);
        digitalWrite(stp_pin4, HIGH);
        break;
        case 1:
        digitalWrite(stp_pin1, LOW);
        digitalWrite(stp_pin2, LOW);
        digitalWrite(stp_pin3, HIGH);
        digitalWrite(stp_pin4, LOW);
        break;
        case 2:
        digitalWrite(stp_pin1, LOW);
        digitalWrite(stp_pin2, HIGH);
        digitalWrite(stp_pin3, LOW);
        digitalWrite(stp_pin4, LOW);
        break;
        case 3:
        digitalWrite(stp_pin1, HIGH);
        digitalWrite(stp_pin2, LOW);
        digitalWrite(stp_pin3, LOW);
        digitalWrite(stp_pin4, LOW);
        break;
      }
    }
  stp_ctr++;
  if(stp_ctr > 3){
    stp_ctr = 0;
  }
  stp_steps++;
  delay(10);
}

//function to display the SSD
void displaySSD(int ctr){
  switch (ctr)
  {
  case 0:
    digitalWrite(pinA, HIGH);   
    digitalWrite(pinB, HIGH);   
    digitalWrite(pinC, HIGH);   
    digitalWrite(pinD, HIGH);   
    digitalWrite(pinE, HIGH);   
    digitalWrite(pinF, HIGH);   
    digitalWrite(pinG, LOW);
    break;
  case 1:
    digitalWrite(pinA, LOW);   
    digitalWrite(pinB, HIGH);   
    digitalWrite(pinC, HIGH);   
    digitalWrite(pinD, LOW);   
    digitalWrite(pinE, LOW);   
    digitalWrite(pinF, LOW);   
    digitalWrite(pinG, LOW);
    break;
  case 2:
    digitalWrite(pinA, HIGH);   
    digitalWrite(pinB, HIGH);   
    digitalWrite(pinC, LOW);   
    digitalWrite(pinD, HIGH);   
    digitalWrite(pinE, HIGH);   
    digitalWrite(pinF, LOW);   
    digitalWrite(pinG, HIGH);
    break;
  case 3:
    digitalWrite(pinA, HIGH);   
    digitalWrite(pinB, HIGH);   
    digitalWrite(pinC, HIGH);   
    digitalWrite(pinD, HIGH);   
    digitalWrite(pinE, LOW);   
    digitalWrite(pinF, LOW);   
    digitalWrite(pinG, HIGH);
    break;
  case 4:
    digitalWrite(pinA, LOW);   
    digitalWrite(pinB, HIGH);   
    digitalWrite(pinC, HIGH);   
    digitalWrite(pinD, LOW);   
    digitalWrite(pinE, LOW);   
    digitalWrite(pinF, HIGH);   
    digitalWrite(pinG, HIGH); 
    break;
  case 5:
    digitalWrite(pinA, HIGH);   
    digitalWrite(pinB, LOW);   
    digitalWrite(pinC, HIGH);   
    digitalWrite(pinD, HIGH);   
    digitalWrite(pinE, LOW);   
    digitalWrite(pinF, HIGH);   
    digitalWrite(pinG, HIGH); 
    break;
  case 6:
    digitalWrite(pinA, LOW);   
    digitalWrite(pinB, LOW);   
    digitalWrite(pinC, HIGH);   
    digitalWrite(pinD, HIGH);   
    digitalWrite(pinE, HIGH);   
    digitalWrite(pinF, HIGH);   
    digitalWrite(pinG, HIGH); 
    break;
  case 7:
    digitalWrite(pinA, HIGH);   
    digitalWrite(pinB, HIGH);   
    digitalWrite(pinC, HIGH);   
    digitalWrite(pinD, LOW);   
    digitalWrite(pinE, LOW);   
    digitalWrite(pinF, LOW);   
    digitalWrite(pinG, LOW); 
    break;
  case 8:
    digitalWrite(pinA, HIGH);   
    digitalWrite(pinB, HIGH);   
    digitalWrite(pinC, HIGH);   
    digitalWrite(pinD, HIGH);   
    digitalWrite(pinE, HIGH);   
    digitalWrite(pinF, HIGH);   
    digitalWrite(pinG, HIGH); 
    break;
  case 9:
    digitalWrite(pinA, HIGH);   
    digitalWrite(pinB, HIGH);   
    digitalWrite(pinC, HIGH);   
    digitalWrite(pinD, LOW);   
    digitalWrite(pinE, LOW);   
    digitalWrite(pinF, HIGH);   
    digitalWrite(pinG, HIGH); 
    break;
  case -1:
    digitalWrite(pinA, LOW);   
    digitalWrite(pinB, LOW);   
    digitalWrite(pinC, LOW);   
    digitalWrite(pinD, LOW);   
    digitalWrite(pinE, LOW);   
    digitalWrite(pinF, LOW);   
    digitalWrite(pinG, LOW);
    break;
  }
  delay(2);
}
