#include "../main.h"
#include "../../include/api.h"
#include "../../include/EZ-Template/api.hpp"

//motor initialization
extern pros::IMU inertial;
extern pros::Motor flywheel;
extern pros::Motor intake;
extern pros::ADIDigitalOut right_wing;
extern pros::ADIDigitalOut left_wing;
extern pros::ADIDigitalOut endgame;
extern Drive chassis;