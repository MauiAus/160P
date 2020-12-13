#include <Arduino.h>

int LED[] = {7,8,9,10};
int inPin[] = {2,3,4,5,6};

int SW1 = 0;
int SW2 = 0;
int SW3 = 0;
int SW4 = 0;
int SW5 = 0;

int BCD = 0;

int grayConv(int x);
int excess3Conv(int x);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i = 0; i < 4; i++){
    pinMode(LED[i],OUTPUT);
  }
  for(int i = 0; i < 5; i++){
    pinMode(inPin[i],INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  SW1 = digitalRead(inPin[0]);
  SW2 = digitalRead(inPin[1]);
  SW3 = digitalRead(inPin[2]);
  SW4 = digitalRead(inPin[3]);
  SW5 = digitalRead(inPin[4]);

  if(SW1 == HIGH){
    delay(1000);
    if(BCD < 9){
      BCD++;
    }
  }
  if(SW2 == HIGH){
    delay(1000);
    if(BCD > -1){
      BCD--;
      for(int i = 0; i < 4; i++)
        digitalWrite(LED[i],LOW);
    }
  }  

  if(SW5 == HIGH){
    BCD = 0;
    for(int i = 0; i < 4; i++)
      digitalWrite(LED[i],LOW);
  }

  int a[4];
  int n;

  if(SW3 == HIGH){
    n = grayConv(BCD);
  }
  else if(SW4 == HIGH){
    n = excess3Conv(BCD);
  }
  else{
    n = BCD; 
  }
  for(int i=0; n>0; i++)    
  {
    a[i]=n%2;    
    n = n/2;  
    if(a[i] == 1){
      digitalWrite(LED[i],HIGH);
    }
    else{
      digitalWrite(LED[i],LOW);
    }
    Serial.println(BCD);
  }    
}

int grayConv(int x){
  switch (x)
  {
  case 0:
    return 0;
    break;
  
  case 1:
    return 1;
    break;
  
  case 2:
    return 3;
    break;
  
  case 3:
    return 2;
    break;
  
  case 4:
    return 6;
    break;
  
  case 5:
    return 7;
    break;
  
  case 6:
    return 5;
    break;
  
  case 7:
    return 8;
    break;
  
  case 8:
    return 12;
    break;
  
  case 9:
    return 13;
    break;
  
  default:
    break;
  }
}

int excess3Conv(int x){
  return x + 3;
}