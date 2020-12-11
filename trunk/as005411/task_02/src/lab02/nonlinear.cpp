#include "nonlinear.h"

/**
*       \brief Noninear controlled object logic implementation.
*
*       Class that contains implementation for nonlinear controlled object logic.
*/
nonlinear::nonlinear(const double &ia, const double &ib, const double &ic, const double &id, const double &iy) : controlobject(ia, ib, ic, id, iy)
{}

double &nonlinear::eq(const double &iu)
{
    ycache = a * y - b * prevy * prevy + c * iu + d * std::sin(prevu);
    prevu = iu;
    prevy = y;
    y = ycache;
    return y;
}

