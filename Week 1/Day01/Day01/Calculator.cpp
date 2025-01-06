#include "Calculator.h"
#include <stdlib.h>

int Calculator::minus(int number1, int number2)
{
	return number1 - number2;
}

float Calculator::add(float f1, float f2)
{
	return f1 + f2;
}

double Calculator::mult(double num, double factor)
{
	return num * factor;
}

bool Calculator::isEven(int number)
{
	return number % 2 == 0;
}

int Calculator::randoNumber()
{
	return rand();
}
