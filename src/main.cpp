/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Sun Jan 16 2022                                           */
/*    Description:  Bellevue Competition Code                                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// vision_1             vision        11              
// airbender            digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here




void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  BL.setStopping(brakeType::coast);
  FL.setStopping(brakeType::coast);
  BR.setStopping(brakeType::coast);
  FR.setStopping(brakeType::coast);
  FAL.setStopping(brakeType::hold);
  FAR.setStopping(brakeType::hold);
  BAL.setStopping(brakeType::hold);
  BAR.setStopping(brakeType::hold);
  
}



void autonomous(void) {
  BL.spin(forward);
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
