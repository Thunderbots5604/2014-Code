#pragma config(Sensor, S1,     HTSPB,               sensorI2CCustom9V)
#pragma config(Sensor, S4,     US_PORT,             sensorSONAR)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*   HiTechnic Experimenter's Kit for the SuperPro

Experiment - 3 Six LEDs and the Ultrasonic sensor

This program reads the raw value of the sound sensor and outputs a
digital value to one of six LEDs.

Port 1 - HiTechnic Prototype Board
Port 4 - Ultrasonic sensor

*/

#include "drivers/hitechnic-superpro.h"

task main() {
  int sonarvalue;
  ubyte outputdata;
  int bit;

  // The data to be written: 0x3F = 111111 binary,
  // makes all digital ports outputs.
  HTSPBsetupIO(HTSPB, 0x3F);

  while(true) {
    // Get the value from the LEGO sound sensor.
    sonarvalue = SensorValue[US_PORT];

    // Set the output bit based on the analogue input value
    bit = sonarvalue / 10;
    if (bit > 5) bit = 5;
    outputdata = 1 << bit;

    eraseDisplay();
    nxtDisplayTextLine(1, "%d", sonarvalue);

    HTSPBwriteIO(HTSPB, outputdata);
    wait1Msec(50);
  }
}
