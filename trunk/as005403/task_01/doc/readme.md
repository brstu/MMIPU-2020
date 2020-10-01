# Laboratory work #1

### Student: Isachenka Anton
##### Task 1. Modeling controlled object

Write program (C++), which simulate object temperature.

Linear and nonlinear models:

<p align="center">
    <img src="img/Linear and nonlinear models.png">
</p>


##### Code:

```c++
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
```

##### Result:

id | Linear model | NonLinear model
---------  |------------ | -------------
1|15 | 16 
2| 33.5  | 37.151 
3|50.15|57.534 
4| 65.135 |74.5444 
5|78.6215 |85.765 
6|90.7593 |90.2453 
7|101.683|89.3295 
8| 111.515 |86.0478 
9|120.364 |83.2596 
10|128.327 |82.1979 
11|135.494|82.5524