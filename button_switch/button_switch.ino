int buttonPin = 12;
int ledPin = 9;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == HIGH) { // se o botão não está pressionado
    digitalWrite(ledPin, LOW); 
  } else {
    digitalWrite(ledPin, HIGH);
  }
}
