#include "PID.h"

#include <algorithm>

 /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
PID::PID() {}
PID::~PID() {}
void PID::Init(double Kp, double Ki, double Kd) {
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  prev_cte = 0.0;    // former cte.
}
void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */ 
  p_error = cte;   // calculating proportional error
  i_error = i_error + cte;    // calculating integral error
  d_error = cte - prev_cte;    // calculating differential error
  prev_cte = cte;
}
double PID::TotalError() {
  return Kp * p_error + Ki * i_error + Kd * d_error;
}

