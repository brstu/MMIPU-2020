#include<iostream>
#include<math.h>
#include "Regulator.h"
#include "NonLinear.h"
#include "Linear.h"
#include "Model.h"

using namespace std;

int main()
{
	cout << "Linear model:\nE:\t\tY:\t\tU:\n\n";
	Linear* model = new Linear(0.1, 0.05);
	Regulator* r = new Regulator(0.5, 5.0, 35.0, 10.0);
	r->PIDRegulator(25, r, model, 0);

	cout << "\n\nNonlinear model:\nE:\t\tY:\t\tU:\n\n";

	NonLinear* n_model = new NonLinear(0.1, 0.0001, 0.1, 0.0001);
	Regulator* nlr = new Regulator(0.5, 5.0, 35.0, 7.0);
	r->PIDRegulator(25, nlr, n_model, 0);

	return 0;
}