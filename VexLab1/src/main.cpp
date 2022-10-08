// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LineTrackerA         line          A               
// LineTrackerB         line          B               
// Right_Drive          motor_group   2, 10           
// Left_Drive           motor_group   1, 9            
// doors                motor_group   3, 8            
// arm                  motor         5               
// Push                 motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LineTrackerA         line          A               
// LineTrackerB         line          B               
// Right_Drive          motor_group   2, 10           
// LEFT_Drive           motor_group   1, 9            
// doors                motor_group   3, 8            
// arm                  motor         5               
// Push                 motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LineTrackerA         line          A               
// LineTrackerB         line          B               
// RIght                motor_group   2, 10           
// LEFT_Drive           motor_group   1, 9            
// doors                motor_group   3, 8            
// arm                  motor         5               
// Push                 motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LineTrackerA         line          A               
// LineTrackerB         line          B               
// RIght                motor_group   2, 10           
// LEFT                 motor_group   1, 9            
// doors                motor_group   3, 8            
// arm                  motor         5               
// Push                 motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LineTrackerA         line          A               
// LineTrackerB         line          B               
// Motor10              motor_group   2, 10           
// LEFT                 motor_group   1, 9            
// doors                motor_group   3, 8            
// arm                  motor         5               
// Push                 motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LineTrackerA         line          A               
// LineTrackerB         line          B               
// Motor10              motor_group   2, 10           
// Motor1               motor_group   1, 9            
// doors                motor_group   3, 8            
// arm                  motor         5               
// Push                 motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LineTrackerA         line          A               
// LineTrackerB         line          B               
// Motor10              motor_group   2, 10           
// Motor1               motor_group   1, 9            
// doors                motor_group   3, 8            
// arm                  motor         5               
// Motor7               motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LineTrackerA         line          A               
// LineTrackerB         line          B               
// Motor10              motor_group   2, 10           
// Motor1               motor_group   1, 9            
// doors                motor_group   3, 8            
// arm                  motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LineTrackerA         line          A               
// LineTrackerB         line          B               
// Motor10              motor_group   2, 10           
// Motor1               motor_group   1, 9            
// doors                motor_group   3, 8            
// arm                  motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LineTrackerA         line          A               
// LineTrackerB         line          B               
// Motor10              motor_group   2, 10           
// Motor1               motor_group   1, 9            
// doors                motor_group   3, 8            
// arm                  motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LineTrackerA         line          A               
// LineTrackerB         line          B               
// Motor10              motor_group   2, 10           
// Motor1               motor_group   1, 9            
// doors                motor_group   3, 8            
// arm                  motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "main.h"
#include "vex.h"
#include <iostream>
#include <math.h>

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LineTrackerA         line          A
// LineTrackerB         line          B
// Motor10              motor_group   2, 10
// Motor1               motor_group   1, 9
// doors                motor_group   6, 8
// arm                  motor         5
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace std;

double wheelDiameter = 10.16;
double track = 28.4;
int globalRpm = 100;

int main() {
  vexcodeInit();
  cout << "starting..." << endl;
  // demoDay();
  // armUp(3600);
  lineFollow(0.8);
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
  double degree = distanceToDegree(cm);
  Motor1.rotateFor(degree, deg, globalRpm, rpm, false);
  Motor10.rotateFor(-degree, deg, globalRpm, rpm);
}

// Changes Distance in cm to degrees
double distanceToDegree(double cm) {
  return (cm * 360 * 5) / (wheelDiameter * M_PI);
}

// Proportional Control
// turn speed = k*(sens1-sens2)
void lineFollow(double k) {
  double turnSpeed;
  vex::task::sleep(1000);
  Motor1.spin(fwd);
  Motor10.spin(fwd);
  while (true) {
    turnSpeed = k * (LineTrackerA.reflectivity() - LineTrackerB.reflectivity());
    cout << LineTrackerA.reflectivity(pct) << "   "
         << LineTrackerB.reflectivity(pct) << "turn speed: " << turnSpeed
         << endl;
    Motor1.setVelocity(100 + turnSpeed, rpm);
    Motor10.setVelocity(100 - turnSpeed, rpm);
    vex::task::sleep(30);
  }
}

void openDoors() { doors.rotateFor(-105, deg, 60, rpm); }

void closeDoors() { doors.rotateFor(115, deg, 60, rpm); }

void armUp(double d) { arm.rotateFor(d, deg, globalRpm, rpm); }

void demoDay() {
  move(-35.0);
  turnAngle(-90);
  armUp(-3600);
  openDoors();
  move(100.0);
}