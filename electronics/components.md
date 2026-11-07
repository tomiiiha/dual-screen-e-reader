# Parts on hand

**Updated November 7, 2026**

| Part | Current status |
| --- | --- |
| ESP32-S3 development board | Working with PlatformIO and USB serial |
| Good Display GDEH0576T81 (5.76 in, 920 x 680) | Tested with GxEPD2 and with the custom CrossPoint build |
| DESPI-C02 display adapter | Working with the display at 3.3 V |
| Adafruit ANO rotary navigation control | All five switches and rotary movement worked in earlier standalone tests; pin mapping needs to change now that SD is attached |
| Adafruit microSD SPI/SDIO breakout | Received, headers soldered, tested |
| 128 GB microSD card | Reformatted from exFAT to FAT32; tested with the ESP32-S3 |
| Breadboard, jumpers, USB cable | In use for the bench prototype |

## What I tested with the new parts

On November 7 I got the SD breakout to initialize, write a text file, and read it back. The card identifies as 116 GiB in the serial output, which is normal for a card sold as 128 GB. I then connected the display to the same SPI bus and displayed the first line of a file stored on the card.

The first SD tests failed with `f_mount failed (3)`. Reformatted the card to FAT32, checked the DET pin, disconnected the display during troubleshooting, and lowered the SD clock to 1 MHz. The simpler test passed, then the combined display test passed too.

## Not bought or built yet

- Second E Ink screen and its interface hardware
- Battery, charger, protection, and power switching
- Final PCB and connectors
- Hinge, case, and screen protection
- Built-in or separate reading light

I'm not buying more parts just to solve a software issue. First I need the existing parts working together, then I can build an actual reading interface.
