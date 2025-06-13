const int sensorIR1 = 2;
const int sensorIR2 = 4;

void setup() {
  Serial.begin(115200);
  pinMode(sensorIR1, INPUT);
  pinMode(sensorIR2, INPUT);
}

void loop() {
  int nilaiIR1 = digitalRead(sensorIR1);
  int nilaiIR2 = digitalRead(sensorIR2);

  Serial.print("Sensor 1: ");
  Serial.print(nilaiIR1 == LOW ? "TERDETEKSI" : "TIDAK");
  Serial.print(" | Sensor 2: ");
  Serial.println(nilaiIR2 == LOW ? "TERDETEKSI" : "TIDAK");

  delay(500);
}
