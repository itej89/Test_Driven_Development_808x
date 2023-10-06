# Test Driven Development 808x

### CI/CD status
![CICD Workflow status](https://github.com/itej89/Test_Driven_Development_808x/actions/workflows/run-unit-test-and-upload-codecov.yml/badge.svg) [![codecov](https://codecov.io/gh/itej89/Test_Driven_Development_808x/branch/main/graph/badge.svg)](https://codecov.io/gh/itej89/Test_Driven_Development_808x) [![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)


## Overview

PID Controller library

- libcontroller
- CMake
- GoogleTest

## Standard install via command-line
```bash
# Download the code:
  git clone https://github.com/itej89/Test_Driven_Development_808x
  cd Test_Driven_Development_808x
```

## Implement PID algorithm

```bash
# PIDLibrary design location
  Test_Driven_Development_808x/libs/libcontroller/UMLClassDiagram.pdf

# Implement the PID Algorithm inside the below file 
  Test_Driven_Development_808x/libs/libcontroller/src/pid_controller.cpp
```


## Steps to build the library and run test cases
``` bash
# Configure the project and generate a native build system:
  # Must re-run this command whenever any CMakeLists.txt file has been changed.
  cmake -S ./ -B build/
# Compile and build the project:
  # rebuild only files that are modified since the last build
  cmake --build build/
  # or rebuild everything from scracth
  cmake --build build/ --clean-first
  # to see verbose output, do:
  cmake --build build/ --verbose
# Run tests:
  cd build/; ctest; cd -
# Clean and start over:
  rm -rf build/
```


## Steps to geneate code coverage report
```bash
# if you don't have gcovr or lcov installed, do:
  sudo apt-get install gcovr lcov
# Set the build type to Debug and WANT_COVERAGE=ON
  cmake -D WANT_COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug -S ./ -B build/
# Now, do a clean compile, run unit test, and generate the covereage report
  cmake --build build/ --clean-first --target all test_coverage
# open a web browser to browse the test coverage report
  open build/test_coverage/index.html

```


