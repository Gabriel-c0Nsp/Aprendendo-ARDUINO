#define DELAY_TIME 100

const int ledCount = 10; // número de leds

// array para os pinos onde os leds estão conectados
int ledPins[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

void setup() {
  // loop para configurar os pinos dos leds como OUTPUT
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < ledCount; i++) {
    barGraphDisplay(i);
  }
}

void barGraphDisplay(int ledOn) {
  for (int i = 0; i < ledCount; i++) {
    if (i == ledOn) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
  delay(DELAY_TIME);
}
