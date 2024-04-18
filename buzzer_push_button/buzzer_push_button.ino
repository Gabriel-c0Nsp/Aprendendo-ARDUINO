int buttonPin = 12;
int buzzerPin = 9;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) {
    digitalWrite(buzzerPin, LOW);
  } else {
    digitalWrite(buzzerPin, HIGH);
  }
}
