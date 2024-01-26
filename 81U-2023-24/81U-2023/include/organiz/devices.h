#include "../main.h"
#include "../../include/api.h"
#include "../../include/EZ-Template/api.hpp"

//motor initialization
extern pros::IMU inertial;
//extern pros::Motor kicker;
extern pros::Motor flywheel;
extern pros::Motor intake;
extern pros::ADIDigitalOut front_wings;
extern pros::ADIDigitalOut back_left_wing;
extern pros::ADIDigitalOut back_right_wing;
extern pros::ADIDigitalOut endgame;
extern pros::Distance kickerdistance;
extern Drive chassis;