# Next steps (after October 31, 2026)

## Current milestone

**Custom CrossPoint Reader firmware now boots and renders a readable 920 × 680 “SD card error.”** The physical SD hardware is not connected. E Ink Hello World and a separate ANO-controlled page demo worked beforehand.

## 1. Preserve today's work before editing further

- [ ] Save `git status` and `git diff` from the local CrossPoint clone **and each changed submodule**.
- [ ] Copy or commit the `custom_reader` PlatformIO configuration, custom board definitions, driver code, and exact library/toolchain versions to a reviewable branch or patch.
- [ ] Verify only one GDEH0576 driver implementation is built (duplicate symbols were encountered during development).
- [ ] Keep `firmware/eink-display-test/` untouched as a recovery baseline; archive the combined ANO/page demo separately.
- [ ] Note actual board module flash/PSRAM size and final partition scheme, which have not been independently cross-checked in the repository.

## 2. Connect storage — **only current purchase round**

- [ ] Receive Adafruit #4682 microSD SPI/SDIO breakout and one microSD card; capture actual model/capacity.
- [ ] Solder header pins, verify pad labels, and connect 3.3 V/GND.
- [ ] Try shared SPI SCK=GPIO12 and MOSI=GPIO11, plus SD MISO=GPIO17 and SD CS=GPIO18; **these SD pins are proposed, not tested**.
- [ ] Ensure display CS=GPIO13 and SD CS=GPIO18 are independently controlled.
- [ ] Format as FAT32 if required and run a basic storage initialization/read-write test.
- [ ] Map SD configuration in CrossPoint to the actual wiring and diagnose the SD startup error.

**Pass condition:** firmware recognizes the card and can read a known file.

## 3. First functional reader (single screen)

- [ ] Load a test EPUB and verify library listing, text rendering, and font/page layout.
- [ ] Map ANO directions, center press, and rotary movement into CrossPoint's input handling (standalone demo is not proof this is done).
- [ ] Turn EPUB pages; test return to library, reading position saving and reopening a book.
- [ ] Inspect memory/PSRAM use and performance at 920 × 680.
- [ ] Compare full/partial refresh and ghosting; note any display-driver limits.

**Pass condition:** read a full chapter without a computer connected to the software workflow (USB power is fine during development).

## 4. Only afterward: folding hardware and power

- [ ] Confirm whether a second 5.76-inch panel is the right size/density for the final reader.
- [ ] Test two E Ink panels with shared SPI and independent CS/BUSY/RESET as needed.
- [ ] Design two-page rendering/turning logic and a folding hinge mock-up.
- [ ] Evaluate screen protection, ribbon bend radius, cable strain relief and repairability.
- [ ] Test a stowable reading-light concept versus integrated frontlight feasibility.
- [ ] Measure peak/idle current, then select battery/protection/charging electronics.
- [ ] Build CAD, a case prototype and eventually a custom PCB.

## Measurements to record

- Firmware build size, free flash/PSRAM/RAM; SD card mount time and I/O errors.
- EPUB page layout time; input-to-refresh latency; partial/full refresh and ghosting.
- Power draw during boot, idle, refresh and deep sleep once measurable.
- Folded dimensions, mass and durability once mechanical prototypes exist.

The second screen, battery and final enclosure are **not** part of the current purchase.
