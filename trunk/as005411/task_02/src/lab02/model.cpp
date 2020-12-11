#include "model.h"

/**
*       \brief Controlled system model implementation.
*
*       This class contains implementation of the logic of model with its modules(regulators, etc.).
*/
model::model(const double &iu, const double &iy, const double &tq) : initu(iu), inity(iy), t0(tq)
{
    cout << "Model created";
    cout << "\n!!!Please initialize modules!!!\n\n";
}

double model::active()
{
    std::fstream linout, nlinout;
    linout.open("linear.csv", std::fstream::out);
    nlinout.open("nonlinear.csv", std::ios::out);
    linout.precision(3);
    nlinout.precision(3);
    linout.flags(std::ios::fixed);
    nlinout.flags(std::ios::fixed);

    linout << "i,e,y,u,\n";
    for(int i = 0; i < 10000; i++)
    {
        et = initu - out;
        ut = cr->eq(et);
        out = col->eq(ut);
        linout << i << ',' << et << ',' << out << ',' << ut << ',' << '\n';
    }
    cout << "Linear: \n" << et << " " << out << " " << ut << '\n';

    nlinout << "i,e,y,u,\n";
    for (int i = 0; i < 10000; i++)
    {
        et = initu - out;
        ut = cr->eq(et);
        out = con->eq(ut);
        nlinout << i << ',' << et << ',' << out << ',' << ut << ',' << '\n';
    }
    cout << "Noninear: \n" << et << " " << out << " " << ut << '\n';
    linout.close();
    nlinout.close();
    return true;
}


bool model::initmodules(linear*& l, nonlinear*& n, regulator*& r)
{
    cr = r;
    col = l;
    con = n;
    return true;
}
