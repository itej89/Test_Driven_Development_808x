# Any C++ source files needed to build this target (shell-app).
add_executable(shell-app
  # list of source cpp files:
  main.cpp
  ${CMAKE_SOURCE_DIR}/libs/libcontroller/src/pid_controller.cpp
)

# Any include directories needed to build this target.
# Note: we do not need to specify the include directories for the
# dependent libraries, they are automatically included.
target_include_directories(shell-app PUBLIC
  # list inclue directories:
  ${CMAKE_SOURCE_DIR}/include
  ${CMAKE_SOURCE_DIR}/libs/libcontroller/include
  ${CMAKE_SOURCE_DIR}/libs/libcontroller/src
)

# Any dependent libraires needed to build this target.
target_link_libraries(shell-app PUBLIC
  # list of libraries
  )

target_link_options(shell-app PUBLIC
  --static
  )
  
