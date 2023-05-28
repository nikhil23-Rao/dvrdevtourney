#include "subsystems/lift.hpp"

const int8_t liftLeftPort = 2;
const int8_t liftRightPort = 3;

okapi::Motor liftLeft = okapi::Motor(liftLeftPort);
okapi::Motor liftRight = okapi::Motor(liftRightPort);
