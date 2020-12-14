#include "NoLin.h"

NoLin::NoLin(const double &ia, const double &ib, const double &ic, const double &id, const double &iy) : Ctrl(ia, ib, ic, id, iy)
{}

double &NoLin::eq(const double &iu)
{
	ycache = a * y - b * prevy * prevy + c * iu + d * std::sin(prevu);
	prevu = iu;
	prevy = y;
	y = ycache;
	return y;
}