#include <Arduino.h>

const int centerButton = 4;
const int encoderA = 9;
const int encoderB = 10;

const char* menu[] = {
    "Continue Reading",
    "Library",
    "Settings"
};

const int menuSize = 3;
int selected = 0;

int lastA;
bool lastCenter = HIGH;

void showMenu() {
    Serial.println("\n--- E-READER MENU ---");

    for (int i = 0; i < menuSize; i++) {
        if (i == selected) {
            Serial.print("> ");
        } else {
            Serial.print("  ");
        }

        Serial.println(menu[i]);
    }
}

void setup() {
    Serial.begin(115200);

    pinMode(centerButton, INPUT_PULLUP);
    pinMode(encoderA, INPUT_PULLUP);
    pinMode(encoderB, INPUT_PULLUP);

    lastA = digitalRead(encoderA);
    lastCenter = digitalRead(centerButton);

    delay(500);
    showMenu();
}

void loop() {
    int currentA = digitalRead(encoderA);

    // Rotate wheel to change selection
    if (currentA != lastA && currentA == LOW) {
        if (digitalRead(encoderB) == HIGH) {
            selected = (selected + 1) % menuSize;
        } else {
            selected = (selected - 1 + menuSize) % menuSize;
        }

        showMenu();
    }

    lastA = currentA;

    // Press center to select
    bool currentCenter = digitalRead(centerButton);

    if (currentCenter == LOW && lastCenter == HIGH) {
        Serial.print("\nSelected: ");
        Serial.println(menu[selected]);
        delay(30);
    }

    lastCenter = currentCenter;

    delay(2);
}
