# Reader update - Nov 12, 2026

## What changed

- Wuthering Heights opens from Browse Files. Once opened it shows up in Library. SD card and EPUB reading were working before the refresh changes.
- The custom GDEH0576T81 driver was doing a full refresh every time. Added a fast path using GxEPD2 writeNative with the previous and current frames.
- Keep a 78,200 byte copy of the last frame in PSRAM. First paint, wake from sleep, Half and Full requests still use a full refresh. Fall back to full if the allocation fails.
- Set the display GPIO modes before panel.init to avoid the RST/DC warnings.
- Added initialization and refresh timing logs.
- Proposed UART logging config for COM4: disable USB CDC on boot and remove the USB serial wait. Only one USB connector on this board.

## Still to test

- Last serial output only showed ROM boot messages. The GPIO warnings were not in that output anymore.
- Need to confirm the latest serial config builds and uploads, then check if application logs show on COM4.
- Need to confirm FAST/FULL timings, page turns, contrast and ghosting on the display. Fast refresh is not hardware-verified yet.
- No changes to SD patches, EPUB parsing, buttons, board wiring or SPI speed in this update.

## Applying this update

Copy the two source/config files into the matching paths in the existing crosspoint-reader checkout. This is not a complete repo. Keep the existing driver header. Review the local config before replacing it, especially any inherited build_unflags or changes made since the last session.

Build from PowerShell in the CrossPoint repo:

```powershell
& "$env:USERPROFILE\.platformio\penv\Scripts\platformio.exe" run -e custom_reader
& "$env:USERPROFILE\.platformio\penv\Scripts\platformio.exe" run -e custom_reader -t upload --upload-port COM4
& "$env:USERPROFILE\.platformio\penv\Scripts\platformio.exe" device monitor -p COM4 -b 115200
```

## Git

freeink-sdk is a submodule, so commit and push its driver change first. Then commit the updated submodule pointer in CrossPoint. Check the branch and remote in both repos first. Previous backup branch was custom-reader-working-2026-11-07.

```powershell
git -C freeink-sdk status
git -C freeink-sdk branch --show-current
git -C freeink-sdk remote -v
git -C freeink-sdk add libs/display/FreeInkDisplay/src/driver/Gdeh0576Driver.cpp
git -C freeink-sdk diff --cached
git -C freeink-sdk commit -m "Add fast refresh to custom reader display"
```

Push that commit to the SDK fork/backup branch before continuing. In the parent repo, stage only the submodule pointer and the intended config/notes files, not the unrelated SD patches or untracked files.

```powershell
git status
git remote -v
git add freeink-sdk
git add platformio.local.ini
git add refresh-notes.md
git diff --cached
git commit -m "Update custom reader refresh and serial config"
```

If platformio.local.ini is ignored, only force-add it if you want that local config tracked in GitHub (otherwise keep it local and omit it from the commit). Push the parent commit to the intended branch after checking the diff. The ZIP does not push anything by itself.

GxEPD2 reference: https://github.com/ZinggJM/GxEPD2/blob/master/src/gdeh/GxEPD2_576_GDEH0576T81.cpp
