# CrossPoint Reader port — initial research

Started: 2026-10-31  
Status: **Research / planning only — nothing ported or flashed yet**

I don't want to write my own EPUB reader. CrossPoint Reader is a possible open-source firmware base that already has book library navigation and EPUB rendering.

## Links

- [CrossPoint Reader source code](https://github.com/crosspoint-reader/crosspoint-reader)
- [CrossPoint PlatformIO configuration](https://github.com/crosspoint-reader/crosspoint-reader/blob/main/platformio.ini)
- [CrossPoint input mapping](https://github.com/crosspoint-reader/crosspoint-reader/blob/main/src/MappedInputManager.h)
- [FreeInk SDK](https://github.com/Free-Ink/freeink-sdk)
- [FreeInk board profiles](https://github.com/Free-Ink/freeink-sdk/blob/main/libs/hardware/BoardConfig/include/BoardConfig.h)
- [FreeInk display drivers](https://github.com/Free-Ink/freeink-sdk/tree/main/libs/display/FreeInkDisplay/src/driver)

## What looks reusable

- CrossPoint already supports multiple ESP32-S3 reader devices, so it's not restricted to ESP32-C3.
- Its `src/main.cpp` uses hardware-facing HAL classes such as `HalDisplay`, `HalGPIO`, and `HalStorage`.
- FreeInk defines board profiles and display drivers separately from the reader UI.
- FreeInk's display driver directory contains an `Ssd2677Driver`, but compatibility with this exact GDEH0576T81 panel's initialization, geometry, and waveforms still needs to be established. We already have a working GxEPD2 driver for this panel and can investigate wrapping it if necessary.
- CrossPoint has `MappedInputManager` with page-forward/page-back and directional actions. The ANO wheel needs quadrature decoding and event mapping.

## Our confirmed hardware

| Part | Working configuration |
| --- | --- |
| MCU | Waveshare ESP32-S3 development board |
| Display | GDEH0576T81 (920 × 680), DESPI-C02, GxEPD2 |
| Display SPI | MOSI 11, SCK 12, CS 13, DC 14, RST 15, BUSY 16 |
| Input | ANO buttons GPIO4–8, encoder A/B GPIO9–10 |
| Serial | 115200 baud; COM4 on current Windows PC |
| Storage | No microSD hardware connected yet |

## Proposed work sequence

1. Clone CrossPoint into a **separate local folder**, with the `freeink-sdk` Git submodule. Keep the current working test programs untouched.
2. Read the existing ESP32-S3 board environments in CrossPoint's `platformio.ini` and the corresponding FreeInk board profiles.
3. Define a dedicated FreeInk board profile for the prototype pinout and 920 × 680 panel; avoid pretending this is an existing supported device.
4. Determine whether FreeInk's SSD2677 code can handle the panel exactly, or bridge the known-working GxEPD2 driver into FreeInk's display interface.
5. Connect ANO directional/center inputs and the rotary events to CrossPoint's input actions.
6. Add supported microSD storage, then test loading one EPUB.
7. Later examine dual-screen rendering; it's outside the scope of the initial port.

## Not yet verified

- Which display-driver implementation will be used by the port
- Build/flash compatibility and actual flash/PSRAM variant of this particular dev board
- SD-card interface and available GPIO after adding storage
- Memory use during EPUB rendering
- Dual-display architecture

**Do not flash a CrossPoint release binary built for an Xteink or other device onto this prototype.** Existing binaries use different board definitions and wiring.
