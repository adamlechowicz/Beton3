//required external libraries
#include <Wire.h> //I2C
#include <U8g2lib.h>
#include <AsyncDelay.h>

//this "tick" will be setup to expire 30 times every second (30FPS)
AsyncDelay tick;

//begins the u8g2 library on the default pins SDA and SCL
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

//types of animation that can be played
enum animation_type{NONE, ACKNOWLEDGE, PLAY, NEXT, PREV, FORWARD, REWIND, UP, DOWN, MUTE, VERSION, SPLASH};

//display refresh rate is 30FPS, 1000 milliseconds in a second
const int FPS = 1000 / 30; //30FPS

//animation_state encodes how many frames into an animation we are
//this gets reset whenever a new animation is started
int animation_state = 0;

//animation encodes the type of the animation we are currently drawing.
//default is NONE, which is a blank display.
enum animation_type animation = NONE;
