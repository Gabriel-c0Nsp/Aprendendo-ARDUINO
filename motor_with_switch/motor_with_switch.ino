int relayPin = 9;
int buttonPin = 12;

int buttonState = HIGH;
int relayState = LOW;
int lastButtonState = HIGH;
long lastChangeTime = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int nowButtonState = digitalRead(buttonPin);

  if (nowButtonState != lastButtonState) {
    lastChangeTime = millis();
  }

  if (millis() - lastChangeTime > 10) {
    if (buttonState != nowButtonState) {
      buttonState = nowButtonState;
      if (buttonState == LOW) {
        relayState = !relayState; // reverte o estado do relay
        digitalWrite(relayPin, relayState); // update o estado do relay
        Serial.println("O botão está pressionado!");
      } else {
        Serial.println("O botão não está pressionado!");
      }
    }
  }
  lastButtonState = nowButtonState; // salvando o estado do botão antes de reiniciar o loop
}
