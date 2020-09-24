#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


void linear(float y_t, float u_t, int a, float b);
void nonLinear(float y_t, float u_t, int a, float b, int c, int d);


int main()
{
	int a = 1, c = 2, d = 3;
	float y_t = 5, u_t = 8, b = 0.0005;
	linear(y_t, u_t, a, b);
	nonLinear(y_t, u_t, a, b, c, d);
	return 0;
}

void linear(float y_t, float u_t, int a, float b)
{
	float y_t1 = 0;
	cout << "By linear equation: \n>>>>>\t\t\t\t<<<<<" << endl;
	cout << "y(t)\t\t\t\ty(t+1)" << endl;
	for (int i = 0; i < 10; i++) {
		y_t1 = a * y_t + b * u_t;
		cout << "No:" << i + 1 << "\t" << setprecision(4) << y_t << "\t\t\t" << y_t1 << endl;
		y_t = y_t1;
	}
}

void nonLinear(float y_t, float u_t, int a, float b, int c, int d)
{
	float y_t0 = 0, y_t1;
	cout << "By non-linear equation: \n>>>>>\t\t\t\t<<<<<" << endl;
	cout << "y(t)\t\t\t\ty(t+1)" << endl;
	for (int i = 0; i < 10; i++) {
		y_t1 = a * y_t - b * pow(y_t0, 2) + c * u_t + d * sin(u_t);
		cout <<"No:"<<i+1<<"\t"<< setprecision(4) << y_t << "\t\t\t" << y_t1 << endl;
		y_t0 = y_t;
		y_t = y_t1;
	}
}