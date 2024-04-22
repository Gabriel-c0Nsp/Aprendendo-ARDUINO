// Usando o micro chip L293D para esse projeto
int in1Pin = 10;
int in2Pin = 9;
int enable1Pin = 11;
boolean rotationDir; // salva a direção do motor
int rotationSpeed;

void setup() {
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
}

void loop() {
  int potenVal = analogRead(A0);  

  rotationSpeed = potenVal - 512;

  if (potenVal > 512) {
    rotationDir = true; // caso maior que 512, gira no sentido horário
  } else {
    rotationDir = false; // gira no sentido anti-horário
  }

  rotationSpeed = abs(potenVal - 512);
  driveMotor(rotationDir, map(rotationSpeed, 0, 512, 0, 255));
}

void driveMotor(boolean dir, int spd) {
  // controla a direção do giro do motor
  if (rotationDir) {
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
  } else {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
  }

  // controla a velocidade do giro do motor
  analogWrite(enable1Pin, constrain(spd, 0, 255));
}
