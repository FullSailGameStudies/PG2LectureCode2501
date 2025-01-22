#include "Person.h"
#include <iostream>

void Person::ItsMyBirthday()
{
	age_++;
	std::cout << "Hi, I am " << Name() << ". It's my birthday! I am " << age_ << " years old! Let's have some cake!\n";
}
