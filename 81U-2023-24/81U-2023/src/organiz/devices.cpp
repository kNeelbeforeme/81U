#include "../../include/organiz/devices.h"

//PORTS 2,3,4 ARE BAD


//motor initialization
pros::Motor flywheel (11);
pros::Motor intake(12);
pros::ADIDigitalOut right_wing('A', false);
pros::ADIDigitalOut left_wing('B', false);
pros::ADIDigitalOut endgame('H', true);
pros::IMU inertial(20);

// Chassis constructor
Drive chassis(
	// Left Chassis Ports (negative port will reverse it!)
	//   the first port is the sensored port (when trackers are not used!)
	{ -10, -9, -8 }

	// Right Chassis Ports (negative port will reverse it!)
	//   the first port is the sensored port (when trackers are not used!)
	, { 1, 2, 3 }

	// IMU Port
	, 19

	// Wheel Diameter (Remember, 4" wheels are actually 4.125!)pros
	//    (or tracking wheel diameter)
	, 4.125

	// Cartridge RPM
	//   (or tick per rotation if using tracking wheels)
	, 600

	// External Gear Ratio (MUST BE DECIMAL)
	//    (or gear ratio of tracking wheel)
	// eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
	// eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
	, 1.75

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

