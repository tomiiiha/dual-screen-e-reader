# Prototype hardware wiring and pin allocation

**Updated:** 2026-10-31. One ESP32-S3, one E Ink panel, one ANO navigation wheel. **3.3 V logic.**

## Verified working: E Ink display (GDEH0576T81 via DESPI-C02)

| Adapter signal | ESP32-S3 | State |
| --- | --- | --- |
| SDI / MOSI | GPIO11 | Verified |
| SCK | GPIO12 | Verified |
| CS | GPIO13 | Verified |
| D/C | GPIO14 | Verified |
| RES / RESET | GPIO15 | Verified |
| BUSY | GPIO16 | Verified |
| GND | GND | Verified |
| 3.3 V | 3V3 | Verified |

Display example: GxEPD2 `GxEPD2_576_GDEH0576T81`, native 920 × 680 monochrome, USB-powered ESP32. A native-resolution CrossPoint error screen also rendered with the custom port on October 31.

## Verified working: Adafruit ANO controls

| ANO signal | ESP32-S3 | Purpose |
| --- | --- | --- |
| COMA | GND | Common switch ground |
| COMB | GND | Common switch ground |
| SW1 | GPIO4 | Center/select |
| SW2 | GPIO5 | Down |
| SW3 | GPIO6 | Right |
| SW4 | GPIO7 | Up |
| SW5 | GPIO8 | Left |
| ENCA | GPIO9 | Rotary A |
| ENCB | GPIO10 | Rotary B |

Standalone controls worked with internal pull-ups (`INPUT_PULLUP`), and a separate ANO + display demonstration successfully changed pages. CrossPoint's actual input mapping remains unverified.

## Proposed only: microSD storage breakout

**Not connected or electrically tested yet.** Current planned purchase: Adafruit #4682 microSD SPI/SDIO breakout and a microSD card. The exact card capacity and purchase receipt are not yet captured here.

| SPI signal | ESP32-S3 proposal | Comment |
| --- | --- | --- |
| CLK / SCK | GPIO12 | Share SPI clock with E Ink |
| DI / MOSI | GPIO11 | Share MOSI with E Ink |
| DO / MISO | GPIO17 | New input for card reads |
| SD CS | GPIO18 | Separate chip select from E Ink CS=13 |
| 3V / VCC | 3V3 | Check actual breakout labeling/specification |
| GND | GND | Shared ground |

Do not confuse the adapter's SDI (E Ink MOSI) with a microSD card's DI/DO signals. For shared SPI, each device must have a separate CS and inactive devices must be deselected. Verify the breakout's pinout and whether library configuration expects hardware SPI or its own `SdFat` SPI object.

## Physical/electrical cautions

- Disconnect USB power before re-routing ribbon cables, jumpers, or headers.
- Do not apply 5 V logic/power to the DESPI-C02 setup that worked at 3.3 V.
- Keep leads short and mechanically secure; breadboard wiring is a temporary proof of concept.
- The final SD, display, and ANO hardware must be tested together before assigning unused GPIOs to other peripherals.
- The second display, power management, lighting, and custom PCB have no final pin assignments yet.
