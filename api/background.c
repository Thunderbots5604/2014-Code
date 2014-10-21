// background.c
// Contains code for a background processes task

#include "api.c"
#include "timer.c"
//#include "movement.c" //uncomment this line if it's giving compile errors for setMovement()

void initializeAPI() {
	setMovement(0,0,0);
	timeInit();
}

task background() {
	monitorSysTimer();
	updateAllTimers();
}