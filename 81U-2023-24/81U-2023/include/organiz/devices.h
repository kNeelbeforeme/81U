#include "../main.h"
#include "../../include/api.h"
#include "../../include/EZ-Template/api.hpp"

//motor initialization
extern pros::IMU inertial;
extern pros::Motor kicker;
extern pros::Motor intake;
extern pros::ADIDigitalOut front_right_wing;
extern pros::ADIDigitalOut front_left_wing;
extern pros::ADIDigitalOut back_left_wing;
extern pros::ADIDigitalOut back_right_wing;
extern pros::ADIDigitalOut endgame;
extern Drive chassis;