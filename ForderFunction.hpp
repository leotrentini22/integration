//
// Created by Leonardo Trentini on 25/11/2022.
//

//I defined a class Function as suggested from the TA, not sure if it is the best way

#ifndef FORDERFUNCTION_HPP_
#define FORDERFUNCTION_HPP_

#include <ostream>
#include <vector>
#include "AbstractFunction.hpp"

/**
 * Daughter class of AbstractFunction
 * it implements the methods to get a function from built step by step iteratively by the user
 */

class ForderFunction : public AbstractFunction{
protected:
    std::vector<int> forder;
    std::vector<int> corder;
public:
    // Constructor:
    ForderFunction();

    // Destructor:
    ~ForderFunction();

    //Methods:

    virtual void SetFunction(int d) override;

    virtual double getFunctionElement(double x) override;
    virtual double getFunctionElement(double x, double y) override;

};

#endif /* FORDERFUNCTION_HPP_ */