# 006 — CrossPoint Reader custom board port and first boot

**Date:** 2026-10-31  
**Status:** **Build and flash successful; readable native-resolution “SD card error” screen.** No SD card or EPUB test yet.

## Why this was attempted

Writing an EPUB parser, library, and reading UI from scratch would be a large detour from the hardware project. The experiment was to adapt the existing open-source CrossPoint Reader/FreeInk stack to a custom ESP32-S3, the 920 × 680 GDEH0576T81, and eventually the ANO physical controls.

## Starting hardware and known-good test

The panel and DESPI-C02 were already working with the GxEPD2 `GxEPD2_576_GDEH0576T81` driver. The standalone test displayed Hello World and a rectangle. Its confirmed SPI connections were MOSI=GPIO11, SCK=GPIO12, CS=GPIO13, D/C=GPIO14, RESET=GPIO15, BUSY=GPIO16; 3.3 V power and common ground. ANO control inputs occupied GPIO4–GPIO10. See [hardware wiring](../hardware-wiring.md).

## Work performed

1. Cloned/opened CrossPoint Reader locally and initialized its SDK/submodule dependencies.
2. Built a reference `x4pro` environment to establish the PlatformIO/FreeInk toolchain. Dependency/build compatibility required troubleshooting (including SdFat/PlatformIO issues); a reference build was eventually successful. **That target is not the final hardware profile.**
3. Added a `custom_reader` environment/profile for the ESP32-S3 and a custom board/device definition (`FREEINK_DEVICE_CUSTOM_READER`). The port targeted 920 × 680 pixels and mapped the GDEH0576T81 SPI pins.
4. Made changes in the board configuration and FreeInk display abstraction, including a GDEH0576 display driver. A compilation/link attempt exposed *multiple-definition* errors: both `Gdeh057Driver.cpp` and `Gdeh0576Driver.cpp` defined the same `freeink::Gdeh0576Driver` methods/functions. This duplicate-definition issue was resolved sufficiently for the subsequent build to link.
5. Rebuilt the custom target, uploaded it successfully to the ESP32-S3, and confirmed a readable “SD card error” message on the physical 920 × 680 panel.

This first boot demonstrates that the application firmware is running and that the custom display port renders real application output. It **does not** verify SD integration, EPUB parsing, successful reading, ANO mapping inside CrossPoint, deep sleep, or dual-screen support.

## Known target configuration

| Setting | Value / evidence |
| --- | --- |
| PlatformIO environment | `custom_reader` |
| Board profile in observed build | `esp32-s3-devkitc-1` |
| Framework | Arduino through PlatformIO / pioarduino Espressif32 |
| Custom device definition | `FREEINK_DEVICE_CUSTOM_READER` |
| MCU family | ESP32-S3 |
| Custom display | GDEH0576T81, 920 × 680 monochrome E Ink |
| SPI clock | 4 MHz initial custom-port setting; not benchmarked |
| Display pin mapping | MOSI 11, SCK 12, CS 13, D/C 14, RESET 15, BUSY 16 |
| Input plan | Center 4, down 5, right 6, up 7, left 8, encoder A 9/B 10 |
| Other reported build flags | `BOARD_HAS_PSRAM`, `dio_opi` (must be verified against the saved `platformio.local.ini`) |
| Built binary size | 4,877,344 bytes (approximately 4.65 MiB) |
| Flash/partition | Reported use of an 8 MB application partition; verify final partition file and actual module flash specification |
| Development PC port | `COM4` during initial tests; port may change |
| Storage | **Not physically connected** |

The custom profile and modifications were performed in the separate local CrossPoint working tree. Exact versions, build flags, pin definitions and final source contents still need to be exported from that local tree. Do not infer a fully reproducible patch from this log alone.

## Files reported as modified or added

- `platformio.local.ini` — local build environment and configuration.
- `freeink-sdk/libs/hardware/BoardConfig/...` (`BoardConfig.h`) — custom device selection, MCU family and pin/board definitions.
- `freeink-sdk/libs/display/FreeInkDisplay/...` (`FreeInkDisplay.cpp`) — panel integration.
- `freeink-sdk/libs/display/FreeInkDisplay/src/driver/Gdeh0576Driver.h` and `.cpp` (or related `Gdeh057Driver.cpp`) — custom panel driver.

**Important:** These names are a work inventory, not a verified complete patch list. Capture `git status`, `git diff`, untracked files, the parent repository commit and submodule commit(s) before continuing. Do not copy the entire upstream repository into this hardware repository without deciding how the dependency should be managed.

## Commands used / useful for reproducing

Run in the local CrossPoint Reader project directory with the proper submodules/dependencies installed:

```powershell
& "$env:USERPROFILE\.platformio\penv\Scripts\platformio.exe" run -e custom_reader
& "$env:USERPROFILE\.platformio\penv\Scripts\platformio.exe" run -e custom_reader -t upload
& "$env:USERPROFILE\.platformio\penv\Scripts\platformio.exe" device monitor -p COM4 -b 115200
```

Observed final build result:

```text
Environment    Status    Duration
custom_reader  SUCCESS   00:04:18.596
```

The controller hard-reset through RTS after uploading. The display then showed the legible SD card error, which is the key hardware-level observation rather than merely trusting a build success message.

## Issues and fixes noted during development

| Issue | Outcome |
| --- | --- |
| Initial platform/package/library build compatibility | Worked through while getting reference CrossPoint target to build; specific final patches must be preserved. |
| Duplicate `Gdeh0576Driver` linker symbols from two driver source files | Corrected before successful custom build; exact resolution must be captured in a source diff. |
| Wrong/unknown upload or serial port in earlier ESP32 experiments | Set working COM port and used PlatformIO upload/monitor. |
| On-device **“SD card error”** | Expected: there is no microSD reader connected yet. Not enough evidence to call this a software defect. |

## Known working / not yet working

- [x] Original GxEPD2 standalone display test.
- [x] Separate ANO-controlled E Ink page demo.
- [x] Custom CrossPoint target compiles and links.
- [x] Firmware uploads and produces readable application output on the panel.
- [ ] Working microSD hardware and card initialization.
- [ ] Actual EPUB loaded, rendered, and page-turned in CrossPoint.
- [ ] ANO controls hooked into CrossPoint's input system.
- [ ] Verified PSRAM use and memory headroom under reading workload.
- [ ] Deep sleep / resume / battery life measurements.
- [ ] Multiple simultaneous panels.
- [ ] Source patch or fork committed to version control.

## Immediate next task

Connect and validate an Adafruit #4682 microSD breakout and a FAT32 microSD card. Proposed shared SPI wiring: SCK GPIO12, MOSI GPIO11, MISO GPIO17 (new), SD CS GPIO18 (new), and 3.3 V/GND. **This is a plan, not verified wiring**; check the exact breakout pin labels and the final CrossPoint SD configuration before powering it.

Once storage initializes, load a small legally obtained or public-domain EPUB and test the library and page turning. Preserve the working boot firmware as a checkpoint before editing the storage stack.
