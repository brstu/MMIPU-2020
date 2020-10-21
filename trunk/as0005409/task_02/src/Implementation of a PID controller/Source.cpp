#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

class model
{
public:
    virtual float equation(float yt, float ut) = 0;
};

class linear : public model
{
private:
    int a;
    float b,yt1;
public:
    linear(int a, float b)
    {
        this->a = a;
        this->b = b;
    }

    float equation(float yt, float ut) 
    {
        yt1 = a * yt + b * ut;
        return yt1;
    }
};

class nonlinear : public model
{
private:
    int a, c, d;
    float b;
    float yt0 = 0, yt1;
public:
    nonlinear(int a, float b, int c, int d)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }

    float equation(float yt, float ut)
    {
        yt1 = a * yt - b * pow(yt0, 2) + c * ut + d * sin(ut);
        yt0 = yt;
        yt = yt1;
        return yt1;
    }
};

int main()
{
    int n = 7, a = 3, c = 7, d = 9;
    float yt = 5, ut = 8, yt0 = 4, ut0 = 7, b = 0.0005;
    return 0;
}