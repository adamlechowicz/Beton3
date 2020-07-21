//A bunch of definitions for the width of each graphical element
#define mountain_width 128
#define mountain_height 16
#define text_width 128
#define text_height 16
#define splash_width 88
#define splash_height 18

//XBM format, first section of text
static const unsigned char text1[] U8X8_PROGMEM = {
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x1f,0x08,0x06,0x00,0xc0,0x0f,0x00,0x02,0x00,0x40,0x00,
 0x01,0x00,0x00,0x02,0x00,0x33,0x00,0x06,0x00,0x00,0x06,0x00,0x02,0x00,0x40,
 0x00,0x01,0x00,0x00,0x02,0x00,0x33,0x1e,0x8f,0xc7,0x07,0x03,0x00,0x1e,0x11,
 0xa0,0xe0,0x71,0x34,0x03,0x02,0x0e,0x33,0x33,0xc6,0xcc,0x8c,0x07,0x00,0x22,
 0x11,0xa0,0x10,0x89,0xcc,0x04,0x02,0x91,0x1f,0x33,0xc6,0xcc,0x0c,0x0c,0x1f,
 0x22,0x11,0x10,0x11,0xf1,0x44,0x04,0x02,0x91,0x33,0x3f,0xc6,0xcc,0x0c,0x0c,
 0x00,0x22,0x11,0x10,0x11,0x89,0x44,0x04,0x02,0x9f,0x33,0x03,0xc6,0xcc,0x0c,
 0x0c,0x00,0x22,0x11,0xf8,0x13,0x89,0x44,0x04,0x02,0x81,0x33,0x23,0xc6,0xcc,
 0x4c,0x0c,0x00,0x22,0x11,0x08,0x12,0x89,0x44,0x04,0x02,0x91,0x1f,0x1e,0x8c,
 0xc7,0x8c,0x07,0x00,0x1e,0x1e,0x08,0xe2,0xf1,0x44,0x04,0x3e,0x0e,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x11,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00 };

//XBM format, second section of text
static const unsigned char text2[] U8X8_PROGMEM = {
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x01,0x00,0x00,0x20,0x08,0x00,0x02,
 0x00,0x01,0x80,0x80,0x00,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x0c,0x00,
 0x02,0x00,0x00,0x80,0x80,0x00,0x47,0xc3,0x11,0x91,0xe1,0xf8,0x00,0xa0,0x8a,
 0xc3,0xe3,0x80,0xd1,0x80,0x88,0x38,0xc8,0x24,0x12,0x11,0x11,0x81,0x00,0x20,
 0x49,0x24,0x12,0x01,0x31,0x01,0x49,0x44,0x40,0x24,0xa2,0x0a,0x11,0x40,0xf0,
 0x21,0x88,0x27,0x12,0x01,0x11,0x01,0x55,0x44,0x40,0x24,0xa2,0x0a,0x11,0x20,
 0x00,0x20,0x48,0x24,0xf2,0x01,0x11,0x01,0x55,0x7c,0x40,0x24,0x42,0x04,0x11,
 0x10,0x00,0x20,0x48,0x24,0x12,0x00,0x11,0x01,0x22,0x04,0x48,0x24,0x42,0x04,
 0x11,0x09,0x00,0x20,0x48,0x24,0x12,0x01,0x11,0x01,0x22,0x44,0x47,0xc4,0x41,
 0x04,0xe1,0xf8,0x00,0x20,0x88,0xc7,0xe3,0x00,0x11,0x01,0x22,0x38,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00 };

