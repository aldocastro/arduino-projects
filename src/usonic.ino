//
//  usonic.ino
//
//  Author: Aldo Castro
//  Copyright (c) 2014. All Right Reserved.
//

#include <UltrasonicSensor.h>
#include <Tank.h>

// Initialize and Set UltrasonicSensor's trigger and echo ports
UltrasonicSensor ultrasonicSensor(3, 13);
//	Initialize the Tank.
Tank tank;

void setup () {
  Serial.begin (9600);
  tank.setMotors();
}

void loop () {
  //  get distance in cm and let the tank explore around. :-)
  tank.exploreAround(ultrasonicSensor.distanceInCentimeters());
}
