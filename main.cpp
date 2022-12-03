//
// Created by Odile on 25.11.2022.
//


// next things to do:
// - check if "ForderFunction" works correctly
// - implement "ForderFunction" and in 2D
// - Doxygen
// - Tests

// extras
// - extend for stranger domains
// - plot

/** Implementation of three different methods for the numerical computation of integrals in one or two dimensions
 * Structure:
 * AbstractIntegrator = Abstract class of integrators, with 3 derived classes
 * MidpointIntegrator, TrapezoidalIntegrator, SimpsonIntegrator
 *
 * AbstractFunction = Abstract class of function, with 3 derived classes (ways of getting function from user)
 * ForderFunction, ParserFunction, CodedFunction
 */


//HOW TO RUN
//click "build", "run" and follow the instructions of the screen


#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include "AbstractFunction.hpp"
#include "ForderFunction.hpp"
#include "ParserFunction.hpp"
#include "AbstractIntegrator.hpp"
#include "MidpointIntegrator.hpp"
#include "TrapezoidalIntegrator.hpp"
#include "SimpsonIntegrator.hpp"
#include "Initialization.hpp"


int main(){
    Initialization init;
    init.SetDimension();
    init.SetParameters();
    init.ChooseMethod();
    init.SetFunctionToIntegrate();
    init.CalculateIntegral();
    init.PrintResult();

    return 0;
}