/**
 * @file pid_controller.cpp
 * @brief Implementation file for the PIDController class
 */

#include "pid_controller.h"

#include <set>

using controller::PIDController;

/**
 * @brief Constructor for PIDController class.
 * @param kp Proportional gain
 * @param ki Integral gain
 * @param kd Derivative gain
 * @param out_min Minimum output
 * @param out_max Maximum output
 * @param sampling_rate Calculation frequency
 */
PIDController::PIDController(double kp, double kd, double ki, double out_min,
                             double out_max, double sampling_rate)
    : kp_(kp),
      kd_(kd),
      ki_(ki),
      out_max_(out_max),
      out_min_(out_min),
      dt_(sampling_rate) {}

/**
 * @brief Compute method used to calculate the PID control output
 * @param setpoint Desired setpoint value
 * @param measurement Input actual velocity value
 * @return PID control output
 */
double PIDController::compute(double setpoint, double measurement) {
  // calculate the error
  double error = setpoint - measurement;
  // compute proprtional control
  double prop_ctrl_ = kp_ * error;

  // calculate the integral error
  integral_error_ += error * dt_;
  double integral_ctrl_ = ki_ * integral_error_;

  // compute the derivative error
  double derivative_error_ = (error - prev_error_) / dt_;
  double derivative_ctrl_ = kd_ * derivative_error_;

  prev_error_ = error;
  // sum the p-i-d controls
  double output = prop_ctrl_ + integral_ctrl_ + derivative_ctrl_;

  // clamp output to bounds
  if (output > out_max_)
    return out_max_;
  else if (output < out_min_)
    return out_min_;
  else
    return output;
}
