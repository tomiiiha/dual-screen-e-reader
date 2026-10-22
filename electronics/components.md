# Electronics / Parts List

Last updated: 2026-10-21

This is mostly to keep track of what I've ordered and what I might use later. Nothing is confirmed to work together yet.

## Ordered

| Part | Qty | Notes |
| --- | --- | --- |
| [Waveshare ESP32-S3 development board](https://www.waveshare.com/esp32-s3-dev-kit-n8r8.htm) | 1 | Main controller for initial tests. |
| [Adafruit ANO rotary navigation encoder breakout, #6311](https://www.adafruit.com/product/6311) | 1 | Pre-soldered encoder. Want to use this for menus and page navigation. |
| [Good Display GDEH0576T81 5.76-inch E Ink panel](https://buy-oled.com/products/gdeh0576t81) | 1 | 920 x 680 (~198 PPI), black and white. Need to confirm whether my order includes the adapter board. (it does) |

Ordered doesn't mean tested yet.

## Already have

- Breadboard
- A bunch of male-to-male jumper wires

## Still figuring out

- A second screen for the two-page version (only ordered one for now)
- Display adapter and exact wiring (check which bundle I bought before connecting anything)
- Any extra jumper types or headers needed for the actual connectors
- microSD storage
- Battery, charger, and power management
- Lighting: built-in frontlight would be nice, but a little stowable gooseneck light could also work
- Final PCB, hinge, and enclosure

## First things to test

1. Power the ESP32 through USB and upload a simple program.
2. Read button presses and rotation from the ANO encoder.
3. Get one E Ink display working with its proper adapter/driver hardware.
4. Show some text, then switch between two test pages using the encoder.

Not buying a second screen or battery just yet. I want to get the first screen working before worrying about the folding part.
