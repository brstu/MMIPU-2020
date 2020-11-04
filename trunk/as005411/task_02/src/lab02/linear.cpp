#include "linear.h"

/**
*       \brief Linear controlled object logic implementation.
*
*       Class that contains implementation for linear controlled object logic.
*/
linear::linear(const double &ia, const double &ib, const double &ic, const double &id, const double &iy): controlobject(ia, ib, ic, id, iy)
{

}

double& linear::eq(const double &iu)
{
    y = a * y + b * iu;
    return y;
}
