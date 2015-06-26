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

/* main_teleop_v2.c | Major version 2 of the robot's tele-op code
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

void displayDebugInfo();

static const bool DISPLAY_DEBUG_INFORMATION = true;

task main()
{
	//initializeAPI();
	initializeRobot();
	eraseDisplay();
	while (true) {
		getJoystickSettings(joystick);
		setMovement(correctJoystickComposite(joystick.joy1_y1), correctJoystickComposite(joystick.joy1_x2));
		//setGoalHookJoystick();
		//setBackboardJoystick();
		//setSweeperJoystick();
		//setConveyorJoystick();
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
