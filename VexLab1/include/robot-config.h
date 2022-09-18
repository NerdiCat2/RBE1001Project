using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern motor Motor1;
extern motor Motor10;
extern sonar RangeFinderE;
extern bumper BumperC;
extern line LineTrackerA;
extern line LineTrackerB;
extern signature vision_1__BLUE_BALL;
extern signature vision_1__RED_BALL;
extern signature vision_1__SIG_3;
extern signature vision_1__SIG_4;
extern signature vision_1__SIG_5;
extern signature vision_1__SIG_6;
extern signature vision_1__SIG_7;
extern vision vision_1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );