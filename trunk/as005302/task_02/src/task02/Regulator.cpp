#include "Regulator.h"
#include <iostream>

Regulator::Regulator(const double K, const double T0, const double TD, const double T)
{
	this->K = K;
	this->T0 = T0;
	this->TD = TD;
	this->T = T;
}
double Regulator::BeginWarm(const double e, const double e0, const double e00)
{
	double q0 = K * (1.0 + TD / T0);
	double q1 = -K * (1 + 2.0 * TD / T0 - T0 / T);
	double q2 = K * TD / T0;
	beginWarm += q0 * e + q1 * e0 + q2 * e00;
	return beginWarm;
}

void Regulator::PIDRegulator(const double w, Regulator* reg, Model* m, double y)
{
	double e = 0.0, e0 = 0.0, e00 = 0.0;
	double u = 0;
	for (int k = 0; k < 50; k++)
	{
		std::cout << e << "\t|\t" << y << "\t|\t" << u << std::endl;
		e = w - y;
		u = reg->BeginWarm(e, e0, e00);
		y = m->equation(u, y);
		e00 = e0;
		e0 = e;
	}
}