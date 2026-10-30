#include <Arduino.h>

const int centerButton = 4;

void setup() {
    Serial.begin(115200);

    pinMode(centerButton, INPUT_PULLUP);

    Serial.println("rotary button test ready");
}

void loop() {
    if (digitalRead(centerButton) == LOW) {
        Serial.println("center button pressed");
        delay(250);
    }
}
