# Electronics / Parts List

Last updated: 2026-10-30

This is mostly to keep track of parts I have, what I have tested, and what I might use later. The complete e-reader hardware is still being figured out.

## Received and tested

| Part | Qty | Notes |
| --- | --- | --- |
| [Waveshare ESP32-S3 development board](https://www.waveshare.com/esp32-s3-dev-kit-n8r8.htm) | 1 | Built, uploaded, and ran test code through PlatformIO. Serial output works. |
| [Adafruit ANO rotary navigation encoder breakout, #6311](https://www.adafruit.com/product/6311) | 1 | All five switches and both rotation directions tested successfully. |

## Ordered, not tested yet

| Part | Qty | Notes |
| --- | --- | --- |
| [Good Display GDEH0576T81 5.76-inch E Ink panel](https://buy-oled.com/products/gdeh0576t81) | 1 | 920 x 680 (~198 PPI), black and white. Ordered with adapter board; still need to verify the actual hardware and wiring when it arrives. |

## Already have

- Breadboard
- A bunch of male-to-male jumper wires

## Still figuring out

- A second screen for the two-page version (only ordered one for now)
- Display adapter pinout and wiring (ordered with the screen; not inspected or connected yet)
- Any extra jumper types or headers needed for the actual connectors
- microSD storage
- Battery, charger, and power management
- Lighting: built-in frontlight would be nice, but a little stowable gooseneck light could also work
- Final PCB, hinge, and enclosure

## First things to test

1. [x] Power the ESP32 through USB and upload a simple program.
2. [x] Read button presses and rotation from the ANO encoder.
3. [ ] Get one E Ink display working with its proper adapter/driver hardware.
4. [ ] Show some text, then switch between two test pages using the encoder.

Not buying a second screen or battery just yet. I want to get the first screen working before worrying about the folding part.
