#pragma once
#include <string>
class FullSailCourse
{
public:
	//getter
	const std::string& GetName() const;
	//setter
	void SetName(const std::string& name)
	{ 
		name_ = name; 
	}

private:
	std::string name_;
};

