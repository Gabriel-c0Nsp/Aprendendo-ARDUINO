int ledPin = 5;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  breath(ledPin, 6);
  delay(500);
}

void breath(int ledPin, int delayMS) {
  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(delayMS);
  }

  for (int i = 255; i >=0; i--) {
    analogWrite(ledPin, i);
    delay(delayMS);
  }
}
