#pragma once
#include <string>
class Person
{
public:
	Person(std::string name, int age) :
		name_(name),
		age_(age)
	{

	}

	void ItsMyBirthday();

	int Age() const { return age_; }
	std::string Name() const { return name_; }

	void Age(int age) {
		if (age >= 0 && age <= 120)
			age_ = age;
	}
	void Name(std::string name)
	{
		if (!name.empty() && name.length() < 128)
		{
			name_ = name;
		}
	}

private:
	int age_;
	std::string name_;
};

