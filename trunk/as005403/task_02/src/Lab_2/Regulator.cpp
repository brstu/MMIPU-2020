#include "Regulator.h"
#include <fstream>
using namespace std;

Regulator::Regulator(const double K, const double T0, const double TD, const double T)
{
	this->K = K;
	this->T0 = T0;
	this->TD = TD;
	this->T = T;
}

double Regulator::get_Ut(const double E, const double E0, const double E0prev)
{
	double q0 = K * (1.0 + TD / T0);
	double q1 = -K * (1 + 2.0 * TD / T0 - T0 / T);
	double q2 = K * TD / T0;
	U += q0 * E + q1 * E0 + q2 * E0prev;
	return U;
}

void Regulator::PIDRegulator(const double w, Regulator * reg, Model * lm, double Yinit,fstream& file)
{
	double E = 0.0, Eprev = 0.0, Eprevprev = 0.0;
	double u = 0, y = Yinit;

//	file.open("file.csv", ios::out | ios::app | ios::in);

	for (int k = 0; k < 1000; k++) {
		E = w - y;
		u = reg->get_Ut(E, Eprev, Eprevprev);
		y = lm->equation(u);

//		file << k << "," << E << "," << U << "," << y << "\n";

		Eprevprev = Eprev;
		Eprev = E;
	}
}

