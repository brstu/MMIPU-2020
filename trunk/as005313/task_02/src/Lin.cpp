#include "Lin.h"

Lin::Lin(const double &ia, const double &ib, const double &ic, const double &id, const double &iy) : Ctrl(ia, ib, ic, id, iy)
{}

double& Lin::eq(const double &iu)
{
	y = a * y + b * iu;
	return y;
}