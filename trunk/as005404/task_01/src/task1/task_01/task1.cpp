
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
	cout << "\nonlinear model\n";
	nonlinear(10, 0.4, 0.3, 0.2, 0.5, 8, 9);
	return 0;
}
