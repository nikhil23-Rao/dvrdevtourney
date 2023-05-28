#include "subsystems/drivetrain.hpp"

using namespace okapi::literals;

const int8_t leftFront = -1;
const int8_t leftBack = -12;
const int8_t rightFront = 13;
const int8_t rightBack = 10;

okapi::MotorGroup rightMotors = okapi::MotorGroup({rightFront, rightBack});
okapi::MotorGroup leftMotors = okapi::MotorGroup({leftFront, leftBack});


std::shared_ptr<okapi::OdomChassisController>
	drivetrain = okapi::ChassisControllerBuilder()
	.withMotors({leftFront, leftBack}, {rightFront, rightBack})
	.withDimensions(okapi::AbstractMotor::gearset::green, {{4_in, 11.5_in}, okapi::imev5GreenTPR})
	.withOdometry() 
    	.buildOdometry();