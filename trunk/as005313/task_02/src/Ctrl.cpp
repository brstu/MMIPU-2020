#include "Ctrl.h"

Ctrl::Ctrl(const double &ia, const double &ib, const double &ic, const double &id, const double &iy) : a(ia), b(ib), c(ic), d(id), y(iy)
{}

Ctrl::Ctrl(Ctrl*& other) : a(other->a), b(other->b), c(other->c), d(other->d), y(other->y)
{}

Ctrl& Ctrl::operator=(const Ctrl*& other)
{
	this->a = other->a;
	this->b = other->b;
	this->c = other->c;
	this->d = other->d;
	this->y = other->y;
	return *this;
}