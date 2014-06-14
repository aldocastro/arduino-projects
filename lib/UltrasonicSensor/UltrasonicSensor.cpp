//
//  UltrasonicSensor.cpp
//
//  Author: Aldo Castro
//  Copyright (c) 2014. All Right Reserved.
//

#include "UltrasonicSensor.h"
#include "Arduino.h"

UltrasonicSensor::UltrasonicSensor(int trigger, int echo) {
  _trigger = trigger;
  _echo = echo;
  //  setup ultrasonic sensor
  pinMode(_trigger, OUTPUT);
  pinMode(_echo, INPUT);
}

long UltrasonicSensor::distanceInCentimeters () {
  long duration;
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(_trigger, OUTPUT);
  digitalWrite(_trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(_trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(_trigger, LOW);
  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(_echo, INPUT);
  duration = pulseIn(_echo, HIGH);

  // convert the time into a distance
  return microsecondsToCentimeters(duration);
}

long UltrasonicSensor::microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long UltrasonicSensor::microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}