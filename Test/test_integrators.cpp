//
// Created by Leonardo Trentini on 09/12/2022.
//

/**
 * Google Test to verify the accuracy of numerical integrators
 */

#include <gtest/gtest.h>
#include "../src/fparser/fparser.hh"
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include "../src/Function/AbstractFunction.hpp"
#include "../src/Function/ForderFunction.hpp"
#include "../src/Function/ParserFunction.hpp"
#include "../src/Function/CodedFunction.hpp"
#include "../src/Integrator/AbstractIntegrator.hpp"
#include "../src/Integrator/MidpointIntegrator.hpp"
#include "../src/Integrator/TrapezoidalIntegrator.hpp"
#include "../src/Integrator/SimpsonIntegrator.hpp"
#include <iostream>
#include <string>

// Demonstrate the accuracy of integrators

TEST(IntegratorTest, CorrectResult) {

    // set a dummy domain 1D, with parameters
    double initialX=0.0, finalX=1.0;
    int N=1000;
    int d=1;

    //true known result
    double result=0.5;

    //tolerance
    double tol=1e-3;


    // set the function to integrate (an already coded one, with a well known primitive)
    // In this case, we set it to be f(x)=x
    AbstractFunction *pfunction;
    pfunction = new CodedFunction;
    pfunction -> SetFunction(d);

    // set the integrator -> at first the Midpoint integrator
    AbstractIntegrator *pIntegration = 0;

    pIntegration = new MidpointIntegrator;
    pIntegration->SetNumberOfPartitions(N);
    pIntegration->SetExtremes(initialX,finalX);

    pIntegration->SetFunction(pfunction);

// TEST: expected to be close to the exact solution
    ASSERT_NEAR(pIntegration->Integrate(), result, tol);


    // test the Trapezoidal Integrator
    pIntegration = new TrapezoidalIntegrator;
    pIntegration->SetNumberOfPartitions(N);
    pIntegration->SetExtremes(initialX,finalX);

    pIntegration->SetFunction(pfunction);

// TEST: expected to be close to the exact solution
    ASSERT_NEAR(pIntegration->Integrate(), result, tol);


    // test the Simpson Integrator
    pIntegration = new SimpsonIntegrator;
    pIntegration->SetNumberOfPartitions(N);
    pIntegration->SetExtremes(initialX,finalX);

    pIntegration->SetFunction(pfunction);

// TEST: expected to be close to the exact solution
    ASSERT_NEAR(pIntegration->Integrate(), result, tol);


    //Test for 2D
    double initialY=0.0, finalY=1.0;
    int M=1001;
    N=1001;
    d=2;
    result=0.25;

    //set the function as f(x,y)=x*y
    pfunction = new CodedFunction;
    pfunction -> SetFunction(d);

    //set the midpoint integrator in 2D
    pIntegration = new MidpointIntegrator;
    pIntegration->SetNumberOfPartitions(N,M);
    pIntegration->SetExtremes(initialX,finalX, initialY, finalY);

    pIntegration->SetFunction(pfunction);

// TEST: expected to be close to the exact solution
    ASSERT_NEAR(pIntegration->Integrate(), result, tol);


    //set the trapezoidal integrator in 2D
    pIntegration = new TrapezoidalIntegrator;
    pIntegration->SetNumberOfPartitions(N,M);
    pIntegration->SetExtremes(initialX,finalX, initialY, finalY);

    pIntegration->SetFunction(pfunction);

// TEST: expected to be close to the exact solution
    ASSERT_NEAR(pIntegration->Integrate(), result, tol);


    //set the simpson integrator in 2D
    pIntegration = new SimpsonIntegrator;
    pIntegration->SetNumberOfPartitions(N,M);
    pIntegration->SetExtremes(initialX,finalX, initialY, finalY);

    pIntegration->SetFunction(pfunction);

// TEST: expected to be close to the exact solution
    ASSERT_NEAR(pIntegration->Integrate(), result, tol);

}
