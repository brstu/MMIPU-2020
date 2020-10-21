#include "Linear.h"
#include "Model.h"


float Lin::calc(float u_t, float y_t) {
	return a * y_t + b * u_t;
}