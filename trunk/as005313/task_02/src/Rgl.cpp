#include "Rgl.h"

Rgl::Rgl(const double &qt) : Rgl(qt, 0, 0, 0)
{}

Rgl::Rgl(const double &qt, double const& ik) : Rgl(qt, ik, 0, 0)
{}

Rgl::Rgl(const double &qt, const double &ik, const double &it) : Rgl(qt, ik, it, 0)
{}

Rgl::Rgl(const double &qt, const double &ik, const double &it, const double &itd) : t0(qt), k(ik), t(it), td(itd)
{
	q0 = k * (1.0 + td / t0);
	q1 = -k * (1.0 + 2.0*td / t0 - t0 / t);
	q2 = k * td / t0;
}

double &Rgl::eq(const double &iek)
{
	uk += q0 * iek + q1 * ek1 + q2 * ek2;
	ek2 = ek1;
	ek1 = iek;
	return uk;
}