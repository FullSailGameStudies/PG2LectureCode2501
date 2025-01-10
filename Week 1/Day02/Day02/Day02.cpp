#include <iostream>
#include <string>
#include <vector>
#include "FullSailCourse.h"

bool postFix(std::string& hero)
{
	srand((unsigned int)time(NULL));
	int postFixNumber = rand() % 1000;
	hero = hero + "-" + std::to_string(postFixNumber);
	return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
	//scores.push_back(5); //not allowed because it is marked as const
	float sum = 0;
	for (auto score : scores)
		sum += score;

	return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
	std::cout << "----SCORES----\n";
	int index = 1;
	for (int score : scores)
		std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
	//size will always be <= capacity
	std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

int Add(int& n1, int& n2)
{
	n1++;
	return n1 + n2;
}
int Sum(std::vector<int>& numbers)
{
	int sum = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		sum += numbers.at(i);
	}
	return sum;
}
void PrintMe(std::string& name)
{

}

void FillGrades(std::vector<float>& course)
{
	for (int i = 0; i < 10; i++)
	{
		course.push_back(rand() % 10001 / 100.0f);
	}
}
void PrintGrades(const std::vector<float>& grades)
{
	//grades.clear();
	std::cout << "\nPG2 grades for January 2025\n";
	for (auto& grade : grades)
	{
		std::cout << "\t" << grade << "\n";
	}
	std::cout << "\n\n";
}

int main()
{
	srand((unsigned int)time(NULL));

	int num1 = 5, num2 = 2;
	int iResult = Add(num1, num2);
	//iResult = Add(125, 22);

	std::vector<int> nums{ 1,2,3,4,5,6,7,8 };

	int& n1 = num1;//n1 is a reference to the num1 variable

	int sum = Sum(nums);

	/*
		╔══════════════════════════════╗
		║Parameters: Pass by Reference.║
		╚══════════════════════════════╝
		Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

		NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
			This is because the parameter is actually just a new name for the other variable.
	*/
	std::string spider = "Spiderman";
	bool isEven = postFix(spider);
	std::string evenResult = (isEven) ? "TRUE" : "FALSE";
	std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


	/*
		CHALLENGE 1:

			Write a method to fill the vector of floats with grades.
			1) pass it in by reference
			2) add 10 grades to the vector
			3) after calling the method in main, print the vector of grades

	*/
	std::vector<float> grades;
	FillGrades(grades);
	PrintGrades(grades);


	/*
		╔══════════════════╗
		║ const parameters ║
		╚══════════════════╝
		const is short for constant. It prevents the variable from being changed in the method.

		This is the way you pass by reference and prevent the method from changing the variable.
	*/
	std::vector<int> highScores;
	highScores.reserve(10);
	printInfo(highScores);//size: null?  capacity: ?
	for (int i = 0; i < 17; ++i)
	{
		highScores.push_back(rand() % 5000);
		printInfo(highScores);//size: ?  capacity: ?
	}
	float avg = average(highScores);



	/*
		CHALLENGE 2:

			Write a method to calculate the stats on a vector of grades
			1) create a method to calculate the min, max.
				Use ref parameters for min and max.
			2) call the method in main and print out the min, max.

	*/
	FullSailCourse pg2("PG2");
	pg2.PrintGrades();
	float minGrade, maxGrade;
	pg2.CalcStats(minGrade, maxGrade);
	std::cout << "Min: " << minGrade << "\tMax: " << maxGrade << "\n";





	/*
		╔═══════════╗
		║ vector<T> ║
		╚═══════════╝

		[  Removing from a vector  ]

		clear() - removes all elements from the vector
		erase(position) - removes the element at the position
		erase(starting position, ending position) - removes a range of elements. the end position is not erased.

	*/
	print(highScores);

	//erase all scores < 2500
	for (int i = 0; i < highScores.size(); i++)
	{
		if (highScores.at(i) < 2500)
		{
			highScores.erase(highScores.begin() + i);
			i--;//decrement i after erasing
		}
	}
	//OR...
	for (int i = 0; i < highScores.size(); )
	{
		if (highScores.at(i) < 2500)
		{
			highScores.erase(highScores.begin() + i);
		}
		else //only increment i when you do not erase
			i++;
	}
	//OR...
	for (auto i = highScores.begin(); i != highScores.end(); )
	{
		if ((*i) < 2500)
		{
			i = highScores.erase(i);
		}
		else //only increment i when you do not erase
			i++;
	}



	print(highScores);



	/*
		CHALLENGE 3:

			Using the vector of grades you created.
			Remove all the failing grades (grades < 59.5).
			Print the grades.
	*/





	/*
		╔═══════════╗
		║ vector<T> ║
		╚═══════════╝


		size(): # of items that have been ADDED
		capacity(): length of the internal array
		reserve(n): presizes the internal array
	*/
	std::vector<int> scores;
	scores.reserve(10); //makes the internal array to hold 10 items.

	printInfo(scores);
}