 cmake_minimum_required(VERSION 3.14)

# Define the project and specify the languages used
project(Petrophysics LANGUAGES CXX)

option(BUILD_PP_TEST "Build the test" ON)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add a library target for the petrophysics code
add_library(Petrophysics STATIC
    petrophysics.h
    petrophysics.cpp
)

set_target_properties(Petrophysics PROPERTIES
    PUBLIC_HEADER "petrophysics.h"
)
# Specify include directories for this target and others that link against it
# target_include_directories(petrophysics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set(EIGEN_ROOT_DIR "/usr/local/include/eigen/3.4.0_1/include/eigen3/")
include_directories(
    ${EIGEN_ROOT_DIR}
)

target_compile_definitions(Petrophysics PUBLIC PETROPHYSICS_LIBRARY) # PRIVATE / INTERFACE
install(TARGETS Petrophysics
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    PUBLIC_HEADER DESTINATION include/Petrophysics
)


if(BUILD_PP_TEST)
  message(STATUS "*** configuring test")
  enable_testing()
  add_subdirectory(tests)
endif()

