using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor Motor1;
extern motor Motor10;
extern sonar RangeFinderE;
extern bumper BumperC;
extern line LineTrackerA;
extern line LineTrackerB;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );