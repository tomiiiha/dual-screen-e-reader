# Current Hardware Pinout

Breadboard wiring for the custom CrossPoint reader, as tested November 7, 2026.

## GDEH0576T81 display through DESPI-C02

| Display signal | ESP32-S3 |
| --- | --- |
| DIN / MOSI | GPIO 11 |
| CLK / SCK | GPIO 12 |
| CS | GPIO 13 |
| DC | GPIO 14 |
| RST / RES | GPIO 15 |
| BUSY | GPIO 16 |
| VCC | 3V3 |
| GND | GND |

## microSD SPI breakout

| Breakout label | ESP32-S3 |
| --- | --- |
| SI (MOSI) | GPIO 11 |
| SO (MISO) | GPIO 10 |
| CLK | GPIO 12 |
| CS | GPIO 9 |
| 3V | 3V3 |
| GND | GND |

The display and SD card share MOSI (GPIO 11) and SCK (GPIO 12), but use separate CS pins. The custom board configuration sets the SD SPI clock to 1 MHz.

## ANO navigation controller

| ANO pin | ESP32-S3 | Current use |
| --- | --- | --- |
| SW1 | GPIO 4 | Center / Select |
| SW2 | GPIO 5 | Down |
| SW3 | GPIO 6 | Right |
| SW4 | GPIO 7 | Up |
| SW5 | GPIO 8 | Left |
| ENCA | GPIO 18 | Rotary encoder A |
| ENCB | GPIO 21 | Rotary encoder B |
| COMA | GND | Common |
| COMB | GND | Common |

Both directions of encoder rotation currently produce Back. The encoder inputs use the ESP32's internal pull-ups.

## Firmware notes

- PlatformIO environment: `custom_reader`
- ESP32-S3 board: `esp32-s3-devkitc-1`
- Display driver: `gdeh0576Driver`
- Rotary Back handling was added to `src/main.cpp`.
- Leave **Text Anti-Aliasing** disabled in CrossPoint settings until grayscale rendering is fixed.

These are the current prototype connections, not a final PCB pinout.
