#include "Linear.h"

Linear::Linear(const float a, const float b, const double Y)
{
	this->a = a;
	this->b = b;
	this->Y = Y;
}

float Linear::equation(double U)
{
	Y = a * Y + b * U;
	return Y;
}


