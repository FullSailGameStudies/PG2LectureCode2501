#include "FullSailCourse.h"
#include <iostream>

const std::string& FullSailCourse::GetName() const
{
	//SetName("GTA6");//not allowed since SetName modifies the data of the class
	return name_;
}

void FullSailCourse::PrintGrades()
{
	//grades.clear();
	std::cout << "\n" << name_ << "\n";
	for (auto& grade : grades_)
	{
		std::cout << "\t" << grade << "\n";
	}
	std::cout << "\n\n";
}
void FullSailCourse::CalcStats(float& min, float& max) const
{
	min = max = 0;
	if (grades_.size() > 0)
	{
		min = max = grades_[0];
		for (int i = 1; i < grades_.size(); i++)
		{
			if (grades_.at(i) > max) max = grades_.at(i);
			if (grades_.at(i) < min) min = grades_.at(i);

			//min = std::min(min, grades_[i]);
			//max = std::max(max, grades_[i]);
		}
	}
}
