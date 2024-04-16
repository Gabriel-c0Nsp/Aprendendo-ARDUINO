int convertValue;
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  convertValue = analogRead(A0);
  analogWrite(ledPin, map(convertValue, 0, 1023, 0, 255)); 
}
