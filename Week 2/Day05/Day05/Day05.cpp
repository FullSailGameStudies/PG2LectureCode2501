// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Console.h"
#include "Input.h"
#include <iomanip>

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

/// <summary>
/// Will search the vector using a linear search algorithm.
/// </summary>
/// <param name="numbers">the vector to search</param>
/// <param name="number">the number to search for</param>
/// <returns>-1 if not found, the index if found</returns>
int LinearSearch(const std::vector<int>& numbers, int number)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == number)
        {
            return i;
        }
    }
    return -1;
}

void PrintGrades(const std::map<std::string, double>& course)
{
    Console::WriteLine("\nPG2 2501", ConsoleColor::Green);
    for (auto& [student,grade] : course)
    {
        std::cout << std::setw(15) << std::left << student << " ";
        std::cout << std::setw(7) << std::right;
        Console::WriteLine(grade, ConsoleColor::White, 
            ((grade < 59.5) ? ConsoleColor::Red : ConsoleColor::Black));
    }
}

int main()
{
    srand(time(NULL));
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 6;
    int foundIndex = LinearSearch(numbers, searchNumber);
    if (foundIndex == -1)
        std::cout << searchNumber << " was not found.\n";
    else
        std::cout << searchNumber << " was found at index " << foundIndex << "\n";


    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a map:
        1) using the insert method.
        2) using [key] = value
    */
    std::map<std::string, float> menu;
    //easy way. use map[key] = value;
    menu["hot dog"] = 1.50f;
    menu["ice cream"] = 2.99f;
    menu["ice cream"] = 6.99f;//OVERWRITES any existing value

    //"hard way". insert(pair)
    std::pair<std::string, float> item = std::make_pair("chicken-fried steak", 13.99f);
    auto wasInserted = menu.insert(item);//will NOT overwrite if the key already exists
    //pair: first (iterator to the item in the map), second (bool: true if inserted)
    if (wasInserted.second)
        std::cout << "Menu item was inserted.\n";
    else
        std::cout << "Item was already on the menu. Overwrite?\n";


    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map


    /*
        CHALLENGE:

            Create a map that stores names (string) and grades. Call the variable grades.
            Add students and grades to your map.

    */

    std::vector<std::string> names{
        "Juan","Nicolas","Ignacio","Kathryn","Joshua","Sherard","Brandon","Jacob","Ja'Sohn",
"Daniel","Hunter","Michael","Aiden","Vy","Valeria","Matthew M","Xavier","Giancarlo","Abigail",
"Sahaja","Dawson","Matthew T","Carlos","Griffin","Matthew R","Dominic","Nathan","Anna",
"Charlotte","Imani","Justin","Maxwell","Quinton","Robert","Steven","Victor","William"
    };
    std::map<std::string, double> grades;
    for (auto& name : names)
    {
        grades[name] = rand() % 10001 / 100.0;
    }
    PrintGrades(grades);






    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    std::cout << "\n\nPG2 Cafe\n";
    for (auto& [menuItem,menuPrice] : menu)
    {
        std::cout << menuItem << " " << menuPrice << "\n";
    }
    for (auto i = menu.begin(); i != menu.end(); i++)
    {
        // *i to access the pair object
        // OR...
        // i-> to access the members of the pair object
        std::string menuItem = i->first;// (*i).first;
        float menuPrice = i->second; // (*i).second;
    }

    //iterator = find(key)
    //not found is map.end()
    std::string itemToFind = "hot dog";
    float myItem = menu["Cheese Burger"];//BAD way to find a key
    auto isFound = menu.find(itemToFind);
    std::cout << "\n\nLooking for " << itemToFind << "...";
    if (isFound == menu.end())
    {
        std::cout << itemToFind << " was not on the menu. Try McDonald's!\n";
    }
    else
    {
        float oldPrice = isFound->second;
        isFound->second *= 1.10;
        std::cout << isFound->first << " used to costs " << oldPrice << ".\n";
        std::cout << "Now it costs " << isFound->second << "!! Thanks Putin!\n";
    }

    //HOW to update a value
    //[key] = value will overwrite  (OK)
    //iterator->second = value to update the value (BEST)



    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }


    /*
        CHALLENGE:

            Loop over your grades map and print each student name and grade.

    */



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }



    /*
        CHALLENGE:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

            curve the grade (add 5) 
                that is stored in the grades map
    */
    do
    {
        std::cout << "\nStudent to curve: ";
        std::string student;
        std::getline(std::cin, student);
        if (student.empty()) break;

        auto foundStudent = grades.find(student);
        if (foundStudent == grades.end())
            std::cout << student << " was not found.\n";
        else
        {
            std::cout << student << "'s grade was " << foundStudent->second << ".";
            foundStudent->second = std::min(100.0, foundStudent->second + 5);
            std::cout << " Now the grade is " << foundStudent->second << "\n";
            PrintGrades(grades);
        }

    } while (true);



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an exisiting value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



    /*
        CHALLENGE:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */
}