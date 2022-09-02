
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

double wheelDiameter = 10.16;
double track = 28.4;
int globalRpm = 100;

int main() {
  vexcodeInit();
  cout << "starting..." << endl;
  star(50.8);

  //turnAngle(360,track,wheelDiameter);
  cout << "end" << endl;
}

// Given a target distance and wheel diameter, drive straight for the given distance.
void move(double cm) {
  cout << "moving " << cm << "cm..." << endl;
  double degree = distanceToDegree(cm, wheelDiameter);
  Motor1.rotateFor(degree, deg, globalRpm, rpm, false);
  Motor10.rotateFor(degree, deg, globalRpm, rpm);
}

// Given a target angle, wheel track, and wheel diameter, turn the BaseBot a
// specified angle.
void turnAngle(double angle, double track, double diameter) {
  cout << "turning " << angle << "degree..." << endl;
  double cm = (track * M_PI * angle) / 360;
  cout << "turning " << cm << "cm..." << endl;
  double degree = distanceToDegree(cm, diameter);
  Motor1.rotateFor(degree, deg, globalRpm, rpm, false);
  Motor10.rotateFor(-degree, deg, globalRpm, rpm);
}

// Changes Distance in cm to degrees
double distanceToDegree(double cm, double d) {
  return (cm * 360 * 5) / (d * M_PI);
}


// Bumping code
void bump() {
  while (true) {
    cout << BumperC.pressing() << endl;
    if (BumperC.pressing() == 1)
      Motor1.spin(reverse, globalRpm, rpm);
    else
      Motor1.stop();
    vex::task::sleep(100);
  }
}

//make a square with sideLength
void square(double sideLength){
  cout << "square of " << sideLength << "cm..." << endl;
  for(int i = 0; i<3; i++){
    move(sideLength);
    turnAngle(90,track,wheelDiameter);
  }
  move(sideLength);
}

//make a six sided star with sideLength
void star(double sideLength){
  cout << "star of " << sideLength << "cm..." << endl;
  for(int i = 0; i<4; i++){
    move(sideLength);
    turnAngle(143,track,wheelDiameter);
  }
  move(sideLength);
}