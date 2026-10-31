# 003 — ESP32 and navigation wheel tests

Date: 2026-10-30
Status: ESP32 and encoder tested; display not tested yet

## What I did

The ESP32-S3 board and the Adafruit ANO rotary navigation encoder arrived, so I started wiring things up on the breadboard.

I set up a PlatformIO project in VS Code using the ESP32-S3 DevKitC-1 board profile and Arduino framework. At first I accidentally tried compiling with the normal C++ runner, which failed because it couldn't find `Arduino.h`. Switching to PlatformIO Build and Upload worked.

After uploading the first serial test, nothing showed in the Serial Monitor until I selected the correct COM port. Once that was fixed, the ESP32 printed the test message once per second.

Then I tested the center button, added the other four directional buttons, and finally connected the encoder's A/B rotation pins. All five buttons and clockwise/counterclockwise rotation worked.

One of the directional buttons initially seemed broken. I had the wire connected to the wrong GPIO pin, so fixing that solved it without changing the code.

I also saved a small mock menu example using the wheel to move between three options and the center button to select. I haven't confirmed that test in the serial monitor yet.

## Wiring

| ANO pin | ESP32 pin | Used for |
| --- | --- | --- |
| COMA | GND | Common |
| COMB | GND | Common |
| SW1 | GPIO4 | Center |
| SW2 | GPIO5 | Down |
| SW3 | GPIO6 | Right |
| SW4 | GPIO7 | Up |
| SW5 | GPIO8 | Left |
| ENCA | GPIO9 | Rotary A |
| ENCB | GPIO10 | Rotary B |

Everything was powered from the ESP32's USB connection. No battery testing yet.

## Code

I kept all five test programs in [`firmware/esp32-tests`](../../firmware/esp32-tests/). The one in `src/main.cpp` is currently the working rotary wheel test. They're separate programs, not meant to be compiled together.

## What works / doesn't work yet

- [x] Build and upload code through PlatformIO
- [x] Serial output at 115200 baud
- [x] Center button
- [x] Up, down, left, right
- [x] Rotary clockwise and counterclockwise
- [x] Mock menu example
- [ ] E Ink panel
- [ ] Reading firmware / EPUBs
- [ ] Second screen

## Next

Get the 5.76-inch Good Display panel running with the correct adapter. After that, look into porting open-source e-reader software instead of making the whole interface myself.
