//Required External Arduino Libraries
#include <ClickEncoder.h>
#include <TimerOne.h>
#include <HID-Project.h>

//Header Files included with Beton Firmware
#include "oled.h"
//oled.h includes important setup for the OLED display
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


//these #define statements dictate which pin connects to which button.
//Eg: Button1 is pin 7, etc.
#define BUTTON1    9
#define BUTTON2    8
#define BUTTON3    7

//these integers are counters which monitor how long each button has been clicked
//for, enabling long-press functions such as rewind.
int button1Clicked = 0;
int button2Clicked = 0;
int button3Clicked = 0;
int encoderClicked = 0;

int encoderValue = 0;

//this statement initializes the encoder on pins A1, A0 and A2
ClickEncoder encoder(A1, A0, A2);

TimeStampedValue<int16_t> value(0);
int16_t current = 0;

void timerIsr() {
  encoder.service();
}

void setup() {
  //starts serial communication over USB
  Serial.begin(9600);

  //enables internal pullup resistors for each button pin
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
  pinMode(BUTTON3, INPUT_PULLUP);

  //starts timer that interrupts when encoder is clicked
  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr);

  //initializes libraries that support USB HID (Consumer) and
  //OLED display (u8g2)
  Consumer.begin();
  u8g2.begin();

  //tick runs at the rate of 30FPS, the refresh rate for the display
  tick.start(FPS, AsyncDelay::MILLIS);

  //displays the startup splash screen
  animation = SPLASH;
}

//Main loop
void loop() {
  //checks to see if the rotary encoder has turned
  current += encoder.getValue();
  auto diff = current - value;
  
  if (diff != 0) {

    encoderValue += diff;
    Serial.println(encoderValue);

    //if turned counter-clockwise, display animation 
    if (diff < 0){
      animation_state = 0;
      animation = DOWN;
    }
    //if turned clockwise, display animation 
    else if (diff > 0){
      animation_state = 0;
      animation = UP;
    }
    //if turned clockwise enough, volume up 
    if (encoderValue > 3) {
      Consumer.write(MEDIA_VOL_UP);
      encoderValue = 0;
      delay(60);      
    } 
    //if turned counter-clockwise enough, volume down
    else if (encoderValue < -3) {
      Consumer.write(MEDIA_VOL_DOWN);
      encoderValue = 0;
      delay(60);              
    }
    value.set(current);
  }

  //check to see if the rotary encoder has been clicked
  ClickEncoder::Button b = encoder.getButton();
  if (b != ClickEncoder::Open) {
    encoderClicked++;
    switch (b) {
      case ClickEncoder::Clicked:
        //if we are displaying splash screens, get rid of them
        if (animation == ACKNOWLEDGE || animation == VERSION){
          acknowledgeReset();
          animation = NONE;
          break;
        }
        //if the encoder is not being long pressed, mute the volume and animate
        if(encoderClicked < 3){
          Consumer.write(MEDIA_VOL_MUTE);
          animation_state = 0;
          animation = MUTE;
        }            
        break;
    }
    //if the encoder has been held down for 100 cycles, display the "credits" animation
    if (encoderClicked > 100){
        animation_state = 0;
        animation = ACKNOWLEDGE;
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

     //if the button is clicked and is not being long pressed, play/pause and animate
     if (button1Value != LOW && button1Clicked < 30){
        animation_state = 0;
        animation = PLAY;
        Consumer.write(MEDIA_PLAY_PAUSE);
     } 
     
     //if the button is being long pressed, display the version number for the firmware.
     if (button1Clicked > 30){
        animation_state = 0;
        animation = VERSION;
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

     //if the button is clicked and is not being long pressed, previous and animate
     if (button2Value != LOW && button2Clicked < 3){
        animation_state = 0;
        animation = PREV;
        Consumer.write(MEDIA_PREV);
     } 
     //if the button is being long pressed, display the rewind animation and repeatedly send rewind keystrokes.
     if (button2Clicked > 3){
        animation_state = 0;
        animation = REWIND;
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

     //if the button is clicked and is not being long pressed, next and animate
     if (button3Value != LOW && button3Clicked < 3){
        animation_state = 0;
        animation = NEXT;
        Consumer.write(MEDIA_NEXT);
     } 
     //if the button is being long pressed, display the rewind animation and repeatedly send fast forward keystrokes.
     if (button3Clicked > 3){
        animation_state = 0;
        animation = FORWARD;
        Consumer.write(MEDIA_FAST_FORWARD);
        delay(250);
      }
  } else {
    button3Clicked = 0;
  }

  //30 times a second (30 FPS), the tick "expires" and displays an animation (or none):
  if (tick.isExpired()) {
    switch(animation){
      
      //if theres no animation active, just clear the display
      case NONE:
        u8g2.clearDisplay();
        break;
        
      //if there is an animation active, draw it, increment the animation state,
      //repeat the tick.
      
      case ACKNOWLEDGE:
        drawAcknowledge();
        animation_state++;
        tick.repeat();
        break;
        
      case PLAY:
        drawPlay();
        animation_state++;
        tick.repeat();
        break;
        
      case NEXT:
        drawNext();
        animation_state++;
        tick.repeat();
        break;
        
      case PREV:
        drawPrev();
        animation_state++;
        tick.repeat();
        break;
        
      case FORWARD:
        drawForward();
        animation_state++;
        tick.repeat();
        break;
        
      case REWIND:
        drawRewind();
        animation_state++;
        tick.repeat();
        break;
        
      case UP:
        drawPlus();
        animation_state++;
        tick.repeat();
        break;
        
      case DOWN:
        drawMinus();
        animation_state++;
        tick.repeat();
        break;
        
      case MUTE:
        drawMute();
        animation_state++;
        tick.repeat();
        break;
        
      case VERSION:
        drawVersion();
        animation_state++;
        tick.repeat();
        break;
        
      case SPLASH:
        drawSplash();
        animation_state++;
        tick.repeat();
        break;
    }
  }
}
