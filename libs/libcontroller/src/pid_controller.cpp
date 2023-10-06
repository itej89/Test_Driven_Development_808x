#include "pid_controller.h"

using controller::PIDController;

PIDController::PIDController(double kp, double kd, double ki, 
            double out_min, double out_max, double sampling_rate) :
            kp_(kp), kd_(kd), ki_(ki), 
            out_max_(out_max), out_min_(out_min),
            dt_(sampling_rate) {

}
       

double PIDController::compute(double setpoint, double measurement) {


    return 9.0;
}