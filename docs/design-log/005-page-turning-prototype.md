# 005 — First page-turning prototype

Date: 2026-10-31  
Status: **Successful — wheel and Left/Right buttons both turn pages**

## What I did

After getting the first Hello World display test to work, I combined the E Ink display code with the ANO navigation-wheel input code. I kept the same breadboard wiring and used PlatformIO to upload one program that draws two pages of hardcoded sample text.

The display shows a title, body text, and a page number. Moving forward or backward causes the ESP32 to redraw the display. I tried it on the physical E Ink panel, and the pages changed successfully. I also checked both ways of turning pages: rotating the navigation wheel **and** pressing the Left/Right buttons. Both worked.

I didn't implement EPUB loading, page layout for real books, or partial refresh in this test. The story text is included directly in the C++ code. This is just to make sure the display and controls work together before moving to existing reader firmware.

## Hardware and wiring

- Waveshare ESP32-S3 development board, powered over USB
- Good Display GDEH0576T81 (5.76 in, 920 × 680) on DESPI-C02 adapter
- Adafruit ANO rotary navigation encoder #6311
- ANO switch commons to GND; buttons GPIO4–8; encoder A/B GPIO9–10
- E Ink: MOSI GPIO11; SCK GPIO12; CS GPIO13; D/C GPIO14; RESET GPIO15; BUSY GPIO16; power 3V3 and GND

Full wiring table and PlatformIO files are in [`firmware/page-turn-test/`](../../firmware/page-turn-test/).

## Software

The project uses the Arduino framework in PlatformIO with GxEPD2 (`GxEPD2_576_GDEH0576T81`). The screen is set to portrait orientation with `display.setRotation(1)`. A simple 180 ms guard prevents immediately repeating a page change.

The display uses full refreshes. The input handling is enough for testing but not yet robust enough for final reader firmware. The sample text is not loaded from a file.

## Results

- [x] Two sample pages render on the physical display
- [x] Clockwise / counterclockwise wheel navigation changes pages
- [x] Right / Left button navigation changes pages
- [x] Display and inputs work simultaneously in one program
- [ ] EPUB support or local library storage
- [ ] CrossPoint Reader adapted to this board
- [ ] Two displays at once

## Next

Investigate CrossPoint Reader and the FreeInk SDK. I want to reuse its book reading and library software, then adapt the display and input handling to this hardware. Keep the Hello World and page-turn projects as known-working references.
