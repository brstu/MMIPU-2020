#include "Reg.h"
#include <iostream>
using std::cout;

float Regulate::get_U_t(float e, float e_0, float e_00)
{
	float q0 = K * (1 + TD / T0);
	float q1 = -K * (1 + (2 * TD / T0) - (T0 / T));
	float q2 = K * TD / T0;

	u_t += q0 * e + q1 * e_0 + q2 * e_00;

	return u_t;
}

void Regulate::start_PID(float w, Model* model, float y_t)
{
	float e = 0.0, e_0 = 0.0, e_00 = 0.0;

	for (int i = 0; i < 1000; i++)
	{
		cout << e << " " << y_t << " " << u_t << "\n";

		e = w - y_t;
		get_U_t(e, e_0, e_00);
		y_t = model->calc(u_t, y_t);

		e_00 = e_0;
		e_0 = e;
	}
}