//
// Created by Leonardo Trentini on 25/11/2022.
//
#ifndef FUNCTION_HPP_
#define FUNCTION_HPP_

#include <ostream>
class Function{
private:
    double (*p_function)(double x,double y);
public:
    Function();
    Function(double (*p_function)(double x));
    Function(double (*p_function)(double x, double y));
    Function(double (*p_function1)(double x), double (*p_function2)(double y));
    ~Function();
    double getFunctionElement(double x, double y);

};

#endif /* FUNCTION_HPP_ */