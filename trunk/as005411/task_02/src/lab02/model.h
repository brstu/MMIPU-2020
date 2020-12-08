#ifndef MODEL_H
#define MODEL_H
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
#include <iomanip>

#include "linear.h"
#include "nonlinear.h"
#include "regulator.h"

/**
*       \brief Controlled system model.
*
*       This class contains our model with its modules(regulators, etc.).
*/
class model
{
private:
    linear *col = 0; //<! Control object with linear logic.
    nonlinear* con = 0; //<! Control object with non-linear logic.
    regulator *cr = 0; //<! Regulator object.
    const double initu, inity, t0; //<! Initial values.
    double out = 0, et = 0, ut = 0; //<! Calculated variables.
public:
    /**
    *   Constructor for our model with some needed values.
    */
    model(const double &iu, const double &iy, const double &tq);
    /**
    *   Method for modules(objects) initialization. It exists because i wanted this program to be modular not monolythic.
    * 
    *   \param l Passed control object with linear logic
    *   \param n Passed control object with non-linear logic.
    *   \param r Passed regulator object.
    */
    bool initmodules(linear *&l, nonlinear *&n, regulator *&r);
    /**
    *   Method for starting our model, and calculating its working variables.
    */
    double active();
};

#endif // MODEL_H
