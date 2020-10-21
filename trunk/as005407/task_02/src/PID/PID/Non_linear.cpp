#include "Non_linear.h"
#include <math.h>


float Non_lin::calc(float u_t, float y_t)
{
	float y_t1 = a * y_t - b * pow(y_t0, 2) + c * u_t + d * sin(u_t0);
	y_t0 = y_t;
	u_t0 = u_t;
	return y_t1;
}