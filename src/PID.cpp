#include "PID.h"
#include <math.h>
#include <numeric>
#include <iostream>
using namespace std;

/*
 * TODO: Complete the PID class.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    // Initialize parameters
    PID::Kp = Kp;
    PID::Ki = Ki;
    PID::Kd = Kd;
    // Initialize errors
    p_error = 0.0;
    i_error = 0.0;
    d_error = 0.0;
    // Set initialization to false to ensure correct initialization of p_error
    is_initialize = false;
}

void PID::UpdateError(double cte) {
    if (!is_initialize) {
        p_error = cte;
        is_initialize = true;
    }
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

double PID::TotalError() {
    return i_error;
}

