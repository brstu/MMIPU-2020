#include "Mod.h"

Mod::Mod(const double &iu, const double &iy, const double &tq) : initu(iu), inity(iy), t0(tq)
{
	cout << "Mod created";
	cout << "\n!!!Please initialize modules!!!\n\n";
}

double Mod::active()
{
	std::fstream linout, nlinout;
	linout.open("Lin.csv", std::fstream::out);
	nlinout.open("NoLin.csv", std::ios::out);
	linout.precision(3);
	nlinout.precision(3);
	linout.flags(std::ios::fixed);
	nlinout.flags(std::ios::fixed);

	linout << 'i' << ';' << 'e' << ';' << 'y' << ';' << 'u' << endl;
	for (int i = 0; i < 10000; i++)
	{
		et = initu - out;
		ut = cr->eq(et);
		out = col->eq(ut);
		linout << i << ';' << et <<';' << out << ';' << ut << endl;
	}
	cout << "Lin: \n" << et << ' ' << out << ' ' << ut << endl;

	nlinout << 'i' << ';' << 'e' << ';' << 'y' << ';' << 'u' << endl;
	for (int i = 0; i < 10000; i++)
	{
		et = initu - out;
		ut = cr->eq(et);
		out = con->eq(ut);
		nlinout << i << ';' << et << ';' << out << ';' << ut << endl;
	}
	cout << "Nolin: \n" << et << ' ' << out << ' ' << ut << endl;
	linout.close();
	nlinout.close();
	return true;
}

bool Mod::initmodules(Lin*& l, NoLin*& n, Rgl*& r)
{
	cr = r;
	col = l;
	con = n;
	return true;
}