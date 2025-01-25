#pragma once
#include "Weapon.h"
class Pistol : public Weapon
{
public:
	Pistol(int range, int damage, int rounds, int magCapacity)
		: 
		Weapon(range, damage),
		rounds_(rounds), magCapacity_(magCapacity)
	{
	}

	int Rounds() const { return rounds_; }
	void Rounds(int newRounds)
	{
		if (newRounds >= 0 && newRounds <= magCapacity_)
			rounds_ = newRounds;
	}

	int MagCapacity() const { return magCapacity_; }
	void MagCapacity(int newCapacity)
	{
		if (newCapacity > 0 && newCapacity <= 30)
			magCapacity_ = newCapacity;
	}

	int calcDamage() override;

private:
	int rounds_, magCapacity_;

};