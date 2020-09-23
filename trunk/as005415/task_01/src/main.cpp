#include <iostream>

void linearEquation(double a, double b, double u_t, double y_t);

int main() {
    std::cout << "Linear equation:" << std::endl;
    linearEquation(10, 5, 0.1, 8);

    return 0;
}

void linearEquation(double a, double b, double u_t, double y_t) {
    double y_t1;

    for (int i = 0; i <= 10; ++i) {
        y_t1 = a * y_t + b * u_t;
        std::cout << "[" << i << "] " << "y(t) = " << y_t << "\t\t y(t+1) = " << y_t1 << std::endl;
        y_t = y_t1;
    }
}