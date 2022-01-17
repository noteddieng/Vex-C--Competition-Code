/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Sun Jan 16 2022                                           */
/*    Description:  Bellevue Competition Code                                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "robot-config.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// vision_1             vision        11              
// airbender            digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

// A global instance of competition
competition Competition;

// Variables
float WHEEL_CIRCUMFERENCE = 4.125 * 3.1416;
float SLIPPAGE = 0.5;
int GEAR_RATIO = 1;
int DEFAULT_drive_pwr = 50;


// ------------------ convert inches to deg ---------------------- // 
float inches_to_deg(float inches){

    float inchesPerDegree = float(WHEEL_CIRCUMFERENCE) / float(360.0);
    float degrees = float(inches) / float(inchesPerDegree);

    float deg_converted = degrees * GEAR_RATIO;

    return deg_converted;
};

int number_ = inches_to_deg(50);

// ------------------ -------------------- ---------------------- // 
void moveFWD(float inches, int drive_pwr) {
    
    float inchesPerDegree = float(WHEEL_CIRCUMFERENCE) / float(360.0);
    float degrees = float(inches) / float(inchesPerDegree);

    float deg_converted = degrees * GEAR_RATIO;

    // Degree values are left as positive so we move forward
    BL.spinFor(deg_converted, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
    FL.spinFor(deg_converted, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
    BR.spinFor(deg_converted, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
    FR.spinFor(deg_converted, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);

};

void moveREV(float inches, int drive_pwr) {
    
    float inchesPerDegree = float(WHEEL_CIRCUMFERENCE) / float(360.0);
    float degrees = float(inches) / float(inchesPerDegree);

    float deg_converted = degrees * GEAR_RATIO;

    // Changed the degrees to negative values so that we can move backwards
    BL.spinFor(-deg_converted, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
    FL.spinFor(-deg_converted, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
    BR.spinFor(-deg_converted, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
    FR.spinFor(-deg_converted, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);

};

void turnRight(float degrees, int drive_pwr){

    BL.spinFor(degrees, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
    FL.spinFor(degrees, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
    BR.spinFor(-degrees, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
    FR.spinFor(-degrees, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
};

void turnLeft(float degrees, int drive_pwr){
  
    BL.spinFor(-degrees, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
    FL.spinFor(-degrees, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
    BR.spinFor(degrees, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
    FR.spinFor(degrees, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
};

void swerveLeft(float degrees, int drive_pwr){
  BR.spinFor(degrees, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
  FR.spinFor(degrees, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
}

void swerveRight(float degrees, int drive_pwr){
  BL.spinFor(degrees, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
  FL.spinFor(degrees, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
}

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Set braketypes
  BL.setStopping(brakeType::coast);
  FL.setStopping(brakeType::coast);
  BR.setStopping(brakeType::coast);
  FR.setStopping(brakeType::coast);
  FAL.setStopping(brakeType::hold);
  FAR.setStopping(brakeType::hold);
  BAL.setStopping(brakeType::hold);
  BAR.setStopping(brakeType::hold);
};


void autonomous(void) {
  
}



void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
