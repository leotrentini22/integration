cmake_minimum_required(VERSION 3.1)
project(integration)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(fparser)

add_executable(main main.cpp AbstractFunction.cpp MidpointIntegrator.cpp AbstractIntegrator.cpp TrapezoidalIntegrator.cpp SimpsonIntegrator.cpp AbstractFunction.cpp ForderFunction.cpp ParserFunction.cpp fparser/fparser.cc Initialization.cpp)
add_executable(testexprtk testexprtk.cpp AbstractFunction.cpp MidpointIntegrator.cpp AbstractIntegrator.cpp TrapezoidalIntegrator.cpp SimpsonIntegrator.cpp AbstractFunction.cpp ForderFunction.cpp ParserFunction.cpp CodedFunction.cpp fparser/fparser.cc)
