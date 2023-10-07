#pragma once

namespace controller {

    /**
     * @brief Class type implements the pid controller
     * 
     */
    class PIDController
    {
    private:
        
        /*!
         * PID gain parameters
        */
        double kp_ = 2, kd_ = 0.01, ki_ = 0.0001;

        /*!
         * Target set point
        */
        double set_point_;

        /*!
         * Previous error
        */
        double prev_error_;

        /*!
         * Integral error
        */
        double integral_error_;

        /*!
         * Output value clamping range
        */
        double out_min_;
        double out_max_;

        /*!
         * sampling rate in seconds for integral and differential 
         *  error calculation
        */
        double dt_;

    public:

        /**
         * @brief Construct a new pid controller object
         * 
         * @param kp proportional gain
         * @param kd derivative gain
         * @param ki integral gain
         * @param out_min output value min
         * @param out_max output value max
         * @param sampling_rate measurement sampling rate
         */
        PIDController(double kp, double kd, double ki, 
            double out_min, double out_max, double sampling_rate);
       
        /**
         * @brief method to compute the control signal value
         * 
         * @param setpoint desired setpoint
         * @param measurement measurement
         * @return double control sigal output
         */
        double compute(double setpoint, double measurement);
    };
 
}

