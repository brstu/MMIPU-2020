# Laboratory work #1

### Student: Shestakov Mark

##### Task 1. Modeling controlled object

Write program (C++), which simulate object temperature.

Linear and nonlinear models:

![](img\sub_eq.png)


##### Code:

```c++
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>

void linear_equation(double a, double b, double u_t, double y_t);

void non_linear_equation(double a, double b, double c, double d, double u_t, double y_t);

void custom_print(double y_t, double y_t1);

int main()
{
    std::cout << "Linear equation:" << std::endl;
    linear_equation(1, 0.003, 27, 16);

    std::cout << "\nNon linear equation:" << std::endl;
    non_linear_equation(1, 0.003, 0.5, 8, 27, 16);

    return 0;
}

auto linear_equation(const double a, const double b, const double u_t, double y_t) -> void
{
    for (auto i = 0; i <= 10; ++i)
    {
        const auto y_t1 = a * y_t + b * u_t;

        std::cout << "[" << i << "]\t";
        custom_print(y_t, y_t1);

        y_t = y_t1;
    }
}

auto non_linear_equation(const double a, const double b, const double c, const double d, const double u_t,
                         double y_t) -> void
{
    double y_t0 = 0; // Y(t-1)

    for (auto i = 0; i <= 10; ++i)
    {
        const auto y_t1 = a * y_t - b * y_t0 * y_t0 + c * u_t + d * sin(u_t);

        std::cout << "[" << i << "]\t";
        custom_print(y_t, y_t1);

        y_t0 = y_t;
        y_t = y_t1;
    }
}

void custom_print(const double y_t, const double y_t1)
{
    std::ostringstream stream_obj1;
    stream_obj1 << std::fixed;
    stream_obj1 << std::setprecision(4);

    stream_obj1 << y_t;
    const auto y_t_str = stream_obj1.str();

    std::ostringstream stream_obj2;
    stream_obj2 << std::fixed;
    stream_obj2 << std::setprecision(4);

    stream_obj2 << y_t1;
    const auto y_t1_str = stream_obj2.str();

    std::cout << "y(t) = " << y_t_str << "\t y(t+1) = " << y_t1_str << std::endl;
}
```

##### Result:

![](img\result.png)