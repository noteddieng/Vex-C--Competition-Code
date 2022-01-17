#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors

// Drive motor configuration
motor BL = motor(PORT1, ratio18_1, false);
motor FL = motor(PORT2, ratio18_1, false);
motor BR = motor(PORT3, ratio18_1, false);
motor FR = motor(PORT4, ratio18_1, false);

// Front arm motor configuration
motor FAL = motor(PORT5, ratio18_1, false);
motor FAR = motor(PORT6, ratio18_1, false);

// Back arm motor configuration
motor BAL = motor(PORT7, ratio18_1, false);
motor BAR = motor(PORT8, ratio18_1, false);

/*vex-vision-config:begin*/
signature vision_1__MOBILE_GOAL = signature (1, -1, 2791, 1395, -4709, -2539, -3624, 1.6, 0);
signature vision_1__RED_GOAL = signature (2, 4749, 9831, 7290, -1333, -545, -939, 1.5, 1);
signature vision_1__BLUE_GOAL = signature (3, -2493, -1105, -1799, 4205, 9217, 6711, 1.3, 0);
code vision_1__MOBILE_GOAL = code (vision_1__(3, vision_1__1213, vision_1__3133, vision_1__2173, vision_1__-4189, vision_1__-3217, vision_1__-3703, vision_1__RED_GOAL, vision_1__0) );
code vision_1__RED_GOAL = code (vision_1__(1, vision_1__6667, vision_1__11049, vision_1__8858, vision_1__-1275, vision_1__-569, vision_1__-922, vision_1__RED_GOAL, vision_1__0) );
code vision_1__BLUE_GOAL = code (vision_1__(2, vision_1__-2731, vision_1__-439, vision_1__-1585, vision_1__2825, vision_1__10271, vision_1__6548, vision_1__0.9, vision_1__0) );
vision vision_1 = vision (PORT11, 82, vision_1__MOBILE_GOAL, vision_1__RED_GOAL, vision_1__BLUE_GOAL);

/*vex-vision-config:end*/

// Pneumatics configuration
digital_out airbender = digital_out(Brain.ThreeWirePort.A);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}