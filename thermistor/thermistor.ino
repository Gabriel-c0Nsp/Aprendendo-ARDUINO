void setup() {
  Serial.begin(9600);
}

void loop() {
  int adcVal = analogRead(A0);
  float v = adcVal * 5.0 / 1024;
  float Rt = 10 * v / (5 - v);
  float tempK = 1 / (log(Rt / 10) / 3950 + 1 / (273.15 + 25)); // calcular temperatura em Kelvin
  float tempC = tempK - 273.15; // calcular temperatura em Celsius

  Serial.print("A temperatura atual é: ");
  Serial.print(tempK);
  Serial.print(" K, ");

  Serial.print(tempC);
  Serial.println(" C");
  delay(500);
}
