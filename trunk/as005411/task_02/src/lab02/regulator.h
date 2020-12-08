#ifndef REGULATOR_H
#define REGULATOR_H

/**
*       \brief Regulator logic class.
* 
*       This class contains Regulator logic.
*/
class regulator
{
private:
    const double k, t, td, t0; //<! Bunch of constants for regulator.
    double uk = 0, ek1 = 0, ek2 = 0; //<! Vitals of all calculations.
    double q0, q1, q2; //<! Also constants for work.
public:

    /** 
    *   Constructor for unspecified variables.
    */
    regulator(const double &qt);
    /**
    *   Constructor for only K variable specified.
    */
    regulator(const double &qt, const double &ik);
    /**
    *   Constructor for variables K and T specified.
    */
    regulator(const double &qt, const double &ik, const double &it);
    /**
    *   Constructor for all variables specified. It also calculates all consts in process.
    */
    regulator(const double &qt, const double &ik, const double &it, const double &itd);
    /**
    *   \brief Primary regulator logic function.
    * 
    *   This function contains primary logic with needed value returned.
    *   \param iek Input value e(k)
    */
    double &eq(const double &iek);
};

#endif // REGULATOR_H
