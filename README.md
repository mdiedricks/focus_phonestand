# Focus Phonestand
> A prototype for a phonestand that will inform your when you have not picked up your phone in the last 30minutes - or however long it you configure it for.

## Table of Contents
* [General Information](#general-information)
* [Technology Used](#technology-used)
* [Project Status](#project-status)
* [Acknowledgements](#acknowledgements)

## General Information
This project was inspired by a few previous projects I had prototyped using the Arduino framework, where simple sensors and lights were used to positive affect. I was exploring to see what else I could design that had a small but positive effect on a person's day.

Once the phone is put down, you have 10 seconds to pick it up again before the 'session' begins. A timer then starts for a 25 minute interval during which you cannot pick up your phone again, without an alarm or audio trigger going off.

The end of the interval is indicated by coloured light. I chose RGB LEDs for these projects as a way of indicating the passage of time, to be a little more subtle, but still precise.

## Technology Used
THe prototype is built on the Arduino framework implementing various modules for functionality.
* DS3231 RTC Real-Time Clock for tracking time during the meditation sessions.
* RGB LED light strip
* 3 x TIP122 NPN transistors for powering the LED strip

## Project Status
The project is still in software development phase, as I try to learn from other explorations what an optimal timing oslution would be.

#### Work to follow
* Remove reliance on RTC - I would like to employ the microcontrollers timers, as the exact date/time is not relevant for the build.
* User-testing
* Transfer to PCB
* Device design and prototyping

## Acknowledgements
[Arduino](https://www.arduino.cc/)

[Adafruit RTClib](https://adafruit.github.io/RTClib/html/class_time_span.html#details)

