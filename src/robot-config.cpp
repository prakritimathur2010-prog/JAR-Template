#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor Belt = motor(PORT4, ratio18_1, false);
motor Intake = motor(PORT3, ratio18_1, false);
motor LeftDriveSmart = motor(PORT1, ratio18_1, false);
motor RightDriveSmart = motor(PORT2, ratio18_1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
controller Controller1 = controller();

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  
}

// following functions are for intake and outtake, here so they can be used in autonomous and driver control
void intake( void ) {
    Belt.spin(fwd, 50, percent);
    Intake.spin(fwd, 50, percent);
}

void outtake( void ) {
    Intake.spin(reverse, 50, percent);
    Belt.spin(reverse, 50, percent);
}

void stop ( void ) {
    Intake.stop(hold);
    Belt.stop(hold);
}
