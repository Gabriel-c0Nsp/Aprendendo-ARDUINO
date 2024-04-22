#include <Servo.h> 

#define SERVO_SPEED 5

Servo myServo; // criando um objeto para controlar o servo 

int pos = 0;
int servoPin = 3;

void setup() {
  myServo.attach(servoPin);
}

void loop() {
  for (pos = 0; pos <= 180; pos++) {
    myServo.write(pos);
    delay(SERVO_SPEED);
  }

  for (pos = 180; pos >= 0; pos--) {
    myServo.write(pos);
    delay(SERVO_SPEED);
  }
}
