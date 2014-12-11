// settings.h
// Contains all setting and configuration constants for the robot
// Different groups of settings should be separated by comments

#define SETTINGS_INCLUDEGUARD

// Joysticks
const int JOYSTICK_MIN_VALUE = 5; //min value where the reading is accepted as an input
const int JOYSTICK_MAX_VALUE = 127; //should only be changed if a different joystick is used
const float JOYSTICK_LINEAR_WEIGHT = 2.5; // Raising this will make the mid-joystick values move the robot faster; lowering will give more control for lower speeds of the robot
//technically, it's the weight of the linear scale to the exponential scale in the final

// Movement
const byte DRIVE_MIN_POWER = 0; //abs(power) cannot be in (0, min)
const byte DRIVE_MAX_POWER = 100; //abs(power) cannot exceed max
const byte STRAFE_MIN_POWER = 0;
const byte STRAFE_MAX_POWER = 100;
const byte ROTATE_MIN_POWER = 0;
const byte ROTATE_MAX_POWER = 100;
const float MOVE_POWER_SCALE = 1.0; //used for imposing speed limits
const float DRIVE_POWER_WEIGHT = 1.0; //weights are used for changing responsiveness of different movements
const float STRAFE_POWER_WEIGHT = 1.0;
const float ROTATE_POWER_WEIGHT = 1.0;

// Motor Constants
const byte MOTOR_MIN_POWER = 0; //not yet implemented
const byte MOTOR_MAX_POWER = 100;
const byte DEFAULT_MOTOR_POWER = 100; // when power is not specified

// Encoder Settings
const int ENCODER_TICKS_PER_DRIVE_INCH = 1440/(3*PI);
const int ENCODER_TICKS_PER_STRAFE_INCH = 100;
const int ENCODER_TICKS_PER_ROTATE_DEGREE = 100;
const int ENCODER_TICKS_PER_SWING_DEGREE = 200;
#warn "(settings.c) Encoder values still need to be set! Encoder functions will not work."

// Functional motor constants
const byte GRAB_MOTOR_SPEED = 35; //**UNTESTED**
const int GRAB_MOTOR_TIME = 500; //**UNTESTED** msecs the motor moves
const byte BACKBOARD_MOTOR_SPEED = 30;
const int BACKBOARD_MOTOR_DOWN_TIME = 500;
const int BACKBOARD_MOTOR_UP_TIME = 565;
const int LIFT_MOTOR_SPEED = 80; //**UNTESTED**
const int LIFT_MOTOR_TIME = 10; //**UNTESTED**
const byte SWEEP_MOTOR_SPEED = 100;
const byte SWEEP_MOTOR_SLOW_SPEED = 40; // speed in 'slow' mode
const byte CONVEYOR_MOTOR_SPEED = 100;
const byte CONVEYOR_MOTOR_SLOW_SPEED = 40;

// Turn constant
const byte TURN_CONSTANT = 0; //used for correcting any natural curvature of the robot while driving
