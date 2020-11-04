#pragma once
#include"Model.h"
/*!
	\brief class that implements Object of Control
	this class extends parent class Model and implements Nonlinear Model
*/
class NonLinear : public Model
{
private:
	float a, b, c, d;///< Coefficients for LinearModel class
	double Y = 1;///< Inital value for Yt
	double Ybefore = 0;///< Variable to store previous Yt
	double Yafter = 0;///< Variable to store next Yt
	double U_prev = 0;///< Variable to store previous InputWarm

public:
	/*!
		Constructor for NonLinearModel class
		\param a,b,c,d coefficients
		\param Y initial value of Yt
	*/
	NonLinear(const float a, const float b, const float c, const float d, const float Y);
	/*!
		it calculate Yt via nonlinear method
		\param ImputWarm output of Regulator
		\return input parameter to Object of Control Yt
	*/
	float equation(double U) override;
};