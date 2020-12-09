#include <Arduino.h>

using namespace std;

int LED[] = {2,3,4,5,6,7,8,9};
int numLeds = 8;
int ctr = 0;

void firstPattern();
void secondPattern();
void thirdPattern();

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < numLeds; i++)
      pinMode(LED[i],OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //firstPattern();
  thirdPattern();
}

void firstPattern() {
  if(ctr == 8)
    ctr = 0;
  digitalWrite(LED[ctr],HIGH);
  delay(1000);
  digitalWrite(LED[ctr],LOW);
  delay(1000);
  Serial.println(LED[ctr]);
  ctr++;
}

void secondPattern(){
  for(int i = 0; i < numLeds; i++){
    digitalWrite(LED[i],HIGH);
    delay(250);
    digitalWrite(LED[i],LOW);
  }
  for(int i = numLeds - 1; i >= 0; i--){
    digitalWrite(LED[i],HIGH);
    delay(250);
    digitalWrite(LED[i],LOW);
  }
}

void thirdPattern(){
  for(int i = 0; i < 25; i++){
    if(i % 2 == 0)
      digitalWrite(LED[0],HIGH);
    else
      digitalWrite(LED[1],HIGH);
    delay(100);
    digitalWrite(LED[0],LOW);
    digitalWrite(LED[1],LOW);
  }
  for(int i = 1; i < numLeds; i++){
    digitalWrite(LED[i],HIGH);
    delay(50);
    digitalWrite(LED[i],LOW);
  }
  for(int i = 0; i < 25; i++){
    if(i % 2 == 0)
      digitalWrite(LED[numLeds - 1],HIGH);
    else
      digitalWrite(LED[numLeds - 2],HIGH);
    delay(100);
    digitalWrite(LED[numLeds - 1],LOW);
    digitalWrite(LED[numLeds - 2],LOW);
  }
  for(int i = numLeds - 1; i >= 0; i--){
    digitalWrite(LED[i],HIGH);
    delay(50);
    digitalWrite(LED[i],LOW);
  }
}