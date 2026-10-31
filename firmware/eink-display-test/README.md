# First E Ink display test — 2026-10-31

This is the first **working** display program for my custom e-reader. It displays `Hello World!`, a second line of text, and a rectangular border on a 5.76-inch monochrome E Ink panel.

This is a separate PlatformIO project from `firmware/esp32-tests/`, which contains the earlier navigation-wheel tests. Keep both for reference.

## Hardware

- Waveshare ESP32-S3 development board
- Good Display GDEH0576T81 (5.76 in, 920 x 680)
- Good Display DESPI-C02 adapter/driver board
- USB connection for development power
- Breadboard and jumpers

## Wiring

| DESPI-C02 | ESP32-S3 |
| --- | --- |
| BUSY | GPIO16 |
| RES | GPIO15 |
| D/C | GPIO14 |
| CS | GPIO13 |
| SCK | GPIO12 |
| SDI | GPIO11 |
| GND | GND |
| 3.3V | 3V3 |

The separate ANO wheel tests previously used GPIO4–GPIO10. This particular program doesn't read the wheel.

## Reference

For the ESP32-S3 GPIO pin layout, I referred to [Espressif's ESP32-S3 development kit documentation (PDF, page 8)](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32s3/esp-dev-kits-en-master-esp32s3.pdf#page=8). My hardware is a Waveshare ESP32-S3 development board, so the PDF was a pin-reference aid rather than a board-specific wiring diagram for the entire prototype.

## Run

1. Disconnect USB before changing any wiring. Confirm `3.3V` is connected to `3V3`, not 5 V, and the display ribbon is seated.
2. Open **this `firmware/eink-display-test` folder** as a PlatformIO project in VS Code.
3. In `platformio.ini`, make sure `monitor_port` and `upload_port` match the ESP32's **actual** serial/upload port. `COM4` is what worked on my Windows computer; other setups will differ.
4. Build and **Upload** in PlatformIO, then open the Serial Monitor at 115200 baud and press RESET if needed.
5. The screen should refresh to show `Hello World!` and the Serial Monitor should end with `Test finished.`

If the Serial Monitor still shows `E-READER MENU`, the ESP32 is running the old program. Check the active PlatformIO project and the upload port before changing the display wiring. If a display BUSY timeout appears, investigate the connections and adapter.

## Result

Successful on 2026-10-31. Full output is in `logs/first-successful-refresh.txt`. Display content was **visually confirmed** on the physical panel, not just reported as successful over serial.

This is a single-screen test. It does not yet read an EPUB, support a second screen, or integrate the navigation wheel.
