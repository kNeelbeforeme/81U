#include "../../include/organiz.h"

void wings(bool out) {
	if (out) {
		left_wing.set_value(true);
		right_wing.set_value(true);
	}
	else {
		left_wing.set_value(false);
		right_wing.set_value(false);
	}
}
void flywheelmove() {
	int flywheelsped = flywheel.get_actual_velocity(),
		targetsped = 300,
		error = 0,
		gain = 0,
		setspeed = 0;

	error = targetsped - flywheelsped;
	if (flywheelsped < 50) {
		gain = 0.01;
	}
	else if (flywheelsped > 50 && flywheelsped < 200) {
		gain = 0.5;
	}
	else {
		gain = 0.25;
	}

	setspeed = flywheelsped + (error * 0.2);
	flywheel.move_velocity(setspeed);

}
