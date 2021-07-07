#include <Arduino.h>

#define PINOUT 8
#define PININ 9

int longPress = 500;
long timeDown = 0;
bool buttonPressed = false;

void setup() {
  Serial.begin(9600);
  pinMode(PINOUT, OUTPUT);
  pinMode(PININ, INPUT);

  digitalWrite(PINOUT, HIGH);
};

void loop() {
  while(digitalRead(PININ) == HIGH){
    delay(100);
    timeDown = timeDown + 100;
  } 

  if(timeDown >= longPress){
    timeDown = 0;
    Serial.print("Button has been pressed");
  }

};