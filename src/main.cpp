#include <RTClib.h>
#include <Arduino.h>

#define PHONEPIN 9
#define TRIGGER 10

RTC_DS3231 rtc;

bool inSession = false;
bool phoneDown = false;
int timeStart_s;
int timeStart_m;
int timeDown_s = 0;
int timeDown_m = 0;
int focusDuration = 25;
DateTime timeTrack;
TimeSpan timeEnd;

void setup() {
  Serial.begin(9600);
  Serial.println("Setting up");
  pinMode(PHONEPIN, INPUT);

};

void loop() {
  //UPDATE TIMER
  if (inSession) {
    timeTrack = rtc.now();
    if (timeDown_m < 1) {
      if (timeDown_s != timeTrack.second()) {
        timeDown_s = timeTrack.second();
      }
    }
    if (timeDown_m != timeTrack.minute()) {
      timeDown_m = timeTrack.minute();
    }

  }

  //CHECK SWITCH
  if (digitalRead(PHONEPIN) == LOW) {
    phoneDown = false;
  } else {
    phoneDown = true;
  }

  // POINT OF NO RETURN
  if (phoneDown && !inSession) {
    if (timeDown_s > TRIGGER) {
      DateTime now = rtc.now();
      timeStart_s = now.second();
      timeStart_m = now.second();
      timeEnd = TimeSpan(0, 0, focusDuration, 0);
      inSession = true;
    }
  }

  // LIFT PHONE
  while (!phoneDown && inSession) {
    if (timeDown_m < focusDuration) {
      //make noise
    } else {
      reset();
      break;
    }
  }
};

void reset() {
  inSession = false;
  timeDown_m = 0;
  timeDown_s = 0;
}
