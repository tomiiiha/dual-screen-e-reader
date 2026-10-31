# 007 — Firmware source and recovery checkpoint

**Date:** 2026-10-31  
**Status:** Custom CrossPoint build boots and renders a readable SD-card error on the physical GDEH0576T81. Source, Git history and build artifacts are backed up locally. EPUB reading is **not** yet demonstrated.

## Working milestones

1. The standalone **E Ink test** displayed “Hello World!” on the Good Display GDEH0576T81 (920 × 680) through the DESPI-C02 adapter.
2. The standalone **page-turn test** changed between two hardcoded text pages using both the ANO rotary wheel and Left/Right buttons. This is *not* EPUB rendering or proof that ANO navigation works inside CrossPoint.
3. A custom **CrossPoint Reader** firmware build compiled and flashed to the ESP32-S3. The device showed a readable “SD card error” screen, consistent with the absence of a connected microSD reader. The error does not establish that the eventual storage implementation will work.

The standalone test sources are in `firmware/eink-display-test/` and `firmware/page-turn-test/` in this repository. Preserve the first test as a known-good baseline.

## Git checkpoints

The CrossPoint port is developed separately in `$env:USERPROFILE\crosspoint-reader` on branch `custom-esp32-s3-reader`. Its customized FreeInk SDK is a Git submodule with its own branch and commit.

| Repository | Branch | Local commit | Contents |
| --- | --- | --- | --- |
| CrossPoint | `custom-esp32-s3-reader` | `24fc5045` | `platformio.custom-reader.ini`, `partitions_custom_reader.csv`, board identity, and FreeInk submodule revision |
| FreeInk SDK | `custom-reader-hardware` | `a628f15` | ESP32-S3 custom board profile, GDEH0576 driver and display selection |
| This e-reader repository | `main` | `791bde7` | Standalone tests, page-turn demo, and initial October 31 design documentation |

The e-reader `main` branch was observed matching `origin/main`, with a clean working tree. **The two CrossPoint/SDK commits have not been pushed to GitHub.** In particular, the parent CrossPoint commit references an SDK submodule revision that is currently available only locally and in the SDK history bundle. Publishing the parent commit alone would not make its submodule reproducible for another clone.

## Local recovery backup

The development-machine checkpoint is:

```text
%USERPROFILE%\Documents\crosspoint-checkpoint-2026-10-31\
```

It includes:

- `crosspoint-history.bundle` and `freeink-history.bundle`: refreshed *after* the above commits; both passed `git bundle verify` and reported complete histories.
- `working-tree-final/`: a final file-level snapshot of the CrossPoint working tree, including otherwise untracked source files, excluding `.git`, `.pio`, `.cache` and `node_modules` folders.
- `final-crosspoint-status.txt`, `final-freeink-status.txt`, `final-crosspoint.patch`, `final-freeink.patch`: records of changes remaining outside the commits.
- `firmware-build/`: copied PlatformIO build artifacts listed below.
- `firmware-checksums.txt`: SHA-256 checksums of backed-up `.bin` files.
- `page-turn-test/`: a separate four-file copy of the working demo (`.gitignore`, `platformio.ini`, `README.md`, `src/main.cpp`).
- Earlier snapshot, patches and status records created during the session.

The final file snapshot copy completed without failed files. This directory remains a **local** backup unless copied to independent storage. Git bundles preserve committed history, not uncommitted or ignored files; those are preserved separately in the working-tree snapshot and patch/status records.

## Saved custom firmware build artifacts

The files below were copied from `.pio/build/custom_reader/` into `firmware-build/`:

| Artifact | Size (bytes) |
| --- | ---: |
| `bootloader.bin` | 18,720 |
| `firmware.bin` | 4,877,344 |
| `firmware.factory.bin` | 4,942,880 |
| `partitions.bin` | 3,072 |
| `firmware.elf` | 97,779,216 |
| `firmware.map` | 37,794,656 |

Their existence and copy are verified from the terminal listing. **A byte-for-byte match to the ESP32's currently flashed contents has not been verified.** Flashing instructions and offsets must be checked before restoring these images.

## Rebuilding from the source checkpoint

The custom environment is stored in the tracked `platformio.custom-reader.ini`. CrossPoint's base `platformio.ini` loads `platformio.local.ini` via `extra_configs`; on a restored working tree, copy the tracked custom config to the expected local filename:

```powershell
Copy-Item .\platformio.custom-reader.ini .\platformio.local.ini
& "$env:USERPROFILE\.platformio\penv\Scripts\platformio.exe" run -e custom_reader
```

The custom configuration selects an ESP32-S3 DevKitC-1 profile, `dio_opi`, an 8 MB flash layout, `BOARD_HAS_PSRAM`, `FREEINK_DEVICE_CUSTOM_READER=1`, the custom partition CSV and GxEPD2 `^1.6.9`. These are **build settings**, not independently verified flash/PSRAM hardware specifications. Rebuilding from scratch also depends on resolving the exact framework and library versions that were installed on the development machine.

## Items still requiring attention

- Review three SdFat patch files reported modified (Windows LF/CRLF warnings were observed); do not assume they are necessary source changes without comparing content.
- Review untracked helper/temporary files, including `apply_custom_reader_changes.py`, `preview/`, and two disabled/legacy display driver files inside the FreeInk SDK. Some may only be historical experiments; do not automatically commit everything.
- Verify actual flash size, PSRAM configuration and partition limits against the physical ESP32-S3 module.
- Make the custom FreeInk SDK commit retrievable if publishing a reproducible CrossPoint fork, and review upstream license obligations.
- Record pinned PlatformIO/framework/library versions, build hashes and confirmed flashing procedure.
- Copy the full checkpoint to another device or independent storage.
- Wire and test the planned microSD reader, configure its pins in CrossPoint, and then open a real EPUB. The GPIO17 MISO / GPIO18 SD-CS wiring is only a proposal until tested.
- Integrate ANO input handling into CrossPoint, then evaluate reading experience, refresh behavior, power and eventual dual-display operation.

## Important boundary

This checkpoint preserves the **known working files and observed results**. It is not a transcript of every experiment or chat message, nor proof of a clean-from-scratch rebuild or fully functional e-reader. The full development conversations remain separate from Git history.
