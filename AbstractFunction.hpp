//
// Created by Leonardo Trentini on 25/11/2022.
//

//I defined a class Function as suggested from the TA, not sure if it is the best way
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