int adcValue;
int ledPins[] = {5, 6, 9, 10};

int ledPins_size = sizeof(ledPins)/sizeof(ledPins[0]);

void setup() {
  for (int i = 0; i < ledPins_size; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  adcValue = analogRead(A0);
  // delimita entre 0-255 e usa PWM para controlar intensidade do led
  for (int i = 0; i < ledPins_size; i++) {
    analogWrite(ledPins[i], map(adcValue, 0, 1023, 0, 255));
  }
}
