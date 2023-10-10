#include <iostream>
#include "pid_controller.h"
// take input from user and show output here

int main() {
  controller::PIDController myController(0.15, .25, .20, 0, 70, .02);
  double setPoint = 45;
  double actualOutput = 20;

  for (int i = 0; i < 30; i++) {
    double output = myController.compute(setPoint, actualOutput);
    actualOutput += output;
  }
  std::cout << "PID output is: " << actualOutput << std::endl;
}
