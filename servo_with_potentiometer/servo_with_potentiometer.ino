#include <Servo.h>

#define SERVO_SPEED 5

Servo servo;

int servoPin = 3;
int potPin = 0;
int potVal;

void setup() {
  servo.attach(servoPin);
}

void loop() {
  potVal = analogRead(A0);
  potVal = map(potVal, 0, 1023, 0, 180); // dessa forma pois o servo vai de 0 a 180 graus 

  servo.write(potVal);
  delay(SERVO_SPEED);
}
