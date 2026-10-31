# Page-turn navigation test (October 31, 2026)

This is a working integration test of my E Ink panel and the ANO rotary navigation wheel. It displays two pages of hardcoded sample text from a short fictional story, then changes pages with either the rotary wheel or the Left/Right buttons.

**Result:** I confirmed that the screen changed and **both the wheel and the Left/Right buttons** could turn pages. This is not an EPUB reader yet.

## Hardware

- Waveshare ESP32-S3 development board (USB powered)
- Good Display GDEH0576T81, 5.76 in / 920 × 680, with DESPI-C02 adapter
- Adafruit ANO rotary navigation breakout (#6311)
- Breadboard and jumper wires

## Wiring

| Connection | ESP32-S3 |
| --- | --- |
| ANO COMA, COMB | GND |
| ANO SW1 (center) | GPIO4 |
| ANO SW2 (down) | GPIO5 |
| ANO SW3 (right) | GPIO6 |
| ANO SW4 (up) | GPIO7 |
| ANO SW5 (left) | GPIO8 |
| ANO ENCA | GPIO9 |
| ANO ENCB | GPIO10 |
| DESPI-C02 SDI | GPIO11 |
| DESPI-C02 SCK | GPIO12 |
| DESPI-C02 CS | GPIO13 |
| DESPI-C02 D/C | GPIO14 |
| DESPI-C02 RES | GPIO15 |
| DESPI-C02 BUSY | GPIO16 |
| DESPI-C02 GND | GND |
| DESPI-C02 3.3V | 3V3 (not 5V) |

The code reads Left, Right, and rotation. The other three ANO buttons are connected but aren't used in this example. Disconnect USB before changing wiring.

## Build and run

1. Open **`firmware/page-turn-test/`** as a PlatformIO project in VS Code. Do not combine multiple test files in the same `src/` folder.
2. The environment is `esp32-s3-devkitc-1`, framework Arduino, with `zinggjm/GxEPD2@^1.6.9`.
3. `COM4` worked for uploading and monitoring on my Windows computer; adjust `upload_port` and `monitor_port` for another computer.
4. Close the Serial Monitor while uploading. Build, Upload, then open Serial Monitor at 115200 baud.
5. Page 1 should appear. Rotate clockwise / press Right for page 2; rotate counterclockwise / press Left for page 1.

The program uses full-screen refresh and simple input edge detection. It is intentionally a short hardware test, not production-quality debouncing or reading software.

## Keeping tests separate

- `firmware/esp32-tests/` — first serial/button/encoder tests.
- `firmware/eink-display-test/` — first successful Hello World display test.
- `firmware/page-turn-test/` — this verified combined display + input demonstration.

## References

- [GxEPD2](https://github.com/ZinggJM/GxEPD2)
- [Espressif ESP32-S3 reference PDF, page 8](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32s3/esp-dev-kits-en-master-esp32s3.pdf#page=8) — reference for pin identification; the actual dev board is from Waveshare.
