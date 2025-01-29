// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"
#include <vector>
#include <fstream>
#include "Console.h"
#include "Input.h"
#include "Day11.h"

int main()
{
	std::cout << "Gone in 60 Seconds!\n";//https://carbuzz.com/features/beyond-eleanor-gone-in-60-seconds-car-names#:~:text=The%20Complete%20List%20Of%20Gone%20In%2060%20Seconds,8%201961%20Porsche%20Speedster%20-%20%22Natalie%22%20More%20items

	Car myHemi(1969, "Plymouth", "Hemi Cuda");
	std::string fileName = "garage.csv";
	std::ofstream outFile(fileName);
	char delimiter = '^';
	if (outFile.is_open())
	{
		myHemi.SerializeCSV(outFile, delimiter);
	}
	else
	{
		std::cout << fileName << " could not be opened.\n";
	}
	outFile.close();

	std::cout << myHemi.vehicleInformation() << "\n";
	myHemi.SerializeCSV(std::cout, ' ');


	std::vector<Car> garage;
	garage.push_back(Car(1967, "Ford", "Shelby Mustang GT500"));
	garage.push_back(Car(1956, "Ford", "T Bird"));
	garage.push_back(Car(1961, "Porsche", "Speedster"));
	garage.push_back(Car(1965, "Pontiac", "GTO"));
	garage.push_back(Car(1969, "Plymouth", "Hemi Cuda"));
	char carDelimiter = '*';

	std::ofstream garageFile(fileName);
	if (garageFile.is_open())
	{
		for (int i = 0; i < garage.size(); i++)
		{
			garage[i].SerializeCSV(garageFile, delimiter);
			if (i < garage.size() - 1)
				garageFile << carDelimiter;//another car needs to be saved. output the car delimiter.
		}
	}
	else
	{
		std::cout << fileName << " could not be opened.\n";
	}
	garageFile.close();


	/*
		╔═════════════╗
		║ Serializing ║
		╚═════════════╝

		Saving the state (data) of objects

		Lecture Code: serialize the vector of Cars to a file.
			Data Format:
				separates cars. EX: car1|car2|car3
				separates data inside a car. EX: 1967;Ford;Shelby Mustang GT500

	*/



	/*
		╔═══════════════╗
		║ Deserializing ║
		╚═══════════════╝

		Recreating the objects from the saved state (data) of objects

		Lecture Code:
			Open the file
			Read in each line
			split each line to get each car
			split each car to get the car details

	*/

	std::ifstream inGarage(fileName);
	std::vector<Car> GsGarage;
	if (inGarage.is_open())
	{
		while (!inGarage.eof())
		{
			std::string carData;
			std::getline(inGarage, carData, carDelimiter);
			Car nextCar(carData, delimiter);
			GsGarage.push_back(nextCar);
		}
	}
	else {
		std::cout << fileName << " could not be opened.\n";
	}
	inGarage.close();
	std::cout << "\n\nG's Garage\n";
	for (auto& car : GsGarage)
	{
		car.SerializeCSV(std::cout, ' ');
		std::cout << "\n";
	}
}