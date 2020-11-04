#include "controlobject.h"
/**
*       \brief Abstract class for control object implementation
*
*       This class contains common variables and methods(mostly abstract) with some additional useful logic such as copyconstructors and other.
*/


controlobject::controlobject(const double &ia, const double &ib, const double &ic, const double &id, const double &iy) : a(ia), b(ib), c(ic), d(id), y(iy)
{

}

controlobject::controlobject(controlobject*& other) : a(other->a), b(other->b), c(other->c), d(other->d), y(other->y)
{
}


controlobject& controlobject::operator=(const controlobject*& other)
{
	this->a = other->a;
	this->b = other->b;
	this->c = other->c;
	this->d = other->d;
	this->y = other->y;
	return *this;
}
