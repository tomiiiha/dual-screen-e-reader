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

// Rotary encoder pins
const int encoderA = 9;
const int encoderB = 10;

int lastA;

void setup() {
    Serial.begin(115200);

    // Set up the five buttons
    for (int i = 0; i < 5; i++) {
        pinMode(buttons[i], INPUT_PULLUP);
    }

    // Set up the rotary encoder
    pinMode(encoderA, INPUT_PULLUP);
    pinMode(encoderB, INPUT_PULLUP);

    lastA = digitalRead(encoderA);

    Serial.println("Navigation wheel ready");
}

void loop() {

    // Check buttons
    for (int i = 0; i < 5; i++) {
        bool pressed = (digitalRead(buttons[i]) == LOW);

        if (pressed && !wasPressed[i]) {
            Serial.print(names[i]);
            Serial.println(" pressed");
        }

        wasPressed[i] = pressed;
    }

    // Check rotation
    int currentA = digitalRead(encoderA);

    if (currentA != lastA && currentA == LOW) {
        if (digitalRead(encoderB) == HIGH) {
            Serial.println("Clockwise");
        } else {
            Serial.println("Counterclockwise");
        }
    }

    lastA = currentA;

    delay(2);
}
