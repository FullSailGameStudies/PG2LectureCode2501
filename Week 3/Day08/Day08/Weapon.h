#pragma once
class Weapon //abstract base class
{
private:
	int mRange;
	int mDamage;

public:
	Weapon(int range, int damage);

	void showMe();
	virtual int calcDamage() = 0;//make it pure virtual with '=0'

	int range() const
	{
		return mRange;
	}
	int damage() const
	{
		return mDamage;
	}
};

