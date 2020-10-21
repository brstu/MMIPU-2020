#pragma once
#include"Model.h"

class NonLinear : public Model
{
private:
	float a, b, c, d;
	double Y = 1;
	double Ybefore = 0;
	double Yafter = 0;
	double U_prev = 0;

public:
	NonLinear(const float a, const float b, const float c, const float d, const float Y);
	float equation(double U) override;
};