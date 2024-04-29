int latchPin = 12;
int clockPin = 13;
int dataPin = 11;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
 
void loop() {
  // Define uma variável de um byte para usar os 8 bits para representar o estado de 8 LEDs de uma "barra de leds".
  // Esta variável é atribuída a 0x01, que é binário 00000001, o que indica apenas um LED aceso.
  byte x = 0x01;

  for (int j = 0; j < 8; j++) {
    digitalWrite(latchPin, LOW);

    // Envia Serial data para o 74HC595
    shiftOut(dataPin, clockPin, LSBFIRST, x);

    // Output high level para o latchPin, e o 74HC595 vai atualizar os dados para o "parallel output port"
    digitalWrite(latchPin, HIGH);

    // faz a variável mover um bit para a esquerda uma vez, então o LED aceso se move um passo para a esquerda uma vez.
    x <<= 1;
    delay(100);
  }
}
