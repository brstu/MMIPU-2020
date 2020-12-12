#pragma once
#ifndef Rgl_H
#define Rgl_H

class Rgl
{
private:
	const double k, t, td, t0;
	double uk = 0, ek1 = 0, ek2 = 0;
	double q0, q1, q2;
public:
	Rgl(const double &qt);
	Rgl(const double &qt, const double &ik);
	Rgl(const double &qt, const double &ik, const double &it);
	Rgl(const double &qt, const double &ik, const double &it, const double &itd);
	double &eq(const double &iek);
};

#endif