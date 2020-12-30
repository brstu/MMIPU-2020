#pragma once
#include "Model.h"
///Regulaton class
class Regulate {
public:
	float K = 0.1, T = 10, TD = 50, T0 = 10, u_t = 0.0;
	float get_U_t(float e, float e_0, float e_00);
	void start_PID(float w, Model* model, float y_t);

};