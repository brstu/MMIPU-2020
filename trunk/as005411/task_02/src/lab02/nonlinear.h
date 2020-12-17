#ifndef NONLINEAR_H
#define NONLINEAR_H
#include "controlobject.h"
#include <cmath>

/**
*       \brief Noninear controlled object logic.
* 
*       Class that contains nonlinear controlled object logic.
*/
class nonlinear : public controlobject
{
private:
    double prevu = 0, prevy = 0, ycache = 0; //<! Variables specific for nonlinear logic.
public:
    /**
    *   Constructor for nonlinear controlled object. Initializes needed variables and stuff.
    */
    nonlinear(const double &ia, const double &ib, const double &ic, const double &id, const double &iy);
    /**
    *   Method that contains primary logic of nonlinear controlled object.
    */
    double &eq (const double &iu) override;
};

#endif // NONLINEAR_H
