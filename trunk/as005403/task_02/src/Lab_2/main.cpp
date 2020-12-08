#include<iostream>
#include<math.h>
#include "Regulator.h"
#include "NonLinear.h"
#include "Linear.h"
#include <fstream>
/**
	\file in this file i solve task to implement PID - controller
	\authors Ilya Dobrolinskiy
	\version 1.0
	\date 04.10.2020
*/
using namespace std;

/// \brief creations of all class' instances
int main() {
	float w_t = 4;
	float a = 0.3, b = 0.1;
	float a1 = 0.3, b1 = 0.1, c1 = 0.1, d1 = 0.1;
	float K = 0.1, T0 = 10, TD = 50, T = 10;
	float y0 = 1;

	
	Linear *model = new Linear(a, b, y0);//(a, b, y0)
	Regulator* regulator = new Regulator(K, T0, TD, T);//(K, T0, TD, T)
	regulator->PIDRegulator(w_t, regulator, model, y0);//(w_t, regulator, model, y0)

	cout << "\n\n\n\n";

	NonLinear* nl_model = new NonLinear(a1, b1, c1, d1, y0);//(a1, b2, c, d, y0)
	Regulator* nl_regulator = new Regulator(K, T0, TD, T);//(K, T0, TD, T)
	nl_regulator->PIDRegulator(w_t, nl_regulator, nl_model, y0);//(w_t, nl_regulator, nl_model, y0)

	return 0;
}
