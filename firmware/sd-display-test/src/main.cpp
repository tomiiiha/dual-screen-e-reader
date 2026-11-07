#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <GxEPD2_BW.h>

// Shared SPI bus
#define SPI_SCK  12
#define SPI_MOSI 11
#define SPI_MISO 10

// SD card
#define SD_CS    9
#define SD_DET  17

// E Ink display
#define EPD_CS   13
#define EPD_DC   14
#define EPD_RST  15
#define EPD_BUSY 16

// GDEH0576T81 (920 x 680)
GxEPD2_BW<GxEPD2_576_GDEH0576T81, 64> display(
    GxEPD2_576_GDEH0576T81(
        EPD_CS, EPD_DC, EPD_RST, EPD_BUSY
    )
);

void setup() {
    Serial.begin(115200);
    delay(2000);

    Serial.println("\n=== Combined Hardware Test ===");

    // Deselect both SPI devices
    pinMode(SD_CS, OUTPUT);
    pinMode(EPD_CS, OUTPUT);
    digitalWrite(SD_CS, HIGH);
    digitalWrite(EPD_CS, HIGH);
    pinMode(SD_DET, INPUT);

    SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI, SD_CS);

    Serial.println("Initializing SD card...");
    bool sdReady = SD.begin(SD_CS, SPI, 1000000);
    String message = "SD initialization failed!";

    if (sdReady) {
        Serial.println("SD initialized successfully!");
        File file = SD.open("/test.txt", FILE_READ);

        if (file) {
            message = file.readStringUntil('\n');
            message.trim();
            file.close();
            Serial.print("Read from SD: ");
            Serial.println(message);
        } else {
            message = "test.txt not found!";
            Serial.println(message);
        }
    } else {
        Serial.println("SD initialization failed!");
    }

    digitalWrite(SD_CS, HIGH);

    display.epd2.selectSPI(
        SPI,
        SPISettings(4000000, MSBFIRST, SPI_MODE0)
    );

    Serial.println("Initializing E Ink display...");
    display.init(115200);
    display.setRotation(0);
    display.setFullWindow();

    display.firstPage();
    do {
        display.fillScreen(GxEPD_WHITE);
        display.setTextColor(GxEPD_BLACK);

        display.setTextSize(3);
        display.setCursor(30, 70);
        display.println("SD Card Test");

        display.setTextSize(2);
        display.setCursor(30, 140);
        display.println(message);
    } while (display.nextPage());

    Serial.println("Display updated successfully!");
    Serial.println("=== Test Complete ===");
}

void loop() {}
