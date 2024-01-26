#include "../../include/organiz/devices.h"

//PORTS ARE BAD


//motor initialization
pros::Motor kicker(-21);
pros::Motor flywheel(11);
pros::Motor intake(6); //R1 in R2 out
pros::ADIDigitalOut front_wings('H', false);
pros::ADIDigitalOut back_left_wing('G', false);
pros::ADIDigitalOut back_right_wing('E', false);
pros::ADIDigitalOut endgame('F', false);
pros::Distance kickerdistance('D');
pros::IMU inertial(19);

// Chassis constructor
Drive chassis(
	// Left Chassis Ports (negative port will reverse it!)
	//   the first port is the sensored/middle port (when trackers are not used!)
	{ -2, -16, -1}

	// Right Chassis Ports (negative port will reverse it!)
	//   the first port is the sensored/middle port (when trackers are not used!)
	, { 9, 20, 10}

	// IMU Port
	, 18

	// Wheel Diameter (Remember, 4" wheels are actually 4.125!)pros
	//    (or tracking wheel diameter)
	, 2.75

	// Cartridge RPM
	//   (or tick per rotation if using tracking wheels)
	, 600

	// External Gear Ratio (MUST BE DECIMAL)
	//    (or gear ratio of tracking wheel)
	// eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
	// eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
	, 1.3333

	// Uncomment if using tracking wheels
	/*
	// Left Tracking Wheel Ports (negative port will reverse it!)
	// ,{1, 2} // 3 wire encoder
	// ,8 // Rotation sensor

	// Right Tracking Wheel Ports (negative port will reverse it!)
	// ,{-3, -4} // 3 wire encoder
	// ,-9 // Rotation sensor
	*/

	// Uncomment if tracking wheels are plugged into a 3 wire expander
	// 3 Wire Port Expander Smart Port
	// ,1
);

