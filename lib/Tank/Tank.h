//
//	Tank.h
//
//	Author: Aldo Castro
//	Copyright (c) 2014. All Right Reserved.
//		

#include <AFMotor.h>

class Tank {
public:
	tank();
	void setLeftMotor(AF_DCMotor motor);
	void setRightMotor(AF_DCMotor motor);
	AF_DCMotor getLeftMotor();
	AF_DCMotor getRightMotor();
  	void stop();
  	void turnAround();
  	void goForward();
  	void goBackward();
  	void commandTank(long distance_cm);
private:
	AF_DCMotor motor_left;
  	AF_DCMotor motor_right;
};
