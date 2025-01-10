#pragma once
#include <string>
#include <vector>
#include <time.h>
class FullSailCourse
{
public:
	FullSailCourse(const std::string& name)
	{
		SetName(name);
		FillGrades();
	}
	//getter
	const std::string& GetName() const;
	//setter
	void SetName(const std::string& name)
	{ 
		name_ = name; 
	}

	void PrintGrades();

	void CalcStats(float& min, float& max) const;//TODO: does this need to be const??

private:
	std::string name_;
	std::vector<float> grades_;

	void FillGrades()
	{
		srand((unsigned int)time(NULL));
		for (int i = 0; i < 10; i++)
		{
			grades_.push_back(rand() % 10001 / 100.0f);
		}
	}
};

