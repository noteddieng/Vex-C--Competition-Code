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
motor BAL = motor(PORT6, ratio18_1, false);
motor FAR = motor(PORT7, ratio18_1, false);
motor FAL = motor(PORT8, ratio18_1, true);
/*vex-vision-config:begin*/
vision vision_1 = vision (PORT11, 50);
/*vex-vision-config:end*/
motor FC = motor(PORT5, ratio36_1, false);

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