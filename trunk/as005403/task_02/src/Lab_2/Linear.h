#pragma once
#include"Model.h"

class Linear : public Model
{
private:
	float a, b;
	double Y = 0;
public:
	Linear(const float a, const float b, const double Y);
	float equation(double U) override;
};

