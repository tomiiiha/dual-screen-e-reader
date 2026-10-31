# Electronics / parts inventory

**Updated:** 2026-10-31  
**Rule for this round:** Only the microSD breakout and microSD card are being selected/ordered now.

## Received and tested

| Item | Qty | Status / evidence |
| --- | ---: | --- |
| Waveshare ESP32-S3 development board | 1 | Runs PlatformIO test code and the flashed CrossPoint `custom_reader` build |
| Adafruit ANO rotary navigation encoder breakout, #6311 | 1 | Five switches and both encoder directions verified, Oct 30; page-changing demo worked Oct 31 |
| Good Display GDEH0576T81 5.76-inch E Ink, 920 × 680 | 1 | GxEPD2 Hello World + visible CrossPoint native-resolution SD error screen, Oct 31 |
| Good Display DESPI-C02 display adapter | 1 | Arrived with panel; SPI and 3.3 V operation verified |
| Breadboard, jumper wires, USB cable | Existing | Temporary bench setup; no battery yet |

## Only items in current purchase plan

| Item | Qty | Status | Notes |
| --- | ---: | --- | --- |
| [Adafruit microSD SPI/SDIO breakout, #4682](https://www.adafruit.com/product/4682) | 1 | **Ordering / not yet received** | User comfortable soldering header pins. Proposed SPI pinout documented in `docs/hardware-wiring.md`. |
| microSD card | 1 | **Ordering / not yet received** | Plan: 16–32 GB, FAT32 if compatible with selected card and firmware. Exact purchased model/capacity to be recorded from receipt. |

**Status language:** the user indicated these are the only items being ordered right now. No completed transaction or delivery is assumed from the conversation alone.

## Deferred — not ordered in this round

- Second E Ink panel and interface hardware (wait until actual reading works on one panel).
- Battery cell/pack, protection, charger, fuel gauge, and power switching.
- Final microcontroller board or custom PCB.
- Hinge, case material, transparent enclosure, fasteners and cable strain relief.
- Integrated frontlight/gooseneck reading light.
- Additional headers, jumpers, wire, connectors, capacitors or tools **unless found necessary during the next verified test**.

## Next purchase validation

After arrival, photograph/record model numbers and card capacity, check breakout voltage/pin labeling, solder header as needed, and verify FAT32 card initialization and a read/write operation using the ESP32 before diagnosing application-level EPUB issues. Record actual cost, retailer, and date only when known.
