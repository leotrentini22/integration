cmake_minimum_required(VERSION 3.14)
project(integration)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(fparser)

#Googletest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
# Create an executable to build:
add_executable(hello_test hello_test.cc)
add_executable(test_integrators Test/test_integrators.cpp Function/AbstractFunction.cpp Integrator/MidpointIntegrator.cpp Integrator/AbstractIntegrator.cpp Integrator/TrapezoidalIntegrator.cpp Integrator/SimpsonIntegrator.cpp Function/AbstractFunction.cpp Function/ForderFunction.cpp Function/ParserFunction.cpp fparser/fparser.cc Initialization.cpp)
add_executable(main main.cpp Function/AbstractFunction.cpp Integrator/MidpointIntegrator.cpp Integrator/AbstractIntegrator.cpp Integrator/TrapezoidalIntegrator.cpp Integrator/SimpsonIntegrator.cpp Function/AbstractFunction.cpp Function/ForderFunction.cpp Function/ParserFunction.cpp fparser/fparser.cc Initialization.cpp)
add_executable(testexprtk testexprtk.cpp Function/AbstractFunction.cpp Integrator/MidpointIntegrator.cpp Integrator/AbstractIntegrator.cpp Integrator/TrapezoidalIntegrator.cpp Integrator/SimpsonIntegrator.cpp Function/AbstractFunction.cpp Function/ForderFunction.cpp Function/ParserFunction.cpp Function/CodedFunction.cpp fparser/fparser.cc)
add_executable(test_main Test/test_main.cpp Function/AbstractFunction.cpp Integrator/MidpointIntegrator.cpp Integrator/AbstractIntegrator.cpp Integrator/TrapezoidalIntegrator.cpp Integrator/SimpsonIntegrator.cpp Function/AbstractFunction.cpp Function/ForderFunction.cpp Function/ParserFunction.cpp fparser/fparser.cc Initialization.cpp)

#Create a link to library:
target_link_libraries(hello_test GTest::gtest_main)
target_link_libraries(test_integrators GTest::gtest_main)
#target_link_libraries(main GTest::gtest_main)
#target_link_libraries(testexprtk GTest::gtest_main)

# include Google test
include(GoogleTest)

gtest_discover_tests(hello_test)
gtest_discover_tests(test_integrators)
#gtest_discover_tests(main)
#gtest_discover_tests(testexprtk)

