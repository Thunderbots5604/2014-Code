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
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define setting_twoEncoders

#include "coord.c"

void rotateDegreesImp(int degrees, byte power);

task main()
{
	setDefaults();
	driveInches(48, -25);
	updateCoords(-48);
	swingDegrees(105, 1, -50);
	updateDirection(-105);
	driveInches(6, -25);
	updateDirection(-90);
	updateCoords(7);
	swingDegrees(90, 1, -50);
	rotateDegreesImp(150, -50);
	updateDirection(-180);
	updateCoords(18);
	driveInches(60, -50);
	updateCoords(-60);
	grabGoal_time();
	updateCoords(-60);
	waitDeciseconds(10);
	rotateDegreesImp(20, 50);
	updateDirection(20);
	waitDeciseconds(1);
	driveInches(48, 50);
	updateCoords(48);
	driveInches(60, 50);
	updateCoords(60);
	rotateDegreesImp(180, 100);
	updateDirection(180);
	releaseGoal_time();
	
	while (true) {
		nxtDisplayCenteredTextLine(0, "X is: %0.01f", readValues('x'));
		nxtDisplayCenteredTextLine(1, "Z is: %0.01f", readValues('z'));
		nxtDisplayCenteredTextLine(2, "O is: %0.01f", (readValues('o') * 180 / PI));
	}
}

void rotateDegreesImp(int degrees, byte power) {
	if (power < 0)
		degrees -= 3;
	if (power > 0)
		degrees -= 5;
	rotateDegrees(degrees, power);
}
