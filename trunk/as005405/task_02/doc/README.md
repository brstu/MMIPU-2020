<h1>Laboratory work #2</h1>
<h2>Student: Kalita Ekaterina</h2>
<h3>Task 2. Modeling PID Regulator</h3>
Write program (C++), using these formulas and previous ones(from task1).

![alt text](https://github.com/brstu/MMIPU-2020/blob/master/tasks/task_02/images/1.png)

<h5>Code:</h5>


```C++
#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>

/*!
    \author Kalita E.U.
    \date November 2020
*/


using namespace std;

/*!
    \brief Main abstract class

    This is abstract class which include virtual method for chield's classes.
*/

class model
{
public:

    /*!
    This is virtual method which other classes need for implement
    \param yt Input Warm
    \param ut Output value
    */

    virtual float equation(float yt, float ut) = 0;
};

/*!
    \brief Linear function class

    It's a linear function class which include method for calculate linear function.
*/

class linear : public model
{
private:

    float a, b, yt_1;

public:

    /*!
    Constructor for Linear function class
      \param a,b coefficients
    */

    linear(float a, float b)
    {
        this->a = a;
        this->b = b;
    }

    /*!
    This function calculates our linear model
        \param yt Input Warm
        \param ut Output variable
        \return yt_1 calculated value

        Function code:
     \code
    float equation(float yt,float ut) override {
          return yt_1 = a * yt + b * ut;
        }
     \endcode
        */

    float equation(float yt, float ut)
    {
        yt_1 = a * yt + b * ut;
        return yt_1;
    }
};

/*!
    \brief NonLineer function class

    This is nonlinear function class which include method for calculate nonlinear function.
*/

class nonlinear : public model
{
private:

    float a, c, d, b;
    float yt_0 = 0, yt_1;
    float ut_0 = 0;

public:

    /*!
    Constructor for Nonlinear function class
      \param a,b,c,d coefficients
    */

    nonlinear(float a, float b, float c, float d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    /*!
     This function calculates our nonlinear model
        \param yt Input Warm
        \param ut Output variable
        \return yt_1 calculated value

     Function code:
     \code
    float equation(float yt, float ut)
    {
        yt_1 = a * yt - b * pow(yt_0, 2) + c * ut + d * sin(ut_0);
        ut_0 = ut;
        yt_0 = yt;
        yt = yt_1;

        return yt_1;

    }
     \endcode
*/


    float equation(float yt, float ut)
    {
        yt_1 = a * yt - b * pow(yt_0, 2) + c * ut + d * sin(ut_0);
        ut_0 = ut;
        yt_0 = yt;
        yt = yt_1;

        return yt_1;

    }
};

/*!
    \brief Regulator class

    This is Regulator class which include method for calculate input warm(ut)
*/

class regulator
{

private:

    float T, T0, TD, K, yt_1 = 0;

public:
     
    /*!
    Constructor for Regulator
      \param T,T0,TD,K coefficients
      
*/

    regulator(float T, float T0, float TD, float K) {
        this->T = T;
        this->T0 = T0;
        this->TD = TD;
        this->K = K;
    }

    /*!
    This function calculates our linear model
        \param yt Input Warm(calculated value)
        \return yt_1 calculated value

        Function code:
     \code
   
       float warm(float e, float em1, float em2) {

        float q0 = K * (1 + TD / T0);
        float q1 = -K * (1 + 2 * TD / T0 - T0 / T);
        float q2 = K * TD / T0;
        yt_1 += q0 * e + q1 * em1 + q2 * em2;

        return yt_1;
    }
    }
    \endcode
        */

    float warm(float e, float em1, float em2) {

        float q0 = K * (1 + TD / T0);
        float q1 = -K * (1 + 2 * TD / T0 - T0 / T);
        float q2 = K * TD / T0;
        
        yt_1 += q0 * e + q1 * em1 + q2 * em2;
   
        return yt_1;
    }
};

/*!
This function starts our PID regulator
\param Model some model(linear or nonlinear)
\param Regulator our regulator
*/

void PIDregulator(float w, float y0, regulator* reg, model* md) {

    float e = 0, em1 = 0, em2 = 0, u = 0, y = y0;
   

    for (int i = 0; i < 100; i++) {
      
        e = w - y;
        u = reg->warm(e, em1, em2);
        y = md->equation(y0, u);

        cout << "E=" << e << " Y=" << y << " U=" << u << endl;

        em2 = em1;
        em1 = e;
    }

}

/// Main function which includes all variables(coefficients), objects, and functions calls. 


int main()
{
    cout << "Linear Model:" << endl;

    linear* l = new linear(0.3, 0.7);
    regulator* rl = new regulator(10, 10, 50, 0.1);
    PIDregulator(3, 2, rl, l);

    cout << endl;
    cout << "NonLinear Model:" << endl;

    nonlinear* nl = new nonlinear(1, 0.003, 0.5, 0.5);

    regulator* rnl = new regulator(10, 15, 55, 0.1);

    PIDregulator(3, 2, rnl, nl);
    return 0;
}
```
<h3>Graphics: </h3>

my Excel died and does not want to make graphics with all my desire
sorry


<h6>But i can show you the result of compiling my program</h6>

![alt text](https://github.com/as005405/MMIPU-2020/blob/master/trunk/as005405/task_02/doc/img/ToHRqZ10GN8.jpg)
<h6> . </h6>
<h6> . </h6>
<h6> . </h6>
![alt text](https://github.com/as005405/MMIPU-2020/blob/master/trunk/as005405/task_02/doc/img/ToHRqZ10GN8.jpg)
<h6> . </h6>
<h6> . </h6>
<h6> . </h6>

