# 002 — First Parts Ordered

Date: 2026-10-21
Status: Parts ordered, not tested

## What I decided today

I've been looking at 6–7 inch E Ink displays, but finding something high-resolution, affordable, easy to drive, *and* frontlit has been more annoying than expected.

For now I'm going with one 5.76-inch Good Display panel to learn how to drive E Ink. It has a 920 x 680 black-and-white display (~198 PPI). This doesn't mean I've picked the final screen size for both pages.

I still want to be able to read in the dark, but a built-in frontlight isn't a must anymore. A little gooseneck reading lamp that folds away into the case might be fun. That idea needs testing before I design around it.

## Ordered

- Waveshare ESP32-S3 development board (need to confirm the exact version from my order)
- Adafruit ANO rotary navigation encoder breakout #6311 (pre-soldered encoder)
- One Good Display GDEH0576T81 5.76-inch E Ink display (need to confirm adapter-board option)

I already have a breadboard and male-to-male jumper wires.

## What I haven't done yet

- No wiring or power tests yet
- No firmware running on the board yet
- No display tests
- No final battery, second display, or enclosure design

## Next

Start on USB power. Get the ESP32 working first, then the encoder, and then the E Ink screen. Once that works I want to use the wheel to switch between two pages of text.
