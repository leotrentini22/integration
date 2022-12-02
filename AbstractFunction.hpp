//
// Created by Leonardo Trentini on 25/11/2022.
//

//I defined a class Function as suggested from the TA, not sure if it is the best way
#ifndef ABSTRACTFUNCTION_HPP_
#define ABSTRACTFUNCTION_HPP_

#include <ostream>
#include <vector>


class AbstractFunction{
public:
    // Constructor:
    AbstractFunction();

    // Destructor:
    virtual ~AbstractFunction();

    //Methods:

    virtual void SetFunction()=0;

    virtual double getFunctionElement(double x)=0;
    virtual double getFunctionElement(double x, double y)=0;


};

#endif /* ABSTRACTFUNCTION_HPP_ */