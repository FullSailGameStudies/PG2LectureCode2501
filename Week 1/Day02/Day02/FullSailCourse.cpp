#include "FullSailCourse.h"

const std::string& FullSailCourse::GetName() const
{
	//SetName("GTA6");//not allowed since SetName modifies the data of the class
	return name_;
}
