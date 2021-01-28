#define relayPin 4
#define inPin 3

int sw = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(relayPin, OUTPUT);
  pinMode(inPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sw = digitalRead(inPin);

  if(sw == HIGH)
    digitalWrite(relayPin, HIGH);
  else
    digitalWrite(relayPin, LOW);
  delay(1000);
}
