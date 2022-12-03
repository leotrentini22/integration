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

void ParserFunction::SetFunction(int d) {
    while(true)
    {   if (d==1) {
            std::cin.ignore(1000, '\n');
            std::cout << "f(x) = ";
            std::getline(std::cin, function);
            if (std::cin.fail()) return;

            int res = fparser->Parse(function, "x");
            std::cout << res << std::endl;
            if (res < 0) break;

            //std::cout << std::string(res + 7, ' ') << "^\n"
            //          << fparser->ErrorMsg() << "\n\n";
        }
        else if (d==2){
            std::cin.ignore(1000, '\n');
            std::cout << "f(x,y) = ";
            std::getline(std::cin, function);
            if (std::cin.fail()) return;

            int res = fparser->Parse(function, "x,y");
            std::cout << res << std::endl;
            if (res < 0) break;

            //std::cout << std::string(res + 7, ' ') << "^\n"
            //          << fparser->ErrorMsg() << "\n\n";
        }
        else{
            std::cout<<"Error: dimension not 1 or 2";
        }
    }
}
double ParserFunction::getFunctionElement(double x) {
    fparser->Parse(function, "x");
    //std::cout<< res<<std::endl;
    //if(res < 0) return 0.0;
    //std::cout << std::string(res+7, ' ') << "^\n"
    //          << fparser->ErrorMsg() << "\n\n";
    double vals[] = { x };
    return fparser->Eval(vals);}

double ParserFunction::getFunctionElement(double x, double y) {
    fparser->Parse(function, "x,y");
    //std::cout<< res<<std::endl;
    //if(res < 0) return 0.0;
    //std::cout << std::string(res+7, ' ') << "^\n"
    //          << fparser->ErrorMsg() << "\n\n";
    double vals[] = { x, y };
    return fparser->Eval(vals);}

