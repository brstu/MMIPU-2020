# First lab
Hanna Akalatovich, AC-54и\
**Purpose**: to write C++ program which simulates this object temperature.
##### Task 1. Modeling controlled object

Write program (C++), which simulate object temperature.

Linear and nonlinear models:

<p align="center">
<img src="images/img2.png" alt="models">
</p>


##### Function for linear model:
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
```
##### Result (a = 1 ; b = 2 ):
y1 | u0  
---  | ---   
3 | 4  
11 | 4  
19 | 4  
27 | 4  
35 | 4  
43 | 4  
51 | 4  
59 | 4  
67 | 4  
75 | 4  
83 | 4 


##### Function for nonlinear model:
```c++

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

##### Result (a = 1; b = 0.2 ; c = 0.4 ; d = 0.1 ):
y1  |            y0         |     u1    |          u0
---  | ---| ---  | --- 
0.2        |     0.1        |     4          |     3
1.45445     |    0.2        |     4         |      3
2.7029      |    1.45445    |     4         |      3
3.53626     |    2.7029     |     4        |       3
3.33158     |    3.53626    |     4        |       3
2.087       |    3.33158    |     4        |       3
1.12356    |     2.087     |      4         |      3
1.5089      |    1.12356   |      4       |        3
2.51287    |     1.5089     |     4        |       3
3.31396    |     2.51287    |     4        |       3
3.30751    |     3.31396     |    4        |       3


**Conclusion**: I have learned how to work with git and I using git systems I uploaded my cpp file and made the report in readme.md file

