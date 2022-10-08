using namespace vex;

extern brain Brain;

// VEXcode devices
extern line LineTrackerA;
extern line LineTrackerB;
extern motor_group RIght;
extern motor_group LEFT;
extern motor_group doors;
extern motor arm;
extern motor Push;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );