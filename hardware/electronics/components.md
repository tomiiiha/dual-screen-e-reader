Possible Electronics
Just keeping track of parts I'm looking at for the e-reader. Nothing here is final, and I still need to check compatibility before buying things.
Microcontroller
    Waveshare ESP32-S3 Dev Kit N8R8

    https://www.waveshare.com/esp32-s3-dev-kit-n8r8.htm
    - ESP32-S3, 8 MB flash, 8 MB PSRAM
    - Starting point for testing the screens and controls
    - Eventually I'd like to design my own PCB rather than leave a dev board inside the reader
    Need to check how many GPIO pins will be available after connecting both displays, storage, and controls.

Displays (need 2)
    Option 1: Good Display 5.76"

        https://www.good-display.com/product/702.html
        - 920 × 680, 198 PPI
        - SPI interface
        - Smaller, probably easier to make portable
    
    Option 2: DisplayModule 7.0"

        https://www.displaymodule.com/products/7-0-inch-epaper-display-1680x1264-dmaye07001nna
        - 1680 × 1264, 300 PPI
        - $69 each when checked
        - Currently my favorite for size and resolution
        - Bare display, so I still need to figure out the driver hardware
        - No confirmed built-in frontlight

    Option 3: Waveshare 7.5" V2

        https://www.waveshare.com/7.5inch-e-paper-hat.htm
        - 800 × 480
        - Driver HAT available
        - Easier to experiment with, but much lower resolution than the 7" DisplayModule
        Need to figure out the full cost of two screens, driver boards, and any other parts they require.

Controls
    Adafruit ANO Rotary Navigation Encoder (6311)

    https://www.adafruit.com/product/6311
    - $10.95 when checked
    - Rotary encoder plus up/down/left/right and center buttons
    - Uses 7 GPIO inputs
    - Could use the wheel for menu navigation and adjusting brightness
    Might still want separate page-turn buttons along the outside edges.

    Alternative: Adafruit 6310 I2C version if GPIO pins become a problem.

Power
    Options I'm considering:
    - USB power for early testing
    - 3 AA batteries with suitable voltage regulation
    - Rechargeable LiPo battery with USB-C charger and battery protection
    LiPo seems like the most useful option for the finished reader.

Storage
    - microSD card for local books
    - EPUB support through existing open-source firmware
    Still need to choose the card socket/module and check firmware support.

Lighting
    Currently considering a small built-in, deployable LED reading light rather than a light layer on the displays.

    More notes in reading-light.md.
    Before Buying Anything
    - [ ] Check 7" display driver compatibility with the ESP32-S3
    - [ ] Compare actual display dimensions and weight
    - [ ] Work out the GPIO requirements
    - [ ] Choose a battery and charging circuit
    - [ ] Test the lighting idea
    - [ ] Estimate total cost for two displays