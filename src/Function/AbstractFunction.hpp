//
// Created by Leonardo Trentini on 25/11/2022.
//

#ifndef ABSTRACTFUNCTION_HPP_
#define ABSTRACTFUNCTION_HPP_

#include <ostream>
#include <vector>

/**
 * Abstract class of function, with 3 derived classes (ways of getting function from user)
 * Only pure virtual methods
 */

class AbstractFunction{
public:
    // Constructor:
    AbstractFunction();

    // Destructor:
    virtual ~AbstractFunction();

    //Methods:
    virtual void SetFunction(int d)=0;

    virtual double getFunctionElement(double x)=0;
    virtual double getFunctionElement(double x, double y)=0;


};

#endif /* ABSTRACTFUNCTION_HPP_ */