int led1Pin = 12;
int led2Pin = 13;
int buzzerPin = 3;
int buttonPin = 5;
float sinValue;
int toneValue;

boolean button_toggle = false;
unsigned long lastLedChangeTime = 0;
unsigned long lastSirenChangeTime = 0;
boolean ledState = false; 

void setup() {
  Serial.begin(9600);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  Serial.println(check_button_state());
  if (check_button_state()) {
    setLed(led1Pin, led2Pin);
    sirenNoise();
  } else {
    turn_off_led(led1Pin, led2Pin);
    turn_off_siren();
  }
}

void setLed(int led1, int led2) {
  unsigned long currentTime = millis();
  if (currentTime - lastLedChangeTime >= 400) {
    digitalWrite(led1, ledState);
    digitalWrite(led2, !ledState);
    ledState = !ledState;
    lastLedChangeTime = currentTime;
  }
}

void sirenNoise() {
  unsigned long currentTime = millis();
  if (currentTime - lastSirenChangeTime >= 500) {
    for (int x = 0; x < 360; x++) {
      sinValue = sin(x * (PI / 180));
      toneValue = 2000 + sinValue * 500;
      tone(buzzerPin, toneValue);
    }
    lastSirenChangeTime = currentTime;
  }
}

boolean check_button_state() {
  if (digitalRead(buttonPin) == LOW) {
    delay(10);

    if (digitalRead(buttonPin) == LOW) {
      if (button_toggle) {
        button_toggle = false;
      } else {
        button_toggle = true;
      }
      while (digitalRead(buttonPin) == LOW);
      delay(10);
    }
  }

  return button_toggle;
}

void turn_off_led(int led1, int led2) {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void turn_off_siren() {
  noTone(buzzerPin);
}
