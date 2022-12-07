
#ifndef CODEDFUNCTION_HPP_
#define CODEDFUNCTION_HPP_

#include <ostream>
#include <vector>
#include "AbstractFunction.hpp"

/**
 * Daughter class of AbstractFunction
 * it implements the methods to use a function directly coded by the user (need to recompile everytime)
 */

class CodedFunction : public AbstractFunction{

public:
    // Constructor:
    CodedFunction();

    // Destructor:
    ~CodedFunction();

    //Methods:

    virtual void SetFunction(int d) override {};

    virtual double getFunctionElement(double x) override;
    virtual double getFunctionElement(double x, double y) override;

};

#endif /* CODEDFUNCTION_HPP_ */