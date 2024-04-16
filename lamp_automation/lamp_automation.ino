#define LIMIT_LIGHT 450

int photoresistorValue;
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  photoresistorValue = analogRead(A0);
  
  if (photoresistorValue < LIMIT_LIGHT) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}
