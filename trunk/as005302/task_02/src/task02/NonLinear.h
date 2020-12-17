#pragma once
#include"Model.h"

class NonLinear : public Model
{
private:
	double a, b, c, d;
	double y0 = 0, beginWarm0 = 0;

public:
	NonLinear(double a, double b, double c, double d);
	double equation(double beginWarm, double y) override;
};