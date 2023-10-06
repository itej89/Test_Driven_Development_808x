#include <gtest/gtest.h>
#include "pid_controller.h"

using controller::PIDController;


TEST( pid_controller_test, commpute_limit) {

  PIDController pid_controller(2, 0.1, 0.001, 1, 100, 0.01);
  EXPECT_EQ(pid_controller.compute(3,4), 9.0);
}

TEST( pid_controller_test, commpute) {

  PIDController pid_controller(2, 0.1, 0.001, 1, 100, 0.01);
  EXPECT_EQ(pid_controller.compute(3,4), 9.0);
}

// TEST(dummy_test, this_will_fail) {
//   EXPECT_EQ(my_function2(3.2), 3.2);
// }
