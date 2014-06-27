
/*******
* Motor states
* pin 2 and 7 in GND -> STOP
* pin 2 and 7 in 5V  -> STOP
* pin 2 in 5V  and pin 7 in GND -> DIRECTION A
* pin 2 in GND and pin 7 in 5V  -> DIRECTION B
*******/

//	enable pins
int enablePin1 = 11;
int enablePin2 = 6;

//	pin 5 and 6 for back_wheels
int back_wheels[] = {3, 5};
//	pin 9 and 10 for front_wheels
int front_wheels[] = {9, 10};

//	set speeds
int full_speed = 255;
int middle_speed = 127;
int cero_speed = 0;

//	set delays
int max_delay = 20000;
int nor_delay = 10000;
int min_delay = 5000;

void setup() {
	Serial.begin(9600);
	motorSetup();
}
 
void loop() {
	turnLeft(full_speed);
	delay(nor_delay);
	turnRight(full_speed);
	delay(nor_delay);
	stop();
	// forward(full_speed);
	// delay(max_delay);
	// stop();
	// delay(min_delay);
	// backward(full_speed);
	// delay(max_delay);
	// stop();
}

void stop() {
	Serial.println("stop");
	digitalWrite(front_wheels[0], LOW);
  	digitalWrite(front_wheels[1], LOW);	

  	digitalWrite(back_wheels[0], LOW);
  	digitalWrite(back_wheels[1], LOW);
}

void turnRight(int speed){
	Serial.println("turnLeft");
	setMotor(front_wheels, speed, HIGH);	
}

void turnLeft(int speed){
	Serial.println("turnRight");
	setMotor(front_wheels, speed, LOW);	
}

void forward(int speed) {
	Serial.println("forward");
	setMotor(back_wheels, speed, HIGH);
}

void backward(int speed) {
	Serial.println("backward");
	setMotor(back_wheels, speed, HIGH);	
}

void motorSetup () {
	for(int i = 0; i < 2; i++){
		pinMode(front_wheels[i], OUTPUT);
		pinMode(back_wheels[i], OUTPUT);
	}
	pinMode(enablePin1, OUTPUT);
	pinMode(enablePin2, OUTPUT);
} 

void setMotor(int motor[], int speed, boolean reverse)
{
	analogWrite(enablePin1, speed);
	analogWrite(enablePin2, speed);
	digitalWrite(motor[0], !reverse);
	digitalWrite(motor[1], reverse);
}
