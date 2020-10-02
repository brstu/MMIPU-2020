# Laboratory work #1

### Student: Isachenka Anton
##### Task 1. Modeling controlled object

Write program (C++), which simulate object temperature.

Linear and nonlinear models:

<p align="center">
    <img src="img/sub_eq.png">
</p>


##### Code:

```c++
#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

//linear function realization
void linear(int n, float a, float b, float Yinit, float InputWarm) {
	float Y = Yinit;
	cout << Y << " ";
	for (int t = 0; t < n; t++) {
		Y = a * Y + b * InputWarm;
		cout << Y << " ";
	}
}
//nonlinear function realization
void nonlinear(int n, float a, float b, float c, float d, float Yinit, float InputWarm) {
	vector<float>v;
	int prevY = 0;
	v.push_back(Yinit);
	float Y = a * Yinit - b * pow(prevY, 2) + c * InputWarm + d * sin(InputWarm);
	v.push_back(Y);
	for (int t = 1; t < n; t++) {

		Y = a * v[t] - b * pow(v[t - 1], 2) + c * InputWarm + d * sin(InputWarm);
		v.push_back(Y);

	}
	for (auto i : v) {
		cout << i << " ";
	}
}

int main() {
	cout << "linear model\n";
	linear(10, 0.9, 0.8, 15, 25);
	cout << "\nnonlinear model\n";
	nonlinear(10, 0.4, 0.3, 0.2, 0.5, 8, 9);
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