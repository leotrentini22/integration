cmake_minimum_required(VERSION 3.1)
project(integration)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(fpaser)

add_executable(main main.cpp AbstractFunction.cpp domain.cpp MidpointIntegrator.cpp AbstractIntegrator.cpp TrapezoidalIntegrator.cpp SimpsonIntegrator.cpp)
add_executable(testexprtk testexprtk.cpp fpaser/fparser.cc)
