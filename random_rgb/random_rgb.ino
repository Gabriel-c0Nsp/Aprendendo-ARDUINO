int ledPinR = 11;
int ledPinG = 10;
int ledPinB = 9;

void setup() {
  pinMode(ledPinR, OUTPUT);
  pinMode(ledPinG, OUTPUT);
  pinMode(ledPinB, OUTPUT);
}

void loop() {
  rgbLedDisplay(random(256), random(256), random(256));
  delay(500);
}

void rgbLedDisplay(int red, int green, int blue) {
  analogWrite(ledPinR, constrain(red, 0, 255)); 
  analogWrite(ledPinR, constrain(green, 0, 255)); 
  analogWrite(ledPinR, constrain(blue, 0, 255)); 
}
