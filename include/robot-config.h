using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern controller Controller1;
extern motor FR;
extern motor FL;
extern motor BR;
extern motor BL;
extern motor BAL;
extern motor FAR;
extern motor FAL;
extern signature vision_1__SIG_1;
extern signature vision_1__SIG_2;
extern signature vision_1__SIG_3;
extern signature vision_1__SIG_4;
extern signature vision_1__SIG_5;
extern signature vision_1__SIG_6;
extern signature vision_1__SIG_7;
extern vision vision_1;
extern motor FC;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );