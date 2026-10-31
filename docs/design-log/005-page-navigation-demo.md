# 005 — E Ink page navigation with the ANO wheel

**Date:** 2026-10-31  
**Status:** Successful in a standalone test sketch; not yet confirmed inside CrossPoint Reader.

## Goal

Combine the working Good Display E Ink output with the Adafruit ANO navigation wheel so a button press or rotation can switch between two simple test pages. This establishes that the input wiring and display wiring can coexist in a basic prototype.

## Hardware used

- Waveshare ESP32-S3 development board, powered from USB.
- Good Display GDEH0576T81 5.76-inch, 920 × 680 monochrome E Ink panel.
- DESPI-C02 3.3 V display interface adapter.
- Adafruit ANO rotary navigation encoder breakout (#6311).
- Breadboard and jumper wires; no storage card or battery.

The ANO was already tested on Oct 30, and GxEPD2 had already shown Hello World on the display on Oct 31. The combined demo then successfully changed displayed pages using both the ANO buttons and rotary wheel.

## Wiring

See [the consolidated pin map](../hardware-wiring.md). The working E Ink connections occupied GPIO11–16, while ANO inputs occupied GPIO4–10, with common ground.

## What was demonstrated

- [x] Input events from ANO controls in standalone test firmware.
- [x] Page switching on the E Ink screen through ANO button controls.
- [x] Page switching on the E Ink screen through rotary movement.
- [ ] Full book/EPUB navigation.
- [ ] CrossPoint Reader input mapping with ANO controls.
- [ ] Quantitative page-turn latency, refresh/ghosting comparisons, and idle power measurements.

## Source preservation

The exact combined-demo sketch and its commit hash have **not** been verified in the main GitHub repository. Recover it from the local development environment and commit it in a separate `firmware/page-navigation-demo/` directory, keeping the known-working `firmware/eink-display-test/` unchanged. Do not replace the only working display test with an experimental sketch.

## Next

Use the CrossPoint application layer to map the same physical controls to menu selection and page turning; treat this as a separate integration milestone from the standalone demo.
