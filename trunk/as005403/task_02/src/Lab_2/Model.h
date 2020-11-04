#pragma once
/*!
	\brief class that implements Object of Control
	abstract class to set needed functions
*/
class Model
{
public:
	/*!
		abstract function to override in child classes
		\param InputWarm output of Regulator
	*/
	virtual float equation(double InputWarm) = 0;
};
