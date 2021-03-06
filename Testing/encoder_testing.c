#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,   tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     sweep,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     rightmotor_1,  tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     conveyor,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     grab,          tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     rightmotor_2,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     leftmotor_2,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     backboard,     tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define setting_twoEncoders
#include "../api/api.c"

task main() {
	//resets the encoders
	//if we fail to do this none of the encoder functions will work
	initializeAPI();
	initializeRobot();
	eraseDisplay();
	//waitForStart();
	
	//low level style
	setMovement(10, 0);
	moveFor(inchesToDriveTicks(36));
	//should automatically halt in moveFor();
	//moveFor() also resets the encoders as soon as it stops.
	waitSeconds(1);
	
	setMovement(0, 10);
	moveFor(degreesToRotateTicks(180));
	waitSeconds(1);
	
	//high level style
	driveInches(36, 10);
	waitSeconds(1);
	
	rotateDegrees(180, -10);
	waitSeconds(1);
	
	//I think that we should only use the high level functions for swinging.
	swingDegrees(90, 1, 10);
	swingDegrees(90, 1, -10);
	waitSeconds(1);
	
	swingDegrees(90, -1, 10);
	swingDegrees(90, -1, -10);
	waitSeconds(1);
	
	//should end up exactly where it started
}
