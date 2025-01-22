#pragma once
#include <string>
#include <iostream>
class Sword
{
public:
	//
	// constructors (ctors)
	//		initialize the fields of the class
	// IF you do not create a ctor, the compiler will give you 
	//		a default ctor.
	//	a default ctor is a ctor w/out parameters.
	// IF you create a ctor, the compiler's version is no longer available
	//Sword() 
	//{
	//	sharpness_ = 1.0f;
	//	length_ = 12;
	//	name_ = "";
	//}
	Sword(float sharpness, int length, std::string name) :
		//member initialization list
		sharpness_(sharpness),
		length_(length),
		name_(name)
	{
		//sharpness = sharpness_;//backwards
	}


	//
	// methods (behavior)
	//
	// Attack, Defense
	//	PascalNamingConvention

	//
	//getters/setters 
	//	public b/c you want other code to have access to the data in a CONTROLLED way
	// 
	// getters (accessors)
	//	 return type: same as the field
	//	 no parameters
	//	 const
	//	 normally defined in the header
	int GetLength() const
	{
		return length_;
	}
	float Sharpness() const { return sharpness_; }

	// setters (mutators)
	//	return type: usually void
	//  parameter's type that matches the field
	//  NON-const
	//	normally defined in the header
	void SetLength(int length)
	{
		if (length > 0 && length < 120)//the gate
		{
			length_ = length;
		}
	}
	void Sharpness(float sharpness)
	{
		if (sharpness > 0 && sharpness <= 1.0f)
			sharpness_ = sharpness;
	}


private:
	//
	// FIELDS (data members)
	//	usually private
	//	naming conventions:
	//		camelCasingNamingConvention
	//		m_fSharpness, m_sharpness, mSharpness, _sharpness, sharpness_
	float sharpness_;
	int length_;
	std::string name_; 

	void Sample(std::string& name)
	{
		//std::string name = "Batman";

		std::cout << name_;
	}
};

