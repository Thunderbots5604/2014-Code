// encoders.c
// Contains code for accessing encoder values at the lowest possible level

// Accessing encoder values

#include "encoders.h"
// Unit conversions

// degrees to ticks
long degreesToTicks(float degrees) {
	return degreesToTurnTicks(degrees);
}

long degreesToTurnTicks(float degrees) {
	return ENCODER_TICKS_PER_TURN_DEGREE * degrees;
}

long degreesToSwingTicks(float degrees) {
	return ENCODER_TICKS_PER_SWING_DEGREE * degrees;
}

// ticks to degrees
float ticksToDegrees(long ticks) {
	return turnTicksToDegrees(ticks);
}

float turnTicksToDegrees(long ticks) {
	return ticks / ENCODER_TICKS_PER_TURN_DEGREE;
}

float swingTicksToDegrees(long ticks) {
	return ticks / ENCODER_TICKS_PER_SWING_DEGREE;
}

// inches to ticks
long inchesToTicks(float inches) {
	return inchesToDriveTicks(inches);
}

long inchesToDriveTicks(float inches) {
	return ENCODER_TICKS_PER_DRIVE_INCH * inches;
}

long inchesToStrafeTicks(float inches) {
	return 	ENCODER_TICKS_PER_STRAFE_INCH * inches;
}

// ticks to inches
float ticksToInches(long ticks) {
	return driveTicksToInches(ticks);
}

float driveTicksToInches(long ticks) {
	return ticks / ENCODER_TICKS_PER_DRIVE_INCH;
}

float strafeTicksToInches(long ticks) {
	return ticks / ENCODER_TICKS_PER_STRAFE_INCH;
}

// centimeters to ticks
long centimetersToTicks(float centimeters) {
	return centimetersToDriveTicks(centimeters);
}

long centimetersToDriveTicks(float centimeters) {
	return inchesToTicks(cmToIn(centimeters));
}

long centimetersToStrafeTicks(float centimeters) {
	return inchesToStrafeTicks(cmToIn(centimeters));
}

// ticks to centimeters
float ticksToCentimeters(long ticks) {
	return driveTicksToCentimeters(ticks);
}

float driveTicksToCentimeters(long ticks) {
	return inToCm(driveTicksToInches(ticks));
}

float strafeTicksToCentimeters(long ticks) {
	return inToCm(strafeTicksToInches(ticks));
}