#ifndef Mod_H
#define Mod_H
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
#include <iomanip>

#include "Lin.h"
#include "NoLin.h"
#include "Rgl.h"

class Mod
{
private:
	Lin *col = 0;
	NoLin* con = 0;
	Rgl *cr = 0;
	const double initu, inity, t0;
	double out = 0, et = 0, ut = 0;
public:
	Mod(const double &iu, const double &iy, const double &tq);
	bool initmodules(Lin *&l, NoLin *&n, Rgl *&r);
	double active();
};

#endif