
#include "vex.h"
#include <iostream>
#include "main.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Motor1               motor         1
// Motor10              motor         10
// RangeFinderE         sonar         E, F
// BumperC              bumper        C
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace std;
using namespace vex;  

int main() {
  vexcodeInit();
  move(20);
}

// Given a target distance and wheel diameter, drive straight for the given
// distance.
void move(double cm) {
  double degree = distanceToDegree(cm, 10.16);
  Motor1.rotateFor(degree, deg, 180, dps, false);
  Motor10.rotateFor(degree, deg, 180, dps, false);
}

// Given a target angle, wheel track, and wheel diameter, turn the BaseBot a
// specified angle.
void turnAngle(double angle, double track, double diameter) {
  double cm = (track * M_PI * angle) / 360;
  double degree = distanceToDegree(cm, track);
  Motor1.rotateFor(degree, deg, 40, rpm, false);
  Motor10.rotateFor(-degree, deg, 40, rpm, false);
}

// Changes Distance in cm to degrees
double distanceToDegree(double cm, double track) {
  return (cm * 360 * 5) / (track * M_PI);
}


// Bumping code
void bump() {
  while (true) {
    cout << BumperC.pressing() << endl;
    if (BumperC.pressing() == 1)
      Motor1.spin(reverse, 120, rpm);
    else
      Motor1.stop();
    vex::task::sleep(100);
  }
}