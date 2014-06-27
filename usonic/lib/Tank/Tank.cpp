//
//  Tank.cpp
//
//  Author: Aldo Castro
//  Copyright (c) 2014. All Right Reserved.
//    

#include "Tank.h"
#include <Arduino.h>

//  MIN distance from an object in cm.
const int MINIMUN_DISTANCE = 20;

//  motor speeds
const int SPEED_NONE = 0;
const int SPEED_HALF = 128;
const int SPEED_FULL = 255;

// motor numbers
const int MOTOR_LEFT = 1;
const int MOTOR_RIGHT = 4;

//  Initialize motors
AF_DCMotor motor_left(MOTOR_LEFT, MOTOR12_1KHZ);
AF_DCMotor motor_right(MOTOR_RIGHT, MOTOR12_1KHZ);

void Tank::setMotors () {
  motor_left.setSpeed(SPEED_FULL);
  motor_left.run(RELEASE);

  motor_right.setSpeed(SPEED_FULL);
  motor_right.run(RELEASE);
}

void Tank::stop() {
  motor_left.run(RELEASE);
  motor_left.run(RELEASE);
}

void Tank::turnAround() {
  stop();
  int i = 0;
  motor_left.setSpeed(SPEED_HALF);
  motor_right.setSpeed(SPEED_HALF);
  while(i++<1800) {
    motor_left.run(BACKWARD);
    motor_right.run(FORWARD);
  }
  motor_left.setSpeed(SPEED_FULL);
  motor_right.setSpeed(SPEED_FULL);
  stop();
}

void Tank::goForward(){
  motor_left.run(FORWARD);
  motor_right.run(FORWARD);
}

void Tank::goBackward(){
  motor_left.run(BACKWARD);
  motor_right.run(BACKWARD);
}

void Tank::exploreAround(long distance_cm) {
  if (distance_cm<=MINIMUN_DISTANCE) {
    stop();
    goBackward(); delay(4000);
    turnAround();
  } else {
    goForward();
  }
}