# 004 — First E Ink display test

Date: 2026-10-31  
Status: **Successful — Hello World! visible on the display**

## What I did

The 5.76-inch Good Display GDEH0576T81 arrived with its DESPI-C02 adapter board. I checked the board and its labels before connecting it to the Waveshare ESP32-S3. The panel's ribbon cable connects to the DESPI-C02, which provides the interface and supporting electronics for the display.

I kept the ANO wheel wiring on GPIO4–GPIO10 and used GPIO11–GPIO16 for the display. The ESP32 was still powered from USB; I haven't added a battery.

I used the GxEPD2 library with its `GxEPD2_576_GDEH0576T81` driver and wrote a small PlatformIO program to draw **Hello World!**, a second line of text, and a rectangle. After some uploading confusion, the program ran and the text appeared on the physical screen.

## Wiring that worked

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

The original navigation wheel connections were left on GPIO4–GPIO10. The DESPI-C02 uses **3.3 V**, not 5 V. Any changes to the ribbon cable or jumper wiring should be made with USB power disconnected.

## Software

- VS Code with PlatformIO
- PlatformIO board: `esp32-s3-devkitc-1`
- Framework: Arduino
- Library: `zinggjm/GxEPD2@^1.6.9`
- Display class: `GxEPD2_576_GDEH0576T81`
- SPI mapping: MOSI GPIO11, SCK GPIO12, CS GPIO13
- Serial monitor: 115200 baud
- Working upload and monitor port on this computer: `COM4`

The complete working PlatformIO project is saved in [`firmware/eink-display-test/`](../../firmware/eink-display-test/).

## Successful Serial Monitor output

```text
=== E-INK DISPLAY TEST ===
Starting ESP32-S3
SPI initialized
Initializing display...
Display initialized
Drawing Hello World...
_PowerOn : 83000
_refresh : 925001
_PowerOff : 143001
Display refresh completed!
Test finished.
```

These are the timings printed by GxEPD2 during the successful run, in microseconds (the reported refresh interval was approximately 0.925 seconds). I also confirmed that **Hello World! was visible on the screen**, so this wasn't just a successful serial log.

## What is now confirmed

- [x] ESP32-S3 can run the GxEPD2 display example.
- [x] SPI wiring between ESP32-S3 and DESPI-C02 works for this test.
- [x] GDEH0576T81 physically displays the test text and border.
- [x] One full-screen refresh completes.
- [x] Navigation wheel's buttons and rotation worked in earlier separate tests.
- [ ] Wheel input and E Ink screen tested together in one firmware program.
- [ ] Partial-refresh behavior measured and evaluated.
- [ ] EPUB rendering / library / microSD.
- [ ] Two-screen operation.
- [ ] Battery power and enclosure.

## Next

Keep this code as a known-working test instead of replacing it with untested firmware. My next major goal is to investigate adapting existing open-source e-reader firmware (especially CrossPoint Reader) to this display and the ANO wheel, rather than writing an EPUB engine from scratch.
