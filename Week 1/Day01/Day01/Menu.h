#pragma once
#include <vector>
#include <string>
class Menu
{
public:
	void AddMenuItem(std::string itemToAdd);

	void Print();

private:
	std::vector<std::string> items_;
};

