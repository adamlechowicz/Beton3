# Béton3 Firmware

This folder holds major versions of the firmware for Béton3.  Firmware is written for Arduino Pro Micro and Pro Micro clones (Arduino Leonardo platform in the Arduino IDE).  

I've made an attempt to document the majority of the code using comments throughout, but if you are using this as a base for a revision and have clarifying questions shoot me an email at alechowicz@umass.edu.

One thing that may help with code readability as well is the simple wiring diagram hosted in a different folder in this repository, at least in terms of understanding which pins connect to which components.

The stock firmware, without modification, hardcodes a basic media control macro pad, with 3 buttons, a rotary encoder, and animations which correspond to the appropriate button press.
- Button 1: Acts as a play/pause button.  Hold down to open the firmware version screen.
- Button 2: Acts as a media next button.  Hold down to fast forward (only works in Windows).
- Button 3: Acts as a media previous button. Hold down to rewind (only works in Windows).
- Rotary Encoder: Clockwise sends media volume up keystrokes, and counter-clockwise sends media volume down keystrokes.  Click acts as a mute keystroke.  Holding the click opens the "about" screen.
