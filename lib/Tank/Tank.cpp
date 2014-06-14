//
//  Tank.cpp
//
//  Author: Aldo Castro
//  Copyright (c) 2014. All Right Reserved.
//    

#include "Tank.h"
#include <Arduino.h>

//  motor speeds
const int SPEED_FULL = 255;
const int SPEED_NONE = 0;

Tank::tank() {
  motor_left = NULL;
  motor_right = NULL;
}

void Tank::setLeftMotor(AF_DCMotor motor) {
  motor_left = motor;
  motor_left.setSpeed(SPEED_FULL);
  motor_left.run(RELEASE);
}

void Tank::setRightMotor(AF_DCMotor motor) {
  motor_right = motor;
  motor_right.setSpeed(SPEED_FULL);
  motor_right.run(RELEASE);
}

AF_DCMotor Tank::getLeftMotor() {
  return motor_left;
}

AF_DCMotor Tank::getRightMotor() {
  return motor_right;
}

void Tank::stop() {
  motor_left.run(RELEASE);
  motor_left.run(RELEASE);
}

void Tank::turnAround() {
  motor_left.run(BACKWARD);
  motor_right.run(FORWARD);
  delay(1000);
  motor_left.run(FORWARD);
  motor_right.run(BACKWARD);
  delay(1000);
}

void Tank::goForward(){
  motor_left.run(FORWARD);
  motor_right.run(FORWARD);
}

void Tank::goBackward(){
  motor_left.run(BACKWARD);
  motor_right.run(BACKWARD);
}

void Tank::commandTank(long distance_cm) {
  if (distance_cm <= 10) {
    goBackward();
//    turnAround();
  } else {
    goForward();
  }
}