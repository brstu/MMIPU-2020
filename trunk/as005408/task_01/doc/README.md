# Laboratory work #1

### Student: Kunitskiy Alexander

##### Task 1. Modeling controlled object

Write program (C++), which simulate object temperature.

Linear and nonlinear models:

<p align="center">
    <img src="img/sub_eq.png"
</p>


##### Code:

```c++
#include <iostream>
#include <cmath>
using namespace std;

void linearEquation(double a, double b, double y_t, double u_t);
void nonLinearEquation(double a, double b, double c, double d, double y_t, double u_t);

int main()
{
	linearEquation(1,0.003,16,27);
	cout << endl;
	nonLinearEquation(1, 0.003, 0.5, 8, 16, 27);
}

void linearEquation(double a, double b, double y_t, double u_t) {

	cout << "Linear model: " << endl;

	for (int i = 0; i < 10; i++)
	{
		double y_t1 = a*y_t + b*u_t;
		cout << "[" << i+1 << "]" << " " << "y(t)= " << y_t << " " << "y(t+1)= " << y_t1 << endl;
		y_t = y_t1;
	}
}

void nonLinearEquation(double a, double b, double c, double d, double y_t, double u_t) {

	cout << "Non Linear Model: " << endl;

	double y_t0 = 0;
	double u_t0 = u_t;

	for (int i = 0; i < 10; i++)
	{
		double y_t1 = a * y_t - b * y_t0 * y_t0 + c * u_t + d * sin(u_t0);
		cout << "[" << i+1 << "]" << " " << "y(t)= " << y_t << " " << "y(t+1)= " << y_t1 << endl;
		y_t0 = y_t;
		y_t = y_t1;
	}
}
```

##### Result:

Linear model|Non Linear Model
---|---
16.081|37.151
16.162|57.534
16.243|74.544
16.324|85.765
16.405|90.245
16.486|89.330
16.567|86.048
16.648|83.260
16.729|82.198
16.810|82.552
