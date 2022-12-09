//
// Created by Odile on 25.11.2022.
//

/*! \file */

/** Implementation of three different methods for the numerical computation of integrals in one or two dimensions
 * \f[
 * |I|=\left| \int_{\Omega} f(x,y) dxdy
 * \right|
 * \f]
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
#include "Function/AbstractFunction.hpp"
#include "Function/ForderFunction.hpp"
#include "Function/ParserFunction.hpp"
#include "Integrator/AbstractIntegrator.hpp"
#include "Integrator/MidpointIntegrator.hpp"
#include "Integrator/TrapezoidalIntegrator.hpp"
#include "Integrator/SimpsonIntegrator.hpp"
#include "Initialization.hpp"
#include <cassert>


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