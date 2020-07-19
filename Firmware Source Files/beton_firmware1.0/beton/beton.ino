#include <ClickEncoder.h>
#include <TimerOne.h>
#include <HID-Project.h>
#include "oled.h"
#include "acknowledge.h"
#include "play.h"
#include "forwardback.h"
#include "nextprev.h"
#include "volupdown.h"
#include "version.h"

template<typename T>
struct TimeStampedValue {
  explicit TimeStampedValue(T value) : _value(value), _timeStamp(0) {}
  void set(const T& value) { _value = value; touch(); }
  operator const T&() const { return _value; }
  void touch() { _timeStamp = millis(); }
  unsigned long getTimeStamp() const { return _timeStamp; }
  
private:
  T _value;
  unsigned long _timeStamp;
};


#define BUTTON1    7
#define BUTTON2    8
#define BUTTON3    9
int button1Clicked = 0;
int button2Clicked = 0;
int button3Clicked = 0;
int encoderClicked = 0;

ClickEncoder encoder(A1, A0, A2);

TimeStampedValue<int16_t> value(0);
int16_t current = 0;
int16_t intensity = 0;

void timerIsr() {
  encoder.service();
}

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);

  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr);

  Consumer.begin();
  u8g2.begin();
  tick.start(FPS, AsyncDelay::MILLIS);
  animation = 99;
}

void loop() {
  current += encoder.getValue();
  auto diff = current - value;
  if (diff != 0) {
    //Serial.print("Encoder Diff: ");    
    //Serial.println(diff);

    if (diff > 0) {
      Consumer.write(MEDIA_VOL_UP);
      animation_state = 0;
      animation = 7;
      delay(80);      
    } 
    else {
      Consumer.write(MEDIA_VOL_DOWN);
      animation_state = 0;
      animation = 8;
      delay(80);              
    }
    Serial.println(intensity);
    value.set(current);
  }

  ClickEncoder::Button b = encoder.getButton();
  if (b != ClickEncoder::Open) {
    encoderClicked++;
    switch (b) {
      case ClickEncoder::Clicked:
        if (animation == 1 || animation == 10){
          acknowledgeReset();
          animation = 0;
          break;
        }
        if(encoderClicked < 3){
          animation_state = 0;
          animation = 9;
          Consumer.write(MEDIA_VOL_MUTE); 
        }            
        break;
    }
    if (encoderClicked > 100){
        animation_state = 0;
        animation = 1;
    }
  } else {
    encoderClicked = 0;
  }

  //Play-Pause Button Logic
  int button1Value = digitalRead(BUTTON1);
  if (button1Value == LOW){
     button1Clicked++;
     delay(100);
     button1Value = digitalRead(BUTTON1);
     if (button1Value != LOW && button1Clicked < 30){
        animation_state = 0;
        animation = 2;
        Consumer.write(MEDIA_PLAY_PAUSE);
     } 
     if (button1Clicked > 30){
        animation_state = 0;
        animation = 10;
        delay(250);
      }
  } else {
    button1Clicked = 0;
  }

  //Previous & Rewind Button Logic
  int button2Value = digitalRead(BUTTON2);
  if (button2Value == LOW){
     button2Clicked++;
     delay(100);
     button2Value = digitalRead(BUTTON2);
     if (button2Value != LOW && button2Clicked < 3){
        animation_state = 0;
        animation = 4;
        Consumer.write(MEDIA_PREV);
     } 
     if (button2Clicked > 3){
        animation_state = 0;
        animation = 6;
        Consumer.write(MEDIA_REWIND);
        delay(250);
      }
  } else {
    button2Clicked = 0;
  }

  //Next & Fast-Forward Button Logic
  int button3Value = digitalRead(BUTTON3);
  if (button3Value == LOW){
     button3Clicked++;
     delay(100);
     button3Value = digitalRead(BUTTON3);
     if (button3Value != LOW && button3Clicked < 3){
        animation_state = 0;
        animation = 3;
        Consumer.write(MEDIA_NEXT);
     } 
     if (button3Clicked > 3){
        animation_state = 0;
        animation = 5;
        Consumer.write(MEDIA_FAST_FORWARD);
        delay(250);
      }
  } else {
    button3Clicked = 0;
  }
  
  if (tick.isExpired()) {
    switch(animation){
      case 0:
        u8g2.clearDisplay();
        break;
      case 1:
        drawAcknowledge();
        animation_state++;
        tick.repeat();
        break;
      case 2:
        drawPlay();
        animation_state++;
        tick.repeat();
        break;
      case 3:
        drawNext();
        animation_state++;
        tick.repeat();
        break;
      case 4:
        drawPrev();
        animation_state++;
        tick.repeat();
        break;
      case 5:
        drawForward();
        animation_state++;
        tick.repeat();
        break;
      case 6:
        drawRewind();
        animation_state++;
        tick.repeat();
        break;
      case 7:
        drawPlus();
        animation_state++;
        tick.repeat();
        break;
      case 8:
        drawMinus();
        animation_state++;
        tick.repeat();
        break;
      case 9:
        drawMute();
        animation_state++;
        tick.repeat();
        break;
      case 10:
        drawVersion();
        animation_state++;
        tick.repeat();
        break;
      case 99:
        drawSplash();
        animation_state++;
        tick.repeat();
        break;
    }
  }
}
