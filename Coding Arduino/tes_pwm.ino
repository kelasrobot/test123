const int ledPin = 16;      // GPIO 16 untuk LED PWM
const int indikatorPin = 2; // GPIO 2 untuk indikator LED

int pwmValues[] = {0, 10, 20, 30, 50, 100, 150, 200};
int stepCount = sizeof(pwmValues) / sizeof(pwmValues[0]);

// PWM konfigurasi
const int freq = 5000;
const int pwmChannel = 0;
const int resolution = 8; // 8-bit (0-255)

void setup() {
  ledcSetup(pwmChannel, freq, resolution);       // setup PWM channel
  ledcAttachPin(ledPin, pwmChannel);             // attach channel ke pin
  pinMode(indikatorPin, OUTPUT);                 // indikator LED
}

void loop() {
  for (int i = 0; i < stepCount; i++) {
    int pwmValue = pwmValues[i];
    ledcWrite(pwmChannel, pwmValue);             // set PWM
    
    // Hitung delay kedipan: semakin besar pwm, semakin cepat
    // Misalnya: pwm 0 → 1000ms, pwm 200 → 100ms
    int blinkDelay = map(pwmValue, 0, 200, 1000, 100);
    unsigned long startTime = millis();

    while (millis() - startTime < 10000) {        // selama 10 detik
      digitalWrite(indikatorPin, HIGH);
      delay(blinkDelay / 2);
      digitalWrite(indikatorPin, LOW);
      delay(blinkDelay / 2);
    }
  }
}
