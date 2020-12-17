#pragma once
#ifndef Lin_H
#define Lin_H
#include "Ctrl.h"

class Lin : protected Ctrl
{
public:
	Lin(const double &ia, const double &ib, const double &ic, const double &id, const double &iy);
	double &eq(const double &iu) override;
};

#endif