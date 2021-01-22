/************************************************************
■参考
	■Arduino 電子工作 実践講座
		p142
************************************************************/
#include <Servo.h>

/************************************************************
************************************************************/
enum STATE{
	STATE__RUN,
	STATE__SLEEP,
};

STATE State = STATE__RUN;
const int SERVO_PIN = 9;
Servo servo;

/************************************************************
************************************************************/

/******************************
******************************/
void setup(){
	servo.attach(SERVO_PIN);
}

/******************************
******************************/
void loop() {
	switch(State){
		case STATE__RUN:
			if(10000 < millis()){
				State = STATE__SLEEP;
				servo.detach();
			}else{
				servo.write(0);
				delay(1000);
				
				servo.write(90);
				delay(1000);
				
				servo.write(180);
				delay(1000);
				
				servo.write(90);
				delay(1000);
			}
			break;
			
		case STATE__SLEEP:
			break;
	}
}
