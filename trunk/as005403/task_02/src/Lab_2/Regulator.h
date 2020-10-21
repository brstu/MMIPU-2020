#pragma once
#include"Model.h"

class Regulator
{
private:
	double U = 0;
	double K, T0, TD, T;
public:
	Regulator(const double K, const double T0, const double TD, const double T);
	double get_Ut(const double E, const double E0 = 0, const double E0prev = 0);
	void PIDRegulator(const double w, Regulator *reg, Model *lm, double Yinit,fstream& file);
};