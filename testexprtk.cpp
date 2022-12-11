// Simple example file for the function parser
// ===========================================

/* When running the program, try for example with these values:

f(x) = x^2
min x: -5
max x: 5
step: 1

*/

#include "src/fparser/fparser.hh"
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include "src/Function/AbstractFunction.hpp"
#include "src/Function/ForderFunction.hpp"
#include "src/Function/ParserFunction.hpp"
#include "src/Function/CodedFunction.hpp"
#include "src/Integrator/AbstractIntegrator.hpp"
#include "src/Integrator/MidpointIntegrator.hpp"
#include "src/Integrator/TrapezoidalIntegrator.hpp"
#include "src/Integrator/SimpsonIntegrator.hpp"
#include <iostream>
#include <string>


int main()
{
    double initialX=0.0, finalX=1.0;
    int N=100;
    int d=1;
    double result=0.0;
    std::cout << "Using parser." << std::endl;
    AbstractFunction *pfunction;
    pfunction = new ForderFunction;
    pfunction -> SetFunction(d);

    AbstractIntegrator *pIntegration = 0;

    pIntegration = new MidpointIntegrator;
    pIntegration->SetNumberOfPartitions(N);
    pIntegration->SetExtremes(initialX,finalX);

    pIntegration->SetFunction(pfunction);

    result = pIntegration->Integrate();

    std::cout<<"result = "<<result;

    return 0;
}
