# Any C++ source files needed to build this target (cpp-test).
add_executable(pid-controller-test
  # list of source cpp files:
  main.cpp
  pid_controller_test.cpp
  )

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.
target_include_directories(pid-controller-test PUBLIC
  # list of include directories:
  ${CMAKE_SOURCE_DIR}/include
  )

# Any dependent libraires needed to build this target.
target_link_libraries(pid-controller-test PUBLIC
  # list of libraries:
  gtest
  gmock
  controller
  )

# Enable CMake’s test runner to discover the tests included in the
# binary, using the GoogleTest CMake module.
gtest_discover_tests(pid-controller-test)
