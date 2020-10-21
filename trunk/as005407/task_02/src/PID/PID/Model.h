#pragma once
class Model
{
public:
	virtual float calc(float u_t, float y_t) = 0;
};