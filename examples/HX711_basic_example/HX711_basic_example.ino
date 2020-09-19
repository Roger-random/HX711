#include "HX711.h"

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {
  if (scale.is_ready()) {
    long raw = scale.read();
    if (raw < -420000 && raw > -700000) {
      double lb = (raw + 429000)/11000.0;
      if (lb > 0) {
        Serial.print("+");
      }
      if (lb < 10 && lb > -10) {
        Serial.print(lb,5);
      } else {
        Serial.print(lb,4);
      }
      Serial.println("     lbs");
    }
  }

  delay(100);
}
