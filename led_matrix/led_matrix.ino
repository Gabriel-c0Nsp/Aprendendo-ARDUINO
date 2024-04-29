int latchPin = 12;
int clockPin = 13;
int dataPin = 11;
int LEDPin[] = {2, 3, 4, 5, 6, 7, 8, 9}; // coluna de pinos ligados
int LEDPin_size = sizeof(LEDPin) / sizeof(LEDPin[0]);

// Definindo o pattern para reproduzir uma carinha sorrindo 
const int smilingFace[] = {
  0x1C, 0x22, 0x51, 0x45, 0x45, 0x51, 0x22, 0x1C
};

// Define os dados dos números e letras, depois salva em "flash area"
const int data[] PROGMEM = { 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // " " 
  0x00, 0x00, 0x21, 0x7F, 0x01, 0x00, 0x00, 0x00, // "1" 
  0x00, 0x00, 0x23, 0x45, 0x49, 0x31, 0x00, 0x00, // "2" 
  0x00, 0x00, 0x22, 0x49, 0x49, 0x36, 0x00, 0x00, // "3" 
  0x00, 0x00, 0x0E, 0x32, 0x7F, 0x02, 0x00, 0x00, // "4" 
  0x00, 0x00, 0x79, 0x49, 0x49, 0x46, 0x00, 0x00, // "5" 
  0x00, 0x00, 0x3E, 0x49, 0x49, 0x26, 0x00, 0x00, // "6" 
  0x00, 0x00, 0x60, 0x47, 0x48, 0x70, 0x00, 0x00, // "7" 
  0x00, 0x00, 0x36, 0x49, 0x49, 0x36, 0x00, 0x00, // "8" 
  0x00, 0x00, 0x32, 0x49, 0x49, 0x3E, 0x00, 0x00, // "9" 
  0x00, 0x00, 0x3E, 0x41, 0x41, 0x3E, 0x00, 0x00, // "0" 
  0x00, 0x00, 0x3F, 0x44, 0x44, 0x3F, 0x00, 0x00, // "A" 
  0x00, 0x00, 0x7F, 0x49, 0x49, 0x36, 0x00, 0x00, // "B" 
  0x00, 0x00, 0x3E, 0x41, 0x41, 0x22, 0x00, 0x00, // "C" 
  0x00, 0x00, 0x7F, 0x41, 0x41, 0x3E, 0x00, 0x00, // "D" 
  0x00, 0x00, 0x7F, 0x49, 0x49, 0x41, 0x00, 0x00, // "E" 
  0x00, 0x00, 0x7F, 0x48, 0x48, 0x40, 0x00, 0x00  // "F" 
}; 

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  for (int i = 0; i < LEDPin_size; i++) {
    pinMode(LEDPin[i], OUTPUT);
  }
}

void loop() {
  // Define uma variável de um byte (8 bits) que é usada para representar o estado selecionado de 8 colunas.
  int cols;

  for (int j = 0; j < 500; j++) {
    cols = 0x01; // Atribui 0x01 (binário 00000001) à variável, que representa que a primeira coluna está selecionada.

    for (int i = 0; i < 8; i++) {     // mostra os dados de 8 colunas escaneando 
      matrixColsVal(cols);
      matrixRowsVal(smilingFace[i]);  // exibe os dados nessa coluna
      delay(1);
      matrixRowsVal(0x00);            // limpa os dados dessa coluna
      cols <<=1;
    }
  }

  // Exibir os padrões dinâmicos de números e letras.
  for (int i = 0; i < 128; i++) { // "espaço, 0-9, A-F" 16 letras, cada letra possui 8 colunas, totalizando 136 colunas. Primeiramente, exibe espaço, depois faz 128 deslocamentos (136-8).
    for (int k = 0; k < 10; k++) {    // repete a imagem de cada frame 10 vezes
      cols = 0x01;

      for (int j = i; j < 8 + i; j++) {                  // exibe a imagem em cada frame
        matrixColsVal(cols);
        matrixRowsVal(pgm_read_word_near(data + j)); // exibe os dados nessa coluna
        delay(1);
        matrixRowsVal(0x00);
        cols <<= 1;
      }
    }
  }
}

void matrixRowsVal(int value) {
  digitalWrite(latchPin, LOW);

  // Envia dados para o 74HC959 chip
  shiftOut(dataPin, clockPin, LSBFIRST, value);

  digitalWrite(latchPin, HIGH);
}

void matrixColsVal(byte value) {
  byte cols = 0x01;

  for (int i = 0; i < 8; i++) {
    // Exibe os dados para a porta correspondente
    digitalWrite(LEDPin[i], ((value & cols) == cols) ? LOW : HIGH);
    cols <<= 1;
  }
}
