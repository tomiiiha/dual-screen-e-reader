# Dual-Screen E-Reader

A custom, foldable, two-page e-paper reader focused on comfortable reading, repairability, and physical controls. The design is being developed incrementally: first a working single-screen reader, then the folding dual-screen hardware.

**Project status — October 31, 2026: custom reader firmware boots on one screen.**

The Waveshare ESP32-S3 is communicating with the Good Display GDEH0576T81 (5.76 in, 920 × 680) through a DESPI-C02 adapter. An initial GxEPD2 example rendered **Hello World!** on the real panel. A separate page-navigation demonstration was successfully controlled using the Adafruit ANO wheel/buttons. Later the same day, a custom build of **CrossPoint Reader** was compiled, uploaded, and displayed a readable **“SD card error”** screen at the panel's native resolution. That error is expected at this stage because no microSD reader is connected yet; it is **not** evidence that books or the full reader UI work.

The first storage purchase is limited to an Adafruit #4682 microSD breakout and a microSD card (purchase/receipt not yet verified in this repository). A battery, second screen, final PCB, hinge, and lighting have **not** been ordered as part of this purchase round.

## Design goals

- Two monochrome E Ink screens, laid out like facing book pages, in a protective folding enclosure.
- Comfortable one-handed use and portable weight/size.
- Physical navigation and page-turn controls; no touchscreen planned.
- Local, owner-controlled book storage and software, rather than a locked-down commercial ecosystem.
- Night reading capability; built-in frontlighting is desirable, but a stowable gooseneck light remains an option.
- Clear or translucent, serviceable case where practical.
- A working single-screen reading experience **before** investing in dual displays, batteries, or custom PCBs.

The 5.76-inch, approximately 198-PPI display is a development choice, **not** a final decision on the two-page display size.

## Progress

| Date | Milestone | Result |
| --- | --- | --- |
| Oct 21, 2026 | First development hardware ordered | ESP32-S3, ANO controls, GDEH0576T81 panel |
| Oct 30, 2026 | Microcontroller and controls | PlatformIO build/upload, serial monitor, all five ANO buttons and both rotation directions |
| Oct 31, 2026 | E Ink bring-up | Visible Hello World text and border via GxEPD2; full refresh |
| Oct 31, 2026 | Combined demo | Buttons and rotary wheel controlled page changes in test firmware |
| Oct 31, 2026 | CrossPoint port | Custom firmware compiled, flashed, and rendered readable native-resolution “SD card error” |
| Next | Storage and first actual book | MicroSD interface and EPUB rendering **not yet tested** |

## Documentation

- [005 — Page navigation demo](docs/design-log/005-page-navigation-demo.md)
- [006 — CrossPoint custom firmware first boot](docs/design-log/006-crosspoint-first-boot.md)
- [Hardware wiring and pin allocation](docs/hardware-wiring.md)
- [Current components and purchase scope](electronics/components.md)
- [Next steps](docs/next-steps.md)

Earlier milestones remain in [`docs/design-log/003-esp32-controls-tested.md`](docs/design-log/003-esp32-controls-tested.md) and [`docs/design-log/004-first-eink-refresh.md`](docs/design-log/004-first-eink-refresh.md).

## Code status and reproducibility

The GitHub repository currently has the known-working early PlatformIO E Ink test in [`firmware/eink-display-test/`](firmware/eink-display-test/). **The modified CrossPoint Reader working tree has not been verified as committed to this repository.** It must be backed up separately, including changes in the `freeink-sdk` submodule, before claiming the new firmware can be rebuilt from this repo alone. See the [first-boot log](docs/design-log/006-crosspoint-first-boot.md) for known filenames, settings, and reproduction gaps.

## License

No license selected yet for the custom project's materials. CrossPoint Reader and its dependencies retain their respective upstream licensing; importing their code requires checking and preserving those notices.
