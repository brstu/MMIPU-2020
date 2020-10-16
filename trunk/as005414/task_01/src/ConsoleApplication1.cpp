#include <iostream>

using namespace std;
void linearSimulation(double a, double b, double u, double y) {
    double y1;
    for (int i = 0; i <= 10; ++i) {
        y1 = a * y + b * u;
        cout << "Iteration:\t" << i << "\t y(t) = " << y << "\t y(t+1) = " << y1 << endl;
        y = y1;
    }
}


void nonLinearSimulation(double a, double b, double c, double d, double u, double y) {
    double y0 = 0; 
    double y1; 
    for (int i = 0; i <= 10; ++i) {
        y1 = a * y - b * y0 * y0 + c * u + d * sin(u);
        cout << "Iteration:\t" << i << "\t y(t) = " << y << "\t y(t+1) = " << y1 << endl;
        y0 = y;
        y = y1;
    }
}


int main() {
    cout << "Linear simulation:" << endl;
    linearSimulation(1, 0.37, 3.6, 18);
    cout << "\n";
    cout << "Non linear simulation:" <<endl;
    nonLinearSimulation(1, 0.0019, 0.5, 3, 5.8, 18);
    return 0;
}
