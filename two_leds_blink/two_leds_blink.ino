// Tentando imitar uma sirene de polícia XD.

int led1Pin = 4;
int led2Pin = 5;

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}

void loop() {
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, LOW);
  delay(200);

  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, HIGH);
  delay(200);
}
