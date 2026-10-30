# ESP32 / ANO wheel tests

Small programs from my first day getting the hardware working (2026-10-30). These aren't the final e-reader firmware.

## Hardware

- Waveshare ESP32-S3 development board, connected to the computer over USB
- Adafruit ANO navigation encoder breakout (#6311)
- Breadboard and jumper wires

## Wiring used

| ANO pin | ESP32 GPIO | Input |
| --- | --- | --- |
| COMA | GND | Common / ground |
| COMB | GND | Common / ground |
| SW1 | GPIO4 | Center |
| SW2 | GPIO5 | Down |
| SW3 | GPIO6 | Right |
| SW4 | GPIO7 | Up |
| SW5 | GPIO8 | Left |
| ENCA | GPIO9 | Rotary A |
| ENCB | GPIO10 | Rotary B |

The GPIO inputs use `INPUT_PULLUP`. The encoder doesn't need its own power supply for these switch inputs.

## Running a test

Open this `firmware/esp32-tests` folder as a PlatformIO project in VS Code. `src/main.cpp` currently contains the working rotary-wheel test.

To run another test, **replace the contents** of `src/main.cpp` with the contents of one file from `examples/`. Do not paste the tests together: they each define their own `setup()` and `loop()`.

Build and Upload through PlatformIO. Open the serial monitor at 115200 baud and select the port that is actually connected to the serial output (CH343 on the Waveshare board in my setup).

## Test files

| File | What it does | Status |
| --- | --- | --- |
| `01-serial-check.cpp` | Prints a message once per second | Worked |
| `02-center-button.cpp` | Reads the center click | Worked |
| `03-directional-buttons.cpp` | Reads all five buttons | Worked |
| `04-rotary-wheel.cpp` | Reads the buttons and both rotation directions | Worked |
| `05-mock-menu.cpp` | Changes a small Serial Monitor menu with the wheel | Code saved; not confirmed tested yet |

I initially tried compiling `main.cpp` with the normal VS Code C++ runner (`g++`). That failed on `Arduino.h`, because this needs PlatformIO's Arduino toolchain. The PlatformIO Build/Upload buttons worked.

I also got no serial output until I selected the correct COM port. One button wasn't working at first because I had its wire on the wrong ESP32 pin; rewiring fixed it.

The rotation code is only a quick test. It may miss or double-count steps because the mechanical encoder isn't fully debounced yet. For actual firmware I'll probably reuse an input-handling library or add proper debouncing.
