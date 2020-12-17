#include<iostream>
#include<math.h>

using namespace std;

class Pattern
{
public:
	virtual double expression(double Warmth, double temp) = 0;
};

class device_of_regulation
{
private:
	double warmth = 0;
	double F;
	double tmp;
	double tmp_d;
	double tmp_0;
public:
	device_of_regulation(const double F, const double tmp_0, const double tmp_d, const double tmp)
	{
		this->F = F;
		this->tmp_0 = tmp_0;
		this->tmp_d = tmp_d;
		this->tmp = tmp;
	}
	double Warmth(const double q_1, const double q_2 = 0, const double q_3 = 0)
	{
		double vr_0;
		double vr_1;
		double vr_2;
		vr_0 = F * (1.0 + tmp_d / tmp_0);
		vr_1 = -F * (1 + 2.0 * tmp_d / tmp_0 - tmp_0 / tmp);
		vr_2 = F * tmp_d / tmp_0;
		warmth += +vr_0 * q_1 + vr_1 * q_2 + vr_2 * q_3;
		return warmth;
	}
};

class line : public Pattern
{
private:
	double first;
	double second;
public:
	line(const double first, const double second)
	{
		this->first = first;
		this->second = second;
	}

	double expression(double warmth, double temp) override
	{
		temp = first * temp + second * warmth;
		return temp;
	}
};

class noline : public Pattern
{
private:
	double first;
	double second;
	double third;
	double fourth;
	double init_temp = 0;
	double init_warmth = 0;
public:
	noline(double first, double second, double third, double fourth)
	{
		this->first = first;
		this->second = second;
		this->third = third;
		this->fourth = fourth;
	}

	double expression(double warmth, double temp) override
	{
		double fir_temp;
		fir_temp = first * temp - second * pow(init_temp, 2) + third * warmth + fourth * sin(init_warmth);
		init_temp = temp;
		init_warmth = warmth;
		return fir_temp;
	}
};

void proportional_integral_derivative(const double fir, device_of_regulation* lan, Pattern* f, double temp)
{
	double q_1;
	double q_2;
	double q_3;
	double l;
	q_1 = 0.0,
	q_2 = 0.0,
	q_3 = 0.0;
	l = 0;
	for (int i = 0; i < 70; i++)
	{
		cout << q_1 << "\t\t" << temp << "\t\t" << l << endl;
		q_1 = fir - temp;
		l = lan->Warmth(q_1, q_2, q_3);
		temp = f->expression(l, temp);
		q_3 = q_2;
		q_2 = q_1;
	}
}

int main()
{
	cout << "line:\nE\t\tY\t\tU\n";

	line* temp_0 = new line(0.1, 0.05);
	device_of_regulation* temp_1 = new device_of_regulation(0.5, 5.0, 35.0, 10.0);
	proportional_integral_derivative(25, temp_1, temp_0, 0);

	cout << "\n\nnoline:\nE\t\tY\t\tU\n";

	noline* temp_2 = new noline(0.1, 0.0001, 0.1, 0.0001);
	device_of_regulation* temp_3 = new device_of_regulation(0.5, 5.0, 35.0, 7.0);
	proportional_integral_derivative(25, temp_3, temp_2, 0);
	return 0;
}