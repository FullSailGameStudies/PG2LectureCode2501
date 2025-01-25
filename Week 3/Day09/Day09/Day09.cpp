﻿// Day09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Pistol.h"
#include <vector>
#include "Knife.h"


class base
{
private:
	int mNum;
public:
	base(int num) : mNum(num)
	{

	}
	void print()
	{
		std::cout << "Hello base " << mNum << "\n";
	}
};

class derived : public base
{
private:
	std::string mStr;
public:
	derived(std::string str, int num) : base(num), mStr(str)
	{ }
};


class Car
{
public:
	Car(int year)
	{
		mModelYear = year;
		mNumberOfCarsMade++;
	}

	int mModelYear; //each car has its own model year variable
	static int mNumberOfCarsMade; //shared by ALL cars

	static void reporting()
	{
		//std::cout << "Model year: " << mModelYear << "\n"; //ERROR! cannot access non-static members
		std::cout << "Number of cars made: " << mNumberOfCarsMade << "\n";
	}

	void vehicleInfo() //there's a hidden parameter called 'this'
	{
		std::cout << "Model Year: " << this->mModelYear << "\n";
	}
};
//initialize explicitly using the class name scoping
int Car::mNumberOfCarsMade = 0;



int main()
{
	{
		// a pointer is a variable that holds a memory address
		int num = 5;
		int* pNum = &num;//stores a memory address in pNum
		std::cout << num << "\n" << pNum << "\n";

		//dereference the pointer to access the value
		//  * on the variable
		std::cout << *pNum << "\n";

		int* pHeapNum = new int(10);//raw pointer
		delete pHeapNum;//release the heap memory

		std::unique_ptr<int> pUNum = std::make_unique<int>(15);
	}//the variables are popped from the stack

	std::unique_ptr<Car> todaysRide = std::make_unique<Car>(2025);
	// dereference with * or with ->
	todaysRide->vehicleInfo();

	std::unique_ptr<Pistol> myGun = std::make_unique<Pistol>(100, 200, 10, 2);
	std::unique_ptr<Weapon> myWeapon =std::move(myGun);
	myGun->calcDamage();

	Knife stabby(5, 10, 18);
	Pistol pewpew(100, 200, 10, 5);

	Car myRide(1988);
	//UPCASTING. ALWAYS safe
	Weapon* currentWeapon = &stabby;//creates a pointer to the Knife object




	std::vector<std::unique_ptr<Weapon>> weapons;
	weapons.push_back(std::make_unique<Knife>(5, 10, 18));
	weapons.push_back(std::make_unique<Pistol>(100, 200, 10, 5));
	weapons.push_back(std::move(myWeapon));

	std::cout << "\nMy Inventory...\n";
	for (auto& wpn : weapons)
	{
		wpn->showMe();
		std::cout << "\n";
	}

	std::cin.get();

	/*
		╔════════════╗
		║ Unique_ptr ║
		╚════════════╝

		Using unique pointers w/ overridden methods


		╔═══════════╗
		║ UPCASTING ║ - casting a derived type variable to a base type variable
		╚═══════════╝

		This is ALWAYS safe.


		To maintain the original object, we need a pointer though. If not, then we're just calling the copy constructor of the base class and lose all the info of the derived.

		Unique pointers owns and manages an object through a pointer.
		std::unique_ptr<derived> pDerived = std::make_unique<derived>("Gotham", 5);


		You can upcast by using the base type in the unique_ptr.
		std::unique_ptr<base> pBase = std::make_unique<derived>("Gotham", 5);
		  OR
		std::unique_ptr<base> pBase = std::move(pDerived); https://learn.microsoft.com/en-us/cpp/standard-library/utility-functions?view=msvc-170&redirectedfrom=MSDN&f1url=%3FappId%3DDev16IDEF1%26l%3DEN-US%26k%3Dk(std%253A%253Amove)%3Bk(move)%3Bk(DevLang-C%252B%252B)%3Bk(TargetOS-Windows)%26rd%3Dtrue#move



		Lecture Code:
			use make_unique and unique_ptr to create a derived instance
			use std::move to upcast it to a base
	*/
	derived der1("Gotham", 1);
	base base1 = der1; //calls the assignment operator of base therefore you lose all the derived parts. base1 is JUST a base object.
	der1.print();
	std::cout << "\n";
	base1.print();



	/*
		╔*************╗
		║  CHALLENGE  ║
		╚*************╝

		Create a vector that holds unique pointers of Weapon.
		Create instances of Weapon and Pistol using make_unique.
		Add them to the vector.

		Loop over the vector and call showMe on each weapon.

	*/




	/*
		╔══════════════════╗
		║  Static Members  ║
		╚══════════════════╝

		When calling a non-static method on a class, you must use a variable of that class.
		That's because the variable is passed in as the 'this' parameter.

		Static methods do not have a 'this' parameter therefore you call them on the
		class name itself.

		That's also why static methods cannot access non-static members.

	*/
	Car myRide2(1988);
	Car::reporting();
	myRide.vehicleInfo();//calling non-static methods. myRide is passed in for 'this'

	/*

		CHALLENGE:
		Add a static method to the Car class that returns an instance of the Car class.

	*/
}