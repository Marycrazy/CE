#include <Arduino.h>
void leitura_temperatura_gas(){
  float temperature = map(analogRead(A0), 0, 1023, -49, 448);
    Serial.println("temperatura:");  
    Serial.print(temperature);
		Serial.println("C");  
    int gas=analogRead(A2);
    Serial.println("\nGaz:");
    Serial.print(gas);
    if (temperature>30 || gas>130){
      tone(4, 1500);
      delay(500);
      noTone (4);
      delay(500);
    }
}
void luz(){
  int luz=analogRead(A1);
  if (luz>600)
    digitalWrite(3,HIGH);
  else
    digitalWrite(3,LOW);
  Serial.println("\nluz: ");
  Serial.print(luz);
}
void setup() {
  pinMode (A2, INPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);	
}
void loop() {
  leitura_temperatura_gas();
  luz();
  delay(1000);
}

