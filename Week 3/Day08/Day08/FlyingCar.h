#pragma once
#include "Car.h"
class FlyingCar : public Car
{
public:
	FlyingCar(int year, std::string make, std::string model, int maxAirspeed) : 
		Car(year,make,model),
		maxAirspeed_(maxAirspeed)
	{
	}

	std::string vehicleInformation() override;

private:
	int maxAirspeed_;
};

