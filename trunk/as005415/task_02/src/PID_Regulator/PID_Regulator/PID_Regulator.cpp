#include <iostream>
#include <cmath>


using std::cout;

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

    double get_U_t(double e, double e_0, double e_00)
    {
        double q0 = K * (1 + TD / T0);
        double q1 = -K * (1 + (2 * TD / T0) - (T0 / T));
        double q2 = K * TD / T0;

        u_t += q0 * e + q1 * e_0 + q2 * e_00;

        return u_t;
    }

    void Start_PID_Regulator(double w, Model* model, double y_t)
    {
        double e = 0.0, e_0 = 0.0, e_00 = 0.0;

        for (int i = 0; i < 1000; i++)
        {
            cout  << e << " " << y_t << " " << u_t << "\n";

            e = w - y_t;
            get_U_t(e, e_0, e_00);
            y_t = model->equation(u_t, y_t);

            e_00 = e_0;
            e_0 = e;
        }
    }
};

int main()
{
    Regulator* regulator = new Regulator(0.1, 10.0, 50.0, 10.0);
    Linear_Model* linear_model = new Linear_Model(0.3, 0.05);
    regulator->Start_PID_Regulator(25, linear_model, 0);

    cout << "\n\n";

    Regulator* regulator2 = new Regulator(0.1, 10.0, 50.0, 10.0);
    Non_Linear_Model* non_linear_model = new Non_Linear_Model(0.3, 0.0001, 0.1, 0.0001);
    regulator2->Start_PID_Regulator(25, non_linear_model, 0);

    return 0;
}