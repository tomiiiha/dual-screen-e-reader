# Documentation preview / review notes

This folder contains **draft replacements/additions** for the GitHub repository `tomiiiha/dual-screen-e-reader`, based on work through October 31, 2026. It has **not** been committed or pushed.

## Proposed changes

- `README.md` — rewrite the current status to include today's successful custom CrossPoint boot.
- `docs/design-log/005-page-navigation-demo.md` — note standalone ANO page-changing test.
- `docs/design-log/006-crosspoint-first-boot.md` — document custom firmware port, build, success and outstanding source preservation.
- `docs/hardware-wiring.md` — single page of verified GPIOs versus planned SD GPIOs.
- `electronics/components.md` — received parts, current two-item storage purchase plan, and deferred purchases.
- `docs/next-steps.md` — begin with preserving the local CrossPoint changes and connecting SD.

## Accuracy reminders

- The GitHub repository has the GxEPD2 test source, but the live modified CrossPoint working tree was not accessible through GitHub. The documentation records observed milestones, not a verified code diff.
- The SD breakout/card are treated as **being ordered**, not arrived or tested. Confirm card capacity/model and the final purchase before changing to `ordered`.
- The E Ink display plus ANO page-changing sketch was reported working, but its source was not found in the current repository.
- CrossPoint shows an SD card error because the SD reader has not been connected. Actual EPUB reading is still pending.
- Before uploading the CrossPoint changes, check upstream license/attribution and submodule status; keep its working test code and docs separate from the basic GxEPD2 example.
