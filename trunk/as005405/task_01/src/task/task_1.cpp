#include <iostream>
#include <cmath>

using namespace std;


void linear(double a, double b, double ut, double yt);
void NoLinear(double a, double b, double c, double d, double ut, double yt);

int main() {
    cout << "-------------------------------------------" << endl;
    cout << "Linear equation:" << endl;
    linear(1, 0.0056, 0.75, 2);

    cout << "-----------------------------------------------------------" << endl;
    cout << "Nonlinear equation:" << endl;
    NoLinear(1, 0.0056, 0.75, 2, 13, 3);
}

void linear(double a, double b, double ut, double yt) {
    double yt1; // This is - y(t+1)
    cout << "-------------------------------------------" << endl;
    
    for (int i = 0; i <= 10; ++i) {
        yt1 = a * yt + b * ut;
        yt = yt1;
        cout <<"y(t"<< i <<") = " << yt << "\t\t\t y(t+1) = " << yt1 << endl;
    }
}

void NoLinear(double a, double b, double c, double d, double ut, double yt) {
    double yt0 = 0; // This is - y(t+1)
    double yt1; // This is - y(t+1)
    cout << "-----------------------------------------------------------" << endl;
    for (int i = 0; i <= 10; ++i) {
        yt1 = a * yt - b * yt0 * yt0 + c * ut + d * sin(ut);
        yt0 = yt;
        yt = yt1;
        cout << "y(t"<<i<<")"<<" = "<< yt << "\t\t\t y(t+1) = " << yt1 << endl;
    }
}