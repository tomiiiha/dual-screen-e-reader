# Dual-Screen E-Reader

I'm building a foldable, two-page E Ink reader with physical controls and software I can modify myself. For now I'm getting one screen working properly before buying a second display or designing the enclosure.

**Current status (November 7, 2026):** The ESP32-S3 can read a text file from a microSD card and display it on the GDEH0576T81. The SD card and screen have been tested together on a shared SPI bus. This is still a standalone test, not a working EPUB reader.

## Design goals

- Two monochrome E Ink pages in a folding case, eventually.
- Comfortable to hold and easy to use with one hand.
- Physical navigation and page-turn buttons. No touchscreen planned.
- Books stored locally, without depending on Kindle firmware or services.
- A clear or translucent case if I can make it practical.
- Some way to read at night. Built-in frontlighting would be nice, but a small separate light is also an option.

The 5.76-inch, 920 x 680 display is the panel I'm using for development. I haven't settled on the final screen size or enclosure.

## Progress

| Date | What I did | Result |
| --- | --- | --- |
| Oct 2026 | Set up the ESP32-S3 and PlatformIO | Uploading code and serial output work |
| Oct 30 | Tested the ANO navigation controls | Five direction/select switches and rotary movement worked in standalone tests |
| Oct 31 | Tested the GDEH0576T81 with GxEPD2 | Hello World and a page-changing demo worked |
| Oct 31 | Built my modified CrossPoint Reader firmware | `custom_reader` compiled, flashed, and displayed an SD card error screen |
| Nov 7 | Connected the microSD breakout | FAT32 card detection, initialization, file writing, and file reading worked |
| Nov 7 | Put SD and E Ink on the same SPI bus | Read `test.txt` from the card and displayed its text on the screen |

There is still a GPIO conflict to fix: the earlier ANO encoder wiring uses pins now assigned to the SD card. The SD/display test passed, but I haven't established working SD, E Ink, and rotary navigation all at once. The ANO input wiring needs to be moved and tested again.

## Hardware on the bench

- ESP32-S3 development board
- Good Display GDEH0576T81, 5.76-inch, 920 x 680 E Ink panel
- DESPI-C02 display adapter
- Adafruit ANO rotary navigation control breakout
- Adafruit microSD SPI/SDIO breakout
- 128 GB microSD card, reformatted as FAT32
- Breadboard, jumper wires, and USB power

The single-screen development setup is still on a breadboard. There is no battery, second panel, or final PCB yet.

## Code and notes

- [SD card and display test](firmware/sd-display-test/)
- [Standalone SD card read/write test](firmware/sd-card-test/)
- [Latest design log](docs/design-log/008-sd-card-and-display.md)
- [Wiring and pin assignments](docs/hardware-wiring.md)
- [Parts list](electronics/components.md)
- [Next steps](docs/next-steps.md)
- [CrossPoint first boot](docs/design-log/006-crosspoint-first-boot.md)
- [CrossPoint backup notes](docs/design-log/007-firmware-checkpoint.md)

The earlier GxEPD2 examples are still under `firmware/eink-display-test/`. I want to keep those as known-working tests while I change the main firmware.

## CrossPoint status

I have a modified local CrossPoint/FreeInk build for this ESP32-S3 and display. It boots and draws on the panel, but the SD card has only been tested in separate PlatformIO programs so far. CrossPoint itself has **not** been updated and verified with the new storage wiring. No EPUB has been opened yet.

The modified CrossPoint source and FreeInk SDK changes are backed up locally; they aren't fully reproducible from this repository yet. See the [checkpoint notes](docs/design-log/007-firmware-checkpoint.md).

## License

I haven't selected a license for my own project files yet. CrossPoint Reader and its dependencies retain their upstream licenses.
