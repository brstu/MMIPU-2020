<h1> Laboratory work #1</h1>


<h3>Student: Kalita Ekaterina</h3>

<h4>Task 1.</h4> 
 Modeling controlled object. Write program (C++). With help Linear and Nonlinear models.
 
 ![alt text](https://github.com/as005405/MMIPU-2020/blob/master/trunk/as005405/task_01/Images/main_eq.png)

<h4>Code:</h4>

```C++
#include <iostream>
#include <cmath>

using namespace std;


void linear(double a, double b, double ut, double yt);
void NoLinear(double a, double b, double c, double d, double ut, double yt);

int main() {
    cout << "-------------------------------------------" << endl;
    cout << "Linear equation:" << endl;
    linear(1, 0.0056, 0.75, 2);

    cout << "-----------------------------------------------------------" << endl;
    cout << "Nonlinear equation:" << endl;
    NoLinear(1, 0.0056, 0.75, 2, 13, 3);
}

void linear(double a, double b, double ut, double yt) {
    double yt1; // This is - y(t+1)
    cout << "-------------------------------------------" << endl;
    
    for (int i = 0; i <= 10; ++i) {
        yt1 = a * yt + b * ut;
        yt = yt1;
        cout <<"y(t"<< i <<") = " << yt << "\t\t\t y(t+1) = " << yt1 << endl;
    }
}

void NoLinear(double a, double b, double c, double d, double ut, double yt) {
    double yt0 = 0; // This is - y(t+1)
    double yt1; // This is - y(t+1)
    cout << "-----------------------------------------------------------" << endl;
    for (int i = 0; i <= 10; ++i) {
        yt1 = a * yt - b * yt0 * yt0 + c * ut + d * sin(ut);
        yt0 = yt;
        yt = yt1;
        cout << "y(t"<<i<<")"<<" = "<< yt << "\t\t\t y(t+1) = " << yt1 << endl;
    }
}
```
  
  
<h3>Result: </h3>

<h4>Linear equation: </h4>

y(t)                     |        y(t+1)           |
-------------------------|--------------------------
y(t0) = 2.0042           |        y(t+1) = 2.0042  |
y(t1) = 2.0084           |        y(t+1) = 2.0084  |
y(t2) = 2.0126           |        y(t+1) = 2.0126  |
y(t3) = 2.0168           |        y(t+1) = 2.0168  |
y(t4) = 2.021            |        y(t+1) = 2.021   |
y(t5) = 2.0252           |        y(t+1) = 2.0252  |
y(t6) = 2.0294           |        y(t+1) = 2.0294  |
y(t7) = 2.0336           |        y(t+1) = 2.0336  |
y(t8) = 2.0378           |        y(t+1) = 2.0378  |
y(t9) = 2.042            |        y(t+1) = 2.042   |
y(t10) = 2.0462          |        y(t+1) = 2.0462  |

<h4>Non Linear equation: </h4>

y(t)                     |        y(t+1)            |
-------------------------|---------------------------
y(t0) = 13.5903          |        y(t+1) = 13.5903  |
y(t1) = 24.1303          |        y(t+1) = 24.1303  |
y(t2) = 33.6863          |        y(t+1) = 33.6863  |
y(t3) = 41.0159          |        y(t+1) = 41.0159  |
y(t4) = 45.2516          |        y(t+1) = 45.2516  |
y(t5) = 46.421           |        y(t+1) = 46.421   |
y(t6) = 45.5442          |        y(t+1) = 45.5442  |
y(t7) = 44.067           |        y(t+1) = 44.067   |
y(t8) = 43.0414          |        y(t+1) = 43.0414  |
y(t9) = 42.7571          |        y(t+1) = 42.7571  |
y(t10) = 42.9731         |        y(t+1) = 42.9731  |
