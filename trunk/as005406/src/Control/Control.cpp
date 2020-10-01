#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


void linear(double a, double b, double yt, double ut);
void nonlinear(double a, double b, double c, double d, double yt, double ut);

int main()
{
    double  a = 1,
        b = 0.01,
        c = 0.5,
        d = 8,
        yt = 30,
        ut = 45;

    linear(a, b, yt, ut);

    nonlinear(a, b, c, d, yt, ut);
    return 0;
}

void linear(double a, double b, double yt, double ut)
{
    double yt1;
    cout << "Linear:" << endl << setw(3) << "i" << setw(10) << "y(t)" << setw(10) << "y(t+1)" << endl;
    for (int i = 0; i < 10; i++)
    {
        yt1 = a * yt + b * ut;
        cout << setw(3) << i + 1 << fixed << setprecision(3) << setw(10) << yt << setw(10) << yt1 << endl;

        yt = yt1;
    }
}

void nonlinear(double a, double b, double c, double d, double yt, double ut)
{
    double yt1, yt0 = 1, ut0 = ut;
    cout << "Nonlinear:" << endl << setw(3) << "i" << setw(10) << "y(t)" << setw(10) << "y(t+1)" << endl;
    for (int i = 0; i < 10; i++)
    {
        yt1 = a * yt - b * yt0 * yt0 + c * ut + d * sin(ut0);
        cout << setw(3) << i + 1 << fixed << setprecision(3) << setw(10) << yt << setw(10) << yt1 << endl;

        yt0 = yt;
        yt = yt1;
    }
}
