# First lab
Hanna Akalatovich, AC-54и\
**Purpose**: to write C++ program which simulates this object temperature.
##### Task 1. Modeling controlled object

Write program (C++), which simulate object temperature.

Linear and nonlinear models:

<p align="center">
<img rel="images/img2.png" alt="models">
</p>


##### Code:
```c++
void linearModel(int a, int b, float y0, float u0) {
	cout << "a=" << a << "," << "b=" << b << endl;
	cout << "y(t+1)=a*y(t)+b*u(t)\n";
	cout << "y1\tu0\n";
	cout << y0 << "\t" << u0 << endl;

	for (int i = 0; i < 10; i++) {
		y0 = a * y0 + b * u0;
		cout << y0 << "\t" << u0 << endl;
	}
}

void nonlinearModel(int a, int b, int c, int d, float y0, float y1, float u0, float u1) {
	float y2 = 0;
	cout << "y(t+1)=a*y(t)-b*(y(t-1))^2+cu(t)+d*sin(u(t-1))\n";
	cout << "y1\t\ty0\t\tu1\t\tu0\n";
	cout << y1 << "\t\t" << y0 << "\t\t" << u1 << "\t\t" << u0 << endl;

	for (int i = 0; i < 10; i++) {
		y2 = a * y1 - b * pow(y0, 2) + c * u1 + d * sin(u0);
		y0 = y1;
		y1 = y2;
		cout << y1 << "\t\t" << y0 << "\t\t" << u1 << "\t\t" << u0 << endl;
	}
}
```
<p align="center">
<img rel="images/result.jpg" alt="result">
</p>

**Conclusion**: I have learhed how to work with git and I using git systems I uploaded my cpp file and made the report in readme.md file

