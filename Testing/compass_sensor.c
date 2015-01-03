#pragma config(Sensor, S4,     compass,           sensorI2CHiTechnicCompass)
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

#include "../api/api.c"
#include "compass_sensor.h"
#include "coord.h"

int initialCompassReading = SensorValue(compass);

int getCompassReading() {
    return SensorValue(compass);
}

int calculateAverageReading(int samples) {
    int reading = getCompassReading();

    for (int i = 0; i < samples; i++) {
        reading += getCompassReading();
    }

    return round(reading / samples);
}

void alignToCompassZero() {
    while (getCompassReading() != 0) {
        rotateWithOrientation(1, 25);
    }
}

void alignToInitial() {
    while (getCompassReading() != initialCompassReading) {
        rotateWithOrientation(1, 25);
    }
}

void rotateDegreesImp(int degrees, byte power) {    // "Imp" stands for 'improved'
    int start = getCompassReading();
    int checkDifference = degrees * sgn(power);

    rotateWithOrientation(degrees, power);

    int end = getCompassReading();

    if ((start + checkDifference) == end) {
        return;                                     // Jumps back to previous code if successful, retries if not.
    } else {
        int degOff = abs((start + checkDifference) - end);
        int sgnPower = sgn((start + checkDifference) - end);
        rotateDegreesImp(degOff, power * sgnPower);            // Recursive calling until value is achieved.
        return;
    }
}
