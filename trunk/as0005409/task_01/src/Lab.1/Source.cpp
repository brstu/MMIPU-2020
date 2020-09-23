#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void linear(float yt, float ut, int a, float b, int n)
{
	float yt1 = 0;
	cout << "y(t)\tu(t)" << endl;
	for (int i = 0; i < n; i++) {
		yt1 = a * yt + b * ut;
		cout << yt1 << "\t" << ut << endl;
		yt = yt1;
	}
}

void nonlinear(float yt, float ut, int a, float b, int c, int d, int n)
{
	float yt0 = 0, yt1;
	cout << "y(t)\t\t\tu(t)" << endl;
	for (int i = 0; i < n; i++) {
		yt1 = a * yt - b * pow(yt0, 2) + c * ut + d * sin(ut);		
		cout <<setprecision(4)<< yt << "\t\t\t" << yt1 << endl;
		yt0 = yt;
		yt = yt1;
	}
}

int main() 
{
	int n = 7, a = 3,  c = 7, d = 9;
	float yt = 5, ut = 8, yt0 = 4 , ut0 = 7, b=0.0005;

	cout << "y(t+1) = a*y(t)+b*u(t)" << endl;
	linear(yt, ut, a, b, n);

	cout << "y(t+1) = a*y(t) - b*y(t-1)^2 + c*u(t) + d*sin(u(t-1))" << endl;
	nonlinear(yt, ut, a, b, c, d, n);
	return 0;
}