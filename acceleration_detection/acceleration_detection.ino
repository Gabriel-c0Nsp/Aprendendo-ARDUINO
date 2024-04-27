#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

#define LED_PIN 13

MPU6050 accelgyro; // construindo o objeto usando o endereço padrão

int16_t ax, ay, az;
int16_t gx, gy, gz;

bool blinkState = false; 

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando aparelhos I2C");
  Wire.begin();
  accelgyro.initialize();
  Serial.println("Testando conexões com os aparelhos");

  if (accelgyro.testConnection()) {
    Serial.println("A conexão foi estabelecida com sucesso");
  } else {
    Serial.println("A conexão com MPU6050 falhou!");
    while(1);
  }

  // accelgyro.setXAccelOffset(-1200);
  // accelgyro.setYAccelOffset(-2500);
  // accelgyro.setZAccelOffset(1988);
  
  Serial.print("X.Y.Z offset :\t");
  Serial.print(accelgyro.getXAccelOffset());
  Serial.println("\t");
  Serial.print(accelgyro.getYAccelOffset());
  Serial.println("\t");
  Serial.print(accelgyro.getZAccelOffset());
  Serial.println("\t");

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  Serial.print("a/g:\t");
  Serial.print(ax);
  Serial.println("\t");
  Serial.print(ay);
  Serial.println("\t");
  Serial.print(az);
  Serial.println("\t");
  Serial.print(gx);
  Serial.println("\t\t");
  Serial.print(gy);
  Serial.println("\t\t");
  Serial.print(gz);

  Serial.print("a/g:\t");
  Serial.print((float)ax / 16384);
  Serial.print("g\t");
  Serial.print((float)ay / 16384);
  Serial.print("g\t");
  Serial.print((float)az / 16384);
  Serial.print("g\t");
  Serial.print((float)gx / 16384);
  Serial.print("d/s  \t");
  Serial.print((float)gy / 16384);
  Serial.print("d/s  \t");
  Serial.print((float)gz / 16384);
  Serial.print("d/s  \n");

  delay(300);

  blinkState = !blinkState;
  digitalWrite(LED_PIN, blinkState);
}
