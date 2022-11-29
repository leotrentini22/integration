cmake_minimum_required(VERSION 3.1)
project(integration)

set(CMAKE_CXX_STANDARD 20)
include_directories(exprtk)

add_executable(main main.cpp function.cpp domain.cpp MidpointIntegrator.cpp AbstractIntegrator.cpp TrapezoidalIntegrator.cpp SimpsonIntegrator.cpp)
add_executable(prova prova.cpp)
