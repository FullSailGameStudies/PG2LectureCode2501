#include "Pistol.h"
#include <iostream>

void Pistol::showMe()
{
	std::cout << "Pistol: ";
	Weapon::showMe();
	std::cout << "Mag Capacity: " << magCapacity_ << " Rounds: " << rounds_ << "\n";
}