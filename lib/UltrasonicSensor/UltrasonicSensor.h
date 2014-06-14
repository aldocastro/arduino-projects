//
//  UltrasonicSensor.h
//
//  Author: Aldo Castro
//  Copyright (c) 2014. All Right Reserved.
//

#ifndef UltrasonicSensor_h
#define UltrasonicSensor_h
#include "Arduino.h"

class UltrasonicSensor {
public:
  UltrasonicSensor(int trigger, int echo);
  long distanceInCentimeters ();
  long microsecondsToInches(long microseconds);
  long microsecondsToCentimeters(long microseconds);
private:
  int _trigger;
  int _echo;
};

#endif