//XBM format, third section of text
static const unsigned char text3[] U8X8_PROGMEM = {
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x40,0x10,0x00,0x00,0x00,0x00,0x04,
 0x00,0x00,0x80,0x20,0x00,0x00,0x02,0x00,0x00,0xc0,0x18,0x00,0x00,0x00,0x00,
 0x04,0x00,0x00,0x80,0x20,0x00,0x1c,0x87,0xa3,0x6b,0x40,0x15,0x87,0xc3,0xe1,
 0x70,0x34,0x22,0x0e,0xc7,0x71,0x38,0x22,0x42,0x64,0x98,0x40,0x92,0x48,0x24,
 0x12,0x89,0x4c,0x22,0x91,0x88,0x20,0x44,0x02,0x42,0x24,0x88,0x40,0x10,0x4f,
 0x20,0xe0,0x09,0x44,0x22,0x81,0x88,0x20,0x04,0x1c,0xc2,0x27,0x88,0x40,0x90,
 0x88,0xc3,0x11,0x09,0x44,0x22,0x8e,0x8f,0x20,0x38,0x20,0x42,0x20,0x88,0x40,
 0x90,0x08,0x04,0x12,0x09,0x44,0x22,0x90,0x80,0x20,0x40,0x22,0x42,0x24,0x88,
 0x40,0x90,0x48,0x24,0x12,0x89,0x44,0x32,0x91,0x88,0x20,0x44,0x1c,0x8c,0x23,
 0x88,0x40,0x10,0x8f,0xc3,0xe1,0x71,0x44,0x2c,0x0e,0x07,0xc3,0x38,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00 };

//XBM format, a crappy outline of the Holyoke Range in Western Massachusetts
static const unsigned char mountains[] U8X8_PROGMEM = {
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x38,
 0x00,0x00,0x00,0xf8,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,
 0xc7,0x03,0x00,0x00,0x04,0x3c,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x00,0x00,
 0x60,0x00,0x1c,0x00,0x00,0x03,0xc0,0x03,0x00,0x00,0x00,0x00,0x00,0x08,0x03,
 0x00,0x1e,0x00,0xe0,0x03,0xf0,0x00,0x00,0x7c,0x00,0x00,0x00,0x00,0x00,0x06,
 0x0c,0xe0,0x01,0x00,0x00,0x3c,0x0f,0x00,0x00,0x80,0x07,0x00,0x00,0xe0,0x83,
 0x01,0x30,0x1c,0x00,0x00,0x00,0xc0,0x00,0x00,0x00,0x00,0xf8,0x00,0x00,0x1e,
 0x7c,0x00,0xc0,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0f,0xc0,
 0x01,0x10,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,
 0x38,0x00,0x20,0x00,0x0c,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x07,0x00,0xc0,0x80,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0xc0,0x01,0x00,0x00,0x61,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x3c,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x80,0x03,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x70,0x00,0x00,0x00,0xc0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00,0x00,0x00,0x00,0x0f,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x00,0x00,0x00,
 0x00 };

//XBM format, the splash text that appears when plugging in Beton3
static const unsigned char splash[] U8X8_PROGMEM = {
 0xff,0x03,0x80,0x01,0x3c,0x00,0x00,0x00,0x00,0xf0,0xff,0xff,0x07,0xc0,0x00,
 0x3c,0x00,0x00,0x00,0x00,0xf0,0xff,0x0f,0x0f,0x60,0x00,0x3c,0x00,0x00,0x00,
 0x00,0x00,0x7c,0x0f,0x0f,0x00,0x00,0x3c,0x00,0x00,0x00,0x00,0x00,0x3e,0x0f,
 0x0f,0xfc,0x03,0xff,0xc0,0x3f,0xf0,0x3f,0x00,0x1f,0x0f,0x0f,0xfe,0x07,0xff,
 0xe0,0x7f,0xf0,0x7f,0x80,0x0f,0x0f,0x0f,0x0f,0x0f,0x3c,0xf0,0xf0,0xf0,0xf0,
 0xc0,0x3f,0x0f,0x0f,0x0f,0x0f,0x3c,0xf0,0xf0,0xf0,0xf0,0xc0,0x7f,0xff,0x03,
 0x0f,0x0f,0x3c,0xf0,0xf0,0xf0,0xf0,0x00,0xf0,0xff,0x03,0x0f,0x0f,0x3c,0xf0,
 0xf0,0xf0,0xf0,0x00,0xf0,0x0f,0x0f,0xff,0x0f,0x3c,0xf0,0xf0,0xf0,0xf0,0x00,
 0xf0,0x0f,0x0f,0xff,0x0f,0x3c,0xf0,0xf0,0xf0,0xf0,0x00,0xf0,0x0f,0x0f,0x0f,
 0x00,0x3c,0xf0,0xf0,0xf0,0xf0,0x00,0xf0,0x0f,0x0f,0x0f,0x00,0x3c,0xf0,0xf0,
 0xf0,0xf0,0x00,0xf0,0x0f,0x0f,0x0f,0x0c,0x3c,0xf0,0xf0,0xf0,0xf0,0x30,0xf0,
 0x0f,0x0f,0x0f,0x0c,0x3c,0xf0,0xf0,0xf0,0xf0,0x30,0xf0,0xff,0x07,0xfe,0x07,
 0xf8,0xe0,0x7f,0xf0,0xf0,0xe0,0x7f,0xff,0x03,0xfc,0x03,0xf0,0xc0,0x3f,0xf0,
 0xf0,0xc0,0x3f };

