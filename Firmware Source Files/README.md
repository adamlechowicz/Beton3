# Béton3 Firmware

This folder holds major versions of the firmware for Béton3.  Firmware is written for Arduino Pro Micro and Pro Micro clones (Arduino Leonardo platform in the Arduino IDE).

I recorded a quick and dirty video of the stock firmware's interface at https://www.youtube.com/watch?v=9jtD4WeTKok

The following open source libraries are dependencies for the firmware:
- [AsyncDelay](https://www.arduinolibraries.info/libraries/async-delay)
- [HID-Project](https://www.arduinolibraries.info/libraries/hid-project)
- [TimerOne](https://www.arduinolibraries.info/libraries/timer-one)
- [U8g2](https://www.arduinolibraries.info/libraries/u8g2)
- [ClickEncoder](https://github.com/0xPIT/encoder)

I've made an attempt to document the majority of the code using comments throughout, but if you are using this as a base for a revision and have clarifying questions shoot me an email at alechowicz@umass.edu.

One thing that may help with code readability as well is the simple wiring diagram hosted in a different folder in this repository, at least in terms of understanding which pins connect to which components.

The stock firmware, without modification, hardcodes a basic media control macro pad, with 3 buttons, a rotary encoder, and animations which correspond to the appropriate button press.
- Button 1: Acts as a play/pause button.  Hold down to open the firmware version screen.
- Button 2: Acts as a media next button.  Hold down to fast forward (only works in Windows).
- Button 3: Acts as a media previous button. Hold down to rewind (only works in Windows).
- Rotary Encoder: Clockwise sends media volume up keystrokes, and counter-clockwise sends media volume down keystrokes.  Click acts as a mute keystroke.  Holding the click opens the "about" screen.
