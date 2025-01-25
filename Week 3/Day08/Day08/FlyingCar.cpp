#include "FlyingCar.h"

std::string FlyingCar::vehicleInformation()
{
	// 2 ways to override:
	//		EXTEND: call the base method
	//		FULLY OVERRIDE: do NOT call the base method
	//
	std::string baseInfo = Car::vehicleInformation();
	std::string newInfo = "\n\tMax Airspeed: " + std::to_string(maxAirspeed_);
	return baseInfo + newInfo;
}
