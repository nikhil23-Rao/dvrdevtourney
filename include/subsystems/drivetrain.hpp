#include "main.h"
#include "okapi/impl/device/motor/motorGroup.hpp"

extern const int8_t leftFront;
extern const int8_t leftBack;
extern const int8_t rightFront;
extern const int8_t rightBack;

extern okapi::MotorGroup rightMotors;
extern okapi::MotorGroup leftMotors;


extern std::shared_ptr<okapi::OdomChassisController> drivetrain;