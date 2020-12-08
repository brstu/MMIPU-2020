#pragma once
#include"Model.h"

class Regulator
{
private:
	double beginWarm = 0;
	double K, T, TD, T0;

public:
	Regulator(const double K, const double T0, const double TD, const double T);
	double BeginWarm(const double e, const double e0 = 0, const double e00 = 0);
	void PIDRegulator(const double w, Regulator* reg, Model* m, double y);
};