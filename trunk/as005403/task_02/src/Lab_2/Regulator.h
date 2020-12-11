#pragma once
#include"Model.h"
/*!
	\brief class that implements Regulator Gr
*/
class Regulator
{
private:
	double U = 0;
	double K, T0, TD, T;
public:
	/*!
		Constructor for Regulator class
		\param K,T0,TD,T coefficients
	*/
	Regulator(const double K, const double T0, const double TD, const double T);
	/*!
		\brief function that calculate u(t) and returns it
		\param E,E0,E0prev values of current, previous and the before previous one errors
		\return InputWarm u(t)
	*/
	double get_Ut(const double E, const double E0 = 0, const double E0prev = 0);
	/*!
	\brief function that simulates a PID controller and outputs in .csv file the results
	\param w some desired value
	\param *reg pointer on Regulator instance
	\param *lm pointer on some Model instance
	\param Yinit initial value of Yt
*/
	void PIDRegulator(const double w, Regulator *reg, Model *lm, double Yinit);
};