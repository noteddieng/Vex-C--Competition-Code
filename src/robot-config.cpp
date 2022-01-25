#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor FR = motor(PORT1, ratio18_1, true);
motor FL = motor(PORT2, ratio18_1, false);
motor BR = motor(PORT3, ratio18_1, true);
motor BL = motor(PORT4, ratio18_1, false);
motor BAL = motor(PORT6, ratio36_1, true);
motor FAR = motor(PORT7, ratio36_1, true);
motor FAL = motor(PORT8, ratio36_1, false);
/*vex-vision-config:begin*/
signature vision_1__MOBILE_GOAL = signature (1, 255, 1057, 656, -2595, -1371, -1983, 2.5, 0);
signature vision_1__RED_GOAL = signature (2, 4647, 7711, 6179, 445, 1431, 938, 2.5, 0);
signature vision_1__BLUE_GOAL = signature (3, -2941, -1869, -2405, 6225, 12529, 9377, 1.4, 0);
vision vision_1 = vision (PORT11, 50, vision_1__MOBILE_GOAL, vision_1__RED_GOAL, vision_1__BLUE_GOAL);
/*vex-vision-config:end*/
motor FC = motor(PORT5, ratio36_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}