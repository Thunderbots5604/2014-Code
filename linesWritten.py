# linesWritten.py
# Returns how many lines of code exist in it's path.

# Please keep this list alphebetized
filesToCheck = ('api/api.c',
	'api/background.c',
	'api/encoders.c',
	'api/encoders.h',
	'api/functions.c',
	'api/functions.h',
	'api/math.c',
	'api/math.h',
	'api/movement.c',
	'api/movement.h',
	'api/ruler.c',
	'api/ruler.h',
	'api/sensors.c',
	'api/sensors.h',
	'api/settings.c',
	'api/simplemovement.c',
	'api/simplemovement.h',
	'api/timer.c',
	'api/timer.h',
	
	'autonomous/drive_off_ramp_auto.c',
	
	'config/2013_robot_config.c',
	'config/default_config.c',
	
	'sample/first_driving_program.c',
	'sample/mecanumDrive.h',
	'sample/SensorTesting.c',
	'sample/SpinTheWheel.c',
	
	'tele-op/main teleop.c',
	
	'testing/main_test_program.c',
	'testing/setMovementTest.c',
	'testing/turn_test.c',
	
	'wait-to-add/unit_converter.c',
	'wait-to-add/unitConverter.c',
	'wait-to-add/WIPCoordSystem.c',
	
	'linesWritten.py')

def lengthOf(filename):
	try:
		return sum(1 for line in open(filename))
	except:
		print("There was an error and " + filename + " could not be read")
		return 0;

# Main code

lines = 0
for file in filesToCheck:
	lines += lengthOf(file)
	
print("All the specified files contain a total of %d lines of code" % lines)