#include "../include/main.h"
#include <string>


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////




bool is_skills = false;
static void toggle_skills() {
	is_skills = !is_skills;
	pros::lcd::clear_line(4);
	if (is_skills) {
		pros::lcd::set_text(4, "Sunai");
	}
	else {
		pros::lcd::set_text(4, "Arjun");
	}

}


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */



void initialize() {
  // Print our branding over your terminal :D
  ez::print_ez_template();
  
  pros::delay(500); // Stop the user from doing anything while legacy ports configure.

  // Configure your chassis controls
  chassis.toggle_modify_curve_with_controller(false); // Enables modifying the controller curve with buttons on the joysticks
  chassis.set_active_brake(0); // Sets the active brake kP. We recommend 0.1.
  chassis.set_curve_default(1, 1); // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)  
  default_constants(); // Set the drive to your own constants from autons.cpp!
  exit_condition_defaults(); // Set the exit conditions to your own constants from autons.cpp!


  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // chassis.set_left_curve_buttons (pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT); // If using tank, only the left side is used. 
  // chassis.set_right_curve_buttons(pros::E_CONTROLLER_DIGITAL_Y,    pros::E_CONTROLLER_DIGITAL_A);

 
  flywheel.set_encoder_units(MOTOR_ENCODER_ROTATIONS);
  flywheel.set_brake_mode(MOTOR_BRAKE_COAST);

  chassis.imu_calibrate(true);

  pros::lcd::register_btn1_cb(toggle_skills);

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.add_autons({
	Auton("Close side code\nThis code goes forward, does some swerves, and scores a preload on CLOSE", close_side),
	Auton("Far side code\nThis code goes forward, does some swerves, and scores a preload FAR", far_side),
	Auton("Skills code: goes into position and turns flywheel", skills_code),
	Auton("Test code__Test code__Test code__Test code", test_code),
	Auton("Forward and backward", drive_example),
	Auton("Interference\n\nAfter driving forward, robot performs differently if interfered or not.", interfered_example),
  });

  // Initialize chassis and auton selector
  chassis.initialize();
  ez::as::initialize();

  ez::print_to_screen("Skills is " + std::to_string(is_skills), 4);
}



/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {

}



/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
  // . . .
}



/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  chassis.reset_pid_targets(); // Resets PID targets to 0
  chassis.reset_gyro(); // Reset gyro position to 0
  chassis.reset_drive_sensor(); // Reset drive sensors to 0
  chassis.set_drive_brake(MOTOR_BRAKE_HOLD); // Set motors to hold.  This helps autonomous consistency.

  ez::as::auton_selector.call_selected_auton(); // Calls selected auton from autonomous selector.



  ez::as::shutdown();
}



/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */



void opcontrol() {
  // This is preference to what you like to drive on.
  chassis.set_drive_brake(MOTOR_BRAKE_COAST);
  flywheel.set_brake_mode(MOTOR_BRAKE_COAST);
  bool wings_out = false;
  wings(wings_out);

  pros::Task flywheel_func(flywheelmove, "moves flywheel to initial point when 'L2' is pressed");

  if (is_skills) {
	  //Sunai Driving
	  while (true) {

		  //chassis.tank(); // Tank control
		  // chassis.arcade_standard(ez::SPLIT); // Standard split arcade
		  chassis.arcade_standard(ez::SINGLE); // Standard single arcade
		  // chassis.arcade_flipped(ez::SPLIT); // Flipped split arcade
		  // chassis.arcade_flipped(ez::SINGLE); // Flipped single arcade

		  //if right far trigger pressed, move intake inward, and vice versa
		  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			  intake.move(127);
		  }
		  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
			  intake.move(-127);
		  }
		  else {
			  intake.brake();
		  }

		  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
			  flywheelmove();
		  }
		  else {
			  flywheel.brake();
		  }




		  //if "A" pressed, toggle wings
		  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
			  wings(true);
		  } else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
			  wings(false);
		  }


		  pros::delay(ez::util::DELAY_TIME); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
	  }
  }  else if (!is_skills) {
	  //Arjun Driving
	  while (true) {

		  //chassis.tank(); // Tank control
		  chassis.arcade_standard(ez::SPLIT); // Standard split arcade
		  // chassis.arcade_standard(ez::SINGLE); // Standard single arcade
		  // chassis.arcade_flipped(ez::SPLIT); // Flipped split arcade
		  // chassis.arcade_flipped(ez::SINGLE); // Flipped single arcade
		  
		  //if left far trigger pressed, move intake inward, and vice versa
		  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			  intake.move(127);
		  }
		  else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
			  intake.move(-127);
		  }
		  else {
			  intake.brake();
		  }

		  if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
			  flywheelmove();
		  }
		  else {
			  flywheel.brake();
		  }



		  //if "A" pressed, toggle wings
		  if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
			  wings(true);
		  }
		  else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
			  wings(false);
		  }


		  pros::delay(ez::util::DELAY_TIME); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
	  }
  }
}
