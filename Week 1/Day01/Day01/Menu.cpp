#include "Menu.h"
#include "Console.h"

void Menu::AddMenuItem(std::string itemToAdd)
{
	items_.push_back(itemToAdd);
}

void Menu::Print()
{
	Console::WriteLine("\nPG2 Cafe  (for loop)");
	for (int i = 0; i < items_.size(); i++)
	{
		//std::string item = items_[i];
		std::cout << items_[i] << "\n";
	}

	Console::WriteLine("\nPG2 Cafe  (range-based for loop)");
	for (auto& item : items_)
	{
		std::cout << item << "\n";
	}

	Console::WriteLine("\nPG2 Cafe  (range-based for loop)");
	for (auto i = items_.begin(); i != items_.end(); i++)
	{
		std::cout << *i << "\n";
	}
}
