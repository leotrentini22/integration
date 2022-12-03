//
// Created by Leonardo Trentini on 02/12/2022.
//
#include "ForderFunction.hpp"
#include <cmath>
#include <iostream>
#include <vector>

//Constructors
ForderFunction::ForderFunction(): forder(), corder(){}
ForderFunction::~ForderFunction() {}

//Methods
double ForderFunction::getFunctionElement(double x) {
    /**
     * Evaluate the function (previously inserted) for a certain point x (1D)
     */

    double function = x;
    int i;
    int j=0;
    for (i =0; i<=forder.size();i++) {
        int f = forder[i];
        int c = corder[j];

        if (f == 1) {
            function = sin(function);
        }
        if (f == 2) {
            function = cos(function);
        }
        if (f == 3) {
            function = exp(function);
        }
        if (f == 4) {
            j++;
            function = function + c;
        }
        if (f == 5) {
            j++;
            function = function * c;
        }
        if (f == 6) {
            function = function;
        }
        else{
            function = x;
        }

    }
    return function;
}

double ForderFunction::getFunctionElement(double x, double y) {
    /**
     * Evaluate the function (previously inserted) for a certain point with coordinates (x,y) (2D)
     * NOT IMPLEMENTED
     */

    return x*y;
}

void ForderFunction::SetFunction(int d) {
    /**
     * Compose a function iteratively from user choices (implemented only 1D)
     */

    //list of the command to create our function:
    // initialization of parameter:
    int f = 0;
    int c = 0;

    forder.push_back(6); // so that it doesn't crush if someone just wants to integrate f(x)=x (i.e. if the first command is -1)
    corder.push_back(1); // same

    //Compose the function and store the command:
    std::cout << "right now f(x)=x" << std::endl;
    while (f >= 0) {
        std::cout << "Choose sin = 1, cos = 2, exp = 3, add a constant = 4, multiply by a constant = 5 or stop =-1 "
                  << std::endl;
        std::cin >> f; //enter the command

        forder.push_back(f); // Store
        if (f == 4) {
            std::cout << "Value of the constant added: " << std::endl;
            std::cin >> c;
            corder.push_back(c);

        }
        if (f == 5) {
            std::cout << "Value of the constant: " << std::endl;
            std::cin >> c;
            corder.push_back(c);
        }
    }
}