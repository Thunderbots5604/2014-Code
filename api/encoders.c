/* encoders.c | Low-level encoder access and convsersions
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

#include "encoders.h"

// Unit conversions

void resetEncoders() {
	leftEnc1 = 0;
	leftEnc2 = 0;
	rightEnc1 = 0;
	rightEnc2 = 0;
}

// degrees to ticks
int degreesToRotateTicks(float degrees) {
	return (int)(ENCODER_TICKS_PER_ROTATE_DEGREE * degrees);
}

int degreesToSwingTicks(float degrees) {
	return (int)(ENCODER_TICKS_PER_SWING_DEGREE * degrees);
}

int degreesToRawTicks(float degrees) {
	//convert raw degrees into ticks for simple rotating mechanisms
	return (int)(ENCODER_TICKS_PER_DEGREE * degrees);
}

// ticks to degrees
float rotateTicksToDegrees(long ticks) {
	return ticks / ENCODER_TICKS_PER_ROTATE_DEGREE;
}

float swingTicksToDegrees(long ticks) {
	return ticks / ENCODER_TICKS_PER_SWING_DEGREE;
}

float rawTicksToDegrees(long ticks) {
	return ticks / ENCODER_TICKS_PER_DEGREE;
}

// inches to ticks
int inchesToDriveTicks(float inches) {
	return (int)(ENCODER_TICKS_PER_DRIVE_INCH * inches);
}

// ticks to inches
float driveTicksToInches(long ticks) {
	return ticks / ENCODER_TICKS_PER_DRIVE_INCH;
}

// centimeters to ticks
int centimetersToDriveTicks(float centimeters) {
	return inchesToDriveTicks(cmToIn(centimeters));
}

// ticks to centimeters
float driveTicksToCentimeters(long ticks) {
	return inToCm(driveTicksToInches(ticks));
}
