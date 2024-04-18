int buzzerPin = 9;
float sinValue; // definindo uma variável para salvar o valor de seno 
int toneValue; // definindo uma variável para salvar a frequência do som

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  for (int x = 0; x < 360; x++) {
    sinValue = sin(x * (PI / 180)); // calculando seno de x  
    toneValue = 2000 + sinValue * 500; // calculando a frequência do som de acordo com o seno de x 
    tone(buzzerPin, toneValue);
    delay(1);
  }
}
