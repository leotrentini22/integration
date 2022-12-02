//
// Created by Odile on 02.12.2022.
//

#include "ParserFunction.hpp"
#include <iostream>
#include <string>

ParserFunction::ParserFunction(): function() {
    this->fparser= new FunctionParser;
}
ParserFunction::~ParserFunction() noexcept {
    delete fparser;
}

void ParserFunction::SetFunction() {
    while(true)
    {
        std::cin.ignore(1000, '\n');
        std::cout << "f(x) = ";
        std::getline(std::cin, function);
        if(std::cin.fail()) return;

        int res = fparser->Parse(function, "x");
        std::cout<< res<<std::endl;
        if(res < 0) break;

        std::cout << std::string(res+7, ' ') << "^\n"
                  << fparser->ErrorMsg() << "\n\n";
    }
}
double ParserFunction::getFunctionElement(double x) {
    int res = fparser->Parse(function, "x");
    std::cout<< res<<std::endl;
    if(res < 0) return 0.0;
    std::cout << std::string(res+7, ' ') << "^\n"
              << fparser->ErrorMsg() << "\n\n";
    double vals[] = { 0 };
    vals[0] = x;
    return fparser->Eval(vals);}

double ParserFunction::getFunctionElement(double x, double y) {return x*y;}

