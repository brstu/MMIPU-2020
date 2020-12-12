#include <iostream>
#include <cmath>
#include <iomanip>
#include "Mod.h"

int main()
{
	double  a = 0.3, 
		b = 0.0001,  
		b1 = 0.1,
		c = 0.01,  
		d = 0.1,
		u_t = 25,
		y_t = 1, 
		k = 0.1, 
		t = 10,  
		tq = 10,
		td = 50;
	Mod *newMod = new Mod(u_t, y_t, tq);
	Lin *ccol = new Lin(a, b1, c, d, y_t);
	NoLin* cconl = new NoLin(a, b, c, d, y_t);
	Rgl *cr = new Rgl(tq, k, t, td);
	newMod->initmodules(ccol, cconl, cr);
	newMod->active();
	delete newMod;
	return 0;
}