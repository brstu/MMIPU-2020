#include <iostream>
#include <cmath>

class Model
{
public:
    virtual float equation(double u_t, double y_t) = 0;
};

class Linear_Model : public Model
{
private:
    float a, b;
public:
    Linear_Model(float a, float b)
    {
        this->a = a;
        this->b = b;
    }
    
    float equation(double u_t, double y_t) override
    {
        return a * y_t + b * u_t;
    }
};

class Non_Linear_Model : public Model
{
private:
    float a, b, c, d;
    double u_t0 = 0, y_t0 = 0;
public:
    Non_Linear_Model(float a, float b, float c, float d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    float equation(double u_t, double y_t) override
    {
        double y_t1 = a * y_t - b * pow(y_t0, 2) + c * u_t + d * sin(u_t0);
        y_t0 = y_t;
        u_t0 = u_t;
        return y_t1;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    return 0;
}