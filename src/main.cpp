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
// Controller1          controller                    
// FR                   motor         1               
// FL                   motor         2               
// BR                   motor         3               
// BL                   motor         4               
// BAL                  motor         6               
// FAR                  motor         7               
// FAL                  motor         8               
// vision_1             vision        11              
// FC                   motor         5               
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
};

void swerveRight(float degrees, int drive_pwr){
  BL.spinFor(degrees, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
  FL.spinFor(degrees, rotationUnits::deg, drive_pwr, velocityUnits::pct, false);
};

void FrontArmUp(float degrees, int pwr){
  FAL.spinFor(degrees, rotationUnits::deg, pwr, velocityUnits::pct, false);
  FAR.spinFor(degrees, rotationUnits::deg, pwr, velocityUnits::pct, false);

};

void FrontArmDown(float degrees, int pwr){
  FAL.spinFor(-degrees, rotationUnits::deg, pwr, velocityUnits::pct, false);
  FAR.spinFor(-degrees, rotationUnits::deg, pwr, velocityUnits::pct, false);
};

void frontClawDown(float degrees, int pwr){
  FC.spinFor(-degrees, rotationUnits::deg, pwr, velocityUnits::pct, false);
};

void frontClawUp(float degrees, int pwr){
  FC.spinFor(degrees, rotationUnits::deg, pwr, velocityUnits::pct, false);
}

void BackArmUp(float degrees, int pwr){
  BAL.spinFor(degrees, rotationUnits::deg, pwr, velocityUnits::pct, false);
};

void BackArmDown(float degrees, int pwr){
  BAL.spinFor(-degrees, rotationUnits::deg, pwr, velocityUnits::pct, false);
};






// Vision code stuf

bool turnToCenterBlue(){

  int FOV = 158;
  int X_BIAS = 20;
  while(true){
    vision_1.takeSnapshot(vision_1__BLUE_GOAL);

    if(vision_1.largestObject.exists){
      
      if(vision_1.largestObject.centerX > FOV + X_BIAS){
        BL.spin(directionType::fwd, 50, velocityUnits::pct);
        FL.spin(directionType::fwd, 50, velocityUnits::pct);
        FR.spin(directionType::rev, 50, velocityUnits::pct);
        BR.spin(directionType::rev, 50, velocityUnits::pct);

        return true;


      } else if(vision_1.largestObject.centerX < FOV + X_BIAS){
        BL.spin(directionType::rev, 50, velocityUnits::pct);
        FL.spin(directionType::rev, 50, velocityUnits::pct);
        BR.spin(directionType::fwd, 50, velocityUnits::pct);
        FR.spin(directionType::fwd, 50, velocityUnits::pct);

        return true;

      }
    }
    else{
      BL.stop(brakeType::coast);
      BR.stop(brakeType::coast);
      FL.stop(brakeType::coast);
      FR.stop(brakeType::coast);

    }
    wait(20, msec);
  }
  
}

bool forwardToScaleBlue(){
  int A_THRESH = 10;

  while(true){
    vision_1.takeSnapshot(vision_1__BLUE_GOAL);

    int object_area = vision_1.largestObject.width * vision_1.largestObject.height;

    if(vision_1.largestObject.exists){
      if(object_area < A_THRESH){
        FL.spin(directionType::fwd, 50, velocityUnits::pct);
        BL.spin(directionType::fwd, 50, velocityUnits::pct);
        FR.spin(directionType::fwd, 50, velocityUnits::pct);
        BR.spin(directionType::fwd, 50, velocityUnits::pct);

        return true;
      }
      else if(object_area > A_THRESH){
        FL.stop(brakeType::coast);
        BL.stop(brakeType::coast);
        FR.stop(brakeType::coast);
        BR.stop(brakeType::coast);

      }
    }
    else{
      BR.stop(brakeType::coast);
      BL.stop(brakeType::coast);
      FR.stop(brakeType::coast);
      FL.stop(brakeType::coast);
    }
  }
}

void pickUpBlueGoal(){
  while(true){

    vision_1.takeSnapshot(vision_1__BLUE_GOAL);

    turnToCenterBlue();
    forwardToScaleBlue();

    int object_area = vision_1.largestObject.width * vision_1.largestObject.height;

    if(vision_1.largestObject.exists){

      if(turnToCenterBlue() == true || forwardToScaleBlue() == true){
        frontClawDown(180, 100);

        FrontArmUp(90, 75);
      }
      else if(turnToCenterBlue() != true || forwardToScaleBlue() != true){
        turnToCenterBlue();

        if(turnToCenterBlue() == true){

          forwardToScaleBlue();

          if(forwardToScaleBlue() == true){
            frontClawDown(180, 100);

            FrontArmUp(90, 75);
          }
        }
      }
      else if(turnToCenterBlue() == true || forwardToScaleBlue() != true){
        forwardToScaleBlue();
        if(forwardToScaleBlue() == true){

          frontClawDown(180, 100);

          FrontArmUp(90, 75);
        }
      }
    else if(turnToCenterBlue() != true || forwardToScaleBlue() == true){
      turnToCenterBlue();

      if(turnToCenterBlue() == true){
        frontClawDown(180, 100);
        FrontArmUp(90, 75);
      }
    }

    }
    else{
      BL.stop(brakeType::coast);
      FL.stop(brakeType::coast);
      BR.stop(brakeType::coast);
      FR.stop(brakeType::coast);
    }
  }
}


void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Set braketypes

  
};


void autonomous(void) {

  moveFWD(10, 75);
  BackArmDown(180, 100);
  turnToCenterBlue();
  forwardToScaleBlue();
  pickUpBlueGoal();
  turnLeft(90, 50);
  FrontArmDown(90, 50);
  frontClawUp(180, 100);
  turnRight(90, 50);
  moveREV(10, 75);
  
}



void usercontrol(void) {
  // User control code here, inside the loop
  while (true) {

    
    FR.spin(directionType::fwd, (Controller1.Axis2.value() - Controller1.Axis1.value()) / 2, velocityUnits::pct);
    BR.spin(directionType::fwd, (Controller1.Axis2.value() - Controller1.Axis1.value()) / 2, velocityUnits::pct);
    BL.spin(directionType::fwd, (Controller1.Axis4.value() + Controller1.Axis3.value() ) / 2, velocityUnits::pct);
    FL.spin(directionType::fwd, (Controller1.Axis4.value() + Controller1.Axis3.value()) / 2, velocityUnits::pct);


  if(Controller1.ButtonUp.pressing()){
      FAR.spin(directionType::fwd, 100, velocityUnits::pct);
      FAL.spin(directionType::fwd, 100, velocityUnits::pct);
  }
  else if(Controller1.ButtonDown.pressing()){
      FAL.spin(directionType::rev, 100, velocityUnits::pct);
      FAR.spin(directionType::rev, 100, velocityUnits::pct);
  }
  else{
    FAL.stop(brakeType::hold);
    FAR.stop(brakeType::hold);
  }

  if(Controller1.ButtonX.pressing()){
      
      BAL.spin(directionType::fwd, 100, velocityUnits::pct);
  }
  else if(Controller1.ButtonB.pressing()){
      
      BAL.spin(directionType::rev, 100, velocityUnits::pct);
  }
  else{
    
    BAL.stop(brakeType::hold);

  }
  if(Controller1.ButtonR2.pressing()){
      FC.spin(directionType::rev, 100, velocityUnits::pct);

  }
  else if(Controller1.ButtonR1.pressing()){
     FC.spin(directionType::fwd, 100, velocityUnits::pct);
  }
  else{
    FC.stop(brakeType::hold);
  }

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
