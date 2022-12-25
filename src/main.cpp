#include "main.h"



std::shared_ptr<OdomChassisController> myChassis = ChassisControllerBuilder()
    .withMotors({1,2}, {3,4}) // left motor is 1, right motor is 2 (reversed)
    .withGains(
        {0.001, 0, 0.0001}, // Distance controller gains
        {0.001, 0, 0.0001}, // Turn controller gains
        {0.001, 0, 0.0001}  // Angle controller gains (helps drive straight)
    )
    // green gearset, 4 inch wheel diameter, 11.5 inch wheel track
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11.5_in}, imev5GreenTPR})
    .withOdometry() // use the same scales as the chassis (above)
    .buildOdometry(); // build an odometry chassis




void initialize() {


//just work
}


void disabled() {}


void competition_initialize() {}




void autonomous() {


myChassis->driveToPoint({1_ft, 1_ft});







}


void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);
	MotorGroup LeftSide({1,2});
	MotorGroup RightSide({3,4});

	while (true) {

		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);		
		LeftSide.moveVelocity(left);
		RightSide.moveVelocity(right);

		pros::delay(20);
	}
}
