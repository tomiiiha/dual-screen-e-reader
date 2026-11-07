# SD card and E Ink test

This is the working PlatformIO test that reads text from the SD card and puts it on the E Ink screen. It is separate from CrossPoint.

On November 7, 2026, the ESP32-S3 read the first line of `/test.txt` from the card and displayed it on the GDEH0576T81. It uses GxEPD2 1.6.9, with SD initialized at 1 MHz SPI and E Ink configured at 4 MHz.

## Wiring

| ESP32-S3 | SD breakout | E Ink / DESPI-C02 |
| --- | --- | --- |
| 3V3 | 3V | 3.3 V input |
| GND | GND | GND |
| GPIO9 | D3/CS | — |
| GPIO10 | D0/SO | — |
| GPIO11 | CMD/SI | SDI / MOSI |
| GPIO12 | CLK | SCK |
| GPIO13 | — | CS |
| GPIO14 | — | D/C |
| GPIO15 | — | RESET |
| GPIO16 | — | BUSY |
| GPIO17 | DET | — |

D1 and DAT2 are unused. Power is 3.3 V. Unplug USB before moving wires.

## Run it

1. Put a FAT32 microSD card in the breakout.
2. Make `/test.txt` in the root of the card. The first line can say `Hello from my e-reader!`.
3. Open this folder as a PlatformIO project, upload `src/main.cpp`, and open the serial monitor at 115200 baud.
4. The first line should appear on the E Ink panel.

**This is not a three-device test.** The ANO rotary encoder originally used GPIO9 and GPIO10, which the SD card uses now, and there was also a reported overlap at GPIO11. Move the conflicting ANO connections before testing navigation and storage together.

It doesn't open EPUB files or run the CrossPoint library UI.
