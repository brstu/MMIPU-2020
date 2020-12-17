#include "NonLinear.h"
#include "Math.h"


NonLinear::NonLinear(const float a, const float b, const float c, const float d, const float Y)
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->Y = Y;
}

float NonLinear::equation(double U)
{
	Yafter = a * Y - b * pow(Ybefore, 2) + c * U + d * sin(U_prev);
	Ybefore = Y;
	Y = Yafter;
	U_prev = U;
	return Yafter;
}



