#include "Linear.h"

Linear::Linear(const double a, const double b)
{
	this->a = a;
	this->b = b;
}
double Linear::equation(double beginWarm, double y) 
{
	y = a * y + b * beginWarm;
	return y;
}