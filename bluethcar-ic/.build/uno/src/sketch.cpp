#include <Arduino.h>

void setup();
void loop();
void stop();
void forward(int speed);
void backward(int speed);
void motorSetup ();
void setMotor(int motor[], int speed, boolean reverse);
#line 1 "src/sketch.ino"

/*******
* Motor states
* pin 2 and 7 in GND -> STOP
* pin 2 and 7 in 5V  -> STOP
* pin 2 in 5V  and pin 7 in GND -> DIRECTION A
* pin 2 in GND and pin 7 in 5V  -> DIRECTION B
*******/

//	pin 5 and 6 for front_wheels
int front_wheels[] = {5, 6};
//	pin 9 and 10 for back_wheels
int back_wheels[] = {9, 10};

//	set speeds
int full_speed = 255;
int middle_speed = 127;
int cero_speed = 0;

//	set delays
int max_delay = 20000;
int nor_delay = 10000;
int min_delay = 5000;

void setup() {
	motorSetup();
}
 
void loop() {
	forward(full_speed);
	delay(max_delay);
	stop();
	delay(min_delay);
	backward(full_speed);
	delay(max_delay);
	stop();
}

void stop() {
	digitalWrite(front_wheels[0], LOW);
  	digitalWrite(front_wheels[1], LOW);	

  	digitalWrite(back_wheels[0], LOW);
  	digitalWrite(back_wheels[1], LOW);
}

void forward(int speed) {
	setMotor(front_wheels, speed, HIGH);
	setMotor(back_wheels, speed, HIGH);
}

void backward(int speed) {
	setMotor(front_wheels, speed, LOW);
	setMotor(back_wheels, speed, LOW);	
}


void motorSetup () {
	for(int i = 0; i < 2; i++){
		pinMode(front_wheels[i], OUTPUT);
		pinMode(back_wheels[i], OUTPUT);
	}
} 

void setMotor(int motor[], int speed, boolean reverse)
{
  digitalWrite(motor[0], !reverse);
  digitalWrite(motor[1], reverse);
}
