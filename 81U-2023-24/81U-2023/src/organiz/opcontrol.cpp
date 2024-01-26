#include "../../include/organiz.h"

void back_wings(bool out) {
	if (out) {
		back_left_wing.set_value(true);
		back_right_wing.set_value(true);
	}
	else {
		back_left_wing.set_value(false);
		back_right_wing.set_value(false);
	}
}

void flywheelmove(int multiplier) {
	int flywheelsped = flywheel.get_actual_velocity(),
		setspeed = 0;

	setspeed = flywheelsped + (10 * multiplier);
	flywheel.move_velocity(setspeed);

}

void kickermove() {
	int dist = kickerdistance.get();

}


//void flywheelmoveauton(bool on, int speed) {
//	while (on) {
//		int flywheelsped = flywheel.get_actual_velocity(),
//			targetsped = speed,
//			error = 0,
//			gain = 0,
//			setspeed = 0;
//
//		error = targetsped - flywheelsped;
//		if (flywheelsped < (speed / 5)) {
//			gain = 0.01;
//		}
//		else if (flywheelsped > (speed / 4) && flywheelsped < (speed / 2)) {
//			gain = 0.5;
//		}
//		else {
//			gain = 0.25;
//		}
//
//		setspeed = flywheelsped + (error * 0.2);
//		flywheel.move_velocity(setspeed);
//		pros::delay(ez::util::DELAY_TIME);
//	}
//}


