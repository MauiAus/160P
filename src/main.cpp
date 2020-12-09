#include <Arduino.h>

using namespace std;

int LED[] = {2,3,4,5,6,7,8,9};
int numLeds = 8;
int ctr = 0;

void firstPattern();
void secondPattern();

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < numLeds; i++)
      pinMode(LED[i],OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //firstPattern();
  secondPattern();
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

