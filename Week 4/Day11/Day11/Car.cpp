#include "Car.h"

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

Car::Car(const std::string& csvData, char delimiter)
{
	DeserializeCSV(csvData, delimiter);
}

void Car::SerializeCSV(std::ostream& outFile, char delimiter) const
{
	outFile << mModelYear << delimiter << mMake << delimiter << mModel;
}

void Car::DeserializeCSV(const std::string& csvData, char delimiter)
{
	std::string data;
	std::stringstream carStream(csvData);
	std::getline(carStream, data, delimiter);
	mModelYear = std::stoi(data);
	std::getline(carStream, mMake, delimiter);
	std::getline(carStream, mModel, delimiter);
}
