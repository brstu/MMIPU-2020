#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

//linear function realization
void linear(int n, float a, float b, float Y0, float U)
{
	float Y = Y0;
	cout << Y << " ";
	for (int t = 0; t < n; t++)
	{
		Y = a * Y + b * U;
		cout << Y << " ";
	}
	cout << endl;
}
//nonlinear function realization
void nonlinear(int n, float a, float b, float c, float d, float Y, float U)//(10, 1, 0.003, 0.5, 8, 16, 27)
{
	float Y_before = 0;

	cout << Y <<" ";
	
	float Y_after = a * Y - b * pow(Y_before, 2) + c * U + d * sin(U);//1*16 - 0.003*0 + 0.5*27 + 8*sin(27)
	Y_before = Y;
	Y = Y_after;
	
	cout << Y_after << " ";
		
	for (int t = 1; t < n; t++)
	{
		
		Y_after = a * Y - b * pow(Y_before, 2) + c * U + d * sin(U);//1*37.15 - 0.03*16^2 + 0.5*27 + 8*sin(27)
		Y_before = Y;
		Y = Y_after;

		cout << Y_after << " ";
	}
		cout << endl;
}


int main()
{
	cout << "linear model\n";
	linear(10, 1, 0.003, 16, 27);//(int n, float a, float b, float Y0, float U)

	cout << "\nnonlinear model\n";
	nonlinear(10, 1, 0.003, 0.5, 8, 16, 27);//(int n, float a, float b, float c, float d, float Y0, float U)
	cout << endl;

	system("pause");

	return 0;
}