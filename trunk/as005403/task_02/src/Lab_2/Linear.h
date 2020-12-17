#pragma once
#include"Model.h"
/*!
	\brief class that implements Object of Control
	this class extends parent class Model and implements Linear Model
*/
class Linear : public Model
{
private:
	float a, b;///< Coefficients for LinearModel class
	double Y = 0;///< Inital value for Yt
public:
	/*!
		Constructor for Linear class
		\param a,b coefficients
		\param Y initial value of Yt
	*/
	Linear(const float a, const float b, const double Y);
	/*!
		it calculate Yt via linear method
		\param ImputWarm output of Regulator
		\return input parameter to Object of Control Yt
	*/
	float equation(double U) override;
};

