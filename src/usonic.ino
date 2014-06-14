//
//  usonic.ino
//
//  Author: Aldo Castro
//  Copyright (c) 2014. All Right Reserved.
//

#include <UltrasonicSensor.h>

// set trigger and echo port for Ultrasonic class
UltrasonicSensor ultrasonicSensor(3, 13);

void setup () {
  Serial.begin (9600);
}

void loop () {
  //  get distance in cm
  long distance_cm = ultrasonicSensor.distanceInCentimeters();

  Serial.print("\n\ndistance: ");
  Serial.print(distance_cm);
  Serial.print(" cm\n\n");
}
