// Simple example file for the function parser
// ===========================================

/* When running the program, try for example with these values:

f(x) = x^2
min x: -5
max x: 5
step: 1

*/

#include "fpaser/fparser.hh"
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include "domain.hpp"
#include "AbstractFunction.hpp"
#include "ForderFunction.hpp"
#include "ParserFunction.hpp"
#include "CodedFunction.hpp"
#include "AbstractIntegrator.hpp"
#include "MidpointIntegrator.hpp"
#include "TrapezoidalIntegrator.hpp"
#include "SimpsonIntegrator.hpp"
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
    pfunction -> SetFunction();

    AbstractIntegrator *pIntegration = 0;

    pIntegration = new MidpointIntegrator;
    pIntegration->SetNumberOfPartitions(N);
    pIntegration->SetExtremes(initialX,finalX);

    pIntegration->SetFunction(pfunction);

    result = pIntegration->Integrate();

    std::cout<<"result = "<<result;

    return 0;
}
