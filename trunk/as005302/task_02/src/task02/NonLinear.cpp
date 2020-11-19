#include"NonLinear.h"
#include<math.h>

NonLinear::NonLinear(double a, double b, double c, double d)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}
double NonLinear::equation(double beginWarm, double y) 
{
	double y1 = a * y - b * pow(y0, 2) + c * beginWarm + d * sin(beginWarm0);
	y0 = y;
	beginWarm0 = beginWarm;
	return y1;
}