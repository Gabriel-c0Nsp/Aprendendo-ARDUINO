int buttonPin = 12;
int ledPin = 9;
boolean isLighting = false;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { // se o botão está pressionado...
    delay(10); // pequeno delay para pular o efeito "bounce"

    if (digitalRead(buttonPin) == LOW) { // confirmando de novo se o botão está pressionado 
      reverseLED();      

      while (digitalRead(buttonPin) == LOW); // espera a pessoa soltar
      delay(10); // pequeno delay para pular o efeito "bounce" quando o botão for solto 
    }
  }
}

void reverseLED() {
  if (isLighting) {
    digitalWrite(ledPin, LOW);
    isLighting = false; // guarda o estado do led 
  } else {
    digitalWrite(ledPin, HIGH);
    isLighting = true; // guarda o estado do led
  }
}
