#ifndef CONTROLOBJECT_H
#define CONTROLOBJECT_H
#include <iostream>

/**
*       \brief Abstract class that contains common controlled object logic.
*
*       This class contains common variables and methods(mostly abstract) with some additional useful logic such as copyconstructors and other.
*/
class controlobject
{
protected:
    double a, b, c, d, y; //<! Common variables for both linear and nonlinear controlled objects
public:
    /**
    *   Constructor for controlled object. Initializes needed variables and stuff.
    */
    controlobject(const double& ia, const double& ib, const double& ic, const double& id, const double& iy);
    controlobject& operator=(const controlobject*& other);
    controlobject(controlobject*& other);
    /**
    *   Common pure virtual method with slightly different logic for linear and nonlinear objects.
    */
    virtual double &eq(const double &iu) = 0;
};

#endif // CONTROLOBJECT_H
