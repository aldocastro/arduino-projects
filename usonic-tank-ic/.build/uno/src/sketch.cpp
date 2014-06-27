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

//	set the LC enable pin at 11
int enablePin = 11;
int enablePin2 = 3;
//	pin 9 and 10 for motor_a
int motor_a[] = {9, 10};
//	pin 5 and 6 for motor_b
int motor_b[] = {5, 6};

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
	digitalWrite(motor_a[0], LOW);
  	digitalWrite(motor_a[1], LOW);	

  	digitalWrite(motor_b[0], LOW);
  	digitalWrite(motor_b[1], LOW);
}

void forward(int speed) {
	setMotor(motor_a, speed, HIGH);
	setMotor(motor_b, speed, HIGH);
}

void backward(int speed) {
	setMotor(motor_a, speed, LOW);
	setMotor(motor_b, speed, LOW);	
}


void motorSetup () {
	for(int i = 0; i < 2; i++){
		pinMode(motor_a[i], OUTPUT);
		pinMode(motor_b[i], OUTPUT);
	}
	pinMode(enablePin, OUTPUT);
	pinMode(enablePin2, OUTPUT);
} 

void setMotor(int motor[], int speed, boolean reverse)
{
  analogWrite(enablePin, speed);
  digitalWrite(motor[0], !reverse);
  digitalWrite(motor[1], reverse);
}
