#pragma once
#include "Model.h"
class  Lin : public Model{
public:
	float a = 0.3, b = 0.05;
	float calc(float u_t, float y_t);
};