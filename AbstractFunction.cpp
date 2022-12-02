//
// Created by Leonardo Trentini on 25/11/2022.
//

//File with the methods for the class Function defined in "function.hpp" -- not finished
#include "AbstractFunction.hpp"
#include <vector>
#include <cmath>
#include <iostream>

AbstractFunction::AbstractFunction() {

}

double AbstractFunction::getFunctionElement(double x) {
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
            function = function + c;
            j++;
        }
        if (f == 5) {
            function = function * c;
            j++;
        }
        else{
            function = x;
        }

    }
    return function;
}

void AbstractFunction::SetElements() {
    //list of the command to create our function:
    // initialization of parameter:
    int f =0;
    int c = 0;

    //Compose the function and store the command:
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