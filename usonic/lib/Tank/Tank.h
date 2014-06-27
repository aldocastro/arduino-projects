//
//	Tank.h
//
//	Author: Aldo Castro
//	Copyright (c) 2014. All Right Reserved.
//		

#include <AFMotor.h>

class Tank {
public:
  	void stop();
	void setMotors();
  	void goForward();
  	void goBackward();
  	void turnAround();
  	void exploreAround(long distance_cm);
};
