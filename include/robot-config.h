using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern motor BL;
extern motor BR;
extern motor FR;
extern motor FL;
extern motor FAL;
extern motor BAL;
extern motor FAR;
extern motor BAR;
extern signature vision_1__MOBILE_GOAL;
extern signature vision_1__RED_GOAL;
extern signature vision_1__BLUE_GOAL;
extern signature vision_1__SIG_4;
extern signature vision_1__SIG_5;
extern signature vision_1__SIG_6;
extern signature vision_1__SIG_7;
extern vision vision_1;
extern digital_out airbender;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );