#include <Arduino.h>


int pinA = 3;
int pinB = 7;
int pinC = 10;
int pinD = 9;
int pinE = 8;
int pinF = 4;
int pinG = 11;
int D[] = {2,5,6,12};

void zero();
void one();
void two();
void three();
void four();
void five();
void six();
void seven();
void eight();
void nine();

void retNum(int x);

void d1(int x);
void d2(int x);
void d3(int x);
void d4(int x);
void addSec();

int sec = 0;
int d1val = 2;
int d2val = 1;
int d3val = 2;
int d4val = 3;
int realsec = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);  
  for(int i = 0; i < 4; i++)
    pinMode(D[i],OUTPUT); 
}

// the loop routine runs over and over again forever:
void loop() {
  //0
  d1(d1val);
  d2(d2val);
  d3(d3val);
  d4(d4val);
  if(sec % 1000 == 0)
    realsec++;
  if(realsec == 61)
  {
    d4val++;
    realsec = 0;
  }
  if(d4val == 10){
    d3val++;
    d4val = 0;
  }
  if(d3val == 6){
    d2val++;
    d3val = 0;
  }
  if(d2val == 10){
    d1val++;
    d2val = 0;
  }
  if(d1val == 2 && d2val == 4){
    d1val = 0;
    d2val = 0;
    d3val = 0;
    d4val = 0;
  }
}

void zero(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, LOW);
}

void one(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW);
}
void two(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);  
}
void three(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH); 
}
void four(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);    
}
void five(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH); 
}
void six(){
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH); 
}
void seven(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, LOW); 
}
void eight(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH); 
}
void nine(){
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH); 
}

void retNum(int x){
  switch (x)
  {
  case 1:
    one();
    break;
  case 2:
    two();
    break;
  case 3:
    three();
    break;
  case 4:
    four();
    break;
  case 5:
    five();
    break;
  case 6:
    six();
    break;
  case 7:
    seven();
    break;
  case 8:
    eight();
    break;
  case 9:
    nine();
    break;
  case 0:
    zero();
    break;
  default:
    break;
  }
}

void d1(int x){
  digitalWrite(D[0],LOW);
  digitalWrite(D[1],HIGH);
  digitalWrite(D[2],HIGH);
  digitalWrite(D[3],HIGH);
  retNum(x);
  delay(1);
  addSec();
}
void d2(int x){
  digitalWrite(D[0],HIGH);
  digitalWrite(D[1],LOW);
  digitalWrite(D[2],HIGH);
  digitalWrite(D[3],HIGH);
  retNum(x);
  delay(1);
  addSec();
}
void d3(int x){
  digitalWrite(D[0],HIGH);
  digitalWrite(D[1],HIGH);
  digitalWrite(D[2],LOW);
  digitalWrite(D[3],HIGH);
  retNum(x);
  delay(1);
  addSec();
}
void d4(int x){
  digitalWrite(D[0],HIGH);
  digitalWrite(D[1],HIGH);
  digitalWrite(D[2],HIGH);
  digitalWrite(D[3],LOW);
  retNum(x);
  delay(1);
  addSec();
}

void addSec(){
  if(sec == 1000)
    sec = 0;
  sec++;
}

