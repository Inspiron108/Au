#include "main.h"
MotorGroup catapult({8,-9});
Motor spinner(20);
pros::Controller master(pros::E_CONTROLLER_MASTER);
MotorGroup LeftSide({1,2});
MotorGroup RightSide({3,4});

auto catatrigger = ADIButton('A', false);

void cata(int trigger = false){

while(!catatrigger.isPressed()){
catapult.moveVoltage(12000);
}
if(trigger == true){
    catapult.moveAbsolute(100,300); 
    trigger = false;
}
}






std::shared_ptr<OdomChassisController> myChassis = ChassisControllerBuilder()
    .withMotors({1,2}, {3,4}) 
    .withGains(
        {0.001, 0, 0.0001}, // Distance controller gains
        {0.001, 0, 0.0001}, // Turn controller gains
        {0.001, 0, 0.0001}  // Angle controller gains (helps drive straight)
    )
    // green gearset, 4 inch wheel diameter, 11.5 inch wheel track
    .withDimensions(AbstractMotor::gearset::green, {{4_in, 11_in}, imev5GreenTPR})
    .withOdometry() // use the same scales as the chassis (above)
    .buildOdometry(); // build an odometry chassis




void initialize() {


//just work
}


void disabled() {}


void competition_initialize() {}




void autonomous() {

myChassis->setState({0_in, 0_in, 0_deg});
myChassis->driveToPoint({1_ft, 1_ft});
myChassis->turnToAngle(90_deg);
myChassis->turnToPoint({5_ft, 0_ft});
myChassis->driveToPoint({5_ft, 2_ft});






}


void opcontrol() {

	while (true) {

		int left = master.get_analog(ANALOG_LEFT_Y);
		int right = master.get_analog(ANALOG_RIGHT_Y);		
		LeftSide.moveVelocity(left);
		RightSide.moveVelocity(right);

		pros::delay(20);
	}
}
