#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     infrared,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     sweep,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     conveyor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     rightmotor_2,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     grab,          tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S2_C1_1,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     backboard,     tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C4_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
#define INFRARED infrared
#define setting_twoEncoders
//USE DEFAULT CONFIG
#define INFRARED infrared

#define setting_twoEncoders

#include "../api/api.c"

void displayDebugInfo();

static const bool DISPLAY_DEBUG_INFORMATION = false;

task main()
{
	initializeAPI();
	initializeRobot();
	eraseDisplay();
	while (true) {
		getJoystickSettings(joystick);
		setMovement(correctJoystickComposite(joystick.joy1_y1), correctJoystickComposite(joystick.joy1_x2));
		setGoalHookJoystick();
		setBackboardJoystick();
		setSweeperJoystick();
		setConveyorJoystick();
		displayDebugInfo();
	}
}

void displayDebugInfo() {
	if (DISPLAY_DEBUG_INFORMATION) {
		//nxtDisplayCenteredTextLine(5, "GRAB: %d", nMotorEncoder[grab]);
		//nxtDisplayCenteredTextLine(6, "BACKBOARD: %d", servo[backboard]);
		//nxtDisplayCenteredTextLine(0, "sweep: %d", motor[sweep]);
		nxtDisplayCenteredTextLine(1, "left1: %d", motor[leftmotor_1]);
		nxtDisplayCenteredTextLine(2, "left2: %d", motor[leftmotor_2]);
		nxtDisplayCenteredTextLine(3, "right1: %d", motor[rightmotor_1]);
		nxtDisplayCenteredTextLine(4, "right2: %d", motor[rightmotor_2]);
	}
}
