#include <Arduino.h>

int sw = 0;//button
//SSD pins
int pinA = 0;
int pinB = 0;
int pinC = 0;
int pinD = 0;
int pinE = 0;
int pinF = 0;
int pinG = 0;
//Stepper pins
int stp_pin1 = 10;
int stp_pin2 = 11;
int stp_pin3 = 12;
int stp_pin4 = 13;

int stp_ctr = 0;//stepper counter
int park_ctr = 0;//Parking counter

void displaySSD(int ctr);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
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
  if(stp_ctr>3)
    stp_ctr = 0;
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
  default:
    digitalWrite(pinA, HIGH);   
    digitalWrite(pinB, HIGH);   
    digitalWrite(pinC, HIGH);   
    digitalWrite(pinD, HIGH);   
    digitalWrite(pinE, HIGH);   
    digitalWrite(pinF, HIGH);   
    digitalWrite(pinG, LOW);
    break;
  }
}
//function to check if the parking is full
