#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
/*!
\brief class model need to inheritance to linear and nonlinear classes.
*/
class model
{
/*!
virtual undefined function that will be overriden in inherited classes
\params yt,ut.
\return 0,cuz this function will override in others classes
*/
public:
    virtual float equation(float yt, float ut) = 0;
};
/*!
\brief class linear inherits the model class,
and further in the class the equation function is redefined,
which are in the model class.

Also in this class there is a constructor, 
and class fields are defined for initializing parameters
that will be passed to the constructor and will be used in the function
*/
class linear : public model
{
private:
    float a, b, yt1;
public:
    /*!
    Construct for class linear
    \param a,b
    */
    linear(float a, float b)
    {
        this->a = a;
        this->b = b;
    }
    /*!
Linear equation
\param yt,ut
\return result of linear equation
*/
    float equation(float yt, float ut)
    {
        yt1 = a * yt + b * ut;
        return yt1;
    }
};
/*!
\brief class nonlinear inherits the model class,
and further in the class the equation function is redefined,
which are in the model class.

Also in this class there is a constructor,
and class fields are defined for initializing parameters
that will be passed to the constructor and will be used in the function
*/
class nonlinear : public model
{
private:
    float a, c, d, b;
    float yt0 = 0, yt1;
    float ut0 = 0;
public:
    /*!
   Construct for class nonlinear
   \param a,b,c,d
   */
    nonlinear(float a, float b, float c, float d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    /*!
    NonLinear equation
    \param yt,ut
    \return result of nonlinear equation
    */
    float equation(float yt, float ut)
    {
        yt1 = a * yt - b * pow(yt0, 2) + c * ut + d * sin(ut0);
        ut0 = ut;
        yt0 = yt;
        yt = yt1;
        return yt1;
    }
};
/*!
\brief class regulator

Also in this class there is a constructor,
and class fields are defined for initializing parameters
that will be passed to the constructor and will be used in the function
*/
class regulator
{
private:
    float T, T0, TD, K, yt1 = 0;
public: 
    /*!
   Construct for class regulator
   \param T,T0,TD,K
   */
    regulator(float T, float T0, float TD, float K) {
        this->T = T;
        this->T0 = T0;
        this->TD = TD;
        this->K = K;
    }
    /*!
      PID control algorithm
      \param e,em1,em2
      \return result of PID control
    */
    float warm(float e, float em1, float em2) {
        float q0 = K * (1 + TD / T0);
        float q1 = -K * (1 + 2 * TD / T0 - T0 / T);
        float q2 = K * TD / T0;
        yt1 += q0 * e + q1 * em1 + q2 * em2;
        return yt1;
    }
};
    /*This function which start our PIDregulator
      \param w,y0,*reg,*md
    */
    void PIDregulator(float w, float y0, regulator *reg, model *md) {
        float e = 0, em1 = 0, em2 = 0, u = 0, y = y0;
        for (int i = 0; i < 1000; i++) {
            e = w - y;
            u = reg->warm(e, em1, em2);
            y = md->equation(y0, u);
            cout << "E=" << e << " Y=" << y << " U=" << u << endl;
            em2 = em1;
            em1 = e;
        }
    }
    //Main function in program in which we create a new objects and calls functions.

int main()
{
    cout << "Linear Model:" << endl;
    linear* l = new linear(0.3, 0.7);
    regulator* rl = new regulator(10, 10, 50, 0.1);
    PIDregulator(3, 2, rl, l);
    cout << endl;
    cout << "NonLinear Model:" << endl;
    nonlinear* nl = new nonlinear(1, 0.003, 0.5, 0.5);
    regulator* rnl = new regulator(10, 10, 50, 0.1);
    PIDregulator(3, 2, rnl, nl);
    return 0;
}