#pragma once
#include"Model.h"

class Linear : public Model
{
private:
	double a, b;

public:
	Linear(const double a, const double b);
	double equation(double beginWarm, double y) override;
};