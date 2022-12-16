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
            std::cout << "Enter the function to integrate\n";
            std::cout << "You are in one dimension, please be aware to use 'x' as only variable\n";
            std::cout << "f(x) = ";
            std::getline(std::cin, function);

            if (std::cin.fail()) {
                std::cout << "\nstd::cin.fail() in Parser Function\nCheck if you have written the function correctly";
                return;
            }

            int res = fparser->Parse(function, "x");

            if (res < 0) break;
            std::cout << "\nError in building the function\nCheck if you have written the function correctly (check typos, variables...)\npress ENTER to retry\n";


        }
        else if (d==2){
            std::cin.ignore(1000, '\n');
            std::cout << "Enter the function to integrate\n";
            std::cout << "You are in two dimensions, please be aware to use 'x' and 'y'  as only variables\n";
            std::cout << "f(x,y) = ";
            std::getline(std::cin, function);
            if (std::cin.fail()) {
                std::cout << "\nstd::cin.fail() in Parser Function\nCheck if you have written the function correctly";
                return;
            }

            int res = fparser->Parse(function, "x,y");

            if (res < 0) break;
            std::cout << "\nError in building the function\nCheck if you have written the function correctly (check typos, variables...)\npress ENTER to retry\n";

        }
        else{
            std::cout<<"Error: dimension not 1 or 2";
        }
    }
}
double ParserFunction::getFunctionElement(double x) {

    fparser->Parse(function, "x");

    double vals[] = { x };
    return fparser->Eval(vals);}

double ParserFunction::getFunctionElement(double x, double y) {

    fparser->Parse(function, "x,y");
    double vals[] = { x, y };
    return fparser->Eval(vals);
}

