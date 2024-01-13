#include "../include/main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 110; // This is 110 / 127 (around 87 % of max speed).We don't suggest making this 127.
							 // If this is 127 and the robot tries to heading correct, it's only correcting by
							 // making one side slower.  When this is 87%, it's correcting by making one side
							 //faster and one side slower, giving better heading correction. 

const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;



///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(5, 5);
  chassis.set_pid_constants(&chassis.headingPID, 0.5, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.6, 0, 3, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.6, 0, 3, 0);
  chassis.set_pid_constants(&chassis.turnPID, 1, 0.0025, 38, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void jerk_constants() {
	chassis.set_slew_min_power(90, 90);
	chassis.set_slew_distance(20, 20);
	chassis.set_pid_constants(&chassis.headingPID, 6, 0, 20, 0);
	chassis.set_pid_constants(&chassis.forward_drivePID, 0.65, 0, 3.25, 0);
	chassis.set_pid_constants(&chassis.backward_drivePID, 0.65, 0, 3.25, 0);
	chassis.set_pid_constants(&chassis.turnPID, 5, 0.002, 38, 15);
	chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void two_mogo_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.0035, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

void exit_condition_defaults() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

void modified_exit_condition() {
  chassis.set_exit_condition(chassis.turn_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3, 500, 7, 500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 80, 50, 300, 150, 500, 500);
}

///
// Auto that tests everything
///
void test_code() {


	chassis.set_drive_pid(12, DRIVE_SPEED, true);
	chassis.wait_drive();

	chassis.set_drive_pid(-12, DRIVE_SPEED, true);

}

///
// Close Side Auton (leftside)
///
void close_side() {
	default_constants();
	chassis.set_angle(90);

	chassis.set_drive_pid(30, DRIVE_SPEED, true);
	chassis.wait_drive();

	intake.move(127);

	chassis.set_drive_pid(-30, DRIVE_SPEED, true);
	chassis.wait_drive();
	intake.brake();

	chassis.set_turn_pid(135, TURN_SPEED);
	chassis.wait_drive();

	chassis.set_drive_pid(-24, DRIVE_SPEED);
	chassis.wait_drive();

}

///
// Close Side No Bar only triballs (leftside)
///
void close_side_nobar() {
	default_constants();

	
}

///
// Far Side Auton (rightside)
///
void far_side() {
	default_constants();

}

void far_side_nobar() {
	default_constants();

}



///
// Drive Example
///
void drive_example() {
  // The first parameter is target inches
  // The second parameter is max speed the robot will drive at
  // The third parameter is a boolean (true or false) for enabling/disabling a slew at the start of drive motions
  // for slew, only enable it when the drive distance is greater then the slew distance + a few inches


  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(12, DRIVE_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED);
  chassis.wait_drive();
}


void skills_code() {
	//drive forward and set up in match load area
	chassis.set_drive_pid(10, DRIVE_SPEED);
	chassis.wait_drive();

	chassis.set_swing_pid(RIGHT_SWING, -115, TURN_SPEED);
	chassis.wait_drive();

	chassis.set_drive_pid(7, DRIVE_SPEED);
	chassis.wait_drive();

	//flywheel.move_velocity(300);
	//pros::delay(35000);
	//match loads done

	chassis.set_drive_pid(-10, DRIVE_SPEED);
	chassis.wait_drive();

	//flywheel.brake();

	chassis.set_turn_pid(0, TURN_SPEED);
	chassis.wait_until(1);

	chassis.set_drive_pid(-10, DRIVE_SPEED);
	chassis.wait_drive();

	chassis.set_swing_pid(RIGHT_SWING, 90, SWING_SPEED);
	chassis.wait_until(89);

	chassis.set_drive_pid(90, DRIVE_SPEED, true);
	chassis.wait_until(89);

	chassis.set_turn_pid(0, TURN_SPEED);
	chassis.wait_drive();

	chassis.set_drive_pid(10, DRIVE_SPEED);
	chassis.wait_drive();

	chassis.set_swing_pid(RIGHT_SWING, -50, SWING_SPEED);
	chassis.wait_until(-44);

	chassis.set_drive_pid(24, DRIVE_SPEED);
	chassis.wait_drive();

	chassis.set_swing_pid(LEFT_SWING, 0, SWING_SPEED);
	chassis.wait_drive();

	chassis.set_drive_pid(7, DRIVE_SPEED + 10);
	chassis.wait_drive();

	chassis.set_swing_pid(LEFT_SWING, 90, SWING_SPEED);
	chassis.wait_drive();

	front_wings(OUT);

	chassis.set_drive_pid(10, DRIVE_SPEED);
	chassis.wait_drive();

	chassis.set_drive_pid(-24, DRIVE_SPEED);
	chassis.wait_drive();

	front_wings(IN);

	chassis.set_swing_pid(RIGHT_SWING, 180, SWING_SPEED);
	chassis.wait_drive();

	chassis.set_drive_pid(-15, DRIVE_SPEED);
	chassis.wait_drive();

	chassis.set_swing_pid(LEFT_SWING, 135, SWING_SPEED);
	chassis.wait_drive();

	front_wings(OUT);

	chassis.set_drive_pid(15, DRIVE_SPEED);
	chassis.wait_drive();

	front_wings(IN);

	chassis.set_drive_pid(-10, DRIVE_SPEED);
	chassis.wait_drive();


}

///
// Turn Example
///
void turn_example() {
  // The first parameter is target degrees
  // The second parameter is max speed the robot will drive at


  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
}



///
// Combining Turn + Drive
///
void drive_and_turn() {
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_drive();
}



///
// Wait Until and Changing Max Speed
///
void wait_until_change_speed() {
  // wait_until will wait until the robot gets to a desired position


  // When the robot gets to 6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // When the robot gets to -6 inches, the robot will travel the remaining distance at a max speed of 40
  chassis.set_drive_pid(-24, DRIVE_SPEED, true);
  chassis.wait_until(-6);
  chassis.set_max_speed(40); // After driving 6 inches at DRIVE_SPEED, the robot will go the remaining distance at 40 speed
  chassis.wait_drive();
}



///
// Swing Example
///
void swing_example() {
  // The first parameter is ez::LEFT_SWING or ez::RIGHT_SWING
  // The second parameter is target degrees
  // The third parameter is speed of the moving side of the drive


  chassis.set_swing_pid(ez::LEFT_SWING, 45, SWING_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(24, DRIVE_SPEED, true);
  chassis.wait_until(12);

  chassis.set_swing_pid(ez::RIGHT_SWING, 0, SWING_SPEED);
  chassis.wait_drive();
}





void jerk(int attempts) {
	jerk_constants();
	for (int i = 0; i <= attempts; i++) {
		chassis.set_drive_pid(-7, 127, false);
		chassis.wait_until(0.5);
		chassis.set_drive_pid(7, 127, false);
		chassis.wait_until(0.5);
	}
	default_constants();
}

///
// Interference example
///
void tug (int attempts) {
  for (int i=0; i<attempts-1; i++) {
	// Attempt to drive backwards
	printf("i - %i", i);
	chassis.set_drive_pid(-12, 127);
	chassis.wait_drive();

	// If failsafed...
	if (chassis.interfered) {
	  chassis.reset_drive_sensor();
	  chassis.set_drive_pid(-2, 20);
	  pros::delay(1000);
	}
	// If robot successfully drove back, return
	else {
	  return;
	}
  }
}

// If there is no interference, robot will drive forward and turn 90 degrees. 
// If interfered, robot will drive forward and then attempt to drive backwards. 
void interfered_example() {
 chassis.set_drive_pid(24, DRIVE_SPEED, true);
 chassis.wait_drive();

 if (chassis.interfered) {
   tug(3);
   return;
 }

 chassis.set_turn_pid(90, TURN_SPEED);
 chassis.wait_drive();
}



// . . .
// Make your own autonomous functions here!
// . . .