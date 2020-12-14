# Laboratory work #2

### Student: Ignatkevich Alexey
#### Task_2. PID controller

In C ++, implement a program that simulates the PID controller discussed above. Use the mathematical model obtained in the previous work as a control object. Use OOP, the program must have at least 3 classes (+ inheritance). The report also contains graphs for different targets of object temperature.

#### PID - controller:

![Shema](doc/images/shemal.png)

## Code:
```c++
#include<iostream>
#include<math.h>

using namespace std;

class Sample
{
public:
	virtual float equation(float inputWarm, float help) = 0;
};

class regulator
{
private:
	double inputWarm = 0;
	double k, T, TD, T0;
public:
	regulator(const double k, const double T0, const double TD, const double T)
	{
		this->k = k;
		this->T0 = T0;
		this->TD = TD;
		this->T = T;
	}
	double InputWarm(const double a, const double a0 = 0, const double a1 = 0)
	{
		double q0 = k * (1.0 + TD / T0);
		double q1 = -k * (1 + 2.0 * TD / T0 - T0 / T);
		double q2 = k * TD / T0;
		inputWarm += q0 * a + q1 * a0 + q2 * a1;
		return inputWarm;
	}
};

class lineal : public Sample
{
private:
	double one;
	double two;
public:
	lineal(const float one, const float two)
	{
		this->one = one;	this->two = two;
	}

	float equation(float inputWarm, float help) override
	{
		help = one * help + two * inputWarm;
		return help;
	}
};

class notlineal : public Sample
{
private:
	float one, two, three, four;
	float y0 = 0, inpWarm = 0;
public:
	notlineal(double one, double two, double three, double four)
	{
		this->one = one;
		this->two = two;
		this->three = three;
		this->four = four;
	}

	float equation(float inputWarm, float help) override
	{
		double help2;
		help2 = one * help - two * pow(y0, 2) + three * inputWarm + four * sin(inpWarm);
		y0 = help;
		inpWarm = inputWarm;
		return help2;
	}
};

void PID(const double w, double help, regulator* reg, Sample* m)
{
	double a=0.0;
	double a0=0.0;
	double a1=0.0;
	double l;
	l = 0;
	for (int i = 0; i < 500; i++)
	{
		cout << a << "\t\t" << help << "\t\t" << l << endl;
		a = w - help;
		l = reg->InputWarm(a, a0, a1);
		help = m->equation(l, help);
		a1 = a0;
		a0 = a;
	}
}

int main()
{
	cout << "lineal:\nE\t\tY\t\tU\n";

	lineal* lm = new lineal(0.2, 0.1);
	regulator* lr = new regulator(0.5, 5.0, 25.0, 10.0);
	PID(20, 1, lr, lm);

	cout << "\n\nnot lineal:\nE\t\tY\t\tU\n";

	notlineal* nlm = new notlineal(0.1, 0.0001, 0.01, 0.1);
	regulator* nlr = new regulator(0.5, 5.0, 45.0, 10.0);
	PID(25, 0, nlr, nlm);
	return 0;
}
```
## Result:

### Linear model:

![Screenshot LineModel](doc/images/linelexa.jpg)

### Non-linear model:

![Screenshot Non-lineModel](doc/images/nolinelexa.jpg)

## Conclusion:

During the execution of the task, I created a program that simulates the operation of the PID-regulator.
