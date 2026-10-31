# Next things to work on

Updated: 2026-10-31

Not a strict schedule. I'd rather get each part working before buying a lot more hardware.

## Completed — initial electronics tests

- [x] Set up ESP32-S3 with PlatformIO and Serial Monitor.
- [x] Test all five ANO navigation buttons and wheel rotation.
- [x] Connect the GDEH0576T81 with the DESPI-C02 adapter.
- [x] Show **Hello World!** on the actual E Ink screen using GxEPD2.
- [x] Save the known-working firmware and wiring details in GitHub.

## Next — figure out how to use existing e-reader firmware

- [ ] Study CrossPoint Reader's board support, display interfaces, and input handling.
- [ ] Check the work needed to connect GxEPD2 (or an equivalent driver) to its display abstraction.
- [ ] Check memory use for the 920 x 680 display and EPUB rendering.
- [ ] Decide how to map the ANO wheel to page turning and menu controls.
- [ ] Choose whether to port CrossPoint or use another open-source firmware base.

**Goal:** a realistic firmware plan that preserves existing EPUB/library functionality.

## After that — reading on one screen

- [ ] Select microSD storage hardware and connect it safely to the ESP32.
- [ ] Load a small test EPUB and render readable pages on the panel.
- [ ] Test page turning through the navigation wheel.
- [ ] Compare full and partial refresh behavior, including ghosting.
- [ ] Measure how much memory the reader uses and basic responsiveness.

**Goal:** actually read a book on one display.

## Later — the dual-screen reader

- [ ] Design the shared SPI wiring, separate chip-select lines, and BUSY/reset control for two screens.
- [ ] Decide how to render two consecutive pages and turn them together.
- [ ] Try a cardboard or simple 3D-printed hinge/mock-up first.
- [ ] Work out cable strain relief, screen backing, and serviceability.
- [ ] Experiment with a stowable reading light.
- [ ] Then work on battery power, charging, a custom PCB, and enclosure materials.

**Goal:** a two-page folding reader built around tested electronics.

## Things to measure eventually

- Full and partial refresh time, including image quality and ghosting
- Input response time
- Current draw while refreshing, reading, and idle
- Battery runtime after adding a power system
- Weight and dimensions of the folding prototype

I don't need a second screen yet. The next major challenge is adapting reading software to the display I already have.
