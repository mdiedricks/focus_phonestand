#include <Arduino.h>

#define PININ 9

int longPress = 500;

long timeDown = 0;
bool buttonPressed = false;

void setup() {
  Serial.begin(9600);
  pinMode(PININ, INPUT);

  Serial.println("Ready to go!");
};

void loop() {
  while (digitalRead(PININ) == HIGH) {
    delay(100);
    timeDown = timeDown + 100;
  }

  if (timeDown >= longPress) {
      timeDown = 0;
      buttonPressed = true;
    }

  if (buttonPressed == true) {
    Serial.println("===Button pressed");
    buttonPressed = false;
  }

};