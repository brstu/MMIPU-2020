#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class model
{
public:
   virtual float equation(double ut, double yt) = 0;
};

class Linear : public model
{
private:
    float a, b;
    double yt1;
public:
    Linear(float a, float b)
    {
        this->a = a;
        this->b = b;
    }

    float equation(double ut, double yt) override
    {
        double yt1 = a * yt + b * ut;
        return yt1;
    }
};

class Non_Linear: public model
{
private:
    float a, b, c, d;
    double ut0 = 0;
    double yt0 = 0;
    double ut=0;
public:
    Non_Linear(float a, float b, float c, float d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    float equation(double ut, double yt) override
    {
        double yt1 = a * yt - b * yt0 * yt0 + c * ut0 + d * sin(ut);
        yt0 = yt;
        ut0 = ut;
        ut = ut0;
        return yt1;
    }
};

class regulator {
private:
    double K;
    double T0;
    double Td;
    double T;
    double yt;
public:
    regulator(double K, double T0, double Td, double T) {
        this->K = K;
        this->T0 = T0;
        this->Td = Td;
        this->T = T;
    }
    double getyt(double E, double Ep = 0, double Epp = 0) {
        double q0 = K * (1 + Td / T0);
        double q1 = -K * (1 + 2.0 * Td/ T0 - T0 / T);
        double q2 = K * Td/ T0;
        yt += q0 * E + q1 * Ep + q2 * Epp;
        return yt;
    }
};

void pid(double wt, regulator* red, model* lm, double Yi) {
    double E = 0.0, Ep = 0.0, Epp = 0.0;
    double u = 0, y = Yi;
    int k;
    for (k = 0; k < 10; k++) {

        E = wt - y;
        u = reg->getyt(E, Ep, Epp);
        y = lm->equation(u);
        Epp = Ep;
        Ep = E;

    }
}
int main()
{

    Linear* m = new Linear(0.7, 0.35, 1);
    regulator* r = new regulator(12, 12, 54, 0.1);
    pid(2, r, m, 1);
    Non_Linear* nlm = new Non_Linear(1, 0.004, 0.6, 4, 1);
    regulator* nlr = new regulator(10, 10, 50, 0.3);

    pid(2, nlr, nlm, 1);
    return 0;
    std::cout << "Hello World!\n";
}