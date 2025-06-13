#include "max6675.h"
int thermoDO = 19;
int thermoCS = 23;
int thermoCLK = 5;
MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

void setup() {
  Serial.begin(9600);
  Serial.println("MAX6675 test");
  delay(500);
}

void loop() {
  Serial.print("C = "); 
  Serial.println(thermocouple.readCelsius());
  Serial.print("F = ");
  Serial.println(thermocouple.readFahrenheit());
  delay(1000);
}
