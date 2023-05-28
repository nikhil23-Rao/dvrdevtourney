#include "main.h"
#include "subsystems/drivetrain.hpp"
#include "subsystems/lift.hpp"
#include "subsystems/rollermanipulator.hpp"
#include "subsystems/clamp.hpp"
#include "subsystems/auton.hpp"

using namespace okapi::literals;

void opcontrol() {
	okapi::Controller controller;
	liftRight.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	liftLeft.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	rollerManipulator.setBrakeMode(okapi::AbstractMotor::brakeMode::hold);
	rollerManipulator.setEncoderUnits(okapi::AbstractMotor::encoderUnits::degrees);

	while (true) {
		if (controller[okapi::ControllerDigital::R1].isPressed()) {
			liftLeft.moveVelocity(70);
			liftRight.moveVelocity(70);
		}
		else if (controller[okapi::ControllerDigital::R2].isPressed()) {
			liftLeft.moveVelocity(-70);
			liftRight.moveVelocity(-70);
		}
		else {
			liftLeft.controllerSet(0);
			liftRight.controllerSet(0);
		} 
		if (controller[okapi::ControllerDigital::L1].isPressed()) {
			   // spin roller manipulator 
			rollerManipulator.controllerSet(1);
		} else {
			rollerManipulator.controllerSet(0);
		} if (controller[okapi::ControllerDigital::L2].isPressed()) {
			clamp.moveVelocity(-200);
		} else {
			clamp.moveAbsolute(0, 200);
		}


		double leftJoystick = controller.getAnalog(okapi::ControllerAnalog::leftY);
		double rightJoystick = controller.getAnalog(okapi::ControllerAnalog::rightY);

		drivetrain->getModel()->tank(leftJoystick, rightJoystick);
		okapi::Rate rate;
		rate.delay(100_Hz);
	}
};

void autonomous() {
	driveDistance(4);

	clamp.moveRelative(0,200);
	
	driveDistance(-4);

}