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
    p_error = -1.0;
    i_error = 0.0;
    d_error = 0.0;
    // Set initialization to false to ensure correct initialization of p_error
    is_initialize = false;
    
    /*
    // Twiddling parameters
    best_error = std::numeric_limits<double>::infinity();
    added_ = false;
    subtracted_ = false;
    twiddle_error = 0;
    best_error = std::numeric_limits<double>::max();
    twiddle_id = 0;
    dp = {0.1*Kp, 0.1*Ki, 0.1*Kd};
    PID::twiddle_t = twiddle_t;
     */
}

void PID::UpdateError(double cte) {
    if (!is_initialize) {
        p_error = cte;
        is_initialize = true;
    }
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
    /*
     if (twiddle_t > std::accumulate(dp.begin(), dp.end(), 0)) {
     std::cout << "dp: " << dp[0] << " p: " << pid_K[0] << ", di: " << dp[1] << " i: " << pid_K[1] << ", dd: " << dp[2] << " d: " << pid_K[2] << std::endl;
     if (twiddle_error<best_error) {
     best_error = twiddle_error;
     dp[twiddle_id] *=1.1;
     twiddle_id = (twiddle_id+1) % pid_K.size();
     added_ = false;
     subtracted_ = false;
     
     
     }
     if (!added_ && !subtracted_) {
     added_= true;
     pid_K[twiddle_id] += dp[twiddle_id];
     } else if (added_ && !subtracted_) {
     subtracted_ = true;
     pid_K[twiddle_id] -= 2*dp[twiddle_id];
     } else {
     pid_K[twiddle_id] += dp[twiddle_id];
     dp[twiddle_id] *= 0.9;
     twiddle_id = (twiddle_id+1) % pid_K.size();
     added_ = false;
     subtracted_ = false;
     }
     twiddle_error = 0;
     }
     */
}

double PID::TotalError() {
    return i_error;
}

