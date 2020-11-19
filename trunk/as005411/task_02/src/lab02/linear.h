#ifndef LINEAR_H
#define LINEAR_H
#include "controlobject.h"

/**
*       \brief Linear controlled object logic.
* 
*       Class that contains linear controlled object logic.
*/
class linear : protected controlobject
{
public:
    /**
    *   Constructor for linear controlled object. Initializes needed variables and stuff.
    */
    linear(const double &ia, const double &ib, const double &ic, const double &id, const double &iy);
    /**
    *   Method that contains primary logic of linear controlled object.
    */
    double &eq (const double &iu) override;
};

#endif // LINEAR_H
