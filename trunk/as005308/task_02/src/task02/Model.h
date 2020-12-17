#pragma once

class Model
{
public:
	virtual double equation(double beginWarm, double y) = 0;
};