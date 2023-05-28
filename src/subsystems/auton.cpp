#include "subsystems/auton.hpp"
#include "subsystems/drivetrain.hpp"
#include <cstdlib>

okapi::IterativePosPIDController pid = okapi::IterativeControllerFactory::posPID(0,0,0);

using namespace okapi::literals;

bool checkIfMoving() {
return abs(rightMotors.getActualVelocity()) + abs(leftMotors.getActualVelocity()) > 10;
}


void driveDistance(double d) {
	double initialX = drivetrain->getState().x.convert(okapi::foot); // forard/back
	double initialY = drivetrain->getState().y.convert(okapi::foot); // left/right

	pid.setTarget(d);

double displacement = 1000;

while ((abs(displacement - d) > 0.1)||checkIfMoving()) {
	double changeX = drivetrain->getState().x.convert(okapi::foot) - initialX;
	double changeY = drivetrain->getState().y.convert(okapi::foot) - initialY;
 
	 displacement = sqrt(powf(changeX, 2) + powf(changeY, 2));

	if (d < 0) {
	displacement = -1 * displacement;
	}

	double pidValue = pid.step(displacement);

	drivetrain->getModel()->tank(pidValue, pidValue);

	okapi::Rate rate;
	rate.delay(100_Hz);
}

	drivetrain->getModel()->tank(0, 0);
}