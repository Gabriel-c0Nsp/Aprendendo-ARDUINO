char inChar;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    inChar = Serial.read();
    Serial.print("received: ");
    Serial.println(inChar);
  }
}
