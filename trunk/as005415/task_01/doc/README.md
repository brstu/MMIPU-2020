# Laboratory work #1

### Student: Shestakov Mark

##### Task 1. Modeling controlled object

Write program (C++), which simulate object temperature.

Linear and nonlinear models:

1. $$
   {y_{t+1}} = ay_t + bu_t
   $$

2. 

2. $$
   {y_{t+1}} = ay_t - by^2_{t-1} + cu_t + d\sin(u_{t-1})
   $$



##### Code:

```c++
#include <iostream>
#include <cmath>

void linearEquation(double a, double b, double u_t, double y_t);

void nonLinearEquation(double a, double b, double c, double d, double u_t, double y_t);

int main() {
    std::cout << "Linear equation:" << std::endl;
    linearEquation(1, 0.003, 27, 16);

    std::cout << "Non linear equation:" << std::endl;
    nonLinearEquation(1, 0.003, 0.5, 8, 27, 16);
    return 0;
}

void linearEquation(double a, double b, double u_t, double y_t) {
    double y_t1; // Y(t+1)

    for (int i = 0; i <= 10; ++i) {
        y_t1 = a * y_t + b * u_t;
        std::cout << "[" << i << "] " << "y(t) = " << y_t << "\t\t y(t+1) = " << y_t1 << std::endl;
        y_t = y_t1;
    }
}

void nonLinearEquation(double a, double b, double c, double d, double u_t, double y_t) {
    double y_t0 = 0; // Y(t-1)
    double y_t1; // Y(t+1)

    for (int i = 0; i <= 10; ++i) {
        y_t1 = a * y_t - b * y_t0 * y_t0 + c * u_t + d * sin(u_t);
        std::cout << "[" << i << "] " << "y(t) = " << y_t << "\t\t y(t+1) = " << y_t1 << std::endl;
        y_t0 = y_t;
        y_t = y_t1;
    }
}
```

