#include "ForderFunction.hpp"
#include <cmath>
#include <iostream>
#include <vector>

//Constructor
ForderFunction::ForderFunction(): forder(), corder(){}

//Destructor
ForderFunction::~ForderFunction() {}

//Methods

double ForderFunction::getFunctionElement(double x) {

    // Goes through a list of command already inserted and executes the operations
    double function = x;
    int i;
    int j=0;
    //Goes through list fo commands
    for (i =0; i<=forder.size();i++) {
        //f is the basic operation
        int f = forder[i];
        //c is the added constant
        int c = corder[j];

        //execute an operation depending on the command entered
        switch (f) {
            case 1:
                function = sin(function);
                break;
            case 2:
                function = cos(function);
                break;
            case 3:
                function = exp(function);
                break;
            case 4:
                j++;
                function = function + c;
                break;
            case 5:
                j++;
                function = function * c;
                break;
            case 6:
                function = function;
                break;
            default:
                function = x;

        }
    }
    return function;
}

double ForderFunction::getFunctionElement(double x, double y) {

    // Goes through a list of command already inserted and executes the operations
    double function = x;
    int i;
    int j=0;
    for (i =0; i<=forder.size();i++) {
        int f = forder[i];
        int c = corder[j];

        switch (f) {
            case 1:
                function = sin(function);
                break;
            case 2:
                function = cos(function);
                break;
            case 3:
                function = exp(function);
                break;
            case 4:
                j++;
                function = function + c;
                break;
            case 5:
                j++;
                function = function * c;
                break;
            case 6:
                function = function;
                break;
            case 7:
                function = function*y;
                break;
            case 8:
                function = function +y;
                break;
            case 9:
                function = pow(function,y);
                break;
            default:
                function = x;

        }
    }
    return function;
}

void ForderFunction::SetFunction(int d) {

     //list of command to compose the function
    std::string command;
    //Different command depending on the dimension:
    if (d==1){command = "Choose sin = 1,\n cos = 2,\n exp = 3,\n add a constant = 4,\n multiply by a constant = 5\n stop =-1 ";}
    if (d ==2){command = "Choose sin = 1,\n cos = 2,\n exp = 3,\n add a constant = 4,\n multiply by a constant = 5,\n *y = 7,\n+y = 8,\n^y = 9 \nstop =-1 ";}

    //initialization of parameter:
    int f = 0;
    int c = 0;

    forder.push_back(6); // so that it doesn't crush if someone just wants to integrate f(x)=x (i.e. if the first command is -1)
    corder.push_back(1); // same

    //Compose the function and store the command:
    std::cout << "By default, the function is f(x)=x" << std::endl;

    while (f >= 0) {
        std::cout << command
                  << std::endl;
        std::cin >> f; //Enter the command

        forder.push_back(f); // Store

        //special cases when use constant in the operation: have to store the constant wanted
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