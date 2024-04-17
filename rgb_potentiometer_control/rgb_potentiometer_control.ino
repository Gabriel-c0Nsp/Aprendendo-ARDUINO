int ledPinR = 11;
int ledPinG = 10;
int ledPinB = 9;

void setup() {
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinB, OUTPUT);
}

void loop() {
  int adcValue;
  
  adcValue = analogRead(A0);
  analogWrite(ledPinR, map(adcValue, 0, 1023, 0, 255));

  adcValue = analogRead(A1);
  analogWrite(ledPinG, map(adcValue, 0, 1023, 0, 255));

  adcValue = analogRead(A2);
  analogWrite(ledPinB, map(adcValue, 0, 1023, 0, 255));
}
