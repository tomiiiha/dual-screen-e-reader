# Dual-Screen E-Reader

A custom folding, dual screen e-paper reader designed around comfortable two page reading, portability, ability to be repaired easily, and simple physical controls.

## Project Status

**Early electronics testing**

Ordered the first parts on October 21. On October 30, I got the ESP32-S3 running in PlatformIO and tested the ANO navigation wheel: five buttons and both rotation directions work. The E Ink display has not been tested yet.

See `docs/design-log/003-esp32-controls-tested.md` for what I did, `firmware/esp32-tests/` for the test code, and `docs/next-steps.md` for what comes next.

## Design Goals

- Two e-paper displays arranged like the pages of a book
- Folding design that protects the displays when closed
- Portable enough for carrying in a bag or pocket
- Some kind of adjustable light for reading at night (integrated frontlight or possibly a little built-in gooseneck lamp)
- Physical buttons for page navigation / control selection
- No touchscreen unless a strong design reason emerges later
- Clear or translucent enclosure where practical so the electronics remain visible (important for personal aesthetics. However, this may end up being a fool's errand)
- Local storage for a substantial book library
- Simple design, this is meant for reading not for anything else
- Serviceable and reasonably reproducible hardware (for me to fix, or anyone to reproduce this project)

## Current Concept

The reader will use two e-paper displays connected through a folding central structure. Physical controls will handle page turning and navigation, avoiding the additional hardware and software complexity of a touchscreen.

The enclosure is intended to be custom designed and 3D printed (for ease of cost and availability), with transparent or translucent materials being explored.

The electronics, mechanical design, firmware, and design decisions will be documented in this repository as the project develops.

## Repository Structure

The repository will eventually contain:

- Electronics design and schematics
- Mechanical CAD and enclosure revisions
- Firmware/software and early hardware test code
- Bill of materials
- Prototypes and test results
- Design notes and engineering decisions
- Build documentation

## Design Log

Major design decisions and prototype revisions will be recorded in the `docs/` directory.

## License

Licensing has not yet been selected. Hardware, software, and documentation licensing will be determined as the project develops.
