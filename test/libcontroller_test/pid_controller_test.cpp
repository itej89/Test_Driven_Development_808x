#include <gtest/gtest.h>
#include "gmock/gmock.h"
#include <vector>
#include "pid_controller.h"

using controller::PIDController;


TEST( pid_controller_test, commpute_limit) {

 PIDController pid_controller(2, 0.1, 0.001, -100, 100, 0.01);
  
  /**
   * @brief Test upper limit clamping of the PID controller
   * 
   */
  double upper_limit = pid_controller.compute(0,-10);
  EXPECT_FLOAT_EQ(upper_limit, 100.0);

  /**
   * @brief Test lower limit clamping of the PID controller
   * 
   */
  double lower_limit = pid_controller.compute(0,10);
  EXPECT_FLOAT_EQ(lower_limit, -100.0);

}

TEST( pid_controller_test, commpute) {

  PIDController pid_controller(2, 0.1, 0.001, -100, 100, 0.01);
  
  /**
   * @brief Call compute method
   * 
   */
  double control_signal = pid_controller.compute(0,-1);

  /**
   * @brief Expect control singal within 5 units of tolerance
   * 
   */
  double diff = std::abs(control_signal - 12);
  EXPECT_LT(diff, 5);


}
