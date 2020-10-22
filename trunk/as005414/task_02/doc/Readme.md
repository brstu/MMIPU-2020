# Laboratory work #2

### Student: Sytoi Zakhar

##### Task 2. PID Controller

In C ++, implement a program that simulates the PID controller discussed above. Use the mathematical model obtained in the previous work as a control object. Use OOP, the program must have at least 3 classes (+ inheritance). The report should also include graphs for different tasks of the object temperature, explain the results obtained (the report can be obtained using Doxygen in chm format).
##### Code:
```c++

#include <iostream>
#include <cmath>


using namespace std;

class Model
{
public:
    virtual double equation(double u_t, double y_t) = 0;
};

class Linear_Model : public Model
{
private:
    double a, b;
public:
    Linear_Model(double a, double b)
    {
        this->a = a;
        this->b = b;
    }

    double equation(double u_t, double y_t) override
    {
        return a * y_t + b * u_t;
    }
};

class Non_Linear_Model : public Model
{
private:
    double a, b, c, d;
    double u_t0 = 0, y_t0 = 0;
public:
    Non_Linear_Model(double a, double b, double c, double d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    double equation(double u_t, double y_t) override
    {
        double y_t1 = a * y_t - b * pow(y_t0, 2) + c * u_t + d * sin(u_t0);
        y_t0 = y_t;
        u_t0 = u_t;
        return y_t1;
    }
};

class Regulator
{
private:
    double K, T, TD, T0;
    double u_t = 0.0;
public:
    Regulator(double K, double T, double TD, double T0)
    {
        this->K = K;
        this->T = T;
        this->TD = TD;
        this->T0 = T0;
    }

    double get_U_t(double e, double e_1, double e_2)
    {
        double q0 = K * (1 + TD / T0);
        double q1 = -K * (1 + (2 * TD / T0) - (T0 / T));
        double q2 = K * TD / T0;

        u_t += q0 * e + q1 * e_1 + q2 * e_2;

        return u_t;
    }

    void Start_PID_Regulator(double w, Model* model, double y_t)
    {
        double e = 0.0, e_1 = 0.0, e_2 = 0.0;

        for (int i = 0; i < 40; i++)
        {
            cout  << e << "\t" << y_t << "\t" << u_t << "\n";

            e = w - y_t;
            get_U_t(e, e_1, e_2);
            y_t = model->equation(u_t, y_t);

            e_2 = e_1;
            e_1 = e;
        }
    }
};

int main()
{
    Regulator* regulator = new Regulator(0.1, 10.0, 50.0, 10.0);
    Linear_Model* linear_model = new Linear_Model(0.33, 0.06);
    regulator->Start_PID_Regulator(25, linear_model, 0);

    cout << "\n\n\n\n\n\n";

    Regulator* regulator2 = new Regulator(0.1, 10.0, 50.0, 10.0);
    Non_Linear_Model* non_linear_model = new Non_Linear_Model(0.24, 0.0002, 0.13, 0.0002);
    regulator2->Start_PID_Regulator(25, non_linear_model, 0);

    return 0;
} 
```
##### Result:
T = 10, T0 = 10, TD = 50, K = 0.1 

linear model (w = 25, a = 0.33, b = 0.06)
   <p>
    <img src="img/linear1.png">
</p>
Nonlinear model (w = 25, a = 0.24, b = 0.0002, c = 0.13, d = 0.0002)
<p>
    <img src="img/nonlinear1.png">
</p>