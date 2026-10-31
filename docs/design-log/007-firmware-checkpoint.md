# 007 — Backing up the CrossPoint firmware

**October 31, 2026**

Today I finished getting a modified version of CrossPoint Reader running on my ESP32-S3. The firmware compiled and uploaded successfully, and the E Ink display showed a readable "SD card error" message.

The error makes sense because I haven't connected a microSD reader yet. It does confirm that CrossPoint is running and can display something on the GDEH0576T81.

Earlier today, I also got the ANO navigation wheel working with the display. I made a small program with two pages of sample text and could switch between them using the wheel or the left/right buttons. That program is separate from CrossPoint, so the controls still need to be integrated into the actual reader firmware.

## Saving the code

Before making any more changes, I wanted to make sure I could get back to this working version.

I saved two local Git commits:

- **CrossPoint — `24fc5045`:** Contains my custom PlatformIO configuration, partition layout, board identification, and the updated FreeInk SDK reference.
- **FreeInk SDK — `a628f15`:** Contains the ESP32-S3 board configuration and the driver for my GDEH0576T81 display.

These commits are on the `custom-esp32-s3-reader` and `custom-reader-hardware` branches, respectively.

Neither commit has been uploaded to GitHub yet. They're saved locally and included in the backups.

My separate `dual-screen-e-reader` GitHub repository already contains the original Hello World display test and the working two-page navigation test. The last verified commit there was `791bde7`.

## Backups

I created a backup folder at:

`C:\Users\tomih\Documents\crosspoint-checkpoint-2026-10-31`

It contains copies of the CrossPoint source files, the remaining uncommitted changes, and the Git histories for both CrossPoint and FreeInk SDK.

The two history files are:

- `crosspoint-history.bundle`
- `freeink-history.bundle`

Both passed Git's bundle verification.

I also saved the compiled firmware from `.pio/build/custom_reader/`. The backup includes `firmware.bin`, `firmware.factory.bin`, the bootloader, partition table, and the `.elf` and `.map` debugging files. I saved SHA-256 checksums for the binary files as well.

The firmware itself is backed up, although I haven't compared it directly against what's currently flashed on the ESP32.

I also made a separate backup of the ANO page-turning program.

## Rebuilding later

The CrossPoint project is located at:

`C:\Users\tomih\crosspoint-reader`

The custom PlatformIO settings are saved as `platformio.custom-reader.ini`. To restore the build configuration, that file can be copied to `platformio.local.ini`.

The build command is:

`platformio run -e custom_reader`

The configuration currently uses an 8 MB flash layout, `dio_opi` memory settings, and GxEPD2 for the display. I still need to confirm the actual flash and PSRAM specifications of my development board.

A completely fresh rebuild from the backups hasn't been tested yet.

## Things to check later

There are a few files I didn't include in the Git commits, including some SdFat patch changes, an earlier display driver, and a Python script used while modifying CrossPoint. These are still in the source backup. I'll review them before deciding whether any need to be committed.

I also need to copy the checkpoint folder to another drive so I don't lose everything if something happens to my computer.

If I eventually upload the modified CrossPoint firmware to GitHub, I'll need to make the custom FreeInk SDK version available too. Otherwise, cloning the repository wouldn't retrieve all the code.

## Next steps

The next goal is to get a real book running in CrossPoint.

I'm planning to connect an Adafruit #4682 microSD breakout to the ESP32-S3. The proposed connections use GPIO11 and GPIO12 for the shared SPI bus, GPIO17 for MISO, and GPIO18 for the SD card's chip select. Those connections haven't been tested yet.

Once the card works, I can try loading an EPUB and see whether CrossPoint can display it properly. After that I'll work on getting the ANO wheel and buttons to control the reader.

For now, I have a working single-screen hardware demonstration, a CrossPoint build that boots, and copies of the code and firmware in case I need to start over.