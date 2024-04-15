char inChar;
int counter;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("counter: ");
  Serial.println(counter);
  delay(1000);
  counter++;
}

void serialEvent() {
  if (Serial.available()) {
    inChar = Serial.read();
    Serial.print("received: ");
    Serial.println(inChar);
  }
}
