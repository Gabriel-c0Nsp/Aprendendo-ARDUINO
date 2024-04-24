int xPin = 0;
int yPin = 1;
int zPin = 2;

int xValue, yValue, zValue;

void setup() {
  pinMode(zPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  xValue = analogRead(xPin);
  yValue = analogRead(yPin);
  zValue = digitalRead(zPin);

  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print("  \t Y: ");
  Serial.print(yValue);
  Serial.print("  \t Z: ");
  Serial.println(zValue);
  delay(500);
}
