
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
int globalRpm = 200;

int main() {
  vexcodeInit();
  cout << "starting..." << endl;
  star(50.8);
  cout << "end" << endl;
}

// Given a target distance, drive straight for the given distance.
void move(double cm) {
  cout << "moving " << cm << "cm..." << endl;
  double degree = distanceToDegree(cm);
  Motor1.rotateFor(degree, deg, globalRpm, rpm, false);
  Motor10.rotateFor(degree, deg, globalRpm, rpm);
}

// Given a target angle turn the BaseBot a specified angle.
void turnAngle(double angle) {
  cout << "turning " << angle << "degree..." << endl;
  double cm = (track * M_PI * angle) / 360;
  cout << "turning " << cm << "cm..." << endl;
  double degree = distanceToDegree(cm);
  Motor1.rotateFor(degree, deg, globalRpm, rpm, false);
  Motor10.rotateFor(-degree, deg, globalRpm, rpm);
}

// Changes Distance in cm to degrees
double distanceToDegree(double cm) {
  return (cm * 360 * 5) / (wheelDiameter * M_PI);
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
    turnAngle(90);
  }
  move(sideLength);
}

//make a six sided star with sideLength
void star(double sideLength){
  cout << "star of " << sideLength << "cm..." << endl;
  for(int i = 0; i<4; i++){
    move(sideLength);
    turnAngle(143);
  }
  move(sideLength);
}

//drives in circle given circumference and fraction of circle to drive
void circle(double c,int outerRpm,double fracOfCircle){
  double innerC =(c - (.5*track))*fracOfCircle;
  double outerC =(c + (.5*track))*fracOfCircle;
  double innerD = distanceToDegree(innerC);
  double outerD =  distanceToDegree(outerC);
   
  double innerRpm = innerD*(outerD *(1/outerRpm));

  Motor1.rotateFor(innerD, deg, innerRpm, rpm, false);
  Motor10.rotateFor(outerD, deg, outerRpm, rpm);
}