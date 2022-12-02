//
// Created by Leonardo Trentini on 25/11/2022.
//

//I defined a class Function as suggested from the TA, not sure if it is the best way
#ifndef FUNCTION_HPP_
#define FUNCTION_HPP_

#include <ostream>
#include <vector>


class AbstractFunction{
protected:
    double (*p_function1D)(double x);
    double (*p_function2D)(double x,double y);
    std::vector<int> forder;
    std::vector<int> corder;
public:
    // Constructor:
    AbstractFunction();
    AbstractFunction(double (*p_function)(double x));
    AbstractFunction(double (*p_function)(double x, double y));

    // Destructor:
    ~AbstractFunction();

    //Method:

    virtual double SetFunction()=0;

    double getFunctionElement(double x);
    double getFunctionElement(double x, double y);

    void SetElements();





};

#endif /* FUNCTION_HPP_ */