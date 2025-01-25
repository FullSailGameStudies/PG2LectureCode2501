#include "Knife.h"
#include <iostream>

void Knife::showMe()
{
	std::cout << "Knife: ";
	Weapon::showMe();
	std::cout << "Length: " << length_ << "\n";
}