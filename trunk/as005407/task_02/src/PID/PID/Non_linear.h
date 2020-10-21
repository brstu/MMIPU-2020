#pragma once
#include "Model.h"
class Non_lin : public Model {
public:
	float a = 0.3, b = 0.0001, c = 0.1, d = 0.0001, u_t0 = 0, y_t0 = 0;
	float calc(float u_t, float y_t) override;
};