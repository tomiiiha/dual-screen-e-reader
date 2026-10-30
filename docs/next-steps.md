# Next things to work on

Written: 2026-10-30

Not a strict schedule. I'd rather get each part working before buying a lot more hardware.

## Next week — first E Ink test

- Wait for the GDEH0576T81 display and adapter board.
- Check the adapter model, pin labels, supply voltage, and cable orientation before powering anything.
- Find a working driver/example for this exact display (possibly GxEPD2 or Good Display's examples).
- Display an image and some text, then try a full and partial refresh.
- Write down what wiring worked, any errors, and roughly how long refreshes take.

**Goal:** one page of text on an actual E Ink screen.

## After that — firmware

- Look through CrossPoint Reader and its supported board/display interfaces.
- Figure out whether adapting its display driver to this screen is reasonable.
- Keep the book library and EPUB parsing from existing open-source firmware if possible.
- Check how much RAM the renderer needs and whether the ESP32-S3 setup is enough.

**Goal:** choose a realistic software base rather than writing my own EPUB reader.

## Once a single page works — storage and controls

- Decide on microSD hardware and how books will be transferred.
- Map the ANO wheel buttons to the firmware's existing input system.
- Test a small EPUB and page turning on one screen.
- Measure basic refresh and input responsiveness.

**Goal:** read a sample EPUB from local storage on one screen.

## Later — the actual two-page reader

- Decide how to handle two displays on shared SPI, including chip selects and busy/reset pins.
- Work out how consecutive pages will be rendered and refreshed.
- Test the hinge with a cheap cardboard or 3D-printed mock-up before designing a final one.
- Think about screen backing, cable clearance, and making the case serviceable.
- Experiment with a small gooseneck book light before making a custom lighting circuit.
- Only then get serious about the custom PCB, battery, and charging circuit.

**Goal:** an actual design direction supported by working hardware tests.

## Things I want to measure eventually

- Full and partial refresh time
- Input response time
- Current draw while reading and while idle
- Battery runtime once the power system is built
- Total weight and dimensions of a folding prototype

I don't need to buy a second screen immediately. The next decision depends on whether the first display and open-source firmware work together.
