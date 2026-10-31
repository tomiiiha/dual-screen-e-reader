
#include <Arduino.h>
#include <SPI.h>
#include <GxEPD2_BW.h>

// Good Display DESPI-C02 connections
#define EPD_MOSI 11
#define EPD_SCK  12
#define EPD_CS   13
#define EPD_DC   14
#define EPD_RST  15
#define EPD_BUSY 16

// GDEH0576T81: 5.76-inch, 920 x 680
GxEPD2_BW<GxEPD2_576_GDEH0576T81, 64> display(
    GxEPD2_576_GDEH0576T81(
        EPD_CS,
        EPD_DC,
        EPD_RST,
        EPD_BUSY
    )
);

void setup() {
    Serial.begin(115200);
    delay(1500);

    Serial.println();
    Serial.println("=== E-INK DISPLAY TEST ===");
    Serial.println("Starting ESP32-S3");

    // Configure SPI connections
    SPI.begin(EPD_SCK, -1, EPD_MOSI, EPD_CS);
    Serial.println("SPI initialized");

    // Initialize the screen
    Serial.println("Initializing display...");
    display.init(115200);
    Serial.println("Display initialized");

    display.setRotation(0);
    display.setFullWindow();

    Serial.println("Drawing Hello World...");

    // Draw and refresh the screen
    display.firstPage();

    do {
        display.fillScreen(GxEPD_WHITE);

        display.setTextColor(GxEPD_BLACK);
        display.setTextSize(4);

        display.setCursor(40, 100);
        display.print("Hello World!");

        display.setTextSize(2);
        display.setCursor(40, 160);
        display.print("ESP32-S3 E-Reader Test");

        display.drawRect(20, 20, 600, 200, GxEPD_BLACK);

    } while (display.nextPage());

    Serial.println("Display refresh completed!");

    // Put the display in low-power mode
    display.hibernate();

    Serial.println("Test finished.");
}

void loop() {
    // No repeated refreshes needed
}
