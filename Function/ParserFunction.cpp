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
    /**
     * Get a function from a string inserted by the user
     */
    while(true)
    {   if (d==1) {
            std::cin.ignore(1000, '\n');
            std::cout << "You are in one dimension, please be aware to use 'x' as only variable\n";
            std::cout << "f(x) = ";
            std::getline(std::cin, function);
            if (function.find("y") != std::string::npos) {
                std::cout << "\nstd::cin.fail() in Parser Function\nCheck if you have written the function correctly\n";
                return;
            }
            if (function.find("z") != std::string::npos) {
                std::cout << "\nstd::cin.fail() in Parser Function\nCheck if you have written the function correctly\n";
                return;
            }
            if (std::cin.fail()) {
                std::cout << "\nstd::cin.fail() in Parser Function\nCheck if you have written the function correctly";
                return;
            }

            int res = fparser->Parse(function, "x");
            //std::cout << res << std::endl;
            if (res < 0) break;

            //std::cout << std::string(res + 7, ' ') << "^\n"
            //          << fparser->ErrorMsg() << "\n\n";
        }
        else if (d==2){
            std::cin.ignore(1000, '\n');
            std::cout << "You are in two dimensions, please be aware to use 'x' and 'y'  as only variables\n";
            std::cout << "f(x,y) = ";
            std::getline(std::cin, function);
            if (std::cin.fail()) {
                std::cout << "\nstd::cin.fail() in Parser Function\nCheck if you have written the function correctly";
                return;
            }

            int res = fparser->Parse(function, "x,y");
            //std::cout << res << std::endl;
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
    /**
     * Evaluate the function (previously inserted) for a certain point x (1D)
     */
    fparser->Parse(function, "x");
    //std::cout<< res<<std::endl;
    //if(res < 0) return 0.0;
    //std::cout << std::string(res+7, ' ') << "^\n"
    //          << fparser->ErrorMsg() << "\n\n";
    double vals[] = { x };
    return fparser->Eval(vals);}

double ParserFunction::getFunctionElement(double x, double y) {
    /**
     * Evaluate the function (previously inserted) for a certain point with coordinates (x,y) (2D)
     */
    fparser->Parse(function, "x,y");
    //std::cout<< res<<std::endl;
    //if(res < 0) return 0.0;
    //std::cout << std::string(res+7, ' ') << "^\n"
    //          << fparser->ErrorMsg() << "\n\n";
    double vals[] = { x, y };
    return fparser->Eval(vals);
}

