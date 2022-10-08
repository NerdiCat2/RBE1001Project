// #include "main.h"
// #include "vex.h"
// #include <iostream>
// #include <math.h>

// // make a square with sideLength
// void square(double sideLength) {
//   std::cout << "square of " << sideLength << "cm..." << std::endl;
//   for (int i = 0; i < 3; i++) {
//     move(sideLength);
//     turnAngle(90);
//   }
//   move(sideLength);
// }

// // make a six sided star with sideLength
// void star(double sideLength) {
//   std::cout << "star of " << sideLength << "cm..." << std::endl;
//   for (int i = 0; i < 4; i++) {
//     move(sideLength);
//     turnAngle(143);
//   }
//   move(sideLength);
// }

// // drives in circle given radius and fraction of circle to drive
// void circle(double r, double outerRpm, double fracOfCircle) {
//   double innerC = ((r - (.5 * track)) * 2 * M_PI) * fracOfCircle;
//   double outerC = ((r + (.5 * track)) * 2 * M_PI) * fracOfCircle;
//   double innerD = distanceToDegree(innerC);
//   double outerD = distanceToDegree(outerC);
//   double innerRpm = innerD / (outerD * (1 / outerRpm));
//   cout << "Motor 1:  " << innerD << " degree, " << innerRpm << " rpm" << endl;
//   cout << "Motor 10: " << outerD << " degree, " << outerRpm << " rpm" << endl;
//   Motor1.rotateFor(innerD, deg, abs(int(innerRpm)), rpm, false);
//   Motor10.rotateFor(outerD, deg, abs(int(outerRpm)), rpm);
// }

// void maze() {
//   cout << "starting maze..." << endl;
//   circle(45.0, globalRpm, .25);
//   circle(-25.0, globalRpm, -.25);
//   double degree = distanceToDegree(12);
//   Motor1.rotateFor(degree, deg, globalRpm, rpm, false);
//   Motor10.rotateFor(degree, deg, globalRpm, rpm);
//   turnAngle(45);
//   move(40.0);
//   degree = distanceToDegree(21);
//   Motor1.rotateFor(-degree, deg, globalRpm, rpm);
//   Motor10.rotateFor(degree, deg, globalRpm, rpm);
//   move(-30.0);
// }

// Bumping code
// void bump() {
//   while (true) {
//     cout << BumperC.pressing() << endl;
//     if (BumperC.pressing() == 1)
//       Motor1.spin(reverse, globalRpm, rpm);
//     else
//       Motor1.stop();
//     vex::task::sleep(100);
//   }
// }



// Standoff distance from object
// void standOff(double cm, double k) {
//   Motor1.spin(fwd);
//   Motor10.spin(fwd);
//   while (true) {
//     cout << "distance: " << RangeFinderE.distance(distanceUnits::cm) << endl;
//     double diff = RangeFinderE.distance(distanceUnits::cm) - cm;
//     double turnSpeed = k * (diff);
//     Motor1.setVelocity(-turnSpeed, rpm);
//     Motor10.setVelocity(-turnSpeed, rpm);
//     vex::task::sleep(30);
//   }
// }

// void wallStandOff(double cm, double k) {
//   Motor1.spin(fwd);
//   Motor10.spin(fwd);
//   while (true) {
//     cout << "distance: " << RangeFinderE.distance(distanceUnits::cm) << endl;
//     double diff = RangeFinderE.distance(distanceUnits::cm) - cm;
//     double turnSpeed = k * (diff);
//     Motor1.setVelocity(-100 - turnSpeed, rpm);
//     Motor10.setVelocity(-100 + turnSpeed, rpm);
//     vex::task::sleep(30);
//   }
// }

// void DetectObject() {
//   // takes a snapshot and searches for sig_s1
//   // you’ll want to use the signature that you defined above
//   vision_1.takeSnapshot(vision_1__BLUE_BALL);
//   // print the coordinates of the center of the object
//   // printf stands for ’print formatted’ and the %d tells it to print
//   // in integer format. The syntax can be found in online tutorials.
//   if (vision_1.objectCount > 0) {
//     printf("x: %d, y %d\n", vision_1.largestObject.centerX,
//            vision_1.largestObject.centerY);
//   }
// }

// void objectAngle() {
//   int x = 155;
//   Motor1.spin(fwd);
//   Motor10.spin(fwd);
//   Motor1.setVelocity(0, rpm);
//   Motor10.setVelocity(0, rpm);
//   cout << "finding object" << endl;
//   int width;
//   while (true) {
//     vision_1.takeSnapshot(vision_1__RED_BALL);
//     if (vision_1.objectCount > 0) {
//       x = vision_1.largestObject.centerX;
//       width = vision_1.largestObject.width;
//       printf("x: %d\n", x);
//       printf("width: %d\n", width);
//       cout << "found object" << endl;
//     } else {
//       cout << "no object detected..." << endl;
//       width = 60;
//       x = 155;
//     }
//     double diff = x - 155;
//     double widthDist = 60 - width;
//     double offsetSpeed = widthDist * 2;
//     double turnSpeed = 1.5 * (diff);
//     Motor1.setVelocity((-offsetSpeed - turnSpeed), rpm);
//     Motor10.setVelocity((-offsetSpeed + turnSpeed), rpm);
//     vex::task::sleep(30);
//   }
// }