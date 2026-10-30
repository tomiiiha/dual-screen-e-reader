#include <Arduino.h>

const int buttons[] = {4, 5, 6, 7, 8};

const char* names[] = {
    "Center",
    "Down",
    "Right",
    "Up",
    "Left"
};

bool wasPressed[5] = {false};

void setup() {
    Serial.begin(115200);

    for (int i = 0; i < 5; i++) {
        pinMode(buttons[i], INPUT_PULLUP);
    }

    Serial.println("All buttons ready");
}

void loop() {
    for (int i = 0; i < 5; i++) {
        bool pressed = (digitalRead(buttons[i]) == LOW);

        if (pressed && !wasPressed[i]) {
            Serial.print(names[i]);
            Serial.println(" pressed");
        }

        wasPressed[i] = pressed;
    }

    delay(20);
}
