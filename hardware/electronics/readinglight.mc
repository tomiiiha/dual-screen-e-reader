Built-in Reading Light Idea
I want to be able to read at night, but a lot of the E Ink screens I'm interested in don't come with a frontlight.

I'm considering building a small reading lamp into the case instead, similar to the flexible clip-on lights for physical books.
Current Idea
A small gooseneck LED lamp that comes out near the hinge/spine.

Ideally:
- Can illuminate both pages
- Adjustable brightness
- Warm and cool light settings would be nice
- Runs off the same battery as the reader
- Can fold or tuck away when not being used
- Doesn't get in the way when closing the reader
I like the idea of having the mechanism visible through the clear housing.
Electronics
Probably need:
- Small white LEDs
- LED driver/current control circuit
- Diffuser for more even light
- A PWM signal from the ESP32 to adjust brightness
Could use separate warm and cool LEDs, each with its own current control.

The rotary encoder could change brightness while in a lighting mode.
Things I'm Worried About
- One light might not illuminate both screens evenly
- Might cause glare or shadows
- The lamp could be annoying to store when the device is folded
- The light will probably use a lot more battery than the screens during reading
- Flexible wiring needs to survive repeated bending
First Test
Before designing the lamp into the case, I want to make a simple prototype.
1. Cut out two pieces of paper the same size as the screens.
2. Put them next to each other like an open book.
3. Mount a small LED light above the middle.
4. Try different distances and angles.
5. Check brightness, shadows, and glare in a dark room.
If one lamp doesn't work well, I could look at two smaller lights or a folding LED bar instead.

This would be an external light built into the housing, not a true frontlight layer on the E Ink panel.

Status: Just an idea for now. Need to prototype it.