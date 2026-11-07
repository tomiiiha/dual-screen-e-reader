# Next steps

**Updated November 7, 2026**

The standalone SD test works, and the SD card and E Ink display can work together. I'm done troubleshooting basic SD reading for now.

## Before changing CrossPoint

- [ ] Move the ANO rotary wires off GPIO9 and GPIO10, which the SD card now uses. Check the reported overlap at GPIO11 too.
- [ ] Repeat the controls test with the updated pin assignments.
- [ ] Run a quick test with SD, display, and ANO connected together. Make sure reading a file still works while using the controls.
- [ ] Keep copies of the standalone working tests so I can go back to them if something breaks.

## Get CrossPoint reading the card

- [ ] Open the local CrossPoint `custom_reader` PlatformIO environment and check the SD driver/board pin configuration.
- [ ] Set up storage for the actual tested wiring: SD CS=9, MISO=10, MOSI=11, SCK=12. DET=17 if needed.
- [ ] Check how CrossPoint and its FreeInk SDK use SPI, and make sure the display CS=13 is handled separately.
- [ ] Build and flash, then check that CrossPoint mounts the SD card without breaking the display.
- [ ] Put a small EPUB on the card and see whether it appears in the library.

## Make it useful as a reader

- [ ] Open an EPUB and get readable text on the screen.
- [ ] Map ANO directions and center/select into the actual CrossPoint interface.
- [ ] Map page turns and, if useful, the rotary encoder.
- [ ] Check that book position is saved and restored.
- [ ] Check refresh behavior, ghosting, and memory use.

## Later

- [ ] Figure out a dedicated sleep/wake and power switch setup.
- [ ] Test battery power and measure current draw.
- [ ] Decide whether to keep this panel size or change it for the two-page design.
- [ ] Work out the second display, hinge, clear case, and lighting.

The immediate goal is still **one usable single-screen reader**. I don't need to start the enclosure or dual-screen work before that.
