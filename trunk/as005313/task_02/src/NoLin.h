#pragma once
#ifndef NoLin_H
#define NoLin_H
#include "Ctrl.h"
#include <cmath>

class NoLin : public Ctrl
{
private:
	double prevu = 0, prevy = 0, ycache = 0;
public:
	NoLin(const double &ia, const double &ib, const double &ic, const double &id, const double &iy);
	double &eq(const double &iu) override;
};

#endif