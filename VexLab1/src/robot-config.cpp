#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Motor1 = motor(PORT1, ratio18_1, true);
motor Motor10 = motor(PORT10, ratio18_1, false);
sonar RangeFinderE = sonar(Brain.ThreeWirePort.E);
bumper BumperC = bumper(Brain.ThreeWirePort.C);
line LineTrackerA = line(Brain.ThreeWirePort.A);
line LineTrackerB = line(Brain.ThreeWirePort.B);
/*vex-vision-config:begin*/
signature vision_1__BLUE_BALL = signature (1, -2849, -2081, -2465, 10103, 14043, 12073, 2, 0);
signature vision_1__RED_BALL = signature (2, 10213, 12125, 11169, -1, 415, 207, 2.5, 0);
vision vision_1 = vision (PORT5, 50, vision_1__BLUE_BALL, vision_1__RED_BALL);
/*vex-vision-config:end*/

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}