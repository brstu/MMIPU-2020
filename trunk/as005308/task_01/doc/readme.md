**Student: Demidovich Anna AS-53**
_Task 1.
Modeling controlled object. Write program (C++). With help Linear and Nonlinear models._

![Screenshot of Task](main_eq.png)

![Screenshot of Task](sub_eq.png)


**Program code:**

```
#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	float a = 1, c = 2, d = 3, b = 0.003;
	float y = 0; 
	float u = 0;
	int n = 10;

	cout << "Input value u:";
	cin >> u;

	cout << "Linear equation:" << endl;  
	for (int i = 0; i <= n; i++)
	{
		y = a * y + b * u;
		cout << i << " - y(t)=" << y << endl;
	}

	cout << endl;

	cout << "Nonlinear equation:" << endl;

	for (int i = 0; i <= n; i++)
	{
		y = a * y - b * pow(y,2) + c * u + d * sin(u);
		cout << i << " y(t)=" << y << endl;
	}
	return 0;
}

```

###### **Result:**


**_LineEqation and NonLineEquation_**

![Screenshot LineModel](screenshot.PNG)

