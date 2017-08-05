#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double pKp, double pKi, double pKd) {

    Kp = pKp;
    Ki = pKi;
    Kd = pKd;

    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
}

void PID::UpdateError(double cte) {

    p_error = cte;
    i_error += cte;
    d_error = cte - p_error;

}

double PID::TotalError() {
    return -1 * (Kp * p_error + Ki * i_error + Kd * d_error);
}

