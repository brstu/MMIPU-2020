#include <iostream>
#include <cmath>
#include <iomanip>
#include "model.h"

/**
*       \file Main function file.
*       \author Rakhlei Vitali.
*       \brief Main project logic.
* 
*       This file contains main project structure and logic of model implementation.
*/

int main()
{
    double  a = 0.3, //0.3
        b = 0.0001,  //0.1
        b1 = 0.1,
        c = 0.01,  //0.1
        d = 0.1,  //0.1
        u_t = 25, //30
        y_t = 1,  //4
        k = 0.1,  //0.1
        t = 10,   //1
        tq = 10,//0.01
        td = 50;  //50

    model *newModel = new model(u_t, y_t, tq);

    linear *ccol = new linear(a, b1, c, d, y_t);
    nonlinear* cconl = new nonlinear(a, b, c, d, y_t);
    regulator *cr = new regulator(tq, k, t, td);

    newModel->initmodules(ccol, cconl, cr);
    newModel->active();

        
    delete newModel;
    cout << "Success" << endl;
    return 0;
}
