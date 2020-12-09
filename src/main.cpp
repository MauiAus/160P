#include <Arduino.h>

using namespace std;

int LED[] = {2,3,4,5,6,7,8,9};
int numLeds = 8;

void firstPattern(int Time);
void secondPattern(int Time);
void thirdPattern(int Time);
void fourthPattern(int Time);
void fifthPattern(int Time);

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < numLeds; i++)
      pinMode(LED[i],OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  firstPattern(1000);
  //secondPattern();
  //thirdPattern();
  //fourthPattern(250);
  //fifthPattern(250);
}

void firstPattern(int Time) {
  digitalWrite(LED[0],HIGH);
  delay(Time);
  digitalWrite(LED[7],HIGH);
  delay(Time);
  digitalWrite(LED[1],HIGH);
  delay(Time);
  digitalWrite(LED[6],HIGH);
  delay(Time);
  digitalWrite(LED[2],HIGH);
  delay(Time);
  digitalWrite(LED[5],HIGH);
  delay(Time);
  digitalWrite(LED[3],HIGH);
  delay(Time);
  digitalWrite(LED[4],HIGH);
  delay(Time);
  for(int i = 0; i < numLeds; i++){
    digitalWrite(LED[i],LOW);
  }
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

void fifthPattern(int Time){
  for(int i = 0; i < 10; i++){
    if(i % 2 == 0){
      digitalWrite(LED[0],HIGH);
      digitalWrite(LED[2],HIGH);
      digitalWrite(LED[4],HIGH);
      digitalWrite(LED[6],HIGH);
      delay(Time);
      digitalWrite(LED[0],LOW);
      digitalWrite(LED[2],LOW);
      digitalWrite(LED[4],LOW);
      digitalWrite(LED[6],LOW);
    }
    else{
      digitalWrite(LED[1],HIGH);
      digitalWrite(LED[3],HIGH);
      digitalWrite(LED[5],HIGH);
      digitalWrite(LED[7],HIGH);
      delay(Time);
      digitalWrite(LED[1],LOW);
      digitalWrite(LED[3],LOW);
      digitalWrite(LED[5],LOW);
      digitalWrite(LED[7],LOW);
    }
  }
}