#define water_sensor 3 
#define signal_pin A5 
#include <Servo.h> 


int value = 0; 
Servo toggle; 

int pinA = 5; 
int pinB = 4; 
int pinC = 3;
int pinD = 2; 

int stp_pin1 = 8; 
int stp_pin2 = 9; 
int stp_pin3 = 10; 
int stp_pin4 = 11; 

int inPinA = 7;
int inPinB = 6;

int stp_ctr = 0; 
int pos = 0; 
int stp_steps = 0;

int SW1 = 0;
int SW2 = 0;

void setup(){ 
  Serial.begin(9600); 
  pinMode(pinA, OUTPUT); 
  pinMode(pinB, OUTPUT); 
  pinMode(pinC, OUTPUT); 
  pinMode(pinD, OUTPUT); 
  pinMode(water_sensor, OUTPUT); 
  digitalWrite(water_sensor, LOW); 
  pinMode(stp_pin1, OUTPUT); 
  pinMode(stp_pin2, OUTPUT); 
  pinMode(stp_pin3, OUTPUT); 
  pinMode(stp_pin4, OUTPUT); 
  toggle.attach(12); 
  toggle.write(90); 
} 

 

void loop(){ 
  SW1 = digitalRead(inPinA);
  SW2 = digitalRead(inPinB);
  digitalWrite(water_sensor, HIGH); 
  delay(10); 
  value = analogRead(signal_pin); 
  digitalWrite(water_sensor, LOW); 
  Serial.print(value);
  displayLevel(intConv(value));

  if(SW1 == HIGH){
    delay(1000);
    Serial.println("button pushed");
    pourMove();
  }

  if(SW2 == HIGH){
    delay(1000);
    Serial.println("button pushed2");
    pourReturn();
  }
  
  /*
  if(value < 90){ 
    toggle.write(180); 
  } 
  else 
  toggle.write(90);
  */ 
  Serial.print("Sensor value: "); 
  Serial.println(value); 
  delay(5000); 
} 

int intConv(int val){
  if(val<5)
    return 0;
  else if(val>=5 && val<25)
    return 1;
  else if(val>=25 && val<50)
    return 2;
  else if(val>=50 && val<75)
    return 3;
  else if(val>=75)
    return 4;
  else
    return 0;
}

void pickUp(){
  toggle.write(180);
  delay(1000);
  toggle.write(90);
}

void pourMove(){
  displayLevel(0);
  for(int i = 0; i<1000;i++)
    OneStep(false);
  pickUp();
}

void pourReturn(){
  displayLevel(0);
  for(int i = 0; i<1000;i++)
    OneStep(true);
  pickUp();
}
 
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

void displayLevel(int lvl){
  switch(lvl){
    case 0:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW); 
      digitalWrite(pinC, LOW); 
      digitalWrite(pinD, LOW); 
      break;
    case 1:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW); 
      digitalWrite(pinC, LOW); 
      digitalWrite(pinD, LOW); 
      break;
    case 2:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH); 
      digitalWrite(pinC, LOW); 
      digitalWrite(pinD, LOW); 
      break;
    case 3:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH); 
      digitalWrite(pinC, HIGH); 
      digitalWrite(pinD, LOW); 
      break;
    case 4:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH); 
      digitalWrite(pinC, HIGH); 
      digitalWrite(pinD, HIGH); 
      break;
  }
}
 
void displaySSD(int ctr){ 
  switch(ctr) 
  { 
    case 0: 
    digitalWrite(pinA, LOW); 
    digitalWrite(pinB, LOW); 
    digitalWrite(pinC, LOW); 
    digitalWrite(pinD, LOW); 
    break; 
    case 1: 
    digitalWrite(pinA, HIGH); 
    digitalWrite(pinB, LOW); 
    digitalWrite(pinC, LOW); 
    digitalWrite(pinD, LOW); 
    break; 
    case 2: 
    digitalWrite(pinA, LOW); 
    digitalWrite(pinB, HIGH); 
    digitalWrite(pinC, LOW); 
    digitalWrite(pinD, LOW); 
    break; 
    case 3: 
    digitalWrite(pinA, HIGH); 
    digitalWrite(pinB, HIGH); 
    digitalWrite(pinC, LOW); 
    digitalWrite(pinD, LOW); 
    break; 
    case 4: 
    digitalWrite(pinA, LOW); 
    digitalWrite(pinB, LOW); 
    digitalWrite(pinC, HIGH); 
    digitalWrite(pinD, LOW); 
    break; 
    case 5: 
    digitalWrite(pinA, HIGH); 
    digitalWrite(pinB, LOW); 
    digitalWrite(pinC, HIGH); 
    digitalWrite(pinD, LOW); 
    break; 
    case 6: 
    digitalWrite(pinA, LOW); 
    digitalWrite(pinB, HIGH); 
    digitalWrite(pinC, HIGH); 
    digitalWrite(pinD, LOW); 
    break; 
    case 7: 
    digitalWrite(pinA, HIGH); 
    digitalWrite(pinB, HIGH); 
    digitalWrite(pinC, HIGH);
    digitalWrite(pinD, LOW); 
    break; 
    case 8: 
    digitalWrite(pinA, LOW); 
    digitalWrite(pinB, LOW); 
    digitalWrite(pinC, LOW); 
    digitalWrite(pinD, HIGH); 
    break; 
    case 9: 
    digitalWrite(pinA, HIGH); 
    digitalWrite(pinB, LOW); 
    digitalWrite(pinC, LOW); 
    digitalWrite(pinD, HIGH); 
    break; 
  } 
} 
