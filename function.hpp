//
// Created by Leonardo Trentini on 25/11/2022.
//

//I defined a class Function as suggested from the TA, not sure if it is the best way
#ifndef FUNCTION_HPP_
#define FUNCTION_HPP_

#include <ostream>
class Function{
private:
    double (*p_function)(double x,double y);
public:
    // Constructor:
    Function();
    Function(double (*p_function)(double x));
    Function(double (*p_function)(double x, double y));
    Function(double (*p_function1)(double x), double (*p_function2)(double y));
    // Destructor:
    ~Function();

    //Method:
    double getFunctionElement(double x, double y);

};

#endif /* FUNCTION_HPP_ */