
add_library (controller)

target_include_directories(controller PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_sources(controller PUBLIC 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/pid_controller.cpp
)