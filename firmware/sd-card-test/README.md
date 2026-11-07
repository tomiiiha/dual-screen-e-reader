# SD card read/write test

The standalone SD test I used before reconnecting the E Ink display. It checks the card-detect pin, initializes an SD card at 1 MHz SPI, appends a line to `/test.txt`, and reads the file back over serial at 115200 baud.

Wiring: 3V3 to 3V, GND to GND, GPIO9 to CS (D3), GPIO10 to MISO (D0/SO), GPIO11 to MOSI (CMD/SI), GPIO12 to CLK, and GPIO17 to DET. D1 and DAT2 aren't used.

The card needs to be FAT32. `FILE_WRITE` appends, so each test run can add another line to an existing `test.txt`.

This project does not initialize the E Ink display and does not test the ANO controls.
