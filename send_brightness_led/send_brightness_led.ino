int inInt;
int counter = 0;
int ledPin = 11;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    Serial.print("received: ");
    inInt = Serial.parseInt(); 
    Serial.println(inInt);
    analogWrite(ledPin, constrain(inInt, 0, 255)); // converter o inteiro recebido para PWM duty cycle e limita valor do int entre 0 a 255
  }
}
