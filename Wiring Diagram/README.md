# Béton3
# Wiring Diagram

Files:
- **Wiring Diagram.pdf** - A pretty basic PDF outline of the wiring for Béton3.

This wiring diagram is intended as a quick reference guide to the wiring setup I used for Béton3.  This diagram should work verbatim for all Arduino Pro Micros, Pro Micro clones, and Pro Micro pin-compatible boards.  Boards that are a similar form factor but not pin-compatible may require some shuffling around on your end.

- **Rotary Encoder**
  - GND to GND on Pro Micro
  - **+** to RAW (6-12V) on Pro Micro
  - SW to A2 on Pro Micro
  - DT to A1 on Pro Micro
  - CLK to A0 on Pro Micro

- **OLED Display**
  - GND to GND on Pro Micro
  - VCC to VCC on Pro Micro
  - SDA to SDA (pin 2) on Pro Micro
  - SCL/SCK to SCL (pin 3) on Pro Micro
  
- **Switch #1**
  - One pin to GND on Pro Micro
  - Other pin to PIN 7 on Pro Micro
  
- **Switch #2**
  - One pin to GND on Pro Micro
  - Other pin to PIN 8 on Pro Micro

- **Switch #3**
  - One pin to GND on Pro Micro
  - Other pin to PIN 9 on Pro Micro

For more information on wiring up Béton3, consult the [Build Guide.](https://github.com/adamlechowicz/Beton3/tree/master/Build%20Guide)
