# Full code for Laboratory work 2

## Rakhlei Vitali

#### controlobject.cpp [[return](https://github.com/as005411/MMIPU-2020/tree/dev/trunk/as005411/task_02/doc#controlobjecth-full)]:

```c++
#include "controlobject.h"

/**
*       \brief Abstract class for control object implementation
*
*       This class contains common variables and methods(mostly abstract) with some additional useful logic such as copyconstructors and other.
*/
controlobject::controlobject(const double &ia, const double &ib, const double &ic, const double &id, const double &iy) : a(ia), b(ib), c(ic), d(id), y(iy)
{}

controlobject::controlobject(controlobject*& other) : a(other->a), b(other->b), c(other->c), d(other->d), y(other->y)
{}

controlobject& controlobject::operator=(const controlobject*& other)
{
	this->a = other->a;
	this->b = other->b;
	this->c = other->c;
	this->d = other->d;
	this->y = other->y;
	return *this;
}
```

#### linear.cpp [[return](https://github.com/as005411/MMIPU-2020/tree/dev/trunk/as005411/task_02/doc#controlobjecth-full)]:

```c++
#include "linear.h"

/**
*       \brief Linear controlled object logic implementation.
*
*       Class that contains implementation for linear controlled object logic.
*/
linear::linear(const double &ia, const double &ib, const double &ic, const double &id, const double &iy): controlobject(ia, ib, ic, id, iy)
{}

double& linear::eq(const double &iu)
{
    y = a * y + b * iu;
    return y;
}
```

#### nonlinear.cpp [[return](https://github.com/as005411/MMIPU-2020/tree/dev/trunk/as005411/task_02/doc#controlobjecth-full)]:

```c++
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
```

#### regulator.cpp [[return](https://github.com/as005411/MMIPU-2020/tree/dev/trunk/as005411/task_02/doc#regulatorh-full)]:

```c++
#include "regulator.h"

/**
*       \brief Regulator logic implementation class.
*
*       This class contains Regulator logic implementation.
*/
regulator::regulator(const double &qt) : regulator(qt, 0, 0, 0)
{}

regulator::regulator(const double &qt, double const& ik) : regulator(qt, ik, 0, 0)
{}

regulator::regulator(const double &qt, const double &ik, const double &it) : regulator(qt, ik, it, 0)
{}

regulator::regulator(const double &qt, const double &ik, const double &it, const double &itd) : t0(qt), k(ik), t(it), td(itd)
{
    q0 = k * (1.0 + td / t0);
    q1 = - k * (1.0 + 2.0*td / t0 - t0 / t);
    q2 = k * td / t0;
}

double &regulator::eq(const double &iek)
{
    uk += q0 * iek + q1 * ek1 + q2 * ek2;
    ek2 = ek1;
    ek1 = iek;
    return uk;
}
```

#### model.cpp [[return](https://github.com/as005411/MMIPU-2020/tree/dev/trunk/as005411/task_02/doc#modelh-full)]:

```c++
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
```

