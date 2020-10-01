#include <iostream>

using namespace std;

void linearEquation(double a, double b, double y_t, double u_t);
void nonLinearEquation(double a, double b, double c, double d, double y_t, double u_t);

int main()
{
	linearEquation(1,0.0003,16,27);
}

void linearEquation(double a, double b, double y_t, double u_t) {

	cout << "Linear model: " << endl;

	for (int i = 0; i < 10; i++)
	{
		double y_t1 = a*y_t + b*u_t;
		cout << "[" << i << "]" << " " << "y(t)= " << y_t << " " << "y(t+1)= " << y_t1 << endl;
		y_t = y_t1;
	}
}

/*void nonLinearEquation(double a, double b, double c, double d, double y_t, double u_t) {

}*/