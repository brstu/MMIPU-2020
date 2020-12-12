#pragma once
#ifndef CTRL_H
#define CTRL_H
#include <iostream>

class Ctrl
{
protected:
	double a, b, c, d, y;
public:
	Ctrl(const double& ia, const double& ib, const double& ic, const double& id, const double& iy);
	Ctrl& operator=(const Ctrl*& other);
	Ctrl(Ctrl*& other);
	virtual double &eq(const double &iu) = 0;
};

#endif