#include <Wire.h> //I2C
#include <U8g2lib.h>
#include <AsyncDelay.h>

AsyncDelay tick;
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
const int FPS = 1000 / 60; //30FPS
int animation_state = 0;
int animation = 0;
