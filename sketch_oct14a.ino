#define water_sensor 3
#define signal_pin A5
#include <Servo.h>

int value = 0;
Servo toggle;

int pos = 0;

void setup(){
  Serial.begin(9600);
  pinMode(water_sensor, OUTPUT);
  digitalWrite(water_sensor, LOW);
  toggle.attach(12);
  toggle.write(90);
}

void loop(){
  digitalWrite(water_sensor, HIGH);
  delay(10);
  value = analogRead(signal_pin);
  digitalWrite(water_sensor, LOW);
  if(value < 90){
    toggle.write(180);
  }
  else
    toggle.write(90);
  Serial.print("Sensor value: ");
  Serial.println(value);
  delay(5000);
}
