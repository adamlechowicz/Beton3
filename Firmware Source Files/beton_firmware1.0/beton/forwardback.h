//XBM format "flipped" play icon (for rewind)
static const unsigned char reverse_play[] U8X8_PROGMEM = {
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x00,0x00,0x00,
 0x3e,0x00,0x00,0x80,0x3f,0x00,0x00,0xe0,0x3f,0x00,0x00,0xf8,0x3f,0x00,0x00,
 0xfe,0x3f,0x00,0x80,0xff,0x3f,0x00,0xe0,0xff,0x3f,0x00,0xf8,0xff,0x3f,0x00,
 0xfe,0xff,0x3f,0x80,0xff,0xff,0x3f,0xe0,0xff,0xff,0x3f,0xf8,0xff,0xff,0x3f,
 0xfc,0xff,0xff,0x3f,0xfc,0xff,0xff,0x3f,0xf8,0xff,0xff,0x3f,0xe0,0xff,0xff,
 0x3f,0x80,0xff,0xff,0x3f,0x00,0xfe,0xff,0x3f,0x00,0xf8,0xff,0x3f,0x00,0xe0,
 0xff,0x3f,0x00,0x80,0xff,0x3f,0x00,0x00,0xfe,0x3f,0x00,0x00,0xf8,0x3f,0x00,
 0x00,0xe0,0x3f,0x00,0x00,0x80,0x3f,0x00,0x00,0x00,0x3e,0x00,0x00,0x00,0x18,
 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };


void drawForward() {
  u8g2.firstPage();  do {
    switch (animation_state) {
      //this switch statement decides which frame of the animation to draw based on the number in animation_state.
      case 0 ... 10:
        u8g2.setContrast(255);
        u8g2.drawXBMP(33, 0, icon_width, icon_height, play);
        u8g2.drawXBMP(63, 0, icon_width, icon_height, play);
        break;
      case 11 ... 20:
        u8g2.setContrast(0);
        u8g2.drawXBMP(-132+(animation_state*15), 0, icon_width, icon_height, play);
        u8g2.drawXBMP(-102+(animation_state*15), 0, icon_width, icon_height, play);
        break;
      case 21:
        animation = 0;
        break;
    }
  } while ( u8g2.nextPage() );
}

void drawRewind() {
  u8g2.firstPage();  do {
    switch (animation_state) {
      //this switch statement decides which frame of the animation to draw based on the number in animation_state.
      case 0 ... 10:
        u8g2.setContrast(255);
        u8g2.drawXBMP(33, 0, icon_width, icon_height, reverse_play);
        u8g2.drawXBMP(63, 0, icon_width, icon_height, reverse_play);
        break;
      case 11 ... 20:
        u8g2.setContrast(0);
        u8g2.drawXBMP(183-(animation_state*15), 0, icon_width, icon_height, reverse_play);
        u8g2.drawXBMP(213-(animation_state*15), 0, icon_width, icon_height, reverse_play);
        break;
      case 21:
        animation = 0;
        break;
    }
  } while ( u8g2.nextPage() );
}
