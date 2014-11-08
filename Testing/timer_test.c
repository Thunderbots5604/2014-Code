#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     infrared,       sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     touch,          sensorTouch)
#pragma config(Motor,  mtr_S1_C1_1,     leftmotor_1,          tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     rightmotor_1,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     Lift1,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     Lift2,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     Left2,         tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     Right2,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_1,     Sweep,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     Flag,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    bucket,               tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    pin,                  tServoStandard)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code painstakingly hand written by Daniel Grimshaw, not by ROBOTC               !!*//

//settings are for last year's robot

#define timersused 1
#define setting_twoMotors

#include "../api/api.c"

task main()
{
	initializeAPI();

	Timer_t timer;
	pTimer_t pTimer = &timer;
	initTimer(pTimer);
	startTimer(pTimer);

	setMovement(100,0);
	while (getSeconds(pTimer) < 2) {}
	setMovement(0,0);
	while (getDeciseconds(pTimer) < 30) {}

	resetTimer(pTimer);
	setMovement(-100, 0);
	while (getCentiseconds(pTimer) < 200) {}
        setMovement(0,0);
        while (getMilliseconds(pTimer) < 3000) {}

	resetTimer(pTimer);
	setMovement(0, 100);
	while (getRuntime(pTimer) < 2.0) {}
        setMovement(0,0);
        while (getSeconds(pTimer) < 3) {}

	resetTimer(pTimer);
	setMovement(0,-100);
	while (getSeconds(pTimer) < 2) {}
        setMovement(0,0);
        while (getDeciseconds(pTimer) < 30) {}

	resetTimer(pTimer);
	setMovement(100,100);
	while (getSeconds(pTimer) < 2) {}
        setMovement(0,0);
        while (getDeciseconds(pTimer) < 30) {}

	resetTimer(pTimer);
	setMovement(-100,-100);
	while (getSeconds(pTimer) < 2) {}
        setMovement(0,0);
}
