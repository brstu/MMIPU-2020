# Laboratory work #2

### Student: Dobrolinskiy Ilya
##### Task 2. PID controller

Write program (C++), that models PID - controller.

PID - controller:

<p align="center">
    <img src="img/schema.png">
</p>


## Project:
<p align="center">
    <img src="img/Project.png">
</p>


##### main.cpp :
```c++
#include<iostream>
#include<math.h>
#include "Regulator.h"
#include "NonLinear.h"
#include "Linear.h"
#include <fstream>
using namespace std;

int main() {
	float w_t = 4;
	float a = 0.3, b = 0.1;
	float a1 = 0.3, b1 = 0.1, c1 = 0.1, d1 = 0.1;
	float K = 0.1, T0 = 10, TD = 50, T = 10;
	float y0 = 1;

	
	Linear *model = new Linear(a, b, y0);//(a, b, y0)
	Regulator* regulator = new Regulator(K, T0, TD, T);//(K, T0, TD, T)
	regulator->PIDRegulator(w_t, regulator, model, y0);//(w_t, regulator, model, y0)

	cout << "\n\n\n\n";

	NonLinear* nl_model = new NonLinear(a1, b1, c1, d1, y0);//(a1, b2, c, d, y0)
	Regulator* nl_regulator = new Regulator(K, T0, TD, T);//(K, T0, TD, T)
	nl_regulator->PIDRegulator(w_t, nl_regulator, nl_model, y0);//(w_t, nl_regulator, nl_model, y0)

	return 0;
}
```

##### Result:
```w(t) = 4 K = 0.1 T0 = 10 TD = 50 T = 10```

##### Linear
 ```a = 0.3 b = 0.1```
<p align="center">
    <img src="img/LinearGraph.png">
</p>

##### Nonlinear
```a = 0.3 b = 0.1 c = 0.1 d = 0.1```
<p align="center">
    <img src="img/NonlinearGraph.png">
</p>