#define DELAY_TIME 200

int led1Pin = 4;  
int led2Pin = 5; 
 
void setup() { 
  pinMode(led1Pin, OUTPUT); 
  pinMode(led2Pin, OUTPUT); 
} 
 
void loop() { 
  setLed(HIGH); // Ligando o led 1 e desligando o led 2.
  setLed(LOW); // Desligando o led 1 e ligando o led 2.
} 
 
void setLed(int led1) { 
  digitalWrite(led1Pin, led1);
 
  if (led1 == HIGH) 
    digitalWrite(led2Pin, LOW); 
  else 
    digitalWrite(led2Pin, HIGH);
 
  delay(DELAY_TIME);       
} 
