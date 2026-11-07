# Prototype wiring

**Updated November 7, 2026.** This is the wiring used for the standalone SD card/display test. Everything is powered through the ESP32-S3's USB connection for now.

## SD card and E Ink display — tested together

The SD card and display use the same SPI clock and MOSI lines. They each have their own chip-select pin.

| ESP32-S3 pin | microSD breakout | E Ink / DESPI-C02 |
| --- | --- | --- |
| 3V3 | 3V | 3.3 V input |
| GND | GND | GND |
| GPIO9 | D3/CS | — |
| GPIO10 | D0/SO (MISO) | — |
| GPIO11 | CMD/SI (MOSI) | SDI / MOSI |
| GPIO12 | CLK (SCK) | SCK |
| GPIO13 | — | CS |
| GPIO14 | — | D/C |
| GPIO15 | — | RESET |
| GPIO16 | — | BUSY |
| GPIO17 | DET (card detect) | — |

The SD card's D1 and DAT2 pins are not used. The tested SPI speed for SD initialization was 1 MHz; the standalone display test used 4 MHz for E Ink.

I use common 3.3 V and ground rails on the breadboard. I need to make sure any split rails are connected. Don't connect either board to a 5 V power rail without checking the board specifications first. Disconnect USB before moving jumpers.

**Test result:** The ESP32 read the first line of `/test.txt` from the FAT32 SD card and drew it on the GDEH0576T81 using GxEPD2. Card detection, SD file writing, and SD file reading also passed in separate tests.

## ANO navigation controls — old tested wiring, now conflicts

The ANO was tested before I added the SD card. These were the pins used at that point:

| ANO function | Original ESP32-S3 pin | Status |
| --- | --- | --- |
| Center/select | GPIO4 | Previously tested |
| Down | GPIO5 | Previously tested |
| Right | GPIO6 | Previously tested |
| Up | GPIO7 | Previously tested |
| Left | GPIO8 | Previously tested |
| Rotary encoder A | GPIO9 | **Conflict: SD CS** |
| Rotary encoder B | GPIO10 | **Conflict: SD MISO** |
| Switch commons | GND | Shared ground |

I also reported that GPIO11 was physically shared with a rotary-control connection in the current breadboard setup. I need to trace that wire before doing the final three-device test; GPIO11 is already the shared SPI MOSI signal.

The buttons were tested with `INPUT_PULLUP` in the standalone control program. The ANO's rotary inputs cannot stay on GPIO9/10 while those pins are used by the SD card. An ordinary button connection also cannot share GPIO11 with SPI MOSI. I'll move any overlapping ANO signals to free GPIOs and update the firmware before claiming the input controls work alongside storage.

## What's not wired or settled

- Final ANO pin mapping with SD attached
- CrossPoint's SD and input configuration
- Battery, charging, power switch, and sleep/wake hardware
- Second display, frontlight, hinge, and enclosure

Older logs show the original ANO mapping and a proposed SD mapping using GPIO17/18. Those were earlier plans. The **tested SD wiring is GPIO9 CS, GPIO10 MISO, GPIO11 MOSI, GPIO12 SCK, and GPIO17 DET**.
