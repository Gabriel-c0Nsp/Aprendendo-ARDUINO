int adcValue;
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  adcValue = analogRead(A0);
  // delimita entre 0-255 e usa PWM para controlar intensidade do led
  analogWrite(ledPin, map(adcValue, 0, 1023, 0, 255)); 
}
