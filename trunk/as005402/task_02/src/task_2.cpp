#include <iostream>
#include<math.h>

using namespace std;

class Model
{
public:
	virtual float equation(double inpWarm, double y) = 0;
};

class LinearModel : public Model {
private:
	float a, b;

public:
	LinearModel(const float a, const float b) {this->a = a; this->b = b;}
	float equation(double inpWarm, double y) override {
		y = a * y + b * inpWarm;
		return y;
	}
};


class NonLinearModel : public Model {
private:
	float a, b, c, d;
	double y0 = 0, inpWarm0 = 0;

public:
	NonLinearModel(float a, float b, float c, float d) {this->a = a; this->b = b; this->c = c; this->d = d;}
	float equation(double inpWarm, double y) override {
		double y1 = a * y - b * pow(y0, 2) + c * inpWarm + d * sin(inpWarm0);
		y0 = y;
		inpWarm0 = inpWarm;
		return y1;
	}
};

class Regulator {
private:
	double inpWarm = 0;
	double K, T, TD, T0;

public:
	Regulator(const double K, const double T0, const double TD, const double T) {this->K = K; this->T0 = T0; this->TD = TD; this->T = T;}
	double InpWarm(const double e, const double e0 = 0, const double e00 = 0) {
		double q0 = K * (1.0 + TD / T0);
		double q1 = -K * (1 + 2.0 * TD / T0 - T0 / T);
		double q2 = K * TD / T0;
		inpWarm += q0 * e + q1 * e0 + q2 * e00;
		return inpWarm;
	}
};

void PIDRegulator(const double w, Regulator* reg, Model* m, double y) {
	double e = 0.0, e0 = 0.0, e00 = 0.0;
	double u = 0;
	for (int k = 0; k < 50; k++) {
		cout << e << "\t\t" << y << "\t\t" << u << endl;
		e = w - y;
		u = reg->InpWarm(e, e0, e00);
		y = m->equation(u, y);
		e00 = e0;
		e0 = e;
	}
}

int main()
{
	cout << "Linear model:\nE\t\tY\t\tU\n";
	LinearModel* m = new LinearModel(0.1, 0.05);
	Regulator* r = new Regulator(0.5, 5.0, 35.0, 10.0);
	PIDRegulator(25, r, m, 0);

	cout << "\n\nNonlinear model:\nE\t\tY\t\tU\n";

	NonLinearModel* nlm = new NonLinearModel(0.1, 0.0001, 0.1, 0.0001);
	Regulator* nlr = new Regulator(0.5, 5.0, 35.0, 7.0); 
	PIDRegulator(25, nlr, nlm, 0);

	return 0;
}
