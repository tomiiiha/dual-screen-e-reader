#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

#define SD_CS   9
#define SD_MISO 10
#define SD_MOSI 11
#define SD_SCK  12
#define SD_DET  17

void setup() {
    Serial.begin(115200);
    delay(2000);

    Serial.println("\n=== SD Card Test ===");

    pinMode(SD_DET, INPUT);
    Serial.print("Card detected: ");
    Serial.println(digitalRead(SD_DET) ? "YES" : "NO");

    pinMode(SD_CS, OUTPUT);
    digitalWrite(SD_CS, HIGH);
    SPI.begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);

    Serial.println("Attempting SD initialization...");
    if (!SD.begin(SD_CS, SPI, 1000000)) {
        Serial.println("SD initialization FAILED");
        return;
    }

    Serial.println("SD initialization SUCCESS!");
    Serial.print("Card size: ");
    Serial.print(SD.cardSize() / (1024ULL * 1024 * 1024));
    Serial.println(" GiB");
    Serial.print("Card type: ");
    Serial.println(SD.cardType());

    File file = SD.open("/test.txt", FILE_WRITE);
    if (file) {
        file.println("Hello from my e-reader!");
        file.close();
        Serial.println("File written successfully!");
    } else {
        Serial.println("File write FAILED");
    }

    File readFile = SD.open("/test.txt", FILE_READ);
    if (readFile) {
        Serial.println("Reading test.txt:");
        while (readFile.available()) {
            Serial.write(readFile.read());
        }
        readFile.close();
    } else {
        Serial.println("Failed to read file!");
    }

    Serial.println("\n=== Test Complete ===");
}

void loop() {}