//a bunch of offsets that I use to create a scrolling text effect with
//three separate sections of text
int text1offset = 6;
int text2offset = text1offset + 128;
int text3offset = text2offset + 128;

 void drawAcknowledge() {
  u8g2.firstPage();  do {
    switch (animation_state) {
      //this switch statement decides which frame of the animation to draw based on the number in animation_state.
      case 0 ... 15:
        u8g2.drawXBMP(text1offset, 0, text_width, text_height, text1);
        u8g2.drawXBMP(0, 16, mountain_width, mountain_height, mountains);
        break;
      case 16 ... 405:
        //these if statements decide which sections of text to draw based on their respective
        //scrolling offsets. (if they are fully off the screen, don't draw them)
        if (text1offset >= -127 && text1offset <= 127){
          u8g2.drawXBMP(text1offset, 0, text_width, text_height, text1);
        }
        if (text2offset <= 127 && text2offset >= -127){
          u8g2.drawXBMP(text2offset, 0, text_width, text_height, text2);
        }
        if (text3offset <= 127 && text3offset >= -127){
          u8g2.drawXBMP(text3offset, 0, text_width, text_height, text3);
        }
        u8g2.drawXBMP(0, 16, mountain_width, mountain_height, mountains);
        text1offset--;
        text2offset--;
        text3offset--;
        break;
      case 406 ... 415:
        u8g2.drawXBMP(text3offset, 0, text_width, text_height, text3);
        u8g2.drawXBMP(0, 16, mountain_width, mountain_height, mountains);
        break;
      case 416 ... 430:
        u8g2.drawXBMP(0, (430-animation_state), mountain_width, mountain_height, mountains);
        break;
      case 431 ... 445:
        u8g2.drawXBMP(0, (-430+animation_state), mountain_width, mountain_height, mountains);
        break;
      case 446:
        u8g2.drawXBMP(0, 16, mountain_width, mountain_height, mountains);
        text1offset = 6;
        text2offset = text1offset + 128;
        text3offset = text2offset + 128;
        animation_state = 0;
        break;
    }
  } while ( u8g2.nextPage() );
}

void drawSplash() {
  u8g2.firstPage();  do {
    switch (animation_state) {
      //this switch statement decides which frame of the animation to draw based on the number in animation_state.
      case 0 ... 39:
        u8g2.drawXBMP(20, 7, splash_width, splash_height, splash);
        break;
      case 40:
        u8g2.drawXBMP(20, 7, splash_width, splash_height, splash);
        animation_state = 0;
        animation = 0;
        break;
    }
  } while ( u8g2.nextPage() );
}

void acknowledgeReset() {
   //resets all the text section offsets to their "resting" state
   text1offset = 6;
   text2offset = text1offset + 128;
   text3offset = text2offset + 128;
   animation_state = 0;
}
