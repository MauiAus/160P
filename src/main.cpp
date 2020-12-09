#include <Arduino.h>

using namespace std;

int LED[] = {2,3,4,5,6,7,8,9};
int numLeds = 8;
int ctr = 0;

void firstPattern(int Time);
void secondPattern(int Time);
void thirdPattern(int Time);
void fourthPattern(int Time);

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < numLeds; i++)
      pinMode(LED[i],OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //firstPattern(60);
  //secondPattern();
  //thirdPattern();
  fourthPattern(250);
}

void firstPattern(int Time) {
  if(ctr == 8)
    ctr = 0;
  digitalWrite(LED[ctr],HIGH);
  delay(Time);
  digitalWrite(LED[ctr],LOW);
  delay(Time);
  Serial.println(LED[ctr]);
  ctr++;
}

void secondPattern(int Time){
  for(int i = 0; i < numLeds; i++){
    digitalWrite(LED[i],HIGH);
    delay(Time);
    digitalWrite(LED[i],LOW);
  }
  for(int i = numLeds - 1; i >= 0; i--){
    digitalWrite(LED[i],HIGH);
    delay(Time);
    digitalWrite(LED[i],LOW);
  }
}

void thirdPattern(int Time){
  for(int i = 0; i < 25; i++){
    if(i % 2 == 0)
      digitalWrite(LED[0],HIGH);
    else
      digitalWrite(LED[1],HIGH);
    delay(Time);
    digitalWrite(LED[0],LOW);
    digitalWrite(LED[1],LOW);
  }
  for(int i = 1; i < numLeds; i++){
    digitalWrite(LED[i],HIGH);
    delay(Time);
    digitalWrite(LED[i],LOW);
  }
  for(int i = 0; i < 25; i++){
    if(i % 2 == 0)
      digitalWrite(LED[numLeds - 1],HIGH);
    else
      digitalWrite(LED[numLeds - 2],HIGH);
    delay(Time);
    digitalWrite(LED[numLeds - 1],LOW);
    digitalWrite(LED[numLeds - 2],LOW);
  }
  for(int i = numLeds - 1; i >= 0; i--){
    digitalWrite(LED[i],HIGH);
    delay(Time);
    digitalWrite(LED[i],LOW);
  }
}

void fourthPattern(int Time){
  for(int i = 0; i < numLeds; i++){
      digitalWrite(LED[i],HIGH);
      digitalWrite(LED[i+1],HIGH);
      delay(Time);
      digitalWrite(LED[i],LOW);
      digitalWrite(LED[i+1],LOW);
  }
  for(int i = numLeds - 1; i >= 0; i--){
    digitalWrite(LED[i],HIGH);
    digitalWrite(LED[i+1],HIGH);
    delay(Time);
    digitalWrite(LED[i],LOW);
    digitalWrite(LED[i+1],LOW);
    Serial.println(LED[i]);
  }
}