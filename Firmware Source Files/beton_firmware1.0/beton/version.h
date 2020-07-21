char* version = "Firmware Version: 1.0";

void drawVersion() {
  u8g2.firstPage();  do {
    switch (animation_state) {
      //this switch statement decides which frame of the animation to draw based on the number in animation_state.
      case 0 ... 10:
        u8g2.setContrast(255);
        u8g2.setFont(u8g2_font_helvB10_tf);
        u8g2.drawStr(5, 13, version);
        u8g2.drawXBMP(0, 16, mountain_width, mountain_height, mountains);
        break;
      case 11 ... 45:
        u8g2.setFont(u8g2_font_helvB10_tf);
        u8g2.drawStr(-animation_state+16, 13, version);
        u8g2.drawXBMP(0, 16, mountain_width, mountain_height, mountains);
        break;
      case 46 ... 66:
        u8g2.setFont(u8g2_font_helvB10_tf);
        u8g2.drawStr(-29, 13, version);
        u8g2.drawXBMP(0, 16, mountain_width, mountain_height, mountains);
        break;
      case 67 ... 101:
        u8g2.setFont(u8g2_font_helvB10_tf);
        u8g2.drawStr(animation_state-96, 13, version);
        u8g2.drawXBMP(0, 16, mountain_width, mountain_height, mountains);
        break;
      case 102:
        u8g2.setFont(u8g2_font_helvB10_tf);
        u8g2.drawStr(5, 13, version);
        u8g2.drawXBMP(0, 16, mountain_width, mountain_height, mountains);
        animation_state = 0;
        break;
    }
  } while ( u8g2.nextPage() );
}
