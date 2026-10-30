#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    delay(1500);

    Serial.println("ESP32-S3 started!");
}

void loop() {
    Serial.println("E-reader prototype is running.");
    delay(1000);
}
