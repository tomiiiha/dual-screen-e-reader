# Electronics / Parts List

Last updated: 2026-10-31

This is mostly to keep track of parts I have, what I have tested, and what I might use later. The complete e-reader hardware is still being figured out.

## Received and tested

| Part | Qty | Notes |
| --- | --- | --- |
| [Waveshare ESP32-S3 development board](https://www.waveshare.com/esp32-s3-dev-kit-n8r8.htm) | 1 | Running PlatformIO firmware. USB serial and SPI display test both work. |
| [Adafruit ANO rotary navigation encoder breakout, #6311](https://www.adafruit.com/product/6311) | 1 | All five switches and both rotation directions tested successfully on 2026-10-30. |
| [Good Display GDEH0576T81 5.76-inch E Ink panel](https://buy-oled.com/products/gdeh0576t81) | 1 | 920 x 680 (~198 PPI), monochrome. **Hello World! displayed successfully** on 2026-10-31 using the DESPI-C02 adapter and GxEPD2. |
| Good Display DESPI-C02 E Ink adapter | 1 | Included with screen. Connected through SPI at 3.3 V and tested with the display. |

## Already have

- Breadboard
- A bunch of male-to-male jumper wires
- USB connection to power the ESP32 during development

## Still figuring out

- A second screen for the two-page version (only have one for now)
- Any extra jumper types or headers needed for the actual connectors
- microSD storage
- Battery, charger, and power management
- Lighting: built-in frontlight would be nice, but a little stowable gooseneck light could also work
- Final PCB, hinge, and enclosure

## Prototype test progress

1. [x] Power the ESP32 through USB and upload a simple program.
2. [x] Read button presses and rotation from the ANO encoder.
3. [x] Get one E Ink display working with its adapter and driver software.
4. [ ] Display multiple pages and switch between them with the encoder.
5. [ ] Read an actual EPUB with existing open-source firmware.

I'm not buying a second screen or battery just yet. I want to get one screen reading actual books before working on the folding hardware.
