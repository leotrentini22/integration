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
add_executable(main main.cpp AbstractFunction.cpp MidpointIntegrator.cpp AbstractIntegrator.cpp TrapezoidalIntegrator.cpp SimpsonIntegrator.cpp AbstractFunction.cpp ForderFunction.cpp ParserFunction.cpp fparser/fparser.cc Initialization.cpp)
add_executable(testexprtk testexprtk.cpp AbstractFunction.cpp MidpointIntegrator.cpp AbstractIntegrator.cpp TrapezoidalIntegrator.cpp SimpsonIntegrator.cpp AbstractFunction.cpp ForderFunction.cpp ParserFunction.cpp CodedFunction.cpp fparser/fparser.cc)
#Create a link to library:
target_link_libraries(hello_test GTest::gtest_main)
#target_link_libraries(main GTest::gtest_main)
#target_link_libraries(testexprtk GTest::gtest_main)
# include Google test
include(GoogleTest)

gtest_discover_tests(hello_test)
#gtest_discover_tests(main)
#gtest_discover_tests(testexprtk)

