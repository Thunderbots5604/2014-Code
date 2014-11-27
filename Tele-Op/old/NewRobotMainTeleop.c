#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,          grab,          tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     rightmotor_2,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     conveyor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     sweep,         tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C4_1,    backboard,            tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)

#define setting_noEncoders

#include "../api/api.c"

bool userIsAGoat() {
	return false;
}

bool userIsNotAGoat() {
	return !userIsAGoat();
}

#warn "Backboard servo values have not been set!"
#define BackboardBase 128
#define BackboardMove 150;

task main()
{
	eraseDisplay();
	nMotorEncoder[grab] = 0;

	while (true) {
		getJoystickSettings(joystick);
		//setMovementFromJoystick(joystick.joy1_y1, joystick.joy1_x2);
		setMovementFromJoystickComposite(joystick.joy1_y1, joystick.joy1_x2);
		if (joy1Btn(2))
			grabGoal();
		if (joy1Btn(4))
			releaseGoal();
		if (joy1Btn(1))
			servo[backboard] = 128;
		if (joy1Btn(3))
			servo[backboard] = 250;

		/*
		if (joy2Btn(2)) {
			motor[sweep] = 100;
			motor[conveyor] = 100;
		}
		else {
			if (!(joy2Btn(6) || joy2Btn(8) || joy2Btn(5) || joy2Btn(7)))
				motor[sweep] = 0;
			else if (joy2Btn(5))
				motor[sweep] = 100;
			else if (joy2Btn(7))
				motor[sweep] = -100;
			else if (joy2Btn(6))
				motor[conveyor] = -100;
			else if (joy2Btn(8))
				motor[conveyor] = 100;
		}*/
	 if (joy2Btn(1) || joy2Btn(4))
      motor[sweep] = 50;
   else if (joy2Btn(5) || joy2Btn(2))
      motor[sweep] = 100;
   else if (joy2Btn(7))
      motor[sweep] = -100;
   else
      motor[sweep]= 0;

		if (joy2Btn(3) || joy2Btn(4))
      motor[conveyor] = 50;
    else if (joy2Btn(6) || joy2Btn(2))
      motor[conveyor] = 100;
    else if (joy2Btn(8))
      motor[conveyor] = -100;
    else
      motor[conveyor] = 0;

		/*nxtDisplayCenteredTextLine(5, "GRAB: %d", nMotorEncoder[grab]);
		nxtDisplayCenteredTextLine(6, "BACKBOARD: %d", servo[backboard]);
		nxtDisplayCenteredTextLine(0, "sweep: %d", motor[sweep]);*/
		nxtDisplayCenteredTextLine(1, "left1: %d", motor[leftmotor_1]);
		nxtDisplayCenteredTextLine(2, "left2: %d", motor[leftmotor_2]);
		nxtDisplayCenteredTextLine(3, "r1: %d", motor[rightmotor_1]);
		nxtDisplayCenteredTextLine(4, "r2: %d", motor[rightmotor_2]);
	}
}
