#include <dht.h>
#include <Servo.h>

dht DHT;
Servo trigger;

int pos = 90;

#define DHT11_PIN 7

void setup(){
  Serial.begin(9600);
  trigger.attach(9);
  trigger.write(180);
}

void loop(){
  int chkhum = DHT.read11(DHT11_PIN);
  int chksnd = analogRead(0);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  Serial.print("Sound=");
  Serial.println(chksnd);
  delay(1000);
  if(DHT.humidity > 85 || chksnd > 90){
    trigger.write(90);
  }
}
