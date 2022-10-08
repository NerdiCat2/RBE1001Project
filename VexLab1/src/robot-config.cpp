#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
line LineTrackerA = line(Brain.ThreeWirePort.A);
line LineTrackerB = line(Brain.ThreeWirePort.B);
motor RIghtMotorA = motor(PORT2, ratio18_1, true);
motor RIghtMotorB = motor(PORT10, ratio18_1, true);
motor_group RIght = motor_group(RIghtMotorA, RIghtMotorB);
motor LEFTMotorA = motor(PORT1, ratio18_1, false);
motor LEFTMotorB = motor(PORT9, ratio18_1, false);
motor_group LEFT = motor_group(LEFTMotorA, LEFTMotorB);
motor doorsMotorA = motor(PORT3, ratio18_1, true);
motor doorsMotorB = motor(PORT8, ratio18_1, false);
motor_group doors = motor_group(doorsMotorA, doorsMotorB);
motor arm = motor(PORT5, ratio18_1, false);
motor Push = motor(PORT7, ratio18_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}