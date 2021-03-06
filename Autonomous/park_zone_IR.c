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
#define INFRARED infrared
#define setting_twoEncoders
//Configuration is current as of 1/01/15 4:54 PM
//USE DEFAULT CONFIG

/* park_zone_IR.c | A self-contained autonomous procedure
 * Copyright (C) 2015 Thunderbots-5604
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#include "../api/api.c"
//#include "../api/coord.c"
bool foo = true;
task grabTask();

int irStartingValues[] = {0, 0, 0};
int irMiddleValues[] = {5, 5, 0};
int irEndingValues[] = {5, 5, 0};

byte sampleAverage(int samples) {
	byte samplespace[samples];

	for (int i = 0; i < samples; i++) {
		samplespace[i] = SensorValue[infrared];
		wait1Msec((int)(1 / samples * 100));
	}
	int total = 0;
	for (int j = 0; j < samples; j++) {
			total += samplespace[j];
	}

	total /= samples;

	return (byte)total;
}

task main()
{
	//waitForStart();
	int startingValue, middleValue, endingValue;
	moveWithDirection(28,-25);
	wait10Msec(100);
	rotateWithOrientation(90,25);
	byte sampleAverage = getIRSampleAverage(100);
	eraseDisplay();
	while (foo) {
		nxtDisplayCenteredTextLine(0, "%d", SensorValue[infrared]);
		nxtDisplayCenteredTextLine(1, "%d", sampleAverage);
	}
}

task grabTask() {
	motor[grab] = GRAB_MOTOR_SPEED/2;
	wait1Msec(GRAB_MOTOR_DOWN_TIME*2);
	motor[grab] = 0;
	isGoalGrabbed = true;
}
