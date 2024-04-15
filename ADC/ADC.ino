int adcValue;  
float voltage;

void setup() {
  Serial.begin(9600);
}

void loop() {
  adcValue = analogRead(A0); // Converte analog do pin A0 para digital
  voltage = adcValue * (5.0 / 1023.0); // Calcula a voltagem com relação ao digital

  // envia o resultado para o computador através do Serial
  Serial.print("convertValue: ");
  Serial.println(adcValue);
  Serial.print("voltage: ");
  Serial.println(voltage);
  delay(500);
}
